// $Id$

#ifndef BATTLE_DATA_STRUCTURES_h
#define BATTLE_DATA_STRUCTURES_h

#include <OgreString.h>

#include "../game/GameState.h"



enum FighterRelationship
{
    PLAYER = 0,
    ENEMY  = 1
};



enum BattleActionType
{
    MONSTER_ACTION = 32, // 0x20
    DISPLAY_TEXT   = 36  // 0x24
};



struct FighterData : public CharacterData
{
    int                         fighter_id;
    FighterRelationship         relationship;

    float                       timer_value;
    bool                        timer_wait;
    bool                        in_action;

    bool                        auto_action;
    Ogre::String                script;
    Ogre::String                action_idle;
    Ogre::String                action_hurt;

    std::map<int, Ogre::String> action;
};



struct AttackData
{
    int          id;
    Ogre::String name;
    Ogre::String formula;
    float        power;
};



#endif // BATTLE_DATA_STRUCTURES_h
