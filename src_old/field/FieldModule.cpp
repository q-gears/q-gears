// $Id$

#include <OgreLogManager.h>
#include <OgreVector2.h>

#include "FieldModule.h"
#include "Math.h"
#include "XmlFieldFile.h"
#include "XmlFieldMapFile.h"
#include "XmlModelFile.h"
#include "../Main.h"
#include "../core/Configuration.h"
#include "../core/ModuleManager.h"
#include "../game/GameState.h"




FieldModule::FieldModule(const int parameter):
    Module(parameter),
    m_MapId(parameter),

    m_FieldScriptManager(NULL),
    m_MessageManager(NULL),
    m_FadeManager(NULL),
    m_Camera(NULL),

    m_Timer(0),

    m_FieldId(parameter),

    m_Walkmesh(NULL),

    m_AnimationIdle("0"),
    m_AnimationWalk("1"),
    m_AnimationRun("2"),

    m_MovementRotation(0),
    m_PlayerModelId(-1),
    m_PlayerModelLock(false),
    m_PlayerModelSlip(true),

    m_EncounterTable(0),
    m_EncounterEnabled(true),
    m_EncounterTime(0),
    m_EncounterPercent(0),
    m_EncounterPreviousBattle(-1)
{
    Ogre::LogManager::getSingletonPtr()->logMessage("FieldModule created.");
}



FieldModule::~FieldModule(void)
{
    if (m_FieldScriptManager != NULL)
    {
        delete m_FieldScriptManager;
    }

    if (m_MessageManager != NULL)
    {
        delete m_MessageManager;
    }

    if (m_FadeManager != NULL)
    {
        delete m_FadeManager;
    }

    if (m_Camera != NULL)
    {
        delete m_Camera;
    }

    Ogre::LogManager::getSingletonPtr()->logMessage("FieldModule destroyed.");
}



void
FieldModule::Input(const Event& input)
{
    bool debug = false;
    if (input.name == "debug_field_walkmesh" ||
        input.name == "debug_field_model" ||
        input.name == "debug_field_script" ||
        input.name == "debug_field_message" ||
        input.name == "debug_field_fade" ||
        input.name == "debug_field_encounter" ||
        input.name == "debug_field_triggers")
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

    if (input.name == "debug_field_walkmesh")
    {
        m_Walkmesh->setVisible(debug);
    }
    else if (input.name == "debug_field_model")
    {
        for (int i = 0; i < m_Models.size(); ++i)
        {
            m_Models[i]->ShowDebug(debug);
        }
    }
    else if (input.name == "debug_field_script")
    {
        m_FieldScriptManager->ShowDebug(debug);
    }
    else if (input.name == "debug_field_message")
    {
        m_MessageManager->ShowDebug(debug);
    }
    else if (input.name == "debug_field_fade")
    {
        m_FadeManager->ShowDebug(debug);
    }
    else if (input.name == "debug_field_encounter")
    {
        if (debug == true)
        {
            m_DebugEncounterOverlay->show();
        }
        else
        {
            m_DebugEncounterOverlay->hide();
        }
    }
    else if (input.name == "debug_field_triggers")
    {
        for (int i = 0; i < m_LineTriggers.size(); ++i)
        {
            m_LineTriggers[i]->ShowDebug(debug);
        }
    }



    else if (input.name == "game_up")
    {
        m_MoveButtons.up = true;
    }
    else if (input.name == "game_down")
    {
        m_MoveButtons.down = true;
    }
    else if (input.name == "game_left")
    {
        m_MoveButtons.left = true;
    }
    else if (input.name == "game_right")
    {
        m_MoveButtons.right = true;
    }
    else if (input.name == "game_run")
    {
        m_MoveButtons.run = true;
    }
    else if (input.name == "game_ok")
    {
        CheckEntityTalk();

        for (int i = 0; i < m_LineTriggers.size(); ++i)
        {
            if (m_LineTriggers[i]->IsEnabled() == true && m_LineTriggers[i]->IsCanBeActivated() == true)
            {
                m_FieldScriptManager->AddScript(m_LineTriggers[i]->GetName(), "on_activate_line", 1);
            }
        }
    }
    else if (input.name == "game_menu")
    {
        //g_ModuleManager->RunMenu(0);
    }



    m_MessageManager->Input(input);



    m_Camera->Input(input);
}



void
FieldModule::OnStart(const float delta_time)
{
    // debug info
    m_DebugEncounterText = new TextArea("DebugEncounterText");
    m_DebugEncounterText->setCaption("");
    m_DebugEncounterText->setMetricsMode(Ogre::GMM_PIXELS);
    m_DebugEncounterText->setPosition(5, 5);
    m_DebugEncounterText->setTextAlignment(TextArea::LEFT);
    m_DebugEncounterText->setFontName("DebugText");
    m_DebugEncounterText->setCharHeight(18);

    m_DebugEncounterOverlay = Ogre::OverlayManager::getSingleton().create("DebugEncounterOverlay");
    m_DebugEncounterOverlay->setZOrder(QGOO_FIELD_DEBUG);
    m_DebugEncounterOverlay->add2D((Ogre::OverlayContainer*)m_DebugEncounterText);
    if (Configuration::getSingleton().GetOptionBool("debug_field_encounter") == true)
    {
        m_DebugEncounterOverlay->show();
    }
    else
    {
        m_DebugEncounterOverlay->hide();
    }



    // this inited first cause it needed for all managers, later we add all managers to script
    m_FieldScriptManager = new FieldScriptManager(this);
    m_FieldScriptManager->ShowDebug(Configuration::getSingleton().GetOptionBool("debug_field_script"));

    m_MessageManager = new MessageManager(this, m_FieldScriptManager);
    m_MessageManager->ShowDebug(Configuration::getSingleton().GetOptionBool("debug_field_message"));
    m_FieldScriptManager->AddMessageManagerToScript(m_MessageManager);

    m_FadeManager = new FieldFadeManager(this, m_FieldScriptManager);
    m_FadeManager->ShowDebug(Configuration::getSingleton().GetOptionBool("debug_field_fade"));
    m_FieldScriptManager->AddFadeManagerToScript(m_FadeManager);

    m_Camera   = new FieldCamera();
    m_Walkmesh = new Walkmesh();

    LoadMap(m_MapId);

    m_Walkmesh->setVisible(Configuration::getSingleton().GetOptionBool("debug_field_walkmesh"));

    for (int i = 0; i < m_LineTriggers.size(); ++i)
    {
        m_LineTriggers[i]->ShowDebug(Configuration::getSingleton().GetOptionBool("debug_field_triggers"));
    }

    SetState(MODULE_RUN);
    Ogre::LogManager::getSingletonPtr()->logMessage("FieldModule started.");
}



