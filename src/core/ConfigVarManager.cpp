#include "ConfigVarManager.h"



template<>ConfigVarManager *Ogre::Singleton< ConfigVarManager >::ms_Singleton = NULL;



ConfigVarManager::ConfigVarManager()
{
    if( ConfigVar::m_StaticConfigVarList != ( ConfigVar* )0xffffffff )
    {
        for( ConfigVar* cvar = ConfigVar::m_StaticConfigVarList; cvar; cvar = cvar->m_Previous )
        {
            m_ConfigVars.push_back( cvar );
        }

        ConfigVar::m_StaticConfigVarList = ( ConfigVar* )0xffffffff;
    }
}



ConfigVar*
ConfigVarManager::Find( const Ogre::String& name ) const
{
    for( size_t i = 0; i < m_ConfigVars.size(); ++i )
    {
        if( m_ConfigVars[ i ]->GetName() == name )
        {
            return m_ConfigVars[ i ];
        }
    }

    return NULL;
}



unsigned int
ConfigVarManager::GetConfigVarNumber() const
{
    return m_ConfigVars.size();
}



ConfigVar*
ConfigVarManager::GetConfigVar( const unsigned int i ) const
{
    if( i < m_ConfigVars.size() )
    {
        return m_ConfigVars[ i ];
    }

    return NULL;
}
