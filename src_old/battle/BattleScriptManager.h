// $Id$

#ifndef BATTLE_SCRIPT_MANAGER_h
#define BATTLE_SCRIPT_MANAGER_h

#include <lua.hpp>
#include <luabind/luabind.hpp>
#include <OgreString.h>

#include "Fighter.h"
#include "../core/Actor.h"

class BattleModule;

typedef std::vector<Fighter*> FighterVector;

struct FighterLua
{
    Ogre::String  action;
    lua_State*    state;
    bool          wait;
    bool          yield;

    FighterVector target;

    // hurt related
    float         time_to_hurt;
};



class BattleScriptManager : public Actor
{
public:
                       BattleScriptManager(BattleModule* module);
    virtual           ~BattleScriptManager(void);

    virtual void       Input(const Event& input);
    virtual void       Update(const float delta_time);

    void               ScriptPlayHurtAction(Fighter* target, const float time);

    void               LoadFile(const Ogre::String& name);

    const int          GetCurrentFighter() const;
    void               ContinueFighterAction(const int fighter_id);
    void               SetFighterAction(const int fighter_id, const Ogre::String& action, const FighterVector& target);

    void               ExecuteLogic(const Ogre::String& script, const Ogre::String& function);
    int                ExecuteDamage(Fighter* attacker, Fighter* target, const AttackData& attack);
    void               SetTableFighter(const FighterVector& fighters, const Ogre::String& name);
    void               SetFighter(Fighter* fighter, const Ogre::String& name);
    void               GetTableFighter(FighterVector& fighters, const Ogre::String& name) const;
    void               GetFighter(Fighter*& fighter, const Ogre::String& name) const;
    void               CreateFighterObject(const Ogre::String& table, Fighter* fighter);
private:
    BattleModule*           m_BattleModule;
    lua_State*              m_LuaState;
    std::vector<FighterLua> m_Fighters;

    int                     m_CurrentFighter;
};



#endif // BATTLE_SCRIPT_MANAGER_h
