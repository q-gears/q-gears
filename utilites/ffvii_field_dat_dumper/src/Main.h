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
};



extern int state;




#endif // MAIN_H
