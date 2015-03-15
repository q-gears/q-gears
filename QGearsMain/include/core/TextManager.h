#ifndef TEXT_MANAGER_H
#define TEXT_MANAGER_H

#include <OgreString.h>
#include <OgreSingleton.h>

#include "tinyxml/tinyxml.h"



class TextManager : public Ogre::Singleton< TextManager >
{
public:
    TextManager();
    virtual ~TextManager();

    void InitCmd();

    void SetLanguage( const Ogre::String& language );
    const Ogre::String& GetLanguage();
    void AddText( const Ogre::String& name, TiXmlNode* node );
    void AddDialog( const Ogre::String& name, TiXmlNode* node, const float width, const float height );
    TiXmlNode* GetText( const Ogre::String& name ) const;
    TiXmlNode* GetDialog( const Ogre::String& name, float &width, float& height ) const;
    void UnloadTexts();

private:
    Ogre::String m_Language;

    struct Text
    {
        Ogre::String name;
        TiXmlNode* node;
    };
    std::vector< Text > m_Texts;

    struct Dialog
    {
        Ogre::String name;
        TiXmlNode* node;
        float width;
        float height;
    };
     std::vector< Dialog > m_Dialogs;
};



#endif // TEXT_MANAGER_H
