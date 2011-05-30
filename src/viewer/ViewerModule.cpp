#include "ViewerModule.h"

//#include <Ogre.h>

#include <OgreEntity.h>
#include <OgreRoot.h>

#include "../core/Assert.h"
#include "../core/Logger.h"
#include "../core/Timer.h"
#include "../core/particles/ParticleSystemManager.h"
#include "../game/Walkmesh.h"
#include "../game/XmlWalkmeshFile.h"
#include "../game/XmlMapsFile.h"
#include "../game/XmlMapFile.h"





ViewerModule::ViewerModule():
    m_Entity( NULL ),
    m_Walkmesh( NULL ),

    m_Grid( NULL ),
    m_Axis( NULL )
{
    m_SceneNode = Ogre::Root::getSingleton().getSceneManager( "Scene" )->getRootSceneNode()->createChildSceneNode( "ViewerModule" );

    //m_EntityState.SetPosition( 300, 5 );
    //m_EntityState.SetVisible( true );
    //m_EntityState.SetText( "Model: not loaded" );

/*
    Ogre::ManualObject* grid = new Ogre::ManualObject("Grid");
    grid->begin("viewer/grid", Ogre::RenderOperation::OT_LINE_LIST);
    float grid_size = 1.0f;
    for (int j = -25; j < 25; ++j)
    {
        for (int i = -25; i < 25; ++i)
        {
            if (j == 24)
            {
                grid->position(grid_size * i, grid_size * (j + 1), 0); grid->position(grid_size * (i + 1), grid_size * (j + 1), 0);
            }
            if (i == -25)
            {
                grid->position(grid_size * i, grid_size * j, 0); grid->position(grid_size * i, grid_size * (j + 1), 0);
            }

            grid->position(grid_size * i, grid_size * j, 0); grid->position(grid_size * (i + 1), grid_size * j, 0);
            grid->position(grid_size * (i + 1), grid_size * j, 0); grid->position(grid_size * (i + 1), grid_size * (j + 1), 0);
        }
    }
    grid->end();
    Ogre::MeshPtr mesh = grid->convertToMesh("grid");
    Ogre::MeshSerializer ser;
    ser.exportMesh(mesh.getPointer(), "grid.mesh");

    Ogre::ManualObject* m_Axis = new Ogre::ManualObject("Axis");
    m_Axis->begin("viewer/axis", Ogre::RenderOperation::OT_LINE_LIST);
    float axis_size = 100.0f;
    m_Axis->position(0, 0, 0); m_Axis->colour(1.0f, 0, 0); m_Axis->position(axis_size, 0, 0); m_Axis->colour(1.0f, 0, 0);
    m_Axis->position(0, 0, 0); m_Axis->colour(0, 1.0f, 0); m_Axis->position(0, axis_size, 0); m_Axis->colour(0, 1.0f, 0);
    m_Axis->position(0, 0, 0); m_Axis->colour(0, 0, 1.0f); m_Axis->position(0, 0, axis_size); m_Axis->colour(0, 0, 1.0f);
    m_Axis->end();
    mesh = m_Axis->convertToMesh("axis");
    ser.exportMesh(mesh.getPointer(), "axis.mesh");
*/

/*
    Ogre::ManualObject* no_model = new Ogre::ManualObject("NoModel");
    no_model->begin("system/no_model", Ogre::RenderOperation::OT_TRIANGLE_LIST);
    float cube_size = 1.0f;
    no_model->position(-cube_size / 2, cube_size / 2, 0); no_model->textureCoord(1, 0);
    no_model->position(cube_size / 2, cube_size / 2, 0); no_model->textureCoord(0, 0);
    no_model->position(-cube_size / 2, -cube_size / 2, 0); no_model->textureCoord(1, 1);
    no_model->position(cube_size / 2, -cube_size / 2, 0); no_model->textureCoord(0, 1);
    no_model->triangle(0, 1, 2);
    no_model->triangle(1, 3, 2);
    no_model->position(-cube_size / 2, cube_size / 2, cube_size); no_model->textureCoord(0, 0);
    no_model->position(cube_size / 2, cube_size / 2, cube_size); no_model->textureCoord(1, 0);
    no_model->position(-cube_size / 2, -cube_size / 2, cube_size); no_model->textureCoord(0, 1);
    no_model->position(cube_size / 2, -cube_size / 2, cube_size); no_model->textureCoord(1, 1);
    no_model->triangle(4, 6, 5);
    no_model->triangle(5, 6, 7);
    no_model->position(-cube_size / 2, -cube_size / 2, cube_size); no_model->textureCoord(1, 1);
    no_model->position(-cube_size / 2, cube_size / 2, cube_size); no_model->textureCoord(1, 0);
    no_model->position(-cube_size / 2, -cube_size / 2, 0); no_model->textureCoord(0, 1);
    no_model->position(-cube_size / 2, cube_size / 2, 0); no_model->textureCoord(0, 0);
    no_model->triangle(8, 9, 10);
    no_model->triangle(9, 11, 10);
    no_model->position(cube_size / 2, cube_size / 2, cube_size); no_model->textureCoord(0, 0);
    no_model->position(cube_size / 2, -cube_size / 2, cube_size); no_model->textureCoord(0, 1);
    no_model->position(cube_size / 2, cube_size / 2, 0); no_model->textureCoord(1, 0);
    no_model->position(cube_size / 2, -cube_size / 2, 0); no_model->textureCoord(1, 1);
    no_model->triangle(12, 13, 14);
    no_model->triangle(13, 15, 14);

    no_model->position(-cube_size / 2, cube_size / 2, cube_size); no_model->textureCoord(0, 0);
    no_model->position(cube_size / 2, cube_size / 2, cube_size); no_model->textureCoord(0, 1);
    no_model->position(-cube_size / 2, cube_size / 2, 0); no_model->textureCoord(1, 0);
    no_model->position(cube_size / 2, cube_size / 2, 0); no_model->textureCoord(1, 1);
    no_model->triangle(15, 16, 17);
    no_model->triangle(16, 18, 17);

    no_model->end();
    m_SceneNode->attachObject(no_model);
//    mesh = m_Axis->convertToMesh("axis");
//    ser.exportMesh(mesh.getPointer(), "axis.mesh");
*/

    m_Grid = Ogre::Root::getSingleton().getSceneManager( "Scene" )->createEntity( "Grid", "system/grid.mesh" );
    m_SceneNode->attachObject( m_Grid );
    m_Axis = Ogre::Root::getSingleton().getSceneManager( "Scene" )->createEntity( "Axis", "system/axis.mesh" );
    m_SceneNode->attachObject( m_Axis );
    m_SceneNode->setPosition( 0, 0, 0 );



//    m_ParticleSystem = ParticleSystemManager::getSingleton().CreateParticleSystem("Test1", "Test");
//    m_SceneNode->attachObject(m_ParticleSystem);



    LOG_TRIVIAL( "ViewerModule created." );
}



