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



#ifndef MOVIE_ENGINE_HH__
#define MOVIE_ENGINE_HH__



extern "C"
{
	#include <ogg/ogg.h>
	#include <theora/theoradec.h>
}
#include <fstream>
#include <string>
#include <list>
#include <queue>
#include <boost/thread.hpp>
#include <OgreFrameListener.h>
#include <OgreSingleton.h>

#include "MediaEngine.h"
#include "MovieBlitter.h"
#include "SoundEngine.h"



class MovieEngine : public MediaEngine,
	public Ogre::FrameListener, public Ogre::Singleton<MovieEngine>
{
public:
	class Player
	{
	public:
		Player(const int arg_id);
		~Player();
		
		void Play(MovieBlitter *(*f_blitter_create)(), const std::string &arg_custom_magic = "");
		void PlayFile(const std::string &arg_path, MovieBlitter *(*f_blitter_create)(),
			const std::string &arg_custom_magic = "");
		void Stop();
		void Pause(const bool arg_pause = true);
		const bool IsActive();
		void Update(const int arg_delta);
		
	private:
		uint32_t m_ID;
		bool m_Paused;
		
		// ogg stream
		std::ifstream m_FileStream;
		ogg_sync_state m_SyncState;
		int m_ReadChunkSize;
		bool m_StreamFinished;
		
		struct Stream
		{
			enum Type
			{
				T_AUDIO,
				T_VIDEO,
				T_DATA
			};
			
			int serial;
			ogg_stream_state state;
			Type type;
		};
		std::list<Stream> m_Streams;
		typedef std::list<Stream>::iterator StreamIt;
		
		// frame queue
		struct Frame
		{
			char *data;
			char *custom;
			int custom_size;
			uint64_t index;
		};
		std::queue<Frame> m_Frames;
		uint32_t m_CacheFramesCount;
		
		// custom
		std::string m_CustomMagic;
		
		// video
		uint64_t m_VideoTimePassed;
		uint64_t m_VideoNextFrameIndex;
		MovieBlitter *m_VideoBlitter;
		
		// theora-related
		th_dec_ctx *m_VideoDecCtx;
		th_info m_VideoInfo;
		th_comment m_VideoComment;
		th_setup_info *m_VideoSetupInfo;
		th_ycbcr_buffer m_YCbCrBuffer;
		
		// audio
		SoundEngine::Player m_AudioPlayer;
		
		void FillBuffer();
		void SetBufferFramesCount(const int arg_count);
		bool PopNextOggPage(ogg_page &ret_page);
		bool PopNextOggPacketBySerial(ogg_packet &ret_packet, const int arg_serial);

		Frame VideoFrameNext(ogg_packet &arg_packet);
		bool VideoFrameIsValid(Frame &arg_frame);
		void VideoFrameFree(Frame &arg_frame);
		bool VideoFrameAddToQueue(ogg_packet &arg_packet);
		
		StreamIt GetStreamByType(const Stream::Type arg_type);
		StreamIt GetStreamBySerial(const int arg_serial);
		
		int DataStreamDecodeHeaderIn(ogg_packet *arg_packet);
		char *ExtractCustomData(int &ret_size);
		void ClearStreams();
		void YCbCrCopy(void *ret_frame, const th_ycbcr_buffer arg_ycbcr_buffer, int arg_pic_width, int arg_pic_height);
	};
	
	MovieEngine();
	~MovieEngine();

	// playback interface
	void PauseAll();
	void ResumeAll();
	void StopAll();
	
	void Update(const int arg_delta);
	virtual bool frameStarted(const Ogre::FrameEvent &evt);

private:
	static const uint32_t m_DEFAULT_CACHE_FRAMES_COUNT;
	static const int m_DEFAULT_READ_CHUNK_SIZE;
	static const uint32_t m_MANUAL_SYNC_DELTA;

	std::list<Player *> m_Players;
};



#endif
