#include "AnimatedModel.h"
#include "AnimationExtractor.h"
#include "ModelFile.h"
#include "common/File.h"
#include "common/Logger.h"



AnimatedModel::AnimatedModel()
{
}



AnimatedModel::~AnimatedModel()
{
}



Ogre::Entity*
AnimatedModel::Export( const ModelInfo& info )
{
    VectorTexForGen textures;

    Ogre::MeshPtr mesh = Ogre::MeshManager::getSingleton().create( info.data.name + "export", "General" );
    Ogre::SkeletonPtr skeleton = Ogre::SkeletonManager::getSingleton().create( info.data.name + "export", "General" );

    Logger* export_text = new Logger( "exported/models/xenogears/field/units/" + info.data.name + ".txt" );



    File* export_file = new File( "./data/field/" + info.model_file );

    int tex_offset = export_file->GetU32LE( 0x04 );
    int mesh_offset = export_file->GetU32LE( 0x08 );
    int hrc_offset = export_file->GetU32LE( 0x0c );
    int tex_size = mesh_offset - tex_offset;
    int mesh_size = hrc_offset - mesh_offset;
    int hrc_size = export_file->GetU32LE( 0x10 ) - hrc_offset;

    File* texture = new File( export_file, tex_offset, tex_size );
    ModelFile* mesh_file = new ModelFile( export_file, mesh_offset, mesh_size );
    File* hrc = new File( export_file, hrc_offset, hrc_size );



    // skeleton
    Ogre::Bone* root1 = skeleton->createBone( "0", 0 );
    Ogre::Bone* root2 = skeleton->createBone( "1", 1 );
    root1->addChild( root2 );

    for( int i = 0; hrc->GetU32LE( i * 4 ) != 0xFFFEFFFE; ++i )
    {
        // first data in submesh index
        Bone bone;
        bone.parent_id = ( s16 )hrc->GetU16LE( i * 4 + 0x02 );
        bone.length    = 20;
        m_Skeleton.push_back( bone );

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

        // create mesh assigned to that bone
        int part_id = ( s16 )hrc->GetU16LE( i * 4 + 0x00 );
        if( part_id != -1 )
        {
            mesh_file->GetModelPart( part_id, mesh, info.data, textures, export_text, i * 2 + 3 );
        }
    }



    AnimationExtractor( skeleton, info, m_Skeleton );



    // draw skeleton
    //DrawSkeleton( m_Skeleton, mesh );



    skeleton->optimiseAllAnimations();
    Ogre::SkeletonSerializer skeleton_serializer;
    skeleton_serializer.exportSkeleton( skeleton.getPointer(), "exported/models/xenogears/field/units/" + info.data.name + ".skeleton" );

    // Update bounds
    Ogre::AxisAlignedBox aabb( -999, -999, -999, 999, 999, 999 );
    mesh->_setBounds( aabb, false );
    mesh->_setBoundingSphereRadius( 999 );
    mesh->setSkeletonName( "models/xenogears/field/units/" + info.data.name + ".skeleton" );

    Ogre::MeshSerializer ser;
    ser.exportMesh( mesh.getPointer(), "exported/models/xenogears/field/units/" + info.data.name + ".mesh" );



    // create and export textures for model
    if( textures.size() > 0 )
    {
        Vram* vram = Vram::MakeInstance().release();

        for( u32 i = 0; i < texture->GetU32LE( 0 ); ++i )
        {
            int offset_to_tex = texture->GetU32LE( 0x04 + i * 0x04 );

            u32 texture_header_id = texture->GetU32LE( offset_to_tex + 0x00 );
            u16 texture_header_vram_x = texture->GetU16LE( offset_to_tex + 0x04 );
            u16 texture_header_vram_y = texture->GetU16LE( offset_to_tex + 0x06 );
            u16 texture_header_move_x = texture->GetU16LE( offset_to_tex + 0x08 );
            u16 texture_header_move_y = texture->GetU16LE( offset_to_tex + 0x0a );
            u16 texture_header_width = texture->GetU16LE( offset_to_tex + 0x0c );
            u16 texture_header_height = texture->GetU16LE( offset_to_tex + 0x0e );



            // palette
            if( texture_header_id == 0x00001101 )
            {
                u16 vram_x = ( texture_header_vram_x + texture_header_move_x ) * 2;
                u16 vram_y = texture_header_vram_y + texture_header_move_y;

                for( int y = 0; y < texture_header_height; ++y )
                {
                    for( int x = 0; x < texture_header_width; ++x )
                    {
                        u16 color = texture->GetU16LE( offset_to_tex + 0x10 + x * 0x02 + y * texture_header_width * 0x02 );
                        vram->PutU16( x * 2 + vram_x, y + vram_y, color );
                    }
                }
            }

            // textures
            else if( texture_header_id == 0x00001100 )
            {
                u16 vram_x = ( texture_header_vram_x + texture_header_move_x ) * 2;
                u16 vram_y = texture_header_vram_y + texture_header_move_y;

                for( int y = 0; y < texture_header_height; ++y )
                {
                    for( int x = 0; x < texture_header_width * 2; ++x )
                    {
                        u8 data = texture->GetU8( offset_to_tex + 0x10 + x + y * texture_header_width * 2 );
                        vram->PutU8( x + vram_x, y + vram_y, data );
                    }
                }
            }
        }

        //vram->Save( "1.png" );

        CreateTexture( vram, info.data, "exported/models/xenogears/field/units/" + info.data.name + ".png", textures );
        delete vram;
    }



    CreateMaterial( "xenogears/model/" + info.data.name, "exported/models/xenogears/field/units/" + info.data.name + ".material", ( textures.size() > 0 ) ? "models/xenogears/field/units/" + info.data.name + ".png" : "", "", "" );



    Ogre::SceneManager* scene_manager = Ogre::Root::getSingleton().getSceneManager( "Scene" );
    Ogre::Entity* thisEntity = scene_manager->createEntity( info.data.name, "models/xenogears/field/units/" + info.data.name + ".mesh" );
    thisEntity->setVisible( true );
    thisEntity->getAnimationState( "Idle" )->setEnabled( true );
    thisEntity->getAnimationState( "Idle" )->setLoop( true );
    Ogre::SceneNode* thisSceneNode = scene_manager->getRootSceneNode()->createChildSceneNode();
    thisSceneNode->setPosition( 0, 0, 0 );
    thisSceneNode->roll( Ogre::Radian( Ogre::Degree( 180.0f ) ) );
    thisSceneNode->yaw( Ogre::Radian( Ogre::Degree( 120.0f ) ) );
    thisSceneNode->pitch( Ogre::Radian( Ogre::Degree( 90.0f ) ) );
    thisSceneNode->attachObject( thisEntity );



    delete mesh_file;
    delete texture;
    delete export_file;

    return thisEntity;
}
