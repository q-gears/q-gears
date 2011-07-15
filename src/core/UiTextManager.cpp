#include "UiTextManager.h"



template<>UiTextManager *Ogre::Singleton< UiTextManager >::ms_Singleton = NULL;



UiTextManager::UiTextManager()
{
}



UiTextManager::~UiTextManager()
{
}



void
UiTextManager::SetLanguage( const Ogre::String& language )
{
}



void
UiTextManager::AddText( const Ogre::String& name, const Ogre::UTFString& text )
{
    m_Texts[ name ] = text;
}



void
UiTextManager::UnloadTexts()
{
    m_Texts.clear();
}



const Ogre::UTFString
UiTextManager::GetText( const Ogre::String& name )
{
    return m_Texts[ name ];
}
