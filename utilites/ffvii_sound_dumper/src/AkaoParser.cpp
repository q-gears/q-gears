#include "AkaoParser.h"

#include "engine/SoundManager.h"
#include "../../common/File.h"
#include "../../common/Logger.h"
#include "../../common/TypeDefine.h"



const u16 akao_pause_table[ 11 ] =
{
    0xc0c0, 0x6060, 0x3030, 0x1818, 0x0c0c, 0x0606, 0x0303, 0x2020, 0x1010, 0x0808, 0x0404
};



s16 akao_left_volume_table[ 256 ] =
{
    32640, 32384, 32128, 31872, 31616, 31360, 31104, 30848, 30592, 30336, 30080, 29824, 29568, 29312, 29056, 28800,
    28544, 28288, 28032, 27776, 27520, 27264, 27008, 26752, 26496, 26240, 25984, 25728, 25472, 25216, 24960, 24704,
    24448, 24192, 23936, 23680, 23424, 23168, 22912, 22656, 22400, 22144, 21888, 21632, 21376, 21120, 20864, 20608,
    20352, 20096, 19840, 19584, 19328, 19072, 18816, 18560, 18304, 18048, 17792, 17536, 17280, 17024, 16768, 16512,
    16256, 16000, 15744, 15488, 15232, 14976, 14720, 14464, 14208, 13952, 13696, 13440, 13184, 12928, 12672, 12416,
    12160, 11904, 11648, 11392, 11136, 10880, 10624, 10368, 10112,  9856,  9600,  9344,  9088,  8832,  8576,  8320,
     8064,  7808,  7552,  7296,  7040,  6784,  6528,  6272,  6016,  5760,  5504,  5248,  4992,  4736,  4480,  4224,
     3968,  3712,  3456,  3200,  2944,  2688,  2432,  2176,  1920,  1664,  1408,  1152,   896,   640,   384,   128,
        0,    -1,    -4,    -9,   -16,   -25,   -36,   -49,   -64,   -81,  -100,  -121,  -144,  -169,  -196,  -225,
     -256,  -289,  -324,  -361,  -400,  -441,  -484,  -529,  -576,  -625,  -676,  -729,  -784,  -841,  -900,  -961,
    -1024, -1089, -1156, -1225, -1296, -1369, -1444, -1521, -1600, -1681, -1764, -1849, -1936, -2025, -2116, -2209,
    -2304, -2401, -2500, -2601, -2704, -2809, -2916, -3025, -3136, -3249, -3364, -3481, -3600, -3721, -3844, -3969,
     4096,  4225,  4356,  4489,  4624,  4761,  4900,  5041,  5184,  5329,  5476,  5625,  5776,  5929,  6084,  6241,
     6400,  6561,  6724,  6889,  7056,  7225,  7396,  7569,  7744,  7921,  8100,  8281,  8464,  8649,  8836,  9025,
     9216,  9409,  9604,  9801, 10000, 10201, 10404, 10609, 10816, 11025, 11236, 11449, 11664, 11881, 12100, 12321,
    12544, 12769, 12996, 13225, 13456, 13689, 13924, 14161, 14400, 14641, 14884, 15129, 15376, 15625, 15876, 16129
};

s16 akao_right_volume_table[ 256 ] =
{
      128,   384,   640,   896,  1152,  1408,  1664,  1920,  2176,  2432,  2688,  2944,  3200,  3456,  3712,  3968,
     4224,  4480,  4736,  4992,  5248,  5504,  5760,  6016,  6272,  6528,  6784,  7040,  7296,  7552,  7808,  8064,
     8320,  8576,  8832,  9088,  9344,  9600,  9856, 10112, 10368, 10624, 10880, 11136, 11392, 11648, 11904, 12160,
    12416, 12672, 12928, 13184, 13440, 13696, 13952, 14208, 14464, 14720, 14976, 15232, 15488, 15744, 16000, 16256,
    16512, 16768, 17024, 17280, 17536, 17792, 18048, 18304, 18560, 18816, 19072, 19328, 19584, 19840, 20096, 20352,
    20608, 20864, 21120, 21376, 21632, 21888, 22144, 22400, 22656, 22912, 23168, 23424, 23680, 23936, 24192, 24448,
    24704, 24960, 25216, 25472, 25728, 25984, 26240, 26496, 26752, 27008, 27264, 27520, 27776, 28032, 28288, 28544,
    28800, 29056, 29312, 29568, 29824, 30080, 30336, 30592, 30848, 31104, 31360, 31616, 31872, 32128, 32384, 32640,
    16129, 15876, 15625, 15376, 15129, 14884, 14641, 14400, 14161, 13924, 13689, 13456, 13225, 12996, 12769, 12544,
    12321, 12100, 11881, 11664, 11449, 11236, 11025, 10816, 10609, 10404, 10201, 10000,  9801,  9604,  9409,  9216,
     9025,  8836,  8649,  8464,  8281,  8100,  7921,  7744,  7569,  7396,  7225,  7056,  6889,  6724,  6561,  6400,
     6241,  6084,  5929,  5776,  5625,  5476,  5329,  5184,  5084,  4900,  4761,  4624,  4489,  4356,  4225,  4096,
    -3969, -3844, -3721, -3600, -3481, -3364, -3249, -3136, -3025, -2916, -2809, -2704, -2601, -2500, -2401, -2304,
    -2209, -2116, -2025, -1936, -1849, -1764, -1981, -1600, -1521, -1444, -1369, -1296, -1225, -1156, -1089, -1024,
     -961,  -900,  -841,  -784,  -729,  -676,  -625,  -576,  -529,  -484,  -441,  -400,  -361,  -324,  -289,  -256,
     -225,  -196,  -169,  -144,  -121,  -100,   -81,   -64,   -49,   -36,   -25,   -16,    -9,    -4,    -1,     0
};

s16 akao_wave_table[ 708 ] =
{
      8191,  -8191,  16383, -16383,  24575, -24575,  32767, -32767,     0,      0,     -2,      0,  32767, -32767,      0,      0,
        -2,      0,   8191,      0,  16383,      0,  24575,      0, 32767,      0,      0,     -2,  32767,      0,  32767,      0,
         0,     -2,  -8191,      0, -16383,      0, -24575,      0,-32767,      0,      0,     -2, -32767,      0, -32767,      0,
         0,     -2,      0,   1280,   2530,   4813,   5790,   6625,  7297,   7789,   8090,   8191,   8092,   7793,   7302,   6632,
      5799,   4823,   3728,   2542,   1293,      0,  -1268,  -2518, -3706,  -4803,  -5782,  -6618,  -7292,  -7786,  -8089,  -8192,
     -8095,  -7798,  -7309,  -6641,  -5809,  -4835,  -3741,  -2556, -1307,      0,   2561,   5060,   9626,  11580,  13250,  14594,
     15578,  16180,  16383,  16184,  15586,  14605,  13265,  11599,  9647,   7457,   5085,   2587,      0,  -2536,  -5036,  -7412,
     -9605, -11563, -13235, -14583, -15571, -16177, -16384, -16189,-15595, -14618, -13281, -11618,  -9669,  -7482,  -5111,  -2614,
         0,   3842,   7590,  14439,  17370,  19875,  21891,  23367, 24270,  24575,  24276,  23379,  21908,  19898,  17398,  14470,
     11186,   7627,   3881,      0,  -3804,  -7554, -11118, -14408,-17344, -19853, -21874, -23357, -24265, -24576, -24284, -23393,
    -21927, -19922, -17427, -14503, -11223,  -7666,  -3921,      0,  5123,  10120,  19252,  23161,  26500,  29188,  31157,  32360,
     32767,  32369,  31173,  29211,  26531,  23198,  19294,  14915, 10170,   5175,      0,  -5072, -10072, -14823, -19210, -23125,
    -26470, -29165, -31142, -32353, -32768, -32378, -31190, -29236,-26562, -23235, -19337, -14963, -10221,  -5227,      0,      0,
       -39,      0,      0,   5123,  10120,  19252,  23161,  26500, 29188,  31157,  32360,  32767,  32369,  31173,  29211,  26531,
     23198,  19294,  14915,  10170,   5175,      0,  -5072, -10072,-14823, -19210, -23125, -26470, -29165, -31142, -32353, -32768,
    -32378, -31190, -29236, -26562, -23235, -19337, -14963, -10221, -5227,      0,      0,    -39,      0,   2530,   4813,   6625,
      7789,   8191,   7793,   6632,   4823,   2542,     13,  -2518, -4803,  -6618,  -7786,  -8192,  -7798,  -6641,  -4835,  -2556,
         0,   5060,   9626,  13250,  15578,  16383,  15586,  13265,  9647,   5085,     26,  -5036,  -9605, -13235, -15571, -16384,
    -15595, -13281,  -9669,  -5111,      0,   7590,  14439,  19875, 23367,  24575,  23379,  19898,  14470,   7627,     39,  -7554,
    -14408, -19853, -23357, -24576, -23393, -19922, -14503,  -7666,     0,  10120,  19252,  26500,  31157,  32767,  31173,  26531,
     19294,  10170,     52, -10072, -19210, -26470, -31142, -32768,-31190, -26562, -19337, -10221,      0,      0,    -20,      0,
         0,  10120,  19252,  26500,  31157,  32767,  31173,  26531, 19294,  10170,     52, -10072, -19210, -26470, -31142, -32768,
    -31190, -26562, -19337, -10221,      0,      0,    -20,      0,     0,   2047,   4095,   6143,   8191,   6143,   4095,   2047,
         0,  -2047,  -4095,  -6143,  -8191,  -6143,  -4095,  -2047,     0,   4095,   8191,  12287,  16383,  12287,   8191,   4095,
         0,  -4095,  -8191, -12287, -16383, -12287,  -8191,  -4095,     0,   6143,  12287,  18431,  24575,  18431,  12287,   6143,
         0,  -6143, -12287, -18431, -24575, -18431, -12287,  -6143,     0,   8191,  16383,  24575,  32767,  24575,  16383,   8191,
         0,  -8191, -16383, -24575, -32767, -24575, -16383,  -8191,     0,      0,    -16,      0,      0,   8191,  16383,  24575,
     32767,  24575,  16383,   8191,      0,  -8191, -16383, -24575,-32767, -24575, -16383,  -8191,      0,      0,    -16,      0,
         0,  12797,  32005,  -2563,  -4882,  31036,  30160,   2044, -3055, -15627,  26127,  13070,  16362, -16671, -29678,   6177,
    -20485,  18944, -11289,  -2827,  -7881,  -6189,  21005,   4355,-20769,  19192,   1862,  28916, -28991, -26855,  13586,  -2560,
      6912, -19223,  15134, -20971, -25400,  26105, -15581,  29176, 11505, -23036, -27908, -14066, -20471,   4325,   2052, -32767,
      4858,   4376,  -6391,  18424, -27175,  -8932,   6921,   3060, 31740,   8447, -27644,  32252, -29963, -18665,  29945,  11004,
     -8954, -10253,  -2819,   1544,  -3560,  27103, -17401,  19191,-30229, -17625,   4361,  32751,  13845,  -4915,  30241, -26603,
     22223, -11258,  13090,  -8218, -20726, -17931, -12792,  23813,-16402,  -4070,   8424, -24810, -29454, -15641, -11730, -14847,
    -17968, -32500,  17187,  10461, -26889,  23612, -24610, -20760,-18917,  16115,   5128,  -9495,  11275, -20173, -22303,   1498,
      2324,  20002,    -24, -30735,   8688, -29403,  32252,   7408, 24081,  15848, -14582, -28905,    -16,  27149,    -29,   4851,
      1055,  30732, -15121,  23298,  15618,    754,   5401,  -9515,-17143, -28135,  -2813,  25309,  14342,   3878, -22277,  -7938,
     -2333,   3586,    528,  17414, -27436, -12022, -22458,   4337,  6860, -16899,   6704, -24341,  24554, -16624, -17425,  -8421,
    -15860,  10976,  16114, -20953,  20481,  -1571,  13841, -21222,  2015,  27909,   6669, -18725,  27947,  13831,  -1076,  16904,
      3873,  14070, -14330,   1539,   -553,  30743,   1541, -20725,-27140,   4332, -22770, -21005,  26127, -16910,  -8456,  -7135,
    -19993,   -787,  23324, -24311, -13070,  -2573, -25861, -19433,-27928,  32520,  19450, -30211,  15388,   -785,  -3365,  18973,
     26397, -10497,  26074,  -3588,  28170,   2572,   4600,  18946, 23548,  -5370, -23059,  12518, -32751, -11724,   2296,  17372,
     -2551, -22798, -26099,  28678,  -2582, -25348, -32482, -21018, -6642, -27145, -19708, -25345,  -4118,  -2791,  -1536,  15094,
    -14379,  10018, -17608,  17361,  30701,  18696, -12798, -21745, 15851,  -9462,  25601,  16377,  30450, -27895, -11761,  29925,
         0,      0,   -256,      0
};

