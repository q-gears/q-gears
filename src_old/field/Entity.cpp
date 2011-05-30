// $Id$

#include <Ogre.h>
#include <OgreFontManager.h>
#include "Math.h"
#include "Entity.h"
#include "../core/ModuleManager.h"
#include "../core/ui/MovableTextArea.h"
#include "../Main.h"



Ogre::String model_movement_string[4] = {"STAND", "MOVE", "JUMP", "CLIMB"};



Entity::Entity(const Ogre::String& name, Ogre::SceneNode* node, FieldScriptManager* script, Walkmesh* walkmesh):
    m_Name(name),

    m_FieldScriptManager(script),
    m_Walkmesh(walkmesh),
    m_SceneNode(node),

    m_DrawDebug(false),

    m_State(STAND),

    m_RotationLock(false),

    m_Triangle(0),

    m_StepSeconds(0),
    m_CurrentStepSeconds(0),

    m_OffsetPositionStart(0.0f, 0.0f, 0.0f),
    m_OffsetPositionEnd(0.0f, 0.0f, 0.0f),
    m_OffsetType(NONE),
    m_OffsetStepSeconds(0),
    m_OffsetCurrentStepSeconds(0),

    m_ClimbMovement(UP_TO_DOWN),
    m_ClimbStart(0.0f, 0.0f, 0.0f),
    m_ClimbEnd(0.0f, 0.0f, 0.0f),
    m_ClimbTriangleEnd(-1),

    m_TurnModel(NULL),
    m_TurnDirectionStart(0),
    m_TurnDirectionEnd(0),
    m_TurnType(NONE),
    m_TurnDirection(CLOCKWISE),
    m_TurnStepSeconds(0),
    m_TurnCurrentStepSeconds(0),

    m_JumpStart(0.0f, 0.0f, 0.0f),
    m_JumpEnd(0.0f, 0.0f, 0.0f),
    m_JumpTriangleEnd(-1),

    m_Speed(90),
    m_MovePlayAnimation(false),
    m_MoveModel(NULL),
    m_MovePosition(0.0f, 0.0f),
    m_MoveStopDistance(0),

    m_Height(126),

    m_SolidRange(32),
    m_Solid(false),

    m_TalkRange(100),
    m_Talkable(false),

    m_AnimationCurrentName(""),
    m_AnimationState(STOP),
    m_AnimationSpeed(1),
    m_AnimationSpeedCurrent(1),
    m_AnimationWait(false),
    m_AnimationEndTime(-1),

    m_AnimationDefault("0"),
    m_AnimationDefaultSpeed(1)
{
    m_ModelNode = m_SceneNode->createChildSceneNode();

    m_ModelSolidCollision = new ModelCollision();
    m_ModelSolidCollision->setMaterial("field/model/solid_collision");
    m_ModelSolidCollisionNode = m_SceneNode->createChildSceneNode();
    m_ModelSolidCollisionNode->setScale(m_SolidRange, m_SolidRange, m_Height);
    m_ModelSolidCollisionNode->attachObject(m_ModelSolidCollision);
    m_ModelSolidCollisionNode->setVisible(m_Solid && m_DrawDebug);

    m_ModelTalkCollision = new ModelCollision();
    m_ModelTalkCollision->setMaterial("field/model/talk_collision");
    m_ModelTalkCollisionNode = m_SceneNode->createChildSceneNode();
    m_ModelTalkCollisionNode->setScale(m_TalkRange, m_TalkRange, m_Height);
    m_ModelTalkCollisionNode->attachObject(m_ModelTalkCollision);
    m_ModelTalkCollisionNode->setVisible(m_Talkable && m_DrawDebug);

    m_ModelDirection = new ModelDirection();
    m_ModelDirection->setMaterial("field/model/direction");
    m_ModelDirectionNode = m_ModelNode->createChildSceneNode();
    m_ModelDirectionNode->attachObject(m_ModelDirection);
    m_ModelDirectionNode->setVisible(true && m_DrawDebug);

    m_ModelNode->setPosition(Ogre::Vector3(0, 0, 0));
    m_SceneNode->setPosition(Ogre::Vector3(0, 0, 0));

    // debug info
    m_DebugInfoText = new MovableTextArea("DebugModelText_" + m_Name);
    m_DebugInfoText->setCaption("");
    m_DebugInfoText->setMetricsMode(Ogre::GMM_PIXELS);
    m_DebugInfoText->setPosition(0, 0);
    m_DebugInfoText->setTextAlignment(TextArea::CENTER);
    m_DebugInfoText->setFontName("DebugText");
    m_DebugInfoText->setCharHeight(18);
    m_DebugInfoText->SetAdditionalHeight(m_Height - 20);
    m_DebugInfoText->Set3DPosition(this->GetPosition());

    m_DebugInfoOverlay = Ogre::OverlayManager::getSingleton().create("DebugModelOverlay_" + m_Name);
    m_DebugInfoOverlay->setZOrder(QGOO_FIELD_DEBUG);
    m_DebugInfoOverlay->add2D((Ogre::OverlayContainer*)m_DebugInfoText);

    Ogre::LogManager::getSingletonPtr()->logMessage("Entity created.");
}



