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
#include "data/QGearsPFileSerializer.h"

#include <OgreLogManager.h>

namespace QGears
{
    //---------------------------------------------------------------------
    PFileSerializer::PFileSerializer() :
        Serializer()
    {
    }

    //---------------------------------------------------------------------
    PFileSerializer::~PFileSerializer()
    {
    }

    //---------------------------------------------------------------------
    template<typename ValueType>
    void
    PFileSerializer::readVector( Ogre::DataStreamPtr &stream
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

    //---------------------------------------------------------------------
    void
    PFileSerializer::readFileHeader( Ogre::DataStreamPtr &stream )
    {
        size_t header_size( sizeof( m_header ) );
        stream->read( &m_header, header_size );
        flipFromLittleEndian( &m_header, 4, header_size / 4 );
    }

    //---------------------------------------------------------------------
    void
    PFileSerializer::readObject( Ogre::DataStreamPtr &stream
                                ,Edge &pDest )
    {
        readShorts( stream, pDest.index, 2 );
        Ogre::Log::Stream log( Ogre::LogManager::getSingleton().stream() );
    }

    //---------------------------------------------------------------------
    void
    PFileSerializer::readObject( Ogre::DataStreamPtr &stream, Colour &pDest )
    {
        uint32 colour;
        readInt( stream, colour );
        pDest.setAsARGB( colour );
    }

    //---------------------------------------------------------------------
    void
    PFileSerializer::readObject( Ogre::DataStreamPtr &stream
                                ,PolygonDefinition &pDest )
    {
        size_t definition_size( sizeof(pDest) );
        stream->read( &pDest, definition_size );
        flipFromLittleEndian( &pDest, 2, definition_size / 2 );
    }

    //---------------------------------------------------------------------
    void
    PFileSerializer::readObject( Ogre::DataStreamPtr &stream
                                ,Group &pDest )
    {
        size_t definition_size( sizeof(pDest) );
        stream->read( &pDest, definition_size );
        flipFromLittleEndian( &pDest, 4, definition_size / 4 );
    }

    //---------------------------------------------------------------------
    void
    PFileSerializer::readObject( Ogre::DataStreamPtr &stream
                                ,BBoxEntry &pDest )
    {
        readInts( stream, &(pDest.unknown), 1 );
        readObject( stream, pDest.bbox );
    }

    //---------------------------------------------------------------------
    void
    PFileSerializer::importPFile( Ogre::DataStreamPtr &stream, PFile* pDest )
    {
        readFileHeader( stream );
        readVector( stream, pDest->getVertices(), m_header.num_vertices );
        readVector( stream, pDest->getNormals(), m_header.num_normals );
        readVector( stream, pDest->getUnknown1(), m_header.num_unknown1 );
        readVector( stream, pDest->getTextureCoordinates()
                   ,m_header.num_texture_coordinates );
        readVector( stream, pDest->getVertexColors()
                   ,m_header.num_vertex_colors );
        readVector( stream, pDest->getPolygonColors(), m_header.num_polygons );
        readVector( stream, pDest->getEdges(), m_header.num_edges );
        readVector( stream, pDest->getPolygonDefinitions()
                   ,m_header.num_polygons );

        stream->skip( m_header.num_materials * sizeof( MaterialInformation ) );

        readVector( stream, pDest->getGroups(), m_header.num_groups );
        readVector( stream, pDest->getBBoxes(), m_header.num_bboxes );
    }

    //---------------------------------------------------------------------
}
