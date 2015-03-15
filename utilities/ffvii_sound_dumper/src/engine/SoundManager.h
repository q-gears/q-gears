/*
 * Main source code was taken from Pete's PSX sound plugin.
 * I plan full source reorganising - want to set more sound
 * engine behaviour
 */



#ifndef SOUND_MANAGER_H
#define SOUND_MANAGER_H



#include "common/TypeDefine.h"



class SoundManager
{
public:
    SoundManager();
    virtual ~SoundManager();

    void Update();

    void PsxChannelPlay(u8 arg_channel);
    void PsxChannelStop(u8 arg_channel);
    void PsxReverbOn(u8 arg_channel);
    void PsxSetReverbDepth( u16 arg_left, u16 arg_right );

    enum SpuRateMode
    {
        SPU_VOICE_LINEARIncN = 1,
        SPU_VOICE_LINEARDecN = 3,
        SPU_VOICE_EXPIncN    = 5,
        SPU_VOICE_EXPDec     = 7
    };

    static const u32 m_PSX_SPU_BASE = 0x1F801C00;

    void SetVoiceStartAddress(u8 arg_voice, u32 arg_address);
    void SetVoiceLoopAddress(u8 arg_voice, u32 arg_address);
    void SetVoiceVolume(u8 arg_voice, s16 arg_volume_left, s16 arg_volume_right);
    void SetVoicePitch(u8 arg_voice, u16 arg_pitch);
    void SetVoiceAttackRate(u8 arg_voice, u16 arg_rate, SpuRateMode arg_mode);
    void SetVoiceSustainRate(u8 arg_voice, u16 arg_rate, SpuRateMode arg_mode);
    void SetVoiceReleaseRate(u8 arg_voice, u16 arg_rate, SpuRateMode arg_mode);
    void SetVoiceDecayRate(u8 arg_voice, u16 arg_rate);
    void SetVoiceSustainLevel(u8 arg_voice, u16 arg_level);

    static const u32 m_REGISTER_BASE = 0x1f801c00;

    bool PsxWriteDMA(u16 arg_address, u8 *arg_data, u32 arg_length);
};



extern SoundManager *SOUNDMAN;

void InitADSR();
void StartADSR(int ch);
int MixADSR(int ch);



// PETE ///////////////
unsigned short SPUreadDMA();
void SPUreadDMAMem( unsigned short *pusPSXMem, int iSize );
void SPUwriteDMA( unsigned short val );
void SPUwriteDMAMem( unsigned short *pusPSXMem, int iSize );
// PETE ///////////////




extern const int gauss[];

#define H_SPUReverbAddr  0x0da2
#define H_SPUirqAddr     0x0da4
#define H_SPUaddr        0x0da6
#define H_SPUdata        0x0da8
#define H_SPUctrl        0x0daa
#define H_SPUstat        0x0dae
#define H_SPUmvolL       0x0d80
#define H_SPUmvolR       0x0d82
#define H_SPUrvolL       0x0d84
#define H_SPUrvolR       0x0d86
#define H_SPUon1         0x0d88
#define H_SPUon2         0x0d8a
#define H_SPUoff1        0x0d8c
#define H_SPUoff2        0x0d8e
#define H_FMod1          0x0d90
#define H_FMod2          0x0d92
#define H_Noise1         0x0d94
#define H_Noise2         0x0d96
#define H_RVBon1         0x0d98
#define H_RVBon2         0x0d9a
#define H_SPUMute1       0x0d9c
#define H_SPUMute2       0x0d9e
#define H_CDLeft         0x0db0
#define H_CDRight        0x0db2
#define H_ExtLeft        0x0db4
#define H_ExtRight       0x0db6
#define H_Reverb         0x0dc0
#define H_SPUPitch0      0x0c04
#define H_SPUPitch1      0x0c14
#define H_SPUPitch2      0x0c24
#define H_SPUPitch3      0x0c34
#define H_SPUPitch4      0x0c44
#define H_SPUPitch5      0x0c54
#define H_SPUPitch6      0x0c64
#define H_SPUPitch7      0x0c74
#define H_SPUPitch8      0x0c84
#define H_SPUPitch9      0x0c94
#define H_SPUPitch10     0x0ca4
#define H_SPUPitch11     0x0cb4
#define H_SPUPitch12     0x0cc4
#define H_SPUPitch13     0x0cd4
#define H_SPUPitch14     0x0ce4
#define H_SPUPitch15     0x0cf4
#define H_SPUPitch16     0x0d04
#define H_SPUPitch17     0x0d14
#define H_SPUPitch18     0x0d24
#define H_SPUPitch19     0x0d34
#define H_SPUPitch20     0x0d44
#define H_SPUPitch21     0x0d54
#define H_SPUPitch22     0x0d64
#define H_SPUPitch23     0x0d74

