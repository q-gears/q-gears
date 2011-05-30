// $Id$

#include "InputFilter.h"



InputFilter::InputFilter(void)
{
    // game
    SetInputMap(OIS::KC_SPACE,       "game_assist");
    SetInputMap(OIS::KC_RETURN,      "game_start");
    SetInputMap(OIS::KC_UP,          "game_up");
    SetInputMap(OIS::KC_RIGHT,       "game_right");
    SetInputMap(OIS::KC_DOWN,        "game_down");
    SetInputMap(OIS::KC_LEFT,        "game_left");
    SetInputMap(OIS::KC_HOME,        "game_camera");
    SetInputMap(OIS::KC_PGUP,        "game_target");
    SetInputMap(OIS::KC_PGDOWN,      "game_next");
    SetInputMap(OIS::KC_END,         "game_previous");
    SetInputMap(OIS::KC_S,           "game_menu");
    SetInputMap(OIS::KC_X,           "game_ok");
    SetInputMap(OIS::KC_Z,           "game_cancel");
    SetInputMap(OIS::KC_Z,           "game_run");
    SetInputMap(OIS::KC_A,           "game_switch");

    // debug field
    SetInputMap(OIS::KC_1,           "debug_field_walkmesh");
    SetInputMap(OIS::KC_2,           "debug_field_model");
    SetInputMap(OIS::KC_3,           "debug_field_script");
    SetInputMap(OIS::KC_4,           "debug_field_message");
    SetInputMap(OIS::KC_5,           "debug_field_fade");
    SetInputMap(OIS::KC_6,           "debug_field_encounter");

    // application specific
    SetInputMap(OIS::KC_F11,         "pause");
    SetInputMap(OIS::KC_ESCAPE,      "quit");
    SetInputMap(OIS::KC_GRAVE,       "console");

    // camera
    SetInputMap(OIS::KC_C,           "camera_change");
    SetInputMap(OIS::MB_Right + 256, "camera_rotate");
    SetInputMap(OIS::KC_W,           "camera_forward");
    SetInputMap(OIS::KC_A,           "camera_left");
    SetInputMap(OIS::KC_S,           "camera_backward");
    SetInputMap(OIS::KC_D,           "camera_right");

    Reset();
}



InputFilter::~InputFilter(void)
{
}



void
InputFilter::Reset(void)
{
    for (int button = 0; button < 264; ++button)
    {
        m_ButtonState[button] = false;
    }

    m_EventQueue.clear();
}



void
InputFilter::ButtonPressed(const int button, const bool down)
{
    if (m_ButtonState[button] != down)
    {
        m_ButtonState[button] = down;
        InsertEventsForButton(button, (m_ButtonState[button] == true) ? IE_PRESSED : IE_RELEASED);
    }
}



void
InputFilter::MouseMoved(int x, int y)
{
    m_EventQueue.push_back(InputEvent("mouse_move", IE_MOVED, x, y));
}



void
InputFilter::Update(void)
{
    for (int button = 0; button < 264; ++button)
    {
        if (m_ButtonState[button] == true)
        {
            InsertEventsForButton(button, IE_REPEATED);
        }
    }
}



bool
InputFilter::IsButtonPressed(const int button) const
{
    return m_ButtonState[button];
}



void
InputFilter::GetInputEvents(InputEventArray& input_events)
{
    input_events = m_EventQueue;

    m_EventQueue.clear();
}



void
InputFilter::ClearAllMappings(void)
{
    m_InputMap.clear();
}



void
InputFilter::SetInputMap(const int button, const Ogre::String& name)
{
    Mapping mapping;
    mapping.key  = button;
    mapping.name = name;
    m_InputMap.push_back(mapping);
}



void
InputFilter::InsertEventsForButton(const int button, const InputEventType type)
{
    std::vector<Mapping>::iterator i = m_InputMap.begin();

    for (; i != m_InputMap.end(); ++i)
    {
        //Ogre::LogManager::getSingletonPtr()->logMessage("Check '" + (*i).name + "':" + Ogre::StringConverter::toString(int((*i).key)) + "==" + Ogre::StringConverter::toString((int)button));

        if ((*i).key == button)
        {
            //Ogre::LogManager::getSingletonPtr()->logMessage("Add '" + (*i).name + "' and type '" + Ogre::StringConverter::toString(int(type)) + "'");
            m_EventQueue.push_back(InputEvent((*i).name, type, 0, 0));
        }
    }
}
