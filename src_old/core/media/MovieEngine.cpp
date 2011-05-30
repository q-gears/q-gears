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



extern "C"
{
	#include <ogg/ogg.h>
	#include <theora/theoradec.h>
}
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <OgreRoot.h>

#include "MovieEngine.h"
#include "MovieBlitter.h"
#include "SoundEngine.h"



using namespace std;
using namespace boost;



template<>MovieEngine *Ogre::Singleton<MovieEngine>::ms_Singleton = 0;



const uint32_t MovieEngine::m_DEFAULT_CACHE_FRAMES_COUNT = 10;

const int MovieEngine::m_DEFAULT_READ_CHUNK_SIZE = 8 * 1024;

const uint32_t MovieEngine::m_MANUAL_SYNC_DELTA = 100;



MovieEngine::Player::Player(const int arg_id) :
	m_ID(arg_id),
	m_Paused(false),
	m_ReadChunkSize(m_DEFAULT_READ_CHUNK_SIZE),
	m_CacheFramesCount(m_DEFAULT_CACHE_FRAMES_COUNT),
	m_AudioPlayer(0)
{
	;
}


MovieEngine::Player::~Player()
{
	Stop();
}


void MovieEngine::Player::Play(MovieBlitter *(*f_blitter_create)(),
		const string &arg_custom_magic)
{
	MovieEngine &engine = MovieEngine::getSingleton();
	
	PlayFile(engine.GetRecordPath(m_ID), f_blitter_create, arg_custom_magic);
}


void MovieEngine::Player::PlayFile(const string &arg_path, MovieBlitter *(*f_blitter_create)(),
		const string &arg_custom_magic)
{
	MovieEngine &engine = MovieEngine::getSingleton();
	
	m_CustomMagic = arg_custom_magic;
	
	// open file
	m_FileStream.open(arg_path.c_str(), ios::binary);
	if(!m_FileStream.is_open())
	{
		engine.Log("Can't play file");
		return;
	}
	
	ogg_sync_init(&m_SyncState);
	
	ogg_page page;
	ogg_packet packet;
	StreamIt it;
	
	int status;
	
	// read headers
	bool to_continue = true;
	while(to_continue && PopNextOggPage(page))
	{
		int page_serial = ogg_page_serialno(&page);
		
		// if page belongs to header
		if(ogg_page_bos(&page))
		{
			Stream item;
			item.serial = page_serial;
			status = ogg_stream_init(&item.state, item.serial);
			
			// check theora
			if(GetStreamByType(Stream::T_VIDEO) == m_Streams.end())
			{
				th_info_init(&m_VideoInfo);
				th_comment_init(&m_VideoComment);
				m_VideoSetupInfo = NULL;

				// get packet from page to check, whether theora or not
				status = ogg_stream_pagein(&item.state, &page);
				status = ogg_stream_packetout(&item.state, &packet);
				
				// try to decode header
				status = th_decode_headerin(&m_VideoInfo,
					&m_VideoComment, &m_VideoSetupInfo, &packet);
				// theora header detected
				if(status > 0)
				{
					engine.Log("Detected Theora video stream");
					item.type = Stream::T_VIDEO;
					m_Streams.push_back(item);
					continue;
				}
			}
			
			// check custom data
			if(GetStreamByType(Stream::T_DATA) == m_Streams.end())
			{
				status = ogg_stream_pagein(&item.state, &page);
				status = ogg_stream_packetout(&item.state, &packet);
				
				status = DataStreamDecodeHeaderIn(&packet);
				
				// theora header detected
				if(status > 0)
				{
					engine.Log("Detected Custom Data stream");
					item.type = Stream::T_DATA;
					m_Streams.push_back(item);
					continue;
				}
			}
			
			//TODO - Vorbis?
			
			// clear unsupported stream
			ogg_stream_clear(&item.state);
		}
		// push last packet to appropriate stream
		else
		{
			it = GetStreamBySerial(page_serial);
			if(it != m_Streams.end())
				status = ogg_stream_pagein(&it->state, &page);

			to_continue = false;
		}
	}
	
	// if video stream detected
	if((it = GetStreamByType(Stream::T_VIDEO)) != m_Streams.end())
	{
		// base init
		m_VideoBlitter = f_blitter_create();
		m_StreamFinished = false;
		m_VideoNextFrameIndex = 0;
		m_VideoTimePassed = 0;

		// read remaining header chunks
		// 1.0 api - read chunks until we encounter 1st video data packet
		to_continue = true;
		while(to_continue)
		{
			PopNextOggPacketBySerial(packet, it->serial);
			status = th_decode_headerin(&m_VideoInfo,
				&m_VideoComment, &m_VideoSetupInfo, &packet);

			to_continue = status > 0;
		}
		// after this we have one video packet for decoding

		m_VideoDecCtx = th_decode_alloc(&m_VideoInfo, m_VideoSetupInfo);

		// decode that one video packet and feed frame to queue
		VideoFrameAddToQueue(packet);

		FillBuffer();
		
		// init supplied blitter
		m_VideoBlitter->Init((int)m_VideoInfo.pic_width, (int)m_VideoInfo.pic_height);
		
		m_AudioPlayer.PlayFile(engine.GetRecordPath(m_ID));
		
		engine.m_Players.push_back(this);
	}
	// no point to play other streams without video
	else
	{
		ClearStreams();
		
		ogg_sync_clear(&m_SyncState);
		m_FileStream.close();
		engine.Log("Theora stream not found");
	}
}


