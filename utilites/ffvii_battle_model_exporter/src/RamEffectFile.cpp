#include <Ogre.h>

#include "RamEffectFile.h"
#include "../../common/Logger.h"
#include "../../common/OgreGenUtilites.h"



RamEffectFile::RamEffectFile(const Ogre::String& file):
    File(file)
{
}



RamEffectFile::RamEffectFile(File* pFile):
    File(pFile)
{
}



RamEffectFile::RamEffectFile(File* pFile, u32 offset, u32 length):
    File(pFile, offset, length)
{
}



RamEffectFile::RamEffectFile(u8* pBuffer, u32 offset, u32 length):
    File(pBuffer, offset, length)
{
}



RamEffectFile::~RamEffectFile()
{
}



Ogre::Entity*
RamEffectFile::GetModel(const EffectInfo info)
{
    VectorTexForGen textures;
    Ogre::MeshPtr mesh = Ogre::MeshManager::getSingleton().create(info.data.name + "export", "General");



    int offset_to_models_description = GetU32LE(info.offset) - 0x80000000; // there is additional info in offset + 4 and so on (described in function funcd29d4)



    int offset_to_vertex     = offset_to_models_description;
    MeshExtractor(info.data, "ffvii/battle_effect/" + info.data.name, this, offset_to_vertex, textures, mesh, info.data.name);



    // Update bounds
    Ogre::AxisAlignedBox aabb(-999, -999, -999, 999, 999, 999);
    mesh->_setBounds(aabb, false);
    mesh->_setBoundingSphereRadius(999);

    Ogre::MeshSerializer ser;
    ser.exportMesh(mesh.getPointer(), "exported/models/battle/effects/" + info.data.name + ".mesh");



    // create and export textures for model
    if (textures.size() > 0)
    {
        Vram* vram = new Vram();
        CreateTexture(vram, info.data, "exported/models/battle/effects/" + info.data.name + ".png", textures);
        delete vram;
    }



    CreateMaterial("ffvii/battle_effect/" + info.data.name, "exported/models/battle/effects/" + info.data.name + ".material", (textures.size() > 0) ? "models/battle/effects/" + info.data.name + ".png" : "", "", "");



    Ogre::SceneManager* scene_manager = Ogre::Root::getSingleton().getSceneManager( "Scene" );
    Ogre::Entity* thisEntity = scene_manager->createEntity( info.data.name, "models/battle/effects/" + info.data.name + ".mesh" );
    thisEntity->setVisible(true);
    Ogre::SceneNode* thisSceneNode = scene_manager->getRootSceneNode()->createChildSceneNode();
    thisSceneNode->setPosition(0, 0, 0);
    thisSceneNode->roll(Ogre::Radian(Ogre::Degree(180.0f)));
    thisSceneNode->yaw(Ogre::Radian(Ogre::Degree(120.0f)));
    thisSceneNode->pitch(Ogre::Radian(Ogre::Degree(90.0f)));
    thisSceneNode->attachObject(thisEntity);

    return thisEntity;
}
