#include <iostream>
#include <fstream>
#include <iomanip>
#include <sys/time.h>

#include "SoundManager.h"
#include "SoundBackend.hh"
#include "backends/SoundBackendSDL.hh"

#ifdef USE_MINGW
    #include <windows.h>
#endif

//#include "../../../common/Logger.h"

SoundManager *SOUNDMAN = NULL;
SoundBackend *SBE = NULL;



unsigned long RateTable[160];

// REVERB info and timing vars...
int *sRVBPlay = NULL;
int *sRVBEnd = NULL;
int *sRVBStart = NULL;
// some delay factor for reverb
int iReverbOff = -1;
int iReverbRepeat = 0;
int iReverbNum = 1;

xa_decode_t   * xapGlobal=0;

u32 * XAFeed  = NULL;
u32 * XAPlay  = NULL;
u32 * XAStart = NULL;
u32 * XAEnd   = NULL;

u32   XARepeat  = 0;
u32   XALastVal = 0;

int             iLeftXAVol  = 32767;
int             iRightXAVol = 32767;

static int gauss_ptr = 0;
static int gauss_window[8] = {0, 0, 0, 0, 0, 0, 0, 0};

#define gvall0 gauss_window[gauss_ptr]
#define gvall(x) gauss_window[(gauss_ptr+x)&3]
#define gvalr0 gauss_window[4+gauss_ptr]
#define gvalr(x) gauss_window[4+((gauss_ptr+x)&3)]

void SetupTimer();
void RemoveTimer();



const unsigned char version = 1;
const unsigned char revision = 0;
const unsigned char build = 0;

// psx buffer / addresses
unsigned short  regArea[10000];
unsigned short  spuMem[256 * 1024];
unsigned char * spuMemC;
unsigned char * pSpuIrq = 0;
unsigned char * pSpuBuffer;

// user settings
int             iUseXA = 1;
int             iVolume = 3;
int             iXAPitch = 1;
int             iUseTimer = 2;
int             iSPUIRQWait = 1;
int             iDebugMode = 0;
int             iRecordMode = 0;
int             iUseReverb = 2;
int             iUseInterpolation = 2;
//int             iDisStereo = 0;

// MAIN infos struct for each channel

// channel + 1 infos (1 is security for fmod handling)
SPUCHAN         s_chan[MAXCHAN + 1];
REVERBInfo      rvb;

// global noise generator
unsigned long   dwNoiseVal = 1;
int             iWatchDog = 0;

// some vars to store psx reg infos
unsigned short  spuCtrl = 0;
unsigned short  spuStat = 0;
unsigned short  spuIrq = 0;
// address into spu mem
unsigned long   spuAddr = 0xffffffff;

// thread handlers
int             bEndThread = 0;
int             bThreadEnded = 0;
int             bSpuInit = 0;
int             bSPUIsOpen = 0;

// flags for faster testing, if new channel starts
unsigned long dwNewChannel = 0;

// func of main emu, called on spu irq
void (*irqCallback)(void) = 0;
void (*cddavCallback)(unsigned short, unsigned short) = 0;

// certain globals (were local before, but
// with the new timeproc I need em global)

static const int f[5][2] =
{
	{  0,   0},
	{ 60,   0},
	{115, -52},
	{ 98, -55},
	{122, -60}
};

int SSumR[NSSIZE];
int SSumL[NSSIZE];
int iCycle = 0;
short * pS;

// last channel processed on spu irq in timer mode
static int lastch = -1;
// last ns pos
static int lastns = 0;
// secure start counter
static int iSecureStart = 0;



SoundManager::SoundManager()
{
	u8 *buffer;


	/* SPU initialization */
	SPUinit();
	SPUopen();



	/* base initialization of main registers */
	u16 temp;

	SPUwriteRegister(0x1f801d80, 0x0000);
	SPUwriteRegister(0x1f801d82, 0x0000);

	// H_SPUctrl
	SPUwriteRegister(0x1f801daa, 0x0000);
	SPUwriteRegister(0x1f801d80, 0x0000);
	SPUwriteRegister(0x1f801d82, 0x0000);

	// returns 0x0000
	temp = SPUreadRegister(0x1f801dae);

	SPUwriteRegister(0x1f801dac, 0x0004);

	// H_SPUvolL
	SPUwriteRegister(0x1f801d84, 0x0000);

	// H_SPUvolR
	SPUwriteRegister(0x1f801d86, 0x0000);

	// H_SPUoff1
	SPUwriteRegister(0x1f801d8c, 0xffff);

	// H_SPUoff2
	SPUwriteRegister(0x1f801d8e, 0xffff);

	// H_RVBon1
	SPUwriteRegister(0x1f801d98, 0x0000);

	// H_RVBon2
	SPUwriteRegister(0x1f801d9a, 0x0000);

	// H_Fmod1
	SPUwriteRegister(0x1f801d90, 0x0000);

	// H_Fmod2
	SPUwriteRegister(0x1f801d92, 0x0000);

	// H_Noise1
	SPUwriteRegister(0x1f801d94, 0x0000);

	// H_Noise2
	SPUwriteRegister(0x1f801d96, 0x0000);

	// H_CDLeft
	SPUwriteRegister(0x1f801db0, 0x0000);

	// H_CDRight
	SPUwriteRegister(0x1f801db2, 0x0000);

	SPUwriteRegister(0x1f801db4, 0x0000);
	SPUwriteRegister(0x1f801db6, 0x0000);

	// returns 0x0000
	temp = SPUreadRegister(0x1f801dae);

	// H_SPUaddr
	SPUwriteRegister(0x1f801da6, 0x0200);

	// H_SPUdata, hmmm... why 8 times??
	for(int i = 0; i < 8; ++i)
		SPUwriteRegister(0x1f801da8, 0x0707);

	// returns 0x0000
	temp = SPUreadRegister(0x1f801daa);

	// H_SPUctrl
	SPUwriteRegister(0x1f801daa, 0x0010);

	// returns 0x0000
	temp = SPUreadRegister(0x1f801dae);

	// returns 0x0010
	temp = SPUreadRegister(0x1f801daa);

	// H_SPUctrl
	SPUwriteRegister(0x1f801daa, 0x0000);

	// returns 0x0000
	temp = SPUreadRegister(0x1f801dae);



	/* clear channels */
	for(int i = 0; i < 24; ++i)
	{
		// left volume
		SPUwriteRegister(m_REGISTER_BASE + 16 * i + 0x00, 0x0000);
		// right volume
		SPUwriteRegister(m_REGISTER_BASE + 16 * i + 0x02, 0x0000);
		// pitch
		SPUwriteRegister(m_REGISTER_BASE + 16 * i + 0x04, 0x3fff);
		// start address
		SPUwriteRegister(m_REGISTER_BASE + 16 * i + 0x06, 0x0200);
		// level with pre-calcs
		SPUwriteRegister(m_REGISTER_BASE + 16 * i + 0x08, 0x0000);
		// adsr times with precalcs
		SPUwriteRegister(m_REGISTER_BASE + 16 * i + 0x0a, 0x0000);
	}



	/* on/off SPU channels, why?? ;) */
	// H_SPUon1
	SPUwriteRegister(0x1f801d88, 0xffff);

	// H_SPUon2
	SPUwriteRegister(0x1f801d8a, 0x00ff);

	// H_SPUoff1
	SPUwriteRegister(0x1f801d8c, 0xffff);

	// H_SPUoff2
	SPUwriteRegister(0x1f801d8e, 0x00ff);



	/* reverb initialization */
	// H_SPUctrl
	SPUwriteRegister(0x1f801daa, 0xc000);
	// H_SPUReverbAddr
	SPUwriteRegister(0x1f801da2, 0xfffe);



	/* dma transfer [sample data from INSTR.ALL] */
	// temporary writing dma dump gotten with real emu
	{
		std::ifstream iF;
		iF.open("data/dmadump.bin", std::ios_base::binary);
		u32 datasize = 483264;
		buffer = new u8[datasize];
		iF.read((char *)buffer, datasize);
		iF.close();
		if(!this->PsxWriteDMA(0x0202, buffer, datasize))
		{
			std::cout << "[SoundManager] error: failed to DMA write sample data"
				<< std::endl;
			exit(EXIT_FAILURE);
		}
		delete [] buffer;
	}



	/* another dma transfer [unknown yet] */
	// temporary writing another dma dump gotten with real emu
	{
		std::ifstream iF;
		iF.open("data/dmadump2.bin", std::ios_base::binary);
		u32 datasize = 64;
		buffer = new u8[datasize];
		iF.read((char *)buffer, datasize);
		iF.close();
		if(!this->PsxWriteDMA(0xedfc, buffer, datasize))
		{
			std::cout << "[SoundManager] error: failed to DMA write unknown data" << std::endl;
			exit(EXIT_FAILURE);
		}
		delete [] buffer;
	}



	/* CDaudio controls? */
	SPUwriteRegister(0x1f801d80, 0x3fff);
	SPUwriteRegister(0x1f801d82, 0x3fff);
	// H_CDLeft
	SPUwriteRegister(0x1f801db0, 0x7fff);
	// H_CDRight
	SPUwriteRegister(0x1f801db2, 0x7fff);
	SPUwriteRegister(0x1f801db4, 0x0000);
	SPUwriteRegister(0x1f801db6, 0x0000);



	/* here turning something important on, or clear something, me thinks... */
	// returns 0xc0000
	temp = SPUreadRegister(0x1f801daa);
	// H_SPUctrl
	SPUwriteRegister(0x1f801daa, 0xc000);
	// returns 0xc000
	temp = SPUreadRegister(0x1f801daa);
	// H_SPUctrl
	SPUwriteRegister(0x1f801daa, 0xc001);
	// returns 0xc001
	temp = SPUreadRegister(0x1f801daa);
	// H_SPUctrl
	SPUwriteRegister(0x1f801daa, 0xc001);
	// returns 0xc001
	temp = SPUreadRegister(0x1f801daa);
	// H_SPUctrl
	SPUwriteRegister(0x1f801daa, 0xc001);



	/* clear channels volume again, for safe?? (cleared before) */
	for(int i = 0; i < 24; ++i)
	{
		// left volume
		SPUwriteRegister(m_REGISTER_BASE + 16 * i + 0x00, 0x0000);
		// right volume
		SPUwriteRegister(m_REGISTER_BASE + 16 * i + 0x02, 0x0000);
	}



	/* another init ;) */
	// returns 0xc001
	temp = SPUreadRegister(0x1f801daa);
	// H_SPUctrl
	SPUwriteRegister(0x1f801daa, 0xc001);
	// returns 0xc001
	temp = SPUreadRegister(0x1f801daa);
	// H_SPUoff1
	SPUwriteRegister(0x1f801d8c, 0x0000);
	// H_SPUoff2
	SPUwriteRegister(0x1f801d8e, 0x0000);
	// returns 0x0000
	temp = SPUreadRegister(0x1f801d9a);
	// returns 0x0000
	temp = SPUreadRegister(0x1f801d98);
	// returns 0x0000
	temp = SPUreadRegister(0x1f801d98);
	// H_RVBon1
	SPUwriteRegister(0x1f801d98, 0x0000);
	// returns 0x0000
	temp = SPUreadRegister(0x1f801d9a);
	// H_RVBon2
	SPUwriteRegister(0x1f801d9a, 0x0000);
	// returns 0x0000
	temp = SPUreadRegister(0x1f801d9a);
	// returns 0x0000
	temp = SPUreadRegister(0x1f801d98);
	// returns 0x0000
	temp = SPUreadRegister(0x1f801d98);
	// H_RVBon1
	SPUwriteRegister(0x1f801d98, 0x0000);
	// returns 0x0000
	temp = SPUreadRegister(0x1f801d9a);
	// H_RVBon2
	SPUwriteRegister(0x1f801d9a, 0x0000);
	// returns 0x0000
	temp = SPUreadRegister(0x1f801d92);
	// returns 0x0000
	temp = SPUreadRegister(0x1f801d90);
	// returns 0x0000
	temp = SPUreadRegister(0x1f801d90);
	// H_FMod1
	SPUwriteRegister(0x1f801d90, 0x0000);
	// returns 0x0000
	temp = SPUreadRegister(0x1f801d92);
	// H_FMod2
	SPUwriteRegister(0x1f801d92, 0x0000);
	// returns 0x0000
	temp = SPUreadRegister(0x1f801d92);
	// returns 0x0000
	temp = SPUreadRegister(0x1f801d90);
	// returns 0x0000
	temp = SPUreadRegister(0x1f801d90);
	// H_FMod1
	SPUwriteRegister(0x1f801d90, 0x0000);
	// returns 0x0000
	temp = SPUreadRegister(0x1f801d92);
	// H_FMod2
	SPUwriteRegister(0x1f801d92, 0x0000);
	// returns 0x0000
	temp = SPUreadRegister(0x1f801d96);
	// returns 0x0000
	temp = SPUreadRegister(0x1f801d94);
	// returns 0x0000
	temp = SPUreadRegister(0x1f801d94);
	// H_Noise1
	SPUwriteRegister(0x1f801d94, 0x0000);
	// returns 0x0000
	temp = SPUreadRegister(0x1f801d96);
	// H_Noise2
	SPUwriteRegister(0x1f801d96, 0x0000);
	// returns 0x0000
	temp = SPUreadRegister(0x1f801d96);
	// returns 0x0000
	temp = SPUreadRegister(0x1f801d94);
	// returns 0x0000
	temp = SPUreadRegister(0x1f801d94);
	// H_Noise1
	SPUwriteRegister(0x1f801d94, 0x0000);
	// returns 0x0000
	temp = SPUreadRegister(0x1f801d96);
	// H_Noise2
	SPUwriteRegister(0x1f801d96, 0x0000);
	// returns 0xc001
	temp = SPUreadRegister(0x1f801daa);
	// H_SPUctrl
	SPUwriteRegister(0x1f801daa, 0xc001);
	// returns 0xc001
	temp = SPUreadRegister(0x1f801daa);
	// H_SPUrvolL
	SPUwriteRegister(0x1f801d84, 0x0000);
	// H_SPUrvolR
	SPUwriteRegister(0x1f801d86, 0x0000);



	/* set reverb parameters?? */
	// H_Reverb
	SPUwriteRegister(0x1f801dc0, 0x00e3);
	SPUwriteRegister(0x1f801dc2, 0x00a9);
	SPUwriteRegister(0x1f801dc4, 0x6f60);
	SPUwriteRegister(0x1f801dc6, 0x4fa8);
	SPUwriteRegister(0x1f801dc8, 0xbce0);
	SPUwriteRegister(0x1f801dca, 0x4510);
	SPUwriteRegister(0x1f801dcc, 0xbef0);
	SPUwriteRegister(0x1f801dce, 0xa680);
	SPUwriteRegister(0x1f801dd0, 0x5680);
	SPUwriteRegister(0x1f801dd2, 0x52c0);
	SPUwriteRegister(0x1f801dd4, 0x0dfb);
	SPUwriteRegister(0x1f801dd6, 0x0b58);
	SPUwriteRegister(0x1f801dd8, 0x0d09);
	SPUwriteRegister(0x1f801dda, 0x0a3c);
	SPUwriteRegister(0x1f801ddc, 0x0bd9);
	SPUwriteRegister(0x1f801dde, 0x0973);
	SPUwriteRegister(0x1f801de0, 0x0b59);
	SPUwriteRegister(0x1f801de2, 0x08da);
	SPUwriteRegister(0x1f801de4, 0x08d9);
	SPUwriteRegister(0x1f801de6, 0x05e9);
	SPUwriteRegister(0x1f801de8, 0x07ec);
	SPUwriteRegister(0x1f801dea, 0x04b0);
	SPUwriteRegister(0x1f801dec, 0x06ef);
	SPUwriteRegister(0x1f801dee, 0x03d2);
	SPUwriteRegister(0x1f801df0, 0x05ea);
	SPUwriteRegister(0x1f801df2, 0x031d);
	SPUwriteRegister(0x1f801df4, 0x031c);
	SPUwriteRegister(0x1f801df6, 0x0238);
	SPUwriteRegister(0x1f801df8, 0x0154);
	SPUwriteRegister(0x1f801dfa, 0x00aa);
	SPUwriteRegister(0x1f801dfc, 0x8000);
	SPUwriteRegister(0x1f801dfe, 0x8000);



	/* and finishing dma transfer of zeroes :), phew */
	{
		u32 datasize = 1024;
		u8 *buffer = new u8[datasize];
		memset((void *)buffer, 0x00, datasize);
		for(int i = 0; i < 28; ++i)
		{
			if(!this->PsxWriteDMA(0xf204 + 128 * i, buffer, datasize))
			{
				std::cout << "[SoundManager] error: failed to DMA write 0x00 data" << std::endl;
				exit(EXIT_FAILURE);
			}
		}
		delete [] buffer;
	}



	/* last init */
	// H_SPUReverbAddr
	SPUwriteRegister(0x1f801da2, 0xf204);
	// returns 0xc001
	temp = SPUreadRegister(0x1f801daa);
	// H_SPUctrl
	SPUwriteRegister(0x1f801daa, 0xc081);
	// returns 0x0000
	temp = SPUreadRegister(0x1f801d96);
	// returns 0x0000
	temp = SPUreadRegister(0x1f801d94);
	// returns 0x0000
	temp = SPUreadRegister(0x1f801d94);
	// H_Noise1
	SPUwriteRegister(0x1f801d94, 0x0000);
	// returns 0x0000
	temp = SPUreadRegister(0x1f801d96);
	// H_Noise2
	SPUwriteRegister(0x1f801d96, 0x0000);
	// returns 0x0000
	temp = SPUreadRegister(0x1f801d96);
	// returns 0x0000
	temp = SPUreadRegister(0x1f801d94);
	// returns 0x0000
	temp = SPUreadRegister(0x1f801d94);
	// H_Noise1
	SPUwriteRegister(0x1f801d94, 0x0000);
	// returns 0x0000
	temp = SPUreadRegister(0x1f801d96);
	// H_Noise2
	SPUwriteRegister(0x1f801d96, 0x0000);
	// returns 0x0000
	temp = SPUreadRegister(0x1f801d9a);
	// returns 0x0000
	temp = SPUreadRegister(0x1f801d98);
	// returns 0x0000
	temp = SPUreadRegister(0x1f801d98);
	// H_RVBon1
	SPUwriteRegister(0x1f801d98, 0x0000);
	// returns 0x0000
	temp = SPUreadRegister(0x1f801d9a);
	// H_RVBon2
	SPUwriteRegister(0x1f801d9a, 0x0000);
	// returns 0x0000
	temp = SPUreadRegister(0x1f801d9a);
	// returns 0x0000
	temp = SPUreadRegister(0x1f801d98);
	// returns 0x0000
	temp = SPUreadRegister(0x1f801d98);
	// H_RVBon1
	SPUwriteRegister(0x1f801d98, 0x0000);
	// returns 0x0000
	temp = SPUreadRegister(0x1f801d9a);
	// H_RVBon2
	SPUwriteRegister(0x1f801d9a, 0x0000);
	// returns 0x0000
	temp = SPUreadRegister(0x1f801d92);
	// returns 0x0000
	temp = SPUreadRegister(0x1f801d90);
	// returns 0x0000
	temp = SPUreadRegister(0x1f801d90);
	// H_FMod1
	SPUwriteRegister(0x1f801d90, 0x0000);
	// returns 0x0000
	temp = SPUreadRegister(0x1f801d92);
	// H_FMod2
	SPUwriteRegister(0x1f801d92, 0x0000);
	// returns 0x0000
	temp = SPUreadRegister(0x1f801d92);
	// returns 0x0000
	temp = SPUreadRegister(0x1f801d90);
	// returns 0x0000
	temp = SPUreadRegister(0x1f801d90);
	// H_FMod1
	SPUwriteRegister(0x1f801d90, 0x0000);
	// returns 0x0000
	temp = SPUreadRegister(0x1f801d92);
	// H_FMod2
	SPUwriteRegister(0x1f801d92, 0x0000);
	// H_SPUoff1
	SPUwriteRegister(0x1f801d8c, 0xffff);
	// H_SPUoff2
	SPUwriteRegister(0x1f801d8e, 0x00ff);
}


