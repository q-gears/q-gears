#ifndef ENTITY_DIRECTION_H
#define ENTITY_DIRECTION_H

#include <OgreCamera.h>
#include <OgreSimpleRenderable.h>



class EntityDirection : public Ogre::SimpleRenderable
{
public:
    EntityDirection();
    virtual ~EntityDirection();

    Ogre::Real getSquaredViewDepth( const Ogre::Camera* cam ) const;
    Ogre::Real getBoundingRadius() const;
};



#endif // ENTITY_DIRECTION_H
