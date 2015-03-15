#include <OgreEntity.h>
#include <OgreRoot.h>

#include "core/CameraManager.h"
#include "core/ConfigVar.h"
#include "core/DebugDraw.h"
#include "core/EntityManager.h"
#include "core/EntityModel.h"
#include "core/InputManager.h"
#include "core/Logger.h"
#include "core/ScriptManager.h"
#include "core/Timer.h"
#include "core/DialogsManager.h"


template<>EntityManager *Ogre::Singleton<EntityManager>::msSingleton = nullptr;
ConfigVar cv_debug_grid("debug_grid", "Draw debug grid", "false");
ConfigVar cv_debug_axis("debug_axis", "Draw debug axis", "false");


float
PointElevation(const Ogre::Vector2& point, const Ogre::Vector3& A, const Ogre::Vector3& B, const Ogre::Vector3& C)
{
    float _A = A.z * (B.y - C.y) + B.z * (C.y - A.y) + C.z * (A.y - B.y);
    float _B = A.y * (B.x - C.x) + B.y * (C.x - A.x) + C.y * (A.x - B.x);
    float _C = A.x * (B.z - C.z) + B.x * (C.z - A.z) + C.x * (A.z - B.z);
    float _D = A.x * (B.z * C.y - C.z * B.y) + B.x * (C.z * A.y - A.z * C.y) + C.x * (A.z * B.y - B.z * A.y);

    return (_D - _C * point.y - _A * point.x) / _B;
}


float
SideOfVector(const Ogre::Vector2& point, const Ogre::Vector2& p1, const Ogre::Vector2& p2)
{
    Ogre::Vector2 AB = p2    - p1;
    Ogre::Vector2 AP = point - p1;
    return AB.x * AP.y - AB.y * AP.x;
}


float
SquareDistanceToLine(const Ogre::Vector3& p, const Ogre::Vector3& p1, const Ogre::Vector3& p2, Ogre::Vector3& proj)
{
    float temp = -((p1.x - p.x) * (p2.x - p1.x) + (p1.y - p.y) *
                   (p2.y - p1.y) + (p1.z - p.z) * (p2.z - p1.z)) /
                  ((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) *
                   (p2.y - p1.y) + (p2.z - p1.z) * (p2.z - p1.z));

    proj.x = temp * (p2.x - p1.x) + p1.x;
    proj.y = temp * (p2.y - p1.y) + p1.y;
    proj.z = temp * (p2.z - p1.z) + p1.z;

    if(((p1.x >= proj.x && p2.x <= proj.x) || (p1.x < proj.x && p2.x >= proj.x)) &&
        ((p1.y >= proj.y && p2.y <= proj.y) || (p1.y < proj.y && p2.y >= proj.y)))
    {
        return (proj.x - p.x) * (proj.x - p.x) + (proj.y - p.y) * (proj.y - p.y) + (proj.z - p.z) * (proj.z - p.z);
    }

    return -1;
}


Ogre::Degree
GetDirectionToPoint(const Ogre::Vector3& current_point, const Ogre::Vector3& direction_point)
{
    Ogre::Vector2 up(0.0f, -1.0f);
    Ogre::Vector2 dir(direction_point.x - current_point.x, direction_point.y - current_point.y);
    // angle between vectors
    Ogre::Degree angle(Ogre::Radian(acosf(dir.dotProduct(up) / (dir.length() * up.length()))));
    return (dir.x < 0) ? Ogre::Degree(360) - angle : angle;
}


EntityManager::EntityManager():
    m_Paused(false),
    m_PlayerEntity(nullptr),
    m_PlayerMove(Ogre::Vector3::ZERO),
    m_PlayerMoveRotation(0),
    m_PlayerLock( false ),
    m_PlayerRun( false )
{
    LOG_TRIVIAL("EntityManager created.");

    m_SceneNode = Ogre::Root::getSingleton().getSceneManager("Scene")->getRootSceneNode()->createChildSceneNode("EntityManager");

    m_Grid = Ogre::Root::getSingleton().getSceneManager("Scene")->createEntity("Grid", "system/grid.mesh");
    m_SceneNode->attachObject(m_Grid);
    m_Axis = Ogre::Root::getSingleton().getSceneManager("Scene")->createEntity("Axis", "system/axis.mesh");
    m_SceneNode->attachObject(m_Axis);
}


EntityManager::~EntityManager()
{
    if(m_Grid != nullptr)
    {
        Ogre::Root::getSingleton().getSceneManager("Scene")->destroyEntity(m_Grid);
    }
    if(m_Axis != nullptr)
    {
        Ogre::Root::getSingleton().getSceneManager("Scene")->destroyEntity(m_Axis);
    }

    Clear();

    Ogre::Root::getSingleton().getSceneManager("Scene")->getRootSceneNode()->removeAndDestroyChild("EntityManager");

    LOG_TRIVIAL("EntityManager destroyed.");
}


void
EntityManager::Input(const QGears::Event& event)
{
    m_Background2D.InputDebug(event);

    if(m_Paused == true)
    {
        return;
    }

    if( m_PlayerEntity != NULL && m_PlayerLock == false )
    {
        if ((event.type == QGears::ET_KEY_REPEAT) && (event.event == "walk_left"))
        {
            m_PlayerMove.x = -1;
        }
        else if ((event.type == QGears::ET_KEY_REPEAT) && (event.event == "walk_right"))
        {
            m_PlayerMove.x = 1;
        }

        if ((event.type == QGears::ET_KEY_REPEAT) && (event.event == "walk_down"))
        {
            m_PlayerMove.y = -1;
        }
        else if ((event.type == QGears::ET_KEY_REPEAT) && (event.event == "walk_up"))
        {
            m_PlayerMove.y = 1;
        }

        if ((event.type == QGears::ET_KEY_REPEAT) && (event.event == "run"))
        {
            m_PlayerRun = true;
        }

        if ((event.type == QGears::ET_KEY_PRESS) && (event.event == "interact"))
        {
            CheckEntityInteract();

            for( unsigned int i = 0; i < m_EntityTriggers.size(); ++i )
            {
                if( m_EntityTriggers[ i ]->IsEnabled() == true && m_EntityTriggers[ i ]->IsActivator( m_PlayerEntity ) == true )
                {
                    ScriptEntity* scr_entity = ScriptManager::getSingleton().GetScriptEntityByName( ScriptManager::ENTITY, m_EntityTriggers[ i ]->GetName() );
                    bool added = ScriptManager::getSingleton().ScriptRequest( scr_entity, "on_interact", 1, "", "", false, false );
                    if( added == false )
                    {
                        LOG_WARNING( "Script \"on_interact\" for entity \"" +  m_EntityTriggers[ i ]->GetName() + "\" doesn't exist." );
                    }
                }
            }
        }
        //rotate move vector to field move rotation
        Ogre::Quaternion q1;
        q1.FromAngleAxis(m_PlayerMoveRotation, Ogre::Vector3::UNIT_Z);
        m_PlayerMove = q1 * m_PlayerMove;
    }
}


