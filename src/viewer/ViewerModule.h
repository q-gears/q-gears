#ifndef VIEWER_MODULE_H
#define VIEWER_MODULE_H

#include <OgreString.h>

#include "../core/Module.h"
//#include "../core/debug/DebugText.h"
#include "../core/particles/ParticleSystem.h"
#include "../game/Walkmesh.h"



class ViewerModule : public Module
{
public:
                 ViewerModule();
    virtual     ~ViewerModule();

    virtual void Input(const Event& input);
    virtual void Update();

    void         PlayAnimation(const Ogre::String& name);
    void         Clear();
    void         SetModelToLoad(const Ogre::String& name);
    void         SetWalkmeshToLoad(const Ogre::String& name);

private:
    ParticleSystem*     m_ParticleSystem;

    //DebugText           m_EntityState;
    Ogre::Entity*       m_Entity;

    Walkmesh*           m_Walkmesh;

    Ogre::Entity*       m_Grid;
    Ogre::Entity*       m_Axis;
    Ogre::SceneNode*    m_SceneNode;
};



#endif // VIEWER_MODULE_H
