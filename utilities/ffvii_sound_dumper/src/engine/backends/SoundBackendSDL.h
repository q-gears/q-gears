#ifndef SOUND_BACKEND_SDL_HH__
#define SOUND_BACKEND_SDL_HH__



#include <SDL/SDL.h>
#include "common/TypeDefine.h"

#include "../SoundBackend.h"



class SoundBackendSDL : public SoundBackend
{
	private:
		struct FillAudioContext
		{
			uint8_t *buffer;
			uint32_t buffer_size;
			uint32_t play_length;
		};

		FillAudioContext m_Context;
		friend void sound_manager_fill_audio(void *arg_user_data,
	Uint8 *arg_stream, int arg_length);

	public:
		SoundBackendSDL();
		virtual ~SoundBackendSDL();

		virtual u32 GetBytesBuffered();
		virtual void FeedStreamData(u8 *arg_data, u32 arg_length);
};



#endif

