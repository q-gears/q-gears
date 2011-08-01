#include "AudioSystem.h"
#include "Logger.h"
#include <list>
#include <boost/thread.hpp>

template<>AudioSystem *Ogre::Singleton<AudioSystem>::ms_Singleton(0);

const int      AudioSystem::m_CH_BUF_COUNT(2);
const ALsizei  AudioSystem::m_CH_BUF_SIZE(96 * 1024);
const float    AudioSystem::m_DEFAULT_LOOP(-1.0f);

const ALfloat AudioSystem::m_LISTENER_POS[3] =
{
	0.0f, 0.0f, 0.0f
};

const ALfloat AudioSystem::m_LISTENER_VEL[3] =
{
	0.0f, 0.0f, 0.0f
};

const ALfloat AudioSystem::m_LISTENER_ORI[6] =
{
	0.0f, 0.0f, -1.0f,  0.0f, 1.0f, 0.0f
};

const uint32_t AudioSystem::m_THREAD_SLEEP_TIME(250);

AudioSystem::Player::Player(const uint32_t id) :
	m_ID(id),
	m_Loop(m_DEFAULT_LOOP),
	m_VorbisInfo(NULL),
	m_VorbisSection(0),
	m_StreamFinished(false)
{
	;
}

AudioSystem::Player::~Player(void)
{
	Stop();
}


void AudioSystem::Player::Play(void)
{
	boost::recursive_mutex::scoped_lock lock(AudioSystem::getSingleton().m_UpdateMutex);
   AudioSystem &engine = AudioSystem::getSingleton();

   //TO-DO: Implent
   //PlayFile(engine.GetRecordPath(m_ID));
}


