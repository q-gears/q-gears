// $Id: FieldPackFile.cpp 96 2006-11-13 03:34:17Z crazy_otaku $

#include "../../common/utilites/Logger.h"
#include "../../common/filesystem/RealFileSystem.h"
#include "../filetypes/ArchiveFile.h"
#include "FieldPackFile.h"



/////////////////////////////// PUBLIC ///////////////////////////////////////

//============================= LIFECYCLE ====================================

FieldPackFile::FieldPackFile(const RString& file):
    File(*REALFILESYSTEM, file)
{
}



FieldPackFile::FieldPackFile(File* pFile):
    File(pFile)
{
}



FieldPackFile::FieldPackFile(File* pFile, const u32& offset, const u32& length):
    File(pFile, offset, length)
{
}



FieldPackFile::FieldPackFile(u8* pBuffer, const u32& offset, const u32& length):
    File(pBuffer, offset, length)
{
}



FieldPackFile::~FieldPackFile(void)
{
}



//============================= OPERATIONS ===================================



File *
FieldPackFile::Extract(u32 file_number)
{
    // there are only 8 files
    if (file_number > 8)
    {
        return NULL;
    }

    u32 length_uncompressed = GetU32LE(0x010C + file_number * 0x04);
    u32 first_file = GetU32LE(0x0130 + file_number * 0x04);
    u32 length = 0;
    if (file_number < 8)
    {
        length = GetU32LE(0x0130 + (file_number + 1) * 0x04) - first_file;
    }
    else
    {
        length = mBufferSize - first_file;
    }

    ArchiveFile* comp = new ArchiveFile(this, first_file, length);
    File* file        = new File(comp, 0, length_uncompressed);
    delete comp;

    return file;
}
