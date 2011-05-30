// $Id$

#include <OgreLogManager.h>

#include "Configuration.h"
#include "TextManager.h"
#include "XmlLangFile.h"
#include "XmlTextFile.h"

TextManager* g_TextManager = NULL;



TextManager::TextManager(void)
{
    XmlLangFile lang_file(Configuration::getSingleton().GetFileRoot() + "text/lang.xml");
    lang_file.LoadLanguageRoot(this, "English");

    Ogre::LogManager::getSingletonPtr()->logMessage("TextManager created. Language root '" + m_LanguageRoot + "'.");
}



TextManager::~TextManager(void)
{
}



void
TextManager::SetLanguageRoot(const Ogre::String& root)
{
    m_LanguageRoot = root;
}



void
TextManager::LoadTexts(const Ogre::String& file_name)
{
    XmlTextFile text_file(Configuration::getSingleton().GetFileRoot() + m_LanguageRoot + file_name);

    TextBlock text_block;
    text_block.block_name = file_name;
    text_file.LoadAllTexts(text_block.text);
    m_Texts.push_back(text_block);
}



void
TextManager::UnloadTexts(const Ogre::String& file_name)
{
    std::list<TextBlock>::iterator i;
    for (i = m_Texts.begin(); i != m_Texts.end(); ++i)
    {
        if ((*i).block_name == file_name)
        {
            m_Texts.erase(i);
        }
    }
}



const TextData
TextManager::GetText(const Ogre::String& name)
{
    for (int i = 0; i < m_Texts.size(); ++i)
    {
        for (int j = 0; j < m_Texts[i].text.size(); ++j)
        {
            if (m_Texts[i].text[j].name == name)
            {
                return m_Texts[i].text[j];
            }
        }
    }
}
