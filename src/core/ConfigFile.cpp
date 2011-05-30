#include "ConfigFile.h"

#include "ConfigCmdManager.h"
#include "Logger.h"
#include "Utilites.h"



void
ConfigFile::Execute( const Ogre::String& name )
{
    // Open the configuration file
    std::ifstream fp;
    // Always open in binary mode
    fp.open( name.c_str(), std::ios::in | std::ios::binary );
    if( !fp )
    {
        LOG_WARNING( "Config file\"" + name + "\" not found!" );
    }
    else
    {
        Ogre::String command = "";

        while( true )
        {
            char c = fp.get(); // get character from file
            if( fp.good() == false )
            {
                break;
            }

            if( c == '\r' || ( c == '\n' && command.size() == 0 ) )
            {
            }
            else if( c == '\n' && command.size() > 0 )
            {
                Ogre::StringVector params = StringTokenise( command );

                if( params.size() > 0 )
                {
                    // handle command
                    ConfigCmd* cmd = ConfigCmdManager::getSingleton().Find( params[ 0 ] );
                    if( cmd != NULL )
                    {
                        cmd->GetHandler()( params );
                    }
                    else
                    {
                        LOG_ERROR( "Can't find command \"" + params[ 0 ] + "\"." );
                    }
                }

                command = "";
            }
            else if( c >= 0 ) // use only ascii characters
            {
                command += c;
            }
        }

        if( command.size() > 0 )
        {
            Ogre::StringVector params = StringTokenise( command );

            if( params.size() > 0 )
            {
                ConfigCmd* cmd = ConfigCmdManager::getSingleton().Find( params[ 0 ] );

                if( cmd != NULL )
                {
                    cmd->GetHandler()( params );
                }
                else
                {
                    LOG_ERROR( "Can't find command \"" + params[ 0 ] + "\"." );
                }
            }
        }

        fp.close(); // close file
    }
}
