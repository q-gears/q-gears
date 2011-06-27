#ifndef INPUT_FILTER_H
#define INPUT_FILTER_H

#include <OgreSingleton.h>
#include <OgreString.h>
#include <OIS.h>
#include <vector>

#include "Event.h"



typedef std::vector< Event > InputEventArray;
typedef std::vector< int > ButtonList;



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
    void                BindCommand( const Ogre::String& cmd, const ButtonList& buttons );
    void                ActivateBinds( int button );

private:
    struct BindInfo
    {
        BindInfo( const Ogre::String& _cmd, const ButtonList& _key_set ):
            cmd( _cmd ),
            key_set( _key_set )
        {};

        ButtonList      key_set;
        Ogre::String    cmd;
    };

    bool                    m_ButtonState[ 256 ];
    char                    m_ButtonText[ 256 ];

    bool                    m_RepeatFirstWait;
    float                   m_RepeatTimer;

    InputEventArray         m_EventQueue;

    // binds
    std::vector< BindInfo > m_Binds;
};



#endif // INPUT_FILTER_H
