#include "EnemyFile.h"

#include <libxml/xmlwriter.h>

#include "FFVIIString.h"
#include "../../common/Logger.h"

xmlTextWriterPtr writer;



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
    writer = xmlNewTextWriterFilename("enemy.xml", 0);
    xmlTextWriterSetIndent(writer, 1);
    xmlTextWriterSetIndentString(writer, BAD_CAST "    ");
    xmlTextWriterStartDocument(writer, NULL, "ISO-8859-1", NULL);
    xmlTextWriterStartElement(writer, BAD_CAST "enemies");

    LOGGER->Log("Enemy Id and Data\n");
    int enemy_data_offset = 0x0298;
    int enemy_ai_offset   = 0x0E80;
    for (int k = 0 ; k < 3; ++k)
    {
        if (GetU16LE(k * 0x02) == 0xffff)
        {
            continue;
        }

        FFVIIString name;
        name.resize(32);
        std::copy(mpBuffer + enemy_data_offset + k * 184, mpBuffer + enemy_data_offset + 0x20 + k * 184, name.begin());
        RString r_name = FFVIIStringToRString(name);
        LOGGER->Log("%02d) ", k + 1);
        LOGGER->Log("ID %04d: ", GetU16LE(k * 0x02));
        LOGGER->Log("%s\n", r_name.c_str());

        LOGGER->Log("level            %02d\n", GetU8(enemy_data_offset + 0x20 + k * 184));
        LOGGER->Log("speed            %02d\n", GetU8(enemy_data_offset + 0x21 + k * 184));
        LOGGER->Log("luck             %02d\n", GetU8(enemy_data_offset + 0x22 + k * 184));
        LOGGER->Log("physical dodge   %02d\n", GetU8(enemy_data_offset + 0x23 + k * 184));
        LOGGER->Log("strength         %02d\n", GetU8(enemy_data_offset + 0x24 + k * 184));
        LOGGER->Log("physical defense %02d\n", GetU8(enemy_data_offset + 0x25 + k * 184));
        LOGGER->Log("magic power      %02d\n", GetU8(enemy_data_offset + 0x26 + k * 184));
        LOGGER->Log("magic defense    %02d\n", GetU8(enemy_data_offset + 0x27 + k * 184));
        LOGGER->Log("element id's:");
        for (int l = 0; l < 8; ++l)
        {
            LOGGER->Log(" %03d", GetU8(enemy_data_offset + 0x28 + k * 184 + l));
        }
        LOGGER->Log("\n");
        LOGGER->Log("effects:     ");
        for (int l = 0; l < 8; ++l)
        {
            LOGGER->Log(" %03d", GetU8(enemy_data_offset + 0x30 + k * 184 + l));
        }
        LOGGER->Log("\n");
        LOGGER->Log("action id: ");
        for (int l = 0; l < 16; ++l)
        {
            LOGGER->Log(" %02x", GetU8(enemy_data_offset + 0x38 + k * 184 + l));
        }
        LOGGER->Log("\n");
        LOGGER->Log("attack id: ");
        for (int l = 0; l < 16; ++l)
        {
            LOGGER->Log(" %04d", (Sint16)GetU16LE(enemy_data_offset + 0x48 + k * 184 + l * 0x02));
        }
        LOGGER->Log("\n");
        LOGGER->Log("camera movement: ");
        for (int l = 0; l < 16; ++l)
        {
            LOGGER->Log(" %04d", (Sint16)GetU16LE(enemy_data_offset + 0x68 + k * 184 + l * 0x02));
        }
        LOGGER->Log("\n");
        LOGGER->Log("drop/stole rates:");
        for (int l = 0; l < 4; ++l)
        {
            LOGGER->Log("   %02x", GetU8(enemy_data_offset + 0x88 + k * 184 + l));
        }
        LOGGER->Log("\n");
        LOGGER->Log("drop/stole items:");
        for (int l = 0; l < 4; ++l)
        {
            LOGGER->Log(" %04d", (Sint16)GetU16LE(enemy_data_offset + 0x8C + k * 184 + l * 0x02));
        }
        LOGGER->Log("\n");
        LOGGER->Log("manipulate attacks id: ");
        for (int l = 0; l < 4; ++l)
        {
            LOGGER->Log(" %04d", (Sint16)GetU16LE(enemy_data_offset + 0x94 + k * 184 + l * 0x02));
        }
        LOGGER->Log("\n");
        LOGGER->Log("MP: %04d\n", (Sint16)GetU16LE(enemy_data_offset + 0x9C + k * 184));
        LOGGER->Log("AP: %04d\n", (Sint16)GetU16LE(enemy_data_offset + 0x9E + k * 184));
        LOGGER->Log("Morph item id: %04d\n", (Sint16)GetU16LE(enemy_data_offset + 0xA0 + k * 184));
        LOGGER->Log("Damage From Back multiplied by: %d%/8\n", GetU8(enemy_data_offset + 0xA2 + k * 184));
        LOGGER->Log("Unknown: %02x\n", GetU8(enemy_data_offset + 0xA3 + k * 184));
        LOGGER->Log("HP: %05d\n", GetU32LE(enemy_data_offset + 0xA4 + k * 184));
        LOGGER->Log("EXP: %05d\n", GetU32LE(enemy_data_offset + 0xA8 + k * 184));
        LOGGER->Log("GIL: %05d\n", GetU32LE(enemy_data_offset + 0xAC + k * 184));
        LOGGER->Log("Immune mask: %08x\n", GetU32LE(enemy_data_offset + 0xB0 + k * 184));
        LOGGER->Log("unknown: ");
        for (int l = 0; l < 4; ++l)
        {
            LOGGER->Log(" %02x", GetU8(enemy_data_offset + 0xB4 + k * 184 + l));
        }
        LOGGER->Log("\n");
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
        LOGGER->Log("\n\n\n");



        xmlTextWriterStartElement(writer, BAD_CAST "enemy");
        xmlTextWriterWriteFormatAttribute(writer, BAD_CAST "id", "%d", (Sint16)GetU16LE(k * 0x02));
        r_name.MakeLower().Replace(" ", "_");
        xmlTextWriterWriteFormatAttribute(writer, BAD_CAST "file_name", "enemy/%s.lua", r_name.c_str());
        xmlTextWriterEndElement(writer);
    }

    xmlTextWriterEndElement(writer);
    xmlTextWriterEndDocument(writer);
    xmlFreeTextWriter(writer);



    LOGGER->Log("\n\n");



    writer = xmlNewTextWriterFilename("battle.xml", 0);
    xmlTextWriterSetIndent(writer, 1);
    xmlTextWriterSetIndentString(writer, BAD_CAST "    ");
    xmlTextWriterStartDocument(writer, NULL, "ISO-8859-1", NULL);
    xmlTextWriterStartElement(writer, BAD_CAST "battles");

    LOGGER->Log("Formation\n");
    int set_up_1_offset  = 0x0008;
    int set_up_2_offset  = 0x0058;
    int formation_offset = 0x0118;
    for (int k = 0 ; k < 4; ++k)
    {
        xmlTextWriterStartElement(writer, BAD_CAST "battle");
        xmlTextWriterWriteFormatAttribute(writer, BAD_CAST "id", "%d", 0);
        xmlTextWriterWriteFormatAttribute(writer, BAD_CAST "map_id", "%d", (Sint16)GetU16LE(set_up_1_offset + 0x00 + k * 20));



        LOGGER->Log("%02d)\n", k + 1);
        LOGGER->Log("Location ID %04d\n", (Sint16)GetU16LE(set_up_1_offset + 0x00 + k * 20));
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
        for (int l = 0; l < 6; ++l)
        {
            xmlTextWriterStartElement(writer, BAD_CAST "formation");
            xmlTextWriterWriteFormatAttribute(writer, BAD_CAST "enemy_id", "%d", (Sint16)GetU16LE(formation_offset + 0x00 + k * 96 + l * 16));
            xmlTextWriterWriteFormatAttribute(writer, BAD_CAST "position", "%d %d %d", (Sint16)GetU16LE(formation_offset + 0x02 + k * 96 + l * 16), (Sint16)GetU16LE(formation_offset + 0x04 + k * 96 + l * 16), (Sint16)GetU16LE(formation_offset + 0x06 + k * 96 + l * 16));
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
        }

        LOGGER->Log("\n");



        xmlTextWriterEndElement(writer);
        xmlTextWriterWriteRaw(writer, BAD_CAST "\n");
    }

    xmlTextWriterEndElement(writer);
    xmlTextWriterEndDocument(writer);
    xmlFreeTextWriter(writer);



    LOGGER->Log("\n\n\n");



    // attack names and id
    LOGGER->Log("Attack Id and Names\n");
    int attack_data         = 0x04C0;
    int attack_id_offset    = 0x0840;
    int attack_names_offset = 0x0880;

    for (int k = 0; k < 32; ++k)
    {
        FFVIIString name;
        name.resize(32);
        std::copy(mpBuffer + attack_names_offset + k * 0x20, mpBuffer + attack_names_offset + 0x20 + k * 0x20, name.begin());
        LOGGER->Log("%02d) ", k + 1);
        LOGGER->Log("ID %05d: ", GetU16LE(attack_id_offset + k * 0x02));
        LOGGER->Log("%02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x ",
                    GetU8(attack_data + k * 0x1C + 0),
                    GetU8(attack_data + k * 0x1C + 1),
                    GetU8(attack_data + k * 0x1C + 2),
                    GetU8(attack_data + k * 0x1C + 3),
                    GetU8(attack_data + k * 0x1C + 4),
                    GetU8(attack_data + k * 0x1C + 5),
                    GetU8(attack_data + k * 0x1C + 6),
                    GetU8(attack_data + k * 0x1C + 7),
                    GetU8(attack_data + k * 0x1C + 8),
                    GetU8(attack_data + k * 0x1C + 9),
                    GetU8(attack_data + k * 0x1C + 10),
                    GetU8(attack_data + k * 0x1C + 11),
                    GetU8(attack_data + k * 0x1C + 12),
                    GetU8(attack_data + k * 0x1C + 13),
                    GetU8(attack_data + k * 0x1C + 14),
                    GetU8(attack_data + k * 0x1C + 15),
                    GetU8(attack_data + k * 0x1C + 16),
                    GetU8(attack_data + k * 0x1C + 17),
                    GetU8(attack_data + k * 0x1C + 18),
                    GetU8(attack_data + k * 0x1C + 19),
                    GetU8(attack_data + k * 0x1C + 20),
                    GetU8(attack_data + k * 0x1C + 21),
                    GetU8(attack_data + k * 0x1C + 22),
                    GetU8(attack_data + k * 0x1C + 23),
                    GetU8(attack_data + k * 0x1C + 24),
                    GetU8(attack_data + k * 0x1C + 25),
                    GetU8(attack_data + k * 0x1C + 26),
                    GetU8(attack_data + k * 0x1C + 27));
        LOGGER->Log("%s\n", FFVIIStringToRString(name).c_str());
    }
}
