/*
-----------------------------------------------------------------------------
The MIT License (MIT)

Copyright (c) 2013-08-11 Tobias Peters <tobias.peters@kreativeffekt.at>

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
#ifndef __QGearsPFile_H__
#define __QGearsPFile_H__

#include <OgreAxisAlignedBox.h>
#include <OgreColourValue.h>
#include <OgreMesh.h>
#include <OgreResource.h>
#include <OgreVector2.h>
#include <OgreVector3.h>

#include "common/TypeDefine.h"

#include "QGearsManualObject.h"

namespace QGears
{
    class PFile
    {
    public:

        PFile();
        virtual ~PFile();

        virtual bool    isValid( void );
        virtual bool    isPolygonDefinitionListValid( void );
        virtual void    addGroups( Ogre::Mesh *mesh, const String &bone_name
                                  ,const String &rsd_name) const;

        //-----------------------------------------------------------------
        struct Edge
        {
            uint16 index[2];
        };

        struct PolygonDefinition
        {
            uint16 unknown_00;
            uint16 vertex[3];
            uint16 normal[3];
            uint16 edge[3];
            uint16 unknown_14;
            uint16 unknown_16;
        };

        struct RenderInformation
        {
            uint8 unknown[100];
        };

        struct Group
        {
            uint32 primitive_type;
            uint32 polygon_start_index;
            uint32 num_polygons;
            uint32 vertex_start_index;
            uint32 num_vertices;
            uint32 edge_start_index;
            uint32 num_edges;
            uint32 unknown_1C;
            uint32 unknown_20;
            uint32 unknown_24;
            uint32 unknown_28;
            uint32 texture_coordinate_start_index;
            uint32 has_texture;
            uint32 texture_index;
        };

        typedef std::vector<Ogre::Vector3>          VertexList;
        typedef std::vector<Ogre::Vector3>          NormalList;
        typedef std::vector<Ogre::Vector3>          Unkown1List;
        typedef std::vector<Ogre::Vector2>          TextureCoordinateList;
        typedef std::vector<Ogre::ColourValue>      VertexColorList;
        typedef std::vector<Ogre::ColourValue>      PolygonColorList;
        typedef std::vector<Edge>                   EdgeList;
        typedef std::vector<PolygonDefinition>      PolygonDefinitionList;
        typedef std::vector<Group>                  GroupList;
        typedef std::vector<Ogre::AxisAlignedBox>   BBoxList;

        virtual VertexList&             getVertices()           { return m_vertices; };
        virtual NormalList&             getNormals()            { return m_normals; };
        virtual Unkown1List&            getUnknown1()           { return m_unknown1; };
        virtual TextureCoordinateList&  getTextureCoordinates() { return m_texture_coordinates; };
        virtual VertexColorList&        getVertexColors()       { return m_vertex_colors; };
        virtual PolygonColorList&       getPolygonColors()      { return m_polygon_colors; };
        virtual EdgeList&               getEdges()              { return m_edges; };
        virtual PolygonDefinitionList&  getPolygonDefinitions() { return m_polygon_definitions; };
        virtual GroupList&              getGroups()             { return m_groups; };
        virtual BBoxList&               getBBoxes()             { return m_bboxes; };

    protected:
        //virtual void loadImpl();
        //virtual void unloadImpl();
        //irtual size_t calculateSize() const;

        virtual void    addGroup( const Group &group, ManualObject &mo
                                 ,const String &sub_name
                                 ,const String &material_name
                                 ,const Ogre::Bone *bone ) const;
        virtual Ogre::Vector3   getPosition( const Ogre::Bone *bone ) const;

        static const Ogre::Quaternion STATIC_ROTATION;
        static Ogre::Quaternion createStaticRotation();
    private:
        VertexList              m_vertices;
        NormalList              m_normals;
        Unkown1List             m_unknown1;
        TextureCoordinateList   m_texture_coordinates;
        VertexColorList         m_vertex_colors;
        PolygonColorList        m_polygon_colors;
        EdgeList                m_edges;
        PolygonDefinitionList   m_polygon_definitions;
        GroupList               m_groups;
        BBoxList                m_bboxes;
    };
}

#endif // __QGearsPFile_H__
