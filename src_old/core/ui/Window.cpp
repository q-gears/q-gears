#include "Window.h"

#include <Ogre.h>



Ogre::String Window::msTypeName = "Window";

#define POSITION_BINDING 0
#define COLOUR_BINDING 1
#define TEXTURE_BINDING 2



Window::Window(const Ogre::String& name):
    Ogre::OverlayContainer(name),

    m_BorderWidth(8),
    m_BackgroundPadding(3),

    m_Transparent(false),

    m_TopLeft(0, 0, 176.0f/256.0f),
    m_TopRight(0, 0, 128.0f/256.0f),
    m_BottomLeft(0, 0, 80.0f/256.0f),
    m_BottomRight(0, 0, 32.0f/256.0f),

    m_BackgroundU1(0),
    m_BackgroundV1(0),
    m_BackgroundU2(1),
    m_BackgroundV2(1),

    m_BackgroundTrU1(0),
    m_BackgroundTrV1(0),
    m_BackgroundTrU2(1),
    m_BackgroundTrV2(1),

    m_TopLeftU1(0),
    m_TopLeftU2(0),
    m_TopLeftV1(1),
    m_TopLeftV2(1),

    m_TopU1(0),
    m_TopU2(0),
    m_TopV1(1),
    m_TopV2(1),

    m_TopRightU1(0),
    m_TopRightU2(0),
    m_TopRightV1(1),
    m_TopRightV2(1),

    m_LeftU1(0),
    m_LeftU2(0),
    m_LeftV1(1),
    m_LeftV2(1),

    m_RightU1(0),
    m_RightU2(0),
    m_RightV1(1),
    m_RightV2(1),

    m_BottomLeftU1(0),
    m_BottomLeftU2(0),
    m_BottomLeftV1(1),
    m_BottomLeftV2(1),

    m_BottomU1(0),
    m_BottomU2(0),
    m_BottomV1(1),
    m_BottomV2(1),

    m_BottomRightU1(0),
    m_BottomRightU2(0),
    m_BottomRightV1(1),
    m_BottomRightV2(1)
{
}



Window::~Window()
{
    delete mRenderOp.vertexData;
}