#define H_SPUStartAdr0   0x0c06
#define H_SPUStartAdr1   0x0c16
#define H_SPUStartAdr2   0x0c26
#define H_SPUStartAdr3   0x0c36
#define H_SPUStartAdr4   0x0c46
#define H_SPUStartAdr5   0x0c56
#define H_SPUStartAdr6   0x0c66
#define H_SPUStartAdr7   0x0c76
#define H_SPUStartAdr8   0x0c86
#define H_SPUStartAdr9   0x0c96
#define H_SPUStartAdr10  0x0ca6
#define H_SPUStartAdr11  0x0cb6
#define H_SPUStartAdr12  0x0cc6
#define H_SPUStartAdr13  0x0cd6
#define H_SPUStartAdr14  0x0ce6
#define H_SPUStartAdr15  0x0cf6
#define H_SPUStartAdr16  0x0d06
#define H_SPUStartAdr17  0x0d16
#define H_SPUStartAdr18  0x0d26
#define H_SPUStartAdr19  0x0d36
#define H_SPUStartAdr20  0x0d46
#define H_SPUStartAdr21  0x0d56
#define H_SPUStartAdr22  0x0d66
#define H_SPUStartAdr23  0x0d76

#define H_SPULoopAdr0   0x0c0e
#define H_SPULoopAdr1   0x0c1e
#define H_SPULoopAdr2   0x0c2e
#define H_SPULoopAdr3   0x0c3e
#define H_SPULoopAdr4   0x0c4e
#define H_SPULoopAdr5   0x0c5e
#define H_SPULoopAdr6   0x0c6e
#define H_SPULoopAdr7   0x0c7e
#define H_SPULoopAdr8   0x0c8e
#define H_SPULoopAdr9   0x0c9e
#define H_SPULoopAdr10  0x0cae
#define H_SPULoopAdr11  0x0cbe
#define H_SPULoopAdr12  0x0cce
#define H_SPULoopAdr13  0x0cde
#define H_SPULoopAdr14  0x0cee
#define H_SPULoopAdr15  0x0cfe
#define H_SPULoopAdr16  0x0d0e
#define H_SPULoopAdr17  0x0d1e
#define H_SPULoopAdr18  0x0d2e
#define H_SPULoopAdr19  0x0d3e
#define H_SPULoopAdr20  0x0d4e
#define H_SPULoopAdr21  0x0d5e
#define H_SPULoopAdr22  0x0d6e
#define H_SPULoopAdr23  0x0d7e

#define H_SPU_ADSRLevel0   0x0c08
#define H_SPU_ADSRLevel1   0x0c18
#define H_SPU_ADSRLevel2   0x0c28
#define H_SPU_ADSRLevel3   0x0c38
#define H_SPU_ADSRLevel4   0x0c48
#define H_SPU_ADSRLevel5   0x0c58
#define H_SPU_ADSRLevel6   0x0c68
#define H_SPU_ADSRLevel7   0x0c78
#define H_SPU_ADSRLevel8   0x0c88
#define H_SPU_ADSRLevel9   0x0c98
#define H_SPU_ADSRLevel10  0x0ca8
#define H_SPU_ADSRLevel11  0x0cb8
#define H_SPU_ADSRLevel12  0x0cc8
#define H_SPU_ADSRLevel13  0x0cd8
#define H_SPU_ADSRLevel14  0x0ce8
#define H_SPU_ADSRLevel15  0x0cf8
#define H_SPU_ADSRLevel16  0x0d08
#define H_SPU_ADSRLevel17  0x0d18
#define H_SPU_ADSRLevel18  0x0d28
#define H_SPU_ADSRLevel19  0x0d38
#define H_SPU_ADSRLevel20  0x0d48
#define H_SPU_ADSRLevel21  0x0d58
#define H_SPU_ADSRLevel22  0x0d68
#define H_SPU_ADSRLevel23  0x0d78

// we have a timebase of 1.020408f ms, not 1 ms... so adjust adsr defines
#define ATTACK_MS      494L
#define DECAYHALF_MS   286L
#define DECAY_MS       572L
#define SUSTAIN_MS     441L
#define RELEASE_MS     437L

#ifndef _MSC_VER
#ifndef LOWORD
#define LOWORD(l)    ((unsigned short)(l))
#endif

#ifndef HIWORD
#define HIWORD(l)    ((unsigned short)(((unsigned long)(l) >> 16) & 0xFFFF))
#endif
#endif

extern int bSPUIsOpen;


typedef struct
{
	long y0, y1;
} ADPCM_Decode_t;

