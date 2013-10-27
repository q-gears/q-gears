/*
-----------------------------------------------------------------------------
Copyright (c) 15.1.2013 Tobias Peters <tobias.peters@kreativeffekt.at>

This file is part of Q-Gears

Q-Gears is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, version 2.0 (GPLv2) of the License.

Q-Gears is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.
-----------------------------------------------------------------------------
*/
#include "data/QGearsAFile.h"

#include <OgreBone.h>
#include <OgreLogManager.h>

#include "data/QGearsAFileSerializer.h"

namespace QGears
{
   //-------------------------------------------------------------------------
   const Ogre::Real AFile::FRAME_DURATION( 1.0 / 30.0 );
   const String     AFile::RESOURCE_TYPE( "QGearsAFile" );

   //-------------------------------------------------------------------------
   AFile::AFile( Ogre::ResourceManager *creator
                ,const String &name, Ogre::ResourceHandle handle
                ,const String &group, bool isManual
                ,Ogre::ManualResourceLoader *loader ) :
        Resource( creator, name, handle, group, isManual, loader )
      , m_bone_count( 0 )
    {
    }

    //-------------------------------------------------------------------------
    AFile::~AFile()
    {
        unload();
    }

    //-------------------------------------------------------------------------
    void
    AFile::setBoneCount( const uint32 bone_count )
    {
        m_bone_count = bone_count;
    }

    //-------------------------------------------------------------------------
    void
    AFile::loadImpl()
    {
        AFileSerializer serializer;
        Ogre::DataStreamPtr stream( openResource() );
        serializer.importAFile( stream, this );
    }

    //-------------------------------------------------------------------------
    void
    AFile::unloadImpl()
    {
        m_bone_count = 0;
        m_frames.clear();
    }

    //-------------------------------------------------------------------------
    size_t
    AFile::calculateSize() const
    {
        size_t size( 0 );
        FrameList::const_iterator it( m_frames.begin() ), it_end( m_frames.end() );
        while( it != it_end )
        {
            size += sizeof( it->root_rotation );
            size += sizeof( it->root_translation );
            size += sizeof( BoneRotationList::value_type ) * it->bone_rotations.size();
            ++it;
        }

        return size;
    }

    //-------------------------------------------------------------------------
    void
    AFile::setFrameRotation( Ogre::TransformKeyFrame* key_frame
                            , const Ogre::Vector3& v ) const
    {
        Ogre::Quaternion rot;
        Ogre::Matrix3 mat;
        mat.FromEulerAnglesZXY( Ogre::Radian(Ogre::Degree( -v.y )), Ogre::Radian(Ogre::Degree( -v.x )), Ogre::Radian(Ogre::Degree( -v.z )) );
        rot.FromRotationMatrix( mat );
        key_frame->setRotation( rot );
    }

    //-------------------------------------------------------------------------
    void
    AFile::addTo( Ogre::SkeletonPtr skeleton, const String& name ) const
    {
        if( skeleton->hasAnimation( name) ) return;

        Ogre::Real length( ( m_frames.size() - 1 ) * FRAME_DURATION );
        Ogre::Animation *anim( skeleton->createAnimation(name, length ));
        uint16 track_handle( 0 );
        Ogre::Bone* bone( skeleton->getBone( "root" ) );
        Ogre::NodeAnimationTrack* track;
        track = anim->createNodeTrack( track_handle++, bone );
        Ogre::Real time;
        size_t index( 0 );
        for( FrameList::const_iterator frame( m_frames.begin())
            ;frame != m_frames.end(); ++frame )
        {
            time = (index++) * FRAME_DURATION;
            Ogre::TransformKeyFrame* key_frame( track->createNodeKeyFrame( time ) );
            key_frame->setTranslate( frame->root_translation );
            setFrameRotation( key_frame, frame->root_rotation );
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