void
EntityManager::Update()
{
    UpdateDebug();

    if(m_Paused == true)
    {
        return;
    }

    // update all entity scripts
    ScriptManager::getSingleton().Update(ScriptManager::ENTITY);

    // set move point for player entity
    if(m_PlayerEntity != nullptr && m_PlayerMove != Ogre::Vector3::ZERO)
    {
        Entity::State state = m_PlayerEntity->GetState();
        if(state == Entity::WALKMESH || state == Entity::NONE)
        {
            m_PlayerMove *= m_PlayerEntity->GetMoveWalkSpeed() * Timer::getSingleton().GetGameTimeDelta();
            m_PlayerEntity->SetMovePosition(m_PlayerEntity->GetPosition() + m_PlayerMove);
            m_PlayerEntity->SetState(Entity::WALKMESH);
        }
    }

    for(unsigned int i = 0; i < m_Entity.size(); ++i)
    {
        m_Entity[i]->Update();

        // it's not needed to update movements it delta time == 0 (for example if we stop time)
        if(Timer::getSingleton().GetGameTimeDelta() == 0)
        {
            continue;
        }

        // update screen scroll
        Entity* scroll_entity = m_Background2D.GetAutoScrollEntity();
        if(scroll_entity == m_Entity[i])
        {
            CameraManager &camera_manager(CameraManager::getSingleton());
            Ogre::Vector3 view = camera_manager.ProjectPointToScreen(scroll_entity->GetPosition());
            Ogre::Vector2 pos = m_Background2D.GetScreenScroll();
            Ogre::Viewport *viewport(camera_manager.getViewport());
            float width = float(viewport->getActualWidth());
            float height = float(viewport->getActualHeight());
            view.x = view.x - width / 2 - pos.x;
            view.y = view.y - height / 2 - pos.y;
            m_Background2D.SetScreenScroll(Ogre::Vector2(-view.x, -view.y));
        }

        // update offseting
        if(m_Entity[i]->GetOffsetType() != AT_NONE)
        {
            SetNextOffsetStep(m_Entity[i]);
        }

        // update turning
        if(m_Entity[i]->GetTurnType() != AT_NONE)
        {
            SetNextTurnStep(m_Entity[i]);
        }

        // update movement
        switch(m_Entity[i]->GetState())
        {
            case Entity::WALKMESH:
            {
                bool is_move = false;

                // try set entity on walkmesh it it's still don't has triangle
                if(m_Entity[i]->GetMoveTriangleId() == -1)
                {
                    if(SetEntityOnWalkmesh(m_Entity[i]) == false)
                    {
                        LOG_TRIVIAL("Can't set entity \"" + m_Entity[i]->GetName() + "\" on walkmesh. Finish move.");
                        m_Entity[i]->UnsetMove();
                    }
                }

                // perform move
                if(m_Entity[i]->GetState() == Entity::WALKMESH)
                {
                    float speed = 0;
                    if(m_PlayerLock == false && m_PlayerEntity == m_Entity[i])
                    {
                        speed = m_Entity[i]->GetMoveWalkSpeed();

                        if( m_PlayerRun == true )
                        {
                            speed *= 4;
                        }
                    }
                    else
                    {
                        speed = m_Entity[i]->GetMoveAutoSpeed();
                    }

                    is_move = PerformWalkmeshMove(m_Entity[i], speed);

                    if(m_Entity[i]->GetMoveAutoAnimation() == true)
                    {
                        if(is_move == true)
                        {
                            if(speed >= m_Entity[i]->GetMoveRunSpeed())
                            {
                                m_Entity[i]->PlayAnimationContinue(m_Entity[i]->GetMoveAnimationRunName());
                            }
                            else
                            {
                                m_Entity[i]->PlayAnimationContinue(m_Entity[i]->GetMoveAnimationWalkName());
                            }
                        }
                        else if (m_Entity[i]->GetAnimationState() != Entity::REQUESTED_ANIMATION)
                        {
                            m_Entity[i]->PlayAnimationContinue(m_Entity[i]->GetDefaultAnimationName());
                        }
                    }
                }
            }
            break;

            case Entity::LINEAR:
            {
                SetNextLinearStep(m_Entity[i]);
            }
            break;

            case Entity::JUMP:
            {
                SetNextJumpStep(m_Entity[i]);
            }
            break;

            case Entity::NONE:
            {
                if(m_Entity[i]->GetAnimationState() != Entity::REQUESTED_ANIMATION)
                {
                    m_Entity[i]->PlayAnimationContinue(m_Entity[i]->GetDefaultAnimationName());
                }
            }
            break;
        }
    }

    // reset player move. It already must be handled in update
    m_PlayerMove = Ogre::Vector3::ZERO;
    m_PlayerRun = false;

    if(m_Background2D.GetScrollType() != Background2D::NONE)
    {
        SetNextScrollStep();
    }
    m_Background2D.Update();
}