bool SoundManager::PsxWriteDMA(u16 arg_address, u8 *arg_data, u32 arg_length)
{
	u16 temp;

	// write and verify destination address
	SPUwriteRegister(0x1f801da6, arg_address);
	if(SPUreadRegister(0x1f801da6) != arg_address)
		return false;

	// set and verify dma operation
	temp = SPUreadRegister(0x1f801daa);
	temp |= 32;
	SPUwriteRegister(0x1f801daa, temp);
	if(SPUreadRegister(0x1f801daa) != temp)
		return false;

	SPUwriteDMAMem((unsigned short *)arg_data, arg_length / 2);

	// clear and verify dma operation
	temp = SPUreadRegister(0x1f801daa);
	temp &= ~32;
	SPUwriteRegister(0x1f801daa, temp);
	if(SPUreadRegister(0x1f801daa) != temp)
		return false;

	return true;
}


SoundManager::~SoundManager()
{
    // close SPU
    SPUclose();
}



void SoundManager::Update()
{
    SPUasync(0xc000);
}


void SoundManager::PsxInstrumentSetReverbDepth(u8 arg_channel,
	u16 arg_left, u16 arg_right)
{
	SPUwriteRegister(0x1f801d84, arg_left);
	SPUwriteRegister(0x1f801d86, arg_right);
}


void SoundManager::PsxChannelPlay(u8 arg_channel)
{
	if(arg_channel < 16)
		// H_SPUon1
		SPUwriteRegister(0x1f801d88, 1 << arg_channel);
	else if(arg_channel >= 16 && arg_channel < 24)
		// H_SPUon2
		SPUwriteRegister(0x1f801d8a, 1 << (arg_channel - 16));
	else
	{
		std::cout << "[SoundManager] error: unknown channel ON" << std::endl;
		exit(EXIT_FAILURE);
	}
}


void SoundManager::PsxReverbOn(u8 arg_channel)
{
	if(arg_channel < 16)
		// H_RVBon1
		SPUwriteRegister(0x1f801d98, 1 << arg_channel);
	else if(arg_channel >= 16 && arg_channel < 24)
		// H_RVBon2
		SPUwriteRegister(0x1f801d9a, 1 << (arg_channel - 16));
	else
	{
		std::cout << "[SoundManager] error: unknown channel REVERB" << std::endl;
		exit(EXIT_FAILURE);
	}
}


void SoundManager::PsxChannelStop(u8 arg_channel)
{
	if(arg_channel < 16)
		// H_SPUoff1
		SPUwriteRegister(0x1f801d8c, 1 << arg_channel);
	else if(arg_channel >= 16 && arg_channel < 24)
		// H_SPUoff2
		SPUwriteRegister(0x1f801d8e, 1 << (arg_channel - 16));
	else
	{
		std::cout << "[SoundManager] error: unknown channel OFF" << std::endl;
		exit(EXIT_FAILURE);
	}
}


// +++
void SoundManager::SetVoiceStartAddress(u8 arg_voice, u32 arg_address)
{
		std::cout << "Set voice start" << std::endl;
    //LOGGER->Log( "Set voice start" );

	if(arg_voice >= 0x18)
	{
		std::cout << "*** error: wrong channel!" << std::endl;
		return;
	}

	// if address isn't divisible by 8, it's
	// increased to the next value divisible by 8
	if(arg_address % 8)
	{
		arg_address += 8;
		arg_address &= ~7;
	}

	SPUwriteRegister(m_PSX_SPU_BASE + arg_voice * 0x10 + 0x06, (u16)(arg_address / 8));
}


// +++
void SoundManager::SetVoiceLoopAddress(u8 arg_voice, u32 arg_address)
{
	if(arg_voice >= 0x18)
	{
		std::cout << "*** error: wrong channel!" << std::endl;
		return;
	}

	// if address isn't divisible by 8, it's
	// increased to the next value divisible by 8
	if(arg_address % 8)
	{
		arg_address += 8;
		arg_address &= ~7;
	}

	SPUwriteRegister(m_PSX_SPU_BASE + arg_voice * 0x10 + 0x0e, (u16)(arg_address / 8));
}


// +++
void SoundManager::SetVoiceVolume(u8 arg_voice,
		s16 arg_volume_left, s16 arg_volume_right)
{
	if(arg_voice >= 0x18)
	{
		std::cout << "*** error: wrong channel!" << std::endl;
		return;
	}

	SPUwriteRegister(m_PSX_SPU_BASE + arg_voice * 0x10 + 0x00,
			arg_volume_left & 0x7fff);
	SPUwriteRegister(m_PSX_SPU_BASE + arg_voice * 0x10 + 0x02,
			arg_volume_right & 0x7fff);
}


// +++
void SoundManager::SetVoicePitch(u8 arg_voice, u16 arg_pitch)
{
	if(arg_voice >= 0x18)
	{
		std::cout << "*** error: wrong channel!" << std::endl;
		return;
	}

	if(arg_pitch >= 0x4000)
	{
		std::cout << "*** error: wrong pitch!" << std::endl;
		return;
	}

	SPUwriteRegister(m_PSX_SPU_BASE + arg_voice * 0x10 + 0x04, arg_pitch);
}


// +++
void SoundManager::SetVoiceAttackRate(u8 arg_voice,
		u16 arg_rate, SpuRateMode arg_mode)
{
	if(arg_voice >= 0x18)
	{
		std::cout << "*** error: wrong channel!" << std::endl;
		return;
	}

	if(arg_rate >= 0x80)
	{
		std::cout << "*** error: wrong attack rate!" << std::endl;
		return;
	}

	u16 value = (arg_mode == SPU_VOICE_EXPIncN) ? (1 << 7) : 0;
	value |= arg_rate;
	value <<= 8;

	u16 temp = SPUreadRegister(m_PSX_SPU_BASE + arg_voice * 0x10 + 0x08) & 0xFF;
	temp |= value;
	SPUwriteRegister(m_PSX_SPU_BASE + arg_voice * 0x10 + 0x08, temp);
}


// +++
void SoundManager::SetVoiceSustainRate(u8 arg_voice,
		u16 arg_rate, SpuRateMode arg_mode)
{
	if(arg_voice >= 0x18)
	{
		std::cout << "*** error: wrong channel!" << std::endl;
		return;
	}

	if(arg_rate >= 0x80)
	{
		std::cout << "*** error: wrong sustain rate!" << std::endl;
		return;
	}

	u16 value;
	switch(arg_mode)
	{
		case SPU_VOICE_EXPIncN:
			value = 0x200;
			break;

		case SPU_VOICE_LINEARDecN:
			value = 0x100;
			break;

		case SPU_VOICE_EXPDec:
			value = 0x300;
			break;

		default:
		std::cout << "*** error: wrong sustain rate mode!" << std::endl;
		case SPU_VOICE_LINEARIncN:
			value = 0x000;
			break;
	}

	u16 temp = SPUreadRegister(m_PSX_SPU_BASE + arg_voice * 0x10 + 0x0a) & 0x3F;
	temp |= (arg_rate | value) << 6;
	SPUwriteRegister(m_PSX_SPU_BASE + arg_voice * 0x10 + 0x0a, temp);
}


// +++
void SoundManager::SetVoiceReleaseRate(u8 arg_voice,
		u16 arg_rate, SpuRateMode arg_mode)
{
	if(arg_voice >= 0x18)
	{
		std::cout << "*** error: wrong channel!" << std::endl;
		return;
	}

	if(arg_rate >= 0x20)
	{
		std::cout << "*** error: wrong release rate!" << std::endl;
		return;
	}

	u16 value = (arg_mode == SPU_VOICE_EXPDec) ? (1 << 5) : 0;
	value |= arg_rate;

	u16 temp = SPUreadRegister(m_PSX_SPU_BASE + arg_voice * 0x10 + 0x0a)
		& 0xFFC0;
	temp |= value;
	SPUwriteRegister(m_PSX_SPU_BASE + arg_voice * 0x10 + 0x0a, temp);
}


// +++
void SoundManager::SetVoiceDecayRate(u8 arg_voice, u16 arg_rate)
{
	if(arg_voice >= 0x18)
	{
		std::cout << "*** error: wrong channel!" << std::endl;
		return;
	}

	if(arg_rate >= 0x10)
	{
		std::cout << "*** error: wrong decay rate!" << std::endl;
		return;
	}

	u16 temp = SPUreadRegister(m_PSX_SPU_BASE + arg_voice * 0x10 + 0x08)
		& 0xFF0F;
	temp |= arg_rate << 4;
	SPUwriteRegister(m_PSX_SPU_BASE + arg_voice * 0x10 + 0x08, temp);
}


// +++
void SoundManager::SetVoiceSustainLevel(u8 arg_voice, u16 arg_level)
{
	if(arg_voice >= 0x18)
	{
		std::cout << "*** error: wrong channel!" << std::endl;
		return;
	}

	if(arg_level >= 0x10)
	{
		std::cout << "*** error: wrong sustain level!" << std::endl;
		return;
	}

	u16 temp = SPUreadRegister(m_PSX_SPU_BASE + arg_voice * 0x10 + 0x08)
		& 0xFFF0;
	temp |= arg_level;
	SPUwriteRegister(m_PSX_SPU_BASE + arg_voice * 0x10 + 0x08, temp);
}


void InitADSR()
{
	unsigned long r = 3;
	unsigned long rs = 1;
	unsigned long rd = 0;
	int i;

	// build the rate table according to Neill's rules
	memset(RateTable, 0, sizeof(unsigned long) * 160);

	// we start at pos 32 with the real values... everything before is 0
	for(i = 32; i < 160; i++)
	{
		if(r < 0x3FFFFFFF)
		{
			r += rs;
			rd++;
			if(rd == 5)
			{
				rd = 1;
				rs *= 2;
			}
		}
		if(r > 0x3FFFFFFF)
			r = 0x3FFFFFFF;

		RateTable[i] = r;
	}
}


void StartADSR(int ch)
{
	s_chan[ch].ADSRX.lVolume = 1;
	s_chan[ch].ADSRX.State = 0;
	s_chan[ch].ADSRX.EnvelopeVol = 0;
}


