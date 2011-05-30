// $Id$

#include "XmlBackground2DFile.h"



XmlBackground2DFile::XmlBackground2DFile(const std::string& file):
    XmlFile(file)
{
    if (m_File != NULL)
    {
        m_RootNode = xmlDocGetRootElement(m_File);

        if (m_RootNode == NULL || xmlStrEqual(m_RootNode->name, BAD_CAST "background") == false)
        {
            m_NormalFile = false;
            Ogre::LogManager::getSingletonPtr()->logMessage("Field XML Manager: " + file + " is not a valid background file! No <background> in root.");
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



XmlBackground2DFile::~XmlBackground2DFile(void)
{
}



Background2D*
XmlBackground2DFile::Load(void)
{
    Background2D* ret = new Background2D();

    if (m_NormalFile != true)
    {
        return ret;
    }

    for (xmlNodePtr node = m_RootNode->xmlChildrenNode; node != NULL; node = node->next)
    {
        if (xmlStrEqual(node->name, BAD_CAST "bottom"))
        {
            for (xmlNodePtr node2 = node->xmlChildrenNode; node2 != NULL; node2 = node2->next)
            {
                if (xmlStrEqual(node2->name, BAD_CAST "bottom_tile"))
                {
                    ret->AddTileBottom(GetInt(node2, "x"),
                                       GetInt(node2, "y"),
                                       GetInt(node2, "width"),
                                       GetInt(node2, "height"),
                                       GetInt(node2, "src_x"),
                                       GetInt(node2, "src_y"));
                }
            }
        }
    }

    Ogre::LogManager::getSingletonPtr()->logMessage("Finish loading Background from XML.");

    return ret;
}
