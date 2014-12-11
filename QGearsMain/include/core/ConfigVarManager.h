#ifndef CONFIG_VAR_MANAGER_H
#define CONFIG_VAR_MANAGER_H

#include <OgreSingleton.h>
#include <vector>

#include "ConfigVar.h"



class ConfigVarManager : public Ogre::Singleton< ConfigVarManager >
{
public:
    ConfigVarManager();

    ConfigVar*   Find( const Ogre::String& name ) const;
    unsigned int GetConfigVarNumber() const;
    ConfigVar*   GetConfigVar( const unsigned int i ) const;

private:
    std::vector< ConfigVar* > m_ConfigVars;
};



#endif // CONFIG_VAR_MANAGER_H