u16 akao_wave_tabke_key_nodes[ 16 ] =
{
    0, 12, 18, 28, 34, 44, 50, 210, 360, 428, 252, 336, 448, 428, 360, 428
};

u8 opcode_size[ 96 ] =
{
    00, 02, 02, 02, 03, 02, 01, 01, 02, 03, 02, 03, 02, 02, 02, 02, // a0-af
    03, 02, 02, 01, 04, 02, 01, 02, 04, 02, 01, 02, 03, 02, 01, 02, // b0-bf
    02, 02, 01, 01, 01, 01, 01, 01, 01, 00, 00, 00, 01, 00, 02, 02, // c0-cf
    01, 00, 02, 02, 01, 01, 01, 01, 02, 02, 02, 00, 02, 03, 03, 03, // d0-df
    00, 00, 00, 00, 00, 00, 00, 00, 03, 04, 03, 04, 03, 01, 00, 00, // e0-ef
    00, 00, 02, 01, 03, 01, 02, 03, 02, 01, 00, 00, 00, 03, 03, 00, // f0-ff
};



AkaoParser *AKAOPARSER = NULL;



AkaoParser::AkaoParser():
    m_Music( NULL )
{
    memset( ( u8* )m_MusicChannelData, 0x00, sizeof( ChannelData ) * 24 );
}



AkaoParser::~AkaoParser()
{
}



void
AkaoParser::Update()
{
    UpdateDynamicSpuParameters();



    if ( m_MusicChannelConfig.active_channel_mask != 0 )
    {

        //V1 = w[80062fea];
        u32 tempo = m_MusicChannelConfig.tempo >> 0x10;
/*
        if (V1 != 0)
        {
            if (V1 < 80)
            {
                tempo += (tempo * V1) >> 0x7;
            }
            else
            {
                tempo = (tempo * V1) >> 0x8;
            }
        }
*/
        m_MusicChannelConfig.tempo_counter += tempo;
        //LOGGER->Log( ToHexString( m_MusicChannelConfig.tempo_counter, 8, '0' ) + "\n" );

        if ( ( m_MusicChannelConfig.tempo_counter & 0xffff0000 ) /*|| ( w[80062ff8] & 00000004 )*/ )
        {
            m_MusicChannelConfig.tempo_counter &= 0x0000ffff;
            //[80062f04] = w(0);

            u32 channel_mask = m_MusicChannelConfig.active_channel_mask;
            int channel_id = 0;
            for ( u32 bit = 1; channel_mask != 0; bit <<= 1, channel_id += 1 )
            {
                if ( channel_mask & bit )
                {
                    channel_mask ^= bit;

                    m_MusicChannelData[ channel_id ].pause -= 0x0101;
                    //LOGGER->Log( "pause " + ToHexString( m_MusicChannelData[ channel_id ].pause, 4, '0' ) + "\n" );

                    //std::cout << "Channel " << channel_id << " pause " << ( m_MusicChannelData[ channel_id ].pause & 0x00ff ) << std::endl;

                    if ( ( m_MusicChannelData[ channel_id ].pause & 0x00ff ) == 0 )
                    {
                        //A1 = 8009a104;
                        UpdateSequence( m_MusicChannelData, channel_id, m_MusicChannelConfig );
                    }
                    else if ( ( m_MusicChannelData[ channel_id ].pause & 0xff00 ) == 0 )
                    {
                        m_MusicChannelData[ channel_id ].pause |= 0x100;

                        //[8009a114] = w(w[8009a114] | S0);
                        //[8009a110] = w(w[8009a110] & (0 NOR S0));
                    }

                    //A0 = S2; // 80096608
                    //A1 = 8009a104;
                    //A2 = S0;
                    //80030A28	jal    func2e478 [$8002e478]
                }
            }

            if ( m_MusicChannelConfig.tempo_increment_counter != 0 )
            {
                m_MusicChannelConfig.tempo_increment_counter -= 1;

                m_MusicChannelConfig.tempo += m_MusicChannelConfig.tempo_increment;
            }

/*
            if (hu[8009a154] != 0)
            {
                [8009a154] = h(hu[8009a154] - 1);
                [8009a144] = w(w[8009a144] + w[8009a148]);
                [8009a13c] = w(w[8009a13c] | 00000080);
            }

            if (hu[8009a15e] != 0)
            {
                [8009a160] = h(hu[8009a160] + 1);

                if (hu[8009a160] == hu[8009a15e])
                {
                    [8009a160] = h(0);
                    [8009a15c] = h(hu[8009a15c] + 1);

                    if (hu[8009a15c] == hu[8009a15a])
                    {
                        [8009a15c] = h(0);
                        [8009a162] = h(hu[8009a162] + 1);
                    }
                }
            }
*/
        }
    }
}



