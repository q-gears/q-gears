#include "FieldModel.h"

#include "FieldFile.h"
#include "ModelFile.h"
#include "common/File.h"
#include "common/Logger.h"
#include "../../common/OgreGenUtilites.h"



FieldModel::FieldModel()
{
}



FieldModel::~FieldModel()
{
}



void
FieldModel::Export( const Ogre::String& model_file, const Ogre::String& texture_file )
{
    MeshData data;
    data.name = "lahan";
    data.tex_width = 4096;
    data.tex_height = 512;

    VectorTexForGen textures;

    FieldFile* field_file = new FieldFile( model_file );
    File* export_file = field_file->Extract( 2 );
    delete field_file;

    int number_of_models = export_file->GetU32LE( 0x00 );

    for( int i = 0; i < number_of_models; ++i )
    {
        Ogre::MeshPtr mesh = Ogre::MeshManager::getSingleton().create( data.name + Ogre::StringConverter::toString( i ) + "export", "General" );
        Ogre::SkeletonPtr skeleton = Ogre::SkeletonManager::getSingleton().create( data.name + Ogre::StringConverter::toString( i ) + "export", "General" );
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



        Logger* export_text = new Logger( "exported/" + data.name + Ogre::StringConverter::toString( i ) + ".txt" );



        int mesh_offset = export_file->GetU32LE( 0x4 + i * 0x04 );
        int mesh_next_offset = ( i + 1 == number_of_models ) ? export_file->GetFileSize() : export_file->GetU32LE( 0x8 + i * 0x04 );
        int mesh_size = mesh_next_offset - mesh_offset;

        ModelFile* mesh_file = new ModelFile( export_file, mesh_offset, mesh_size );
        mesh_file->GetModel( mesh, data, textures, export_text );
        delete mesh_file;


        skeleton->optimiseAllAnimations();
        Ogre::SkeletonSerializer skeleton_serializer;
        skeleton_serializer.exportSkeleton( skeleton.getPointer(), "exported/models/field/maps/" + data.name + "/" + data.name + Ogre::StringConverter::toString( i ) + ".skeleton" );

        // Update bounds
        Ogre::AxisAlignedBox aabb( -999, -999, -999, 999, 999, 999 );
        mesh->_setBounds( aabb, false );
        mesh->_setBoundingSphereRadius( 999 );

        mesh->setSkeletonName( "models/field/maps/" + data.name + "/" + data.name + Ogre::StringConverter::toString( i ) + ".skeleton" );

        Ogre::MeshSerializer ser;
        ser.exportMesh( mesh.getPointer(), "exported/models/field/maps/" + data.name + "/" + data.name + Ogre::StringConverter::toString( i ) + ".mesh" );
    }



    // create and export textures for model
    if( textures.size() > 0 )
    {
        File* texture = new File( texture_file );
        Vram* vram = Vram::MakeInstance().release();

        for( u32 i = 0; i < texture->GetFileSize(); )
        {
            u32 texture_header_id = texture->GetU32LE( i + 0x00 );
            u16 texture_header_vram_x = texture->GetU16LE( i + 0x04 );
            u16 texture_header_vram_y = texture->GetU16LE( i + 0x06 );
            u16 texture_header_move_x = texture->GetU16LE( i + 0x08 );
            u16 texture_header_move_y = texture->GetU16LE( i + 0x0a );
            u16 texture_header_width = texture->GetU16LE( i + 0x0c );
            u16 texture_header_height = texture->GetU16LE( i + 0x0e );

            u32 number_of_chunk = texture->GetU32LE( i + 0x18 );

            u16 vram_x = ( texture_header_vram_x + texture_header_move_x ) * 2;
            u16 vram_y = texture_header_vram_y + texture_header_move_y;

            // move to data (header always in separate sector)
            u32 temp_i = i;
            i += 0x0800;

            for( u32 j = 0; j < number_of_chunk; ++j )
            {
                // get height of current chunk
                u16 height = texture->GetU16LE( temp_i + 0x1C + j * 0x02 );
//LOGGER->Log("texture_header_width = " + ToHexString(texture_header_width, 8, '0') + "\n");
//LOGGER->Log("height = " + ToHexString(height, 8, '0') + "\n");
//LOGGER->Log("vram_x = " + ToHexString(vram_x, 8, '0') + "\n");
//LOGGER->Log("vram_y = " + ToHexString(vram_y, 8, '0') + "\n");
                // palette
                if( texture_header_id == 0x00001201 )
                {
                    for( int y = 0; y < height; ++y )
                    {
                        for( int x = 0; x < texture_header_width; ++x )
                        {
                            u16 color = texture->GetU16LE( i + x * 0x02 + y * texture_header_width * 0x02 );
                            vram->PutU16( x * 2 + vram_x, y + vram_y, color );
//LOGGER->Log("put color (" + ToHexString(color, 8, '0') + ") to x (" + ToHexString(x * 2 + vram_x, 8, '0') + ") y (" + ToHexString(y + vram_y, 8, '0') + ")\n");
                        }
                    }
                }

                // textures
                else if( texture_header_id == 0x00001200 )
                {
                    for( int y = 0; y < height; ++y )
                    {
                        for( int x = 0; x < texture_header_width * 2; ++x )
                        {
                            u8 data = texture->GetU8( i + x + y * texture_header_width * 2 );
                            vram->PutU8( x + vram_x, y + vram_y, data );
                        }
                    }
                }

                // move pointer to start of next texture
                i += static_cast<u32>(ceil( ( float )( texture_header_width * 2 * height) / 0x0800 ) * 0x0800);
                // update height
                texture_header_height += height;
                vram_y += height;
            }
        }

        //vram->Save( "1.png" );

        CreateTexture( vram, data, "exported/models/field/maps/" + data.name + "/" + data.name + ".png", textures );

        delete vram;
        delete texture;
    }



    CreateMaterial( "xeno/field/" + data.name, "exported/models/field/maps/" + data.name + "/" + data.name + ".material", (textures.size() > 0) ? "models/field/maps/" + data.name + "/" + data.name + ".png" : "", "", "" );



    for( int i = 0; i < number_of_models; ++i )
    {
        Ogre::SceneManager* scene_manager = Ogre::Root::getSingleton().getSceneManager( "Scene" );
        Ogre::Entity* thisEntity = scene_manager->createEntity( data.name + Ogre::StringConverter::toString( i ), "models/field/maps/" + data.name + "/" + data.name + Ogre::StringConverter::toString( i ) + ".mesh" );
        thisEntity->setVisible( true );
        thisEntity->getAnimationState( "Idle" )->setEnabled( true );
        thisEntity->getAnimationState( "Idle" )->setLoop( true );
        Ogre::SceneNode* thisSceneNode = scene_manager->getRootSceneNode()->createChildSceneNode();
        thisSceneNode->setPosition( 0, 0, 0 );
        thisSceneNode->roll( Ogre::Radian( Ogre::Degree( 180.0f ) ) );
        thisSceneNode->yaw( Ogre::Radian( Ogre::Degree( 120.0f ) ) );
        thisSceneNode->pitch( Ogre::Radian( Ogre::Degree( 90.0f ) ) );
        thisSceneNode->attachObject( thisEntity );
    }



    delete export_file;
}