int MixADSR(int ch)
{
	// channel stopped
	if(s_chan[ch].bStop)
	{
		// release
		if(s_chan[ch].ADSRX.ReleaseModeExp)
		{
			switch((s_chan[ch].ADSRX.EnvelopeVol >> 28) & 0x07)
			{
				case 0:
					s_chan[ch].ADSRX.EnvelopeVol -= RateTable[(4 *
						(s_chan[ch].ADSRX.ReleaseRate^0x1F)) - 0x18 + 0 + 32];
					break;

				case 1:
					s_chan[ch].ADSRX.EnvelopeVol -= RateTable[(4 *
						(s_chan[ch].ADSRX.ReleaseRate^0x1F)) - 0x18 + 4 + 32];
					break;

				case 2:
					s_chan[ch].ADSRX.EnvelopeVol -= RateTable[(4 *
						(s_chan[ch].ADSRX.ReleaseRate^0x1F)) - 0x18 + 6 + 32];
					break;

				case 3:
					s_chan[ch].ADSRX.EnvelopeVol -= RateTable[(4 *
						(s_chan[ch].ADSRX.ReleaseRate^0x1F)) - 0x18 + 8 + 32];
					break;

				case 4:
					s_chan[ch].ADSRX.EnvelopeVol -= RateTable[(4 *
						(s_chan[ch].ADSRX.ReleaseRate^0x1F)) - 0x18 + 9 + 32];
					break;

				case 5:
					s_chan[ch].ADSRX.EnvelopeVol -= RateTable[(4 *
						(s_chan[ch].ADSRX.ReleaseRate^0x1F)) - 0x18 + 10 + 32];
					break;

				case 6:
					s_chan[ch].ADSRX.EnvelopeVol -= RateTable[(4 *
						(s_chan[ch].ADSRX.ReleaseRate^0x1F)) - 0x18 + 11 + 32];
					break;

				case 7:
					s_chan[ch].ADSRX.EnvelopeVol -= RateTable[(4 *
						(s_chan[ch].ADSRX.ReleaseRate^0x1F)) - 0x18 + 12 + 32];
					break;
			}
		}
		else
			s_chan[ch].ADSRX.EnvelopeVol -= RateTable[(4 *
				(s_chan[ch].ADSRX.ReleaseRate^0x1F)) - 0x0C + 32];

		if(s_chan[ch].ADSRX.EnvelopeVol < 0)
		{
			s_chan[ch].ADSRX.EnvelopeVol = 0;
			s_chan[ch].bOn = 0;
		}

		s_chan[ch].ADSRX.lVolume = s_chan[ch].ADSRX.EnvelopeVol >> 21;

		return s_chan[ch].ADSRX.lVolume;
	}

	// channel not stopped
	else
	{
		// attack
		if(s_chan[ch].ADSRX.State == 0)
		{
			if(s_chan[ch].ADSRX.AttackModeExp)
			{
				if(s_chan[ch].ADSRX.EnvelopeVol < 0x60000000)
					s_chan[ch].ADSRX.EnvelopeVol += RateTable[
						(s_chan[ch].ADSRX.AttackRate^0x7F) - 0x10 + 32];
				else
					s_chan[ch].ADSRX.EnvelopeVol += RateTable[
						(s_chan[ch].ADSRX.AttackRate^0x7F) - 0x18 + 32];
			}
			else
				s_chan[ch].ADSRX.EnvelopeVol += RateTable[
					(s_chan[ch].ADSRX.AttackRate^0x7F) - 0x10 + 32];

			if(s_chan[ch].ADSRX.EnvelopeVol < 0)
			{
				s_chan[ch].ADSRX.EnvelopeVol = 0x7FFFFFFF;
				s_chan[ch].ADSRX.State = 1;
			}

			s_chan[ch].ADSRX.lVolume = s_chan[ch].ADSRX.EnvelopeVol >> 21;
			return s_chan[ch].ADSRX.lVolume;
		}

		// decay
		if(s_chan[ch].ADSRX.State == 1)
		{
			switch((s_chan[ch].ADSRX.EnvelopeVol >> 28) & 0x07)
			{
				case 0:
					s_chan[ch].ADSRX.EnvelopeVol -= RateTable[(4 *
						(s_chan[ch].ADSRX.DecayRate^0x1F)) - 0x18 + 0 + 32];
					break;

				case 1:
					s_chan[ch].ADSRX.EnvelopeVol -= RateTable[(4 *
						(s_chan[ch].ADSRX.DecayRate^0x1F)) - 0x18 + 4 + 32];
					break;

				case 2:
					s_chan[ch].ADSRX.EnvelopeVol -= RateTable[(4 *
						(s_chan[ch].ADSRX.DecayRate^0x1F)) - 0x18 + 6 + 32];
					break;

				case 3:
					s_chan[ch].ADSRX.EnvelopeVol -= RateTable[(4 *
						(s_chan[ch].ADSRX.DecayRate^0x1F)) - 0x18 + 8 + 32];
					break;

				case 4:
					s_chan[ch].ADSRX.EnvelopeVol -= RateTable[(4 *
						(s_chan[ch].ADSRX.DecayRate^0x1F)) - 0x18 + 9 + 32];
					break;

				case 5:
					s_chan[ch].ADSRX.EnvelopeVol -= RateTable[(4 *
						(s_chan[ch].ADSRX.DecayRate^0x1F)) - 0x18 + 10 + 32];
					break;

				case 6:
					s_chan[ch].ADSRX.EnvelopeVol -= RateTable[(4 *
						(s_chan[ch].ADSRX.DecayRate^0x1F)) - 0x18 + 11 + 32];
					break;

				case 7:
					s_chan[ch].ADSRX.EnvelopeVol -= RateTable[(4 *
						(s_chan[ch].ADSRX.DecayRate^0x1F)) - 0x18 + 12 + 32];
					break;
			}

			if(s_chan[ch].ADSRX.EnvelopeVol < 0)
				s_chan[ch].ADSRX.EnvelopeVol = 0;

			if(((s_chan[ch].ADSRX.EnvelopeVol >> 27) & 0xF) <=
					s_chan[ch].ADSRX.SustainLevel)
				s_chan[ch].ADSRX.State = 2;

			s_chan[ch].ADSRX.lVolume = s_chan[ch].ADSRX.EnvelopeVol >> 21;
			return s_chan[ch].ADSRX.lVolume;
		}

		// sustain
		if(s_chan[ch].ADSRX.State == 2)
		{
			if(s_chan[ch].ADSRX.SustainIncrease)
			{
				if(s_chan[ch].ADSRX.SustainModeExp)
				{
					if(s_chan[ch].ADSRX.EnvelopeVol < 0x60000000)
						s_chan[ch].ADSRX.EnvelopeVol += RateTable[
							(s_chan[ch].ADSRX.SustainRate^0x7F) - 0x10 + 32];
					else
						s_chan[ch].ADSRX.EnvelopeVol += RateTable[
							(s_chan[ch].ADSRX.SustainRate^0x7F) - 0x18 + 32];
				}
				else
					s_chan[ch].ADSRX.EnvelopeVol += RateTable[
						(s_chan[ch].ADSRX.SustainRate^0x7F) - 0x10 + 32];

				if(s_chan[ch].ADSRX.EnvelopeVol < 0)
					s_chan[ch].ADSRX.EnvelopeVol = 0x7FFFFFFF;
			}
			else
			{
				if(s_chan[ch].ADSRX.SustainModeExp)
				{
					switch((s_chan[ch].ADSRX.EnvelopeVol >> 28) & 0x7)
					{
						case 0:
							s_chan[ch].ADSRX.EnvelopeVol -= RateTable[
								((s_chan[ch].ADSRX.SustainRate^0x7F))
								- 0x1B + 0 + 32];
							break;

						case 1:
							s_chan[ch].ADSRX.EnvelopeVol -= RateTable[
								((s_chan[ch].ADSRX.SustainRate^0x7F))
								- 0x1B + 4 + 32];
							break;

						case 2:
							s_chan[ch].ADSRX.EnvelopeVol -= RateTable[
								((s_chan[ch].ADSRX.SustainRate^0x7F))
								- 0x1B + 6 + 32];
							break;

						case 3:
							s_chan[ch].ADSRX.EnvelopeVol -= RateTable[
								((s_chan[ch].ADSRX.SustainRate^0x7F))
								- 0x1B + 8 + 32];
							break;

						case 4:
							s_chan[ch].ADSRX.EnvelopeVol -= RateTable[
								((s_chan[ch].ADSRX.SustainRate^0x7F))
								- 0x1B + 9 + 32];
							break;

						case 5:
							s_chan[ch].ADSRX.EnvelopeVol -= RateTable[
								((s_chan[ch].ADSRX.SustainRate^0x7F))
								- 0x1B + 10 + 32];
							break;

						case 6:
							s_chan[ch].ADSRX.EnvelopeVol -= RateTable[
								((s_chan[ch].ADSRX.SustainRate^0x7F))
								- 0x1B + 11 + 32];
							break;

						case 7:
							s_chan[ch].ADSRX.EnvelopeVol -= RateTable[
								((s_chan[ch].ADSRX.SustainRate^0x7F))
								- 0x1B + 12 + 32];
							break;
					}
				}
				else
					s_chan[ch].ADSRX.EnvelopeVol -= RateTable[
						((s_chan[ch].ADSRX.SustainRate^0x7F)) - 0x0F + 32];

				if(s_chan[ch].ADSRX.EnvelopeVol < 0)
					s_chan[ch].ADSRX.EnvelopeVol = 0;
			}

			s_chan[ch].ADSRX.lVolume = s_chan[ch].ADSRX.EnvelopeVol >> 21;
			return s_chan[ch].ADSRX.lVolume;
		}
	}

	return 0;
}

unsigned short SPUreadDMA()
{
#ifdef DEBUG_OUTPUT
	std::cout << "SPUreadDMA()" << std::endl;
#endif

	unsigned short s = spuMem[spuAddr >> 1];
	spuAddr += 2;
	if(spuAddr > 0x7ffff)
		spuAddr = 0;

	iWatchDog = 0;

	return s;
}


void SPUreadDMAMem(unsigned short *pusPSXMem, int iSize)
{
#ifdef DEBUG_OUTPUT
	std::cout << "SPUreadDMAMem()" << std::endl;
#endif

	int i;

	for(i = 0; i < iSize; i++)
	{
		// spu addr got by writeregister
		*pusPSXMem++ = spuMem[spuAddr >> 1];
		// inc spu addr
		spuAddr += 2;
		// wrap
		if(spuAddr > 0x7ffff)
			spuAddr = 0;
	}

	iWatchDog = 0;
}


// to investigate: do sound data updates by writedma affect spu
// irqs? Will an irq be triggered, if new data is written to
// the memory irq address?

void SPUwriteDMA(unsigned short val)
{
#ifdef DEBUG_OUTPUT
	std::cout << "SPUwriteDMA()" << std::endl;
#endif

	// spu addr got by writeregister
	spuMem[spuAddr >> 1] = val;

	// inc spu addr
	spuAddr += 2;
	// wrap
	if(spuAddr > 0x7ffff)
		spuAddr = 0;

	iWatchDog = 0;
}



void SPUwriteDMAMem(unsigned short *pusPSXMem, int iSize)
{
    int i;

    for ( i = 0; i < iSize; i++ )
    {
        // spu addr got by writeregister
        spuMem[spuAddr >> 1] = *pusPSXMem++;
        // inc spu addr
        spuAddr += 2;
        // wrap
        if(spuAddr > 0x7ffff)
        {
            spuAddr = 0;
        }
    }

    iWatchDog = 0;
}


