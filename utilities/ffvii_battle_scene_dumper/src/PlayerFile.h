#ifndef PLFILE_H
#define PLFILE_H

#include "../../common/File.h"



class PlayerFile : public File
{
public:
    PlayerFile( const Ogre::String &file );
    PlayerFile( File* file );
    PlayerFile( File* file, const u32 &offset, const u32 &length );
    PlayerFile( u8* buffer, const u32 &offset, const u32 &length );
    virtual ~PlayerFile();

private:
    void DumpData();
};



#endif // PLFILE_H
