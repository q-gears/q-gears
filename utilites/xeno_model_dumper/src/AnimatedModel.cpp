#include "AnimatedModel.h"
#include "ModelFile.h"
#include "../../common/File.h"
#include "../../common/Logger.h"
#include "../../common/OgreGenUtilites.h"



AnimatedModel::AnimatedModel()
{
}



AnimatedModel::~AnimatedModel()
{
}



void
AnimatedModel::Export(const Ogre::String& model_file, const Ogre::String& animation_file)
{
    MeshData data;
    data.name = "weltall";
    data.tex_width = 4096;
    data.tex_height = 256;



    VectorTexForGen textures;

    Ogre::MeshPtr mesh = Ogre::MeshManager::getSingleton().create(data.name + "export", "General");
    Ogre::SkeletonPtr skeleton = Ogre::SkeletonManager::getSingleton().create(data.name + "export", "General");

    Logger* export_text = new Logger("exported/" + data.name + ".txt");



    File* export_file = new File(model_file);

    int tex_offset = export_file->GetU32LE(0x04);
    int mesh_offset = export_file->GetU32LE(0x08);
    int tex_size = mesh_offset - tex_offset;
    int mesh_size = export_file->GetU32LE(0x0c) - mesh_offset;

    File* texture = new File(export_file, tex_offset, tex_size);
    ModelFile* mesh_file = new ModelFile(export_file, mesh_offset, mesh_size);
    mesh_file->GetModel(mesh, data, textures, export_text);



    skeleton->optimiseAllAnimations();
    Ogre::SkeletonSerializer skeleton_serializer;
    skeleton_serializer.exportSkeleton(skeleton.getPointer(), "exported/" + data.name + ".skeleton");

    // Update bounds
    Ogre::AxisAlignedBox aabb(-999, -999, -999, 999, 999, 999);
    mesh->_setBounds(aabb, false);
    mesh->_setBoundingSphereRadius(999);

    //mesh->setSkeletonName(data.name + ".skeleton");

    Ogre::MeshSerializer ser;
    ser.exportMesh(mesh.getPointer(), "exported/" + data.name + ".mesh");



    // create and export textures for model
    if (textures.size() > 0)
    {
        Vram* vram = new Vram();

        for (int i = 0; i < texture->GetU32LE(0); ++i)
        {
            int offset_to_tex = texture->GetU32LE(0x04 + i * 0x04);

            u32 texture_header_id = texture->GetU32LE(offset_to_tex + 0x00);
            u16 texture_header_vram_x = texture->GetU16LE(offset_to_tex + 0x04);
            u16 texture_header_vram_y = texture->GetU16LE(offset_to_tex + 0x06);
            u16 texture_header_move_x = texture->GetU16LE(offset_to_tex + 0x08);
            u16 texture_header_move_y = texture->GetU16LE(offset_to_tex + 0x0a);
            u16 texture_header_width = texture->GetU16LE(offset_to_tex + 0x0c);
            u16 texture_header_height = texture->GetU16LE(offset_to_tex + 0x0e);



            // palette
            if (texture_header_id == 0x00001101)
            {
                u16 vram_x = (texture_header_vram_x + texture_header_move_x) * 2;
                u16 vram_y = texture_header_vram_y + texture_header_move_y;

                for (int y = 0; y < texture_header_height; ++y)
                {
                    for (int x = 0; x < texture_header_width; ++x)
                    {
                        u16 color = texture->GetU16LE(offset_to_tex + 0x10 + x * 0x02 + y * texture_header_width * 0x02);
                        vram->PutU16(x * 2 + vram_x, y + vram_y, color);

//LOGGER->Log("put color (" + ToHexString(color, 8, '0') + ") to x (" + ToHexString(x * 2 + vram_x, 8, '0') + ") y (" + ToHexString(y + vram_y, 8, '0') + ")\n");
                    }
                }
            }

            // textures
            else if (texture_header_id == 0x00001100)
            {
                u16 vram_x = (texture_header_vram_x + texture_header_move_x) * 2;
                u16 vram_y = texture_header_vram_y + texture_header_move_y;

                for (int y = 0; y < texture_header_height; ++y)
                {
                    for (int x = 0; x < texture_header_width * 2; ++x)
                    {
                        u8 data = texture->GetU8(offset_to_tex + 0x10 + x + y * texture_header_width * 2);
                        vram->PutU8(x + vram_x, y + vram_y, data);
                    }
                }
            }
        }

        vram->Save("1.png");

        CreateTexture(vram, data, "exported/" + data.name + ".png", textures);
        delete vram;
    }



    CreateMaterial( "" + data.name, "exported/" + data.name + ".material", (textures.size() > 0) ? data.name + ".png" : "", "", "" );



    Ogre::SceneManager* scene_manager = Ogre::Root::getSingleton().getSceneManager("Scene");
    Ogre::Entity* thisEntity = scene_manager->createEntity(data.name, data.name + ".mesh");
    thisEntity->setVisible(true);
    //thisEntity->getAnimationState("idle")->setEnabled(true);
    //thisEntity->getAnimationState("idle")->setLoop(true);
    Ogre::SceneNode* thisSceneNode = scene_manager->getRootSceneNode()->createChildSceneNode();
    thisSceneNode->setPosition(0, 0, 0);
    thisSceneNode->roll(Ogre::Radian(Ogre::Degree(180.0f)));
    thisSceneNode->yaw(Ogre::Radian(Ogre::Degree(120.0f)));
    thisSceneNode->pitch(Ogre::Radian(Ogre::Degree(90.0f)));
    thisSceneNode->attachObject(thisEntity);



    delete mesh_file;
    delete texture;
    delete export_file;
}
