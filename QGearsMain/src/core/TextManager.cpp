#include "core/TextManager.h"
#include "core/TextManagerCommands.h"
#include "core/XmlTextsFile.h"



template<>TextManager* Ogre::Singleton< TextManager >::msSingleton = NULL;



TextManager::TextManager():
    m_Language( "" )
{
    InitCmd();
}



TextManager::~TextManager()
{
    UnloadTexts();
}



void
TextManager::SetLanguage( const Ogre::String& language )
{
    m_Language = language;

    UnloadTexts();

    XmlTextsFile texts( "./data/texts.xml" );
    texts.LoadTexts();
}



const Ogre::String&
TextManager::GetLanguage()
{
    return m_Language;
}



void
TextManager::AddText( const Ogre::String& name, TiXmlNode* node )
{
    Text text;
    text.name = name;
    text.node = node;
    m_Texts.push_back( text );
}



void
TextManager::AddDialog( const Ogre::String& name, TiXmlNode* node, const float width, const float height )
{
    Dialog dialog;
    dialog.name = name;
    dialog.node = node;
    dialog.width = width;
    dialog.height = height;
    m_Dialogs.push_back( dialog );
}



TiXmlNode*
TextManager::GetText( const Ogre::String& name ) const
{
    for( unsigned int i = 0; i < m_Texts.size(); ++i )
    {
        if( m_Texts[ i ].name == name )
        {
            return m_Texts[ i ].node;
        }
    }

    LOG_WARNING( "Can't find text \"" + name + "\"." );

    return NULL;
}



TiXmlNode*
TextManager::GetDialog( const Ogre::String& name, float &width, float& height ) const
{
    for( unsigned int i = 0; i < m_Dialogs.size(); ++i )
    {
        if( m_Dialogs[ i ].name == name )
        {
            width = m_Dialogs[ i ].width;
            height = m_Dialogs[ i ].height;
            return m_Dialogs[ i ].node;
        }
    }

    return NULL;
}



void
TextManager::UnloadTexts()
{
    for( unsigned int i = 0; i < m_Texts.size(); ++i )
    {
        delete m_Texts[ i ].node;
    }
    m_Texts.clear();

    for( unsigned int i = 0; i < m_Dialogs.size(); ++i )
    {
        delete m_Dialogs[ i ].node;
    }
    m_Dialogs.clear();
}
