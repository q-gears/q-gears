// $Id$

#ifndef FIGHTER_h
#define FIGHTER_h

#include <OgreEntity.h>
#include <OgreOverlay.h>
#include <OgreSceneNode.h>
#include <OgreString.h>

#include "BattleDataStructures.h"
#include "../core/Actor.h"
#include "../core/ui/MovableTextArea.h"

class BattleScriptManager;



class Fighter : public Actor
{
public:
                         Fighter(const Ogre::String& name, const Ogre::String& file_name, Ogre::SceneNode* node, BattleScriptManager* script);
    virtual             ~Fighter();

    void                 ShowDebug(const bool show);

    virtual void         Input(const Event& input);
    virtual void         Update(const float delta_time);

    int                  ScriptPlayAnimation(const char* animation);

    const Ogre::String   GetName() const;

    const Ogre::Vector3  GetPosition() const;
    void                 SetPosition(const Ogre::Vector3& position);
    void                 SetDirection(const Ogre::Degree& direction);
    const Ogre::Degree   GetDirection() const;

private:
    Fighter();

protected:
    BattleScriptManager*  m_ScriptManager;

    Ogre::String          m_Name;

    bool                  m_DrawDebug;
    MovableTextArea*      m_DebugInfoText;
    Ogre::Overlay*        m_DebugInfoOverlay;

    // model
    Ogre::Entity*         m_Model;
    Ogre::SceneNode*      m_SceneNode;
    Ogre::SceneNode*      m_ModelNode;

    Ogre::AnimationState* m_AnimationCurrent;
    int                   m_AnimationFighterWaiting;

public:
    FighterData           data;
};



#endif // FIGHTER_h
