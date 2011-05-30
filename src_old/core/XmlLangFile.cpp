// $Id$

#include <OgreLogManager.h>

#include "XmlLangFile.h"



XmlLangFile::XmlLangFile(const Ogre::String& file):
    XmlFile(file)
{
    if (m_File != NULL)
    {
        m_RootNode = xmlDocGetRootElement(m_File);

        if (m_RootNode == NULL || xmlStrEqual(m_RootNode->name, BAD_CAST "languages") == false)
        {
            m_NormalFile = false;
            Ogre::LogManager::getSingletonPtr()->logMessage("Field XML Manager: " + file + " is not a valid languages file! No <languages> in root.");
        }
        else
        {
            m_NormalFile = true;
        }
    }
    else
    {
        m_NormalFile = false;
    }
}



XmlLangFile::~XmlLangFile(void)
{
}



void
XmlLangFile::LoadLanguageRoot(TextManager* text_manager, const Ogre::String& language)
{
    if (m_NormalFile != true)
    {
        return;
    }

    for (xmlNodePtr node = m_RootNode->xmlChildrenNode; node != NULL; node = node->next)
    {
        if (xmlStrEqual(node->name, BAD_CAST "language") && GetString(node, "name") == language)
        {
            for (xmlNodePtr node2 = node->xmlChildrenNode; node2 != NULL; node2 = node2->next)
            {
                if (xmlStrEqual(node2->name, BAD_CAST "root"))
                {
                    text_manager->SetLanguageRoot(GetString(node2, "path"));
                    return;
                }
            }
        }
    }

    Ogre::LogManager::getSingletonPtr()->logMessage("[ERROR] Language '" + language + "' not found in given lang.xml");
}
