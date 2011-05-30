#include "ConfigCmdManager.h"
#include "Console.h"



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
    ConfigCmdManager::getSingleton().AddCmd( "script_run_file", "Run script file", "", CmdScriptRunFile, NULL );
}