const int gauss[] =
{
	0x172, 0x519, 0x176, 0x000, 0x16E, 0x519, 0x17A, 0x000,
	0x16A, 0x518, 0x17D, 0x000, 0x166, 0x518, 0x181, 0x000,
	0x162, 0x518, 0x185, 0x000, 0x15F, 0x518, 0x189, 0x000,
	0x15B, 0x518, 0x18D, 0x000, 0x157, 0x517, 0x191, 0x000,
	0x153, 0x517, 0x195, 0x000, 0x150, 0x517, 0x19A, 0x000,
	0x14C, 0x516, 0x19E, 0x000, 0x148, 0x516, 0x1A2, 0x000,
	0x145, 0x515, 0x1A6, 0x000, 0x141, 0x514, 0x1AA, 0x000,
	0x13E, 0x514, 0x1AE, 0x000, 0x13A, 0x513, 0x1B2, 0x000,
	0x137, 0x512, 0x1B7, 0x001, 0x133, 0x511, 0x1BB, 0x001,
	0x130, 0x511, 0x1BF, 0x001, 0x12C, 0x510, 0x1C3, 0x001,
	0x129, 0x50F, 0x1C8, 0x001, 0x125, 0x50E, 0x1CC, 0x001,
	0x122, 0x50D, 0x1D0, 0x001, 0x11E, 0x50C, 0x1D5, 0x001,
	0x11B, 0x50B, 0x1D9, 0x001, 0x118, 0x50A, 0x1DD, 0x001,
	0x114, 0x508, 0x1E2, 0x001, 0x111, 0x507, 0x1E6, 0x002,
	0x10E, 0x506, 0x1EB, 0x002, 0x10B, 0x504, 0x1EF, 0x002,
	0x107, 0x503, 0x1F3, 0x002, 0x104, 0x502, 0x1F8, 0x002,
	0x101, 0x500, 0x1FC, 0x002, 0x0FE, 0x4FF, 0x201, 0x002,
	0x0FB, 0x4FD, 0x205, 0x003, 0x0F8, 0x4FB, 0x20A, 0x003,
	0x0F5, 0x4FA, 0x20F, 0x003, 0x0F2, 0x4F8, 0x213, 0x003,
	0x0EF, 0x4F6, 0x218, 0x003, 0x0EC, 0x4F5, 0x21C, 0x004,
	0x0E9, 0x4F3, 0x221, 0x004, 0x0E6, 0x4F1, 0x226, 0x004,
	0x0E3, 0x4EF, 0x22A, 0x004, 0x0E0, 0x4ED, 0x22F, 0x004,
	0x0DD, 0x4EB, 0x233, 0x005, 0x0DA, 0x4E9, 0x238, 0x005,
	0x0D7, 0x4E7, 0x23D, 0x005, 0x0D4, 0x4E5, 0x241, 0x005,
	0x0D2, 0x4E3, 0x246, 0x006, 0x0CF, 0x4E0, 0x24B, 0x006,
	0x0CC, 0x4DE, 0x250, 0x006, 0x0C9, 0x4DC, 0x254, 0x006,
	0x0C7, 0x4D9, 0x259, 0x007, 0x0C4, 0x4D7, 0x25E, 0x007,
	0x0C1, 0x4D5, 0x263, 0x007, 0x0BF, 0x4D2, 0x267, 0x008,
	0x0BC, 0x4D0, 0x26C, 0x008, 0x0BA, 0x4CD, 0x271, 0x008,
	0x0B7, 0x4CB, 0x276, 0x009, 0x0B4, 0x4C8, 0x27B, 0x009,
	0x0B2, 0x4C5, 0x280, 0x009, 0x0AF, 0x4C3, 0x284, 0x00A,
	0x0AD, 0x4C0, 0x289, 0x00A, 0x0AB, 0x4BD, 0x28E, 0x00A,
	0x0A8, 0x4BA, 0x293, 0x00B, 0x0A6, 0x4B7, 0x298, 0x00B,
	0x0A3, 0x4B5, 0x29D, 0x00B, 0x0A1, 0x4B2, 0x2A2, 0x00C,
	0x09F, 0x4AF, 0x2A6, 0x00C, 0x09C, 0x4AC, 0x2AB, 0x00D,
	0x09A, 0x4A9, 0x2B0, 0x00D, 0x098, 0x4A6, 0x2B5, 0x00E,
	0x096, 0x4A2, 0x2BA, 0x00E, 0x093, 0x49F, 0x2BF, 0x00F,
	0x091, 0x49C, 0x2C4, 0x00F, 0x08F, 0x499, 0x2C9, 0x00F,
	0x08D, 0x496, 0x2CE, 0x010, 0x08B, 0x492, 0x2D3, 0x010,
	0x089, 0x48F, 0x2D8, 0x011, 0x086, 0x48C, 0x2DC, 0x011,
	0x084, 0x488, 0x2E1, 0x012, 0x082, 0x485, 0x2E6, 0x013,
	0x080, 0x481, 0x2EB, 0x013, 0x07E, 0x47E, 0x2F0, 0x014,
	0x07C, 0x47A, 0x2F5, 0x014, 0x07A, 0x477, 0x2FA, 0x015,
	0x078, 0x473, 0x2FF, 0x015, 0x076, 0x470, 0x304, 0x016,
	0x075, 0x46C, 0x309, 0x017, 0x073, 0x468, 0x30E, 0x017,
	0x071, 0x465, 0x313, 0x018, 0x06F, 0x461, 0x318, 0x018,
	0x06D, 0x45D, 0x31D, 0x019, 0x06B, 0x459, 0x322, 0x01A,
	0x06A, 0x455, 0x326, 0x01B, 0x068, 0x452, 0x32B, 0x01B,
	0x066, 0x44E, 0x330, 0x01C, 0x064, 0x44A, 0x335, 0x01D,
	0x063, 0x446, 0x33A, 0x01D, 0x061, 0x442, 0x33F, 0x01E,
	0x05F, 0x43E, 0x344, 0x01F, 0x05E, 0x43A, 0x349, 0x020,
	0x05C, 0x436, 0x34E, 0x020, 0x05A, 0x432, 0x353, 0x021,
	0x059, 0x42E, 0x357, 0x022, 0x057, 0x42A, 0x35C, 0x023,
	0x056, 0x425, 0x361, 0x024, 0x054, 0x421, 0x366, 0x024,
	0x053, 0x41D, 0x36B, 0x025, 0x051, 0x419, 0x370, 0x026,
	0x050, 0x415, 0x374, 0x027, 0x04E, 0x410, 0x379, 0x028,
	0x04D, 0x40C, 0x37E, 0x029, 0x04C, 0x408, 0x383, 0x02A,
	0x04A, 0x403, 0x388, 0x02B, 0x049, 0x3FF, 0x38C, 0x02C,
	0x047, 0x3FB, 0x391, 0x02D, 0x046, 0x3F6, 0x396, 0x02E,
	0x045, 0x3F2, 0x39B, 0x02F, 0x043, 0x3ED, 0x39F, 0x030,
	0x042, 0x3E9, 0x3A4, 0x031, 0x041, 0x3E5, 0x3A9, 0x032,
	0x040, 0x3E0, 0x3AD, 0x033, 0x03E, 0x3DC, 0x3B2, 0x034,
	0x03D, 0x3D7, 0x3B7, 0x035, 0x03C, 0x3D2, 0x3BB, 0x036,
	0x03B, 0x3CE, 0x3C0, 0x037, 0x03A, 0x3C9, 0x3C5, 0x038,
	0x038, 0x3C5, 0x3C9, 0x03A, 0x037, 0x3C0, 0x3CE, 0x03B,
	0x036, 0x3BB, 0x3D2, 0x03C, 0x035, 0x3B7, 0x3D7, 0x03D,
	0x034, 0x3B2, 0x3DC, 0x03E, 0x033, 0x3AD, 0x3E0, 0x040,
	0x032, 0x3A9, 0x3E5, 0x041, 0x031, 0x3A4, 0x3E9, 0x042,
	0x030, 0x39F, 0x3ED, 0x043, 0x02F, 0x39B, 0x3F2, 0x045,
	0x02E, 0x396, 0x3F6, 0x046, 0x02D, 0x391, 0x3FB, 0x047,
	0x02C, 0x38C, 0x3FF, 0x049, 0x02B, 0x388, 0x403, 0x04A,
	0x02A, 0x383, 0x408, 0x04C, 0x029, 0x37E, 0x40C, 0x04D,
	0x028, 0x379, 0x410, 0x04E, 0x027, 0x374, 0x415, 0x050,
	0x026, 0x370, 0x419, 0x051, 0x025, 0x36B, 0x41D, 0x053,
	0x024, 0x366, 0x421, 0x054, 0x024, 0x361, 0x425, 0x056,
	0x023, 0x35C, 0x42A, 0x057, 0x022, 0x357, 0x42E, 0x059,
	0x021, 0x353, 0x432, 0x05A, 0x020, 0x34E, 0x436, 0x05C,
	0x020, 0x349, 0x43A, 0x05E, 0x01F, 0x344, 0x43E, 0x05F,
	0x01E, 0x33F, 0x442, 0x061, 0x01D, 0x33A, 0x446, 0x063,
	0x01D, 0x335, 0x44A, 0x064, 0x01C, 0x330, 0x44E, 0x066,
	0x01B, 0x32B, 0x452, 0x068, 0x01B, 0x326, 0x455, 0x06A,
	0x01A, 0x322, 0x459, 0x06B, 0x019, 0x31D, 0x45D, 0x06D,
	0x018, 0x318, 0x461, 0x06F, 0x018, 0x313, 0x465, 0x071,
	0x017, 0x30E, 0x468, 0x073, 0x017, 0x309, 0x46C, 0x075,
	0x016, 0x304, 0x470, 0x076, 0x015, 0x2FF, 0x473, 0x078,
	0x015, 0x2FA, 0x477, 0x07A, 0x014, 0x2F5, 0x47A, 0x07C,
	0x014, 0x2F0, 0x47E, 0x07E, 0x013, 0x2EB, 0x481, 0x080,
	0x013, 0x2E6, 0x485, 0x082, 0x012, 0x2E1, 0x488, 0x084,
	0x011, 0x2DC, 0x48C, 0x086, 0x011, 0x2D8, 0x48F, 0x089,
	0x010, 0x2D3, 0x492, 0x08B, 0x010, 0x2CE, 0x496, 0x08D,
	0x00F, 0x2C9, 0x499, 0x08F, 0x00F, 0x2C4, 0x49C, 0x091,
	0x00F, 0x2BF, 0x49F, 0x093, 0x00E, 0x2BA, 0x4A2, 0x096,
	0x00E, 0x2B5, 0x4A6, 0x098, 0x00D, 0x2B0, 0x4A9, 0x09A,
	0x00D, 0x2AB, 0x4AC, 0x09C, 0x00C, 0x2A6, 0x4AF, 0x09F,
	0x00C, 0x2A2, 0x4B2, 0x0A1, 0x00B, 0x29D, 0x4B5, 0x0A3,
	0x00B, 0x298, 0x4B7, 0x0A6, 0x00B, 0x293, 0x4BA, 0x0A8,
	0x00A, 0x28E, 0x4BD, 0x0AB, 0x00A, 0x289, 0x4C0, 0x0AD,
	0x00A, 0x284, 0x4C3, 0x0AF, 0x009, 0x280, 0x4C5, 0x0B2,
	0x009, 0x27B, 0x4C8, 0x0B4, 0x009, 0x276, 0x4CB, 0x0B7,
	0x008, 0x271, 0x4CD, 0x0BA, 0x008, 0x26C, 0x4D0, 0x0BC,
	0x008, 0x267, 0x4D2, 0x0BF, 0x007, 0x263, 0x4D5, 0x0C1,
	0x007, 0x25E, 0x4D7, 0x0C4, 0x007, 0x259, 0x4D9, 0x0C7,
	0x006, 0x254, 0x4DC, 0x0C9, 0x006, 0x250, 0x4DE, 0x0CC,
	0x006, 0x24B, 0x4E0, 0x0CF, 0x006, 0x246, 0x4E3, 0x0D2,
	0x005, 0x241, 0x4E5, 0x0D4, 0x005, 0x23D, 0x4E7, 0x0D7,
	0x005, 0x238, 0x4E9, 0x0DA, 0x005, 0x233, 0x4EB, 0x0DD,
	0x004, 0x22F, 0x4ED, 0x0E0, 0x004, 0x22A, 0x4EF, 0x0E3,
	0x004, 0x226, 0x4F1, 0x0E6, 0x004, 0x221, 0x4F3, 0x0E9,
	0x004, 0x21C, 0x4F5, 0x0EC, 0x003, 0x218, 0x4F6, 0x0EF,
	0x003, 0x213, 0x4F8, 0x0F2, 0x003, 0x20F, 0x4FA, 0x0F5,
	0x003, 0x20A, 0x4FB, 0x0F8, 0x003, 0x205, 0x4FD, 0x0FB,
	0x002, 0x201, 0x4FF, 0x0FE, 0x002, 0x1FC, 0x500, 0x101,
	0x002, 0x1F8, 0x502, 0x104, 0x002, 0x1F3, 0x503, 0x107,
	0x002, 0x1EF, 0x504, 0x10B, 0x002, 0x1EB, 0x506, 0x10E,
	0x002, 0x1E6, 0x507, 0x111, 0x001, 0x1E2, 0x508, 0x114,
	0x001, 0x1DD, 0x50A, 0x118, 0x001, 0x1D9, 0x50B, 0x11B,
	0x001, 0x1D5, 0x50C, 0x11E, 0x001, 0x1D0, 0x50D, 0x122,
	0x001, 0x1CC, 0x50E, 0x125, 0x001, 0x1C8, 0x50F, 0x129,
	0x001, 0x1C3, 0x510, 0x12C, 0x001, 0x1BF, 0x511, 0x130,
	0x001, 0x1BB, 0x511, 0x133, 0x001, 0x1B7, 0x512, 0x137,
	0x000, 0x1B2, 0x513, 0x13A, 0x000, 0x1AE, 0x514, 0x13E,
	0x000, 0x1AA, 0x514, 0x141, 0x000, 0x1A6, 0x515, 0x145,
	0x000, 0x1A2, 0x516, 0x148, 0x000, 0x19E, 0x516, 0x14C,
	0x000, 0x19A, 0x517, 0x150, 0x000, 0x195, 0x517, 0x153,
	0x000, 0x191, 0x517, 0x157, 0x000, 0x18D, 0x518, 0x15B,
	0x000, 0x189, 0x518, 0x15F, 0x000, 0x185, 0x518, 0x162,
	0x000, 0x181, 0x518, 0x166, 0x000, 0x17D, 0x518, 0x16A,
	0x000, 0x17A, 0x519, 0x16E, 0x000, 0x176, 0x519, 0x172
};

void SPUwriteRegister(unsigned long reg, unsigned short val)
{
#ifdef DEBUG_OUTPUT
	std::cout << setfill('0');
	std::cout << "*** SPUwriteRegister() " << "[address 0x"
	   << hex << setw(8) << reg << "] ";
#endif

	const unsigned long r = reg & 0xfff;
	regArea[(r - 0xc00) >> 1] = val;

	// some channel info?
	if(r >= 0x0c00 && r < 0x0d80)
	{
		// calc channel
		int ch = (r >> 4) - 0xc0;

		switch(r & 0x0f)
		{
			// l volume
			case 0:
#ifdef DEBUG_OUTPUT
				std::cout << "Left Volume - ";
#endif

				SetVolumeL((unsigned char)ch, val);
				break;

			// r volume
			case 2:
#ifdef DEBUG_OUTPUT
				std::cout << "Right Volume - ";
#endif

				SetVolumeR((unsigned char)ch, val);
				break;

			// pitch
			case 4:
#ifdef DEBUG_OUTPUT
				std::cout << "Pitch - ";
#endif

				SetPitch(ch, val);
				break;

			// start
			case 6:
#ifdef DEBUG_OUTPUT
				std::cout << "Start Address - ";
#endif
				s_chan[ch].pStart = spuMemC + ((unsigned long)val << 3);
				break;

			// level with pre-calcs
			case 8:
#ifdef DEBUG_OUTPUT
				std::cout << "Level with Pre-Calcs - ";
#endif

				{
					const unsigned long lval = val;

					s_chan[ch].ADSRX.AttackModeExp=(lval&0x8000)?1:0;
					s_chan[ch].ADSRX.AttackRate=(lval>>8) & 0x007f;
					s_chan[ch].ADSRX.DecayRate=(lval>>4) & 0x000f;
					s_chan[ch].ADSRX.SustainLevel=lval & 0x000f;
				}
				break;

			// adsr times with pre-calcs
			case 10:
#ifdef DEBUG_OUTPUT
				std::cout << "ADSR Times with Pre-Calcs - ";
#endif

				{
					const unsigned long lval = val;

					s_chan[ch].ADSRX.SustainModeExp = (lval & 0x8000) ? 1 : 0;
					s_chan[ch].ADSRX.SustainIncrease = (lval & 0x4000) ? 0 : 1;
					s_chan[ch].ADSRX.SustainRate = (lval >> 6) & 0x007f;
					s_chan[ch].ADSRX.ReleaseModeExp = (lval & 0x0020) ? 1 : 0;
					s_chan[ch].ADSRX.ReleaseRate = lval & 0x001f;
				}
				break;

			// adsr volume... mmm have to investigate this
			case 12:
#ifdef DEBUG_OUTPUT
				std::cout << "ADSR Volume - ";
#endif
				break;

			// loop
			case 14:
#ifdef DEBUG_OUTPUT
				std::cout << "Loop Address - ";
#endif
				s_chan[ch].pLoop = spuMemC + ((unsigned long)val << 3);
				s_chan[ch].bIgnoreLoop = 1;
				break;
		}

		iWatchDog = 0;

#ifdef DEBUG_OUTPUT
		std::cout << "0x" << hex << setw(4) << val << std::endl;
#endif

		return;
	}

	switch(r)
	{
		case H_SPUaddr:
#ifdef DEBUG_OUTPUT
			std::cout << "H_SPUaddr - ";
#endif
			spuAddr = (unsigned long)val << 3;
			break;

		case H_SPUdata:
#ifdef DEBUG_OUTPUT
			std::cout << "H_SPUdata - ";
#endif
			spuMem[spuAddr >> 1] = val;
			spuAddr += 2;
			if(spuAddr > 0x7ffff)
				spuAddr = 0;
			break;

		case H_SPUctrl:
#ifdef DEBUG_OUTPUT
			std::cout << "H_SPUctrl - ";
#endif
			spuCtrl = val;
			break;

		case H_SPUstat:
#ifdef DEBUG_OUTPUT
			std::cout << "H_SPUstat - ";
#endif
			spuStat = val & 0xf800;
			break;

		case H_SPUReverbAddr:
#ifdef DEBUG_OUTPUT
			std::cout << "H_SPUReverbAddr - ";
#endif
			if(val == 0xFFFF || val <= 0x200)
				rvb.StartAddr = rvb.CurrAddr = 0;
			else
			{
				const long iv = (unsigned long)val << 2;
				if(rvb.StartAddr != iv)
				{
					rvb.StartAddr = (unsigned long)val << 2;
					rvb.CurrAddr = rvb.StartAddr;
				}
			}
			break;

		case H_SPUirqAddr:
#ifdef DEBUG_OUTPUT
			std::cout << "H_SPUirqAddr - ";
#endif
			spuIrq = val;
			pSpuIrq = spuMemC + ((unsigned long) val << 3);
			break;

		case H_SPUrvolL:
#ifdef DEBUG_OUTPUT
			std::cout << "H_SPUrvolL - ";
#endif
			rvb.VolLeft = val;
			break;

		case H_SPUrvolR:
#ifdef DEBUG_OUTPUT
			std::cout << "H_SPUrvolR - ";
#endif
			rvb.VolRight = val;
			break;

		case H_SPUon1:
#ifdef DEBUG_OUTPUT
			std::cout << "H_SPUon1 - ";
#endif
			SoundOn(0, 16, val);
			break;

		case H_SPUon2:
#ifdef DEBUG_OUTPUT
			std::cout << "H_SPUon2 - ";
#endif
			SoundOn(16, 24, val);
			break;

		case H_SPUoff1:
#ifdef DEBUG_OUTPUT
			std::cout << "H_SPUoff1 - ";
#endif
			SoundOff(0, 16, val);
			break;

		case H_SPUoff2:
#ifdef DEBUG_OUTPUT
			std::cout << "H_SPUoff2 - ";
#endif
			SoundOff(16, 24, val);
			break;

		case H_CDLeft:
#ifdef DEBUG_OUTPUT
			std::cout << "H_CDLeft - ";
#endif
			iLeftXAVol = val & 0x7fff;
			if(cddavCallback)
				cddavCallback(0, val);
			break;

		case H_CDRight:
#ifdef DEBUG_OUTPUT
			std::cout << "H_CDRight - ";
#endif
			iRightXAVol = val & 0x7fff;
			if(cddavCallback)
				cddavCallback(1, val);
			break;

		case H_FMod1:
#ifdef DEBUG_OUTPUT
			std::cout << "H_FMod1 - ";
#endif
			FModOn(0, 16, val);
			break;

		case H_FMod2:
#ifdef DEBUG_OUTPUT
			std::cout << "H_FMod2 - ";
#endif
			FModOn(16, 24, val);
			break;

		case H_Noise1:
#ifdef DEBUG_OUTPUT
			std::cout << "H_Noise1 - ";
#endif
			NoiseOn(0, 16, val);
			break;

		case H_Noise2:
#ifdef DEBUG_OUTPUT
			std::cout << "H_Noise2 - ";
#endif
			NoiseOn(16, 24, val);
			break;

		case H_RVBon1:
#ifdef DEBUG_OUTPUT
			std::cout << "H_RVBon1 - ";
#endif
			ReverbOn(0, 16, val);
			break;

		case H_RVBon2:
#ifdef DEBUG_OUTPUT
			std::cout << "H_RVBon2 - ";
#endif
			ReverbOn(16, 24, val);
			break;

		case H_Reverb + 0:
#ifdef DEBUG_OUTPUT
			std::cout << "H_Reverb - ";
#endif
			rvb.FB_SRC_A = val;

			// OK, here's the fake REVERB stuff...
			// depending on effect we do more or less delay and repeats... bah
			// still... better than nothing :)

			SetREVERB(val);
			break;


		case H_Reverb+2   : rvb.FB_SRC_B=(short)val;       break;
		case H_Reverb+4   : rvb.IIR_ALPHA=(short)val;      break;
		case H_Reverb+6   : rvb.ACC_COEF_A=(short)val;     break;
		case H_Reverb+8   : rvb.ACC_COEF_B=(short)val;     break;
		case H_Reverb+10  : rvb.ACC_COEF_C=(short)val;     break;
		case H_Reverb+12  : rvb.ACC_COEF_D=(short)val;     break;
		case H_Reverb+14  : rvb.IIR_COEF=(short)val;       break;
		case H_Reverb+16  : rvb.FB_ALPHA=(short)val;       break;
		case H_Reverb+18  : rvb.FB_X=(short)val;           break;
		case H_Reverb+20  : rvb.IIR_DEST_A0=(short)val;    break;
		case H_Reverb+22  : rvb.IIR_DEST_A1=(short)val;    break;
		case H_Reverb+24  : rvb.ACC_SRC_A0=(short)val;     break;
		case H_Reverb+26  : rvb.ACC_SRC_A1=(short)val;     break;
		case H_Reverb+28  : rvb.ACC_SRC_B0=(short)val;     break;
		case H_Reverb+30  : rvb.ACC_SRC_B1=(short)val;     break;
		case H_Reverb+32  : rvb.IIR_SRC_A0=(short)val;     break;
		case H_Reverb+34  : rvb.IIR_SRC_A1=(short)val;     break;
		case H_Reverb+36  : rvb.IIR_DEST_B0=(short)val;    break;
		case H_Reverb+38  : rvb.IIR_DEST_B1=(short)val;    break;
		case H_Reverb+40  : rvb.ACC_SRC_C0=(short)val;     break;
		case H_Reverb+42  : rvb.ACC_SRC_C1=(short)val;     break;
		case H_Reverb+44  : rvb.ACC_SRC_D0=(short)val;     break;
		case H_Reverb+46  : rvb.ACC_SRC_D1=(short)val;     break;
		case H_Reverb+48  : rvb.IIR_SRC_B1=(short)val;     break;
		case H_Reverb+50  : rvb.IIR_SRC_B0=(short)val;     break;
		case H_Reverb+52  : rvb.MIX_DEST_A0=(short)val;    break;
		case H_Reverb+54  : rvb.MIX_DEST_A1=(short)val;    break;
		case H_Reverb+56  : rvb.MIX_DEST_B0=(short)val;    break;
		case H_Reverb+58  : rvb.MIX_DEST_B1=(short)val;    break;
		case H_Reverb+60  : rvb.IN_COEF_L=(short)val;      break;
		case H_Reverb+62  : rvb.IN_COEF_R=(short)val;      break;
	}

	iWatchDog = 0;

#ifdef DEBUG_OUTPUT
	std::cout << "0x" << hex << setw(4) << val << std::endl;
#endif
}



