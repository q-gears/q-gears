#ifndef CONFIG_VAR_MANAGER_H
#define CONFIG_VAR_MANAGER_H

#include <OgreSingleton.h>
#include <vector>

#include "ConfigVar.h"



class ConfigVarManager : public Ogre::Singleton<ConfigVarManager>
{
public:
                    ConfigVarManager();

    ConfigVar*      Find(const Ogre::String& name) const;
    int             GetConfigVarNumber();
    ConfigVar*      GetConfigVar(int i) const;

private:
    std::vector<ConfigVar*> m_ConfigVars;
};



#endif // CONFIG_VAR_MANAGER_H
