#ifndef MAIN_H
#define MAIN_H

#include <Ogre.h>



enum
{
    EXIT,
    GAME
};




struct Field
{
    Ogre::String name;
    int tex_width;
    int tex_height;
};



extern int state;




#endif // MAIN_H
