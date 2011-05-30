// $Id$

#include <OgreLogManager.h>
#include <lua.hpp>
#include <luabind/luabind.hpp>
#include <luabind/yield_policy.hpp>

#include "Model.h"
#include "FieldFadeManager.h"
#include "FieldModule.h"
#include "MessageManager.h"
#include "FieldScriptManager.h"
#include "../Main.h"
#include "../core/Configuration.h"
#include "../core/script/Binder.h"



bool
priority_queue_compare(QueueItem a, QueueItem b)
{
    return a.priority > b.priority;
}



class priority_find
{
public:
    priority_find(const int priority):
        m_Priority(priority)
    {
    }

    bool
    operator()(const QueueItem& a) const
    {
        return a.priority <= m_Priority;
    }

private:
    int m_Priority;
};



FieldScriptManager::FieldScriptManager(FieldModule* field)
{
    Ogre::LogManager::getSingletonPtr()->logMessage("FieldScriptManager created.");

    // debug info
    m_DebugInfoText = new TextArea("DebugScriptText");
    m_DebugInfoText->setCaption("");
    m_DebugInfoText->setMetricsMode(Ogre::GMM_PIXELS);
    m_DebugInfoText->setPosition(5, 5);
    m_DebugInfoText->setTextAlignment(TextArea::LEFT);
    m_DebugInfoText->setFontName("DebugText");
    m_DebugInfoText->setCharHeight(18);

    m_DebugInfoOverlay = Ogre::OverlayManager::getSingleton().create("DebugScriptOverlay");
    m_DebugInfoOverlay->setZOrder(QGOO_FIELD_DEBUG);
    m_DebugInfoOverlay->add2D((Ogre::OverlayContainer*)m_DebugInfoText);



    m_LuaState = lua_open();
    luabind::open(m_LuaState);
    luaopen_base(m_LuaState);
    luaopen_string(m_LuaState);
    luaopen_table(m_LuaState);
    luaopen_math(m_LuaState);



    luabind::module(m_LuaState)
    [
        luabind::class_<Entity>("Entity")
            // setting
            .def("set_visible", (void(Entity::*)(const bool))&Entity::ScriptSetVisible)
            .def("set_position_triangle", (void(Entity::*)(const float, const float, const float, const int))&Entity::ScriptSetPositionTriangle)
            .def("set_speed", (void(Entity::*)(const float))&Entity::ScriptSetSpeed)
            .def("set_direction", (void(Entity::*)(const float))&Entity::ScriptSetDirection)
            .def("get_triangle", (const int(Entity::*)())&Entity::ScriptGetTriangle)
            .def("set_solid_range", (void(Entity::*)(const float))&Entity::ScriptSetSolidRange)
            .def("set_solid", (void(Entity::*)(const bool))&Entity::SetSolid)
            .def("set_talk_range", (void(Entity::*)(const float))&Entity::SetTalkRange)
            .def("set_talkable", (void(Entity::*)(const bool))&Entity::SetTalkable)
            .def("set_rotation_lock", (void(Entity::*)(const bool))&Entity::SetRotationLock)

            // dynamic actions
            .def("move_to_position", (int(Entity::*)(const float, const float, const bool))&Entity::MoveToPosition, luabind::yield)
            .def("move_to_model", (int(Entity::*)(Entity*, const bool))&Entity::MoveToModel, luabind::yield)
            .def("turn_to_model", (int(Entity::*)(Entity*, const TurnDirection, const float))&Entity::TurnToModel, luabind::yield)
            .def("turn_to_direction", (int(Entity::*)(const float, const TurnDirection, const ActionType, const float))&Entity::TurnToDirection, luabind::yield)
            .def("jump_to_position", (int(Entity::*)(const float, const float, const int, const float))&Entity::JumpToPosition, luabind::yield)
            .def("climb_to_position", (int(Entity::*)(const float, const float, const float, const int, const ClimbMovement))&Entity::ClimbToPosition, luabind::yield)
            .def("offset_to_position", (void(Entity::*)(const float, const float, const float, const ActionType, const float))&Entity::OffsetToPosition)
            .def("set_offset_wait", (int(Entity::*)())&Entity::SetOffsetWait, luabind::yield)

            // animation
            .def("set_animation_default", (void(Entity::*)(const char*, const float))&Entity::SetAnimationDefault)
            .def("play_animation_wait", (int(Entity::*)(const char*, const float, const float, const float, const bool))&Entity::PlayAnimationWait, luabind::yield)
            .def("play_animation", (void(Entity::*)(const char*, const float, const float, const float, const bool))&Entity::PlayAnimation)
            .def("set_animation_wait", (int(Entity::*)())&Entity::SetAnimationWait, luabind::yield)

            .enum_("constants")
            [
                luabind::value("CLOCKWISE", CLOCKWISE),
                luabind::value("ANTICLOCKWISE", ANTICLOCKWISE),
                luabind::value("CLOSEST", CLOSEST),

                luabind::value("UP_TO_DOWN", UP_TO_DOWN),
                luabind::value("DOWN_TO_UP", DOWN_TO_UP),
                luabind::value("LEFT_TO_RIGHT", LEFT_TO_RIGHT),
                luabind::value("RIGHT_TO_LEFT", RIGHT_TO_LEFT)
            ]
    ];

    luabind::module(m_LuaState)
    [
        luabind::class_<FieldModule>("Field")
            .def("line_trigger_on", (void(FieldModule::*)(const char*, const bool))&FieldModule::LineTriggerOn)
            .def("jump_to_map", (void(FieldModule::*)(const int, const float, const float, const float, const float))&FieldModule::JumpToMap)
            .def("battle_run", (int(FieldModule::*)(const int))&FieldModule::BattleRun, luabind::yield)
            .def("lock_walkmesh", (void(FieldModule::*)(const int, const bool))&FieldModule::LockWalkmesh)

            .def("load_model", (Entity*(FieldModule::*)(const char*, const int))&FieldModule::LoadModel)
            .def("load_sprite", (Entity*(FieldModule::*)(const char*, const int))&FieldModule::LoadSprite)
            .def("set_entity_to_character", (void(FieldModule::*)(Entity*, const int))&FieldModule::ScriptSetEntityToCharacter)
            .def("set_player_entity", (void(FieldModule::*)(Entity*))&FieldModule::ScriptSetPlayerEntity)
            .def("pc_lock", (void(FieldModule::*)(const bool))&FieldModule::ScriptPCLock)
            .def("pc_slip", (void(FieldModule::*)(const bool))&FieldModule::PCSlip)

            .def("random_encounter_on", (void(FieldModule::*)(const bool))&FieldModule::RandomEncounterOn)
            .def("random_encounter_table", (void(FieldModule::*)(const int))&FieldModule::RandomEncounterTable)

            .enum_("constants")
            [
                luabind::value("NONE", NONE),
                luabind::value("LINEAR", LINEAR),
                luabind::value("SMOOTH", SMOOTH)
            ]
    ];

    luabind::module(m_LuaState)
    [
        luabind::class_<FieldScriptManager>("Script")
            .def("wait", (int(FieldScriptManager::*)(const float))&FieldScriptManager::ScriptWait, luabind::yield)
            .def("request", (void(FieldScriptManager::*)(const char*, const char*, const int))&FieldScriptManager::ScriptRequest)
            .def("request_start_wait", (int(FieldScriptManager::*)(const char*, const char*, const int))&FieldScriptManager::ScriptRequestStartWait, luabind::yield)
            .def("request_end_wait", (int(FieldScriptManager::*)(const char*, const char*, const int))&FieldScriptManager::ScriptRequestEndWait, luabind::yield)
    ];

    luabind::module(m_LuaState)
    [
        luabind::class_<MessageManager>("Message")
            .def("show_text", (void(MessageManager::*)(const int, const int, const int, const int))&MessageManager::ShowText)
            .def("show_text", (void(MessageManager::*)(const int, const char*, const int, const int, const int, const int))&MessageManager::ShowText)
            .def("show_text_wait", (int(MessageManager::*)(const int, const int, const int, const int))&MessageManager::ShowTextWait, luabind::yield)
            .def("show_text_wait", (int(MessageManager::*)(const int, const char*, const int, const int, const int, const int))&MessageManager::ShowTextWait, luabind::yield)
            .def("hide", (void(MessageManager::*)(const int))&MessageManager::Hide)
            .def("set_style", (void(MessageManager::*)(const int, const MessageStyle))&MessageManager::SetStyle)
            .def("set_clickable", (void(MessageManager::*)(const int, const bool))&MessageManager::SetClickable)
            .def("set_cursor", (void(MessageManager::*)(const int, const int, const int))&MessageManager::SetCursor)
            .def("get_cursor", (int(MessageManager::*)(const int))&MessageManager::GetCursor)

            .enum_("constants")
            [
                luabind::value("SOLID", MSL_SOLID),
                luabind::value("TRANSPARENT", MSL_TRANSPARENT),
                luabind::value("NONE", MSL_NONE)
            ]
    ];

    luabind::module(m_LuaState)
    [
        luabind::class_<FieldFadeManager>("Fade")
            .def("fade", (void(FieldFadeManager::*)(const int, const int, const int, const FieldFadeType, const float))&FieldFadeManager::FadeIn)
            .def("fade", (void(FieldFadeManager::*)(const int, const int, const int, const FieldFadeType, const float, const int))&FieldFadeManager::FadeIn)
            .def("clear", (void(FieldFadeManager::*)())&FieldFadeManager::Clear)
            .def("black", (void(FieldFadeManager::*)())&FieldFadeManager::Black)
            .def("wait", (int(FieldFadeManager::*)())&FieldFadeManager::Wait, luabind::yield)

            .enum_("constants")
            [
                luabind::value("ADD", FF_ADD),
                luabind::value("SUBTRACT", FF_SUBTRACT)
            ]
    ];

    BindGameStateToLua(m_LuaState);

    // set global script object
    luabind::globals(m_LuaState)["script"] = boost::ref(*this);
    luabind::globals(m_LuaState)["field"] = boost::ref(*field);
}



