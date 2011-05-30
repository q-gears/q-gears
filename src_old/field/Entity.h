// $Id$

#ifndef ENTITY_h
#define ENTITY_h

#include "ModelCollision.h"
#include "ModelDirection.h"
#include "FieldTypes.h"
#include "FieldScriptManager.h"
#include "Walkmesh.h"
#include "../core/Actor.h"
#include "../core/ui/MovableTextArea.h"



class Entity : public Actor
{
public:
                         Entity(const Ogre::String& name, Ogre::SceneNode* node, FieldScriptManager* script, Walkmesh* walkmesh);
    virtual             ~Entity();

    virtual void         Input(const Event& input);
    virtual void         Update(const float delta_time);

    void                 ShowDebug(const bool show);

    const ModelMovement  GetState() const;

    const Ogre::String   GetName() const;

    // script functions
    void                 ScriptSetVisible(const bool visible);
    void                 ScriptSetPositionTriangle(const float x, const float y, const float z, const int triangle_id);
    void                 ScriptSetSpeed(const float speed);
    void                 ScriptSetDirection(const float direction);
    const int            ScriptGetTriangle() const;
    void                 ScriptSetSolidRange(const float range);

    const Ogre::Vector3  GetPosition() const;
    void                 SetPosition(const Ogre::Vector3& position);
    const Ogre::Vector3  GetOffset() const;
    void                 SetOffset(const Ogre::Vector3& position);
    void                 SetTriangle(const int triangle);
    const int            GetTriangle() const;
    void                 SetDirection(const Ogre::Degree& direction);
    const Ogre::Degree   GetDirection() const;
    void                 SetRotationLock(const bool lock);
    const bool           GetRotationLock() const;

    const float          GetStepSeconds() const;
    void                 SetCurrentStepSeconds(const float seconds);
    const float          GetCurrentStepSeconds() const;

    // offset related
    void                 OffsetToPosition(const float x, const float y, const float z, const ActionType type, const float seconds);
    const int            SetOffsetWait();
    void                 SetOffseting(const Ogre::Vector3& position, const ActionType type, const float seconds);
    void                 UnsetOffseting();
    const Ogre::Vector3  GetOffsetPositionStart() const;
    const Ogre::Vector3  GetOffsetPositionEnd() const;
    const ActionType     GetOffsetType() const;
    const float          GetOffsetStepSeconds() const;
    void                 SetOffsetCurrentStepSeconds(const float seconds);
    const float          GetOffsetCurrentStepSeconds() const;

    // climb related
    const int            ClimbToPosition(const float x, const float y, const float z, const int triangle_id, const ClimbMovement movement);
    void                 SetClimb(const Ogre::Vector3& end, const int end_triangle, const ClimbMovement movement);
    void                 UnsetClimb(const bool end);
    const ClimbMovement  GetClimbMovement() const;
    const Ogre::Vector3& GetClimbStart() const;
    const Ogre::Vector3& GetClimbEnd() const;

    // turn related
    const int            TurnToDirection(const float direction, const TurnDirection turn_direction, const ActionType turn_type, const float seconds);
    const int            TurnToModel(Entity* entity, const TurnDirection turn_direction, const float seconds);
    void                 SetTurn(const Ogre::Degree& direction_to, Entity* entity, const TurnDirection turn_direction, const ActionType turn_type, const float seconds);
    void                 UnsetTurn();
    const Ogre::Degree   CalculateTurnAngle(const Ogre::Degree& start, const Ogre::Degree& end) const;
    const Ogre::Degree   GetTurnDirectionStart() const;
    const Ogre::Degree   GetTurnDirectionEnd() const;
    const ActionType     GetTurnType() const;
    const float          GetTurnStepSeconds() const;
    void                 SetTurnCurrentStepSeconds(const float seconds);
    const float          GetTurnCurrentStepSeconds() const;

    // jump related
    const int            JumpToPosition(const float x, const float y, const int triangle_id, const float seconds);
    void                 SetJump(const Ogre::Vector2& jump_to, const int triangle_id, const float seconds);
    void                 UnsetJump();
    const Ogre::Vector3& GetJumpStart() const;
    const Ogre::Vector3& GetJumpEnd() const;

    // move related
    void                 SetSpeed(const float speed);
    const float          GetSpeed() const;
    void                 SetMovePlayAnimation(const bool play);
    const bool           GetMovePlayAnimation() const;

