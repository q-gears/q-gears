#include "Console.h"
#include "Logger.h"
#include "Entity.h"
#include "EntityManager.h"
#include "UiManager.h"
#include "UiWidget.h"
#include "XmlMapFile.h"
#include "XmlMapsFile.h"



void
ScriptPrint( const char* text )
{
    Console::getSingleton().AddTextToOutput( text );
}



void
ScriptMap( const char* text )
{
    EntityManager::getSingleton().Clear();

    XmlMapsFile xml( "./data/maps.xml" );
    Ogre::String file_name = xml.GetMapFileNameByName( text );

    XmlMapFile xml_map( "./data/" + file_name );
    xml_map.LoadMap();
}



void
ScriptConsole( const char* text )
{
    Console::getSingleton().ExecuteCommand( text );
}



void
ScriptManager::InitBinds()
{
    // globals
    luabind::module( m_LuaState )
    [
        luabind::def( "print", ( void( * )( const char* ) ) &ScriptPrint ),
        luabind::def( "map", ( void( * )( const char* ) ) &ScriptMap ),
        luabind::def( "console", ( void( * )( const char* ) ) &ScriptConsole )
    ];

    // entity access
    luabind::module( m_LuaState )
    [
        luabind::class_< Entity >( "Entity" )
            .def( "set_position", ( void( Entity::* )( const float, const float, const float ) ) &Entity::ScriptSetPosition )
            .def( "set_direction", ( void( Entity::* )( const float ) ) &Entity::ScriptSetDirection )
            .def( "set_solid_radius", ( void( Entity::* )( const float ) ) &Entity::SetSolidRadius )
            .def( "get_solid_radius", ( float( Entity::* )() ) &Entity::GetSolidRadius )
            .def( "set_solid", ( void( Entity::* )( const bool ) ) &Entity::SetSolid )
            .def( "is_solid", ( bool( Entity::* )() ) &Entity::IsSolid )
            .def( "set_talk_radius", ( void( Entity::* )( const float ) ) &Entity::SetTalkRadius )
            .def( "get_talk_radius", ( float( Entity::* )() ) &Entity::GetTalkRadius )
            .def( "set_talkable", ( void( Entity::* )( const bool ) ) &Entity::SetTalkable )
            .def( "is_talkable", ( bool( Entity::* )() ) &Entity::IsTalkable )
            .def( "set_visible", ( void( Entity::* )( const bool ) ) &Entity::SetVisible )
            .def( "is_visible", ( bool( Entity::* )() ) &Entity::IsVisible )
            .def( "set_move_auto_speed", ( void( Entity::* )( const float ) ) &Entity::SetMoveAutoSpeed )
            .def( "get_move_auto_speed", ( float( Entity::* )() ) &Entity::GetMoveAutoSpeed )
            .def( "get_move_triangle_id", ( int( Entity::* )() ) &Entity::GetMoveTriangleId )
            .def( "move_auto_rotation", ( void( Entity::* )( const bool ) ) &Entity::SetMoveAutoRotation )
            .def( "move_auto_animation", ( void( Entity::* )( const bool ) ) &Entity::SetMoveAutoAnimation )
            .def( "move_to_position", ( void( Entity::* )( const float, const float ) ) &Entity::ScriptMoveToPosition )
            .def( "move_to_entity", ( void( Entity::* )( Entity* ) ) &Entity::ScriptMoveToEntity )
            .def( "move_sync", ( int( Entity::* )() ) &Entity::ScriptMoveSync, luabind::yield )
            .def( "linear_to_position", ( void( Entity::* )( const float, const float, const float, const LinearMovement, const char* ) ) &Entity::ScriptLinearToPosition )
            .def( "linear_sync", ( int( Entity::* )() ) &Entity::ScriptLinearSync, luabind::yield )
            .def( "jump_to_position", ( void( Entity::* )( const float, const float, const float, const float ) )&Entity::ScriptJumpToPosition)
            .def( "jump_sync", ( int( Entity::* )() ) &Entity::ScriptJumpSync, luabind::yield )
            .def( "offset_to_position", ( void( Entity::* )( const float, const float, const float, const ActionType, const float ) ) &Entity::ScriptOffsetToPosition )
            .def( "offset_sync", ( int( Entity::* )() ) &Entity::ScriptOffsetSync, luabind::yield )
            .def( "turn_to_entity", ( void( Entity::* )( Entity*, const TurnDirection, const float ) )&Entity::ScriptTurnToEntity )
            .def( "turn_to_direction", ( void( Entity::* )( const float, const TurnDirection, const ActionType, const float ) )&Entity::ScriptTurnToDirection )
            .def( "turn_sync", ( int( Entity::* )() ) &Entity::ScriptTurnSync, luabind::yield )
            .def( "set_animation_speed", ( void( Entity::* )( const float ) ) &Entity::ScriptSetAnimationSpeed )
            .def( "play_animation", ( void( Entity::* )( const char* ) ) &Entity::ScriptPlayAnimation )
            .def( "play_animation_stop", ( void( Entity::* )( const char* ) ) &Entity::ScriptPlayAnimationStop )
            .def( "play_animation", ( void( Entity::* )( const char*, const float, const float ) ) &Entity::ScriptPlayAnimation )
            .def( "play_animation_stop", ( void( Entity::* )( const char*, const float, const float ) ) &Entity::ScriptPlayAnimationStop )
            .def( "set_default_animation", ( void( Entity::* )( const char* ) ) &Entity::ScriptSetDefaultAnimation )
            .def( "animation_sync", ( int( Entity::* )()) &Entity::ScriptAnimationSync, luabind::yield )

            .enum_( "constants" )
            [
                luabind::value( "NONE", AT_NONE ),
                luabind::value( "LINEAR", AT_LINEAR ),
                luabind::value( "SMOOTH", AT_SMOOTH ),

                luabind::value( "CLOCKWISE", TD_CLOCKWISE ),
                luabind::value( "ANTICLOCKWISE", TD_ANTICLOCKWISE ),
                luabind::value( "CLOSEST", TD_CLOSEST ),

                luabind::value( "UP_TO_DOWN", LM_UP_TO_DOWN ),
                luabind::value( "DOWN_TO_UP", LM_DOWN_TO_UP ),
                luabind::value( "LEFT_TO_RIGHT", LM_LEFT_TO_RIGHT ),
                luabind::value( "RIGHT_TO_LEFT", LM_RIGHT_TO_LEFT )
            ]
    ];

    // game access
    luabind::module( m_LuaState )
    [
        luabind::class_< EntityPoint >( "EntityPoint" )
            .def( "get_position", ( void( EntityPoint::* )() ) &EntityPoint::ScriptGetPosition ) // return 3 values internaly
            .def( "get_rotation", ( float( EntityPoint::* )() ) &EntityPoint::ScriptGetRotation )
    ];

    // game access
    luabind::module( m_LuaState )
    [
        luabind::class_< EntityManager >( "EntityManager" )
            .def( "set_paused", ( void( EntityManager::* )( const bool ) ) &EntityManager::ScriptSetPaused )
            .def( "get_entity", ( Entity*( EntityManager::* )( const char* ) ) &EntityManager::ScriptGetEntity )
            .def( "get_entity_point", ( EntityPoint*( EntityManager::* )( const char* ) ) &EntityManager::ScriptGetEntityPoint )
            .def( "set_player_entity", ( void( EntityManager::* )( const char* ) ) &EntityManager::ScriptSetPlayerEntity )
            .def( "unset_player_entity", ( void( EntityManager::* )() ) &EntityManager::ScriptUnsetPlayerEntity )
            .def( "player_lock", ( void( EntityManager::* )( const bool ) ) &EntityManager::ScriptPlayerLock )
    ];

    // 2d background access
    luabind::module( m_LuaState )
    [
        luabind::class_< Background2D >( "Background2D" )
            .def( "autoscroll_to_entity", ( void( Background2D::* )( Entity* ) ) &Background2D::ScriptAutoScrollToEntity )
            .def( "scroll_to_position", ( void( Background2D::* )( const float, const float, const Background2D::ScrollType, const float ) ) &Background2D::ScriptScrollToPosition )
            .def( "scroll_sync", ( int( Background2D::* )() ) &Background2D::ScriptScrollSync, luabind::yield )
            .def( "play_animation_looped", ( void( Background2D::* )( const char* ) ) &Background2D::ScriptPlayAnimationLooped )
            .def( "play_animation_once", ( void( Background2D::* )( const char* ) ) &Background2D::ScriptPlayAnimationOnce )
            .def( "animation_sync", ( int( Background2D::* )( const char* ) ) &Background2D::ScriptAnimationSync, luabind::yield )

            .enum_( "constants" )
            [
                luabind::value( "NONE", AT_NONE ),
                luabind::value( "LINEAR", AT_LINEAR ),
                luabind::value( "SMOOTH", AT_SMOOTH )
            ]
    ];

    // ui widget access
    luabind::module( m_LuaState )
    [
        luabind::class_< UiWidget >( "UiWidget" )
            .def( "set_visible", ( void( UiWidget::* )( const bool ) ) &UiWidget::SetVisible )
            .def( "is_visible", ( bool( UiWidget::* )() ) &UiWidget::IsVisible )
            .def( "play_animation", ( void( UiWidget::* )( const char* ) ) &UiWidget::ScriptPlayAnimation )
            .def( "play_animation_stop", ( void( UiWidget::* )( const char* ) ) &UiWidget::ScriptPlayAnimationStop )
            .def( "play_animation", ( void( UiWidget::* )( const char*, const float, const float ) ) &UiWidget::ScriptPlayAnimation )
            .def( "play_animation_stop", ( void( UiWidget::* )( const char*, const float, const float ) ) &UiWidget::ScriptPlayAnimationStop )
            .def( "set_default_animation", ( void( UiWidget::* )( const char* ) ) &UiWidget::ScriptSetDefaultAnimation )
            .def( "animation_sync", ( int( UiWidget::* )() ) &UiWidget::ScriptAnimationSync, luabind::yield )
            .def( "set_colour", ( void( UiWidget::* )( const float, const float, const float ) ) &UiWidget::SetColour )
            .def( "set_alpha", ( void( UiWidget::* )( const float ) ) &UiWidget::SetAlpha )
            .def( "set_z", ( void( UiWidget::* )( const float ) ) &UiWidget::SetZ )
    ];

    // ui access
    luabind::module( m_LuaState )
    [
        luabind::class_< UiManager >( "UiManager" )
            .def( "get_widget", ( UiWidget*( UiManager::* )( const char* ) ) &UiManager::ScriptGetWidget )
    ];

    // script access
    luabind::module( m_LuaState )
    [
        luabind::class_< ScriptManager >( "Script" )
            .def( "wait", ( int( ScriptManager::* )( const float ) ) &ScriptManager::ScriptWait, luabind::yield )
            .def( "request", ( void( ScriptManager::* )( const char*, const char*, const int ) ) &ScriptManager::ScriptRequest )
            .def( "request_start_sync", ( int( ScriptManager::* )( const char*, const char*, const int ) ) &ScriptManager::ScriptRequestStartSync, luabind::yield )
            .def( "request_end_sync", ( int( ScriptManager::* )( const char*, const char*, const int ) ) &ScriptManager::ScriptRequestEndSync, luabind::yield )
    ];

    luabind::globals( m_LuaState )[ "entity_manager" ] = boost::ref( *( EntityManager::getSingletonPtr() ) );
    luabind::globals( m_LuaState )[ "background2d" ] = boost::ref( *( EntityManager::getSingletonPtr()->GetBackground2D() ) );
    luabind::globals( m_LuaState )[ "ui_manager" ] = boost::ref( *( UiManager::getSingletonPtr() ) );
    luabind::globals( m_LuaState )[ "script" ] = boost::ref( *this );
}
