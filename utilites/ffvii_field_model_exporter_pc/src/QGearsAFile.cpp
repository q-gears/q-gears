/*
-----------------------------------------------------------------------------
The MIT License (MIT)

Copyright (c) 2013-08-12 Tobias Peters <tobias.peters@kreativeffekt.at>

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
#include "QGearsAFile.h"

#include <OgreBone.h>
#include <OgreLogManager.h>

namespace QGears
{
   //-------------------------------------------------------------------------
   const Ogre::Real AFile::FRAME_DURATION( 1.0 / 30.0 );

   //-------------------------------------------------------------------------
    AFile::AFile() :
        m_bone_count( 0 )
    {
    }

    //-------------------------------------------------------------------------
    AFile::~AFile()
    {
    }

    //-------------------------------------------------------------------------
    void
    AFile::setBoneCount( const uint32 bone_count )
    {
        m_bone_count = bone_count;
    }

    //-------------------------------------------------------------------------
    void
    AFile::setFrameRotation( Ogre::TransformKeyFrame* key_frame
                            , const Ogre::Vector3& v ) const
    {
        Ogre::Quaternion rot;
        Ogre::Matrix3 mat;
        mat.FromEulerAnglesZXY( Ogre::Radian(Ogre::Degree( -v.y )), Ogre::Radian(Ogre::Degree( -v.x )), Ogre::Radian(Ogre::Degree( v.z )) );
        rot.FromRotationMatrix( mat );
        key_frame->setRotation( rot );
    }

    //-------------------------------------------------------------------------
    void
    AFile::addTo( Ogre::SkeletonPtr skeleton, const String& name ) const
    {
        Ogre::Real length( m_frames.size() * FRAME_DURATION );
        Ogre::Animation* anim( skeleton->createAnimation(name, length ));
        uint16 track_handle( 0 );
        Ogre::Bone* bone( skeleton->getBone( "root" ) );
        Ogre::NodeAnimationTrack* track;
        track = anim->createNodeTrack( track_handle++, bone );
        Ogre::Real time( 0 );
        for( FrameList::const_iterator frame( m_frames.begin())
            ;frame != m_frames.end(); ++frame )
        {
            Ogre::TransformKeyFrame* key_frame( track->createNodeKeyFrame( time ) );
            key_frame->setTranslate( frame->root_translation );
            setFrameRotation( key_frame, frame->root_rotation );
            time += FRAME_DURATION;
        }
        for( uint32 i(0); i < m_bone_count; ++i )
        {
            bone = skeleton->getBone( i + 1 );
            track = anim->createNodeTrack( track_handle++, bone );
            time = 0;
            for( FrameList::const_iterator frame( m_frames.begin())
                ;frame != m_frames.end(); ++frame )
            {
                const Ogre::Vector3& rot( frame->bone_rotations[i] );
                Ogre::TransformKeyFrame* key_frame( track->createNodeKeyFrame( time ) );
                setFrameRotation( key_frame, rot );
                time += FRAME_DURATION;
            }
        }
    }

    //-------------------------------------------------------------------------
}
