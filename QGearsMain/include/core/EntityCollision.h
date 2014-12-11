#ifndef ENTITY_COLLISION_H
#define ENTITY_COLLISION_H

#include <OgreCamera.h>
#include <OgreSimpleRenderable.h>



class EntityCollision : public Ogre::SimpleRenderable
{
public:
    EntityCollision();
    virtual ~EntityCollision();

    Ogre::Real getSquaredViewDepth( const Ogre::Camera* cam ) const;
    Ogre::Real getBoundingRadius() const;
};



#endif // ENTITY_COLLISION_H
