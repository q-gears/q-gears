// $Id: File.cpp 147 2007-02-24 06:13:17Z super_gb $

#include <cassert>
#include <cstring>

#include "../../common/filesystem/FileSystem.h"
#include "../../common/filesystem/RealFileSystem.h"
#include "../../common/utilites/Logger.h"

#include "File.h"



File::File(FileSystem &fs, const RString& file):
  mFileName(file),
  mpBuffer(NULL),
  mBufferSize(0)
{
    LOGGER->Log("Loading file: %s", mFileName.c_str());
    mBufferSize = fs.GetFileSize(mFileName);

    mpBuffer = (u8*)malloc(sizeof(u8) * mBufferSize);

    if (!fs.ReadFile(mFileName, mpBuffer, 0, mBufferSize))
    {
        LOGGER->Log("Warning: %s not found!", mFileName.c_str());
    }
}



File::File(File* pFile, const u32& offset, const u32& length):
  mpBuffer(NULL),
  mBufferSize(length)
{
    assert(pFile != NULL);

    mFileName = pFile->GetFileName();

    mpBuffer = (u8 *)malloc(sizeof(u8) * mBufferSize);
    pFile->GetFileBuffer(mpBuffer, offset, mBufferSize);
}



File::File(u8* pBuffer, const u32& offset, const u32& length):
  mFileName("BUFFER"),
  mpBuffer(NULL),
  mBufferSize(length)
{
    assert(pBuffer != NULL);

    mpBuffer = (u8*)malloc(sizeof(u8) * mBufferSize);
    memcpy(mpBuffer, pBuffer + offset, mBufferSize);
}



File::File(File* pFile)
{
    assert(pFile != NULL);

    mBufferSize = pFile->GetFileSize();
    mFileName   = pFile->GetFileName();

    mpBuffer = (u8*)malloc(sizeof(u8) * mBufferSize);
    pFile->GetFileBuffer(mpBuffer, 0, mBufferSize);
}


File::~File(void)
{
    free(mpBuffer);
}



//============================= OPERATIONS ===================================

void
File::WriteFile(const RString& file) const
{
  REALFILESYSTEM->WriteNewFile(file, mpBuffer, mBufferSize);
}



//============================= ACCESS     ===================================

const RString&
File::GetFileName(void) const
{
    return mFileName;
}



const u32&
File::GetFileSize(void) const
{
    return mBufferSize;
}



void
File::GetFileBuffer(u8* pBuffer, const u32& start, const u32& length) const
{
    memcpy(pBuffer, mpBuffer + start, length);
}



const u8
File::GetU8(const u32& offset) const
{
    return static_cast<u8>(*(mpBuffer + offset));
}



const u16
File::GetU16LE(const u32& offset) const
{
    return ((u8*)mpBuffer + offset)[0] | (((u8*)mpBuffer + offset)[1] << 8);
}



const u32
File::GetU32LE(const u32& offset) const
{
    return ((u8*)mpBuffer + offset)[0] | (((u8*)mpBuffer + offset)[1] << 8) | (((u8*)mpBuffer + offset)[2] << 16) | (((u8*)mpBuffer + offset)[3] << 24);
}
