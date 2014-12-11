// $Id: ArchiveFile.cpp 96 2006-11-13 03:34:17Z crazy_otaku $

#include "../../common/utilites/Logger.h"

#include "../../common/filesystem/RealFileSystem.h"
#include "ArchiveFile.h"



/////////////////////////////// PUBLIC ///////////////////////////////////////

//============================= LIFECYCLE ====================================

ArchiveFile::ArchiveFile(const RString& file):
    File(*REALFILESYSTEM, file)
{
    Extract();
}



ArchiveFile::ArchiveFile(File* pFile):
    File(pFile)
{
    Extract();
}



ArchiveFile::ArchiveFile(File* pFile, const u32& offset, const u32& length):
    File(pFile, offset, length)
{
    Extract();
}



ArchiveFile::ArchiveFile(u8* pBuffer, const u32& offset, const u32& length):
    File(pBuffer, offset, length)
{
    Extract();
}



ArchiveFile::~ArchiveFile(void)
{
}



//============================= OPERATIONS ===================================

void
ArchiveFile::Extract(void)
{
    u16 circle_size = 4096;
    u16 F = 18;

    u8 circle_buffer[4096];
    int r = 0;
    for (u16 i = 0; i < circle_size - F; i++)
    {
        circle_buffer[i] = 0;
    }
    r = circle_size - F;

    // current position in mpBuffer (compressed)
    u32 comp_position = 0;

    u32 decomp_length = GetU32LE(comp_position);
    comp_position += 0x04;
    u8 *decomp_buffer = (u8 *)malloc(sizeof(u8) * decomp_length);

    // current position in decomp_buffer
    u32 decomp_position = 0;

    // decompression
    while (decomp_position < decomp_length)
    {
        // Control byte
        u8 control_byte = GetU8(comp_position++);

        for (u8 shift = 0; shift < 8; shift++)
        {
            if ((control_byte & (1 << shift)) == 0)
            {
                // not compressed
                // copy byte in circle burrer and in decomp_buffer
                u8 temp = GetU8(comp_position++);
                decomp_buffer[decomp_position++] = temp;
                circle_buffer[r++]               = temp;
                r &= circle_size - 1;
            }
            else
            {
                // compressed
                // get 2 bytes
                u8 reference1 = GetU8(comp_position++);
                u8 reference2 = GetU8(comp_position++);
                // offset for circle_buffer
                u16 reference_offset = reference1 | ((reference2 & 0x0F) << 8);
                // length are always lesser than real by 3
                u8 reference_length = ((reference2 & 0xF0) >> 4) + 3;

                // copy bytes
                for (u32 i = 0; i < reference_length; i++)
                {
                    u8 temp = circle_buffer[(r - reference_offset) & (circle_size - 1)];
                    decomp_buffer[decomp_position++] = temp;
                    circle_buffer[r++]               = temp;
                    r &= circle_size - 1;
                }
            }
        }
    }

    free(mpBuffer);
    mpBuffer = decomp_buffer;
    mBufferSize = decomp_length;
}
