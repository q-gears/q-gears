#include "SoundParser.h"

#include "engine/SoundManager.h"
#include "../../common/Logger.h"



SoundParser *SOUND_PARSER = NULL;



SoundParser::SoundParser()
{
}



SoundParser::~SoundParser()
{
}



void
SoundParser::Update()
{
}



void
SoundParser::UpdateSpu()
{
    spu = w[8004ff84];

    T2 = 0;

    T6 = 0;
    T5 = 0;
    T4 = 0;

    for( int channel_id = 0; channel_id < 24; ++channel_id )
    {
        u16 spu_update_flags = m_ChannelData[ channel_id ].spu_update_flags;

        if( spu_update_flags & SPU_VOLUME )
        {
            LOGGER->Log( "UpdateSpu::SPU_VOLUME channel " + Ogre::StringConverter::toString( channel_id ) + " value:" + Ogre::StringConverter::toString( channel_data[ channel_id ].left_volume ) + " " + Ogre::StringConverter::toString( channel_data[ channel_id ].right_volume ) + ".\n" );
            SOUNDMAN->SetVoiceVolume( channel_id, m_ChannelData[ channel_id ].left_volume, m_ChannelData[ channel_id ].right_volume );
        }

        if( spu_update_flags & SPU_PITCH )
        {
            LOGGER->Log( "UpdateSpu::SPU_PITCH channel " + Ogre::StringConverter::toString( channel_id ) + " value:" + Ogre::StringConverter::toString( channel_data[ channel_id ].pitch ) + ".\n" );
            SOUNDMAN->SetVoicePitch( channel_id, m_ChannelData[ channel_id ].pitch );
        }

        if( spu_update_flags & SPU_OFFSET )
        {
            LOGGER->Log( "UpdateSpu::SPU_OFFSET channel start " + Ogre::StringConverter::toString( channel_id ) + " value:" + Ogre::StringConverter::toString( channel_data[ channel_id ].start_offset ) + " >>> 8 loop " + Ogre::StringConverter::toString( channel_id ) + " value:" + Ogre::StringConverter::toString( channel_data[ channel_id ].loop_offset ) + " >>> 8.\n" );
            SOUNDMAN->SetVoiceStartAddress( channel_id, m_ChannelData[ channel_id ].start_offset >>> 8 );
            SOUNDMAN->SetVoiceLoopAddress( channel_id, m_ChannelData[ channel_id ].loop_offset >>> 8 );
        }

        if( spu_update_flags & SPU_ATTACK )
        {
            // +24 >> 2 attack mode
            // +27 attack rate
            //LOGGER->Log( "UpdateSpu::SPU_ATTACK_RATE|SPU_ATTACK_MODE channel " + Ogre::StringConverter::toString( channel_id ) + " value:" + Ogre::StringConverter::toString( channel_data[ channel_id ].attack_rate ) + " " + Ogre::StringConverter::toString( channel_data[ channel_id ].attack_mode ) + ".\n" );
            SOUNDMAN->SetVoiceAttackRate( channel_id, channel_data[ channel_id ].attack_rate, ( SoundManager::SpuRateMode )( channel_data[ channel_id ].attack_mode >> 2) );
        }

        if (spu_update_flags & 0020)
        {
            [spu + channel_id * 10 + 8] = h((hu[spu + channel_id * 10 + 8] & ff0f) + (bu[channel_data + 28] << 4)); // decay rate
        }

        if (spu_update_flags & 0040)
        {
            // +25 >> 1 sustain mode
            // +29 sustain rate
            [spu + channel_id * 10 + a] = h((hu[spu + channel_id * 10 + a] & 003f) + (bu[channel_data + 29] << 6) + ((bu[channel_data + 25] >> 1) << e)); // sustain mode and rate
        }

        if (spu_update_flags & 0080)
        {
            [spu + channel_id * 10 + a] = h((hu[spu + channel_id * 10 + a] & ffc0) + bu[channel_data + 2a] + ((bu[channel_data + 26] >> 2) << 5)); // release mode and rate
        }

        if (spu_update_flags & 0100)
        {
            [spu + channel_id * 10 + 8] = h((hu[spu + channel_id * 10 + 8] & fff0) + bu[channel_data + 2b]); // sustain level
        }

        T2 = T2 | spu_update_flags & 7000;
        [channel_data + 6] = h(0);

        V0 = hu[channel_data + 2];
        T4 = T4 | (((V0 >> 4) & 1) << channel_id);
        T5 = T5 | (((V0 >> 5) & 1) << channel_id);
        T6 = T6 | (((V0 >> 6) & 1) << channel_id);
    }



    if (T2 & ffff)
    {
        if (T2 & 1000)
        {
            [spu + 190] = h(T4);       // Channel FM (pitch lfo) mode (0-15)
            [spu + 192] = h(T4 >> 10); // Channel FM (pitch lfo) mode (16-23)
        }

        if (T2 & 2000)
        {
            [spu + 194] = h(T5);       // Channel Noise mode (0-15)
            [spu + 196] = h(T5 >> 10); // Channel Noise mode (16-23)
        }

        if (T2 & 4000)
        {
            [spu + 198] = h(T6);       // Channel Reverb mode (0-15)
            [spu + 19a] = h(T6 >> 10); // Channel Reverb mode (16-23)
        }
    }

    V0 = w[80058b98];
    if (V0 != 0)
    {
        [spu + 188] = h(V0);       // Voice ON (0-15)
        [spu + 18a] = h(V0 >> 10); // Voice ON (16-23)
        [80058b98] = w(0);
    }
}