Entity::~Entity(void)
{
    m_DebugInfoOverlay->remove2D((Ogre::OverlayContainer*)m_DebugInfoText);
    delete m_DebugInfoText;

    Ogre::OverlayManager::getSingleton().destroy(m_DebugInfoOverlay);

    delete m_ModelSolidCollision;
    delete m_ModelTalkCollision;
    delete m_ModelDirection;

    m_SceneNode->removeAndDestroyAllChildren();

    Ogre::LogManager::getSingletonPtr()->logMessage("Entity destroyed.");
}



void
Entity::Input(const Event& input)
{
}



void
Entity::Update(const float delta_time)
{
    if (m_DebugInfoOverlay->isVisible() == true)
    {
        Ogre::String caption;
        caption = this->GetName() + ": " + model_movement_string[m_State];

        Ogre::Vector3 pos = this->GetPosition();
        caption += "\nanim: " + m_AnimationCurrentName +
                   "\npos: " + Ogre::StringConverter::toString(pos) + " id: " + Ogre::StringConverter::toString(this->GetTriangle());

        m_DebugInfoText->setCaption(caption);
        m_DebugInfoText->Set3DPosition(pos);
    }



    if (m_MoveModel != NULL)
    {
        Ogre::Vector3 pos = m_MoveModel->GetPosition();
        m_MovePosition.x = pos.x;
        m_MovePosition.y = pos.y;
        m_MoveStopDistance = this->GetSolidRange() + m_MoveModel->GetSolidRange();
    }

    if (m_TurnModel != NULL)
    {
        Ogre::Vector3 pos1 = this->GetPosition();
        Ogre::Vector3 pos2 = m_TurnModel->GetPosition();
        Ogre::Degree angle = get_direction_to_point(pos1, pos2);

        angle = this->CalculateTurnAngle(m_TurnDirectionStart, angle);

        m_TurnDirectionEnd = angle;
    }
}



void
Entity::ShowDebug(const bool show)
{
    m_DrawDebug = show;

    if (show == true)
    {
        m_DebugInfoOverlay->show();
        m_ModelSolidCollision->setVisible(m_Solid);
        m_ModelTalkCollision->setVisible(m_Talkable);
        m_ModelDirection->setVisible(true);
    }
    else
    {
        m_DebugInfoOverlay->hide();
        m_ModelSolidCollision->setVisible(false);
        m_ModelTalkCollision->setVisible(false);
        m_ModelDirection->setVisible(false);
    }
}



const ModelMovement
Entity::GetState(void) const
{
    return m_State;
}



const Ogre::String
Entity::GetName() const
{
    return m_Name;
}



void
Entity::ScriptSetVisible(const bool visible)
{
    Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT] entity:set_visible: Set visibility to '" + Ogre::StringConverter::toString(visible) + "'.");

    SetVisible(visible);
}



