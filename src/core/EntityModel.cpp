#include "EntityModel.h"

#include <OgreEntity.h>
#include <OgreRoot.h>

#include "../core/Logger.h"
#include "../core/Timer.h"



EntityModel::EntityModel( const Ogre::String& name, const Ogre::String file_name, Ogre::SceneNode* node ):
    Entity( name, node ),
    m_AnimationCurrent( NULL )
{
    Ogre::SceneManager* scene_manager;
    scene_manager = Ogre::Root::getSingleton().getSceneManager( "Scene" );
    m_Model = scene_manager->createEntity( m_Name, file_name );
    m_Model->setVisible( true );

    PlayAnimation( m_AnimationDefault, DEFAULT, 0, -1 );

    m_ModelNode->attachObject( m_Model );
}



EntityModel::~EntityModel()
{
    Ogre::Root::getSingleton().getSceneManager( "Scene" )->destroyEntity( m_Model );
}



void
EntityModel::Update()
{
    if( m_AnimationCurrent != NULL )
    {
        float delta_time = Timer::getSingleton().GetGameTimeDelta();

        bool stop_check = ( m_AnimationCurrent->hasEnded() == true ) || ( m_AnimationCurrent->getTimePosition() + delta_time >= m_AnimationEndTime );

        if( stop_check == true )
        {
            //LOG_TRIVIAL( "Animation finished for entity \"" + m_Name + "\"." );
            for( int i = 0; i < m_AnimationSync.size(); ++i)
            {
                ScriptManager::getSingleton().ContinueScriptExecution( m_AnimationSync[ i ] );
            }
            m_AnimationSync.clear();

            if( m_AnimationState == DEFAULT )
            {
                float time = ( m_AnimationCurrent->hasEnded() != true ) ? m_AnimationCurrent->getTimePosition() : 0;

                if( delta_time < 0 && m_AnimationCurrent->getTimePosition() == 0 )
                {
                    time = m_AnimationCurrent->getLength();
                }

                PlayAnimation( m_AnimationDefault, DEFAULT, time, -1 );

                m_AnimationCurrent->addTime( delta_time );
            }
        }
        else
        {
            m_AnimationCurrent->addTime( delta_time );
        }
    }



    Entity::Update();
}



void
EntityModel::SetVisible( const bool visible )
{
    m_Model->setVisible( visible );
}



const bool
EntityModel::IsVisible() const
{
    return m_Model->isVisible();
}



void
EntityModel::PlayAnimation( const Ogre::String& animation, EntityAnimation state, const float start, const float end )
{
    if( m_AnimationCurrent != NULL )
    {
        m_AnimationCurrent->setEnabled( false );
    }

    if( m_Model->getAllAnimationStates()->hasAnimationState( animation ) == true )
    {
        m_AnimationCurrentName = animation;
        m_AnimationCurrent = m_Model->getAnimationState( animation );
        m_AnimationCurrent->setLoop( false );
        m_AnimationCurrent->setEnabled( true );
        m_AnimationCurrent->setTimePosition( start );

        m_AnimationEndTime = (end == -1) ? m_AnimationCurrent->getLength() : end;
        m_AnimationState = state;
    }
    else
    {
        LOG_ERROR( "Animation '" + animation + "' doesn't exist in model '" + m_Model->getName() + "'." );
    }
}
