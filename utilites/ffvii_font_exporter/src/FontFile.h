#ifndef FONT_FILE_H
#define FONT_FILE_H

#include "../../common/File.h"



class FontFile : public File
{
public:
    FontFile( const Ogre::String& file );
    FontFile( File* file );
    FontFile( File* file, const u32 offset, const u32 length );
    FontFile( u8* buffer, const u32 offset, const u32 length );
    virtual ~FontFile();

    void Export( const Ogre::String& export_file, bool english );
};



#endif // FONT_FILE_H
