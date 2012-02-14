#include "EntityManager.h"

#include <OgreEntity.h>
#include <OgreRoot.h>

#include "ConfigVar.h"
#include "EntityModel.h"
#include "Logger.h"
#include "ScriptManager.h"
#include "Timer.h"



template<>EntityManager *Ogre::Singleton< EntityManager >::ms_Singleton = NULL;



ConfigVar cv_debug_grid( "debug_grid", "Draw debug grid", "false" );
ConfigVar cv_debug_axis( "debug_axis", "Draw debug axis", "false" );



const float
PointElevation( const Ogre::Vector2& point, const Ogre::Vector3& A, const Ogre::Vector3& B, const Ogre::Vector3& C )
{
    float _A = A.z * ( B.y - C.y ) + B.z * ( C.y - A.y ) + C.z * ( A.y - B.y );
    float _B = A.y * ( B.x - C.x ) + B.y * ( C.x - A.x ) + C.y * ( A.x - B.x );
    float _C = A.x * ( B.z - C.z ) + B.x * ( C.z - A.z ) + C.x * ( A.z - B.z );
    float _D = A.x * ( B.z * C.y - C.z * B.y ) + B.x * ( C.z * A.y - A.z * C.y ) + C.x * ( A.z * B.y - B.z * A.y );

    return ( _D - _C * point.y - _A * point.x ) / _B;
}



const float
SideOfVector( const Ogre::Vector2& point, const Ogre::Vector2& p1, const Ogre::Vector2& p2 )
{
    Ogre::Vector2 AB = p2    - p1;
    Ogre::Vector2 AP = point - p1;
    return AB.x * AP.y - AB.y * AP.x;
}



EntityManager::EntityManager():
    m_EntityTableName( "EntityContainer" ),
    m_PlayerEntity( NULL ),
    m_PlayerMove( Ogre::Vector3::ZERO )
{
    LOG_TRIVIAL( "EntityManager created." );

    m_SceneNode = Ogre::Root::getSingleton().getSceneManager( "Scene" )->getRootSceneNode()->createChildSceneNode( "EntityManager" );

    m_Grid = Ogre::Root::getSingleton().getSceneManager( "Scene" )->createEntity( "Grid", "system/grid.mesh" );
    m_SceneNode->attachObject( m_Grid );
    m_Axis = Ogre::Root::getSingleton().getSceneManager( "Scene" )->createEntity( "Axis", "system/axis.mesh" );
    m_SceneNode->attachObject( m_Axis );
}



EntityManager::~EntityManager()
{
    if( m_Grid != NULL )
    {
        Ogre::Root::getSingleton().getSceneManager( "Scene" )->destroyEntity( m_Grid );
    }
    if( m_Axis != NULL )
    {
        Ogre::Root::getSingleton().getSceneManager( "Scene" )->destroyEntity( m_Axis );
    }

    Clear();

    Ogre::Root::getSingleton().getSceneManager( "Scene" )->getRootSceneNode()->removeAndDestroyChild( "EntityManager" );

    LOG_TRIVIAL( "EntityManager destroyed." );
}



void
EntityManager::Input( const Event& event )
{
    if( m_PlayerEntity != NULL )
    {
        if( ( event.type == ET_KEY_IMPULSE ) && ( event.param1 == OIS::KC_LEFT ) )
        {
            m_PlayerMove.x = -1;
        }
        else if( ( event.type == ET_KEY_IMPULSE ) && ( event.param1 == OIS::KC_RIGHT ) )
        {
            m_PlayerMove.x = 1;
        }

        if( ( event.type == ET_KEY_IMPULSE ) && ( event.param1 == OIS::KC_DOWN ) )
        {
            m_PlayerMove.y = -1;
        }

        if( ( event.type == ET_KEY_IMPULSE ) && ( event.param1 == OIS::KC_UP ) )
        {
            m_PlayerMove.y = 1;
        }
    }
}



