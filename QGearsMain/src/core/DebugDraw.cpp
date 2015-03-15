#include "core/DebugDraw.h"
#include <OgreFontManager.h>
#include <OgreHardwareBufferManager.h>
#include <OgreMaterialManager.h>

#include "core/CameraManager.h"
#include "core/DebugDraw.h"
#include "core/Logger.h"
#include "core/UiTextArea.h"


template<>DebugDraw *Ogre::Singleton<DebugDraw>::msSingleton = nullptr;


DebugDraw::DebugDraw():
    m_Colour(1, 1, 1, 1),
    m_ScreenSpace(true),
    m_Z(0),
    m_FadeStartSquare(999999),
    m_FadeEndSquare(999999),
    m_FontHeight(16),
    m_LineMaxVertexCount(0),
    m_Line3dMaxVertexCount(0),
    m_QuadMaxVertexCount(0),
    m_TextMaxVertexCount(0)
{
    m_SceneManager = Ogre::Root::getSingleton().getSceneManager("Scene");
    m_RenderSystem = Ogre::Root::getSingletonPtr()->getRenderSystem();

    CreateLineVertexBuffer();
    CreateLine3dVertexBuffer();
    CreateTriangle3dVertexBuffer();
    CreateQuadVertexBuffer();
    CreateTextVertexBuffer();

    m_Material = Ogre::MaterialManager::getSingleton().create("DebugDraw", "General");
    Ogre::Pass* pass = m_Material->getTechnique(0)->getPass(0);
    pass->setVertexColourTracking(Ogre::TVC_AMBIENT);
    pass->setCullingMode(Ogre::CULL_NONE);
    pass->setDepthCheckEnabled(true);
    pass->setDepthWriteEnabled(true);
    pass->setLightingEnabled(false);
    pass->setSceneBlending(Ogre::SBT_TRANSPARENT_ALPHA);

    m_Material3d = Ogre::MaterialManager::getSingleton().create("DebugDraw3d", "General");
    pass = m_Material3d->getTechnique( 0 )->getPass(0);
    pass->setVertexColourTracking(Ogre::TVC_AMBIENT);
    pass->setCullingMode(Ogre::CULL_NONE);
    pass->setDepthCheckEnabled(true);
    pass->setDepthWriteEnabled(true);
    pass->setLightingEnabled(false);
    pass->setSceneBlending(Ogre::SBT_TRANSPARENT_ALPHA);

    m_Font = Ogre::FontManager::getSingleton().getByName("CourierNew");
    if(m_Font.isNull())
    {
        LOG_ERROR("Could not find font \"CourierNew\" for debug draw.");
        throw std::runtime_error("Font load failure");
    }

    m_Font->load();
    pass = m_Font->getMaterial()->getTechnique(0)->getPass(0);
    pass->setVertexColourTracking(Ogre::TVC_AMBIENT);
    pass->setCullingMode(Ogre::CULL_NONE);
    pass->setDepthCheckEnabled(true);
    pass->setDepthWriteEnabled(true);
    pass->setLightingEnabled(false);
    pass->setSceneBlending(Ogre::SBT_TRANSPARENT_ALPHA);

    //Ogre::MaterialSerializer mat;
    //mat.exportMaterial( m_Font->getMaterial(), "font.material" );

    m_SceneManager->addRenderQueueListener(this);
}


DebugDraw::~DebugDraw()
{
    m_SceneManager->removeRenderQueueListener(this);

    DestroyLineVertexBuffer();
    DestroyLine3dVertexBuffer();
    DestroyTriangle3dVertexBuffer();
    DestroyQuadVertexBuffer();
    DestroyTextVertexBuffer();
}


void
DebugDraw::SetColour(const Ogre::ColourValue& colour)
{
    m_Colour = colour;
}


void
DebugDraw::SetScreenSpace(const bool screen_space)
{
    m_ScreenSpace = screen_space;
}


void
DebugDraw::SetZ(const float z)
{
    m_Z = z;
}


void
DebugDraw::SetFadeDistance(const float fade_s, const float fade_e)
{
    m_FadeStartSquare = fade_s * fade_s;
    m_FadeEndSquare = fade_e * fade_e;
}


void
DebugDraw::SetTextAlignment(TextAlignment alignment)
{
    m_TextAlignment = alignment;
}