FieldScriptManager::~FieldScriptManager(void)
{
    m_DebugInfoOverlay->remove2D((Ogre::OverlayContainer*)m_DebugInfoText);
    delete m_DebugInfoText;
    Ogre::OverlayManager::getSingleton().destroy(m_DebugInfoOverlay);

    // we must clear all lua objects before closing lua state
    m_Entity.clear();
    lua_close(m_LuaState);

    Ogre::LogManager::getSingletonPtr()->logMessage("FieldScriptManager destroyed.");
}



void
FieldScriptManager::Input(const Event& input)
{
}



void
FieldScriptManager::Update(const float delta_time)
{
    //lua_gc (m_LuaState, LUA_GCCOLLECT, 0);

    for (int i = 0; i < m_Entity.size(); ++i)
    {
        if (m_Entity[i].queue.size() > 0)
        {
            int current_script = m_Entity[i].queue.size() - 1;

            if (m_Entity[i].queue[current_script].wait == false)
            {
                m_CurrentScriptInfo.script = m_Entity[i].queue[current_script].script;
                m_CurrentScriptInfo.entity_id = i;
                m_CurrentScriptInfo.priority = m_Entity[i].queue[current_script].priority;

                if (m_Entity[i].queue[current_script].yield == false)
                {
                    Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT] Start script '" + m_CurrentScriptInfo.script + "' for entity '" + m_Entity[i].name + "'.");

                    m_Entity[i].queue[current_script].state = lua_newthread(m_LuaState);
                    // we dont want thread to be garbage collected so we store it
                    m_Entity[i].queue[current_script].state_id = luaL_ref(m_LuaState, LUA_REGISTRYINDEX);
                    luabind::object table = luabind::gettable(luabind::globals(m_Entity[i].queue[current_script].state)["entity"], m_Entity[i].name);

                    if (luabind::type(table) == LUA_TTABLE && luabind::type(table[m_CurrentScriptInfo.script]) == LUA_TFUNCTION)
                    {
                        int ret = 0;

                        try
                        {
                            ret = luabind::resume_function<int>(table[m_CurrentScriptInfo.script], table);
                        }
                        catch(luabind::error& e)
                        {
                            luabind::object error_msg(luabind::from_stack(e.state(), -1));
                            Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT ERROR] " + Ogre::String(luabind::object_cast<std::string>(error_msg)));
                        }

                        if (ret == 0)
                        {
                            Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT] Script '" + m_Entity[i].queue[current_script].script + "' for entity '" + m_Entity[i].name + "' finished.");
                            // delete thread
                            luaL_unref(m_LuaState, LUA_REGISTRYINDEX, m_Entity[i].queue[current_script].state_id);

                            if (m_Entity[i].queue[current_script].paused_script_end.entity_id != -1)
                            {
                                this->ContinueEntityScriptExecution(m_Entity[i].queue[current_script].paused_script_end);
                            }

                            m_Entity[i].queue.erase(m_Entity[i].queue.begin() + current_script);
                        }
                        else if (ret == 1)
                        {
                            Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT] Script '" + m_Entity[i].queue[current_script].script + "' for entity '" + m_Entity[i].name + "' not paused and will be continued next cycle.");
                            m_Entity[i].queue[current_script].yield = true;
                        }
                        else
                        {
                            Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT] Script '" + m_Entity[i].queue[current_script].script + "' for entity '" + m_Entity[i].name + "' not finished yet.");
                            m_Entity[i].queue[current_script].yield = true;
                            m_Entity[i].queue[current_script].wait = true;
                        }
                    }
                    else
                    {
                        Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT ERROR] Script '" + m_Entity[i].queue[current_script].script + "' for entity '" + m_Entity[i].name + "' doesn't exist.");

                        if (m_Entity[i].queue[current_script].paused_script_end.entity_id != -1)
                        {
                            this->ContinueEntityScriptExecution(m_Entity[i].queue[current_script].paused_script_end);
                        }

                        m_Entity[i].queue.erase(m_Entity[i].queue.begin() + current_script);
                    }
                }
                else
                {
                    Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT] Continue script '" + m_Entity[i].queue[current_script].script + "' for entity '" + m_Entity[i].name + "'.");

                    int ret = 0;

                    try
                    {
                        ret = luabind::resume<int>(m_Entity[i].queue[current_script].state);
                    }
                    catch(luabind::error& e)
                    {
                        luabind::object error_msg(luabind::from_stack(e.state(), -1));
                        Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT ERROR] " + Ogre::String(luabind::object_cast<std::string>(error_msg)));
                    }

                    if (ret == 0)
                    {
                        Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT] Script '" + m_Entity[i].queue[current_script].script + "' for entity '" + m_Entity[i].name + "' finished.");
                        // delete thread
                        luaL_unref(m_LuaState, LUA_REGISTRYINDEX, m_Entity[i].queue[current_script].state_id);

                        if (m_Entity[i].queue[current_script].paused_script_end.entity_id != -1)
                        {
                            this->ContinueEntityScriptExecution(m_Entity[i].queue[current_script].paused_script_end);
                        }

                        m_Entity[i].queue.erase(m_Entity[i].queue.begin() + current_script);
                    }
                    else if (ret == 1)
                    {
                        Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT] Script '" + m_Entity[i].queue[current_script].script + "' for entity '" + m_Entity[i].name + "' not paused and will be continued next cycle.");
                    }
                    else
                    {
                        Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT] Script '" + m_Entity[i].queue[current_script].script + "' for entity '" + m_Entity[i].name + "' not finished yet.");
                        m_Entity[i].queue[current_script].wait = true;
                    }
                }
            }
            else if (m_Entity[i].queue[current_script].seconds_to_wait > 0)
            {
                m_Entity[i].queue[current_script].seconds_to_wait -= delta_time;
                m_Entity[i].queue[current_script].seconds_to_wait = (m_Entity[i].queue[current_script].seconds_to_wait < 0) ? 0 : m_Entity[i].queue[current_script].seconds_to_wait;

                if (m_Entity[i].queue[current_script].seconds_to_wait == 0)
                {
                    m_Entity[i].queue[current_script].wait = false;
                }
            }
        }
    }



    // copy all requested scripts to main queue
    // must be done before or after script execution to save script indexes
    this->CopyRequestedScripts();



    if (m_DebugInfoOverlay->isVisible() == true)
    {
        Ogre::String caption;

        for (int i = 0; i < m_Entity.size(); ++i)
        {
            caption += m_Entity[i].name + ": ";

            if (m_Entity[i].queue.size() > 0)
            {
                int current_script = m_Entity[i].queue.size() - 1;

                caption += "'" + m_Entity[i].queue[current_script].script + "'";
                if (m_Entity[i].queue[current_script].wait == true)
                {
                    if (m_Entity[i].queue[current_script].seconds_to_wait != 0)
                    {
                        caption += " wait (" + Ogre::StringConverter::toString(m_Entity[i].queue[current_script].seconds_to_wait) + ")";
                    }
                    else
                    {
                        caption += " in action";
                    }
                }
            }

            caption += "\n";
        }

        m_DebugInfoText->setCaption(caption);
    }
}