unsigned short SPUreadRegister(unsigned long reg)
{
#ifdef DEBUG_OUTPUT
	std::cout << setfill('0');
	std::cout << "*** SPUreadRegister(0x" << hex << setw(8) << reg << "), returned ";
#endif

	const unsigned long r = reg & 0xfff;

	iWatchDog = 0;

	if(r >= 0x0c00 && r < 0x0d80)
	{
		switch(r & 0x0f)
		{
			// get adsr vol
			case 12:
				{
					const int ch = (r >> 4) - 0xc0;

					// we are started, but not processed? return 1
					if(s_chan[ch].bNew)
					{
#ifdef DEBUG_OUTPUT
						std::cout << "0x" << hex << setw(4) << 1 << std::endl;
#endif
						return 1;
					}

					// same here... we haven't decoded one sample
					// yet, so no envelope yet. return 1 as well
					if(s_chan[ch].ADSRX.lVolume &&
						!s_chan[ch].ADSRX.EnvelopeVol)
					{
#ifdef DEBUG_OUTPUT
						std::cout << "0x" << hex << setw(4) << 1 << std::endl;
#endif
						return 1;
					}

#ifdef DEBUG_OUTPUT
					std::cout << "0x" << hex << setw(4)
						<< (unsigned short)(s_chan[ch].ADSRX.EnvelopeVol >> 16)
						<< std::endl;
#endif
					return (unsigned short)(s_chan[ch].ADSRX.EnvelopeVol >> 16);
				}

			// get loop address
			case 14:
				{
					const int ch = (r >> 4) - 0xc0;
					if(s_chan[ch].pLoop == NULL)
					{
#ifdef DEBUG_OUTPUT
						std::cout << "0x" << hex << setw(4) << 0 << std::endl;
#endif
						return 0;
					}

#ifdef DEBUG_OUTPUT
					std::cout << "0x" << hex << setw(4)
						<< (unsigned short)((s_chan[ch].pLoop - spuMemC) >> 3)
						<< std::endl;
#endif
					return (unsigned short)((s_chan[ch].pLoop - spuMemC) >> 3);
				}
		}
	}

	switch(r)
	{
		case H_SPUctrl:
#ifdef DEBUG_OUTPUT
			std::cout << "0x" << hex << setw(4) << spuCtrl << std::endl;
#endif
			return spuCtrl;

		case H_SPUstat:
#ifdef DEBUG_OUTPUT
			std::cout << "0x" << hex << setw(4) << spuStat << std::endl;
#endif
			return spuStat;

		case H_SPUaddr:
#ifdef DEBUG_OUTPUT
			std::cout << "0x" << hex
				<< setw(4) << (unsigned short)(spuAddr >> 3) << std::endl;
#endif
			return (unsigned short)(spuAddr >> 3);

		case H_SPUdata:
			{
				unsigned short s = spuMem[spuAddr >> 1];
				spuAddr += 2;
				if(spuAddr > 0x7ffff)
					spuAddr = 0;

#ifdef DEBUG_OUTPUT
				std::cout << "0x" << hex << setw(4) << s << std::endl;
#endif
				return s;
			}

		case H_SPUirqAddr:
#ifdef DEBUG_OUTPUT
			std::cout << "0x" << hex << setw(4) << spuIrq << std::endl;
#endif
			return spuIrq;
	}

#ifdef DEBUG_OUTPUT
	std::cout << "0x" << hex << setw(4) << regArea[(r - 0xc00) >> 1] << std::endl;
#endif
	return regArea[(r - 0xc00) >> 1];
}


void SoundOn(int start, int end, unsigned short val)
{
	int ch;

	// loop channels
	for(ch = start; ch < end; ch++, val >>= 1)
	{
		if((val & 1) && s_chan[ch].pStart)
		// mmm... start has to be set before key on !?!

		{
			s_chan[ch].bIgnoreLoop = 0;
			s_chan[ch].bNew = 1;

			// bitfield for faster testing
			dwNewChannel |= (1 << ch);
		}
	}
}


void SoundOff(int start, int end, unsigned short val)
{
	int ch;

	// loop channels
	for(ch = start; ch < end; ch++, val >>= 1)
	{
		if(val & 1) // && s_chan[i].bOn)  mmm...
			s_chan[ch].bStop = 1;
	}
}


void FModOn(int start, int end, unsigned short val)
{
	int ch;

	// loop channels
	for(ch = start; ch < end; ch++, val >>= 1)
	{
		// fmod on/off
		if(val & 1)
		{
			if(ch > 0)
			{
				// sound channel
				s_chan[ch].bFMod = 1;

				// freq channel
				s_chan[ch - 1].bFMod = 2;
			}
		}
		else
			s_chan[ch].bFMod = 0;
	}
}


void NoiseOn(int start, int end, unsigned short val)
{
	int ch;

	// loop channels
	for(ch = start; ch < end; ch++, val >>= 1)
	{
		// noise on/off
		if(val & 1)
		{
			s_chan[ch].bNoise = 1;
		}
		else
		{
			s_chan[ch].bNoise = 0;
		}
	}
}


// please note: sweep and phase invert are wrong... but I've never seen
// them used
void SetVolumeL(unsigned char ch, short vol)
{
	s_chan[ch].iLeftVolRaw = vol;

	// sweep
	if(vol & 0x8000)
	{
		short sInc = 1;
		if(vol & 0x2000)
			sInc = -1;

		// -> mmm... phase inverted? have to investigate this
		if(vol & 0x1000)
			vol ^= 0xffff;

		// -> sweep: 0..127 -> 0..64
		vol = ((vol & 0x7f) + 1) / 2;

		// -> HACK: we don't sweep right now, so we
		// just raise/lower the volume by the half!
		vol += vol / (2 * sInc);
		vol *= 128;
	}

	// no sweep
	else
	{
		// -> mmm... phase inverted? have to investigate this
		if(vol & 0x4000)
			vol = 0x3fff - (vol & 0x3fff);
	}

	vol &= 0x3fff;

	// store volume
	s_chan[ch].iLeftVolume = vol;
}

void SetVolumeR(unsigned char ch, short vol)
{
	s_chan[ch].iRightVolRaw = vol;

	// comments... see above :)
	if(vol & 0x8000)
	{
		short sInc = 1;
		if(vol & 0x2000)
			sInc = -1;
		if(vol & 0x1000)
			vol ^= 0xffff;
		vol = ((vol & 0x7f) + 1) / 2;
		vol += vol / (2 * sInc);
		vol *= 128;
	}
	else
	{
		if(vol & 0x4000)
			vol = 0x3fff - (vol & 0x3fff);
	}

	vol &= 0x3fff;
	s_chan[ch].iRightVolume = vol;
}


void SetPitch(int ch, unsigned short val)
{
	int NP;
	if(val > 0x3fff)
		NP = 0x3fff;
	else
		NP = val;

	s_chan[ch].iRawPitch = NP;

	NP = (44100L * NP) / 4096L;
	if(NP < 1)
		NP = 1;

	s_chan[ch].iActFreq = NP;
}


void ReverbOn(int start, int end, unsigned short val)
{
	int ch;

	// loop channels
	for(ch = start; ch < end; ch++, val >>= 1)
	{
		// reverb on/off
		if(val & 1)
			s_chan[ch].bReverb = 1;
		else
			s_chan[ch].bReverb = 0;
	}
}
void SetREVERB(unsigned short val)
{
	switch(val)
	{
		// off
		case 0x0000:
			iReverbOff = -1;
			break;

		// ok room
		case 0x007D:
			iReverbOff = 32;
			iReverbNum = 2;
			iReverbRepeat = 128;
			break;

		// studio small
		case 0x0033:
			iReverbOff = 32;
			iReverbNum = 2;
			iReverbRepeat = 64;
			break;

		// ok studio medium
		case 0x00B1:
			iReverbOff = 48;
			iReverbNum = 2;
			iReverbRepeat = 96;
			break;

		// ok studio large ok
		case 0x00E3:
			iReverbOff = 64;
			iReverbNum = 2;
			iReverbRepeat = 128;
			break;

		// ok hall
		case 0x01A5:
			iReverbOff = 128;
			iReverbNum = 4;
			iReverbRepeat = 32;
			break;

		// space echo
		case 0x033D:
			iReverbOff = 256;
			iReverbNum = 4;
			iReverbRepeat = 64;
			break;

		// echo/delay
		case 0x0001:
			iReverbOff = 184;
			iReverbNum = 3;
			iReverbRepeat = 128;
			break;

		// half echo
		case 0x0017:
			iReverbOff = 128;
			iReverbNum = 2;
			iReverbRepeat = 128;
			break;

		default:
			iReverbOff = 32;
			iReverbNum = 1;
			iReverbRepeat = 0;
			break;
	}
}


void StartREVERB(int ch)
{
	// reverb possible?
	if(s_chan[ch].bReverb && (spuCtrl & 0x80))
	{
		if(iUseReverb == 2)
			s_chan[ch].bRVBActive = 1;
		else
			// fake reverb used?
			if(iUseReverb == 1 && iReverbOff > 0)
			{
				// activate it
				s_chan[ch].bRVBActive = 1;
				s_chan[ch].iRVBOffset = iReverbOff * 45;
				s_chan[ch].iRVBRepeat = iReverbRepeat * 45;
				s_chan[ch].iRVBNum = iReverbNum;
			}
	}
	else
		// no reverb
		s_chan[ch].bRVBActive = 0;
}


void InitREVERB()
{
	if(iUseReverb == 2)
		memset(sRVBStart, 0, NSSIZE * 2 * 4);
}


void StoreREVERB(int ch, int ns)
{
	if(iUseReverb == 0)
		return;

	// Neil's reverb
	if(iUseReverb == 2)
	{
		const int iRxl =
			(s_chan[ch].sval * s_chan[ch].iLeftVolume) / 0x4000;
		const int iRxr =
			(s_chan[ch].sval * s_chan[ch].iRightVolume) / 0x4000;

		ns <<= 1;

		// -> we mix all active reverb channels into an extra buffer
		*(sRVBStart + ns) += iRxl;
		*(sRVBStart + ns + 1) += iRxr;
	}

	// Pete's easy fake reverb
	else
	{
		int *pN;
		int iRn, iRr = 0;

		// we use the half channel volume (/0x8000) for the
		// first reverb effects, quarter for next and so on
		int iRxl =
			(s_chan[ch].sval * s_chan[ch].iLeftVolume) / 0x8000;
		int iRxr =
			(s_chan[ch].sval * s_chan[ch].iRightVolume) / 0x8000;

		for(iRn = 1; iRn <= s_chan[ch].iRVBNum;
				iRn++, iRr += s_chan[ch].iRVBRepeat,iRxl /= 2, iRxr /= 2)
		{
			pN = sRVBPlay + ((s_chan[ch].iRVBOffset + iRr + ns) << 1);
			if(pN >= sRVBEnd)
				pN = sRVBStart + (pN - sRVBEnd);

			(*pN) += iRxl;
			pN++;
			(*pN) += iRxr;
		}
	}
}


// get_buffer content helper: takes care about wraps
int g_buffer(int iOff)
{
	short *p = (short *)spuMem;
	iOff = (iOff * 4) + rvb.CurrAddr;
	while(iOff > 0x3FFFF)
		iOff = rvb.StartAddr + (iOff - 0x40000);
	while(iOff < rvb.StartAddr)
		iOff = 0x3ffff - (rvb.StartAddr - iOff);

	return (int)*(p + iOff);
}


