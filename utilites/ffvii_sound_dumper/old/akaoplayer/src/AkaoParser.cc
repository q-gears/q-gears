#include <string.h>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>
#include "common/typedefs.h"
#include "engine/SoundManager.hh"

#include "AkaoParser.hh"

//#define GDEBUG

#define CALL_MEMBER_FN(arg_obj, arg_method) ((arg_obj)->*(arg_method))



AkaoParser *AKAOMAN = NULL;



const char *AkaoParser::m_AKAO_MAGIC = "AKAO";

const u8 AkaoParser::m_AKAO_PAUSE_TABLE[11] =
{
	0xc0, 0x60, 0x30, 0x18,
	0x0c, 0x06, 0x03, 0x20,
	0x10, 0x08, 0x04
};

const s16 AkaoParser::m_AKAO_VOLUME_TABLE_L[256] =
{
	32640, 32384, 32128, 31872, 31616, 31360, 31104, 30848,
	30592, 30336, 30080, 29824, 29568, 29312, 29056, 28800,
	28544, 28288, 28032, 27776, 27520, 27264, 27008, 26752,
	26496, 26240, 25984, 25728, 25472, 25216, 24960, 24704,
	24448, 24192, 23936, 23680, 23424, 23168, 22912, 22656,
	22400, 22144, 21888, 21632, 21376, 21120, 20864, 20608,
	20352, 20096, 19840, 19584, 19328, 19072, 18816, 18560,
	18304, 18048, 17792, 17536, 17280, 17024, 16768, 16512,
	16256, 16000, 15744, 15488, 15232, 14976, 14720, 14464,
	14208, 13952, 13696, 13440, 13184, 12928, 12672, 12416,
	12160, 11904, 11648, 11392, 11136, 10880, 10624, 10368,
	10112,  9856,  9600,  9344,  9088,  8832,  8576,  8320,
	 8064,  7808,  7552,  7296,  7040,  6784,  6528,  6272,
	 6016,  5760,  5504,  5248,  4992,  4736,  4480,  4224,
	 3968,  3712,  3456,  3200,  2944,  2688,  2432,  2176,
	 1920,  1664,  1408,  1152,   896,   640,   384,   128,
	    0,    -1,    -4,    -9,   -16,   -25,   -36,   -49,
	  -64,   -81,  -100,  -121,  -144,  -169,  -196,  -225,
	 -256,  -289,  -324,  -361,  -400,  -441,  -484,  -529,
	 -576,  -625,  -676,  -729,  -784,  -841,  -900,  -961,
	-1024, -1089, -1156, -1225, -1296, -1369, -1444, -1521,
	-1600, -1681, -1764, -1849, -1936, -2025, -2116, -2209,
	-2304, -2401, -2500, -2601, -2704, -2809, -2916, -3025,
	-3136, -3249, -3364, -3481, -3600, -3721, -3844, -3969,
	 4096,  4225,  4356,  4489,  4624,  4761,  4900,  5041,
	 5184,  5329,  5476,  5625,  5776,  5929,  6084,  6241,
	 6400,  6561,  6724,  6889,  7056,  7225,  7396,  7569,
	 7744,  7921,  8100,  8281,  8464,  8649,  8836,  9025,
	 9216,  9409,  9604,  9801, 10000, 10201, 10404, 10609,
	10816, 11025, 11236, 11449, 11664, 11881, 12100, 12321,
	12544, 12769, 12996, 13225, 13456, 13689, 13924, 14161,
	14400, 14641, 14884, 15129, 15376, 15625, 15876, 16129
};

const s16 AkaoParser::m_AKAO_VOLUME_TABLE_R[256] =
{
	  128,   384,   640,   896,  1152,  1408,  1664,  1920,
	 2176,  2432,  2688,  2944,  3200,  3456,  3712,  3968,
	 4224,  4480,  4736,  4992,  5248,  5504,  5760,  6016,
	 6272,  6528,  6784,  7040,  7296,  7552,  7808,  8064,
	 8320,  8576,  8832,  9088,  9344,  9600,  9856, 10112,
	10368, 10624, 10880, 11136, 11392, 11648, 11904, 12160,
	12416, 12672, 12928, 13184, 13440, 13696, 13952, 14208,
	14464, 14720, 14976, 15232, 15488, 15744, 16000, 16256,
	16512, 16768, 17024, 17280, 17536, 17792, 18048, 18304,
	18560, 18816, 19072, 19328, 19584, 19840, 20096, 20352,
	20608, 20864, 21120, 21376, 21632, 21888, 22144, 22400,
	22656, 22912, 23168, 23424, 23680, 23936, 24192, 24448,
	24704, 24960, 25216, 25472, 25728, 25984, 26240, 26496,
	26752, 27008, 27264, 27520, 27776, 28032, 28288, 28544,
	28800, 29056, 29312, 29568, 29824, 30080, 30336, 30592,
	30848, 31104, 31360, 31616, 31872, 32128, 32384, 32640,
	16129, 15876, 15625, 15376, 15129, 14884, 14641, 14400,
	14161, 13924, 13689, 13456, 13225, 12996, 12769, 12544,
	12321, 12100, 11881, 11664, 11449, 11236, 11025, 10816,
	10609, 10404, 10201, 10000,  9801,  9604,  9409,  9216,
	 9025,  8836,  8649,  8464,  8281,  8100,  7921,  7744,
	 7569,  7396,  7225,  7056,  6889,  6724,  6561,  6400,
	 6241,  6084,  5929,  5776,  5625,  5476,  5329,  5184,
	 5084,  4900,  4761,  4624,  4489,  4356,  4225,  4096,
	-3969, -3844, -3721, -3600, -3481, -3364, -3249, -3136,
	-3025, -2916, -2809, -2704, -2601, -2500, -2401, -2304,
	-2209, -2116, -2025, -1936, -1849, -1764, -1981, -1600,
	-1521, -1444, -1369, -1296, -1225, -1156, -1089, -1024,
	 -961,  -900,  -841,  -784,  -729,  -676,  -625,  -576,
	 -529,  -484,  -441,  -400,  -361,  -324,  -289,  -256,
	 -225,  -196,  -169,  -144,  -121,  -100,   -81,   -64,
	  -49,   -36,   -25,   -16,    -9,    -4,    -1,     0
};

