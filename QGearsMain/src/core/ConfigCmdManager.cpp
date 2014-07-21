#include "core/ConfigCmdManager.h"
#include "core/ConfigCmdManagerCommands.h"

#include "core/Assert.h"
#include "common/make_unique.h"


template<>ConfigCmdManager *Ogre::Singleton< ConfigCmdManager >::msSingleton = NULL;



ConfigCmdManager::ConfigCmdManager()
{
    InitCmd();
}



ConfigCmdManager::~ConfigCmdManager()
{

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

    m_Commands.emplace_back( std::make_unique<ConfigCmd>( name, description, params_description, handler, completion ) );
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
            return m_Commands[ i ].get();
        }
    }
    return nullptr;
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
        return m_Commands[ i ].get();
    }

    return nullptr;
}