void AudioSystem::Player::PlayFile(const std::string &file)
{
   boost::recursive_mutex::scoped_lock lock(AudioSystem::getSingleton().m_UpdateMutex);
   AudioSystem &engine = AudioSystem::getSingleton();

	// open vorbis file
	if(ov_fopen(const_cast<char *>(file.c_str()), &m_VorbisFile))
	{
		LOG_ERROR("Can't play file");
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
				(const ALvoid *)AudioSystem::getSingleton().m_Buffer,
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


void AudioSystem::Player::Stop(void)
{
   boost::recursive_mutex::scoped_lock lock(AudioSystem::getSingleton().m_UpdateMutex);

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
   std::list<Player *> &players_list = AudioSystem::getSingleton().playerList;
	players_list.erase(find(players_list.begin(), players_list.end(), this));
}


void AudioSystem::Player::Pause(void)
{
   boost::recursive_mutex::scoped_lock lock(AudioSystem::getSingleton().m_UpdateMutex);

	if(IsActive())
		alSourcePause(m_Source);
}


const bool AudioSystem::Player::IsActive(void)
{
   boost::recursive_mutex::scoped_lock lock(AudioSystem::getSingleton().m_UpdateMutex);

   std::list<Player *> &players_list = AudioSystem::getSingleton().playerList;
	return find(players_list.begin(), players_list.end(), this) != players_list.end();
}


void AudioSystem::Player::SetLoop(const float loop)
{
   boost::recursive_mutex::scoped_lock lock(AudioSystem::getSingleton().m_UpdateMutex);
   m_Loop = loop;
}


ALsizei AudioSystem::Player::FillBuffer(void)
{
	ALsizei read = 0;

	if(m_StreamFinished)
		return read;

	char *&buffer = AudioSystem::getSingleton().m_Buffer;

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


void AudioSystem::Player::Update(void)
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
					(const ALvoid *)AudioSystem::getSingleton().m_Buffer,
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


uint64_t AudioSystem::Player::GetPosition(void)
{
   boost::recursive_mutex::scoped_lock lock(AudioSystem::getSingleton().m_UpdateMutex);

	int play_offset;
	alGetSourcei(m_Source, AL_SAMPLE_OFFSET, &play_offset);
	return (ov_pcm_tell(&m_VorbisFile) - (m_CH_BUF_COUNT * m_CH_BUF_SIZE
		/ m_VorbisInfo->channels / sizeof(int16_t) - play_offset)) * 1000 / m_VorbisInfo->rate;
}

AudioSystem::AudioSystem(void) :
   m_ThreadContinue(true)
{
   m_Initialized = Init();
   if(m_Initialized)
   {
      LOG_TRIVIAL("AudioSystem :: OK");
      m_Buffer       = new char[m_CH_BUF_SIZE];
      m_UpdateThread = new boost::thread(boost::ref(*this));
   }
   else
      LOG_WARNING("AudioSystem :: Fail");
}

AudioSystem::~AudioSystem(void)
{
   Stop();
   if(m_Initialized)
   {
      LOG_TRIVIAL("AudioSystem :: Drop");
      m_ThreadContinue = false;
      m_UpdateThread->join();
      delete m_UpdateThread;
      delete [] m_Buffer;

      DeInit();
      LOG_TRIVIAL("Succes");
   }
}

void AudioSystem::Play(void)
{
   boost::recursive_mutex::scoped_lock lock(m_UpdateMutex);

   for(std::list<AudioSystem::Player *>::iterator it = playerList.begin();
         it != playerList.end(); ++it)
      (*it)->Play();
}

void AudioSystem::Pause(void)
{
   boost::recursive_mutex::scoped_lock lock(m_UpdateMutex);

   for(std::list<AudioSystem::Player *>::iterator it = playerList.begin();
         it != playerList.end(); ++it)
      (*it)->Pause();
}

void AudioSystem::Stop(void)
{
   boost::recursive_mutex::scoped_lock lock(m_UpdateMutex);

   for(std::list<AudioSystem::Player *>::iterator it = playerList.begin();
         it != playerList.end(); ++it)
   {
      std::list<AudioSystem::Player *>::iterator jt = it++;
      (*jt)->Stop();
   }
}

const bool AudioSystem::Init(void)
{
   m_ALDevice = alcOpenDevice(NULL);
   if(!m_ALDevice)
   {
      LOG_ERROR("AudioSystem :: There's no default sound device");
      return false;
   }

   m_ALContext = alcCreateContext(m_ALDevice, NULL);
   if(!m_ALContext)
   {
      LOG_ERROR("AudioSystem :: Could not create context for sound device");
      return false;
   }
   alcMakeContextCurrent(m_ALContext);

   /* listeners */
   alListenerfv(AL_POSITION, m_LISTENER_POS);
   alListenerfv(AL_VELOCITY, m_LISTENER_VEL);
   alListenerfv(AL_ORIENTATION, m_LISTENER_ORI);

   return true;
}

void AudioSystem::DeInit(void)
{
   alcMakeContextCurrent(NULL);
   alcDestroyContext(m_ALContext);
   alcCloseDevice(m_ALDevice);
}

/* Should not really bother using this on release build */
const char* AudioSystem::ALError(void)
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

const char* AudioSystem::ALCError(const ALCdevice *device)
{
#if _DEBUG
   const ALCdevice *alc_device = (device == NULL ?
         const_cast<ALCdevice *>(m_ALDevice) :
         const_cast<ALCdevice *>(device));

   ALCenum error_code = alcGetError(const_cast<ALCdevice *>(alc_device)));
   if(error_code == ALC_NO_ERROR)
      return NULL;
   else
      return alcGetString(device, error_code);
#else
   return NULL; /* We are perfect */
#endif
}

void AudioSystem::Update(void)
{
   boost::recursive_mutex::scoped_lock lock(m_UpdateMutex);

   std::list<AudioSystem::Player*>::iterator it = playerList.begin();
   while(it != playerList.end())
   {
      /* we are erasin in Update() method, so this is important */
      std::list<AudioSystem::Player*>::iterator jt = it++;
      (*jt)->Update();
   }
}

void AudioSystem::operator()()
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

