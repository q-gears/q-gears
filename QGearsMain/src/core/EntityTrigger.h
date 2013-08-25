#ifndef ENTITY_TRIGGER_H
#define ENTITY_TRIGGER_H

#include <OgreRoot.h>

class Entity;



class EntityTrigger
{
public:
    EntityTrigger( const Ogre::String& name );
    virtual ~EntityTrigger();

    void UpdateDebug();

    const Ogre::String& GetName() const;

    void SetEnabled( const bool enabled );
    bool IsEnabled() const;

    void AddActivator( Entity* activator );
    void RemoveActivator( Entity* activator );
    bool IsActivator( Entity* activator );

    void SetPoints( const Ogre::Vector3& point1, const Ogre::Vector3& point2 );
    const Ogre::Vector3& GetPoint1() const;
    const Ogre::Vector3& GetPoint2() const;

protected:
    Ogre::String m_Name;

    bool m_Enabled;

    std::vector< Entity* > m_Activators;

    Ogre::Vector3 m_Point1;
    Ogre::Vector3 m_Point2;
};



#endif // ENTITY_TRIGGER_H
