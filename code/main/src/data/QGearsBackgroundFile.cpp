/*
-----------------------------------------------------------------------------
The MIT License (MIT)

Copyright (c) 2013-08-11 Tobias Peters <tobias.peters@kreativeffekt.at>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
-----------------------------------------------------------------------------
*/
#include "data/QGearsBackgroundFile.h"

#include <OgreResourceGroupManager.h>
#include <OgreLogManager.h>

#include "data/QGearsBackgroundFileSerializer.h"

namespace QGears
{
    //---------------------------------------------------------------------
    const String    BackgroundFile::RESOURCE_TYPE( "QGearsBackgroundFile" );

    //---------------------------------------------------------------------
    BackgroundFile::BackgroundFile( Ogre::ResourceManager *creator
                 ,const String &name, Ogre::ResourceHandle handle
                 ,const String &group, bool isManual
                 ,Ogre::ManualResourceLoader *loader ) :
        Ogre::Resource( creator, name, handle, group, isManual, loader )
    {
        createParamDictionary( RESOURCE_TYPE );
    }

    //---------------------------------------------------------------------
    BackgroundFile::~BackgroundFile()
    {
        unload();
    }

    //---------------------------------------------------------------------
    void
    BackgroundFile::loadImpl()
    {
        BackgroundFileSerializer serializer;
        Ogre::DataStreamPtr stream( Ogre::ResourceGroupManager::getSingleton().openResource( mName, mGroup, true, this ) );
        serializer.importBackgroundFile( stream, this );
    }

    //---------------------------------------------------------------------
    void
    BackgroundFile::unloadImpl()
    {
        memset( m_layers , 0, sizeof( m_layers  ) );
        memset( m_palette, 0, sizeof( m_palette ) );
        for( size_t i(PAGE_COUNT); i--; )
        {
            m_pages[i].enabled = false;
            m_pages[i].unknown_02 = 0;
            m_pages[i].value_size = 0;
            m_pages[i].data.clear();
        }
    }

    //---------------------------------------------------------------------
    size_t
    BackgroundFile::calculateSize() const
    {
        size_t data_size( 0 );
        for( size_t i(LAYER_COUNT); i--; )
        {
            data_size += calculateSize( m_layers[i] );
        }

        for( size_t i(PAGE_COUNT); i--; )
        {
            data_size += calculateSize( m_pages[i] );
        }

        return data_size;
    }

    //---------------------------------------------------------------------
    size_t
    BackgroundFile::calculateSize( const Layer &layer ) const
    {
        return sizeof( layer.enabled )
              +sizeof( layer.width )
              +sizeof( layer.height )
              +sizeof( layer.unknown_06 )
              +sizeof( layer.unknown_08 )
              +sizeof( layer.unknown_0E )
              +layer.sprites.size() * sizeof( layer.sprites[0] );
    }

    //---------------------------------------------------------------------
    size_t
    BackgroundFile::calculateSize( const Page &page ) const
    {
        return sizeof( page.enabled )
              +sizeof( page.unknown_02 )
              +sizeof( page.value_size )
              +page.data.size();
    }

    //---------------------------------------------------------------------
    // TODO implement BackgroundTextureLoader and move this code there
    Ogre::Image*
    BackgroundFile::createImage( const PaletteFilePtr &palette ) const
    {
        SpriteList sprites;
        for( size_t i(0); i < LAYER_COUNT; ++i )
        {
            if( m_layers[i].enabled )
            {
                sprites.insert( sprites.end(), m_layers[i].sprites.begin(), m_layers[i].sprites.end() );
            }
        }
        size_t sprite_count( sprites.size() );
        size_t width( 1024 );
        size_t row_pitch( width);
        size_t height( width );
        size_t pixel_count( width * height );

        row_pitch = width;
        Ogre::MemoryDataStream *buffer( new Ogre::MemoryDataStream( sizeof(Color) * pixel_count ) );
        Color *color( reinterpret_cast<Color*>( buffer->getPtr() ) );

        Ogre::LogManager::getSingleton().stream()
            << "Image Size: " << width << " x " << height
            << " sprite_count " << sprite_count;
        size_t dst_x( 0 ), dst_y( 0 );
        for( SpriteList::const_iterator it( sprites.begin() )
            ;it != sprites.end()
            ;++it)
        {
            const Page &data_page( m_pages[it->data_page] );
            const PaletteFile::Page &palette_page( palette->getPage( it->palette_page ) );
            const Pixel &src( it->src );
            if( !data_page.enabled )
            {
                Ogre::LogManager::getSingleton().stream()
                    << "Error: referencing an disabled data page";
            }
            for( uint16 y( SPRITE_HEIGHT ); y--; )
            {
                for( uint16 x( SPRITE_WIDTH ); x--; )
                {
                    size_t data_index( (src.y + y) * PAGE_DATA_WIDTH + src.x + x );
                    if( data_index >= data_page.data.size() )
                    {
                        Ogre::LogManager::getSingleton().stream()
                            << "Error: data page Index out of Bounds " << data_index;
                    }
                    uint8 index( data_page.data[ data_index ] );
                    if( index >= palette_page.size() )
                    {
                        Ogre::LogManager::getSingleton().stream()
                            << "Error: palette page Index out of Bounds " << index;
                    }

                    data_index = (dst_y + y ) * row_pitch + dst_x + x;
                    if( data_index >= pixel_count )
                    {
                        Ogre::LogManager::getSingleton().stream()
                            << "Error: writing Pixel out of Bounds " << data_index
                            << " " << (dst_x + x) << " x " << dst_y + y;
                    }
                    color[data_index] = PaletteFile::convert( palette_page[ index ] );
                }
            }

            dst_x += SPRITE_WIDTH;
            if( dst_x >= width )
            {
                dst_x = 0;
                dst_y += SPRITE_HEIGHT;
            }
        }

        Ogre::DataStreamPtr stream( buffer );
        Ogre::Image *image( new Ogre::Image() );
        image->loadRawData( stream, width, height, Ogre::PF_A1R5G5B5 );

        return image;
    }

    //---------------------------------------------------------------------
}
