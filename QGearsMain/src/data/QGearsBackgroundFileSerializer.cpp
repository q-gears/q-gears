/*
-----------------------------------------------------------------------------
The MIT License (MIT)

Copyright (c) 2013-08-10 Tobias Peters <tobias.peters@kreativeffekt.at>

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
#include "data/QGearsBackgroundFileSerializer.h"
#include "data/QGearsPaletteFileSerializer.h"

#include <OgreException.h>
#include <OgreLogManager.h>
#include <OgreStringConverter.h>

namespace QGears
{
    //---------------------------------------------------------------------
    const String        BackgroundFileSerializer::SECTION_NAME_PALETTE("PALETTE");
    const String        BackgroundFileSerializer::SECTION_NAME_BACK   ("BACK");
    const String        BackgroundFileSerializer::SECTION_NAME_TEXTURE("TEXTURE");
    const String        BackgroundFileSerializer::TAG_FILE_END        ("END");
    const Ogre::Real    BackgroundFileSerializer::src_big_SCALE( 10000000.0 );

    //---------------------------------------------------------------------
    BackgroundFileSerializer::BackgroundFileSerializer() :
        Serializer(), m_layer_index(BackgroundFile::LAYER_COUNT)
    {
    }

    //---------------------------------------------------------------------
    BackgroundFileSerializer::~BackgroundFileSerializer()
    {
    }

    //---------------------------------------------------------------------
    void
    BackgroundFileSerializer::importBackgroundFile( Ogre::DataStreamPtr &stream
                                                   ,BackgroundFile *pDest )
    {
        readFileHeader( stream );

        read1ByteBool( stream, pDest->getLayers()[0].enabled );
        readPallete( stream, pDest );

        stream->skip( 2 * 2 ); // 2 *  uint16 unused;

        readBackground( stream, pDest );
        readTexture( stream, pDest );
        readEnd( stream );
    }

    //---------------------------------------------------------------------
    void
    BackgroundFileSerializer::readFileHeader( Ogre::DataStreamPtr &stream )
    {
        uint16 data[2];
        readShorts( stream, data, 2 );
        m_header.unused = data[0];
        m_header.sort_sprites_by_palette = data[1];
    }

    //---------------------------------------------------------------------
    void
    BackgroundFileSerializer::readSectionHeader( Ogre::DataStreamPtr &stream
                                                ,const String &section_name )
    {
        String actual( readString( stream, section_name.size() ) );
        if( actual != section_name )
        {
            Ogre::LogManager::getSingleton().stream()
                << "Warming: Section didn't start with"
                << " expected String '" << section_name << "'"
                << " actual was '" << actual << "'";
        }

    }

    //---------------------------------------------------------------------
    void
    BackgroundFileSerializer::readEnd( Ogre::DataStreamPtr &stream )
    {
        readEndString( stream, TAG_FILE_END );
    }

    //---------------------------------------------------------------------
    void
    BackgroundFileSerializer::readPallete( Ogre::DataStreamPtr &stream
                                          ,BackgroundFile *pDest )
    {
        readSectionHeader( stream, SECTION_NAME_PALETTE );
        stream->read( pDest->getPalette().data(), BackgroundFile::PALETTE_ENTRY_COUNT );
    }

    //---------------------------------------------------------------------
    void
    BackgroundFileSerializer::readBackground( Ogre::DataStreamPtr &stream
                                             ,BackgroundFile *pDest )
    {
        readSectionHeader( stream, SECTION_NAME_BACK );
        auto& layers( pDest->getLayers() );
        for( size_t i( 0 ); i < BackgroundFile::LAYER_COUNT; ++i )
        {
            if( i != 0 )
            {
                read1ByteBool( stream, layers[i].enabled );
            }

            readLayer(stream, &layers[i], i);
        }
    }

    //---------------------------------------------------------------------
    void
    BackgroundFileSerializer::readLayer( Ogre::DataStreamPtr &stream
                                        ,Layer *pDest, size_t layer_index )
    {
        if( !pDest->enabled ) return;

        uint16 tmp[4], sprite_count;
        readShorts( stream, tmp, 4 );
        pDest->width        = tmp[0];
        pDest->height       = tmp[1];
        sprite_count        = tmp[2];
        pDest->unknown_06   = tmp[3];

        switch( layer_index )
        {
          case 1:
            readShorts( stream, pDest->unknown_08, 3 );
          case 2:
          case 3:
            readShorts( stream, pDest->unknown_0E, 4 );
        }
        stream->skip( 2 * 2 ); // 2 * uint16 unused;
        m_layer_index = layer_index;
        readVector( stream, pDest->sprites, sprite_count );
    }

    //---------------------------------------------------------------------
    void
    BackgroundFileSerializer::readObject( Ogre::DataStreamPtr &stream, SpriteData &pDest )
    {
        readObject( stream, pDest.dst );
        readShorts( stream, pDest.unknown_04, 2 );
        readObject( stream, pDest.src );
        readObject( stream, pDest.src2 );
        readShort( stream, pDest.width );
        readShort( stream, pDest.height );

        uint16 size;
        // width and height are sometimes incorrect in the file
        if ( m_layer_index < 2 )
        {
            size = 16;
        }
        else if ( m_layer_index < BackgroundFile::LAYER_COUNT)
        {
            size = 32;
        }
        else
        {
            OGRE_EXCEPT(Ogre::Exception::ERR_INVALIDPARAMS
                ,"m_layer_index not set correctly"
                ,"BackgroundFileSerializer::readObject" );
        }
        pDest.width = pDest.height = size;

        readShort( stream, pDest.palette_page );
        readShort( stream, pDest.depth );

        // Force depth values
        switch ( m_layer_index )
        {
          case 0:
            pDest.depth = 4095;
            break;
          case 2:
            pDest.depth = 4096;
            break;
          case 3:
            pDest.depth = 0;
            break;
        }

        uint8 animation[2];
        stream->read( animation, sizeof( animation ) );
        pDest.animation_id = animation[0];
        pDest.animation_frame = animation[1];
        uint8 has_blending[2];
        stream->read( has_blending, sizeof( has_blending ) );
        pDest.has_blending[0] = has_blending[0] > 0;
        pDest.has_blending[1] = has_blending[1] > 0;

        readShort( stream, pDest.blending );
        readShort( stream, pDest.data_page );
        readShort( stream, pDest.data_page2 );
        // when data_page2 != 0, it must be used instead of data_page
        if ( pDest.data_page2 )
        {
            pDest.src = pDest.src2;
            pDest.data_page = pDest.data_page2;
        }
        readShort( stream, pDest.colour_depth );
        readObject( stream, pDest.src_big );
        pDest.src_big /= src_big_SCALE;
        stream->skip( 2 * 2 ); // 2 * uint16 unused
    }


    //---------------------------------------------------------------------
    void
    BackgroundFileSerializer::readTexture( Ogre::DataStreamPtr &stream
                                          ,BackgroundFile *pDest )
    {
        readSectionHeader( stream, SECTION_NAME_TEXTURE );
        for (auto& page : pDest->getPages())
        {
            readObject(stream, page);
        }
    }

    //---------------------------------------------------------------------
    void
    BackgroundFileSerializer::readObject( Ogre::DataStreamPtr& stream, Color& pDest )
    {
        uint16 colour;
        readShort( stream, colour );
        pDest.r = static_cast<float>(( colour & BIT_MASK_RED   ) >> 11);
        pDest.g = static_cast<float>(( colour & BIT_MASK_GREEN ) >>  6);
        pDest.b = static_cast<float>(colour & BIT_MASK_BLUE);
        pDest /= BIT_SIZE;
        pDest.a = 1.0f;
        if ( colour == 0 )
        {
            pDest.a = 0.0f;
        }
    }

    //---------------------------------------------------------------------
    void
    BackgroundFileSerializer::readObject( Ogre::DataStreamPtr &stream, Page &pDest )
    {
        read2ByteBool( stream, pDest.enabled );
        if( !pDest.enabled ) return;

        readShort( stream, pDest.unknown_02 );
        readShort( stream, pDest.value_size );
        if( pDest.value_size != 1 && pDest.value_size != 2 )
        {
            OGRE_EXCEPT(Ogre::Exception::ERR_INVALIDPARAMS
                ,"Page value_size other then 1 and 2 is not supported"
                ,"BackgroundFileSerializer::readObject" );
        }

        size_t color_count( BackgroundFile::PAGE_DATA_SIZE );
        pDest.colors.clear();
        pDest.data.clear();

        if( pDest.value_size == 2 )
        {
            pDest.colors.reserve( color_count );
            for( size_t i( color_count ); i--; )
            {
                Color colourDest;
                readObject( stream, colourDest );
                pDest.colors.push_back( colourDest );
            }
        }
        else
        {
            pDest.data.resize( color_count );
            stream->read( &pDest.data[0], color_count );
        }
    }

    //---------------------------------------------------------------------
}
