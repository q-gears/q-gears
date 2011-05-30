// $Id$

#ifndef FIELD_TYPES_h
#define FIELD_TYPES_h



enum TurnDirection
{
    CLOCKWISE,
    ANTICLOCKWISE,
    CLOSEST
};

enum ModelMovement
{
    STAND,
    MOVE,
    JUMP,
    CLIMB
};

enum ModelAnimation
{
    STOP,
    PLAY_STOP_IN_LAST_FRAME,
    PLAY_GO_TO_DEFAULT,
    PLAY_DEFAULT
};

enum ClimbMovement
{
    UP_TO_DOWN,
    DOWN_TO_UP,
    LEFT_TO_RIGHT,
    RIGHT_TO_LEFT
};



enum ActionType
{
    NONE,
    LINEAR,
    SMOOTH
};




#endif // FIELD_TYPES_h