void
FieldModule::Update(const float delta_time)
{
    for (int i = 0; i < m_Models.size(); ++i)
    {
        m_Models[i]->Update(delta_time);
    }



    // if game not on pause
    if (delta_time != 0)
    {
        for (int i = 0; i < m_Models.size(); ++i)
        {
            switch (m_Models[i]->GetState())
            {
                case STAND:
                {
                    m_Models[i]->AnimationUpdate(delta_time);
                }
                break;

                case MOVE:
                {
                    m_Models[i]->AnimationUpdate(delta_time);
                    SetNextMoveStep(i, delta_time);
                }
                break;

                case JUMP:
                {
                    m_Models[i]->AnimationUpdate(delta_time);
                    SetNextJumpStep(i, delta_time);
                }
                break;

                case CLIMB:
                {
                    SetNextClimbStep(i, delta_time);
                }
                break;
            }
        }



        for (int i = 0; i < m_Models.size(); ++i)
        {
            if (m_Models[i]->GetOffsetType() != NONE)
            {
                SetNextOffsetStep(i, delta_time);
            }
        }



        for (int i = 0; i < m_Models.size(); ++i)
        {
            if (m_Models[i]->GetTurnType() != NONE)
            {
                SetNextTurnStep(i, delta_time);
            }
        }



        if (m_PlayerModelLock != true && m_PlayerModelId != -1)
        {
            if (m_Models[m_PlayerModelId]->GetState() == STAND)
            {
                Ogre::Vector3 move_vector(0.0f, 0.0f, 0.0f);

                if (m_MoveButtons.up == true)
                {
                    move_vector.y += 1.0f;
                }
                else if (m_MoveButtons.down == true)
                {
                    move_vector.y -= 1.0f;
                }

                if (m_MoveButtons.left == true)
                {
                    move_vector.x -= 1.0f;
                }
                else if (m_MoveButtons.right == true)
                {
                    move_vector.x += 1.0f;
                }


                if (move_vector.y != 0 || move_vector.x != 0)
                {
                    if (m_MoveButtons.run == true)
                    {
                        m_Models[m_PlayerModelId]->SetSpeed(360);
                    }
                    else
                    {
                        m_Models[m_PlayerModelId]->SetSpeed(90);
                    }

                    //rotate move vector to field move rotation
                    Ogre::Quaternion q1;
                    q1.FromAngleAxis(m_MovementRotation, Ogre::Vector3::UNIT_Z);
                    move_vector = q1 * move_vector;
                    move_vector.normalise();
                    move_vector = move_vector * delta_time;

                    bool move = SetNextStep(m_PlayerModelId, Ogre::Vector2(move_vector.x, move_vector.y));

                    // check encounter
                    if (move == true && CheckEncounterAvailable() == true)
                    {
                        m_EncounterTime += delta_time;
                        if (m_EncounterTime >= 1)
                        {
                            CheckEncounters();
                            m_EncounterTime = 0;
                        }
                    }

                    // PC model work according to button state not the real speed
                    if (move == true)
                    {
                        if (m_MoveButtons.run == true)
                        {
                            m_Models[m_PlayerModelId]->PlayAnimationLooped(m_AnimationRun, 1);
                        }
                        else
                        {
                            m_Models[m_PlayerModelId]->PlayAnimationLooped(m_AnimationWalk, 1);
                        }
                    }
                    else
                    {
                        m_Models[m_PlayerModelId]->PlayAnimationLooped(m_AnimationIdle, 1);
                    }
                }
                else
                {
                    m_Models[m_PlayerModelId]->PlayAnimationLooped(m_AnimationIdle, 1);
                }
            }
        }
    }



    // encounter debug
    if (m_DebugEncounterOverlay->isVisible() == true)
    {
        Ogre::String caption;

        caption += "EncounterEnabled: " + Ogre::StringConverter::toString(m_EncounterEnabled) + "\n";
        caption += "EncounterTime: " + Ogre::StringConverter::toString(m_EncounterTime) + "\n";
        caption += "EncounterPercent: " + Ogre::StringConverter::toString(m_EncounterPercent) + "\n";
        caption += "EncounterTable: " + Ogre::StringConverter::toString(m_EncounterTable) + "\n";

        m_DebugEncounterText->setCaption(caption);
    }



    m_MoveButtons.right = false;
    m_MoveButtons.left  = false;
    m_MoveButtons.down  = false;
    m_MoveButtons.up    = false;
    m_MoveButtons.run   = false;

    //Ogre::LogManager::getSingletonPtr()->logMessage("FieldModule running.");

    m_FieldScriptManager->Update(delta_time);
    m_MessageManager->Update(delta_time);
    m_FadeManager->Update(delta_time);
    m_Camera->Update(delta_time);
}



void
FieldModule::OnFinish(const float delta_time)
{
    UnloadMap();

    // delete debug
    m_DebugEncounterOverlay->remove2D((Ogre::OverlayContainer*)m_DebugEncounterText);
    delete m_DebugEncounterText;
    Ogre::OverlayManager::getSingleton().destroy(m_DebugEncounterOverlay);



    SetState(MODULE_STOP);
    Ogre::LogManager::getSingletonPtr()->logMessage("FieldModule stopped.");
}



void
FieldModule::OnPauseOn()
{
    Ogre::Root::getSingleton().getSceneManager("Scene")->getRootSceneNode()->removeChild(m_SceneNode);

    m_MessageManager->ShowMessages(false);
    m_FadeManager->ShowFade(false);
    m_Walkmesh->setVisible(false);
    for (int i = 0; i < m_Models.size(); ++i)
    {
        m_Models[i]->ShowDebug(false);
    }
    m_FieldScriptManager->ShowDebug(false);
    m_MessageManager->ShowDebug(false);
    m_FadeManager->ShowDebug(false);
    m_DebugEncounterOverlay->hide();
    for (int i = 0; i < m_LineTriggers.size(); ++i)
    {
        m_LineTriggers[i]->ShowDebug(false);
    }

    Ogre::LogManager::getSingletonPtr()->logMessage("FieldModule paused.");
}



void
FieldModule::OnPauseOff()
{
    Ogre::Root::getSingleton().getSceneManager("Scene")->getRootSceneNode()->addChild(m_SceneNode);

    m_MessageManager->ShowMessages(true);
    m_FadeManager->ShowFade(true);
    m_Walkmesh->setVisible(Configuration::getSingleton().GetOptionBool("debug_field_walkmesh"));
    for (int i = 0; i < m_Models.size(); ++i)
    {
        m_Models[i]->ShowDebug(Configuration::getSingleton().GetOptionBool("debug_field_model"));
    }
    m_FieldScriptManager->ShowDebug(Configuration::getSingleton().GetOptionBool("debug_field_script"));
    m_MessageManager->ShowDebug(Configuration::getSingleton().GetOptionBool("debug_field_message"));
    m_FadeManager->ShowDebug(Configuration::getSingleton().GetOptionBool("debug_field_fade"));
    if (Configuration::getSingleton().GetOptionBool("debug_field_encounter") == true)
    {
        m_DebugEncounterOverlay->show();
    }
    for (int i = 0; i < m_LineTriggers.size(); ++i)
    {
        m_LineTriggers[i]->ShowDebug(Configuration::getSingleton().GetOptionBool("debug_field_triggers"));
    }

    // if battle was started - continue script
    if (m_BattleScriptInfo.entity_id != -1)
    {
        m_FieldScriptManager->ContinueEntityScriptExecution(m_BattleScriptInfo);
        m_BattleScriptInfo.entity_id = -1;
    }

    Ogre::LogManager::getSingletonPtr()->logMessage("FieldModule unpaused.");
}



