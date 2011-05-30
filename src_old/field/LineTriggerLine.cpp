// $Id$

#include <Ogre.h>

#include "LineTriggerLine.h"

#define POSITION_BINDING 0
#define COLOUR_BINDING 1



LineTriggerLine::LineTriggerLine(const Ogre::Vector3& point1, const Ogre::Vector3& point2)
{
    mRenderOp.vertexData = new Ogre::VertexData();



    mRenderOp.indexData = 0;
    mRenderOp.vertexData->vertexCount = 2;
    mRenderOp.vertexData->vertexStart = 0;
    mRenderOp.operationType = Ogre::RenderOperation::OT_LINE_LIST;
    mRenderOp.useIndexes = false;

    Ogre::VertexDeclaration* decl = mRenderOp.vertexData->vertexDeclaration;
    Ogre::VertexBufferBinding* bind = mRenderOp.vertexData->vertexBufferBinding;

    // 1st buffer
    decl->addElement(POSITION_BINDING, 0, Ogre::VET_FLOAT3, Ogre::VES_POSITION);
    Ogre::HardwareVertexBufferSharedPtr vbuf0 = Ogre::HardwareBufferManager::getSingleton().createVertexBuffer(
            decl->getVertexSize(0),
            mRenderOp.vertexData->vertexCount,
            Ogre::HardwareBuffer::HBU_STATIC_WRITE_ONLY);
    bind->setBinding(POSITION_BINDING, vbuf0);

    float* pPos = static_cast<float*>(vbuf0->lock(Ogre::HardwareBuffer::HBL_DISCARD));

    *pPos++ = point1.x; *pPos++ = point1.y; *pPos++ = point1.z;
    *pPos++ = point2.x; *pPos++ = point2.y; *pPos++ = point2.z;

    vbuf0->unlock();

    // setup the bounding box of this SimpleRenderable
    Ogre::AxisAlignedBox aabb;
    aabb.setInfinite();
    setBoundingBox(aabb);
}



LineTriggerLine::~LineTriggerLine(void)
{
    delete mRenderOp.vertexData;
}



void
LineTriggerLine::SetPoints(const Ogre::Vector3& point1, const Ogre::Vector3& point2)
{
    Ogre::HardwareVertexBufferSharedPtr vbuf = mRenderOp.vertexData->vertexBufferBinding->getBuffer(POSITION_BINDING);
    float* pPos = static_cast<float*>(vbuf->lock(Ogre::HardwareBuffer::HBL_NORMAL));

    *pPos++ = point1.x; *pPos++ = point1.y; *pPos++ = point1.z;
    *pPos++ = point2.x; *pPos++ = point2.y; *pPos++ = point2.z;

    vbuf->unlock();
}



Ogre::Real
LineTriggerLine::getSquaredViewDepth(const Ogre::Camera* cam) const
{
}



Ogre::Real
LineTriggerLine::getBoundingRadius(void) const
{
}