    const int            MoveToPosition(const float x, const float y, const bool play_animation);
    const int            MoveToModel(Entity* entity, const bool play_animation);
    void                 SetMove(const Ogre::Vector2& move_to, Entity* entity, const float stop_distance);
    void                 UnsetMove();
    const Ogre::Vector2& GetMovePosition() const;
    const float          GetMoveStopDistance() const;

    // height related
    const int            GetHeight() const;

    // solid related
    void                 SetSolidRange(const float range);
    const float          GetSolidRange() const;
    void                 SetSolid(const bool solid);
    const bool           IsSolid() const;

    // talk related
    void                 SetTalkRange(const float range);
    const float          GetTalkRange() const;
    void                 SetTalkable(const bool talkable);
    const bool           IsTalkable() const;

    // model related
    virtual void         SetVisible(const bool visible) = 0;
    virtual const bool   IsVisible() const = 0;

    // animation related
    void                 SetAnimationDefault(const char* animation, const float relative_speed);
    void                 PlayAnimation(const char* animation, const float start, const float end, const float relative_speed, const bool stop_in_last_frame);
    const int            PlayAnimationWait(const char* animation, const float start, const float end, const float relative_speed, const bool stop_in_last_frame);
    const int            SetAnimationWait();

    virtual void         AnimationUpdate(const float delta_time) = 0;
    virtual bool         SetAnimationState(const Ogre::String& animation, const float start, const float end, const float speed, const ModelAnimation state) = 0;
    virtual void         PlayAnimationLooped(const Ogre::String& animation, const float relative_speed) = 0;

private:
    Entity(void);

protected:
    FieldScriptManager*   m_FieldScriptManager;

    Walkmesh*             m_Walkmesh;

    Ogre::String          m_Name;

    bool                  m_DrawDebug;
    MovableTextArea*      m_DebugInfoText;
    Ogre::Overlay*        m_DebugInfoOverlay;

    Ogre::SceneNode*      m_SceneNode;
    Ogre::SceneNode*      m_ModelNode;
    Ogre::SceneNode*      m_ModelDirectionNode;
    ModelDirection*       m_ModelDirection;
    Ogre::SceneNode*      m_ModelSolidCollisionNode;
    ModelCollision*       m_ModelSolidCollision;
    Ogre::SceneNode*      m_ModelTalkCollisionNode;
    ModelCollision*       m_ModelTalkCollision;


    ModelMovement         m_State;

    // rotation
    bool                  m_RotationLock;

    // walkmesh related
    int                   m_Triangle;

    float                 m_StepSeconds;
    float                 m_CurrentStepSeconds;
    ScriptInfo            m_ScriptInfo;

    // offset related
    Ogre::Vector3         m_OffsetPositionStart;
    Ogre::Vector3         m_OffsetPositionEnd;
    ActionType            m_OffsetType;
    float                 m_OffsetStepSeconds;
    float                 m_OffsetCurrentStepSeconds;
    ScriptInfo            m_OffsetScriptInfo;

    // climb related
    ClimbMovement         m_ClimbMovement;
    Ogre::Vector3         m_ClimbStart;
    Ogre::Vector3         m_ClimbEnd;
    int                   m_ClimbTriangleEnd;

    // turn related
    Entity*               m_TurnModel;
    Ogre::Degree          m_TurnDirectionStart;
    Ogre::Degree          m_TurnDirectionEnd;
    ActionType            m_TurnType;
    TurnDirection         m_TurnDirection;
    float                 m_TurnStepSeconds;
    float                 m_TurnCurrentStepSeconds;
    ScriptInfo            m_TurnScriptInfo;

    // jump related
    float                 m_JumpB;
    Ogre::Vector3         m_JumpStart;
    Ogre::Vector3         m_JumpEnd;
    int                   m_JumpTriangleEnd;

    // move related
    float                 m_Speed;
    Entity*               m_MoveModel;
    Ogre::Vector2         m_MovePosition;
    float                 m_MoveStopDistance;
    bool                  m_MovePlayAnimation;

    // height related
    float                 m_Height;

    // collision related
    float                 m_SolidRange;
    bool                  m_Solid;

    // talk related
    float                 m_TalkRange;
    bool                  m_Talkable;

    // animation related
    Ogre::String          m_AnimationCurrentName;
    ModelAnimation        m_AnimationState;
    float                 m_AnimationSpeed;
    float                 m_AnimationSpeedCurrent;
    bool                  m_AnimationWait;
    float                 m_AnimationEndTime;

    Ogre::String          m_AnimationDefault;
    float                 m_AnimationDefaultSpeed;
};



#endif // MODEL_h
