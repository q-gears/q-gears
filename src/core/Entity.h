#ifndef ENTITY_H
#define ENTITY_H

#include <OgreString.h>

#include "EntityCollision.h"
#include "EntityDirection.h"
#include "ScriptManager.h"



enum ActionType
{
    AT_NONE,
    AT_LINEAR,
    AT_SMOOTH
};



enum TurnDirection
{
    TD_CLOCKWISE,
    TD_ANTICLOCKWISE,
    TD_CLOSEST
};



enum LinearMovement
{
    LM_UP_TO_DOWN,
    LM_DOWN_TO_UP,
    LM_LEFT_TO_RIGHT,
    LM_RIGHT_TO_LEFT
};



class Entity
{
public:
    enum AnimationState
    {
        REQUESTED_ANIMATION,
        AUTO_ANIMATION
    };

    enum AnimationPlayType
    {
        PLAY_DEFAULT,
        PLAY_ONCE,
        PLAY_LOOPED
    };

    enum State
    {
        NONE,
        WALKMESH,
        LINEAR,
        JUMP
    };

                         Entity( const Ogre::String& name, Ogre::SceneNode* node );
    virtual              ~Entity();

    virtual void         Update();

    const Ogre::String&  GetName() const;

    void                 SetPosition( const Ogre::Vector3& position );
    void                 ScriptSetPosition( const float x, const float y, const float z );
    const Ogre::Vector3  GetPosition() const;

    void                 SetOffset( const Ogre::Vector3& position );
    const Ogre::Vector3  GetOffset() const;

    void                 SetDirection( const Ogre::Degree& direction );
    void                 ScriptSetDirection( const float direction );
    Ogre::Degree         GetDirection() const;

    // height related
    float                GetHeight() const;

    // solid related
    void                 SetSolidRadius( const float radius );
    float                GetSolidRadius() const;
    void                 SetSolid( const bool solid );
    bool                 IsSolid() const;

    // talk related
    void                 SetTalkRadius( const float radius );
    float                GetTalkRadius() const;
    void                 SetTalkable( const bool talkable );
    bool                 IsTalkable() const;

    // model related
    virtual void         SetVisible( const bool visible ) = 0;
    virtual bool         IsVisible() const = 0;

    // different type of movement state related
    void                 SetState( const State state );
    State                GetState() const;

    // movement related
    void                 SetMoveSpeed( const float speed );
    float                GetMoveSpeed() const;
    void                 SetMoveSpeedRun( const float speed );
    float                GetMoveSpeedRun() const;
    void                 SetMovePosition( const Ogre::Vector3& target );
    const Ogre::Vector3& GetMovePosition() const;
    float                GetMoveStopDistance() const;
    void                 SetMoveTriangleId( const int triangle );
    int                  GetMoveTriangleId() const;
    void                 SetMoveAutoRotation( const bool rotate );
    bool                 GetMoveAutoRotation() const;
    void                 SetMoveAutoAnimation( const bool animate );
    bool                 GetMoveAutoAnimation() const;
    const Ogre::String&  GetMoveAnimationWalkName() const;
    const Ogre::String&  GetMoveAnimationRunName() const;
    void                 ScriptMoveToPosition( const float x, const float y );
    void                 ScriptMoveToEntity( Entity* entity );
    int                  ScriptMoveSync();
    void                 UnsetMove();

    // linear related
    void                 ScriptLinearToPosition( const float x, const float y, const float z, const LinearMovement movement, const char* animation );
    int                  ScriptLinearSync();
    void                 SetLinear( const Ogre::Vector3& end, const LinearMovement movement, const Ogre::String& animation );
    void                 UnsetLinear();
    LinearMovement       GetLinearMovement() const;
    const Ogre::Vector3& GetLinearStart() const;
    const Ogre::Vector3& GetLinearEnd() const;

    // jump related
    void                 ScriptJumpToPosition( const float x, const float y, const float z,const float seconds );
    int                  ScriptJumpSync();
    void                 SetJump( const Ogre::Vector3& jump_to, const float seconds );
    void                 UnsetJump();
    const Ogre::Vector3& GetJumpStart() const;
    const Ogre::Vector3& GetJumpEnd() const;
    float                GetJumpSeconds() const;
    void                 SetJumpCurrentSeconds( const float seconds );
    float                GetJumpCurrentSeconds() const;

    // offset related
    void                 ScriptOffsetToPosition( const float x, const float y, const float z, const ActionType type, const float seconds );
    int                  ScriptOffsetSync();
    void                 UnsetOffset();
    const Ogre::Vector3& GetOffsetPositionStart() const;
    const Ogre::Vector3& GetOffsetPositionEnd() const;
    ActionType           GetOffsetType() const;
    float                GetOffsetSeconds() const;
    void                 SetOffsetCurrentSeconds( const float seconds );
    float                GetOffsetCurrentSeconds() const;

