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

                    m_MusicChannelData[ channel_id ].pause -= 0x101;
                    //LOGGER->Log( "pause " + ToHexString( m_MusicChannelData[ channel_id ].pause, 4, '0' ) + "\n" );

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
        int frame_id = m_Music->GetU16LE( 4 );
        int frame_length = m_Music->GetU16LE( 6 );
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
        m_MusicChannelConfig.active_channel_mask = m_Music->GetU32LE( 16 );
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
                //[S3 + 34] = w(0);
                //[S3 + 38] = w(0);
                m_MusicChannelData[ channel_id ].volume_level = 0x3fff0000;
                m_MusicChannelData[ channel_id ].pause = 0x103;
                //[S3 + 5c] = h(0);
                //[S3 + 5e] = h(0);
                m_MusicChannelData[ channel_id ].volume_index = 0x4000;
                //[S3 + 62] = h(0);
                //[S3 + 64] = h(0);
                //[S3 + 6c] = h(0);
                //[S3 + 6e] = h(0);
                //[S3 + 7e] = h(0);
                //[S3 + 80] = h(0);
                //[S3 + 90] = h(0);
                //[S3 + 92] = h(0);
                //[S3 + 9e] = h(0);
                //[S3 + a0] = h(0);
                //[S3 + a4] = h(0);
                //[S3 + a6] = h(0);
                //[S3 + b8] = h(0);
                m_MusicChannelData[ channel_id ].saved_pause = 0;
                m_MusicChannelData[ channel_id ].pause_multiplier = 0;
                //[S3 + c6] = h(4000);
                m_MusicChannelData[ channel_id ].pitch_selector = 0;
                m_MusicChannelData[ channel_id ].pitch_modifier = 0;
                //[S3 + d2] = h(0);
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
        [8009a13c] = w(0);
        [8009a144] = w(0);
        [8009a148] = w(0);
*/
       m_MusicChannelConfig.tempo_increment_counter = 0;
