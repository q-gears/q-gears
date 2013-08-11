#include "QGearsBackgroundFile.h"

#include "Logger.h"

namespace QGears
{
    //---------------------------------------------------------------------
    BackgroundFile::BackgroundFile( const File* pFile, u32 offset, u32 length, const PaletteFile* palette ):
        File( pFile, offset, length )
       ,m_palette( palette )
       ,m_pages( NULL )
    {
        read();
    }

    //---------------------------------------------------------------------
    BackgroundFile::~BackgroundFile()
    {
    }

    //---------------------------------------------------------------------
    void
    BackgroundFile::writeSprites( Color_BGR* image, u16 layer_index )
    {
        LOGGER->Log( "Info: writing sprites\n" );
        Layer* layer( m_layers + layer_index );
        if( !layer->enabled ) return;

        u16 count( layer->count );
        std::cout << " layer_index: " << layer_index
                  << " sprite_count: " << count
                  << " width: " << layer->width
                  << " height: " << layer->height
                  << std::endl;
        SpriteData* sprite( layer->sprites );
        for( ;count--; ++sprite)
        {
            s16 src_x( sprite->src_x )
              , src_y( sprite->src_y )
              , dst_x( m_width  / 2 + sprite->dst_x )
              , dst_y( m_height / 2 + sprite->dst_y )
              , page( sprite->data_page )
              , palette( sprite->palette_page );
            u32 color_offset( m_raw_data_offset );
            color_offset += page * PAGE_DATA_SIZE;
            color_offset += page * 6 + 6;
            color_offset += src_x + src_y * PAGE_DATA_WIDTH;
            if( color_offset  > m_BufferSize )
            {
                LOGGER->Log( "Warning: read past end of file\n" );
                continue;
            }

            ///*
            std::cout << "Sprite: " << layer->count - count
                      << " ?: " << sprite->unknown_0F

                      //<< " float0: " << sprite->unknown_u
                      //<< " float1: " << sprite->unknown_v
                      //<< " float2: " << sprite->unknown_w
                      << std::endl;
            //*/
            for( u16 y(0x10); y--; )
            {
                for( u16 x(0x10); x--; )
                {
                    u8 index( m_pages[ page ].data[ src_y + y ][ src_x + x ] );
                    u16 color( m_palette->getPage( palette )[ index ] );
                    Color_BGR* color_out( image );
                    color_out += ( dst_y + y ) * m_row_pitch;
                    color_out += dst_x + x;
                    color_out += layer_index * m_row_pitch * m_height;
                    *color_out = m_palette->convertColor( color );
                }
            }
        }

    }

    //---------------------------------------------------------------------
    void BackgroundFile::readSpriteList( u16 layer_index )
    {
        std::cout << " Layer: " << m_offset << std::endl;
        Layer* layer( m_layers + layer_index );
        if( layer_index != 0 )
        {
            layer->enabled = readU8();
        }

        if( layer->enabled )
        {
            layer->width = readU16LE();
            layer->height = readU16LE();
            layer->count = readU16LE();
            std::cout << "  unknown_06: " << readU16LE();
            switch( layer_index )
            {
              case 1:
                std::cout << " unknown: " << readU16LE();
                std::cout << " unknown: " << readU16LE();
                std::cout << " unknown: " << readU16LE();
              case 2:
              case 3:
                std::cout << " unknown: " << readU16LE();
                std::cout << " unknown: " << readU16LE();
                std::cout << " unknown: " << readU16LE();
                std::cout << " unknown: " << readU16LE();
            }

            readU16LE(); // unused
            readU16LE(); // unused
            layer->sprites = reinterpret_cast<SpriteData*>( m_Buffer + m_offset );
            m_offset += sizeof( *layer->sprites ) * layer->count;
            std::cout << std::endl;
        }
    }

    //---------------------------------------------------------------------
    void
    BackgroundFile::read()
    {
        LOGGER->Log( "Info: BackgroundFile::read();\n" );
        memset( &m_layers, 0, sizeof( m_layers ) );

        m_offset = 0x2; // u16 unused

        readU16LE(); // unknown
        m_layers[0].enabled = readU8();

        m_offset += 7; // "PALETTE"
        m_offset += 20; // u8 palette data

        readU16LE(); // unused
        readU16LE(); // unused

        m_offset += 4; // "BACK"

        readSpriteList( 0 );
        readSpriteList( 1 );
        readSpriteList( 2 );
        readSpriteList( 3 );

        m_offset += 7; // "TEXTURE" unused

        m_width  = 1024;
        m_height = 1024;

        if( m_offset > m_BufferSize )
        {
            LOGGER->Log( "Warning: read past end of file\n" );
            return;
        }
        m_pages = reinterpret_cast<Page*>( m_Buffer + m_offset );
        m_raw_data_offset = m_offset;
        m_row_pitch = m_width;

        const char* ppm( "P6 \n1024 4096\n255\n");
        u32 pixel_count( m_row_pitch * m_height * 4 );
        u32 image_size( 18 + pixel_count * sizeof(Color_BGR) );
        u8* img_buffer((u8*)malloc( image_size ));
        memcpy( img_buffer, ppm, 18 );
        Color_BGR* image( reinterpret_cast<Color_BGR*>( img_buffer + 18 ) );
        for( int i( pixel_count ); i--; )
        {
            image[i].red   = 0;
            image[i].green = 0;
            image[i].blue  = 0xFF;
        }

        writeSprites( image, 0 );
        writeSprites( image, 1 );
        writeSprites( image, 2 );
        writeSprites( image, 3 );

        free( m_Buffer );
        m_Buffer = img_buffer;
        m_BufferSize = image_size;
    }

}
