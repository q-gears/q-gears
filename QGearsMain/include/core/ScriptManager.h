#ifndef SCRIPT_MANAGER_H
#define SCRIPT_MANAGER_H

#include <OgreSingleton.h>
#include <OgreString.h>

#include "Event.h"
extern "C"
{
    #include <lua/lua.h>
}
#include <luabind/luabind.hpp>

class Entity;



struct ScriptId
{
    ScriptId(): entity( "" ), function( "" ){}

    Ogre::String entity;
    Ogre::String function;
};



struct ScriptEntity;



struct QueueScript
{
    QueueScript():
        function( "" ),
        argument1( "" ),
        argument2( "" ),
        priority( 0 ),
        state( NULL ),
        seconds_to_wait( 0 ),
        wait( false ),
        yield( false )
    {}

    Ogre::String function;
    Ogre::String argument1;
    Ogre::String argument2;
    int priority;
    lua_State* state;
    int state_id; // for storing and deleating thread
    float seconds_to_wait;
    bool wait;
    bool yield;
    ScriptId paused_script_start; // script paused by call of this script.
    ScriptId paused_script_end; // script paused by call of this script.
};



class ScriptManager : public Ogre::Singleton< ScriptManager >
{
public:
    enum Type
    {
        SYSTEM,
        ENTITY,
        UI
    };

    ScriptManager();
    virtual ~ScriptManager();

    void Input( const Event& event );
    void Update( const Type type );

    void RunString( const Ogre::String& lua );
    void RunFile( const Ogre::String& file );

    // binds
    void InitBinds();
    void InitCmd();

    void AddEntity( const Type type, const Ogre::String& entity_name, Entity* entity );
    void RemoveEntity( const Type type, const Ogre::String& entity_name );
    void AddEntityScript( const Ogre::String& entity_name, const Ogre::String& function_name, int priority );
    void RemoveEntityTopScript( ScriptEntity& entity );

    luabind::object GetTableByEntityName( const ScriptManager::Type type, const Ogre::String& name, lua_State* state ) const;
    QueueScript* GetScriptByScriptId( const ScriptId& script ) const;
    ScriptEntity* GetScriptEntityByName( const Type type, const Ogre::String& entity_name ) const;
    const ScriptId GetCurrentScriptId() const;
    void ContinueScriptExecution( const ScriptId& script );

    int ScriptWait( const float seconds );
    void ScriptRequest( const Type type, const char* entity, const char* function, const int priority );
    int ScriptRequestStartSync( const Type type, const char* entity, const char* function, const int priority );
    int ScriptRequestEndSync( const Type type, const char* entity, const char* function, const int priority );
    bool ScriptRequest( ScriptEntity* script_entity, const Ogre::String& function, const int priority, const Ogre::String& argument1, const Ogre::String& argument2, bool start_sync, bool end_sync );

    void AddValueToStack( const float value );

private:
    lua_State* m_LuaState;

    Ogre::String m_SystemTableName;
    Ogre::String m_EntityTableName;
    Ogre::String m_UiTableName;

    std::vector< ScriptEntity > m_ScriptEntity;

    ScriptId m_CurrentScriptId;
};



struct ScriptEntity
{
    ScriptEntity():
        name( "" ),
        type( ScriptManager::SYSTEM ),
        resort( false )
    {
    }

    Ogre::String name;
    ScriptManager::Type type;
    std::vector< QueueScript > queue;
    bool resort;
};



#endif // SCRIPT_MANAGER_H
