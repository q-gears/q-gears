// $Id$

#include <OgreLogManager.h>
#include <OgreStringConverter.h>
#include <lua.hpp>
#include <luabind/luabind.hpp>

#include "BattleDataStructures.h"
#include "BattleModule.h"
#include "BattleScriptManager.h"
#include "../core/Configuration.h"
#include "../core/script/Binder.h"



BattleScriptManager::BattleScriptManager(BattleModule* battle):
    m_BattleModule(battle),
    m_CurrentFighter(-1)
{
    m_LuaState = lua_open();
    luabind::open(m_LuaState);
    luaopen_base(m_LuaState);
    luaopen_string(m_LuaState);
    luaopen_table(m_LuaState);
    luaopen_math(m_LuaState);

    // default library
    if (luaL_dofile(m_LuaState, (Configuration::getSingleton().GetFileRoot() + "system/scripts/bit.lua").c_str()) == 1)
    {
        luabind::object error_msg(luabind::from_stack(m_LuaState, -1));
        Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT ERROR] " + Ogre::String(luabind::object_cast<std::string>(error_msg)));
    }
    if (luaL_dofile(m_LuaState, (Configuration::getSingleton().GetFileRoot() + "system/scripts/hex.lua").c_str()) == 1)
    {
        luabind::object error_msg(luabind::from_stack(m_LuaState, -1));
        Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT ERROR] " + Ogre::String(luabind::object_cast<std::string>(error_msg)));
    }
    if (luaL_dofile(m_LuaState, (Configuration::getSingleton().GetFileRoot() + "system/scripts/battle.lua").c_str()) == 1)
    {
        luabind::object error_msg(luabind::from_stack(m_LuaState, -1));
        Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT ERROR] " + Ogre::String(luabind::object_cast<std::string>(error_msg)));
    }
    if (luaL_dofile(m_LuaState, (Configuration::getSingleton().GetFileRoot() + "system/scripts/damage.lua").c_str()) == 1)
    {
        luabind::object error_msg(luabind::from_stack(m_LuaState, -1));
        Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT ERROR] " + Ogre::String(luabind::object_cast<std::string>(error_msg)));
    }

    //lua_gc (m_LuaState, LUA_GCSTOP, 0);

    luabind::module(m_LuaState)
    [
        luabind::class_<CharacterData>("CharacterData")
            .def_readwrite("level",         &CharacterData::level)

            .def_readwrite("max_hp",        &CharacterData::max_hp)
            .def_readwrite("current_hp",    &CharacterData::current_hp)
            .def_readwrite("max_mp",        &CharacterData::max_mp)
            .def_readwrite("current_mp",    &CharacterData::current_mp)

            .def_readwrite("attack",        &CharacterData::attack)
            .def_readwrite("defense",       &CharacterData::defense)
            .def_readwrite("magic_attack",  &CharacterData::magic_attack)
            .def_readwrite("magic_defense", &CharacterData::magic_defense)
            .def_readwrite("speed",         &CharacterData::speed)

            .def_readwrite("row",           &CharacterData::row)
    ];



    luabind::module(m_LuaState)
    [
        luabind::class_<FighterData, CharacterData>("FighterData")
            .def_readwrite("relationship",  &FighterData::relationship)

            .def_readwrite("auto_action",   &FighterData::auto_action)
            .def_readwrite("action_idle",   &FighterData::action_idle)
            .def_readwrite("action_hurt",   &FighterData::action_hurt)

            .enum_("constants")
            [
                luabind::value("PLAYER", PLAYER),
                luabind::value("ENEMY",  ENEMY)
            ]
    ];



    luabind::module(m_LuaState)
    [
        luabind::class_<AttackData>("AttackData")
            .def_readwrite("formula", &AttackData::formula)
            .def_readwrite("power",   &AttackData::power)
    ];



    luabind::module(m_LuaState)
    [
        luabind::class_<Fighter>("Fighter")
            .def("play_animation", (int(Fighter::*)(const char*))&Fighter::ScriptPlayAnimation, luabind::yield)
            .def_readwrite("data", &Fighter::data)
    ];



    luabind::module(m_LuaState)
    [
        luabind::class_<BattleModule>("Battle")
            .def("run_command", (void(BattleModule::*)(const BattleActionType, const int))&BattleModule::ScriptRunCommand)

            .enum_("constants")
            [
                luabind::value("MONSTER_ACTION", MONSTER_ACTION),
                luabind::value("DISPLAY_TEXT", DISPLAY_TEXT)
            ]
    ];
    luabind::globals(m_LuaState)["battle"] = boost::ref(*battle);



    luabind::module(m_LuaState)
    [
        luabind::class_<BattleScriptManager>("ScriptManager")
            .def("play_hurt_action", (void(BattleScriptManager::*)(Fighter*, const float))&BattleScriptManager::ScriptPlayHurtAction)
    ];
    luabind::globals(m_LuaState)["script"] = boost::ref(*this);



    BindGameStateToLua(m_LuaState);

    Ogre::LogManager::getSingletonPtr()->logMessage("BattleScriptManager created.");
}



