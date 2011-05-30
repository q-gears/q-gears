/*
	This file is part of Q-Gears.

	Copyright 2008,2009 Gennadiy Brich

	Q-Gears is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	Q-Gears is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with Q-Gears.  If not, see <http://www.gnu.org/licenses/>.
*/



#include <string>
#include <list>
#include <boost/thread.hpp>

#if defined(__WIN32__) || defined(_WIN32)
	#include <al.h>
	#include <alc.h>
#else
	#include <AL/al.h>
	#include <AL/alc.h>
#endif

#include <vorbis/vorbisfile.h>
#include <OgreLogManager.h>

#include "SoundEngine.h"



using namespace std;
using namespace boost;



template<>SoundEngine *Ogre::Singleton<SoundEngine>::ms_Singleton(0);



const int SoundEngine::m_CH_BUF_COUNT(2);

const ALsizei SoundEngine::m_CH_BUF_SIZE(96 * 1024);

const double SoundEngine::m_DEFAULT_LOOP(-1.0f);

const ALfloat SoundEngine::m_DEFAULT_LISTENER_POS[3] =
{
	0.0f, 0.0f, 0.0f
};

const ALfloat SoundEngine::m_DEFAULT_LISTENER_VEL[3] =
{
	0.0f, 0.0f, 0.0f
};

const ALfloat SoundEngine::m_DEFAULT_LISTENER_ORI[6] =
{
	0.0f, 0.0f, -1.0f,  0.0f, 1.0f, 0.0f
};

const int SoundEngine::m_THREAD_SLEEP_TIME(250);



SoundEngine::Player::Player(const int arg_id) :
	m_ID(arg_id),
	m_Loop(m_DEFAULT_LOOP),
	m_VorbisInfo(NULL),
	m_VorbisSection(0),
	m_StreamFinished(false)
{
	;
}


SoundEngine::Player::~Player()
{
	Stop();
}


void SoundEngine::Player::Play()
{
	recursive_mutex::scoped_lock lock(SoundEngine::getSingleton().m_UpdateMutex);
	
	SoundEngine &engine = SoundEngine::getSingleton();
	
	PlayFile(engine.GetRecordPath(m_ID));
}


