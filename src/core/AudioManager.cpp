#include "AudioManager.h"
#include "XmlMusicsFile.h"
#include "Logger.h"
#include <list>
#include <boost/thread.hpp>

template<>AudioManager *Ogre::Singleton<AudioManager>::ms_Singleton = NULL;

const int      AudioManager::m_CH_BUF_COUNT(2);
const ALsizei  AudioManager::m_CH_BUF_SIZE(96 * 1024);
const float    AudioManager::m_DEFAULT_LOOP(-1.0f);

const ALfloat AudioManager::m_LISTENER_POS[3] =
{
	0.0f, 0.0f, 0.0f
};

const ALfloat AudioManager::m_LISTENER_VEL[3] =
{
	0.0f, 0.0f, 0.0f
};

const ALfloat AudioManager::m_LISTENER_ORI[6] =
{
	0.0f, 0.0f, -1.0f,  0.0f, 1.0f, 0.0f
};

const uint32_t AudioManager::m_THREAD_SLEEP_TIME(250);

AudioManager::Player::Player(const Ogre::String& id) :
	m_ID(id),
	m_Loop(m_DEFAULT_LOOP),
	m_VorbisInfo(NULL),
	m_VorbisSection(0),
	m_StreamFinished(false)
{
	;
}

AudioManager::Player::~Player(void)
{
	Stop();
}


void AudioManager::Player::Play(void)
{
	boost::recursive_mutex::scoped_lock lock(AudioManager::getSingleton().m_UpdateMutex);
   AudioManager &engine = AudioManager::getSingleton();

   AudioManager::Music* Music = engine.GetMusic( m_ID );
   if(!Music)
   {
      LOG_ERROR("No such music found with name '"+m_ID);
      return;
   }

   SetLoop( Music->Loop );
   PlayFile( Music->File );
}


void AudioManager::Player::PlayFile(const Ogre::String &file)
{
   boost::recursive_mutex::scoped_lock lock(AudioManager::getSingleton().m_UpdateMutex);
   AudioManager &engine = AudioManager::getSingleton();

   printf("Open music %s\n", file.c_str());
	// open vorbis file
	if(ov_fopen(const_cast<char *>(file.c_str()), &m_VorbisFile))
	{
		LOG_ERROR("Can't play file '"+file);
		return;
	}

	if(!engine.m_Initialized)
	{
		LOG_ERROR("Audio system is not initialized");
		return;
	}

	// get file info
	m_VorbisInfo = ov_info(&m_VorbisFile, -1.0f);

	// create sound source
	alGenSources(1, &m_Source);

	// create buffers
	ALuint buffers[m_CH_BUF_COUNT];
	alGenBuffers(m_CH_BUF_COUNT, buffers);

	// set source parameters
	alSourcei(m_Source, AL_LOOPING, AL_FALSE);

	// fill buffers
	for(int i = 0; i < m_CH_BUF_COUNT; ++i)
	{
		ALsizei buffer_size = FillBuffer();

		if(buffer_size)
		{
			alBufferData(buffers[i], m_VorbisInfo->channels == 1 ?
				AL_FORMAT_MONO16 : AL_FORMAT_STEREO16,
				(const ALvoid *)AudioManager::getSingleton().m_Buffer,
				(ALsizei)buffer_size, (ALsizei)m_VorbisInfo->rate);

			alSourceQueueBuffers(m_Source, 1, &buffers[i]);
		}
		else
		{
			m_StreamFinished = true;
			alDeleteBuffers(1, &buffers[i]);
		}
	}

	// start playback
	alSourcePlay(m_Source);

	// add player to players list
	engine.playerList.push_back(this);
}


void AudioManager::Player::Stop(void)
{
   boost::recursive_mutex::scoped_lock lock(AudioManager::getSingleton().m_UpdateMutex);

	if(!IsActive())
		return;

	// stop source
	alSourceStop(m_Source);

	// get source buffers
	int queued_count = 0;
	alGetSourcei(m_Source, AL_BUFFERS_QUEUED, &queued_count);

	// unqueue and delete buffers
	for(int i = 0; i < queued_count; ++i)
	{
		ALuint buffer_id;
		alSourceUnqueueBuffers(m_Source, 1, &buffer_id);
		alDeleteBuffers(1, &buffer_id);
	}

	// delete source
	alDeleteSources(1, &m_Source);

	// rest cleanup
	ov_clear(&m_VorbisFile);

	// remove player from list
   std::list<Player *> &players_list = AudioManager::getSingleton().playerList;
	players_list.erase(find(players_list.begin(), players_list.end(), this));
}


