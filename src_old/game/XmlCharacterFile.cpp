// $Id$

#include <OgreLogManager.h>
#include <OgreStringConverter.h>

#include "XmlCharacterFile.h"



XmlCharacterFile::XmlCharacterFile(const Ogre::String& file):
    XmlFile(file)
{
    if (m_File != NULL)
    {
        m_RootNode = xmlDocGetRootElement(m_File);

        if (m_RootNode == NULL || xmlStrEqual(m_RootNode->name, BAD_CAST "characters") == false)
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



XmlCharacterFile::~XmlCharacterFile(void)
{
}



void
XmlCharacterFile::GetCharacters(std::vector<Character>& character_vector)
{
    if (m_NormalFile != true)
    {
        return;
    }

    character_vector.clear();

    for (xmlNodePtr node = m_RootNode->xmlChildrenNode; node != NULL; node = node->next)
    {
        if (xmlStrEqual(node->name, BAD_CAST "character"))
        {
            Character character;
            character.id                       = GetInt(node, "id");
            character.name                     = GetString(node, "name");

            character.level                    = GetInt(node, "level");

            character.max_hp                   = GetInt(node, "max_hp");
            character.current_hp               = GetInt(node, "current_hp");
            character.max_mp                   = GetInt(node, "max_mp");
            character.current_mp               = GetInt(node, "current_mp");

            character.attack                   = GetInt(node, "attack");
            character.defense                  = GetInt(node, "defense");
            character.magic_attack             = GetInt(node, "magic_attack");
            character.magic_defense            = GetInt(node, "magic_defense");
            character.speed                    = GetInt(node, "speed");

            character.row                      = GetInt(node, "row");

            character.status_darkness          = GetBool(node, "status_darkness");
            character.status_darkness_immunity = GetBool(node, "status_darkness_immunity");

            character.available                = GetBool(node, "available");
            character.locked                   = GetBool(node, "locked");

            character_vector.push_back(character);
        }
    }
}
