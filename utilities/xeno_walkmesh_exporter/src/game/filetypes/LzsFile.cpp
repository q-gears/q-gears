// $Id: LzsFile.cpp 147 2007-02-24 06:13:17Z super_gb $

#include "LzsFile.h"

#include "../../common/filesystem/GameFileSystem.h"
#include "../../common/utilites/Logger.h"


LzsFile::LzsFile(const RString& file):
    File(*GAMEFILESYSTEM, file)
{
    ExtractLzs();
}



LzsFile::LzsFile(File* pFile, const u32& offset, const u32& length):
    File(pFile, offset, length)
{
    ExtractLzs();
}



LzsFile::LzsFile(u8* pBuffer, const u32& offset, const u32& length):
    File(pBuffer, offset, length)
{
    ExtractLzs();
}



LzsFile::LzsFile(File* pFile):
    File(pFile)
{
    ExtractLzs();
}



LzsFile::~LzsFile(void)
{
}



void
LzsFile::ExtractLzs(void)
{
    u32 input_length = GetU32LE(0) + 4;

    if (input_length != mBufferSize)
    {
        LOGGER->Log(LOGGER_WARNING,
			"Warning: extract failed, this is not lzs!");
//        return;
    }



    u32 extract_size = (mBufferSize + 255) & ~255;
    u8* extract_buffer = (u8*)malloc(extract_size);



    u32 input_offset = 4;
    int output_offset = 0;
    u8 control_byte = 0;
    u8 control_bit = 0;

    while (input_offset < mBufferSize)
    {
        if (control_bit == 0)
        {
            control_byte = ((u8*)mpBuffer)[input_offset++];
            control_bit = 8;
        }

        if (control_byte & 1)
        {
            ((u8*)extract_buffer)[output_offset++] = ((u8*)mpBuffer)[input_offset++];

            if (output_offset == extract_size)
            {
                extract_size += 256;
                extract_buffer = (u8*)realloc(extract_buffer, extract_size);
            }
        }
        else
        {
            u8 reference1 = ((u8*)mpBuffer)[input_offset++];
            u8 reference2 = ((u8*)mpBuffer)[input_offset++];

            u16 reference_offset = reference1 | ((reference2 & 0xF0) << 4);

            u8 reference_length = (reference2 & 0xF) + 3;

            int real_offset = output_offset - ((output_offset - 18 - reference_offset) & 0xFFF);

            for (int j = 0; j < reference_length; ++j)
            {
                if (real_offset < 0)
                {
                    ((u8*)extract_buffer)[output_offset++] = 0;
                }
                else
                {
                    ((u8*)extract_buffer)[output_offset++] = ((u8*)extract_buffer)[real_offset];
                }

                if (output_offset == extract_size)
                {
                    extract_size += 256;
                    extract_buffer = (u8*)realloc(extract_buffer, extract_size);
                }

                ++real_offset;
            }
        }

        control_byte >>= 1;
        control_bit--;
    }

    free(mpBuffer);
    // the real buffer size and mBufferSize will be a bit different
    mpBuffer = extract_buffer;
    mBufferSize = output_offset;
}
