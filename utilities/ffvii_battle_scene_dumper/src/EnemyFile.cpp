#include "EnemyFile.h"

#include "FFVIIString.h"
#include "../../common/Logger.h"



Ogre::String
ElementIdToString( const int element_id )
{
    switch( element_id )
    {
        case 0x00: return "Fire";
        case 0x02: return "Lighting";
        case 0x03: return "Earth";
        case 0x05: return "Gravity";
        case 0x07: return "Wind";
        case 0x0b: return "Hit";
        case 0x0c: return "Punch";
        case 0x0d: return "Shoot";
    }

    return "UnknownElement0x" + HexToString( element_id, 4, '0' );
}

Ogre::String
ElementEffectIdToString( const int effect_id )
{
    switch( effect_id )
    {
        case 0x02: return "DoubleDamage";
        case 0x05: return "Nullify";
    }

    return "UnknownElementEffect0x" + HexToString( effect_id, 4, '0' );
}

Ogre::String
StatusIdToString( const int status_id )
{
    switch( status_id )
    {
        case 0x00: return "Death";
        case 0x02: return "Sleep";
        case 0x03: return "Poison";
        case 0x04: return "Sadness";
        case 0x05: return "Fury";
        case 0x06: return "Confusion";
        case 0x07: return "Silence";
        case 0x0a: return "Stop";
        case 0x0b: return "Frog";
        case 0x0c: return "Small";
        case 0x15: return "DeathSentence";
        case 0x19: return "Paralysis";
        case 0x1a: return "Darkness";
    }

    return "UnknownStatusId0x" + HexToString( status_id, 4, '0' );
}

Ogre::String
ItemIdToString( const int item_id )
{
    switch( item_id )
    {
        case 0x00: return "Potion";
        case 0x03: return "Ether";
        case 0x14: return "Grenade";
    }

    return "UnknownItemId0x" + HexToString( item_id, 4, '0' );
}

Ogre::String
AttackIdToString( const int attack_id )
{
    switch( attack_id )
    {
        case 0x001b: return "Fire";
        case 0x0110: return "MachineGun";
        case 0x0111: return "Tonfa";
        case 0x0112: return "Bite";
        case 0x0113: return "Tentacle";
        case 0x0114: return "Drilldrive";
        case 0x0115: return "Handclaw";
        case 0x0116: return "BeamGun";
        case 0x0117: return "LaserCannon";
        case 0x0118: return "WMachineGun";
        case 0x0119: return "SmokeShot";
        case 0x011a: return "Rifle";
        case 0x011b: return "ScorpionTail";
        case 0x011c: return "SearchScope";
        case 0x011d: return "Rifle";
        case 0x011e: return "TailLaser";
        case 0x011f: return "Empty0x11f";
        case 0x0120: return "Empty0x120";
    }

    return "UnknownAttackId0x" + HexToString( attack_id, 4, '0' );
}




Ogre::String
StageIdToFileName( const int stage_id )
{
    switch( stage_id )
    {
        case 0x09: return "sector_1_train_station";
        case 0x0c: return "reactor_1_entrance";
    }

    return "UnknownStageId0x" + HexToString( stage_id, 4, '0' );
}


EnemyFile::EnemyFile( const Ogre::String &file ):
    File( file )
{
    DumpData();
}



EnemyFile::EnemyFile( File *file, const u32 &offset, const u32 &length ):
    File( file, offset, length )
{
    DumpData();
}



EnemyFile::EnemyFile( u8* buffer, const u32 &offset, const u32 &length ):
    File( buffer, offset, length )
{
    DumpData();
}



EnemyFile::EnemyFile( File *file ):
    File( file )
{
    DumpData();
}



EnemyFile::~EnemyFile()
{
}



