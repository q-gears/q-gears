#include <OgreStringConverter.h>

#include "CameraManager.h"
#include "ConfigCmdManager.h"
#include "Console.h"



void
CommandCameraFree( const Ogre::StringVector& params )
{
    if( params.size() < 1 )
    {
        Console::getSingleton().AddTextToOutput( "Usage: /camera_free <enable>" );
        return;
    }

    CameraManager::getSingleton().SetCameraFree( Ogre::StringConverter::parseBool( params[ 1 ] ) );
}



void
CommandCameraFreeCompletition( Ogre::StringVector& complete_params )
{
    complete_params.push_back( "true" );
    complete_params.push_back( "false" );
}



void
CameraManager::InitCommands()
{
    ConfigCmdManager::getSingleton().AddCommand( "camera_free", "Enable or disable free camera", "", CommandCameraFree, CommandCameraFreeCompletition );
}
