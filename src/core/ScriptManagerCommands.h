#include "ConfigCmdManager.h"
#include "Console.h"



void
CmdScriptRunString( const Ogre::StringVector& params )
{
    if( params.size() < 2 )
    {
        Console::getSingleton().AddTextToOutput( "Usage: /script_run_string <string>" );
        return;
    }

    ScriptManager::getSingleton().RunString( params[ 1 ] );
}



void
CmdScriptRunFile( const Ogre::StringVector& params )
{
    if( params.size() < 2 )
    {
        Console::getSingleton().AddTextToOutput( "Usage: /script_run_file <file name>" );
        return;
    }

    ScriptManager::getSingleton().RunFile( params[ 1 ] );
}



void
ScriptManager::InitCmd()
{
    ConfigCmdManager::getSingleton().AddCommand( "script_run_string", "Run script string", "", CmdScriptRunString, NULL );
    ConfigCmdManager::getSingleton().AddCommand( "script_run_file", "Run script file", "", CmdScriptRunFile, NULL );
}
