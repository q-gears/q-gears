#include "core/ConfigVar.h"
#include "core/DebugDraw.h"
#include "core/Logger.h"
#include "core/ScriptManager.h"
#include "core/ScriptManagerBinds.h"
#include "core/ScriptManagerCommands.h"
#include "core/Timer.h"
#include "core/Utilites.h"
#include "core/XmlScriptsFile.h"
#include "LuaIncludes.h"


ConfigVar cv_debug_script("debug_script", "Debug script flags. 0x01 - System, 0x02 - Entity, 0x04 - Ui.", "0");
template<>ScriptManager *Ogre::Singleton<ScriptManager>::msSingleton = nullptr;
Ogre::String script_entity_type[] = {"SYSTEM", "ENTITY", "UI"};


bool
priority_queue_compare(QueueScript a, QueueScript b)
{
    return a.priority < b.priority;
}


ScriptManager::ScriptManager():
    m_SystemTableName("System"),
    m_EntityTableName("EntityContainer"),
    m_UiTableName("UiContainer")
{
    LOG_TRIVIAL("ScriptManager started.");

    m_LuaState = lua_open();
    luabind::open(m_LuaState);
    luaopen_base(m_LuaState);
    luaopen_string(m_LuaState);
    luaopen_table(m_LuaState);
    luaopen_math(m_LuaState);

    InitBinds();
    InitCmd();

    RunFile("system/system.lua");

    XmlScriptsFile scripts("./data/scripts.xml");
    scripts.LoadScripts();
}


ScriptManager::~ScriptManager()
{
    lua_close(m_LuaState);

    LOG_TRIVIAL("ScriptManager closed.");
}


void
ScriptManager::Input(const QGears::Event& event)
{
    if ((event.type == QGears::ET_KEY_PRESS || event.type == QGears::ET_KEY_REPEAT_WAIT) &&
                                      (
                                        event.param1 == OIS::KC_RETURN ||
                                        event.param1 == OIS::KC_ESCAPE ||
                                        event.param1 == OIS::KC_SPACE ||
                                        event.param1 == OIS::KC_LCONTROL ||
                                        event.param1 == OIS::KC_LEFT ||
                                        event.param1 == OIS::KC_RIGHT ||
                                        event.param1 == OIS::KC_DOWN ||
                                        event.param1 == OIS::KC_UP
                                     ))
    {
        for(unsigned int i = 0; i < m_ScriptEntity.size(); ++i)
        {
            Ogre::String argument2 = "";
            if (event.type == QGears::ET_KEY_PRESS)
            {
                argument2 = "Press";
            }
            else if (event.type == QGears::ET_KEY_REPEAT_WAIT)
            {
                argument2 = "Repeat";
            }
            ScriptRequest(&m_ScriptEntity[i], "on_button", 100, KeyToString((OIS::KeyCode)((int)event.param1)), argument2, false, false);
        }
    }
}