ViewerModule::~ViewerModule()
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

    Ogre::Root::getSingleton().getSceneManager( "Scene" )->getRootSceneNode()->removeAndDestroyChild( "ViewerModule" );

    LOG_TRIVIAL( "ViewerModule destroyed." );
}



void
ViewerModule::Input( const Event& event )
{
    if (event.type == ET_KEY_PRESS && event.param1 == OIS::KC_DOWN)
    {
        bool change = false;
        if (m_Entity != NULL)
        {
            if (m_Entity->getAllAnimationStates() != NULL)
            {
                Ogre::AnimationStateIterator animations = m_Entity->getAllAnimationStates()->getAnimationStateIterator();

                while (animations.hasMoreElements() == true)
                {
                    Ogre::AnimationState* state = animations.getNext();

                    if (change == true)
                    {
                        state->setEnabled(true);
                        state->setLoop(true);
                        //m_EntityState.SetText("Model: " + m_Entity->getName() + ": " + state->getAnimationName());
                        break;
                    }
                    if (state->getEnabled() == true && animations.hasMoreElements() != false)
                    {
                        state->setEnabled(false);
                        state->setLoop(false);
                        change = true;
                    }
                }
            }
        }
    }
    else if (event.type == ET_KEY_PRESS && event.param1 == OIS::KC_UP)
    {
        bool change = false;
        if (m_Entity != NULL && m_Entity->getAllAnimationStates() != NULL)
        {
            Ogre::AnimationStateIterator animations = m_Entity->getAllAnimationStates()->getAnimationStateIterator();

            Ogre::AnimationState* old_state;
            Ogre::AnimationState* new_state = animations.getNext();

            while (animations.hasMoreElements() == true)
            {
                old_state = new_state;
                new_state = animations.getNext();

                if (new_state->getEnabled() == true)
                {
                    new_state->setEnabled(false);
                    new_state->setLoop(false);
                    old_state->setEnabled(true);
                    old_state->setLoop(true);
                    //m_EntityState.SetText("Model: " + m_Entity->getName() + ": " + old_state->getAnimationName());
                }
            }
        }
    }
}




