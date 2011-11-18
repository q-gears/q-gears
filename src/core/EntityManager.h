#ifndef ENTITY_MANAGER_H
#define ENTITY_MANAGER_H

#include <OgreSingleton.h>

#include "Background2D.h"
#include "Entity.h"
#include "Walkmesh.h"



class EntityManager : public Ogre::Singleton< EntityManager >
{
public:
    EntityManager();
    virtual ~EntityManager();

    void Update();

    void Clear();

    Walkmesh* GetWalkmesh();
    Background2D* GetBackground2D();
    void AddEntityModel( const Ogre::String& name, const Ogre::String& file_name, const Ogre::Vector3& position, const Ogre::Degree& direction );
    void AddEntityScript( const Ogre::String& name );

    Entity* GetEntity( const Ogre::String& name );
    Entity* ScriptGetEntity( const char* name );

private:
    // movement
    const bool SetEntityOnWalkmesh( Entity* entity );
    void PerformWalkmeshMove( Entity* entity );
    const bool WalkmeshBorderCross( Entity* entity, Ogre::Vector3& position, const Ogre::Vector2& move_vector );
    const bool CheckSolidCollisions( Entity* entity, Ogre::Vector3& position );
    void SetEntityDirectionByVector( Entity* entity, const Ogre::Vector2& vector );

private:
    Walkmesh m_Walkmesh;
    Background2D m_Background2D;
    std::vector< Entity* > m_EntityModels;
    std::vector< Ogre::String > m_EntityScripts;

    Ogre::SceneNode* m_SceneNode;

    Ogre::Entity* m_Grid;
    Ogre::Entity* m_Axis;
};



#endif // ENTITY_MANAGER_H
