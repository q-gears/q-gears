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
    const Ogre::Real    BackgroundFileSerializer::unknown_24_SCALE( 10000000.0 );

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
                read1ByteBool( stream, layer->enabled );
            }

            readLayer( stream, layer, i );
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

        readShort( stream, pDest.palette_page );
        readShort( stream, pDest.depth );

        stream->read( pDest.flags_18, sizeof( pDest.flags_18 ) );
        uint8 flags[2];
        stream->read( flags, sizeof( flags ) );
        pDest.flags_20[0] = flags[0];
        pDest.flags_20[1] = flags[1];

        readShort( stream, pDest.unknown_1C );
        readShort( stream, pDest.data_page );
        readShort( stream, pDest.unknown_20 );
        readShort( stream, pDest.unknown_22 );
        readObject( stream, pDest.unknown_24 );
        pDest.unknown_24 /= unknown_24_SCALE;
        stream->skip( 2 * 2 ); // 2 * uint16 unused
    }


    //---------------------------------------------------------------------
    void
    BackgroundFileSerializer::readTexture( Ogre::DataStreamPtr &stream
                                          ,BackgroundFile *pDest )
    {
        readSectionHeader( stream, SECTION_NAME_TEXTURE );
        Page *pages( pDest->getPages() );
        for( size_t i(0); i < BackgroundFile::PAGE_COUNT; ++i )
        {
            readObject( stream, pages[i] );
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

        if( pDest.value_size == 2 )
        {
            Ogre::LogManager::getSingleton().stream()
                << "Warning: Page value_size == 2 @" << stream->tell();
        }

        size_t data_size( pDest.value_size * BackgroundFile::PAGE_DATA_SIZE );
        pDest.data.clear();
        pDest.data.resize( data_size );
        stream->read( &pDest.data[0], data_size );
    }

    //---------------------------------------------------------------------
}
