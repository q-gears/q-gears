#include "LzsFile.h"

#include "Logger.h"



LzsFile::LzsFile(const Ogre::String& file):
    File(file)
{
    ExtractLzs();
}



LzsFile::LzsFile(File* pFile, u32 offset, u32 length):
    File(pFile, offset, length)
{
    ExtractLzs();
}



LzsFile::LzsFile(u8* pBuffer, u32 offset, u32 length):
    File(pBuffer, offset, length)
{
    ExtractLzs();
}



LzsFile::LzsFile(File* pFile):
    File(pFile)
{
    ExtractLzs();
}



LzsFile::~LzsFile()
{
}



void
LzsFile::ExtractLzs()
{
    u32 input_length = GetU32LE(0) + 4;

    if (input_length != m_BufferSize)
    {
        LOGGER->Log("Warning: extract failed, this is not lzs!\n");
        return;
    }



    u32 extract_size = (m_BufferSize + 255) & ~255;
    u8* extract_buffer = (u8*)malloc(extract_size);



    int input_offset = 4;
    int output_offset = 0;
    u8 control_byte = 0;
    u8 control_bit = 0;

    while (input_offset < m_BufferSize)
    {
        if (control_bit == 0)
        {
            control_byte = ((u8*)m_Buffer)[input_offset++];
            control_bit = 8;
        }

        if (control_byte & 1)
        {
            ((u8*)extract_buffer)[output_offset++] = ((u8*)m_Buffer)[input_offset++];

            if (output_offset == extract_size)
            {
                extract_size += 256;
                extract_buffer = (u8*)realloc(extract_buffer, extract_size);
            }
        }
        else
        {
            u8 reference1 = ((u8*)m_Buffer)[input_offset++];
            u8 reference2 = ((u8*)m_Buffer)[input_offset++];

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

    free(m_Buffer);
    // the real buffer size and mBufferSize will be a bit different
    m_Buffer = extract_buffer;
    m_BufferSize = output_offset;
}