void
FieldScriptManager::AddFadeManagerToScript(FieldFadeManager* fade)
{
    luabind::globals(m_LuaState)["fade"] = boost::ref(*fade);
}



void
FieldScriptManager::AddMessageManagerToScript(MessageManager* message)
{
    luabind::globals(m_LuaState)["message"] = boost::ref(*message);
}



void
FieldScriptManager::ShowDebug(const bool show)
{
    if (show == true)
    {
        m_DebugInfoOverlay->show();
    }
    else
    {
        m_DebugInfoOverlay->hide();
    }
}



void
FieldScriptManager::LoadFile(const Ogre::String& name)
{
    Ogre::LogManager::getSingletonPtr()->logMessage("Load script file.");

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
    if (luaL_dofile(m_LuaState, (Configuration::getSingleton().GetFileRoot() + name).c_str()) == 1)
    {
        luabind::object error_msg(luabind::from_stack(m_LuaState, -1));
        Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT ERROR] " + Ogre::String(luabind::object_cast<std::string>(error_msg)));
    }

    lua_getglobal(m_LuaState, "entity");
    if (lua_istable(m_LuaState, -1))
    {
        // first key
        lua_pushnil(m_LuaState);
        while (lua_next(m_LuaState, -2) != 0)
        {
            // add all entity to array
            ScriptUnit entity;
            entity.name = lua_tostring(m_LuaState, -2);

            QueueItem queue;
            queue.script   = "on_start";
            queue.priority = 999;
            entity.queue.push_back(queue);

            m_Entity.push_back(entity);

            Ogre::LogManager::getSingletonPtr()->logMessage(Ogre::String("Entity '") + lua_tostring(m_LuaState, -2) + Ogre::String("' was added."));

            // removes 'value'; keeps 'key' for next iteration
            lua_pop(m_LuaState, 1);
         }

    }

    lua_pop(m_LuaState, 1);
}



