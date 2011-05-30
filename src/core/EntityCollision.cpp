#include "EntityCollision.h"

#include <OgreHardwareBufferManager.h>


EntityCollision::EntityCollision()
{
    mRenderOp.vertexData = new Ogre::VertexData();

    mRenderOp.indexData = 0;
    mRenderOp.vertexData->vertexCount = 74;
    mRenderOp.vertexData->vertexStart = 0;
    mRenderOp.operationType = Ogre::RenderOperation::OT_LINE_LIST;
    mRenderOp.useIndexes = false;

    Ogre::VertexDeclaration* decl = mRenderOp.vertexData->vertexDeclaration;
    Ogre::VertexBufferBinding* bind = mRenderOp.vertexData->vertexBufferBinding;

    decl->addElement( 0, 0, Ogre::VET_FLOAT3, Ogre::VES_POSITION );
    Ogre::HardwareVertexBufferSharedPtr vbuf0 = Ogre::HardwareBufferManager::getSingleton().createVertexBuffer(
            decl->getVertexSize( 0 ),
            mRenderOp.vertexData->vertexCount,
            Ogre::HardwareBuffer::HBU_STATIC_WRITE_ONLY );
    bind->setBinding( 0, vbuf0 );

    float* pPos = static_cast< float* >( vbuf0->lock( Ogre::HardwareBuffer::HBL_DISCARD ) );

    *pPos++ = -1.0f; *pPos++ =  0.0f; *pPos++ =  0.0f;
    *pPos++ = -1.0f; *pPos++ =  0.0f; *pPos++ =  1.0f;

    *pPos++ = -1.0f; *pPos++ =  0.0f; *pPos++ =  0.0f;
    *pPos++ = -0.9f; *pPos++ =  0.5f; *pPos++ =  0.0f;
    *pPos++ = -0.9f; *pPos++ =  0.5f; *pPos++ =  0.0f;
    *pPos++ = -0.9f; *pPos++ =  0.5f; *pPos++ =  1.0f;
    *pPos++ = -0.9f; *pPos++ =  0.5f; *pPos++ =  1.0f;
    *pPos++ = -1.0f; *pPos++ =  0.0f; *pPos++ =  1.0f;

    *pPos++ = -0.9f; *pPos++ =  0.5f; *pPos++ =  0.0f;
    *pPos++ = -0.5f; *pPos++ =  0.9f; *pPos++ =  0.0f;
    *pPos++ = -0.5f; *pPos++ =  0.9f; *pPos++ =  0.0f;
    *pPos++ = -0.5f; *pPos++ =  0.9f; *pPos++ =  1.0f;
    *pPos++ = -0.5f; *pPos++ =  0.9f; *pPos++ =  1.0f;
    *pPos++ = -0.9f;  *pPos++ =  0.5f;*pPos++ =  1.0f;

    *pPos++ = -0.5f; *pPos++ =  0.9f; *pPos++ =  0.0f;
    *pPos++ =  0.0f; *pPos++ =  1.0f; *pPos++ =  0.0f;
    *pPos++ =  0.0f; *pPos++ =  1.0f; *pPos++ =  0.0f;
    *pPos++ =  0.0f; *pPos++ =  1.0f; *pPos++ =  1.0f;
    *pPos++ =  0.0f; *pPos++ =  1.0f; *pPos++ =  1.0f;
    *pPos++ = -0.5f; *pPos++ =  0.9f; *pPos++ =  1.0f;

    *pPos++ =  0.0f; *pPos++ =  1.0f; *pPos++ =  0.0f;
    *pPos++ =  0.5f; *pPos++ =  0.9f; *pPos++ =  0.0f;
    *pPos++ =  0.5f; *pPos++ =  0.9f; *pPos++ =  0.0f;
    *pPos++ =  0.5f; *pPos++ =  0.9f; *pPos++ =  1.0f;
    *pPos++ =  0.5f; *pPos++ =  0.9f; *pPos++ =  1.0f;
    *pPos++ =  0.0f; *pPos++ =  1.0f; *pPos++ =  1.0f;

    *pPos++ =  0.5f; *pPos++ =  0.9f; *pPos++ =  0.0f;
    *pPos++ =  0.9f; *pPos++ =  0.5f; *pPos++ =  0.0f;
    *pPos++ =  0.9f; *pPos++ =  0.5f; *pPos++ =  0.0f;
    *pPos++ =  0.9f; *pPos++ =  0.5f; *pPos++ =  1.0f;
    *pPos++ =  0.9f; *pPos++ =  0.5f; *pPos++ =  1.0f;
    *pPos++ =  0.5f; *pPos++ =  0.9f; *pPos++ =  1.0f;

    *pPos++ =  0.9f; *pPos++ =  0.5f; *pPos++ =  0.0f;
    *pPos++ =  1.0f; *pPos++ =  0.0f; *pPos++ =  0.0f;
    *pPos++ =  1.0f; *pPos++ =  0.0f; *pPos++ =  0.0f;
    *pPos++ =  1.0f; *pPos++ =  0.0f; *pPos++ =  1.0f;
    *pPos++ =  1.0f; *pPos++ =  0.0f; *pPos++ =  1.0f;
    *pPos++ =  0.9f; *pPos++ =  0.5f; *pPos++ =  1.0f;

    *pPos++ = -1.0f; *pPos++ =  0.0f; *pPos++ =  0.0f;
    *pPos++ = -0.9f; *pPos++ = -0.5f; *pPos++ =  0.0f;
    *pPos++ = -0.9f; *pPos++ = -0.5f; *pPos++ =  0.0f;
    *pPos++ = -0.9f; *pPos++ = -0.5f; *pPos++ =  1.0f;
    *pPos++ = -0.9f; *pPos++ = -0.5f; *pPos++ =  1.0f;
    *pPos++ = -1.0f; *pPos++ =  0.0f; *pPos++ =  1.0f;

    *pPos++ = -0.9f; *pPos++ = -0.5f; *pPos++ =  0.0f;
    *pPos++ = -0.5f; *pPos++ = -0.9f; *pPos++ =  0.0f;
    *pPos++ = -0.5f; *pPos++ = -0.9f; *pPos++ =  0.0f;
    *pPos++ = -0.5f; *pPos++ = -0.9f; *pPos++ =  1.0f;
    *pPos++ = -0.5f; *pPos++ = -0.9f; *pPos++ =  1.0f;
    *pPos++ = -0.9f; *pPos++ = -0.5f; *pPos++ =  1.0f;

    *pPos++ = -0.5f; *pPos++ = -0.9f; *pPos++ =  0.0f;
    *pPos++ =  0.0f; *pPos++ = -1.0f; *pPos++ =  0.0f;
    *pPos++ =  0.0f; *pPos++ = -1.0f; *pPos++ =  0.0f;
    *pPos++ =  0.0f; *pPos++ = -1.0f; *pPos++ =  1.0f;
    *pPos++ =  0.0f; *pPos++ = -1.0f; *pPos++ =  1.0f;
    *pPos++ = -0.5f; *pPos++ = -0.9f; *pPos++ =  1.0f;

    *pPos++ =  0.0f; *pPos++ = -1.0f; *pPos++ =  0.0f;
    *pPos++ =  0.5f; *pPos++ = -0.9f; *pPos++ =  0.0f;
    *pPos++ =  0.5f; *pPos++ = -0.9f; *pPos++ =  0.0f;
    *pPos++ =  0.5f; *pPos++ = -0.9f; *pPos++ =  1.0f;
    *pPos++ =  0.5f; *pPos++ = -0.9f; *pPos++ =  1.0f;
    *pPos++ =  0.0f; *pPos++ = -1.0f; *pPos++ =  1.0f;

    *pPos++ =  0.5f; *pPos++ = -0.9f; *pPos++ =  0.0f;
    *pPos++ =  0.9f; *pPos++ = -0.5f; *pPos++ =  0.0f;
    *pPos++ =  0.9f; *pPos++ = -0.5f; *pPos++ =  0.0f;
    *pPos++ =  0.9f; *pPos++ = -0.5f; *pPos++ =  1.0f;
    *pPos++ =  0.9f; *pPos++ = -0.5f; *pPos++ =  1.0f;
    *pPos++ =  0.5f; *pPos++ = -0.9f; *pPos++ =  1.0f;

    *pPos++ =  0.9f; *pPos++ = -0.5f; *pPos++ =  0.0f;
    *pPos++ =  1.0f; *pPos++ =  0.0f; *pPos++ =  0.0f;
    *pPos++ =  1.0f; *pPos++ =  0.0f; *pPos++ =  0.0f;
    *pPos++ =  1.0f; *pPos++ =  0.0f; *pPos++ =  1.0f;
    *pPos++ =  1.0f; *pPos++ =  0.0f; *pPos++ =  1.0f;
    *pPos++ =  0.9f; *pPos++ = -0.5f; *pPos++ =  1.0f;

    vbuf0->unlock();

    Ogre::AxisAlignedBox aabb;
    aabb.setInfinite();
    setBoundingBox( aabb );
}



EntityCollision::~EntityCollision()
{
    delete mRenderOp.vertexData;
}



Ogre::Real
EntityCollision::getSquaredViewDepth( const Ogre::Camera* cam ) const
{
}



Ogre::Real
EntityCollision::getBoundingRadius() const
{
}