void
DebugDraw::Line(const float x1, const float y1, const float x2, const float y2)
{
    if(m_LineRenderOp.vertexData->vertexCount + 2 > m_LineMaxVertexCount)
    {
        LOG_ERROR("Max number of lines reached. Can't create more than " + Ogre::StringConverter::toString( m_LineMaxVertexCount / 2 ) + " lines.");
        return;
    }

    Ogre::Viewport *viewport(CameraManager::getSingleton().getViewport());
    float width = static_cast<float>(viewport->getActualWidth());
    float height = static_cast<float>(viewport->getActualHeight());

    float new_x1 = (m_ScreenSpace == true) ?  ((int) x1 / width) * 2 - 1 : x1;
    float new_y1 = (m_ScreenSpace == true) ? -(((int) y1 / height) * 2 - 1) : y1;
    float new_x2 = (m_ScreenSpace == true) ?  ((int) x2 / width) * 2 - 1 : x2;
    float new_y2 = (m_ScreenSpace == true) ? -(((int) y2 / height) * 2 - 1) : y2;

    float* writeIterator = (float*) m_LineVertexBuffer->lock(Ogre::HardwareBuffer::HBL_NORMAL);
    writeIterator += m_LineRenderOp.vertexData->vertexCount * 7;

    // TODO: This and the method below could be refactored
    *writeIterator++ = new_x1;
    *writeIterator++ = new_y1;
    *writeIterator++ = m_Z;
    *writeIterator++ = m_Colour.r;
    *writeIterator++ = m_Colour.g;
    *writeIterator++ = m_Colour.b;
    *writeIterator++ = m_Colour.a;

    *writeIterator++ = new_x2;
    *writeIterator++ = new_y2;
    *writeIterator++ = m_Z;
    *writeIterator++ = m_Colour.r;
    *writeIterator++ = m_Colour.g;
    *writeIterator++ = m_Colour.b;
    *writeIterator++ = m_Colour.a;

    m_LineRenderOp.vertexData->vertexCount += 2;

    m_LineVertexBuffer->unlock();
}


void
DebugDraw::Line3d(const Ogre::Vector3& point1, const Ogre::Vector3& point2)
{
    if(m_Line3dRenderOp.vertexData->vertexCount + 2 > m_Line3dMaxVertexCount)
    {
        LOG_ERROR("Max number of 3d lines reached. Can't create more than " + Ogre::StringConverter::toString(m_Line3dMaxVertexCount / 2) + " 3d lines.");
        return;
    }

    float* writeIterator = (float*) m_Line3dVertexBuffer->lock(Ogre::HardwareBuffer::HBL_NORMAL);
    writeIterator += m_Line3dRenderOp.vertexData->vertexCount * 7;

    *writeIterator++ = point1.x;
    *writeIterator++ = point1.y;
    *writeIterator++ = point1.z;
    *writeIterator++ = m_Colour.r;
    *writeIterator++ = m_Colour.g;
    *writeIterator++ = m_Colour.b;
    *writeIterator++ = m_Colour.a;

    *writeIterator++ = point2.x;
    *writeIterator++ = point2.y;
    *writeIterator++ = point2.z;
    *writeIterator++ = m_Colour.r;
    *writeIterator++ = m_Colour.g;
    *writeIterator++ = m_Colour.b;
    *writeIterator++ = m_Colour.a;

    m_Line3dRenderOp.vertexData->vertexCount += 2;

    m_Line3dVertexBuffer->unlock();
}


