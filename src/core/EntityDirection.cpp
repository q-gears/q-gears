#include "EntityDirection.h"

#include <OgreHardwareBufferManager.h>



EntityDirection::EntityDirection()
{
    mRenderOp.vertexData = new Ogre::VertexData();

    mRenderOp.indexData = 0;
    mRenderOp.vertexData->vertexCount = 2;
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

    *pPos++ = 0.0f; *pPos++ = 0.0f; *pPos++ = 0.0f;
    *pPos++ = 0.0f; *pPos++ = -1.0f; *pPos++ = 0.0f;

    vbuf0->unlock();

    Ogre::AxisAlignedBox aabb;
    aabb.setInfinite();
    setBoundingBox( aabb );
}



EntityDirection::~EntityDirection()
{
    delete mRenderOp.vertexData;
}



Ogre::Real
EntityDirection::getSquaredViewDepth( const Ogre::Camera* cam ) const
{
}



Ogre::Real
EntityDirection::getBoundingRadius() const
{
}
