#ifndef AKAO_PARSER_HH__
#define AKAO_PARSER_HH__



#include <inttypes.h>
#include <vector>
#include "common/typedefs.h"



using namespace std;



class AkaoParser
{

public:

	AkaoParser();
	virtual ~AkaoParser();

	// voice routines
	int LoadVoiceData(const char *arg_all_file,
		const char *arg_dat_file);
	void UnloadVoiceData();
	int GetVoicesCount();

	// sequence routines
	int LoadSequenceData(const char *arg_file);
	void UnloadSequenceData();
	int PlaySequenceData();
	void StopSequenceData();

	template <typename T>
	T StreamRead(int arg_ch)
	{
		T result = *(T *)&m_CD[arg_ch].stream[m_CD[arg_ch].current_pos];
		m_CD[arg_ch].current_pos += sizeof(result);
		return result;
	}

	void Update(int arg_delta);

	// debug routines
	int DumpSequenceData(const char *arg_file);
	void AerisTest();

private:

	/* TYPE DEFINES */
	typedef void (AkaoParser::*OpcodeProcessor)(int);


	/* CONSTANTS */
	static const  int m_AKAO_INSTR_ALL_SHIFT = 0xff0;
	static const char *m_AKAO_MAGIC;
	static const  int m_AKAO_CHANNELS_COUNT = 24;
	static const  int m_AKAO_OPCODES_COUNT = 0x60;
	static const   u8 m_AKAO_PAUSE_TABLE[11];
	static const  int m_AKAO_DEFAULT_VOLUME_MODIFIER = 0x7f;
	static const  s16 m_AKAO_VOLUME_TABLE_L[256];
	static const  s16 m_AKAO_VOLUME_TABLE_R[256];
	static const  s16 m_AKAO_WAVE_TABLE[708];
	static const  u16 m_AKAO_WAVE_TABLE_KEY_NODES[16];
	static const  int m_AKAO_TIME_CONSTANT = 280000;


	/* ENUMERATIONS */
	enum SpuParameter
	{
		SPU_VOLUME_LEFT   = 1 <<  0,
		SPU_VOLUME_RIGHT  = 1 <<  1,
		SPU_PITCH         = 1 <<  4,
		SPU_ADDRESS_START = 1 <<  7,
		SPU_ATTACK_RATE   = 1 <<  8,
		SPU_SUSTAIN_RATE  = 1 <<  9,
		SPU_RELEASE_RATE  = 1 << 10,
		SPU_ATTACK_MODE   = 1 << 11,
		SPU_DECAY_RATE    = 1 << 12,
		SPU_SUSTAIN_MODE  = 1 << 13,
		SPU_RELEASE_MODE  = 1 << 14,
		SPU_SUSTAIN_LEVEL = 1 << 15,
		SPU_ADDRESS_LOOP  = 1 << 16,

		// CUSTOM
		SPU_REVERB        = 1 << 23,
		SPU_REVERB_DEPTH_LEFT     = 1 << 24,
		SPU_REVERB_DEPTH_RIGHT    = 1 << 25
	};


	/* STRUCTURES */
	struct VoiceIndex
	{
		union
		{
			u32 attack_offset;
			u32 length;
		};
		u32 loop_offset;
		u8 attack_rate;
		u8 decay_rate;
		u8 sustain_level;
		u8 sustain_rate;
		u8 release_rate;
		u8 attack_mode;
		u8 sustain_mode;
		u8 release_mode;
		u32 pitch[12];
	};

	struct AkaoHeader
	{
		u8 magic[4];
		u16 id;
		u16 length;
		u16 reverb_mode;
		u8 unused[6];
	};

	struct SpuConfig
	{
		u32 refresh_flags;

		u32 address_start;
		u32 address_loop;
		s16 volume_left;
		s16 volume_right;
		u16 pitch;

		// adsr
		u16 attack_rate;
		u16 attack_mode;
		u16 decay_rate;
		u16 sustain_rate;
		u16 sustain_mode;
		u16 sustain_level;
		u16 release_rate;
		u16 release_mode;

