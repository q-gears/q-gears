#ifndef TYPE_DEFINE_H
#define TYPE_DEFINE_H

#include <OgrePlatform.h>
#include <OgreString.h>

typedef Ogre::uint8  u8;
typedef Ogre::uint16 u16;
typedef Ogre::uint32 u32;

typedef Ogre::int8  s8;
typedef Ogre::int16 s16;
typedef Ogre::int32 s32;

namespace QGears
{
    typedef Ogre::uchar  uchar;
    typedef Ogre::uint8  uint8;
    typedef Ogre::uint16 uint16;
    typedef Ogre::uint32 uint32;

    typedef Ogre::int8  sint8;
    typedef Ogre::int16 sint16;
    typedef Ogre::int32 sint32;

    typedef Ogre::String String;

    struct ColorComponents
    {
        u8 blue;
        u8 green;
        u8 red;
        u8 alpha;
    };

    union ColorA8R8G8B8
    {
        ColorComponents comp;
        u32 all;
    };

    extern const String    EXT_MATERIAL;
    extern const String    EXT_MESH;
    extern const String    EXT_SKELETON;

    extern const String    EXT_P;
    extern const String    EXT_PLY;
    extern const String    EXT_RSD;
    extern const String    EXT_TIM;
    extern const String    EXT_TEX;
}

#endif // TYPE_DEFINE_H
