#include "Fade.h"

#include <OgreHardwareBufferManager.h>
#include <OgreRenderSystem.h>
#include <OgreRoot.h>


Ogre::String Fade::msTypeName = "Fade";

#define POSITION_BINDING 0
#define COLOUR_BINDING 1
#define TEXTURE_BINDING 2



Fade::Fade(const Ogre::String& name):
    Ogre::OverlayContainer(name),

    m_BackgroundU1(0),
    m_BackgroundV1(0),
    m_BackgroundU2(1),
    m_BackgroundV2(1)
{
}



Fade::~Fade()
{
    delete mRenderOp.vertexData;
}



void
Fade::initialise(void)
{
    if (!mInitialised)
    {
        // Setup render op in advance
        mRenderOp.vertexData = new Ogre::VertexData();
        mRenderOp.vertexData->vertexStart = 0;
        mRenderOp.vertexData->vertexCount = 6;
        mRenderOp.useIndexes = false;
        mRenderOp.operationType = Ogre::RenderOperation::OT_TRIANGLE_LIST;

        // Create as separate buffers so we can lock & discard separately
        Ogre::VertexDeclaration* decl = mRenderOp.vertexData->vertexDeclaration;
        decl->addElement(POSITION_BINDING, 0, Ogre::VET_FLOAT3, Ogre::VES_POSITION);
        decl->addElement(COLOUR_BINDING, 0, Ogre::VET_COLOUR, Ogre::VES_DIFFUSE);
        decl->addElement(TEXTURE_BINDING, 0, Ogre::VET_FLOAT2, Ogre::VES_TEXTURE_COORDINATES, 0);

        // Vertex buffer
        Ogre::HardwareVertexBufferSharedPtr vbuf0 = Ogre::HardwareBufferManager::getSingleton().createVertexBuffer(
            decl->getVertexSize(POSITION_BINDING),
            mRenderOp.vertexData->vertexCount,
            Ogre::HardwareBuffer::HBU_STATIC_WRITE_ONLY);

        // Colour buffer
        Ogre::HardwareVertexBufferSharedPtr vbuf1 = Ogre::HardwareBufferManager::getSingleton().createVertexBuffer(
            decl->getVertexSize(COLOUR_BINDING),
            mRenderOp.vertexData->vertexCount,
            Ogre::HardwareBuffer::HBU_STATIC_WRITE_ONLY);

        // Texture buffer
        Ogre::HardwareVertexBufferSharedPtr vbuf2 = Ogre::HardwareBufferManager::getSingleton().createVertexBuffer(
            decl->getVertexSize(TEXTURE_BINDING),
            mRenderOp.vertexData->vertexCount,
            Ogre::HardwareBuffer::HBU_STATIC_WRITE_ONLY);

        // Bind buffer
        mRenderOp.vertexData->vertexBufferBinding->setBinding(POSITION_BINDING, vbuf0);
        mRenderOp.vertexData->vertexBufferBinding->setBinding(COLOUR_BINDING, vbuf1);
        mRenderOp.vertexData->vertexBufferBinding->setBinding(TEXTURE_BINDING, vbuf2);

        mInitialised = true;

        this->updateColours();
    }
}



const Ogre::String&
Fade::getTypeName(void) const
{
    return msTypeName;
}



void
Fade::getRenderOperation(Ogre::RenderOperation& op)
{
    op = mRenderOp;
}



void
Fade::setMaterialName(const Ogre::String& matName)
{
    OverlayElement::setMaterialName(matName);
}



void
Fade::_updateRenderQueue(Ogre::RenderQueue* queue)
{
    if (mVisible && !mpMaterial.isNull())
    {
        OverlayElement::_updateRenderQueue(queue);
    }
}



void
Fade::SetColour(const Ogre::ColourValue& colour)
{
    m_Colour = colour;

    this->updateColours();
}



void
Fade::SetBackgroundUV(const float u1, const float v1, const float u2, const float v2)
{
    m_BackgroundU1 = u1;
    m_BackgroundU2 = u2;
    m_BackgroundV1 = v1;
    m_BackgroundV2 = v2;
    mGeomUVsOutOfDate = true;
}



void
Fade::updatePositionGeometry(void)
{
    if (mInitialised == true)
    {
        Ogre::HardwareVertexBufferSharedPtr vbuf = mRenderOp.vertexData->vertexBufferBinding->getBuffer(POSITION_BINDING);
        float* pPos = static_cast<float*>(vbuf->lock(Ogre::HardwareBuffer::HBL_DISCARD));

        float left = -1;
        float right = 1;
        float top = -1;
        float bottom = 1;

        // center
        *pPos++ = left;  *pPos++ = top;    *pPos++ = 0.0f;
        *pPos++ = right; *pPos++ = top;    *pPos++ = 0.0f;
        *pPos++ = left;  *pPos++ = bottom; *pPos++ = 0.0f;
        *pPos++ = right; *pPos++ = top;    *pPos++ = 0.0f;
        *pPos++ = right; *pPos++ = bottom; *pPos++ = 0.0f;
        *pPos++ = left;  *pPos++ = bottom; *pPos++ = 0.0f;

        vbuf->unlock();
    }
}



void
Fade::updateTextureGeometry(void)
{
    // Generate for as many texture layers as there are in material
    if (!mpMaterial.isNull() && mInitialised == true)
    {
        Ogre::HardwareVertexBufferSharedPtr vbuf = mRenderOp.vertexData->vertexBufferBinding->getBuffer(TEXTURE_BINDING);
        float* pVBStart = static_cast<float*>(vbuf->lock(Ogre::HardwareBuffer::HBL_DISCARD));

        // Find start offset for this set
        float* pTex = pVBStart;

        pTex[ 0] = m_BackgroundU1; pTex[ 1] = m_BackgroundV1;
        pTex[ 2] = m_BackgroundU2; pTex[ 3] = m_BackgroundV1;
        pTex[ 4] = m_BackgroundU1; pTex[ 5] = m_BackgroundV2;
        pTex[ 6] = m_BackgroundU2; pTex[ 7] = m_BackgroundV1;
        pTex[ 8] = m_BackgroundU2; pTex[ 9] = m_BackgroundV2;
        pTex[10] = m_BackgroundU1; pTex[11] = m_BackgroundV2;

        vbuf->unlock();
    }
}



void
Fade::updateColours(void)
{
    if (mInitialised == true)
    {
        Ogre::HardwareVertexBufferSharedPtr vbuf = mRenderOp.vertexData->vertexBufferBinding->getBuffer(COLOUR_BINDING);
        Ogre::RenderSystem* rs = Ogre::Root::getSingleton().getRenderSystem();
        Ogre::RGBA colours[mRenderOp.vertexData->vertexCount];

        // only center needs cpecific colours
        rs->convertColourValue(m_Colour, colours + 1);
        rs->convertColourValue(m_Colour, colours + 0);
        rs->convertColourValue(m_Colour, colours + 2);
        rs->convertColourValue(m_Colour, colours + 3);
        rs->convertColourValue(m_Colour, colours + 4);
        rs->convertColourValue(m_Colour, colours + 5);

        vbuf->writeData(0, vbuf->getSizeInBytes(), colours, true);
    }
}