void
DebugDraw::Triangle3d(const Ogre::Vector3& point1, const Ogre::Vector3& point2, const Ogre::Vector3& point3)
{
    if(m_Triangle3dRenderOp.vertexData->vertexCount + 3 > m_Triangle3dMaxVertexCount)
    {
        LOG_ERROR("Max number of 3d triangles reached. Can't create more than " + Ogre::StringConverter::toString(m_Triangle3dMaxVertexCount / 3) + " 3d triangles.");
        return;
    }

    float* writeIterator = (float*) m_Triangle3dVertexBuffer->lock(Ogre::HardwareBuffer::HBL_NORMAL);
    writeIterator += m_Triangle3dRenderOp.vertexData->vertexCount * 7;

    *writeIterator++ = point1.x;
    *writeIterator++ = point1.y;
    *writeIterator++ = point1.z;
    *writeIterator++ = m_Colour.r;
    *writeIterator++ = m_Colour.g;
    *writeIterator++ = m_Colour.b;
    *writeIterator++ = m_Colour.a;

    *writeIterator++ = point2.x;
    *writeIterator++ = point2.y;
    *writeIterator++ = point2.z;
    *writeIterator++ = m_Colour.r;
    *writeIterator++ = m_Colour.g;
    *writeIterator++ = m_Colour.b;
    *writeIterator++ = m_Colour.a;

    *writeIterator++ = point3.x;
    *writeIterator++ = point3.y;
    *writeIterator++ = point3.z;
    *writeIterator++ = m_Colour.r;
    *writeIterator++ = m_Colour.g;
    *writeIterator++ = m_Colour.b;
    *writeIterator++ = m_Colour.a;

    m_Triangle3dRenderOp.vertexData->vertexCount += 3;

    m_Triangle3dVertexBuffer->unlock();
}


void
DebugDraw::Quad(const float x1, const float y1, const float x2, const float y2, const float x3, const float y3, const float x4, const float y4)
{
    if(m_QuadRenderOp.vertexData->vertexCount + 6 > m_QuadMaxVertexCount)
    {
        LOG_ERROR("Max number of quads reached. Can't create more than " + Ogre::StringConverter::toString( m_QuadMaxVertexCount / 6 ) + " quads.");
        return;
    }

    Ogre::Viewport *viewport(CameraManager::getSingleton().getViewport());
    float width = static_cast<float>(viewport->getActualWidth());
    float height = static_cast<float>(viewport->getActualHeight());

    float new_x1 = (m_ScreenSpace == true) ?  ((int) x1 / width) * 2 - 1 : x1;
    float new_y1 = (m_ScreenSpace == true) ? -(((int) y1 / height) * 2 - 1) : y1;
    float new_x2 = (m_ScreenSpace == true) ?  ((int) x2 / width) * 2 - 1 : x2;
    float new_y2 = (m_ScreenSpace == true) ? -((y2 / height) * 2 - 1) : y2;
    float new_x3 = (m_ScreenSpace == true) ?  ((int) x3 / width) * 2 - 1 : x3;
    float new_y3 = (m_ScreenSpace == true) ? -(((int) y3 / height) * 2 - 1) : y3;
    float new_x4 = (m_ScreenSpace == true) ?  ((int) x4 / width) * 2 - 1 : x4;
    float new_y4 = (m_ScreenSpace == true) ? -(((int) y4 / height) * 2 - 1) : y4;

    float* writeIterator = (float*) m_QuadVertexBuffer->lock(Ogre::HardwareBuffer::HBL_NORMAL);
    writeIterator += m_QuadRenderOp.vertexData->vertexCount * 7;

    *writeIterator++ = new_x1;
    *writeIterator++ = new_y1;
    *writeIterator++ = m_Z;
    *writeIterator++ = m_Colour.r;
    *writeIterator++ = m_Colour.g;
    *writeIterator++ = m_Colour.b;
    *writeIterator++ = m_Colour.a;

    *writeIterator++ = new_x2;
    *writeIterator++ = new_y2;
    *writeIterator++ = m_Z;
    *writeIterator++ = m_Colour.r;
    *writeIterator++ = m_Colour.g;
    *writeIterator++ = m_Colour.b;
    *writeIterator++ = m_Colour.a;

    *writeIterator++ = new_x3;
    *writeIterator++ = new_y3;
    *writeIterator++ = m_Z;
    *writeIterator++ = m_Colour.r;
    *writeIterator++ = m_Colour.g;
    *writeIterator++ = m_Colour.b;
    *writeIterator++ = m_Colour.a;

    *writeIterator++ = new_x1;
    *writeIterator++ = new_y1;
    *writeIterator++ = m_Z;
    *writeIterator++ = m_Colour.r;
    *writeIterator++ = m_Colour.g;
    *writeIterator++ = m_Colour.b;
    *writeIterator++ = m_Colour.a;

    *writeIterator++ = new_x3;
    *writeIterator++ = new_y3;
    *writeIterator++ = m_Z;
    *writeIterator++ = m_Colour.r;
    *writeIterator++ = m_Colour.g;
    *writeIterator++ = m_Colour.b;
    *writeIterator++ = m_Colour.a;

    *writeIterator++ = new_x4;
    *writeIterator++ = new_y4;
    *writeIterator++ = m_Z;
    *writeIterator++ = m_Colour.r;
    *writeIterator++ = m_Colour.g;
    *writeIterator++ = m_Colour.b;
    *writeIterator++ = m_Colour.a;

    m_QuadRenderOp.vertexData->vertexCount += 6;

    m_QuadVertexBuffer->unlock();
}


