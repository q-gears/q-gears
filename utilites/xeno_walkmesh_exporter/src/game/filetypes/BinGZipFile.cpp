// $Id: BinGZipFile.cpp 147 2007-02-24 06:13:17Z super_gb $

#include <cassert>
#include <zlib.h>

#include "../../common/filesystem/GameFileSystem.h"
#include "../../common/utilites/Logger.h"

#include "BinGZipFile.h"



/////////////////////////////// PUBLIC ///////////////////////////////////////

//============================= LIFECYCLE ====================================

BinGZipFile::BinGZipFile(const RString& file):
    File(*GAMEFILESYSTEM, file),
    mNumberOfFiles(0)
{
    InnerGetNumberOfFiles();
}



BinGZipFile::BinGZipFile(File* pFile):
    File(pFile),
    mNumberOfFiles(0)
{
    InnerGetNumberOfFiles();
}



BinGZipFile::BinGZipFile(File* pFile, const u32& offset, const u32& length):
    File(pFile, offset, length),
    mNumberOfFiles(0)
{
    InnerGetNumberOfFiles();
}



BinGZipFile::BinGZipFile(u8* pBuffer, const u32& offset, const u32& length):
    File(pBuffer, offset, length),
    mNumberOfFiles(0)
{
    InnerGetNumberOfFiles();
}



BinGZipFile::~BinGZipFile(void)
{
}



//============================= OPERATIONS ===================================

File*
BinGZipFile::ExtractGZip(const u32& fileNumber)
{
    if (fileNumber >= mNumberOfFiles)
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
    strm.next_in   = mpBuffer + offset;     /* next input byte */
    strm.avail_in  = mBufferSize;          /* number of bytes available at next_in */
    strm.next_out  = extract_buffer;       /* next output byte should be put there */
    strm.avail_out = extract_size;         /* remaining free space at next_out */

    ret = inflateInit2(&strm, 15 + 32);

    if (ret != Z_OK)
    {
        switch (ret)
        {
            case Z_MEM_ERROR:
                inflateEnd(&strm);
                LOGGER->Log(LOGGER_WARNING,
					"Warning: inflateInit2 - Z_MEM_ERROR in file %s",
					mFileName.c_str());
                break;
            case Z_STREAM_ERROR:
                inflateEnd(&strm);
                LOGGER->Log(LOGGER_WARNING,
					"Warning: inflateInit2 - Z_STREAM_ERROR in file %s",
					mFileName.c_str());
                break;
            default:
                inflateEnd(&strm);
                LOGGER->Log(LOGGER_WARNING,
					"Warning: inflateInit2 - unknown error in file %s",
					mFileName.c_str());
        }
        return NULL;
    }

    do
    {
        if (strm.next_out == NULL)
        {
            inflateEnd(&strm);
            LOGGER->Log(LOGGER_WARNING,
				"Warning: strm.next_out == NULL in file %s", mFileName.c_str());
            return NULL;
        }

        ret = inflate(&strm, Z_NO_FLUSH);
        assert(ret != Z_STREAM_ERROR);

        switch (ret)
        {
            case Z_NEED_DICT:
                inflateEnd(&strm);
                LOGGER->Log(LOGGER_WARNING,
					"Warning: inflate - Z_NEED_DICT in file %s",
					mFileName.c_str());
                return NULL;
            case Z_DATA_ERROR:
                inflateEnd(&strm);
                LOGGER->Log(LOGGER_WARNING,
					"Warning: inflate - Z_DATA_ERROR in file %s",
					mFileName.c_str());
                return NULL;
            case Z_MEM_ERROR:
                inflateEnd(&strm);
                LOGGER->Log(LOGGER_WARNING,
					"Warning: inflate - Z_MEM_ERROR in file %s",
					mFileName.c_str());
                return NULL;
        }

        if (ret != Z_STREAM_END)
        {
            extract_buffer = (u8*)realloc(extract_buffer, extract_size * 2);

            if (extract_buffer == NULL)
            {
                inflateEnd(&strm);
                LOGGER->Log(LOGGER_WARNING,
					"Warning: extract_buffer == NULL in file %s",
					mFileName.c_str());
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
        LOGGER->Log(LOGGER_WARNING,
			"Warning: ret != Z_STREAM_END in file %s", mFileName.c_str());
        return NULL;
    }

    File* file = new File(extract_buffer, 0, extract_size);
    free(extract_buffer);
    return file;
}



//============================= ACCESS     ===================================

const u32&
BinGZipFile::GetNumberOfFiles(void)
{
    return mNumberOfFiles;
}



/////////////////////////////// PROTECTED  ///////////////////////////////////

//============================= OPERATIONS ===================================

void
BinGZipFile::InnerGetNumberOfFiles(void)
{
    mNumberOfFiles = 0;

    for (u32 pointer = 0; pointer < mBufferSize;)
    {
        u16 temp = GetU16LE(pointer);
        pointer += 6;

        // condition for gzip header
        if (GetU32LE(pointer) == 0x00088B1F && GetU32LE(pointer + 4) == 0x00000000)
        {
            ++mNumberOfFiles;
        }

        pointer += temp;
    }

    if (mNumberOfFiles == 0)
    {
        LOGGER->Log(LOGGER_WARNING,
			"Warning: %s isn't archive. number_of_files == 0",
			mFileName.c_str());
    }
}



u32
BinGZipFile::InnerGetFileOffset(const u32& fileNumber)
{
    if (fileNumber >= mNumberOfFiles)
    {
        return 0;
    }

    u32 current_file = 0;

    for (u32 pointer = 0; pointer < mBufferSize;)
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
