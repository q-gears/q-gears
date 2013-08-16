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
#include "QGearsPFile.h"

#include <OgreLog.h>
#include <OgreRoot.h>
#include <OgreSceneManager.h>

namespace QGears
{
    //---------------------------------------------------------------------
    const Ogre::Quaternion PFile::STATIC_ROTATION( PFile::createStaticRotation() );

    //---------------------------------------------------------------------
    PFile::PFile()
    {
        //ctor
    }

    //---------------------------------------------------------------------
    PFile::~PFile()
    {
        //dtor
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
                     ,const String &rsd_name ) const
    {
        Ogre::Log::Stream log( Ogre::LogManager::getSingleton().stream() );
        const Ogre::SkeletonPtr skeleton( mesh->getSkeleton() );
        ManualObject mo( mesh );
        for( size_t g(0); g < m_groups.size(); ++g )
        {
            /*
            log << "\n primitive_type                : " << group.primitive_type
                << "\n polygon_start_index           : " << group.polygon_start_index
                << "\n num_polygons                  : " << group.num_polygons
                << "\n vertex_start_index            : " << group.vertex_start_index
                << "\n num_vertices                  : " << group.num_vertices
                << "\n edge_start_index              : " << group.edge_start_index
                << "\n num_edges                     : " << group.num_edges
                << "\n unknown_1C                    : " << group.unknown_1C
                << "\n unknown_20                    : " << group.unknown_20
                << "\n unknown_24                    : " << group.unknown_24
                << "\n unknown_28                    : " << group.unknown_28
                << "\n texture_coordinate_start_index: " << group.texture_coordinate_start_index
                << "\n has_textures                  : " << group.has_texture
                << "\n texture_index                 : " << group.texture_index
                << "\n";
            */
            String sub_name( bone_name + "/" + rsd_name + "/" + Ogre::StringConverter::toString(g) );
            String material_name( mesh->getName() + "/" + sub_name );
            addGroup( m_groups[g], mo, sub_name, material_name, skeleton->getBone( bone_name ) );
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
                    ,const String &sub_name, const String &material_name
                    ,const Ogre::Bone *bone ) const
    {
        Ogre::Radian angle( Ogre::Degree( 180 ) );
        Ogre::Quaternion rot( angle, Ogre::Vector3::UNIT_X );
        size_t vertex_count( group.num_polygons * 3 );
        size_t index_count( vertex_count );
        mo.begin( sub_name, material_name, vertex_count, index_count );
        size_t end_index( group.polygon_start_index + group.num_polygons );
        uint16 bone_handle( bone->getHandle() ), index( 0 );
        for( size_t p( group.polygon_start_index ); p < end_index; ++p )
        {
            const PolygonDefinition& polygon( m_polygon_definitions[p] );
            for( int i(3); i--; )
            {
                uint32 v( group.vertex_start_index
                         +polygon.vertex[i] )
                      ,n( 0 + polygon.normal[i] )
                      ,t( group.texture_coordinate_start_index
                         +polygon.vertex[i] );
                mo.position( ( STATIC_ROTATION *  m_vertices[ v ] )
                            + getPosition( bone ) );
                mo.colour( m_vertex_colors[ v ] );
                mo.normal( STATIC_ROTATION * m_normals[ n ] );
                if( group.has_texture )
                {
                    mo.textureCoord( m_texture_coordinates[t] );
                }
                mo.bone( index, bone_handle ); mo.index( index++ );
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
