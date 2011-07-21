#ifndef AKAO_PARSER_H
#define AKAO_PARSER_H

#include <Ogre.h>

#include <vector>
#include "../../common/File.h"
#include "../../common/TypeDefine.h"



class AkaoParser
{
public:
    AkaoParser();
    virtual ~AkaoParser();

    void Update();

    // instrument
    void LoadInstruments( const Ogre::String& all_file, const Ogre::String& dat_file );
    void UnloadInstruments();

    // akao command 0x10
    void PlayMusic( const Ogre::String& file );

    // debug routines
    void DumpSequenceData( const Ogre::String& file );



private:
    enum SpuParameter
    {
        SPU_LEFT_VOLUME   = 1 <<  0, // 0x00000001
        SPU_RIGHT_VOLUME  = 1 <<  1, // 0x00000002
        SPU_PITCH         = 1 <<  4, // 0x00000010
        SPU_START_OFFSET  = 1 <<  7, // 0x00000080
        SPU_ATTACK_RATE   = 1 <<  8, // 0x00000100
        SPU_SUSTAIN_RATE  = 1 <<  9, // 0x00000200
        SPU_RELEASE_RATE  = 1 << 10, // 0x00000400
        SPU_ATTACK_MODE   = 1 << 11, // 0x00000800
        SPU_DECAY_RATE    = 1 << 12, // 0x00001000
        SPU_SUSTAIN_MODE  = 1 << 13, // 0x00002000
        SPU_RELEASE_MODE  = 1 << 14, // 0x00004000
        SPU_SUSTAIN_LEVEL = 1 << 15, // 0x00008000
        SPU_LOOP_OFFSET   = 1 << 16, // 0x00010000
    };

    enum SpuConfigUpdate
    {
        SPU_REVERB        = 1 <<  7, // 0x00000080
    };



    // instrument
    struct InstrumentData
    {
        u32 start_offset;
        u32 loop_offset;
        u8 attack_rate;
        u8 decay_rate;
        u8 sustain_level;
        u8 sustain_rate;
        u8 release_rate;
        u8 attack_mode;
        u8 sustain_mode;
        u8 release_mode;
        u32 pitch[ 12 ];
    };
    std::vector< InstrumentData > m_InstrumentData;



    struct ChannelData
    {
        // 0x00 [][][][]
        u32 akao_sequence_pointer;
        // 0x04-0x10 [][][][]
        u32 loop_pointer[ 4 ];

        // 0x18 [][][][] in real here was addreses into wave table, but we store indexes here
        u32 wave1_table_index;
        // 0x1c [][][][]
        u32 wave2_table_index;
        // 0x20 [][][][]
        u32 wave3_table_index;
        // 0x24 [][]
        u16 mirror_channel_id;
        // 0x2c [][][][]
        s32 volume_multiplier;

        // 0x30 [][][][]
        u32 pitch_base;
        // 0x34 [][][][]
        s32 pitch_addition;
        // 0x38 [][][][]
        u32 mirror_update_flags;

        // 0x44 [][][][]
        s32 volume_level;
        // 0x48 [][][][]
        s32 volume_level_new;
        // 0x4c [][][][]
        s32 pitch_growth;

        // 0x54 [][]
        u16 unknown_54;
        // 0x56 [][]
        u16 pause;
        // 0x58 [][]
        int instrument_id;

        // 0x5c [][]
        u16 volume_level_change_ticks;

        // 0x60 [][]
        u16 volume_index;
        // 0x62 [][]
        u16 unknown_62;
        // 0x64 [][]
        u16 unknown_64;
        // 0x66 [][]
        u16 pitch_correction;
        // 0x68 [][]
        u16 unknown_68;
        // 0x6a [][]
        u16 unknown_6a;
        // 0x6c [][]
        u16 unknown_6c;
        // 0x6e [][]
        u16 unknown_6e;

