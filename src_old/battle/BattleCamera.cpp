// $Id$

#include <OgreRenderWindow.h>
#include <OgreRoot.h>
#include <OgreViewport.h>

#include "BattleCamera.h"



BattleCamera::BattleCamera(void):
    m_CameraFreeRotate(false)
{
    // we must create this not in constructor of field cause this change camera.
    Ogre::SceneManager* scene_manager;
    scene_manager = Ogre::Root::getSingleton().getSceneManager("Scene");
    m_Camera = scene_manager->createCamera("BattleCamera");
    m_Camera->setNearClipDistance(5);
    m_Camera->setPosition(Ogre::Vector3(9000, 6000, 9000));
    m_Camera->lookAt(Ogre::Vector3(0, 0, 0));

    Ogre::Viewport* viewport = Ogre::Root::getSingleton().getAutoCreatedWindow()->getViewport(0);
    m_PreviousCamera = viewport->getCamera();
    viewport->setCamera(m_Camera);
    m_Camera->setAspectRatio(Ogre::Real(viewport->getActualWidth()) / Ogre::Real(viewport->getActualHeight()));
}



BattleCamera::~BattleCamera(void)
{
    Ogre::SceneManager* scene_manager;
    scene_manager = Ogre::Root::getSingleton().getSceneManager("Scene");
    scene_manager->destroyCamera(scene_manager->getCamera("BattleCamera"));

    Ogre::Root::getSingleton().getAutoCreatedWindow()->getViewport(0)->setCamera(m_PreviousCamera);
}



void
BattleCamera::Input(const Event& input)
{
    //Ogre::LogManager::getSingletonPtr()->logMessage("Event come '" + input.name + "' and type '" + Ogre::StringConverter::toString(int(input.type)) + "'");
    if (input.name == "camera_forward")
    {
        m_Camera->moveRelative(Ogre::Vector3( 0, 0, -50));
    }
    if (input.name == "camera_left")
    {
        m_Camera->moveRelative(Ogre::Vector3(-50, 0,  0));
    }
    if (input.name == "camera_backward")
    {
        m_Camera->moveRelative(Ogre::Vector3( 0, 0,  50));
    }
    if (input.name == "camera_right")
    {
        m_Camera->moveRelative(Ogre::Vector3( 50, 0,  0));
    }

    if (input.name == "camera_rotate_on")
    {
        m_CameraFreeRotate = true;
    }
    else if (input.name == "camera_rotate_off")
    {
        m_CameraFreeRotate = false;
    }

    if (m_CameraFreeRotate && input.name == "mouse_move")
    {
        m_Camera->rotate(Ogre::Vector3::UNIT_Y, Ogre::Radian(Ogre::Degree(-input.x * 0.13)));
        m_Camera->pitch(Ogre::Degree(-input.y * 0.13));
    }
}



void
BattleCamera::Update(const float delta_time)
{
}
