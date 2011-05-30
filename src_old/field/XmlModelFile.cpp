// $Id$

#include <OgreLogManager.h>
#include <OgreStringConverter.h>

#include "XmlModelFile.h"



XmlModelFile::XmlModelFile(const Ogre::String& file):
    XmlFile(file)
{
    if (m_File != NULL)
    {
        m_RootNode = xmlDocGetRootElement(m_File);

        if (m_RootNode == NULL || xmlStrEqual(m_RootNode->name, BAD_CAST "models") == false)
        {
            m_NormalFile = false;
            Ogre::LogManager::getSingletonPtr()->logMessage("Field XML Manager: " + file + " is not a valid model file! No <models> in root.");
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



XmlModelFile::~XmlModelFile(void)
{
}



const Ogre::String
XmlModelFile::GetModelFileNameById(const int model_id)
{
    Ogre::String ret("");

    if (m_NormalFile != true)
    {
        return ret;
    }

    for (xmlNodePtr node = m_RootNode->xmlChildrenNode; node != NULL; node = node->next)
    {
        if (xmlStrEqual(node->name, BAD_CAST "model"))
        {
            if (GetInt(node, "id") == model_id)
            {
                ret = GetString(node, "file_name");
                return ret;
            }
        }
    }

    Ogre::LogManager::getSingletonPtr()->logMessage("[ERROR] Can't find model with id " + Ogre::StringConverter::toString(model_id) + ".");
    return ret;
}
