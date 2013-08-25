#ifndef SOUND_PARSER_H
#define SOUND_PARSER_H

#include <Ogre.h>

#include "../../common/File.h"
#include "../../common/TypeDefine.h"



class SoundParser
{
public:
    SoundParser();
    virtual ~SoundParser();

    void Update();

    // debug routines
    void DumpSequenceData( const Ogre::String& file );



private:
    enum SpuParameter
    {
        SPU_VOLUME        = 1 <<  0, // 0x0001
        SPU_PITCH         = 1 <<  2, // 0x0004
        SPU_OFFSET        = 1 <<  3, // 0x0008
        SPU_ATTACK        = 1 <<  4, // 0x0010
        SPU_DECAY_RATE    = 1 <<  5, // 0x0020
        SPU_SUSTAIN       = 1 <<  6, // 0x0040
        SPU_RELEASE       = 1 <<  7, // 0x0080
        SPU_SUSTAIN_LEVEL = 1 <<  8, // 0x0100
        SPU_FM_MODE       = 1 << 12, // 0x1000
        SPU_NOISE_MODE    = 1 << 13, // 0x2000
        SPU_REVERB_MODE   = 1 << 14, // 0x4000
    };

    struct ChannelData
    {
        // 0xc4 PART
        // 0x06
        u16 spu_update_flags;
        // 0x08
        u16 left_volume;
        // 0x0a
        u16 right_volume;
        // 0x14
        u16 pitch;
        // 0x1c
        u32 start_offset;
        // 0x20
        u32 loop_offset;
        // 0x24
        u8 attack_mode;
        // 0x27
        u8 attack_rate;



        // 0xf0 [][][][]
        u32 sustain_mode;
        // 0xf4 [][][][]
        u32 release_mode;


        // 0xfc [][]
        u16 decay_rate;
        // 0xfe [][]
        u16 sustain_level;
        // 0x100 [][]
        u16 sustain_rate;
        // 0x102 [][]
        u16 release_rate;

    };
    ChannelData m_ChannelData[ 24 ];



private:
    void UpdateSpu();
};



extern SoundParser *SOUND_PARSER;



#endif // SOUND_PARSER_H
