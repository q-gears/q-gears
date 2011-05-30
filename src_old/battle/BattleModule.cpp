// $Id$

#include <libxml/tree.h>
#include <Ogre.h>

#include "BattleModule.h"
#include "XmlAttackFile.h"
#include "XmlBattleFile.h"
#include "../core/Configuration.h"
#include "../core/ModuleManager.h"



BattleModule::BattleModule(const int parameter):
    Module(parameter),
    m_BattleId(parameter),

    m_Background(NULL),
    m_Camera(NULL),
    m_ScriptManager(NULL),

    m_BattleActionCurrentPriority(0)
{
    Ogre::LogManager::getSingletonPtr()->logMessage("BattleModule created.");
}



BattleModule::~BattleModule(void)
{
    if (m_Camera != NULL)
    {
        delete m_Camera;
    }
    if (m_ScriptManager != NULL)
    {
        delete m_ScriptManager;
    }

    Ogre::LogManager::getSingletonPtr()->logMessage("BattleModule destroyed.");
}



void
BattleModule::Input(const Event& input)
{
    bool debug = false;
    if (input.name == "debug_battle_fighter")
    {
        if (input.value.size() >= 1)
        {
            debug = Ogre::StringConverter::parseBool(input.value[0]);
        }
        else
        {
            debug = Configuration::getSingleton().GetOptionBool(input.name);
            debug = (debug == true) ? false : true;
        }

        Configuration::getSingleton().SetOption(input.name, debug);
    }

    if (input.name == "debug_battle_fighter")
    {
        for (int i = 0; i < m_Fighters.size(); ++i)
        {
            m_Fighters[i]->ShowDebug(debug);
        }
    }



    if (input.name == "game_cancel")
    {
        SetState(MODULE_FINISH);
    }

    m_Camera->Input(input);
}



void
BattleModule::OnStart(const float delta_time)
{
    m_Camera        = new BattleCamera();
    m_ScriptManager = new BattleScriptManager(this);



    LoadBattle(m_BattleId);



    for (int i = 0; i < m_Fighters.size(); ++i)
    {
        m_Fighters[i]->ShowDebug(Configuration::getSingleton().GetOptionBool("debug_battle_fighter"));
    }



    SetState(MODULE_RUN);
    Ogre::LogManager::getSingletonPtr()->logMessage("BattleModule started.");
}



void
BattleModule::Update(const float delta_time)
{
    // update fighter
    for (int i = 0; i < m_Fighters.size(); ++i)
    {
        m_Fighters[i]->Update(delta_time);

        if (m_Fighters[i]->data.status_death != true)
        {
            if (m_Fighters[i]->data.timer_value < 5.0f)
            {
                m_Fighters[i]->data.timer_value += delta_time;

                if (m_Fighters[i]->data.timer_value >= 5.0f)
                {
                    if (m_Fighters[i]->data.auto_action == true)
                    {
                        if (m_Fighters[i]->data.script != "")
                        {
                            m_BattleActionCurrentPriority = 2;
                            ExecuteLogic(i, "on_action");
                        }
                    }
                }
            }
            else if (m_Fighters[i]->data.timer_wait == false)
            {
                m_Fighters[i]->data.timer_value = 0;
            }
        }
    }



    // execute action from battle queue
    int fighter_in_action;
    for (fighter_in_action = 0; fighter_in_action < m_Fighters.size(); ++fighter_in_action)
    {
        if (m_Fighters[fighter_in_action]->data.in_action == true)
        {
            break;
        }
    }
    if (fighter_in_action >= m_Fighters.size())
    {
        for (int i = 0; i < 8; ++i)
        {
            if (m_BattleActionQueue[i].size() > 0)
            {
                ExecuteAction(m_BattleActionQueue[i].front());

                m_BattleActionQueue[i].pop();

                break;
            }
        }
    }



    m_Camera->Update(delta_time);



    m_ScriptManager->Update(delta_time);
}



void
BattleModule::OnFinish(const float delta_time)
{
    UnloadBattle();
    SetState(MODULE_STOP);
    Ogre::LogManager::getSingletonPtr()->logMessage("BattleModule stopped.");
}



void
BattleModule::ScriptRunCommand(const BattleActionType action, const int action_id)
{
    if (m_BattleActionCurrentPriority < 8)
    {
        RequestedBattleAction battle_action;
        battle_action.type          = action;
        battle_action.action_id     = action_id;

        Ogre::LogManager::getSingletonPtr()->logMessage("Add battle_action with priority '" + Ogre::StringConverter::toString(m_BattleActionCurrentPriority) + "': action='" + Ogre::StringConverter::toString(action) + "', action_id='" + Ogre::StringConverter::toString(action_id) + "'.");

        // get target ids
        m_ScriptManager->GetTableFighter(battle_action.target, "fighters_target");
        for (int i = 0; i < battle_action.target.size(); ++i)
        {
            Ogre::LogManager::getSingletonPtr()->logMessage("Target:" + battle_action.target[i]->GetName() + ".");
        }

        // get actor ids
        m_ScriptManager->GetFighter(battle_action.actor, "fighter_self");
        Ogre::LogManager::getSingletonPtr()->logMessage("Self:" + battle_action.actor->GetName() + ".");

        battle_action.actor->data.timer_wait = true;
        m_BattleActionQueue[m_BattleActionCurrentPriority].push(battle_action);
    }
}



