#ifndef VRAM_H
#define VRAM_H

#include "common/TypeDefine.h"
#include "common/Surface.h"



class Vram
{
public:
    Vram();
    virtual ~Vram();

    u16 GetWidth() const;
    u16 GetHeight() const;

    void Save( const Ogre::String& file );

    void AddImageBuffer( u16 x, u16 y, u16 width, u16 height, u8* buffer );
    void PutU8( u16 x, u16 y, u8 byte );
    u8 GetU8( u16 x, u16 y ) const;
    void PutU16( u16 x, u16 y, u16 bytes );
    u16 GetU16( u16 x, u16 y ) const;

private:
    u8  m_Vram[ 2048 * 512 ];

    u16 m_Width;
    u16 m_Height;
};



#endif
