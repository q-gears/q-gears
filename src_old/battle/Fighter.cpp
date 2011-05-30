// $Id$

#include <OgreLogManager.h>
#include <OgreOverlayManager.h>
#include <OgreRoot.h>
#include <OgreStringConverter.h>

#include "BattleScriptManager.h"
#include "Fighter.h"
#include "../Main.h"



Fighter::Fighter(const Ogre::String& name, const Ogre::String& file_name, Ogre::SceneNode* node, BattleScriptManager* script):
    m_ScriptManager(script),

    m_Name(name),

    m_SceneNode(node),

    m_DrawDebug(false),

    m_AnimationCurrent(NULL),
    m_AnimationFighterWaiting(-1)
{
    m_ModelNode = m_SceneNode->createChildSceneNode();

    // debug info
    m_DebugInfoText = new MovableTextArea("DebugBattleFighterText_" + m_Name);
    m_DebugInfoText->setCaption("");
    m_DebugInfoText->setMetricsMode(Ogre::GMM_PIXELS);
    m_DebugInfoText->setPosition(0, 0);
    m_DebugInfoText->setTextAlignment(TextArea::CENTER);
    m_DebugInfoText->setFontName("DebugText");
    m_DebugInfoText->setCharHeight(18);
    //m_DebugInfoText->SetAdditionalHeight(m_Height - 20);
    m_DebugInfoText->Set3DPosition(this->GetPosition());

    m_DebugInfoOverlay = Ogre::OverlayManager::getSingleton().create("DebugBattleFighterOverlay_" + m_Name);
    m_DebugInfoOverlay->setZOrder(QGOO_BATTLE_DEBUG);
    m_DebugInfoOverlay->add2D((Ogre::OverlayContainer*)m_DebugInfoText);
    if (m_DrawDebug == true)
    {
        m_DebugInfoOverlay->show();
    }
    else
    {
        m_DebugInfoOverlay->hide();
    }

    Ogre::SceneManager* scene_manager;
    scene_manager = Ogre::Root::getSingleton().getSceneManager("Scene");
    m_Model = scene_manager->createEntity(m_Name, file_name);
    m_Model->setVisible(true);

    m_ModelNode->attachObject(m_Model);
    //m_ModelNode->setPosition(0, 2000, 0);
    m_ModelNode->pitch(Ogre::Radian(Ogre::Degree(180)));

    Ogre::LogManager::getSingletonPtr()->logMessage("Fighter created.");
}



Fighter::~Fighter(void)
{
    Ogre::SceneManager* scene_manager;
    scene_manager = Ogre::Root::getSingleton().getSceneManager("Scene");
    scene_manager->destroyEntity(m_Model);

    m_DebugInfoOverlay->remove2D((Ogre::OverlayContainer*)m_DebugInfoText);
    delete m_DebugInfoText;

    Ogre::OverlayManager::getSingleton().destroy(m_DebugInfoOverlay);

    m_SceneNode->removeAndDestroyAllChildren();

    Ogre::LogManager::getSingletonPtr()->logMessage("Entity destroyed.");
}



void
Fighter::ShowDebug(const bool show)
{
    m_DrawDebug = show;

    if (show == true)
    {
        m_DebugInfoOverlay->show();
    }
    else
    {
        m_DebugInfoOverlay->hide();
    }
}



void
Fighter::Input(const Event& input)
{
}



void
Fighter::Update(const float delta_time)
{
    if (m_DebugInfoOverlay->isVisible() == true)
    {
        Ogre::String caption;
        caption = this->GetName() + ":\n";
        caption += "hp:" + Ogre::StringConverter::toString(data.current_hp) + "/" + Ogre::StringConverter::toString(data.max_hp) + "\n";
        //caption += "mp:" + Ogre::StringConverter::toString(data.current_mp) + "/" + Ogre::StringConverter::toString(data.max_mp) + "\n";
        //caption += "row:" + Ogre::StringConverter::toString(data.row) + "\n";
        caption += "timer:" + Ogre::StringConverter::toString(data.timer_value) + "\n";

        m_DebugInfoText->setCaption(caption);
        m_DebugInfoText->Set3DPosition(this->GetPosition());
    }



    if (m_AnimationCurrent != NULL)
    {
        if (m_AnimationCurrent->getTimePosition() + delta_time < m_AnimationCurrent->getLength())
        {
            m_AnimationCurrent->addTime(delta_time);
        }
        else if (m_AnimationFighterWaiting != -1)
        {
            m_ScriptManager->ContinueFighterAction(m_AnimationFighterWaiting);
            m_AnimationFighterWaiting = -1;
        }
    }
}



int
Fighter::ScriptPlayAnimation(const char* animation)
{
    if (m_AnimationCurrent != NULL)
    {
        m_AnimationCurrent->setEnabled(false);
    }

    m_AnimationCurrent = m_Model->getAnimationState(animation);
    m_AnimationCurrent->setLoop(false);
    m_AnimationCurrent->setEnabled(true);
    m_AnimationCurrent->setTimePosition(0);

    m_AnimationFighterWaiting = m_ScriptManager->GetCurrentFighter();
    Ogre::LogManager::getSingletonPtr()->logMessage("Play animation '" + Ogre::String(animation) + ". Script '" + Ogre::StringConverter::toString(m_AnimationFighterWaiting) + "' waits. Fighter '" + m_Name + "'");

    return -1;
}



const Ogre::String
Fighter::GetName() const
{
    return m_Name;
}



const Ogre::Vector3
Fighter::GetPosition(void) const
{
    return m_SceneNode->getPosition();
}



void
Fighter::SetPosition(const Ogre::Vector3& position)
{
    m_SceneNode->setPosition(position);
}



void
Fighter::SetDirection(const Ogre::Degree& direction)
{
    float angle = direction.valueDegrees() - Ogre::Math::Floor(direction.valueDegrees() / 360.0f) * 360.0f;

    if (angle < 0)
    {
        angle = 360 + angle;
    }

    Ogre::Quaternion q;
    Ogre::Vector3 vec = Ogre::Vector3::UNIT_Y;
    q.FromAngleAxis(Ogre::Radian(Ogre::Degree(angle)), vec);
    m_SceneNode->setOrientation(q);
}



const Ogre::Degree
Fighter::GetDirection(void) const
{
    Ogre::Quaternion q = m_SceneNode->getOrientation();
    Ogre::Degree temp;
    Ogre::Vector3 vec = Ogre::Vector3::UNIT_Y;
    q.ToAngleAxis(temp, vec);

    return temp;
}
