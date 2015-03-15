// $Id$

#include <Ogre.h>
#include <OgreOverlayManager.h>

#include "Walkmesh.h"
#include "../../Main.h"

#define POSITION_BINDING 0
#define COLOUR_BINDING 1



Walkmesh::Walkmesh(void)
{
    mRenderOp.vertexData = new Ogre::VertexData();

    this->setMaterial("field/walkmesh");

    m_Overlay = Ogre::OverlayManager::getSingleton().create("WalkmeshDebugOverlay");
    m_Overlay->setZOrder(10);

    Ogre::LogManager::getSingletonPtr()->logMessage("Walkmesh created.");
}



Walkmesh::~Walkmesh(void)
{
    for (size_t i = 0; i < m_TriangleTexts.size(); ++i)
    {
        m_Overlay->remove2D((Ogre::OverlayContainer*)m_TriangleTexts[i]);
        delete m_TriangleTexts[i];
    }
    Ogre::OverlayManager::getSingleton().destroy(m_Overlay);

    delete mRenderOp.vertexData;

    Ogre::LogManager::getSingletonPtr()->logMessage("Walkmesh destroyed.");
}



void
Walkmesh::AddTriangle(const WalkmeshTriangle& triangle)
{
    m_Triangles.push_back(triangle);
}



const int
Walkmesh::GetAccessSide(const int triangle_id, const unsigned char side) const
{
    if (triangle_id >= static_cast<int>(m_Triangles.size()) || triangle_id < 0)
    {
        Ogre::LogManager::getSingletonPtr()->logMessage("Walkmesh::GetAccessSide: triangle_id greater than number of triangles in walkmesh or less than zero.");
        return -1;
    }

    if (side >= 3)
    {
        Ogre::LogManager::getSingletonPtr()->logMessage("Walkmesh::GetAccessSide: side greater than 2. Side indexed from 0 to 2.");
        return -1;
    }

    return m_Triangles[triangle_id].access_side[side];
}



const Ogre::Vector3&
Walkmesh::GetA(const int triangle_id) const
{
    if (triangle_id >= static_cast<int>(m_Triangles.size()) || triangle_id < 0)
    {
        Ogre::LogManager::getSingletonPtr()->logMessage("Walkmesh::GetA: triangle_id greater than number of triangles in walkmesh or less than zero.");
        return Ogre::Vector3::ZERO;
    }

    return m_Triangles[triangle_id].a;
}



const Ogre::Vector3&
Walkmesh::GetB(const int triangle_id) const
{
    if (triangle_id >= static_cast<int>(m_Triangles.size()) || triangle_id < 0)
    {
        Ogre::LogManager::getSingletonPtr()->logMessage("Walkmesh::GetB: triangle_id greater than number of triangles in walkmesh or less than zero.");
        return Ogre::Vector3::ZERO;
    }

    return m_Triangles[triangle_id].b;
}



const Ogre::Vector3&
Walkmesh::GetC(const int triangle_id) const
{
    if (triangle_id >= static_cast<int>(m_Triangles.size()) || triangle_id < 0)
    {
        Ogre::LogManager::getSingletonPtr()->logMessage("Walkmesh::GetC: triangle_id greater than number of triangles in walkmesh or less than zero.");
        return Ogre::Vector3::ZERO;
    }

    return m_Triangles[triangle_id].c;
}



void
Walkmesh::LockWalkmesh(const int triangle_id, const bool lock)
{
    if (triangle_id >= static_cast<int>(m_Triangles.size()) || triangle_id < 0)
    {
        Ogre::LogManager::getSingletonPtr()->logMessage("Walkmesh::SetAccessible: triangle_id greater than number of triangles in walkmesh or less than zero.");
        return;
    }

    m_Triangles[triangle_id].locked = lock;



    Ogre::HardwareVertexBufferSharedPtr vbuf1 = mRenderOp.vertexData->vertexBufferBinding->getBuffer(COLOUR_BINDING);
    Ogre::RGBA* pPos = static_cast<Ogre::RGBA*>(vbuf1->lock(Ogre::HardwareBuffer::HBL_NORMAL));

    Ogre::ColourValue color = (lock == false) ? Ogre::ColourValue(1, 1, 1) : Ogre::ColourValue(1, 0, 0);
    Ogre::RenderSystem* rs = Ogre::Root::getSingleton().getRenderSystem();

    for (int i = 0; i < 3; ++i)
    {
        int id = m_Triangles[triangle_id].access_side[i];

        if (id != -1)
        {
            rs->convertColourValue(color, pPos + triangle_id * 6 + i * 2 + 0);
            rs->convertColourValue(color, pPos + triangle_id * 6 + i * 2 + 1);

            for (int j = 0; j < 3; ++j)
            {
                if (m_Triangles[id].access_side[j] == triangle_id)
                {
                    rs->convertColourValue(color, pPos + id * 6 + j * 2 + 0);
                    rs->convertColourValue(color, pPos + id * 6 + j * 2 + 1);

                    break;
                }
            }
        }
    }

    vbuf1->unlock();
}



const bool
Walkmesh::IsLocked(const int triangle_id) const
{
    if (triangle_id >= static_cast<int>(m_Triangles.size()) || triangle_id < 0)
    {
        Ogre::LogManager::getSingletonPtr()->logMessage("Walkmesh::IsAccessible: triangle_id greater than number of triangles in walkmesh or less than zero.");
        return true;
    }

    return m_Triangles[triangle_id].locked;
}



