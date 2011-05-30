// $Id$

#include <Ogre.h>
#include "Math.h"
#include "Model.h"
#include "../Main.h"



Model::Model(const Ogre::String& name, const Ogre::String file_name, Ogre::SceneNode* node, FieldScriptManager* script, Walkmesh* walkmesh):
    Entity(name, node, script, walkmesh),

    m_AnimationCurrent(NULL)
{
    Ogre::SceneManager* scene_manager;
    scene_manager = Ogre::Root::getSingleton().getSceneManager("Scene");
    m_Model = scene_manager->createEntity(m_Name, file_name);
    m_Model->setVisible(false);

    m_ModelNode->attachObject(m_Model);

    // start anim
    this->SetAnimationState(m_AnimationDefault, 0, -1, m_AnimationDefaultSpeed, PLAY_DEFAULT);

    Ogre::LogManager::getSingletonPtr()->logMessage("Model created.");
}



Model::~Model(void)
{
    Ogre::SceneManager* scene_manager;
    scene_manager = Ogre::Root::getSingleton().getSceneManager("Scene");
    scene_manager->destroyEntity(m_Model);

    Ogre::LogManager::getSingletonPtr()->logMessage("Model destroyed.");
}



void
Model::Input(const Event& input)
{
    Entity::Input(input);
}



void
Model::Update(const float delta_time)
{
    Entity::Update(delta_time);
}



void
Model::SetVisible(const bool visible)
{
    m_Model->setVisible(visible);
}



const bool
Model::IsVisible(void) const
{
    return m_Model->isVisible();
}



void
Model::AnimationUpdate(const float delta_time)
{
    // if we don't play anything start defaut animation
    if (m_AnimationCurrent == NULL)
    {
        this->SetAnimationState(m_AnimationDefault, 0, -1, m_AnimationDefaultSpeed, PLAY_DEFAULT);
    }

    if (m_AnimationState != STOP)
    {
        bool stop_check = (m_AnimationCurrent->hasEnded() == true) || (m_AnimationCurrent->getTimePosition() + delta_time * m_AnimationSpeedCurrent >= m_AnimationEndTime);

        if (m_AnimationWait == true && stop_check == true)
        {
            m_FieldScriptManager->ContinueEntityScriptExecution(m_ScriptInfo);
            m_AnimationWait = false;
            m_ScriptInfo.entity_id = -1;
        }

        if (m_AnimationState == PLAY_DEFAULT || (stop_check == true && m_AnimationState == PLAY_GO_TO_DEFAULT))
        {
            float time = (m_AnimationCurrent->hasEnded() != true) ? m_AnimationCurrent->getTimePosition() : 0;

            if (delta_time < 0 && m_AnimationCurrent->getTimePosition() == 0)
            {
                time = m_AnimationCurrent->getLength();
            }

            this->SetAnimationState(m_AnimationDefault, time, -1, m_AnimationDefaultSpeed, PLAY_DEFAULT);
            m_AnimationCurrent->addTime(delta_time * m_AnimationSpeedCurrent);
        }
        else if (stop_check != true)
        {
            m_AnimationCurrent->addTime(delta_time * m_AnimationSpeedCurrent);
        }
        else
        {
            m_AnimationState = STOP;
        }
    }
}



bool
Model::SetAnimationState(const Ogre::String& animation, const float start, const float end, const float speed, const ModelAnimation state)
{
    if (m_Model->getAllAnimationStates()->hasAnimationState(animation) == true)
    {
        if (m_AnimationCurrent != NULL)
        {
            m_AnimationCurrent->setEnabled(false);
        }

        m_AnimationCurrentName = animation;
        m_AnimationCurrent = m_Model->getAnimationState(animation);
        m_AnimationCurrent->setLoop(false);
        m_AnimationCurrent->setEnabled(true);
        m_AnimationCurrent->setTimePosition(start);

        m_AnimationSpeedCurrent = speed;
        m_AnimationEndTime = (end == -1) ? m_AnimationCurrent->getLength() : end;

        m_AnimationState = state;
        return true;
    }
    else
    {
        if (m_AnimationCurrent != NULL)
        {
            m_AnimationCurrentName = "";
            m_AnimationCurrent->setEnabled(false);
            m_AnimationCurrent = NULL;
            m_AnimationState = STOP;
        }

        Ogre::LogManager::getSingletonPtr()->logMessage("[ERROR] Animation '" + animation + "' doesn't exist in model '" + m_Model->getName() + "'.");
        return false;
    }
}



void
Model::PlayAnimationLooped(const Ogre::String& animation, const float relative_speed)
{
    float time = 0;
    if (m_AnimationCurrent != NULL && m_Model->getAllAnimationStates()->hasAnimationState(animation) && m_AnimationCurrent == m_Model->getAnimationState(animation))
    {
        time = (m_AnimationCurrent->hasEnded() != true) ?
            m_AnimationCurrent->getTimePosition() :
            m_AnimationCurrent->getTimePosition() - m_AnimationCurrent->getLength();
    }

    this->SetAnimationState(animation, time, -1, m_AnimationSpeed * relative_speed, PLAY_GO_TO_DEFAULT);
}
