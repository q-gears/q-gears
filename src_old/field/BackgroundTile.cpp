// $Id$

#include <Ogre.h>

#include "BackgroundTile.h"

#define POSITION_BINDING 0
#define TEXCOORD_BINDING 1



BackgroundTile::BackgroundTile(void)
{
    // use identity projection and view matrices
    mUseIdentityProjection = true;
    mUseIdentityView = true;

    mRenderOp.vertexData = new Ogre::VertexData();

    mRenderOp.indexData = 0;
    mRenderOp.vertexData->vertexCount = 4;
    mRenderOp.vertexData->vertexStart = 0;
    mRenderOp.operationType = Ogre::RenderOperation::OT_TRIANGLE_STRIP;
    mRenderOp.useIndexes = false;

    Ogre::VertexDeclaration* decl = mRenderOp.vertexData->vertexDeclaration;
    Ogre::VertexBufferBinding* bind = mRenderOp.vertexData->vertexBufferBinding;

    decl->addElement(POSITION_BINDING, 0, Ogre::VET_FLOAT3, Ogre::VES_POSITION);


    Ogre::HardwareVertexBufferSharedPtr vbuf = Ogre::HardwareBufferManager::getSingleton().createVertexBuffer(
        decl->getVertexSize(POSITION_BINDING),
        mRenderOp.vertexData->vertexCount,
        Ogre::HardwareBuffer::HBU_STATIC_WRITE_ONLY);

    // Bind buffer
    bind->setBinding(POSITION_BINDING, vbuf);

    decl->addElement(TEXCOORD_BINDING, 0, Ogre::VET_FLOAT2, Ogre::VES_TEXTURE_COORDINATES);


    Ogre::HardwareVertexBufferSharedPtr tvbuf = Ogre::HardwareBufferManager::getSingleton().createVertexBuffer(
        decl->getVertexSize(TEXCOORD_BINDING),
        mRenderOp.vertexData->vertexCount,
        Ogre::HardwareBuffer::HBU_STATIC_WRITE_ONLY);

    // Bind buffer
    bind->setBinding(TEXCOORD_BINDING, tvbuf);



    // set basic white material
    this->setMaterial("field_tileset");
    Ogre::MaterialPtr mat = this->getMaterial();
    mat->setDepthCheckEnabled(false);
}



BackgroundTile::~BackgroundTile(void)
{
    delete mRenderOp.vertexData;
}



void
BackgroundTile::SetTile(const int x, const int y, const int width, const int height, const int tex_x, const int tex_y)
{
    Ogre::HardwareVertexBufferSharedPtr vbuf = mRenderOp.vertexData->vertexBufferBinding->getBuffer(POSITION_BINDING);
    float* pFloat = static_cast<float*>(vbuf->lock(Ogre::HardwareBuffer::HBL_DISCARD));

    Ogre::Real vpWidth, vpHeight;
    Ogre::OverlayManager& oMgr = Ogre::OverlayManager::getSingleton();
    vpWidth = (Ogre::Real)(oMgr.getViewportWidth()) / 2;
    vpHeight = (Ogre::Real)(oMgr.getViewportHeight()) / 2;

    float start_x = (x / vpWidth);
    float start_y = (-y / vpHeight);
    float end_x   = ((x + width) / vpWidth);
    float end_y   = ((-y - height) / vpHeight);

    *pFloat++ = start_x;
    *pFloat++ = start_y;
    *pFloat++ = 0;

    *pFloat++ = start_x;
    *pFloat++ = end_y;
    *pFloat++ = 0;

    *pFloat++ = end_x;
    *pFloat++ = start_y;
    *pFloat++ = 0;

    *pFloat++ = end_x;
    *pFloat++ = end_y;
    *pFloat++ = 0;

    vbuf->unlock();



    // Set up basic tex coordinates
    Ogre::MaterialPtr mat = this->getMaterial();
    std::pair<int, int> tex_size = mat->getTechnique(0)->getPass(0)->getTextureUnitState(0)->getTextureDimensions();
    //Ogre::LogManager::getSingletonPtr()->logMessage("Tex Size: " + Ogre::StringConverter::toString(tex_size.first) + " " + Ogre::StringConverter::toString(tex_size.second));
    Ogre::HardwareVertexBufferSharedPtr tvbuf = mRenderOp.vertexData->vertexBufferBinding->getBuffer(TEXCOORD_BINDING);
    float* pTex = static_cast<float*>(tvbuf->lock(Ogre::HardwareBuffer::HBL_DISCARD));
    *pTex++ = (float)tex_x / tex_size.first;
    *pTex++ = (float)tex_y / tex_size.second;
    *pTex++ = (float)tex_x / tex_size.first;
    *pTex++ = (float)(tex_y + height) / tex_size.second;
    *pTex++ = (float)(tex_x + width) / tex_size.first;
    *pTex++ = (float)tex_y / tex_size.second;
    *pTex++ = (float)(tex_x + width) / tex_size.first;
    *pTex++ = (float)(tex_y + height) / tex_size.second;
    tvbuf->unlock();
}



void
BackgroundTile::getWorldTransforms(Ogre::Matrix4* xform) const
{
    // return identity matrix to prevent parent transforms
    *xform = Ogre::Matrix4::IDENTITY;
}



const Ogre::Quaternion&
BackgroundTile::getWorldOrientation(void) const
{
    return Ogre::Quaternion::IDENTITY;
}



const Ogre::Vector3&
BackgroundTile::getWorldPosition(void) const
{
    return Ogre::Vector3::ZERO;
}