void
FieldModule::LoadMap(const int field_id)
{
    Ogre::SceneManager* scene_manager;
    scene_manager = Ogre::Root::getSingleton().getSceneManager("Scene");
    m_SceneNode = scene_manager->getRootSceneNode()->createChildSceneNode("FieldModule");
    scene_manager->setAmbientLight(Ogre::ColourValue(1.0, 1.0, 1.0));


    XmlFieldFile field_file(Configuration::getSingleton().GetFileRoot() + "field/field.xml");
    Ogre::String name = field_file.GetMapFileNameById(field_id);
    Ogre::LogManager::getSingletonPtr()->logMessage("Load field \"" + Configuration::getSingleton().GetFileRoot() + name + "\".");

    if (name != "")
    {
        XmlFieldMapFile map_file(Configuration::getSingleton().GetFileRoot() + name);
        map_file.LoadMap(this);
    }

/*
    {
        XmlBackground2DFile background_file("data/field/map/md1stin.xml");
        m_Background = background_file.Load();
    }
*/
}



void
FieldModule::UnloadMap()
{
    //delete m_Background

    if (m_Walkmesh != NULL)
    {
        delete m_Walkmesh;
    }

    for (int i = 0; i < m_Models.size(); ++i)
    {
        delete m_Models[i];
    }

    for (int i = 0; i < m_LineTriggers.size(); ++i)
    {
        delete m_LineTriggers[i];
    }

    Ogre::SceneManager* scene_manager;
    scene_manager = Ogre::Root::getSingleton().getSceneManager("Scene");
    scene_manager->getRootSceneNode()->removeAndDestroyChild("FieldModule");
}



void
FieldModule::JumpToMap(const int map_id, const float x, const float y, const float z, const float direction)
{
    Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT] field:jump_to_map: Jump to map '" + Ogre::StringConverter::toString(map_id) + "'.");

    g_ModuleManager->RunField(map_id);
    g_GameState->SetPlayerCharacterPosition(Ogre::Vector3(x, y, z));
    g_GameState->SetPlayerCharacterDirection(Ogre::Degree(direction));
}



int
FieldModule::BattleRun(const int battle_id)
{
    if (m_BattleScriptInfo.entity_id != -1)
    {
        Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT ERROR] field:battle_run: Entity already waiting for something.");
        return 1;
    }
    m_BattleScriptInfo = m_FieldScriptManager->GetCurrentScriptInfo();


    Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT] field:battle_run: Start battle with id '" + Ogre::StringConverter::toString(battle_id) + "'.");

    g_ModuleManager->RunBattle(battle_id);

    return -1;
}



Entity*
FieldModule::LoadModel(const char* name, const int model_id)
{
    XmlModelFile model_file(Configuration::getSingleton().GetFileRoot() + "field/model.xml");
    Ogre::String file_name = model_file.GetModelFileNameById(model_id);

    Ogre::SceneNode* node = Ogre::Root::getSingleton().getSceneManager("Scene")->getSceneNode("FieldModule")->createChildSceneNode("Model" + Ogre::StringConverter::toString(m_Models.size()));
    Model* entity = new Model(name, file_name, node, m_FieldScriptManager, m_Walkmesh);

    entity->ShowDebug(Configuration::getSingleton().GetOptionBool("debug_field_model"));

    Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT] Create model '" + entity->GetName() + "' by requested model with id '" + Ogre::StringConverter::toString(model_id) + "' from file '" + file_name + "'.");

    m_Models.push_back(entity);
    return entity;
}



Entity*
FieldModule::LoadSprite(const char* name, const int sprite_id)
{
    Ogre::SceneNode* node = Ogre::Root::getSingleton().getSceneManager("Scene")->getSceneNode("FieldModule")->createChildSceneNode("Model" + Ogre::StringConverter::toString(m_Models.size()));
    Sprite* entity = new Sprite(name, "", node, m_FieldScriptManager, m_Walkmesh);

    entity->ShowDebug(Configuration::getSingleton().GetOptionBool("debug_field_model"));

    Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT] Create sprite '" + entity->GetName() + "' by requested model with id '" + Ogre::StringConverter::toString(sprite_id) + "' from file '" + name + "'.");

    m_Models.push_back(entity);
    return entity;
}



void
FieldModule::ScriptSetEntityToCharacter(Entity* entity, const int character_id)
{
    Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT] field:set_model_to_character: Assosiate entity '" + entity->GetName() + "' and character with id '" + Ogre::StringConverter::toString(character_id) + "'.");

    for (int i = 0; i < m_Models.size(); ++i)
    {
        if (m_Models[i] == entity)
        {
            m_CharactersModels[character_id] = i;

            if (g_GameState->GetPartyCharacter(0) == character_id)
            {
                m_PlayerModelId = i;

                entity->SetPosition(g_GameState->GetPlayerCharacterPosition());
                SetEntityOnWalkmesh(i);
                entity->SetDirection(g_GameState->GetPlayerCharacterDirection());
                entity->SetVisible(true);
                entity->SetSolid(true);

                Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT] field:set_model_to_character: Set as player.");
            }

            return;
        }
    }
}



void
FieldModule::ScriptSetPlayerEntity(Entity* entity)
{
    Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT] field:set_player_model: Give control to model '" + entity->GetName() + "'.");

    for (int i = 0; i < m_Models.size(); ++i)
    {
        if (m_Models[i] == entity)
        {
            m_PlayerModelId = i;
            return;
        }
    }
}



void
FieldModule::ScriptPCLock(const bool lock)
{
    Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT] field:pc_lock: Lock player control '" + Ogre::StringConverter::toString(lock) + "'.");

    if (m_PlayerModelId != -1)
    {
        m_Models[m_PlayerModelId]->PlayAnimationLooped(m_AnimationIdle, 1);
    }

    m_PlayerModelLock = lock;
}



void
FieldModule::PCSlip(const bool slip)
{
    Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT] field:pc_slip: Set pc slipping from walk to '" + Ogre::StringConverter::toString(slip) + "'.");
    m_PlayerModelSlip = slip;
}



void
FieldModule::LockWalkmesh(const int triangle_id, const bool lock)
{
    Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT] field:lock_walkmesh: Set lock walkmesh triangle with id '" + Ogre::StringConverter::toString(triangle_id) + "' to '" + Ogre::StringConverter::toString(lock) + "'.");
    m_Walkmesh->LockWalkmesh(triangle_id, lock);
}



void
FieldModule::LineTriggerOn(const char* name, const bool on)
{
    Ogre::String l_name = Ogre::String(name);

    Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT] field:line_trigger_on: Set line trigger '" + l_name + "' to '" + Ogre::StringConverter::toString(on) + "'.");

    bool found = false;
    for (int i = 0; i < m_LineTriggers.size(); ++i)
    {
        if (m_LineTriggers[i]->GetName() == l_name)
        {
            m_LineTriggers[i]->SetEnabled(on);
            found = true;
        }
    }

    if (found == false)
    {
        Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT ERROR] field:line_trigger_on: There is no line trigger with name '" + l_name + "'.");
    }
}



void
FieldModule::RandomEncounterOn(const bool on)
{
    Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT] field:random_encounter_on: Set random encounter '" + Ogre::StringConverter::toString(on) + "'.");

    m_EncounterEnabled = on;
}



