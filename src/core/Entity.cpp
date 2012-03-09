#include "Entity.h"

#include <OgreSceneNode.h>

#include "ConfigVar.h"
#include "DebugDraw.h"
#include "Logger.h"



ConfigVar cv_debug_entity( "debug_entity", "Draw entity debug info", "false" );



Entity::Entity( const Ogre::String& name, Ogre::SceneNode* node ):
    m_Name( name ),
    m_SceneNode( node ),

    m_Height( 1 ),

    m_SolidRadius( 0.2 ),
    m_Solid( false ),

    m_TalkRadius( 0.25f ),
    m_Talkable( false ),

    m_State( ES_NONE ),

    m_MoveSpeed( 0.9f ),
    m_MoveSpeedRun( 3.6f ),
    m_MovePosition( Ogre::Vector3( 0, 0, 0 ) ),
    m_MoveEntity( NULL ),
    m_MoveStopDistance( 0 ),
    m_MoveTriangleId( -1 ),
    m_MoveAutoRotation( true ),
    m_MoveAutoAnimation( true ),
    m_MoveAnimationIdle( "Idle" ),
    m_MoveAnimationWalk( "Walk" ),
    m_MoveAnimationRun( "Run" ),

    m_OffsetPositionStart( 0.0f, 0.0f, 0.0f ),
    m_OffsetPositionEnd( 0.0f, 0.0f, 0.0f ),
    m_OffsetType( AT_NONE ),
    m_OffsetStepSeconds( 0 ),
    m_OffsetCurrentStepSeconds( 0 ),

    m_TurnDirection( TD_CLOSEST ),
    m_TurnDirectionStart( 0 ),
    m_TurnDirectionEnd( 0 ),
    m_TurnEntity( NULL ),
    m_TurnType( AT_NONE ),
    m_TurnStepSeconds( 0 ),
    m_TurnCurrentStepSeconds( 0 ),

    m_LinearMovement( LM_UP_TO_DOWN ),
    m_LinearStart( 0.0f, 0.0f, 0.0f ),
    m_LinearEnd( 0.0f, 0.0f, 0.0f ),

    m_AnimationDefault( "Idle" ),
    m_AnimationCurrentName( "" ),
    m_AnimationAutoPlay( true )
{
    m_ModelNode = m_SceneNode->createChildSceneNode();

    m_Direction = new EntityDirection();
    m_Direction->setMaterial( "entity/direction" );
    m_DirectionNode = m_SceneNode->createChildSceneNode();
    m_DirectionNode->attachObject( m_Direction );

    m_SolidCollision = new EntityCollision();
    m_SolidCollision->setMaterial( "entity/solid_collision" );
    m_SolidCollisionNode = m_SceneNode->createChildSceneNode();
    m_SolidCollisionNode->setScale( m_SolidRadius, m_SolidRadius, m_Height );
    m_SolidCollisionNode->attachObject( m_SolidCollision );

    m_TalkCollision = new EntityCollision();
    m_TalkCollision->setMaterial( "entity/talk_collision" );
    m_TalkCollisionNode = m_SceneNode->createChildSceneNode();
    m_TalkCollisionNode->setScale( m_TalkRadius, m_TalkRadius, m_Height );
    m_TalkCollisionNode->attachObject( m_TalkCollision );

    m_ModelNode->setPosition( Ogre::Vector3::ZERO );
    m_SceneNode->setPosition( Ogre::Vector3::ZERO );

    LOG_TRIVIAL( "Entity \"" + m_Name + "\" created." );
}



Entity::~Entity()
{
    delete m_SolidCollision;
    delete m_TalkCollision;

    m_SceneNode->removeAndDestroyAllChildren();

    LOG_TRIVIAL( "Entity \"" + m_Name + "\" destroyed." );
}



