#include "InputManager.h"
#include "InputManagerCommands.h"

#include "ConfigCmdManager.h"
#include "Console.h"
#include "Logger.h"
#include "Timer.h"



template<>InputManager *Ogre::Singleton< InputManager >::ms_Singleton = NULL;



InputManager::InputManager():
    m_RepeatFirstWait( true ),
    m_RepeatTimer( 0 )
{
    InitCmd();

    Reset();
}



InputManager::~InputManager()
{
}



void
InputManager::Reset()
{
    for( int button = 0; button < 256; ++button )
    {
        m_ButtonState[ button ] = false;
    }
}



void
InputManager::ButtonPressed( int button, char text, bool down )
{
    if( m_ButtonState[ button ] != down )
    {
        m_ButtonState[ button ] = down;
        m_ButtonText[ button ] = text;

        m_EventQueue.push_back( Event( ( down == true ) ? ET_KEY_PRESS : ET_KEY_RELEASE, button, text ) );

        m_RepeatFirstWait = true;
        m_RepeatTimer = 0;
    }

    if( down == true && Console::getSingleton().IsVisible() != true )
    {
        ActivateBinds( button );
    }
}



void
InputManager::MousePressed( int button, bool down )
{
    m_EventQueue.push_back( Event( ( down == true ) ? ET_MOUSE_PRESS : ET_MOUSE_RELEASE, button, 0 ) );
}



void
InputManager::MouseMoved( int x, int y )
{
    m_EventQueue.push_back( Event( ET_MOUSE_MOVE, x, y ) );
}



void
InputManager::MouseScrolled( int value )
{
    m_EventQueue.push_back( Event( ET_MOUSE_SCROLL, value, 0 ) );
}



void
InputManager::Update()
{
    m_RepeatTimer += Timer::getSingleton().GetSystemTimeDelta();

    if( ( m_RepeatFirstWait == true && m_RepeatTimer >= 0.5 ) || ( m_RepeatFirstWait == false && m_RepeatTimer >= 0.05 ) )
    {
        for( int button = 0; button < 256; ++button )
        {
            if( m_ButtonState[ button ] == true )
            {
                m_EventQueue.push_back( Event( ET_KEY_REPEAT, button, m_ButtonText[ button ] ) );
            }
        }

        m_RepeatFirstWait = false;
        m_RepeatTimer = 0;
    }

    // send impulses
    for( int button = 0; button < 256; ++button )
    {
        if( m_ButtonState[ button ] == true )
        {
            m_EventQueue.push_back( Event( ET_KEY_IMPULSE, button, m_ButtonText[ button ] ) );
        }
    }
}



bool
InputManager::IsButtonPressed( int button ) const
{
    return m_ButtonState[ button ];
}



void
InputManager::GetInputEvents( InputEventArray& input_events )
{
    input_events = m_EventQueue;

    m_EventQueue.clear();
}



void
InputManager::BindCommand( const Ogre::String& cmd, const ButtonList& buttons )
{
    BindInfo info = BindInfo( cmd, buttons );
    m_Binds.push_back( info );
}



void
InputManager::ActivateBinds( int button )
{
    std::vector< int > binds_indexes;
    for( size_t i = 0; i < m_Binds.size(); ++i )
    {
        // if we found pressed button in this bind
        if( std::find( m_Binds[ i ].key_set.begin(), m_Binds[ i ].key_set.end(), button ) != m_Binds[ i ].key_set.end() )
        {
            size_t j = 0;
            for( ; j < m_Binds[ i ].key_set.size(); ++j )
            {
                if( IsButtonPressed( m_Binds[ i ].key_set[ j ] ) == false )
                {
                    break;
                }
            }

            if( j >= m_Binds[ i ].key_set.size() )
            {
                binds_indexes.push_back( i );
            }
        }
    }

    std::vector< int > binds_to_activate;
    size_t max_size = 0;
    for( size_t i = 0; i < binds_indexes.size(); ++i )
    {
        if( max_size < m_Binds[ binds_indexes[ i ] ].key_set.size() )
        {
            max_size = m_Binds[ binds_indexes[ i ] ].key_set.size();

            binds_to_activate.clear();
            binds_to_activate.push_back( binds_indexes[ i ] );
        }
        else if( max_size == m_Binds[ binds_indexes[ i ] ].key_set.size() )
        {
            binds_to_activate.push_back( binds_indexes[ i ] );
        }
    }

    for( size_t i = 0; i < binds_to_activate.size(); ++i )
    {
        Ogre::StringVector params = StringTokenise( m_Binds[ binds_to_activate[ i ] ].cmd );

        // handle command
        ConfigCmd* cmd = ConfigCmdManager::getSingleton().Find( params[ 0 ] );
        if( cmd != NULL )
        {
            cmd->GetHandler()( params );
        }
        else
        {
            LOG_ERROR( "Can't find command \"" + params[ 0 ] + "\" in bind command \"" + m_Binds[ i ].cmd + "\"." );
        }
    }
}