void
Entity::ScriptSetPositionTriangle(const float x, const float y, const float z, const int triangle_id)
{
    Ogre::Vector3 position(x, y, z);

    Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT] entity:set_position_triangle: Position set to '" + Ogre::StringConverter::toString(position) + "' and triangle to '" + Ogre::StringConverter::toString(triangle_id) + "'.");

    this->SetPosition(position);
    this->SetTriangle(triangle_id);
}



void
Entity::ScriptSetSpeed(const float speed)
{
    Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT] entity:set_speed: Speed set to '" + Ogre::StringConverter::toString(speed) + "'.");

    SetSpeed(speed);
}



void
Entity::ScriptSetDirection(const float direction)
{
    Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT] entity:set_direction: Direction set to '" + Ogre::StringConverter::toString(direction) + "'.");

    SetDirection(Ogre::Degree(direction));
}



const int
Entity::ScriptGetTriangle(void) const
{
    int triangle = GetTriangle();
    Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT] entity:get_triangle: returned triangle '" + Ogre::StringConverter::toString(triangle) + "'.");

    return triangle;
}



void
Entity::ScriptSetSolidRange(const float range)
{
    Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT] entity:set_solid_range: Solid range set to '" + Ogre::StringConverter::toString(range) + "'.");

    SetSolidRange(range);
}



const Ogre::Vector3
Entity::GetPosition(void) const
{
    return m_SceneNode->getPosition();
}



void
Entity::SetPosition(const Ogre::Vector3& position)
{
    m_SceneNode->setPosition(position);
}



const Ogre::Vector3
Entity::GetOffset() const
{
    return m_ModelNode->getPosition();
}



void
Entity::SetOffset(const Ogre::Vector3& position)
{
    m_ModelNode->setPosition(position);
}



void
Entity::SetTriangle(const int triangle)
{
    m_Triangle = triangle;
}



const int
Entity::GetTriangle(void) const
{
    return m_Triangle;
}



void
Entity::SetDirection(const Ogre::Degree& direction)
{
    float angle = direction.valueDegrees() - Ogre::Math::Floor(direction.valueDegrees() / 360.0f) * 360.0f;

    if (angle < 0)
    {
        angle = 360 + angle;
    }

    Ogre::Quaternion q;
    Ogre::Vector3 vec = Ogre::Vector3::UNIT_Z;
    q.FromAngleAxis(Ogre::Radian(Ogre::Degree(angle)), vec);
    m_ModelNode->setOrientation(q);
}



const Ogre::Degree
Entity::GetDirection(void) const
{
    Ogre::Quaternion q = m_ModelNode->getOrientation();
    Ogre::Degree temp;
    Ogre::Vector3 vec = Ogre::Vector3::UNIT_Z;
    q.ToAngleAxis(temp, vec);

    return temp;
}



void
Entity::SetRotationLock(const bool lock)
{
    m_RotationLock = lock;

    Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT] Set rotation lock to '" + Ogre::StringConverter::toString(lock) + "'.");
}



const bool
Entity::GetRotationLock(void) const
{
    return m_RotationLock;
}



const float
Entity::GetStepSeconds(void) const
{
    return m_StepSeconds;
}



void
Entity::SetCurrentStepSeconds(const float seconds)
{
    m_CurrentStepSeconds = (seconds > m_StepSeconds) ? m_StepSeconds : seconds;
    m_CurrentStepSeconds = (m_CurrentStepSeconds < 0) ? 0 : m_CurrentStepSeconds;
}


const float
Entity::GetCurrentStepSeconds(void) const
{
    return m_CurrentStepSeconds;
}



void
Entity::OffsetToPosition(const float x, const float y, const float z, const ActionType type, const float seconds)
{
    if (m_OffsetScriptInfo.entity_id != -1)
    {
        Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT ERROR] offset_to_position: Entity already offseting and waiting till it ends.");
        return;
    }

    this->SetOffseting(Ogre::Vector3(x, y, z), type, seconds);

    Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT] offset_to_position '" + Ogre::StringConverter::toString(Ogre::Vector3(x, y, z)) + "'.");
}



