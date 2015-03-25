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
#include "data/QGearsHRCFile.h"

#include <OgreLogManager.h>
#include <OgreMeshManager.h>
#include <OgreSkeletonManager.h>

//#include "common/FF7NameLookup.h"
#include "../../SupportedGames/FinalFantasy7/include/common/FF7NameLookup.h"

#include "common/QGearsStringUtil.h"
#include "data/QGearsHRCFileSerializer.h"
#include "data/QGearsHRCMeshLoader.h"
#include "data/QGearsHRCSkeletonLoader.h"

namespace QGears
{
    //---------------------------------------------------------------------
    /*static*/ const String    HRCFile::RESOURCE_TYPE( "QGearsHRCFile" );
    /*static*/ const float     HRCFile::kDownScaler = 1.0f; //33.0f; TODO fix unit tests before changing me

    //---------------------------------------------------------------------
    HRCFile::HRCFile( Ogre::ResourceManager *creator
                     ,const String &name, Ogre::ResourceHandle handle
                     ,const String &group, bool isManual
                     ,Ogre::ManualResourceLoader *loader ) :
        Ogre::Resource( creator, name, handle, group, isManual, loader )
       ,m_mesh_loader( nullptr )
       ,m_skeleton_loader( nullptr )
    {
        createParamDictionary( RESOURCE_TYPE );
    }

    //---------------------------------------------------------------------
    HRCFile::~HRCFile()
    {
        if( m_skeleton_loader )
        {
            Ogre::SkeletonManager::getSingleton().remove( m_skeleton->getHandle() );
            delete m_skeleton_loader;
            m_skeleton_loader = nullptr;
        }
        if( m_mesh_loader )
        {
            Ogre::MeshManager::getSingleton().remove( m_mesh->getHandle() );
            delete m_mesh_loader;
            m_mesh_loader = nullptr;
        }

        m_skeleton.setNull();
        m_mesh.setNull();
        unload();
    }

    //---------------------------------------------------------------------
    void
    HRCFile::loadImpl()
    {
        HRCFileSerializer serializer;
        Ogre::DataStreamPtr stream( Ogre::ResourceGroupManager::getSingleton().openResource( mName, mGroup, true, this ) );
        serializer.importHRCFile( stream, this );


        const String skeleton_file_name( getSkeletonFileName() );
        Ogre::SkeletonManager &skeleton_manager( Ogre::SkeletonManager::getSingleton() );
        m_skeleton = skeleton_manager.getByName( skeleton_file_name, mGroup );
        if( m_skeleton.isNull() )
        {
            assert( m_skeleton_loader == nullptr );
            m_skeleton_loader = new HRCSkeletonLoader( *this );
            m_skeleton = skeleton_manager.create( skeleton_file_name, mGroup, true, m_skeleton_loader );
        }

        const String mesh_file_name( getMeshFileName() );
        Ogre::LogManager::getSingleton().stream()
                << "HRC::loadImpl(): mesh_file_name: " << mesh_file_name;
        Ogre::MeshManager &mesh_manager( Ogre::MeshManager::getSingleton() );
        m_mesh = mesh_manager.getByName( mesh_file_name, mGroup );
        if( m_mesh.isNull() )
        {
            assert( m_mesh_loader == nullptr );
            m_mesh_loader = new HRCMeshLoader( *this );
            m_mesh = mesh_manager.create( mesh_file_name, mGroup, true, m_mesh_loader );
        }
    }

    //---------------------------------------------------------------------
    void
    HRCFile::unloadImpl()
    {
        m_skeleton_name.clear();
        m_bones.clear();
    }

    //---------------------------------------------------------------------
    size_t
    HRCFile::calculateSize( const Bone &bone ) const
    {
        size_t size_rsd_names( 0 );
        for( RSDNameList::const_iterator it( bone.rsd_names.begin() )
            ;it != bone.rsd_names.end()
            ;++it )
        {
            size_rsd_names += it->size();
        }

        return bone.name.size()
              +bone.parent.size()
              +sizeof( bone.length )
              +size_rsd_names;
    }

    //---------------------------------------------------------------------
    size_t
    HRCFile::calculateSize() const
    {
        size_t size_bones( 0 );
        for( BoneList::const_iterator it( m_bones.begin() )
            ;it != m_bones.end()
            ;++it )
        {
            size_bones += calculateSize( *it );
        }

        return m_skeleton_name.size() + size_bones;
    }

    //---------------------------------------------------------------------
    void
    HRCFile::setSkeletonName( const String &name )
    {
        m_skeleton_name = name;
    }

    //---------------------------------------------------------------------
    String
    HRCFile::getSkeletonFileName( void ) const
    {
        String path;
        StringUtil::splitPath( getName(), path );
        return path + m_skeleton_name + EXT_SKELETON;
    }

    //---------------------------------------------------------------------
    String
    HRCFile::getMeshFileName( void ) const
    {
        String base_name;
        StringUtil::splitBase( getName(), base_name );

        return FF7::NameLookup::model( base_name ) + EXT_MESH;
    }

    //---------------------------------------------------------------------
    Ogre::SkeletonPtr
    HRCFile::getSkeleton( void ) const
    {
        m_skeleton->load();
        return m_skeleton;
    }

    //---------------------------------------------------------------------
}
