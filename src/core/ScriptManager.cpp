#include "ScriptManager.h"
#include "ScriptManagerBinds.h"
#include "ScriptManagerCommands.h"

#include "ConfigVar.h"
#include "DebugDraw.h"
#include "Logger.h"
#include "Timer.h"
#include "Utilites.h"
extern "C"
{
    #include "library/lua/lua.h"
    #include "library/lua/lualib.h"
    #include "library/lua/lauxlib.h"
}
#include "library/luabind/luabind.hpp"
#include "library/luabind/yield_policy.hpp"



ConfigVar cv_debug_script( "debug_script", "Debug script", "false" );



bool
priority_queue_compare( QueueScript a, QueueScript b )
{
    return a.priority < b.priority;
}



template<>ScriptManager *Ogre::Singleton< ScriptManager >::ms_Singleton = NULL;



ScriptManager::ScriptManager()
{
    LOG_TRIVIAL( "ScriptManager started." );

    m_LuaState = lua_open();
    luabind::open( m_LuaState );
    luaopen_base( m_LuaState );
    luaopen_string( m_LuaState );
    luaopen_table( m_LuaState );
    luaopen_math( m_LuaState );

    InitBinds();
    InitCmd();
}



ScriptManager::~ScriptManager()
{
    lua_close( m_LuaState );

    LOG_TRIVIAL( "ScriptManager closed." );
}