BattleScriptManager::~BattleScriptManager(void)
{
    // we must clear all lua objects before closing lua state
    lua_close(m_LuaState);

    Ogre::LogManager::getSingletonPtr()->logMessage("BattleScriptManager destroyed.");
}



void
BattleScriptManager::Input(const Event& input)
{
}



void
BattleScriptManager::Update(const float delta_time)
{
    lua_gc (m_LuaState, LUA_GCCOLLECT, 0);

    for (int i = 0; i < m_Fighters.size(); ++i)
    {
        if (m_Fighters[i].wait == false)
        {
            m_CurrentFighter = i;
            m_BattleModule->SetVariableForFighter(i);
            SetTableFighter(m_Fighters[i].target, "fighters_target");

            if (m_Fighters[i].yield == false)
            {
                Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT] Start action script '" + m_Fighters[i].action + "' for fighter '" + m_BattleModule->m_Fighters[i]->GetName() + "'.");

                m_Fighters[i].state = lua_newthread(m_LuaState);

                luabind::object table = luabind::globals(m_Fighters[i].state)[m_BattleModule->m_Fighters[i]->GetName()];

                if (luabind::type(table) == LUA_TTABLE && luabind::type(table[m_Fighters[i].action]) == LUA_TFUNCTION)
                {
                    int ret = 0;
                    try
                    {
                        ret = luabind::resume_function<int>(table[m_Fighters[i].action], table);
                    }
                    catch(luabind::error& e)
                    {
                        luabind::object error_msg(luabind::from_stack(e.state(), -1));
                        Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT ERROR] " + Ogre::String(luabind::object_cast<std::string>(error_msg)));
                    }

                    if (ret == 0)
                    {
                        Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT] Script '" + m_Fighters[i].action + "' for fighter '" + m_BattleModule->m_Fighters[i]->GetName() + "' finished.");
                        m_Fighters[i].action = m_BattleModule->m_Fighters[i]->data.action_idle;
                    }
                    else
                    {
                        Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT] Script '" + m_Fighters[i].action + "' for fighter '" + m_BattleModule->m_Fighters[i]->GetName() + "' will be continued later.");
                        m_Fighters[i].wait = true;
                        m_Fighters[i].yield = true;
                    }
                }
                else
                {
                    Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT ERROR] Script '" + m_Fighters[i].action + "' for fighter '" + m_BattleModule->m_Fighters[i]->GetName() + "' doesn't exist.");
                }
            }
            else
            {
                Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT] Continue action '" + m_Fighters[i].action + "' for entity '" + m_BattleModule->m_Fighters[i]->GetName() + "'.");

                int ret = 0;

                try
                {
                    ret = luabind::resume<int>(m_Fighters[i].state);
                }
                catch(luabind::error& e)
                {
                    luabind::object error_msg(luabind::from_stack(e.state(), -1));
                    Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT ERROR] " + Ogre::String(luabind::object_cast<std::string>(error_msg)));
                }

                if (ret == 0)
                {
                    Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT] Script '" + m_Fighters[i].action + "' for fighter '" + m_BattleModule->m_Fighters[i]->GetName() + "' finished.");
                    m_Fighters[i].yield = false;
                    m_Fighters[i].action = m_BattleModule->m_Fighters[i]->data.action_idle;
                }
                else
                {
                    Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT] Script '" + m_Fighters[i].action + "' for fighter '" + m_BattleModule->m_Fighters[i]->GetName() + "' will be continued later.");
                    m_Fighters[i].wait = true;
                }
            }
        }



        if (m_Fighters[i].wait == false && m_Fighters[i].yield == false && m_BattleModule->m_Fighters[i]->data.in_action == true)
        {
            m_BattleModule->m_Fighters[i]->data.timer_wait = false;
            m_BattleModule->m_Fighters[i]->data.in_action = false;
        }



        if (m_Fighters[i].time_to_hurt != 0)
        {
            m_Fighters[i].time_to_hurt -= delta_time;
            if (m_Fighters[i].time_to_hurt <= 0)
            {
                m_Fighters[i].time_to_hurt = 0;
                FighterVector target;
                SetFighterAction(i, m_BattleModule->m_Fighters[i]->data.action_hurt, target);
            }
        }
    }
}



void
BattleScriptManager::ScriptPlayHurtAction(Fighter* target, const float time)
{
    m_Fighters[target->data.fighter_id].time_to_hurt = time;
}