void
FieldModule::RandomEncounterTable(const int table_id)
{
    Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT] field:random_encounter_table: Set random encounter table to '" + Ogre::StringConverter::toString(table_id) + "'.");

    m_EncounterTable = table_id;
}



const bool
FieldModule::SetNextStep(const int model_id, const Ogre::Vector2& move_vector)
{
    Ogre::LogManager* log = Ogre::LogManager::getSingletonPtr();

    ModelMovement state = m_Models[model_id]->GetState();
    if (state != STAND && state != MOVE)
    {
        log->logMessage("ObjectManager::SetNextStep: Tried set move entity that are not on walkmesh.");
        return false;
    }

    if (move_vector.x == 0 && move_vector.y == 0)
    {
        log->logMessage("[ERROR] ObjectManager::SetNextStep: Move vector has zero length.");
        return false;
    }

    int current_triangle = m_Models[model_id]->GetTriangle();
    if (current_triangle == -1)
    {
        log->logMessage("ObjectManager::SetNextStep: Tried set move entity that are not on walkmesh. Triangle -1.");
        return false;
    }

    //log->logMessage("Start position calculation.");



    Ogre::Vector3 start_point = Ogre::Vector3(m_Models[model_id]->GetPosition().x, m_Models[model_id]->GetPosition().y, m_Models[model_id]->GetPosition().z);
    /*log->logMessage("Start point: " + Ogre::StringConverter::toString(start_point.x) +
                                " " + Ogre::StringConverter::toString(start_point.y) +
                                " " + Ogre::StringConverter::toString(start_point.z) + ".");*/


    Ogre::Vector2 direction = move_vector;
    //log->logMessage("Move vector: " + Ogre::StringConverter::toString(direction.x) +
    //                            " " + Ogre::StringConverter::toString(direction.y) + ".");

    Ogre::Vector3 rotation(0.0f, 0.0f, 0.0f);
    Ogre::Quaternion q1 (0.0f, 0.0f, 0.0f, 1.0f);
    Ogre::Vector3 end_point(0.0f, 0.0f, 0.0f);
    Ogre::Vector3 end_point2(0.0f, 0.0f, 0.0f);
    bool first_triangle_check  = false;
    bool second_triangle_check = false;
    bool third_triangle_check  = false;
    bool last_triangle_check   = false;
    bool first_entity_check    = false;
    bool second_entity_check   = false;
    bool third_entity_check    = false;



    // shorten move vector by triangle angle
    end_point.x = start_point.x + direction.x;
    end_point.y = start_point.y + direction.y;
    Ogre::Vector3 A3 = m_Walkmesh->GetA(current_triangle);
    Ogre::Vector3 B3 = m_Walkmesh->GetB(current_triangle);
    Ogre::Vector3 C3 = m_Walkmesh->GetC(current_triangle);
    end_point.z = point_elevation(Ogre::Vector2(end_point.x, end_point.y), A3, B3, C3);
    Ogre::Vector3 temp = end_point - start_point;
    temp.normalise();
    temp = temp * direction.length();
    direction.x = temp.x;
    direction.y = temp.y;
    //log->logMessage("Shortened Direction:(" + Ogre::StringConverter::toString(direction.x) +
    //                                    " " + Ogre::StringConverter::toString(direction.y) + ").");



    // set direction for entity if we want to move
    SetEntityDirectionByVector2(model_id, direction);



    //log->logMessage("Start cycle.");
    for (int i = 0; (m_PlayerModelId == model_id && m_PlayerModelSlip == true && i < 16) ||
                    (m_PlayerModelId == model_id && m_PlayerModelSlip == false && i < 3) ||
                    (m_PlayerModelId != model_id && i <= 16); ++i)
    {
        //log->logMessage("Cycle " + Ogre::StringConverter::toString(i) + ".");

        // multiply move_vector by speed
        ////////////////////////////////////////
        Ogre::Vector2 speed = direction * m_Models[model_id]->GetSpeed();

        ////////////////////////////////////////
        //LOGGER->Log(LOGGER_WARNING, "Move vector with speed: %f %f.", direction.x, direction.y);
        // get ending point
        end_point = Ogre::Vector3(start_point.x + speed.x, start_point.y + speed.y, start_point.z);
        //LOGGER->Log(LOGGER_WARNING, "End point: %f %f %f.", end_point.x, end_point.y, end_point.z);



        // 1st check
        // rotate move_vector +45
        q1.FromAngleAxis(Ogre::Radian(Ogre::Degree(45)), Ogre::Vector3::UNIT_Z);
        rotation.x = direction.x;
        rotation.y = direction.y;
        rotation.z = 0;
        rotation.normalise();
        rotation = q1 * rotation;
        //log->logMessage("Move vector length: " + Ogre::StringConverter::toString(rotation.length()) + ".");
        // multiply move_vector by solid range
        rotation = rotation * m_Models[model_id]->GetSolidRange();
        end_point2.x = end_point.x + rotation.x;
        end_point2.y = end_point.y + rotation.y;
        //log->logMessage("Left sector part end point:(" + Ogre::StringConverter::toString(end_point2.x) +
        //                                           " " + Ogre::StringConverter::toString(end_point2.y) + ").");



        // check_triangle
        //log->logMessage("Left Triangle Check");
        first_triangle_check = WalkmeshBorderCross(model_id, end_point2, direction);
        m_Models[model_id]->SetTriangle(current_triangle);

        // model_check
        first_entity_check = CheckSolidCollisions(model_id, end_point2);




        // 2nd check
        // rotate move_vector +45
        q1.FromAngleAxis(Ogre::Radian(Ogre::Degree(-45)), Ogre::Vector3::UNIT_Z);
        rotation.x = direction.x;
        rotation.y = direction.y;
        rotation.z = 0;
        rotation.normalise();
        rotation = q1 * rotation;
        //log->logMessage("Move vector length: " + Ogre::StringConverter::toString(rotation.length()) + ".");
        // multiply move_vector by solid range
        rotation = rotation * m_Models[model_id]->GetSolidRange();
        end_point2.x = end_point.x + rotation.x;
        end_point2.y = end_point.y + rotation.y;
        //log->logMessage("Right sector part end point:(" + Ogre::StringConverter::toString(end_point2.x) +
        //                                           " " + Ogre::StringConverter::toString(end_point2.y) + ").");



        // check triangle
        //log->logMessage("Right Triangle Check");
        second_triangle_check = WalkmeshBorderCross(model_id, end_point2, direction);
        m_Models[model_id]->SetTriangle(current_triangle);

        // model_check
        second_entity_check = CheckSolidCollisions(model_id, end_point2);



        // 3rd check
        // multiply move_vector by solid range
        //rotation *= m_Models[model_id]->GetSolidRange();
        rotation.x = direction.x;
        rotation.y = direction.y;
        rotation.z = 0;
        rotation.normalise();
        //log->logMessage("Move vector length: " + Ogre::StringConverter::toString(rotation.length()) + ".");
        rotation = rotation * m_Models[model_id]->GetSolidRange();
        end_point2.x = end_point.x + rotation.x;
        end_point2.y = end_point.y + rotation.y;
        //log->logMessage("Central sector part end point:(" + Ogre::StringConverter::toString(end_point2.x) +
        //                                              " " + Ogre::StringConverter::toString(end_point2.y) + ").");



        // check triangle
        //log->logMessage("Center Triangle Check");
        third_triangle_check = WalkmeshBorderCross(model_id, end_point2, direction);
        m_Models[model_id]->SetTriangle(current_triangle);

        // model_check
        third_entity_check = CheckSolidCollisions(model_id, end_point2);



        // check condition and modify move_vector
        if (first_triangle_check  != false || second_triangle_check != false || third_triangle_check  != false ||
            first_entity_check    != false || second_entity_check   != false || third_entity_check    != false)
        {
            // only for NPC
            if (model_id != m_PlayerModelId || m_PlayerModelLock == true)
            {
                // if we collide only directly into triangle border
                if (first_triangle_check  == false &&
                    second_triangle_check == false &&
                    third_triangle_check  != false)
                {
                    q1.FromAngleAxis(Ogre::Radian(Ogre::Degree(-7)), Ogre::Vector3::UNIT_Z);
                    rotation.x = direction.x;
                    rotation.y = direction.y;
                    rotation = q1 * rotation;
                    direction.x = rotation.x;
                    direction.y = rotation.y;
                }
                // or if we only collide into others entity directly
                else if (first_entity_check  == false &&
                         second_entity_check == false &&
                         third_entity_check  != false)
                {
                    //LOGGER->Log(LOGGER_WARNING, "We try to rotate.");
                    q1.FromAngleAxis(Ogre::Radian(Ogre::Degree(-11.25f)), Ogre::Vector3::UNIT_Z);
                    rotation.x = direction.x;
                    rotation.y = direction.y;
                    rotation = q1 * rotation;
                    direction.x = rotation.x;
                    direction.y = rotation.y;
                }



                // if not both left and right check was fail
                if (first_triangle_check == false || second_triangle_check == false)
                {
                    if ((first_triangle_check == false && first_entity_check != false) ||
                        (first_triangle_check != false && second_triangle_check == false))
                    {
                        q1.FromAngleAxis(Ogre::Radian(Ogre::Degree(-11.25f)), Ogre::Vector3::UNIT_Z);
                        rotation.x = direction.x;
                        rotation.y = direction.y;
                        rotation = q1 * rotation;
                        direction.x = rotation.x;
                        direction.y = rotation.y;
                        //LOGGER->Log(LOGGER_WARNING, "New move vector: %f %f.", direction.x, direction.y);
                    }

                    if (first_triangle_check == false &&
                        first_entity_check == false &&
                        (second_triangle_check != false || second_entity_check != false))
                    {
                        q1.FromAngleAxis(Ogre::Radian(Ogre::Degree(11.25f)), Ogre::Vector3::UNIT_Z);
                        rotation.x = direction.x;
                        rotation.y = direction.y;
                        rotation = q1 * rotation;
                        direction.x = rotation.x;
                        direction.y = rotation.y;
                        //LOGGER->Log(LOGGER_WARNING, "New move vector: %f %f.", direction.x, direction.y);
                    }

                    continue;
                }

                break;
            }
            // only for PC
            else
            {
                if (first_entity_check  == false &&
                    second_entity_check == false &&
                    third_entity_check  == false)
                {
                    // if not both left and right check was fail
                    if (first_triangle_check == false || second_triangle_check == false)
                    {
                        if ((first_triangle_check == false && first_entity_check != false) ||
                            (first_triangle_check != false && second_triangle_check == false))
                        {
                            q1.FromAngleAxis(Ogre::Radian(Ogre::Degree(-11.25f)), Ogre::Vector3::UNIT_Z);
                            rotation.x = direction.x;
                            rotation.y = direction.y;
                            rotation = q1 * rotation;
                            direction.x = rotation.x;
                            direction.y = rotation.y;
                            /*log->logMessage("New move vector: " + Ogre::StringConverter::toString(direction.x) +
                                                            " " + Ogre::StringConverter::toString(direction.y) + ".");*/
                        }

                        if (first_triangle_check == false &&
                            first_entity_check == false &&
                            (second_triangle_check != false || second_entity_check != false))
                        {
                            q1.FromAngleAxis(Ogre::Radian(Ogre::Degree(11.25f)), Ogre::Vector3::UNIT_Z);
                            rotation.x = direction.x;
                            rotation.y = direction.y;
                            rotation = q1 * rotation;
                            direction.x = rotation.x;
                            direction.y = rotation.y;
                            /*log->logMessage("New move vector: " + Ogre::StringConverter::toString(direction.x) +
                                                            " " + Ogre::StringConverter::toString(direction.y) + ".");*/
                        }

                        continue;
                    }

                    break;
                }
            }
        }
    }

    //log->logMessage("Stop cycle.");



    // set new X, Y and Z
    last_triangle_check = WalkmeshBorderCross(model_id, end_point, direction);

    if (first_triangle_check  != false ||
        second_triangle_check != false ||
        third_triangle_check  != false ||
        last_triangle_check   != false ||
        first_entity_check    != false ||
        second_entity_check   != false ||
        third_entity_check    != false)
    {
        //log->logMessage("Stop position calculation without changes.");
        return false;
    }



    // check all triggers and encounters if we PC
    if (m_PlayerModelId == model_id && m_PlayerModelLock != true)
    {
        CheckLineTriggers(model_id, end_point);

        // increment danger counter
        float length = (direction * m_Models[model_id]->GetSpeed()).length();
        if (CheckEncounterAvailable() == true)
        {
            m_EncounterPercent += length / m_Encounters[m_EncounterTable].rate;
        }
    }



    m_Models[model_id]->SetPosition(end_point);
    return true;
}



