#ifndef FIELD_MODULE_h
#define FIELD_MODULE_h

#include <vector>

#include "FieldCamera.h"
#include "FieldFadeManager.h"
#include "FieldScriptManager.h"
#include "FieldTypes.h"
#include "LineTrigger.h"
#include "MessageManager.h"
#include "Model.h"
#include "Sprite.h"
#include "Walkmesh.h"
#include "../core/Module.h"



class XmlFieldMapFile;



struct MoveButtons
{
    bool up;
    bool right;
    bool down;
    bool left;
    bool run;

    MoveButtons():
        up(false),
        right(false),
        down(false),
        left(false),
        run(false)
    {
    }
};



class FieldModule : public Module
{
friend class XmlFieldMapFile;

public:
                       FieldModule(void);
                       FieldModule(const int parameter);
    virtual           ~FieldModule(void);

    virtual void       Input(const Event& input);
    virtual void       OnStart(const float delta_time);
    virtual void       Update(const float delta_time);
    virtual void       OnFinish(const float delta_time);

    virtual void       OnPauseOn();
    virtual void       OnPauseOff();

public:
    void               LoadMap(const int field_id);
    void               UnloadMap();
    void               JumpToMap(const int map_id, const float x, const float y, const float z, const float direction);
    int                BattleRun(const int battle_id);
    Entity*            LoadModel(const char* name, const int model_id);
    Entity*            LoadSprite(const char* name, const int sprite_id);
    void               ScriptSetEntityToCharacter(Entity* entity, const int character_id);
    void               ScriptSetPlayerEntity(Entity* entity);
    void               ScriptPCLock(const bool lock);
    void               PCSlip(const bool slip);
    void               LockWalkmesh(const int triangle_id, const bool lock);
    void               LineTriggerOn(const char* name, const bool on);
    void               RandomEncounterOn(const bool on);
    void               RandomEncounterTable(const int table_id);

private:
    // movement
    const bool         SetNextStep(const int model_id, const Ogre::Vector2& move_vector);
    const bool         WalkmeshBorderCross(const int model_id, Ogre::Vector3& position, const Ogre::Vector2& move_vector);
    const bool         CheckSolidCollisions(const int model_id, Ogre::Vector3& position);
    void               CheckLineTriggers(const int model_id, const Ogre::Vector3& position);

    void               CheckEntityTalk();
    void               CheckEncounters();

    void               SetEntityDirectionByVector2(const int entity_id, const Ogre::Vector2& vector);
    void               SetEntityOnWalkmesh(const int entity_id);

    void               SetNextOffsetStep(const int model_id, const float delta_time);
    void               SetNextClimbStep(const int model_id, const float delta_time);
    void               SetNextTurnStep(const int model_id, const float delta_time);
    void               SetNextJumpStep(const int model_id, const float delta_time);
    void               SetNextMoveStep(const int model_id, const float delta_time);

    const bool         CheckModelId(const int model_id) const;
    const bool         CheckEncounterAvailable() const;

private:
    FieldScriptManager*         m_FieldScriptManager;
    MessageManager*             m_MessageManager;
    FieldFadeManager*           m_FadeManager;
    FieldCamera*                m_Camera;

    Ogre::SceneNode*            m_SceneNode;

    int                         m_MapId;

    float                       m_Timer;

    MoveButtons                 m_MoveButtons;

    // Level related
    int                         m_FieldId;
    Walkmesh*                   m_Walkmesh;
    float                       m_Scale;

    std::vector<LineTrigger*>   m_LineTriggers;

    Ogre::String                m_AnimationIdle;
    Ogre::String                m_AnimationWalk;
    Ogre::String                m_AnimationRun;

    std::vector<Entity*>        m_Models;
    std::map<int, int>          m_CharactersModels;
    Ogre::Radian                m_MovementRotation;
    int                         m_PlayerModelId;
    bool                        m_PlayerModelLock;
    bool                        m_PlayerModelSlip;

    // encounters
    struct Encounter
    {
        int percentage;
        int battle_id;
    };

    struct EncounterTable
    {
        float                  rate;
        std::vector<Encounter> encounter;
    };

    std::vector<EncounterTable> m_Encounters;
    int                         m_EncounterTable;
    bool                        m_EncounterEnabled;
    float                       m_EncounterTime;
    float                       m_EncounterPercent;
    int                         m_EncounterPreviousBattle;

    ScriptInfo                  m_BattleScriptInfo;

    // debug
    TextArea*                   m_DebugEncounterText;
    Ogre::Overlay*              m_DebugEncounterOverlay;
};



#endif // FIELD_MODULE_h