void
ScriptManager::Update(const ScriptManager::Type type)
{
    // resort all queue. This will give us correct info for debug draw.
    for(unsigned int i = 0; i < m_ScriptEntity.size(); ++i)
    {
        if(m_ScriptEntity[i].type == type)
        {
            if(m_ScriptEntity[i].queue.size() > 0)
            {
                if(m_ScriptEntity[i].resort == true)
                {
                    std::stable_sort(m_ScriptEntity[i].queue.begin(), m_ScriptEntity[i].queue.end(), priority_queue_compare);
                    m_ScriptEntity[i].resort = false;
                }
            }
        }
    }

    // draw debug before update. This way it will be posible to see scripts that run once
    int debug = cv_debug_script.GetI();
    if(debug != 0)
    {
        DEBUG_DRAW.SetTextAlignment(DEBUG_DRAW.LEFT);
        DEBUG_DRAW.SetScreenSpace(true);
        int y = 34;

        for(unsigned int i = 0; i < 3; ++i)
        {
            if((debug & (1 << i)) != 0)
            {
                DEBUG_DRAW.SetColour(Ogre::ColourValue(0.8f, 0.8f, 0.0f, 1.0f));
                DEBUG_DRAW.Text(10.0f, static_cast<float>(y), "Script \"" + script_entity_type[i] + "\" entity:");
                y += 16;

                for(unsigned int j = 0; j < m_ScriptEntity.size(); ++j)
                {
                    if(m_ScriptEntity[j].type == i)
                    {
                        Ogre::String text = m_ScriptEntity[j].name;

                        unsigned int queue_size = m_ScriptEntity[j].queue.size();
                        if(queue_size > 0)
                        {
                            text += ": ";
                            DEBUG_DRAW.SetColour(Ogre::ColourValue(0.8f, 0.8f, 0.0f, 1.0f));
                        }
                        else
                        {
                            DEBUG_DRAW.SetColour(Ogre::ColourValue(0.5, 0.5, 0.5, 1));
                        }
                        for(unsigned int k = 0; k < queue_size; ++k)
                        {
                            if(k > 0)
                            {
                                text += ", ";
                            }
                            text += "(" + Ogre::StringConverter::toString(m_ScriptEntity[j].queue[k].priority) + ")" + m_ScriptEntity[j].queue[k].function;

                            if(m_ScriptEntity[j].queue[k].wait == true)
                            {
                                if(m_ScriptEntity[j].queue[k].seconds_to_wait != 0)
                                {
                                    text += ":wait(" + Ogre::StringConverter::toString(m_ScriptEntity[j].queue[k].seconds_to_wait) + ")";
                                }
                            }
                        }

                        DEBUG_DRAW.Text(20.0f, static_cast<float>(y), text);
                        y += 16;
                    }
                }
            }
        }
    }

    for(unsigned int i = 0; i < m_ScriptEntity.size(); ++i)
    {
        if(m_ScriptEntity[i].type == type)
        {
            if(m_ScriptEntity[i].queue.size() > 0)
            {
                m_CurrentScriptId.entity = m_ScriptEntity[i].name;
                m_CurrentScriptId.function = m_ScriptEntity[i].queue[0].function;

                if(m_ScriptEntity[i].queue[0].wait == false)
                {
                    if(m_ScriptEntity[i].queue[0].yield == false)
                    {
                        LOG_TRIVIAL("[SCRIPT] Start script \"" + m_CurrentScriptId.function + "\" for entity \"" + m_CurrentScriptId.entity + "\".");

                        if(m_ScriptEntity[i].queue[0].paused_script_start.entity != "")
                        {
                            ContinueScriptExecution(m_ScriptEntity[i].queue[0].paused_script_start);
                            m_ScriptEntity[i].queue[0].paused_script_start.entity = "";
                        }

                        luabind::object table = GetTableByEntityName(type, m_CurrentScriptId.entity, m_ScriptEntity[i].queue[0].state);

                        if(table.is_valid() &&
                            luabind::type(table) == LUA_TTABLE &&
                            luabind::type(table[m_CurrentScriptId.function]) == LUA_TFUNCTION)
                        {
                            int ret = 0;

                            try
                            {
                                ret = luabind::resume_function< int >(table[m_CurrentScriptId.function], table, m_ScriptEntity[i].queue[0].argument1.c_str(), m_ScriptEntity[i].queue[0].argument2.c_str());
                            }
                            catch(luabind::error& /*e*/)
                            {
                                LOG_ERROR(Ogre::String(lua_tostring(m_ScriptEntity[i].queue[0].state , -1)));
                            }

                            if(ret == 0)
                            {
                                LOG_TRIVIAL("[SCRIPT] Script \"" + m_CurrentScriptId.function + "\" for entity \"" + m_CurrentScriptId.entity + "\" finished.");
                                if(m_ScriptEntity[i].queue[0].function != "on_update")
                                {
                                    RemoveEntityTopScript(m_ScriptEntity[i]);
                                }
                            }
                            else if(ret == 1)
                            {
                                LOG_TRIVIAL("[SCRIPT] Script \"" + m_CurrentScriptId.function + "\" for entity \"" + m_CurrentScriptId.entity + "\" not paused and will be continued next cycle.");
                                m_ScriptEntity[i].queue[0].yield = true;
                            }
                            else
                            {
                                LOG_TRIVIAL("[SCRIPT] Script \"" + m_CurrentScriptId.function + "\" for entity \"" + m_CurrentScriptId.entity + "\" not finished yet.");
                                m_ScriptEntity[i].queue[0].yield = true;
                                m_ScriptEntity[i].queue[0].wait = true;
                            }
                        }
                        else
                        {
                            LOG_WARNING("Script \"" + m_CurrentScriptId.function + "\" for entity \"" + m_CurrentScriptId.entity + "\" doesn't exist.");
                            RemoveEntityTopScript(m_ScriptEntity[i]);
                        }
                    }
                    else
                    {
                        LOG_TRIVIAL("[SCRIPT] Continue function \"" + m_CurrentScriptId.function + "\" for entity \"" + m_CurrentScriptId.entity + "\".");

                        int ret = 0;

                        try
                        {
                            ret = luabind::resume< int >(m_ScriptEntity[i].queue[0].state);
                        }
                        catch(luabind::error& e)
                        {
                            luabind::object error_msg(luabind::from_stack(e.state(), -1));
                            LOG_WARNING(Ogre::String(luabind::object_cast< std::string >(error_msg)));
                        }

                        if(ret == 0) // finished
                        {
                            LOG_TRIVIAL("[SCRIPT] Script \"" + m_CurrentScriptId.function + "\" for entity \"" + m_CurrentScriptId.entity + "\" finished.");

                            // stop yield for on_update
                            m_ScriptEntity[i].queue[0].yield = false;

                            if(m_ScriptEntity[i].queue[0].function != "on_update")
                            {
                                RemoveEntityTopScript(m_ScriptEntity[i]);
                            }
                        }
                        else if(ret == 1)
                        {
                            LOG_TRIVIAL("[SCRIPT] Script \"" + m_CurrentScriptId.function + "\" for entity \"" + m_CurrentScriptId.entity + "\" not paused and will be continued next cycle.");
                        }
                        else
                        {
                            LOG_TRIVIAL("[SCRIPT] Script \"" + m_CurrentScriptId.function + "\" for entity \"" + m_CurrentScriptId.entity + "\" not finished yet.");
                            m_ScriptEntity[i].queue[0].wait = true;
                        }
                    }
                }
                else if(m_ScriptEntity[i].queue[0].seconds_to_wait > 0)
                {
                    m_ScriptEntity[i].queue[0].seconds_to_wait -= Timer::getSingleton().GetGameTimeDelta();
                    m_ScriptEntity[i].queue[0].seconds_to_wait = (m_ScriptEntity[i].queue[0].seconds_to_wait < 0) ? 0 : m_ScriptEntity[i].queue[0].seconds_to_wait;

                    if(m_ScriptEntity[i].queue[0].seconds_to_wait == 0)
                    {
                        m_ScriptEntity[i].queue[0].wait = false;
                    }
                }
            }
        }
    }
}


