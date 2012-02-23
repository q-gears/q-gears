#include "DrawSkeleton.h"

#define POSITION_BINDING 0
#define COLOUR_BINDING 1

#include "../../common/Logger.h"

float* pPos;
u32 cur_index;
u16* idata;
Ogre::SubMesh* sub_mesh;



void
DrawSkeleton( const Skeleton& skeleton, const Ogre::MeshPtr& mesh )
{
    if( skeleton.size() == 0 )
    {
        return;
    }

    sub_mesh = mesh->createSubMesh( "Skeleton" );
    sub_mesh->setMaterialName( "Skeleton" );
    sub_mesh->useSharedVertices = false;
    sub_mesh->operationType = Ogre::RenderOperation::OT_LINE_LIST;

    // Allocate and prepare vertex data
    sub_mesh->vertexData = new Ogre::VertexData();
    sub_mesh->vertexData->vertexStart = 0;
    sub_mesh->vertexData->vertexCount = static_cast< size_t >( skeleton.size() * 2 );

    sub_mesh->indexData = new Ogre::IndexData();
    sub_mesh->indexData->indexStart = 0;
    sub_mesh->indexData->indexCount = sub_mesh->vertexData->vertexCount;
    sub_mesh->indexData->indexBuffer = Ogre::HardwareBufferManager::getSingleton().createIndexBuffer(
        Ogre::HardwareIndexBuffer::IT_16BIT,
        sub_mesh->indexData->indexCount,
        Ogre::HardwareBuffer::HBU_STATIC_WRITE_ONLY );
    idata = static_cast< u16* >( sub_mesh->indexData->indexBuffer->lock( Ogre::HardwareBuffer::HBL_DISCARD ) );
    cur_index = 0;

    Ogre::VertexDeclaration* decl = sub_mesh->vertexData->vertexDeclaration;
    Ogre::VertexBufferBinding* bind = sub_mesh->vertexData->vertexBufferBinding;
    // 1st buffer
    decl->addElement( POSITION_BINDING, 0, Ogre::VET_FLOAT3, Ogre::VES_POSITION );
    Ogre::HardwareVertexBufferSharedPtr vbuf0 = Ogre::HardwareBufferManager::getSingleton().createVertexBuffer(
        decl->getVertexSize( POSITION_BINDING ),
        sub_mesh->vertexData->vertexCount,
        Ogre::HardwareBuffer::HBU_STATIC_WRITE_ONLY );
    bind->setBinding( POSITION_BINDING, vbuf0 );

    // 2nd buffer
    decl->addElement( COLOUR_BINDING, 0, Ogre::VET_COLOUR, Ogre::VES_DIFFUSE );
    Ogre::HardwareVertexBufferSharedPtr vbuf1 = Ogre::HardwareBufferManager::getSingleton().createVertexBuffer(
        decl->getVertexSize( COLOUR_BINDING ),
        sub_mesh->vertexData->vertexCount,
        Ogre::HardwareBuffer::HBU_STATIC_WRITE_ONLY );
    // Set vertex buffer binding so buffer 1 is bound to our colour buffer
    bind->setBinding( COLOUR_BINDING, vbuf1 );

    pPos = static_cast< float* >( vbuf0->lock( Ogre::HardwareBuffer::HBL_DISCARD ) );


    Ogre::RGBA colours[ sub_mesh->vertexData->vertexCount ];



    DrawBone( skeleton, -1, colours );



    vbuf0->unlock();
    vbuf1->writeData( 0, vbuf1->getSizeInBytes(), colours, true );

    sub_mesh->indexData->indexBuffer->unlock();
    sub_mesh->indexData->optimiseVertexCacheTriList();
}



void
DrawBone( const Skeleton& skeleton, int parent_index, Ogre::RGBA* colours )
{
    for( size_t i = 0; i < skeleton.size(); ++i )
    {
        if( skeleton[ i ].parent_id == parent_index )
        {

            *pPos++ = 0; *pPos++ = 0; *pPos++ = 0;
            *pPos++ = 0; *pPos++ = 0; *pPos++ = 0;

            Ogre::ColourValue colour1 = Ogre::ColourValue( 1, 0, 0 );
            Ogre::ColourValue colour2 = Ogre::ColourValue( 1, 1, 0 );

            Ogre::RenderSystem* rs = Ogre::Root::getSingleton().getRenderSystem();
            rs->convertColourValue( colour1, colours + cur_index + 0 );
            rs->convertColourValue( colour2, colours + cur_index + 1 );

            idata[ cur_index + 0 ] = cur_index + 0;
            idata[ cur_index + 1 ] = cur_index + 1;

            Ogre::VertexBoneAssignment vba;
            vba.vertexIndex = cur_index + 0;
            vba.boneIndex = ( parent_index == -1 ) ? 1 : parent_index * 2 + 3;
            vba.weight = 1.0f;
            sub_mesh->addBoneAssignment( vba );
            vba.vertexIndex = cur_index + 1;
            vba.boneIndex = i * 2 + 3;
            vba.weight = 1.0f;
            sub_mesh->addBoneAssignment( vba );

            cur_index += 2;

            DrawBone( skeleton, i, colours );
        }
    }
}
