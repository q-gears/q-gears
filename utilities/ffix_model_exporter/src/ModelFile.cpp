#include "ModelFile.h"

#include <Ogre.h>

#include "AnimationExtractor.h"
#include "MeshExtractor.h"
#include "../../common/Logger.h"
#include "../../common/TimToVram.h"



ModelFile::ModelFile( const Ogre::String& file ):
    File( file )
{
}



ModelFile::ModelFile( File* pFile ):
    File( pFile )
{
}



ModelFile::ModelFile( File* pFile, u32 offset, u32 length ):
    File( pFile, offset, length )
{
}



ModelFile::ModelFile( u8* pBuffer, u32 offset, u32 length ):
    File( pBuffer, offset, length )
{
}



ModelFile::~ModelFile()
{
}



Ogre::Entity*
ModelFile::GetModel( const ModelInfo& info )
{
    VectorTexForGen textures;
    Ogre::MeshPtr mesh = Ogre::MeshManager::getSingleton().create( info.data.name + "export", "General" );
    Ogre::SkeletonPtr skeleton = Ogre::SkeletonManager::getSingleton().create( info.data.name + "export", "General" );

    int number_of_bones = GetU8( 0x02 );
    int number_of_parts = GetU8( 0x03 );
    int offset_to_bones = GetU32LE( 0x0c );
    int offset_to_parts = GetU32LE( 0x10 );



    Ogre::Bone* root1 = skeleton->createBone( "0", 0 );
    Ogre::Bone* root2 = skeleton->createBone( "1", 1 );
    root1->addChild( root2 );

    for( int i = 0; i < number_of_bones; ++i )
    {
        Bone bone;
        bone.parent_id = ( i != 0 ) ? ( s8 )GetU8( offset_to_bones + i * 0x04 + 0x03 ) : -1;
        bone.length    = ( s16 )GetU16LE( offset_to_bones + i * 0x04 + 0x00 );
        m_Skeleton.push_back(bone);

        Ogre::Bone* bone1 = skeleton->createBone( Ogre::StringConverter::toString( i * 2 + 2 ), i * 2 + 2 );
        Ogre::Bone* bone2 = skeleton->createBone( Ogre::StringConverter::toString( i * 2 + 3 ), i * 2 + 3 );

        LOGGER->Log( "Add skeleton bone: bone_id = " + Ogre::StringConverter::toString( i ) + ", length = " + Ogre::StringConverter::toString( bone.length ) + ", parent = " + Ogre::StringConverter::toString( bone.parent_id ) + ".\n" );

        if( bone.parent_id == -1 )
        {
            skeleton->getBone( 1 )->addChild( bone1 );
        }
        else
        {
            skeleton->getBone( bone.parent_id * 2 + 3 )->addChild( bone1 );
        }
        bone1->addChild( bone2 );
    }



    AnimationExtractor( skeleton, info, m_Skeleton );



    // draw skeleton
    {
        //DrawSkeleton( m_Skeleton, mesh );
    }



    for( int i = 0; i < number_of_parts; ++i )
    {
        MeshExtractor( info.data, "ffix/field_model/" + info.data.name, this, offset_to_parts + i * 0x28, textures, mesh );
    }



    // <OGRE> ///////////////////////////////
    skeleton->optimiseAllAnimations();
    Ogre::SkeletonSerializer skeleton_serializer;
    skeleton_serializer.exportSkeleton( skeleton.getPointer(), "exported/models/field/units/" + info.data.name + ".skeleton" );

    // Update bounds
    Ogre::AxisAlignedBox aabb( -999, -999, -999, 999, 999, 999 );
    mesh->_setBounds( aabb, false );
    mesh->_setBoundingSphereRadius( 999 );

    mesh->setSkeletonName( "models/field/units/" + info.data.name + ".skeleton" );

    Ogre::MeshSerializer ser;
    ser.exportMesh( mesh.getPointer(), "exported/models/field/units/" + info.data.name + ".mesh" );



    // create and export textures for model
    //if (textures.size() > 0)
    {
        Vram* vram = Vram::MakeInstance().release();

        File* tex = new File( "./data/field/5/1b/2/4/1.tim" );
        LoadTimFileToVram( tex, 0, vram );
        delete tex;
        tex = new File( "./data/field/5/1b/2/4/2.tim" );
        LoadTimFileToVram( tex, 0, vram );
        delete tex;

        vram->Save( "1.jpg" );

        CreateTexture( vram, info.data, "exported/models/field/units/" + info.data.name + ".png", textures );

        delete vram;
    }



    CreateMaterial( "ffix/field_model/" + info.data.name, "exported/models/field/units/" + info.data.name + ".material", ( textures.size() > 0 ) ? "models/field/units/" + info.data.name + ".png" : "", "", "" );



    Ogre::SceneManager* scene_manager = Ogre::Root::getSingleton().getSceneManager( "Scene" );
    Ogre::Entity* thisEntity = scene_manager->createEntity( info.data.name, "models/field/units/" + info.data.name + ".mesh" );
    //thisEntity->setDisplaySkeleton(true);
    //thisEntity->setDebugDisplayEnabled(true);
    thisEntity->setVisible( false );
    thisEntity->getAnimationState( info.animations_name[ 0 ] )->setEnabled(true);
    thisEntity->getAnimationState( info.animations_name[ 0 ] )->setLoop(true);
    Ogre::SceneNode* thisSceneNode = scene_manager->getRootSceneNode()->createChildSceneNode();
    thisSceneNode->setPosition( 0, 0, 0 );
    thisSceneNode->roll( Ogre::Radian( Ogre::Degree( 180.0f ) ) );
    thisSceneNode->yaw( Ogre::Radian( Ogre::Degree( 120.0f ) ) );
    thisSceneNode->pitch( Ogre::Radian( Ogre::Degree(90.0f ) ) );
    thisSceneNode->attachObject( thisEntity );

    return thisEntity;
}
