#include <cassert>
#include <zlib.h>

#include "Logger.h"
#include "BinGZipFile.h"



BinGZipFile::BinGZipFile(const Ogre::String& file):
    File(file),
    m_NumberOfFiles(0)
{
    InnerGetNumberOfFiles();
}



BinGZipFile::BinGZipFile(File* pFile):
    File(pFile),
    m_NumberOfFiles(0)
{
    InnerGetNumberOfFiles();
}



BinGZipFile::BinGZipFile(File* pFile, u32 offset, u32 length):
    File(pFile, offset, length),
    m_NumberOfFiles(0)
{
    InnerGetNumberOfFiles();
}



BinGZipFile::BinGZipFile(u8* pBuffer, u32 offset, u32 length):
    File(pBuffer, offset, length),
    m_NumberOfFiles(0)
{
    InnerGetNumberOfFiles();
}



BinGZipFile::~BinGZipFile()
{
}



File*
BinGZipFile::ExtractGZip(u32 fileNumber)
{
    if (fileNumber >= m_NumberOfFiles)
    {
        return NULL;
    }

    u32 extract_size = 256 * 1024;
    u8* extract_buffer = (u8*)malloc(extract_size);

    int ret;
    z_stream strm;

    u32 offset = InnerGetFileOffset(fileNumber);

    strm.zalloc    = Z_NULL;               /* used to allocate the internal state */
    strm.zfree     = Z_NULL;               /* used to free the internal state */
    strm.opaque    = Z_NULL;               /* private data object passed to zalloc and zfree */
    strm.next_in   = m_Buffer + offset;     /* next input byte */
    strm.avail_in  = m_BufferSize;          /* number of bytes available at next_in */
    strm.next_out  = extract_buffer;       /* next output byte should be put there */
    strm.avail_out = extract_size;         /* remaining free space at next_out */

    ret = inflateInit2(&strm, 15 + 32);

    if (ret != Z_OK)
    {
        switch (ret)
        {
            case Z_MEM_ERROR:
                inflateEnd(&strm);
                LOGGER->Log("Warning: inflateInit2 - Z_MEM_ERROR in file " + m_FileName);
                break;
            case Z_STREAM_ERROR:
                inflateEnd(&strm);
                LOGGER->Log("Warning: inflateInit2 - Z_STREAM_ERROR in file " + m_FileName);
                break;
            default:
                inflateEnd(&strm);
                LOGGER->Log("Warning: inflateInit2 - unknown error in file " + m_FileName);
        }
        return NULL;
    }

    do
    {
        if (strm.next_out == NULL)
        {
            inflateEnd(&strm);
            LOGGER->Log("Warning: strm.next_out == NULL in file " + m_FileName);
            return NULL;
        }

        ret = inflate(&strm, Z_NO_FLUSH);
        assert(ret != Z_STREAM_ERROR);

        switch (ret)
        {
            case Z_NEED_DICT:
                inflateEnd(&strm);
                LOGGER->Log("Warning: inflate - Z_NEED_DICT in file " + m_FileName);
                return NULL;
            case Z_DATA_ERROR:
                inflateEnd(&strm);
                LOGGER->Log("Warning: inflate - Z_DATA_ERROR in file " + m_FileName);
                return NULL;
            case Z_MEM_ERROR:
                inflateEnd(&strm);
                LOGGER->Log("Warning: inflate - Z_MEM_ERROR in file " + m_FileName);
                return NULL;
        }

        if (ret != Z_STREAM_END)
        {
            extract_buffer = (u8*)realloc(extract_buffer, extract_size * 2);

            if (extract_buffer == NULL)
            {
                inflateEnd(&strm);
                LOGGER->Log("Warning: extract_buffer == NULL in file " + m_FileName);
                return NULL;
            }

            strm.next_out = (u8*)extract_buffer + extract_size;
            strm.avail_out = extract_size;
            extract_size *= 2;
        }
    }
    while (ret != Z_STREAM_END);

    extract_size = extract_size - strm.avail_out;
    (void)inflateEnd(&strm);

    if (ret != Z_STREAM_END)
    {
        LOGGER->Log("Warning: ret != Z_STREAM_END in file " + m_FileName);
        return NULL;
    }

    File* file = new File(extract_buffer, 0, extract_size);
    free(extract_buffer);
    return file;
}



u32
BinGZipFile::GetNumberOfFiles()
{
    return m_NumberOfFiles;
}



void
BinGZipFile::InnerGetNumberOfFiles()
{
    m_NumberOfFiles = 0;

    for (u32 pointer = 0; pointer < m_BufferSize;)
    {
        u16 temp = GetU16LE(pointer);
        pointer += 6;

        // condition for gzip header
        if (GetU32LE(pointer) == 0x00088B1F && GetU32LE(pointer + 4) == 0x00000000)
        {
            ++m_NumberOfFiles;
        }

        pointer += temp;
    }

    if (m_NumberOfFiles == 0)
    {
        LOGGER->Log("Warning: " + m_FileName + " isn't archive. number_of_files == 0");
    }
}



u32
BinGZipFile::InnerGetFileOffset(u32 fileNumber)
{
    if (fileNumber >= m_NumberOfFiles)
    {
        return 0;
    }

    u32 current_file = 0;

    for (u32 pointer = 0; pointer < m_BufferSize;)
    {
        u16 temp = GetU16LE(pointer);
        pointer += 6;

        // condition for gzip header
        if (GetU32LE(pointer) == 0x00088B1F && GetU32LE(pointer + 4) == 0x00000000)
        {
            if (fileNumber == current_file)
            {
                return pointer;
            }
        }

        ++current_file;
        pointer += temp;
    }

    return 0;
}
