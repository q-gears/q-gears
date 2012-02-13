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

    m_SolidRadius( 1 ),
    m_Solid( false ),

    m_TalkRadius( 0.25f ),
    m_Talkable( false ),

    m_MoveState( NONE ),
    m_MoveSpeed( 0.5f ),
    m_MoveSpeedRun( 1.5f ),
    m_MoveTarget( Ogre::Vector3( 0, 0, 0 ) ),
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

    m_AnimationDefault( "Idle" ),
    m_AnimationCurrentName( "" )
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

        static Ogre::String move_state_string[] = { "NONE", "MOVE_WALKMESH", "MOVE_LINEAR", "JUMP" };

        DEBUG_DRAW.Text( entity_pos, 0, 24, "Move state: " + move_state_string[ m_MoveState ] );
        DEBUG_DRAW.Text( entity_pos, 0, 36, Ogre::StringConverter::toString( entity_pos ) );
        if( m_MoveState == MOVE_WALKMESH )
        {
            DEBUG_DRAW.Text( entity_pos, 0, 48, "Triangle: " + Ogre::StringConverter::toString( m_MoveTriangleId ) );
            DEBUG_DRAW.Text( entity_pos, 0, 60, "Target: " + Ogre::StringConverter::toString( m_MoveTarget ) );
        }
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



const Ogre::Degree
Entity::GetDirection() const
{
    Ogre::Quaternion q = m_ModelNode->getOrientation();
    Ogre::Degree temp;
    Ogre::Vector3 vec = Ogre::Vector3::UNIT_Z;
    q.ToAngleAxis( temp, vec );

    return temp;
}



const float
Entity::GetHeight() const
{
    return m_Height;
}



void
Entity::SetSolidRadius( const float radius )
{
    m_SolidRadius = radius;
    m_SolidCollisionNode->setScale( m_SolidRadius * 2, m_SolidRadius * 2, m_Height );
}



const float
Entity::GetSolidRadius() const
{
    return m_SolidRadius;
}



void
Entity::SetSolid( const bool solid )
{
    m_Solid = solid;
}



const bool
Entity::IsSolid() const
{
    return m_Solid;
}



void
Entity::SetTalkRadius( const float radius )
{
    m_TalkRadius = radius;
    m_TalkCollisionNode->setScale( m_TalkRadius * 2, m_TalkRadius * 2, m_Height );
}



const float
Entity::GetTalkRadius() const
{
    return m_TalkRadius;
}



void
Entity::SetTalkable( const bool talkable )
{
    m_Talkable = talkable;
}



const bool
Entity::IsTalkable() const
{
    return m_Talkable;
}



void
Entity::SetMoveState( const MoveState state )
{
    m_MoveState = state;
}



const MoveState
Entity::GetMoveState() const
{
    return m_MoveState;
}



void
Entity::SetMoveSpeed( const float speed )
{
    m_MoveSpeed = speed;
}



const float
Entity::GetMoveSpeed() const
{
    return m_MoveSpeed;
}



void
Entity::SetMoveSpeedRun( const float speed )
{
    m_MoveSpeedRun = speed;
}



const float
Entity::GetMoveSpeedRun() const
{
    return m_MoveSpeedRun;
}



void
Entity::SetMoveTarget( const Ogre::Vector3& target )
{
    m_MoveTarget = target;
}



const Ogre::Vector3
Entity::GetMoveTarget() const
{
    return m_MoveTarget;
}



void
Entity::SetMoveTriangleId( const int triangle )
{
    m_MoveTriangleId = triangle;
}



const int
Entity::GetMoveTriangleId() const
{
    return m_MoveTriangleId;
}



void
Entity::SetMoveAutoRotation( const bool rotate )
{
    m_MoveAutoRotation = rotate;
}



const bool
Entity::GetMoveAutoRotation() const
{
    return m_MoveAutoRotation;
}



void
Entity::SetMoveAutoAnimation( const bool animate )
{
    m_MoveAutoAnimation = animate;
}



const bool
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
Entity::ScriptMoveWalkmesh( const float x, const float y )
{
    m_MoveTarget = Ogre::Vector3( x, y, 0 );
    m_MoveState = MOVE_WALKMESH;
    LOG_TRIVIAL( "[SCRIPT] Entity \"" + m_Name + "\" set move to walkmesh position \"" + Ogre::StringConverter::toString( m_MoveTarget ) + "\"." );
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



const int
Entity::ScriptOffsetSync()
{
    ScriptId script = ScriptManager::getSingleton().GetCurrentScriptId();

    LOG_TRIVIAL( "[SCRIPT] Wait entity \"" + m_Name + "\" offset for function \"" + script.function + "\" in script entity \"" + script.entity + "\"." );

    m_OffsetSync.push_back( script );
    return -1;
}



void
Entity::UnsetOffseting()
{
    m_OffsetType = AT_NONE;

    for( int i = 0; i < m_OffsetSync.size(); ++i)
    {
        ScriptManager::getSingleton().ContinueScriptExecution( m_OffsetSync[ i ] );
    }
    m_OffsetSync.clear();
}



const Ogre::Vector3
Entity::GetOffsetPositionStart() const
{
    return m_OffsetPositionStart;
}



const Ogre::Vector3
Entity::GetOffsetPositionEnd() const
{
    return m_OffsetPositionEnd;
}



const ActionType
Entity::GetOffsetType() const
{
    return m_OffsetType;
}



const float
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



const float
Entity::GetOffsetCurrentStepSeconds() const
{
    return m_OffsetCurrentStepSeconds;
}



const Ogre::String&
Entity::GetCurrentAnimationName() const
{
    return m_AnimationCurrentName;
}



void
Entity::ScriptPlayAnimation( const char* name )
{
    PlayAnimation( Ogre::String( name ), DEFAULT, 0, -1 );
}



void
Entity::ScriptPlayAnimationStop( const char* name )
{
    PlayAnimation( Ogre::String( name ), ONCE, 0, -1 );
}



void
Entity::ScriptPlayAnimation( const char* name, const float start, const float end )
{
    PlayAnimation( Ogre::String( name ), DEFAULT, start, end );
}



void
Entity::ScriptPlayAnimationStop( const char* name, const float start, const float end )
{
    PlayAnimation( Ogre::String( name ), ONCE, start, end );
}



void
Entity::ScriptSetDefaultAnimation( const char* animation )
{
    m_AnimationDefault = Ogre::String( animation );
}



const int
Entity::ScriptAnimationSync()
{
    ScriptId script = ScriptManager::getSingleton().GetCurrentScriptId();

    LOG_TRIVIAL( "[SCRIPT] Wait entity \"" + m_Name + "\" animation for function \"" + script.function + "\" in script entity \"" + script.entity + "\"." );

    m_AnimationSync.push_back( script );
    return -1;
}