void
ScriptManager::RunString(const Ogre::String& lua)
{
    int preEvalIndex = lua_gettop(m_LuaState);
    if(luaL_dostring(m_LuaState, lua.c_str()) == 1)
    {
        LOG_ERROR(Ogre::String(lua_tostring(m_LuaState, -1)));
    }
    else
    {
        int index = lua_gettop(m_LuaState);
        if (index > 0 && index != preEvalIndex)
        {
            auto str = lua_tostring(m_LuaState, index);
            LOG_CONSOLE(str != nullptr ? str : "(nullptr; try tostring(...)?)");
            lua_pop(m_LuaState, 1);
        }
    }
}


void
ScriptManager::RunFile(const Ogre::String& file)
{
    if(luaL_dofile(m_LuaState, ("./data/" + file).c_str()) == 1)
    {
        LOG_ERROR(Ogre::String(lua_tostring(m_LuaState, -1)));
    }
}


void
ScriptManager::AddEntity(const ScriptManager::Type type, const Ogre::String& entity_name, Entity* entity)
{
    for(unsigned int i = 0; i < m_ScriptEntity.size(); ++i)
    {
        if(m_ScriptEntity[i].type == type && m_ScriptEntity[i].name == entity_name)
        {
            LOG_ERROR("Script \"" + script_entity_type[type] + "\" entity \"" + entity_name + "\" already exist in script manager.");
            return;
        }
    }

    luabind::object table = GetTableByEntityName(type, entity_name, m_LuaState);

    if(table.is_valid() && luabind::type(table) == LUA_TTABLE)
    {
        ScriptEntity script_entity;
        script_entity.name = entity_name;
        script_entity.type = type;

        // init entity field for model entity
        if(entity != nullptr)
        {
            table["entity"] = boost::ref(*entity);
        }

        // check "on_start" script
        if(luabind::type(table["on_start"]) == LUA_TFUNCTION)
        {
            QueueScript script;
            script.function = "on_start";
            script.priority = 1;
            script.state = lua_newthread(m_LuaState);
            // we dont want thread to be garbage collected so we store it
            script.state_id = luaL_ref(m_LuaState, LUA_REGISTRYINDEX);
            script.seconds_to_wait = 0;
            script.wait = false;
            script.yield = false;
            script_entity.queue.push_back(script);
        }

        // check "on_update" script
        if(luabind::type(table["on_update"]) == LUA_TFUNCTION)
        {
            QueueScript script;
            script.function = "on_update";
            script.priority = 999;
            script.state = lua_newthread(m_LuaState);
            // we dont want thread to be garbage collected so we store it
            script.state_id = luaL_ref(m_LuaState, LUA_REGISTRYINDEX);
            script.seconds_to_wait = 0;
            script.wait = false;
            script.yield = false;
            script_entity.queue.push_back(script);
        }

        m_ScriptEntity.push_back(script_entity);
    }
}