const s16 AkaoParser::m_AKAO_WAVE_TABLE[708] = 
{
	  8191,  -8191,  16383, -16383,  24575, -24575,  32767, -32767, 
	     0,      0,     -2,      0,  32767, -32767,      0,      0, 
	    -2,      0,   8191,      0,  16383,      0,  24575,      0, 
	 32767,      0,      0,     -2,  32767,      0,  32767,      0, 
	     0,     -2,  -8191,      0, -16383,      0, -24575,      0, 
	-32767,      0,      0,     -2, -32767,      0, -32767,      0, 
	     0,     -2,      0,   1280,   2530,   4813,   5790,   6625, 
	  7297,   7789,   8090,   8191,   8092,   7793,   7302,   6632, 
	  5799,   4823,   3728,   2542,   1293,      0,  -1268,  -2518, 
	 -3706,  -4803,  -5782,  -6618,  -7292,  -7786,  -8089,  -8192, 
	 -8095,  -7798,  -7309,  -6641,  -5809,  -4835,  -3741,  -2556, 
	 -1307,      0,   2561,   5060,   9626,  11580,  13250,  14594, 
	 15578,  16180,  16383,  16184,  15586,  14605,  13265,  11599, 
	  9647,   7457,   5085,   2587,      0,  -2536,  -5036,  -7412, 
	 -9605, -11563, -13235, -14583, -15571, -16177, -16384, -16189, 
	-15595, -14618, -13281, -11618,  -9669,  -7482,  -5111,  -2614, 
	     0,   3842,   7590,  14439,  17370,  19875,  21891,  23367, 
	 24270,  24575,  24276,  23379,  21908,  19898,  17398,  14470, 
	 11186,   7627,   3881,      0,  -3804,  -7554, -11118, -14408, 
	-17344, -19853, -21874, -23357, -24265, -24576, -24284, -23393, 
	-21927, -19922, -17427, -14503, -11223,  -7666,  -3921,      0, 
	  5123,  10120,  19252,  23161,  26500,  29188,  31157,  32360, 
	 32767,  32369,  31173,  29211,  26531,  23198,  19294,  14915, 
	 10170,   5175,      0,  -5072, -10072, -14823, -19210, -23125, 
	-26470, -29165, -31142, -32353, -32768, -32378, -31190, -29236, 
	-26562, -23235, -19337, -14963, -10221,  -5227,      0,      0, 
	   -39,      0,      0,   5123,  10120,  19252,  23161,  26500, 
	 29188,  31157,  32360,  32767,  32369,  31173,  29211,  26531, 
	 23198,  19294,  14915,  10170,   5175,      0,  -5072, -10072, 
	-14823, -19210, -23125, -26470, -29165, -31142, -32353, -32768, 
	-32378, -31190, -29236, -26562, -23235, -19337, -14963, -10221, 
	 -5227,      0,      0,    -39,      0,   2530,   4813,   6625, 
	  7789,   8191,   7793,   6632,   4823,   2542,     13,  -2518, 
	 -4803,  -6618,  -7786,  -8192,  -7798,  -6641,  -4835,  -2556, 
	     0,   5060,   9626,  13250,  15578,  16383,  15586,  13265, 
	  9647,   5085,     26,  -5036,  -9605, -13235, -15571, -16384, 
	-15595, -13281,  -9669,  -5111,      0,   7590,  14439,  19875, 
	 23367,  24575,  23379,  19898,  14470,   7627,     39,  -7554, 
	-14408, -19853, -23357, -24576, -23393, -19922, -14503,  -7666, 
	     0,  10120,  19252,  26500,  31157,  32767,  31173,  26531, 
	 19294,  10170,     52, -10072, -19210, -26470, -31142, -32768, 
	-31190, -26562, -19337, -10221,      0,      0,    -20,      0, 
	     0,  10120,  19252,  26500,  31157,  32767,  31173,  26531, 
	 19294,  10170,     52, -10072, -19210, -26470, -31142, -32768, 
	-31190, -26562, -19337, -10221,      0,      0,    -20,      0, 
	     0,   2047,   4095,   6143,   8191,   6143,   4095,   2047, 
	     0,  -2047,  -4095,  -6143,  -8191,  -6143,  -4095,  -2047, 
	     0,   4095,   8191,  12287,  16383,  12287,   8191,   4095, 
	     0,  -4095,  -8191, -12287, -16383, -12287,  -8191,  -4095, 
	     0,   6143,  12287,  18431,  24575,  18431,  12287,   6143, 
	     0,  -6143, -12287, -18431, -24575, -18431, -12287,  -6143, 
	     0,   8191,  16383,  24575,  32767,  24575,  16383,   8191, 
	     0,  -8191, -16383, -24575, -32767, -24575, -16383,  -8191, 
	     0,      0,    -16,      0,      0,   8191,  16383,  24575, 
	 32767,  24575,  16383,   8191,      0,  -8191, -16383, -24575, 
	-32767, -24575, -16383,  -8191,      0,      0,    -16,      0, 
	     0,  12797,  32005,  -2563,  -4882,  31036,  30160,   2044, 
	 -3055, -15627,  26127,  13070,  16362, -16671, -29678,   6177, 
	-20485,  18944, -11289,  -2827,  -7881,  -6189,  21005,   4355, 
	-20769,  19192,   1862,  28916, -28991, -26855,  13586,  -2560, 
	  6912, -19223,  15134, -20971, -25400,  26105, -15581,  29176, 
	 11505, -23036, -27908, -14066, -20471,   4325,   2052, -32767, 
	  4858,   4376,  -6391,  18424, -27175,  -8932,   6921,   3060, 
	 31740,   8447, -27644,  32252, -29963, -18665,  29945,  11004, 
	 -8954, -10253,  -2819,   1544,  -3560,  27103, -17401,  19191, 
	-30229, -17625,   4361,  32751,  13845,  -4915,  30241, -26603, 
	 22223, -11258,  13090,  -8218, -20726, -17931, -12792,  23813, 
	-16402,  -4070,   8424, -24810, -29454, -15641, -11730, -14847, 
	-17968, -32500,  17187,  10461, -26889,  23612, -24610, -20760, 
	-18917,  16115,   5128,  -9495,  11275, -20173, -22303,   1498, 
	  2324,  20002,    -24, -30735,   8688, -29403,  32252,   7408, 
	 24081,  15848, -14582, -28905,    -16,  27149,    -29,   4851, 
	  1055,  30732, -15121,  23298,  15618,    754,   5401,  -9515, 
	-17143, -28135,  -2813,  25309,  14342,   3878, -22277,  -7938, 
	 -2333,   3586,    528,  17414, -27436, -12022, -22458,   4337, 
	  6860, -16899,   6704, -24341,  24554, -16624, -17425,  -8421, 
	-15860,  10976,  16114, -20953,  20481,  -1571,  13841, -21222, 
	  2015,  27909,   6669, -18725,  27947,  13831,  -1076,  16904, 
	  3873,  14070, -14330,   1539,   -553,  30743,   1541, -20725, 
	-27140,   4332, -22770, -21005,  26127, -16910,  -8456,  -7135, 
	-19993,   -787,  23324, -24311, -13070,  -2573, -25861, -19433, 
	-27928,  32520,  19450, -30211,  15388,   -785,  -3365,  18973, 
	 26397, -10497,  26074,  -3588,  28170,   2572,   4600,  18946, 
	 23548,  -5370, -23059,  12518, -32751, -11724,   2296,  17372, 
	 -2551, -22798, -26099,  28678,  -2582, -25348, -32482, -21018, 
	 -6642, -27145, -19708, -25345,  -4118,  -2791,  -1536,  15094, 
	-14379,  10018, -17608,  17361,  30701,  18696, -12798, -21745, 
	 15851,  -9462,  25601,  16377,  30450, -27895, -11761,  29925, 
	     0,      0,   -256,      0
};