void
EntityManager::UpdateDebug()
{
    m_Grid->setVisible(cv_debug_grid.GetB());
    m_Axis->setVisible(cv_debug_axis.GetB());

    for(unsigned int i = 0; i < m_Entity.size(); ++i)
    {
        m_Entity[i]->UpdateDebug();
    }

    for(unsigned int i = 0; i < m_EntityTriggers.size(); ++i)
    {
        m_EntityTriggers[i]->UpdateDebug();
    }

    for(unsigned int i = 0; i < m_EntityPoints.size(); ++i)
    {
        m_EntityPoints[i]->UpdateDebug();
    }

    m_Walkmesh.UpdateDebug();
    m_Background2D.UpdateDebug();
}


void
EntityManager::OnResize()
{
    m_Background2D.OnResize();
}


void
EntityManager::Clear()
{
    m_Walkmesh.Clear();
    m_Background2D.Clear();
    DialogsManager::getSingleton().Clear();

    for(unsigned int i = 0; i < m_Entity.size(); ++i)
    {
        ScriptManager::getSingleton().RemoveEntity(ScriptManager::ENTITY, m_Entity[i]->GetName());
        delete m_Entity[i];
    }
    m_Entity.clear();
    m_PlayerEntity = nullptr;
    m_PlayerMove = Ogre::Vector3::ZERO;
    m_PlayerMoveRotation = 0;

    m_PlayerLock = false;

    for(unsigned int i = 0; i < m_EntityTriggers.size(); ++i)
    {
        ScriptManager::getSingleton().RemoveEntity(ScriptManager::ENTITY, m_EntityTriggers[i]->GetName());
        delete m_EntityTriggers[i];
    }
    m_EntityTriggers.clear();

    for(unsigned int i = 0; i < m_EntityPoints.size(); ++i)
    {
        delete m_EntityPoints[i];
    }
    m_EntityPoints.clear();

    for(unsigned int i = 0; i < m_EntityScripts.size(); ++i)
    {
        ScriptManager::getSingleton().RemoveEntity(ScriptManager::ENTITY, m_EntityScripts[i]);
    }

    m_SceneNode->removeAndDestroyAllChildren();
}


void
EntityManager::ScriptSetPaused(const bool paused)
{
    m_Paused = paused;
}


Walkmesh*
EntityManager::GetWalkmesh()
{
    return &m_Walkmesh;
}


Background2D*
EntityManager::GetBackground2D()
{
    return &m_Background2D;
}


void
EntityManager::AddEntity(const Ogre::String& name, const Ogre::String& file_name, const Ogre::Vector3& position, const Ogre::Degree& rotation)
{
    AddEntity(name, file_name, position, rotation, Ogre::Vector3::UNIT_SCALE, Ogre::Quaternion::IDENTITY);
}


void
EntityManager::AddEntity(const Ogre::String& name, const Ogre::String& file_name, const Ogre::Vector3& position, const Ogre::Degree& rotation, const Ogre::Vector3& scale, const Ogre::Quaternion& root_orientation)
{
    Ogre::SceneNode* node = m_SceneNode->createChildSceneNode("Model_" + name);
    EntityModel* entity = new EntityModel(name, file_name, node);
    entity->SetPosition(position);
    entity->SetRotation(rotation);
    entity->setScale(scale);
    entity->setRootOrientation(root_orientation);

    m_Entity.push_back(entity);

    ScriptManager::getSingleton().AddEntity(ScriptManager::ENTITY, entity->GetName(), entity);
}


void
EntityManager::ScriptAddEntity(const char* name, const char* file_name, const float x, const float y, const float z, const float rotation)
{
    AddEntity(name, file_name, Ogre::Vector3(x, y, z), Ogre::Degree(rotation));
}


void
EntityManager::AddEntityTrigger(const Ogre::String& name, const Ogre::Vector3& point1, const Ogre::Vector3& point2, const bool enabled)
{
    EntityTrigger* trigger = new EntityTrigger(name);
    trigger->SetPoints(point1, point2);
    trigger->SetEnabled(enabled);
    m_EntityTriggers.push_back(trigger);

    ScriptManager::getSingleton().AddEntity(ScriptManager::ENTITY, trigger->GetName(), nullptr);
}


void
EntityManager::AddEntityPoint(const Ogre::String& name, const Ogre::Vector3& position, const float rotation)
{
    EntityPoint* entity_point = new EntityPoint(name);
    entity_point->SetPosition(position);
    entity_point->SetRotation(rotation);
    m_EntityPoints.push_back(entity_point);
}


void
EntityManager::AddEntityScript(const Ogre::String& name)
{
    m_EntityScripts.push_back(name);
    ScriptManager::getSingleton().AddEntity(ScriptManager::ENTITY, name, nullptr);
}


void
EntityManager::ScriptAddEntityScript(const char* name)
{
    AddEntityScript(name);
}


Entity*
EntityManager::GetEntity(const Ogre::String& name) const
{
    for(unsigned int i = 0; i < m_Entity.size(); ++i)
    {
        if(m_Entity[i]->GetName() == name)
        {
            return m_Entity[i];
        }
    }

    return nullptr;
}


Entity*
EntityManager::ScriptGetEntity(const char* name) const
{
    return GetEntity(Ogre::String(name));
}


EntityPoint*
EntityManager::ScriptGetEntityPoint(const char* name) const
{
    for(unsigned int i = 0; i < m_EntityPoints.size(); ++i)
    {
        if(m_EntityPoints[i]->GetName() == name)
        {
            return m_EntityPoints[i];
        }
    }

    return nullptr;
}


void
EntityManager::ScriptSetPlayerEntity(const char* name)
{
    for(unsigned int i = 0; i < m_Entity.size(); ++i)
    {
        if(m_Entity[i]->GetName() == name)
        {
            m_PlayerEntity = m_Entity[i];
        }
    }
}


void
EntityManager::ScriptUnsetPlayerEntity()
{
    m_PlayerEntity = nullptr;
}


void
EntityManager::ScriptPlayerLock(const bool lock)
{
    m_PlayerLock = lock;
    if(lock == true)
    {
        m_PlayerMove = Ogre::Vector3::ZERO;
    }
}


void
EntityManager::SetPlayerMoveRotation(const Ogre::Radian rotation)
{
    m_PlayerMoveRotation = rotation;
}