        // 0x72 [][]
        u16 wave1_delay;
        // 0x74 [][]
        u16 wave1_delay_current;
        // 0x76 [][]
        u16 wave1_refresh_interval;
        // 0x78 [][]
        u16 wave1_refresh_interval_counter;
        // 0x7a [][]
        u16 wave1_table_node_index;
        // 0x7c [][]
        u16 wave1_multiplier;
        // 0x7e [][]
        u16 wave1_modifier;

        // 0x86 [][]
        u16 wave2_delay;
        // 0x88 [][]
        u16 wave2_delay_current;

        // 0x8c [][]
        u16 wave2_refresh_interval_counter;
        // 0x8e [][]
        u16 wave2_table_node_index;

        // 0x9a [][]
        u16 wave3_refresh_interval_counter;
        // 0x9c [][]
        u16 wave3_table_node_index;

        // 0xb8 [][]
        u16 loop_index;
        // 0xba-0xc0 [][]
        u16 loop_count[ 4 ];

        // 0xc2 [][]
        u16 saved_pause;
        // 0xc4 [][]
        u16 pause_multiplier;

        // 0xcc [][]
        u16 pitch_selector;
        // 0xce [][]
        s16 pitch_modifier;
        // 0xd0 [][]
        u16 saved_pitch;
        // 0xd2 [][]
        u16 unknown_d2;
        // 0xd4 [][]
        u16 unknown_d4;
        // 0xd6 [][]
        s16 pitch_addition2;
        // 0xd8 [][]
        u16 unknown_d8;

        // 0xe0 [][][][]
        u32 spu_update_flags;
        // 0xe4 [][][][]
        u32 start_offset;
        // 0xe8 [][][][]
        u32 loop_offset;
        // 0xec [][][][]
        u32 attack_mode;
        // 0xf0 [][][][]
        u32 sustain_mode;
        // 0xf4 [][][][]
        u32 release_mode;
        // 0xf8 [][]
        u16 pitch;
        // 0xfa [][]
        u16 attack_rate;
        // 0xfc [][]
        u16 decay_rate;
        // 0xfe [][]
        u16 sustain_level;
        // 0x100 [][]
        u16 sustain_rate;
        // 0x102 [][]
        u16 release_rate;
        // 0x104 [][]
        u16 left_volume;
        // 0x106 [][]
        u16 right_volume;
    };
    ChannelData m_MusicChannelData[ 24 ];



    struct ChannelConfig
    {
        // 0x04 [][][][]
        u32 active_channel_mask;
        // 0x08 [][][][]
        u32 for_play_channel_mask;
        // 0x0c [][][][]
        u32 unknown_0c;
        // 0x18 [][][][]
        u32 tempo;
        // 0x1c [][][][]
        u32 tempo_increment;
        // 0x20 [][][][]
        u32 tempo_counter;

        // 0x38 [][][][]
        u32 spu_update_flags;

        // 0x40 [][][][]
        u32 reverb_depth;

        // 0x48 [][]
        u16 tempo_increment_counter;
        // 0x4e [][]
        u16 conditional_value;
        // 0x50 [][][][]
        u32 reverb_depth_increment_counter;

        // 0x56 [][]
        u16 upper_timer_top;
        // 0x58 [][]
        u16 upper_timer;
        // 0x5a [][]
        u16 lower_timer_top;
        // 0x5c [][]
        u16 lower_timer;
        // 0x5e [][]
        u16 top_timer;
    };
    ChannelConfig m_MusicChannelConfig;



    File* m_Music;



private:
    void UpdateDynamicSpuParameters();
    void UpdatePitchAndVolume( ChannelData* channel_data, int channel_id );
    void UpdateSpu( ChannelData* channel_data, int channel_id );
    void UpdatePlayChannel( bool on, u32 channel_mask );
    void UpdateSequence( ChannelData* channel_data, int channel_id, ChannelConfig& channel_config );

    const u8 NextSequenceHandle( ChannelData* channel_data, int channel_id, ChannelConfig& channel_config );

    void InitChannelInstrument( ChannelData* channel_data, int channel_id, int instrument_id );
};



extern AkaoParser *AKAOPARSER;



#endif // AKAO_PARSER_H