void
ScriptManager::RemoveEntity(const ScriptManager::Type type, const Ogre::String& entity_name)
{
    for(unsigned int i = 0; i < m_ScriptEntity.size(); ++i)
    {
        if(m_ScriptEntity[i].type == type && m_ScriptEntity[i].name == entity_name)
        {
            while(m_ScriptEntity[i].queue.size() > 0)
            {
                ScriptManager::RemoveEntityTopScript(m_ScriptEntity[i]);
            }

            m_ScriptEntity.erase(m_ScriptEntity.begin() + i);

            return;
        }
    }
}


void
ScriptManager::RemoveEntityTopScript(ScriptEntity& entity)
{
    if(entity.queue.size() > 0)
    {
        // delete thread
        luaL_unref(m_LuaState, LUA_REGISTRYINDEX, entity.queue[0].state_id);

        if(entity.queue[0].paused_script_end.entity != "")
        {
            ContinueScriptExecution(entity.queue[0].paused_script_end);
            entity.queue[0].paused_script_end.entity = "";
        }

        entity.queue.erase(entity.queue.begin());
    }
}


luabind::object
ScriptManager::GetTableByEntityName(const ScriptManager::Type type, const Ogre::String& name, lua_State* state) const
{
    // get real table by name
    Ogre::StringVector table_path = StringTokenise(name, ".");
    luabind::object table = luabind::globals(state);

    switch(type)
    {
        case ScriptManager::SYSTEM: table = table[m_SystemTableName]; break;
        case ScriptManager::ENTITY: table = table[m_EntityTableName]; break;
        case ScriptManager::UI: table = table[m_UiTableName]; break;
    }

    if(luabind::type(table) != LUA_TTABLE)
    {
        return luabind::object();
    }

    for(unsigned int i = 0; i < table_path.size(); ++i)
    {
        table = table[table_path[i]];
        if(luabind::type(table) != LUA_TTABLE)
        {
            return luabind::object();
        }
    }

    return table;
}


QueueScript*
ScriptManager::GetScriptByScriptId(const ScriptId& script) const
{
    for(unsigned int i = 0; i < m_ScriptEntity.size(); ++i)
    {
        if(script.entity == m_ScriptEntity[i].name)
        {
            for(unsigned int j = 0; j < m_ScriptEntity[i].queue.size(); ++j)
            {
                if(script.function == m_ScriptEntity[i].queue[j].function)
                {
                    return (QueueScript*) &(m_ScriptEntity[i].queue[j]);
                }
            }

            return nullptr;
        }
    }

    return nullptr;
}


ScriptEntity*
ScriptManager::GetScriptEntityByName(const Type type, const Ogre::String& entity_name) const
{
    for(unsigned int i = 0; i < m_ScriptEntity.size(); ++i)
    {
        if(m_ScriptEntity[i].type == type && m_ScriptEntity[i].name == entity_name)
        {
            return (ScriptEntity*) &(m_ScriptEntity[i]);
        }
    }

    return nullptr;
}


const ScriptId
ScriptManager::GetCurrentScriptId() const
{
    return m_CurrentScriptId;
}


void
ScriptManager::ContinueScriptExecution(const ScriptId& script)
{
    QueueScript* script_pointer = GetScriptByScriptId(script);

    if(script_pointer == nullptr)
    {
        LOG_ERROR("There is no script \"" + script.function + "\" for entity \"" + script.entity + "\". Can't continue script execution.");
        return;
    }

    script_pointer->wait = false;
}


int
ScriptManager::ScriptWait(const float seconds)
{
    LOG_TRIVIAL("script:wait: We set script wait for " + Ogre::StringConverter::toString(seconds) + " seconds.");

    QueueScript* script = GetScriptByScriptId(m_CurrentScriptId);

    if(script == nullptr)
    {
        LOG_ERROR("script:wait: Currently no any script running.");
        return 1;
    }

    if(seconds == 0)
    {
        return 1;
    }

    script->seconds_to_wait = seconds;

    return -1;
}


