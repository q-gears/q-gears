// $Id$

#ifndef FIELD_SCRIPT_MANAGER_h
#define FIELD_SCRIPT_MANAGER_h

#include <lua.hpp>
#include <luabind/luabind.hpp>
#include <OgreOverlay.h>
#include <OgreString.h>
#include <vector>

#include "../core/Actor.h"
#include "../core/ui/TextArea.h"

class FieldFadeManager;
class FieldModule;
class MessageManager;



struct ScriptInfo
{
    ScriptInfo():
        entity_id(-1),
        priority(0)
    {
    }

    Ogre::String script;
    int          entity_id;
    int          priority;
};



struct QueueItem
{
    QueueItem():
        state(NULL),
        seconds_to_wait(0),
        wait(false),
        yield(false)
    {
    }

    int          priority;
    Ogre::String script;
    lua_State*   state;
    int          state_id; // for storing and deleating thread
    float        seconds_to_wait;
    bool         wait;
    bool         yield;
    ScriptInfo   paused_script_start; // script paused by call of this script.
    ScriptInfo   paused_script_end; // script paused by call of this script.
};

struct ScriptUnit
{
    Ogre::String           name;
    std::vector<QueueItem> queue;
    std::vector<QueueItem> requests;
};



class FieldScriptManager : public Actor
{
public:
                       FieldScriptManager(FieldModule* field);
    virtual           ~FieldScriptManager(void);

    virtual void       Input(const Event& input);
    virtual void       Update(const float delta_time);

    void               AddFadeManagerToScript(FieldFadeManager* fade);
    void               AddMessageManagerToScript(MessageManager* message);

    void               ShowDebug(const bool show);

    void               LoadFile(const Ogre::String& name);

    // pause related
    const ScriptInfo   GetCurrentScriptInfo(void) const;
    void               ContinueEntityScriptExecution(const ScriptInfo& pause);

    void               AddScript(const Ogre::String& entity, const Ogre::String& script, const int priority);

    int                ScriptWait(const float seconds);
    void               ScriptRequest(const char* entity, const char* script, const int priority);
    int                ScriptRequestStartWait(const char* entity, const char* script, const int priority);
    int                ScriptRequestEndWait(const char* entity, const char* script, const int priority);

private:
    const int          GetEntityIdByName(const Ogre::String& name) const;
    const int          GetScriptIdByName(const int entity_id, const Ogre::String& name) const;
    void               CopyRequestedScripts();

private:
    TextArea*                               m_DebugInfoText;
    Ogre::Overlay*                          m_DebugInfoOverlay;

    lua_State*                              m_LuaState;

    ScriptInfo                              m_CurrentScriptInfo;
    std::vector<ScriptUnit>                 m_Entity;
};



#endif // FIELD_SCRIPT_MANAGER_h
