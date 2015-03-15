#include "core/ConfigCmdManager.h"
#include "core/Console.h"
#include "core/InputManager.h"
#include "core/InputManagerCommands.h"
#include "core/Logger.h"
#include "core/Timer.h"


template<>InputManager *Ogre::Singleton<InputManager>::msSingleton = nullptr;


InputManager::InputManager():
    m_RepeatFirstWait(true),
    m_RepeatTimer(0)
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
    for(int button = 0; button < 256; ++button)
    {
        m_ButtonState[button] = false;
    }
}


void
InputManager::ButtonPressed(int button, char text, bool down)
{
    if( m_ButtonState[ button ] != down )
    {
        m_ButtonState[ button ] = down;
        m_ButtonText[ button ] = text;

        QGears::Event event;
        event.type = (down == true) ? QGears::ET_KEY_PRESS : QGears::ET_KEY_RELEASE;
        event.param1 = button;
        event.param2 = text;
        m_EventQueue.push_back( event );

        m_RepeatFirstWait = true;
        m_RepeatTimer = 0;
    }

    if( Console::getSingleton().IsVisible() != true )
    {
        if( down == true )
        {
            ActivateBinds( button );
            AddGameEvents(button, QGears::ET_KEY_PRESS);
        }
        else
        {
            AddGameEvents(button, QGears::ET_KEY_RELEASE);
        }
    }
}



void
InputManager::MousePressed( int button, bool down )
{
    QGears::Event event;
    event.type = (down == true) ? QGears::ET_KEY_PRESS : QGears::ET_KEY_RELEASE;
    event.param1 = button;
    m_EventQueue.push_back( event );
}



void
InputManager::MouseMoved( int x, int y )
{
    QGears::Event event;
    event.type = QGears::ET_MOUSE_MOVE;
    event.param1 = x;
    event.param2 = y;
    m_EventQueue.push_back( event );
}



void
InputManager::MouseScrolled( int value )
{
    QGears::Event event;
    event.type = QGears::ET_MOUSE_SCROLL;
    event.param1 = value;
    m_EventQueue.push_back( event );
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
                QGears::Event event;
                event.type = QGears::ET_KEY_REPEAT_WAIT;
                event.param1 = button;
                event.param2 = m_ButtonText[ button ];
                m_EventQueue.push_back( event );

                if( Console::getSingleton().IsVisible() != true )
                {
                    AddGameEvents(button, QGears::ET_KEY_REPEAT_WAIT);
                }
            }
        }

        m_RepeatFirstWait = false;
        m_RepeatTimer = 0;
    }

    for( int button = 0; button < 256; ++button )
    {
        if( m_ButtonState[ button ] == true )
        {
            QGears::Event event;
            event.type = QGears::ET_KEY_REPEAT;
            event.param1 = button;
            event.param2 = m_ButtonText[ button ];
            m_EventQueue.push_back( event );

            if( Console::getSingleton().IsVisible() != true )
            {
                AddGameEvents(button, QGears::ET_KEY_REPEAT);
            }
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
InputManager::BindCommand( ConfigCmd* cmd, const Ogre::StringVector& params, const ButtonList& buttons )
{
    BindInfo info;
    info.cmd = cmd;
    info.params = params;
    info.buttons = buttons;
    m_Binds.push_back( info );
}



void
InputManager::BindGameEvent( const Ogre::String& event, const ButtonList& buttons )
{
    BindGameEventInfo info;
    info.event = event;
    info.buttons = buttons;
    m_BindGameEvents.push_back( info );
}



void
InputManager::ActivateBinds( const int button )
{
    std::vector< int > binds_indexes;
    for( unsigned int i = 0; i < m_Binds.size(); ++i )
    {
        // if we found pressed button in this bind
        if( std::find( m_Binds[ i ].buttons.begin(), m_Binds[ i ].buttons.end(), button ) != m_Binds[ i ].buttons.end() )
        {
            unsigned int j = 0;
            for( ; j < m_Binds[ i ].buttons.size(); ++j )
            {
                if( IsButtonPressed( m_Binds[ i ].buttons[ j ] ) == false )
                {
                    break;
                }
            }

            if( j >= m_Binds[ i ].buttons.size() )
            {
                binds_indexes.push_back( i );
            }
        }
    }

    std::vector< int > binds_to_activate;
    unsigned int max_size = 0;
    for( unsigned int i = 0; i < binds_indexes.size(); ++i )
    {
        if( max_size < m_Binds[ binds_indexes[ i ] ].buttons.size() )
        {
            max_size = m_Binds[ binds_indexes[ i ] ].buttons.size();

            binds_to_activate.clear();
            binds_to_activate.push_back( binds_indexes[ i ] );
        }
        else if( max_size == m_Binds[ binds_indexes[ i ] ].buttons.size() )
        {
            binds_to_activate.push_back( binds_indexes[ i ] );
        }
    }

    for( unsigned int i = 0; i < binds_to_activate.size(); ++i )
    {
         m_Binds[ binds_to_activate[ i ] ].cmd->GetHandler()( m_Binds[ binds_to_activate[ i ] ].params );
    }
}



void
InputManager::AddGameEvents(const int button, const QGears::EventType type)
{
    std::vector< int > binds_indexes;
    for( unsigned int i = 0; i < m_BindGameEvents.size(); ++i )
    {
        // if we found button in this bind
        if( std::find( m_BindGameEvents[ i ].buttons.begin(), m_BindGameEvents[ i ].buttons.end(), button ) != m_BindGameEvents[ i ].buttons.end() )
        {
            unsigned int j = 0;
            for( ; j < m_BindGameEvents[ i ].buttons.size(); ++j )
            {
                if( m_BindGameEvents[ i ].buttons[ j ] != button )
                {
                    if( IsButtonPressed( m_BindGameEvents[ i ].buttons[ j ] ) == false )
                    {
                        break;
                    }
                }
            }

            if( j >= m_BindGameEvents[ i ].buttons.size() )
            {
                binds_indexes.push_back( i );
            }
        }
    }

    std::vector< int > binds_to_activate;
    unsigned int max_size = 0;
    for( unsigned int i = 0; i < binds_indexes.size(); ++i )
    {
        if( max_size < m_BindGameEvents[ binds_indexes[ i ] ].buttons.size() )
        {
            max_size = m_BindGameEvents[ binds_indexes[ i ] ].buttons.size();

            binds_to_activate.clear();
            binds_to_activate.push_back( binds_indexes[ i ] );
        }
        else if( max_size == m_BindGameEvents[ binds_indexes[ i ] ].buttons.size() )
        {
            binds_to_activate.push_back( binds_indexes[ i ] );
        }
    }

    for( unsigned int i = 0; i < binds_to_activate.size(); ++i )
    {
        QGears::Event event;
        event.type = type;
        event.event = m_BindGameEvents[ binds_to_activate[ i ] ].event;
        m_EventQueue.push_back( event );
    }
}
