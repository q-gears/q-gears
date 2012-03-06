#ifndef ARCHIVE_FILE_H
#define ARCHIVE_FILE_H



#include "../../common/File.h"



class ArchiveFile : public File
{
public:
    ArchiveFile( const Ogre::String &file );
    ArchiveFile( File* file );
    ArchiveFile( File* file, const u32 &offset, const u32 &length );
    ArchiveFile( u8* buffer, const u32 &offset, const u32 &length );
    virtual ~ArchiveFile();

private:
    void Extract();
};



#endif // ARCHIVE_FILE_H
