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

    void SetPosition( const Ogre::Vector3& point );
    const Ogre::Vector3& GetPosition() const;
    void ScriptGetPosition() const;

    void SetRotation( const float rotation );
    float GetRotation() const;
    float ScriptGetRotation() const;

protected:
    Ogre::String m_Name;
    Ogre::Vector3 m_Position;
    float m_Rotation;
};



#endif // ENTITY_POINT_H
