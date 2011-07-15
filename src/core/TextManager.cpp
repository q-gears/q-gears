#include "TextManager.h"



template<>TextManager *Ogre::Singleton< TextManager >::ms_Singleton = NULL;



TextManager::TextManager()
{
}



TextManager::~TextManager()
{
}



void
TextManager::SetLanguage( const Ogre::String& language )
{
}



void
TextManager::AddText( const Ogre::String& name, const Ogre::UTFString& text )
{
    m_Texts[ name ] = text;
}



void
TextManager::UnloadTexts()
{
    m_Texts.clear();
}



const Ogre::UTFString
TextManager::GetText( const Ogre::String& name )
{
    return m_Texts[ name ];
}
