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



#ifndef SOUND_ENGINE_HH__
#define SOUND_ENGINE_HH__



#include <string>
#include <sstream>
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
#include <OgreSingleton.h>

#include "MediaEngine.h"



class SoundEngine : public MediaEngine, public Ogre::Singleton<SoundEngine>
{
public:
	class Player
	{
	public:
		Player(const int arg_id);
		~Player();
		
		void Play();
		void PlayFile(const std::string &arg_path);
		void Stop();
		void Pause(const bool arg_pause = true);
		const bool IsActive();
		void SetLoop(const double arg_loop);
		void Update();
		uint64_t GetPosition();
		
	private:
		uint32_t m_ID;
		double m_Loop;
		OggVorbis_File m_VorbisFile;
		vorbis_info *m_VorbisInfo;
		int m_VorbisSection;
		bool m_StreamFinished;
		ALuint m_Source;
		
		ALsizei FillBuffer();
	};
	
	SoundEngine();
	~SoundEngine();

	// playback interface
	void PauseAll();
	void ResumeAll();
	void StopAll();

	void Update();
	// boost threading interface
	void operator()();

private:
	// allocate for every new player two 96Kb buffer chunks
	// every chunk would buffer ~0.5 seconds of 44100Hz stereo 16-bit data
	// in that case we can sleep updating buffers for 250ms
	static const int m_CH_BUF_COUNT;
	static const ALsizei m_CH_BUF_SIZE;

	// default loop offset for every new player
	static const double m_DEFAULT_LOOP;
	
	// default listener position
	static const ALfloat m_DEFAULT_LISTENER_POS[3];
	// default listener speed
	static const ALfloat m_DEFAULT_LISTENER_VEL[3];
	// default listener orientation
	static const ALfloat m_DEFAULT_LISTENER_ORI[6];

	// general
	bool m_Initialized;
	ALCdevice *m_ALDevice;
	ALCcontext *m_ALContext;
	char *m_Buffer;
	std::string m_ErrorMessage;

	// threading
	static const int m_THREAD_SLEEP_TIME;
	boost::recursive_mutex m_UpdateMutex;
	boost::thread *m_UpdateThread;
	bool m_ThreadContinue;
	
	std::list<Player *> m_Players;

	const bool OpenALInit();
	void OpenALFree();
	const bool OpenALalError();
	const bool OpenALalcError(const ALCdevice *arg_device = NULL);
};



#endif
