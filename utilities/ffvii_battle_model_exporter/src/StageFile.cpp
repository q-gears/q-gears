#include "StageFile.h"

#include <Ogre.h>

#include "../../common/Logger.h"
#include "../../common/TimToVram.h"
#include "../../common/OgreGenUtilites.h"



StageFile::StageFile( const Ogre::String& file ):
    LzsFile( file )
{
}



StageFile::StageFile(File* pFile):
    LzsFile(pFile)
{
}



StageFile::StageFile(File* pFile, u32 offset, u32 length):
    LzsFile(pFile, offset, length)
{
}



StageFile::StageFile(u8* pBuffer, u32 offset, u32 length):
    LzsFile(pBuffer, offset, length)
{
}



StageFile::~StageFile()
{
}



Ogre::Entity*
StageFile::GetModel( const StageInfo& info )
{
    //DumpSettings("exported/" + info.data.name + ".lua");

    VectorTexForGen textures;
    Ogre::MeshPtr mesh = Ogre::MeshManager::getSingleton().create(info.data.name + "export", "General");
    Ogre::SkeletonPtr skeleton = Ogre::SkeletonManager::getSingleton().create(info.data.name + "export", "General");

    u32 number_of_files = GetU32LE(0);
    LOGGER->Log("Number of file " + IntToString(number_of_files) + "\n");



    Ogre::Bone* root1 = skeleton->createBone( "0", 0 );
    Ogre::Bone* root2 = skeleton->createBone( "1", 1 );
    root1->addChild( root2 );

    Ogre::Animation* anim = skeleton->createAnimation( "Idle", 1 );
    Ogre::NodeAnimationTrack* track1 = anim->createNodeTrack( 0, root1 );
    track1->removeAllKeyFrames();
    Ogre::TransformKeyFrame* frame1 = track1->createNodeKeyFrame( 0 );
    Ogre::Matrix3 matrix;
    matrix.FromEulerAnglesYXZ( Ogre::Radian( Ogre::Degree( 0 ) ), Ogre::Radian( Ogre::Degree( -90 ) ), Ogre::Radian( Ogre::Degree( 0 ) ) );
    Ogre::Quaternion rot;
    rot.FromRotationMatrix( matrix );
    frame1->setRotation( rot );



    for (u32 i = 1; i < number_of_files - 1; ++i)
    {
        int offset_to_vertex = GetU32LE(0x04 + i * 0x04);
        MeshExtractor(info.data, "ffvii/battle_stage/" + info.data.name, this, offset_to_vertex, textures, mesh, Ogre::StringConverter::toString(i), 1);
    }



    // <OGRE> ///////////////////////////////
    skeleton->optimiseAllAnimations();
    Ogre::SkeletonSerializer skeleton_serializer;
    skeleton_serializer.exportSkeleton(skeleton.getPointer(), "exported/models/ffvii/battle/stages/" + info.data.name + ".skeleton");

    // Update bounds
    Ogre::AxisAlignedBox aabb(-999, -999, -999, 999, 999, 999);
    mesh->_setBounds(aabb, false);
    mesh->_setBoundingSphereRadius(999);

    mesh->setSkeletonName( "models/ffvii/battle/stages/" + info.data.name + ".skeleton" );

    Ogre::MeshSerializer ser;
    ser.exportMesh(mesh.getPointer(), "exported/models/ffvii/battle/stages/" + info.data.name + ".mesh");



    // create and export textures for model
    if( textures.size() > 0 )
    {
        int number_of_files = GetU32LE( 0x00 );
        int offset_to_texture = GetU32LE( number_of_files * 0x04 );
        Vram* vram = Vram::MakeInstance().release();

        LoadTimFileToVram( this, offset_to_texture, vram );
        //vram->Save( "qqq" );
        CreateTexture( vram, info.data, "exported/models/ffvii/battle/stages/" + info.data.name + ".png", textures );
        delete vram;
    }



    CreateMaterial("ffvii/battle_stage/" + info.data.name, "exported/models/ffvii/battle/stages/" + info.data.name + ".material", "models/ffvii/battle/stages/" + info.data.name + ".png", "", "");



    Ogre::SceneManager* scene_manager = Ogre::Root::getSingleton().getSceneManager( "Scene" );
    Ogre::Entity* thisEntity = scene_manager->createEntity( info.data.name, "models/ffvii/battle/stages/" + info.data.name + ".mesh" );
    //thisEntity->setDisplaySkeleton(true);
    //thisEntity->setDebugDisplayEnabled(true);
    thisEntity->setVisible(false);
    thisEntity->getAnimationState( "Idle" )->setEnabled( true );
    thisEntity->getAnimationState( "Idle" )->setLoop( true );
    Ogre::SceneNode* thisSceneNode = scene_manager->getRootSceneNode()->createChildSceneNode();
    thisSceneNode->setPosition( 0, 0, 0 );
    thisSceneNode->roll( Ogre::Radian( Ogre::Degree( 180.0f ) ) );
    thisSceneNode->yaw( Ogre::Radian( Ogre::Degree( 120.0f ) ) );
    thisSceneNode->pitch( Ogre::Radian( Ogre::Degree( 90.0f ) ) );
    thisSceneNode->attachObject( thisEntity );

    return thisEntity;
}