bool
EntityManager::SetEntityOnWalkmesh(Entity* entity)
{
    Ogre::Vector3 position3 = entity->GetPosition();
    Ogre::Vector2 position2;
    position2.x = position3.x;
    position2.y = position3.y;

    std::vector< std::pair< int, float > > triangles;

    // we search for posible triangles
    for(int i = 0; i < m_Walkmesh.GetNumberOfTriangles(); ++i)
    {
        Ogre::Vector3 A3 = m_Walkmesh.GetA(i);
        Ogre::Vector3 B3 = m_Walkmesh.GetB(i);
        Ogre::Vector3 C3 = m_Walkmesh.GetC(i);

        Ogre::Vector2 A2(A3.x, A3.y);
        Ogre::Vector2 B2(B3.x, B3.y);
        Ogre::Vector2 C2(C3.x, C3.y);

        if(Ogre::Math::pointInTri2D(position2, A2, B2, C2) == true)
        {
            triangles.push_back(std::make_pair(i, PointElevation(position2, m_Walkmesh.GetA(i), m_Walkmesh.GetB(i), m_Walkmesh.GetC(i))));
        }
    }

    // if our coords doesn't match any triangle
    if(triangles.size() == 0)
    {
        LOG_ERROR("Can't find any triangle to place entity \"" + entity->GetName() + "\" on walkmesh.");
        return false;
    }

/*
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
*/

    // place entity on fount triangles
    // first try to set on top triangle less than current pos of entity
    float pos_z = position3.z;
    int triangle_id = -1;
    for(size_t i = 0; i < triangles.size(); ++i)
    {
        if(triangles[i].second <= pos_z)
        {
            pos_z = triangles[i].second;
            triangle_id = triangles[i].first;
            break;
        }
    }
    // if every triangle are higher than entity
    if(triangle_id == -1)
    {
        for(size_t i = 0; i < triangles.size(); ++i)
        {
            if(triangles[i].second >= pos_z)
            {
                pos_z = triangles[i].second;
                triangle_id = triangles[i].first;
            }
        }
    }
    entity->SetPosition(Ogre::Vector3(position2.x, position2.y, pos_z));
    entity->SetMoveTriangleId(triangle_id);
    return true;
}