void
EnemyFile::DumpData()
{
    Logger* export_text = new Logger( "enemy.lua" );
    bool added = false;

    int enemy_data_offset = 0x0298;
    int enemy_ai_offset   = 0x0e80;

    for( int k = 0 ; k < 3; ++k )
    {
        if( GetU16LE( k * 0x02 ) == 0xffff )
        {
            continue;
        }

        FFVIIString name;
        name.resize( 32 );
        std::copy( m_Buffer + enemy_data_offset + k * 184, m_Buffer + enemy_data_offset + k * 184 + 0x20, name.begin() );
        Ogre::String r_name = FFVIIStringToString( name );

        export_text->Log( "-- " + Ogre::String( r_name.c_str() ) + "(" + IntToString( GetU16LE( k * 0x02 ) ) + ")\n" );
        export_text->Log( Ogre::String( r_name.c_str() ) + "= {\n" );

        export_text->Log( "    max_hp = " + IntToString( GetU32LE( enemy_data_offset + k * 184 + 0xa4 ) ) + ",\n" );
        export_text->Log( "    max_mp = " + IntToString( GetU16LE( enemy_data_offset + k * 184 + 0x9c ) ) + ",\n" );
        export_text->Log( "\n" );
        export_text->Log( "    level = " + IntToString( GetU8( enemy_data_offset + k * 184 + 0x20 ) ) + ",\n" );
        export_text->Log( "    physical_power = " + IntToString( GetU8( enemy_data_offset + k * 184 + 0x24 ) ) + ",\n" );
        export_text->Log( "    physical_defense = " + IntToString( GetU8( enemy_data_offset + k * 184 + 0x25 ) ) + ",\n" );
        export_text->Log( "    physical_dodge = " + IntToString( GetU8( enemy_data_offset + k * 184 + 0x23 ) ) + ",\n" );
        export_text->Log( "    magic_power = " + IntToString( GetU8( enemy_data_offset + k * 184 + 0x26 ) ) + ",\n" );
        export_text->Log( "    magic_defense = " + IntToString( GetU8( enemy_data_offset + k * 184 + 0x27 ) ) + ",\n" );
        export_text->Log( "    speed = " + IntToString( GetU8( enemy_data_offset + k * 184 + 0x21 ) ) + ",\n" );
        export_text->Log( "    luck = " + IntToString( GetU8( enemy_data_offset + k * 184 + 0x22 ) ) + ",\n" );
        export_text->Log( "\n" );
        export_text->Log( "    back_damage_multiplier = " + FloatToString( GetU8( enemy_data_offset + k * 184 + 0xa2 ) / 8.0f ) + ",\n" );
        export_text->Log( "\n" );
        export_text->Log( "    morph_item = " + ItemIdToString( GetU16LE( enemy_data_offset + k * 184 + 0xa0 ) ) + ",\n" );
        export_text->Log( "\n" );
        export_text->Log( "    reward_exp = " + IntToString( GetU32LE( enemy_data_offset + k * 184 + 0xa8 ) ) + ",\n" );
        export_text->Log( "    reward_ap = " + IntToString( GetU16LE( enemy_data_offset + k * 184 + 0x9e ) ) + ",\n" );
        export_text->Log( "    reward_gil = " + IntToString( GetU32LE( enemy_data_offset + k * 184 + 0xac ) ) + ",\n" );
        export_text->Log( "\n" );

        export_text->Log( "    reward_items_drop = {" );
        added = false;
        for( int l = 0; l < 4; ++l )
        {
            u8 rate = GetU8( enemy_data_offset + k * 184 + 0x88 + l );
            u16 item_id = GetU16LE( enemy_data_offset + k * 184 + 0x8c + l * 0x02 );
            if( item_id != 65535 && rate < 0x80 )
            {
                added = true;
                export_text->Log( "\n        " + ItemIdToString( item_id ) + " = " + IntToString( rate ) + "," );
            }
            if( added == true && l == 3 )
            {
                export_text->Log( "\n    " );
            }
        }
        export_text->Log( "},\n");

        export_text->Log( "\n" );

        export_text->Log( "    elements = {" );
        bool added = false;
        for( int l = 0; l < 8; ++l )
        {
            int element_id = GetU8( enemy_data_offset + k * 184 + 0x28 + l );
            if( element_id != 255 )
            {
                added = true;
                int effect = GetU8( enemy_data_offset + k * 184 + 0x30 + l );
                export_text->Log( "\n        " + ElementIdToString( element_id ) + " = \"" + ElementEffectIdToString( effect ) + "\"," );
            }
            if( added == true && l == 7 )
            {
                export_text->Log( "\n    " );
            }
        }
        export_text->Log( "},\n");

        export_text->Log( "\n" );

        u32 status_immunes = GetU32LE( enemy_data_offset + k * 184 + 0xb0 );
        export_text->Log( "    status_immunes = {" );
        added = false;
        for( int l = 0; l < 32; ++l )
        {
            if( ( ( status_immunes >> l ) & 1 ) == 0 )
            {
                added = true;
                export_text->Log( "\n        " + StatusIdToString( l ) + "," );
            }
            if( added == true && l == 31 )
            {
                export_text->Log( "\n    " );
            }
        }
        export_text->Log( "},\n");

        export_text->Log( "\n" );

        export_text->Log( "    attacks = {" );
        added = false;
        for( int l = 0; l < 16; ++l )
        {
            int script_id = GetU8( enemy_data_offset + k * 184 + 0x38 + l );
            int attack_id = GetU16LE( enemy_data_offset + k * 184 + 0x48 + l * 0x02 );
            int camera_movement = GetU16LE( enemy_data_offset + k * 184 + 0x68 + l * 0x02 );
            if( attack_id != 65535 )
            {
                added = true;
                if( l != 0 )
                {
                    export_text->Log( "," );
                }
                export_text->Log( "\n        " + AttackIdToString( attack_id ) + " = {" );
                bool ext_added = false;
                if( script_id != 255 )
                {
                    ext_added = true;
                    export_text->Log( "\n            script_id = " + IntToString( script_id ) + "," );
                }
                if( camera_movement != 65535 )
                {
                    ext_added = true;
                    export_text->Log( "\n            camera_movement = " + IntToString( camera_movement ) + "," );
                }
                if( ext_added == true )
                {
                    export_text->Log( "\n        " );
                }
                export_text->Log( "}" );
            }
            if( added == true && l == 15 )
            {
                export_text->Log( "\n    " );
            }
        }
        export_text->Log( "},\n");

        export_text->Log( "\n" );

        export_text->Log( "    items_steal = {" );
        added = false;
        for( int l = 0; l < 4; ++l )
        {
            u8 rate = GetU8( enemy_data_offset + k * 184 + 0x88 + l );
            u16 item_id = GetU16LE( enemy_data_offset + k * 184 + 0x8c + l * 0x02 );
            if( item_id != 65535 && rate >= 0x80 )
            {
                added = true;
                export_text->Log( "\n        " + ItemIdToString( item_id ) + " = " + IntToString( rate - 0x80 ) + "," );
            }
            if( added == true && l == 3 )
            {
                export_text->Log( "\n    " );
            }
        }
        export_text->Log( "},\n");

        export_text->Log( "\n" );

        int berserk = GetU16LE( enemy_data_offset + k * 184 + 0x94 );
        if( berserk != 65535 )
        {
            export_text->Log( "    berserk_attack = " + AttackIdToString( berserk ) + ",\n\n" );
        }

        export_text->Log( "    manipulate_attacks = {");
        added = false;
        for( int l = 0; l < 3; ++l )
        {
            int attack_id = GetU16LE( enemy_data_offset + k * 184 + 0x94 + l * 0x02 );
            if( attack_id != 65535 )
            {
                added = true;
                export_text->Log( "\n        " + AttackIdToString( attack_id ) + "," );
            }
            if( added == true && l == 2 )
            {
                export_text->Log( "\n    " );
            }
        }
        export_text->Log( "},\n");

        //export_text->Log( "\n    unknown_0x9a = \"0x" + HexToString( GetU16LE( enemy_data_offset + k * 184 + 0x9a ), 4, '0' ) + ",\n" );

/*



        LOGGER->Log("AI:\n");
        int ai_offset = enemy_ai_offset + GetU16LE(enemy_ai_offset + k * 2);

        for (int l = 0; l < 0x10; ++l)
        {
            u16 local_script_offset = GetU16LE(ai_offset + l * 2);
            if (local_script_offset == 0xFFFF)
            {
                continue;
            }

            LOGGER->Log("script %x:\n", l);

            int script_offset = ai_offset + local_script_offset;
            int pointer = 0;
            bool run = true;

            for (; run == true;)
            {
                u8 opcode = GetU8(script_offset + pointer);
                u8 opcode_h = opcode >> 4;
                u8 opcode_l = opcode & 0xF;

                LOGGER->Log("0x%04x ", pointer);



                if (GetU8(script_offset + pointer + 0)  == 0x00 &&
                    GetU8(script_offset + pointer + 3)  == 0x52 &&
                    GetU8(script_offset + pointer + 4)  == 0x70)
                {
                    int address1 = GetU16LE(script_offset + pointer + 1) >> 3;
                    int bits1    = GetU16LE(script_offset + pointer + 1) & 7;
                    int jump     = GetU16LE(script_offset + pointer + 5);

                    LOGGER->Log("JumpIfTrue(bit[0x%04x + 0x%02x])(0x%04x);\n", address1, bits1, jump);
                    pointer += 7;
                    continue;
                }

                if (GetU8(script_offset + pointer + 0)  == 0x01 &&
                    GetU8(script_offset + pointer + 3)  == 0x52 &&
                    GetU8(script_offset + pointer + 4)  == 0x70)
                {
                    int address1 = GetU16LE(script_offset + pointer + 1) >> 3;
                    int bits1    = GetU16LE(script_offset + pointer + 1) & 7;
                    int jump     = GetU16LE(script_offset + pointer + 5);

                    LOGGER->Log("JumpIfTrue(b[0x%04x + 0x%02x])(0x%04x);\n", address1, bits1, jump);
                    pointer += 7;
                    continue;
                }

                if (GetU8(script_offset + pointer + 0)  == 0x00 &&
                    GetU8(script_offset + pointer + 3)  == 0x70)
                {
                    int address1 = GetU16LE(script_offset + pointer + 1) >> 3;
                    int bits1    = GetU16LE(script_offset + pointer + 1) & 7;
                    int jump     = GetU16LE(script_offset + pointer + 4);

                    LOGGER->Log("JumpIfFalse(bit[0x%04x + 0x%02x])(0x%04x);\n", address1, bits1, jump);
                    pointer += 6;
                    continue;
                }

                if (GetU8(script_offset + pointer + 0)  == 0x01 &&
                    GetU8(script_offset + pointer + 3)  == 0x60 &&
                    GetU8(script_offset + pointer + 5)  == 0x35 &&
                    GetU8(script_offset + pointer + 6)  == 0x60 &&
                    GetU8(script_offset + pointer + 8)  == 0x40 &&
                    GetU8(script_offset + pointer + 9)  == 0x70)
                {
                    int address1 = GetU16LE(script_offset + pointer + 1) >> 3;
                    int bits1    = GetU16LE(script_offset + pointer + 1) & 7;

                    int value1   = GetU8(script_offset + pointer + 4);
                    int value2   = GetU8(script_offset + pointer + 7);

                    int jump     = GetU16LE(script_offset + pointer + 10);

                    LOGGER->Log("JumpIf((b[0x%04x + 0x%02x] & 0x%02x) != 0x%02x)(0x%04x);\n", address1, bits1, value1, value2, jump);
                    pointer += 12;
                    continue;
                }

                if (GetU8(script_offset + pointer + 0)  == 0x02 &&
                    GetU8(script_offset + pointer + 1)  == 0x60 &&
                    GetU8(script_offset + pointer + 2)  == 0x20 &&
                    GetU8(script_offset + pointer + 3)  == 0x00 &&
                    GetU8(script_offset + pointer + 4)  == 0x26 &&
                    GetU8(script_offset + pointer + 5)  == 0x40 &&
                    GetU8(script_offset + pointer + 6)  == 0x80 &&
                    GetU8(script_offset + pointer + 7)  == 0x60 &&
                    GetU8(script_offset + pointer + 8)  == 0x00 &&
                    GetU8(script_offset + pointer + 9)  == 0x40 &&
                    GetU8(script_offset + pointer + 10) == 0x70)
                {
                    int address = GetU16LE(script_offset + pointer + 11);
                    LOGGER->Log("JumpIfSelfNotInFrontRow(0x%04x);\n", address);
                    pointer += 13;
                    continue;
                }

                if (GetU8(script_offset + pointer + 0)  == 0x02 &&
                    GetU8(script_offset + pointer + 1)  == 0x80 &&
                    GetU8(script_offset + pointer + 2)  == 0x20 &&
                    GetU8(script_offset + pointer + 3)  == 0x00 &&
                    GetU8(script_offset + pointer + 4)  == 0x26 &&
                    GetU8(script_offset + pointer + 5)  == 0x40 &&
                    GetU8(script_offset + pointer + 6)  == 0x80 &&
                    GetU8(script_offset + pointer + 7)  == 0x60 &&
                    GetU8(script_offset + pointer + 8)  == 0x00 &&
                    GetU8(script_offset + pointer + 9)  == 0x40 &&
                    GetU8(script_offset + pointer + 10) == 0x70)
                {
                    int address = GetU16LE(script_offset + pointer + 11);
                    LOGGER->Log("JumpIfNotAllFriendsInFrontRow(0x%04x);\n", address);
                    pointer += 13;
                    continue;
                }

                if (GetU8(script_offset + pointer + 0)  == 0x02 &&
                    GetU8(script_offset + pointer + 1)  == 0x80 &&
                    GetU8(script_offset + pointer + 2)  == 0x20 &&
                    GetU8(script_offset + pointer + 3)  == 0x00 &&
                    GetU8(script_offset + pointer + 4)  == 0x26 &&
                    GetU8(script_offset + pointer + 5)  == 0x40 &&
                    GetU8(script_offset + pointer + 6)  == 0x80 &&
                    GetU8(script_offset + pointer + 7)  == 0x60 &&
                    GetU8(script_offset + pointer + 8)  == 0x01 &&
                    GetU8(script_offset + pointer + 9)  == 0x40 &&
                    GetU8(script_offset + pointer + 10) == 0x70)
                {
                    int address = GetU16LE(script_offset + pointer + 11);
                    LOGGER->Log("JumpIfNotAllFriendsInBackRow(0x%04x);\n", address);
                    pointer += 13;
                    continue;
                }

                if (GetU8(script_offset + pointer + 0)  == 0x02 &&
                    GetU8(script_offset + pointer + 1)  == 0xA0 &&
                    GetU8(script_offset + pointer + 2)  == 0x20 &&
                    GetU8(script_offset + pointer + 3)  == 0x00 &&
                    GetU8(script_offset + pointer + 4)  == 0x26 &&
                    GetU8(script_offset + pointer + 5)  == 0x40 &&
                    GetU8(script_offset + pointer + 6)  == 0x80 &&
                    GetU8(script_offset + pointer + 7)  == 0x60 &&
                    GetU8(script_offset + pointer + 8)  == 0x00 &&
                    GetU8(script_offset + pointer + 9)  == 0x40 &&
                    GetU8(script_offset + pointer + 10) == 0x70)
                {
                    int address = GetU16LE(script_offset + pointer + 11);
                    LOGGER->Log("JumpIfNotAllOpponentsInFrontRow(0x%04x);\n", address);
                    pointer += 13;
                    continue;
                }

                if (GetU8(script_offset + pointer + 0)  == 0x02 &&
                    GetU8(script_offset + pointer + 1)  == 0xA0 &&
                    GetU8(script_offset + pointer + 2)  == 0x20 &&
                    GetU8(script_offset + pointer + 3)  == 0x00 &&
                    GetU8(script_offset + pointer + 4)  == 0x26 &&
                    GetU8(script_offset + pointer + 5)  == 0x40 &&
                    GetU8(script_offset + pointer + 6)  == 0x80 &&
                    GetU8(script_offset + pointer + 7)  == 0x60 &&
                    GetU8(script_offset + pointer + 8)  == 0x01 &&
                    GetU8(script_offset + pointer + 9)  == 0x40 &&
                    GetU8(script_offset + pointer + 10) == 0x70)
                {
                    int address = GetU16LE(script_offset + pointer + 11);
                    LOGGER->Log("JumpIfNotAllOpponentsInBackRow(0x%04x);\n", address);
                    pointer += 13;
                    continue;
                }

                if (GetU8(script_offset + pointer + 0)  == 0x02 &&
                    GetU8(script_offset + pointer + 1)  == 0xA0 &&
                    GetU8(script_offset + pointer + 2)  == 0x20 &&
                    GetU8(script_offset + pointer + 3)  == 0x00 &&
                    GetU8(script_offset + pointer + 4)  == 0x1a &&
                    GetU8(script_offset + pointer + 5)  == 0x40 &&
                    GetU8(script_offset + pointer + 6)  == 0x80 &&
                    GetU8(script_offset + pointer + 7)  == 0x60 &&
                    GetU8(script_offset + pointer + 8)  == 0x00 &&
                    GetU8(script_offset + pointer + 9)  == 0x40 &&
                    GetU8(script_offset + pointer + 10) == 0x70)
                {
                    int address = GetU16LE(script_offset + pointer + 11);
                    LOGGER->Log("JumpIfAllOpponentsInDarknessStatus(0x%04x);\n", address);
                    pointer += 13;
                    continue;
                }

                if ((GetU8(script_offset + pointer + 0)  == 0x10 || GetU8(script_offset + pointer + 0)  == 0x11 || GetU8(script_offset + pointer + 0)  == 0x12) &&
                    GetU8(script_offset + pointer + 3)  == 0x60 &&
                    GetU8(script_offset + pointer + 5)  == 0x90)
                {
                    int address = GetU16LE(script_offset + pointer + 1) >> 3;
                    int bits    = GetU16LE(script_offset + pointer + 1) & 7;
                    int value   = GetU8(script_offset + pointer + 4);
                    LOGGER->Log("[0x%04x + 0x%02x] = b(0x%02x);\n", address, bits, value);
                    pointer += 6;
                    continue;
                }

                if ((GetU8(script_offset + pointer + 0)  == 0x10 || GetU8(script_offset + pointer + 0)  == 0x11 || GetU8(script_offset + pointer + 0)  == 0x12) &&
                    GetU8(script_offset + pointer + 3)  == 0x61 &&
                    GetU8(script_offset + pointer + 6)  == 0x90)
                {
                    int address = GetU16LE(script_offset + pointer + 1) >> 3;
                    int bits    = GetU16LE(script_offset + pointer + 1) & 7;
                    int value   = GetU16LE(script_offset + pointer + 4);
                    LOGGER->Log("[0x%04x + 0x%02x] = h(0x%04x);\n", address, bits, value);
                    pointer += 7;
                    continue;
                }

                if ((GetU8(script_offset + pointer + 0)  == 0x10 || GetU8(script_offset + pointer + 0)  == 0x11 || GetU8(script_offset + pointer + 0)  == 0x12) &&
                    GetU8(script_offset + pointer + 3)  == 0x62 &&
                    GetU8(script_offset + pointer + 7)  == 0x90)
                {
                    int address = GetU16LE(script_offset + pointer + 1) >> 3;
                    int bits    = GetU16LE(script_offset + pointer + 1) & 7;
                    int value   = (GetU16LE(script_offset + pointer + 4) << 1) | GetU8(script_offset + pointer + 6);
                    LOGGER->Log("[0x%04x + 0x%02x] = w(0x%08x);\n", address, bits, value);
                    pointer += 8;
                    continue;
                }

                if (GetU8(script_offset + pointer + 0)  == 0x11 &&
                    GetU8(script_offset + pointer + 3)  == 0x01 &&
                    GetU8(script_offset + pointer + 6)  == 0x60 &&
                    GetU8(script_offset + pointer + 8)  == 0x35 &&
                    GetU8(script_offset + pointer + 9)  == 0x90)
                {
                    int address1 = GetU16LE(script_offset + pointer + 1) >> 3;
                    int bits1    = GetU16LE(script_offset + pointer + 1) & 7;

                    int address2 = GetU16LE(script_offset + pointer + 4) >> 3;
                    int bits2    = GetU16LE(script_offset + pointer + 4) & 7;

                    int value    = GetU8(script_offset + pointer + 7);

                    LOGGER->Log("[0x%04x + 0x%02x] = b(b[0x%04x + 0x%02x] & 0x%02x);\n", address1, bits1, address2, bits2, value);
                    pointer += 10;
                    continue;
                }

                if (GetU8(script_offset + pointer + 0)  == 0x12 &&
                    GetU8(script_offset + pointer + 3)  == 0x02 &&
                    GetU8(script_offset + pointer + 6)  == 0x90)
                {
                    int address1 = GetU16LE(script_offset + pointer + 1) >> 3;
                    int bits1    = GetU16LE(script_offset + pointer + 1) & 7;
                    int address2 = GetU16LE(script_offset + pointer + 4) >> 3;
                    int bits2    = GetU16LE(script_offset + pointer + 4) & 7;

                    LOGGER->Log("[0x%04x + 0x%02x] = h(h[0x%04x + 0x%02x]);\n", address1, bits1, address2, bits2);
                    pointer += 7;
                    continue;
                }

                if (GetU8(script_offset + pointer + 0)  == 0x12 &&
                    GetU8(script_offset + pointer + 3)  == 0x61 &&
                    GetU8(script_offset + pointer + 6)  == 0x90)
                {
                    int address = GetU16LE(script_offset + pointer + 1) >> 3;
                    int bits    = GetU16LE(script_offset + pointer + 1) & 7;
                    int value   = GetU8(script_offset + pointer + 4) | (GetU8(script_offset + pointer + 5) << 8);
                    LOGGER->Log("[0x%04x + 0x%02x] = h(0x%04x);\n", address, bits, value);
                    pointer += 7;
                    continue;
                }

                if (GetU8(script_offset + pointer + 0)  == 0x12 &&
                    GetU8(script_offset + pointer + 1)  == 0x70 &&
                    GetU8(script_offset + pointer + 2)  == 0x20 &&
                    GetU8(script_offset + pointer + 3)  == 0x02 &&
                    GetU8(script_offset + pointer + 4)  == 0xA0 &&
                    GetU8(script_offset + pointer + 5)  == 0x20 &&
                    GetU8(script_offset + pointer + 6)  == 0x00 &&
                    GetU8(script_offset + pointer + 7)  == 0x26 &&
                    GetU8(script_offset + pointer + 8)  == 0x40 &&
                    GetU8(script_offset + pointer + 9)  == 0x80 &&
                    GetU8(script_offset + pointer + 10) == 0x60 &&
                    GetU8(script_offset + pointer + 11) == 0x01 &&
                    GetU8(script_offset + pointer + 12) == 0x40 &&
                    GetU8(script_offset + pointer + 13) == 0x82 &&
                    GetU8(script_offset + pointer + 14) == 0x90)
                {
                    LOGGER->Log("SetRandomOpponentInBackRowToAttack();\n");
                    pointer += 15;
                    continue;
                }

                if (GetU8(script_offset + pointer + 0)  == 0x12 &&
                    GetU8(script_offset + pointer + 1)  == 0x70 &&
                    GetU8(script_offset + pointer + 2)  == 0x20 &&
                    GetU8(script_offset + pointer + 3)  == 0x02 &&
                    GetU8(script_offset + pointer + 4)  == 0xA0 &&
                    GetU8(script_offset + pointer + 5)  == 0x20 &&
                    GetU8(script_offset + pointer + 6)  == 0x00 &&
                    GetU8(script_offset + pointer + 7)  == 0x26 &&
                    GetU8(script_offset + pointer + 8)  == 0x40 &&
                    GetU8(script_offset + pointer + 9)  == 0x80 &&
                    GetU8(script_offset + pointer + 10) == 0x60 &&
                    GetU8(script_offset + pointer + 11) == 0x00 &&
                    GetU8(script_offset + pointer + 12) == 0x40 &&
                    GetU8(script_offset + pointer + 13) == 0x82 &&
                    GetU8(script_offset + pointer + 14) == 0x90)
                {
                    LOGGER->Log("SetRandomOpponentInFrontRowToAttack();\n");
                    pointer += 15;
                    continue;
                }

                if (GetU8(script_offset + pointer + 0)  == 0x12 &&
                    GetU8(script_offset + pointer + 1)  == 0x70 &&
                    GetU8(script_offset + pointer + 2)  == 0x20 &&
                    GetU8(script_offset + pointer + 3)  == 0x02 &&
                    GetU8(script_offset + pointer + 4)  == 0xA0 &&
                    GetU8(script_offset + pointer + 5)  == 0x20 &&
                    GetU8(script_offset + pointer + 6)  == 0x03 &&
                    GetU8(script_offset + pointer + 7)  == 0x60 &&
                    GetU8(script_offset + pointer + 8)  == 0x41 &&
                    GetU8(script_offset + pointer + 9)  == 0x80 &&
                    GetU8(script_offset + pointer + 10) == 0x85 &&
                    GetU8(script_offset + pointer + 11) == 0x82 &&
                    GetU8(script_offset + pointer + 12) == 0x90)
                {
                    LOGGER->Log("SetRandomOpponentWithLowestCurrentHP();\n");
                    pointer += 13;
                    continue;
                }

                if (GetU8(script_offset + pointer + 0)  == 0x12 &&
                    GetU8(script_offset + pointer + 1)  == 0x70 &&
                    GetU8(script_offset + pointer + 2)  == 0x20 &&
                    GetU8(script_offset + pointer + 3)  == 0x02 &&
                    GetU8(script_offset + pointer + 4)  == 0xA0 &&
                    GetU8(script_offset + pointer + 5)  == 0x20 &&
                    GetU8(script_offset + pointer + 6)  == 0x03 &&
                    GetU8(script_offset + pointer + 7)  == 0x60 &&
                    GetU8(script_offset + pointer + 8)  == 0x41 &&
                    GetU8(script_offset + pointer + 9)  == 0x80 &&
                    GetU8(script_offset + pointer + 10) == 0x84 &&
                    GetU8(script_offset + pointer + 11) == 0x82 &&
                    GetU8(script_offset + pointer + 12) == 0x90)
                {
                    LOGGER->Log("SetRandomOpponentWithHighestCurrentHP();\n");
                    pointer += 13;
                    continue;
                }

                if (GetU8(script_offset + pointer + 0)  == 0x12 &&
                    GetU8(script_offset + pointer + 1)  == 0x70 &&
                    GetU8(script_offset + pointer + 2)  == 0x20 &&
                    GetU8(script_offset + pointer + 3)  == 0x02 &&
                    GetU8(script_offset + pointer + 4)  == 0xA0 &&
                    GetU8(script_offset + pointer + 5)  == 0x20 &&
                    GetU8(script_offset + pointer + 6)  == 0x02 &&
                    GetU8(script_offset + pointer + 7)  == 0x10 &&
                    GetU8(script_offset + pointer + 8)  == 0x41 &&
                    GetU8(script_offset + pointer + 9)  == 0x80 &&
                    GetU8(script_offset + pointer + 10) == 0x85 &&
                    GetU8(script_offset + pointer + 11) == 0x82 &&
                    GetU8(script_offset + pointer + 12) == 0x90)
                {
                    LOGGER->Log("SetRandomOpponentWithLowestMagicDefence();\n");
                    pointer += 13;
                    continue;
                }

                if (GetU8(script_offset + pointer + 0)  == 0x12 &&
                    GetU8(script_offset + pointer + 1)  == 0x70 &&
                    GetU8(script_offset + pointer + 2)  == 0x20 &&
                    GetU8(script_offset + pointer + 3)  == 0x02 &&
                    GetU8(script_offset + pointer + 4)  == 0xA0 &&
                    GetU8(script_offset + pointer + 5)  == 0x20 &&
                    GetU8(script_offset + pointer + 6)  == 0x02 &&
                    GetU8(script_offset + pointer + 7)  == 0x00 &&
                    GetU8(script_offset + pointer + 8)  == 0x41 &&
                    GetU8(script_offset + pointer + 9)  == 0x80 &&
                    GetU8(script_offset + pointer + 10) == 0x85 &&
                    GetU8(script_offset + pointer + 11) == 0x82 &&
                    GetU8(script_offset + pointer + 12) == 0x90)
                {
                    LOGGER->Log("SetRandomOpponentWithLowestDefence();\n");
                    pointer += 13;
                    continue;
                }

                if (GetU8(script_offset + pointer + 0)  == 0x12 &&
                    GetU8(script_offset + pointer + 1)  == 0x70 &&
                    GetU8(script_offset + pointer + 2)  == 0x20 &&
                    GetU8(script_offset + pointer + 3)  == 0x02 &&
                    GetU8(script_offset + pointer + 4)  == 0xA0 &&
                    GetU8(script_offset + pointer + 5)  == 0x20 &&
                    GetU8(script_offset + pointer + 6) == 0x82 &&
                    GetU8(script_offset + pointer + 7) == 0x90)
                {
                    LOGGER->Log("SetRandomOpponentToAttack();\n");
                    pointer += 8;
                    continue;
                }

                if (GetU8(script_offset + pointer + 0)  == 0x60 &&
                    GetU8(script_offset + pointer + 2)  == 0x02 &&
                    GetU8(script_offset + pointer + 5) == 0x92)
                {
                    int action   = GetU8(script_offset + pointer + 1);
                    int address1 = GetU16LE(script_offset + pointer + 3) >> 3;
                    int bits1    = GetU16LE(script_offset + pointer + 3) & 7;

                    LOGGER->Log("RunCommand(0x%02x, h[0x%04x + 0x%02x]);\n", action, address1, bits1);
                    pointer += 6;
                    continue;
                }

                if (GetU8(script_offset + pointer + 0)  == 0x81 &&
                    GetU8(script_offset + pointer + 1)  == 0x01 &&
                    GetU8(script_offset + pointer + 4)  == 0x34 &&
                    GetU8(script_offset + pointer + 5)  == 0x52 &&
                    GetU8(script_offset + pointer + 6) == 0x70)
                {
                    int address1 = GetU16LE(script_offset + pointer + 2) >> 3;
                    int bits1    = GetU16LE(script_offset + pointer + 2) & 7;
                    int jump     = GetU16LE(script_offset + pointer + 7);

                    LOGGER->Log("JumpIfRandomNot(1/b[0x%04x + 0x%02x])(0x%04x);\n", address1, bits1, jump);
                    pointer += 9;
                    continue;
                }

                if (GetU8(script_offset + pointer + 0)  == 0x81 &&
                    GetU8(script_offset + pointer + 1)  == 0x60 &&
                    GetU8(script_offset + pointer + 3)  == 0x34 &&
                    GetU8(script_offset + pointer + 4)  == 0x52 &&
                    GetU8(script_offset + pointer + 5) == 0x70)
                {
                    int value    = GetU8(script_offset + pointer + 2);
                    int jump     = GetU16LE(script_offset + pointer + 6);

                    LOGGER->Log("JumpIfRandomNot(1/0x%02x)(0x%04x);\n", value, jump);
                    pointer += 8;
                    continue;
                }



                switch (opcode)
                {
                    case 0x00:
                    case 0x01:
                    case 0x02:
                    case 0x03:
                    {
                        LOGGER->Log("0x%02x LoadValue(0x%04x)\n", opcode, GetU16LE(script_offset + pointer + 1));
                        pointer += 3;
                    }
                    break;

                    case 0x10:
                    case 0x11:
                    case 0x12:
                    case 0x13:
                    {
                        LOGGER->Log("0x%02x PushAddress(0x%04x)\n", opcode, GetU16LE(script_offset + pointer + 1));
                        pointer += 3;
                    }
                    break;

                    case 0x30:
                    {
                        LOGGER->Log("0x%02x MathAdd()\n", opcode);
                        pointer += 1;
                    }
                    break;

                    case 0x31:
                    {
                        LOGGER->Log("0x%02x MathSub()\n", opcode);
                        pointer += 1;
                    }
                    break;

                    case 0x32:
                    {
                        LOGGER->Log("0x%02x MathMul()\n", opcode);
                        pointer += 1;
                    }
                    break;

                    case 0x33:
                    {
                        LOGGER->Log("0x%02x MathDiv()\n", opcode);
                        pointer += 1;
                    }
                    break;


                    case 0x34:
                    {
                        LOGGER->Log("0x%02x MathMod()\n", opcode);
                        pointer += 1;
                    }
                    break;

                    case 0x35:
                    {
                        LOGGER->Log("0x%02x MathAnd()\n", opcode);
                        pointer += 1;
                    }
                    break;

                    case 0x36:
                    {
                        LOGGER->Log("0x%02x MathOr()\n", opcode);
                        pointer += 1;
                    }
                    break;

                    case 0x37:
                    {
                        LOGGER->Log("0x%02x MathNor()\n", opcode);
                        pointer += 1;
                    }
                    break;

                    case 0x40:
                    {
                        LOGGER->Log("0x%02x CompareEqual()\n", opcode);
                        pointer += 1;
                    }
                    break;

                    case 0x41:
                    {
                        LOGGER->Log("0x%02x CompareNotEqual()\n", opcode);
                        pointer += 1;
                    }
                    break;

                    case 0x42:
                    {
                        LOGGER->Log("0x%02x CompareGreaterEqual()\n", opcode);
                        pointer += 1;
                    }
                    break;

                    case 0x43:
                    {
                        LOGGER->Log("0x%02x CompareLessEqual()\n", opcode);
                        pointer += 1;
                    }
                    break;

                    case 0x44:
                    {
                        LOGGER->Log("0x%02x CompareGreater()\n", opcode);
                        pointer += 1;
                    }
                    break;

                    case 0x45:
                    {
                        LOGGER->Log("0x%02x CompareLess()\n", opcode);
                        pointer += 1;
                    }
                    break;

                    case 0x50:
                    {
                        LOGGER->Log("0x%02x LogAnd()\n", opcode);
                        pointer += 1;
                    }
                    break;

                    case 0x51:
                    {
                        LOGGER->Log("0x%02x LogOr()\n", opcode);
                        pointer += 1;
                    }
                    break;

                    case 0x52:
                    {
                        LOGGER->Log("0x%02x LogNot()\n", opcode);
                        pointer += 1;
                    }
                    break;

                    case 0x60:
                    {
                        u32 value = GetU8(script_offset + pointer + 1);
                        LOGGER->Log("0x%02x PushImmediate(0x%02x)\n", opcode, value);
                        pointer += 2;
                    }
                    break;

                    case 0x61:
                    {
                        u32 value = GetU8(script_offset + pointer + 1) | (GetU8(script_offset + pointer + 2) << 8);
                        LOGGER->Log("0x%02x PushImmediate(0x%04x)\n", opcode, value);
                        pointer += 3;
                    }
                    break;

                    case 0x70:
                    {
                        LOGGER->Log("0x%02x JumpIfFalse(0x%04x)\n", opcode, GetU16LE(script_offset + pointer + 1));
                        pointer += 3;
                    }
                    break;

                    case 0x71:
                    {
                        LOGGER->Log("0x%02x JumpIfNotEqual(0x%04x)\n", opcode, GetU16LE(script_offset + pointer + 1));
                        pointer += 3;
                    }
                    break;

                    case 0x72:
                    {
                        LOGGER->Log("0x%02x JumpTo(0x%04x)\n", opcode, GetU16LE(script_offset + pointer + 1));
                        pointer += 3;
                    }
                    break;

                    case 0x73:
                    {
                        LOGGER->Log("0x%02x FinishScript()\n", opcode);
                        run = false;
                        pointer += 1;
                    }
                    break;

                    case 0x75:
                    {
                        LOGGER->Log("0x%02x LinkScriptToOtherPlayer()\n", opcode);
                        pointer += 1;
                    }
                    break;

                    case 0x80:
                    {
                        LOGGER->Log("0x%02x FilterValueByMask()\n", opcode);
                        pointer += 1;
                    }
                    break;

                    case 0x81:
                    {
                        LOGGER->Log("0x%02x MathRandom()\n", opcode);
                        pointer += 1;
                    }
                    break;

                    case 0x82:
                    {
                        LOGGER->Log("0x%02x PickRandomBit()\n", opcode);
                        pointer += 1;
                    }
                    break;

                    case 0x83:
                    {
                        LOGGER->Log("0x%02x CountActiveBits()\n", opcode);
                        pointer += 1;
                    }
                    break;

                    case 0x84:
                    {
                        LOGGER->Log("0x%02x GetHighestMask()\n", opcode);
                        pointer += 1;
                    }
                    break;

                    case 0x85:
                    {
                        LOGGER->Log("0x%02x GetLowestMask()\n", opcode);
                        pointer += 1;
                    }
                    break;

                    case 0x86:
                    {
                        LOGGER->Log("0x%02x GetMPCost()\n", opcode);
                        pointer += 1;
                    }
                    break;

                    case 0x87:
                    {
                        LOGGER->Log("0x%02x SetBit()\n", opcode);
                        pointer += 1;
                    }
                    break;

                    case 0x90:
                    {
                        LOGGER->Log("0x%02x StoreValue()\n", opcode);
                        pointer += 1;
                    }
                    break;

                    case 0x91:
                    {
                        LOGGER->Log("0x%02x Pop()\n", opcode);
                        pointer += 1;
                    }
                    break;

                    case 0x92:
                    {
                        LOGGER->Log("0x%02x RunCommand()\n", opcode);
                        pointer += 1;
                    }
                    break;

                    case 0x93:
                    {
                        LOGGER->Log("0x%02x DisplayText(", opcode);
                        pointer += 1;

                        FFVIIString text;

                        unsigned char letter = GetU8(script_offset + pointer);
                        while (true)
                        {
                            if (letter == 0xea || letter == 0xeb || letter == 0xec || letter == 0xed || letter == 0xee || letter == 0xef || letter == 0xf0 || letter == 0xf1)
                            {
                                LOGGER->Log("[variable%02x", letter);
                                LOGGER->Log("%02x", GetU8(script_offset + pointer + 1));
                                LOGGER->Log("%02x]", GetU8(script_offset + pointer + 2));
                                pointer += 3;
                            }
                            else
                            {
                                LOGGER->Log("%02x", letter);
                                text.push_back(letter);
                                pointer += 1;

                                if (letter == 0xff)
                                {
                                    break;
                                }
                            }

                            letter = GetU8(script_offset + pointer);
                        }

                        RString r_text = FFVIIStringToRString(text);
                        LOGGER->Log(")(%s)\n", r_text.c_str());

                    }
                    break;

                    case 0x94:
                    {
                        LOGGER->Log("0x%02x CopyUnitsData()\n", opcode);
                        pointer += 1;
                    }
                    break;

                    case 0x95:
                    {
                        LOGGER->Log("0x%02x ExchangeByteWithMemory(800f83a4 + 2 <-> memorybank1/2)\n", opcode);
                        pointer += 1;
                    }
                    break;

                    case 0x96:
                    {
                        LOGGER->Log("0x%02x GetUnitsElementalDefense()\n", opcode);
                        pointer += 1;
                    }
                    break;

                    case 0xA0:
                    {
                        LOGGER->Log("0x%02x DebugTextOutput(", opcode);
                        pointer += 1;

                        unsigned char pop = GetU8(script_offset + pointer);
                        pointer += 1;

                        char letter[2];
                        letter[1] = 0;

                        letter[0] = GetU8(script_offset + pointer);
                        while (letter[0] != 0)
                        {
                            LOGGER->Log("%s", letter);
                            pointer += 1;

                            letter[0] = GetU8(script_offset + pointer);
                        }

                        pointer += 1;
                        LOGGER->Log(")(pop %d var from stack)\n", pop);

                    }
                    break;

                    default:
                    {
                        LOGGER->Log("0x%02x Unknown\n", opcode);
                        run = false;
                    }
                }
            }

            LOGGER->Log("\n", l);
        }
*/
        export_text->Log( "},\n\n\n" );
    }



//    <entity_model name="Background" file_name="models/battle/stages/reactor_1.mesh" position="0 0 0" direction="0" />

//    <entity_model name="Mp1" file_name="models/battle/units/mp.mesh" position="-5 2.5 0" direction="0" />
//    <entity_model name="Mp2" file_name="models/battle/units/mp.mesh" position="-5 2.5 0" direction="0" />

    int set_up_1_offset  = 0x0008;
    int set_up_2_offset  = 0x0058;
    int formation_offset = 0x0118;

    for( int k = 0 ; k < 4; ++k )
    {
        delete export_text;
        export_text = new Logger( "battle_" + IntToString( k ) + ".xml" );
        export_text->Log( "<map>\n" );
        export_text->Log( "    <entity_model name=\"Background\" file_name=\"models/ffvii/battle/stages/" + StageIdToFileName( GetU16LE( set_up_1_offset + k * 20 + 0x00 ) ) + ".mesh\" position=\"0 0 0\" direction=\"0\" />\n\n" );
/*

        LOGGER->Log("unknown: ");
        for (int l = 0; l < 18; ++l)
        {
            LOGGER->Log(" %02x", GetU8(set_up_1_offset + 0x02 + k * 20 + l));
        }
        LOGGER->Log("\n");
        LOGGER->Log("unknown: ");
        for (int l = 0; l < 48; ++l)
        {
            LOGGER->Log(" %02x", GetU8(set_up_2_offset + k * 48 + l));
        }
        LOGGER->Log("\n");
        LOGGER->Log("formation:\n");
*/
        for( int l = 0; l < 6; ++l )
        {
            Ogre::Vector3 position = Ogre::Vector3(
                ( s16 )GetU16LE( formation_offset + k * 96 + l * 16 + 0x02 ),
                ( s16 )GetU16LE( formation_offset + k * 96 + l * 16 + 0x06 ),
                ( s16 )GetU16LE( formation_offset + k * 96 + l * 16 + 0x04 )
            );
            position /= 512.0f;
            export_text->Log( "    <entity_model name=\"" + IntToString( ( s16 )GetU16LE( formation_offset + k * 96 + l * 16 + 0x00 ) ) + "\" file_name=\"models/ffvii/battle/stages/" + StageIdToFileName( GetU16LE( set_up_1_offset + k * 20 + 0x00 ) ) + ".mesh\" position=\"" + Ogre::StringConverter::toString( position ) + "\" direction=\"0\" />\n" );

/*
            xmlTextWriterWriteFormatAttribute(writer, BAD_CAST "row", "%d", GetU16LE(formation_offset + 0x08 + k * 96 + l * 16));
            xmlTextWriterEndElement(writer);

            int enemy_id = (Sint16)GetU16LE(formation_offset + 0x00 + k * 96 + l * 16);
            if (enemy_id != -1)
            {
                LOGGER->Log("Enemy Id %04d\t", (Sint16)GetU16LE(formation_offset + 0x00 + k * 96 + l * 16));
                LOGGER->Log("Position:");
                LOGGER->Log(" x(%04d)", (Sint16)GetU16LE(formation_offset + 0x02 + k * 96 + l * 16));
                LOGGER->Log(" y(%04d)", (Sint16)GetU16LE(formation_offset + 0x04 + k * 96 + l * 16));
                LOGGER->Log(" z(%04d)\t", (Sint16)GetU16LE(formation_offset + 0x06 + k * 96 + l * 16));
                LOGGER->Log("Row %d\t", (Sint16)GetU16LE(formation_offset + 0x08 + k * 96 + l * 16));
                LOGGER->Log("unknown: ");
                for (int l = 0; l < 6; ++l)
                {
                    LOGGER->Log(" %02x", GetU8(formation_offset + 0x0A + k * 96 + l * 16));
                }
                LOGGER->Log("\n");
            }
*/
        }
    }



    // attack names and id
    delete export_text;
    export_text = new Logger( "enemy_attacks.lua" );
    int attack_data         = 0x04c0;
    int attack_id_offset    = 0x0840;
    int attack_names_offset = 0x0880;

    for( int k = 0; k < 32; ++k )
    {
        int attack_id = GetU16LE( attack_id_offset + k * 0x02 );
        if( attack_id != 65535 )
        {
            FFVIIString name;
            name.resize(32);
            std::copy( m_Buffer + attack_names_offset + k * 0x20, m_Buffer + attack_names_offset + 0x20 + k * 0x20, name.begin() );

            export_text->Log( "-- " + Ogre::String( FFVIIStringToString( name ).c_str() ) + " (" + IntToString( GetU16LE( attack_id_offset + k * 0x02 ) ) + ")\n" );


            export_text->Log( Ogre::String( AttackIdToString( attack_id ) ) + " = {\n" );

            export_text->Log( "    mp_cost = " + IntToString( GetU16LE( attack_data + k * 0x1c + 0x04 ) ) + ",\n" );
            export_text->Log( "    power = " + FloatToString( GetU8( attack_data + k * 0x1c + 0x0f ) / 16.0f ) + ",\n" );
            export_text->Log( "    hit = " + IntToString( GetU8( attack_data + k * 0x1c + 0 ) ) + ",\n" );
            export_text->Log( "\n");
            export_text->Log( "    formula = \"0x" + HexToString( GetU8( attack_data + k * 0x1c + 0x0e ), 2, '0' ) + "\",\n" );
            export_text->Log( "    target = \"0x" + HexToString( GetU8( attack_data + k * 0x1c + 0x0c ), 2, '0' ) + "\",\n" );
            export_text->Log( "    additional_effect = \"0x" + HexToString( GetU8( attack_data + k * 0x1c + 0x12 ), 2, '0' ) + "\",\n" );
            export_text->Log( "    additional_effect_modifier = \"0x" + HexToString( GetU8( attack_data + k * 0x1c + 0x13 ), 2, '0' ) + "\",\n" );
            export_text->Log( "    special = \"0x" + HexToString( GetU16LE( attack_data + k * 0x1c + 0x1a ), 4, '0' ) + "\",\n" );
            export_text->Log( "\n");
            int restore_type = GetU8( attack_data + k * 0x1c + 0x10 );
            if( restore_type == 0 )
            {
                export_text->Log( "    restore_type = \"restore_hp\"\n\n" );
            }
            else if( restore_type == 1 )
            {
                export_text->Log( "    restore_type = \"restore_mp\"\n\n" );
            }
            else if( restore_type == 2 )
            {
                export_text->Log( "    restore_type = \"restore_status\"\n\n" );
            }

            u16 elements = GetU16LE( attack_data + k * 0x1c + 0x18 );
            export_text->Log( "    elements = {" );
            added = false;
            if( elements != 65535 )
            {
                for( int l = 0; l < 16; ++l )
                {
                    if( ( ( elements >> l ) & 1 ) != 0 )
                    {
                        added = true;
                        export_text->Log( "\n        " + ElementIdToString( l ) + "," );
                    }
                    if( added == true && l == 15 )
                    {
                        export_text->Log( "\n    " );
                    }
                }
            }
            export_text->Log( "},\n\n");

            u8 status_chance = GetU8( attack_data + k * 0x1c + 0x11 );
            u8 status_type = status_chance >> 6;
            status_chance = ( status_chance & 0x3f ) << 2;
            u32 status = GetU32LE( attack_data + k * 0x1c + 0x14 );
            if( status != 0xffffffff )
            {
                if( status_type == 0 )
                {
                    export_text->Log( "    status_add = {" );
                }
                else if( status_type == 1 )
                {
                    export_text->Log( "    status_remove = {" );
                }
                else if( status_type == 2 )
                {
                    export_text->Log( "    status_switch = {" );
                }

                for( int l = 0; l < 32; ++l )
                {
                    if( ( ( status >> l ) & 1 ) != 0 )
                    {
                        export_text->Log( "\n        " + StatusIdToString( l ) + "," );
                    }
                    if( l == 31 )
                    {
                        export_text->Log( "\n    " );
                    }
                }

                export_text->Log( "},\n\n");
            }

            export_text->Log( "    target_hurt_script_id = " + IntToString( GetU8( attack_data + k * 0x1c + 0x02 ) ) + ",\n" );

            int sound_id = GetU16LE( attack_data + k * 0x1c + 6 );
            if( sound_id != 65535 )
            {
                export_text->Log( "    sound_id_normal = " + IntToString( sound_id ) + ",\n" );
                export_text->Log( "    sound_id_cricical = " + IntToString( sound_id ) + ",\n" );
                export_text->Log( "    sound_id_miss = " + IntToString( sound_id ) + ",\n" );
            }

            int attack_effect_id = GetU8( attack_data + k * 0x1c + 0x0d );
            if( attack_effect_id != 255 )
            {
                export_text->Log( "    attack_effect_id = " + IntToString( attack_effect_id ) + ",\n" );
            }

            int impact_effect_id = GetU8( attack_data + k * 0x1c + 0x01 );
            if( impact_effect_id != 255 )
            {
                export_text->Log( "    impact_effect_id = " + IntToString( impact_effect_id ) + ",\n" );
            }

            int camera_id = GetU16LE( attack_data + k * 0x1c + 0x08 );
            if( camera_id != 65535 )
            {
                export_text->Log( "    camera_id_single = " + IntToString( camera_id ) + ",\n" );
            }

            camera_id = GetU16LE( attack_data + k * 0x1c + 0x0a );
            if( camera_id != 65535 )
            {
                export_text->Log( "    camera_id_multiple = " + IntToString( camera_id ) + ",\n" );
            }

            export_text->Log( "},\n\n\n" );
        }
    }
}