void
EntityManager::Update()
{
    m_Grid->setVisible( cv_debug_grid.GetB() );
    m_Axis->setVisible( cv_debug_axis.GetB() );



    // set move point for player entity
    if( m_PlayerEntity != NULL && m_PlayerMove != Ogre::Vector3::ZERO )
    {
        m_PlayerMove *= m_PlayerEntity->GetMoveSpeed() * Timer::getSingleton().GetGameTimeDelta();
        m_PlayerEntity->SetMoveTarget( m_PlayerEntity->GetPosition() + m_PlayerMove );
        m_PlayerEntity->SetMoveState( MS_WALKMESH );
        m_PlayerMove = Ogre::Vector3::ZERO;
    }



    for( size_t i = 0; i < m_EntityModels.size(); ++i )
    {
        m_EntityModels[ i ]->Update();



        // update offseting
        if( m_EntityModels[ i ]->GetOffsetType() != AT_NONE )
        {
            SetNextOffsetStep( m_EntityModels[ i ] );
        }



        // update turning
        if( m_EntityModels[ i ]->GetTurnType() != AT_NONE )
        {
            SetNextTurnStep( m_EntityModels[ i ] );
        }



        // update movement
        bool move = false;
        if( m_EntityModels[ i ]->GetMoveState() == MS_WALKMESH )
        {
            // try set entity on walkmesh it it's still don't has triangle
            if( m_EntityModels[ i ]->GetMoveTriangleId() == -1 )
            {
                if( SetEntityOnWalkmesh( m_EntityModels[ i ] ) == false )
                {
                    m_EntityModels[ i ]->UnsetMove();
                }
            }

            // perform move
            if( m_EntityModels[ i ]->GetMoveState() == MS_WALKMESH )
            {
                move = PerformWalkmeshMove( m_EntityModels[ i ] );
            }
        }



        // we perform move so play acording animation if needed
        if( m_EntityModels[ i ]->GetMoveAutoAnimation() == true )
        {
            if( move == true )
            {
                if( m_EntityModels[ i ]->GetMoveSpeed() >= m_EntityModels[ i ]->GetMoveSpeedRun() )
                {
                    m_EntityModels[ i ]->PlayAnimationLooped( m_EntityModels[ i ]->GetMoveAnimationRunName() );
                }
                else
                {
                    m_EntityModels[ i ]->PlayAnimationLooped( m_EntityModels[ i ]->GetMoveAnimationWalkName() );
                }
            }
            else
            {
                m_EntityModels[ i ]->PlayAnimationLooped( m_EntityModels[ i ]->GetMoveAnimationIdleName() );
            }
        }
    }



    m_Walkmesh.Update();
}



