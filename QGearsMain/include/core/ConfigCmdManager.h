#ifndef CONFIG_CMD_MANAGER_H
#define CONFIG_CMD_MANAGER_H

#include <OgreSingleton.h>
#include <vector>
#include <memory>
#include "ConfigCmd.h"



class ConfigCmdManager : public Ogre::Singleton< ConfigCmdManager >
{
public:
    ConfigCmdManager();
    ~ConfigCmdManager();

    void AddCommand( const Ogre::String& name, const Ogre::String& description, const Ogre::String& params_description, ConfigCmdHandler handler, ConfigCmdCompletion completion );

    void ExecuteString( const Ogre::String& cmd_string );

    // return command with specified name
    ConfigCmd* Find( const Ogre::String& name ) const;
    int GetConfigCmdNumber();
    ConfigCmd* GetConfigCmd( unsigned int i ) const;

private:
    // forbid copy
    ConfigCmdManager( const ConfigCmdManager& rhs ) = delete;
    ConfigCmdManager operator =( const ConfigCmdManager& rhs ) = delete;

    void InitCmd();

    std::vector< std::unique_ptr<ConfigCmd> > m_Commands;
};



#endif // CONFIG_CMD_MANAGER_H
