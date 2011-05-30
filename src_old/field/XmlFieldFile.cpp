// $Id$

#include <OgreLogManager.h>
#include <OgreStringConverter.h>

#include "XmlFieldFile.h"



XmlFieldFile::XmlFieldFile(const Ogre::String& file):
    XmlFile(file)
{
    if (m_File != NULL)
    {
        m_RootNode = xmlDocGetRootElement(m_File);

        if (m_RootNode == NULL || xmlStrEqual(m_RootNode->name, BAD_CAST "maps") == false)
        {
            m_NormalFile = false;
            Ogre::LogManager::getSingletonPtr()->logMessage("Field XML Manager: " + file + " is not a valid field file! No <maps> in root.");
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



XmlFieldFile::~XmlFieldFile(void)
{
}



const Ogre::String
XmlFieldFile::GetMapFileNameById(const int field_id)
{
    Ogre::String ret("");

    if (m_NormalFile != true)
    {
        return ret;
    }

    for (xmlNodePtr node = m_RootNode->xmlChildrenNode; node != NULL; node = node->next)
    {
        if (xmlStrEqual(node->name, BAD_CAST "map"))
        {
            if (GetInt(node, "id") == field_id)
            {
                ret = GetString(node, "file_name");
                return ret;
            }
        }
    }

    Ogre::LogManager::getSingletonPtr()->logMessage("Can't find field's map with id " + Ogre::StringConverter::toString(field_id) + ".");
    return ret;
}