const bool
FieldModule::WalkmeshBorderCross(const int model_id, Ogre::Vector3& position, const Ogre::Vector2& move_vector)
{
    Ogre::LogManager* log = Ogre::LogManager::getSingletonPtr();
    //log->logMessage("Start CheckTriangles");

    int current_triangle = m_Models[model_id]->GetTriangle();
    if (current_triangle == -1)
    {
        return true;
    }

    Ogre::Vector2 pos = Ogre::Vector2(position.x, position.y);

    for (;;)
    {
        Ogre::Vector3 A3 = m_Walkmesh->GetA(current_triangle);
        Ogre::Vector3 B3 = m_Walkmesh->GetB(current_triangle);
        Ogre::Vector3 C3 = m_Walkmesh->GetC(current_triangle);
        /*log->logMessage("Triangle:A(" + Ogre::StringConverter::toString(A3.x) +
                                  " " + Ogre::StringConverter::toString(A3.y) +
                                  " " + Ogre::StringConverter::toString(A3.z) +
                               ") B(" + Ogre::StringConverter::toString(B3.x) +
                                  " " + Ogre::StringConverter::toString(B3.y) +
                                  " " + Ogre::StringConverter::toString(B3.z) +
                               ") C(" + Ogre::StringConverter::toString(C3.x) +
                                  " " + Ogre::StringConverter::toString(C3.y) +
                                  " " + Ogre::StringConverter::toString(C3.z) + ").");*/
        Ogre::Vector2 A(A3.x, A3.y);
        Ogre::Vector2 B(B3.x, B3.y);
        Ogre::Vector2 C(C3.x, C3.y);

        float sign1 = side_of_vector(pos, B, A);
        float sign2 = side_of_vector(pos, C, B);
        float sign3 = side_of_vector(pos, A, C);

        /*log->logMessage("(" + Ogre::StringConverter::toString(sign1) +
                        " " + Ogre::StringConverter::toString(sign2) +
                        " " + Ogre::StringConverter::toString(sign3) + ").");*/

        int next_triangle = -1;

        if (sign1 < 0)
        {
            next_triangle = m_Walkmesh->GetAccessSide(current_triangle, 0);
            //log->logMessage("BA leave to " + Ogre::StringConverter::toString(next_triangle) + ".");
        }
        else if (sign2 < 0)
        {
            next_triangle = m_Walkmesh->GetAccessSide(current_triangle, 1);
            //log->logMessage("CB leave to " + Ogre::StringConverter::toString(next_triangle) + ".");
        }
        else if (sign3 < 0)
        {
            next_triangle = m_Walkmesh->GetAccessSide(current_triangle, 2);
            //log->logMessage("AC leave to " + Ogre::StringConverter::toString(next_triangle) + ".");
        }
        else
        {
            //log->logMessage("In triangle.");
            position.z = point_elevation(pos, A3, B3, C3);
            //log->logMessage("Stop CheckTriangles with 0 and triangle " + Ogre::StringConverter::toString(current_triangle) + ".");
            m_Models[model_id]->SetTriangle(current_triangle);
            return false;
        }

        if (next_triangle >= 0)
        {
            bool lock = m_Walkmesh->IsLocked(next_triangle);

            if (lock == false)
            {
                current_triangle = next_triangle;
                //log->logMessage("New current triangle " + Ogre::StringConverter::toString(current_triangle) + ".");
                continue;
            }
        }

        position.z = point_elevation(pos, A3, B3, C3);
        //log->logMessage("Stop CheckTriangles with 1 and triangle " + Ogre::StringConverter::toString(current_triangle) + ".");
        m_Models[model_id]->SetTriangle(current_triangle);
        return true;
    }
}