void
Entity::Update()
{
    m_DirectionNode->setVisible( cv_debug_entity.GetB() );
    m_SolidCollisionNode->setVisible( cv_debug_entity.GetB() & m_Solid );
    m_TalkCollisionNode->setVisible( cv_debug_entity.GetB() & m_Talkable );

    // debug output
    if( cv_debug_entity.GetB() == true )
    {
        DEBUG_DRAW.SetColour( Ogre::ColourValue::White );
        DEBUG_DRAW.SetScreenSpace( true );
        DEBUG_DRAW.SetTextAlignment( DEBUG_DRAW.CENTER );
        DEBUG_DRAW.SetFadeDistance( 20, 30 );

        Ogre::Vector3 entity_pos = GetPosition();

        DEBUG_DRAW.Text( entity_pos, 0, 0, m_Name );
        DEBUG_DRAW.Text( entity_pos, 0, 12, m_AnimationCurrentName );

        static Ogre::String move_state_string[] = { "NONE", "MOVE_WALKMESH", "MOVE_LINEAR", "MOVE_JUMP" };

        DEBUG_DRAW.Text( entity_pos, 0, 24, "Move state: " + move_state_string[ m_State ] );
        DEBUG_DRAW.Text( entity_pos, 0, 36, Ogre::StringConverter::toString( entity_pos ) );
        switch( m_State )
        {
            case ES_WALKMESH:
            {
                DEBUG_DRAW.Text( entity_pos, 0, 48, "Triangle: " + Ogre::StringConverter::toString( m_MoveTriangleId ) );
                DEBUG_DRAW.Text( entity_pos, 0, 60, "Target position: " + Ogre::StringConverter::toString( m_MovePosition ) );
            }
            break;

            case ES_LINEAR:
            {
                DEBUG_DRAW.Text( m_LinearStart, 0, 0, "Start: " + Ogre::StringConverter::toString( m_LinearStart ) );
                DEBUG_DRAW.Text( m_LinearEnd, 0, 0, "End: " + Ogre::StringConverter::toString( m_LinearEnd ) );
                DEBUG_DRAW.Line3d( m_LinearStart, m_LinearEnd );
            }
            break;
        }
    }



    if( m_MoveEntity != NULL )
    {
        m_MovePosition = m_MoveEntity->GetPosition();
        m_MoveStopDistance = GetSolidRadius() + m_MoveEntity->GetSolidRadius();
    }



    if( m_TurnEntity != NULL )
    {
        Ogre::Degree angle = GetDirectionToEntity( m_TurnEntity );

        angle = CalculateTurnAngle( m_TurnDirectionStart, angle );

        m_TurnDirectionEnd = angle;
    }
}



const Ogre::String&
Entity::GetName() const
{
    return m_Name;
}



void
Entity::SetPosition( const Ogre::Vector3& position )
{
    m_SceneNode->setPosition( position );
}



void
Entity::ScriptSetPosition( const float x, const float y, const float z )
{
    SetPosition( Ogre::Vector3( x, y, z ) );
}



const Ogre::Vector3
Entity::GetPosition() const
{
    return m_SceneNode->getPosition();
}



void
Entity::SetOffset( const Ogre::Vector3& position )
{
    m_ModelNode->setPosition( position );
}



const Ogre::Vector3
Entity::GetOffset() const
{
    return m_ModelNode->getPosition();
}



void
Entity::SetDirection( const Ogre::Degree& direction )
{
    float angle = direction.valueDegrees() - Ogre::Math::Floor( direction.valueDegrees() / 360.0f ) * 360.0f;

    if( angle < 0 )
    {
        angle = 360 + angle;
    }

    Ogre::Quaternion q;
    Ogre::Vector3 vec = Ogre::Vector3::UNIT_Z;
    q.FromAngleAxis( Ogre::Radian( Ogre::Degree( angle ) ), vec );
    m_ModelNode->setOrientation( q );
    m_DirectionNode->setOrientation( q );
}



