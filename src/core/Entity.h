#ifndef ENTITY_H
#define ENTITY_H

#include <OgreString.h>

#include "EntityCollision.h"
#include "EntityDirection.h"
#include "ScriptManager.h"



enum EntityAnimation
{
    DEFAULT,
    ONCE
};



enum MoveState
{
    NONE,
    MOVE_WALKMESH,
    MOVE_LINEAR,
    JUMP
};



class Entity
{
public:
                        Entity( const Ogre::String& name, Ogre::SceneNode* node );
    virtual             ~Entity();

    virtual void        Update();

    const Ogre::String& GetName() const;

    void                SetPosition( const Ogre::Vector3& position );
    void                ScriptSetPosition( const float x, const float y, const float z );
    const Ogre::Vector3 GetPosition() const;

    void                SetOffset( const Ogre::Vector3& position );
    const Ogre::Vector3 GetOffset() const;

    void                SetDirection( const Ogre::Degree& direction );
    void                ScriptSetDirection( const float direction );
    const Ogre::Degree  GetDirection() const;

    // height related
    const float         GetHeight() const;

    // solid related
    void                SetSolidRadius( const float radius );
    const float         GetSolidRadius() const;
    void                SetSolid( const bool solid );
    const bool          IsSolid() const;

    // talk related
    void                SetTalkRadius( const float radius );
    const float         GetTalkRadius() const;
    void                SetTalkable( const bool talkable );
    const bool          IsTalkable() const;

    // model related
    virtual void        SetVisible( const bool visible ) = 0;
    virtual const bool  IsVisible() const = 0;

    // movement related
    void                SetMoveState( const MoveState state );
    const MoveState     GetMoveState() const;
    void                SetMoveSpeed( const float speed );
    const float         GetMoveSpeed() const;
    void                SetMoveTarget( const Ogre::Vector3& target );
    const Ogre::Vector3 GetMoveTarget() const;
    void                SetMoveTriangleId( const int triangle );
    const int           GetMoveTriangleId() const;
    void                SetMoveAutoRotation( const bool rotate );
    const bool          GetMoveAutoRotation() const;
    void                ScriptMoveWalkmesh( const float x, const float y );

    // animation related
    const Ogre::String& GetCurrentAnimationName() const;
    virtual void        PlayAnimation( const Ogre::String& animation, EntityAnimation state, const float start, const float end ) = 0;
    void                ScriptPlayAnimation( const char* name );
    void                ScriptPlayAnimationStop( const char* name );
    void                ScriptPlayAnimation( const char* name, const float start, const float end );
    void                ScriptPlayAnimationStop( const char* name, const float start, const float end );
    void                ScriptSetDefaultAnimation( const char* animation );
    const int           ScriptAnimationSync();

private:
    Entity();

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

    // move related
    MoveState               m_MoveState;
    float                   m_MoveSpeed;
    Ogre::Vector3           m_MoveTarget;
    int                     m_MoveTriangleId;
    bool                    m_MoveAutoRotation;

    // animation
    Ogre::String            m_AnimationCurrentName;
    std::vector< ScriptId > m_AnimationSync;
    EntityAnimation         m_AnimationState;
    Ogre::String            m_AnimationDefault;
    float                   m_AnimationEndTime;
};



#endif // ENTITY_H
