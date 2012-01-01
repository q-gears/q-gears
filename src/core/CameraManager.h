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
    void OnResize();

    const Ogre::Vector3 ProjectPointToScreen( const Ogre::Vector3& point );

    Ogre::Camera* GetCurrentCamera();

public:
    enum CameraState
    {
        CAMERA_2D,
        CAMERA_FREE
    };

private:
    Ogre::Camera* m_Camera;
    Ogre::Viewport* m_Viewport;

    CameraState m_State;

    // camera free related
    bool m_CameraFreeRotate;

    // camera 2D related
    Ogre::Matrix4 m_CameraViewMatrix;
    Ogre::Matrix4 m_CameraProjectionMatrix;
};



#endif // CAMERA_MANAGER_H
