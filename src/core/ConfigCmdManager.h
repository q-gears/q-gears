#ifndef CONFIG_CMD_MANAGER_H
#define CONFIG_CMD_MANAGER_H

#include <OgreSingleton.h>
#include <vector>

#include "ConfigCmd.h"



class ConfigCmdManager : public Ogre::Singleton< ConfigCmdManager >
{
public:
    ConfigCmdManager();
    ~ConfigCmdManager();

    void                AddCmd( const Ogre::String& name, const Ogre::String& description, const Ogre::String& params_description, ConfigCmdHandler handler, ConfigCmdCompletion completion );

    void                ExecuteString( const Ogre::String& cmd_string );

    // return command with specified name
    ConfigCmd*          Find( const Ogre::String& name ) const;
    int                 GetConfigCmdNumber();
    ConfigCmd*          GetConfigCmd( size_t i ) const;

private:
    // forbid copy
    ConfigCmdManager( const ConfigCmdManager& rhs );
    ConfigCmdManager operator =( const ConfigCmdManager& rhs );

    void InitCmd();

    std::vector< ConfigCmd* > m_Commands;
};



#endif // CONFIG_CMD_MANAGER_H