bool
EntityManager::PerformWalkmeshMove(Entity* entity, const float speed)
{
    Ogre::Vector3 start_point = entity->GetPosition();
    Ogre::Vector3 move_vector = entity->GetMovePosition() - start_point;
    Ogre::Vector2 direction(move_vector.x, move_vector.y);

    direction.normalise();
    direction *= Timer::getSingleton().GetGameTimeDelta();
    direction *= speed;

    // if we still need to move but speed ot time don't allow us to do this just return for now
    if(direction.isZeroLength() == true)
    {
        return false;
    }

    int current_triangle = entity->GetMoveTriangleId();
    if(current_triangle == -1)
    {
        LOG_ERROR("Entity \"" + entity->GetName() + "\" not placed on walkmesh and can't move.");
        return false;
    }

    //LOG_TRIVIAL("Start position calculation.");
    //LOG_TRIVIAL("Start point: " + Ogre::StringConverter::toString(start_point) + ".");
    //LOG_TRIVIAL("Move vector: " + Ogre::StringConverter::toString(direction) + ".");

    Ogre::Vector3 rotation(0.0f, 0.0f, 0.0f);
    Ogre::Quaternion q1(0.0f, 0.0f, 0.0f, 1.0f);
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

    Ogre::Vector3 A3 = m_Walkmesh.GetA(current_triangle);
    Ogre::Vector3 B3 = m_Walkmesh.GetB(current_triangle);
    Ogre::Vector3 C3 = m_Walkmesh.GetC(current_triangle);

    end_point.z = PointElevation(Ogre::Vector2(end_point.x, end_point.y), A3, B3, C3);
    Ogre::Vector3 temp = end_point - start_point;
    temp.normalise();
    temp = temp * direction.length();
    direction.x = temp.x;
    direction.y = temp.y;

    //LOG_TRIVIAL("Shortened Direction:(" + Ogre::StringConverter::toString(direction) + ").");



    // set direction for entity if we want to move
    if(entity->GetMoveAutoRotation() == true)
    {
        Ogre::Vector2 up(0.0f, -1.0f);
        // angle between vectors
        Ogre::Degree angle(Ogre::Radian(acosf(direction.dotProduct(up) / (direction.length() * up.length()))));
        angle = (direction.x < 0) ? Ogre::Degree(360) - angle : angle;

        entity->SetRotation(Ogre::Degree(angle));
    }

    float solid = (entity->IsSolid() == true) ? entity->GetSolidRadius() : 0.01f;

    // get ending point
    end_point.z = start_point.z;
    //LOG_TRIVIAL("End point: (" + Ogre::StringConverter::toString(end_point) + ").");

    //LOG_TRIVIAL("Start cycle.");
    for(int i = 0; (entity == m_PlayerEntity && /*m_PlayerModelSlip == true &&*/ i < 16) ||
                    (entity == m_PlayerEntity && /*m_PlayerModelSlip == false &&*/ i < 3) ||
                    (entity != m_PlayerEntity && i <= 16); ++i)
    {
        //LOG_TRIVIAL("Cycle " + Ogre::StringConverter::toString(i) + ".");
        end_point = Ogre::Vector3(start_point.x + direction.x, start_point.y + direction.y, start_point.z);

        // 1st check
        // rotate move_vector +45
        q1.FromAngleAxis(Ogre::Radian(Ogre::Degree(45)), Ogre::Vector3::UNIT_Z);
        rotation.x = direction.x;
        rotation.y = direction.y;
        rotation.z = 0;
        rotation.normalise();
        rotation = q1 * rotation;
        //LOG_TRIVIAL("Move vector length: " + Ogre::StringConverter::toString(rotation.length()) + ".");
        // multiply move_vector by solid range
        rotation = rotation * solid;
        end_point2.x = end_point.x + rotation.x;
        end_point2.y = end_point.y + rotation.y;
        //LOG_TRIVIAL("Left sector part end point:(" + Ogre::StringConverter::toString(end_point2) + ").");
        // check_triangle
        first_triangle_check = WalkmeshBorderCross(entity, end_point2, direction);
        entity->SetMoveTriangleId(current_triangle);
        // model_check
        first_entity_check = CheckSolidCollisions(entity, end_point2);
        //LOG_TRIVIAL("Entity \"" + entity->GetName() + "\" check1: " + Ogre::StringConverter::toString(first_triangle_check) + " " + Ogre::StringConverter::toString(first_entity_check) + ".");

        // 2nd check
        // rotate move_vector +45
        q1.FromAngleAxis(Ogre::Radian(Ogre::Degree(-45)), Ogre::Vector3::UNIT_Z);
        rotation.x = direction.x;
        rotation.y = direction.y;
        rotation.z = 0;
        rotation.normalise();
        rotation = q1 * rotation;
        // multiply move_vector by solid range
        rotation = rotation * solid;
        end_point2.x = end_point.x + rotation.x;
        end_point2.y = end_point.y + rotation.y;
        // check triangle
        second_triangle_check = WalkmeshBorderCross(entity, end_point2, direction);
        entity->SetMoveTriangleId(current_triangle);
        // model_check
        second_entity_check = CheckSolidCollisions(entity, end_point2);
        //LOG_TRIVIAL("Entity \"" + entity->GetName() + "\" check2: " + Ogre::StringConverter::toString(second_triangle_check) + " " + Ogre::StringConverter::toString(second_entity_check) + ".");

        // 3rd check
        rotation.x = direction.x;
        rotation.y = direction.y;
        rotation.z = 0;
        rotation.normalise();
        rotation = rotation * solid;
        end_point2.x = end_point.x + rotation.x;
        end_point2.y = end_point.y + rotation.y;
        // check triangle
        third_triangle_check = WalkmeshBorderCross(entity, end_point2, direction);
        entity->SetMoveTriangleId(current_triangle);
        // model_check
        third_entity_check = CheckSolidCollisions(entity, end_point2);
        //LOG_TRIVIAL("Entity \"" + entity->GetName() + "\" check3: " + Ogre::StringConverter::toString(third_triangle_check) + " " + Ogre::StringConverter::toString(third_entity_check) + ".");

        // check condition and modify move_vector
        if(first_triangle_check  != false || second_triangle_check != false || third_triangle_check  != false ||
            first_entity_check    != false || second_entity_check   != false || third_entity_check    != false)
        {
            // only for NPC
            if(entity != m_PlayerEntity)
            {
                // if we collide only directly into triangle border
                if(first_triangle_check  == false && second_triangle_check == false && third_triangle_check  != false)
                {
                    q1.FromAngleAxis(Ogre::Radian(Ogre::Degree(-7)), Ogre::Vector3::UNIT_Z);
                    rotation.x = direction.x;
                    rotation.y = direction.y;
                    rotation = q1 * rotation;
                    direction.x = rotation.x;
                    direction.y = rotation.y;
                }
                // or if we only collide into others entity directly
                else if(first_entity_check  == false && second_entity_check == false && third_entity_check  != false)
                {
                    //LOG_TRIVIAL("Entity \"" + entity->GetName() + "\" try to rotate.");
                    q1.FromAngleAxis(Ogre::Radian(Ogre::Degree(-11.25f)), Ogre::Vector3::UNIT_Z);
                    rotation.x = direction.x;
                    rotation.y = direction.y;
                    rotation = q1 * rotation;
                    direction.x = rotation.x;
                    direction.y = rotation.y;
                }

                // if not both left and right check was fail
                if(first_triangle_check == false || second_triangle_check == false)
                {
                    if((first_triangle_check == false && first_entity_check != false) || (first_triangle_check != false && second_triangle_check == false))
                    {
                        q1.FromAngleAxis(Ogre::Radian(Ogre::Degree(-11.25f)), Ogre::Vector3::UNIT_Z);
                        rotation.x = direction.x;
                        rotation.y = direction.y;
                        rotation = q1 * rotation;
                        direction.x = rotation.x;
                        direction.y = rotation.y;
                        //LOGGER->Log(LOGGER_WARNING, "New move vector: %f %f.", direction.x, direction.y);
                    }

                    if(first_triangle_check == false && first_entity_check == false && (second_triangle_check != false || second_entity_check != false))
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
                if(first_entity_check  == false && second_entity_check == false && third_entity_check  == false)
                {
                    // if not both left and right check was fail
                    if(first_triangle_check == false || second_triangle_check == false)
                    {
                        if((first_triangle_check == false && first_entity_check != false) ||
                            (first_triangle_check != false && second_triangle_check == false))
                        {
                            q1.FromAngleAxis(Ogre::Radian(Ogre::Degree(-11.25f)), Ogre::Vector3::UNIT_Z);
                            rotation.x = direction.x;
                            rotation.y = direction.y;
                            rotation = q1 * rotation;
                            direction.x = rotation.x;
                            direction.y = rotation.y;
                            //LOG_TRIVIAL("Entity \"" + entity->GetName() + "\" new move vector: " + Ogre::StringConverter::toString(direction.x) + " " + Ogre::StringConverter::toString(direction.y) + ".");
                        }

                        if(first_triangle_check == false && first_entity_check == false && (second_triangle_check != false || second_entity_check != false))
                        {
                            q1.FromAngleAxis(Ogre::Radian(Ogre::Degree(11.25f)), Ogre::Vector3::UNIT_Z);
                            rotation.x = direction.x;
                            rotation.y = direction.y;
                            rotation = q1 * rotation;
                            direction.x = rotation.x;
                            direction.y = rotation.y;
                            //LOG_TRIVIAL("Entity \"" + entity->GetName() + "\" new move vector: " + Ogre::StringConverter::toString(direction.x) + " " + Ogre::StringConverter::toString(direction.y) + ".");
                        }
                        continue;
                    }
                    break;
                }
            }
        }
    }

    //LOG_TRIVIAL("Stop cycle.");

    // set new X, Y and Z
    last_triangle_check = WalkmeshBorderCross(entity, end_point, direction);

    if(first_triangle_check  != false || second_triangle_check != false || third_triangle_check  != false || last_triangle_check   != false ||
        first_entity_check    != false || second_entity_check   != false || third_entity_check    != false)
    {
        LOG_TRIVIAL("Entity \"" + entity->GetName() + "\" can't move to specified position.");
        return false;
    }

    // check triggers before set entity position because we check move line
    CheckTriggers(entity, end_point);
    entity->SetPosition(end_point);

    // if we come to destination point - finish movement
    Ogre::Vector3 final = entity->GetMovePosition() - end_point;
    if(Ogre::Vector2(final.x, final.y).length() <= entity->GetMoveStopDistance() + speed / 10)
    {
        entity->UnsetMove();
    }

    return true;
}


bool
EntityManager::WalkmeshBorderCross(Entity* entity, Ogre::Vector3& position, const Ogre::Vector2& move_vector)
{
    int current_triangle = entity->GetMoveTriangleId();
    if (current_triangle == -1)
    {
        return true;
    }

    Ogre::Vector2 pos = Ogre::Vector2(position.x, position.y);

    for(;;)
    {
        Ogre::Vector3 A3 = m_Walkmesh.GetA(current_triangle);
        Ogre::Vector3 B3 = m_Walkmesh.GetB(current_triangle);
        Ogre::Vector3 C3 = m_Walkmesh.GetC(current_triangle);
        /*LOG_ERROR("Triangle:A(" + Ogre::StringConverter::toString(A3.x) +
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

        float sign1 = SideOfVector(pos, B, A);
        float sign2 = SideOfVector(pos, C, B);
        float sign3 = SideOfVector(pos, A, C);

        int next_triangle = -1;

        if(sign1 < 0)
        {
            next_triangle = m_Walkmesh.GetAccessSide(current_triangle, 0);
        }
        else if(sign2 < 0)
        {
            next_triangle = m_Walkmesh.GetAccessSide(current_triangle, 1);
        }
        else if(sign3 < 0)
        {
            next_triangle = m_Walkmesh.GetAccessSide(current_triangle, 2);
        }
        else
        {
            position.z = PointElevation(pos, A3, B3, C3);
            //LOG_ERROR("In triangle.");
            //LOG_ERROR("Stop CheckTriangles with false and triangle " + Ogre::StringConverter::toString(current_triangle) + ".");
            entity->SetMoveTriangleId(current_triangle);
            return false;
        }

        if(next_triangle >= 0)
        {
            bool lock = m_Walkmesh.IsLocked(next_triangle);

            if(lock == false)
            {
                current_triangle = next_triangle;
                continue;
            }
        }

        position.z = PointElevation(pos, A3, B3, C3);
        entity->SetMoveTriangleId(current_triangle);
        return true;
    }
}


bool
EntityManager::CheckSolidCollisions(Entity* entity, Ogre::Vector3& position)
{
    if(entity->IsSolid() == false)
    {
        return false;
    }

    for(size_t i = 0; i < m_Entity.size(); ++i)
    {
        if(m_Entity[i]->IsSolid() == false)
        {
            continue;
        }

        if(m_Entity[i] == entity)
        {
            continue;
        }

        Ogre::Vector3 pos1 = m_Entity[i]->GetPosition();
        float solid_range = m_Entity[i]->GetSolidRadius();
        solid_range *= solid_range;

        float height = (pos1.z < position.z) ? m_Entity[i]->GetHeight() : entity->GetHeight();

        //log->logMessage("Height collision(" + Ogre::StringConverter::toString(pos1.z) + " " + Ogre::StringConverter::toString(position.z) + " " + Ogre::StringConverter::toString(height) + ").");

        if(((pos1.z - position.z + height) < (height * 2)) && ((pos1.z - position.z + height) >= 0))
        {
            float distance = (pos1.x - position.x) * (pos1.x - position.x) + (pos1.y - position.y) * (pos1.y - position.y);

            //log->logMessage("Dist collision(" + Ogre::StringConverter::toString(solid_range) + " " + Ogre::StringConverter::toString(distance) + ").");

            if(distance < solid_range)
            {
                //log->logMessage("Collide with entity.");

                // if this is player and we move by ourself (in ffvii only player model checked)
/*
                if (model_id == m_PlayerModelId && m_PlayerModelLock == false)
                {
                    m_FieldScriptManager->AddScript(m_Models[i]->GetName(), "on_collide", 1);
                }
*/
                return true;
            }
        }
    }

    //LOGGER->Log(LOGGER_INFO, "Not collide with entity");
    return false;
}


