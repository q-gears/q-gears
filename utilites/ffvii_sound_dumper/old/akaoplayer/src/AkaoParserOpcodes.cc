#include <iostream>
#include <iomanip>
#include "AkaoParser.hh"



const int AkaoParser::m_KnownOpcodes[m_AKAO_OPCODES_COUNT] =
{
//	0  1  2  3  4  5  6  7  8  9  A  B  C  D  E  F
	1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, // A
	0, 1, 1, 0, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, // B
	1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, // C
	1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, // D
	1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, // E
	1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1  // F
};


const int AkaoParser::m_OpcodesParametersCount[m_AKAO_OPCODES_COUNT] =
{
//	0  1  2  3  4  5  6  7  8  9  A  B  C  D  E  F
	0, 1, 1, 1, 2, 1, 0, 0, 1, 2, 1, 2, 1, 1, 1, 1, // A
	2, 1, 1, 0, 3, 1, 0, 1, 3, 1, 0, 1, 2, 1, 0, 1, // B
	1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, // C
	0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 1, 2, 2, 2, // D
	0, 0, 0, 0, 0, 0, 0, 0, 2, 3, 2, 3, 2, 0, 2, 3, // E
	3, 3, 1, 0, 2, 0, 1, 2, 1, 0, 0, 0, 0, 2, 2, 0, // F
};


AkaoParser::OpcodeProcessor
AkaoParser::m_ProcessOpcode[m_AKAO_OPCODES_COUNT] =
{
	&AkaoParser::OpcodeA0, &AkaoParser::OpcodeA1,
	&AkaoParser::OpcodeA2, &AkaoParser::OpcodeA3,
	&AkaoParser::OpcodeA4, &AkaoParser::OpcodeA5,
	&AkaoParser::OpcodeA6, &AkaoParser::OpcodeA7,
	&AkaoParser::OpcodeA8, &AkaoParser::OpcodeA9,
	&AkaoParser::OpcodeAA, &AkaoParser::OpcodeAB,
	&AkaoParser::OpcodeAC, &AkaoParser::OpcodeAD,
	&AkaoParser::OpcodeAE, &AkaoParser::OpcodeAF,

	&AkaoParser::OpcodeB0, &AkaoParser::OpcodeB1,
	&AkaoParser::OpcodeB2, &AkaoParser::OpcodeB3,
	&AkaoParser::OpcodeB4, &AkaoParser::OpcodeB5,
	&AkaoParser::OpcodeB6, &AkaoParser::OpcodeB7,
	&AkaoParser::OpcodeB8, &AkaoParser::OpcodeB9,
	&AkaoParser::OpcodeBA, &AkaoParser::OpcodeBB,
	&AkaoParser::OpcodeBC, &AkaoParser::OpcodeBD,
	&AkaoParser::OpcodeBE, &AkaoParser::OpcodeBF,

	&AkaoParser::OpcodeC0, &AkaoParser::OpcodeC1,
	&AkaoParser::OpcodeC2, &AkaoParser::OpcodeC3,
	&AkaoParser::OpcodeC4, &AkaoParser::OpcodeC5,
	&AkaoParser::OpcodeC6, &AkaoParser::OpcodeC7,
	&AkaoParser::OpcodeC8, &AkaoParser::OpcodeC9,
	&AkaoParser::OpcodeCA, &AkaoParser::OpcodeCB,
	&AkaoParser::OpcodeCC, &AkaoParser::OpcodeCD,
	&AkaoParser::OpcodeCE, &AkaoParser::OpcodeCF,

	&AkaoParser::OpcodeD0, &AkaoParser::OpcodeD1,
	&AkaoParser::OpcodeD2, &AkaoParser::OpcodeD3,
	&AkaoParser::OpcodeD4, &AkaoParser::OpcodeD5,
	&AkaoParser::OpcodeD6, &AkaoParser::OpcodeD7,
	&AkaoParser::OpcodeD8, &AkaoParser::OpcodeD9,
	&AkaoParser::OpcodeDA, &AkaoParser::OpcodeDB,
	&AkaoParser::OpcodeDC, &AkaoParser::OpcodeDD,
	&AkaoParser::OpcodeDE, &AkaoParser::OpcodeDF,

	&AkaoParser::OpcodeA0, &AkaoParser::OpcodeA0,
	&AkaoParser::OpcodeA0, &AkaoParser::OpcodeA0,
	&AkaoParser::OpcodeA0, &AkaoParser::OpcodeA0,
	&AkaoParser::OpcodeA0, &AkaoParser::OpcodeA0,
	&AkaoParser::OpcodeE8, &AkaoParser::OpcodeE9,
	&AkaoParser::OpcodeEA, &AkaoParser::OpcodeEB,
	&AkaoParser::OpcodeEC, &AkaoParser::OpcodeED,
	&AkaoParser::OpcodeEE, &AkaoParser::OpcodeEF,

	&AkaoParser::OpcodeF0, &AkaoParser::OpcodeF1,
	&AkaoParser::OpcodeF2, &AkaoParser::OpcodeF3,
	&AkaoParser::OpcodeF4, &AkaoParser::OpcodeF5,
	&AkaoParser::OpcodeF6, &AkaoParser::OpcodeF7,
	&AkaoParser::OpcodeF8, &AkaoParser::OpcodeF9,
	&AkaoParser::OpcodeA0, &AkaoParser::OpcodeA0,
	&AkaoParser::OpcodeA0, &AkaoParser::OpcodeFD,
	&AkaoParser::OpcodeFE, &AkaoParser::OpcodeA0
};