typedef struct
{
	int freq;
	int nbits;
	int stereo;
	int nsamples;
	ADPCM_Decode_t left, right;
	short pcm[16384];
} xa_decode_t;



extern xa_decode_t *xapGlobal;

extern u32 *XAFeed;
extern u32 *XAPlay;
extern u32 *XAStart;
extern u32 *XAEnd;

extern u32 XARepeat;
extern u32 XALastVal;

extern int iLeftXAVol;
extern int iRightXAVol;

#define PSE_LT_SPU                  4
#define PSE_SPU_ERR_SUCCESS         0
#define PSE_SPU_ERR                 -60
#define PSE_SPU_ERR_NOTCONFIGURED   PSE_SPU_ERR - 1
#define PSE_SPU_ERR_INIT            PSE_SPU_ERR - 2
#ifndef max
#define max(a,b)            (((a) > (b)) ? (a) : (b))
#define min(a,b)            (((a) < (b)) ? (a) : (b))
#endif

// 137 ms test buffer... if less than that is buffered, a new upload will happen
#define TESTSIZE    24192
// num of channels
#define MAXCHAN     24
// ~ 1 ms of data
#define NSSIZE 45



// ADSR infos per channel
typedef struct
{
	int            AttackModeExp;
	long           AttackTime;
	long           DecayTime;
	long           SustainLevel;
	int            SustainModeExp;
	long           SustainModeDec;
	long           SustainTime;
	int            ReleaseModeExp;
	unsigned long  ReleaseVal;
	long           ReleaseTime;
	long           ReleaseStartTime;
	long           ReleaseVol;
	long           lTime;
	long           lVolume;
} ADSRInfo;

typedef struct
{
	int            State;
	int            AttackModeExp;
	int            AttackRate;
	int            DecayRate;
	int            SustainLevel;
	int            SustainModeExp;
	int            SustainIncrease;
	int            SustainRate;
	int            ReleaseModeExp;
	int            ReleaseRate;
	int            EnvelopeVol;
	long           lVolume;
	long           lDummy1;
	long           lDummy2;
} ADSRInfoEx;

// used for debug channel muting
#define FLAG_MUTE  1
// used for simple interpolation
#define FLAG_IPOL0 2
#define FLAG_IPOL1 4


// MAIN CHANNEL STRUCT
typedef struct
{
	int bNew;              // start flag
	int iSBPos;            // mixing stuff
	int spos;
	int sinc;
	int SB[32 + 32];       // Pete added another 32 dwords in 1.6 ...
	                       // prevents overflow issues with gaussian/cubic
						   // interpolation (thanx xodnizel!), and can be
						   // used for even better interpolations, eh? :)
	int sval;

	unsigned char *pStart; // start ptr into sound mem
	unsigned char *pCurr;  // current pos in sound mem
	unsigned char *pLoop;  // loop ptr in sound mem

	int bOn;               // is channel active (sample playing?)
	int bStop;             // is ch stop (can still be playing, if ADSR Release)
	int bReverb;           // reverb, must have ctrl register bit, to get active
	int iActFreq;          // current psx pitch
	int iUsedFreq;         // current pc pitch
	int iLeftVolume;       // left volume
	int iLeftVolRaw;       // left psx volume value
	int bIgnoreLoop;       // ignore loop, if an external loop address is used
	int iMute;             // mute mode
	int iRightVolume;      // right volume
	int iRightVolRaw;      // right psx volume value
	int iRawPitch;         // raw pitch (0...3fff)
	int iIrqDone;          // debug irq done flag
	int s_1;               // last decoding infos
	int s_2;
	int bRVBActive;        // reverb active flag
	int iRVBOffset;        // reverb offset
	int iRVBRepeat;        // reverb repeat
	int bNoise;            // noise active flag
	int bFMod;             // freq mod (0=off, 1=sound channel, 2=freq channel)
	int iRVBNum;           // another reverb helper
	int iOldNoise;         // old noise val for this channel
	ADSRInfo ADSR;         // active ADSR settings
	ADSRInfoEx ADSRX;      // next ADSR settings
					       // (will be moved to active on sample start)
} SPUCHAN;


