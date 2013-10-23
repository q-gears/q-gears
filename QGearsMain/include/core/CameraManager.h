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

    // camera free related
    void SetCameraFree( const bool enable );

    // camera 2D related
    void Set2DCamera( const Ogre::Vector3 position, const Ogre::Quaternion orientation, const Ogre::Radian fov );
    void Set2DScroll( const Ogre::Vector2& position );
    const Ogre::Vector2& Get2DScroll() const;

    const Ogre::Vector3 ProjectPointToScreen( const Ogre::Vector3& point );

    Ogre::Camera*   GetCurrentCamera();
    Ogre::Viewport* getViewport();

private:

    void InitCommands();

private:
    Ogre::Camera   *m_Camera;
    Ogre::Viewport *m_Viewport;

    // camera free related
    bool m_CameraFree;
    bool m_CameraFreeRotate;

    // camera 2D related
    Ogre::Vector3 m_2DPosition;
    Ogre::Quaternion m_2DOrientation;
    Ogre::Radian m_2DFOV;
    Ogre::Vector2 m_2DScroll;
};



#endif // CAMERA_MANAGER_H
