#ifndef ENTITY_MANAGER_H
#define ENTITY_MANAGER_H

#include <OgreSingleton.h>

#include "Background2D.h"
#include "Entity.h"
#include "Event.h"
#include "Walkmesh.h"



class EntityManager : public Ogre::Singleton< EntityManager >
{
public:
    EntityManager();
    virtual ~EntityManager();

    void Input( const Event& event );
    void Update();

    void Clear();

    Walkmesh* GetWalkmesh();
    Background2D* GetBackground2D();
    void AddEntityModel( const Ogre::String& name, const Ogre::String& file_name, const Ogre::Vector3& position, const Ogre::Degree& direction );
    void AddEntityScript( const Ogre::String& name );

    Entity* GetEntity( const Ogre::String& name ) const;
    Entity* ScriptGetEntity( const char* name ) const;

    void ScriptSetPlayerEntity( const char* name );
    void ScriptUnsetPlayerEntity();

private:
    // movement
    bool SetEntityOnWalkmesh( Entity* entity );
    bool PerformWalkmeshMove( Entity* entity );
    bool WalkmeshBorderCross( Entity* entity, Ogre::Vector3& position, const Ogre::Vector2& move_vector );
    bool CheckSolidCollisions( Entity* entity, Ogre::Vector3& position );
    void SetEntityDirectionByVector( Entity* entity, const Ogre::Vector2& vector );

    void SetNextOffsetStep( Entity* entity );
    void SetNextTurnStep( Entity* entity );
    void SetNextLinearStep( Entity* entity );
    void SetNextJumpStep( Entity* entity );
private:
    Walkmesh                    m_Walkmesh;
    Background2D                m_Background2D;

    Ogre::String                m_EntityTableName;
    std::vector< Entity* >      m_EntityModels;
    Entity*                     m_PlayerEntity;
    Ogre::Vector3               m_PlayerMove;

    std::vector< Ogre::String > m_EntityScripts;

    Ogre::SceneNode*            m_SceneNode;

    Ogre::Entity*               m_Grid;
    Ogre::Entity*               m_Axis;
};



#endif // ENTITY_MANAGER_H
