#include "WalkmeshFile.h"



WalkmeshFile::WalkmeshFile(const std::string &file):
    File(*GAMEFILESYSTEM, file)
{
}



WalkmeshFile::WalkmeshFile(File *file):
    File(file)
{
}



WalkmeshFile::~WalkmeshFile()
{
}



void
WalkmeshFile::GetWalkmesh(Walkmesh* walkmesh)
{
    // numbers of subblock
    u32 block_count = GetU32LE(0);
    u32 start = 0x04;

    for (u32 i = 0; i < block_count; ++i)
    {
        u32 block_size   = GetU32LE(start + i * 0x04);
        u32 block_start  = GetU32LE(start + 0x14 + i * 0x08);
        u32 block_vertex = GetU32LE(start + 0x14 + i * 0x08 + 0x04);

        for (u32 i = 0; i < block_size;)
        {
            u16 a_offset = static_cast<u16>(block_vertex + GetU16LE(block_start + i + 0x00) * 0x08);
            u16 b_offset = static_cast<u16>(block_vertex + GetU16LE(block_start + i + 0x02) * 0x08);
            u16 c_offset = static_cast<u16>(block_vertex + GetU16LE(block_start + i + 0x04) * 0x08);

            WalkmeshTriangle triangle;
            triangle.a = Ogre::Vector3((s16)GetU16LE(0x00 + a_offset),
                                       (s16)GetU16LE(0x02 + a_offset),
                                       (s16)GetU16LE(0x04 + a_offset));
            triangle.b = Ogre::Vector3((s16)GetU16LE(0x00 + b_offset),
                                       (s16)GetU16LE(0x02 + b_offset),
                                       (s16)GetU16LE(0x04 + b_offset));
            triangle.c = Ogre::Vector3((s16)GetU16LE(0x00 + c_offset),
                                       (s16)GetU16LE(0x02 + c_offset),
                                       (s16)GetU16LE(0x04 + c_offset));

            triangle.access_side[0] = (s16)GetU16LE(block_start + i + 0x06);
            triangle.access_side[1] = (s16)GetU16LE(block_start + i + 0x08);
            triangle.access_side[2] = (s16)GetU16LE(block_start + i + 0x0a);

            triangle.unknown1 = GetU8(block_start + i + 0x0c);
            triangle.unknown2 = GetU8(block_start + i + 0x0d);

            walkmesh->AddTriangle(triangle);

            i += 0x0E;
        }
    }
}
