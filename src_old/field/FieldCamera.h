// $Id$

#ifndef FIELD_CAMERA_h
#define FIELD_CAMERA_h

#include <Ogre.h>

#include "../core/Actor.h"



enum CameraState
{
    CS_2_5D_GAME, // FFVII
    CS_2_5D_FREE,
    CS_3D_GAME,   // XenoGears
    CS_3D_FREE
};



class FieldCamera : public Actor
{
public:
                  FieldCamera(void);
    virtual      ~FieldCamera(void);

    virtual void  Input(const Event& input);
    virtual void  Update(const float delta_time);

    // 3D free related
    void          SetToPosition(const Ogre::Vector3& position);

    // 2,5D game related
    void          Set2_5DMatrixes(const Ogre::Matrix4& view, const Ogre::Matrix4& projection);

private:
    Ogre::Camera* m_Camera;
    Ogre::Camera* m_PreviousCamera;
    CameraState   m_CameraState;

    // 3D free related
    bool          m_CameraFreeRotate;

    // 2,5D game related
    Ogre::Matrix4 m_CameraViewMatrix;
    Ogre::Matrix4 m_CameraProjectionMatrix;
};



#endif // FIELD_CAMERA_h