    // turn related
    void                 ScriptTurnToDirection( const float direction, const TurnDirection turn_direction, const ActionType turn_type, const float seconds );
    void                 ScriptTurnToEntity( Entity* entity, const TurnDirection turn_direction, const float seconds );
    int                  ScriptTurnSync();
    void                 SetTurn( const Ogre::Degree& direction_to, Entity* entity, const TurnDirection turn_direction, const ActionType turn_type, const float seconds );
    void                 UnsetTurn();
    Ogre::Degree         CalculateTurnAngle( const Ogre::Degree& start, const Ogre::Degree& end ) const;
    Ogre::Degree         GetTurnDirectionStart() const;
    Ogre::Degree         GetTurnDirectionEnd() const;
    ActionType           GetTurnType() const;
    float                GetTurnSeconds() const;
    void                 SetTurnCurrentSeconds( const float seconds );
    float                GetTurnCurrentSeconds() const;

    // animation related
    const Ogre::String&  GetDefaultAnimationName() const;
    const Ogre::String&  GetCurrentAnimationName() const;
    AnimationState       GetAnimationState() const;
    virtual void         PlayAnimation( const Ogre::String& animation, AnimationState state, AnimationPlayType play_type, const float start, const float end ) = 0;
    virtual void         PlayAnimationContinue( const Ogre::String& animation ) = 0;
    virtual void         UpdateAnimation( const float delta ) = 0;
    void                 ScriptPlayAnimation( const char* name );
    void                 ScriptPlayAnimationStop( const char* name );
    void                 ScriptPlayAnimation( const char* name, const float start, const float end );
    void                 ScriptPlayAnimationStop( const char* name, const float start, const float end );
    void                 ScriptSetDefaultAnimation( const char* animation );
    int                  ScriptAnimationSync();

private:
    Entity();
    Ogre::Degree         GetDirectionToEntity( Entity* entity ) const;

protected:
    Ogre::String            m_Name;

    Ogre::SceneNode*        m_SceneNode;
    Ogre::SceneNode*        m_ModelNode;

    // height related
    float                   m_Height;

    Ogre::SceneNode*        m_DirectionNode;
    EntityDirection*        m_Direction;

    // collision related
    Ogre::SceneNode*        m_SolidCollisionNode;
    EntityCollision*        m_SolidCollision;
    float                   m_SolidRadius;
    bool                    m_Solid;

    // talk related
    Ogre::SceneNode*        m_TalkCollisionNode;
    EntityCollision*        m_TalkCollision;
    float                   m_TalkRadius;
    bool                    m_Talkable;

    // move state related
    State                   m_State;
    std::vector< ScriptId > m_Sync;

    // move related
    float                   m_MoveSpeed;
    float                   m_MoveSpeedRun;
    Ogre::Vector3           m_MovePosition;
    Entity*                 m_MoveEntity;
    float                   m_MoveStopDistance;
    int                     m_MoveTriangleId;
    bool                    m_MoveAutoRotation;
    bool                    m_MoveAutoAnimation;
    Ogre::String            m_MoveAnimationWalk;
    Ogre::String            m_MoveAnimationRun;

    // linear movement related
    LinearMovement          m_LinearMovement;
    Ogre::Vector3           m_LinearStart;
    Ogre::Vector3           m_LinearEnd;

    // jump related
    Ogre::Vector3           m_JumpStart;
    Ogre::Vector3           m_JumpEnd;
    float                   m_JumpSeconds;
    float                   m_JumpCurrentSeconds;

    // offset related
    Ogre::Vector3           m_OffsetPositionStart;
    Ogre::Vector3           m_OffsetPositionEnd;
    ActionType              m_OffsetType;
    float                   m_OffsetSeconds;
    float                   m_OffsetCurrentSeconds;
    std::vector< ScriptId > m_OffsetSync;

    // turn related
    TurnDirection           m_TurnDirection;
    Ogre::Degree            m_TurnDirectionStart;
    Ogre::Degree            m_TurnDirectionEnd;
    Entity*                 m_TurnEntity;
    ActionType              m_TurnType;
    float                   m_TurnSeconds;
    float                   m_TurnCurrentSeconds;
    std::vector< ScriptId > m_TurnSync;

    // animation
    Ogre::String            m_AnimationCurrentName;
    std::vector< ScriptId > m_AnimationSync;
    AnimationState          m_AnimationState;
    AnimationPlayType       m_AnimationPlayType;
    Ogre::String            m_AnimationDefault;
    float                   m_AnimationEndTime;
    bool                    m_AnimationAutoPlay;
};



#endif // ENTITY_H
