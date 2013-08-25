// $Id: SubPacketFile.cpp 93 2006-11-12 13:49:02Z einherjar $

#include "../../common/utilites/Logger.h"

#include "SubPacketFile.h"



/////////////////////////////// PUBLIC ///////////////////////////////////////

//============================= LIFECYCLE ====================================

SubPacketFile::SubPacketFile(const RString& file):
    PacketFile(file)
{
}



SubPacketFile::SubPacketFile(File* pFile):
    PacketFile(pFile)
{
}



SubPacketFile::SubPacketFile(File* pFile, const u32& offset, const u32& length):
    PacketFile(pFile, offset, length)
{
}



SubPacketFile::SubPacketFile(u8* pBuffer, const u32& offset, const u32& length):
    PacketFile(pBuffer, offset, length)
{
}



SubPacketFile::~SubPacketFile(void)
{
}



//============================= OPERATIONS ===================================

File*
SubPacketFile::ExtractFile(const u32& fileNumber)
{
    if (fileNumber >= GetNumberOfFiles())
    {
        return NULL;
    }

    u32 length = ((fileNumber + 1 == GetNumberOfFiles()) ? mBufferSize : GetU32LE(0x04 + (fileNumber + 1) * 0x04)) - GetU32LE(0x04 + fileNumber * 0x04);

    File* file = new File(this, GetU32LE(0x04 + fileNumber * 0x04), length);
    return file;
}