// set_buffer content helper: takes care about wraps and clipping
void s_buffer(int iOff, int iVal)
{
	short *p = (short *)spuMem;
	iOff = (iOff * 4) + rvb.CurrAddr;
	while(iOff > 0x3FFFF)
		iOff = rvb.StartAddr + (iOff - 0x40000);
	while(iOff < rvb.StartAddr)
		iOff = 0x3ffff - (rvb.StartAddr - iOff);
	if(iVal < -32768L)
		iVal = -32768L;
	if(iVal > 32767L)
		iVal = 32767L;

	*(p + iOff) = (short)iVal;
}


// set_buffer (+1 sample) content helper: takes care about wraps and clipping
void s_buffer1(int iOff, int iVal)
{
	short *p = (short *)spuMem;
	iOff = (iOff * 4) + rvb.CurrAddr + 1;
	while(iOff > 0x3FFFF)
		iOff = rvb.StartAddr + (iOff - 0x40000);
	while(iOff < rvb.StartAddr)
		iOff = 0x3ffff - (rvb.StartAddr - iOff);
	if(iVal < -32768L)
		iVal = -32768L;
	if(iVal > 32767L)
		iVal = 32767L;

	*(p + iOff) = (short)iVal;
}


int MixREVERBLeft(int ns)
{
	if(iUseReverb == 0)
		return 0;

	if(iUseReverb == 2)
	{
		// this func will be called with 44.1 khz
		static int iCnt = 0;

		// reverb is off
		if(!rvb.StartAddr)
		{
			rvb.iLastRVBLeft = rvb.iLastRVBRight =
				rvb.iRVBLeft = rvb.iRVBRight = 0;

			return 0;
		}

		iCnt++;

		// we work on every second left value: downsample to 22 khz
		if(iCnt & 1)
		{
			// -> reverb on? oki
			if(spuCtrl & 0x80)
			{
				int ACC0, ACC1, FB_A0, FB_A1, FB_B0, FB_B1;

				const int INPUT_SAMPLE_L = *(sRVBStart + (ns << 1));
				const int INPUT_SAMPLE_R = *(sRVBStart + (ns << 1) + 1);

				const int IIR_INPUT_A0 =
					(g_buffer(rvb.IIR_SRC_A0) * rvb.IIR_COEF) / 32768L +
					(INPUT_SAMPLE_L * rvb.IN_COEF_L) / 32768L;
				const int IIR_INPUT_A1 =
					(g_buffer(rvb.IIR_SRC_A1) * rvb.IIR_COEF) / 32768L +
					(INPUT_SAMPLE_R * rvb.IN_COEF_R) / 32768L;
				const int IIR_INPUT_B0 =
					(g_buffer(rvb.IIR_SRC_B0) * rvb.IIR_COEF) / 32768L +
					(INPUT_SAMPLE_L * rvb.IN_COEF_L) / 32768L;
				const int IIR_INPUT_B1 =
					(g_buffer(rvb.IIR_SRC_B1) * rvb.IIR_COEF) / 32768L +
					(INPUT_SAMPLE_R * rvb.IN_COEF_R) / 32768L;

				const int IIR_A0 = (IIR_INPUT_A0 * rvb.IIR_ALPHA) / 32768L +
					(g_buffer(rvb.IIR_DEST_A0) *
					 (32768L - rvb.IIR_ALPHA)) / 32768L;
				const int IIR_A1 = (IIR_INPUT_A1 * rvb.IIR_ALPHA) / 32768L +
					(g_buffer(rvb.IIR_DEST_A1) *
					 (32768L - rvb.IIR_ALPHA)) / 32768L;
				const int IIR_B0 = (IIR_INPUT_B0 * rvb.IIR_ALPHA) / 32768L +
					(g_buffer(rvb.IIR_DEST_B0) *
					 (32768L - rvb.IIR_ALPHA)) / 32768L;
				const int IIR_B1 = (IIR_INPUT_B1 * rvb.IIR_ALPHA) / 32768L +
					(g_buffer(rvb.IIR_DEST_B1) *
					 (32768L - rvb.IIR_ALPHA)) / 32768L;

				s_buffer1(rvb.IIR_DEST_A0, IIR_A0);
				s_buffer1(rvb.IIR_DEST_A1, IIR_A1);
				s_buffer1(rvb.IIR_DEST_B0, IIR_B0);
				s_buffer1(rvb.IIR_DEST_B1, IIR_B1);

				ACC0 = (g_buffer(rvb.ACC_SRC_A0) * rvb.ACC_COEF_A) / 32768L +
					(g_buffer(rvb.ACC_SRC_B0) * rvb.ACC_COEF_B) / 32768L +
					(g_buffer(rvb.ACC_SRC_C0) * rvb.ACC_COEF_C) / 32768L +
					(g_buffer(rvb.ACC_SRC_D0) * rvb.ACC_COEF_D) / 32768L;
				ACC1 = (g_buffer(rvb.ACC_SRC_A1) * rvb.ACC_COEF_A) / 32768L +
					(g_buffer(rvb.ACC_SRC_B1) * rvb.ACC_COEF_B) / 32768L +
					(g_buffer(rvb.ACC_SRC_C1) * rvb.ACC_COEF_C) / 32768L +
					(g_buffer(rvb.ACC_SRC_D1) * rvb.ACC_COEF_D) / 32768L;

				FB_A0 = g_buffer(rvb.MIX_DEST_A0 - rvb.FB_SRC_A);
				FB_A1 = g_buffer(rvb.MIX_DEST_A1 - rvb.FB_SRC_A);
				FB_B0 = g_buffer(rvb.MIX_DEST_B0 - rvb.FB_SRC_B);
				FB_B1 = g_buffer(rvb.MIX_DEST_B1 - rvb.FB_SRC_B);

				s_buffer(rvb.MIX_DEST_A0,
					ACC0 - (FB_A0 * rvb.FB_ALPHA) / 32768L);
				s_buffer(rvb.MIX_DEST_A1,
					ACC1 - (FB_A1 * rvb.FB_ALPHA) / 32768L);

				s_buffer(rvb.MIX_DEST_B0, (rvb.FB_ALPHA * ACC0) / 32768L -
					(FB_A0 * (int)(rvb.FB_ALPHA ^ 0xFFFF8000)) / 32768L -
					(FB_B0 * rvb.FB_X) / 32768L);
				s_buffer(rvb.MIX_DEST_B1, (rvb.FB_ALPHA * ACC1) / 32768L -
					(FB_A1 * (int)(rvb.FB_ALPHA ^ 0xFFFF8000)) / 32768L -
					(FB_B1 * rvb.FB_X) / 32768L);

				rvb.iLastRVBLeft  = rvb.iRVBLeft;
				rvb.iLastRVBRight = rvb.iRVBRight;

				rvb.iRVBLeft =
					(g_buffer(rvb.MIX_DEST_A0) + g_buffer(rvb.MIX_DEST_B0)) / 3;
				rvb.iRVBRight =
					(g_buffer(rvb.MIX_DEST_A1) + g_buffer(rvb.MIX_DEST_B1)) / 3;

				rvb.iRVBLeft = (rvb.iRVBLeft * rvb.VolLeft) / 0x4000;
				rvb.iRVBRight = (rvb.iRVBRight * rvb.VolRight) / 0x4000;

				rvb.CurrAddr++;
				if(rvb.CurrAddr > 0x3ffff)
					rvb.CurrAddr = rvb.StartAddr;

				return rvb.iLastRVBLeft + (rvb.iRVBLeft-rvb.iLastRVBLeft) / 2;
			}
			// reverb off
			else
				rvb.iLastRVBLeft = rvb.iLastRVBRight =
					rvb.iRVBLeft = rvb.iRVBRight = 0;

			rvb.CurrAddr++;
			if(rvb.CurrAddr > 0x3ffff)
				rvb.CurrAddr = rvb.StartAddr;
		}

		return rvb.iLastRVBLeft;
	}
	// easy fake reverb
	else
	{
		// -> simply take the reverb mix buf value
		const int iRV = *sRVBPlay;
		// -> init it after
		*sRVBPlay++ = 0;
		// -> and take care about wrap arounds
		if(sRVBPlay >= sRVBEnd)
			sRVBPlay = sRVBStart;

		// -> return reverb buf mix val
		return iRV;
	}
}


int MixREVERBRight()
{
	if(iUseReverb == 0)
		return 0;

	// Neill's reverb
	if(iUseReverb == 2)
	{
		int i = rvb.iLastRVBRight + (rvb.iRVBRight - rvb.iLastRVBRight) / 2;
		rvb.iLastRVBRight = rvb.iRVBRight;

		// -> just return the last right reverb val
		// (little bit scaled by the previous right val)
		return i;
	}
	// easy fake reverb
	else
	{
		// -> simply take the reverb mix buf value
		const int iRV = *sRVBPlay;
		// -> init it after
		*sRVBPlay++ = 0;
		// -> and take care about wrap arounds
		if(sRVBPlay >= sRVBEnd)
			sRVBPlay = sRVBStart;

		// -> return reverb mix buf val
		return iRV;
	}
}


void MixXA()
{
	int ns;

	for(ns = 0; ns < NSSIZE && XAPlay != XAFeed; ns++)
	{
		XALastVal = *XAPlay++;
		if(XAPlay == XAEnd)
			XAPlay = XAStart;
		SSumL[ns] += (((short)(XALastVal & 0xffff)) * iLeftXAVol) / 32767;
		SSumR[ns] += (((short)((XALastVal >> 16) & 0xffff)) *
			iRightXAVol) / 32767;
	}

	if(XAPlay == XAFeed && XARepeat)
	{
		XARepeat--;
		for(;ns < NSSIZE; ns++)
		{
			SSumL[ns] += (((short)(XALastVal & 0xffff)) * iLeftXAVol) / 32767;
			SSumR[ns] += (((short)((XALastVal >> 16) & 0xffff)) *
				iRightXAVol) / 32767;
		}
	}
}


void FeedXA(xa_decode_t *xap)
{
	int sinc, spos, i, iSize, iPlace, vl, vr;

	if(!bSPUIsOpen)
		return;

	// store info for save states
	xapGlobal = xap;
	// set up repeat
	XARepeat  = 100;

	// get size
	iSize = ((44100 * xap->nsamples) / xap->freq);

	// if none
	if(!iSize)
		return;

	// how much space in my buf?
	if(XAFeed < XAPlay)
		iPlace = XAPlay - XAFeed;
	else
		iPlace = (XAEnd - XAFeed) + (XAPlay - XAStart);

	// no place at all
	if(iPlace == 0)
		return;

	// pitch change option
	if(iXAPitch)
	{
		static unsigned long dwLT = 0;
		static unsigned long dwFPS = 0;
		static int   iFPSCnt = 0;
		static int   iLastSize = 0;
		static unsigned long dwL1 = 0;
		unsigned long dw, dw1, dw2;

//G		dw = timeGetTime_spu();
		dw = GGetTime();

		iPlace = iSize;

		dwFPS += dw - dwLT;
		iFPSCnt++;

		dwLT = dw;

		if(iFPSCnt >= 10)
		{
			if(!dwFPS)
				dwFPS = 1;
			dw1 = 1000000 / dwFPS;
			if(dw1 >= (dwL1 - 100) && dw1 <= (dwL1 + 100))
				dw1 = dwL1;
			else
				dwL1 = dw1;
			dw2 = (xap->freq * 100 / xap->nsamples);
			if((!dw1) || ((dw2 + 100) >= dw1))
				iLastSize = 0;
			else
			{
				iLastSize = iSize * dw2 / dw1;
				if(iLastSize > iPlace)
					iLastSize = iPlace;
				iSize = iLastSize;
			}
			iFPSCnt = 0;
			dwFPS = 0;
		}
		else
		{
			if(iLastSize)
				iSize = iLastSize;
		}
	}

	spos = 0x10000L;
	// calc freq by num / size
	sinc = (xap->nsamples << 16) / iSize;

	if(xap->stereo)
	{
		u32 * pS = (u32 *)xap->pcm;
		u32 l = 0;

		if(iXAPitch)
		{
			int32_t l1, l2;
			short s;
			for(i = 0; i < iSize; i++)
			{
				if(iUseInterpolation == 2)
				{
					while(spos >= 0x10000L)
					{
						l = *pS++;
						gauss_window[gauss_ptr] = (short)LOWORD(l);
						gauss_window[4 + gauss_ptr] = (short)HIWORD(l);
						gauss_ptr = (gauss_ptr + 1) & 3;
						spos -= 0x10000L;
					}
					vl = (spos >> 6) & ~3;
					vr = (gauss[vl]*gvall0) & ~2047;
					vr += (gauss[vl + 1] * gvall(1)) & ~2047;
					vr += (gauss[vl + 2] * gvall(2)) & ~2047;
					vr += (gauss[vl + 3] * gvall(3)) & ~2047;
					l= (vr >> 11) & 0xffff;
					vr = (gauss[vl] * gvalr0) & ~2047;
					vr += (gauss[vl + 1] * gvalr(1)) & ~2047;
					vr += (gauss[vl + 2] * gvalr(2)) & ~2047;
					vr += (gauss[vl + 3] * gvalr(3)) & ~2047;
					l |= vr << 5;
				}
				else
				{
					while(spos >= 0x10000L)
					{
						l = *pS++;
						spos -= 0x10000L;
					}
				}

				s = (short)LOWORD(l);
				l1 = s;
				l1 = (l1 * iPlace) / iSize;
				if(l1 < -32767)
					l1 = -32767;
				if(l1 > 32767)
					l1 = 32767;
				s = (short)HIWORD(l);
				l2 = s;
				l2 = (l2 * iPlace) / iSize;
				if(l2 < -32767)
					l2 = -32767;
				if(l2 > 32767)
					l2 = 32767;
				l = (l1 & 0xffff)|(l2 << 16);

				*XAFeed++ = l;

				if(XAFeed == XAEnd)
					XAFeed = XAStart;
				if(XAFeed == XAPlay)
				{
					if(XAPlay != XAStart)
						XAFeed = XAPlay - 1;
					break;
				}

				spos += sinc;
			}
		}
		else
		{
			for(i = 0; i < iSize; i++)
			{
				if(iUseInterpolation == 2)
				{
					while(spos >= 0x10000L)
					{
						l = *pS++;
						gauss_window[gauss_ptr] = (short)LOWORD(l);
						gauss_window[4 + gauss_ptr] = (short)HIWORD(l);
						gauss_ptr = (gauss_ptr + 1) & 3;
						spos -= 0x10000L;
					}
					vl = (spos >> 6) & ~3;
					vr = (gauss[vl] * gvall0) & ~2047;
					vr += (gauss[vl + 1] * gvall(1)) & ~2047;
					vr += (gauss[vl + 2] * gvall(2)) & ~2047;
					vr += (gauss[vl + 3] * gvall(3)) & ~2047;
					l = (vr >> 11) & 0xffff;
					vr = (gauss[vl] * gvalr0) & ~2047;
					vr += (gauss[vl + 1] * gvalr(1)) & ~2047;
					vr += (gauss[vl + 2] * gvalr(2)) & ~2047;
					vr += (gauss[vl + 3] * gvalr(3)) & ~2047;
					l |= vr << 5;
				}
				else
				{
					while(spos>=0x10000L)
					{
						l = *pS++;
						spos -= 0x10000L;
					}
				}

				*XAFeed++ = l;

				if(XAFeed == XAEnd)
					XAFeed = XAStart;
				if(XAFeed == XAPlay)
				{
					if(XAPlay != XAStart)
						XAFeed = XAPlay - 1;
					break;
				}

				spos += sinc;
			}
		}
	}
	else
	{
		unsigned short * pS = (unsigned short *)xap->pcm;
		u32 l;
		short s = 0;

		if(iXAPitch)
		{
			int32_t l1;
			for(i = 0; i < iSize; i++)
			{
				if(iUseInterpolation == 2)
				{
					while(spos >= 0x10000L)
					{
						gauss_window[gauss_ptr] = (short)*pS++;
						gauss_ptr = (gauss_ptr + 1) & 3;
						spos -= 0x10000L;
					}
					vl = (spos >> 6) & ~3;
					vr = (gauss[vl] * gvall0) & ~2047;
					vr += (gauss[vl + 1] * gvall(1)) & ~2047;
					vr += (gauss[vl + 2] * gvall(2)) & ~2047;
					vr += (gauss[vl + 3] * gvall(3)) & ~2047;
					l1 = s = vr >> 11;
					l1 &= 0xffff;
				}
				else
				{
					while(spos >= 0x10000L)
					{
						s = *pS++;
						spos -= 0x10000L;
					}
					l1 = s;
				}

				l1 = (l1 * iPlace) / iSize;
				if(l1 < -32767)
					l1 = -32767;
				if(l1 > 32767)
					l1 = 32767;
				l = (l1 & 0xffff) | (l1 << 16);
				*XAFeed++ = l;

				if(XAFeed == XAEnd)
					XAFeed = XAStart;
				if(XAFeed == XAPlay)
				{
					if(XAPlay != XAStart)
						XAFeed = XAPlay - 1;
					break;
				}

				spos += sinc;
			}
		}
		else
		{
			for(i = 0; i < iSize; i++)
			{
				if(iUseInterpolation == 2)
				{
					while(spos >= 0x10000L)
					{
						gauss_window[gauss_ptr] = (short)*pS++;
						gauss_ptr = (gauss_ptr + 1) & 3;
						spos -= 0x10000L;
					}
					vl = (spos >> 6) & ~3;
					vr = (gauss[vl] * gvall0) & ~2047;
					vr += (gauss[vl + 1] * gvall(1)) & ~2047;
					vr += (gauss[vl + 2] * gvall(2)) & ~2047;
					vr += (gauss[vl + 3] * gvall(3)) & ~2047;
					l= s = vr >> 11;
					l &= 0xffff;
				}
				else
				{
					while(spos >= 0x10000L)
					{
						s = *pS++;
						spos -= 0x10000L;
					}
					l = s;
				}

				*XAFeed++ = (l | (l << 16));

				if(XAFeed == XAEnd)
					XAFeed = XAStart;
				if(XAFeed == XAPlay)
				{
					if(XAPlay != XAStart)
						XAFeed = XAPlay - 1;
					break;
				}

				spos += sinc;
			}
		}
	}
}

