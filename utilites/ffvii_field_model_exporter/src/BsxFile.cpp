#include <Ogre.h>

#include "../../common/Logger.h"

#include "BsxFile.h"
#include "BcxFile.h"
#include "TdbFile.h"
#include "AnimationFile.h"
#include "MeshFile.h"
#include "SkeletonFile.h"



BsxFile::BsxFile(const Ogre::String& file):
    LzsFile(file)
{
    ReadBSXTextureToVram();
}



BsxFile::BsxFile(File* pFile):
    LzsFile(pFile)
{
    ReadBSXTextureToVram();
}



BsxFile::BsxFile(File* pFile, const u32 offset, const u32 length):
    LzsFile(pFile, offset, length)
{
    ReadBSXTextureToVram();
}



BsxFile::BsxFile(u8* pBuffer, const u32 offset, const u32 length):
    LzsFile(pBuffer, offset, length)
{
    ReadBSXTextureToVram();
}



BsxFile::~BsxFile()
{
}



Ogre::Entity*
BsxFile::GetModel( Ogre::Entity* entity, const s8 character_id, const Unit& unit, const DatModelData dat )
{
    int start_animation = ( dat.global_model_id > 0 ) ? 3 : 0;
    u32 offset_to_models_description = GetU32LE(0x04);
    u32 number_of_models_description = GetU32LE( offset_to_models_description + 0x04 );

    if( character_id >= number_of_models_description )
    {
        return NULL;
    }

    u32 offset_to_field_model_description = offset_to_models_description + 0x10 + character_id * 0x30;
    //LOGGER->Log(LOGGER_INFO, "\n\noffset_to_field_model_description: %08x", offset_to_field_model_description);

    u8 number_of_bones      = GetU8(offset_to_field_model_description + 0x17);
    u8 number_of_parts      = GetU8(offset_to_field_model_description + 0x23);
    u8 number_of_animations = GetU8(offset_to_field_model_description + 0x2f);
    //LOGGER->Log(LOGGER_INFO, "number of bones %02x", number_of_bones);
    //LOGGER->Log(LOGGER_INFO, "number of parts %02x", number_of_parts);
    //LOGGER->Log(LOGGER_INFO, "number of animations %02x", number_of_animations);

    VectorTexForGenBsx textures;
    std::vector< s16 > skeleton_length;

    Ogre::MeshPtr mesh;
    Ogre::SkeletonPtr skeleton;

    if (entity == NULL)
    {
        mesh     = Ogre::MeshManager::getSingleton().create( "export" + unit.name, "General" );
        skeleton = Ogre::SkeletonManager::getSingleton().create( "export" + unit.name, "General" );

        switch (dat.global_model_id)
        {
            case 1:
            {
                BcxFile file( "data/field/cloud.bcx" );
                file.GetModel(skeleton_length, unit, mesh, skeleton, textures);
            }
            break;

            case 3:
            {
                BcxFile file( "data/field/ballet.bcx" );
                file.GetModel(skeleton_length, unit, mesh, skeleton, textures);
            }
            break;

            case 4:
            {
                BcxFile file( "data/field/tifa.bcx" );
                file.GetModel(skeleton_length, unit, mesh, skeleton, textures);
            }
            break;

            case 7:
            {
                BcxFile file( "data/field/yufi.bcx" );
                file.GetModel(skeleton_length, unit, mesh, skeleton, textures);
            }
            break;

            default:
            {
                // mesh
                u32 offset_to_parts = offset_to_field_model_description + GetU32LE(offset_to_field_model_description + 0x4) + number_of_bones * 4;
                MeshFile file_m(this);
                file_m.GetData(unit.name, offset_to_parts, number_of_parts, mesh, textures);

                // skeleton
                u32 offset_to_bones = offset_to_field_model_description + GetU16LE(offset_to_field_model_description + 0x4);
                SkeletonFile file_s(this);
                file_s.GetData(skeleton_length, offset_to_bones, number_of_bones, skeleton);
            }
        }
    }
    else
    {
        skeleton = Ogre::SkeletonManager::getSingleton().getByName(entity->getSkeleton()->getName());

        switch( dat.global_model_id )
        {
            case 1:
            {
                BcxFile file( "data/field/cloud.bcx" );
                file.GetSkeleton( skeleton_length );
            }
            break;

            case 3:
            {
                BcxFile file( "data/field/ballet.bcx" );
                file.GetSkeleton( skeleton_length );
            }
            break;

            case 4:
            {
                BcxFile file( "data/field/tifa.bcx" );
                file.GetSkeleton( skeleton_length );
            }
            break;

            case 7:
            {
                BcxFile file( "data/field/yufi.bcx" );
                file.GetSkeleton( skeleton_length );
            }
            break;

            default:
            {
                // skeleton
                u32 offset_to_bones = offset_to_field_model_description + GetU16LE( offset_to_field_model_description + 0x4 );
                SkeletonFile file_s( this );
                Ogre::SkeletonPtr null_skeleton;
                null_skeleton.setNull();
                file_s.GetData( skeleton_length, offset_to_bones, number_of_bones, null_skeleton );
            }
        }
    }



    // animations
    u32 offset_to_animations = offset_to_field_model_description + GetU16LE(offset_to_field_model_description + 0x4) + number_of_bones * 4 + number_of_parts * 0x20;
    AnimationFile file( this );
    file.GetData( skeleton_length, unit, offset_to_animations, number_of_animations, start_animation, skeleton );



    Ogre::SkeletonSerializer skeleton_serializer;
    skeleton_serializer.exportSkeleton( skeleton.getPointer(), "exported/models/ffvii/field/units/" + unit.name + ".skeleton" );

    if (entity == NULL)
    {
        // Update bounds
        Ogre::AxisAlignedBox aabb( -999, -999, -999, 999, 999, 999 );
        mesh->_setBounds( aabb, false );
        mesh->_setBoundingSphereRadius( 999 );

        mesh->setSkeletonName( "models/ffvii/field/units/" + unit.name + ".skeleton" );

        Ogre::MeshSerializer ser;
        ser.exportMesh( mesh.getPointer(), "exported/models/ffvii/field/units/" + unit.name + ".mesh" );



        // create and export textures for model
        CreateTexture( unit.name, dat.face_id, textures );



        Ogre::MaterialPtr material = Ogre::MaterialManager::getSingleton().create( "ffvii/model/field/" + unit.name, "General" );
        Ogre::Technique* tech = material->getTechnique( 0 );
        Ogre::Pass* pass1 = tech->getPass( 0 );
        pass1->setVertexColourTracking( Ogre::TVC_AMBIENT );
        pass1->setCullingMode( Ogre::CULL_NONE );
        Ogre::Pass* pass2 = tech->createPass();
        pass2->setCullingMode( Ogre::CULL_NONE );
        pass2->setAlphaRejectFunction( Ogre::CMPF_GREATER );
        pass2->setAlphaRejectValue( 0 );
        Ogre::TextureUnitState* tex = pass2->createTextureUnitState();
        if( dat.face_id != 0x21 )
        {
            tex->setTextureScroll( 0.0625, 0 );
        }
        tex->setTextureName( "models/ffvii/field/units/" + unit.name + ".png" );
        tex->setNumMipmaps( 0 );
        tex->setTextureFiltering( Ogre::TFO_NONE );
        Ogre::MaterialSerializer mat;
        mat.exportMaterial( material, "exported/models/ffvii/field/units/" + unit.name + ".material" );



        Ogre::SceneManager* scene_manager = Ogre::Root::getSingleton().getSceneManager( "Scene" );
        Ogre::Entity* thisEntity = scene_manager->createEntity( unit.name, "models/ffvii/field/units/" + unit.name + ".mesh" );
        //thisEntity->setDisplaySkeleton(true);
        //thisEntity->setDebugDisplayEnabled(true);
        thisEntity->setVisible( false );
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
    else
    {
        entity->refreshAvailableAnimationState();
        return NULL;
    }
}



void
BsxFile::CreateTexture( const Ogre::String& name, const int face_id, const VectorTexForGenBsx& textures )
{
    int tex_width = 512;
    int tex_height = 256;

    Ogre::TexturePtr ptex;
    Ogre::HardwarePixelBufferSharedPtr buffer;
    ptex = Ogre::TextureManager::getSingleton().createManual( "DynaTex", "General", Ogre::TEX_TYPE_2D, tex_width, tex_height, 0, Ogre::PF_R8G8B8A8, Ogre::TU_STATIC );
    buffer = ptex->getBuffer( 0, 0 );
    buffer->lock( Ogre::HardwareBuffer::HBL_DISCARD );
    const Ogre::PixelBox& pb = buffer->getCurrentLock();




    for( int i = 0; i < textures.size(); ++i )
    {
        if( textures[ i ].type == 0 || textures[ i ].type == 1 )
        {
            TdbFile face_texture( "data/field/field.tdb" );
            face_texture.CreateTexture( pb, face_id, textures[ i ].start_x, textures[ i ].start_y );
        }
        else if( textures[ i ].type == 2 )
        {
            CreateTextureFromVram( pb, &m_Vram, textures[ i ].start_x, textures[ i ].start_y, textures[ i ].palette_x, textures[ i ].palette_y, textures[ i ].texture_x, textures[ i ].texture_y, textures[ i ].bpp, true );
        }
    }



    Ogre::Image image;
    image.loadDynamicImage((Ogre::uchar*)pb.data, tex_width, tex_height, Ogre::PF_R8G8B8A8);
    image.save( "exported/models/ffvii/field/units/" + name + ".png" );
    buffer->unlock();

    return;
}



void
BsxFile::ReadBSXTextureToVram()
{
    u32 offset_to_models_description = GetU32LE( 0x04 );
    u32 offset_to_texture = offset_to_models_description + GetU32LE( offset_to_models_description + 0x08 );

    u32 unknown = GetU32LE( offset_to_texture + 0x04 ) & 0xffffff00;
    //LOGGER->Log(LOGGER_INFO, "WARNING WARNING %04x", unknown);

    u8 number_of_texture = GetU8( offset_to_texture + 0x04 );
    //LOGGER->Log(LOGGER_INFO, "number_of_texture %04x", number_of_texture);
    if( number_of_texture == 0 )
    {
        return;
    }

    for( int i = 0; i < number_of_texture; ++i )
    {
        u16 width     = GetU16LE( offset_to_texture + 0x08 + i * 0x0c + 0x00 ) * 2;
        u16 height    = GetU16LE( offset_to_texture + 0x08 + i * 0x0c + 0x02 );
        u16 vram_x    = GetU16LE( offset_to_texture + 0x08 + i * 0x0c + 0x04 ) * 2;
        u16 vram_y    = GetU16LE( offset_to_texture + 0x08 + i * 0x0c + 0x06 );
        u32 start     = offset_to_texture + GetU32LE( offset_to_texture + 0x08 + i * 0x0c + 0x08 );
        //LOGGER->Log(LOGGER_INFO, "Store BSX texture to vram %04x %04x", vram_x, vram_y);
        for( int y = 0; y < height; ++y )
        {
            for( int x = 0; x < width; ++x )
            {
                m_Vram.PutU8( vram_x + x, vram_y + y, GetU8( start + y * width + x ) );
            }
        }
    }
}