void SoundEngine::Player::PlayFile(const string &arg_path)
{
	recursive_mutex::scoped_lock lock(SoundEngine::getSingleton().m_UpdateMutex);
	
	SoundEngine &engine = SoundEngine::getSingleton();
	
	// open vorbis file
	if(ov_fopen(const_cast<char *>(arg_path.c_str()), &m_VorbisFile))
	{
		engine.Log("Can't play file");
		return;
	}

	if(!engine.m_Initialized)
	{
		engine.Log("Not initialized");
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
				(const ALvoid *)SoundEngine::getSingleton().m_Buffer,
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
	engine.m_Players.push_back(this);
}


void SoundEngine::Player::Stop()
{
	recursive_mutex::scoped_lock lock(SoundEngine::getSingleton().m_UpdateMutex);
	
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
	list<Player *> &players_list = SoundEngine::getSingleton().m_Players;
	players_list.erase(find(players_list.begin(), players_list.end(), this));
}


void SoundEngine::Player::Pause(const bool arg_pause)
{
	recursive_mutex::scoped_lock lock(SoundEngine::getSingleton().m_UpdateMutex);
	
	if(IsActive())
	{
		if(arg_pause)
			alSourcePause(m_Source);
		else
			alSourcePlay(m_Source);
	}
}


const bool SoundEngine::Player::IsActive()
{
	recursive_mutex::scoped_lock lock(SoundEngine::getSingleton().m_UpdateMutex);
	
	list<Player *> &players_list = SoundEngine::getSingleton().m_Players;
	return find(players_list.begin(), players_list.end(), this) != players_list.end();
}


void SoundEngine::Player::SetLoop(const double arg_loop)
{
	recursive_mutex::scoped_lock lock(SoundEngine::getSingleton().m_UpdateMutex);
	
	m_Loop = arg_loop;
}


ALsizei SoundEngine::Player::FillBuffer()
{
	ALsizei read = 0;
	
	if(m_StreamFinished)
		return read;
	
	char *&buffer = SoundEngine::getSingleton().m_Buffer;
	
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


void SoundEngine::Player::Update()
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
					(const ALvoid *)SoundEngine::getSingleton().m_Buffer,
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


uint64_t SoundEngine::Player::GetPosition()
{
	recursive_mutex::scoped_lock lock(SoundEngine::getSingleton().m_UpdateMutex);
	
	int play_offset;
	alGetSourcei(m_Source, AL_SAMPLE_OFFSET, &play_offset);
	return (ov_pcm_tell(&m_VorbisFile) - (m_CH_BUF_COUNT * m_CH_BUF_SIZE
		/ m_VorbisInfo->channels / sizeof(int16_t) - play_offset)) * 1000 / m_VorbisInfo->rate;
}


SoundEngine::SoundEngine() :
	m_ErrorMessage(""),
	m_ThreadContinue(true)
{
	// suspend next created thread while not fully initialized
	recursive_mutex::scoped_lock lock(m_UpdateMutex);

	SetLogPrefix("SoundEngine: ");

	Log("Initializing...");

	m_Initialized = OpenALInit();

	if(m_Initialized)
	{
		Log("Success");
		m_Buffer = new char[m_CH_BUF_SIZE];
		m_UpdateThread = new thread(ref(*this));
	}
	else
		Log("Failure");
}


SoundEngine::~SoundEngine()
{
	StopAll();

	if(m_Initialized)
	{
		Log("Destroying...");
		m_ThreadContinue = false;
		m_UpdateThread->join();
		delete m_UpdateThread;
		delete [] m_Buffer;

		OpenALFree();
		Log("Success");
	}
}


void SoundEngine::PauseAll()
{
	recursive_mutex::scoped_lock lock(m_UpdateMutex);

	for(list<Player *>::iterator it = m_Players.begin();
			it != m_Players.end(); ++it)
		(*it)->Pause(true);
}


void SoundEngine::ResumeAll()
{
	recursive_mutex::scoped_lock lock(m_UpdateMutex);

	for(list<Player *>::iterator it = m_Players.begin();
			it != m_Players.end(); ++it)
		(*it)->Pause(false);
}


void SoundEngine::StopAll()
{
	recursive_mutex::scoped_lock lock(m_UpdateMutex);

	int players_size = SoundEngine::m_Players.size();
	
	list<Player *>::iterator it = m_Players.begin();
	while(it != m_Players.end())
	{
		// we are erasing in Stop() method, so this is important
		list<Player *>::iterator jt = it++;
		(*jt)->Stop();
	}
}


const bool SoundEngine::OpenALInit()
{
	bool result = false;

	m_ALDevice = alcOpenDevice(NULL);
	if (m_ALDevice == NULL)
	{
		Log("Default sound device is not present");
		return result;
	}

	// create and select rendering context
	m_ALContext = alcCreateContext(m_ALDevice, NULL);
	if (m_ALContext == NULL)
	{
		Log("Can't create context for sound device");
		return result;
	}
	alcMakeContextCurrent(m_ALContext);

	// set default listener properties
	alListenerfv(AL_POSITION, m_DEFAULT_LISTENER_POS);
	alListenerfv(AL_VELOCITY, m_DEFAULT_LISTENER_VEL);
	alListenerfv(AL_ORIENTATION, m_DEFAULT_LISTENER_ORI);

	result = true;

	return result;
}


void SoundEngine::OpenALFree()
{
	// deselect active context
	alcMakeContextCurrent(NULL);
	// destroy context
	alcDestroyContext(m_ALContext);
	// close sound device
	alcCloseDevice(m_ALDevice);
}


const bool SoundEngine::OpenALalError()
{
	bool result;

	ALenum error_code = alGetError();

	if(error_code == AL_NO_ERROR)
		result = false;
	else
	{
		m_ErrorMessage = string(alGetString(error_code));
		result = true;
	}

	return result;
}


const bool SoundEngine::OpenALalcError(const ALCdevice *arg_device)
{
	bool result;

	const ALCdevice *device = (arg_device == NULL ?
		const_cast<ALCdevice *>(m_ALDevice) :
		const_cast<ALCdevice *>(arg_device));

	ALCenum error_code = alcGetError(const_cast<ALCdevice *>(device));

	if(error_code == ALC_NO_ERROR)
		result = false;
	else
	{
		m_ErrorMessage =
			string(alcGetString(const_cast<ALCdevice *>(device), error_code));
		result = true;
	}

	return result;
}


void SoundEngine::Update()
{
	recursive_mutex::scoped_lock lock(m_UpdateMutex);
	
	list<Player *>::iterator it = m_Players.begin();
	while(it != m_Players.end())
	{
		// we are erasing in Update() method, so this is important
		list<Player *>::iterator jt = it++;
		(*jt)->Update();
	}
}


void SoundEngine::operator()()
{
	while(m_ThreadContinue)
	{
		Update();

		// sleep some time [250ms]
		xtime xt;
		xtime_get(&xt, TIME_UTC);
		xt.nsec += m_THREAD_SLEEP_TIME * 1000000;
		thread::sleep(xt);

		// try give control to another threads, if we are non-preemptive
		m_UpdateThread->yield();
	}
}