const bool
FieldModule::CheckSolidCollisions(const int model_id, Ogre::Vector3& position)
{
    if (m_Models[model_id]->IsSolid() == false)
    {
        return false;
    }

    //Ogre::LogManager* log = Ogre::LogManager::getSingletonPtr();
    for (int i = 0; i < m_Models.size(); ++i)
    {
        if (m_Models[i]->IsSolid() == false)
        {
            continue;
        }

        if (i == model_id)
        {
            continue;
        }

        Ogre::Vector3 pos1 = m_Models[i]->GetPosition();
        float solid_range1 = m_Models[i]->GetSolidRange();
        float solid_range2 = m_Models[model_id]->GetSolidRange();

        float height = (pos1.z < position.z) ? m_Models[i]->GetHeight() : m_Models[model_id]->GetHeight();

        //log->logMessage("Height collision(" + Ogre::StringConverter::toString(pos1.z) + " " + Ogre::StringConverter::toString(position.z) + " " + Ogre::StringConverter::toString(height) + ").");

        if (((pos1.z - position.z + height) < (height * 2)) && ((pos1.z - position.z + height) >= 0))
        {
            float solid_range = (solid_range1 + solid_range2) * (solid_range1 + solid_range2);
            float distance = (pos1.x - position.x) * (pos1.x - position.x) + (pos1.y - position.y) * (pos1.y - position.y);

            //log->logMessage("Dist collision(" + Ogre::StringConverter::toString(solid_range) + " " + Ogre::StringConverter::toString(distance) + ").");

            if (distance < solid_range)
            {
                //log->logMessage("Collide with entity.");

                // if this is player and we move by ourself (in ffvii only player model checked)
                if (model_id == m_PlayerModelId && m_PlayerModelLock == false)
                {
                    m_FieldScriptManager->AddScript(m_Models[i]->GetName(), "on_collide", 1);
                }

                return true;
            }
        }
    }

    //LOGGER->Log(LOGGER_INFO, "Not collide with entity");
    return false;
}



void
FieldModule::CheckLineTriggers(const int model_id, const Ogre::Vector3& position)
{
    if (m_Models[model_id]->IsSolid() == false)
    {
        return;
    }

    for (int i = 0; i < m_LineTriggers.size(); ++i)
    {
        if (m_LineTriggers[i]->IsEnabled() == true)
        {
            m_LineTriggers[i]->SetCanBeActivated(false);

            Ogre::Vector3 lp1 = m_LineTriggers[i]->GetPoint1();
            Ogre::Vector3 lp2 = m_LineTriggers[i]->GetPoint2();
            Ogre::Vector3 mp1 = m_Models[model_id]->GetPosition();

            Ogre::Vector3 proj;

            // calculate distance
            float square_dist = square_distance_to_line(mp1, lp1, lp2, proj);
            float solid = m_Models[model_id]->GetSolidRange();

            if (square_dist != -1 && square_dist < solid * solid)
            {
                if (m_LineTriggers[i]->IsInLine() == false)
                {
                    m_FieldScriptManager->AddScript(m_LineTriggers[i]->GetName(), "on_enter_line", 1);
                    m_LineTriggers[i]->SetInLine(true);
                }

                // check that 1st and 2nd points are on different side of line
                float cond1 = ((lp2.x - lp1.x) * (mp1.y - lp1.y)) - ((mp1.x - lp1.x) * (lp2.y - lp1.y));
                float cond2 = ((lp2.x - lp1.x) * (position.y - lp1.y)) - ((position.x - lp1.x) * (lp2.y - lp1.y));

                // if we cross the line
                if ((cond1 > 0 && cond2 <= 0) || (cond2 > 0 && cond1 <= 0) || (cond1 >= 0 && cond2 < 0) || (cond2 >= 0 && cond1 < 0))
                {
                    m_FieldScriptManager->AddScript(m_LineTriggers[i]->GetName(), "on_cross_line", 1);
                }

                // if we not move in line
                if (mp1 == position)
                {
                    m_FieldScriptManager->AddScript(m_LineTriggers[i]->GetName(), "on_move_to_line", 1);
                    m_LineTriggers[i]->SetCanBeActivated(true);
                }
                else
                {
                    const Ogre::Degree direction_to_line = get_direction_to_point(mp1, proj);
                    const Ogre::Degree movement_direction = get_direction_to_point(mp1, position);

                    // if we move to line
                    Ogre::Degree angle = direction_to_line - movement_direction + Ogre::Degree(90);
                    angle = (angle > Ogre::Degree(360)) ? angle - Ogre::Degree(360) : angle;

                    if (angle < Ogre::Degree(180) && angle > Ogre::Degree(0))
                    {
                        m_FieldScriptManager->AddScript(m_LineTriggers[i]->GetName(), "on_move_to_line", 1);
                        m_LineTriggers[i]->SetCanBeActivated(true);
                    }
                }
            }
            else
            {
                if (m_LineTriggers[i]->IsInLine() == true)
                {
                    m_FieldScriptManager->AddScript(m_LineTriggers[i]->GetName(), "on_leave_line", 1);
                    m_LineTriggers[i]->SetInLine(false);
                }
            }
        }
    }
}