// stop channel
// TODO
void AkaoParser::OpcodeA0(int arg_ch)
{
	arg_ch = arg_ch;
}


// load voice
void AkaoParser::OpcodeA1(int arg_ch)
{
	u8 current_voice = StreamRead<u8>(arg_ch);

	/* THIS CODE IS CONSIDERED TOTALLY UNNEEDED, AS PITCH SET HERE IS AT
	 * ONCE OVERWRITTED BY SO-CALLED "STREAM BYTE" (SEQUENCE BYTE, THAT
	 * CONTAINS PITCH INDEX FROM INSTRUMENT PITCH TABLE AND INDEX OF TIMING
	 * VALUE). HOWEVER IT'S SOMEHOW USED IN SQUARE CODE, AND LEAD TO WRITING
	 * INVALID PITCH VALUE TO CHANNEL STRUCTURE AFTER CHANNEL LOOPS TO IT'S
	 * BEGINNING WITH "EE" OR SIMILAR OPCODES */
/*
	// set new pitch based on old one
	// (unsure why to set default pitch, on next
	// tick it'll be overwritten with new one)
	m_CD[arg_ch].pitch_base =
			m_CD[arg_ch].pitch_base *
			m_VoiceIndex[current_voice].pitch[0] /
			m_VoiceIndex[
			m_CD[arg_ch].voice_index].pitch[0];

	SOUNDMAN->SetVoicePitch(arg_ch,
			m_CD[arg_ch].pitch_base);
*/

	this->LoadVoice(arg_ch, current_voice);
}


// pause
void AkaoParser::OpcodeA2(int arg_ch)
{
	u8 current_pause_index = StreamRead<u8>(arg_ch);

	m_CD[arg_ch].pause = current_pause_index;
	m_CD[arg_ch].pause_index = current_pause_index;
	m_CD[arg_ch].pause_multiplier = 0;
}


// volume level
void AkaoParser::OpcodeA3(int arg_ch)
{
	m_CD[arg_ch].volume_multiplier = StreamRead<u8>(arg_ch);
}


// TODO
void AkaoParser::OpcodeA4(int arg_ch)
{
	arg_ch = arg_ch;
}


// pitch correction
void AkaoParser::OpcodeA5(int arg_ch)
{
	m_CD[arg_ch].pitch_correction = StreamRead<u8>(arg_ch);
}


// pitch correction increment
void AkaoParser::OpcodeA6(int arg_ch)
{
	++m_CD[arg_ch].pitch_correction;
	m_CD[arg_ch].pitch_correction &= 0x0f;
}


// pitch correction decrement
void AkaoParser::OpcodeA7(int arg_ch)
{
	--m_CD[arg_ch].pitch_correction;
	m_CD[arg_ch].pitch_correction &= 0x0f;
}