void
BattleScriptManager::LoadFile(const Ogre::String& name)
{
    Ogre::LogManager::getSingletonPtr()->logMessage("Load script file '" + name + "'.");

    if (luaL_dofile(m_LuaState, (Configuration::getSingleton().GetFileRoot() + "battle/model/" + name).c_str()) == 1)
    {
        luabind::object error_msg(luabind::from_stack(m_LuaState, -1));
        Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT ERROR] " + Ogre::String(luabind::object_cast<std::string>(error_msg)));
    }
}



const int
BattleScriptManager::GetCurrentFighter() const
{
    return m_CurrentFighter;
}



void
BattleScriptManager::ContinueFighterAction(const int fighter_id)
{
    m_Fighters[fighter_id].wait = false;
}



void
BattleScriptManager::SetFighterAction(const int fighter_id, const Ogre::String& action, const FighterVector& target)
{
    m_Fighters[fighter_id].action  = action;
    m_Fighters[fighter_id].wait    = false;
    m_Fighters[fighter_id].yield   = false;
    m_Fighters[fighter_id].target  = target;
}



void
BattleScriptManager::ExecuteLogic(const Ogre::String& script, const Ogre::String& function)
{
    Ogre::LogManager::getSingletonPtr()->logMessage("Execute '" + function + "' logic for '" + script + "'.");

    luabind::object table = luabind::globals(m_LuaState)[script];

    if (luabind::type(table) == LUA_TTABLE && luabind::type(table[function]) == LUA_TFUNCTION)
    {
        try
        {
            luabind::call_function<void>(table[function], table);
        }
        catch(luabind::error& e)
        {
            luabind::object error_msg(luabind::from_stack(e.state(), -1));
            Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT ERROR] " + Ogre::String(luabind::object_cast<std::string>(error_msg)));
        }
    }
    else
    {
        Ogre::LogManager::getSingletonPtr()->logMessage("[ERROR] Function '" + function + "' for '" + script + "' not found. '" + script + "' is not table or '" + function + "' is not function.");
    }
}



int
BattleScriptManager::ExecuteDamage(Fighter* attacker, Fighter* target, const AttackData& attack)
{
    Ogre::LogManager::getSingletonPtr()->logMessage("Calculate damage for '" + attacker->GetName() + "' from '" + target->GetName() + "' with function '" + attack.formula + "'.");

    luabind::object function = luabind::globals(m_LuaState)["damage"];

    if (luabind::type(function) == LUA_TFUNCTION)
    {
        try
        {
            return luabind::call_function<float>(function, attacker, target, attack);
        }
        catch(luabind::error& e)
        {
            luabind::object error_msg(luabind::from_stack(e.state(), -1));
            Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT ERROR] " + Ogre::String(luabind::object_cast<std::string>(error_msg)));
        }
    }
    else
    {
        Ogre::LogManager::getSingletonPtr()->logMessage("[ERROR] Function 'damage' not found.");
    }
}



void
BattleScriptManager::SetTableFighter(const FighterVector& fighters, const Ogre::String& name)
{
    luabind::globals(m_LuaState)[name] = luabind::newtable(m_LuaState);
    for (luabind::iterator i(luabind::globals(m_LuaState)[name]), end; i != end; ++i)
    {
        *i = luabind::nil;
    }
    for (int i = 0; i < fighters.size(); ++i)
    {
        luabind::globals(m_LuaState)[name][i + 1] = fighters[i];
    }
}



void
BattleScriptManager::SetFighter(Fighter* fighter, const Ogre::String& name)
{
    luabind::globals(m_LuaState)[name] = boost::ref(*fighter);
}



void
BattleScriptManager::GetTableFighter(FighterVector& fighters, const Ogre::String& name) const
{
    for (luabind::iterator i(luabind::globals(m_LuaState)[name]), end; i != end; ++i)
    {
        fighters.push_back(luabind::object_cast<Fighter*>(*i));
    }
}



void
BattleScriptManager::GetFighter(Fighter*& fighter, const Ogre::String& name) const
{
    fighter = luabind::object_cast<Fighter*>(luabind::globals(m_LuaState)[name]);
}



void
BattleScriptManager::CreateFighterObject(const Ogre::String& table, Fighter* fighter)
{
    Ogre::LogManager::getSingletonPtr()->logMessage("Derive object '" + fighter->GetName() + "' from table '" + table + "'.");

    luabind::object object = luabind::newtable(m_LuaState);
    luabind::globals(m_LuaState)[fighter->GetName()] = object;
    object["meta"] = luabind::newtable(m_LuaState);
    object["meta"]["__index"] = luabind::globals(m_LuaState)[table];
    luabind::setmetatable(object, object["meta"]);

    FighterLua fighter_lua;
    fighter_lua.wait         = false;
    fighter_lua.yield        = false;
    fighter_lua.action       = fighter->data.action_idle;
    fighter_lua.time_to_hurt = 0;
    m_Fighters.push_back(fighter_lua);
}
