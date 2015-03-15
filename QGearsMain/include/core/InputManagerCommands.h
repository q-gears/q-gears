#include <OgreStringConverter.h>

#include "Console.h"
#include "ConfigCmdManager.h"
#include "ConfigVarManager.h"
#include "Logger.h"
#include "Utilites.h"



bool
ParseKeys( const Ogre::String& string, ButtonList& key_codes )
{
    Ogre::StringVector keys = Ogre::StringUtil::split( string, "+" );

    for( unsigned int i = 0; i < keys.size(); ++i )
    {
        key_codes.push_back( StringToKey( keys[ i ] ) );
    }

    bool fail = false;
    for( unsigned int i = 0; i < key_codes.size(); ++i )
    {
        if( key_codes[ i ] == OIS::KC_UNASSIGNED )
        {
            LOG_ERROR( "Failed to parse key string \"" + string + "\". Can't recognize key " + Ogre::StringConverter::toString( i ) );
            fail = true;
        }
    }

    return fail;
}



void
CmdBind( const Ogre::StringVector& params )
{
    if( params.size() != 3 )
    {
        Console::getSingleton().AddTextToOutput( "Usage: /bind <key1>+[key2]+[key3] \"<command line>\"" );
        return;
    }

    ButtonList key_codes;

    if( ParseKeys( params[ 1 ], key_codes ) == false )
    {
        Ogre::StringVector params_cmd = StringTokenise( params[ 2 ] );

        // handle command
        ConfigCmd* cmd = ConfigCmdManager::getSingleton().Find( params_cmd[ 0 ] );
        if( cmd != NULL )
        {
            InputManager::getSingleton().BindCommand( cmd, params_cmd, key_codes );
            LOG_TRIVIAL( "Bind \"" + params[ 1 ] + "\" to command \"" + params[ 2 ] + "\"." );
        }
        else
        {
            LOG_ERROR( "Can't find command \"" + params_cmd[ 0 ] + "\" in bind command \"" + params[ 2 ] + "\"." );
        }
    }
}



void
CmdBindGameEvent( const Ogre::StringVector& params )
{
    if( params.size() != 3 )
    {
        Console::getSingleton().AddTextToOutput( "Usage: /game_bind <key1>+[key2]+[key3] \"<game event>\"" );
        return;
    }

    ButtonList key_codes;

    if( ParseKeys( params[ 1 ], key_codes ) == false )
    {
        InputManager::getSingleton().BindGameEvent( params[ 2 ], key_codes );
        LOG_TRIVIAL( "Bind \"" + params[ 1 ] + "\" to game event \"" + params[ 2 ] + "\"." );
    }
}



void
InputManager::InitCmd()
{
    ConfigCmdManager::getSingleton().AddCommand( "bind", "Bind command to keys", "", CmdBind, NULL );
    ConfigCmdManager::getSingleton().AddCommand( "bind_game_event", "Bind game event to keys", "", CmdBindGameEvent, NULL );
}