void
EntityManager::Clear()
{
    m_Walkmesh.Clear();

    for( size_t i = 0; i < m_EntityModels.size(); ++i )
    {
        ScriptManager::getSingleton().RemoveEntity( m_EntityTableName + "." + m_EntityModels[ i ]->GetName() );
        delete m_EntityModels[ i ];
    }
    m_EntityModels.clear();
    m_PlayerEntity = NULL;

    for( size_t i = 0; i < m_EntityScripts.size(); ++i )
    {
        ScriptManager::getSingleton().RemoveEntity( m_EntityTableName + "." + m_EntityScripts[ i ] );
    }

    m_SceneNode->removeAndDestroyAllChildren();
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
EntityManager::AddEntityModel( const Ogre::String& name, const Ogre::String& file_name, const Ogre::Vector3& position, const Ogre::Degree& direction )
{
    Ogre::SceneNode* node = m_SceneNode->createChildSceneNode( "Model_" + name );
    EntityModel* entity = new EntityModel( name, file_name, node );
    entity->SetPosition( position );
    entity->SetDirection( direction );

    m_EntityModels.push_back( entity );

    ScriptManager::getSingleton().AddEntity( m_EntityTableName + "." + entity->GetName() );
}



void
EntityManager::AddEntityScript( const Ogre::String& name )
{
    m_EntityScripts.push_back( name );
    ScriptManager::getSingleton().AddEntity( m_EntityTableName + "." + name );
}



Entity*
EntityManager::GetEntity( const Ogre::String& name ) const
{
    for( size_t i = 0; i < m_EntityModels.size(); ++i )
    {
        if( m_EntityModels[ i ]->GetName() == name )
        {
            return m_EntityModels[ i ];
        }
    }

    return NULL;
}



Entity*
EntityManager::ScriptGetEntity( const char* name ) const
{
    return GetEntity( Ogre::String( name ) );
}



void
EntityManager::ScriptSetPlayerEntity( const char* name )
{
    for( size_t i = 0; i < m_EntityModels.size(); ++i )
    {
        if( m_EntityModels[ i ]->GetName() == name )
        {
            m_PlayerEntity = m_EntityModels[ i ];
        }
    }
}



const bool
EntityManager::SetEntityOnWalkmesh( Entity* entity )
{
    Ogre::Vector3 position3 = entity->GetPosition();
    Ogre::Vector2 position2;
    position2.x = position3.x;
    position2.y = position3.y;

    std::vector< std::pair< int, float > > triangles;

    // we search for posible triangles
    for( int i = 0; i < m_Walkmesh.GetNumberOfTriangles(); ++i )
    {
        Ogre::Vector3 A3 = m_Walkmesh.GetA( i );
        Ogre::Vector3 B3 = m_Walkmesh.GetB( i );
        Ogre::Vector3 C3 = m_Walkmesh.GetC( i );

        Ogre::Vector2 A2( A3.x, A3.y );
        Ogre::Vector2 B2( B3.x, B3.y );
        Ogre::Vector2 C2( C3.x, C3.y );

        if( Ogre::Math::pointInTri2D( position2, A2, B2, C2 ) == true )
        {
            triangles.push_back( std::make_pair( i, PointElevation( position2, m_Walkmesh.GetA( i ), m_Walkmesh.GetB( i ), m_Walkmesh.GetC( i ) ) ) );
        }
    }



    // if our coords doesn't match any triangle
    if( triangles.size() == 0 )
    {
        LOG_ERROR( "Can't find any triangle to place entity \"" + entity->GetName() + "\" on walkmesh." );
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
    for( size_t i = 0; i < triangles.size(); ++i )
    {
        if( triangles[ i ].second <= pos_z )
        {
            pos_z = triangles[ i ].second;
            triangle_id = triangles[ i ].first;
            break;
        }
    }
    // if every triangle are higher than entity
    if( triangle_id == -1 )
    {
        for( size_t i = 0; i < triangles.size(); ++i )
        {
            if( triangles[ i ].second >= pos_z )
            {
                pos_z = triangles[ i ].second;
                triangle_id = triangles[ i ].first;
            }
        }
    }
    entity->SetPosition( Ogre::Vector3( position2.x, position2.y, pos_z ) );
    entity->SetMoveTriangleId( triangle_id );
    return true;
}



const bool
EntityManager::PerformWalkmeshMove( Entity* entity )
{
    Ogre::Vector3 start_point = entity->GetPosition();
    Ogre::Vector3 move_vector = entity->GetMoveTarget() - start_point;
    Ogre::Vector2 direction( move_vector.x, move_vector.y );

    // if we already in point to where we want to move - finish movement
    //if( direction.length() <= 0.01 )
    {
        //entity->UnsetMove();
        //return;
    }

    direction.normalise();
    direction *= Timer::getSingleton().GetGameTimeDelta();
    direction *= entity->GetMoveSpeed();

    // if we still need to move but speed ot time don't allow us to do this just return for now
    if( direction.isZeroLength() == true )
    {
        return false;
    }

    int current_triangle = entity->GetMoveTriangleId();
    if( current_triangle == -1 )
    {
        entity->UnsetMove();
        LOG_ERROR( "Entity not placed on walkmesh and can't move.");
        return false;
    }

    //LOG_TRIVIAL( "Start position calculation." );
    //LOG_TRIVIAL( "Start point: " + Ogre::StringConverter::toString( start_point ) + "." );
    //LOG_TRIVIAL( "Move vector: " + Ogre::StringConverter::toString( direction ) + "." );

    Ogre::Vector3 rotation( 0.0f, 0.0f, 0.0f );
    Ogre::Quaternion q1( 0.0f, 0.0f, 0.0f, 1.0f );
    Ogre::Vector3 end_point( 0.0f, 0.0f, 0.0f );
    Ogre::Vector3 end_point2( 0.0f, 0.0f, 0.0f );
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

    Ogre::Vector3 A3 = m_Walkmesh.GetA( current_triangle );
    Ogre::Vector3 B3 = m_Walkmesh.GetB( current_triangle );
    Ogre::Vector3 C3 = m_Walkmesh.GetC( current_triangle );

    end_point.z = PointElevation( Ogre::Vector2( end_point.x, end_point.y ), A3, B3, C3 );
    Ogre::Vector3 temp = end_point - start_point;
    temp.normalise();
    temp = temp * direction.length();
    direction.x = temp.x;
    direction.y = temp.y;

    //LOG_TRIVIAL( "Shortened Direction:(" + Ogre::StringConverter::toString( direction ) + ")." );



    // set direction for entity if we want to move
    if( entity->GetMoveAutoRotation() == true )
    {
        Ogre::Vector2 up( 0.0f, -1.0f );
        // angle between vectors
        Ogre::Degree angle( Ogre::Radian( acosf( direction.dotProduct( up ) / ( direction.length() * up.length() ) ) ) );
        angle = ( direction.x < 0 ) ? Ogre::Degree( 360 ) - angle : angle;

        entity->SetDirection( Ogre::Degree( angle ) );
    }



    float solid = ( entity->IsSolid() == true ) ? entity->GetSolidRadius() : 0.01;



    // get ending point
    end_point.z = start_point.z;
    //LOG_TRIVIAL( "End point: (" + Ogre::StringConverter::toString( end_point ) + ")." );

    //LOG_TRIVIAL( "Start cycle." );
//    for (int i = 0; (m_PlayerModelId == model_id && m_PlayerModelSlip == true && i < 16) ||
                    //(m_PlayerModelId == model_id && m_PlayerModelSlip == false && i < 3) ||
                    //(m_PlayerModelId != model_id && i <= 16); ++i)
    for (int i = 0; i <= 16; ++i )
    {
        //LOG_TRIVIAL( "Cycle " + Ogre::StringConverter::toString( i ) + "." );

        // 1st check
        // rotate move_vector +45
        q1.FromAngleAxis( Ogre::Radian( Ogre::Degree( 45 ) ), Ogre::Vector3::UNIT_Z );
        rotation.x = direction.x;
        rotation.y = direction.y;
        rotation.z = 0;
        rotation.normalise();
        rotation = q1 * rotation;
        //LOG_TRIVIAL( "Move vector length: " + Ogre::StringConverter::toString( rotation.length() ) + "." );
        // multiply move_vector by solid range
        rotation = rotation * solid;
        end_point2.x = end_point.x + rotation.x;
        end_point2.y = end_point.y + rotation.y;
        //LOG_TRIVIAL( "Left sector part end point:(" + Ogre::StringConverter::toString( end_point2 ) + ")." );
        // check_triangle
        first_triangle_check = WalkmeshBorderCross( entity, end_point2, direction );
        entity->SetMoveTriangleId( current_triangle );
        // model_check
        first_entity_check = CheckSolidCollisions( entity, end_point2 );
        //LOG_ERROR( "Check1: " + Ogre::StringConverter::toString( first_triangle_check ) + " " + Ogre::StringConverter::toString( first_entity_check ) + "." );

        // 2nd check
        // rotate move_vector +45
        q1.FromAngleAxis( Ogre::Radian( Ogre::Degree( -45 ) ), Ogre::Vector3::UNIT_Z );
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
        second_triangle_check = WalkmeshBorderCross( entity, end_point2, direction );
        entity->SetMoveTriangleId( current_triangle );
        // model_check
        second_entity_check = CheckSolidCollisions( entity, end_point2 );
        //LOG_ERROR( "Check2: " + Ogre::StringConverter::toString( second_triangle_check ) + " " + Ogre::StringConverter::toString( second_entity_check ) + "." );

        // 3rd check
        rotation.x = direction.x;
        rotation.y = direction.y;
        rotation.z = 0;
        rotation.normalise();
        rotation = rotation * solid;
        end_point2.x = end_point.x + rotation.x;
        end_point2.y = end_point.y + rotation.y;
        // check triangle
        third_triangle_check = WalkmeshBorderCross( entity, end_point2, direction );
        entity->SetMoveTriangleId( current_triangle );
        // model_check
        third_entity_check = CheckSolidCollisions( entity, end_point2 );
        //LOG_ERROR( "Check3: " + Ogre::StringConverter::toString( third_triangle_check ) + " " + Ogre::StringConverter::toString( third_entity_check ) + "." );

        // check condition and modify move_vector
        if (first_triangle_check  != false || second_triangle_check != false || third_triangle_check  != false ||
            first_entity_check    != false || second_entity_check   != false || third_entity_check    != false)
        {
/*
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
*/
                if( first_entity_check  == false && second_entity_check == false && third_entity_check  == false )
                {
                    // if not both left and right check was fail
                    if( first_triangle_check == false || second_triangle_check == false )
                    {
                        if( ( first_triangle_check == false && first_entity_check != false ) ||
                            ( first_triangle_check != false && second_triangle_check == false ) )
                        {
                            q1.FromAngleAxis( Ogre::Radian( Ogre::Degree( -11.25f ) ), Ogre::Vector3::UNIT_Z );
                            rotation.x = direction.x;
                            rotation.y = direction.y;
                            rotation = q1 * rotation;
                            direction.x = rotation.x;
                            direction.y = rotation.y;
                            /*log->logMessage("New move vector: " + Ogre::StringConverter::toString(direction.x) +
                                                            " " + Ogre::StringConverter::toString(direction.y) + ".");*/
                        }

                        if( first_triangle_check == false && first_entity_check == false && ( second_triangle_check != false || second_entity_check != false ) )
                        {
                            q1.FromAngleAxis( Ogre::Radian( Ogre::Degree( 11.25f ) ), Ogre::Vector3::UNIT_Z );
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
//            }
        }
    }

    //LOG_TRIVIAL( "Stop cycle." );



    // set new X, Y and Z
    last_triangle_check = WalkmeshBorderCross( entity, end_point, direction );

    if( first_triangle_check  != false || second_triangle_check != false || third_triangle_check  != false || last_triangle_check   != false ||
        first_entity_check    != false || second_entity_check   != false || third_entity_check    != false )
    {
        LOG_WARNING( "Can't move to specified position.");
        entity->UnsetMove();
        return false;
    }


/*
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
*/


    entity->SetPosition( end_point );



    // if we come to destination point - finish movement
    Ogre::Vector3 final = entity->GetMoveTarget() - end_point;
    if( Ogre::Vector2( final.x, final.y ).length() <= 0.01 )
    {
        entity->UnsetMove();
    }

    return true;
}



const bool
EntityManager::WalkmeshBorderCross( Entity* entity, Ogre::Vector3& position, const Ogre::Vector2& move_vector)
{
    int current_triangle = entity->GetMoveTriangleId();
    if (current_triangle == -1)
    {
        return true;
    }

    Ogre::Vector2 pos = Ogre::Vector2( position.x, position.y );

    for( ;; )
    {
        Ogre::Vector3 A3 = m_Walkmesh.GetA( current_triangle );
        Ogre::Vector3 B3 = m_Walkmesh.GetB( current_triangle );
        Ogre::Vector3 C3 = m_Walkmesh.GetC( current_triangle );
        /*LOG_ERROR( "Triangle:A(" + Ogre::StringConverter::toString( A3.x ) +
                             " " + Ogre::StringConverter::toString( A3.y ) +
                             " " + Ogre::StringConverter::toString( A3.z ) +
                          ") B(" + Ogre::StringConverter::toString( B3.x ) +
                             " " + Ogre::StringConverter::toString( B3.y ) +
                             " " + Ogre::StringConverter::toString( B3.z ) +
                          ") C(" + Ogre::StringConverter::toString( C3.x ) +
                             " " + Ogre::StringConverter::toString( C3.y ) +
                             " " + Ogre::StringConverter::toString( C3.z ) + ")." );*/
        Ogre::Vector2 A( A3.x, A3.y );
        Ogre::Vector2 B( B3.x, B3.y );
        Ogre::Vector2 C( C3.x, C3.y );

        float sign1 = SideOfVector( pos, B, A );
        float sign2 = SideOfVector( pos, C, B );
        float sign3 = SideOfVector( pos, A, C );

        /*log->logMessage("(" + Ogre::StringConverter::toString(sign1) +
                        " " + Ogre::StringConverter::toString(sign2) +
                        " " + Ogre::StringConverter::toString(sign3) + ").");*/

        int next_triangle = -1;

        if( sign1 < 0 )
        {
            next_triangle = m_Walkmesh.GetAccessSide( current_triangle, 0 );
            //log->logMessage("BA leave to " + Ogre::StringConverter::toString(next_triangle) + ".");
        }
        else if( sign2 < 0 )
        {
            next_triangle = m_Walkmesh.GetAccessSide( current_triangle, 1 );
            //log->logMessage("CB leave to " + Ogre::StringConverter::toString(next_triangle) + ".");
        }
        else if( sign3 < 0 )
        {
            next_triangle = m_Walkmesh.GetAccessSide( current_triangle, 2 );
            //log->logMessage("AC leave to " + Ogre::StringConverter::toString(next_triangle) + ".");
        }
        else
        {
            position.z = PointElevation( pos, A3, B3, C3 );
            //LOG_ERROR( "In triangle." );
            //LOG_ERROR( "Stop CheckTriangles with false and triangle " + Ogre::StringConverter::toString( current_triangle ) + "." );
            entity->SetMoveTriangleId( current_triangle );
            return false;
        }

        if( next_triangle >= 0 )
        {
            bool lock = m_Walkmesh.IsLocked( next_triangle );

            if( lock == false )
            {
                current_triangle = next_triangle;
                //log->logMessage("New current triangle " + Ogre::StringConverter::toString(current_triangle) + ".");
                continue;
            }
        }

        position.z = PointElevation( pos, A3, B3, C3 );
        //log->logMessage("Stop CheckTriangles with 1 and triangle " + Ogre::StringConverter::toString(current_triangle) + ".");
        entity->SetMoveTriangleId( current_triangle );
        return true;
    }
}



const bool
EntityManager::CheckSolidCollisions( Entity* entity, Ogre::Vector3& position )
{
    if( entity->IsSolid() == false )
    {
        return false;
    }

    //Ogre::LogManager* log = Ogre::LogManager::getSingletonPtr();
    for( size_t i = 0; i < m_EntityModels.size(); ++i )
    {
        if( m_EntityModels[ i ]->IsSolid() == false )
        {
            continue;
        }

        if( m_EntityModels[ i ] == entity )
        {
            continue;
        }

        Ogre::Vector3 pos1 = m_EntityModels[ i ]->GetPosition();
        float solid_range1 = m_EntityModels[ i ]->GetSolidRadius();
        float solid_range2 = entity->GetSolidRadius();

        float height = ( pos1.z < position.z ) ? m_EntityModels[ i ]->GetHeight() : entity->GetHeight();

        //log->logMessage("Height collision(" + Ogre::StringConverter::toString(pos1.z) + " " + Ogre::StringConverter::toString(position.z) + " " + Ogre::StringConverter::toString(height) + ").");

        if( ( ( pos1.z - position.z + height ) < ( height * 2 ) ) && ( ( pos1.z - position.z + height ) >= 0 ) )
        {
            float solid_range = ( solid_range1 + solid_range2 ) * ( solid_range1 + solid_range2 );
            float distance = ( pos1.x - position.x ) * ( pos1.x - position.x ) + ( pos1.y - position.y ) * ( pos1.y - position.y );

            //log->logMessage("Dist collision(" + Ogre::StringConverter::toString(solid_range) + " " + Ogre::StringConverter::toString(distance) + ").");

            if( distance < solid_range )
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
EntityManager::SetNextOffsetStep( Entity* entity )
{
    ActionType type = entity->GetOffsetType();
    float steps = entity->GetOffsetStepSeconds();
    float step = entity->GetOffsetCurrentStepSeconds();

    Ogre::Vector3 start = entity->GetOffsetPositionStart();
    Ogre::Vector3 end = entity->GetOffsetPositionEnd();

    float x = step / steps;
    float smooth_modifier = ( type == AT_SMOOTH ) ? -2 * x * x * x + 3 * x * x : x;
    Ogre::Vector3 current = start + ( end - start ) * smooth_modifier;

    entity->SetOffset( current );

    if (step == steps)
    {
        entity->UnsetOffset();
    }
    else
    {
        entity->SetOffsetCurrentStepSeconds( step + Timer::getSingleton().GetGameTimeDelta() );
    }
}



void
EntityManager::SetNextTurnStep( Entity* entity )
{
    ActionType type = entity->GetTurnType();
    float steps = entity->GetTurnStepSeconds();
    float step = entity->GetTurnCurrentStepSeconds();

    Ogre::Degree start = entity->GetTurnDirectionStart();
    Ogre::Degree end = entity->GetTurnDirectionEnd();

    float x = step / steps;
    float smooth_modifier = ( type == AT_SMOOTH ) ? -2 * x * x * x + 3 * x * x : x;
    Ogre::Degree direction = start + ( end - start ) * smooth_modifier;

    entity->SetDirection( direction );

    if( step == steps )
    {
        entity->UnsetTurn();
    }
    else
    {
        entity->SetTurnCurrentStepSeconds( step + Timer::getSingleton().GetGameTimeDelta() );
    }
}
