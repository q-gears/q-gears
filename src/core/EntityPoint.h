#ifndef ENTITY_POINT_H
#define ENTITY_POINT_H

#include <OgreRoot.h>



class EntityPoint
{
public:
    EntityPoint( const Ogre::String& name );
    virtual ~EntityPoint();

    void Update();

    const Ogre::String& GetName() const;

    void SetPoint( const Ogre::Vector3& point );
    const Ogre::Vector3& GetPoint() const;
    void ScriptGetPoint() const;

protected:
    Ogre::String m_Name;
    Ogre::Vector3 m_Point;
};



#endif // ENTITY_POINT_H