void
FieldModule::CheckEntityTalk()
{
    if (m_PlayerModelId == -1 || m_PlayerModelLock == true || m_Models[m_PlayerModelId]->IsSolid() == false)
    {
        return;
    }

    int model_to_talk = -1;
    Ogre::Degree less_angle(90);

    for (int i = 0; i < m_Models.size(); ++i)
    {
        if (m_Models[i]->IsTalkable() == false)
        {
            continue;
        }

        if (i == m_PlayerModelId)
        {
            continue;
        }

        Ogre::Vector3 pos1 = m_Models[i]->GetPosition();
        float talk_range = m_Models[i]->GetTalkRange();
        Ogre::Vector3 pos2 = m_Models[m_PlayerModelId]->GetPosition();
        float solid_range = m_Models[m_PlayerModelId]->GetSolidRange();

        int height = (pos1.z < pos2.z) ? m_Models[i]->GetHeight() : m_Models[m_PlayerModelId]->GetHeight();

        if (((pos1.z - pos2.z + height) < (height * 2)) && ((pos1.z - pos2.z + height) >= 0))
        {
            talk_range = (talk_range + solid_range) * (talk_range + solid_range);
            float distance = (pos1.x - pos2.x) * (pos1.x - pos2.x) + (pos1.y - pos2.y) * (pos1.y - pos2.y);

            if (distance < talk_range + solid_range)
            {
                Ogre::Degree angle_to_model = get_direction_to_point(pos2, pos1);
                Ogre::Degree angle_pc       = m_Models[m_PlayerModelId]->GetDirection();
                Ogre::Degree angle = angle_pc - angle_to_model;
                angle = (angle < Ogre::Degree(0)) ? -angle : angle;
                angle = (angle >= Ogre::Degree(180)) ? Ogre::Degree(360) - angle : angle;

                //Ogre::LogManager::getSingletonPtr()->logMessage("--------- angle_to_model '" + Ogre::StringConverter::toString(angle_to_model) + "' angle_pc'" + Ogre::StringConverter::toString(angle_pc) + "' angle '" + Ogre::StringConverter::toString(angle) + "'.");

                if (angle < less_angle)
                {
                    angle = less_angle;
                    model_to_talk = i;
                }
            }
        }
    }

    if (model_to_talk != -1)
    {
        m_FieldScriptManager->AddScript(m_Models[model_to_talk]->GetName(), "on_talk", 1);
    }
}



void
FieldModule::CheckEncounters()
{
    // check encounter
    if (rand() % 1000 < m_EncounterPercent * 10)
    {
        int chance = rand() % 1000;
        int chance_sum = 0;

        for (int e_try = 0; e_try < 2; ++e_try)
        {
            for (int i = 0; i < m_Encounters[m_EncounterTable].encounter.size(); ++i)
            {
                if (m_Encounters[m_EncounterTable].encounter[i].percentage * 10 + chance_sum > chance)
                {
                    int battle_id = m_Encounters[m_EncounterTable].encounter[i].battle_id;
                    // we roll once again if this is battle we fought previous
                    if (battle_id != m_EncounterPreviousBattle || e_try != 0)
                    {
                        Ogre::LogManager::getSingletonPtr()->logMessage("[INFO] Encount battle '" + Ogre::StringConverter::toString(battle_id) + "' from table '" + Ogre::StringConverter::toString(m_EncounterTable) + "'.");
                        g_ModuleManager->RunBattle(battle_id);

                        m_EncounterPreviousBattle = battle_id;
                        m_EncounterPercent = 0;

                        return;
                    }
                }

                chance_sum += m_Encounters[m_EncounterTable].encounter[i].percentage * 10;
            }
        }
    }

    return;
}



void
FieldModule::SetEntityDirectionByVector2(const int entity_id, const Ogre::Vector2& vector)
{
    if (m_Models[entity_id]->GetRotationLock() == false)
    {
        Ogre::Vector2 up(0.0f, -1.0f);
        // angle between vectors
        Ogre::Degree angle(Ogre::Radian(acosf(vector.dotProduct(up) / (vector.length() * up.length()))));
        angle = (vector.x < 0) ? Ogre::Degree(360) - angle : angle;

        //Ogre::LogManager::getSingletonPtr()->logMessage("Direction(" + Ogre::StringConverter::toString(Ogre::Degree(angle)) + ").");
        m_Models[entity_id]->SetDirection(Ogre::Degree(angle));
    }
}



void
FieldModule::SetEntityOnWalkmesh(const int entity_id)
{
    Ogre::Vector3 position3 = m_Models[entity_id]->GetPosition();
    Ogre::Vector2 position2;
    position2.x = position3.x;
    position2.y = position3.y;

    std::vector<std::pair<int, float> > triangles;

    // we search for posible triangles
    for (int i = 0; i < m_Walkmesh->GetNumberOfTriangles() ; ++i)
    {
        Ogre::Vector3 A3 = m_Walkmesh->GetA(i);
        Ogre::Vector3 B3 = m_Walkmesh->GetB(i);
        Ogre::Vector3 C3 = m_Walkmesh->GetC(i);

        Ogre::Vector2 A2(A3.x, A3.y);
        Ogre::Vector2 B2(B3.x, B3.y);
        Ogre::Vector2 C2(C3.x, C3.y);

        float sign1 = side_of_vector(position2, B2, A2);
        float sign2 = side_of_vector(position2, C2, B2);
        float sign3 = side_of_vector(position2, A2, C2);

        if (sign1 >= 0 && sign2 >= 0 && sign3 >= 0)
        {
            triangles.push_back(std::make_pair(i, point_elevation(position2, A3, B3, C3)));
        }
    }



    // if our coords doesn't match any triangle
    if (triangles.size() == 0)
    {
        return;
    }



    int triangle = m_Models[entity_id]->GetTriangle();
    if (triangle != -1)
    {
        for (int i = 0; i < triangles.size(); ++i)
        {
            if (triangles[i].first == triangle)
            {
                m_Models[entity_id]->SetPosition(Ogre::Vector3(position2.x, position2.y, triangles[i].second));
                return;
            }
        }
    }



    float z = 0;
    int triangle_id = -1;
    for (int i = 0; i < triangles.size(); ++i)
    {
        if (triangles[i].second > z)
        {
            z = triangles[i].second;
            triangle_id = triangles[i].first;
        }
    }

    m_Models[entity_id]->SetPosition(Ogre::Vector3(position2.x, position2.y, z));
    m_Models[entity_id]->SetTriangle(triangle_id);
}



void
FieldModule::SetNextOffsetStep(const int model_id, const float delta_time)
{
    ActionType type = m_Models[model_id]->GetOffsetType();
    float steps = m_Models[model_id]->GetOffsetStepSeconds();
    float step = m_Models[model_id]->GetOffsetCurrentStepSeconds();

    Ogre::Vector3 start = m_Models[model_id]->GetOffsetPositionStart();
    Ogre::Vector3 end = m_Models[model_id]->GetOffsetPositionEnd();

    float x = step / steps;
    float smooth_modifier = (type == SMOOTH) ? -2 * x * x * x + 3 * x * x : x;
    Ogre::Vector3 current = start + (end - start) * smooth_modifier;

    m_Models[model_id]->SetOffset(current);

    if (step == steps)
    {
        m_Models[model_id]->UnsetOffseting();
    }
    else
    {
        m_Models[model_id]->SetOffsetCurrentStepSeconds(step + delta_time);
    }
}