void
Window::initialise(void)
{
    if (!mInitialised)
    {
        // Setup render op in advance
        mRenderOp.vertexData = new Ogre::VertexData();
        mRenderOp.vertexData->vertexStart = 0;
        mRenderOp.vertexData->vertexCount = 54;
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



void
Window::SetTransparent(const bool transparent)
{
    m_Transparent = transparent;
    mGeomUVsOutOfDate = true;
}



const Ogre::String&
Window::getTypeName(void) const
{
    return msTypeName;
}



void
Window::getRenderOperation(Ogre::RenderOperation& op)
{
    op = mRenderOp;
}



void
Window::setMaterialName(const Ogre::String& matName)
{
    OverlayElement::setMaterialName(matName);
}



void
Window::_updateRenderQueue(Ogre::RenderQueue* queue)
{
    if (mVisible && !mpMaterial.isNull())
    {
        OverlayElement::_updateRenderQueue(queue);
    }
}



void
Window::SetBackgroundColour(const Ogre::ColourValue& tl, const Ogre::ColourValue& tr, const Ogre::ColourValue& bl, const Ogre::ColourValue& br)
{
    m_TopLeft = tl;
    m_TopRight = tr;
    m_BottomLeft = bl;
    m_BottomRight = br;

    this->updateColours();
}



void
Window::SetBackgroundUV(const float u1, const float v1, const float u2, const float v2)
{
    m_BackgroundU1 = u1;
    m_BackgroundU2 = u2;
    m_BackgroundV1 = v1;
    m_BackgroundV2 = v2;
    mGeomUVsOutOfDate = true;
}



void
Window::SetBackgroundTransparentUV(const float u1, const float v1, const float u2, const float v2)
{
    m_BackgroundTrU1 = u1;
    m_BackgroundTrU2 = u2;
    m_BackgroundTrV1 = v1;
    m_BackgroundTrV2 = v2;
    mGeomUVsOutOfDate = true;
}



void
Window::SetTopLeftUV(const float u1, const float v1, const float u2, const float v2)
{
    m_TopLeftU1 = u1;
    m_TopLeftU2 = u2;
    m_TopLeftV1 = v1;
    m_TopLeftV2 = v2;
    mGeomUVsOutOfDate = true;
}



void
Window::SetTopUV(const float u1, const float v1, const float u2, const float v2)
{
    m_TopU1 = u1;
    m_TopU2 = u2;
    m_TopV1 = v1;
    m_TopV2 = v2;
    mGeomUVsOutOfDate = true;
}



void
Window::SetTopRightUV(const float u1, const float v1, const float u2, const float v2)
{
    m_TopRightU1 = u1;
    m_TopRightU2 = u2;
    m_TopRightV1 = v1;
    m_TopRightV2 = v2;
    mGeomUVsOutOfDate = true;
}



void
Window::SetLeftUV(const float u1, const float v1, const float u2, const float v2)
{
    m_LeftU1 = u1;
    m_LeftU2 = u2;
    m_LeftV1 = v1;
    m_LeftV2 = v2;
    mGeomUVsOutOfDate = true;
}



void
Window::SetRightUV(const float u1, const float v1, const float u2, const float v2)
{
    m_RightU1 = u1;
    m_RightU2 = u2;
    m_RightV1 = v1;
    m_RightV2 = v2;
    mGeomUVsOutOfDate = true;
}



void
Window::SetBottomLeftUV(const float u1, const float v1, const float u2, const float v2)
{
    m_BottomLeftU1 = u1;
    m_BottomLeftU2 = u2;
    m_BottomLeftV1 = v1;
    m_BottomLeftV2 = v2;
    mGeomUVsOutOfDate = true;
}



void
Window::SetBottomUV(const float u1, const float v1, const float u2, const float v2)
{
    m_BottomU1 = u1;
    m_BottomU2 = u2;
    m_BottomV1 = v1;
    m_BottomV2 = v2;
    mGeomUVsOutOfDate = true;
}



void
Window::SetBottomRightUV(const float u1, const float v1, const float u2, const float v2)
{
    m_BottomRightU1 = u1;
    m_BottomRightU2 = u2;
    m_BottomRightV1 = v1;
    m_BottomRightV2 = v2;
    mGeomUVsOutOfDate = true;
}



void
Window::updatePositionGeometry(void)
{
    if (mInitialised == true)
    {
        //0---1/3
        //|    /|
        //|  /  |
        //|/    |
        //2/5---4

        //+-+-+-+
        //|1 2 3|
        //|4 0 5|
        //|6 7 8|
        //+-+-+-+

        Ogre::HardwareVertexBufferSharedPtr vbuf = mRenderOp.vertexData->vertexBufferBinding->getBuffer(POSITION_BINDING);
        float* pPos = static_cast<float*>(vbuf->lock(Ogre::HardwareBuffer::HBL_DISCARD));

        int width = Ogre::OverlayManager::getSingleton().getViewportWidth() / 2;
        int height = Ogre::OverlayManager::getSingleton().getViewportHeight() / 2;

        float left;
        float right;
        float top;
        float bottom;

        // center
        top    = -(mPixelTop + m_BackgroundPadding - height) / height;
        right  =  (mPixelLeft + mPixelWidth - m_BackgroundPadding - width) / width;
        left   =  (mPixelLeft + m_BackgroundPadding - width) / width;
        bottom = -(mPixelTop + mPixelHeight - m_BackgroundPadding - height) / height;
        *pPos++ = left;  *pPos++ = top;    *pPos++ = -1.0f;
        *pPos++ = right; *pPos++ = top;    *pPos++ = -1.0f;
        *pPos++ = left;  *pPos++ = bottom; *pPos++ = -1.0f;
        *pPos++ = right; *pPos++ = top;    *pPos++ = -1.0f;
        *pPos++ = right; *pPos++ = bottom; *pPos++ = -1.0f;
        *pPos++ = left;  *pPos++ = bottom; *pPos++ = -1.0f;

        // top left
        top    = -(mPixelTop - height) / height;
        right  =  (mPixelLeft + m_BorderWidth - width) / width;
        left   =  (mPixelLeft - width) / width;
        bottom = -(mPixelTop + m_BorderWidth - height) / height;
        *pPos++ = left;  *pPos++ = top;    *pPos++ = 0;
        *pPos++ = right; *pPos++ = top;    *pPos++ = 0;
        *pPos++ = left;  *pPos++ = bottom; *pPos++ = 0;
        *pPos++ = right; *pPos++ = top;    *pPos++ = 0;
        *pPos++ = right; *pPos++ = bottom; *pPos++ = 0;
        *pPos++ = left;  *pPos++ = bottom; *pPos++ = 0;

        // top
        top    = -(mPixelTop - height) / height;
        right  =  (mPixelLeft + mPixelWidth - m_BorderWidth - width) / width;
        left   =  (mPixelLeft + m_BorderWidth - width) / width;
        bottom = -(mPixelTop + m_BorderWidth - height) / height;
        *pPos++ = left;  *pPos++ = top;    *pPos++ = 0;
        *pPos++ = right; *pPos++ = top;    *pPos++ = 0;
        *pPos++ = left;  *pPos++ = bottom; *pPos++ = 0;
        *pPos++ = right; *pPos++ = top;    *pPos++ = 0;
        *pPos++ = right; *pPos++ = bottom; *pPos++ = 0;
        *pPos++ = left;  *pPos++ = bottom; *pPos++ = 0;

        // top right
        top    = -(mPixelTop - height) / height;
        right  =  (mPixelLeft + mPixelWidth - width) / width;
        left   =  (mPixelLeft + mPixelWidth - m_BorderWidth - width) / width;
        bottom = -(mPixelTop + m_BorderWidth - height) / height;
        *pPos++ = left;  *pPos++ = top;    *pPos++ = 0;
        *pPos++ = right; *pPos++ = top;    *pPos++ = 0;
        *pPos++ = left;  *pPos++ = bottom; *pPos++ = 0;
        *pPos++ = right; *pPos++ = top;    *pPos++ = 0;
        *pPos++ = right; *pPos++ = bottom; *pPos++ = 0;
        *pPos++ = left;  *pPos++ = bottom; *pPos++ = 0;

        // left
        top    = -(mPixelTop + m_BorderWidth - height) / height;
        right  =  (mPixelLeft + m_BorderWidth - width) / width;
        left   =  (mPixelLeft - width) / width;
        bottom = -(mPixelTop + mPixelHeight - m_BorderWidth - height) / height;
        *pPos++ = left;  *pPos++ = top;    *pPos++ = 0;
        *pPos++ = right; *pPos++ = top;    *pPos++ = 0;
        *pPos++ = left;  *pPos++ = bottom; *pPos++ = 0;
        *pPos++ = right; *pPos++ = top;    *pPos++ = 0;
        *pPos++ = right; *pPos++ = bottom; *pPos++ = 0;
        *pPos++ = left;  *pPos++ = bottom; *pPos++ = 0;

        // right
        top    = -(mPixelTop + m_BorderWidth - height) / height;
        right  =  (mPixelLeft + mPixelWidth - width) / width;
        left   =  (mPixelLeft + mPixelWidth - m_BorderWidth - width) / width;
        bottom = -(mPixelTop + mPixelHeight - m_BorderWidth - height) / height;
        *pPos++ = left;  *pPos++ = top;    *pPos++ = 0;
        *pPos++ = right; *pPos++ = top;    *pPos++ = 0;
        *pPos++ = left;  *pPos++ = bottom; *pPos++ = 0;
        *pPos++ = right; *pPos++ = top;    *pPos++ = 0;
        *pPos++ = right; *pPos++ = bottom; *pPos++ = 0;
        *pPos++ = left;  *pPos++ = bottom; *pPos++ = 0;

        // bottom left
        top    = -(mPixelTop + mPixelHeight - m_BorderWidth - height) / height;
        right  =  (mPixelLeft + m_BorderWidth - width) / width;
        left   =  (mPixelLeft - width) / width;
        bottom = -(mPixelTop + mPixelHeight - height) / height;
        *pPos++ = left;  *pPos++ = top;    *pPos++ = 0;
        *pPos++ = right; *pPos++ = top;    *pPos++ = 0;
        *pPos++ = left;  *pPos++ = bottom; *pPos++ = 0;
        *pPos++ = right; *pPos++ = top;    *pPos++ = 0;
        *pPos++ = right; *pPos++ = bottom; *pPos++ = 0;
        *pPos++ = left;  *pPos++ = bottom; *pPos++ = 0;

        // bottom
        top    = -(mPixelTop + mPixelHeight - m_BorderWidth - height) / height;
        right  =  (mPixelLeft + mPixelWidth - m_BorderWidth - width) / width;
        left   =  (mPixelLeft + m_BorderWidth - width) / width;
        bottom = -(mPixelTop + mPixelHeight - height) / height;
        *pPos++ = left;  *pPos++ = top;    *pPos++ = 0;
        *pPos++ = right; *pPos++ = top;    *pPos++ = 0;
        *pPos++ = left;  *pPos++ = bottom; *pPos++ = 0;
        *pPos++ = right; *pPos++ = top;    *pPos++ = 0;
        *pPos++ = right; *pPos++ = bottom; *pPos++ = 0;
        *pPos++ = left;  *pPos++ = bottom; *pPos++ = 0;

        // bottom right
        top    = -(mPixelTop + mPixelHeight - m_BorderWidth - height) / height;
        right  =  (mPixelLeft + mPixelWidth - width) / width;
        left   =  (mPixelLeft + mPixelWidth - m_BorderWidth - width) / width;
        bottom = -(mPixelTop + mPixelHeight - height) / height;
        *pPos++ = left;  *pPos++ = top;    *pPos++ = 0;
        *pPos++ = right; *pPos++ = top;    *pPos++ = 0;
        *pPos++ = left;  *pPos++ = bottom; *pPos++ = 0;
        *pPos++ = right; *pPos++ = top;    *pPos++ = 0;
        *pPos++ = right; *pPos++ = bottom; *pPos++ = 0;
        *pPos++ = left;  *pPos++ = bottom; *pPos++ = 0;

        vbuf->unlock();
    }
}



void
Window::updateTextureGeometry(void)
{
    // Generate for as many texture layers as there are in material
    if (!mpMaterial.isNull() && mInitialised == true)
    {
        Ogre::HardwareVertexBufferSharedPtr vbuf = mRenderOp.vertexData->vertexBufferBinding->getBuffer(TEXTURE_BINDING);
        float* pVBStart = static_cast<float*>(vbuf->lock(Ogre::HardwareBuffer::HBL_DISCARD));

        /*
        0---2/3
        |    /|
        |  /  |
        |/    |
        1/5---4
        */
        // Find start offset for this set
        float* pTex = pVBStart;

        // center
        if (m_Transparent == false)
        {
            pTex[ 0] = m_BackgroundU1; pTex[ 1] = m_BackgroundV1;
            pTex[ 2] = m_BackgroundU2; pTex[ 3] = m_BackgroundV1;
            pTex[ 4] = m_BackgroundU1; pTex[ 5] = m_BackgroundV2;
            pTex[ 6] = m_BackgroundU2; pTex[ 7] = m_BackgroundV1;
            pTex[ 8] = m_BackgroundU2; pTex[ 9] = m_BackgroundV2;
            pTex[10] = m_BackgroundU1; pTex[11] = m_BackgroundV2;
        }
        else
        {
            pTex[ 0] = m_BackgroundTrU1; pTex[ 1] = m_BackgroundTrV1;
            pTex[ 2] = m_BackgroundTrU2; pTex[ 3] = m_BackgroundTrV1;
            pTex[ 4] = m_BackgroundTrU1; pTex[ 5] = m_BackgroundTrV2;
            pTex[ 6] = m_BackgroundTrU2; pTex[ 7] = m_BackgroundTrV1;
            pTex[ 8] = m_BackgroundTrU2; pTex[ 9] = m_BackgroundTrV2;
            pTex[10] = m_BackgroundTrU1; pTex[11] = m_BackgroundTrV2;
        }

        // top left
        pTex[12] = m_TopLeftU1; pTex[13] = m_TopLeftV1;
        pTex[14] = m_TopLeftU2; pTex[15] = m_TopLeftV1;
        pTex[16] = m_TopLeftU1; pTex[17] = m_TopLeftV2;
        pTex[18] = m_TopLeftU2; pTex[19] = m_TopLeftV1;
        pTex[20] = m_TopLeftU2; pTex[21] = m_TopLeftV2;
        pTex[22] = m_TopLeftU1; pTex[23] = m_TopLeftV2;

        // top
        pTex[24] = m_TopU1; pTex[25] = m_TopV1;
        pTex[26] = m_TopU2; pTex[27] = m_TopV1;
        pTex[28] = m_TopU1; pTex[29] = m_TopV2;
        pTex[30] = m_TopU2; pTex[31] = m_TopV1;
        pTex[32] = m_TopU2; pTex[33] = m_TopV2;
        pTex[34] = m_TopU1; pTex[35] = m_TopV2;

        // top right
        pTex[36] = m_TopRightU1; pTex[37] = m_TopRightV1;
        pTex[38] = m_TopRightU2; pTex[39] = m_TopRightV1;
        pTex[40] = m_TopRightU1; pTex[41] = m_TopRightV2;
        pTex[42] = m_TopRightU2; pTex[43] = m_TopRightV1;
        pTex[44] = m_TopRightU2; pTex[45] = m_TopRightV2;
        pTex[46] = m_TopRightU1; pTex[47] = m_TopRightV2;

        // left
        pTex[48] = m_LeftU1; pTex[49] = m_LeftV1;
        pTex[50] = m_LeftU2; pTex[51] = m_LeftV1;
        pTex[52] = m_LeftU1; pTex[53] = m_LeftV2;
        pTex[54] = m_LeftU2; pTex[55] = m_LeftV1;
        pTex[56] = m_LeftU2; pTex[57] = m_LeftV2;
        pTex[58] = m_LeftU1; pTex[59] = m_LeftV2;

        // right
        pTex[60] = m_RightU1; pTex[61] = m_RightV1;
        pTex[62] = m_RightU2; pTex[63] = m_RightV1;
        pTex[64] = m_RightU1; pTex[65] = m_RightV2;
        pTex[66] = m_RightU2; pTex[67] = m_RightV1;
        pTex[68] = m_RightU2; pTex[69] = m_RightV2;
        pTex[70] = m_RightU1; pTex[71] = m_RightV2;

        // bottom left
        pTex[72] = m_BottomLeftU1; pTex[73] = m_BottomLeftV1;
        pTex[74] = m_BottomLeftU2; pTex[75] = m_BottomLeftV1;
        pTex[76] = m_BottomLeftU1; pTex[77] = m_BottomLeftV2;
        pTex[78] = m_BottomLeftU2; pTex[79] = m_BottomLeftV1;
        pTex[80] = m_BottomLeftU2; pTex[81] = m_BottomLeftV2;
        pTex[82] = m_BottomLeftU1; pTex[83] = m_BottomLeftV2;

        // bottom
        pTex[84] = m_BottomU1; pTex[85] = m_BottomV1;
        pTex[86] = m_BottomU2; pTex[87] = m_BottomV1;
        pTex[88] = m_BottomU1; pTex[89] = m_BottomV2;
        pTex[90] = m_BottomU2; pTex[91] = m_BottomV1;
        pTex[92] = m_BottomU2; pTex[93] = m_BottomV2;
        pTex[94] = m_BottomU1; pTex[95] = m_BottomV2;

        // bottom right
        pTex[96] = m_BottomRightU1; pTex[97] = m_BottomRightV1;
        pTex[98] = m_BottomRightU2; pTex[99] = m_BottomRightV1;
        pTex[100] = m_BottomRightU1; pTex[101] = m_BottomRightV2;
        pTex[102] = m_BottomRightU2; pTex[103] = m_BottomRightV1;
        pTex[104] = m_BottomRightU2; pTex[105] = m_BottomRightV2;
        pTex[106] = m_BottomRightU1; pTex[107] = m_BottomRightV2;

        vbuf->unlock();
    }
}



void
Window::updateColours(void)
{
    if (mInitialised == true)
    {
        /*
        0---1/3
        |    /|
        |  /  |
        |/    |
        2/5---4
        */

        Ogre::HardwareVertexBufferSharedPtr vbuf = mRenderOp.vertexData->vertexBufferBinding->getBuffer(COLOUR_BINDING);
        Ogre::RenderSystem* rs = Ogre::Root::getSingleton().getRenderSystem();
        Ogre::RGBA colours[mRenderOp.vertexData->vertexCount];

        // only center needs cpecific colours
        rs->convertColourValue(m_TopRight, colours + 1);
        rs->convertColourValue(m_TopLeft, colours + 0);
        rs->convertColourValue(m_BottomLeft, colours + 2);
        rs->convertColourValue(m_TopRight, colours + 3);
        rs->convertColourValue(m_BottomRight, colours + 4);
        rs->convertColourValue(m_BottomLeft, colours + 5);

        for (int i = 6; i < mRenderOp.vertexData->vertexCount; ++i)
        {
            rs->convertColourValue(Ogre::ColourValue::White, colours + i);
        }

        vbuf->writeData(0, vbuf->getSizeInBytes(), colours, true);
    }
}