void
DebugDraw::Text(const float x, const float y, const Ogre::String& text)
{
    if(m_TextRenderOp.vertexData->vertexCount + text.size() * 6 > m_TextMaxVertexCount)
    {
        LOG_ERROR("Max number of text reached. Can't add text \"" + text + "\". Max number of letters is " +
                   Ogre::StringConverter::toString( m_TextMaxVertexCount / 6 ) + ".");
        return;
    }

    float* writeIterator = (float*) m_TextVertexBuffer->lock(Ogre::HardwareBuffer::HBL_NORMAL);
    writeIterator += m_TextRenderOp.vertexData->vertexCount * 9;

    Ogre::Viewport *viewport(CameraManager::getSingleton().getViewport());
    float width = static_cast<float>(viewport->getActualWidth());
    float height = static_cast<float>(viewport->getActualHeight());

    float length = 0;
    if(m_TextAlignment != LEFT)
    {
        for(auto &c : text)
        {
            length += ((m_Font->getGlyphAspectRatio(c) * m_FontHeight) / width) * 2;
        }

        if(m_TextAlignment == CENTER)
        {
            length /= 2;
        }
    }

    float current_x = (m_ScreenSpace == true) ? ((int) x / width) * 2 - 1 : x;
    current_x -= length;
    float current_y =  (m_ScreenSpace == true) ? -(((int) y / height) * 2 - 1) : y;
    float char_height = -(m_FontHeight / height) * 2;

    for( unsigned int i = 0; i < text.size(); ++i )
    {
        float char_width = ( ( m_Font->getGlyphAspectRatio( text[ i ] ) * m_FontHeight ) / width ) * 2;

        float new_x1 = current_x;
        float new_y1 = current_y;

        float new_x2 = current_x + char_width;
        float new_y2 = current_y;

        float new_x3 = current_x + char_width;
        float new_y3 = current_y + char_height;

        float new_x4 = current_x;
        float new_y4 = current_y + char_height;

        current_x += char_width;

        const Ogre::Font::UVRect& uv = m_Font->getGlyphTexCoords( text[ i ] );

        *writeIterator++ = new_x1;
        *writeIterator++ = new_y1;
        *writeIterator++ = m_Z;
        *writeIterator++ = m_Colour.r;
        *writeIterator++ = m_Colour.g;
        *writeIterator++ = m_Colour.b;
        *writeIterator++ = m_Colour.a;
        *writeIterator++ = uv.left;
        *writeIterator++ = uv.top;

        *writeIterator++ = new_x2;
        *writeIterator++ = new_y2;
        *writeIterator++ = m_Z;
        *writeIterator++ = m_Colour.r;
        *writeIterator++ = m_Colour.g;
        *writeIterator++ = m_Colour.b;
        *writeIterator++ = m_Colour.a;
        *writeIterator++ = uv.right;
        *writeIterator++ = uv.top;

        *writeIterator++ = new_x3;
        *writeIterator++ = new_y3;
        *writeIterator++ = m_Z;
        *writeIterator++ = m_Colour.r;
        *writeIterator++ = m_Colour.g;
        *writeIterator++ = m_Colour.b;
        *writeIterator++ = m_Colour.a;
        *writeIterator++ = uv.right;
        *writeIterator++ = uv.bottom;

        *writeIterator++ = new_x1;
        *writeIterator++ = new_y1;
        *writeIterator++ = m_Z;
        *writeIterator++ = m_Colour.r;
        *writeIterator++ = m_Colour.g;
        *writeIterator++ = m_Colour.b;
        *writeIterator++ = m_Colour.a;
        *writeIterator++ = uv.left;
        *writeIterator++ = uv.top;

        *writeIterator++ = new_x3;
        *writeIterator++ = new_y3;
        *writeIterator++ = m_Z;
        *writeIterator++ = m_Colour.r;
        *writeIterator++ = m_Colour.g;
        *writeIterator++ = m_Colour.b;
        *writeIterator++ = m_Colour.a;
        *writeIterator++ = uv.right;
        *writeIterator++ = uv.bottom;

        *writeIterator++ = new_x4;
        *writeIterator++ = new_y4;
        *writeIterator++ = m_Z;
        *writeIterator++ = m_Colour.r;
        *writeIterator++ = m_Colour.g;
        *writeIterator++ = m_Colour.b;
        *writeIterator++ = m_Colour.a;
        *writeIterator++ = uv.left;
        *writeIterator++ = uv.bottom;

        m_TextRenderOp.vertexData->vertexCount += 6;
    }

    m_TextVertexBuffer->unlock();
}


