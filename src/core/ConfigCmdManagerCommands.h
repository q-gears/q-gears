#include <OgreRenderWindow.h>
#include <OgreRoot.h>
#include <OgreStringConverter.h>

#include "Console.h"
#include "ConfigCmdManager.h"
#include "ConfigVarManager.h"
#include "EntityManager.h"
#include "Logger.h"
#include "XmlMapFile.h"
#include "XmlMapsFile.h"



void
CmdEcho( const Ogre::StringVector& params )
{
    if( params.size() < 1 )
    {
        Console::getSingleton().AddTextToOutput( "Usage: /echo <string to output>" );
        return;
    }

    Ogre::String text = "";

    for( int i = 1; i < params.size(); ++i )
    {
        if( i != 1 )
        {
            text += " ";
        }
        text += params[ i ];
    }

    Console::getSingleton().AddTextToOutput( text + "\n" );
}



void
CmdConfigVarList( const Ogre::StringVector& params )
{
    if( params.size() > 2 )
    {
        Console::getSingleton().AddTextToOutput( "Usage: /config_var_list [search string]" );
        return;
    }

    int number = 0;
    int num_vars = ConfigVarManager::getSingleton().GetConfigVarNumber();
    for( int i = 0; i < num_vars; ++i )
    {
        ConfigVar* var = ConfigVarManager::getSingleton().GetConfigVar( i );
        Ogre::String name = var->GetName();

        if( params.size() > 1 )
        {
            int found = name.find( params[ 1 ] );
            if( found == 0 )
            {
                Console::getSingleton().AddTextToOutput( var->GetName() + " = \"" + var->GetS() + "\"" );
                ++number;
            }
        }
        else
        {
            Console::getSingleton().AddTextToOutput( var->GetName() + " = \"" + var->GetS() + "\"" );
            ++number;
        }
    }

    Console::getSingleton().AddTextToOutput( Ogre::StringConverter::toString(number) + " config variables.\n" );
}



void
CmdConfigCmdList(const Ogre::StringVector& params)
{
    if (params.size() > 2)
    {
        Console::getSingleton().AddTextToOutput("Usage: /config_cmd_list [search string]");
        return;
    }

    int number = 0;
    int num_cmds = ConfigCmdManager::getSingleton().GetConfigCmdNumber();
    for (int i = 0; i < num_cmds; ++i)
    {
        ConfigCmd* cmd = ConfigCmdManager::getSingleton().GetConfigCmd(i);
        Ogre::String name = cmd->GetName();

        if (params.size() > 1)
        {
            //Ogre::LogManager::getSingletonPtr()->logMessage("Search for " + params[1] + " in " + name);

            int found = name.find(params[1]);

            //Ogre::LogManager::getSingletonPtr()->logMessage("Found " + Ogre::StringConverter::toString(found));

            if (found == 0)
            {
                Console::getSingleton().AddTextToOutput(cmd->GetName());
                ++number;
            }
        }
        else
        {
            Console::getSingleton().AddTextToOutput(cmd->GetName());
            ++number;
        }
    }

    Console::getSingleton().AddTextToOutput(Ogre::StringConverter::toString(number) + " config commands.\n");
}



// set cvar value
void
CmdSetConfigVar(const Ogre::StringVector& params)
{
    if (params.size() < 2 || params.size() > 3)
    {
        Console::getSingleton().AddTextToOutput("Usage: /set <config variable> [value]");
        return;
    }

    Ogre::String name = params[1];

    ConfigVar* cvar = ConfigVarManager::getSingleton().Find(name);
    if (cvar == NULL)
    {
        LOG_ERROR("Config variable \"" + name + "\" not found.");
        return;
    }

    if (params.size() == 3)
    {
        cvar->SetS(params[2]);

        Console* console = Console::getSingletonPtr();
        if (console != NULL)
        {
            LOG_TRIVIAL(params[1] + " changed to \"" + params[2] + "\".");
        }
    }
    else
    {
        // reset to default
        cvar->SetS(cvar->GetDefaultValue());
        LOG_TRIVIAL(params[1] + " changed to default \"" + cvar->GetDefaultValue() + "\".");
    }
}



