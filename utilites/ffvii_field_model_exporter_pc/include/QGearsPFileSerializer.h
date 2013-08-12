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
#ifndef __QGearsPFileSerializer_H__
#define __QGearsPFileSerializer_H__

#include "common/TypeDefine.h"
#include "QGearsPFile.h"
#include "QGearsSerializer.h"

namespace QGears
{
    class PFileSerializer : public Serializer
    {
    public:
                        PFileSerializer();
        virtual        ~PFileSerializer();

        virtual void 	importPFile( Ogre::DataStreamPtr &stream, PFile* pDest );

        struct Header
        {
            Ogre::uint32 version;
            Ogre::uint32 unknown_04;
            Ogre::uint32 vertex_type;
            Ogre::uint32 num_vertices;
            Ogre::uint32 num_normals;
            Ogre::uint32 num_unknown1;
            Ogre::uint32 num_texture_coordinates;
            Ogre::uint32 num_vertex_colors;
            Ogre::uint32 num_edges;
            Ogre::uint32 num_polygons;
            Ogre::uint32 num_unknown2;
            Ogre::uint32 num_unknown3;
            Ogre::uint32 num_hundreds;
            Ogre::uint32 num_groups;
            Ogre::uint32 num_bboxes;
            Ogre::uint32 norm_index_table_flag;
            Ogre::uint32 runtime_data[0x10];
        };

        typedef PFile::Edge Edge;

        typedef PFile::PolygonDefinition PolygonDefinition;
        typedef PFile::RenderInformation RenderInformation;

        typedef PFile::Group Group;

    protected:
        virtual void 	readFileHeader( Ogre::DataStreamPtr &stream );
        virtual void    readObject( Ogre::DataStreamPtr &stream, Edge &pDest );
        virtual void    readObject( Ogre::DataStreamPtr &stream, PolygonDefinition &pDest );
        virtual void    readObject( Ogre::DataStreamPtr &stream, Group &pDest );
        using Serializer::readObject;

        template<typename ValueType>
                void    readVector( Ogre::DataStreamPtr &stream
                                   ,std::vector<ValueType> &pDest
                                   ,size_t count );

    private:
        Header  m_header;
    };
}

#endif // __QGearsPFileSerializer_H__