void
DebugDraw::Text(const Ogre::Vector3& point, const float x, const float y, const Ogre::String& text)
{
    Ogre::Vector3 point2d = CameraManager::getSingleton().ProjectPointToScreen(point);

    if(point2d.z <= 0)
    {
        float dist_sq = point.squaredDistance(CameraManager::getSingleton().GetCurrentCamera()->getPosition());

        if(dist_sq < m_FadeEndSquare)
        {
            float a = (dist_sq > m_FadeStartSquare) ? (1.0f - (dist_sq - m_FadeStartSquare ) / ( m_FadeEndSquare - m_FadeStartSquare)) : 1.0f;
            Ogre::ColourValue colour = m_Colour;
            colour.a = a;
            SetColour(colour);
            Text(point2d.x + x, point2d.y + y, text);
        }
    }
}


void
DebugDraw::renderQueueEnded(Ogre::uint8 queueGroupId, const Ogre::String& invocation, bool& repeatThisInvocation)
{
    if(queueGroupId == Ogre::RENDER_QUEUE_OVERLAY)
    {
        m_RenderSystem->clearFrameBuffer(Ogre::FBT_DEPTH);
        m_RenderSystem->_setWorldMatrix(Ogre::Matrix4::IDENTITY);
        m_RenderSystem->_setViewMatrix(Ogre::Matrix4::IDENTITY);
        m_RenderSystem->_setProjectionMatrix(Ogre::Matrix4::IDENTITY);

        if(m_LineRenderOp.vertexData->vertexCount != 0)
        {
            m_SceneManager->_setPass(m_Material->getTechnique(0)->getPass(0), true, false);
            m_RenderSystem->_render(m_LineRenderOp);
            m_LineRenderOp.vertexData->vertexCount = 0;
        }

        if(m_QuadRenderOp.vertexData->vertexCount != 0)
        {
            m_SceneManager->_setPass(m_Material->getTechnique(0)->getPass(0), true, false);
            m_RenderSystem->_render(m_QuadRenderOp);
            m_QuadRenderOp.vertexData->vertexCount = 0;
        }

        if(m_TextRenderOp.vertexData->vertexCount != 0)
        {
            m_SceneManager->_setPass(m_Font->getMaterial()->getTechnique(0)->getPass(0), true, false);
            m_RenderSystem->_render(m_TextRenderOp);
            m_TextRenderOp.vertexData->vertexCount = 0;
        }
    }
    else if(queueGroupId == Ogre::RENDER_QUEUE_MAIN)
    {
        m_RenderSystem->_setWorldMatrix(Ogre::Matrix4::IDENTITY);
        m_RenderSystem->_setViewMatrix(CameraManager::getSingleton().GetCurrentCamera()->getViewMatrix());
        m_RenderSystem->_setProjectionMatrix(CameraManager::getSingleton().GetCurrentCamera()->getProjectionMatrix());

        if(m_Line3dRenderOp.vertexData->vertexCount != 0)
        {
            m_SceneManager->_setPass(m_Material3d->getTechnique(0)->getPass(0), true, false);
            m_RenderSystem->_render(m_Line3dRenderOp);
            m_Line3dRenderOp.vertexData->vertexCount = 0;
        }

        if(m_Triangle3dRenderOp.vertexData->vertexCount != 0)
        {
            m_SceneManager->_setPass(m_Material3d->getTechnique(0)->getPass(0), true, false);
            m_RenderSystem->_render(m_Triangle3dRenderOp);
            m_Triangle3dRenderOp.vertexData->vertexCount = 0;
        }
    }
}


