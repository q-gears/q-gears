#include <OgreEntity.h>
#include <OgreRoot.h>

#include "core/EntityModel.h"
#include "core/Logger.h"
#include "core/Timer.h"


EntityModel::EntityModel(const Ogre::String& name, const Ogre::String file_name, Ogre::SceneNode* node):
    Entity(name, node),
    m_AnimationCurrent(nullptr)
{
    Ogre::SceneManager* scene_manager;
    scene_manager = Ogre::Root::getSingleton().getSceneManager("Scene");
    m_Model = scene_manager->createEntity(m_Name, file_name);
    m_Model->setVisible(true);

    PlayAnimation(m_AnimationDefault, Entity::AUTO_ANIMATION, Entity::PLAY_LOOPED, 0, -1);

    m_ModelNode->attachObject(m_Model);
}


EntityModel::~EntityModel()
{
    Ogre::Root::getSingleton().getSceneManager("Scene")->destroyEntity(m_Model);
}


void
EntityModel::Update()
{
    if(m_AnimationAutoPlay == true)
    {
        UpdateAnimation(Timer::getSingleton().GetGameTimeDelta());
    }

    Entity::Update();
}


void
EntityModel::SetVisible(const bool visible)
{
    m_Model->setVisible(visible);
}


bool
EntityModel::IsVisible() const
{
    return m_Model->isVisible();
}


void
EntityModel::PlayAnimation(const Ogre::String& animation, Entity::AnimationState state, Entity::AnimationPlayType play_type, const float start, const float end)
{
    if(m_AnimationCurrent != nullptr)
    {
        m_AnimationCurrent->setEnabled(false);
    }

    if(m_Model->getAllAnimationStates()->hasAnimationState(animation) == true)
    {
        m_AnimationCurrentName = animation;
        m_AnimationCurrent = m_Model->getAnimationState(animation);
        m_AnimationCurrent->setLoop((play_type == Entity::PLAY_LOOPED) ? true : false);
        m_AnimationCurrent->setEnabled(true);
        m_AnimationCurrent->setTimePosition((start == -1) ? m_AnimationCurrent->getLength() : start);

        m_AnimationEndTime = (end == -1) ? m_AnimationCurrent->getLength() : end;
        m_AnimationState = state;
        m_AnimationPlayType = play_type;
    }
    else
    {
        // Idle is hard coded to the default animation, so don't spam crazy amounts of errors if its not found.
        if (animation != "Idle")
        {
            LOG_ERROR("Animation '" + animation + "' doesn't exist in model '" + m_Model->getName() + "'.");
        }
    }
}


void
EntityModel::PlayAnimationContinue(const Ogre::String& animation)
{
    if(m_AnimationCurrent == nullptr ||                                                 // if animation isn't played
        (m_Model->getAllAnimationStates()->hasAnimationState(animation) == true && // and we want to play animation that exist (use this to avoid exception)
          (m_AnimationCurrent != m_Model->getAnimationState(animation) ||          // and animation we want is not animation that currently playing
            m_AnimationPlayType != Entity::PLAY_LOOPED)))                                       // or now playing animation we want but it doesn't looped
    {
        PlayAnimation(animation, Entity::AUTO_ANIMATION, Entity::PLAY_LOOPED, 0, -1);
    }
}


void
EntityModel::UpdateAnimation(const float delta)
{
    if(m_AnimationCurrent != nullptr)
    {
        float delta_mod = delta * m_AnimationSpeed;

        bool stop_check = (m_AnimationCurrent->hasEnded() == true) || (m_AnimationCurrent->getTimePosition() + delta_mod >= m_AnimationEndTime);

        if(stop_check == true)
        {
            //LOG_TRIVIAL("Animation finished for entity \"" + m_Name + "\".");
            for(size_t i = 0; i < m_AnimationSync.size(); ++i)
            {
                ScriptManager::getSingleton().ContinueScriptExecution(m_AnimationSync[i]);
            }
            m_AnimationSync.clear();

            if(m_AnimationPlayType == Entity::PLAY_DEFAULT)
            {
                float time = (m_AnimationCurrent->hasEnded() != true) ? m_AnimationCurrent->getTimePosition() : 0;
                PlayAnimation(m_AnimationDefault, Entity::AUTO_ANIMATION, Entity::PLAY_LOOPED, time, -1);
                m_AnimationCurrent->addTime(delta_mod);
            }
            else if(m_AnimationPlayType == Entity::PLAY_LOOPED)
            {
                float time = (m_AnimationCurrent->hasEnded() != true) ? m_AnimationCurrent->getTimePosition() : m_AnimationCurrent->getTimePosition() - m_AnimationCurrent->getLength();
                PlayAnimation(m_AnimationCurrentName, Entity::AUTO_ANIMATION, Entity::PLAY_LOOPED, time, -1);
                m_AnimationCurrent->addTime(delta_mod);
            }
        }
        else
        {
            m_AnimationCurrent->addTime(delta_mod);
        }
    }
}
