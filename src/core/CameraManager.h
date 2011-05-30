#ifndef CAMERA_MANAGER_H
#define CAMERA_MANAGER_H

#include <OgreCamera.h>
#include <OgreSingleton.h>

#include "Event.h"



class CameraManager : public Ogre::Singleton< CameraManager >
{
public:
    CameraManager();
    virtual ~CameraManager();

    void Input( const Event& event );
    void Update();

    const Ogre::Vector3 ProjectPointToScreen( const Ogre::Vector3& point );

    Ogre::Camera* GetCurrentCamera();

private:
    Ogre::Camera* m_Camera;
    Ogre::Viewport* m_Viewport;

    // 3D free related
    bool m_CameraFreeRotate;
};



#endif // CAMERA_MANAGER_H
