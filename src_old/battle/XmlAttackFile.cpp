// $Id$

#include <OgreLogManager.h>
#include <OgreRoot.h>
#include <OgreStringConverter.h>

#include "BattleModule.h"
#include "XmlAttackFile.h"



XmlAttackFile::XmlAttackFile(const Ogre::String& file):
    XmlFile(file)
{
    if (m_File != NULL)
    {
        m_RootNode = xmlDocGetRootElement(m_File);

        if (m_RootNode == NULL || xmlStrEqual(m_RootNode->name, BAD_CAST "attacks") == false)
        {
            m_NormalFile = false;
            Ogre::LogManager::getSingletonPtr()->logMessage("Battle XML Manager: " + file + " is not a valid attacks file! No <attacks> in root.");
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



XmlAttackFile::~XmlAttackFile()
{
}



void
XmlAttackFile::Load(BattleModule* battle_module)
{
    if (m_NormalFile != true)
    {
        return;
    }

    battle_module->m_AttacksData.clear();

    for (xmlNodePtr node = m_RootNode->xmlChildrenNode; node != NULL; node = node->next)
    {
        if (xmlStrEqual(node->name, BAD_CAST "attack"))
        {
            AttackData attack;
            attack.id      = GetInt(node, "id");
            attack.name    = GetString(node, "name");
            attack.formula = GetString(node, "formula");
            attack.power   = GetFloat(node, "power");

            battle_module->m_AttacksData.push_back(attack);
        }
    }
}