void
ViewerModule::Update()
{
    float delta_time = Timer::getSingleton().GetGameTimeDelta();

    if (m_Entity != NULL && m_Entity->getAllAnimationStates() != NULL)
    {
        Ogre::AnimationStateIterator animations = m_Entity->getAllAnimationStates()->getAnimationStateIterator();

        while (animations.hasMoreElements() == true)
        {
            Ogre::AnimationState* state = animations.getNext();

            if (state->getEnabled() == true)
            {
                state->addTime(delta_time);
            }
        }
    }

    //m_ParticleSystem->Update(delta_time);
}



void
ViewerModule::PlayAnimation(const Ogre::String& name)
{
    if (m_Entity != NULL)
    {
        Ogre::String info_text = "Model: " + m_Entity->getName();

        if (m_Entity->getAllAnimationStates() != NULL && m_Entity->getAllAnimationStates()->hasAnimationState(name))
        {
            Ogre::AnimationStateIterator animations = m_Entity->getAllAnimationStates()->getAnimationStateIterator();
            while (animations.hasMoreElements() == true)
            {
                Ogre::AnimationState* state = animations.getNext();
                if (state->getEnabled() == true)
                {
                    state->setEnabled(false);
                    state->setLoop(false);
                }
            }

            Ogre::AnimationState* animation = m_Entity->getAnimationState(name);
            animation->setEnabled(true);
            animation->setLoop(true);

            info_text += ": " + name;
        }
        else
        {
            Ogre::LogManager::getSingletonPtr()->logMessage("[ERROR] ViewerModule: animation with name '" + name + "' doesn't exist in model '" + m_Entity->getName() + "'.");
        }

        //m_EntityState.SetText(info_text);
    }
}



void
ViewerModule::Clear()
{
    if (m_Entity != NULL)
    {
        Ogre::Root::getSingleton().getSceneManager("Scene")->destroyEntity(m_Entity);
        m_Entity = NULL;
    }
    if (m_Walkmesh != NULL)
    {
        delete m_Walkmesh;
        m_Walkmesh = NULL;
    }

    m_SceneNode->removeAndDestroyAllChildren();
}



void
ViewerModule::SetModelToLoad( const Ogre::String& name )
{
    Clear();

    if( Ogre::ResourceGroupManager::getSingleton().resourceExists( "Game", name ) == true)
    {
        m_Entity = Ogre::Root::getSingleton().getSceneManager( "Scene" )->createEntity( name, name, "Game" );
        //m_Entity->setDisplaySkeleton( true );
        //m_EntityState.SetText( "Model: '" + name + "': " );
        PlayAnimation( "idle" );
        m_SceneNode->attachObject( m_Entity );
        //m_SceneNode->showBoundingBox( true );
    }
    else
    {
        m_Entity = Ogre::Root::getSingleton().getSceneManager( "Scene" )->createEntity( Ogre::SceneManager::PT_CUBE );
        //m_EntityState.SetText( "Model: '" + name + "'" );
        m_SceneNode->attachObject( m_Entity );
    }
}



void
ViewerModule::SetWalkmeshToLoad( const Ogre::String& name )
{
    Clear();

    XmlMapsFile xml( "./data/game_data/maps.xml" );
    Ogre::String file_name = xml.GetMapFileNameByName( name );

    XmlMapFile xml_map( "./data/" + file_name );
    Ogre::String walkmesh_file_name = xml_map.GetWalkmeshFileName();

    if( walkmesh_file_name != "" )
    {
        XmlWalkmeshFile walkmesh_file( "./data/" + walkmesh_file_name );
        m_Walkmesh = new Walkmesh();
        walkmesh_file.Load( m_Walkmesh );
        //m_SceneNode->attachObject( m_Walkmesh );
        //m_Walkmesh->setVisible( true );
    }
}
