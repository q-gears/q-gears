#include "EnemyFile.h"

#include <Ogre.h>

#include "AnimationExtractor.h"
#include "AnimationScriptDumper.h"
#include "../../common/Logger.h"
#include "../../common/OgreGenUtilites.h"
#include "../../common/TimToVram.h"



EnemyFile::EnemyFile( const Ogre::String& file ):
    LzsFile( file ),
    m_WithWeapon( false )
{
}



EnemyFile::EnemyFile( File* pFile ):
    LzsFile( pFile ),
    m_WithWeapon( false )
{
}



EnemyFile::EnemyFile( File* pFile, u32 offset, u32 length ):
    LzsFile( pFile, offset, length ),
    m_WithWeapon( false )
{
}



EnemyFile::EnemyFile( u8* pBuffer, u32 offset, u32 length ):
    LzsFile( pBuffer, offset, length ),
    m_WithWeapon( false )
{
}



EnemyFile::~EnemyFile()
{
}



Ogre::Entity*
EnemyFile::GetModel( const EnemyInfo& info )
{
    DumpSettings( "exported/models/ffvii/battle/units/" + info.data.name + ".lua" );

    VectorTexForGen textures;
    Ogre::MeshPtr mesh = Ogre::MeshManager::getSingleton().create(info.data.name + "export", "General");
    Ogre::SkeletonPtr skeleton = Ogre::SkeletonManager::getSingleton().create(info.data.name + "export", "General");



    int offset_to_models_description = GetU32LE(0x04);
    int number_of_bones = GetU32LE(offset_to_models_description);

    Ogre::Bone* root1 = skeleton->createBone("0", 0);
    Ogre::Bone* root2 = skeleton->createBone("1", 1);
    root1->addChild(root2);

    for (int i = 0; i < number_of_bones; ++i)
    {
        Bone bone;
        bone.parent_id = (s16)GetU16LE(offset_to_models_description + 0x0c + i * 0x08 + 0x00);
        bone.length    = (s16)GetU16LE(offset_to_models_description + 0x0c + i * 0x08 + 0x02);
        bone.offset    = GetU32LE(offset_to_models_description + 0x0c + i * 0x08 + 0x04);
        m_Skeleton.push_back(bone);

        Ogre::Bone* bone1 = skeleton->createBone(Ogre::StringConverter::toString(i * 2 + 2), i * 2 + 2);
        Ogre::Bone* bone2 = skeleton->createBone(Ogre::StringConverter::toString(i * 2 + 3), i * 2 + 3);

        LOGGER->Log("Skeleton bone-" + Ogre::StringConverter::toString(i + 2) + " length-" + Ogre::StringConverter::toString(bone.length) + " parent-" + Ogre::StringConverter::toString(bone.parent_id) +  + "\n");
        LOGGER->Log("bone1 " + Ogre::StringConverter::toString(i * 2 + 2) + ", bone2 " + Ogre::StringConverter::toString(i * 2 + 3) + "\n");

        skeleton->getBone(bone.parent_id * 2 + 1)->addChild(bone1);
        bone1->addChild(bone2);
    }

    if( m_WithWeapon == true )
    {
        Ogre::Bone* weapon1 = skeleton->createBone("weapon_1", number_of_bones * 2 + 2);
        root1->addChild(weapon1);
        Ogre::Bone* weapon2 = skeleton->createBone("weapon_2", number_of_bones * 2 + 3);
        weapon1->addChild(weapon2);
    }



    for (size_t bone = 0; bone < m_Skeleton.size(); ++bone)
    {
        int offset = m_Skeleton[bone].offset;
        if (offset != 0)
        {
            int offset_to_vertex = offset_to_models_description + offset;
            MeshExtractor(info.data, "ffvii/battle_model/" + info.data.name, this, offset_to_vertex, textures, mesh, Ogre::StringConverter::toString(bone), bone * 2 + 2);
        }
    }

    if (m_WithWeapon == true)
    {
        int number_of_files = GetU32LE(0x00);
        int offset_to_models_description = GetU32LE(number_of_files * 0x04 - 0x04);
        int offset_to_vertex = offset_to_models_description + 0x0c;
        MeshExtractor(info.data, "ffvii/battle_model/" + info.data.name, this, offset_to_vertex, textures, mesh, "weapon", number_of_bones * 2 + 3);
    }



    AnimationExtractor(this, skeleton, info, m_Skeleton, m_WithWeapon);



    // <OGRE> ///////////////////////////////
    skeleton->optimiseAllAnimations();
    Ogre::SkeletonSerializer skeleton_serializer;
    skeleton_serializer.exportSkeleton(skeleton.getPointer(), "exported/models/ffvii/battle/units/" + info.data.name + ".skeleton");

    // Update bounds
    Ogre::AxisAlignedBox aabb(-999, -999, -999, 999, 999, 999);
    mesh->_setBounds(aabb, false);
    mesh->_setBoundingSphereRadius(999);

    mesh->setSkeletonName( "models/ffvii/battle/units/" + info.data.name + ".skeleton" );

    Ogre::MeshSerializer ser;
    ser.exportMesh(mesh.getPointer(), "exported/models/ffvii/battle/units/" + info.data.name + ".mesh");



    // create and export textures for model
    if (textures.size() > 0)
    {
        int number_of_files = GetU32LE(0x00);
        int offset_to_texture = GetU32LE(number_of_files * 0x04);
        Vram* vram = Vram::MakeInstance().release();

        LoadTimFileToVram(this, offset_to_texture, vram);

        CreateTexture( vram, info.data, "exported/models/ffvii/battle/units/" + info.data.name + ".png", textures );
        delete vram;
    }



    //CreateMaterial("ffvii/battle_model/" + info.data.name, "exported/models/ffvii/battle/units/" + info.data.name + ".material", (textures.size() > 0) ? "models/ffvii/battle/units/" + info.data.name + ".png" : "", "Test/Fixed", "Test/Red");
    CreateMaterial("ffvii/battle_model/" + info.data.name, "exported/models/ffvii/battle/units/" + info.data.name + ".material", (textures.size() > 0) ? "models/ffvii/battle/units/" + info.data.name + ".png" : "", "", "");



    Ogre::SceneManager* scene_manager = Ogre::Root::getSingleton().getSceneManager( "Scene" );
    Ogre::Entity* thisEntity = scene_manager->createEntity( info.data.name, "models/ffvii/battle/units/" + info.data.name + ".mesh" );
    //thisEntity->setDisplaySkeleton(true);
    //thisEntity->setDebugDisplayEnabled(true);
    thisEntity->setVisible(false);
    thisEntity->getAnimationState("Idle")->setEnabled(true);
    thisEntity->getAnimationState("Idle")->setLoop(true);
    Ogre::SceneNode* thisSceneNode = scene_manager->getRootSceneNode()->createChildSceneNode();
    thisSceneNode->setPosition(0, 0, 0);
    thisSceneNode->roll(Ogre::Radian(Ogre::Degree(180.0f)));
    thisSceneNode->yaw(Ogre::Radian(Ogre::Degree(120.0f)));
    thisSceneNode->pitch(Ogre::Radian(Ogre::Degree(90.0f)));
    thisSceneNode->attachObject(thisEntity);

    return thisEntity;
}



