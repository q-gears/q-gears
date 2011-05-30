#ifndef LINE_TRIGGER_h
#define LINE_TRIGGER_h

#include <Ogre.h>
#include "../core/Actor.h"

#include "LineTriggerLine.h"



class LineTrigger : public Actor
{
public:
                         LineTrigger(const Ogre::String& name, Ogre::SceneNode* node, const Ogre::Vector3& point1, const Ogre::Vector3& point2);
    virtual             ~LineTrigger(void);

    virtual void         Input(const Event& input);
    virtual void         Update(const float delta_time);

    void                 ShowDebug(const bool show);

    const Ogre::String   GetName() const;

    void                 SetEnabled(const bool enabled);
    const bool           IsEnabled() const;

    void                 SetInLine(const bool in_line);
    const bool           IsInLine() const;

    void                 SetCanBeActivated(const bool can_be_activated);
    const bool           IsCanBeActivated() const;

    void                 SetPoints(const Ogre::Vector3& point1, const Ogre::Vector3& point2);
    const Ogre::Vector3& GetPoint1(void) const;
    const Ogre::Vector3& GetPoint2(void) const;

protected:
    Ogre::SceneNode* m_SceneNode;
    LineTriggerLine* m_LineTriggerLine;

    Ogre::String     m_Name;

    bool             m_Enabled;
    bool             m_InLine;
    bool             m_CanBeActivated;

    Ogre::Vector3    m_Point1;
    Ogre::Vector3    m_Point2;
};



#endif // LINE_TRIGGER_h
