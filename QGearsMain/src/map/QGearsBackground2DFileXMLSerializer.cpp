/*
-----------------------------------------------------------------------------
The MIT License (MIT)

Copyright (c) 2013-08-26 Tobias Peters <tobias.peters@kreativeffekt.at>

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
#include "data/QGearsBackground2DFileXMLSerializer.h"

#include <OgreLogManager.h>
#include <OgreException.h>

namespace QGears
{
    //---------------------------------------------------------------------
    Background2DFileXMLSerializer::Background2DFileXMLSerializer() :
        XMLSerializer()
    {
    }

    //---------------------------------------------------------------------
    Background2DFileXMLSerializer::~Background2DFileXMLSerializer()
    {
    }

    //---------------------------------------------------------------------
    void
    Background2DFileXMLSerializer::importBackground2DFile( Ogre::DataStreamPtr &stream, Background2DFile* pDest )
    {
        size_t start_position( stream->tell() );
        readFileHeader( stream );

        uint32 section_offsets[ m_header.section_count ];
        readInts( stream, section_offsets, m_header.section_count );

        Ogre::DataStreamPtr section;
        for( size_t i(0); i < m_header.section_count; ++i )
        {
            size_t current_offset( stream->tell() - start_position );
            size_t section_gap( section_offsets[i] - current_offset );
            if( current_offset > section_offsets[i] )
            {
                OGRE_EXCEPT(Ogre::Exception::ERR_INVALIDPARAMS
                    ,"FLevel sections overlap"
                    ,"FLevelFileSerializer::importFLevelFile" );
            }
            else if( section_gap )
            {
                stream->skip( section_gap );
                Ogre::LogManager::getSingleton().stream()
                    << "Warning: skiping gap in front of section " << i
                    << " gap size " << section_gap
                    << " FLevelFileSerializer::importFLevelFile";
            }

            readSectionData( stream, section );
            readSection( section, pDest, i );
            section->close();
            section.setNull();
        }
        readEnd( stream );
    }

    //---------------------------------------------------------------------
}