void InterpolateUp(int ch)
{
	if(s_chan[ch].SB[32]==1)                              // flag == 1? calc step and set flag... and don't change the value in this pass
	{
		const int id1=s_chan[ch].SB[30]-s_chan[ch].SB[29];  // curr delta to next val
		const int id2=s_chan[ch].SB[31]-s_chan[ch].SB[30];  // and next delta to next-next val :)

		s_chan[ch].SB[32]=0;

		if(id1>0)                                           // curr delta positive
		{
			if(id2<id1)
			{s_chan[ch].SB[28]=id1;s_chan[ch].SB[32]=2;}
			else
				if(id2<(id1<<1))
					s_chan[ch].SB[28]=(id1*s_chan[ch].sinc)/0x10000L;
				else
					s_chan[ch].SB[28]=(id1*s_chan[ch].sinc)/0x20000L;
		}
		else                                                // curr delta negative
		{
			if(id2>id1)
			{s_chan[ch].SB[28]=id1;s_chan[ch].SB[32]=2;}
			else
				if(id2>(id1<<1))
					s_chan[ch].SB[28]=(id1*s_chan[ch].sinc)/0x10000L;
				else
					s_chan[ch].SB[28]=(id1*s_chan[ch].sinc)/0x20000L;
		}
	}
	else
		if(s_chan[ch].SB[32]==2)                              // flag 1: calc step and set flag... and don't change the value in this pass
		{
			s_chan[ch].SB[32]=0;

			s_chan[ch].SB[28]=(s_chan[ch].SB[28]*s_chan[ch].sinc)/0x20000L;
			if(s_chan[ch].sinc<=0x8000)
				s_chan[ch].SB[29]=s_chan[ch].SB[30]-(s_chan[ch].SB[28]*((0x10000/s_chan[ch].sinc)-1));
			else s_chan[ch].SB[29]+=s_chan[ch].SB[28];
		}
		else                                                  // no flags? add bigger val (if possible), calc smaller step, set flag1
			s_chan[ch].SB[29]+=s_chan[ch].SB[28];
}

//
// even easier interpolation on downsampling, also no special filter, again just "Pete's common sense" tm
//

void InterpolateDown(int ch)
{
	if(s_chan[ch].sinc>=0x20000L)                                 // we would skip at least one val?
	{
		s_chan[ch].SB[29]+=(s_chan[ch].SB[30]-s_chan[ch].SB[29])/2; // add easy weight
		if(s_chan[ch].sinc>=0x30000L)                               // we would skip even more vals?
			s_chan[ch].SB[29]+=(s_chan[ch].SB[31]-s_chan[ch].SB[30])/2;// add additional next weight
	}
}

////////////////////////////////////////////////////////////////////////
// helpers for gauss interpolation

#define gval0 (((short*)(&s_chan[ch].SB[29]))[gpos])
#define gval(x) (((short*)(&s_chan[ch].SB[29]))[(gpos+x)&3])

//#include "gauss_i.h"

////////////////////////////////////////////////////////////////////////

//#include "xa.c"

////////////////////////////////////////////////////////////////////////
// START SOUND... called by main thread to setup a new sound on a channel
////////////////////////////////////////////////////////////////////////

void StartSound(int ch)
{
	StartADSR(ch);
	StartREVERB(ch);

	s_chan[ch].pCurr=s_chan[ch].pStart;                   // set sample start

	s_chan[ch].s_1=0;                                     // init mixing vars
	s_chan[ch].s_2=0;
	s_chan[ch].iSBPos=28;

	s_chan[ch].bNew=0;                                    // init channel flags
	s_chan[ch].bStop=0;
	s_chan[ch].bOn=1;

	s_chan[ch].SB[29]=0;                                  // init our interpolation helpers
	s_chan[ch].SB[30]=0;

	if(iUseInterpolation>=2)                              // gauss interpolation?
	{s_chan[ch].spos=0x30000L;s_chan[ch].SB[28]=0;}  // -> start with more decoding
	else {s_chan[ch].spos=0x10000L;s_chan[ch].SB[31]=0;}  // -> no/simple interpolation starts with one 44100 decoding

	dwNewChannel&=~(1<<ch);                               // clear new channel bit
}

////////////////////////////////////////////////////////////////////////
// MAIN SPU FUNCTION
// here is the main job handler... thread, timer or direct func call
// basically the whole sound processing is done in this fat func!
////////////////////////////////////////////////////////////////////////

// 5 ms waiting phase, if buffer is full and no new sound has to get started
// .. can be made smaller (smallest val: 1 ms), but bigger waits give
// better performance

#define PAUSE_W 5
#define PAUSE_L 5000

////////////////////////////////////////////////////////////////////////

static void *MAINThread(void *arg)
{
//	std::cout << "!!!!!!!!!!!!!!!!!!!TEST!!!!!!!!!!!!!!!!!!" << std::endl;
	int s_1, s_2;
	int fa;
	int ns;
	int voldiv = iVolume;
	unsigned char *start;
	unsigned int nSample;
	int ch, predict_nr, shift_factor, flags, d, s;
	int gpos, bIRQReturn = 0;

	// until we are shutting down
	while(!bEndThread)
	{
		// ok, at the beginning we are looking if there is
		// enuff free place in the dsound/oss buffer to
		// fill in new data, or if there is a new channel to start.
		// if not, we wait (thread) or return (timer/spuasync)
		// until enuff free place is available/a new channel gets
		// started

		// new channel should start immedately?
		// (at least one bit 0 ... MAXCHANNEL is set?)
		if(dwNewChannel)
		{
			// set iSecure
			// (if it is set 5 times - that means on 5 tries a new samples
			// has been started - in a row, we will reset it, to give the
			// sound update a chance)
			iSecureStart++;
			if(iSecureStart > 5)
				iSecureStart = 0;
		}
		// 0: no new channel
		else
			iSecureStart = 0;

		// no new start? no thread end? and still enough data in sound buffer?
		while(!iSecureStart && !bEndThread &&
			(SBE->GetBytesBuffered() > TESTSIZE))
		{
			// reset secure
			iSecureStart = 0;

			// linux no-thread mode? bye
			if(iUseTimer)
				return 0;

			// else sleep for x ms (linux)

#ifndef USE_MINGW
			usleep(PAUSE_L);
#else
			Sleep(PAUSE_L);
#endif

//			SDL_Delay(PAUSE_L);
			if(dwNewChannel)
			// if a new channel kicks in (or, of course,
			// sound buffer runs low), we will leave the loop
				iSecureStart = 1;
		}

		// continue from irq handling in timer mode?
		// will be -1 if no continue is pending
		if(lastch >= 0)
		{
			// -> setup all kind of vars to continue
			ch = lastch;
			ns = lastns;
			lastch = -1;

			// -> directly jump to the continue point
			goto GOON;
		}



		{
			// loop em all... we will collect 1 ms
			// of sound of each playing channel
			for(ch = 0; ch < MAXCHAN; ch++)
			{
				// start new channel
				if(s_chan[ch].bNew)
					StartSound(ch);

				// channel not playing? - next
				if(!s_chan[ch].bOn)
					continue;

				// new psx frequency?
				if(s_chan[ch].iActFreq != s_chan[ch].iUsedFreq)
				{
					// take int and calc steps
					s_chan[ch].iUsedFreq = s_chan[ch].iActFreq;
					s_chan[ch].sinc = s_chan[ch].iRawPitch << 4;
					if(!s_chan[ch].sinc)
						s_chan[ch].sinc = 1;

					// freq change in simple interpolation mode [set flag]
					if(iUseInterpolation == 1)
						s_chan[ch].SB[32] = 1;
				}

				// loop until 1 ms of data is reached
				ns = 0;
				while(ns < NSSIZE)
				{
					while(s_chan[ch].spos >= 0x10000L)
					{
						// 28 reached
						if(s_chan[ch].iSBPos == 28)
						{
							// set up the current pos
							start = s_chan[ch].pCurr;

							// special "stop" sign
							if (start == (unsigned char *)-1)
							{
								// turn everything off
								s_chan[ch].bOn = 0;
								s_chan[ch].ADSRX.lVolume = 0;
								s_chan[ch].ADSRX.EnvelopeVol = 0;

								// and done for this channel
								goto ENDX;
							}

							s_chan[ch].iSBPos = 0;

							// spu irq handler here? mmm... do it later

							s_1 = s_chan[ch].s_1;
							s_2 = s_chan[ch].s_2;

							predict_nr = (int)*start;
							start++;
							shift_factor = predict_nr & 0xf;
							predict_nr >>= 4;
							flags=(int)*start;
							start++;

							for (nSample = 0; nSample < 28; start++)
							{
								d = (int)*start;
								s = ((d & 0xf) << 12);
								if(s & 0x8000)
									s |= 0xffff0000;

								fa = (s >> shift_factor);
								fa = fa + ((s_1 * f[predict_nr][0]) >> 6) +
									((s_2 * f[predict_nr][1]) >> 6);
								s_2 = s_1;
								s_1 = fa;
								s = ((d & 0xf0) << 8);

								s_chan[ch].SB[nSample++] = fa;

								if(s & 0x8000)
									s |= 0xffff0000;
								fa = (s >> shift_factor);
								fa = fa + ((s_1 * f[predict_nr][0]) >> 6) +
									((s_2 * f[predict_nr][1]) >> 6);
								s_2 = s_1;
								s_1 = fa;

								s_chan[ch].SB[nSample++] = fa;
							}

							// irq check? mmm...

							// some callbacks and irq active?
							if(irqCallback && (spuCtrl & 0x40))
							{
								// irq address reached? &
								// special: irq on looping addr,
								// when stop/loop flag is set
								if((pSpuIrq > start - 16 && pSpuIrq <= start)
									||
									((flags & 1) &&
									(pSpuIrq >  s_chan[ch].pLoop - 16 &&
									pSpuIrq <= s_chan[ch].pLoop)))
								{
									// debug flag
									s_chan[ch].iIrqDone = 1;
									// call main emu
									irqCallback();

									// option: wait after irq for main emu
									if(iSPUIRQWait)
									{
										unsigned long dwWatchTime;

										if(iUseTimer == 2)
											bIRQReturn = 1;
										else
										{
//											dwWatchTime = timeGetTime_spu() +
//												2500;
											dwWatchTime = GGetTime() +
												2500;
											iWatchDog = 1;
											while(iWatchDog && !bEndThread &&
												GGetTime() < dwWatchTime)
#ifndef USE_MINGW
			usleep(10);
#else
			Sleep(10);
#endif

//												SDL_Delay(1000L);
										}
									}
								}
							}

							// flag handler

							// loop address
							if((flags & 4) && (!s_chan[ch].bIgnoreLoop))
								s_chan[ch].pLoop = start - 16;

							// stop loop
							if(flags & 1)
							{
								// PETE: if we don't check exactly for 3,
								// loop hang ups will happen (DQ4, for example)
								if(flags != 3 || s_chan[ch].pLoop == NULL)
								{
									// and checking if pLoop is
									// set avoids crashes, yeah
									start = (unsigned char *)-1;
								}
								else
								{
									start = s_chan[ch].pLoop;
								}
							}

							// store values for next cycle
							s_chan[ch].pCurr = start;
							s_chan[ch].s_1 = s_1;
							s_chan[ch].s_2 = s_2;

							// special return for
							// "spu irq - wait for cpu action"
							if(bIRQReturn)
							{
								bIRQReturn = 0;
								lastch = ch;
								lastns = ns;
								return 0;
							}
GOON:
							;
						}

						// get sample data
						fa = s_chan[ch].SB[s_chan[ch].iSBPos++];

						// muted?
						if((spuCtrl & 0x4000) == 0)
							fa = 0;
						// else adjust
						else
						{
							if(fa > 32767L)
								fa = 32767L;
							if(fa < -32767L)
								fa = -32767L;
						}

						// gauss/cubic interpolation
						if(iUseInterpolation >= 2)
						{
							gpos = s_chan[ch].SB[28];
							gval0 = fa;
							gpos = (gpos + 1) & 3;
							s_chan[ch].SB[28] = gpos;
						}
						// simple interpolation
						else if(iUseInterpolation == 1)
						{
							s_chan[ch].SB[28] = 0;
							// helpers for simple linear interpolation:
							// delay real val for two slots, and calc
							// the two deltas, for a
							// 'look at the future behaviour'
							s_chan[ch].SB[29] = s_chan[ch].SB[30];

							s_chan[ch].SB[30] = s_chan[ch].SB[31];
							s_chan[ch].SB[31] = fa;
							// flag: calc new interpolation
							s_chan[ch].SB[32] = 1;
						}
						// no interpolation
						else
							s_chan[ch].SB[29] = fa;

						s_chan[ch].spos -= 0x10000L;
					}

					// noise handler... just produces some noise data
					// surely wrong...
					// and no noise frequency (spuCtrl & 0x3f00) will be used...
					// and sometimes the noise will be
					// used as fmod modulation... pfff

					if(s_chan[ch].bNoise)
					{
						if((dwNoiseVal <<= 1) & 0x80000000L)
						{
							dwNoiseVal ^= 0x0040001L;
							fa = ((dwNoiseVal >> 2) & 0x7fff);
							fa = -fa;
						}
						else
							fa = (dwNoiseVal >> 2) & 0x7fff;

						// mmm... depending on the noise freq we allow
						// bigger/smaller changes to the previous val
						fa = s_chan[ch].iOldNoise +
							((fa - s_chan[ch].iOldNoise) /
							 ((0x001f - ((spuCtrl & 0x3f00) >> 9)) + 1));
						if(fa > 32767L)
							fa = 32767L;
						if(fa < -32767L)
							fa = -32767L;
						s_chan[ch].iOldNoise = fa;

						// no gauss/cubic interpolation?
						if(iUseInterpolation < 2)
							// store noise val in "current sample slot"
							s_chan[ch].SB[29] = fa;
					}
					// NO NOISE (NORMAL SAMPLE DATA) HERE
					else
					{
						// cubic interpolation
						if(iUseInterpolation == 3)
						{
							long xd;
							xd = ((s_chan[ch].spos) >> 1) + 1;
							gpos = s_chan[ch].SB[28];

							fa = gval(3) - 3 * gval(2) + 3 * gval(1) - gval0;
							fa *= (xd - (2 << 15)) / 6;
							fa >>= 15;
							fa += gval(2) - gval(1) - gval(1) + gval0;
							fa *= (xd - (1 << 15)) >> 1;
							fa >>= 15;
							fa += gval(1) - gval0;
							fa *= xd;
							fa >>= 15;
							fa = fa + gval0;
						}
						// gauss interpolation
						else if(iUseInterpolation == 2)
						{
							int vl, vr;
							vl = (s_chan[ch].spos >> 6) & ~3;
							gpos = s_chan[ch].SB[28];
							vr = (gauss[vl] * gval0) & ~2047;
							vr += (gauss[vl + 1] * gval(1)) & ~2047;
							vr += (gauss[vl + 2] * gval(2)) & ~2047;
							vr += (gauss[vl + 3] * gval(3)) & ~2047;
							fa = vr >> 11;
						}
						// simple interpolation
						else if(iUseInterpolation == 1)
						{
							// upsampling?
							if(s_chan[ch].sinc < 0x10000L)
								InterpolateUp(ch);
							else
								InterpolateDown(ch);
							fa = s_chan[ch].SB[29];
						}
						else
							// no interpolation
							fa = s_chan[ch].SB[29];
					}

					// add adsr
					s_chan[ch].sval = (MixADSR(ch) * fa) / 1023;

					// fmod freq channel
					if(s_chan[ch].bFMod == 2)
					{
						int NP = s_chan[ch+1].iRawPitch;

						NP = ((32768L + s_chan[ch].sval) * NP) / 32768L;

						if(NP > 0x3fff)
							NP = 0x3fff;
						if(NP < 0x1)
							NP = 0x1;

						// mmmm... if I do this, all is screwed
						// s_chan[ch+1].iRawPitch=NP;

						// calc frequency
						NP = (44100L * NP) / (4096L);

						s_chan[ch + 1].iActFreq = NP;
						s_chan[ch + 1].iUsedFreq = NP;
						s_chan[ch + 1].sinc = (((NP / 10) << 16) / 4410);
						if(!s_chan[ch + 1].sinc)
							s_chan[ch + 1].sinc = 1;
						// freq change in simple interpolation mode
						if(iUseInterpolation == 1)
							s_chan[ch + 1].SB[32] = 1;

						// mmmm... set up freq decoding positions?
						// s_chan[ch+1].iSBPos=28;
						// s_chan[ch+1].spos=0x10000L;
					}
					else
					{
						// ok, left/right sound volume
						// (psx volume goes from 0 ... 0x3fff)

						// debug mute
						if(s_chan[ch].iMute)
							s_chan[ch].sval = 0;
						else
						{
							SSumL[ns] += (s_chan[ch].sval *
								s_chan[ch].iLeftVolume) / 0x4000L;
							SSumR[ns] += (s_chan[ch].sval *
								s_chan[ch].iRightVolume) / 0x4000L;
						}

						// now let us store sound data for reverb
						if(s_chan[ch].bRVBActive)
							StoreREVERB(ch, ns);
					}

					// ok, go on until 1 ms data
					// of this channel is collected

					ns++;
					s_chan[ch].spos += s_chan[ch].sinc;
				} // while(ns < NSSIZE)
ENDX:
				;
			} // for(ch = 0; ch < MAXCHAN; ch++)
		}

		// here we have another 1 ms of sound data

		// mix XA infos (if any)
		if(XAPlay != XAFeed || XARepeat)
			MixXA();

		// mix all channels (including reverb) into one buffer
/*
		// no stereo?
		if(iDisStereo)
		{
			int dl, dr;
			for(ns = 0; ns < NSSIZE; ns++)
			{
				SSumL[ns] += MixREVERBLeft(ns);

				dl = SSumL[ns] / voldiv;
				SSumL[ns] = 0;
				if(dl < -32767)
					dl = -32767;
				if(dl > 32767)
					dl = 32767;

				SSumR[ns] += MixREVERBRight();

				dr = SSumR[ns] / voldiv;
				SSumR[ns] = 0;
				if(dr < -32767)
					dr = -32767;
				if(dr > 32767)
					dr = 32767;
				*pS++ = (dl + dr) / 2;
			}
		}
		// stereo
		else
*/
			for(ns = 0; ns < NSSIZE; ns++)
			{
				SSumL[ns] += MixREVERBLeft(ns);

				d = SSumL[ns] / voldiv;
				SSumL[ns] = 0;
				if(d < -32767)
					d = -32767;
				if(d > 32767)
					d = 32767;
				*pS++ = d;

				SSumR[ns] += MixREVERBRight();

				d = SSumR[ns] / voldiv;
				SSumR[ns] = 0;
				if(d < -32767)
					d = -32767;
				if(d > 32767)
					d = 32767;
				*pS++ = d;
			}

		InitREVERB();

		// feed the sound
		// wanna have around 1/60 sec (16.666 ms) updates

		//temp fix: lowered for low latency alsa configs
		if(iCycle++ > 8)
		{
			SBE->FeedStreamData((u8 *)pSpuBuffer,
					((unsigned char *)pS) -
					((unsigned char *)pSpuBuffer));
			pS = (short *)pSpuBuffer;
			iCycle = 0;
		}
	}

	// end of big main loop...
	bThreadEnded = 1;

	return 0;
}



