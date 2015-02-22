#ifndef __QGearsTile_H__
#define __QGearsTile_H__

#include <OgreVector2.h>
#include <OgreVector4.h>

#include "common/TypeDefine.h"

namespace QGears
{
    enum Blending
    {
        B_ALPHA
       ,B_ADD
       ,B_SUBTRACT
    };

    struct KeyFrame
    {
        Ogre::Real      time;
        Ogre::Vector4   uv;
    };

    typedef std::vector< KeyFrame >   KeyFrameList;

    struct Animation
    {
        Ogre::Real      length;
        KeyFrameList    key_frames;
    };

    typedef std::map< String, Animation >   AnimationMap;

    struct Tile
    {
        int             width;
        int             height;
        Ogre::Vector2   destination;
        Ogre::Vector4   uv;
        Ogre::Real      depth;
        Blending        blending;
        AnimationMap    animations;
    };
}

#endif // __QGearsTile_H__
