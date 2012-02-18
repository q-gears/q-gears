#include "DrawSkeleton.h"

#define POSITION_BINDING 0

#include "../../common/Logger.h"

float* pPos;
u32 cur_index;
u16* idata;



void
DrawSkeleton( const Skeleton& skeleton, const Ogre::MeshPtr& mesh )
{
    Ogre::SubMesh* sub_mesh = mesh->createSubMesh( "Skeleton" );
    sub_mesh->setMaterialName( "Skeleton" );
    sub_mesh->useSharedVertices = false;
    sub_mesh->operationType = Ogre::RenderOperation::OT_LINE_LIST;

    // Allocate and prepare vertex data
    sub_mesh->vertexData = new Ogre::VertexData();
    sub_mesh->vertexData->vertexStart = 0;
    sub_mesh->vertexData->vertexCount = static_cast< size_t >( skeleton.size() * 2 - 2 );

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

    pPos = static_cast< float* >( vbuf0->lock( Ogre::HardwareBuffer::HBL_DISCARD ) );

    DrawBone( skeleton, 0, Ogre::Matrix3::IDENTITY, Ogre::Vector3::ZERO );

    vbuf0->unlock();

    sub_mesh->indexData->indexBuffer->unlock();
    sub_mesh->indexData->optimiseVertexCacheTriList();
}



void
DrawBone( const Skeleton& skeleton, int parent_index, const Ogre::Matrix3& matrix, const Ogre::Vector3& translation )
{
    for( size_t i = 1; i < skeleton.size(); ++i )
    {
        if( skeleton[ i ].parent_id == parent_index )
        {
            Ogre::Vector3 start = translation * matrix;
            Ogre::Vector3 end = start;
            LOGGER->Log( "bone " + Ogre::StringConverter::toString( i ) + " start" + Ogre::StringConverter::toString( start ) + " end " + Ogre::StringConverter::toString( end ) + "\n" );
            end.y += skeleton[ i ].length / 512.0f;

            DrawBone( skeleton, i, matrix, end );

            *pPos++ = start.x;  *pPos++ = start.y;  *pPos++ = start.z;
            *pPos++ = end.x;    *pPos++ = end.y;    *pPos++ = end.z;

            idata[ cur_index + 0 ] = cur_index + 0;
            idata[ cur_index + 1 ] = cur_index + 1;

            cur_index += 2;
        }
    }
}