void
Entity::ScriptSetDirection( const float direction )
{
    SetDirection( Ogre::Degree( direction ) );
}



Ogre::Degree
Entity::GetDirection() const
{
    Ogre::Quaternion q = m_ModelNode->getOrientation();
    Ogre::Degree temp;
    Ogre::Vector3 vec = Ogre::Vector3::UNIT_Z;
    q.ToAngleAxis( temp, vec );

    return temp;
}



float
Entity::GetHeight() const
{
    return m_Height;
}



void
Entity::SetSolidRadius( const float radius )
{
    m_SolidRadius = radius;
    m_SolidCollisionNode->setScale( m_SolidRadius, m_SolidRadius, m_Height );
}



float
Entity::GetSolidRadius() const
{
    return m_SolidRadius;
}



void
Entity::SetSolid( const bool solid )
{
    m_Solid = solid;
}



bool
Entity::IsSolid() const
{
    return m_Solid;
}



void
Entity::SetTalkRadius( const float radius )
{
    m_TalkRadius = radius;
    m_TalkCollisionNode->setScale( m_TalkRadius, m_TalkRadius, m_Height );
}



float
Entity::GetTalkRadius() const
{
    return m_TalkRadius;
}



void
Entity::SetTalkable( const bool talkable )
{
    m_Talkable = talkable;
}



bool
Entity::IsTalkable() const
{
    return m_Talkable;
}



void
Entity::SetState( const EntityState state )
{
    m_State = state;
}



EntityState
Entity::GetState() const
{
    return m_State;
}



void
Entity::SetMoveSpeed( const float speed )
{
    m_MoveSpeed = speed;
}



float
Entity::GetMoveSpeed() const
{
    return m_MoveSpeed;
}



void
Entity::SetMoveSpeedRun( const float speed )
{
    m_MoveSpeedRun = speed;
}



float
Entity::GetMoveSpeedRun() const
{
    return m_MoveSpeedRun;
}



void
Entity::SetMovePosition( const Ogre::Vector3& target )
{
    m_MovePosition = target;
}



const Ogre::Vector3&
Entity::GetMovePosition() const
{
    return m_MovePosition;
}



void
Entity::SetMoveTriangleId( const int triangle )
{
    m_MoveTriangleId = triangle;
}



int
Entity::GetMoveTriangleId() const
{
    return m_MoveTriangleId;
}



void
Entity::SetMoveAutoRotation( const bool rotate )
{
    m_MoveAutoRotation = rotate;
}



bool
Entity::GetMoveAutoRotation() const
{
    return m_MoveAutoRotation;
}



void
Entity::SetMoveAutoAnimation( const bool animate )
{
    m_MoveAutoAnimation = animate;
}



bool
Entity::GetMoveAutoAnimation() const
{
    return m_MoveAutoAnimation;
}



const Ogre::String&
Entity::GetMoveAnimationIdleName() const
{
    return m_MoveAnimationIdle;
}



const Ogre::String&
Entity::GetMoveAnimationWalkName() const
{
    return m_MoveAnimationWalk;
}



const Ogre::String&
Entity::GetMoveAnimationRunName() const
{
    return m_MoveAnimationRun;
}



void
Entity::ScriptMoveToPosition( const float x, const float y )
{
    m_State = ES_WALKMESH;

    m_MovePosition = Ogre::Vector3( x, y, 0 );
    m_MoveEntity = NULL;
    m_MoveStopDistance = 0;
    LOG_TRIVIAL( "[SCRIPT] Entity \"" + m_Name + "\" set move to walkmesh position \"" + Ogre::StringConverter::toString( m_MovePosition ) + "\"." );
}



void
Entity::ScriptMoveToEntity( Entity* entity )
{
    m_State = ES_WALKMESH;

    m_MovePosition = entity->GetPosition();
    m_MoveEntity = entity;
    m_MoveStopDistance = GetSolidRadius() + entity->GetSolidRadius();
    LOG_TRIVIAL( "[SCRIPT] Entity \"" + m_Name + "\" set move to entity \"" + entity->GetName() + "\"." );
}



