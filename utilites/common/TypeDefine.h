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
    typedef Ogre::uint8  uint8;
    typedef Ogre::uint16 uint16;
    typedef Ogre::uint32 uint32;

    typedef Ogre::int8  sint8;
    typedef Ogre::int16 sint16;
    typedef Ogre::int32 sint32;

    typedef Ogre::String String;
#if OGRE_COMPILER == OGRE_COMPILER_MSVC
#pragma pack (push, 1)
#else
#pragma pack (1)
#endif

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

#if OGRE_COMPILER == OGRE_COMPILER_MSVC
#pragma pack (pop)
#else
#pragma pack ()
#endif

}

#endif // TYPE_DEFINE_H