const u16 AkaoParser::m_AKAO_WAVE_TABLE_KEY_NODES[16] =
{
	  0,  12,  18,  28,  34,  44,  50, 210,
	360, 428, 252, 336, 448, 428, 360, 428
};


AkaoParser::AkaoParser():
	m_SequenceDataFilename(""),
	m_IsPlaying(false)
{
	memset((char *)m_CD, 0x00,
		sizeof(AkaoChannelData) * m_AKAO_CHANNELS_COUNT);
}


AkaoParser::~AkaoParser()
{
	this->UnloadSequenceData();
	this->UnloadVoiceData();
}


int AkaoParser::LoadVoiceData(const char *arg_all_file,
		const char *arg_dat_file)
{
    // load instruments adpsm
    {
        File* file = new File( arg_all_file );

        u32 address = file->GetU32LE( 0x0 ) / 8;
        u32 datasize = file->GetU32LE( 0x4 );

        u8* buffer = new u8[ datasize ];
        file->GetFileBuffer( buffer, 0x10, datasize );

        if ( !SOUNDMAN->PsxWriteDMA( address, buffer, datasize ) )
        {
            LOGGER->Log( "[AkaoParser::LoadVoiceData] error: failed to DMA write sample data.\n" );
        }

        delete[] buffer;
        delete file;
    }





	// check if this voice data already loaded
	int filenames_count = m_VoiceFilenames.size();
	if(filenames_count)
		for(int i = 0; i < filenames_count; ++i)
			if(m_VoiceFilenames[i] == string(arg_all_file))
			{
				cout << "[AkaoParser] error: voice file " << arg_all_file
					<< " already loaded" << endl;
				return 2;
			}

	// open index file
	ifstream iIndexF;
	iIndexF.open(arg_dat_file, ios_base::binary);
	if(!iIndexF.is_open())
	{
		cout << "[AkaoParser] error: cann't open " << arg_dat_file << endl;
		return 1;
	}

	// get voice file size
	ifstream iVoiceF;
	size_t voice_file_size;
	iVoiceF.open(arg_all_file, ios_base::binary);
	if(!iVoiceF.is_open())
	{
		cout << "[AkaoParser] error: cann't open " << arg_all_file << endl;
		return 1;
	}
	iVoiceF.seekg(0, std::ios_base::end);
	voice_file_size = iVoiceF.tellg();
	iVoiceF.seekg(0, std::ios_base::beg);

	// load index records
	VoiceIndex voice_index_record;
	while(true)
	{
		iIndexF.read((char *)&voice_index_record,
				sizeof(voice_index_record));

		// exit if reached zeroed record
		if(!voice_index_record.attack_offset)
			break;

		// FIXME!!
		m_PsxAttackOffset.push_back(voice_index_record.attack_offset);
		m_PsxLoopOffset.push_back(voice_index_record.loop_offset);

		// shift pointers due to psx loading issues
		voice_index_record.attack_offset -= m_AKAO_INSTR_ALL_SHIFT;
		voice_index_record.loop_offset -=
			(m_AKAO_INSTR_ALL_SHIFT + voice_index_record.attack_offset);
		voice_index_record.loop_offset /= 16;

		// load voice to memory
		if(!m_VoiceIndex.empty())
		{
			int last_index = m_VoiceIndex.size() - 1;
			u32 length = voice_index_record.attack_offset - 16 -
				m_VoiceIndex[last_index].attack_offset;

			u8 *voice = new u8[length];
			iVoiceF.seekg(m_VoiceIndex[last_index].attack_offset);
			iVoiceF.read((char *)voice, length);
			m_VoiceIndex[last_index].length =
				length / 16;
			m_VoiceData.push_back(voice);
		}

		m_VoiceIndex.push_back(voice_index_record);
	}

	// load last sample
	{
		int last_index = m_VoiceIndex.size() - 1;

		u32 length = voice_file_size - 16 -
			m_VoiceIndex[last_index].attack_offset;
	
		u8 *voice = new u8[length];
		iVoiceF.seekg(m_VoiceIndex[last_index].attack_offset);
		iVoiceF.read((char *)voice, length);
		m_VoiceIndex[last_index].length = length / 16;
		m_VoiceData.push_back(voice);
	}

	iVoiceF.close();
	iIndexF.close();

	// save loaded voice data filename
	m_VoiceFilenames.push_back(string(arg_all_file));

	return 0;
}


