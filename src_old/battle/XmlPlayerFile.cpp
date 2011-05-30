// $Id$

#include <OgreLogManager.h>
#include <OgreRoot.h>
#include <OgreStringConverter.h>

#include "XmlPlayerFile.h"



XmlPlayerFile::XmlPlayerFile(const Ogre::String& file):
    XmlFile(file)
{
    if (m_File != NULL)
    {
        m_RootNode = xmlDocGetRootElement(m_File);

        if (m_RootNode == NULL || xmlStrEqual(m_RootNode->name, BAD_CAST "players") == false)
        {
            m_NormalFile = false;
            Ogre::LogManager::getSingletonPtr()->logMessage("Battle XML Manager: " + file + " is not a valid player file! No <players> in root.");
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



XmlPlayerFile::~XmlPlayerFile()
{
}



void
XmlPlayerFile::Load(const int player_id, FighterData& data, Ogre::String& model, Ogre::String& script)
{
    if (m_NormalFile != true)
    {
        return;
    }

    Ogre::SceneManager* scene_manager;
    scene_manager = Ogre::Root::getSingleton().getSceneManager("Scene");

    for (xmlNodePtr node = m_RootNode->xmlChildrenNode; node != NULL; node = node->next)
    {
        if (xmlStrEqual(node->name, BAD_CAST "player"))
        {
            if (GetInt(node, "id") == player_id)
            {
                for (xmlNodePtr node2 = node->xmlChildrenNode; node2 != NULL; node2 = node2->next)
                {
                    if (xmlStrEqual(node2->name, BAD_CAST "action"))
                    {
                        data.action[GetInt(node2, "attack_id")] = GetString(node2, "action");
                    }
                }

                data.script                   = GetString(node, "script");
                data.action_idle              = GetString(node, "action_idle");
                data.action_hurt              = GetString(node, "action_hurt");

                model  = GetString(node, "model");
                script = GetString(node, "script_file");
                return;
            }
        }
    }

    Ogre::LogManager::getSingletonPtr()->logMessage("Can't find data for player with id " + Ogre::StringConverter::toString(player_id) + ".");
    return;
}