// volume unknown
void AkaoParser::OpcodeA8(int arg_ch)
{
	m_CD[arg_ch].volume_level = StreamRead<s8>(arg_ch) << 23;

	m_CD[arg_ch].volume_level_change_ticks = 0;
	m_CD[arg_ch].volume_level_changed = true;
}


// volume increase/decrease
void AkaoParser::OpcodeA9(int arg_ch)
{
	u8 current_ticks = StreamRead<u8>(arg_ch);

	m_CD[arg_ch].volume_level_change_ticks = current_ticks ?
		current_ticks : 0x100;
	m_CD[arg_ch].volume_level &= 0xffff0000;

	m_CD[arg_ch].volume_level_new = ((StreamRead<s8>(arg_ch) << 23) -
		 m_CD[arg_ch].volume_level) /
		m_CD[arg_ch].volume_level_change_ticks;
}


// volume index
void AkaoParser::OpcodeAA(int arg_ch)
{
	m_CD[arg_ch].volume_index = StreamRead<u8>(arg_ch);
	m_CD[arg_ch].volume_index_changed = true;
}


// TODO
void AkaoParser::OpcodeAB(int arg_ch)
{
	arg_ch = arg_ch;
}


// TODO
void AkaoParser::OpcodeAC(int arg_ch)
{
	arg_ch = arg_ch;
}


void AkaoParser::OpcodeAD(int arg_ch)
{
	u8 attack_rate = StreamRead<u8>(arg_ch);

	SpuSetParameter(m_CD[arg_ch].spu_config,
			SPU_ATTACK_RATE, attack_rate);

	if(m_CD[arg_ch].mirror_enabled)
	{
		SpuSetParameter(m_CD[m_CD[arg_ch].mirror].spu_config,
				SPU_ATTACK_RATE, attack_rate);
	}
}


void AkaoParser::OpcodeAE(int arg_ch)
{
	u8 decay_rate = StreamRead<u8>(arg_ch);

	SpuSetParameter(m_CD[arg_ch].spu_config,
			SPU_DECAY_RATE, decay_rate);

	if(m_CD[arg_ch].mirror_enabled)
	{
		SpuSetParameter(m_CD[m_CD[arg_ch].mirror].spu_config,
				SPU_DECAY_RATE, decay_rate);
	}
}


void AkaoParser::OpcodeAF(int arg_ch)
{
	u8 sustain_level = StreamRead<u8>(arg_ch);

	SpuSetParameter(m_CD[arg_ch].spu_config,
			SPU_SUSTAIN_LEVEL, sustain_level);

	if(m_CD[arg_ch].mirror_enabled)
	{
		SpuSetParameter(m_CD[m_CD[arg_ch].mirror].spu_config,
				SPU_SUSTAIN_LEVEL, sustain_level);
	}
}


void AkaoParser::OpcodeB0(int arg_ch)
{
	OpcodeAE(arg_ch);
	OpcodeAF(arg_ch);
}


void AkaoParser::OpcodeB1(int arg_ch)
{
	u8 sustain_rate = StreamRead<u8>(arg_ch);

	SpuSetParameter(m_CD[arg_ch].spu_config,
			SPU_SUSTAIN_RATE, sustain_rate);

	if(m_CD[arg_ch].mirror_enabled)
	{
		SpuSetParameter(m_CD[m_CD[arg_ch].mirror].spu_config,
				SPU_SUSTAIN_RATE, sustain_rate);
	}
}


void AkaoParser::OpcodeB2(int arg_ch)
{
	u8 release_rate = StreamRead<u8>(arg_ch);

	SpuSetParameter(m_CD[arg_ch].spu_config,
			SPU_RELEASE_RATE, release_rate);

	if(m_CD[arg_ch].mirror_enabled)
	{
		SpuSetParameter(m_CD[m_CD[arg_ch].mirror].spu_config,
				SPU_RELEASE_RATE, release_rate);
	}
}


// TODO
void AkaoParser::OpcodeB3(int arg_ch)
{
	arg_ch = arg_ch;
}


