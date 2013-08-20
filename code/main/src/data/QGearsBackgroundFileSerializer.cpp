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
        stream->read( pDest->getPaletteIndices(), BackgroundFile::PALETTE_ENTRY_COUNT );
    }

    //---------------------------------------------------------------------
    void
    BackgroundFileSerializer::readBackground( Ogre::DataStreamPtr &stream
                                             ,BackgroundFile *pDest )
    {
        readSectionHeader( stream, SECTION_NAME_BACK );
    }

    //---------------------------------------------------------------------
    void
    BackgroundFileSerializer::importBackgroundFile( Ogre::DataStreamPtr &stream
                                                   ,BackgroundFile *pDest )
    {
        readFileHeader( stream );

        uint8 layer_0_enabled;
        stream->read( &layer_0_enabled, 1 );

        readPallete( stream, pDest );

        stream->skip( 2 * 2 ); // 2 *  uint16 unused;

        readBackground( stream, pDest );
    }

    //---------------------------------------------------------------------
}