void
AkaoParser::LoadInstruments( const Ogre::String& all_file, const Ogre::String& dat_file )
{
    // load instruments adpsm
    {
        File* file = new File( all_file );

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



    {
        File* file = new File( dat_file );

        int file_size = file->GetFileSize();

        // load index records
        InstrumentData data;
        for ( int i = 0; i < file_size; i += 0x40 )
        {
            data.start_offset = file->GetU32LE( i + 0x00 );
            data.loop_offset = file->GetU32LE( i + 0x04 );
            data.attack_rate = file->GetU8( i + 0x08 );
            data.decay_rate = file->GetU8( i + 0x09 );
            data.sustain_level = file->GetU8( i + 0x0a );
            data.sustain_rate = file->GetU8( i + 0x0b );
            data.release_rate = file->GetU8( i + 0x0c );
            data.attack_mode = file->GetU8( i + 0x0d );
            data.sustain_mode = file->GetU8( i + 0x0e );
            data.release_mode = file->GetU8( i + 0x0f );
            data.pitch[ 0 ] = file->GetU32LE( i + 0x10 );
            data.pitch[ 1 ] = file->GetU32LE( i + 0x14 );
            data.pitch[ 2 ] = file->GetU32LE( i + 0x18 );
            data.pitch[ 3 ] = file->GetU32LE( i + 0x1c );
            data.pitch[ 4 ] = file->GetU32LE( i + 0x20 );
            data.pitch[ 5 ] = file->GetU32LE( i + 0x24 );
            data.pitch[ 6 ] = file->GetU32LE( i + 0x28 );
            data.pitch[ 7 ] = file->GetU32LE( i + 0x2c );
            data.pitch[ 8 ] = file->GetU32LE( i + 0x30 );
            data.pitch[ 9 ] = file->GetU32LE( i + 0x34 );
            data.pitch[ 10 ] = file->GetU32LE( i + 0x38 );
            data.pitch[ 11 ] = file->GetU32LE( i + 0x3c );

            m_InstrumentData.push_back( data );
        }

        delete file;
    }
}



void
AkaoParser::UnloadInstruments()
{
    m_InstrumentData.clear();
}



void
AkaoParser::PlayMusic( const Ogre::String& file )
{
    if ( m_Music != NULL )
    {
        delete m_Music;
    }
    m_Music = new File( file );



    if ( m_Music->GetU8( 0 ) == 0x41 && m_Music->GetU8( 1 ) == 0x4b && m_Music->GetU8( 2 ) == 0x41 && m_Music->GetU8( 3 ) == 0x4f) // AKAO
    {
        int music_id = m_Music->GetU16LE( 4 );
        int length = m_Music->GetU16LE( 6 );
        int reverb_mode = m_Music->GetU16LE( 8 );

        //A0 = reverb_mode;
        //func29af0;

        //[V0 + 0] = w(w[8009a000]);
        //[V0 + 4] = w(akao_offset + 16);
        //[V0 + 8] = w(frame_length);
        //[V0 + c] = w(frame_id);
        //[V0 + 10] = w(w[8009a008]);


/*
        if (m_MusicChannelConfig.active_channel_mask != 0)
        {
            A2 = 80096608;

            V0 = w[8009a128];
            V1 = w[8009a12c];

            [8009a12c] = w(0);
            [8009a128] = w(0);
            [8009a110] = w(0);

            m_MusicChannelConfig.for_play_channel_mask = 0;

            A0 = m_MusicChannelConfig.active_channel_mask | V0 | V1;
            m_MusicChannelConfig.active_channel_mask = A0;
            [8009a114] = w(A0 | w[8009a114]);

            A1 = 1;
            loop29f18:	; 80029F18
                if (A0 XOR A1)
                {
                    A0 = A0 XOR A1;
                    [A2 + 56] = h(204);
                    [A2 + 0] = w(80049c40);
                }

                A1 = A1 << 1;
                A2 = A2 + 108;
            80029F34	bne    a0, zero, loop29f18 [$80029f18]
        }
*/



        //[8009a114] = w(w[8009a114] | 00ffffff);



        u16 offset_to_akao = 0;
        m_MusicChannelConfig.active_channel_mask = m_Music->GetU32LE( 0x10 ) & /*0x00ffffff*/ 1;
        u32 channel_mask = m_MusicChannelConfig.active_channel_mask;
        int channel_id = 0;
        for ( u32 bit = 1; channel_mask != 0; bit <<= 1, channel_id += 1 )
        {
            if ( channel_mask & bit )
            {
                channel_mask ^= bit;

                m_MusicChannelData[ channel_id ].akao_sequence_pointer = 20 + offset_to_akao + 2 + m_Music->GetU16LE( 20 + offset_to_akao );
                offset_to_akao += 2;
                LOGGER->Log( "Init channel " + ToIntString( channel_id ) + " with offset to AKAO " + ToHexString( m_MusicChannelData[ channel_id ].akao_sequence_pointer, 4, '0' ) + "\n" );

                InitChannelInstrument( m_MusicChannelData, channel_id, 0x14 );

                //[S3 + 14] = w(80083580);
                m_MusicChannelData[ channel_id ].volume_multiplier = 0x7f;
                m_MusicChannelData[ channel_id ].pitch_addition = 0;
                m_MusicChannelData[ channel_id ].mirror_update_flags = 0;
                m_MusicChannelData[ channel_id ].volume_level = 0x3fff0000;
                m_MusicChannelData[ channel_id ].pause = 0x103;
                //[S3 + 5c] = h(0);
                //[S3 + 5e] = h(0);
                m_MusicChannelData[ channel_id ].volume_index = 0x4000;
                m_MusicChannelData[ channel_id ].unknown_62 = 0;
                m_MusicChannelData[ channel_id ].unknown_64 = 0;
                m_MusicChannelData[ channel_id ].unknown_6c = 0;
                m_MusicChannelData[ channel_id ].unknown_6e = 0;
                m_MusicChannelData[ channel_id ].wave_modifier = 0;
                //[S3 + 80] = h(0);
                //[S3 + 90] = h(0);
                //[S3 + 92] = h(0);
                //[S3 + 9e] = h(0);
                //[S3 + a0] = h(0);
                //[S3 + a4] = h(0);
                //[S3 + a6] = h(0);
                m_MusicChannelData[ channel_id ].loop_index = 0;
                m_MusicChannelData[ channel_id ].saved_pause = 0;
                m_MusicChannelData[ channel_id ].pause_multiplier = 0;
                //[S3 + c6] = h(4000);
                m_MusicChannelData[ channel_id ].pitch_selector = 0;
                m_MusicChannelData[ channel_id ].pitch_modifier = 0;
                m_MusicChannelData[ channel_id ].unknown_d2 = 0;
                //[S3 + da] = h(0);
            }
        }

        m_MusicChannelConfig.for_play_channel_mask = 0;
/*
        [8009a110] = w(0);
*/

        m_MusicChannelConfig.tempo = 0xffff0000;
        m_MusicChannelConfig.tempo_counter = 1; // this way we update sequence on next update
/*
        [8009a128] = w(0);
        [8009a12c] = w(0);
        [8009a130] = w(0);
        [8009a134] = w(0);
        [8009a138] = w(0);
*/
        m_MusicChannelConfig.spu_update_flags = 0;
        m_MusicChannelConfig.reverb_depth = 0;
        //[8009a148] = w(0);

        m_MusicChannelConfig.tempo_increment_counter = 0;

        //[8009a150] = h(0);
        //[8009a152] = h(0);
        m_MusicChannelConfig.reverb_depth_increment_counter = 0;
        //[8009a158] = h(0);
        m_MusicChannelConfig.upper_timer_top = 0;
        m_MusicChannelConfig.upper_timer = 0;
        m_MusicChannelConfig.lower_timer_top = 0;
        m_MusicChannelConfig.lower_timer = 0;
        m_MusicChannelConfig.top_timer = 0;
/*
        [8009a15e] = h(0);
        [8009a160] = h(0);
        [8009a162] = h(0);

        if (w[80062ff8] & 1)
        {
            [8009a108] = w(0);
            [8009a118] = w(w[8009a108]);
        }

        func2ff4c

        func30038

        func30148
*/
    }
}



void
AkaoParser::UpdateDynamicSpuParameters()
{
    u32 for_play_channel_mask = 0;



    if( m_MusicChannelConfig.spu_update_flags & SPU_REVERB )
    {
        s16 reverb_depth = m_MusicChannelConfig.reverb_depth >> 0x10;
        /* looks like update of total reverb volume if this is ever used
        V1 = hu[80062fb8];
        if (V1 < 80)
        {
            reverb_depth = reverb_depth + ((reverb_depth * V1) >> 7);
        }
        else
        {
            reverb_depth = (reverb_depth * V1) >> 8;
        }
        */
        u8 pan = 0x40 /*hu[80062f70]*/;
        s16 left = reverb_depth;
        s16 right = reverb_depth;
        if( pan < 0x40 )
        {
            right = reverb_depth - ( ( reverb_depth * ( pan ^ 0x3f ) ) >> 6 );
        }
        else
        {
            left = reverb_depth - ( ( reverb_depth * ( pan & 0x3f ) ) >> 6 );
        }

        SOUNDMAN->PsxSetReverbDepth( left, right );

        m_MusicChannelConfig.spu_update_flags ^= SPU_REVERB;
    }



    if ( m_MusicChannelConfig.active_channel_mask != 0 )
    {
        for_play_channel_mask |= m_MusicChannelConfig.for_play_channel_mask;
        u32 channel_mask = m_MusicChannelConfig.active_channel_mask;
        int channel_id = 0;
        for ( u32 bit = 1; channel_mask != 0; bit <<= 1, channel_id += 1 )
        {
            if ( channel_mask & bit )
            {
                channel_mask ^= bit;

                UpdatePitchAndVolume( m_MusicChannelData, channel_id );

                if ( m_MusicChannelData[ channel_id ].spu_update_flags )
                {
                    UpdateSpu( m_MusicChannelData, channel_id );
                }
            }
        }

        m_MusicChannelConfig.for_play_channel_mask = 0;
    }



    if ( for_play_channel_mask != 0 )
    {
        UpdatePlayChannel( true, for_play_channel_mask );
    }
}



void
AkaoParser::UpdatePitchAndVolume( ChannelData* channel_data, int channel_id )
{
    int temp = ( ( channel_data[ channel_id ].volume_level >> 16) * channel_data[ channel_id ].volume_multiplier ) >> 7;

    if ( channel_data[ channel_id ].spu_update_flags & ( SPU_LEFT_VOLUME | SPU_RIGHT_VOLUME ) )
    {
        //temp = ( ( temp + h[T0 + d8] ) * ( hu[80062f5e] & 0x7f ) ) >> 7;
        temp = ( temp * 0x7f ) >> 7;

/*
        if (hu[8009c5a8] != 0)
        {
            temp = (temp * h[8009c5a2 + channel_id * c]) >> 7;
        }
*/


        int volume_index = ( /*h[T0 + da] + */channel_data[ channel_id ].volume_index >> 8) & 0xff;

/*
        V1 = w[8009a104];
        if (V1 == 1) // stereo
*/
        {
            channel_data[ channel_id ].left_volume = ( temp * akao_left_volume_table[ volume_index ] ) >> 0xf;
            channel_data[ channel_id ].right_volume = ( temp * akao_right_volume_table[ volume_index ] ) >> 0xf;
        }
/*
        else if (V1 == 4)
        {
            channel_data[ channel_id ].left_volume = (temp * akao_left_volume_table[ volume_index ] ) >> 0xf;
            channel_data[ channel_id ].right_volume = (temp * akao_right_volume_table[ volume_index ] ) >> 0xf;

            if (A1 & 00aaaaaa == 0)
            {
                channel_data[ channel_id ].left_volume = 0 NOR channel_data[ channel_id ].left_volume;
            }
            else
            {
                channel_data[ channel_id ].right_volume = 0 NOR channel_data[ channel_id ].right_volume;
            }
        }
        else
        {
            channel_data[ channel_id ].left_volume = ( temp * h[80049cc4]) >> 0xf;
            channel_data[ channel_id ].right_volume = ( temp * h[80049cc4]) >> 0xf;
        }
*/
    }



    u16 new_pitch = 0;
/*
    if (w[T0 + 38] & 00000010)
    {
        V1 = h[T0 + d6] + h[T0 + 36] + w[T0 - 10]; // uses pitch from previous channel
    }
    else*/
    if ( channel_data[ channel_id ].spu_update_flags & SPU_PITCH )
    {
        new_pitch = channel_data[ channel_id ].pitch_base + ( channel_data[ channel_id ].pitch_addition >> 0x10 ) + channel_data[ channel_id ].pitch_addition2;
    }



    if (/*(w[T0 + 38] & 00000010) ||*/ ( channel_data[ channel_id ].spu_update_flags & SPU_PITCH ) )
    {
        channel_data[ channel_id ].spu_update_flags |= SPU_PITCH;
        channel_data[ channel_id ].pitch = new_pitch & 0x3fff;
    }
}



void
AkaoParser::UpdateSpu( ChannelData* channel_data, int channel_id )
{
    //S1 = A0;
    //S0 = A1;

    if ( channel_data[ channel_id ].spu_update_flags & SPU_PITCH )
    {
/*
        A0 = S1;
        A1 = hu[S0 + 1c]; // f8
        func395c8;
*/
        //LOGGER->Log( "UpdateSpu::SPU_PITCH channel " + Ogre::StringConverter::toString( channel_id ) + " value:" + Ogre::StringConverter::toString( channel_data[ channel_id ].pitch ) + ".\n" );
        SOUNDMAN->SetVoicePitch( channel_id, channel_data[ channel_id ].pitch );
        channel_data[ channel_id ].spu_update_flags &= ~SPU_PITCH;
    }

    if ( channel_data[ channel_id ].spu_update_flags & ( SPU_LEFT_VOLUME | SPU_RIGHT_VOLUME ) )
    {
/*
        A0 = S1;
        A1 = h[S0 + 28]; // 104
        A2 = h[S0 + 2a]; // 106
        func393c8;
*/
        //LOGGER->Log( "UpdateSpu::SPU_LEFT_VOLUME|SPU_RIGHT_VOLUME channel " + Ogre::StringConverter::toString( channel_id ) + " value:" + Ogre::StringConverter::toString( channel_data[ channel_id ].left_volume ) + " " + Ogre::StringConverter::toString( channel_data[ channel_id ].right_volume ) + ".\n" );
        SOUNDMAN->SetVoiceVolume( channel_id, channel_data[ channel_id ].left_volume, channel_data[ channel_id ].right_volume );
        channel_data[ channel_id ].spu_update_flags &= ~( SPU_LEFT_VOLUME | SPU_RIGHT_VOLUME );
    }

    if ( channel_data[ channel_id ].spu_update_flags & SPU_START_OFFSET )
    {
/*
        A0 = S1;
        A1 = w[S0 + 8];
        func39644; // we set start address here
*/
        //LOGGER->Log( "UpdateSpu::SPU_START_OFFSET channel " + Ogre::StringConverter::toString( channel_id ) + " value:" + Ogre::StringConverter::toString( channel_data[ channel_id ].start_offset ) + ".\n" );
        SOUNDMAN->SetVoiceStartAddress( channel_id, channel_data[ channel_id ].start_offset );
        channel_data[ channel_id ].spu_update_flags &= ~SPU_START_OFFSET;
    }

    if ( channel_data[ channel_id ].spu_update_flags & SPU_LOOP_OFFSET )
    {
/*
        A0 = S1;
        A1 = w[S0 + c];
        func396c0;
*/
        //LOGGER->Log( "UpdateSpu::SPU_LOOP_OFFSET channel " + Ogre::StringConverter::toString( channel_id ) + " value:" + Ogre::StringConverter::toString( channel_data[ channel_id ].loop_offset ) + ".\n" );
        SOUNDMAN->SetVoiceLoopAddress( channel_id, channel_data[ channel_id ].loop_offset );
        channel_data[ channel_id ].spu_update_flags &= ~SPU_LOOP_OFFSET;
    }

    if ( channel_data[ channel_id ].spu_update_flags & ( SPU_SUSTAIN_RATE | SPU_SUSTAIN_MODE ) )
    {
/*
        A0 = S1;
        A1 = h[S0 + 24]; // 100
        A2 = h[S0 + 14]; // f0
        func398ec;
*/
        //LOGGER->Log( "UpdateSpu::SPU_SUSTAIN_RATE|SPU_SUSTAIN_MODE channel " + Ogre::StringConverter::toString( channel_id ) + " value:" + Ogre::StringConverter::toString( channel_data[ channel_id ].sustain_rate ) + " " + Ogre::StringConverter::toString( channel_data[ channel_id ].sustain_mode ) + ".\n" );
        SOUNDMAN->SetVoiceSustainRate( channel_id, channel_data[ channel_id ].sustain_rate, (SoundManager::SpuRateMode)channel_data[ channel_id ].sustain_mode );
        channel_data[ channel_id ].spu_update_flags &= ~( SPU_SUSTAIN_RATE | SPU_SUSTAIN_MODE );
    }

    if ( channel_data[ channel_id ].spu_update_flags & ( SPU_ATTACK_RATE | SPU_ATTACK_MODE ) )
    {
/*
        A0 = S1;
        A1 = h[S0 + 1e]; // fa
        A2 = h[S0 + 10]; // ec
        func39850;
*/
        //LOGGER->Log( "UpdateSpu::SPU_ATTACK_RATE|SPU_ATTACK_MODE channel " + Ogre::StringConverter::toString( channel_id ) + " value:" + Ogre::StringConverter::toString( channel_data[ channel_id ].attack_rate ) + " " + Ogre::StringConverter::toString( channel_data[ channel_id ].attack_mode ) + ".\n" );
        SOUNDMAN->SetVoiceAttackRate( channel_id, channel_data[ channel_id ].attack_rate, ( SoundManager::SpuRateMode )channel_data[ channel_id ].attack_mode );
        channel_data[ channel_id ].spu_update_flags &= ~( SPU_ATTACK_RATE | SPU_ATTACK_MODE );
    }

    if ( channel_data[ channel_id ].spu_update_flags & ( SPU_RELEASE_RATE | SPU_RELEASE_MODE ) )
    {
/*
        A0 = S1;
        A1 = h[S0 + 26]; // 102 // release rate
        A2 = h[S0 + 18]; // f4 // release mode
        func399d0;
*/
        //LOGGER->Log( "UpdateSpu::SPU_RELEASE_RATE|SPU_RELEASE_MODE channel " + Ogre::StringConverter::toString( channel_id ) + " value:" + Ogre::StringConverter::toString( channel_data[ channel_id ].release_rate ) + " " + Ogre::StringConverter::toString( channel_data[ channel_id ].release_mode ) + ".\n" );
        SOUNDMAN->SetVoiceReleaseRate( channel_id, channel_data[ channel_id ].release_rate, (SoundManager::SpuRateMode)channel_data[ channel_id ].release_mode );
        channel_data[ channel_id ].spu_update_flags &= ~( SPU_RELEASE_RATE | SPU_RELEASE_MODE );
    }

    if ( channel_data[ channel_id ].spu_update_flags & ( SPU_DECAY_RATE | SPU_SUSTAIN_LEVEL ) )
    {
/*
        A0 = S1;
        A1 = h[S0 + 20]; // fc // decay rate.
        func3973c;

        A0 = S1;
        A1 = h[S0 + 22]; // fe // sustain level.
        func397c8;
*/
        //LOGGER->Log( "UpdateSpu::SPU_DECAY_RATE|SPU_SUSTAIN_LEVEL channel " + Ogre::StringConverter::toString( channel_id ) + " value:" + Ogre::StringConverter::toString( channel_data[ channel_id ].decay_rate ) + " " + Ogre::StringConverter::toString( channel_data[ channel_id ].sustain_level ) + ".\n" );
        SOUNDMAN->SetVoiceDecayRate( channel_id, channel_data[ channel_id ].decay_rate );
        SOUNDMAN->SetVoiceSustainLevel( channel_id, channel_data[ channel_id ].sustain_level );
        channel_data[ channel_id ].spu_update_flags &= ~( SPU_DECAY_RATE | SPU_SUSTAIN_LEVEL );
    }
}



void
AkaoParser::UpdatePlayChannel( bool on, u32 channel_mask )
{
    int channel_id = 0;
    for ( u32 bit = 1; channel_mask != 0; bit <<= 1, channel_id += 1 )
    {
        if ( channel_mask & bit )
        {
            channel_mask ^= bit;

            if ( on == true )
            {
                SOUNDMAN->PsxChannelPlay( channel_id );
                std::cout << "Play channel " << channel_id << std::endl;
            }
            else
            {
                SOUNDMAN->PsxChannelStop( channel_id );
                std::cout << "Stop channel " << channel_id << std::endl;
            }
        }
    }
}



void
AkaoParser::UpdateSequence( ChannelData* channel_data, int channel_id, ChannelConfig& channel_config )
{
    //LOGGER->Log( "UpdateSequence for channel " + ToIntString( channel_id ) + "\n" );

    u8 opcode;

    for( ;; )
    {
        opcode = m_Music->GetU8( channel_data[ channel_id ].akao_sequence_pointer );

        if( opcode < 0xa0 )
        {
            channel_data[ channel_id ].akao_sequence_pointer += 1;
            break;
        }
        else if( opcode == 0xa1 ) // load instrument
        {
            LOGGER->Log( "    0xA1 [NOT COMPLETE] " );
            int instrument_id = m_Music->GetU8( channel_data[ channel_id ].akao_sequence_pointer + 1 );
            LOGGER->Log( "load instrument \"" + ToIntString( instrument_id ) + "\"\n" );

/*
            A0 = hu[A3 + 24];

            if (w[80062f04] != 0)
            {
                A0 = A0 - 18;
            }

            if (w[A3 + 38] & 00000100)
            {
                [A1 + 24] = w(w[A1 + 24] & (0 NOR (1 << A0)))
                [A3 + 38] = w(w[A3 + 38] & fffffeff)
            }

            if (hu[A3 + 54] != 0 || (A2 & w[A1 + c] & w[80099fcc]) == 0)
            {
                [A3 + e0] = w(w[A3 + e0] | 00000010);
                [A3 + 30] = w((w[A3 + 30] * w[80075f28 + instrument_id * 40 + 10]) / w[80075f28 + hu[A3 + 58] * 40 + 10]);
            }
*/
            // if loaded adsr release rate, load rest
            // note from G
            /*
            if (w[A3 + 38] & 00000200)
            {
                InstrumentData data = m_InstrumentData[ instrument_id ];

                channel_data[ channel_id ].instrument_id = instrument_id;
                channel_data[ channel_id ].start_offset = data.start_offset;
                channel_data[ channel_id ].loop_offset = data.loop_offset;
                channel_data[ channel_id ].attack_rate = data.attack_rate;
                channel_data[ channel_id ].decay_rate = data.decay_rate;
                channel_data[ channel_id ].attack_mode = data.attack_mode;
                channel_data[ channel_id ].sustain_mode = data.sustain_mode;
                channel_data[ channel_id ].sustain_level = data.sustain_level;
                channel_data[ channel_id ].sustain_rate = data.sustain_rate;
                channel_data[ channel_id ].spu_update_flags |=
                    SPU_START_OFFSET | SPU_ATTACK_RATE | SPU_SUSTAIN_RATE |
                    SPU_ATTACK_MODE | SPU_DECAY_RATE | SPU_SUSTAIN_MODE |
                    SPU_SUSTAIN_LEVEL | SPU_LOOP_OFFSET; // update everything we just set
            }
            else // init all data
            */
            {
                InitChannelInstrument( channel_data, channel_id, instrument_id );
            }

            channel_data[ channel_id ].akao_sequence_pointer += 2;
        }
        else if( opcode == 0xa3 ) // set volume multiplier
        {
            LOGGER->Log( "    0xA3 " );
            channel_data[ channel_id ].volume_multiplier = m_Music->GetU8( channel_data[ channel_id ].akao_sequence_pointer + 1 );
            channel_data[ channel_id ].spu_update_flags |= SPU_LEFT_VOLUME | SPU_RIGHT_VOLUME;
            LOGGER->Log( "Set volume multiplier to 0x" + ToHexString( channel_data[ channel_id ].volume_multiplier, 2, '0' ) + ".\n" );
            channel_data[ channel_id ].akao_sequence_pointer += 2;
        }
        else if( opcode == 0xa5 ) // set pitch correction
        {
            LOGGER->Log( "    0xA5 " );
            channel_data[ channel_id ].pitch_correction = m_Music->GetU8( channel_data[ channel_id ].akao_sequence_pointer + 1 );
            LOGGER->Log( "Set pitch correction to 0x" + ToHexString( channel_data[ channel_id ].pitch_correction, 4, '0' ) + ".\n" );
            channel_data[ channel_id ].akao_sequence_pointer += 2;
        }
        else if( opcode == 0xa6 ) // increment pitch correction
        {
            LOGGER->Log( "    0xA6 Increment pitch correction.\n" );
            channel_data[ channel_id ].pitch_correction = ( channel_data[ channel_id ].pitch_correction + 1 ) & 0xf;
            channel_data[ channel_id ].akao_sequence_pointer += 1;
        }
        else if( opcode == 0xa7 ) // decrement pitch correction
        {
            LOGGER->Log( "    0xA7 Decrement pitch correction.\n" );
            channel_data[ channel_id ].pitch_correction = ( channel_data[ channel_id ].pitch_correction - 1 ) & 0xf;
            channel_data[ channel_id ].akao_sequence_pointer += 1;
        }
        else if( opcode == 0xa8 ) // set volume
        {
            LOGGER->Log( "    0xA8 " );
            channel_data[ channel_id ].volume_multiplier = m_Music->GetU8( channel_data[ channel_id ].akao_sequence_pointer + 1 );
            channel_data[ channel_id ].spu_update_flags |= SPU_LEFT_VOLUME | SPU_RIGHT_VOLUME;
            channel_data[ channel_id ].volume_level_change_ticks = 0;
            channel_data[ channel_id ].volume_level = m_Music->GetU8( channel_data[ channel_id ].akao_sequence_pointer + 1 ) << 0x17;
            LOGGER->Log( "Set volume to 0x" + ToHexString(channel_data[ channel_id ].volume_level, 8, '0' ) + " and reset volume_level_change_ticks.\n" );
            channel_data[ channel_id ].akao_sequence_pointer += 2;
        }
        else if( opcode == 0xa9 ) // set volume increase/descrease
        {
            LOGGER->Log( "    0xA9 " );
            u16 value1 = m_Music->GetU8( channel_data[ channel_id ].akao_sequence_pointer + 1 );
            u16 value2 = m_Music->GetU8( channel_data[ channel_id ].akao_sequence_pointer + 2 );
            value1 = ( value1 == 0 ) ? 0x100 : value1;
            channel_data[ channel_id ].volume_level_change_ticks = value1;
            channel_data[ channel_id ].volume_level &= 0xffff0000;
            channel_data[ channel_id ].volume_level_new = ( ( value2 << 0x17 ) - channel_data[ channel_id ].volume_level ) / channel_data[ channel_id ].volume_level_change_ticks;
            LOGGER->Log( "Set volume tick to 0x" + ToHexString( channel_data[ channel_id ].volume_level_change_ticks, 4, '0' ) + " and " );
            LOGGER->Log( "volume_level_new 0x" + ToHexString( channel_data[ channel_id ].volume_level_new, 8, '0' ) + ".\n" );
            channel_data[ channel_id ].akao_sequence_pointer += 3;
        }
        else if( opcode == 0xaa ) // set volume pan
        {
            LOGGER->Log( "    0xAA " );
            channel_data[ channel_id ].spu_update_flags |= SPU_LEFT_VOLUME | SPU_RIGHT_VOLUME;
            channel_data[ channel_id ].volume_index = m_Music->GetU8( channel_data[ channel_id ].akao_sequence_pointer + 1 ) << 0x8;
            channel_data[ channel_id ].unknown_62 = 0;
            LOGGER->Log( "Set volume pan to 0x" + ToHexString( channel_data[ channel_id ].volume_index, 4, '0' ) + ".\n" );
            channel_data[ channel_id ].akao_sequence_pointer += 2;
        }
        else if( opcode == 0xad ) // ???
        {
            LOGGER->Log( "    0xAD [UNIMPLEMENTED]\n" );
            channel_data[ channel_id ].akao_sequence_pointer += 2;
        }
        else if( opcode == 0xb1 ) // ???
        {
            LOGGER->Log( "    0xB1 [UNIMPLEMENTED]\n" );
            channel_data[ channel_id ].akao_sequence_pointer += 2;
        }
        else if( opcode == 0xb4 ) // set wave
        {
            LOGGER->Log( "    0xB4 " );
            channel_data[ channel_id ].mirror_update_flags &= 0x00000001;

            u16 value1 = m_Music->GetU8( channel_data[ channel_id ].akao_sequence_pointer + 1 );
            u16 value2 = m_Music->GetU8( channel_data[ channel_id ].akao_sequence_pointer + 2 );
            u16 value3 = m_Music->GetU8( channel_data[ channel_id ].akao_sequence_pointer + 3 );

            if( channel_data[ channel_id ].unknown_54 != 0 )
            {
                channel_data[ channel_id ].wave_delay = 0;

                if( value1 != 0 )
                {
                    channel_data[ channel_id ].wave_modifier = value1 << 0x8;
                }
            }
            else
            {
                channel_data[ channel_id ].wave_delay = value1;
            }

            if( value2 == 0 )
            {
                value2 = 0x100;
            }

            channel_data[ channel_id ].wave_refresh_interval = value2;
            channel_data[ channel_id ].wave_table_node_index = value3;
            u16 pitch_base = channel_data[ channel_id ].pitch_base;
            if( ( channel_data[ channel_id ].wave_modifier & 0x8000 ) == 0 )
            {

                pitch_base = ( ( pitch_base << 4 ) - pitch_base ) >> 8;
            }

            channel_data[ channel_id ].wave_multiplier = ( ( ( channel_data[ channel_id ].wave_modifier & 0x7f00 ) >> 8 ) * pitch_base ) >> 7;
            channel_data[ channel_id ].wave_delay_current = channel_data[ channel_id ].wave_delay;
            channel_data[ channel_id ].wave_refresh_interval_counter = channel_data[ channel_id ].wave_table_node_index;
            channel_data[ channel_id ].wave_table_index = akao_wave_tabke_key_nodes[ channel_data[ channel_id ].wave_table_node_index ];
            LOGGER->Log( "Set wave refresh interval to 0x" + ToHexString( channel_data[ channel_id ].wave_refresh_interval, 4, '0' ) + " " );
            LOGGER->Log( ", node index to 0x" + ToHexString( channel_data[ channel_id ].wave_table_node_index, 4, '0' ) + " " );
            LOGGER->Log( "and wave delay (or wave modifier) to 0x" + ToHexString( value1, 2, '0' ) + ".\n" );
            channel_data[ channel_id ].akao_sequence_pointer += 4;
        }
        else if( opcode == 0xb5 ) // set wave modifier
        {
            LOGGER->Log( "    0xB5 " );
            channel_data[ channel_id ].wave_modifier = m_Music->GetU8( channel_data[ channel_id ].akao_sequence_pointer + 1 ) << 0x8;
            u16 pitch_base = channel_data[ channel_id ].pitch_base;
            if( ( channel_data[ channel_id ].wave_modifier & 0x8000 ) == 0 )
            {
                pitch_base = ( ( pitch_base << 4 ) - pitch_base ) >> 8;
            }
            channel_data[ channel_id ].wave_multiplier = ( ( ( channel_data[ channel_id ].wave_modifier & 0x7f00) >> 8 ) * pitch_base ) >> 7;
            LOGGER->Log( "Set wave modifier to 0x" + ToHexString( channel_data[ channel_id ].wave_modifier, 4, '0' ) + ".\n" );
            channel_data[ channel_id ].akao_sequence_pointer += 2;
        }
        else if( opcode == 0xc2 ) // turn reverb on
        {
            LOGGER->Log( "    0xC2 [UNIMPLEMENTED]\n" );
            channel_data[ channel_id ].akao_sequence_pointer += 1;
        }
        else if( opcode == 0xcc )
        {
            LOGGER->Log( "    0xCC Set unknown_6e to 1.\n" );
            channel_data[ channel_id ].unknown_6e = 1;
            channel_data[ channel_id ].akao_sequence_pointer += 1;
        }
        else if( opcode == 0xcd ) // does nothing
        {
            LOGGER->Log( "    0xCD Do nothing.\n" );
            channel_data[ channel_id ].akao_sequence_pointer += 1;
        }
        else if( opcode == 0xd9 )
        {
            LOGGER->Log( "    0xD9 [UNIMPLEMENTED]\n" );
            channel_data[ channel_id ].akao_sequence_pointer += 2;
        }
        else if( opcode == 0xe0 ) // ???
        {
            LOGGER->Log( "    0xE0 [UNIMPLEMENTED]\n" );
            channel_data[ channel_id ].akao_sequence_pointer += 1;
        }
        else if( opcode == 0xe2 ) // ???
        {
            LOGGER->Log( "    0xE2 [UNIMPLEMENTED]\n" );
            channel_data[ channel_id ].akao_sequence_pointer += 1;
        }
        else if( opcode == 0xe8 ) // set tempo
        {
            LOGGER->Log( "    0xE8 " );
            channel_config.tempo = m_Music->GetU16LE( channel_data[ channel_id ].akao_sequence_pointer + 1 ) << 0x10;
            channel_config.tempo_increment_counter = 0;
            LOGGER->Log( "Set tempo to 0x" + ToHexString( channel_config.tempo, 8, '0' ) + " and reset tempo increment counter to 0.\n" );
            channel_data[ channel_id ].akao_sequence_pointer += 3;
        }
        else if( opcode == 0xea ) // set reverb depth
        {
            LOGGER->Log( "    0xEA " );
            channel_config.spu_update_flags |= SPU_REVERB;
            channel_config.reverb_depth = m_Music->GetU16LE( channel_data[ channel_id ].akao_sequence_pointer + 1 ) << 0x10;
            channel_config.reverb_depth_increment_counter = 0;
            LOGGER->Log( "Set reverb depth to 0x" + ToHexString( channel_config.reverb_depth, 8, '0' ) + " and reset reverb depth increment counter to 0.\n" );
            channel_data[ channel_id ].akao_sequence_pointer += 3;
        }
        else if( opcode == 0xec )
        {
            LOGGER->Log( "    0xEC [UNIMPLEMENTED]\n" );
            channel_data[ channel_id ].akao_sequence_pointer += 3;
        }
        else if( opcode == 0xee ) // ???
        {
            LOGGER->Log( "    0xEE [UNIMPLEMENTED]\n" );
            channel_data[ channel_id ].akao_sequence_pointer += 3;
        }
        else if( opcode == 0xf0 )
        {
            LOGGER->Log( "    0xF0 [UNIMPLEMENTED]\n" );
            channel_data[ channel_id ].akao_sequence_pointer += 4;
        }
        else if( opcode == 0xf1 )
        {
            LOGGER->Log( "    0xF1 [UNIMPLEMENTED]\n" );
            channel_data[ channel_id ].akao_sequence_pointer += 4;
        }
        else if( opcode == 0xfd ) // reset timers lower and upper
        {
            LOGGER->Log( "    0xFD Reset upper timer to 0 with bound " );
            channel_config.upper_timer_top = m_Music->GetU8( channel_data[ channel_id ].akao_sequence_pointer + 2 );
            LOGGER->Log( ToHexString( channel_config.upper_timer_top, 4, '0' ) + " and lower timer to 0 with bound " );
            channel_config.upper_timer = 0;
            channel_config.lower_timer_top = m_Music->GetU8( channel_data[ channel_id ].akao_sequence_pointer + 1 );
            LOGGER->Log( ToHexString( channel_config.lower_timer_top, 4, '0' ) + ".\n" );
            channel_config.lower_timer = 0;
            channel_data[ channel_id ].akao_sequence_pointer += 3;
        }
        else if( opcode == 0xfe ) // reset timer top
        {
            LOGGER->Log( "    0xFE Reset top timer to " );
            channel_config.top_timer = m_Music->GetU16LE( channel_data[ channel_id ].akao_sequence_pointer + 1 );
            LOGGER->Log( ToHexString( channel_config.top_timer, 4, '0' ) + ".\n" );
            channel_data[ channel_id ].akao_sequence_pointer += 3;
        }
        else if( opcode == 0xff )
        {
            LOGGER->Log( "    0xFF [UNIMPLEMENTED]\n" );
            channel_data[ channel_id ].akao_sequence_pointer += 4;
        }
        else
        {
            LOGGER->Log( ToHexString( opcode, 2, '0' ) + " [UNKNOWN]\n" );
            break;
        }
    }



    if( opcode != 0xa0 )
    {
        LOGGER->Log( "    0x" + ToHexString( opcode, 2, '0' ) + " PLAY.\n" );

        u8 ret_op = NextSequenceHandle( channel_data, channel_id, channel_config );



        if( channel_data[ channel_id ].pause_multiplier != 0)
        {
            channel_data[ channel_id ].pause = channel_data[ channel_id ].pause_multiplier * 0x101;
        }

        if( ( channel_data[ channel_id ].pause & 0xff ) == 0 )
        {
            channel_data[ channel_id ].pause = akao_pause_table[ opcode % 11 ];
        }

        if( ( ( ret_op - 0x84 ) >= 0xb ) && ( ( channel_data[ channel_id ].unknown_6e & 5 ) == 0 ) )
        {
            channel_data[ channel_id ].pause -= 0x0200;
        }

        channel_data[ channel_id ].saved_pause = channel_data[ channel_id ].pause & 0x00ff;



        if( opcode >= 0x8f )
        {
            channel_data[ channel_id ].unknown_6c = 0;
            channel_data[ channel_id ].unknown_6e &= 0xfffd;
            channel_data[ channel_id ].pitch_addition2 = 0;
            channel_data[ channel_id ].unknown_d8 = 0;
        }
        else if( opcode < 0x84 )
        {
            u32 calculated_pitch;

/*
            if (w[S0 + 38] & 00000008)
            {
                if (hu[S0 + 54] == 0)
                {
                    80031050	lw     v0, $0008(s3)
                    80031058	or     v0, s5, v0
                    80031060	sw     v0, $0008(s3)
                }
                else
                {
                    80031064	lui    v0, $800a
                    80031068	lw     v0, $9fd0(v0)
                    8003106C	nop
                    80031070	or     v0, s5, v0
                    80031074	lui    at, $800a
                    80031078	sw     v0, $9fd0(at)
                }

                V1 = (opcode / 0xb) / 0xc;
                A0 = (opcode / 0xb) % 0xc
                8003108C	lw     a2, $0014(s0)

                800310A8	andi   a0, a0, $00ff
                800310AC	sll    v0, a0, $02
                800310B0	addu   v0, v0, a0
                800310B4	addu   a2, a2, v0
                800310B8	lbu    v1, $0000(a2)
                800310BC	lhu    v0, $0058(s0)
                800310C0	nop
                if (V1 != V0)
                {
                    800310CC	sh     v1, $0058(s0)
                    800310D0	lbu    v0, $0000(a2)
                    800310D4	nop
                    800310D8	sll    v0, v0, $06
                    800310DC	lui    at, $8007
                    800310E0	addiu  at, at, $5f28
                    800310E4	addu   at, at, v0
                    800310E8	lw     v0, $0000(at)
                    800310EC	nop
                    800310F0	sw     v0, $00e4(s0)
                    800310F4	lbu    v0, $0000(a2)
                    800310F8	nop
                    800310FC	sll    v0, v0, $06
                    80031100	lui    at, $8007
                    80031104	addiu  at, at, $5f2c
                    80031108	addu   at, at, v0
                    8003110C	lw     v0, $0000(at)
                    80031110	nop
                    80031114	sw     v0, $00e8(s0)
                    80031118	lbu    v0, $0000(a2)
                    8003111C	nop
                    80031120	sll    v0, v0, $06
                    80031124	lui    at, $8007
                    80031128	addiu  at, at, $5f30
                    8003112C	addu   at, at, v0
                    80031130	lbu    v0, $0000(at)
                    80031134	nop
                    80031138	sh     v0, $00fa(s0)
                    8003113C	lbu    v0, $0000(a2)
                    80031140	nop
                    80031144	sll    v0, v0, $06
                    80031148	lui    at, $8007
                    8003114C	addiu  at, at, $5f31
                    80031150	addu   at, at, v0
                    80031154	lbu    v0, $0000(at)
                    80031158	nop
                    8003115C	sh     v0, $00fc(s0)
                    80031160	lbu    v0, $0000(a2)
                    80031164	nop
                    80031168	sll    v0, v0, $06
                    8003116C	lui    at, $8007
                    80031170	addiu  at, at, $5f32
                    80031174	addu   at, at, v0
                    80031178	lbu    v0, $0000(at)
                    8003117C	nop
                    80031180	sh     v0, $00fe(s0)
                    80031184	lbu    v0, $0000(a2)
                    80031188	nop
                    8003118C	sll    v0, v0, $06
                    80031190	lui    at, $8007
                    80031194	addiu  at, at, $5f33
                    80031198	addu   at, at, v0
                    8003119C	lbu    v0, $0000(at)
                    800311A0	nop
                    800311A4	sh     v0, $0100(s0)
                    800311A8	lbu    v0, $0000(a2)
                    800311AC	nop
                    800311B0	sll    v0, v0, $06
                    800311B4	lui    at, $8007
                    800311B8	addiu  at, at, $5f35
                    800311BC	addu   at, at, v0
                    800311C0	lbu    v0, $0000(at)
                    800311C4	nop
                    800311C8	sw     v0, $00ec(s0)
                    800311CC	lbu    v0, $0000(a2)
                    800311D0	nop
                    800311D4	sll    v0, v0, $06
                    800311D8	lui    at, $8007
                    800311DC	addiu  at, at, $5f36
                    800311E0	addu   at, at, v0
                    800311E4	lbu    v1, $0000(at)
                    800311E8	lw     v0, $0038(s0)
                    800311EC	nop
                    800311F0	andi   v0, v0, $0200
                    800311F8	sw     v1, $00f0(s0)
                    if (V0 == 0)
                    {
                        800311FC	lbu    v0, $0000(a2)
                        80031200	lui    a0, $0001
                        80031204	sll    v0, v0, $06
                        80031208	lui    at, $8007
                        8003120C	addiu  at, at, $5f34
                        80031210	addu   at, at, v0
                        80031214	lbu    v0, $0000(at)
                        80031218	ori    a0, a0, $ff80
                        8003121C	sh     v0, $0102(s0)
                        80031220	lbu    v1, $0000(a2)
                        80031224	lw     v0, $00e0(s0)
                        80031228	sll    v1, v1, $06
                        8003122C	lui    at, $8007
                        80031230	addiu  at, at, $5f37
                        80031234	addu   at, at, v1
                        80031238	lbu    v1, $0000(at)
                        8003123C	or     v0, v0, a0
                        80031240	sw     v0, $00e0(s0)
                        80031248	sw     v1, $00f4(s0)
                    }
                    else
                    {
                        8003124C	lui    v1, $0001
                        80031250	lw     v0, $00e0(s0)
                        80031254	ori    v1, v1, $bb80
                        80031258	or     v0, v0, v1
                        8003125C	sw     v0, $00e0(s0)
                    }
                }

                V1 = bu[A2 + 1];

                A1 = (opcode / 0xb) / c;
                V1 = (opcode / 0xb) % c;

                A1 = A1 & ff;
                A0 = w[80075f38 + bu[A2 + 0] * 40 + V1 * 4];

                if (A1 >= 7)
                {
                    V0 = A1 - 6;
                    A0 = V0 << A0;
                }
                else if (A1 < 6)
                {
                    V0 = 6 - A1;
                    A0 = A0 >> V0;
                }

                [S0 + 44] = w((bu[A2 + 2] + (bu[A2 + 3] << 8)) << 10);
                [S0 + 60] = h(bu[A2 + 4] << 8);
            }
            else
*/
            {
                u8 pitch_index = opcode / 11 + channel_data[ channel_id ].pitch_correction * 12;
/*
                if ((hu[S0 + 6c] != 0) && (hu[S0 + 6a] != 0))
                {
                    [S0 + 68] = h(hu[S0 + 6c]);
                    [S0 + d2] = h(pitch_index + channel_data[ channel_id ].pitch_selector - hu[S0 + 6a] - hu[S0 + d4]);
                    channel_data[ channel_id ].saved_pitch = h(hu[S0 + 6a] - channel_data[ channel_id ].pitch_selector - hu[S0 + d4]);
                    pitch_index = bu[S0 + 6a] + bu[S0 + d4];
                }
                else
*/
                {
                    channel_data[ channel_id ].saved_pitch = pitch_index;
                    pitch_index += channel_data[ channel_id ].pitch_selector & 0xff;
                }

/*
                if ((hu[S0 + 6e] & 0002) == 0)
                {
                    if (hu[S0 + 54] == 0)
                    {
*/
                        channel_config.for_play_channel_mask |= ( 1 << channel_id );
/*
                        if (w[S0 + 38] & 00000100)
                        {
                            V1 = hu[S0 + 24];
                            if (w[S0 + 24] >= 18)
                            {
                                V1 = V1 - 18;
                            }

                            [S3 + 8] = w(w[[S3 + 8]] | (1 << V1));
                        }
                    }
                    else
                    {
                        [80099fd0] = w(w[80099fd0] | S5);
                    }
                    [S0 + 64] = h(0);
                }
*/
                u8 mod = pitch_index / 12;
                calculated_pitch = m_InstrumentData[ channel_data[ channel_id ].instrument_id ].pitch[ pitch_index %= 12 ];
                if (mod >= 7)
                {
                    calculated_pitch <<= ( mod - 6 );
                }
                else if (mod < 6)
                {
                    calculated_pitch >>= ( 6 - mod );
                }
            }
/*
            if (hu[S0 + 54] == 0)
            {
                [S3 + c] = w(w[S3 + c] | S5);
            }
            else
            {
                [80099fd4] = w(w[80099fd4] | S5);
            }
*/
            channel_data[ channel_id ].spu_update_flags |= SPU_LEFT_VOLUME | SPU_RIGHT_VOLUME | SPU_PITCH;

            if ( channel_data[ channel_id ].pitch_modifier != 0 )
            {
                if ( channel_data[ channel_id ].pitch_modifier > 0 )
                {
                    calculated_pitch += ( calculated_pitch * channel_data[ channel_id ].pitch_modifier ) >> 7;
                }
                else
                {
                    calculated_pitch += ( calculated_pitch * channel_data[ channel_id ].pitch_modifier ) >> 8;
                }

                calculated_pitch &= 0xffff;
            }

            channel_data[ channel_id ].pitch_base = calculated_pitch;
/*
            if (w[S0 + 38] & 00000001)
            {
                8003152C	lhu    v0, $007e(s0)
                80031534	andi   v1, v0, $7f00
                80031538	andi   v0, v0, $8000
                80031540	srl    v1, v1, $08
                if (V0 != 0)
                {
                    80031548	mult   v1, a0
                }
                else
                {
                    8003154C	sll    v0, a0, $04
                    80031550	subu   v0, v0, a0
                    80031554	srl    v0, v0, $08
                    80031558	mult   v1, v0
                }

                8003155C	mflo   v0
                80031560	srl    v1, v0, $07
                80031568	sh     v1, $007c(s0)

                [S0 + 18] = w(w[8004a5cc + hu[S0 + 7a] * 4]);
                [S0 + 74] = h(hu[S0 + 72]);
                [S0 + 78] = h(1);
            }

            if (w[S0 + 38] & 00000002)
            {
                [S0 + 1c] = w(w[8004a5cc + hu[S0 + 8e] * 4]);
                [S0 + 88] = h(hu[S0 + 86]);
                [S0 + 8c] = h(1);
            }

            if (w[S0 + 38] & 00000004)
            {
                800315E8	lhu    v0, $009c(s0)
                800315EC	nop
                800315F0	sll    v0, v0, $02
                800315F4	lui    at, $8005
                800315F8	addiu  at, at, $a5cc (=-$5a34)
                800315FC	addu   at, at, v0
                80031600	lw     v1, $0000(at)
                80031604	ori    v0, zero, $0001
                80031608	sh     v0, $009a(s0)
                8003160C	sw     v1, $0020(s0)
            }
*/
            //[S0 + d6] = h(0);
            //[S0 + d8] = h(0);
            //[S0 + 34] = w(0);
        }



        u16 unknown_d2 = channel_data[ channel_id ].unknown_d2;

        channel_data[ channel_id ].unknown_6e = ( channel_data[ channel_id ].unknown_6e & 0xfffd ) | ( ( channel_data[ channel_id ].unknown_6e & 0x0001 ) << 1 );

        if( unknown_d2 != 0 )
        {
            channel_data[ channel_id ].saved_pitch += unknown_d2;

            u8 selected_pitch = channel_data[ channel_id ].saved_pitch + channel_data[ channel_id ].pitch_selector;
            u32 pitch_value = 0;

            if( channel_data[ channel_id ].unknown_54 == 0 )
            {
                pitch_value = m_InstrumentData[ channel_data[ channel_id ].instrument_id ].pitch[ selected_pitch % 12 ];

                s16 pitch_modifier = channel_data[ channel_id ].pitch_modifier;
                if( pitch_modifier != 0 )
                {
                    if( pitch_modifier > 0 )
                    {
                        pitch_modifier = ( pitch_value * pitch_modifier ) >> 7;
                    }
                    else
                    {
                        pitch_modifier = ( pitch_value * pitch_modifier ) >> 8;
                    }
                    pitch_value += pitch_modifier;
                }
            }
            else
            {
                pitch_value = m_InstrumentData[ channel_data[ channel_id ].instrument_id ].pitch[ selected_pitch %= 12 ];
            }

            pitch_value <<= 0x10;

            selected_pitch /= 12;

            if( selected_pitch >= 7 )
            {
                pitch_value <<= selected_pitch - 6;
            }
            else if (selected_pitch < 6)
            {
                pitch_value >>= 6 - selected_pitch;
            }

            channel_data[ channel_id ].unknown_64 = channel_data[ channel_id ].unknown_68;
            channel_data[ channel_id ].unknown_d2 = 0;
            channel_data[ channel_id ].pitch_growth = (pitch_value + channel_data[ channel_id ].pitch_addition - ( channel_data[ channel_id ].pitch_base << 0x10 ) ) / channel_data[ channel_id ].unknown_64;
        }

        channel_data[ channel_id ].unknown_d4 = channel_data[ channel_id ].pitch_selector;
        channel_data[ channel_id ].unknown_6a = channel_data[ channel_id ].saved_pitch;
    }
    else // 0xa0
    {
        LOGGER->Log( "    0xA0 FINISH.\n" );
    }
}



const u8
AkaoParser::NextSequenceHandle( ChannelData* channel_data, int channel_id, ChannelConfig& channel_config )
{
    u32 pointer = channel_data[ channel_id ].akao_sequence_pointer;
    u16 loop_index = channel_data[ channel_id ].loop_index;

    while( true )
    {
        u8 opcode = m_Music->GetU8( pointer );

        if( opcode < 0x9a )
        {
            if( opcode >= 0x8f )
            {
                channel_data[ channel_id ].unknown_6c = 0;
                channel_data[ channel_id ].unknown_6e &= 0xfffa;
            }

            return opcode;
        }

        if( opcode < 0xa0 )
        {
            return 0xa0;
        }


        u8 size = opcode_size[ opcode - 0xa0 ];
        if( size == 0 )
        {
            switch( opcode )
            {
                case 0xc9:
                {
                    if( m_Music->GetU8( pointer + 1 ) == channel_data[ channel_id ].loop_count[ loop_index ] )
                    {
                        pointer += 2;
                        loop_index = (loop_index - 1) & 3;
                    }
                    else
                    {
                        pointer = channel_data[ channel_id ].loop_pointer[ loop_index ];
                    }
                    continue;
                }
                break;

                case 0xca:
                {
                    pointer = channel_data[ channel_id ].loop_pointer[ loop_index ];
                    continue;
                }
                break;

                case 0xcb:
                case 0xcd:
                case 0xd1:
                case 0xdb:
                {
                    pointer += 1;
                    channel_data[ channel_id ].unknown_6c = 0;
                    channel_data[ channel_id ].unknown_6e &= 0xfffa;
                    continue;
                }
                break;

                case 0xee:
                {
                    pointer += 3 + ( s16 )( m_Music->GetU16LE( pointer + 1 ) );
                    continue;
                }
                break;

                case 0xef:
                {
                    if( channel_config.conditional_value >= m_Music->GetU8( pointer + 1 ) )
                    {
                        pointer += 4 + ( s16 )( m_Music->GetU16LE( pointer + 2 ) );
                    }
                    else
                    {
                        pointer += 4;
                    }
                    continue;
                }
                break;

                case 0xf0:
                case 0xf1:
                {
                    if( m_Music->GetU8( pointer + 1 ) == channel_data[ channel_id ].loop_count[ loop_index ] + 1 )
                    {
                        loop_index = (loop_index - 1) & 3;
                        pointer += 4 + ( s16 )( m_Music->GetU16LE( pointer + 2 ) );
                    }
                    else
                    {
                        pointer += 4;
                    }
                    continue;
                }
                break;

                default:
                {
                    channel_data[ channel_id ].unknown_6c = 0;
                    channel_data[ channel_id ].unknown_6e &= 0xfffa;
                    return 0xa0;
                }
            }
        }

        pointer += size;
    }
}



void
AkaoParser::InitChannelInstrument( ChannelData* channel_data, int channel_id, int instrument_id )
{
    //LOGGER->Log( "Load voice " + Ogre::StringConverter::toString( instrument_id ) + " to channel " + Ogre::StringConverter::toString( channel_id ) + ".\n" );
    InstrumentData data = m_InstrumentData[ instrument_id ];

    channel_data[ channel_id ].instrument_id = instrument_id;
    channel_data[ channel_id ].start_offset = data.start_offset;
    channel_data[ channel_id ].loop_offset = data.loop_offset;
    //LOGGER->Log( "SPU_ADDRESS_START " + Ogre::StringConverter::toString( data.start_offset ) + "\n" );
    //LOGGER->Log( "SPU_ADDRESS_LOOP " + Ogre::StringConverter::toString( data.loop_offset ) + "\n" );
    channel_data[ channel_id ].attack_mode = data.attack_mode;
    channel_data[ channel_id ].sustain_mode = data.sustain_mode;
    channel_data[ channel_id ].release_mode = data.release_mode;
    channel_data[ channel_id ].attack_rate = data.attack_rate;
    channel_data[ channel_id ].decay_rate = data.decay_rate;
    channel_data[ channel_id ].sustain_level = data.sustain_level;
    channel_data[ channel_id ].sustain_rate = data.sustain_rate;
    channel_data[ channel_id ].release_rate = data.release_rate;
    channel_data[ channel_id ].spu_update_flags |=
        SPU_START_OFFSET | SPU_ATTACK_RATE | SPU_SUSTAIN_RATE | SPU_RELEASE_RATE |
        SPU_ATTACK_MODE | SPU_DECAY_RATE | SPU_SUSTAIN_MODE | SPU_RELEASE_MODE |
        SPU_SUSTAIN_LEVEL | SPU_LOOP_OFFSET; // update everything we just set
}



void
AkaoParser::DumpSequenceData( const Ogre::String& file )
{
    std::ofstream oF;
    oF.open( file.c_str(), std::ios_base::binary | std::ios_base::out );
    if ( !oF.is_open() )
    {
        return;
    }

    oF << std::setfill( '0' );
    oF << std::hex;
    oF << "*** Frame ID: 0x" << std::setw( 4 ) << m_Music->GetU16LE( 4 ) << std::endl;
    oF << std::dec;
    oF << "*** Frame Length: " << m_Music->GetU16LE( 6 ) << " bytes" << std::endl;
    oF << std::hex;
    oF << "*** Reverb Mode: 0x" << std::setw( 4 ) << m_Music->GetU16LE( 8 ) << std::endl;
    oF << std::endl;

    oF << std::hex;
    oF << "*** Channels mask: " <<std:: setw( 8 ) << m_Music->GetU32LE( 16 ) << std::endl << std::endl;

    for ( int i = 0; i < 24; ++i )
    {
        if ( ( ( m_Music->GetU32LE( 16 ) ) & ( 1 << i ) ) == 0 )
        {
            continue;
        }

        oF << std::dec;
        oF << "*** Channel " << std::setw( 2 ) << ( int )i << " sequence: " << std::endl;

        oF << std::hex;
        u16 j = 0;
        bool work = true;
        while ( work )
        {
            u8 opcode = m_Music->GetU8( m_MusicChannelData[ i ].akao_sequence_pointer + j );
            switch ( opcode )
            {
                case 0xa0:
                    oF << std::setw( 2 ) << ( int )m_Music->GetU8( m_MusicChannelData[ i ].akao_sequence_pointer + j + 0 );
                    oF << std::endl;
                    work = false;
                    break;
                // no parameters
                case 0xa6: case 0xa7: case 0xb3: case 0xb6: case 0xba: case 0xbe: case 0xc2: case 0xc3:
                case 0xc4: case 0xc5: case 0xc6: case 0xc7: case 0xc8: case 0xca: case 0xcb: case 0xcc:
                case 0xcd: case 0xd0: case 0xd1: case 0xd4: case 0xd5: case 0xd6: case 0xd7: case 0xdb:
                case 0xe0: case 0xe1: case 0xe2: case 0xe3: case 0xe4: case 0xe5: case 0xe6: case 0xe7:
                case 0xed: case 0xf3: case 0xf5: case 0xf9: case 0xfa: case 0xfb: case 0xfc: case 0xff:
                    oF << std::setw( 2 ) << ( int )m_Music->GetU8( m_MusicChannelData[ i ].akao_sequence_pointer + j + 0 );
                    oF << std::endl;
                    ++j;
                    break;
                // one parameter
                case 0xa1: case 0xa2: case 0xa3: case 0xa5: case 0xa8: case 0xaa: case 0xac: case 0xad:
                case 0xae: case 0xaf: case 0xb1: case 0xb2: case 0xb5: case 0xb7: case 0xb9: case 0xbb:
                case 0xbd: case 0xbf: case 0xc0: case 0xc1: case 0xc9: case 0xce: case 0xcf: case 0xd2:
                case 0xd3: case 0xd8: case 0xd9: case 0xda: case 0xdc: case 0xf2: case 0xf6: case 0xf8:
                    oF << std::setw( 2 ) << ( int )m_Music->GetU8( m_MusicChannelData[ i ].akao_sequence_pointer + j + 0 ) << ' ';
                    oF << std::setw( 2 ) << ( int )m_Music->GetU8( m_MusicChannelData[ i ].akao_sequence_pointer + j + 1 );
                    oF << std::endl;
                    j += 2;
                    break;
                // two parameters
                case 0xa4: case 0xa9: case 0xab: case 0xb0: case 0xbc: case 0xdd: case 0xde: case 0xdf:
                case 0xe8: case 0xea: case 0xec: case 0xee: case 0xf4: case 0xf7: case 0xfd: case 0xfe:
                    oF << std::setw( 2 ) << ( int )m_Music->GetU8( m_MusicChannelData[ i ].akao_sequence_pointer + j + 0 ) << ' ';
                    oF << std::setw( 2 ) << ( int )m_Music->GetU8( m_MusicChannelData[ i ].akao_sequence_pointer + j + 1 ) << ' ';
                    oF << std::setw( 2 ) << ( int )m_Music->GetU8( m_MusicChannelData[ i ].akao_sequence_pointer + j + 2 );
                    oF << std::endl;
                    j += 3;
                    break;
                // three parameters
                case 0xb4: case 0xb8: case 0xe9: case 0xeb: case 0xef: case 0xf0: case 0xf1:
                    oF << std::setw( 2 ) << ( int )m_Music->GetU8( m_MusicChannelData[ i ].akao_sequence_pointer + j + 0 ) << ' ';
                    oF << std::setw( 2 ) << ( int )m_Music->GetU8( m_MusicChannelData[ i ].akao_sequence_pointer + j + 1 ) << ' ';
                    oF << std::setw( 2 ) << ( int )m_Music->GetU8( m_MusicChannelData[ i ].akao_sequence_pointer + j + 2 ) << ' ';
                    oF << std::setw( 2 ) << ( int )m_Music->GetU8( m_MusicChannelData[ i ].akao_sequence_pointer + j + 3 );
                    oF << std::endl;
                    j += 4;
                    break;
                default:
                    oF << std::setw( 2 ) << ( int )m_Music->GetU8( m_MusicChannelData[ i ].akao_sequence_pointer + j + 0 );
                    if ( m_Music->GetU8( m_MusicChannelData[ i ].akao_sequence_pointer + j + 1 ) < 0xa0)
                    {
                        oF << ' ';
                    }
                    else
                    {
                        oF << std::endl;
                    }
                    ++j;
            }
        }

        oF << std::endl;
    }

    oF.close();
}
