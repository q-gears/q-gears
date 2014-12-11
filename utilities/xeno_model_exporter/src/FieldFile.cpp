#include "FieldFile.h"

#include "ArchiveFile.h"



FieldFile::FieldFile( const Ogre::String& file ):
    File( file )
{
}



FieldFile::FieldFile(File* file, const u32 offset, const u32 length ):
    File( file, offset, length )
{
}



FieldFile::FieldFile( u8* buffer, const u32 offset, const u32 length ):
    File( buffer, offset, length )
{
}



FieldFile::FieldFile( File* file ):
    File( file )
{
}



FieldFile::~FieldFile()
{
}



File*
FieldFile::Extract( const int file_number )
{
    // there are only 8 files
    if( file_number > 8 )
    {
        return NULL;
    }

    u32 length_uncompressed = GetU32LE( 0x010c + file_number * 0x04 );

    u32 first_file = GetU32LE( 0x0130 + file_number * 0x04);
    u32 length     = GetU32LE( 0x0130 + ( file_number + 1 ) * 0x04) - first_file;

    ArchiveFile* comp = new ArchiveFile( this, first_file, length );
    File* file = new File( comp, 0, length_uncompressed );
    delete comp;

    return file;
}