// toggle cvar value
void
CmdToggleConfigVar( const Ogre::StringVector& params )
{
    if( params.size() < 4 )
    {
        Console::getSingleton().AddTextToOutput( "Usage: /toggle <config variable> [value1] [value2] ..." );
        return;
    }

    Ogre::String name = params[ 1 ];

    ConfigVar* cvar = ConfigVarManager::getSingleton().Find( name );
    if( cvar == NULL )
    {
        LOG_ERROR( "Config variable \"" + name + "\" not found." );
        return;
    }

    // sequentially trigger values
    int number_of_values = params.size() - 2;
    Ogre::String value = cvar->GetS();
    int i = 0;

    for( ; i < number_of_values; ++i )
    {
        if( value == params[ i + 2 ] )
        {
            ++i;
            break;
        }
    }

    if( i == number_of_values )
    {
        i = 0;
    }

    cvar->SetS( params[ i + 2 ] );
}



// increment cvar value
void
CmdIncrementConfigVar( const Ogre::StringVector& params )
{
    if( params.size() != 5 )
    {
        Console::getSingleton().AddTextToOutput( "Usage: /increment <cvar name> [value min] [value max] [step]" );
        return;
    }

    Ogre::String name = params[ 1 ];

    ConfigVar* cvar = ConfigVarManager::getSingleton().Find( name );
    if( cvar == NULL )
    {
        LOG_ERROR( "Config variable \"" + name + "\" not found." );
        return;
    }

    float start_value = Ogre::StringConverter::parseReal( params[ 2 ] );
    float end_value = Ogre::StringConverter::parseReal( params[ 3 ] );
    float step = Ogre::StringConverter::parseReal( params[ 4 ] );

    float new_value = cvar->GetF() + step;
    if( new_value > end_value )
    {
        new_value = end_value;
    }
    else if( new_value < start_value )
    {
        new_value = start_value;
    }

    cvar->SetF( new_value );
}



void
CmdSetLogLevel( const Ogre::StringVector& params )
{
    if( params.size() != 2 )
    {
        Console::getSingleton().AddTextToOutput( "Usage: /log_level <level: 1 - only errors, 2 - errors and warnings, 3 - all>" );
        return;
    }

    int value = Ogre::StringConverter::parseInt( params[ 1 ] );
    if( value > 0 && value < 4 )
    {
        Ogre::LogManager::getSingletonPtr()->getDefaultLog()->setLogDetail( ( Ogre::LoggingLevel )value );

        switch( value )
        {
            case 1: Console::getSingleton().AddTextToOutput( "Logger level changed to \"only errors\".\n" ); break;
            case 2: Console::getSingleton().AddTextToOutput( "Logger level changed to \"errors and warnings\".\n" ); break;
            case 3: Console::getSingleton().AddTextToOutput( "Logger level changed to \"all\".\n" ); break;
        }
    }
    else
    {
        Console::getSingleton().AddTextToOutput( "Logger level can't be changed. Value \"" + params[ 1 ] + "\" isn't supported.\n" );
    }
}



void
CmdMap( const Ogre::StringVector& params )
{
    if( params.size() != 2 )
    {
        Console::getSingleton().AddTextToOutput( "Usage: /map [map_id]" );
        return;
    }

    EntityManager::getSingleton().Clear();

    XmlMapsFile xml( "./data/game_data/maps.xml" );
    Ogre::String file_name = xml.GetMapFileNameByName( params[ 1 ] );

    XmlMapFile xml_map( "./data/" + file_name );
    xml_map.LoadMap();
}



void
CmdMapCompletion( Ogre::StringVector& complete_params )
{
    XmlMapsFile xml( "./data/game_data/maps.xml" );
    xml.GetMapNames( complete_params );
}



void
CmdResolution( const Ogre::StringVector& params )
{
    if( params.size() < 3 )
    {
        Console::getSingleton().AddTextToOutput( "Usage: /resolution <width> <height> [full screen]" );
        return;
    }

    Ogre::RenderWindow* window = ( Ogre::RenderWindow* )Ogre::Root::getSingleton().getRenderTarget( "QGearsWindow" );

    if( params.size() >= 4 )
    {
        window->setFullscreen( Ogre::StringConverter::parseBool( params[ 3 ] ), Ogre::StringConverter::parseInt( params[ 1 ] ), Ogre::StringConverter::parseInt( params[ 2 ] ) );
    }
    else
    {
        window->resize( Ogre::StringConverter::parseInt( params[ 1 ] ), Ogre::StringConverter::parseInt( params[ 2 ] ) );
    }
}



