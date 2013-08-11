#include "QGearsPaletteFile.h"

#include <cstring>

#include "Logger.h"

namespace QGears
{
    //---------------------------------------------------------------------
    PaletteFile::PaletteFile( const File* pFile, u32 offset, u32 length ):
        File( pFile, offset, length )
       ,m_colors( NULL )
    {
        read();
    }

    //---------------------------------------------------------------------
    PaletteFile::~PaletteFile()
    {
        clear();
    }

    //---------------------------------------------------------------------
    void PaletteFile::clear()
    {
        m_colors = NULL;
        std::memset( &m_header, 0, sizeof( m_header ) );
    }

    //---------------------------------------------------------------------
    u16* PaletteFile::getPage( u16 page_number ) const
    {
        u16* colors( m_colors );
        return colors + page_number * m_header.colors_per_page;
    }

    //---------------------------------------------------------------------
    PaletteFile::Color_BGR PaletteFile::convertColor( u16 in_color )
    {
        Color_BGR out_color;
        out_color.red   = in_color << 3;
        out_color.green = in_color >> 2;
        out_color.blue  = in_color >> 7;
        return out_color;
    }

    //---------------------------------------------------------------------
    void
    PaletteFile::read()
    {
        LOGGER->Log( "Info: PaletteFile::read();\n" );
        clear();
        size_t header_size( sizeof( m_header ) );
        if ( m_BufferSize < header_size )
        {
            LOGGER->Log( "Warning: not an flevel palette file, not enough space for header!\n" );
            return;
        }


        std::memcpy( &m_header, m_Buffer, header_size );
        u32 data_size( m_header.colors_per_page * m_header.page_count * 2 );
        if (   m_BufferSize != m_header.file_size
            || m_BufferSize < data_size
           )
        {
            LOGGER->Log( "Warning: not an flevel palette file!\n" );
            return;
        }
        m_colors = reinterpret_cast<u16*>(m_Buffer + header_size);
    }

}
