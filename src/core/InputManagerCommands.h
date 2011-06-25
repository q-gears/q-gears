#include <OgreStringConverter.h>

#include "Console.h"
#include "ConfigCmdManager.h"
#include "ConfigVarManager.h"
#include "Logger.h"
#include "Utilites.h"



void
CmdBind( const Ogre::StringVector& params )
{
    if( params.size() < 3 || params.size() > 4 )
    {
        Console::getSingleton().AddTextToOutput( "Usage: /bind <key1>+[key2]+[key3] \"<command line>\"" );
        return;
    }

    Ogre::StringVector keys = Ogre::StringUtil::split( params[ 1 ], "+" );
    ButtonList key_codes;

    for( int i = 0; i < keys.size(); ++i )
    {
        key_codes.push_back( StringToKey( keys[ i ] ) );
    }

    bool fail = false;
    for( int i = 0; i < key_codes.size(); ++i )
    {
        if( key_codes[ i ] == OIS::KC_UNASSIGNED )
        {
            LOG_ERROR( "Failed to bind \"" + params[ 1 ] + "\" to command \"" + params[ 2 ] + "\". Can't recognize key " + Ogre::StringConverter::toString( i ) );
            fail = true;
        }
    }

    if( fail == false )
    {
        InputManager::getSingleton().BindCommand( params[ 2 ], key_codes );
        LOG_TRIVIAL( "Bind \"" + params[ 1 ] + "\" to command \"" + params[ 2 ] + "\"." );
    }
}



void
InputManager::InitCmd()
{
    ConfigCmdManager::getSingleton().AddCmd( "bind", "Bind command to keys", "", CmdBind, NULL );
}
