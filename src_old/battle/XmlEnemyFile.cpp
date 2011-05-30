// $Id$

#include <OgreLogManager.h>
#include <OgreRoot.h>
#include <OgreStringConverter.h>

#include "XmlEnemyFile.h"



XmlEnemyFile::XmlEnemyFile(const Ogre::String& file):
    XmlFile(file)
{
    if (m_File != NULL)
    {
        m_RootNode = xmlDocGetRootElement(m_File);

        if (m_RootNode == NULL || xmlStrEqual(m_RootNode->name, BAD_CAST "enemies") == false)
        {
            m_NormalFile = false;
            Ogre::LogManager::getSingletonPtr()->logMessage("Battle XML Manager: " + file + " is not a valid enemy file! No <enemies> in root.");
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



XmlEnemyFile::~XmlEnemyFile()
{
}



void
XmlEnemyFile::Load(const int enemy_id, FighterData& data, Ogre::String& model, Ogre::String& script)
{
    if (m_NormalFile != true)
    {
        return;
    }

    Ogre::SceneManager* scene_manager;
    scene_manager = Ogre::Root::getSingleton().getSceneManager("Scene");

    for (xmlNodePtr node = m_RootNode->xmlChildrenNode; node != NULL; node = node->next)
    {
        if (xmlStrEqual(node->name, BAD_CAST "enemy"))
        {
            if (GetInt(node, "id") == enemy_id)
            {
                for (xmlNodePtr node2 = node->xmlChildrenNode; node2 != NULL; node2 = node2->next)
                {
                    if (xmlStrEqual(node2->name, BAD_CAST "action"))
                    {
                        data.action[GetInt(node2, "attack_id")] = GetString(node2, "action");
                    }
                }

                data.level                    = GetInt(node, "level");

                data.max_hp                   = GetInt(node, "max_hp");
                data.current_hp               = GetInt(node, "current_hp");
                data.max_mp                   = GetInt(node, "max_mp");
                data.current_mp               = GetInt(node, "current_mp");

                data.attack                   = GetInt(node, "attack");
                data.defense                  = GetInt(node, "defense");
                data.magic_attack             = GetInt(node, "magic_attack");
                data.magic_defense            = GetInt(node, "magic_defense");
                data.speed                    = GetInt(node, "speed");

                data.status_darkness          = GetBool(node, "status_darkness");
                data.status_darkness_immunity = GetBool(node, "status_darkness_immunity");

                data.row                      = 0;

                data.script                   = GetString(node, "script");
                data.action_idle              = GetString(node, "action_idle");
                data.action_hurt              = GetString(node, "action_hurt");

                model  = GetString(node, "model");
                script = GetString(node, "script_file");
                return;
            }
        }
    }

    Ogre::LogManager::getSingletonPtr()->logMessage("Can't find data for enemy with id " + Ogre::StringConverter::toString(enemy_id) + ".");
    return;
}