void AkaoParser::UnloadVoiceData()
{
	if(!m_VoiceData.empty())
	{
		int voice_data_count = m_VoiceData.size();
		for(int i = 0; i < voice_data_count; ++i)
			delete [] m_VoiceData[i];

		m_VoiceData.clear();
	}

	m_VoiceIndex.clear();
	m_VoiceFilenames.clear();
}


int AkaoParser::GetVoicesCount()
{
	return m_VoiceData.size();
}


int AkaoParser::LoadSequenceData(const char *arg_file)
{
	if(m_SequenceDataFilename != "")
		return 0xff;

	// read akao header from file
	ifstream iF;
	iF.open(arg_file, ios_base::binary | ios_base::in);
	if(!iF.is_open())
		return 1;
	iF.read((char *)&m_SequenceHeader, sizeof(m_SequenceHeader));
	if(memcmp(m_AKAO_MAGIC, m_SequenceHeader.magic,
			sizeof(m_SequenceHeader.magic)))
		return 2;

	// read rest akao data from file
	u8 *buffer = new u8[m_SequenceHeader.length];
	iF.read((char *)buffer, m_SequenceHeader.length);
	iF.close();

	u16 buffer_index = 0;
	u32 channels_info = *(u32 *)&buffer[buffer_index] & 0xffffff;
	buffer_index += 4;

	// calculate channels count
	u8 channels_count = 0;
	for(int i = 0; i < m_AKAO_CHANNELS_COUNT; ++i)
		if(channels_info & (1 << i))
			++channels_count;

	// fill real buffer offsets to channels
	u16 *buffer_offsets = new u16[channels_count + 1];
	memset((char *)buffer_offsets, 0x00, channels_count + 1);
	for(int i = 0; i < channels_count; ++i)
	{
		buffer_offsets[i] = *(u16 *)&buffer[buffer_index];
		buffer_index += 2;
		buffer_offsets[i] += buffer_index;
	}
	buffer_offsets[channels_count] = m_SequenceHeader.length;

	// allocate & fill arrays of akaos channels sequences
	buffer_index = 0;
	for(int i = 0; i < m_AKAO_CHANNELS_COUNT; ++i)
	{
		m_CD[i].stream_length = 0;
		if(channels_info & (1 << i))
		{
			m_CD[i].stream_length = buffer_offsets[buffer_index + 1] -
				buffer_offsets[buffer_index];

			m_CD[i].stream =
				new u8[m_CD[i].stream_length];

			memcpy((char *)m_CD[i].stream,
					(char *)&buffer[buffer_offsets[buffer_index]],
					m_CD[i].stream_length);

			++buffer_index;
		}
	}

	delete [] buffer_offsets;
	delete [] buffer;

	m_SequenceDataFilename = string(arg_file);

	return 0;
}


void AkaoParser::UnloadSequenceData()
{
	for(int i = 0; i < m_AKAO_CHANNELS_COUNT; ++i)
	{
		if(m_CD[i].stream)
			delete [] m_CD[i].stream;

//		if(m_CD[i].sample)
//			delete [] m_CD[i].sample;
	}

	m_SequenceDataFilename = "";
}


int AkaoParser::PlaySequenceData()
{
	if(m_SequenceDataFilename == "")
		return 0xff;

	for(int i = 0; i < m_AKAO_CHANNELS_COUNT; ++i)
	{
		if(m_CD[i].stream == NULL)
			continue;

		// voice
		m_CD[i].voice_index = 0x14;
		// (at least it sets to 0x14 by default in Square code)

		// position
		m_CD[i].current_pos = 0;
		m_CD[i].saved_pos_index = 0;
		for(int j = 0; j < 4; ++j)
		{
			m_CD[i].saved_pos[j] = 0;
			m_CD[i].saved_unknown[j] = 0;
		}

		// pause
		m_CD[i].pause = 0;
		m_CD[i].pause_index = 0;
		m_CD[i].pause_multiplier = 0;

		// pitch
		m_CD[i].pitch_base = 0;
		m_CD[i].pitch_unknown1 = 0;
		m_CD[i].pitch_80062fe6 = 0;
		m_CD[i].pitch_correction = 0;
		m_CD[i].pitch_selector = 0;
		m_CD[i].pitch_modifier = 0;
		m_CD[i].pitch_saved_parameters = 0;
		m_CD[i].pitch_wave_shift = 0;

		// volume
		m_CD[i].volume_multiplier = m_AKAO_DEFAULT_VOLUME_MODIFIER;
		m_CD[i].volume_level = 0;
		m_CD[i].volume_level_changed = false;
		m_CD[i].volume_index = 0;
		m_CD[i].volume_index_changed = false;
		SpuSetParameter(m_CD[i].spu_config, SPU_VOLUME_LEFT, 0x3fff);
		SpuSetParameter(m_CD[i].spu_config, SPU_VOLUME_RIGHT, 0x3fff);

		// wave
		m_CD[i].wave_delay = 0;
		m_CD[i].wave_delay_current = 0;
		m_CD[i].wave_refresh_interval = 0;
		m_CD[i].wave_refresh_interval_current = 0;
		m_CD[i].wave_table_node_index = 0;
		m_CD[i].wave_multiplier = 0;
		m_CD[i].wave_modifier = 0;
		m_CD[i].wave_table_index = 0;
		m_CD[i].wave_loaded = false;

		m_CD[i].mirror = 0;
		m_CD[i].mirror_enabled = false;

		// channel stream
		m_CD[i].pause = 0;
	}

	m_IsPlaying = true;
	m_Tempo = 0xffff;

	m_MSPassed = 0;
	m_MSPeriodicalPassed = 0;

	return 0;
}


