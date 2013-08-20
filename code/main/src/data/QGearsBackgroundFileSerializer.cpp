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

#include <OgreLogManager.h>

namespace QGears
{
    //---------------------------------------------------------------------
    const String BackgroundFileSerializer::SECTION_NAME_PALETTE("PALETTE");
    const String BackgroundFileSerializer::SECTION_NAME_BACK   ("BACK");
    const String BackgroundFileSerializer::SECTION_NAME_TEXTURE("TEXTURE");

    //---------------------------------------------------------------------
    BackgroundFileSerializer::BackgroundFileSerializer() :
        Serializer()
    {
    }

    //---------------------------------------------------------------------
    BackgroundFileSerializer::~BackgroundFileSerializer()
    {
    }

    //---------------------------------------------------------------------
    void
    BackgroundFileSerializer::readFileHeader( Ogre::DataStreamPtr &stream )
    {
        uint16 data[2];
        readShorts( stream, data, 2 );
        m_header.unused = data[0];
        m_header.unknown = data[1];
    }

    //---------------------------------------------------------------------
    void
    BackgroundFileSerializer::readSectionHeader( Ogre::DataStreamPtr &stream
                                                ,const String &section_name )
    {
        String actual_name( readString( stream, section_name.size() ) );
        if( actual_name != section_name )
        {
            Ogre::LogManager::getSingleton().stream()
                << "Warming: Section didn't start with"
                << "expected String '" << section_name << "'"
                << " actual was '" << actual_name << "'";
        }

    }

    //---------------------------------------------------------------------
    void
    BackgroundFileSerializer::readPallete( Ogre::DataStreamPtr &stream
                                          ,BackgroundFile *pDest )
    {
        readSectionHeader( stream, SECTION_NAME_PALETTE );
        stream->read( pDest->getPalette(), BackgroundFile::PALETTE_ENTRY_COUNT );
    }

    //---------------------------------------------------------------------
    void
    BackgroundFileSerializer::readBackground( Ogre::DataStreamPtr &stream
                                             ,BackgroundFile *pDest )
    {
        readSectionHeader( stream, SECTION_NAME_BACK );
        Layer *layer( pDest->getLayers() );
        for( size_t i( 0 ); i < BackgroundFile::LAYER_COUNT; ++i, ++layer )
        {
            if( i != 0 )
            {
                readLayerEnabled( stream, layer );
            }

            readLayer( stream, layer, i );
        }
    }

    //---------------------------------------------------------------------
    void
    BackgroundFileSerializer::readLayerEnabled( Ogre::DataStreamPtr &stream, Layer *pDest )
    {
        uint8 enabled;
        stream->read( &enabled, 1 );
        pDest->enabled = enabled;
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
        stream->skip( 2 * 2 ); // 2 *  uint16 unused;
        readVector( stream, pDest->sprites, sprite_count );
    }

    //---------------------------------------------------------------------
    void
    BackgroundFileSerializer::readObject( Ogre::DataStreamPtr &stream, SpriteData &pDest )
    {
        readObject( stream, pDest.dst );
        readShorts( stream, pDest.unknown_04, 2 );
        readObject( stream, pDest.src );
        readShorts( stream, pDest.unknown_0C, 4 );

        uint16 tmp[4];
        readShorts( stream, tmp, 2 );
        pDest.palette_page = tmp[0];
        pDest.unknown_16   = tmp[1];

        stream->read( pDest.flags, sizeof( pDest.flags ) );

        readShorts( stream, tmp, 4 );
        pDest.unknown_1C = tmp[0];
        pDest.data_page  = tmp[1];
        pDest.unknown_20 = tmp[2];
        pDest.unknown_22 = tmp[3];
        readObject( stream, pDest.unknown_24 );
        readShorts( stream, pDest.unused_30, 2 );
    }

    //---------------------------------------------------------------------
    void
    BackgroundFileSerializer::readObject( Ogre::DataStreamPtr &stream, Pixel &pDest )
    {
        stream->read( &pDest, sizeof( pDest ) );
        flipFromLittleEndian( &pDest, 2, 2 );
    }

    //---------------------------------------------------------------------
    void
    BackgroundFileSerializer::importBackgroundFile( Ogre::DataStreamPtr &stream
                                                   ,BackgroundFile *pDest )
    {
        pDest->clear();
        readFileHeader( stream );

        readLayerEnabled( stream, pDest->getLayers() );
        readPallete( stream, pDest );

        stream->skip( 2 * 2 ); // 2 *  uint16 unused;

        readBackground( stream, pDest );
    }

    //---------------------------------------------------------------------
}
