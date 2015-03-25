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
#include "data/QGearsAFileSerializer.h"

#include <OgreException.h>
#include <OgreLogManager.h>
#include "data/QGearsHRCFile.h"

namespace QGears
{
    //-------------------------------------------------------------------------
    AFileSerializer::AFileSerializer() :
        Serializer()
    {
    }

    //-------------------------------------------------------------------------
    AFileSerializer::~AFileSerializer()
    {
    }

    //---------------------------------------------------------------------
    template<typename ValueType>
    void
    AFileSerializer::readVector( Ogre::DataStreamPtr &stream
                                ,std::vector<ValueType> &pDest
                                ,size_t count )
    {
        pDest.clear();
        pDest.reserve( count );
        for( size_t i( count ); i--; )
        {
            ValueType in_tmp;
            readObject( stream, in_tmp );
            pDest.push_back( in_tmp );
        }
    }

    //-------------------------------------------------------------------------
    void
    AFileSerializer::readFileHeader( Ogre::DataStreamPtr &stream )
    {
        size_t header_size( sizeof( m_header ) );
        stream->read( &m_header, header_size );
        flipFromLittleEndian( &m_header, 4, header_size / 4 );
    }

    //-------------------------------------------------------------------------
    void
    AFileSerializer::readObject( Ogre::DataStreamPtr &stream, AFile::Frame &pDest )
    {
        readObject( stream, pDest.root_rotation );
        readObject( stream, pDest.root_translation );
        pDest.root_translation = pDest.root_translation / HRCFile::kDownScaler;
        readVector( stream, pDest.bone_rotations, m_header.bone_count );
    }

    //-------------------------------------------------------------------------
    void
    AFileSerializer::importAFile( Ogre::DataStreamPtr &stream, AFile* pDest )
    {
        readFileHeader( stream );

        if( m_header.version != 1 )
        {
            OGRE_EXCEPT(Ogre::Exception::ERR_INVALIDPARAMS
                ,"Animation has unsupported version only version 1 supported"
                ,"AFileSerializer::importAFile" );
        }

        pDest->setBoneCount( m_header.bone_count );
        readVector( stream, pDest->getFrames(), m_header.frame_count );
    }

    //-------------------------------------------------------------------------
}
