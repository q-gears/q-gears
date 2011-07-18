#include <iostream>
#include <sstream>
#include <iomanip>
#include <SDL/SDL.h>

#include "AkaoParser.hh"
#include "engine/SoundManager.h"

#include "main.hh"



int main(int argc, char *argv[])
{
	SOUNDMAN = new SoundManager();
	AKAOMAN = new AkaoParser();
	cout << setfill('0');


	AKAOMAN->LoadVoiceData("data/INSTR.ALL", "data/INSTR.DAT");
	if(argc == 2)
	{
		AKAOMAN->LoadSequenceData(argv[1]);
//		AKAOMAN->DumpSequenceData((string(argv[1]) + ".dmp").c_str());
//		exit(EXIT_SUCCESS);
		AKAOMAN->PlaySequenceData();
	}

	// if without commandline parameters
	if(argc != 2)
	{
		AKAOMAN->AerisTest();
		return 0;
	}

	uint32_t ticks;
	uint32_t previous_ticks;

	// SDL workaround
	ticks = (uint32_t)SDL_GetTicks();
#ifndef USE_MINGW
			usleep(1000);
#else
			Sleep(1000);
#endif
	ticks = (uint32_t)SDL_GetTicks();

	while(true)
	{
		previous_ticks = ticks;
		ticks = (uint32_t)SDL_GetTicks();

		AKAOMAN->Update(ticks - previous_ticks);
		uint32_t refresh_ticks;
		refresh_ticks = (uint32_t)SDL_GetTicks();
		SOUNDMAN->Update();

#ifndef USE_MINGW
			usleep(10);
#else
			Sleep(10);
#endif
	}



	delete AKAOMAN;
	delete SOUNDMAN;

	exit(EXIT_SUCCESS);
}

