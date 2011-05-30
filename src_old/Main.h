// $Id$

#ifndef MAIN_H
#define MAIN_H



enum QG_OVERLAY_ORDERING
{
    QGOO_FIELD_FADE = 3,

    QGOO_FIELD_MESSAGE = 5, // this is layer for bottom message, all next will be drawn as + 2 (first for window, second for text)

    QGOO_GAMESTATE_DEBUG = 100,
    QGOO_FIELD_DEBUG = 100,
    QGOO_BATTLE_DEBUG = 100,

    QGOO_CONSOLE = 600
};

enum QG_STATE
{
    QG_EXIT,
    QG_GAME
};

extern QG_STATE g_ApplicationState;

#define QG_VERSION_NAME "Q-Gears 0.00 alpha-5"


#endif // MAIN_H