void
ScriptManager::Update()
{
    for( int i = 0; i < m_ScriptEntity.size(); ++i )
    {
        if( m_ScriptEntity[ i ].queue.size() > 0 )
        {
            if( m_ScriptEntity[ i ].resort == true )
            {
                std::stable_sort( m_ScriptEntity[ i ].queue.begin(), m_ScriptEntity[ i ].queue.end(), priority_queue_compare );
                m_ScriptEntity[ i ].resort = false;
            }

            QueueScript* current_script = &( m_ScriptEntity[ i ].queue[ 0 ] );

            m_CurrentScriptId.entity = m_ScriptEntity[ i ].name;
            m_CurrentScriptId.function = current_script->function;

            if( current_script->wait == false )
            {
                if( current_script->yield == false)
                {
                    LOG_TRIVIAL( "[SCRIPT] Start script '" + current_script->function + "' for entity '" + m_CurrentScriptId.entity + "'." );

                    if( current_script->paused_script_start.entity != "" )
                    {
                        ContinueScriptExecution( current_script->paused_script_start );
                        current_script->paused_script_start.entity = "";
                    }

                    if( m_ScriptEntity[ i ].table.is_valid() &&
                        luabind::type( m_ScriptEntity[ i ].table ) == LUA_TTABLE &&
                        luabind::type( m_ScriptEntity[ i ].table[ current_script->function ] ) == LUA_TFUNCTION )
                    {
                        int ret = 0;

                        try
                        {
                            ret = luabind::resume_function< int >( m_ScriptEntity[ i ].table[ current_script->function ], m_ScriptEntity[ i ].table );
                        }
                        catch( luabind::error& e )
                        {
                            luabind::object error_msg( luabind::from_stack( e.state(), -1 ) );
                            LOG_WARNING( Ogre::String( luabind::object_cast< std::string >( error_msg ) ) );
                        }

                        if( ret == 0 )
                        {
                            LOG_TRIVIAL( "[SCRIPT] Script '" + current_script->function + "' for entity '" + m_CurrentScriptId.entity + "' finished." );
                            RemoveEntityTopScript( m_ScriptEntity[ i ] );
                        }
                        else if( ret == 1 )
                        {
                            LOG_TRIVIAL( "[SCRIPT] Script '" + current_script->function + "' for entity '" + m_CurrentScriptId.entity + "' not paused and will be continued next cycle." );
                            current_script->yield = true;
                        }
                        else
                        {
                            LOG_TRIVIAL( "[SCRIPT] Script '" + current_script->function + "' for entity '" + m_CurrentScriptId.entity + "' not finished yet." );
                            current_script->yield = true;
                            current_script->wait = true;
                        }
                    }
                    else
                    {
                        LOG_WARNING( "Script '" + current_script->function + "' for entity '" + m_CurrentScriptId.entity + "' doesn't exist." );
                        RemoveEntityTopScript( m_ScriptEntity[ i ] );
                    }
                }
                else
                {
                    LOG_TRIVIAL( "[SCRIPT] Continue function '" + current_script->function + "' for entity '" + m_CurrentScriptId.entity + "'." );

                    int ret = 0;

                    try
                    {
                        ret = luabind::resume< int >( current_script->state );
                    }
                    catch( luabind::error& e )
                    {
                        luabind::object error_msg( luabind::from_stack( e.state(), -1 ) );
                        LOG_WARNING( Ogre::String( luabind::object_cast< std::string >( error_msg ) ) );
                    }

                    if( ret == 0 ) // finished
                    {
                        LOG_TRIVIAL( "[SCRIPT] Script '" + current_script->function + "' for entity '" + m_CurrentScriptId.entity + "' finished." );
                        RemoveEntityTopScript( m_ScriptEntity[ i ] );
                    }
                    else if (ret == 1)
                    {
                        LOG_TRIVIAL( "[SCRIPT] Script '" + current_script->function + "' for entity '" + m_CurrentScriptId.entity + "' not paused and will be continued next cycle." );
                    }
                    else
                    {
                        LOG_TRIVIAL( "[SCRIPT] Script '" + current_script->function + "' for entity '" + m_CurrentScriptId.entity + "' not finished yet." );
                        current_script->wait = true;
                    }
                }
            }
            else if( current_script->seconds_to_wait > 0 )
            {
                current_script->seconds_to_wait -= Timer::getSingleton().GetGameTimeDelta();
                current_script->seconds_to_wait = ( current_script->seconds_to_wait < 0 ) ? 0 : current_script->seconds_to_wait;

                if( current_script->seconds_to_wait == 0 )
                {
                    current_script->wait = false;
                }
            }
        }
    }



    if( cv_debug_script.GetB() == true )
    {
        DEBUG_DRAW.SetTextAlignment( DEBUG_DRAW.LEFT );
        DEBUG_DRAW.SetScreenSpace( true );
        DEBUG_DRAW.SetColour( 0.8, 0.8, 0, 1 );
        DEBUG_DRAW.Text( 10, 34, "Script entity:" );

        for( int i = 0; i < m_ScriptEntity.size(); ++i )
        {
            DEBUG_DRAW.SetColour( 0.5, 0.5, 0.5, 1 );
            Ogre::String text = m_ScriptEntity[ i ].name + ": ";

            if( m_ScriptEntity[ i ].queue.size() > 0 )
            {
                text += m_ScriptEntity[ i ].queue[ 0 ].function;

                if( m_ScriptEntity[ i ].queue[ 0 ].wait == true )
                {
                    DEBUG_DRAW.SetColour( 0.8, 0.8, 0, 1 );
                    if( m_ScriptEntity[ i ].queue[ 0 ].seconds_to_wait != 0 )
                    {
                        text += ":wait( " + Ogre::StringConverter::toString( m_ScriptEntity[ i ].queue[ 0 ].seconds_to_wait ) + " )";
                    }
                }
            }

            DEBUG_DRAW.Text( 20, 50 + i * 16, text );
        }
    }
}



void
ScriptManager::RunString( const Ogre::String& lua )
{
    if( luaL_dostring( m_LuaState, lua.c_str() ) == 1 )
    {
        luabind::object error_msg( luabind::from_stack( m_LuaState, -1 ) );
        LOG_WARNING( Ogre::String( luabind::object_cast< std::string >( error_msg ) ) );
    }
}