void AkaoParser::StopSequenceData()
{
	m_IsPlaying = false;
}


void AkaoParser::Update(int arg_delta)
{
	// exit if nothing to do
	if(!m_IsPlaying || !arg_delta)
		return;

	/* periodical processing */
	this->PeriodicalProcess(arg_delta);

	/* ordinary opcode processing */
	this->OpcodeProcess(arg_delta);

	/* write parameters to SPU */
	SpuUpdate();
}


void AkaoParser::PeriodicalProcess(int arg_delta)
{
	// (as in akao_write_data 4 times frequently then)
	// next processing

	// cumulate passed milliseconds
	m_MSPeriodicalPassed += arg_delta;

	int time_edge = m_AKAO_TIME_CONSTANT / (m_Tempo * 4);
	if(m_MSPeriodicalPassed < time_edge)
		return;

	// if we are behind current time edge
	m_MSPeriodicalPassed -= time_edge;

	for(int i = 0; i < m_AKAO_CHANNELS_COUNT; ++i)
	{
		bool pitch_changed = false;
		
		// pitch wave processing (opcode B4)
		if(m_CD[i].wave_delay_current)
			--m_CD[i].wave_delay_current;
		if(!m_CD[i].wave_delay_current &&
				m_CD[i].wave_loaded)
		{
			--m_CD[i].wave_refresh_interval_current;
			if(!m_CD[i].wave_refresh_interval_current)
			{
				// ch[0x76] - here is 2nd parameter of B4
				m_CD[i].wave_refresh_interval_current =
					m_CD[i].wave_refresh_interval;
	
				// wierd...
				// looks like if we have two zeroes in a row
				// then 3rd coefficient isn't actual coefficient for
				// multiplication but it's next index offset
				if(!m_AKAO_WAVE_TABLE[m_CD[i].wave_table_index] &&
					!m_AKAO_WAVE_TABLE[m_CD[i].wave_table_index + 1])
				{
					m_CD[i].wave_table_index +=
						m_AKAO_WAVE_TABLE[m_CD[i].wave_table_index + 2];
				}
		
				s16 a3;
				{
					s32 v0 = m_CD[i].wave_multiplier *
						m_AKAO_WAVE_TABLE[m_CD[i].wave_table_index];
	
					a3 = v0 >> 16;
				}
						
				++m_CD[i].wave_table_index;
						
				// write new pitch shift,
				// if we have other shift that now
				if(a3 != m_CD[i].pitch_wave_shift)
				{
					m_CD[i].pitch_wave_shift = a3;
												
					if(m_CD[i].pitch_wave_shift >= 0)
						m_CD[i].pitch_wave_shift *= 2;
	
					// set flag that we changed pitch
					pitch_changed = true;
				}
			}
		}
	
		if(pitch_changed)
		{
			// add changes to base pitch
			u16 current_pitch = m_CD[i].pitch_base +
				m_CD[i].pitch_unknown1 +
				m_CD[i].pitch_wave_shift;
					
			if(m_CD[i].pitch_80062fe6)
			{
				cout << "*** WARNING: can't show this message for now!"
					<< endl;
	
				s32 v0 = current_pitch * m_CD[i].pitch_80062fe6;
				if(m_CD[i].pitch_80062fe6 < 0x80)
				{
					// sra
					current_pitch += v0 >> 7;
				}
				else
				{
					// sra
					current_pitch = v0 >> 8;
				}
			}
			SpuSetParameter(m_CD[i].spu_config, SPU_PITCH, current_pitch);
		}
	}
}


