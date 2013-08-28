#ifndef __QGearsGameState_H__
#define __QGearsGameState_H__

#define QG_VERSION_NAME "Q-Gears v0.21 (3rd alpha Run Wild)"

namespace QGears
{
    enum GAME_STATE
    {
        G_EXIT,
        G_GAME
    };

    extern GAME_STATE g_ApplicationState;
}

#endif // __QGearsGameState_H__
