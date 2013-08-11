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
    Ogre::ManualObject*
    PFile::getManualObject( void ) const
    {
        Ogre::Log::Stream log( Ogre::LogManager::getSingleton().stream() );
        Ogre::SceneManager* scene_manager( Ogre::Root::getSingleton().getSceneManager( "Scene" ) );
        Ogre::ManualObject* mo( scene_manager->createManualObject() );

        for( size_t g(0); g < m_groups.size(); ++g )
        {
            const Group& group( m_groups[g] );
            log << "\nprimitive_type                : " << group.primitive_type
                << "\npolygon_start_index           : " << group.polygon_start_index
                << "\nnum_polygons                  : " << group.num_polygons
                << "\nvertex_start_index            : " << group.vertex_start_index
                << "\nnum_vertices                  : " << group.num_vertices
                << "\nedge_start_index              : " << group.edge_start_index
                << "\nnum_edges                     : " << group.num_edges
                << "\nunknown_1C                    : " << group.unknown_1C
                << "\nunknown_20                    : " << group.unknown_20
                << "\nunknown_24                    : " << group.unknown_24
                << "\nunknown_28                    : " << group.unknown_28
                << "\ntexture_coordinate_start_index: " << group.texture_coordinate_start_index
                << "\nhas_textures                  : " << group.has_texture
                << "\ntexture_index                 : " << group.texture_index
                << "\n";

            String material_name( "test/" + Ogre::StringConverter::toString(g) );

            mo->begin( material_name, Ogre::RenderOperation::OT_TRIANGLE_LIST );

            size_t end_index( group.polygon_start_index + group.num_polygons );
            for( size_t p( group.polygon_start_index ); p < end_index; ++p )
            {
                for( int i(3); i--; )
                {
                    const PolygonDefinition& polygon( m_polygon_definitions[p] );
                    uint32 v( group.vertex_start_index
                             +polygon.vertex[i] )
                          ,n( 0 + polygon.normal[i] )
                          ,t( group.texture_coordinate_start_index
                             +polygon.vertex[i] );
                    mo->position( m_vertices[ v ] );
                    mo->colour( m_vertex_colors[ v ] );
                    mo->normal( m_normals[ n ] );
                    if( group.has_texture )
                    {
                        mo->textureCoord( m_texture_coordinates[t] );
                    }
                }
            }
            mo->end();
        }

        return mo;
    }
    //---------------------------------------------------------------------
}
