#include "Vram.h"

#include <OgreStringConverter.h>

#include "Logger.h"
#include <string.h>


Vram::Vram():
    m_Width( 2048 ),
    m_Height(512)
{
    memset( m_Vram, 0, 2048 * 512 );
}



Vram::~Vram()
{
}



u16
Vram::GetWidth() const
{
    return m_Width;
}



u16
Vram::GetHeight() const
{
    return m_Height;
}



void
Vram::Save(const Ogre::String& file)
{
    Ogre::TexturePtr ptex;
    Ogre::HardwarePixelBufferSharedPtr buffer;
    ptex = Ogre::TextureManager::getSingleton().createManual("DynaTex", "General", Ogre::TEX_TYPE_2D, m_Width / 2, m_Height, 0, Ogre::PF_R8G8B8A8, Ogre::TU_STATIC);
    buffer = ptex->getBuffer(0, 0);
    buffer->lock(Ogre::HardwareBuffer::HBL_DISCARD);
    const Ogre::PixelBox& pb = buffer->getCurrentLock();
    u32* data = static_cast<u32*>(pb.data);

    for( int i = 0, size = m_Width * m_Height / 2; i < size; ++i )
    {
        u16 col = ( m_Vram[ i * 2 + 1 ] << 8) | m_Vram[ i * 2 + 0 ];
        data[ i ] = ( ( ( col & 0x1f ) * 255 / 31 ) << 0x18 ) | ( ( ( ( col >>  5 ) & 0x1f ) * 255 / 31 ) << 0x10 ) | ( ( ( ( col >> 10 ) & 0x1f ) * 255 / 31 ) << 0x8 ) | 0xff;
    }

    Ogre::Image image;
    image.loadDynamicImage( (Ogre::uchar*)pb.data, m_Width / 2, m_Height, Ogre::PF_R8G8B8A8 );
    image.save( file + ".png" );
    buffer->unlock();
}



void
Vram::PutU8(u16 x, u16 y, u8 byte)
{
    if( x > m_Width || y > m_Height )
    {
        LOGGER->Log( "Vram::PutU8: Error: Tried to put byte in Vram x(" + Ogre::StringConverter::toString( x ) + ") y(" + Ogre::StringConverter::toString( y ) + ")\n" );
        return;
    }

    m_Vram[ y * m_Width + x ] = byte;
}



u8
Vram::GetU8( u16 x, u16 y ) const
{
    if( x > m_Width || y > m_Height )
    {
        LOGGER->Log( "Vram::GetU8: Error: Tried to get byte from Vram x(" + Ogre::StringConverter::toString( x ) + ") y(" + Ogre::StringConverter::toString( y ) + ")\n");
        return 0;
    }

    return m_Vram[ y * m_Width + x ];
}



void
Vram::PutU16( u16 x, u16 y, u16 bytes )
{
    if( x + 1 > m_Width || y > m_Height )
    {
        LOGGER->Log( "Vram::PutU16: Error: Tried to put pixel in Vram x(" + Ogre::StringConverter::toString( x ) + ") y(" + Ogre::StringConverter::toString( y ) + ")\n" );
        return;
    }

    // this byte order use to make posible store everything to vram as U8 but get as U16LE
    m_Vram[ y * m_Width + x + 1 ] = bytes >> 8;
    m_Vram[ y * m_Width + x + 0 ] = bytes & 0x00ff;
}



u16
Vram::GetU16( u16 x, u16 y ) const
{
    if( x + 1 > m_Width || y > m_Height )
    {
        LOGGER->Log( "Vram::GetU16: Error: Tried to get pixel from Vram x(" + Ogre::StringConverter::toString( x ) + ") y(" + Ogre::StringConverter::toString( y ) + ")\n" );
        return 0;
    }

    // this byte order use to make posible store everything to vram as U8 but get as U16LE
    return ( m_Vram[ y * m_Width + x + 1 ] << 8) | m_Vram[ y * m_Width + x + 0 ];
}
