#include "PlayerFile.h"

#include "FFVIIString.h"
#include "../../common/Logger.h"



PlayerFile::PlayerFile( const Ogre::String &file ):
    File( file )
{
    DumpData();
}



PlayerFile::PlayerFile( File *file, const u32 &offset, const u32 &length ):
    File( file, offset, length )
{
    DumpData();
}



PlayerFile::PlayerFile( u8* buffer, const u32 &offset, const u32 &length ):
    File( buffer, offset, length )
{
    DumpData();
}



PlayerFile::PlayerFile( File *file ):
    File( file )
{
    DumpData();
}



PlayerFile::~PlayerFile()
{
}



void
PlayerFile::DumpData()
{
/*
    for (int i = 0; i < 12; ++i)
    {
        int ai_offset = GetU16LE(i * 2);
        if (ai_offset == 0xffff)
        {
            continue;
        }
        LOGGER->Log("PLAYER %x:\n", i);

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
    }
*/
}
