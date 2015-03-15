#include "AnimationExtractor.h"

#include "common/Logger.h"
#include "common/File.h"



void
AnimationExtractor( const Ogre::SkeletonPtr& skeleton, const ModelInfo& info, Skeleton& skeleton_data )
{
    float fps = 1;

    File* file = new File( "./data/field/" + info.animation_file );

    for( size_t i = 0; i < info.animations.size(); ++i )
    {
        if( info.animations[ i ] == "" )
        {
            continue;
        }

        //LOGGER->Log( "AnimationExtractor: " + Ogre::StringConverter::toString( i ) + " " + info.animations[ i ] + " as animation with name " + info.animations_name[ i ] + "\n" );

        int number_of_frames = 2/*file->GetU16LE( 0x2 )*/;

        Ogre::Animation* anim = skeleton->createAnimation( info.animations[ i ], ( number_of_frames - 1 ) / fps );

        float time = 0;
        float tx, ty, tz;
        float rx, ry, rz;
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
            // this is just to orientate model to right direction
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
            }
            frame2 = track2->createNodeKeyFrame( time );



            u32 start;
            u32 first  = file->GetU32LE( 0x04 );
            u32 second = first  + file->GetU32LE( first + 0x04 );
            if( frame == 0 )
            {
                start  = second + file->GetU32LE( second + 0x04 + 0 * 0x4 );
            }
            else
            {
                start  = second + file->GetU32LE( second + 0x04 + i * 0x4 );
            }

            u16 max_rot_num = file->GetU16LE( start + 0xc );
            u16 max_trans_num = file->GetU16LE( start + 0xe );

            u16 rot_flag   = file->GetU16LE( start + 0x4 ) & 1;
            u16 trans_flag = file->GetU16LE( start + 0x4 ) & 2;

            if( file->GetU16LE( start + 0x6 ) == 0 )
            {
                start = start + ( max_rot_num + 1 ) * 6;
            }

            start += 0x18;

            u16 rot_num = 0;
            u16 trans_num = 0;

            for( size_t bone = 0; bone < skeleton_data.size(); ++bone )
            {
                tx = 0; ty = 0; tz = 0;
                rx = 0; ry = 0; rz = 0;

                bool bone_rotated = true;
                bool bone_translated = true;

                if( ( rot_flag == 0 ) && ( rot_num < max_rot_num ) )
                {
                    rx = ( s16 )file->GetU16LE( start + 0x00 );
                    ry = ( s16 )file->GetU16LE( start + 0x02 );
                    rz = ( s16 )file->GetU16LE( start + 0x04 );
                    rx = ( rx / 4096.0f ) * 360.0f;
                    ry = ( ry / 4096.0f ) * 360.0f;
                    rz = ( rz / 4096.0f ) * 360.0f;
                    //LOGGER->Log( "Rotation: frame = " + Ogre::StringConverter::toString( frame ) + ", bone = " + Ogre::StringConverter::toString( bone ) + ", rx = " + ToHexString( file->GetU16LE( start + 0x00 ), 4, '0' ) + ", ry = " + ToHexString( file->GetU16LE( start + 0x02 ), 4, '0' ) + ", rz = " + ToHexString( file->GetU16LE( start + 0x04 ), 4, '0' ) + ".\n" );
                    //LOGGER->Log( "Rotation: frame = " + Ogre::StringConverter::toString( frame ) + ", bone = " + Ogre::StringConverter::toString( bone ) + ", rx = " + Ogre::StringConverter::toString( rx ) + ", ry = " + Ogre::StringConverter::toString( ry ) + ", rz = " + Ogre::StringConverter::toString( rz ) + ".\n" );
                    start += 0x6;
                    rot_num += 1;
                }
                else
                {
                    bone_rotated = false;
                }

                if( ( trans_flag == 0 ) && ( trans_num < max_trans_num ) )
                {
                    tx = ( s16 )file->GetU16LE( start + 0x00 );
                    ty = ( s16 )file->GetU16LE( start + 0x02 );
                    tz = ( s16 )file->GetU16LE( start + 0x04 );

                    start += 0x6;
                    trans_num += 1;
                }
                else
                {
                    bone_translated = false;
                }



                // assign data to bone
                bone1 = skeleton->getBone( bone * 2 + 2 );
                bone2 = skeleton->getBone( bone * 2 + 3 );
                if( frame == 0 )
                {
                    track1 = anim->createNodeTrack( bone * 2 + 2, bone1 );
                    track1->removeAllKeyFrames();
                    track2 = anim->createNodeTrack( bone * 2 + 3, bone2 );
                    track2->removeAllKeyFrames();

                }
                else
                {
                    track1 = anim->getNodeTrack( bone * 2 + 2 );
                    track2 = anim->getNodeTrack( bone * 2 + 3 );
                }
                frame1 = track1->createNodeKeyFrame( time );
                frame2 = track2->createNodeKeyFrame( time );

                Ogre::Vector3 translate = Ogre::Vector3( tx, ty, tz ) / 512.0f;
                //LOGGER->Log( "AnimationExtractor: frame = " + Ogre::StringConverter::toString( frame ) + ", bone = " + Ogre::StringConverter::toString( bone ) + ", bone_translated = \"" + Ogre::StringConverter::toString( bone_translated ) + "\",  translation = " + Ogre::StringConverter::toString(  ( bone_translated == true ) ? translate : track1->getNodeKeyFrame( frame - 1 )->getTranslate() ) + ".\n" );
                frame1->setTranslate( ( bone_translated == true || frame == 0 ) ? translate : track1->getNodeKeyFrame( frame - 1 )->getTranslate() );
                mat.FromEulerAnglesXYZ( Ogre::Radian( Ogre::Degree( rx ) ), Ogre::Radian( Ogre::Degree( ry ) ), Ogre::Radian( Ogre::Degree( rz ) ) );
                //mat.FromEulerAnglesXZY( Ogre::Radian( Ogre::Degree( rx ) ), Ogre::Radian( Ogre::Degree( rz ) ), Ogre::Radian( Ogre::Degree( ry ) ) );
                //mat.FromEulerAnglesYXZ( Ogre::Radian( Ogre::Degree( ry ) ), Ogre::Radian( Ogre::Degree( rx ) ), Ogre::Radian( Ogre::Degree( rz ) ) );
                ////mat.FromEulerAnglesYZX( Ogre::Radian( Ogre::Degree( ry ) ), Ogre::Radian( Ogre::Degree( rz ) ), Ogre::Radian( Ogre::Degree( rx ) ) );
                ////mat.FromEulerAnglesZYX( Ogre::Radian( Ogre::Degree( rz ) ), Ogre::Radian( Ogre::Degree( ry ) ), Ogre::Radian( Ogre::Degree( rx ) ) );
                ////mat.FromEulerAnglesZXY( Ogre::Radian( Ogre::Degree( rz ) ), Ogre::Radian( Ogre::Degree( rx ) ), Ogre::Radian( Ogre::Degree( ry ) ) );
                rot.FromRotationMatrix( mat );
                //LOGGER->Log( "AnimationExtractor: frame = " + Ogre::StringConverter::toString( frame ) + ", bone = " + Ogre::StringConverter::toString( bone ) + ", bone_rotated = \"" + Ogre::StringConverter::toString( bone_rotated ) + "\" rotation = " + Ogre::StringConverter::toString(  ( bone_translated == true ) ? rot : track2->getNodeKeyFrame( frame - 1 )->getRotation() ) + ".\n" );
                frame2->setRotation( ( bone_rotated == true || frame == 0 ) ? rot : track2->getNodeKeyFrame( frame - 1 )->getRotation() );
            }

            time += 1.0f / fps;
        }
    }

    delete file;
}
