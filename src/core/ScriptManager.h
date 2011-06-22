#ifndef SCRIPT_MANAGER_H
#define SCRIPT_MANAGER_H

#include <OgreSingleton.h>
#include <OgreString.h>

extern "C"
{
    #include "library/lua/lua.h"
}
#include "library/luabind/luabind.hpp"

class GameModule;



struct ScriptId
{
    ScriptId(): entity( "" ), function( "" ){}

    Ogre::String entity;
    Ogre::String function;
};





struct QueueScript
{
    QueueScript(): function( "" ), priority( 0 ), state( NULL ), seconds_to_wait( 0 ), wait( false ), yield( false ){}

    Ogre::String function;
    int priority;
    lua_State* state;
    int state_id; // for storing and deleating thread
    float seconds_to_wait;
    bool wait;
    bool yield;
    ScriptId paused_script_start; // script paused by call of this script.
    ScriptId paused_script_end; // script paused by call of this script.
};



struct ScriptEntity
{
    ScriptEntity(): name( "" ), resort( false ){}

    Ogre::String name;
    luabind::object table;
    std::vector< QueueScript > queue;
    bool resort;
};



class ScriptManager : public Ogre::Singleton< ScriptManager >
{
public:
    ScriptManager();
    virtual ~ScriptManager();

    void Update();

    void RunString( const Ogre::String& lua );
    void RunFile( const Ogre::String& file );

    // binds
    void InitBinds();
    void InitCmd();

    void AddEntity( const Ogre::String& entity_name );
    void RemoveEntity( const Ogre::String& entity_name );
    void AddEntityScript( const Ogre::String& entity_name, const Ogre::String& function_name, int priority );
    void RemoveEntityTopScript( ScriptEntity& entity );

    QueueScript* GetScriptByScriptId( const ScriptId& script ) const;
    ScriptEntity* GetScriptEntityByName( const Ogre::String& name ) const;
    const ScriptId GetCurrentScriptId() const;
    void ContinueScriptExecution( const ScriptId& script );

    int ScriptWait( const float seconds );
    void ScriptRequest( const char* entity, const char* function, const int priority );
    int ScriptRequestStartSync( const char* entity, const char* function, const int priority );
    int ScriptRequestEndSync( const char* entity, const char* function, const int priority );

private:
    lua_State* m_LuaState;

    std::vector< ScriptEntity > m_ScriptEntity;
    ScriptId m_CurrentScriptId;
};



#endif // SCRIPT_MANAGER_H