void AkaoParser::OpcodeB4(int arg_ch)
{
	m_CD[arg_ch].wave_loaded = true;

	m_CD[arg_ch].wave_delay = StreamRead<u8>(arg_ch);

	m_CD[arg_ch].wave_delay_current =
		m_CD[arg_ch].wave_delay;

	u8 current_refresh_interval = StreamRead<u8>(arg_ch);

	m_CD[arg_ch].wave_refresh_interval =
		current_refresh_interval ? current_refresh_interval : 0x100;

	m_CD[arg_ch].wave_refresh_interval_current = 1;

	m_CD[arg_ch].wave_table_node_index = StreamRead<u8>(arg_ch);

	m_CD[arg_ch].wave_table_index =
		m_AKAO_WAVE_TABLE_KEY_NODES[
			m_CD[arg_ch].wave_table_node_index];

	this->RefreshWaveParameters(arg_ch);
}


void AkaoParser::OpcodeB5(int arg_ch)
{
	m_CD[arg_ch].wave_modifier = StreamRead<u8>(arg_ch) << 8;

	this->RefreshWaveParameters(arg_ch);
}


// TODO
void AkaoParser::OpcodeB6(int arg_ch)
{
	arg_ch = arg_ch;
}


void AkaoParser::OpcodeB7(int arg_ch)
{
	u8 attack_mode = StreamRead<u8>(arg_ch);

	SpuSetParameter(m_CD[arg_ch].spu_config,
			SPU_ATTACK_MODE, attack_mode);

	if(m_CD[arg_ch].mirror_enabled)
	{
		SpuSetParameter(m_CD[m_CD[arg_ch].mirror].spu_config,
				SPU_ATTACK_MODE, attack_mode);
	}
}


// TODO
void AkaoParser::OpcodeB8(int arg_ch)
{
	arg_ch = arg_ch;
}


// TODO
void AkaoParser::OpcodeB9(int arg_ch)
{
	arg_ch = arg_ch;
}


// TODO
void AkaoParser::OpcodeBA(int arg_ch)
{
	arg_ch = arg_ch;
}


void AkaoParser::OpcodeBB(int arg_ch)
{
	u8 sustain_mode = StreamRead<u8>(arg_ch);

	SpuSetParameter(m_CD[arg_ch].spu_config,
			SPU_SUSTAIN_MODE, sustain_mode);

	if(m_CD[arg_ch].mirror_enabled)
	{
		SpuSetParameter(m_CD[m_CD[arg_ch].mirror].spu_config,
				SPU_SUSTAIN_MODE, sustain_mode);
	}
}


// TODO
void AkaoParser::OpcodeBC(int arg_ch)
{
	arg_ch = arg_ch;
}


// TODO
void AkaoParser::OpcodeBD(int arg_ch)
{
	arg_ch = arg_ch;
}


// TODO
void AkaoParser::OpcodeBE(int arg_ch)
{
	arg_ch = arg_ch;
}


void AkaoParser::OpcodeBF(int arg_ch)
{
	u8 release_mode = StreamRead<u8>(arg_ch);

	SpuSetParameter(m_CD[arg_ch].spu_config,
			SPU_RELEASE_MODE, release_mode);

	if(m_CD[arg_ch].mirror_enabled)
	{
		SpuSetParameter(m_CD[m_CD[arg_ch].mirror].spu_config,
				SPU_RELEASE_MODE, release_mode);
	}
}


// pitch selector
void AkaoParser::OpcodeC0(int arg_ch)
{
	m_CD[arg_ch].pitch_selector = StreamRead<s8>(arg_ch);
}


// pitch selector increment/decrement
void AkaoParser::OpcodeC1(int arg_ch)
{
	m_CD[arg_ch].pitch_selector += StreamRead<s8>(arg_ch);
}


// turn on reverb for channel
void AkaoParser::OpcodeC2(int arg_ch)
{
	SpuSetParameter(m_CD[arg_ch].spu_config,
			SPU_REVERB, 1);
}


// TODO
void AkaoParser::OpcodeC3(int arg_ch)
{
	arg_ch = arg_ch;
}


// TODO
void AkaoParser::OpcodeC4(int arg_ch)
{
	arg_ch = arg_ch;
}


// TODO
void AkaoParser::OpcodeC5(int arg_ch)
{
	arg_ch = arg_ch;
}


// TODO
void AkaoParser::OpcodeC6(int arg_ch)
{
	arg_ch = arg_ch;
}