void
ScriptManager::ScriptRequest(const Type type, const char* entity, const char* function, const int priority)
{
    LOG_TRIVIAL("[SCRIPT] script:request: Request function \"" + Ogre::String(function) + "\" for entity \"" + Ogre::String(entity) + "\" with priority " + Ogre::StringConverter::toString(priority) + ".");

    ScriptEntity* script_entity = GetScriptEntityByName(type, Ogre::String(entity));

    if(script_entity == nullptr)
    {
        LOG_WARNING("[SCRIPT] script:request: Entity \"" + Ogre::String(entity) + "\" doesn't exist.");
        return;
    }

    bool added = ScriptRequest(script_entity, function, priority, "", "", false, false);

    if(added == false)
    {
        LOG_WARNING("Script '" + Ogre::String(function) + "' for entity '" +  Ogre::String(entity) + "' doesn't exist.");
    }
}


int
ScriptManager::ScriptRequestStartSync(const Type type, const char* entity, const char* function, const int priority)
{
    LOG_TRIVIAL("[SCRIPT] script:request_start_sync: Request function \"" + Ogre::String(function) + "\" for entity \"" + Ogre::String(entity) + "\" with priority " + Ogre::StringConverter::toString(priority) + ".");

    ScriptEntity* script_entity = GetScriptEntityByName(type, Ogre::String(entity));

    if(script_entity == nullptr)
    {
        LOG_ERROR("[SCRIPT] script:request_start_sync: Entity \"" + Ogre::String(entity) + "\" doesn't exist.");
        return 1;
    }

    bool added = ScriptRequest(script_entity, function, priority, "", "", true, false);

    if(added == false)
    {
        LOG_WARNING("Script '" + Ogre::String(function) + "' for entity '" +  Ogre::String(entity) + "' doesn't exist.");
        return 1;
    }

    return -1;
}


int
ScriptManager::ScriptRequestEndSync(const Type type, const char* entity, const char* function, const int priority)
{
    LOG_TRIVIAL("[SCRIPT] script:request_end_sync: Request function \"" + Ogre::String(function) + "\" for entity \"" + Ogre::String(entity) + "\" with priority " + Ogre::StringConverter::toString(priority) + ".");

    ScriptEntity* script_entity = GetScriptEntityByName(type, Ogre::String(entity));

    if(script_entity == nullptr)
    {
        LOG_ERROR("[SCRIPT] script:request_end_sync: Entity \"" + Ogre::String(entity) + "\" doesn't exist.");
        return 1;
    }

    bool added = ScriptRequest(script_entity, function, priority, "", "", false, true);

    if(added == false)
    {
        LOG_WARNING("Script '" + Ogre::String(function) + "' for entity '" +  Ogre::String(entity) + "' doesn't exist.");
        return 1;
    }

    return -1;
}


bool
ScriptManager::ScriptRequest(ScriptEntity* script_entity, const Ogre::String& function, const int priority, const Ogre::String& argument1, const Ogre::String& argument2, bool start_sync, bool end_sync)
{
    luabind::object table = GetTableByEntityName(script_entity->type, script_entity->name, m_LuaState);
    if(table.is_valid() && luabind::type(table) == LUA_TTABLE && luabind::type(table[function]) == LUA_TFUNCTION)
    {
        QueueScript script;
        script.function = function;
        script.argument1 = argument1;
        script.argument2 = argument2;
        script.priority = priority;
        script.state = lua_newthread(m_LuaState);
        // we dont want thread to be garbage collected so we store it
        script.state_id = luaL_ref(m_LuaState, LUA_REGISTRYINDEX);
        script.seconds_to_wait = 0;
        script.wait = false;
        script.yield = false;
        if(start_sync == true)
        {
            script.paused_script_start = GetCurrentScriptId();
        }
        if(end_sync == true)
        {
            script.paused_script_end = GetCurrentScriptId();
        }
        script_entity->queue.push_back(script);
        script_entity->resort = true;

        return true;
    }

    return false;
}


void
ScriptManager::AddValueToStack(const float value)
{
    QueueScript* script = GetScriptByScriptId(m_CurrentScriptId);
    if(script != nullptr)
    {
        lua_pushnumber(script->state, value);
    }
}
