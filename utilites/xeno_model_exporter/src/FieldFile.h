#ifndef FIELD_FILE_H
#define FIELD_FILE_H



#include "../../common/File.h"



class FieldFile : public File
{
public:
    FieldFile( const Ogre::String& file );
    FieldFile( File* file );
    FieldFile( File* file, const u32 offset, const u32 length );
    FieldFile( u8* buffer, const u32 offset, const u32 length );
    virtual ~FieldFile();

    File* Extract( const int file_number );
};



#endif // FIELD_FILE_H
