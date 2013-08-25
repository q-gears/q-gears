// $Id: Main.h 93 2006-11-12 13:49:02Z einherjar $

#ifndef MAIN_H
#define MAIN_H

#include "common/utilites/StdString.h"



enum
{
    EXIT,
    GAME
};

extern unsigned char state;

extern void    game_main(void);
extern void    game_module_start(void);
extern RString game_title(void);



#endif // MAIN_H