void
EnemyFile::DumpSettings(const Ogre::String& file)
{
    Logger* settings = new Logger( file );

    int model_settings_offset = GetU32LE(0x08);

    m_WithWeapon = (GetU8( model_settings_offset + 2 ) & 0x80) > 0;
    LOGGER->Log( "Model With Weapon '" + Ogre::StringConverter::toString(m_WithWeapon) + "'\n" );

    settings->Log("// animation scripts\n");
    settings->Log("+00 [][]     " + HexToString(GetU16LE(model_settings_offset + 0), 4, '0') + " - if this is not 0 we add 0x40 bit to 8015190b\n");
    settings->Log("+02 []       " + HexToString(GetU8(model_settings_offset + 2), 2, '0') + " - 0x3f - dead type. 0x80 - play secondary animation\n");
    settings->Log("+03 []       " + HexToString(GetU8(model_settings_offset + 3), 2, '0') + "\n");
    settings->Log("+04 [][]     " + HexToString(GetU16LE(model_settings_offset + 4), 4, '0') + " - collision radius. Set to 801518e4+6\n");
    settings->Log("+06 [][]     " + HexToString(GetU16LE(model_settings_offset + 6), 4, '0') + " - to 801518ec\n");
    settings->Log("+08 [][]     " + HexToString(GetU16LE(model_settings_offset + 8), 4, '0') + " - to 801518ee\n");
    settings->Log("+0a [][]     " + HexToString(GetU16LE(model_settings_offset + 0xa), 4, '0') + " - to 801518f0\n");
    settings->Log("+0c [][]     " + HexToString(GetU16LE(model_settings_offset + 0xc), 4, '0') + "\n");
    settings->Log("+0e [][]     " + HexToString(GetU16LE(model_settings_offset + 0xe), 4, '0') + "\n");
    settings->Log("+10 [][]     " + HexToString(GetU16LE(model_settings_offset + 0x10), 4, '0') + " - filler?\n");

    settings->Log("+12 array of joints (bone indexes)\n    ");
    for (int i = 0; i < 0x10; ++i)
    {
        if (i != 0)
        {
            settings->Log(" ");
        }
        settings->Log(HexToString(GetU8(model_settings_offset + 0x12 + i), 2, '0'));
    }
    settings->Log("\n");

    settings->Log("+22 [][]     " + HexToString(GetU16LE(model_settings_offset + 0x22), 4, '0') + " - filler?\n");

    settings->Log("+24 array of 8 offsets to something\n    ");
    for (int i = 0; i < 8; ++i)
    {
        if (i != 0)
        {
            settings->Log(" ");
        }
        settings->Log(HexToString(GetU32LE(model_settings_offset + 0x24 + i * 4), 8, '0'));
    }
    settings->Log("\n");

    settings->Log("+44 array of 4 something\n    ");
    for (int i = 0; i < 4; ++i)
    {
        if (i != 0)
        {
            settings->Log(" ");
        }
        settings->Log(HexToString(GetU16LE(model_settings_offset + 0x44 + i * 2), 4, '0'));
    }
    settings->Log("\n");

    settings->Log("+4c array of 6 something\n    ");
    for (int i = 0; i < 6; ++i)
    {
        if (i != 0)
        {
            settings->Log(" ");
        }
        settings->Log(HexToString(GetU16LE(model_settings_offset + 0x4c + i * 2), 4, '0'));
    }
    settings->Log("\n");

    settings->Log("+58 array of 6 something\n    ");
    for (int i = 0; i < 6; ++i)
    {
        if (i != 0)
        {
            settings->Log(" ");
        }
        settings->Log(HexToString(GetU16LE(model_settings_offset + 0x58 + i * 2), 4, '0'));
    }
    settings->Log("\n");

    settings->Log("+64 [][]     " + HexToString(GetU16LE(model_settings_offset + 0x64), 4, '0') + "\n");
    settings->Log("+66 [][]     " + HexToString(GetU16LE(model_settings_offset + 0x66), 4, '0') + " - filler?\n");

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
        settings->Log(HexToString(GetU32LE(model_settings_offset + 0x68 + i * 4), 8, '0'));
    }
    settings->Log("\n");



    AnimationScriptDumper(this, model_settings_offset, settings);



    delete settings;
}
