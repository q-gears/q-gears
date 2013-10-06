#include "core/ConfigVar.h"

#include <OgreStringConverter.h>

#include "core/Assert.h"



ConfigVar* ConfigVar::m_StaticConfigVarList = NULL;



ConfigVar::ConfigVar(const Ogre::String& name, const Ogre::String& description, const Ogre::String& default_value):
    m_Name(name),
    m_Description(description),
    m_DefaultValue(default_value),
    m_ValueS(default_value)
{
    QGEARS_ASSERT(name != "", "m_Name of ConfigVar can`t be empty!");
    QGEARS_ASSERT(default_value != "", "m_DefaultValue of ConfigVar can`t be empty!");
    QGEARS_ASSERT(description != "", "m_Description of ConfigVar can`t be empty!");

    UpdateVariables();

    if (m_StaticConfigVarList != (ConfigVar*)0xffffffff)
    {
        m_Previous = m_StaticConfigVarList;
        m_StaticConfigVarList = this;
    }
    else
    {
        QGEARS_ASSERT(false, "ConfigVar declared after RegisterCvars were called!");
    }
}



int
ConfigVar::GetI() const
{
    return m_ValueI;
}



float
ConfigVar::GetF() const
{
    return m_ValueF;
}



bool
ConfigVar::GetB() const
{
    return m_ValueB;
}



Ogre::String
ConfigVar::GetS() const
{
    return m_ValueS;
}



void
ConfigVar::SetI(int value)
{
    m_ValueS = Ogre::StringConverter::toString(value);
    UpdateVariables();
}



void
ConfigVar::SetF(float value)
{
    m_ValueS = Ogre::StringConverter::toString(value);
    UpdateVariables();
}



void
ConfigVar::SetB(bool value)
{
    m_ValueS = Ogre::StringConverter::toString(value);
    UpdateVariables();
}



void
ConfigVar::SetS(const Ogre::String& value)
{
    m_ValueS = value;
    UpdateVariables();
}



const Ogre::String&
ConfigVar::GetName() const
{
    return m_Name;
}



const Ogre::String&
ConfigVar::GetDescription() const
{
    return m_Description;
}



const Ogre::String&
ConfigVar::GetDefaultValue() const
{
    return m_DefaultValue;
}



void
ConfigVar::UpdateVariables()
{
    m_ValueI = Ogre::StringConverter::parseInt(m_ValueS);
    m_ValueF = Ogre::StringConverter::parseReal(m_ValueS);
    m_ValueB = Ogre::StringConverter::parseBool(m_ValueS);
}