void MovieEngine::Player::Stop()
{
	if(!IsActive())
		return;
	
	ClearStreams();
	
	// stop audio playback
	m_AudioPlayer.Stop();
	
	delete m_VideoBlitter;
	
	th_decode_free(m_VideoDecCtx);
	th_setup_free(m_VideoSetupInfo);
	th_comment_clear(&m_VideoComment);
	th_info_clear(&m_VideoInfo);

	ogg_sync_clear(&m_SyncState);
	m_FileStream.close();
	
	// remove player from list
	list<Player *> &players_list = MovieEngine::getSingleton().m_Players;
	players_list.erase(find(players_list.begin(), players_list.end(), this));
}


void MovieEngine::Player::Pause(const bool arg_pause)
{
	m_Paused = arg_pause;
	m_AudioPlayer.Pause(m_Paused);
}


const bool MovieEngine::Player::IsActive()
{
	list<Player *> &players_list = MovieEngine::getSingleton().m_Players;
	return find(players_list.begin(), players_list.end(), this) != players_list.end();
}


void MovieEngine::Player::Update(const int arg_delta)
{
	if(m_Paused)
		return;
	
	m_VideoTimePassed += arg_delta;
	
	// perform sync to audio
	if(m_AudioPlayer.IsActive())
	{
		if(m_AudioPlayer.GetPosition() - m_VideoTimePassed > m_MANUAL_SYNC_DELTA)
			m_VideoTimePassed = m_AudioPlayer.GetPosition();
	}

	// that way we can avoid precision errors
	uint64_t current_frame_index =
		static_cast<uint64_t>(m_VideoInfo.fps_numerator * m_VideoTimePassed) /
		(1000 * m_VideoInfo.fps_denominator);

	if(!m_Frames.empty())
	{
		Frame next_frame = m_Frames.front();
		if(next_frame.index <= current_frame_index)
		{
			m_VideoBlitter->Blit(static_cast<void *>(next_frame.data),
					static_cast<void *>(next_frame.custom), next_frame.custom_size);
			VideoFrameFree(next_frame);
			m_Frames.pop();
		}
	}

	// fill frame buffer
	FillBuffer();
}