void SPUasync(unsigned long cycle)
{
//	std::cout << "*** SPUasync(0x"<< hex << setw(8) << cycle << ")" << std::endl;

	// clear the watchdog
	iWatchDog = 0;

	// special mode, only used in Linux by this spu
	// (or if you enable the experimental Windows mode)
	if(iUseTimer == 2)
	{
		// no init, no call
		if(!bSpuInit)
			return;

		// linux high-compat mode
		MAINThread(0);
	}
}



void SPUupdate(void)
{
#ifdef DEBUG_OUTPUT
	std::cout << "*** SPUupdate()" << std::endl;
#endif
	SPUasync(0);
}



void SPUplayADPCMchannel(xa_decode_t *xap)
{
#ifdef DEBUG_OUTPUT
	std::cout << "*** SPUplayADPCMchannel()" << std::endl;
#endif

	if(!iUseXA)
		return;
	if(!xap)
		return;
	if(!xap->freq)
		return;

	FeedXA(xap);
}



long SPUinit(void)
{
#ifdef DEBUG_OUTPUT
	std::cout << "*** SPUinit()" << std::endl;
#endif

	spuMemC = (unsigned char *)spuMem;
	memset((void *)s_chan, 0, MAXCHAN * sizeof(SPUCHAN));
	memset((void *)&rvb, 0, sizeof(REVERBInfo));
	InitADSR();
	return 0;
}


void SetupTimer(void)
{
	// init some mixing buffers
	memset(SSumR, 0, NSSIZE * sizeof(int));
	memset(SSumL, 0, NSSIZE * sizeof(int));
	// setup soundbuffer pointer
	pS = (short *)pSpuBuffer;

	// init thread vars
	bEndThread = 0;
	bThreadEnded = 0;
	// flag: we are inited
	bSpuInit = 1;
}


void RemoveTimer(void)
{
	// raise flag to end thread
	bEndThread = 1;

	if(!iUseTimer)
	{
		int i = 0;
		// wait until thread has ended
		while(!bThreadEnded && i < 2000)
		{
#ifndef USE_MINGW
			usleep(10);
#else
			Sleep(10);
#endif
//			SDL_Delay(1000L);
			i++;
		}
	}

	// no more spu is running
	bThreadEnded = 0;
	bSpuInit = 0;
}


void SetupStreams(void)
{
	int i;

	// alloc mixing buffer
	pSpuBuffer = (unsigned char *)malloc(32768);

	if(iUseReverb == 1)
		i = 88200 * 2;
	else
		i = NSSIZE * 2;

	// alloc reverb buffer
	sRVBStart = (int *)malloc(i * 4);
	memset(sRVBStart, 0, i * 4);
	sRVBEnd = sRVBStart + i;
	sRVBPlay = sRVBStart;

	// alloc xa buffer
	XAStart = (u32 *)malloc(44100 * 4);
	XAPlay = XAStart;
	XAFeed = XAStart;
	XAEnd = XAStart + 44100;

	for(i = 0; i < MAXCHAN; i++)
	{
		// we don't use mutex sync... not needed, would only
		// slow us down:

		// init sustain
		s_chan[i].ADSRX.SustainLevel = 1024;
		s_chan[i].iMute = 0;
		s_chan[i].iIrqDone = 0;
		s_chan[i].pLoop = spuMemC;
		s_chan[i].pStart = spuMemC;
		s_chan[i].pCurr = spuMemC;
	}
}


void RemoveStreams(void)
{
	// free mixing buffer
	free(pSpuBuffer);
	pSpuBuffer = NULL;
	// free reverb buffer
	free(sRVBStart);
	sRVBStart = 0;
	// free xa buffer
	free(XAStart);
	XAStart = 0;
}



long SPUopen(void)
{
#ifdef DEBUG_OUTPUT
	std::cout << "*** SPUopen()" << std::endl;
#endif

	// security for some stupid main emus
	if(bSPUIsOpen)
		return 0;

	iUseXA = 1;
	iVolume = 3;
	iReverbOff = -1;
	spuIrq = 0;
	spuAddr = 0xffffffff;
	bEndThread = 0;
	bThreadEnded = 0;
	spuMemC = (unsigned char *)spuMem;
	memset((void *)s_chan, 0, (MAXCHAN + 1) * sizeof(SPUCHAN));
	pSpuIrq = 0;
	iSPUIRQWait = 1;

	SBE = new SoundBackendSDL();

	// prepare streaming
	SetupStreams();

	// timer for feeding data
	SetupTimer();

	bSPUIsOpen = 1;

	return PSE_SPU_ERR_SUCCESS;
}



void SPUsetConfigFile(char * pCfg)
{
#ifdef DEBUG_OUTPUT
	std::cout << "*** SPUsetConfigFile()" << std::endl;
#endif

//	pConfigFile = pCfg;
}



long SPUclose(void)
{
#ifdef DEBUG_OUTPUT
	std::cout << "*** SPUclose()" << std::endl;
#endif

	// security
	if(!bSPUIsOpen)
		return 0;

	bSPUIsOpen = 0;
	RemoveTimer();

	if(SBE != NULL)
		delete SBE;

	RemoveStreams();

	return 0;
}



long SPUshutdown(void)
{
#ifdef DEBUG_OUTPUT
	std::cout << "*** SPUshutdown()" << std::endl;
#endif

	return 0;
}



long SPUtest(void)
{
#ifdef DEBUG_OUTPUT
	std::cout << "*** SPUtest()" << std::endl;
#endif

	return 0;
}



long SPUconfigure(void)
{
#ifdef DEBUG_OUTPUT
	std::cout << "*** SPUconfigure()" << std::endl;
#endif

//G	StartCfgTool("CFG");
	return 0;
}



void SPUabout(void)
{
#ifdef DEBUG_OUTPUT
	std::cout << "*** SPUabout()" << std::endl;
#endif

//G	StartCfgTool("ABOUT");
}



void SPUregisterCallback(void (*callback)(void))
{
#ifdef DEBUG_OUTPUT
	std::cout << "*** SPUregisterCallback()" << std::endl;
#endif

	irqCallback = callback;
}



void SPUregisterCDDAVolume(void (*CDDAVcallback)(unsigned short,unsigned short))
{
#ifdef DEBUG_OUTPUT
	std::cout << "*** SPUregisterCDDAVolume()" << std::endl;
#endif

	cddavCallback = CDDAVcallback;
}



unsigned short SPUgetOne(unsigned long val)
{
#ifdef DEBUG_OUTPUT
	std::cout << "*** SPUgetOne()" << std::endl;
#endif

	if(spuAddr != 0xffffffff)
	{
		return SPUreadDMA();
	}
	if(val >= 512 * 1024)
		val = 512 * 1024 - 1;
	return spuMem[val >> 1];
}



void SPUputOne(unsigned long val, unsigned short data)
{
#ifdef DEBUG_OUTPUT
	std::cout << "*** SPUputOne()" << std::endl;
#endif

	if(spuAddr != 0xffffffff)
	{
		SPUwriteDMA(data);
		return;
	}
	if(val >= 512 * 1024)
		val = 512 * 1024 - 1;
	spuMem[val >> 1] = data;
}



void SPUplaySample(unsigned char ch)
{
#ifdef DEBUG_OUTPUT
	std::cout << "*** SPUplaySample()" << std::endl;
#endif
}



void SPUsetAddr(unsigned char ch, unsigned short waddr)
{
#ifdef DEBUG_OUTPUT
	std::cout << "*** SPUsetAddr()" << std::endl;
#endif

	s_chan[ch].pStart = spuMemC + ((unsigned long)waddr << 3);
}



void SPUsetPitch(unsigned char ch, unsigned short pitch)
{
#ifdef DEBUG_OUTPUT
	std::cout << "*** SPUsetPitch()" << std::endl;
#endif

	SetPitch(ch, pitch);
}



void SPUsetVolumeL(unsigned char ch, short vol)
{
#ifdef DEBUG_OUTPUT
	std::cout << "*** SPUsetVolumeL()" << std::endl;
#endif

	SetVolumeR(ch, vol);
}



void SPUsetVolumeR(unsigned char ch, short vol)
{
#ifdef DEBUG_OUTPUT
	std::cout << "*** SPUsetVolumeR()" << std::endl;
#endif

	SetVolumeL(ch, vol);
}



void SPUstartChannels1(unsigned short channels)
{
#ifdef DEBUG_OUTPUT
	std::cout << "*** SPUstartChannels1()" << std::endl;
#endif

	SoundOn(0, 16, channels);
}



void SPUstartChannels2(unsigned short channels)
{
#ifdef DEBUG_OUTPUT
	std::cout << "*** SPUstartChannels2()" << std::endl;
#endif

	SoundOn(16, 24, channels);
}



void SPUstopChannels1(unsigned short channels)
{
#ifdef DEBUG_OUTPUT
	std::cout << "*** SPUstopChannels1()" << std::endl;
#endif

	SoundOff(0, 16, channels);
}



void SPUstopChannels2(unsigned short channels)
{
#ifdef DEBUG_OUTPUT
	std::cout << "*** SPUstopChannels2()" << std::endl;
#endif

	SoundOff(16, 24, channels);
}



void SPUplaySector(unsigned long mode, unsigned char *p)
{
#ifdef DEBUG_OUTPUT
	std::cout << "*** SPUplaySector()\n" << std::endl;
#endif

	// no XA
	if(!iUseXA)
		return;
}


u32 GGetTime()
{
	// well, maybe there are better ways
	// to do that, but at least it works
	struct timeval tv;
	gettimeofday(&tv, 0);

	return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

