#include "AnimationExtractor.h"

#include "../../common/Logger.h"



void
AnimationExtractor( const Ogre::SkeletonPtr& skeleton, const ModelInfo& info, Skeleton& skeleton_data )
{
    if( info.animations.size() != info.animations_name.size() )
    {
        LOGGER->Log( "AnimationExtractor ERROR: number of animations dont match number of animation names.\n" );
        return;
    }

    float fps = 25.0f;

    for( size_t i = 0; i < info.animations.size(); ++i )
    {
        if( info.animations[ i ] == "" || info.animations_name[ i ] == "" )
        {
            continue;
        }
        File* file = new File( "./data/field/" + info.animations[ i ] );

        LOGGER->Log( "AnimationExtractor: " + Ogre::StringConverter::toString( i ) + " " + info.animations[ i ] + " as animation with name " + info.animations_name[ i ] + "\n" );

        int number_of_frames = file->GetU16LE( 0x2 );
        Ogre::Animation* anim = skeleton->createAnimation( info.animations_name[ i ], ( number_of_frames - 1 ) / fps );

        float time = 0;
        float tx, ty, tz;
        u32 raw_rx, raw_ry, raw_rz;
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



            u32 high_angle_offset = file->GetU32LE( 0xc );
            u32 low_angle_offset = file->GetU32LE( 0x10 );

            for( size_t bone = 0; bone < skeleton_data.size(); ++bone )
            {
                tx = 0; ty = 0; tz = 0;
                rx = 0; ry = 0; rz = 0;
                raw_rx = 0; raw_ry = 0; raw_rz = 0;

                if( bone == 0 )
                {
                    // create root translation
                    u16 flags = file->GetU16LE( 0xa );
                    if( flags & 1 )
                    {
                        tx = ( s16 )file->GetU16LE( 0x4 );
                    }
                    else
                    {
                        u16 offset = file->GetU16LE( 0x4 );
                        tx = ( s16 )file->GetU16LE( offset + frame * 2 );
                    }
                    if( flags & 2 )
                    {
                        ty = ( s16 )file->GetU16LE( 0x6 );
                    }
                    else
                    {
                        u16 offset = file->GetU16LE( 0x6 );
                        ty = ( s16 )file->GetU16LE( offset + frame * 2 );
                    }
                    if( flags & 4 )
                    {
                        tz = ( s16 )file->GetU16LE( 0x8 );
                    }
                    else
                    {
                        u16 offset = file->GetU16LE( 0x8 );
                        tz = ( s16 )file->GetU16LE( offset + frame * 2 );
                    }
                }



                u16 flags = file->GetU16LE( high_angle_offset + 0x6 );

                u16 data = file->GetU16LE( high_angle_offset + 0x0 );
                //LOGGER->Log( "AnimationExtractor: data_x = 0x" + ToHexString( data, 4, '0' ) + ".\n" );
                if( ( flags & 1 ) == 0 )
                {
                    data = file->GetU8( data + frame );
                    //LOGGER->Log( "AnimationExtractor: flagged data_x = 0x" + ToHexString( data, 4, '0' ) + ".\n" );
                }
                raw_rx = ( data & 0xff ) << 4;

                data = file->GetU16LE( high_angle_offset + 0x2 );
                //LOGGER->Log( "AnimationExtractor: data_y = 0x" + ToHexString( data, 4, '0' ) + ".\n" );
                if( ( flags & 2 ) == 0 )
                {
                    data = file->GetU8( data + frame );
                    //LOGGER->Log( "AnimationExtractor: flagged data_y = 0x" + ToHexString( data, 4, '0' ) + ".\n" );
                }
                raw_ry = ( data & 0xff ) << 4;

                data = file->GetU16LE( high_angle_offset + 0x4 );
                //LOGGER->Log( "AnimationExtractor: data_z = 0x" + ToHexString( data, 4, '0' ) + ".\n" );
                if( ( flags & 4 ) == 0 )
                {
                    data = file->GetU8( data + frame );
                    //LOGGER->Log( "AnimationExtractor: flagged data_z = 0x" + ToHexString( data, 4, '0' ) + ".\n" );
                }
                raw_rz = ( data & 0xff ) << 4;

                //LOGGER->Log( "AnimationExtractor: GET ROTATION frame = " + Ogre::StringConverter::toString( frame ) + ", bone = " + Ogre::StringConverter::toString( bone ) + ", flags = 0x" + ToHexString( flags, 4, '0' ) + ", high_rx = 0x" + ToHexString( raw_rx, 4, '0' ) + ", high_ry = 0x" + ToHexString( raw_ry, 4, '0' ) + ", high_rz = 0x" + ToHexString( raw_rz, 4, '0' ) + ".\n" );

                // if there is low range angles
                if( low_angle_offset != 0 )
                {
                    flags = file->GetU16LE( low_angle_offset + 0x6 );

                    u16 data = file->GetU16LE( low_angle_offset + 0x0 );
                    if( ( flags & 1 ) == 0 )
                    {
                        data = file->GetU8( data + frame / 2 );
                        if( frame & 1 )
                        {
                            data >>= 4;
                        }
                    }
                    raw_rx |= data & 0xf;

                    data = file->GetU16LE( low_angle_offset + 0x2 );
                    if( ( flags & 2 ) == 0 )
                    {
                        data = file->GetU8( data + frame / 2 );
                        if( frame & 1 )
                        {
                            data >>= 4;
                        }
                    }
                    raw_ry |= data & 0xf;

                    data = file->GetU16LE( low_angle_offset + 0x4 );
                    if( ( flags & 4 ) == 0 )
                    {
                        data = file->GetU8( data + frame / 2 );
                        if( frame & 1 )
                        {
                            data >>= 4;
                        }
                    }
                    raw_rz |= data & 0xf;

                    //LOGGER->Log( "AnimationExtractor: GET ROTATION frame = " + Ogre::StringConverter::toString( frame ) + ", bone = " + Ogre::StringConverter::toString( bone ) + ", low_flags = 0x" + ToHexString( flags, 4, '0' ) + ", total_rx = 0x" + ToHexString( raw_rx, 4, '0' ) + ", total_ry = 0x" + ToHexString( raw_ry, 4, '0' ) + ", total_rz = 0x" + ToHexString( raw_rz, 4, '0' ) + ".\n" );

                    low_angle_offset += 8;
                }

                high_angle_offset += 8;



                rx = ( raw_rx / 4096.0f ) * 360.0f;
                ry = ( raw_ry / 4096.0f ) * 360.0f;
                rz = ( raw_rz / 4096.0f ) * 360.0f;



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

        delete file;
    }
}
