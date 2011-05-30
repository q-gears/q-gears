// $Id$

#ifndef BATTLE_CAMERA_h
#define BATTLE_CAMERA_h

#include <OgreCamera.h>

#include "../core/Actor.h"



class BattleCamera : public Actor
{
public:
                  BattleCamera(void);
    virtual      ~BattleCamera(void);

    virtual void  Input(const Event& input);
    virtual void  Update(const float delta_time);

private:
    Ogre::Camera* m_Camera;
    Ogre::Camera* m_PreviousCamera;

    bool          m_CameraFreeRotate;
};



#endif // BATTLE_CAMERA_h