void AkaoParser::OpcodeProcess(int arg_delta)
{
	// cumulate passed milliseconds
	m_MSPassed += arg_delta;

	int time_edge = m_AKAO_TIME_CONSTANT / m_Tempo;
	if(m_MSPassed < time_edge)
		return;

	// if we are behind current time edge
	m_MSPassed -= time_edge;

	for(int i = 0; i < m_AKAO_CHANNELS_COUNT; ++i)
	{
		// pause calculation
		--m_CD[i].pause;

		// here is non-blocking periodical processing
		{
			// processing for opcode A9 (volume increase/decrease)
			if(m_CD[i].volume_level_change_ticks)
			{
				--m_CD[i].volume_level_change_ticks;
				if(((m_CD[i].volume_level +
						m_CD[i].volume_level_new) & 0xFFE00000) !=
						(m_CD[i].volume_level & 0xFFE00000))
					m_CD[i].volume_level_changed = true;

				m_CD[i].volume_level +=
					m_CD[i].volume_level_new;
			}

			// volume setting, ugly
			// directly taken from FF7 binary :)
			if(m_CD[i].volume_level_changed ||
					m_CD[i].volume_index_changed)
			{
				int32_t temp =
					(unsigned)((m_CD[i].volume_level >> 16)
					* m_CD[i].volume_multiplier) >> 7;
				temp *= m_AKAO_DEFAULT_VOLUME_MODIFIER;
				temp >>= 7;

				int32_t volume_left = (temp * m_AKAO_VOLUME_TABLE_L[
						m_CD[i].volume_index]) >> 15;
				int32_t volume_right = (temp * m_AKAO_VOLUME_TABLE_R[
						m_CD[i].volume_index]) >> 15;

#ifdef GDEBUG
				cout << "*** L_VOLUME: "
					<< dec << volume_left << endl;
				cout << "*** R_VOLUME: "
					<< dec << volume_right << endl;
#endif

				SpuSetParameter(m_CD[i].spu_config,
						SPU_VOLUME_LEFT, volume_left);
				SpuSetParameter(m_CD[i].spu_config,
						SPU_VOLUME_RIGHT, volume_right);

				m_CD[i].volume_level_changed = false;
				m_CD[i].volume_index_changed = false;
			}
		}

		// if we have paused or not active channel
		// go to process next channel
		if(m_CD[i].pause || m_CD[i].stream == NULL)
			continue;

	u8 current_opcode;
	do
	{
		current_opcode = StreamRead<u8>(i);

		// control opcodes
		if(current_opcode < 0xa0)
			break;

		// execute opcode
		int opcode_index = current_opcode - 0xa0;
		if(m_KnownOpcodes[opcode_index])
		{
			// currently reversing opcodes
			if(m_KnownOpcodes[opcode_index] == 2)
			{
				cout << "WORKING opcode: ";
				PrintOpcode(i, current_opcode);
				cout << endl;
			}
	
			// see AkaoParserOpcodes.cc
			CALL_MEMBER_FN(this, m_ProcessOpcode[opcode_index])(i);
		}
		// dump opcode to console
		else
		{
			cout << "unknown opcode: ";
			PrintOpcode(i, current_opcode);
			cout << endl;
			m_CD[i].current_pos += m_OpcodesParametersCount[opcode_index];
		}
	
	}while(current_opcode != 0xa0);

	// channel finished
	if(current_opcode == 0xa0)
		continue;

		// play sample using predefined pitch from
		// index file and silence from table
		{

			// pause calculation
			u8 pause_index = current_opcode % 11;

			// custom pause
			if(m_CD[i].pause_multiplier)
			{
				m_CD[i].pause = m_CD[i].pause_multiplier;
			}
			else
			{
				m_CD[i].pause =
					m_AKAO_PAUSE_TABLE[pause_index];
			}

			m_CD[i].pause_index = m_CD[i].pause;
		}

		if(current_opcode < 0x84)
		{
			// play sample
			u8 pitch_index = current_opcode / 11;
			if(pitch_index < 12)
			{
				// pitch processing
				u8 pitch_index = current_opcode / 11;

				// save pitch parameters
				m_CD[i].pitch_saved_parameters = 
					pitch_index + m_CD[i].pitch_correction * 12;
	
				// pitch selector
				pitch_index += m_CD[i].pitch_selector;
	
				// load selected pitch from table
				u32 current_pitch = m_VoiceIndex[
					m_CD[i].voice_index].pitch[pitch_index];
	
				// apply pitch correction
				if(m_CD[i].pitch_correction >= 7)
					current_pitch <<= (m_CD[i].pitch_correction - 6);
				else if(m_CD[i].pitch_correction < 6)
					current_pitch >>= (6 - m_CD[i].pitch_correction);
	
				// pitch modifier
				if(m_CD[i].pitch_modifier)
				{
					current_pitch +=
						current_pitch * m_CD[i].pitch_modifier /
						(m_CD[i].pitch_modifier > 0 ? 128 : 256);
	
					// make sure we are not out of 0xffff range
					current_pitch = current_pitch & 0xffff;
				}
	
				m_CD[i].pitch_base = current_pitch;
				this->RefreshWaveParameters(i);
				SpuSetParameter(m_CD[i].spu_config, SPU_PITCH, current_pitch);
				SOUNDMAN->PsxChannelPlay(i);
			}
		}
		else if(current_opcode >= 0x8f && current_opcode < 0x9a)
		{
			// loop more
			// TODO investigate!
			SOUNDMAN->PsxChannelStop(i);
		}
		// stop playback
		else if(current_opcode >= 0x9a)
		{
			SOUNDMAN->PsxChannelStop(i);
		}
	} // for(int i = 0; i < m_AKAO_CHANNELS_COUNT; ++i)
}


void AkaoParser::SpuSetParameter(SpuConfig &arg_cfg,
		SpuParameter arg_param, u32 arg_value)
{
	switch(arg_param)
	{
	case SPU_VOLUME_LEFT:
		arg_cfg.volume_left = arg_value;
		break;

	case SPU_VOLUME_RIGHT:
		arg_cfg.volume_right = arg_value;
		break;

	case SPU_PITCH:
		arg_cfg.pitch = arg_value;
		break;

	case SPU_ADDRESS_START:
		arg_cfg.address_start = arg_value;
		break;

	case SPU_ATTACK_RATE:
		arg_cfg.attack_rate = arg_value;
		break;

	case SPU_SUSTAIN_RATE:
		arg_cfg.sustain_rate = arg_value;
		break;

	case SPU_RELEASE_RATE:
		arg_cfg.release_rate = arg_value;
		break;

	case SPU_ATTACK_MODE:
		arg_cfg.attack_mode = arg_value;
		break;

	case SPU_DECAY_RATE:
		arg_cfg.decay_rate = arg_value;
		break;

	case SPU_SUSTAIN_MODE:
		arg_cfg.sustain_mode = arg_value;
		break;

	case SPU_RELEASE_MODE:
		arg_cfg.release_mode = arg_value;
		break;

	case SPU_SUSTAIN_LEVEL:
		arg_cfg.sustain_level = arg_value;
		break;

	case SPU_ADDRESS_LOOP:
		arg_cfg.address_loop = arg_value;
		break;

	case SPU_REVERB:
		arg_cfg.reverb = arg_value;
		break;

	case SPU_REVERB_DEPTH_LEFT:
		arg_cfg.reverb_depth_left = arg_value;
		break;

	case SPU_REVERB_DEPTH_RIGHT:
		arg_cfg.reverb_depth_right = arg_value;
		break;

	default:
		;
	}

	arg_cfg.refresh_flags |= (int)arg_param;
}


