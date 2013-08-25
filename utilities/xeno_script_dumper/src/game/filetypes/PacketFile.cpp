// $Id: PacketFile.cpp 93 2006-11-12 13:49:02Z einherjar $

#include "../../common/utilites/Logger.h"
#include "../../common/filesystem/RealFileSystem.h"
#include "PacketFile.h"




/////////////////////////////// PUBLIC ///////////////////////////////////////

//============================= LIFECYCLE ====================================

PacketFile::PacketFile(const RString& file):
    File(*REALFILESYSTEM, file),
    mNumberOfFiles(0)
{
    InnerGetNumberOfFiles();
}



PacketFile::PacketFile(File* pFile):
    File(pFile),
    mNumberOfFiles(0)
{
    InnerGetNumberOfFiles();
}



PacketFile::PacketFile(File* pFile, const u32& offset, const u32& length):
    File(pFile, offset, length),
    mNumberOfFiles(0)
{
    InnerGetNumberOfFiles();
}



PacketFile::PacketFile(u8* pBuffer, const u32& offset, const u32& length):
    File(pBuffer, offset, length),
    mNumberOfFiles(0)
{
    InnerGetNumberOfFiles();
}



PacketFile::~PacketFile(void)
{
}



//============================= OPERATIONS ===================================

File*
PacketFile::ExtractFile(const u32& fileNumber)
{
    if (fileNumber >= mNumberOfFiles)
    {
        return NULL;
    }

    // its not a subfile so last offset is the offset to end of file
    u32 length = GetU32LE(0x04 + (fileNumber + 1) * 0x04) - GetU32LE(0x04 + fileNumber * 0x04);

    File* file = new File(this, GetU32LE(0x04 + fileNumber * 0x04), length);
    return file;
}


//============================= ACCESS     ===================================

const u32&
PacketFile::GetNumberOfFiles(void)
{
    return mNumberOfFiles;
}



/////////////////////////////// PROTECTED  ///////////////////////////////////

//============================= OPERATIONS ===================================

void
PacketFile::InnerGetNumberOfFiles(void)
{
    mNumberOfFiles = GetU32LE(0x00);
}
