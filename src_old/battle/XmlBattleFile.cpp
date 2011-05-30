// $Id$

#include <OgreEntity.h>
#include <OgreLogManager.h>
#include <OgreRoot.h>
#include <OgreStringConverter.h>
#include <map>

#include "BattleModule.h"
#include "XmlBattleFile.h"
#include "XmlEnemyFile.h"
#include "XmlPlayerFile.h"
#include "../core/Configuration.h"
#include "../game/GameState.h"

struct EnemyNumber
{
    EnemyNumber(): number(0){};
    int number;
};



XmlBattleFile::XmlBattleFile(const Ogre::String& file):
    XmlFile(file)
{
    if (m_File != NULL)
    {
        m_RootNode = xmlDocGetRootElement(m_File);

        if (m_RootNode == NULL || xmlStrEqual(m_RootNode->name, BAD_CAST "battles") == false)
        {
            m_NormalFile = false;
            Ogre::LogManager::getSingletonPtr()->logMessage("Battle XML Manager: " + file + " is not a valid battle file! No <battles> in root.");
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



XmlBattleFile::~XmlBattleFile()
{
}



void
XmlBattleFile::Load(const int battle_id, BattleModule* battle_module)
{
    if (m_NormalFile != true)
    {
        return;
    }

    Ogre::SceneManager* scene_manager;
    scene_manager = Ogre::Root::getSingleton().getSceneManager("Scene");

    for (xmlNodePtr node = m_RootNode->xmlChildrenNode; node != NULL; node = node->next)
    {
        if (xmlStrEqual(node->name, BAD_CAST "battle"))
        {
            if (GetInt(node, "id") == battle_id)
            {
                Ogre::String map_name = GetString(node, "map_file");
                Ogre::LogManager::getSingletonPtr()->logMessage("Battle map name " + map_name + ".");

                battle_module->m_Background = scene_manager->createEntity("BattleField", map_name);
                scene_manager->getSceneNode("BattleModule")->createChildSceneNode("BattleField")->attachObject(battle_module->m_Background);



                // init player
                int party_size = 0;
                for (int i = 0; i < g_GameState->PartyGetSize(); ++i)
                {
                    if (g_GameState->GetPartyCharacter(i) != -1)
                    {
                        ++party_size;
                    }
                }

                for (int i = 0; i < g_GameState->PartyGetSize(); ++i)
                {
                    int chatacter_id = g_GameState->GetPartyCharacter(i);

                    if (chatacter_id != -1)
                    {

                        FighterData data;

                        XmlPlayerFile player(Configuration::getSingleton().GetFileRoot() + "battle/player.xml");
                        Ogre::String model = "";
                        Ogre::String script_file = "";
                        player.Load(chatacter_id, data, model, script_file);
                        if (model != "")
                        {
                            data.Copy(g_GameState->CharacterGet(chatacter_id));
                            data.relationship = PLAYER;
                            data.auto_action  = false;
                            data.timer_value  = 0;
                            data.timer_wait   = false;
                            data.in_action    = false;
                            data.fighter_id   = battle_module->m_Fighters.size();

                            Ogre::String unique_name = "Character" + Ogre::StringConverter::toString(chatacter_id);
                            Fighter* fighter = new Fighter(unique_name, model, scene_manager->getSceneNode("BattleModule")->createChildSceneNode("BattleModel" + unique_name), battle_module->m_ScriptManager);
                            fighter->data = data;

                            // if unit has script
                            if (script_file != "")
                            {
                                battle_module->m_ScriptManager->LoadFile(script_file);
                                // create this object
                                battle_module->m_ScriptManager->CreateFighterObject(data.script, fighter);
                            }

                            /////////////////////////
                            // hack
                            Ogre::Vector3 pos = Ogre::Vector3(0, 0, 0);
                            if (party_size == 1)
                            {
                                pos = Ogre::Vector3(0, 0, -1700);
                            }
                            else if (party_size == 2)
                            {
                                if (i == 0)
                                {
                                    pos = Ogre::Vector3(-1000, 0, -1700);
                                }
                                else if (i == 1)
                                {
                                    pos = Ogre::Vector3(1000, 0, -1700);
                                }
                            }

                            fighter->SetPosition(pos);
                            if (pos.z > 0)
                            {
                                fighter->SetDirection(Ogre::Degree(180));
                            }
                            /////////////////////////

                            battle_module->m_Fighters.push_back(fighter);
                        }
                    }
                }



                // init enemy
                std::map<int, EnemyNumber> inited_enemy_number;

                for (xmlNodePtr node_2 = node->xmlChildrenNode; node_2 != NULL; node_2 = node_2->next)
                {
                    if (!xmlStrEqual(node_2->name, BAD_CAST "formation"))
                    {
                        continue;
                    }

                    FighterData data;
                    XmlEnemyFile enemy(Configuration::getSingleton().GetFileRoot() + "battle/enemy.xml");
                    int enemy_id = GetInt(node_2, "enemy_id");
                    Ogre::String model = "";
                    Ogre::String script_file = "";
                    enemy.Load(enemy_id, data, model, script_file);
                    if (model != "")
                    {
                        data.relationship = ENEMY;
                        data.auto_action  = true;
                        data.timer_value  = 0;
                        data.timer_wait   = false;
                        data.in_action    = false;
                        data.fighter_id   = battle_module->m_Fighters.size();

                        Ogre::String unique_name = Ogre::StringConverter::toString(enemy_id) + "_" + Ogre::StringConverter::toString(inited_enemy_number[enemy_id].number);
                        Fighter* fighter = new Fighter(unique_name, model, scene_manager->getSceneNode("BattleModule")->createChildSceneNode("BattleModel" + unique_name), battle_module->m_ScriptManager);
                        fighter->data = data;

                        // if this is first monster of this kind init script
                        if (inited_enemy_number[enemy_id].number == 0 && script_file != "")
                        {
                            battle_module->m_ScriptManager->LoadFile(script_file);
                        }

                        if (script_file != "")
                        {
                            // create this object
                            battle_module->m_ScriptManager->CreateFighterObject(data.script, fighter);
                        }

                        /////////////////////////
                        // hack
                        Ogre::Vector3 pos = GetVector3(node_2, "position");
                        fighter->SetPosition(pos);
                        if (pos.z > 0)
                        {
                            fighter->SetDirection(Ogre::Degree(180));
                        }
                        /////////////////////////

                        battle_module->m_Fighters.push_back(fighter);

                        inited_enemy_number[enemy_id].number += 1;
                    }
                }

                return;
            }
        }
    }

    Ogre::LogManager::getSingletonPtr()->logMessage("Can't find data for battle with id " + Ogre::StringConverter::toString(battle_id) + ".");
}