		// custom
		u16 reverb;
		s16 reverb_depth_left;
		s16 reverb_depth_right;
	};

	struct AkaoChannelData
	{
		// voice
		u8 voice_index;

		// position
		u16 current_pos;
		u16 saved_pos_index;
		u16 saved_pos[4];
		u16 saved_unknown[4];

		// pause
		// ch[0x56]
		u8 pause;
		// ch[0xc2]
		u16 pause_index;
		// ch[0xc4]
		u16 pause_multiplier;

		// pitch
		// ch[0x30] and other pitch duplications
		u16 pitch_base;
		// ch[0x36]
		s16 pitch_unknown1;
		// used in 8002f1f8, investigate later
		u8 pitch_80062fe6;
		// ch[0x66]
		u8 pitch_correction;
		// ch[0xcc]
		s8 pitch_selector;
		// ch[0xce]
		s8 pitch_modifier;
		// ch[0xd0]
		u16 pitch_saved_parameters;
		// ch[0xd6]
		s16 pitch_wave_shift;

		// volume
		// ch[0x2c]
		u8 volume_multiplier;
		// ch[0x44]
		s32 volume_level;
		// ch[0x48]
		s32 volume_level_new;
		// ch[0x5c]
		u16 volume_level_change_ticks;
		bool volume_level_changed;
		// ch[0x60]
		u8 volume_index;
		bool volume_index_changed;

		// wave
		// ch[0x72]
		u16 wave_delay;
		// ch[0x74]
		u16 wave_delay_current;
		// ch[0x76]
		u16 wave_refresh_interval;
		// ch[0x78]
		u16 wave_refresh_interval_current;
		// ch[0x7a]
		u8 wave_table_node_index;
		// ch[0x7c]
		s16 wave_multiplier;
		// ch[0x7e]
		s16 wave_modifier;
		// ch[0x18]
		u16 wave_table_index;
		// ch[0x38] & 1
		bool wave_loaded;

		// mirror
		// ch[0x24]
		int mirror;
		bool mirror_enabled;

		// channel stream
		u8 *stream;
		u16 stream_length;

		SpuConfig spu_config;
	};


	/* FIELDS */
	// voice variables
	vector<string> m_VoiceFilenames;
	vector<VoiceIndex> m_VoiceIndex;
	vector<u8 *> m_VoiceData;

	// sequence variables
	AkaoHeader m_SequenceHeader;
	string m_SequenceDataFilename;
	AkaoChannelData m_CD[m_AKAO_CHANNELS_COUNT];
	u16 m_Tempo;
	int m_MSPassed;
	int m_MSPeriodicalPassed;

	// processing variables
	bool m_IsPlaying;


	/* METHODS */
	// helper array for opcode processing
	static OpcodeProcessor m_ProcessOpcode[m_AKAO_OPCODES_COUNT];
	static const int m_KnownOpcodes[m_AKAO_OPCODES_COUNT];
	static const int m_OpcodesParametersCount[m_AKAO_OPCODES_COUNT];

	// processing
	void PeriodicalProcess(int arg_delta);
	void OpcodeProcess(int arg_delta);

	// HAL
	void SpuSetParameter(SpuConfig &arg_cfg, SpuParameter arg_param,
			u32 arg_value);
	void SpuUpdate();

	// too big prototype list, separated
#define AKAO_PARSER_INSIDE
	#include "AkaoParserOpcodes.hh"
#undef AKAO_PARSER_INSIDE

	// miscellaneous
	void LoadVoice(int arg_ch, int arg_voice);
	void RefreshWaveParameters(int arg_ch);

	// debug routines
	void PrintOpcode(int arg_ch, u8 arg_opc);

	// FIXME!!
	vector<u32> m_PsxAttackOffset;
	vector<u32> m_PsxLoopOffset;
};



extern AkaoParser *AKAOMAN;



#endif