void AkaoParser::SpuUpdate()
{
	for(int i = 0; i < m_AKAO_CHANNELS_COUNT; ++i)
	{
		SpuConfig &config = m_CD[i].spu_config;
		u32 flags = config.refresh_flags;
		
		if(!flags)
			continue;

		if(flags & SPU_ADDRESS_START)
			SOUNDMAN->SetVoiceStartAddress(i, config.address_start);

		if(flags & SPU_ADDRESS_LOOP)
			SOUNDMAN->SetVoiceLoopAddress(i, config.address_loop);

		if((flags & SPU_VOLUME_LEFT) || (flags & SPU_VOLUME_RIGHT))
			SOUNDMAN->SetVoiceVolume(i,
					config.volume_left, config.volume_right);

		if(flags & SPU_PITCH)
			SOUNDMAN->SetVoicePitch(i, config.pitch);

		if((flags & SPU_ATTACK_RATE) || (flags & SPU_ATTACK_MODE))
		{
			SOUNDMAN->SetVoiceAttackRate(i, config.attack_rate,
					(SoundManager::SpuRateMode)config.attack_mode);
		}

		if(flags & SPU_DECAY_RATE)
			SOUNDMAN->SetVoiceDecayRate(i, config.decay_rate);

		if((flags & SPU_SUSTAIN_RATE) || (flags & SPU_SUSTAIN_MODE))
			SOUNDMAN->SetVoiceSustainRate(i, config.sustain_rate,
					(SoundManager::SpuRateMode)config.sustain_mode);

		if(flags & SPU_SUSTAIN_LEVEL)
			SOUNDMAN->SetVoiceSustainLevel(i, config.sustain_level);

		if((flags & SPU_RELEASE_RATE) || (flags & SPU_RELEASE_MODE))
		{
			SOUNDMAN->SetVoiceReleaseRate(i, config.release_rate,
					(SoundManager::SpuRateMode)config.release_mode);
		}

		// CUSTOM
		// FIXME!!
		if(flags & SPU_REVERB)
			SOUNDMAN->PsxReverbOn(i);

		if((flags & SPU_REVERB_DEPTH_LEFT) || (flags & SPU_REVERB_DEPTH_RIGHT))
		{
			SOUNDMAN->PsxInstrumentSetReverbDepth(i, config.reverb_depth_left,
					config.reverb_depth_right);
		}


		config.refresh_flags = 0;
	}
}


void AkaoParser::LoadVoice(int arg_ch, int arg_voice)
{
	// save loaded voice index
	m_CD[arg_ch].voice_index = arg_voice;

	// FIXME!!
//	SpuSetParameter(m_CD[arg_ch].spu_config, SPU_ADDRESS_START,
//			m_VoiceIndex[arg_voice].attack_offset);
//	SpuSetParameter(m_CD[arg_ch].spu_config, SPU_ADDRESS_LOOP,
//			m_VoiceIndex[arg_voice].loop_offset);	
	SpuSetParameter(m_CD[arg_ch].spu_config, SPU_ADDRESS_START,
			m_PsxAttackOffset[arg_voice]);
	SpuSetParameter(m_CD[arg_ch].spu_config, SPU_ADDRESS_LOOP,
			m_PsxLoopOffset[arg_voice]);
	


	// adsr settings

	SpuSetParameter(m_CD[arg_ch].spu_config, SPU_ATTACK_RATE,
			m_VoiceIndex[arg_voice].attack_rate);
	SpuSetParameter(m_CD[arg_ch].spu_config, SPU_ATTACK_MODE,
			m_VoiceIndex[arg_voice].attack_mode);
	SpuSetParameter(m_CD[arg_ch].spu_config, SPU_SUSTAIN_RATE,
			m_VoiceIndex[arg_voice].sustain_rate);
	SpuSetParameter(m_CD[arg_ch].spu_config, SPU_SUSTAIN_MODE,
			m_VoiceIndex[arg_voice].sustain_mode);
	SpuSetParameter(m_CD[arg_ch].spu_config, SPU_RELEASE_RATE,
			m_VoiceIndex[arg_voice].release_rate);
	SpuSetParameter(m_CD[arg_ch].spu_config, SPU_RELEASE_MODE,
			m_VoiceIndex[arg_voice].release_mode);
	SpuSetParameter(m_CD[arg_ch].spu_config, SPU_DECAY_RATE,
			m_VoiceIndex[arg_voice].decay_rate);
	SpuSetParameter(m_CD[arg_ch].spu_config, SPU_SUSTAIN_LEVEL,
			m_VoiceIndex[arg_voice].sustain_level);
}


void AkaoParser::RefreshWaveParameters(int arg_ch)
{
	s32 temp;

	if(m_CD[arg_ch].wave_modifier & 0x8000)
	{
		temp = ((m_CD[arg_ch].wave_modifier & 0x7f00) >> 8) *
			m_CD[arg_ch].pitch_base;
	}
	else
	{
		temp = ((m_CD[arg_ch].wave_modifier & 0x7f00) >> 8) *
			(((int)(15 * m_CD[arg_ch].pitch_base)) >> 8);
	}

	m_CD[arg_ch].wave_multiplier = temp >> 7;
	
	//	m_CD[i].wave_multiplier =
	//		(s16)((s32)(((m_CD[i].wave_modifier & 0x7f00) >> 8) *
	//		(m_CD[i].wave_modifier & 0x8000 ?
	//		m_CD[i].pitch_base :
	//		((s32)(15 * m_CD[i].pitch_base)) >> 8)) >> 7);
}