void
EntityManager::CheckTriggers(Entity* entity, Ogre::Vector3& position)
{
    if(entity->IsSolid() == false)
    {
        return;
    }

    for(unsigned int i = 0; i < m_EntityTriggers.size(); ++i)
    {
        ScriptEntity* scr_entity = ScriptManager::getSingleton().GetScriptEntityByName(ScriptManager::ENTITY, m_EntityTriggers[i]->GetName());

        if(scr_entity != nullptr && m_EntityTriggers[i]->IsEnabled() == true)
        {
            Ogre::Vector3 lp1 = m_EntityTriggers[i]->GetPoint1();
            Ogre::Vector3 lp2 = m_EntityTriggers[i]->GetPoint2();
            Ogre::Vector3 mp1 = entity->GetPosition();

            Ogre::Vector3 proj;

            // calculate distance
            float square_dist = SquareDistanceToLine(mp1, lp1, lp2, proj);
            float solid = entity->GetSolidRadius();

            if(square_dist != -1 && square_dist < solid * solid)
            {
                if(m_EntityTriggers[i]->IsActivator(entity) == false)
                {
                    bool added = ScriptManager::getSingleton().ScriptRequest(scr_entity, "on_enter_line", 1, entity->GetName(), "", false, false);
                    if(added == false)
                    {
                        LOG_WARNING("Script \"on_enter_line\" for entity \"" +  m_EntityTriggers[i]->GetName() + "\" doesn't exist.");
                    }
                    m_EntityTriggers[i]->AddActivator(entity);
                }

                // check that 1st and 2nd points are on different side of line
                float cond1 = ((lp2.x - lp1.x) * (mp1.y - lp1.y)) - ((mp1.x - lp1.x) * (lp2.y - lp1.y));
                float cond2 = ((lp2.x - lp1.x) * (position.y - lp1.y)) - ((position.x - lp1.x) * (lp2.y - lp1.y));

                // if we cross the line
                if((cond1 > 0 && cond2 <= 0) || (cond2 > 0 && cond1 <= 0) || (cond1 >= 0 && cond2 < 0) || (cond2 >= 0 && cond1 < 0))
                {
                    bool added = ScriptManager::getSingleton().ScriptRequest(scr_entity, "on_cross_line", 1, entity->GetName(), "", false, false);
                    if(added == false)
                    {
                        LOG_WARNING("Script \"on_cross_line\" for entity \"" +  m_EntityTriggers[i]->GetName() + "\" doesn't exist.");
                    }
                }

                // if we not move in line
                if(mp1 == position)
                {
                    bool added = ScriptManager::getSingleton().ScriptRequest(scr_entity, "on_move_to_line", 1, entity->GetName(), "", false, false);
                    if(added == false)
                    {
                        LOG_WARNING("Script \"on_move_to_line\" for entity \"" +  m_EntityTriggers[i]->GetName() + "\" doesn't exist.");
                    }
                }
                else
                {
                    const Ogre::Degree direction_to_line = GetDirectionToPoint(mp1, proj);
                    const Ogre::Degree movement_direction = GetDirectionToPoint(mp1, position);

                    // if we move to line
                    Ogre::Degree angle = direction_to_line - movement_direction + Ogre::Degree(90);
                    angle = (angle > Ogre::Degree(360)) ? angle - Ogre::Degree(360) : angle;

                    if(angle < Ogre::Degree(180) && angle > Ogre::Degree(0))
                    {
                        bool added = ScriptManager::getSingleton().ScriptRequest(scr_entity, "on_move_to_line", 1, entity->GetName(), "", false, false);
                        if(added == false)
                        {
                            LOG_WARNING("Script \"on_move_to_line\" for entity \"" +  m_EntityTriggers[i]->GetName() + "\" doesn't exist.");
                        }
                    }
                }
            }
            else
            {
                if(m_EntityTriggers[i]->IsActivator(entity) == true)
                {
                    bool added = ScriptManager::getSingleton().ScriptRequest(scr_entity, "on_leave_line", 1, entity->GetName(), "", false, false);
                    if(added == false)
                    {
                        LOG_WARNING("Script \"on_leave_line\" for entity \"" +  m_EntityTriggers[i]->GetName() + "\" doesn't exist.");
                    }
                    m_EntityTriggers[i]->RemoveActivator(entity);
                }
            }
        }
    }
}



