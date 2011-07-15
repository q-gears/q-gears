#ifndef UI_TEXT_MANAGER_H
#define UI_TEXT_MANAGER_H

#include <OgreSingleton.h>
#include <OgreString.h>
#include <OgreUTFString.h>
#include <map>



class UiTextManager : public Ogre::Singleton< UiTextManager >
{
public:
    UiTextManager();
    virtual ~UiTextManager();

    void SetLanguage( const Ogre::String& language );

    void AddText( const Ogre::String& name, const Ogre::UTFString& text );
    void UnloadTexts();
    const Ogre::UTFString GetText( const Ogre::String& name );

private:
    std::map< Ogre::String, Ogre::UTFString > m_Texts;
};



#endif // UI_TEXT_MANAGER_H