/*
void
StageFile::DumpSettings(const Ogre::String& file)
{
    Logger* settings = new Logger(file);

    int model_settings_offset = GetU32LE(0x08);

    m_WithWeapon = GetU8(model_settings_offset + 2) & 0x80;
    LOGGER->Log("Model With Weapon '" + Ogre::StringConverter::toString(m_WithWeapon) + "'\n");

    settings->Log("// animation scripts\n");
    settings->Log("+00 [][]     " + ToHexString(GetU16LE(model_settings_offset + 0), 4, '0') + " - if this is not 0 we add 0x40 bit to 8015190b\n");
    settings->Log("+02 []       " + ToHexString(GetU8(model_settings_offset + 2), 2, '0') + " - 0x3f - dead type. 0x80 - play secondary animation\n");
    settings->Log("+03 []       " + ToHexString(GetU8(model_settings_offset + 3), 2, '0') + "\n");
    settings->Log("+04 [][]     " + ToHexString(GetU16LE(model_settings_offset + 4), 4, '0') + " - collision radius. Set to 801518e4+6\n");
    settings->Log("+06 [][]     " + ToHexString(GetU16LE(model_settings_offset + 6), 4, '0') + " - to 801518ec\n");
    settings->Log("+08 [][]     " + ToHexString(GetU16LE(model_settings_offset + 8), 4, '0') + " - to 801518ee\n");
    settings->Log("+0a [][]     " + ToHexString(GetU16LE(model_settings_offset + 0xa), 4, '0') + " - to 801518f0\n");
    settings->Log("+0c [][]     " + ToHexString(GetU16LE(model_settings_offset + 0xc), 4, '0') + "\n");
    settings->Log("+0e [][]     " + ToHexString(GetU16LE(model_settings_offset + 0xe), 4, '0') + "\n");
    settings->Log("+10 [][]     " + ToHexString(GetU16LE(model_settings_offset + 0x10), 4, '0') + " - filler?\n");

    settings->Log("+12 array of joints (bone indexes)\n    ");
    for (int i = 0; i < 0x10; ++i)
    {
        if (i != 0)
        {
            settings->Log(" ");
        }
        settings->Log(ToHexString(GetU8(model_settings_offset + 0x12 + i), 2, '0'));
    }
    settings->Log("\n");

    settings->Log("+22 [][]     " + ToHexString(GetU16LE(model_settings_offset + 0x22), 4, '0') + " - filler?\n");

    settings->Log("+24 array of 8 offsets to something\n    ");
    for (int i = 0; i < 8; ++i)
    {
        if (i != 0)
        {
            settings->Log(" ");
        }
        settings->Log(ToHexString(GetU32LE(model_settings_offset + 0x24 + i * 4), 8, '0'));
    }
    settings->Log("\n");

    settings->Log("+44 array of 4 something\n    ");
    for (int i = 0; i < 4; ++i)
    {
        if (i != 0)
        {
            settings->Log(" ");
        }
        settings->Log(ToHexString(GetU16LE(model_settings_offset + 0x44 + i * 2), 4, '0'));
    }
    settings->Log("\n");

    settings->Log("+4c array of 6 something\n    ");
    for (int i = 0; i < 6; ++i)
    {
        if (i != 0)
        {
            settings->Log(" ");
        }
        settings->Log(ToHexString(GetU16LE(model_settings_offset + 0x4c + i * 2), 4, '0'));
    }
    settings->Log("\n");

    settings->Log("+58 array of 6 something\n    ");
    for (int i = 0; i < 6; ++i)
    {
        if (i != 0)
        {
            settings->Log(" ");
        }
        settings->Log(ToHexString(GetU16LE(model_settings_offset + 0x58 + i * 2), 4, '0'));
    }
    settings->Log("\n");

    settings->Log("+64 [][]     " + ToHexString(GetU16LE(model_settings_offset + 0x64), 4, '0') + "\n");
    settings->Log("+66 [][]     " + ToHexString(GetU16LE(model_settings_offset + 0x66), 4, '0') + " - filler?\n");

    settings->Log("+68 array of 32 offsets to animation scripts\n    ");
    for (int i = 0; i < 0x20; ++i)
    {
        if (i != 0)
        {
            if (i % 8 == 0)
            {
                settings->Log("\n    ");
            }
            else
            {
                settings->Log(" ");
            }
        }
        settings->Log(ToHexString(GetU32LE(model_settings_offset + 0x68 + i * 4), 8, '0'));
    }
    settings->Log("\n");



    AnimationScriptDumper(this, model_settings_offset, settings);



    delete settings;
}
*/