int
Entity::ScriptMoveSync()
{
    ScriptId script = ScriptManager::getSingleton().GetCurrentScriptId();

    LOG_TRIVIAL( "[SCRIPT] Wait entity \"" + m_Name + "\" move for function \"" + script.function + "\" in script entity \"" + script.entity + "\"." );

    m_Sync.push_back( script );
    return -1;
}



void
Entity::UnsetMove()
{
    m_State = ES_NONE;

    m_MoveEntity = NULL;
    m_MoveStopDistance = 0;

    for( size_t i = 0; i < m_Sync.size(); ++i)
    {
        ScriptManager::getSingleton().ContinueScriptExecution( m_Sync[ i ] );
    }
    m_Sync.clear();
}



void
Entity::ScriptLinearToPosition( const float x, const float y, const float z, const LinearMovement movement, const char* animation )
{
    Ogre::Vector3 pos = Ogre::Vector3( x, y, z );
    SetLinear( pos, movement, Ogre::String( animation ) );

    LOG_TRIVIAL( "[SCRIPT] Entity \"" + m_Name + "\" set linear move to position \"" + Ogre::StringConverter::toString( pos ) + "\" with animation \"" + animation + "\"." );
}



int
Entity::ScriptLinearSync()
{
    ScriptId script = ScriptManager::getSingleton().GetCurrentScriptId();

    LOG_TRIVIAL( "[SCRIPT] Wait entity \"" + m_Name + "\" linear move for function \"" + script.function + "\" in script entity \"" + script.entity + "\"." );

    m_Sync.push_back( script );
    return -1;
}



void
Entity::SetLinear( const Ogre::Vector3& end, const LinearMovement movement, const Ogre::String& animation )
{
    m_State = ES_LINEAR;
    m_LinearMovement = movement;
    m_LinearStart = GetPosition();
    m_LinearEnd = end;

    // linear animation
    m_AnimationAutoPlay = false;
    PlayAnimation( animation, EA_LOOPED, 0, -1 );

    // after move we need reattach entity to walkmesh
    m_MoveTriangleId = -1;
}



void
Entity::UnsetLinear()
{
    m_State = ES_NONE;

    // linear animation
    m_AnimationAutoPlay = true;
    PlayAnimation( m_AnimationDefault, EA_LOOPED, 0, -1 );

    for( size_t i = 0; i < m_Sync.size(); ++i)
    {
        ScriptManager::getSingleton().ContinueScriptExecution( m_Sync[ i ] );
    }
    m_Sync.clear();
}



LinearMovement
Entity::GetLinearMovement() const
{
    return m_LinearMovement;
}



const Ogre::Vector3&
Entity::GetLinearStart() const
{
    return m_LinearStart;
}



const Ogre::Vector3&
Entity::GetLinearEnd() const
{
    return m_LinearEnd;
}



void
Entity::ScriptOffsetToPosition( const float x, const float y, const float z, const ActionType type, const float seconds )
{
    LOG_TRIVIAL( "[SCRIPT] Entity \"" + m_Name + "\" set offset to position \"" + Ogre::StringConverter::toString( Ogre::Vector3( x, y, z ) ) + "'." );

    Ogre::Vector3 position = Ogre::Vector3( x, y, z );

    if( type == AT_NONE )
    {
        this->SetOffset( position );
        return;
    }

    m_OffsetPositionStart = GetOffset();
    m_OffsetPositionEnd = position;
    m_OffsetType = type;
    m_OffsetStepSeconds = seconds;
    m_OffsetCurrentStepSeconds = 0;
}