void
CmdResolutionCompletition( Ogre::StringVector& complete_params )
{
    complete_params.push_back( "640 480 0" );
    complete_params.push_back( "640 480 1" );
    complete_params.push_back( "800 600 0" );
    complete_params.push_back( "800 600 1" );
    complete_params.push_back( "1024 768 0" );
    complete_params.push_back( "1024 768 1" );
    complete_params.push_back( "1280 720 0" );
    complete_params.push_back( "1280 720 1" );
    complete_params.push_back( "1280 1024 0" );
    complete_params.push_back( "1280 1024 1" );
}



void
CmdScreenshot( const Ogre::StringVector& params )
{
    Ogre::RenderWindow* window = ( Ogre::RenderWindow* )Ogre::Root::getSingleton().getRenderTarget( "QGearsWindow" );
    Ogre::String ret = window->writeContentsToTimestampedFile( "screenshot_", ".tga" );
    Console::getSingleton().AddTextToOutput( "Screenshot " + ret + " saved." );
}



/*
void
CmdViewer( const Ogre::StringVector& params )
{
    if( params.size() == 2 || params.size() > 3 )
    {
        Console::getSingleton().AddTextToOutput( "Usage: /viewer [type_of_thing_to_view] [path_to_resource]" );
        return;
    }

    ModuleManager::getSingleton().RunViewer();

    if( params.size() == 3 )
    {
        ViewerModule* module = ( ViewerModule* )( ModuleManager::getSingleton().GetTopModule() );

        if( params[ 1 ] == "walkmesh" )
        {
            module->SetWalkmeshToLoad( params[ 2 ] );
        }
        else if( params[ 1 ] == "model" )
        {
            module->SetModelToLoad( params[ 2 ] );
        }
        else
        {
            LOG_ERROR( "Unsupported type \"" + params[ 1 ] + "\" in viewer command." );
        }
    }
}



void
CmdViewerCompletion( Ogre::StringVector& complete_params )
{
    // models
    complete_params.push_back( "model" );

    Ogre::FileInfoListPtr resources = Ogre::ResourceGroupManager::getSingleton().listResourceFileInfo( "Game" );
    Ogre::FileInfoList resource_names = *resources;

    Ogre::FileInfoList::iterator i = resource_names.begin();
    for( ; i != resource_names.end(); ++i )
    {
        Ogre::String name;
        Ogre::String ext;
        Ogre::StringUtil::splitBaseFilename( i->filename, name, ext );
        if( ext == "mesh" )
        {
            complete_params.push_back( "model " + i->filename );
        }
    }

    // walkmeshes
    complete_params.push_back( "walkmesh" );
    XmlMapsFile xml( "./data/game_data/maps.xml" );
    Ogre::StringVector tmp;
    xml.GetMapNames( tmp );
    for( int i = 0; i < tmp.size(); ++i )
    {
        complete_params.push_back( "walkmesh " + tmp[ i ] );
    }
}
*/


void
ConfigCmdManager::InitCmd()
{
    AddCmd( "echo", "Print command parameters", "", CmdEcho, NULL );
    AddCmd( "config_var_list", "List of registered config variables", "[<filter substring>]", CmdConfigVarList, NULL );
    AddCmd( "config_cmd_list", "List of registered config commands", "[<filter substring>]", CmdConfigCmdList, NULL );
    AddCmd( "set", "Set cvar value", "<cvar name> [value]", CmdSetConfigVar, NULL );
    AddCmd( "toggle", "Toggle cvar value", "<cvar name> [value1] [value2] ...", CmdToggleConfigVar, NULL );
    AddCmd( "increment", "Increment cvar value", "<cvar name> [value min] [value max] [step]", CmdIncrementConfigVar, NULL );

    AddCmd( "set_log_level", "Set log messages level", "", CmdSetLogLevel, NULL );

    AddCmd( "map", "Run game module", "", CmdMap, CmdMapCompletion );

    AddCmd( "resolution", "Change resolution", "", CmdResolution, CmdResolutionCompletition );
    AddCmd( "screenshot", "Capture current screen content", "", CmdScreenshot, NULL );

    //AddCmd( "viewer", "Run viewer module", "", CmdViewer, CmdViewerCompletion );
}