void AudioManager::Player::Pause(void)
{
   boost::recursive_mutex::scoped_lock lock(AudioManager::getSingleton().m_UpdateMutex);

	if(IsActive())
		alSourcePause(m_Source);
}


const bool AudioManager::Player::IsActive(void)
{
   boost::recursive_mutex::scoped_lock lock(AudioManager::getSingleton().m_UpdateMutex);

   std::list<Player *> &players_list = AudioManager::getSingleton().playerList;
	return find(players_list.begin(), players_list.end(), this) != players_list.end();
}


void AudioManager::Player::SetLoop(const float loop)
{
   boost::recursive_mutex::scoped_lock lock(AudioManager::getSingleton().m_UpdateMutex);
   m_Loop = loop;
}


ALsizei AudioManager::Player::FillBuffer(void)
{
	ALsizei read = 0;

	if(m_StreamFinished)
		return read;

	char *&buffer = AudioManager::getSingleton().m_Buffer;

	bool finished = false;
	do
	{
		long result = ov_read(&m_VorbisFile, buffer + read,
			m_CH_BUF_SIZE - read, 0, 2, 1, &m_VorbisSection);

		switch(result)
		{
		// error
		case OV_HOLE:
		case OV_EBADLINK:
		case OV_EINVAL:
			finished = true;
			break;

		// end of stream
		case 0:
			// if there isn't loop point or can't seek
			if(m_Loop < 0.0f || ov_time_seek(&m_VorbisFile, m_Loop))
				finished = true;
			break;

		// readed "result" bytes
		default:
			read += result;
			if(read == m_CH_BUF_SIZE)
				finished = true;
		}
	}
	while(!finished);

	return read;
}


void AudioManager::Player::Update(void)
{
	// try to fill processed buffers
	{
		int processed;
		alGetSourcei(m_Source, AL_BUFFERS_PROCESSED, &processed);

		for(int i = 0; i < processed; ++i)
		{
			// try fill buffer
			ALsizei buffer_size = FillBuffer();

			if(buffer_size)
			{
				ALuint buffer_id;
				alSourceUnqueueBuffers(m_Source, 1, &buffer_id);

				alBufferData(buffer_id, m_VorbisInfo->channels == 1 ?
					AL_FORMAT_MONO16 : AL_FORMAT_STEREO16,
					(const ALvoid *)AudioManager::getSingleton().m_Buffer,
					(ALsizei)buffer_size, (ALsizei)m_VorbisInfo->rate);

				alSourceQueueBuffers(m_Source, 1, &buffer_id);
			}
			// finished reading stream
			else
			{
				m_StreamFinished = true;
				break;
			}
		}
	}

	// manage source state
	{
		int processed;
		alGetSourcei(m_Source, AL_BUFFERS_PROCESSED, &processed);

		int queued;
		alGetSourcei(m_Source, AL_BUFFERS_QUEUED, &queued);

		if(m_StreamFinished && processed == queued)
		{
			Stop();
		}
		else
		{
			ALenum source_state;
			alGetSourcei(m_Source, AL_SOURCE_STATE, &source_state);
			if(source_state == AL_STOPPED)
			{
				alSourcePlay(m_Source);
			}
		}
	}
}


uint64_t AudioManager::Player::GetPosition(void)
{
   boost::recursive_mutex::scoped_lock lock(AudioManager::getSingleton().m_UpdateMutex);

	int play_offset;
	alGetSourcei(m_Source, AL_SAMPLE_OFFSET, &play_offset);
	return (ov_pcm_tell(&m_VorbisFile) - (m_CH_BUF_COUNT * m_CH_BUF_SIZE
		/ m_VorbisInfo->channels / sizeof(int16_t) - play_offset)) * 1000 / m_VorbisInfo->rate;
}

AudioManager::AudioManager(void) :
   m_ThreadContinue(true)
{
   m_Initialized = Init();
   if(m_Initialized)
   {
      LOG_TRIVIAL("AudioManager :: OK");
      m_Buffer       = new char[m_CH_BUF_SIZE];
      m_UpdateThread = new boost::thread(boost::ref(*this));
   }
   else
      LOG_WARNING("AudioManager :: Fail");

   /* Load musics */
   XmlMusicsFile musics( "./data/musics.xml" );
   musics.LoadMusics();
}

