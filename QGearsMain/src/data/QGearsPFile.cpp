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
#include "data/QGearsPFile.h"

#include <OgreBone.h>
#include <OgreLogManager.h>
#include <OgreStringConverter.h>

#include "common/QGearsStringUtil.h"
#include "data/QGearsPFileSerializer.h"
#include "data/QGearsHRCFile.h"

namespace QGears
{
    //---------------------------------------------------------------------
    const String            PFile::RESOURCE_TYPE( "QGearsPFile" );
    const Ogre::Quaternion  PFile::STATIC_ROTATION( PFile::createStaticRotation() );

    //---------------------------------------------------------------------
    PFile::PFile( Ogre::ResourceManager *creator
                 ,const String &name, Ogre::ResourceHandle handle
                 ,const String &group, bool isManual
                 ,Ogre::ManualResourceLoader *loader ) :
        Ogre::Resource( creator, name, handle, group, isManual, loader )
    {
        createParamDictionary( RESOURCE_TYPE );
    }

    //---------------------------------------------------------------------
    PFile::~PFile()
    {
        unload();
    }

    //---------------------------------------------------------------------
    void
    PFile::loadImpl()
    {
        PFileSerializer serializer;
        Ogre::DataStreamPtr stream( Ogre::ResourceGroupManager::getSingleton().openResource( mName, mGroup, true, this ) );
        serializer.importPFile( stream, this );
    }

    //---------------------------------------------------------------------
    void
    PFile::unloadImpl()
    {
        m_vertices.clear();
        m_normals.clear();
        m_unknown1.clear();
        m_texture_coordinates.clear();
        m_vertex_colors.clear();
        m_polygon_colors.clear();
        m_edges.clear();
        m_polygon_definitions.clear();
        m_groups.clear();
        m_bboxes.clear();
    }

    //---------------------------------------------------------------------
    size_t
    PFile::calculateSize() const
    {
        return m_vertices.size()            * sizeof( m_vertices.front() )
              +m_normals.size()             * sizeof( m_normals.front() )
              +m_unknown1.size()            * sizeof( m_unknown1.front() )
              +m_texture_coordinates.size() * sizeof( m_texture_coordinates.front() )
              +m_vertex_colors.size()       * sizeof( m_vertex_colors.front() )
              +m_polygon_colors.size()      * sizeof( m_polygon_colors.front() )
              +m_edges.size()               * sizeof( m_edges.front() )
              +m_polygon_definitions.size() * sizeof( m_polygon_definitions.front() )
              +m_groups.size()              * sizeof( m_groups.front() )
              +m_bboxes.size()              * sizeof( m_bboxes.front() )
            ;
    }

    //---------------------------------------------------------------------
    bool
    PFile::isValid( void )
    {
        return true
            && isPolygonDefinitionListValid();
    }

    //---------------------------------------------------------------------
    bool
    PFile::isPolygonDefinitionListValid( void )
    {
        Ogre::Log::Stream log( Ogre::LogManager::getSingleton().stream() );

        size_t vertex_count( m_vertices.size() )
              ,normal_count( m_normals.size() )
              ,edge_count  ( m_edges.size() );
        for( size_t p( m_polygon_definitions.size() ); p--; )
        {
            PolygonDefinition& def( m_polygon_definitions[p] );
            for( int i(3); i--; )
            {
                if( def.vertex[i] >= vertex_count )
                {
                    log << "Error: index to vertex is out of Bounds "
                        << " m_polygon_definitions[" << p << "]"
                        << ".vertex[" << i << "]: " << def.vertex[i];
                    return false;
                }
                if( def.normal[i] >= normal_count )
                {
                    log << "Error: index to normal is out of Bounds "
                        << " m_polygon_definitions[" << p << "]"
                        << ".normal[" << i << "]: " << def.normal[i];
                    return false;
                }
                if( def.edge[i] >= edge_count )
                {
                    log << "Error: index to edge is out of Bounds "
                        << " m_polygon_definitions[" << p << "]"
                        << ".edge[" << i << "]: " << def.edge[i];
                    return false;
                }
            }
        }

        return true;
    }

    //---------------------------------------------------------------------
    void
    PFile::addGroups( Ogre::Mesh *mesh, const String &bone_name
                     ,const RSDFilePtr &rsd ) const
    {
        const Ogre::SkeletonPtr skeleton( mesh->getSkeleton() );
        const String material_base_name( rsd->getMaterialBaseName() );
        String rsd_base;
        StringUtil::splitBase( rsd->getName(), rsd_base );

        ManualObject mo( mesh );
        for( size_t g(0); g < m_groups.size(); ++g )
        {
            const String sub_name( bone_name + "/" + rsd_base + "/" + Ogre::StringConverter::toString(g) );
            addGroup( m_groups[g], mo, sub_name, material_base_name, skeleton->getBone( bone_name ) );
        }
    }

    //---------------------------------------------------------------------
    Ogre::Vector3
    PFile::getPosition( const Ogre::Bone *bone ) const
    {
        Ogre::Vector3 pos( 0, 0, 0 );
        const Ogre::Node* node( bone );
        while( node )
        {
            pos.z += node->getPosition().y;
            node = node->getParent();
        }
        return pos;
    }

    //---------------------------------------------------------------------
    void
    PFile::addGroup( const Group &group, ManualObject &mo
                    ,const String &sub_name, const String &material_base_name
                    ,const Ogre::Bone *bone ) const
    {
        size_t material_index( 0 );
        if( group.has_texture )
        {
            material_index = group.texture_index + 1;
        }
        String material_name( material_base_name + "/" + Ogre::StringConverter::toString( material_index ) );
        const uint16 bone_handle( bone->getHandle() );
        const Ogre::Vector3 bone_position( getPosition( bone ) );

        size_t index( 0 );
        size_t vertex_count( group.num_polygons * 3 );
        size_t index_count( vertex_count );
        size_t polygon_end_index( group.polygon_start_index + group.num_polygons );
        mo.begin( sub_name, material_name, vertex_count, index_count );
        for( size_t p( group.polygon_start_index ); p < polygon_end_index; ++p )
        {
            const PolygonDefinition& polygon( m_polygon_definitions[p] );
            for( int i(3); i--; )
            {
                uint32 v( group.vertex_start_index
                         +polygon.vertex[i] )
                      ,n( 0 + polygon.normal[i] )
                      ,t( group.texture_coordinate_start_index
                         +polygon.vertex[i] );
                Ogre::Vector3 pos( m_vertices[ v ] );
                mo.position((STATIC_ROTATION *  (pos / HRCFile::kDownScaler)) + bone_position);
                mo.colour( m_vertex_colors[ v ] );
                mo.normal( STATIC_ROTATION * m_normals[ n ] );
                if( group.has_texture )
                {
                    mo.textureCoord(m_texture_coordinates[t]);
                }
                mo.bone( index, bone_handle );
                mo.index( index++ );
            }
        }
        mo.end();
    }

    //---------------------------------------------------------------------
    Ogre::Quaternion
    PFile::createStaticRotation()
    {
        Ogre::Radian angle( Ogre::Degree( 180 ) );
        return Ogre::Quaternion( angle, Ogre::Vector3::UNIT_X );
    }

    //---------------------------------------------------------------------
}
