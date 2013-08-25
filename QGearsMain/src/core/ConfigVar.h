#ifndef CONFIG_VAR_H
#define CONFIG_VAR_H

#include <OgreString.h>



class ConfigVarManager;



class ConfigVar
{
    friend class ConfigVarManager;

public:
                        ConfigVar(const Ogre::String& name, const Ogre::String& description, const Ogre::String& default_value);

    int                 GetI() const;
    float               GetF() const;
    bool                GetB() const;
    Ogre::String        GetS() const;

    void                SetI(int value);
    void                SetF(float value);
    void                SetB(bool value);
    void                SetS(const Ogre::String& value);

    const Ogre::String& GetName() const;
    const Ogre::String& GetDescription() const;
    const Ogre::String& GetDefaultValue() const;

    void                UpdateVariables();

private:
    // forbid copy
    ConfigVar(const ConfigVar&);
    ConfigVar&operator=(const ConfigVar&);

    Ogre::String    m_Name;
    Ogre::String    m_Description;
    Ogre::String    m_DefaultValue;
    int             m_ValueI;
    float           m_ValueF;
    bool            m_ValueB;
    Ogre::String    m_ValueS;

    ConfigVar*          m_Previous;
    static ConfigVar*   m_StaticConfigVarList;
};



#endif // CONFIG_VAR_H