void
EntityManager::CheckEntityInteract()
{
    if( m_PlayerEntity == NULL || m_PlayerLock == true || m_PlayerEntity->IsSolid() == false )
    {
        return;
    }

    Ogre::Degree angle_pc = m_PlayerEntity->GetRotation();
    Entity* entity_to_interact = NULL;
    Ogre::Degree less_angle( 90 );

    for( unsigned int i = 0; i < m_Entity.size(); ++i )
    {
        if( m_Entity[ i ]->IsTalkable() == false )
        {
            continue;
        }

        if( m_Entity[ i ] == m_PlayerEntity )
        {
            continue;
        }

        Ogre::Vector3 pos1 =  m_Entity[ i ]->GetPosition();
        float interact_range =  m_Entity[ i ]->GetTalkRadius();
        Ogre::Vector3 pos2 = m_PlayerEntity->GetPosition();
        float solid_range = m_PlayerEntity->GetSolidRadius();

        int height = ( pos1.z < pos2.z ) ?  m_Entity[ i ]->GetHeight() : m_PlayerEntity->GetHeight();

        if( ( ( pos1.z - pos2.z + height ) < ( height * 2 ) ) && ( ( pos1.z - pos2.z + height ) >= 0 ) )
        {
            interact_range = ( interact_range + solid_range ) * ( interact_range + solid_range );
            float distance = ( pos1.x - pos2.x ) * ( pos1.x - pos2.x ) + ( pos1.y - pos2.y ) * ( pos1.y - pos2.y );

            if( distance < interact_range + solid_range )
            {
                Ogre::Degree angle_to_model = GetDirectionToPoint( pos2, pos1 );
                Ogre::Degree angle = angle_pc - angle_to_model;
                angle = ( angle < Ogre::Degree( 0 ) ) ? -angle : angle;
                angle = ( angle >= Ogre::Degree( 180 ) ) ? Ogre::Degree( 360 ) - angle : angle;

                if( angle < less_angle )
                {
                    angle = less_angle;
                    entity_to_interact = m_Entity[ i ];
                }
            }
        }
    }

    if( entity_to_interact != NULL )
    {
        Ogre::String name = entity_to_interact->GetName();
        ScriptEntity* scr_entity = ScriptManager::getSingleton().GetScriptEntityByName( ScriptManager::ENTITY, name );
        bool added = ScriptManager::getSingleton().ScriptRequest( scr_entity, "on_interact", 1, "", "", false, false );
        if( added == false )
        {
            LOG_WARNING( "Script \"on_interact\" for entity \"" +  name + "\" doesn't exist." );
        }
    }
}

void
EntityManager::SetNextOffsetStep(Entity* entity)
{
    ActionType type = entity->GetOffsetType();
    float total = entity->GetOffsetSeconds();
    float current = entity->GetOffsetCurrentSeconds();

    current += Timer::getSingleton().GetGameTimeDelta();
    current = (current > total) ? total : current;

    Ogre::Vector3 start = entity->GetOffsetPositionStart();
    Ogre::Vector3 end = entity->GetOffsetPositionEnd();

    float x = current / total;
    float smooth_modifier = (type == AT_SMOOTH) ? -2 * x * x * x + 3 * x * x : x;
    Ogre::Vector3 offset = start + (end - start) * smooth_modifier;

    entity->SetOffset(offset);

    if(current == total)
    {
        entity->UnsetOffset();
    }
    else
    {
        entity->SetOffsetCurrentSeconds(current);
    }
}


