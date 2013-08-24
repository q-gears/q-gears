/*
-----------------------------------------------------------------------------
The MIT License (MIT)

Copyright (c) 2013-08-24 Tobias Peters <tobias.peters@kreativeffekt.at>

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
#include "data/QGearsFLevelFileSerializer.h"

#include <OgreLogManager.h>
#include <OgreException.h>

namespace QGears
{
    //---------------------------------------------------------------------
    const String    FLevelFileSerializer::TAG_FILE_END  ("FINAL FANTASY7");

    //---------------------------------------------------------------------
    FLevelFileSerializer::FLevelFileSerializer() :
        Serializer()
    {
    }

    //---------------------------------------------------------------------
    FLevelFileSerializer::~FLevelFileSerializer()
    {
    }

    //---------------------------------------------------------------------
    void
    FLevelFileSerializer::importFLevelFile( Ogre::DataStreamPtr &stream, FLevelFile* pDest )
    {
        readFileHeader( stream );

        if( m_header.version != 0 )
        {
            OGRE_EXCEPT(Ogre::Exception::ERR_INVALIDPARAMS
                ,"FLevel has unsupported version"
                ,"FLevelFileSerializer::importFLevelFile" );
        }

        if( m_header.section_count != SECTION_COUNT )
        {
            Ogre::LogManager::getSingleton().stream()
                << "Warning: FLevel section_count has unexpected value "
                << m_header.section_count << " should be " << SECTION_COUNT
                << " FLevelFileSerializer::importFLevelFile";
        }

        uint32 section_offsets[ m_header.section_count ];

        for( size_t section(0); section < m_header ); ++section )
        {

        }
        readEnd();
    }

    //---------------------------------------------------------------------
    void
    FLevelFileSerializer::readFileHeader( Ogre::DataStreamPtr &stream )
    {
        readShort( stream, m_header.version );
        readInt(   stream, m_header.section_count );
    }

    //---------------------------------------------------------------------
    void
    FLevelFileSerializer::readSection( Ogre::DataStreamPtr &stream
                                      ,Ogre::DataStreamPtr &out_buffer )
    {
        uint32 length( 0 );
        readInt( stream, length );
        // TODO: implement SubDataStream class to restrict access size etc
        // so we don't have to copy the whole memory
        Ogre::MemoryDataStream *buffer( new Ogre::MemoryDataStream( length ) );
        stream->read( buffer->getPtr(), length );
        out_buffer = buffer;
    }

    //---------------------------------------------------------------------
    void
    FLevelFileSerializer::readEnd( Ogre::DataStreamPtr &stream )
    {
        readEndString( stream, TAG_FILE_END );
    }

    //---------------------------------------------------------------------
}