const ScriptInfo
FieldScriptManager::GetCurrentScriptInfo(void) const
{
    return m_CurrentScriptInfo;
}



void
FieldScriptManager::ContinueEntityScriptExecution(const ScriptInfo& pause)
{
    // find script
    int script_id = GetScriptIdByName(pause.entity_id, pause.script);
    if (script_id == -1)
    {
        Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT ERROR] ContinueEntityScriptExecution: Script '" + pause.script + "' for entity '" + Ogre::StringConverter::toString(pause.entity_id) + "' not found.");
    }

    m_Entity[pause.entity_id].queue[script_id].wait = false;
}



void
FieldScriptManager::AddScript(const Ogre::String& entity, const Ogre::String& script, const int priority)
{
    int id = this->GetEntityIdByName(entity);
    if (id == -1)
    {
        Ogre::LogManager::getSingletonPtr()->logMessage("[WARNING] entity '" + entity + "' doesn't has script representation.");
        return;
    }

    // if this priority already executed - return
    std::vector<QueueItem>::iterator it = std::find_if(m_Entity[id].queue.begin(), m_Entity[id].queue.end(), priority_find(priority));
    if (it != m_Entity[id].queue.end())
    {
        return;
    }

    QueueItem item;
    item.script   = script;
    item.priority = priority;
    m_Entity[id].queue.push_back(item);
}



