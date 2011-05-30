// $Id$

#ifndef BACKGROUND_TILE_h
#define BACKGROUND_TILE_h

#include "OgreSimpleRenderable.h"



class _OgreExport BackgroundTile : public Ogre::SimpleRenderable
{
public:
               BackgroundTile(void);
    virtual   ~BackgroundTile(void);

    void       SetTile(const int x, const int y, const int width, const int height, const int tex_x, const int tex_y);

    Ogre::Real getSquaredViewDepth(const Ogre::Camera* cam) const { return 0; }
    Ogre::Real getBoundingRadius(void) const { return 0; }

protected:
    void                    getWorldTransforms(Ogre::Matrix4* xform) const;
    const Ogre::Quaternion& getWorldOrientation(void) const;
    const Ogre::Vector3&    getWorldPosition(void) const;
};



#endif // BACKGROUND_TILE_h
