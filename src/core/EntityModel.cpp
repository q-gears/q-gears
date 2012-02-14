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

    PlayAnimation( m_AnimationDefault, EA_DEFAULT, 0, -1 );

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
            for( size_t i = 0; i < m_AnimationSync.size(); ++i)
            {
                ScriptManager::getSingleton().ContinueScriptExecution( m_AnimationSync[ i ] );
            }
            m_AnimationSync.clear();

            if( m_AnimationState == EA_DEFAULT )
            {
                float time = ( m_AnimationCurrent->hasEnded() != true ) ? m_AnimationCurrent->getTimePosition() : 0;

                PlayAnimation( m_AnimationDefault, EA_DEFAULT, time, -1 );

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
        m_AnimationCurrent->setTimePosition( ( start == -1 ) ? m_AnimationCurrent->getLength() : start );

        m_AnimationEndTime = ( end == -1 ) ? m_AnimationCurrent->getLength() : end;
        m_AnimationState = state;
    }
    else
    {
        LOG_ERROR( "Animation '" + animation + "' doesn't exist in model '" + m_Model->getName() + "'." );
    }
}



void
EntityModel::PlayAnimationLooped( const Ogre::String& animation )
{
    float time = 0;
    if( m_AnimationCurrent != NULL &&                                               // if some animation is played
        m_Model->getAllAnimationStates()->hasAnimationState( animation ) == true && // and we want to play animation that exist (use this to avoid exception)
        m_AnimationCurrent == m_Model->getAnimationState( animation ) )             // and animation we want is the animation that currently playing
    {
        time = ( m_AnimationCurrent->hasEnded() != true ) ?
            m_AnimationCurrent->getTimePosition() :
            m_AnimationCurrent->getTimePosition() - m_AnimationCurrent->getLength();
    }

    PlayAnimation( animation, EA_DEFAULT, time, -1 );
}