void MovieEngine::Player::FillBuffer()
{
	if(m_StreamFinished && m_Frames.empty() && !m_AudioPlayer.IsActive())
	{
		Stop();
	}
	else
	{
		while(m_Frames.size() < m_CacheFramesCount)
		{
			ogg_packet packet;
			if(PopNextOggPacketBySerial(packet, GetStreamByType(Stream::T_VIDEO)->serial))
			{
				VideoFrameAddToQueue(packet);
			}
			// stream finished
			else
			{
				m_StreamFinished = true;
				break;
			}
		}
	}
}


void MovieEngine::Player::SetBufferFramesCount(const int arg_count)
{
	m_CacheFramesCount = arg_count;
}


bool MovieEngine::Player::PopNextOggPage(ogg_page &ret_page)
{
	bool result;

	bool to_continue = true;
	while(to_continue)
	{
		// if we have at least one full page buffered, return it
		if(ogg_sync_pageout(&m_SyncState, &ret_page) == 1)
		{
			to_continue = false;
			result = true;
		}
		else
		{
			// input file finished
			if(m_FileStream.eof())
			{
				to_continue = false;
				result = false;
			}
			// read next stream chunk to ogg sync buffer
			else
			{
				m_FileStream.read(ogg_sync_buffer(&m_SyncState, m_ReadChunkSize), m_ReadChunkSize);
				ogg_sync_wrote(&m_SyncState, m_FileStream.gcount());
			}
		}
	}

	return result;
}


bool MovieEngine::Player::PopNextOggPacketBySerial(ogg_packet &ret_packet, const int arg_serial)
{
	bool result;
	
	StreamIt stream = GetStreamBySerial(arg_serial);
	
	bool to_continue = true;
	while(to_continue)
	{
		// we have ready packet
		if(ogg_stream_packetout(&stream->state, &ret_packet) == 1)
		{
			to_continue = false;
			result = true;
		}
		// read next pages to fill packet
		else
		{
			// read successfully
			ogg_page page;
			if(PopNextOggPage(page))
			{
				int page_serial = ogg_page_serialno(&page);
				
				StreamIt it = GetStreamBySerial(page_serial);
				if(it != m_Streams.end())
					ogg_stream_pagein(&it->state, &page);
			}
			// finished reading
			else
			{
				to_continue = false;
				result = false;
			}
		}
	}

	return result;
}


MovieEngine::Player::Frame MovieEngine::Player::VideoFrameNext(ogg_packet &arg_packet)
{
	Frame result;

	int status = th_decode_packetin(m_VideoDecCtx, &arg_packet, NULL);
	result.custom = ExtractCustomData(result.custom_size);

	if(!status)
	{
		th_decode_ycbcr_out(m_VideoDecCtx, m_YCbCrBuffer);
		
		int frame_size = m_VideoInfo.pic_height *
			m_VideoInfo.pic_width * sizeof(uint32_t);

		result.data = new char[frame_size];

		YCbCrCopy(result.data, m_YCbCrBuffer, m_VideoInfo.pic_width, m_VideoInfo.pic_height);
		
		result.index = m_VideoNextFrameIndex++;
	}
	else
	{
		result.data = NULL;
		
		if(result.custom_size)
			delete [] result.custom;
	}

	return result;
}


bool MovieEngine::Player::VideoFrameIsValid(Frame &arg_frame)
{
	return arg_frame.data != NULL;
}


void MovieEngine::Player::VideoFrameFree(Frame &arg_frame)
{
	delete [] arg_frame.data;
	
	if(arg_frame.custom_size)
		delete [] arg_frame.custom;
}


bool MovieEngine::Player::VideoFrameAddToQueue(ogg_packet &arg_packet)
{
	bool result;

	Frame frame = VideoFrameNext(arg_packet);
	if(VideoFrameIsValid(frame))
	{
		m_Frames.push(frame);
		result = true;
	}
	else
		result = false;

	return result;
}


MovieEngine::Player::StreamIt MovieEngine::Player::GetStreamByType(const Stream::Type arg_type)
{
	StreamIt result = m_Streams.end();
	
	for(StreamIt it = m_Streams.begin(); it != m_Streams.end(); ++it)
		if(it->type == arg_type)
		{
			result = it;
			break;
		}
	
	return result;
}


