#ifndef MAIN_H
#define MAIN_H

#include <Ogre.h>



enum
{
    EXIT,
    GAME
};



struct FieldKeyFrame
{
    float time;
    bool blank;
    unsigned char animation_index;
};

enum FiledAnimationType
{
    FAT_ANIMATION,
    FAT_CLUT
};

struct FiledAnimation
{
    Ogre::String name;
    float time;
    FiledAnimationType type;
    unsigned char animation;
    unsigned char clut;
    std::vector< FieldKeyFrame > keyframes;
};

struct Field
{
    Ogre::String name;
    int tex_width;
    int tex_height;
    std::vector< FiledAnimation > animations;
};



extern int state;




#endif // MAIN_H
