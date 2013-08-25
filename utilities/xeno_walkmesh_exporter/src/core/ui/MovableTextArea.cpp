#include "MovableTextArea.h"

#include <Ogre.h>



MovableTextArea::MovableTextArea(const Ogre::String& name):
    Ogre::TextAreaOverlayElement(name),

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
    Ogre::Camera* camera = Ogre::Root::getSingleton().getAutoCreatedWindow()->getViewport(0)->getCamera();

    Ogre::Vector3 p = m_Position;
    p.z = p.z + m_AdditionalHeight;
    p = camera->getProjectionMatrix() * camera->getViewMatrix() * p;

    //p.x = 1 + p.x;
    //p.y = -1 + p.y;
    // we round aligment to pixel border to reduce blurring
    int width = Ogre::OverlayManager::getSingleton().getViewportWidth() / 2;
    int height = Ogre::OverlayManager::getSingleton().getViewportHeight() / 2;
    p.x = (float)((int)((1 + p.x) * width)) / width;
    p.y = (float)((int)((-1 + p.y) * height)) / height;
    p.z = 0;


    *xform = Ogre::Matrix3::IDENTITY;
    xform->setTrans(p);
}