void
BattleModule::LoadBattle(const int battle_id)
{
    Ogre::SceneManager* scene_manager;
    scene_manager = Ogre::Root::getSingleton().getSceneManager("Scene");
    scene_manager->getRootSceneNode()->createChildSceneNode("BattleModule");
    scene_manager->setAmbientLight(Ogre::ColourValue(1.0, 1.0, 1.0));

    XmlBattleFile battle_file(Configuration::getSingleton().GetFileRoot() + "battle/battle.xml");
    battle_file.Load(battle_id, this);

    XmlAttackFile attack_file(Configuration::getSingleton().GetFileRoot() + "battle/attack.xml");
    attack_file.Load(this);

    for (int i = 0; i < m_Fighters.size(); ++i)
    {
        if (m_Fighters[i]->data.script != "")
        {
            m_BattleActionCurrentPriority = 0;
            ExecuteLogic(i, "on_start");
        }
    }
}



void
BattleModule::UnloadBattle()
{
    for (int i = 0; i < m_Fighters.size(); ++i)
    {
        delete m_Fighters[i];
    }
    m_Fighters.clear();

    Ogre::SceneManager* scene_manager;
    scene_manager = Ogre::Root::getSingleton().getSceneManager("Scene");
    scene_manager->destroyEntity(m_Background);

    scene_manager->getRootSceneNode()->removeAndDestroyChild("BattleModule");
}



void
BattleModule::SetVariableForFighter(const int fighter_id)
{
    // fill array with enemies of this fighter
    FighterVector fighters_enemy;
    for (int i = 0; i < m_Fighters.size(); ++i)
    {
        if (m_Fighters[i]->data.relationship != m_Fighters[fighter_id]->data.relationship &&
            m_Fighters[i]->data.status_death != true)
        {
            fighters_enemy.push_back(m_Fighters[i]);
            Ogre::LogManager::getSingletonPtr()->logMessage("Add '" + m_Fighters[i]->GetName() + "' to target.");
        }
    }
    // fill array with ally of this fighter
    FighterVector fighters_ally;
    for (int i = 0; i < m_Fighters.size(); ++i)
    {
        if (m_Fighters[i]->data.relationship == m_Fighters[fighter_id]->data.relationship)
        {
            fighters_ally.push_back(m_Fighters[i]);
        }
    }

    m_ScriptManager->SetFighter(m_Fighters[fighter_id], "fighter_self");
    m_ScriptManager->SetTableFighter(fighters_enemy, "fighters_enemy");
    m_ScriptManager->SetTableFighter(fighters_ally, "fighters_ally");
}



void
BattleModule::ExecuteLogic(const int id, const Ogre::String& function)
{
    if (m_Fighters[id]->data.script != "")
    {
        SetVariableForFighter(id);
        m_ScriptManager->ExecuteLogic(m_Fighters[id]->GetName(), function);
    }
}



void
BattleModule::ExecuteAction(const RequestedBattleAction& action)
{
    Ogre::LogManager::getSingletonPtr()->logMessage("Execute battle_action: action='" + Ogre::StringConverter::toString(action.type) + "', action_id='" + Ogre::StringConverter::toString(action.action_id) + "'.");
    bool error = false;

    if (action.type == MONSTER_ACTION)
    {
        for (int i = 0; i < action.target.size(); ++i)
        {
            Ogre::LogManager::getSingletonPtr()->logMessage("Target:" + action.target[i]->GetName() + ".");
        }

        Ogre::LogManager::getSingletonPtr()->logMessage("Self:" + action.actor->GetName() + ".");

        int attack_id = FindAttack(action.action_id);
        if (attack_id != -1)
        {
            for (int i = 0; i < action.target.size(); ++i)
            {
                ExecuteDamage(action.actor, action.target[i], m_AttacksData[attack_id]);
            }

            if (action.actor->data.action[action.action_id] != "")
            {
                Ogre::LogManager::getSingletonPtr()->logMessage("Set new action:" + action.actor->data.action[action.action_id] + ".");
                m_ScriptManager->SetFighterAction(action.actor->data.fighter_id, action.actor->data.action[action.action_id], action.target);
                action.actor->data.in_action = true;
            }
            else
            {
                error = true;
                Ogre::LogManager::getSingletonPtr()->logMessage("[ERROR] There is no action found for attack with id:" + Ogre::StringConverter::toString(action.action_id) + ".");
            }
        }
        else
        {
            error = true;
            Ogre::LogManager::getSingletonPtr()->logMessage("[ERROR] Can't find attack with id:" + Ogre::StringConverter::toString(action.action_id) + ".");
        }
    }
    else
    {
        error = true;
        Ogre::LogManager::getSingletonPtr()->logMessage("[ERROR] Action type:" + Ogre::StringConverter::toString(action.type) + " not supported yet.");
    }

    if (error == true)
    {
        action.actor->data.timer_wait = false;
    }
}



void
BattleModule::ExecuteDamage(Fighter* attacker, Fighter* target, const AttackData& attack)
{
    int damage = m_ScriptManager->ExecuteDamage(attacker, target, attack);
    target->data.current_hp -= damage;
    if (target->data.current_hp <= 0)
    {
        target->data.current_hp = 0;
        target->data.status_death = true;
        target->ShowDebug(false);
    }
    Ogre::LogManager::getSingletonPtr()->logMessage("Damage:" + Ogre::StringConverter::toString(damage) + ". Current HP = '" + Ogre::StringConverter::toString(target->data.current_hp) + "'.");
}



const int
BattleModule::FindAttack(const int id) const
{
    for (int i = 0; i < m_AttacksData.size(); ++i)
    {
        if (m_AttacksData[i].id == id)
        {
            return i;
        }
    }

    return -1;
}