void
DebugDraw::CreateLineVertexBuffer()
{
    m_LineMaxVertexCount = 1024 * 2;
    m_LineRenderOp.vertexData = new Ogre::VertexData;
    m_LineRenderOp.vertexData->vertexStart = 0;

    Ogre::VertexDeclaration* vDecl = m_LineRenderOp.vertexData->vertexDeclaration;

    size_t offset = 0;
    vDecl->addElement(0, 0, Ogre::VET_FLOAT3, Ogre::VES_POSITION);
    offset += Ogre::VertexElement::getTypeSize(Ogre::VET_FLOAT3);
    vDecl->addElement(0, offset, Ogre::VET_FLOAT4, Ogre::VES_DIFFUSE);

    m_LineVertexBuffer = Ogre::HardwareBufferManager::getSingletonPtr()->createVertexBuffer(vDecl->getVertexSize(0), m_LineMaxVertexCount, Ogre::HardwareBuffer::HBU_DYNAMIC_WRITE_ONLY, false);

    m_LineRenderOp.vertexData->vertexBufferBinding->setBinding(0, m_LineVertexBuffer);
    m_LineRenderOp.operationType = Ogre::RenderOperation::OT_LINE_LIST;
    m_LineRenderOp.useIndexes = false;
}


void
DebugDraw::DestroyLineVertexBuffer()
{
    delete m_LineRenderOp.vertexData;
    m_LineRenderOp.vertexData = 0;
    m_LineVertexBuffer.setNull();
    m_LineMaxVertexCount = 0;
}


void
DebugDraw::CreateLine3dVertexBuffer()
{
    m_Line3dMaxVertexCount = 1024 * 2;
    m_Line3dRenderOp.vertexData = new Ogre::VertexData;
    m_Line3dRenderOp.vertexData->vertexStart = 0;

    Ogre::VertexDeclaration* vDecl = m_Line3dRenderOp.vertexData->vertexDeclaration;

    size_t offset = 0;
    vDecl->addElement(0, 0, Ogre::VET_FLOAT3, Ogre::VES_POSITION);
    offset += Ogre::VertexElement::getTypeSize(Ogre::VET_FLOAT3);
    vDecl->addElement(0, offset, Ogre::VET_FLOAT4, Ogre::VES_DIFFUSE);

    m_Line3dVertexBuffer = Ogre::HardwareBufferManager::getSingletonPtr()->createVertexBuffer(vDecl->getVertexSize( 0 ), m_Line3dMaxVertexCount, Ogre::HardwareBuffer::HBU_DYNAMIC_WRITE_ONLY, false);

    m_Line3dRenderOp.vertexData->vertexBufferBinding->setBinding(0, m_Line3dVertexBuffer);
    m_Line3dRenderOp.operationType = Ogre::RenderOperation::OT_LINE_LIST;
    m_Line3dRenderOp.useIndexes = false;
}


void
DebugDraw::DestroyLine3dVertexBuffer()
{
    delete m_Line3dRenderOp.vertexData;
    m_Line3dRenderOp.vertexData = 0;
    m_Line3dVertexBuffer.setNull();
    m_Line3dMaxVertexCount = 0;
}


void
DebugDraw::CreateTriangle3dVertexBuffer()
{
    m_Triangle3dMaxVertexCount = 128 * 3;
    m_Triangle3dRenderOp.vertexData = new Ogre::VertexData;
    m_Triangle3dRenderOp.vertexData->vertexStart = 0;

    Ogre::VertexDeclaration* vDecl = m_Triangle3dRenderOp.vertexData->vertexDeclaration;

    size_t offset = 0;
    vDecl->addElement(0, 0, Ogre::VET_FLOAT3, Ogre::VES_POSITION);
    offset += Ogre::VertexElement::getTypeSize(Ogre::VET_FLOAT3);
    vDecl->addElement(0, offset, Ogre::VET_FLOAT4, Ogre::VES_DIFFUSE);

    m_Triangle3dVertexBuffer = Ogre::HardwareBufferManager::getSingletonPtr()->createVertexBuffer(vDecl->getVertexSize(0), m_Triangle3dMaxVertexCount, Ogre::HardwareBuffer::HBU_DYNAMIC_WRITE_ONLY, false);

    m_Triangle3dRenderOp.vertexData->vertexBufferBinding->setBinding(0, m_Triangle3dVertexBuffer);
    m_Triangle3dRenderOp.operationType = Ogre::RenderOperation::OT_TRIANGLE_LIST;
    m_Triangle3dRenderOp.useIndexes = false;
}