void
Walkmesh::SetUpWalkmesh(void)
{
    SetUpWalkmeshVertices();

    // setup the bounding box of this SimpleRenderable
    Ogre::AxisAlignedBox aabb;
    aabb.setInfinite();
    setBoundingBox(aabb);
}



void
Walkmesh::SetUpWalkmeshVertices(void)
{
    Ogre::LogManager::getSingletonPtr()->logMessage("SetUp walkmesh vertexes.");
    mRenderOp.indexData = 0;
    mRenderOp.vertexData->vertexCount = m_Triangles.size() * 6;
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

    // 2nd buffer
    decl->addElement(COLOUR_BINDING, 0, Ogre::VET_COLOUR, Ogre::VES_DIFFUSE);
    Ogre::HardwareVertexBufferSharedPtr vbuf1 = Ogre::HardwareBufferManager::getSingleton().createVertexBuffer(
            Ogre::VertexElement::getTypeSize(Ogre::VET_COLOUR),
            mRenderOp.vertexData->vertexCount,
            Ogre::HardwareBuffer::HBU_STATIC_WRITE_ONLY);
    // Set vertex buffer binding so buffer 1 is bound to our colour buffer
    bind->setBinding(COLOUR_BINDING, vbuf1);

    float* pPos = static_cast<float*>(vbuf0->lock(Ogre::HardwareBuffer::HBL_DISCARD));




    Ogre::RenderSystem* rs = Ogre::Root::getSingleton().getRenderSystem();
    
    std::vector<Ogre::RGBA> coloursVec(m_Triangles.size() * 6);

    Ogre::RGBA* colours = coloursVec.data();

    Ogre::ColourValue c_access = Ogre::ColourValue(1, 1, 1);
    Ogre::ColourValue c_deny   = Ogre::ColourValue(1, 0, 0);

    for (size_t i = 0; i < m_Triangles.size(); ++i)
    {
        // line 0
        *pPos++ = m_Triangles[i].a.x; *pPos++ = m_Triangles[i].a.y; *pPos++ = m_Triangles[i].a.z;
        *pPos++ = m_Triangles[i].b.x; *pPos++ = m_Triangles[i].b.y; *pPos++ = m_Triangles[i].b.z;
        // line 1
        *pPos++ = m_Triangles[i].b.x; *pPos++ = m_Triangles[i].b.y; *pPos++ = m_Triangles[i].b.z;
        *pPos++ = m_Triangles[i].c.x; *pPos++ = m_Triangles[i].c.y; *pPos++ = m_Triangles[i].c.z;
        // line 2
        *pPos++ = m_Triangles[i].c.x; *pPos++ = m_Triangles[i].c.y; *pPos++ = m_Triangles[i].c.z;
        *pPos++ = m_Triangles[i].a.x; *pPos++ = m_Triangles[i].a.y; *pPos++ = m_Triangles[i].a.z;

        rs->convertColourValue((m_Triangles[i].access_side[0] == -1) ? c_deny : c_access, colours + i * 6 + 0);
        rs->convertColourValue((m_Triangles[i].access_side[0] == -1) ? c_deny : c_access, colours + i * 6 + 1);
        rs->convertColourValue((m_Triangles[i].access_side[1] == -1) ? c_deny : c_access, colours + i * 6 + 2);
        rs->convertColourValue((m_Triangles[i].access_side[1] == -1) ? c_deny : c_access, colours + i * 6 + 3);
        rs->convertColourValue((m_Triangles[i].access_side[2] == -1) ? c_deny : c_access, colours + i * 6 + 4);
        rs->convertColourValue((m_Triangles[i].access_side[2] == -1) ? c_deny : c_access, colours + i * 6 + 5);

        MovableTextArea* text = new MovableTextArea("Text");
        text->setCaption(Ogre::StringConverter::toString(m_Triangles[i].unknown1) + "/" + Ogre::StringConverter::toString(m_Triangles[i].unknown2));
        text->setMetricsMode(Ogre::GMM_PIXELS);
        text->setPosition(0, 0);
        text->setAlignment(Ogre::TextAreaOverlayElement::Center);
        text->setFontName("DebugText");
        text->setCharHeight(18);
        text->Set3DPosition((m_Triangles[i].a + m_Triangles[i].b + m_Triangles[i].c) / 3);
        m_Overlay->add2D((Ogre::OverlayContainer*)text);
        m_TriangleTexts.push_back(text);
    }

    vbuf0->unlock();
    vbuf1->writeData(0, vbuf1->getSizeInBytes(), colours, true);
    Ogre::LogManager::getSingletonPtr()->logMessage("SetUp walkmesh vertexes finished.");
}



Ogre::Real
Walkmesh::getSquaredViewDepth(const Ogre::Camera* cam) const
{
    return 0;
}



Ogre::Real
Walkmesh::getBoundingRadius(void) const
{
    return 0;
}



void
Walkmesh::setVisible(bool visible)
{
    if (visible == true)
    {
        m_Overlay->show();
    }
    else
    {
        m_Overlay->hide();
    }

    Ogre::SimpleRenderable::setVisible(visible);
}
