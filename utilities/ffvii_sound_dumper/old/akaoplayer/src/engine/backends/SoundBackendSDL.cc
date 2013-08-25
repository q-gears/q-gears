#include <SDL/SDL.h>
#include "common/typedefs.h"

#include "engine/backends/SoundBackendSDL.hh"



using namespace std;



void sound_manager_fill_audio(void *arg_user_data,
	Uint8 *arg_stream, int arg_length);


SoundBackendSDL::SoundBackendSDL()
{
	// init SDL::Audio subsystem
	Uint32 initialized_subsystems = SDL_WasInit(SDL_INIT_EVERYTHING);
	int initialization_successfull;
	if(initialized_subsystems)
		if(initialized_subsystems & SDL_INIT_AUDIO)
			SDL_CloseAudio();
		else
			initialization_successfull = SDL_InitSubSystem(SDL_INIT_AUDIO);
	else
		initialization_successfull = SDL_Init(SDL_INIT_AUDIO);

	if(initialization_successfull == -1)
	{
		cout << "[SoundManager] error: " << SDL_GetError();
		exit(EXIT_FAILURE);
	}
	else
		cout << "[SoundManager] info: initialization successfull."
			<< endl;

	// set desired configuration
	SDL_AudioSpec desired_configuration;
	desired_configuration.freq = m_FREQUENCY;            // frequency
	desired_configuration.format = AUDIO_S16SYS;         // sample format
	desired_configuration.channels = m_CHANNELS_COUNT;   // channels count
	desired_configuration.samples = 512;                 // internal buffer size
	desired_configuration.callback =
		sound_manager_fill_audio;                        // callback function
	desired_configuration.userdata = (void *)&m_Context; // user data
	SDL_AudioSpec obtained_configuration;
	SDL_OpenAudio(&desired_configuration, &obtained_configuration);
	if(desired_configuration.freq != obtained_configuration.freq ||
		desired_configuration.format != obtained_configuration.format ||
		desired_configuration.channels != obtained_configuration.channels)
	{
		cout << "[SoundManager] error: obtained unsuitable configuration."
			<< endl;
		SDL_CloseAudio();
		SDL_QuitSubSystem(SDL_INIT_AUDIO);
	}

	// initialize context for callback
	m_Context.buffer_size = m_BUFFER_SIZE;
	m_Context.buffer = new uint8_t[m_Context.buffer_size];
	if(m_Context.buffer == NULL)
	{
		cout << "[SoundManager] error: out of memory." << endl;
		exit(EXIT_FAILURE);
	}

	m_Context.play_length = 0;

	SDL_PauseAudio(0);
}


SoundBackendSDL::~SoundBackendSDL()
{
	SDL_PauseAudio(1);

	SDL_CloseAudio();
	SDL_QuitSubSystem(SDL_INIT_AUDIO);
	if(!SDL_WasInit(SDL_INIT_EVERYTHING))
	{
		cout << "[SoundManager] info: exit successfull" << endl;
		SDL_Quit();
	}

	if(m_Context.buffer != NULL)
		delete [] m_Context.buffer;
}


u32 SoundBackendSDL::GetBytesBuffered()
{
	if(m_Context.play_length <
			m_Context.buffer_size / 2)
		return 0;
	else
		return m_Context.buffer_size;
}


void SoundBackendSDL::FeedStreamData(u8 *arg_data, u32 arg_length)
{
	SDL_LockAudio();

	memcpy((void *)(m_Context.buffer + m_Context.play_length),
			(const void *)arg_data, arg_length);
	m_Context.play_length += arg_length;

	SDL_UnlockAudio();
}


void sound_manager_fill_audio(void *arg_user_data,
	Uint8 *arg_stream, int arg_length)
{
	SoundBackendSDL::FillAudioContext *context =
			(SoundBackendSDL::FillAudioContext *)arg_user_data;

	if(!context->play_length)
		return;

	int play_length = arg_length < (int)context->play_length ?
			arg_length : context->play_length;

	// mix data to sdl buffer for playing
	SDL_MixAudio(arg_stream, (Uint8 *)context->buffer,
			play_length, SDL_MIX_MAXVOLUME);
	context->play_length -= play_length;

	// shift pcm data to buffer beginning
	memcpy((void *)context->buffer,
			(const void *)(context->buffer + play_length),
			context->play_length);
}