const int
Entity::SetOffsetWait()
{
    Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT] set_offset_wait: Set current offseting to wait.");

    if (m_OffsetScriptInfo.entity_id != -1)
    {
        Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT ERROR] set_offset_wait: Entity already in waiting state.");
        return 1;
    }

    m_OffsetScriptInfo = m_FieldScriptManager->GetCurrentScriptInfo();

    return -1;
}



void
Entity::SetOffseting(const Ogre::Vector3& position, const ActionType type, const float seconds)
{
    if (type == NONE)
    {
        this->SetOffset(position);
        return;
    }

    m_OffsetPositionStart = this->GetOffset();
    m_OffsetPositionEnd = position;
    m_OffsetType = type;
    m_OffsetStepSeconds = seconds;
    m_OffsetCurrentStepSeconds = 0;
}



void
Entity::UnsetOffseting()
{
    m_OffsetType = NONE;

    if (m_OffsetScriptInfo.entity_id != -1)
    {
        m_FieldScriptManager->ContinueEntityScriptExecution(m_OffsetScriptInfo);
        m_OffsetScriptInfo.entity_id = -1;
    }
}



const Ogre::Vector3
Entity::GetOffsetPositionStart() const
{
    return m_OffsetPositionStart;
}



const Ogre::Vector3
Entity::GetOffsetPositionEnd() const
{
    return m_OffsetPositionEnd;
}



const ActionType
Entity::GetOffsetType() const
{
    return m_OffsetType;
}



const float
Entity::GetOffsetStepSeconds() const
{
    return m_OffsetStepSeconds;
}



void
Entity::SetOffsetCurrentStepSeconds(const float seconds)
{
    m_OffsetCurrentStepSeconds = (seconds > m_OffsetStepSeconds) ? m_OffsetStepSeconds : seconds;
    m_OffsetCurrentStepSeconds = (m_OffsetCurrentStepSeconds < 0) ? 0 : m_OffsetCurrentStepSeconds;
}



const float
Entity::GetOffsetCurrentStepSeconds() const
{
    return m_OffsetCurrentStepSeconds;
}



const int
Entity::ClimbToPosition(const float x, const float y, const float z, const int triangle_id, const ClimbMovement movement)
{
    if (m_ScriptInfo.entity_id != -1)
    {
        Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT ERROR] Climb to position: Entity already doing some action (MOVING, JUMPING or CLIMBING) and waiting till it ends.");
        return 1;
    }
    m_ScriptInfo = m_FieldScriptManager->GetCurrentScriptInfo();

    this->SetClimb(Ogre::Vector3(x, y, z), triangle_id, movement);

    Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT] Climb to position '" + Ogre::StringConverter::toString(Ogre::Vector3(x, y, z)) + "'.");

    return -1;
}



void
Entity::SetClimb(const Ogre::Vector3& end, const int end_triangle, const ClimbMovement movement)
{
    Ogre::Vector3 start = this->GetPosition();
    Ogre::Vector3 end_start = end - start;
    float steps = end_start.length() / 120;

    m_State = CLIMB;
    m_ClimbMovement = movement;
    m_ClimbStart = m_SceneNode->getPosition();
    m_ClimbEnd = end;
    m_ClimbTriangleEnd = end_triangle;
    m_StepSeconds = steps;
    m_CurrentStepSeconds = 0;
}



void
Entity::UnsetClimb(const bool end)
{
    m_State = STAND;

    if (end == true)
    {
        m_Triangle = m_ClimbTriangleEnd;
    }

    if (m_ScriptInfo.entity_id != -1)
    {
        m_FieldScriptManager->ContinueEntityScriptExecution(m_ScriptInfo);
        m_ScriptInfo.entity_id = -1;
    }
}



const ClimbMovement
Entity::GetClimbMovement(void) const
{
    return m_ClimbMovement;
}



const Ogre::Vector3&
Entity::GetClimbStart(void) const
{
    return m_ClimbStart;
}



const Ogre::Vector3&
Entity::GetClimbEnd(void) const
{
    return m_ClimbEnd;
}



