#include "core/ConfigCmd.h"



ConfigCmd::ConfigCmd(const Ogre::String& name, const Ogre::String& description, const Ogre::String& params_description, ConfigCmdHandler handler, ConfigCmdCompletion completion):
    m_Name(name),
    m_Description(description),
    m_ParamsDescription(params_description),
    m_Handler(handler),
    m_Completion(completion)
{
}



const Ogre::String&
ConfigCmd::GetName() const
{
    return m_Name;
}



const Ogre::String&
ConfigCmd::GetDescription() const
{
    return m_Description;
}



const Ogre::String&
ConfigCmd::GetParamsDescription() const
{
    return m_ParamsDescription;
}



ConfigCmdHandler
ConfigCmd::GetHandler() const
{
    return m_Handler;
}



ConfigCmdCompletion
ConfigCmd::GetCompletion() const
{
    return m_Completion;
}