int
FieldScriptManager::ScriptWait(const float seconds)
{
    Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT] script:wait: We set script wait for " + Ogre::StringConverter::toString(seconds) + " seconds.");

    ScriptInfo info = this->GetCurrentScriptInfo();
    if (info.entity_id == -1)
    {
        Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT ERROR] script:wait: Currently no entity running. Probably initing.");
        return 1;
    }

    int script_id = this->GetScriptIdByName(info.entity_id, info.script);
    if (script_id == -1)
    {
        Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT ERROR] script:wait: Currently no script running. Probably initing.");
        return 1;
    }

    if (seconds == 0)
    {
        return 1;
    }

    m_Entity[info.entity_id].queue[script_id].seconds_to_wait = seconds;

    return -1;
}



void
FieldScriptManager::ScriptRequest(const char* entity, const char* script, const int priority)
{
    Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT] script:request: Request script '" + Ogre::String(script) + "' for entity '" + Ogre::String(entity) + "' with priority '" + Ogre::StringConverter::toString(priority) + "'.");

    int id = this->GetEntityIdByName(Ogre::String(entity));

    if (id == -1)
    {
        Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT ERROR] script:request: Entity doesn't exist.");
        return;
    }

    QueueItem item;
    item.script   = Ogre::String(script);
    item.priority = priority;
    m_Entity[id].requests.push_back(item);
}