/*
        [8009a150] = h(0);
        [8009a152] = h(0);
        [8009a154] = h(0);
        [8009a158] = h(0);
        [8009a15c] = h(0);
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
        new_pitch = channel_data[ channel_id ].pitch_base + channel_data[ channel_id ].pitch_addition + channel_data[ channel_id ].pitch_addition2;
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
            }
            else
            {
                SOUNDMAN->PsxChannelStop( channel_id );
            }
        }
    }
}



void
AkaoParser::UpdateSequence( ChannelData* channel_data, int channel_id, ChannelConfig& channel_config )
{
    LOGGER->Log( "UpdateSequence for channel " + ToIntString( channel_id ) + "\n" );

    u8 opcode;

    for ( ;; )
    {
        opcode = m_Music->GetU8( channel_data[ channel_id ].akao_sequence_pointer );

        if ( opcode < 0xa0 )
        {
            LOGGER->Log( "    " + ToHexString( opcode, 2, '0' ) + " [UNIMPLEMENTED] " );
            channel_data[ channel_id ].akao_sequence_pointer += 1;
            break;
        }
        else if ( opcode == 0xa1 ) // load instrument
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
        else if ( opcode == 0xa3 ) // set volume multiplier
        {
            LOGGER->Log( "    0xA3 " );
            channel_data[ channel_id ].volume_multiplier = m_Music->GetU8( channel_data[ channel_id ].akao_sequence_pointer + 1 );
            channel_data[ channel_id ].spu_update_flags |= SPU_LEFT_VOLUME | SPU_RIGHT_VOLUME;
            LOGGER->Log( "set volume multiplier to \"" + ToHexString( channel_data[ channel_id ].volume_multiplier, 2, '0' ) + "\"\n" );
            channel_data[ channel_id ].akao_sequence_pointer += 2;
        }
        else if ( opcode == 0xa5 ) // set pitch correction
        {
            LOGGER->Log( "    0xA5 " );
            channel_data[ channel_id ].pitch_correction = m_Music->GetU8( channel_data[ channel_id ].akao_sequence_pointer + 1 );
            LOGGER->Log( "set pitch correction to \"" + ToHexString( channel_data[ channel_id ].pitch_correction, 4, '0' ) + "\"\n" );
            channel_data[ channel_id ].akao_sequence_pointer += 2;
        }
        else if ( opcode == 0xa6 )
        {
            LOGGER->Log( "    0xA6 [UNIMPLEMENTED]\n" );
            channel_data[ channel_id ].akao_sequence_pointer += 1;
        }
        else if ( opcode == 0xa7 ) // ???
        {
            LOGGER->Log( "    0xA7 [UNIMPLEMENTED]\n" );
            channel_data[ channel_id ].akao_sequence_pointer += 1;
        }
        else if ( opcode == 0xa8 ) // set channel volume
        {
            LOGGER->Log( "    0xA8 [UNIMPLEMENTED] " );
            LOGGER->Log( "set channel volume to \"" + ToHexString( m_Music->GetU8( channel_data[ channel_id ].akao_sequence_pointer + 1 ) << 0x17, 8, '0' ) + "\"\n" );
            channel_data[ channel_id ].akao_sequence_pointer += 2;
        }
        else if ( opcode == 0xa9 ) // set channel volume increase/descrease
        {
            LOGGER->Log( "    0xA9 [UNIMPLEMENTED] " );
            LOGGER->Log( "set volume tick to \"" + ToHexString( m_Music->GetU8( channel_data[ channel_id ].akao_sequence_pointer + 1 ), 2, '0' ) + "\" and " );
            LOGGER->Log( "set change volume to \"" + ToHexString( m_Music->GetU8( channel_data[ channel_id ].akao_sequence_pointer + 2 ) << 0x17, 8, '0' ) + "\"\n" );
            channel_data[ channel_id ].akao_sequence_pointer += 3;
        }
        else if ( opcode == 0xaa ) // set volume pan
        {
            LOGGER->Log( "    0xAA [UNIMPLEMENTED] " );
            LOGGER->Log( "set volume pan to \"" + ToHexString( m_Music->GetU8( channel_data[ channel_id ].akao_sequence_pointer + 1 ) << 0x8, 4, '0' ) + "\"\n" );
            channel_data[ channel_id ].akao_sequence_pointer += 2;
        }
        else if ( opcode == 0xad ) // ???
        {
            LOGGER->Log( "    0xAD [UNIMPLEMENTED]\n" );
            channel_data[ channel_id ].akao_sequence_pointer += 2;
        }
        else if ( opcode == 0xb1 ) // ???
        {
            LOGGER->Log( "    0xB1 [UNIMPLEMENTED]\n" );
            channel_data[ channel_id ].akao_sequence_pointer += 2;
        }
        else if ( opcode == 0xb4 ) // set wave
        {
            LOGGER->Log( "    0xB4 [UNIMPLEMENTED] " );
            LOGGER->Log( "set wave data\n" );
            channel_data[ channel_id ].akao_sequence_pointer += 4;
        }
        else if ( opcode == 0xb5 ) // ???
        {
            LOGGER->Log( "    0xB5 [UNIMPLEMENTED]\n" );
            channel_data[ channel_id ].akao_sequence_pointer += 2;
        }
        else if ( opcode == 0xc2 ) // turn reverb on
        {
            LOGGER->Log( "    0xC2 [UNIMPLEMENTED] turn reverb on\n" );
            channel_data[ channel_id ].akao_sequence_pointer += 1;
        }
        else if ( opcode == 0xcc )
        {
            LOGGER->Log( "    0xCC [UNIMPLEMENTED]\n" );
            channel_data[ channel_id ].akao_sequence_pointer += 1;
        }
        else if ( opcode == 0xcd )
        {
            LOGGER->Log( "    0xCD [UNIMPLEMENTED]\n" );
            channel_data[ channel_id ].akao_sequence_pointer += 1;
        }
        else if ( opcode == 0xd9 )
        {
            LOGGER->Log( "    0xD9 [UNIMPLEMENTED]\n" );
            channel_data[ channel_id ].akao_sequence_pointer += 2;
        }
        else if ( opcode == 0xe0 ) // ???
        {
            LOGGER->Log( "    0xE0 [UNIMPLEMENTED]\n" );
            channel_data[ channel_id ].akao_sequence_pointer += 1;
        }
        else if ( opcode == 0xe2 ) // ???
        {
            LOGGER->Log( "    0xE2 [UNIMPLEMENTED]\n" );
            channel_data[ channel_id ].akao_sequence_pointer += 1;
        }
        else if ( opcode == 0xe8 ) // set tempo
        {
            LOGGER->Log( "    0xE8 " );
            channel_config.tempo = m_Music->GetU16LE( channel_data[ channel_id ].akao_sequence_pointer + 1 ) << 0x10;
            channel_config.tempo_increment_counter = 0;
            LOGGER->Log( "set tempo to \"" + ToHexString( channel_config.tempo, 4, '0' ) + "\"\n" );
            channel_data[ channel_id ].akao_sequence_pointer += 3;
        }
        else if ( opcode == 0xea ) // set reverb depth
        {
            LOGGER->Log( "    0xEA [UNIMPLEMENTED] " );
            LOGGER->Log( "set reverb depth to \"" + ToHexString( m_Music->GetU16LE( channel_data[ channel_id ].akao_sequence_pointer + 1 ) << 0x10, 8, '0' ) + "\"\n" );

            channel_data[ channel_id ].akao_sequence_pointer += 3;
        }
        else if ( opcode == 0xec )
        {
            LOGGER->Log( "    0xEC [UNIMPLEMENTED]\n" );
            channel_data[ channel_id ].akao_sequence_pointer += 3;
        }
        else if ( opcode == 0xee ) // ???
        {
            LOGGER->Log( "    0xEE [UNIMPLEMENTED]\n" );
            channel_data[ channel_id ].akao_sequence_pointer += 3;
        }
        else if ( opcode == 0xf0 )
        {
            LOGGER->Log( "    0xF0 [UNIMPLEMENTED]\n" );
            channel_data[ channel_id ].akao_sequence_pointer += 4;
        }
        else if ( opcode == 0xf1 )
        {
            LOGGER->Log( "    0xF1 [UNIMPLEMENTED]\n" );
            channel_data[ channel_id ].akao_sequence_pointer += 4;
        }
        else if ( opcode == 0xfd ) // reset timers lower and upper
        {
            LOGGER->Log( "    0xFD [UNIMPLEMENTED] " );
            LOGGER->Log( "reset timers that can be readed in field with 0xF7 CHMPH. " );
            LOGGER->Log( "Values Upper(" + ToHexString( m_Music->GetU8( channel_data[ channel_id ].akao_sequence_pointer + 2 ), 2, '0' ) + ") " );
            LOGGER->Log( "Lower(" + ToHexString( m_Music->GetU8( channel_data[ channel_id ].akao_sequence_pointer + 1 ), 2, '0' ) + ")\n" );
            channel_data[ channel_id ].akao_sequence_pointer += 3;
        }
        else if ( opcode == 0xfe ) // reset timers main
        {
            LOGGER->Log( "    0xFE [UNIMPLEMENTED] " );
            LOGGER->Log( "reset main timer than increment when all lower and upper timers counted. Can be readed in field with 0xF7 CHMPH. " );
            LOGGER->Log( "Value(" + ToHexString( m_Music->GetU16LE( channel_data[ channel_id ].akao_sequence_pointer + 1 ), 4, '0' ) + ")\n" );
            channel_data[ channel_id ].akao_sequence_pointer += 3;
        }
        else if ( opcode == 0xff )
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



    if ( opcode != 0xa0 )
    {
        //A0 = S0;
        //func318bc; // special handling in case of next opcode
        //A0 = V0;

        if ( channel_data[ channel_id ].pause_multiplier != 0)
        {
            channel_data[ channel_id ].pause = channel_data[ channel_id ].pause_multiplier * 0x101;
        }

        if ( ( channel_data[ channel_id ].pause & 0xff ) == 0 )
        {
            channel_data[ channel_id ].pause = akao_pause_table[ opcode % 11 ];
        }

        //if (((A0 - 84) >= b) && (hu[S0 + 6e] & 5) == 0))
        //{
            //channel_data[ channel_id ].pause -= 0x0200;
        //}

        channel_data[ channel_id ].saved_pause = channel_data[ channel_id ].pause & 0x00ff;

        if ( opcode >= 0x8f )
        {
            //[S0 + 6c] = h(0);
            //[S0 + d6] = h(0);
            //[S0 + d8] = h(0);
            //[S0 + 6e] = h(hu[S0 + 6e] & fffd);
        }
        else if ( opcode < 0x84 )
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
                        channel_config.for_play_channel_mask |= 1 << channel_id;
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

        //[S0 + 6e] = h((hu[S0 + 6e] & fffd) | ((hu[S0 + 6e] & 0001) << 1));

/*
        if (h[S0 + d2] != 0)
        {
            channel_data[ channel_id ].saved_pitch += h[S0 + d2];

            S2 = channel_data[ channel_id ].saved_pitch + channel_data[ channel_id ].pitch_selector & 0xff;

            if (hu[S0 + 54] == 0)
            {
                A0 = m_InstrumentData[ channel_data[ channel_id ].instrument_id ].pitch[ S2 % 12 ];

                V0 = channel_data[ channel_id ].pitch_modifier;
                if (V0 != 0)
                {
                    if (V0 > 0)
                    {
                        V0 = (A0 * V0) >> 7;
                    }
                    else
                    {
                        V0 = (A0 * V0) >> 8;
                    }
                    A0 = (A0 + V0) & ffff;
                }

                A0 = A0 << 10;
            }
            else
            {
                A0 = m_InstrumentData[ channel_data[ channel_id ].instrument_id ].pitch[ S2 % 12 ] << 0x10;
            }

            S2 = (S2 & ff) / c;
            V1 = S2 & ff;

            if (V1 >= 7)
            {
                A0 = A0 << (V1 - 6);
            }
            else if (V1 < 6)
            {
                A0 = A0 >> (6 - V1);
            }

            [S0 + 64] = h(hu[S0 + 68]);
            [S0 + d2] = h(0);
            [S0 + 4c] = w((A0 + w[S0 + 34] - (w[S0 + 30] << 10)) / hu[S0 + 64]);
        }
*/

        //[S0 + d4] = h(channel_data[ channel_id ].pitch_selector);
        //[S0 + 6a] = h(channel_data[ channel_id ].saved_pitch);
    }



    LOGGER->Log( "UpdateSequence end\n" );
}



void
AkaoParser::InitChannelInstrument( ChannelData* channel_data, int channel_id, int instrument_id )
{
    InstrumentData data = m_InstrumentData[ instrument_id ];

    channel_data[ channel_id ].instrument_id = instrument_id;
    channel_data[ channel_id ].start_offset = data.start_offset;
    channel_data[ channel_id ].loop_offset = data.loop_offset;
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
