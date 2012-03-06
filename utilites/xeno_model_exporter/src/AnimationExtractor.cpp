#include "AnimationExtractor.h"

#include "../../common/Logger.h"
#include "../../common/File.h"



void
AnimationExtractor( const Ogre::SkeletonPtr& skeleton, const ModelInfo& info, Skeleton& skeleton_data )
{
    float fps = 25.0f;
    File* file = new File( "./data/field/" + info.animation_file );

    for( size_t i = 0; i < 1/*info.animations.size()*/; ++i )
    {
        if( info.animations[ i ] == "" )
        {
            continue;
        }

        //LOGGER->Log( "AnimationExtractor: " + Ogre::StringConverter::toString( i ) + " " + info.animations[ i ] + " as animation with name " + info.animations_name[ i ] + "\n" );

        int number_of_frames = 1/*file->GetU16LE( 0x2 )*/;
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



            u32 first  = file->GetU32LE( 0x04 );
            u32 second = first  + file->GetU32LE( first + 0x04 );
            u32 start  = second + file->GetU32LE( second + 0x04 );
            start += 0x18;


            for( int bone = 0; bone < skeleton_data.size(); ++bone )
            {
                tx = 0; ty = 0; tz = 0;
                rx = 0; ry = 0; rz = 0;

                rx = ( s16 )file->GetU16LE( start + bone * 0x0c + 0x00 );
                ry = ( s16 )file->GetU16LE( start + bone * 0x0c + 0x02 );
                rz = ( s16 )file->GetU16LE( start + bone * 0x0c + 0x04 );
                rx = ( rx / 4096.0f ) * 360.0f;
                ry = ( ry / 4096.0f ) * 360.0f;
                rz = ( rz / 4096.0f ) * 360.0f;

                tx = ( s16 )file->GetU16LE( start + bone * 0x0c + 0x06 ) / 512.0f;
                ty = ( s16 )file->GetU16LE( start + bone * 0x0c + 0x08 ) / 512.0f;
                tz = ( s16 )file->GetU16LE( start + bone * 0x0c + 0x0a ) / 512.0f;



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
                Ogre::Vector3 translate = Ogre::Vector3( tx, ty, tz + skeleton_data[ bone ].length ) / 512.0f;
                //LOGGER->Log( "AnimationExtractor: frame = " + Ogre::StringConverter::toString( frame ) + ", bone = " + Ogre::StringConverter::toString( bone ) + ", translation = " + Ogre::StringConverter::toString( translate ) + ".\n" );
                frame1->setTranslate( translate );
                //mat.FromEulerAnglesXYZ( Ogre::Radian( Ogre::Degree( rx ) ), Ogre::Radian( Ogre::Degree( ry ) ), Ogre::Radian( Ogre::Degree( rz ) ) );
                //mat.FromEulerAnglesXZY( Ogre::Radian( Ogre::Degree( rx ) ), Ogre::Radian( Ogre::Degree( rz ) ), Ogre::Radian( Ogre::Degree( ry ) ) );
                //mat.FromEulerAnglesYZX( Ogre::Radian( Ogre::Degree( ry ) ), Ogre::Radian( Ogre::Degree( rz ) ), Ogre::Radian( Ogre::Degree( rx ) ) );
                //mat.FromEulerAnglesYXZ( Ogre::Radian( Ogre::Degree( ry ) ), Ogre::Radian( Ogre::Degree( rx ) ), Ogre::Radian( Ogre::Degree( rz ) ) );
                mat.FromEulerAnglesZYX( Ogre::Radian( Ogre::Degree( rz ) ), Ogre::Radian( Ogre::Degree( ry ) ), Ogre::Radian( Ogre::Degree( rx ) ) );
                //mat.FromEulerAnglesZXY( Ogre::Radian( Ogre::Degree( rz ) ), Ogre::Radian( Ogre::Degree( rx ) ), Ogre::Radian( Ogre::Degree( ry ) ) );
                //LOGGER->Log( "AnimationExtractor: frame = " + Ogre::StringConverter::toString( frame ) + ", bone = " + Ogre::StringConverter::toString( bone ) + ", rotation = " + Ogre::StringConverter::toString( rx ) + " " + Ogre::StringConverter::toString( ry ) + " " + Ogre::StringConverter::toString( rz ) + ".\n" );
                rot.FromRotationMatrix( mat );
                frame2->setRotation( rot );
            }

            time += 1.0f / fps;
        }
    }

    delete file;
}
