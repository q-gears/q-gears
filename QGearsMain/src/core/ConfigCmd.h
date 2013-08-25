#ifndef CONFIG_CMD_H
#define CONFIG_CMD_H

#include <OgreString.h>
#include <OgreStringVector.h>



class ConfigCmdManager;

typedef void ( *ConfigCmdHandler )( const Ogre::StringVector& params );
typedef void ( *ConfigCmdCompletion )( Ogre::StringVector& complete_params );



class ConfigCmd
{
    friend class ConfigCmdManager;

public:
    const Ogre::String&     GetName() const;
    const Ogre::String&     GetDescription() const;
    const Ogre::String&     GetParamsDescription() const;

    ConfigCmdHandler        GetHandler() const;
    ConfigCmdCompletion     GetCompletion() const;

private:
    // ConfigCmd could be created only by ConfigCmdManager
    ConfigCmd(const Ogre::String& name, const Ogre::String& description, const Ogre::String& params_description, ConfigCmdHandler handler, ConfigCmdCompletion completion);

    // forbid copy
    ConfigCmd(const ConfigCmd& rhs);
    ConfigCmd& operator =(const ConfigCmd& rhs);

    Ogre::String            m_Name;
    Ogre::String            m_Description;
    Ogre::String            m_ParamsDescription;
    ConfigCmdHandler        m_Handler;
    ConfigCmdCompletion     m_Completion;
};



#endif // CONFIG_CMD_H
