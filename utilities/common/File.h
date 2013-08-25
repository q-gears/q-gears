#ifndef FILE_H
#define FILE_H

#include "TypeDefine.h"
#include <OgreString.h>



class File
{
public:
    File( const Ogre::String& file );
    File( const File* pFile );
    File( const File* pFile, u32 offset, u32 length );
    File( const u8* pBuffer, u32 offset, u32 length );
    virtual ~File();

    void WriteFile( const Ogre::String& file ) const;
    const Ogre::String& GetFileName() const;
    u32 GetFileSize() const;
    void GetFileBuffer( u8* pBuffer, const u32 &start, const u32 &length ) const;
    u8 GetU8( u32 offset ) const;
    u16 GetU16LE( u32 offset ) const;
    u32 GetU32LE( u32 offset ) const;
    u8 readU8();
    u16 readU16LE();
    u32 readU32LE();

protected:
    Ogre::String m_FileName;
    u32 m_offset;
    u8* m_Buffer;
    u32 m_BufferSize;
};



#endif // FILE_H