int
FieldScriptManager::ScriptRequestStartWait(const char* entity, const char* script, const int priority)
{
    Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT] script:request_start_wait: Request script '" + Ogre::String(script) + "' for entity '" + Ogre::String(entity) + "' with priority '" + Ogre::StringConverter::toString(priority) + "'.");

    int id = this->GetEntityIdByName(Ogre::String(entity));

    if (id == -1)
    {
        Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT ERROR] script:request_start_wait: Entity doesn't exist.");
        return 1;
    }

    QueueItem item;
    item.script              = Ogre::String(script);
    item.priority            = priority;
    item.paused_script_start = this->GetCurrentScriptInfo();
    m_Entity[id].requests.push_back(item);

    return -1;
}



int
FieldScriptManager::ScriptRequestEndWait(const char* entity, const char* script, const int priority)
{
    Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT] script:request_end_wait: Request script '" + Ogre::String(script) + "' for entity '" + Ogre::String(entity) + "' with priority '" + Ogre::StringConverter::toString(priority) + "'.");

    int id = this->GetEntityIdByName(Ogre::String(entity));

    if (id == -1)
    {
        Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT ERROR] script:request_end_wait: Entity doesn't exist.");
        return 1;
    }

    QueueItem item;
    item.script            = Ogre::String(script);
    item.priority          = priority;
    item.paused_script_end = this->GetCurrentScriptInfo();
    m_Entity[id].requests.push_back(item);

    return -1;
}



const int
FieldScriptManager::GetEntityIdByName(const Ogre::String& name) const
{
    for (int i = 0; i < m_Entity.size(); ++i)
    {
        if (name == m_Entity[i].name)
        {
            return i;
        }
    }

    return -1;
}



const int
FieldScriptManager::GetScriptIdByName(const int entity_id, const Ogre::String& name) const
{
    for (int i = 0; i < m_Entity[entity_id].queue.size(); ++i)
    {
        if (name == m_Entity[entity_id].queue[i].script)
        {
            return i;
        }
    }

    return -1;
}



void
FieldScriptManager::CopyRequestedScripts()
{
    // we copy requested scripts only with higher priority than executed
    for (int i = 0; i < m_Entity.size(); ++i)
    {
        if (m_Entity[i].requests.size() > 0)
        {
            std::sort(m_Entity[i].requests.begin(), m_Entity[i].requests.end(), priority_queue_compare);

            int current_script = m_Entity[i].requests.size() - 1;

            // if this priority already executed - not add yet
            std::vector<QueueItem>::iterator it = std::find_if(m_Entity[i].queue.begin(), m_Entity[i].queue.end(), priority_find(m_Entity[i].requests[current_script].priority));
            if (it == m_Entity[i].queue.end())
            {
                if (m_Entity[i].requests[current_script].paused_script_start.entity_id != -1)
                {
                    this->ContinueEntityScriptExecution(m_Entity[i].requests[current_script].paused_script_start);
                }

                m_Entity[i].queue.push_back(m_Entity[i].requests[current_script]);
                m_Entity[i].requests.erase(m_Entity[i].requests.begin() + current_script);
            }
        }
    }
}