void
ScriptManager::RunFile( const Ogre::String& file )
{
    if( luaL_dofile( m_LuaState, ( "data/" + file ).c_str() ) == 1 )
    {
        luabind::object error_msg( luabind::from_stack( m_LuaState, -1 ) );
        LOG_WARNING( Ogre::String( luabind::object_cast< std::string >( error_msg ) ) );
    }
}



void
ScriptManager::AddEntity( const Ogre::String& entity_name )
{
    for( int i = 0; i < m_ScriptEntity.size(); ++i )
    {
        if( m_ScriptEntity[ i ].name == entity_name )
        {
            LOG_WARNING( "Script entity \"" + entity_name + "\" already exist in script manager." );
            return;
        }
    }

    ScriptEntity script_entity;
    script_entity.name = entity_name;

    QueueScript script;
    script.function = "on_start";
    script.priority = 0;
    script.state = lua_newthread( m_LuaState );
    // we dont want thread to be garbage collected so we store it
    script.state_id = luaL_ref( m_LuaState, LUA_REGISTRYINDEX );
    script.seconds_to_wait = 0;
    script.wait = false;
    script.yield = false;
    script_entity.queue.push_back( script );

    Ogre::StringVector table_path = StringTokenise( entity_name, "." );
    luabind::object table = luabind::globals( script.state );
    for( int i = 0; i < table_path.size(); ++i )
    {
        table = table[ table_path[ i ] ];

        if( luabind::type( table ) == LUA_TTABLE )
        {
            script_entity.table = table;
        }
        else
        {
            LOG_WARNING( "Script entity \"" + entity_name + "\" try use table \"" + table_path[ i ] + "\" which is not a table. Table will not be added and entity won't work." );
            script_entity.table = luabind::object();
            break;
        }
    }

    m_ScriptEntity.push_back( script_entity );
}



void
ScriptManager::RemoveEntity( const Ogre::String& entity_name )
{
    for( int i = 0; i < m_ScriptEntity.size(); ++i )
    {
        if( m_ScriptEntity[ i ].name == entity_name )
        {
            while( m_ScriptEntity[ i ].queue.size() > 0 )
            {
                ScriptManager::RemoveEntityTopScript( m_ScriptEntity[ i ] );
            }

            m_ScriptEntity.erase( m_ScriptEntity.begin() + i );

            return;
        }
    }

    LOG_WARNING( "Entity \"" + entity_name + "\" not found in script manager." );
}



void
ScriptManager::RemoveEntityTopScript( ScriptEntity& entity )
{
    if( entity.queue.size() > 0 )
    {
        // delete thread
        luaL_unref( m_LuaState, LUA_REGISTRYINDEX, entity.queue[ 0 ].state_id );

        if( entity.queue[ 0 ].paused_script_end.entity != "" )
        {
            ContinueScriptExecution( entity.queue[ 0 ].paused_script_end );
            entity.queue[ 0 ].paused_script_end.entity = "";
        }

        entity.queue.erase( entity.queue.begin() );
    }
}



QueueScript*
ScriptManager::GetScriptByScriptId( const ScriptId& script ) const
{
    for(int i = 0; i < m_ScriptEntity.size(); ++i )
    {
        if( script.entity == m_ScriptEntity[ i ].name )
        {
            for( int j = 0; j < m_ScriptEntity[ i ].queue.size(); ++j )
            {
                if( script.function == m_ScriptEntity[ i ].queue[ j ].function )
                {
                    return (QueueScript*) &( m_ScriptEntity[ i ].queue[ j ] );
                }
            }

            return NULL;
        }
    }

    return NULL;
}



ScriptEntity*
ScriptManager::GetScriptEntityByName( const Ogre::String& name ) const
{
    for(int i = 0; i < m_ScriptEntity.size(); ++i )
    {
        if( name == m_ScriptEntity[ i ].name )
        {
            return (ScriptEntity*) &( m_ScriptEntity[ i ] );
        }
    }

    return NULL;
}



const ScriptId
ScriptManager::GetCurrentScriptId() const
{
    return m_CurrentScriptId;
}