void
DebugDraw::DestroyTriangle3dVertexBuffer()
{
    delete m_Triangle3dRenderOp.vertexData;
    m_Triangle3dRenderOp.vertexData = 0;
    m_Triangle3dVertexBuffer.setNull();
    m_Triangle3dMaxVertexCount = 0;
}


void
DebugDraw::CreateQuadVertexBuffer()
{
    m_QuadMaxVertexCount = 128 * 6;
    m_QuadRenderOp.vertexData = new Ogre::VertexData;
    m_QuadRenderOp.vertexData->vertexStart = 0;

    Ogre::VertexDeclaration* vDecl = m_QuadRenderOp.vertexData->vertexDeclaration;

    size_t offset = 0;
    vDecl->addElement(0, 0, Ogre::VET_FLOAT3, Ogre::VES_POSITION);
    offset += Ogre::VertexElement::getTypeSize(Ogre::VET_FLOAT3);
    vDecl->addElement(0, offset, Ogre::VET_FLOAT4, Ogre::VES_DIFFUSE);

    m_QuadVertexBuffer = Ogre::HardwareBufferManager::getSingletonPtr()->createVertexBuffer(vDecl->getVertexSize(0), m_QuadMaxVertexCount, Ogre::HardwareBuffer::HBU_DYNAMIC_WRITE_ONLY, false);

    m_QuadRenderOp.vertexData->vertexBufferBinding->setBinding(0, m_QuadVertexBuffer);
    m_QuadRenderOp.operationType = Ogre::RenderOperation::OT_TRIANGLE_LIST;
    m_QuadRenderOp.useIndexes = false;
}


void
DebugDraw::DestroyQuadVertexBuffer()
{
    delete m_QuadRenderOp.vertexData;
    m_QuadRenderOp.vertexData = 0;
    m_QuadVertexBuffer.setNull();
    m_QuadMaxVertexCount = 0;
}


void
DebugDraw::CreateTextVertexBuffer()
{
    m_TextMaxVertexCount = 4096 * 6;
    m_TextRenderOp.vertexData = new Ogre::VertexData;
    m_TextRenderOp.vertexData->vertexStart = 0;

    Ogre::VertexDeclaration* vDecl = m_TextRenderOp.vertexData->vertexDeclaration;

    size_t offset = 0;
    vDecl->addElement(0, 0, Ogre::VET_FLOAT3, Ogre::VES_POSITION);
    offset += Ogre::VertexElement::getTypeSize(Ogre::VET_FLOAT3);
    vDecl->addElement(0, offset, Ogre::VET_FLOAT4, Ogre::VES_DIFFUSE);
    offset += Ogre::VertexElement::getTypeSize(Ogre::VET_FLOAT4);
    vDecl->addElement(0, offset, Ogre::VET_FLOAT2, Ogre::VES_TEXTURE_COORDINATES);

    m_TextVertexBuffer = Ogre::HardwareBufferManager::getSingletonPtr()->createVertexBuffer(vDecl->getVertexSize(0), m_TextMaxVertexCount, Ogre::HardwareBuffer::HBU_DYNAMIC_WRITE_ONLY, false);

    m_TextRenderOp.vertexData->vertexBufferBinding->setBinding(0, m_TextVertexBuffer);
    m_TextRenderOp.operationType = Ogre::RenderOperation::OT_TRIANGLE_LIST;
    m_TextRenderOp.useIndexes = false;
}


void
DebugDraw::DestroyTextVertexBuffer()
{
    delete m_TextRenderOp.vertexData;
    m_TextRenderOp.vertexData = 0;
    m_TextVertexBuffer.setNull();
    m_TextMaxVertexCount = 0;
}