// REVERB
typedef struct
{
	int StartAddr;      // reverb area start addr in samples
	int CurrAddr;       // reverb area curr addr in samples

	int VolLeft;
	int VolRight;
	int iLastRVBLeft;
	int iLastRVBRight;
	int iRVBLeft;
	int iRVBRight;


	int FB_SRC_A;       // (offset)
	int FB_SRC_B;       // (offset)
	int IIR_ALPHA;      // (coef.)
	int ACC_COEF_A;     // (coef.)
	int ACC_COEF_B;     // (coef.)
	int ACC_COEF_C;     // (coef.)
	int ACC_COEF_D;     // (coef.)
	int IIR_COEF;       // (coef.)
	int FB_ALPHA;       // (coef.)
	int FB_X;           // (coef.)
	int IIR_DEST_A0;    // (offset)
	int IIR_DEST_A1;    // (offset)
	int ACC_SRC_A0;     // (offset)
	int ACC_SRC_A1;     // (offset)
	int ACC_SRC_B0;     // (offset)
	int ACC_SRC_B1;     // (offset)
	int IIR_SRC_A0;     // (offset)
	int IIR_SRC_A1;     // (offset)
	int IIR_DEST_B0;    // (offset)
	int IIR_DEST_B1;    // (offset)
	int ACC_SRC_C0;     // (offset)
	int ACC_SRC_C1;     // (offset)
	int ACC_SRC_D0;     // (offset)
	int ACC_SRC_D1;     // (offset)
	int IIR_SRC_B1;     // (offset)
	int IIR_SRC_B0;     // (offset)
	int MIX_DEST_A0;    // (offset)
	int MIX_DEST_A1;    // (offset)
	int MIX_DEST_B0;    // (offset)
	int MIX_DEST_B1;    // (offset)
	int IN_COEF_L;      // (coef.)
	int IN_COEF_R;      // (coef.)
} REVERBInfo;


extern char * pConfigFile;

extern int *          sRVBPlay;
extern int *          sRVBEnd;
extern int *          sRVBStart;
extern int            iReverbOff;
extern int            iReverbRepeat;
extern int            iReverbNum;

// psx buffers / addresses
extern unsigned short  regArea[];
extern unsigned short  spuMem[];
extern unsigned char * spuMemC;
extern unsigned char * pSpuIrq;
extern unsigned char * pSpuBuffer;

// user settings
extern int        iUseXA;
extern int        iVolume;
extern int        iXAPitch;
extern int        iUseTimer;
extern int        iSPUIRQWait;
extern int        iDebugMode;
extern int        iRecordMode;
extern int        iUseReverb;
extern int        iUseInterpolation;
extern int        iDisStereo;
// MISC

extern int iWatchDog;

//extern SPUCHAN s_chan[];
extern REVERBInfo rvb;

extern unsigned long dwNoiseVal;
extern unsigned short spuCtrl;
extern unsigned short spuStat;
extern unsigned short spuIrq;
extern unsigned long  spuAddr;
extern int      bEndThread;
extern int      bThreadEnded;
extern int      bSpuInit;
extern unsigned long dwNewChannel;

extern int      SSumR[];
extern int      SSumL[];
extern int      iCycle;
extern short *  pS;

extern void (*cddavCallback)(unsigned short,unsigned short);
extern SPUCHAN s_chan[];



void SPUwriteRegister(unsigned long reg, unsigned short val);
unsigned short SPUreadRegister(unsigned long reg);
void SoundOn(int start, int end, unsigned short val);
void SoundOff(int start, int end, unsigned short val);
void FModOn(int start, int end, unsigned short val);
void NoiseOn(int start, int end, unsigned short val);
void SetVolumeL(unsigned char ch, short vol);
void SetVolumeR(unsigned char ch, short vol);
void SetPitch(int ch, unsigned short val);
void ReverbOn(int start, int end, unsigned short val);

void SetREVERB(unsigned short val);
void StartREVERB(int ch);
void InitREVERB();
void StoreREVERB(int ch, int ns);
int g_buffer(int iOff);
void s_buffer(int iOff, int iVal);
void s_buffer1(int iOff, int iVal);
int MixREVERBLeft(int ns);
int MixREVERBRight();

void MixXA();
void FeedXA(xa_decode_t *xap);

long SPUinit(void);
long SPUopen(void);
long SPUclose(void);
void SPUasync(unsigned long cycle);
void SPUplayADPCMchannel(xa_decode_t *xap);
unsigned short SPUgetOne(unsigned long val);
void SPUputOne(unsigned long val,unsigned short data);
void SPUplaySample(unsigned char ch);
void SPUsetAddr(unsigned char ch, unsigned short waddr);
void SPUsetPitch(unsigned char ch, unsigned short pitch);
void SPUsetVolumeL(unsigned char ch, short vol);
void SPUsetVolumeR(unsigned char ch, short vol);
void SPUstartChannels1(unsigned short channels);
void SPUstartChannels2(unsigned short channels);
void SPUstopChannels1(unsigned short channels);
void SPUstopChannels2(unsigned short channels);
void SPUplaySector(unsigned long mode, unsigned char * p);
u32 GGetTime();



#endif

