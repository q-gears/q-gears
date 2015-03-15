#ifndef INPUT_FILTER_H
#define INPUT_FILTER_H

#include <OgreSingleton.h>
#include <OgreString.h>
#include <OIS.h>
#include <vector>

#include "Event.h"



typedef std::vector< QGears::Event > InputEventArray;
typedef std::vector< int > ButtonList;

class ConfigCmd;

class InputManager : public Ogre::Singleton< InputManager >
{
public:
                        InputManager();
    virtual             ~InputManager();

    void                ButtonPressed( int button, char text, bool down );
    void                MousePressed( int button, bool down );
    void                MouseMoved( int x, int y );
    void                MouseScrolled( int value );
    void                Reset();
    void                Update();

    bool                IsButtonPressed( int button ) const;

    void                GetInputEvents( InputEventArray& input_events );

    // binds
    void                InitCmd();
    void                BindCommand( ConfigCmd* cmd, const Ogre::StringVector& params, const ButtonList& buttons );
    void                BindGameEvent( const Ogre::String& event, const ButtonList& buttons );
    void                ActivateBinds( const int button );
    void                AddGameEvents( const int button, const QGears::EventType type );

private:
    bool                    m_ButtonState[ 256 ];
    char                    m_ButtonText[ 256 ];

    bool                    m_RepeatFirstWait;
    float                   m_RepeatTimer;

    InputEventArray         m_EventQueue;

    // binds
    struct BindInfo
    {
        BindInfo():
            cmd( NULL )
        {}

        ConfigCmd* cmd;
        Ogre::StringVector params;
        ButtonList buttons;
    };
    std::vector< BindInfo > m_Binds;
    struct BindGameEventInfo
    {
        Ogre::String event;
        ButtonList buttons;
    };
    std::vector< BindGameEventInfo > m_BindGameEvents;
};



#endif // INPUT_FILTER_H