void AkaoParser::PrintOpcode(int arg_ch, u8 arg_opc)
{
	cout << hex;
	cout << setfill('0');

	cout << (int)arg_opc;

	int parameters_count = m_OpcodesParametersCount[arg_opc - 0xa0];
	if(parameters_count)
		for(int i = 0; i < parameters_count; ++i)
			cout << ' ' << setw(2) <<
				(int)m_CD[arg_ch].stream[m_CD[arg_ch].current_pos + i];

	cout << setfill(' ');
	cout << dec;
}


int AkaoParser::DumpSequenceData(const char *arg_file)
{
	if(m_SequenceDataFilename == "")
		return 0xff;

	ofstream oF;
	oF.open(arg_file, ios_base::binary | ios_base::out);
	if(!oF.is_open())
		return 1;

	oF << setfill('0');
	oF << hex;
	oF << "*** Frame ID: 0x" << setw(4) << m_SequenceHeader.id << endl;
	oF << dec;
	oF << "*** Frame Length: " << m_SequenceHeader.length << " bytes" << endl;
	oF << hex;
	oF << "*** Reverb Mode: 0x" << setw(4)
		<< m_SequenceHeader.reverb_mode << endl;
	oF << hex;
	oF << "*** Unused Data: ";
	for(int i = 0; i < 6; ++i)
		oF << setw(2) << (int)m_SequenceHeader.unused[i] << ' ';
	oF << endl;

	u8 channels_count = 0;
	for(int i = 0; i < m_AKAO_CHANNELS_COUNT; ++i)
		if(m_CD[i].stream)
			++channels_count;
	oF << dec;
	oF << "*** Channels count: " << setw(2)
		<< (int)channels_count << endl << endl;

	for(int i = 0; i < m_AKAO_CHANNELS_COUNT; ++i)
	{
		if(m_CD[i].stream == NULL)
			continue;
		oF << dec;
		oF << "*** Channel " << setw(2) << (int)i << " sequence: " << endl;

		oF << hex;
		u16 j = 0;
		while(j < m_CD[i].stream_length)
		{
			switch(m_CD[i].stream[j])
			{
				// no parameters
				case 0xa0:
				case 0xa6:
				case 0xa7:
				case 0xb3:
				case 0xb6:
				case 0xba:
				case 0xbe:
				case 0xc2:
				case 0xc3:
				case 0xc4:
				case 0xc5:
				case 0xc6:
				case 0xc7:
				case 0xc8:
				case 0xca:
				case 0xcb:
				case 0xcc:
				case 0xcd:
				case 0xd0:
				case 0xd1:
				case 0xd4:
				case 0xd5:
				case 0xd6:
				case 0xd7:
				case 0xdb:
				case 0xe0:
				case 0xe1:
				case 0xe2:
				case 0xe3:
				case 0xe4:
				case 0xe5:
				case 0xe6:
				case 0xe7:
				case 0xed:
				case 0xf3:
				case 0xf5:
				case 0xf9:
				case 0xfa:
				case 0xfb:
				case 0xfc:
				case 0xff:
					oF << setw(2) << (int)m_CD[i].stream[j];
					oF << endl;
					++j;
					break;

				// one parameter
				case 0xa1:
				case 0xa2:
				case 0xa3:
				case 0xa5:
				case 0xa8:
				case 0xaa:
				case 0xac:
				case 0xad:
				case 0xae:
				case 0xaf:
				case 0xb1:
				case 0xb2:
				case 0xb5:
				case 0xb7:
				case 0xb9:
				case 0xbb:
				case 0xbd:
				case 0xbf:
				case 0xc0:
				case 0xc1:
				case 0xc9:
				case 0xce:
				case 0xcf:
				case 0xd2:
				case 0xd3:
				case 0xd8:
				case 0xd9:
				case 0xda:
				case 0xdc:
				case 0xf2:
				case 0xf6:
				case 0xf8:
					oF << setw(2) << (int)m_CD[i].stream[j] << ' ';
					oF << setw(2) << (int)m_CD[i].stream[j + 1];
					oF << endl;
					j += 2;
					break;

				// two parameters
				case 0xa4:
				case 0xa9:
				case 0xab:
				case 0xb0:
				case 0xbc:
				case 0xdd:
				case 0xde:
				case 0xdf:
				case 0xe8:
				case 0xea:
				case 0xec:
				case 0xee:
				case 0xf4:
				case 0xf7:
				case 0xfd:
				case 0xfe:
					oF << setw(2) << (int)m_CD[i].stream[j] << ' ';
					oF << setw(2) << (int)m_CD[i].stream[j + 1] << ' ';
					oF << setw(2) << (int)m_CD[i].stream[j + 2];
					oF << endl;
					j += 3;
					break;

				// three parameters
				case 0xb4:
				case 0xb8:
				case 0xe9:
				case 0xeb:
				case 0xef:
				case 0xf0:
				case 0xf1:
					oF << setw(2) << (int)m_CD[i].stream[j] << ' ';
					oF << setw(2) << (int)m_CD[i].stream[j + 1] << ' ';
					oF << setw(2) << (int)m_CD[i].stream[j + 2] << ' ';
					oF << setw(2) << (int)m_CD[i].stream[j + 3];
					oF << endl;
					j += 4;
					break;

				default:
					oF << setw(2)
						<< (int)m_CD[i].stream[j];
					if(j < m_CD[i].stream_length - 1 &&
							m_CD[i].stream[j + 1] < 0xa0)
						oF << ' ';
					else
						oF << endl;
					++j;
				}
		}

		oF << endl;
	}

	oF.close();

	return 0;
}


void AkaoParser::AerisTest()
{
	;
}

