/*
-----------------------------------------------------------------------------
The MIT License (MIT)

Copyright (c) 2013-08-17 Tobias Peters <tobias.peters@kreativeffekt.at>

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
#include "QGearsHRCSkeletonLoader.h"

#include <OgreBone.h>

#include "QGearsHRCFile.h"

namespace QGears
{
    //-------------------------------------------------------------------------
    const String            HRCSkeletonLoader::ROOT_BONE_NAME( "root" );
    const Ogre::Quaternion  HRCSkeletonLoader::ROOT_ORIENTATION( HRCSkeletonLoader::createRootOrientation() );

    typedef HRCFile::BoneList BoneList;

    //-------------------------------------------------------------------------
    HRCSkeletonLoader::HRCSkeletonLoader( HRCFile &hrc_file ) :
        m_hrc_file( hrc_file )
    {
    }

    //-------------------------------------------------------------------------
    HRCSkeletonLoader::~HRCSkeletonLoader()
    {
    }

    //---------------------------------------------------------------------
    Ogre::Quaternion
    HRCSkeletonLoader::createRootOrientation()
    {
        Ogre::Radian angle( Ogre::Degree( 180 ) );
        Ogre::Vector3 axis( 0, 1, 1 );
        return Ogre::Quaternion( angle, axis );
    }

    //-------------------------------------------------------------------------
    void
    HRCSkeletonLoader::loadResource( Ogre::Resource *resource )
    {
        Ogre::Skeleton *skeleton( static_cast<Ogre::Skeleton *>(resource) );
        assert( skeleton );

        m_hrc_file.load();
        Ogre::Bone *root( skeleton->createBone( ROOT_BONE_NAME ) );
        root->setOrientation( ROOT_ORIENTATION );

        BoneList &bones( m_hrc_file.getBones() );
        for( BoneList::const_iterator it_bone( bones.begin() )
            ;it_bone != bones.end()
            ;++it_bone )
        {
            Ogre::Bone* child( skeleton->createBone( it_bone->name ) );
            Ogre::Bone* parent( skeleton->getBone( it_bone->parent ) );
            child->setPosition( 0, it_bone->length, 0 );
            parent->addChild( child );
        }
    }

    //-------------------------------------------------------------------------
}