int
Entity::ScriptOffsetSync()
{
    ScriptId script = ScriptManager::getSingleton().GetCurrentScriptId();

    LOG_TRIVIAL( "[SCRIPT] Wait entity \"" + m_Name + "\" offset for function \"" + script.function + "\" in script entity \"" + script.entity + "\"." );

    m_OffsetSync.push_back( script );
    return -1;
}



void
Entity::UnsetOffset()
{
    m_OffsetType = AT_NONE;

    for( size_t i = 0; i < m_OffsetSync.size(); ++i)
    {
        ScriptManager::getSingleton().ContinueScriptExecution( m_OffsetSync[ i ] );
    }
    m_OffsetSync.clear();
}



const Ogre::Vector3&
Entity::GetOffsetPositionStart() const
{
    return m_OffsetPositionStart;
}



const Ogre::Vector3&
Entity::GetOffsetPositionEnd() const
{
    return m_OffsetPositionEnd;
}



ActionType
Entity::GetOffsetType() const
{
    return m_OffsetType;
}



float
Entity::GetOffsetStepSeconds() const
{
    return m_OffsetStepSeconds;
}



void
Entity::SetOffsetCurrentStepSeconds( const float seconds )
{
    m_OffsetCurrentStepSeconds = ( seconds > m_OffsetStepSeconds ) ? m_OffsetStepSeconds : seconds;
    m_OffsetCurrentStepSeconds = ( m_OffsetCurrentStepSeconds < 0 ) ? 0 : m_OffsetCurrentStepSeconds;
}



float
Entity::GetOffsetCurrentStepSeconds() const
{
    return m_OffsetCurrentStepSeconds;
}



void
Entity::ScriptTurnToDirection( const float direction, const TurnDirection turn_direction, const ActionType turn_type, const float seconds )
{
    SetTurn( Ogre::Degree( direction ), NULL, turn_direction, turn_type, seconds );
    LOG_TRIVIAL("[SCRIPT] Entity \"" + m_Name + "\" turn to angle \"" + Ogre::StringConverter::toString( direction ) + "\".");
}



void
Entity::ScriptTurnToEntity( Entity* entity, const TurnDirection turn_direction, const float seconds )
{
    if( entity == NULL || entity == this )
    {
        LOG_ERROR("[SCRIPT] Turn to entity: Invalid entity pointer (NUUL or this).");
        return;
    }

    Ogre::Degree angle = GetDirectionToEntity( entity );
    SetTurn( angle, entity, turn_direction, AT_SMOOTH, seconds );
    LOG_TRIVIAL( "[SCRIPT] Entity \"" + m_Name + "\" turn to entity \"" + entity->GetName() + ".");
}



int
Entity::ScriptTurnSync()
{
    ScriptId script = ScriptManager::getSingleton().GetCurrentScriptId();

    LOG_TRIVIAL( "[SCRIPT] Wait entity \"" + m_Name + "\" turn for function \"" + script.function + "\" in script entity \"" + script.entity + "\"." );

    m_TurnSync.push_back( script );
    return -1;
}



void
Entity::SetTurn( const Ogre::Degree& direction_to, Entity* entity, const TurnDirection turn_direction, const ActionType turn_type, const float seconds )
{
    if( turn_type == AT_NONE )
    {
        SetDirection( direction_to );
        return;
    }

    m_TurnDirection = turn_direction;

    Ogre::Degree angle_start = GetDirection();
    Ogre::Degree angle_end = CalculateTurnAngle( angle_start, direction_to );

    m_TurnEntity = entity;
    m_TurnDirectionStart = angle_start;
    m_TurnDirectionEnd = angle_end;
    m_TurnType = turn_type;
    m_TurnStepSeconds = seconds;
    m_TurnCurrentStepSeconds = 0;
}



void
Entity::UnsetTurn()
{
    m_TurnType = AT_NONE;

    for( size_t i = 0; i < m_TurnSync.size(); ++i)
    {
        ScriptManager::getSingleton().ContinueScriptExecution( m_TurnSync[ i ] );
    }
    m_TurnSync.clear();
}



