#include "MovableTextArea.h"
#include "../CameraManager.h"

#include <OgreOverlayManager.h>



MovableTextArea::MovableTextArea(const Ogre::String& name):
    TextArea(name),

    m_Position(0, 0, 0),
    m_AdditionalHeight(0)
{
}



MovableTextArea::~MovableTextArea()
{
}



void
MovableTextArea::Set3DPosition(const Ogre::Vector3& position)
{
    m_Position = position;
}



void
MovableTextArea::SetAdditionalHeight(const float height)
{
    m_AdditionalHeight = height;
}



void
MovableTextArea::getWorldTransforms(Ogre::Matrix4 *xform) const
{
    Ogre::Camera* camera = CameraManager::getSingleton().GetCurrentCamera();

    Ogre::Vector3 p = m_Position;
    p.z = p.z + m_AdditionalHeight;
    p = camera->getProjectionMatrix() * camera->getViewMatrix() * p;

    // we round aligment to pixel border to reduce blurring
    int width = Ogre::OverlayManager::getSingleton().getViewportWidth() / 2;
    int height = Ogre::OverlayManager::getSingleton().getViewportHeight() / 2;
    p.x = (float)((int)((1 + p.x) * width)) / width;
    p.y = (float)((int)((-1 + p.y) * height)) / height;
    p.z = 0;

    *xform = Ogre::Matrix3::IDENTITY;
    xform->setTrans(p);
}
