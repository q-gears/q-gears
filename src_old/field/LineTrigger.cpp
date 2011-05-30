// $Id$

#include "LineTrigger.h"



LineTrigger::LineTrigger(const Ogre::String& name, Ogre::SceneNode* node, const Ogre::Vector3& point1, const Ogre::Vector3& point2):
    m_SceneNode(node),

    m_Name(name),

    m_Enabled(false),
    m_InLine(false),

    m_Point1(point1),
    m_Point2(point2)
{
    m_LineTriggerLine = new LineTriggerLine(point1, point2);
    m_LineTriggerLine->setMaterial("field/line_trigger/off");
    Ogre::SceneNode* c_node = m_SceneNode->createChildSceneNode();
    c_node->attachObject(m_LineTriggerLine);
}



LineTrigger::~LineTrigger(void)
{
    delete m_LineTriggerLine;
}



void
LineTrigger::Input(const Event& input)
{
}



void
LineTrigger::Update(const float delta_time)
{
}



void
LineTrigger::ShowDebug(const bool show)
{
    m_LineTriggerLine->setVisible(show);
}



const Ogre::String
LineTrigger::GetName() const
{
    return m_Name;
}



void
LineTrigger::SetEnabled(const bool enabled)
{
    m_Enabled = enabled;

    if (m_Enabled == true)
    {
        m_LineTriggerLine->setMaterial("field/line_trigger/on");
    }
    else
    {
        m_InLine = false;
        m_LineTriggerLine->setMaterial("field/line_trigger/off");
    }
}



const bool
LineTrigger::IsEnabled() const
{
    return m_Enabled;
}



void
LineTrigger::SetInLine(const bool in_line)
{
    m_InLine = in_line;

    if (m_InLine == true)
    {
        m_LineTriggerLine->setMaterial("field/line_trigger/active");
    }
    else
    {
        m_LineTriggerLine->setMaterial("field/line_trigger/on");
    }
}



const bool
LineTrigger::IsInLine() const
{
    return m_InLine;
}



void
LineTrigger::SetCanBeActivated(const bool can_be_activated)
{
    m_CanBeActivated = can_be_activated;
}



const bool
LineTrigger::IsCanBeActivated() const
{
    return m_CanBeActivated;
}



void
LineTrigger::SetPoints(const Ogre::Vector3& point1, const Ogre::Vector3& point2)
{
    m_Point1 = point1;
    m_Point2 = point2;
    m_LineTriggerLine->SetPoints(point1, point2);
}



const Ogre::Vector3&
LineTrigger::GetPoint1(void) const
{
    return m_Point1;
}



const Ogre::Vector3&
LineTrigger::GetPoint2(void) const
{
    return m_Point2;
}