MovieEngine::Player::StreamIt MovieEngine::Player::GetStreamBySerial(const int arg_serial)
{
	StreamIt result = m_Streams.end();
	
	for(StreamIt it = m_Streams.begin(); it != m_Streams.end(); ++it)
		if(it->serial == arg_serial)
		{
			result = it;
			break;
		}
	
	return result;
}


int MovieEngine::Player::DataStreamDecodeHeaderIn(ogg_packet *arg_packet)
{
	int result = 0;
	
	if(!m_CustomMagic.empty() && m_CustomMagic == string(reinterpret_cast<char *>(arg_packet->packet), arg_packet->bytes))
	{
		result = 1;
	}
	
	return result;
}


char *MovieEngine::Player::ExtractCustomData(int &ret_size)
{
	char *result = NULL;
	
	StreamIt stream = GetStreamByType(Stream::T_DATA);
	
	if(stream != m_Streams.end())
	{
		ogg_packet packet;
		PopNextOggPacketBySerial(packet, stream->serial);
		
		ret_size = packet.bytes;
		result = new char[ret_size];
		memcpy(result, packet.packet, ret_size);
	}
	
	return result;
}


void MovieEngine::Player::ClearStreams()
{
	for(StreamIt it = m_Streams.begin(); it != m_Streams.end(); ++it)
		ogg_stream_clear(&it->state);
	
	m_Streams.clear();
}


void MovieEngine::Player::YCbCrCopy(void *ret_frame, const th_ycbcr_buffer arg_ycbcr_buffer, int arg_pic_width, int arg_pic_height)
{
	uint32_t *write_ptr = static_cast<uint32_t *>(ret_frame);
	for(int y = 0; y < arg_pic_height; ++y)
	{
		uint8_t *y_data = arg_ycbcr_buffer[0].data + arg_ycbcr_buffer[0].stride * y;
		int uv_step = y / 2;
		uint8_t *u_data = arg_ycbcr_buffer[1].data + arg_ycbcr_buffer[1].stride * uv_step;
		uint8_t *v_data = arg_ycbcr_buffer[2].data + arg_ycbcr_buffer[2].stride * uv_step;

		for(int x = 0; x < arg_pic_width; ++x)
		{
			int uv_offset = x / 2;
			*write_ptr++ = (y_data[x] << 16) | (u_data[uv_offset] << 8) | v_data[uv_offset];
		}
	}
}


MovieEngine::MovieEngine()
{
	SetLogPrefix("MovieEngine: ");
	
	Log("Initializing...");
	Log("Success");
	
	Ogre::Root::getSingleton().addFrameListener(this);
}


MovieEngine::~MovieEngine()
{
	Log("Destroying...");
	Log("Success");
	
	Ogre::Root::getSingleton().removeFrameListener(this);
}


void MovieEngine::PauseAll()
{
	for(list<Player *>::iterator it = m_Players.begin();
			it != m_Players.end(); ++it)
		(*it)->Pause(true);
}


void MovieEngine::ResumeAll()
{
	for(list<Player *>::iterator it = m_Players.begin();
			it != m_Players.end(); ++it)
		(*it)->Pause(false);
}


void MovieEngine::StopAll()
{
	int players_size = MovieEngine::m_Players.size();
	
	list<Player *>::iterator it = m_Players.begin();
	while(it != m_Players.end())
	{
		// we are erasing in Stop() method, so this is important
		list<Player *>::iterator jt = it++;
		(*jt)->Stop();
	}
}


void MovieEngine::Update(const int arg_delta)
{
	list<Player *>::iterator it = m_Players.begin();
	while(it != m_Players.end())
	{
		// we are erasing in Update() method, so this is important
		list<Player *>::iterator jt = it++;
		
		(*jt)->Update(arg_delta);
	}
}


bool MovieEngine::frameStarted(const Ogre::FrameEvent &evt)
{
	Update(evt.timeSinceLastFrame * 1000);
	
	return true;
}
