// $Id$

#include <OgreLogManager.h>

#include "XmlTextFile.h"



XmlTextFile::XmlTextFile(const Ogre::String& file):
    XmlFile(file)
{
    if (m_File != NULL)
    {
        m_RootNode = xmlDocGetRootElement(m_File);

        if (m_RootNode == NULL || xmlStrEqual(m_RootNode->name, BAD_CAST "texts") == false)
        {
            m_NormalFile = false;
            Ogre::LogManager::getSingletonPtr()->logMessage("XML text Manager: " + file + " is not a valid texts file! No <texts> in root.");
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



XmlTextFile::~XmlTextFile(void)
{
}



void
XmlTextFile::LoadAllTexts(TextDataVector& texts)
{
    if (m_NormalFile != true)
    {
        return;
    }

    for (xmlNodePtr node = m_RootNode->xmlChildrenNode; node != NULL; node = node->next)
    {
        if (xmlStrEqual(node->name, BAD_CAST "dialog"))
        {
            TextData text;
            text.name   = GetString(node, "name");
            text.text   = GetText(node);
            text.width  = GetInt(node, "width");
            text.height = GetInt(node, "height");
            texts.push_back(text);
        }
    }
}