AudioManager::~AudioManager(void)
{
   Stop();
   if(m_Initialized)
   {
      LOG_TRIVIAL("AudioManager :: Drop");
      m_ThreadContinue = false;
      m_UpdateThread->join();
      delete m_UpdateThread;
      delete [] m_Buffer;

      alcMakeContextCurrent(NULL);
      alcDestroyContext(m_ALContext);
      alcCloseDevice(m_ALDevice);
      LOG_TRIVIAL("AudioManager :: Destroyed");
   }
}

void AudioManager::Play(void)
{
   boost::recursive_mutex::scoped_lock lock(m_UpdateMutex);

   for(std::list<AudioManager::Player *>::iterator it = playerList.begin();
         it != playerList.end(); ++it)
      (*it)->Play();
}

void AudioManager::Pause(void)
{
   boost::recursive_mutex::scoped_lock lock(m_UpdateMutex);

   for(std::list<AudioManager::Player *>::iterator it = playerList.begin();
         it != playerList.end(); ++it)
      (*it)->Pause();
}

void AudioManager::Stop(void)
{
   boost::recursive_mutex::scoped_lock lock(m_UpdateMutex);

   for(std::list<AudioManager::Player *>::iterator it = playerList.begin();
         it != playerList.end(); ++it)
   {
      std::list<AudioManager::Player *>::iterator jt = it++;
      (*jt)->Stop();
   }
}

AudioManager::Music* AudioManager::GetMusic( const Ogre::String& name )
{
   boost::recursive_mutex::scoped_lock lock(m_UpdateMutex);

   for(std::list<AudioManager::Music>::iterator it = musicList.begin();
         it != musicList.end(); ++it)
   {
      if(it->Name == name)
      {
         return &(*it);
      }
   }

   return NULL;
}

void AudioManager::AddMusic(const AudioManager::Music &music)
{
   boost::recursive_mutex::scoped_lock lock(m_UpdateMutex);

   for(std::list<AudioManager::Music>::iterator it = musicList.begin();
         it != musicList.end(); ++it)
   {
      if(it->Name == music.Name)
      {
         LOG_ERROR("AudioManager :: Music with name '"+music.Name+"' already exists");
         return;
      }
   }

   /* add */
   musicList.push_back(music);
}

const bool AudioManager::Init(void)
{
   m_ALDevice = alcOpenDevice(NULL);
   if(!m_ALDevice)
   {
      LOG_ERROR("AudioManager :: There's no default sound device");
      return false;
   }

   m_ALContext = alcCreateContext(m_ALDevice, NULL);
   if(!m_ALContext)
   {
      LOG_ERROR("AudioManager :: Could not create context for sound device");
      return false;
   }
   alcMakeContextCurrent(m_ALContext);

   /* listeners */
   alListenerfv(AL_POSITION, m_LISTENER_POS);
   alListenerfv(AL_VELOCITY, m_LISTENER_VEL);
   alListenerfv(AL_ORIENTATION, m_LISTENER_ORI);

   return true;
}

/* Should not really bother using this on release build */
const char* AudioManager::ALError(void)
{
#if _DEBUG
   ALenum error_code = alGetError();
   if(error_code == AL_NO_ERROR)
      return NULL;
   else
      return alGetString(error_code);
#else
   return NULL; /* We are perfect */
#endif
}

const char* AudioManager::ALCError(const ALCdevice *device)
{
#if _DEBUG
   const ALCdevice *alc_device = (device == NULL ?
         const_cast<ALCdevice *>(m_ALDevice) :
         const_cast<ALCdevice *>(device));

   ALCenum error_code = alcGetError(const_cast<ALCdevice *>(alc_device));
   if(error_code == ALC_NO_ERROR)
      return NULL;
   else
      return alcGetString(const_cast<ALCdevice *>(device), error_code);
#else
   return NULL; /* We are perfect */
#endif
}

void AudioManager::Update(void)
{
   boost::recursive_mutex::scoped_lock lock(m_UpdateMutex);

   std::list<AudioManager::Player*>::iterator it = playerList.begin();
   while(it != playerList.end())
   {
      /* we are erasin in Update() method, so this is important */
      std::list<AudioManager::Player*>::iterator jt = it++;
      (*jt)->Update();
   }
}

void AudioManager::operator()()
{
   while(m_ThreadContinue)
   {
      Update();

      boost::xtime xt;
      boost::xtime_get(&xt, boost::TIME_UTC);
      xt.nsec += m_THREAD_SLEEP_TIME * 1000000;
      boost::thread::sleep(xt);

      m_UpdateThread->yield();
   }
}

