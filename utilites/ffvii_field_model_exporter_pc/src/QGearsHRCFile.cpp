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
#include "QGearsHRCFile.h"

#include <OgreBone.h>
#include <OgreMaterialManager.h>
#include <OgreSkeletonManager.h>

#include "QGearsHRCFileSerializer.h"

namespace QGears
{
    //---------------------------------------------------------------------
    const String    HRCFile::ROOT_BONE_NAME( "root" );
    const String    HRCFile::RESOURCE_TYPE( "QGearsHRCFile" );
    const Ogre::Quaternion  HRCFile::ROOT_ORIENTATION( HRCFile::createRootOrientation() );

    //---------------------------------------------------------------------
    HRCFile::HRCFile( Ogre::ResourceManager *creator
                     ,const String &name, Ogre::ResourceHandle handle
                     ,const String &group, bool isManual
                     ,Ogre::ManualResourceLoader *loader ) :
        Ogre::Resource( creator, name, handle, group, isManual, loader )
    {
        createParamDictionary( RESOURCE_TYPE );
    }

    //---------------------------------------------------------------------
    HRCFile::~HRCFile()
    {
        unload();
    }

    //---------------------------------------------------------------------
    void
    HRCFile::loadImpl()
    {
        HRCFileSerializer serializer;
        Ogre::DataStreamPtr stream( Ogre::ResourceGroupManager::getSingleton().openResource( mName, mGroup, true, this ) );
        serializer.importHRCFile( stream, this );
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
    String
    HRCFile::getBaseName( void ) const
    {
        String base, ext;
        Ogre::StringUtil::splitBaseFilename( getName(), base, ext );
        return base;
    }

    //---------------------------------------------------------------------
    void
    HRCFile::setSkeletonName( const String &name )
    {
        m_skeleton_name = name;
    }

    //---------------------------------------------------------------------
    Ogre::SkeletonPtr
    HRCFile::createSkeleton( const String &name, const String &group ) const
    {
        Ogre::SkeletonPtr skeleton( Ogre::SkeletonManager::getSingleton().create( name, group ) );
        Ogre::Bone *root( skeleton->createBone( ROOT_BONE_NAME ) );
        root->setOrientation( ROOT_ORIENTATION );
        for( BoneList::const_iterator it_bone( m_bones.begin() )
            ;it_bone != m_bones.end()
            ;++it_bone )
        {
            Ogre::Bone* child( skeleton->createBone( it_bone->name ) );
            Ogre::Bone* parent( skeleton->getBone( it_bone->parent ) );
            child->setPosition( 0, it_bone->length, 0 );
            parent->addChild( child );
        }
        return skeleton;
    }

    //---------------------------------------------------------------------
    Ogre::Quaternion
    HRCFile::createRootOrientation()
    {
        Ogre::Radian angle( Ogre::Degree( 180 ) );
        Ogre::Vector3 axis( 0, 1, 1 );
        return Ogre::Quaternion( angle, axis );
    }

    //---------------------------------------------------------------------
}