// TODO
void AkaoParser::OpcodeC7(int arg_ch)
{
	arg_ch = arg_ch;
}


// save current stream position
void AkaoParser::OpcodeC8(int arg_ch)
{
	m_CD[arg_ch].saved_pos_index = 
		(m_CD[arg_ch].saved_pos_index + 1) & 3;

	m_CD[arg_ch].saved_pos[
		m_CD[arg_ch].saved_pos_index] =
		m_CD[arg_ch].current_pos;
	
	m_CD[arg_ch].saved_unknown[
		m_CD[arg_ch].saved_pos_index] = 0;
}


// partial unknown
void AkaoParser::OpcodeC9(int arg_ch)
{
	// read parameter
	u16 p0 = StreamRead<u8>(arg_ch);

	if(!p0)
		p0 = 0x100;

	// if opcode parameter not equal saved_unknown[saved_pos_index]
	if(m_CD[arg_ch].saved_unknown[
		m_CD[arg_ch].saved_pos_index] != p0)
	{
		// set stream position to saved_pos[saved_pos_index]
		m_CD[arg_ch].current_pos =
			m_CD[arg_ch].saved_pos[
			m_CD[arg_ch].saved_pos_index];
	}
	else
	{
		// decrement saved position index by 1 (% 4)
		m_CD[arg_ch].saved_pos_index =
			(m_CD[arg_ch].saved_pos_index + 3) & 3;
	}

	// increment saved_unknown[saved_pos_index]
	++m_CD[arg_ch].saved_unknown[
		m_CD[arg_ch].saved_pos_index];
}


// loads saved position
void AkaoParser::OpcodeCA(int arg_ch)
{
	++m_CD[arg_ch].saved_unknown[
		m_CD[arg_ch].saved_pos_index];

	m_CD[arg_ch].current_pos =
		m_CD[arg_ch].saved_pos[
		m_CD[arg_ch].saved_pos_index];
}


// TODO
void AkaoParser::OpcodeCB(int arg_ch)
{
	arg_ch = arg_ch;
}


// seems debug
void AkaoParser::OpcodeCC(int arg_ch)
{
	arg_ch = arg_ch;
}


// unused
void AkaoParser::OpcodeCD(int arg_ch)
{
	arg_ch = arg_ch;
}


// TODO
void AkaoParser::OpcodeCE(int arg_ch)
{
	arg_ch = arg_ch;
}


// TODO
void AkaoParser::OpcodeCF(int arg_ch)
{
	arg_ch = arg_ch;
}


// seems debug
void AkaoParser::OpcodeD0(int arg_ch)
{
	arg_ch = arg_ch;
}


// unused
void AkaoParser::OpcodeD1(int arg_ch)
{
	arg_ch = arg_ch;
}


// TODO
void AkaoParser::OpcodeD2(int arg_ch)
{
	arg_ch = arg_ch;
}


// TODO
void AkaoParser::OpcodeD3(int arg_ch)
{
	arg_ch = arg_ch;
}


// TODO
void AkaoParser::OpcodeD4(int arg_ch)
{
	arg_ch = arg_ch;
}


// TODO
void AkaoParser::OpcodeD5(int arg_ch)
{
	arg_ch = arg_ch;
}


// TODO
void AkaoParser::OpcodeD6(int arg_ch)
{
	arg_ch = arg_ch;
}


// TODO
void AkaoParser::OpcodeD7(int arg_ch)
{
	arg_ch = arg_ch;
}


// pitch modifier
void AkaoParser::OpcodeD8(int arg_ch)
{
	m_CD[arg_ch].pitch_modifier = StreamRead<s8>(arg_ch);
}


// pitch modifier increment/decrement
void AkaoParser::OpcodeD9(int arg_ch)
{
	m_CD[arg_ch].pitch_modifier += StreamRead<s8>(arg_ch);
}


// TODO
void AkaoParser::OpcodeDA(int arg_ch)
{
	arg_ch = arg_ch;
}


// TODO
void AkaoParser::OpcodeDB(int arg_ch)
{
	arg_ch = arg_ch;
}


// TODO
void AkaoParser::OpcodeDC(int arg_ch)
{
	arg_ch = arg_ch;
}


