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
#include "QGearsPFileSerializer.h"

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
    };

    //---------------------------------------------------------------------
    void
    PFileSerializer::readFileHeader( Ogre::DataStreamPtr &stream )
    {
        size_t header_size( sizeof( m_header ) );
        stream->read( &m_header, header_size );
        flipFromLittleEndian( &m_header, 4, header_size / 4 );
        Ogre::Log::Stream log( Ogre::LogManager::getSingleton().stream() );

        log  << "\nversion:      " << m_header.version
             << "\nvertex_type:  " << m_header.vertex_type
             << "\nnum_vertices: " << m_header.num_vertices
             << "\nnum_normals:  " << m_header.num_normals
             << "\n";
    }

    //---------------------------------------------------------------------
    void
    PFileSerializer::readObject( Ogre::DataStreamPtr &stream
                                ,Ogre::Vector2 &pDest )
    {
        float v[2];
        readFloats( stream, v, 2 );
        pDest.x = v[0];
        pDest.y = v[1];
    }

    //---------------------------------------------------------------------
    void
    PFileSerializer::readObject( Ogre::DataStreamPtr &stream
                                ,Ogre::Vector3 &pDest )
    {
        float tmp[3];
        readFloats( stream, tmp, 3 );
        pDest.x = tmp[0];
        pDest.y = tmp[1];
        pDest.z = tmp[2];
    }

    //---------------------------------------------------------------------
    void
    PFileSerializer::readObject( Ogre::DataStreamPtr &stream
                                ,Ogre::ColourValue &pDest )
    {
        Ogre::uint32 tmp;
        readInts( stream, &tmp, 1 );
        pDest.setAsARGB( tmp );
    }

    //---------------------------------------------------------------------
    void
    PFileSerializer::readObject( Ogre::DataStreamPtr &stream
                                ,Ogre::AxisAlignedBox &pDest )
    {
        Ogre::Vector3 tmp;
        readObject( stream, tmp );
        pDest.setMaximum( tmp );

        readObject( stream, tmp );
        pDest.setMinimum( tmp );
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
    PFileSerializer::importPFile( Ogre::DataStreamPtr &stream, PFile* pDest )
    {
        Ogre::Log::Stream log( Ogre::LogManager::getSingleton().stream() );
        log << "Info: reading header\n";
        readFileHeader( stream );

        log << "Info: reading m_vertices " << m_header.num_vertices << " @" << stream->tell() << "\n";
        readVector( stream, pDest->getVertices(), m_header.num_vertices );

        log << "Info: reading m_normals " << m_header.num_normals << " @" << stream->tell() << "\n";
        readVector( stream, pDest->getNormals(), m_header.num_normals );

        log << "Info: reading m_unknown1 " << m_header.num_unknown1 << " @" << stream->tell() << "\n";
        readVector( stream, pDest->getUnknown1(), m_header.num_unknown1 );

        log << "Info: reading m_texture_coordinates " << m_header.num_texture_coordinates << " @" << stream->tell() << "\n";
        readVector( stream, pDest->getTextureCoordinates()
                   ,m_header.num_texture_coordinates );

        log << "Info: reading m_vertex_colors " << m_header.num_vertex_colors << " @" << stream->tell() << "\n";
        readVector( stream, pDest->getVertexColors()
                   ,m_header.num_vertex_colors );

        log << "Info: reading m_polygon_colors " << m_header.num_polygons << " @" << stream->tell() << "\n";
        readVector( stream, pDest->getPolygonColors(), m_header.num_polygons );

        log << "Info: reading m_edges " << m_header.num_edges << " @" << stream->tell() << "\n";
        readVector( stream, pDest->getEdges(), m_header.num_edges );

        log << "Info: reading m_polygon_definitions " << m_header.num_polygons << " @" << stream->tell() << "\n";
        readVector( stream, pDest->getPolygonDefinitions()
                   ,m_header.num_polygons );

        stream->skip( m_header.num_hundreds * sizeof( RenderInformation ) );

        log << "Info: reading m_groups " << m_header.num_groups << " @" << stream->tell() << "\n";
        readVector( stream, pDest->getGroups(), m_header.num_groups );

        stream->skip( 4 );
        log << "Info: reading m_bboxes " << m_header.num_bboxes << " @" << stream->tell() << "\n";
        readVector( stream,pDest->getBBoxes(), m_header.num_bboxes );

        if( !pDest->isValid() )
        {
            // TODO throw invalid params exception
        }
    }

    //---------------------------------------------------------------------
}