const int
Entity::TurnToDirection(const float direction, const TurnDirection turn_direction, const ActionType turn_type, const float seconds)
{
    if (m_TurnScriptInfo.entity_id != -1)
    {
        Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT ERROR] Turn to direction: Entity already turning and waiting till it ends.");
        return 1;
    }

    this->SetTurn(Ogre::Degree(direction), NULL, turn_direction, turn_type, seconds);

    Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT] Turn to angle '" + Ogre::StringConverter::toString(direction) + "'.");

    return -1;
}



const int
Entity::TurnToModel(Entity* model, const TurnDirection turn_direction, const float seconds)
{
    if (m_TurnScriptInfo.entity_id != -1)
    {
        Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT ERROR] Turn to model: Entity already turning and waiting till it ends.");
        return 1;
    }

    if (model == NULL || model == this)
    {
        Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT ERROR] Turn to model: Invalid model pointer.");
        return 1;
    }

    Ogre::Vector3 pos1 = this->GetPosition();
    Ogre::Vector3 pos2 = model->GetPosition();
    Ogre::Degree angle = get_direction_to_point(pos1, pos2);

    this->SetTurn(angle, model, turn_direction, SMOOTH, seconds);

    Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT] Turn to model at position '" + Ogre::StringConverter::toString(pos2) + "' with angle '" + Ogre::StringConverter::toString(angle) + "'.");

    return -1;
}



void
Entity::SetTurn(const Ogre::Degree& direction_to, Entity* model, const TurnDirection turn_direction, const ActionType turn_type, const float seconds)
{
    if (turn_type == NONE)
    {
        this->SetDirection(direction_to);
        return;
    }

    m_TurnDirection = turn_direction;

    Ogre::Degree angle_start = this->GetDirection();
    Ogre::Degree angle_end = this->CalculateTurnAngle(angle_start, direction_to);

    m_TurnModel = model;
    m_TurnDirectionStart = angle_start;
    m_TurnDirectionEnd = angle_end;
    m_TurnType = turn_type;
    m_TurnStepSeconds = seconds;
    m_TurnCurrentStepSeconds = 0;
    m_TurnScriptInfo = m_FieldScriptManager->GetCurrentScriptInfo();
}



void
Entity::UnsetTurn(void)
{
    m_TurnModel = NULL;
    m_TurnType = NONE;
    if (m_TurnScriptInfo.entity_id != -1)
    {
        m_FieldScriptManager->ContinueEntityScriptExecution(m_TurnScriptInfo);
        m_TurnScriptInfo.entity_id = -1;
    }
}



const Ogre::Degree
Entity::CalculateTurnAngle(const Ogre::Degree& start, const Ogre::Degree& end) const
{
    Ogre::Degree ret = end;

    switch (m_TurnDirection)
    {
        case CLOCKWISE:
        {
            if (end <= start)
            {
                ret = end + Ogre::Degree(360);
            }
        }
        break;

        case ANTICLOCKWISE:
        {
            if (end >= start)
            {
                ret = end - Ogre::Degree(360);
            }
        }
        break;

        case CLOSEST:
        {
            Ogre::Degree delta = end - start;

            delta = (delta < Ogre::Degree(0)) ? -delta : delta;

            if (delta > Ogre::Degree(180))
            {
                if (start < end)
                {
                    ret = end - Ogre::Degree(360);
                }
                else
                {
                    ret = end + Ogre::Degree(360);
                }
            }
        }
        break;
    }

    return ret;
}



const Ogre::Degree
Entity::GetTurnDirectionStart(void) const
{
    return m_TurnDirectionStart;
}



const Ogre::Degree
Entity::GetTurnDirectionEnd(void) const
{
    return m_TurnDirectionEnd;
}



const ActionType
Entity::GetTurnType(void) const
{
    return m_TurnType;
}



const float
Entity::GetTurnStepSeconds(void) const
{
    return m_TurnStepSeconds;
}



void
Entity::SetTurnCurrentStepSeconds(const float seconds)
{
    m_TurnCurrentStepSeconds = (seconds > m_TurnStepSeconds) ? m_TurnStepSeconds : seconds;
    m_TurnCurrentStepSeconds = (m_TurnCurrentStepSeconds < 0) ? 0 : m_TurnCurrentStepSeconds;
}


