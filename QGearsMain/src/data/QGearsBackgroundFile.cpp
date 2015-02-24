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
        for (auto& layer : m_layers)
        {
            memset(&layer, 0, sizeof(layer));
        }

        for (auto& pal : m_palette)
        {
            memset(&pal, 0, sizeof(pal));
        }

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
    void
    BackgroundFile::addAllSprites( SpriteList& sprites ) const
    {
        for( size_t i(0); i < LAYER_COUNT; ++i )
        {
            if( m_layers[i].enabled )
            {
                sprites.insert( sprites.end(), m_layers[i].sprites.begin(), m_layers[i].sprites.end() );
            }
        }
    }

    //---------------------------------------------------------------------
    Ogre::Image*
    BackgroundFile::createImage( const PaletteFilePtr &palette ) const
    {
        assert( !palette.isNull() );
        SpriteList sprites;
        addAllSprites( sprites );

        size_t sprite_count( sprites.size() );
        size_t width( 1024 );
        size_t row_pitch( width );
        size_t height( width );
        size_t pixel_count( width * height );

        row_pitch = width;
        Ogre::PixelFormat format( Ogre::PF_A8R8G8B8 );
        size_t memory_size( Ogre::PixelUtil::getMemorySize( width, height, 1, format ) );
        Ogre::MemoryDataStream *buffer( new Ogre::MemoryDataStream( memory_size ) );
        uint32 *color( reinterpret_cast<uint32*>( buffer->getPtr() ) );

        Ogre::LogManager::getSingleton().stream()
            << "Image Size: " << width << " x " << height
            << " sprite_count " << sprite_count;
        size_t dst_x(0), dst_y(0),
                dst_x_16(0), dst_y_16(0),
                dst_x_32(0), dst_y_32(0);
        size_t dst_n_16(0);
        for( SpriteList::const_iterator it( sprites.begin() )
            ;it != sprites.end()
            ;++it)
        {
            const Page& data_page( m_pages[it->data_page] );
            const Pixel& src(it->src);
            if (!data_page.enabled)
            {
                Ogre::LogManager::getSingleton().stream()
                    << "Error: referencing an disabled data page";
            }

            // Position sprites in 32x32 blocks
            if (it->width == 32)
            {
                dst_x = dst_x_32;
                dst_y = dst_y_32;

                dst_x_32 += 32;
                if (dst_x_32 == width)
                {
                    dst_y_32 += 32;
                    dst_x_32 = 0;
                }
            }
            else if (it->width == 16)
            {
                // if we start new 16x16*4 block
                if (dst_n_16 == 0)
                {
                    dst_x_16 = dst_x_32;
                    dst_y_16 = dst_y_32;

                    dst_x_32 += 32;
                    if (dst_x_32 == width)
                    {
                        dst_y_32 += 32;
                        dst_x_32 = 0;
                    }
                }

                dst_x = dst_x_16;
                dst_y = dst_y_16;

                ++dst_n_16;
                if (dst_n_16 == 1 || dst_n_16 == 3)
                {
                    dst_x_16 += 16;
                }
                else if (dst_n_16 == 2)
                {
                    dst_x_16 -= 16;
                    dst_y_16 += 16;
                }
                else if (dst_n_16 == 4)
                {
                    dst_n_16 = 0;
                }
            }
            else
            {
                Ogre::LogManager::getSingleton().stream()
                    << "Error: sprite data with invalid size";
            }

            if (data_page.value_size == 2)
            {
                for (uint16 y(it->height); y--;)
                {
                    for (uint16 x(it->width); x--;)
                    {
                        size_t data_index((src.y + y) * PAGE_DATA_WIDTH + src.x + x);
                        if (data_index >= data_page.colors.size())
                        {
                            Ogre::LogManager::getSingleton().stream()
                                << "Error: data page Index out of Bounds " << data_index;
                        }

                        Color colour(data_page.colors.at(data_index));
                        data_index = (dst_y + y) * row_pitch + dst_x + x;
                        if (data_index >= pixel_count)
                        {
                            Ogre::LogManager::getSingleton().stream()
                                << "Error: writing Pixel out of Bounds " << data_index
                                << " " << (dst_x + x) << " x " << dst_y + y;
                        }
                        color[data_index] = colour.getAsARGB();
                    }
                }
            }
            else if (data_page.value_size == 1)
            {
                if (it->palette_page >= palette->getPages().size())
                {
                    Ogre::LogManager::getSingleton().stream()
                        << "Error: palette page Index out of Bounds " << it->palette_page;
                }
                const PaletteFile::Page& palette_page(palette->getPage(it->palette_page));
                bool firstColorHidden(false);
                if (it->palette_page < PALETTE_ENTRY_COUNT) 
                {
                    firstColorHidden = m_palette[it->palette_page] > 0;
                }
                for (uint16 y(it->height); y--;)
                {
                    for (uint16 x(it->width); x--;)
                    {
                        size_t data_index((src.y + y) * PAGE_DATA_WIDTH + src.x + x);
                        if (data_index >= data_page.data.size())
                        {
                            Ogre::LogManager::getSingleton().stream()
                                << "Error: data page Index out of Bounds " << data_index;
                        }
                        uint8 index(data_page.data.at(data_index));
                        if (index >= palette_page.size())
                        {
                            Ogre::LogManager::getSingleton().stream()
                                << "Error: palette page Index out of Bounds " << index;
                        }

                        data_index = (dst_y + y) * row_pitch + dst_x + x;
                        if (data_index >= pixel_count)
                        {
                            Ogre::LogManager::getSingleton().stream()
                                << "Error: writing Pixel out of Bounds " << data_index
                                << " " << (dst_x + x) << " x " << dst_y + y;
                        }
                        Color colour(palette_page[index]);
                        // Strange PC version behavior: empty colors are replaced by the first color and the first color is hidden by a flag
                        if (colour == Color::ZERO)
                        {
                            colour = palette_page[0];
                        }
                        if (index == 0 && firstColorHidden)
                        {
                            colour.a = 0;
                        }
                        else
                        {
                            colour.a = 1;
                        }
                        color[data_index] = colour.getAsARGB();
                    }
                }
            }
        }

        Ogre::DataStreamPtr stream( buffer );
        Ogre::Image *image( new Ogre::Image() );
        image->loadRawData( stream, width, height, format );
        return image;
    }

    //---------------------------------------------------------------------
}
