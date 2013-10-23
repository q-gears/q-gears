/*
-----------------------------------------------------------------------------
The MIT License (MIT)

Copyright (c) 2013-08-16 Tobias Peters <tobias.peters@kreativeffekt.at>

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
#include "data/QGearsRSDFile.h"

#include <OgreMaterialManager.h>
#include <OgrePass.h>
#include <OgreTechnique.h>

#include "common/QGearsStringUtil.h"
#include "data/QGearsRSDFileSerializer.h"

namespace QGears
{

    //---------------------------------------------------------------------
    const Ogre::String  RSDFile::RESOURCE_TYPE( "QGearsRSDFile" );

    //---------------------------------------------------------------------
    RSDFile::RSDFile( Ogre::ResourceManager *creator
                     ,const Ogre::String &name, Ogre::ResourceHandle handle
                     ,const Ogre::String &group, bool isManual
                     ,Ogre::ManualResourceLoader *loader ) :
        Ogre::Resource( creator, name, handle, group, isManual, loader )
    {
        createParamDictionary( RESOURCE_TYPE );
    }

    //---------------------------------------------------------------------
    RSDFile::~RSDFile()
    {
        unload();
    }

    //---------------------------------------------------------------------
    void
    RSDFile::loadImpl()
    {
        RSDFileSerializer serializer;
        Ogre::DataStreamPtr stream( Ogre::ResourceGroupManager::getSingleton().openResource( mName, mGroup, true, this ) );
        serializer.importRSDFile( stream, this );

        Ogre::MaterialManager &material_manager( Ogre::MaterialManager::getSingleton() );

        const String material_base_name( getMaterialBaseName() );
        Ogre::MaterialPtr material;
        for( size_t i(0); i <= getTextureNameCount(); ++i )
        {
            Ogre::String material_name( material_base_name + "/" + Ogre::StringConverter::toString( i ) );
            material = material_manager.getByName( material_name, mGroup );
            if( material.isNull() )
            {
#ifndef NDEBUG
                Ogre::LogManager::getSingleton().stream()
                        << " creating Material for RSDFile"
                        << " '" << material_name << "'";
#endif
                material = material_manager.create( material_name, mGroup );
                material->_notifyOrigin( getName() );
                m_materials.push_back( material );
                Ogre::Pass *pass( material->getTechnique( 0 )->getPass( 0 ) );
                pass->setVertexColourTracking( Ogre::TVC_AMBIENT );
                if( i > 0 )
                {
                    addTexture( pass, i - 1 );
                }
            }
        }
    }

    //---------------------------------------------------------------------
    void
    RSDFile::unloadImpl()
    {
        // clear data here
        m_polygon_name.clear();
        m_material_name.clear();
        m_group_name.clear();
        m_texture_names.clear();
        for( MaterialList::iterator it( m_materials.begin() )
            ;it != m_materials.end()
            ;++it )
        {
            Ogre::MaterialManager::getSingleton().remove( (*it)->getHandle() );
        }
        m_materials.clear();
    }

    //---------------------------------------------------------------------
    size_t
    RSDFile::calculateSize() const
    {
        size_t size_texture_names( 0 );
        for( TextureNameList::const_iterator it( m_texture_names.begin() )
            ;it != m_texture_names.end()
            ;++it )
        {
            size_texture_names += it->size();
        }

        return m_polygon_name.size()
              +m_material_name.size()
              +m_group_name.size()
              +size_texture_names;
    }

    //---------------------------------------------------------------------
    String
    RSDFile::getMaterialBaseName( void ) const
    {
        String base_name, ext, path;
        StringUtil::splitPath( getName(), path );
        StringUtil::splitBase( m_material_name, base_name );
        StringUtil::toLowerCase( base_name );
        return path + base_name;
    }

    //---------------------------------------------------------------------
    void
    RSDFile::addTexture( Ogre::Pass *pass, const size_t index ) const
    {
        String texture_name;
        StringUtil::splitPath( getName(), texture_name );
        texture_name += m_texture_names[ index ];

        if ( StringUtil::endsWith( texture_name, EXT_TIM ) )
        {
            StringUtil::toLowerCase( texture_name );
            if( !Ogre::ResourceGroupManager::getSingleton().resourceExists( mGroup, texture_name ) )
            {
                texture_name = StringUtil::replaceAll( texture_name, EXT_TIM, EXT_TEX );
            }
        }

        if( !texture_name.empty() )
        {
            pass->setAlphaRejectFunction( Ogre::CMPF_GREATER );
            pass->setAlphaRejectValue( 0 );
            Ogre::TextureUnitState *texture_unit( pass->createTextureUnitState() );
            texture_unit->setTextureName( texture_name );
            texture_unit->setNumMipmaps( 0 );
            texture_unit->setTextureFiltering( Ogre::TFO_NONE );
        }
    }

    //---------------------------------------------------------------------
    void
    RSDFile::setPolygonName( const String &polygon_name )
    {
        m_polygon_name = polygon_name;
    }

    //---------------------------------------------------------------------
    void
    RSDFile::setMaterialName( const String &material_name )
    {
        m_material_name = material_name;
    }

    //---------------------------------------------------------------------
    void
    RSDFile::setGroupName( const String &group_name )
    {
        m_group_name = group_name;
    }

    //---------------------------------------------------------------------
    const String&
    RSDFile::getPolygonName( void ) const
    {
        return m_polygon_name;
    }

    //---------------------------------------------------------------------
    const String&
    RSDFile::getMaterialName( void ) const
    {
        return m_material_name;
    }

    //---------------------------------------------------------------------
    const String&
    RSDFile::getGroupName( void ) const
    {
        return m_group_name;
    }

    //---------------------------------------------------------------------
    size_t
    RSDFile::getTextureNameCount( void ) const
    {
        return m_texture_names.size();
    }

    //---------------------------------------------------------------------
    RSDFile::TextureNameList&
    RSDFile::getTextureNames( void )
    {
        return m_texture_names;
    }

    //---------------------------------------------------------------------
}
