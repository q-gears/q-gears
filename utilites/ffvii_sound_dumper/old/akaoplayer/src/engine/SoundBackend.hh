#ifndef SOUND_BACKEND_HH__
#define SOUND_BACKEND_HH__



#include "common/typedefs.h"
#include <iostream>



class SoundBackend
{
	protected:
		static const u32 m_BUFFER_SIZE = 70560;
		static const u16 m_FREQUENCY = 44100;
		static const u8 m_CHANNELS_COUNT = 2;
	
	public:
		SoundBackend(){}
		virtual ~SoundBackend(){}

		virtual u32 GetBytesBuffered() = 0;
		virtual void FeedStreamData(u8 *arg_data, u32 arg_length) = 0;
};



#endif

