#include "ConfigCmdManager.h"
#include "ConfigCmdManagerCommands.h"

#include "Assert.h"



template<>ConfigCmdManager *Ogre::Singleton< ConfigCmdManager >::ms_Singleton = NULL;



ConfigCmdManager::ConfigCmdManager()
{
    InitCmd();
}



ConfigCmdManager::~ConfigCmdManager()
{
    for( unsigned int i = 0; i < m_Commands.size(); ++i )
    {
        delete m_Commands[ i ];
    }
}



void
ConfigCmdManager::AddCommand( const Ogre::String& name, const Ogre::String& description, const Ogre::String& params_description, ConfigCmdHandler handler, ConfigCmdCompletion completion )
{
    QGEARS_ASSERT( name != "", "Command name shouldn't be empty." );
    QGEARS_ASSERT( handler, "Null command handler." );

    // see if command already added
    for( unsigned int i = 0; i < m_Commands.size(); ++i )
    {
        QGEARS_ASSERT( m_Commands[ i ]->GetName() != name, "Command already exist." );
    }

    m_Commands.push_back( new ConfigCmd( name, description, params_description, handler, completion ) );
}



void
ConfigCmdManager::ExecuteString( const Ogre::String& cmd_string )
{
}



ConfigCmd*
ConfigCmdManager::Find( const Ogre::String& name ) const
{
    for( unsigned int i = 0; i < m_Commands.size(); ++i )
    {
        if( m_Commands[ i ]->GetName() == name )
        {
            return m_Commands[ i ];
        }
    }

    return NULL;
}



int
ConfigCmdManager::GetConfigCmdNumber()
{
    return m_Commands.size();
}



ConfigCmd*
ConfigCmdManager::GetConfigCmd( unsigned int i ) const
{
    if( i < m_Commands.size() )
    {
        return m_Commands[ i ];
    }

    return NULL;
}