void
ScriptManager::ContinueScriptExecution( const ScriptId& script )
{
    QueueScript* script_pointer = GetScriptByScriptId( script );

    if( script_pointer == NULL )
    {
        LOG_ERROR( "There is no script \"" + script.function + "\" for entity \"" + script.entity + "\". Can't continue script execution." );
        return;
    }

    script_pointer->wait = false;
}



int
ScriptManager::ScriptWait( const float seconds )
{
    LOG_TRIVIAL( "script:wait: We set script wait for " + Ogre::StringConverter::toString( seconds ) + " seconds." );

    QueueScript* script = GetScriptByScriptId( m_CurrentScriptId );

    if( script == NULL )
    {
        LOG_ERROR( "script:wait: Currently no any script running." );
        return 1;
    }

    if( seconds == 0 )
    {
        return 1;
    }

    script->seconds_to_wait = seconds;

    return -1;
}



void
ScriptManager::ScriptRequest( const char* entity, const char* function, const int priority )
{
    LOG_TRIVIAL( "[SCRIPT] script:request: Request function \"" + Ogre::String( function ) + "\" for entity \"" + Ogre::String( entity ) + "\" with priority " + Ogre::StringConverter::toString( priority ) + "." );

    ScriptEntity* script_entity = GetScriptEntityByName( Ogre::String( entity ) );

    if( script_entity == NULL )
    {
        LOG_ERROR( "[SCRIPT] script:request: Entity \"" + Ogre::String( entity ) + "\" doesn't exist." );
        return;
    }

    QueueScript script;
    script.function = function;
    script.priority = priority;
    script.state = lua_newthread( m_LuaState );
    // we dont want thread to be garbage collected so we store it
    script.state_id = luaL_ref( m_LuaState, LUA_REGISTRYINDEX );
    script_entity->queue.push_back( script );
    script_entity->resort = true;
}



int
ScriptManager::ScriptRequestStartSync( const char* entity, const char* function, const int priority )
{
    LOG_TRIVIAL( "[SCRIPT] script:request_start_sync: Request function \"" + Ogre::String( function ) + "\" for entity \"" + Ogre::String( entity ) + "\" with priority " + Ogre::StringConverter::toString( priority ) + "." );

    ScriptEntity* script_entity = GetScriptEntityByName( Ogre::String( entity ) );

    if( script_entity == NULL )
    {
        LOG_ERROR( "[SCRIPT] script:request_start_sync: Entity \"" + Ogre::String( entity ) + "\" doesn't exist." );
        return 1;
    }

    QueueScript script;
    script.function = function;
    script.priority = priority;
    script.state = lua_newthread( m_LuaState );
    // we dont want thread to be garbage collected so we store it
    script.state_id = luaL_ref( m_LuaState, LUA_REGISTRYINDEX );
    script.paused_script_start = GetCurrentScriptId();
    script_entity->queue.push_back( script );
    script_entity->resort = true;

    return -1;
}



int
ScriptManager::ScriptRequestEndSync( const char* entity, const char* function, const int priority )
{
    LOG_TRIVIAL( "[SCRIPT] script:request_end_sync: Request function \"" + Ogre::String( function ) + "\" for entity \"" + Ogre::String( entity ) + "\" with priority " + Ogre::StringConverter::toString( priority ) + "." );

    ScriptEntity* script_entity = GetScriptEntityByName( Ogre::String( entity ) );

    if( script_entity == NULL )
    {
        LOG_ERROR( "[SCRIPT] script:request_end_sync: Entity \"" + Ogre::String( entity ) + "\" doesn't exist." );
        return 1;
    }

    QueueScript script;
    script.function = function;
    script.priority = priority;
    script.state = lua_newthread( m_LuaState );
    // we dont want thread to be garbage collected so we store it
    script.state_id = luaL_ref( m_LuaState, LUA_REGISTRYINDEX );
    script.paused_script_end = GetCurrentScriptId();
    script_entity->queue.push_back( script );
    script_entity->resort = true;

    return -1;
}