Ogre::Degree
Entity::CalculateTurnAngle( const Ogre::Degree& start, const Ogre::Degree& end ) const
{
    Ogre::Degree ret = end;

    switch( m_TurnDirection )
    {
        case TD_CLOCKWISE:
        {
            if( end <= start )
            {
                ret = end + Ogre::Degree( 360 );
            }
        }
        break;

        case TD_ANTICLOCKWISE:
        {
            if( end >= start )
            {
                ret = end - Ogre::Degree( 360 );
            }
        }
        break;

        case TD_CLOSEST:
        {
            Ogre::Degree delta = end - start;

            delta = ( delta < Ogre::Degree( 0 ) ) ? -delta : delta;

            if( delta > Ogre::Degree( 180 ) )
            {
                if( start < end )
                {
                    ret = end - Ogre::Degree( 360 );
                }
                else
                {
                    ret = end + Ogre::Degree( 360 );
                }
            }
        }
        break;
    }

    return ret;
}



Ogre::Degree
Entity::GetTurnDirectionStart() const
{
    return m_TurnDirectionStart;
}



Ogre::Degree
Entity::GetTurnDirectionEnd() const
{
    return m_TurnDirectionEnd;
}



ActionType
Entity::GetTurnType() const
{
    return m_TurnType;
}



float
Entity::GetTurnStepSeconds() const
{
    return m_TurnStepSeconds;
}



void
Entity::SetTurnCurrentStepSeconds( const float seconds )
{
    m_TurnCurrentStepSeconds = ( seconds > m_TurnStepSeconds ) ? m_TurnStepSeconds : seconds;
    m_TurnCurrentStepSeconds = ( m_TurnCurrentStepSeconds < 0 ) ? 0 : m_TurnCurrentStepSeconds;
}



float
Entity::GetTurnCurrentStepSeconds() const
{
    return m_TurnCurrentStepSeconds;
}



const Ogre::String&
Entity::GetCurrentAnimationName() const
{
    return m_AnimationCurrentName;
}



void
Entity::ScriptPlayAnimation( const char* name )
{
    PlayAnimation( Ogre::String( name ), EA_DEFAULT, 0, -1 );
}



void
Entity::ScriptPlayAnimationStop( const char* name )
{
    PlayAnimation( Ogre::String( name ), EA_ONCE, 0, -1 );
}



void
Entity::ScriptPlayAnimation( const char* name, const float start, const float end )
{
    PlayAnimation( Ogre::String( name ), EA_DEFAULT, start, end );
}



void
Entity::ScriptPlayAnimationStop( const char* name, const float start, const float end )
{
    PlayAnimation( Ogre::String( name ), EA_ONCE, start, end );
}



void
Entity::ScriptSetDefaultAnimation( const char* animation )
{
    m_AnimationDefault = Ogre::String( animation );
}



int
Entity::ScriptAnimationSync()
{
    ScriptId script = ScriptManager::getSingleton().GetCurrentScriptId();

    LOG_TRIVIAL( "[SCRIPT] Wait entity \"" + m_Name + "\" animation for function \"" + script.function + "\" in script entity \"" + script.entity + "\"." );

    m_AnimationSync.push_back( script );
    return -1;
}



Ogre::Degree
Entity::GetDirectionToEntity( Entity* entity ) const
{
    Ogre::Vector3 current_point = GetPosition();
    Ogre::Vector3 direction_point = entity->GetPosition();

    Ogre::Vector2 up(0.0f, -1.0f);
    Ogre::Vector2 dir( direction_point.x - current_point.x, direction_point.y - current_point.y );
    // angle between vectors
    Ogre::Degree angle( Ogre::Radian( acosf( dir.dotProduct( up ) / ( dir.length() * up.length() ) ) ) );
    return ( dir.x < 0 ) ? Ogre::Degree( 360 ) - angle : angle;
}