// TODO
void AkaoParser::OpcodeDD(int arg_ch)
{
	arg_ch = arg_ch;
}


// TODO
void AkaoParser::OpcodeDE(int arg_ch)
{
	arg_ch = arg_ch;
}


// TODO
void AkaoParser::OpcodeDF(int arg_ch)
{
	arg_ch = arg_ch;
}


// tempo
void AkaoParser::OpcodeE8(int arg_ch)
{
	m_Tempo = StreamRead<u16>(arg_ch);
}


// TODO
void AkaoParser::OpcodeE9(int arg_ch)
{
	arg_ch = arg_ch;
}


// reverb depth
void AkaoParser::OpcodeEA(int arg_ch)
{
	u16 reverb_depth = StreamRead<u16>(arg_ch);

	SpuSetParameter(m_CD[arg_ch].spu_config,
			SPU_REVERB_DEPTH_LEFT, reverb_depth);
	SpuSetParameter(m_CD[arg_ch].spu_config,
			SPU_REVERB_DEPTH_RIGHT, reverb_depth);
}


// TODO
void AkaoParser::OpcodeEB(int arg_ch)
{
	arg_ch = arg_ch;
}


// TODO
void AkaoParser::OpcodeEC(int arg_ch)
{
	arg_ch = arg_ch;
}


// TODO
void AkaoParser::OpcodeED(int arg_ch)
{
	arg_ch = arg_ch;
}


// advance stream position
void AkaoParser::OpcodeEE(int arg_ch)
{
	// load parameter
	s16 p0 = StreamRead<s16>(arg_ch);

	m_CD[arg_ch].current_pos += p0;
}


// doesn't used in FF7
// TODO
void AkaoParser::OpcodeEF(int arg_ch)
{
	arg_ch = arg_ch;
}


// advance stream position (depends on p0)
void AkaoParser::OpcodeF0(int arg_ch)
{
	// load parameter
	u16 p0 = StreamRead<u8>(arg_ch);

	s16 p1 = StreamRead<s16>(arg_ch);

	if(!p0)
		p0 = 0x100;

	if(m_CD[arg_ch].saved_unknown[
			m_CD[arg_ch].saved_pos_index] + 1 == p0)
	m_CD[arg_ch].current_pos += p1;
}


// advance stream position
// and decrement ch[0xb8] (depends on p0)
void AkaoParser::OpcodeF1(int arg_ch)
{
	// load parameter
	u16 p0 = StreamRead<u8>(arg_ch);

	s16 p1 = StreamRead<s16>(arg_ch);

	if(!p0)
		p0 = 0x100;

	if(m_CD[arg_ch].saved_unknown[
			m_CD[arg_ch].saved_pos_index] + 1 == p0)
	{
		m_CD[arg_ch].current_pos += p1;
		
		// decrement saved position index by 1 (% 4)
		m_CD[arg_ch].saved_pos_index =
			(m_CD[arg_ch].saved_pos_index + 3) & 3;
	}
}


// TODO
void AkaoParser::OpcodeF2(int arg_ch)
{
	arg_ch = arg_ch;
}


// TODO
void AkaoParser::OpcodeF3(int arg_ch)
{
	arg_ch = arg_ch;
}


// TODO
void AkaoParser::OpcodeF4(int arg_ch)
{
	arg_ch = arg_ch;
}


// TODO
void AkaoParser::OpcodeF5(int arg_ch)
{
	arg_ch = arg_ch;
}


// TODO
void AkaoParser::OpcodeF6(int arg_ch)
{
	arg_ch = arg_ch;
}


// TODO
void AkaoParser::OpcodeF7(int arg_ch)
{
	arg_ch = arg_ch;
}


// TODO
void AkaoParser::OpcodeF8(int arg_ch)
{
	arg_ch = arg_ch;
}


// TODO
void AkaoParser::OpcodeF9(int arg_ch)
{
	arg_ch = arg_ch;
}


// TODO
void AkaoParser::OpcodeFD(int arg_ch)
{
	arg_ch = arg_ch;
}


// TODO
void AkaoParser::OpcodeFE(int arg_ch)
{
	arg_ch = arg_ch;
}

