#include "AnimationExtractor.h"

#include "../../common/Logger.h"



void
AnimationExtractor( const Ogre::SkeletonPtr& skeleton, const ModelInfo& info, Skeleton& skeleton_data )
{
    for( size_t i = 0; i < info.animations.size(); ++i )
    {
        if( info.animations[ i ] == "" )
        {
            continue;
        }

        File* file = new File( "./data/field/" + info.animations[ i ] );

        LOGGER->Log( "AnimationExtractor:" + Ogre::StringConverter::toString( i ) + " " + info.animations[ i ] + "\n" );

        int number_of_frames = file->GetU16LE( 0x2 );
        Ogre::Animation* anim = skeleton->createAnimation( info.animations[ i ], ( number_of_frames - 1 ) / 10.0f );

        float time = 0;
        float tx, ty, tz;
        Ogre::Bone* bone1;
        Ogre::Bone* bone2;
        Ogre::NodeAnimationTrack* track1;
        Ogre::NodeAnimationTrack* track2;
        Ogre::TransformKeyFrame* frame1;
        Ogre::TransformKeyFrame* frame2;
        Ogre::Quaternion rot;
        Ogre::Matrix3 mat;

        for ( int frame = 0; frame < number_of_frames; ++frame )
        {
            if( frame == 0 )
            {
                bone1 = skeleton->getBone( 0 );
                track1 = anim->createNodeTrack( 0, bone1 );
                track1->removeAllKeyFrames();
                frame1 = track1->createNodeKeyFrame( time );
                mat.FromEulerAnglesYXZ( Ogre::Radian( Ogre::Degree( 0 ) ), Ogre::Radian( Ogre::Degree( -90 ) ), Ogre::Radian( Ogre::Degree( 0 ) ) );
                rot.FromRotationMatrix( mat );
                frame1->setRotation( rot );
                bone2 = skeleton->getBone( 1 );
                track2 = anim->createNodeTrack( 1, bone2 );
                track2->removeAllKeyFrames();
                frame2 = track2->createNodeKeyFrame( time );
            }
            else
            {
                bone1 = skeleton->getBone( 0 );
                track1 = anim->getNodeTrack( 0 );
                frame1 = track1->createNodeKeyFrame( time );
                mat.FromEulerAnglesYXZ( Ogre::Radian( Ogre::Degree( 0 ) ), Ogre::Radian(Ogre::Degree( -90 ) ), Ogre::Radian( Ogre::Degree( 0 ) ) );
                rot.FromRotationMatrix( mat );
                frame1->setRotation( rot );
                bone2 = skeleton->getBone( 1 );
                track2 = anim->getNodeTrack( 1 );
                frame2 = track2->createNodeKeyFrame( time );
            }

            // create root translation
            u8 flags = file->GetU16LE( 0xa );

            if( flags & 1 )
            {
                tx = file->GetU16LE( 0x4 );
            }
            else
            {
                u16 offset = file->GetU16LE( 0x4 );
                tx = file->GetU16LE( offset + frame * 2 );
            }

            if( flags & 2 )
            {
                ty = file->GetU16LE( 0x6 );
            }
            else
            {
                u16 offset = file->GetU16LE( 0x6 );
                ty = file->GetU16LE( offset + frame * 2 );
            }

            if( flags & 4 )
            {
                tz = file->GetU16LE( 0x8 );
            }
            else
            {
                u16 offset = file->GetU16LE( 0x8 );
                tz = file->GetU16LE( offset + frame * 2 );
            }

            frame2->setTranslate( Ogre::Vector3( tx, ty, tz ) / 512 );

            u32 high_angle_offset = file->GetU32LE( 0xc );
            u32 low_angle_offset = file->GetU32LE( 0x10 );



/*

            for (int bone = 0; bone < skeleton_data.size(); ++bone)
            {
                skeleton_data[bone].rx += (ReadEncryptedRotationBits(file, offset_to_animation + 5, readed_bits, compression) / 4096.0f) * 360;
                skeleton_data[bone].ry += (ReadEncryptedRotationBits(file, offset_to_animation + 5, readed_bits, compression) / 4096.0f) * 360;
                skeleton_data[bone].rz += (ReadEncryptedRotationBits(file, offset_to_animation + 5, readed_bits, compression) / 4096.0f) * 360;
                bone1 = skeleton->getBone(bone * 2 + 2);
                bone2 = skeleton->getBone(bone * 2 + 3);
                track1 = anim->getNodeTrack(bone * 2 + 2);
                track2 = anim->getNodeTrack(bone * 2 + 3);
                frame1 = track1->createNodeKeyFrame(time);
                frame2 = track2->createNodeKeyFrame(time);
                frame2->setTranslate(Ogre::Vector3(0, 0, skeleton_data[bone].length) / 512);
                mat.FromEulerAnglesYXZ(Ogre::Radian(Ogre::Degree(skeleton_data[bone].ry)), Ogre::Radian(Ogre::Degree(skeleton_data[bone].rx)), Ogre::Radian(Ogre::Degree(skeleton_data[bone].rz)));
                rot.FromRotationMatrix(mat);
                frame1->setRotation(rot);
            }
*/
            time += 1.0f / 10.0f;
        }

        delete file;
    }
}
