#ifndef TEXT_MANAGER_H
#define TEXT_MANAGER_H

#include <OgreSingleton.h>
#include <OgreString.h>
#include <OgreUTFString.h>
#include <map>



class TextManager : public Ogre::Singleton< TextManager >
{
public:
    TextManager();
    virtual ~TextManager();

    void SetLanguage( const Ogre::String& language );

    void AddText( const Ogre::String& name, const Ogre::UTFString& text );
    void UnloadTexts();
    const Ogre::UTFString GetText( const Ogre::String& name );

private:
    std::map< Ogre::String, Ogre::UTFString > m_Texts;
};



#endif // TEXT_MANAGER_H