const float
Entity::GetTurnCurrentStepSeconds(void) const
{
    return m_TurnCurrentStepSeconds;
}



const int
Entity::JumpToPosition(const float x, const float y, const int triangle_id, const float seconds)
{
    Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT] jump_to_position: Start jump calculation.");

    if (m_ScriptInfo.entity_id != -1)
    {
        Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT ERROR] jump_to_position: Entity already in waiting state.");
        return 1;
    }

    Ogre::Vector2 jump_to(x, y);
    this->SetJump(jump_to, triangle_id, seconds);

    Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT] jump_to_position: Jump to position '" + Ogre::StringConverter::toString(jump_to) + "' with '" + Ogre::StringConverter::toString(seconds) + "' steps.");

    return -1;
}



void
Entity::SetJump(const Ogre::Vector2& jump_to, const int triangle_id, const float seconds)
{
    m_State = JUMP;

    m_JumpEnd.x = jump_to.x;
    m_JumpEnd.y = jump_to.y;
    Ogre::Vector3 A3 = m_Walkmesh->GetA(triangle_id);
    Ogre::Vector3 B3 = m_Walkmesh->GetB(triangle_id);
    Ogre::Vector3 C3 = m_Walkmesh->GetC(triangle_id);
    m_JumpEnd.z = point_elevation(Ogre::Vector2(m_JumpEnd.x, m_JumpEnd.y), A3, B3, C3);

    m_JumpStart = this->GetPosition();

    m_JumpTriangleEnd = triangle_id;

    m_StepSeconds = seconds;
    m_CurrentStepSeconds = 0;
    m_ScriptInfo = m_FieldScriptManager->GetCurrentScriptInfo();
}



void
Entity::UnsetJump(void)
{
    m_Triangle = m_JumpTriangleEnd;
    m_State = STAND;

    if (m_ScriptInfo.entity_id != -1)
    {
        m_FieldScriptManager->ContinueEntityScriptExecution(m_ScriptInfo);
        m_ScriptInfo.entity_id = -1;
    }
}



const Ogre::Vector3&
Entity::GetJumpStart(void) const
{
    return m_JumpStart;
}



const Ogre::Vector3&
Entity::GetJumpEnd(void) const
{
    return m_JumpEnd;
}



void
Entity::SetSpeed(const float speed)
{
    m_Speed = speed;
}



const float
Entity::GetSpeed(void) const
{
    return m_Speed;
}



void
Entity::SetMovePlayAnimation(const bool play)
{
    m_MovePlayAnimation = play;
}



const bool
Entity::GetMovePlayAnimation(void) const
{
    return m_MovePlayAnimation;
}



const int
Entity::MoveToPosition(const float x, const float y, const bool play_animation)
{
    Ogre::Vector2 pos(x, y);
    Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT] move_to_position: Move to point '" + Ogre::StringConverter::toString(pos) + "'.");

    if (m_ScriptInfo.entity_id != -1)
    {
        Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT ERROR] move_to_position: Entity already in waiting state.");
        return 1;
    }

    this->SetMove(pos, NULL, 0);
    this->SetMovePlayAnimation(play_animation);

    return -1;
}



const int
Entity::MoveToModel(Entity* model, const bool play_animation)
{
    Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT] move_to_model: Move to model '" + model->GetName() + "'.");

    if (m_ScriptInfo.entity_id != -1)
    {
        Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT ERROR] move_to_model: Entity already in waiting state.");
        return 1;
    }

    SetMove(Ogre::Vector2(0, 0), model, GetSolidRange() + model->GetSolidRange());
    SetMovePlayAnimation(play_animation);

    return -1;
}



void
Entity::SetMove(const Ogre::Vector2& move_to, Entity* model, const float stop_distance)
{
    m_State = MOVE;
    m_MovePosition = move_to;
    m_MoveModel = model;
    m_MoveStopDistance = stop_distance;
    m_ScriptInfo = m_FieldScriptManager->GetCurrentScriptInfo();
}