void
EntityManager::SetNextTurnStep(Entity* entity)
{
    ActionType type = entity->GetTurnType();
    float total = entity->GetTurnSeconds();
    float current = entity->GetTurnCurrentSeconds();

    current += Timer::getSingleton().GetGameTimeDelta();
    current = (current > total) ? total : current;

    Ogre::Degree start = entity->GetTurnDirectionStart();
    Ogre::Degree end = entity->GetTurnDirectionEnd();

    float x = current / total;
    float smooth_modifier = (type == AT_SMOOTH) ? -2 * x * x * x + 3 * x * x : x;
    Ogre::Degree rotation = start + (end - start) * smooth_modifier;

    entity->SetRotation(rotation);

    if(current == total)
    {
        entity->UnsetTurn();
    }
    else
    {
        entity->SetTurnCurrentSeconds(current);
    }
}


void
EntityManager::SetNextLinearStep(Entity* entity)
{
    bool to_end = true;
    bool is_move = false;

    Ogre::Vector3 start = entity->GetLinearStart();
    Ogre::Vector3 end = entity->GetLinearEnd();
    Ogre::Vector3 current = entity->GetPosition();

    float delta = Timer::getSingleton().GetGameTimeDelta();

    if(entity == m_PlayerEntity)
    {
        LinearMovement move = entity->GetLinearMovement();

        if(move == LM_DOWN_TO_UP || move == LM_UP_TO_DOWN)
        {
            if(m_PlayerMove.y > 0) // move up
            {
                to_end = (move == LM_DOWN_TO_UP) ? true : false;
                is_move = true;
            }
            else if(m_PlayerMove.y < 0) // move down
            {
                to_end = (move == LM_DOWN_TO_UP) ? false : true;
                is_move = true;
            }
        }
        else if(move == LM_LEFT_TO_RIGHT || move == LM_RIGHT_TO_LEFT)
        {
            if(m_PlayerMove.x > 0) // move right
            {
                to_end = (move == LM_LEFT_TO_RIGHT) ? true : false;
                is_move = true;
            }
            else if(m_PlayerMove.x < 0) // move left
            {
                to_end = (move == LM_LEFT_TO_RIGHT) ? false : true;
                is_move = true;
            }
        }
    }
    else
    {
        is_move = true;
    }

    if(is_move == true)
    {
        Ogre::Vector3 position;

        if(to_end == true)
        {
            Ogre::Vector3 end_start = end - start;
            float time = end_start.length() / 1.2f; // move whole line by this number of seconds
            position.x = current.x + (end_start.x / time) * delta;
            position.y = current.y + (end_start.y / time) * delta;
            position.z = current.z + (end_start.z / time) * delta;
            position.x = (end_start.x < 0) ? std::max(position.x, end.x) : std::min(position.x, end.x);
            position.y = (end_start.y < 0) ? std::max(position.y, end.y) : std::min(position.y, end.y);
            position.z = (end_start.z < 0) ? std::max(position.z, end.z) : std::min(position.z, end.z);

            if(position == end)
            {
                entity->UnsetLinear();
            }
        }
        else
        {
            Ogre::Vector3 end_start = start - end;
            float time = end_start.length() / 1.2f; // move whole line by this number of seconds
            position.x = current.x + (end_start.x / time) * delta;
            position.y = current.y + (end_start.y / time) * delta;
            position.z = current.z + (end_start.z / time) * delta;
            position.x = (end_start.x < 0) ? std::max(position.x, start.x) : std::min(position.x, start.x);
            position.y = (end_start.y < 0) ? std::max(position.y, start.y) : std::min(position.y, start.y);
            position.z = (end_start.z < 0) ? std::max(position.z, start.z) : std::min(position.z, start.z);

            if(position == start)
            {
                entity->UnsetLinear();
            }
        }

        entity->SetPosition(position);
        entity->UpdateAnimation((to_end == true) ? delta : -delta);
    }
}


void
EntityManager::SetNextJumpStep(Entity* entity)
{
    float total = entity->GetJumpSeconds();
    float current = entity->GetJumpCurrentSeconds();

    current += Timer::getSingleton().GetGameTimeDelta();
    current = (current > total) ? total : current;

    Ogre::Vector3 start_position = entity->GetJumpStart();
    Ogre::Vector3 end_position   = entity->GetJumpEnd();
    Ogre::Vector3 position;
    position.x = start_position.x + ((end_position.x - start_position.x) / total) * current;
    position.y = start_position.y + ((end_position.y - start_position.y) / total) * current;
    position.z = current * current * -13.08f + current * ((end_position.z - start_position.z) / total + total * 13.08f) + start_position.z;
    entity->SetPosition(position);

    if(total == current)
    {
        entity->UnsetJump();
    }
    else
    {
        entity->SetJumpCurrentSeconds(current);
    }
}


void
EntityManager::SetNextScrollStep()
{
    Background2D::ScrollType type = m_Background2D.GetScrollType();
    float total = m_Background2D.GetScrollSeconds();
    float current = m_Background2D.GetScrollCurrentSeconds();

    current += Timer::getSingleton().GetGameTimeDelta();
    current = (current > total) ? total : current;

    Ogre::Vector2 start = m_Background2D.GetScrollPositionStart();
    Ogre::Vector2 end = m_Background2D.GetScrollPositionEnd();

    float x = current / total;
    float smooth_modifier = (type == Background2D::SMOOTH) ? -2 * x * x * x + 3 * x * x : x;
    Ogre::Vector2 scroll = start + (end - start) * smooth_modifier;

    m_Background2D.SetScroll(scroll);

    if(current == total)
    {
        m_Background2D.UnsetScroll();
    }
    else
    {
        m_Background2D.SetScrollCurrentSeconds(current);
    }
}
