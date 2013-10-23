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
#include "common/QGearsManualObject.h"

#include "data/QGearsRSDFile.h"

namespace QGears
{
    class PFile : public Ogre::Resource
    {
    public:

        PFile( Ogre::ResourceManager *creator, const String &name
              ,Ogre::ResourceHandle handle, const String &group
              ,bool isManual = false, Ogre::ManualResourceLoader *loader = NULL );

        virtual ~PFile();

        virtual bool    isValid( void );
        virtual bool    isPolygonDefinitionListValid( void );
        virtual void    addGroups( Ogre::Mesh *mesh, const String &bone_name
                                  ,const RSDFilePtr &rsd ) const;

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

        struct MaterialInformation
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

        struct BBoxEntry
        {
            uint32 unknown;
            Ogre::AxisAlignedBox bbox;
        };

        typedef Ogre::ColourValue               Colour;

        typedef std::vector<Ogre::Vector3>      VertexList;
        typedef std::vector<Ogre::Vector3>      NormalList;
        typedef std::vector<Ogre::Vector3>      Unkown1List;
        typedef std::vector<Ogre::Vector2>      TextureCoordinateList;
        typedef std::vector<Colour>             VertexColorList;
        typedef std::vector<Colour>             PolygonColorList;
        typedef std::vector<Edge>               EdgeList;
        typedef std::vector<PolygonDefinition>  PolygonDefinitionList;
        typedef std::vector<Group>              GroupList;
        typedef std::vector<BBoxEntry>          BBoxList;

        virtual VertexList&             getVertices()           { return m_vertices; }
        virtual NormalList&             getNormals()            { return m_normals; }
        virtual Unkown1List&            getUnknown1()           { return m_unknown1; }
        virtual TextureCoordinateList&  getTextureCoordinates() { return m_texture_coordinates; }
        virtual VertexColorList&        getVertexColors()       { return m_vertex_colors; }
        virtual PolygonColorList&       getPolygonColors()      { return m_polygon_colors; }
        virtual EdgeList&               getEdges()              { return m_edges; }
        virtual PolygonDefinitionList&  getPolygonDefinitions() { return m_polygon_definitions; }
        virtual GroupList&              getGroups()             { return m_groups; }
        virtual BBoxList&               getBBoxes()             { return m_bboxes; }

        static const String RESOURCE_TYPE;

    protected:
        virtual void loadImpl();
        virtual void unloadImpl();
        virtual size_t calculateSize() const;

        virtual void    addGroup( const Group &group, ManualObject &mo
                                 ,const String &sub_name
                                 ,const String &material_base_name
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

    //-------------------------------------------------------------------------
    class PFilePtr : public Ogre::SharedPtr<PFile>
    {
    public:
        PFilePtr() : Ogre::SharedPtr<PFile>() {}
        explicit PFilePtr( PFile *rep ) : Ogre::SharedPtr<PFile>(rep) {}
        PFilePtr( const PFilePtr &r ) : Ogre::SharedPtr<PFile>(r) {}
        PFilePtr( const Ogre::ResourcePtr &r ) : Ogre::SharedPtr<PFile>()
        {
            if( r.isNull() )
                return;
            // lock & copy other mutex pointer
            OGRE_LOCK_MUTEX(*r.OGRE_AUTO_MUTEX_NAME)
            OGRE_COPY_AUTO_SHARED_MUTEX(r.OGRE_AUTO_MUTEX_NAME)
            pRep = static_cast<PFile*>(r.getPointer());
            pUseCount = r.useCountPointer();
            useFreeMethod = r.freeMethod();
            if (pUseCount)
            {
                ++(*pUseCount);
            }
        }

        /// Operator used to convert a ResourcePtr to a PFilePtr
        PFilePtr& operator=( const Ogre::ResourcePtr& r )
        {
            if(pRep == static_cast<PFile*>(r.getPointer()))
                return *this;
            release();
            if( r.isNull() )
                return *this; // resource ptr is null, so the call to release above has done all we need to do.
            // lock & copy other mutex pointer
            OGRE_LOCK_MUTEX(*r.OGRE_AUTO_MUTEX_NAME)
            OGRE_COPY_AUTO_SHARED_MUTEX(r.OGRE_AUTO_MUTEX_NAME)
            pRep = static_cast<PFile*>(r.getPointer());
            pUseCount = r.useCountPointer();
            useFreeMethod = r.freeMethod();
            if (pUseCount)
            {
                ++(*pUseCount);
            }
            return *this;
        }
    };
}

#endif // __QGearsPFile_H__