void
Entity::UnsetMove(void)
{
    if (this->GetMovePlayAnimation() == true)
    {
        this->SetAnimationState(m_AnimationDefault, 0, -1, m_AnimationSpeedCurrent, PLAY_DEFAULT);
    }

    m_MoveModel = NULL;
    m_MoveStopDistance = 0;

    if (m_ScriptInfo.entity_id != -1)
    {
        m_FieldScriptManager->ContinueEntityScriptExecution(m_ScriptInfo);
        m_ScriptInfo.entity_id = -1;
    }

    m_State = STAND;
}


const Ogre::Vector2&
Entity::GetMovePosition(void) const
{
    return m_MovePosition;
}



const float
Entity::GetMoveStopDistance() const
{
    return m_MoveStopDistance;
}



const int
Entity::GetHeight(void) const
{
    return m_Height;
}



void
Entity::SetSolidRange(const float range)
{
    m_SolidRange = range;
    m_ModelSolidCollisionNode->setScale(m_SolidRange, m_SolidRange, m_Height);
}



const float
Entity::GetSolidRange(void) const
{
    return m_SolidRange;
}



void
Entity::SetSolid(const bool solid)
{
    Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT] set_solid: Solidity set to '" + Ogre::StringConverter::toString(solid) + "'.");

    m_ModelSolidCollisionNode->setVisible(solid && m_DrawDebug);

    m_Solid = solid;
}



const bool
Entity::IsSolid(void) const
{
    return m_Solid;
}



void
Entity::SetTalkRange(const float range)
{
    m_TalkRange = range;
    m_ModelTalkCollisionNode->setScale(m_TalkRange, m_TalkRange, m_Height);
}



const float
Entity::GetTalkRange(void) const
{
    return m_TalkRange;
}



void
Entity::SetTalkable(const bool talkable)
{
    m_ModelTalkCollisionNode->setVisible(talkable && m_DrawDebug);

    m_Talkable = talkable;
}



const bool
Entity::IsTalkable(void) const
{
    return m_Talkable;
}



void
Entity::SetAnimationDefault(const char* animation, const float relative_speed)
{
    Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT] Set default animation (" + Ogre::String(animation) + ").");

    m_AnimationDefault      = Ogre::String(animation);
    m_AnimationDefaultSpeed = m_AnimationSpeed * relative_speed;
    m_AnimationState        = PLAY_DEFAULT;
}



void
Entity::PlayAnimation(const char* animation, const float start, const float end, const float relative_speed, const bool stop_in_last_frame)
{
    Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT] Play animation (" + Ogre::String(animation) + ").");

    this->SetAnimationState(Ogre::String(animation), start, end, m_AnimationSpeed * relative_speed, (stop_in_last_frame == true) ? PLAY_STOP_IN_LAST_FRAME : PLAY_GO_TO_DEFAULT);
}



const int
Entity::PlayAnimationWait(const char* animation, const float start, const float end, const float relative_speed, const bool stop_in_last_frame)
{
    Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT] play_animation_wait: Play animation (" + Ogre::String(animation) + ") and wait.");

    if (m_ScriptInfo.entity_id != -1)
    {
        Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT ERROR] play_animation_wait: Model already in waiting state.");
        return 1;
    }

    m_ScriptInfo = m_FieldScriptManager->GetCurrentScriptInfo();
    m_AnimationWait = true;

    bool ret = this->SetAnimationState(Ogre::String(animation), start, end, m_AnimationSpeed * relative_speed, (stop_in_last_frame == true) ? PLAY_STOP_IN_LAST_FRAME : PLAY_GO_TO_DEFAULT);

    if (ret == false)
    {
        Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT ERROR] play_animation_wait: Animation don't exist.");
        return 1;
    }

    return -1;
}



const int
Entity::SetAnimationWait()
{
    Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT] set_animation_wait: Set current animation to wait.");

    if (m_ScriptInfo.entity_id != -1)
    {
        Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT ERROR] set_animation_wait: Model already in waiting state.");
        return 1;
    }

    m_ScriptInfo = m_FieldScriptManager->GetCurrentScriptInfo();
    m_AnimationWait = true;

    return -1;
}