void
FieldModule::SetNextMoveStep(const int model_id, const float delta_time)
{
    Ogre::LogManager* log = Ogre::LogManager::getSingletonPtr();
    //log->logMessage("Auto move.");

    Ogre::Vector3 start_point = m_Models[model_id]->GetPosition();
    Ogre::Vector2 end_point2  = m_Models[model_id]->GetMovePosition();
    float speed               = m_Models[model_id]->GetSpeed();
    float stop_distance       = m_Models[model_id]->GetMoveStopDistance();

    Ogre::Vector2 start_point2(start_point.x, start_point.y);
    Ogre::Vector2 move_vector = end_point2 - start_point2;

    float length_square = move_vector.squaredLength() - (stop_distance * stop_distance);
    float speed_square  = (speed * delta_time) * (speed * delta_time);


    // if we have stop distance check it against collision
    if (length_square < speed_square + 0x1000 || length_square < 4)
    {
        m_Models[model_id]->UnsetMove();
        //log->logMessage("Finish auto move.");
        return;
    }

    move_vector.normalise();
    move_vector = move_vector * delta_time;

    bool move = SetNextStep(model_id, move_vector);

    // play animation if requested
    if (m_Models[model_id]->GetMovePlayAnimation() == true)
    {
        if (move == true)
        {
            if (m_Models[model_id]->GetSpeed() > 3)
            {
                m_Models[model_id]->PlayAnimationLooped(m_AnimationRun, 1);
            }
            else
            {
                m_Models[model_id]->PlayAnimationLooped(m_AnimationWalk, 1);
            }
        }
        else
        {
            m_Models[model_id]->PlayAnimationLooped(m_AnimationIdle, 1);
        }
    }

    return;
}



void
FieldModule::SetNextTurnStep(const int model_id, const float delta_time)
{
    ActionType type = m_Models[model_id]->GetTurnType();
    float steps = m_Models[model_id]->GetTurnStepSeconds();
    float step = m_Models[model_id]->GetTurnCurrentStepSeconds();

    Ogre::Degree start = m_Models[model_id]->GetTurnDirectionStart();
    Ogre::Degree end = m_Models[model_id]->GetTurnDirectionEnd();

    float x = step / steps;
    float smooth_modifier = (type == SMOOTH) ? -2 * x * x * x + 3 * x * x : x;
    Ogre::Degree direction = start + (end - start) * smooth_modifier;

    m_Models[model_id]->SetDirection(direction);

    if (step == steps)
    {
        m_Models[model_id]->UnsetTurn();
    }
    else
    {
        m_Models[model_id]->SetTurnCurrentStepSeconds(step + delta_time);
    }
}



void
FieldModule::SetNextJumpStep(const int model_id, const float delta_time)
{
    Ogre::LogManager* log = Ogre::LogManager::getSingletonPtr();

    float steps = m_Models[model_id]->GetStepSeconds();
    float current_step = m_Models[model_id]->GetCurrentStepSeconds();

    if (current_step == steps)
    {
        m_Models[model_id]->UnsetJump();
        return;
    }

    m_Models[model_id]->SetCurrentStepSeconds(current_step + delta_time);

    Ogre::Vector3 start_position = m_Models[model_id]->GetJumpStart();
    Ogre::Vector3 end_position   = m_Models[model_id]->GetJumpEnd();
    Ogre::Vector3 position;
    position.x = start_position.x + ((end_position.x - start_position.x) / steps) * current_step;
    position.y = start_position.y + ((end_position.y - start_position.y) / steps) * current_step;
    position.z = current_step * current_step * -1307.8125f + current_step * ((end_position.z - start_position.z) / steps + steps * 1307.8125f) + start_position.z;
    m_Models[model_id]->SetPosition(position);
}



void
FieldModule::SetNextClimbStep(const int model_id, const float delta_time)
{
    Ogre::LogManager* log = Ogre::LogManager::getSingletonPtr();

    bool to_end = true;
    bool is_move = false;

    float steps = m_Models[model_id]->GetStepSeconds();
    float current_step = m_Models[model_id]->GetCurrentStepSeconds();

    if (model_id == m_PlayerModelId && m_PlayerModelLock != true)
    {
        ClimbMovement move = m_Models[model_id]->GetClimbMovement();

        if (move == DOWN_TO_UP || move == UP_TO_DOWN)
        {
            if (m_MoveButtons.up == true)
            {
                to_end = (move == DOWN_TO_UP) ? true : false;
                is_move = true;
            }
            else if (m_MoveButtons.down == true)
            {
                to_end = (move == DOWN_TO_UP) ? false : true;
                is_move = true;
            }
        }
        else if (move == LEFT_TO_RIGHT || move == RIGHT_TO_LEFT)
        {
            if (m_MoveButtons.right == true)
            {
                to_end = (move == LEFT_TO_RIGHT) ? true : false;
                is_move = true;
            }
            else if (m_MoveButtons.left == true)
            {
                to_end = (move == LEFT_TO_RIGHT) ? false : true;
                is_move = true;
            }
        }

        if (is_move == true)
        {
            if (to_end == true)
            {
                if (current_step == steps)
                {
                    m_Models[model_id]->UnsetClimb(true);
                    is_move = false;
                }
                else
                {
                    m_Models[model_id]->SetCurrentStepSeconds(current_step + delta_time);
                }
            }
            else
            {
                if (current_step == 0)
                {
                    m_Models[model_id]->UnsetClimb(false);
                    is_move = false;
                }
                else
                {
                    m_Models[model_id]->SetCurrentStepSeconds(current_step - delta_time);
                }
            }
        }
    }
    else
    {
        if (current_step == steps)
        {
            m_Models[model_id]->UnsetClimb(true);
        }
        else
        {
            m_Models[model_id]->SetCurrentStepSeconds(current_step + delta_time);
            is_move = true;
        }
    }

    if (is_move == true)
    {
        Ogre::Vector3 start_position = m_Models[model_id]->GetClimbStart();
        Ogre::Vector3 end_position   = m_Models[model_id]->GetClimbEnd();
        Ogre::Vector3 position;
        position.x = start_position.x + ((end_position.x - start_position.x) / steps) * current_step;
        position.y = start_position.y + ((end_position.y - start_position.y) / steps) * current_step;
        position.z = start_position.z + ((end_position.z - start_position.z) / steps) * current_step;
        m_Models[model_id]->SetPosition(position);
        m_Models[model_id]->AnimationUpdate((to_end == true) ? delta_time : -delta_time);
    }
}



const bool
FieldModule::CheckModelId(const int model_id) const
{
    return !(model_id >= m_Models.size() || model_id < 0);
}



const bool
FieldModule::CheckEncounterAvailable() const
{
    if (m_EncounterEnabled == true && m_EncounterTable < m_Encounters.size() && m_EncounterTable >= 0)
    {
        if (m_Encounters[m_EncounterTable].rate > 0)
        {
            return true;
        }
        else
        {
            Ogre::LogManager::getSingletonPtr()->logMessage("[ERROR] Encounter table '" + Ogre::StringConverter::toString(m_EncounterTable) + "' rate less or equal zero.");
        }
    }

    return false;
}
