#include <OgreStringConverter.h>

#include "QGearsGameState.h"
#include "core/CameraManager.h"
#include "core/ConfigVar.h"
#include "core/Console.h"
#include "core/DebugDraw.h"
#include "core/EntityManager.h"
#include "core/GameFrameListner.h"
#include "core/InputManager.h"
#include "core/Logger.h"
#include "core/ScriptManager.h"
#include "core/Timer.h"
#include "core/UiManager.h"
#include "core/DialogsManager.h"


ConfigVar cv_debug_fps("debug_fps", "Debug FPS", "false");


GameFrameListener::GameFrameListener(Ogre::RenderWindow* win):
    m_Window(win),

    m_InputManager(0),
    m_Keyboard(0)
{
    OIS::ParamList pl;
    size_t windowHnd = 0;
    std::ostringstream windowHndStr;

    win->getCustomAttribute("WINDOW", &windowHnd);
    windowHndStr << windowHnd;
    pl.insert(std::make_pair(std::string("WINDOW"), windowHndStr.str()));

#if defined __WIN32__
    pl.insert(std::make_pair(std::string("w32_mouse"), std::string("DISCL_FOREGROUND")));
    pl.insert(std::make_pair(std::string("w32_mouse"), std::string("DISCL_NONEXCLUSIVE")));
#else
    pl.insert(std::make_pair(std::string("x11_mouse_grab"), std::string("false")));
    pl.insert(std::make_pair(std::string("x11_mouse_hide"), std::string("false")));
   // pl.insert(std::make_pair(std::string("x11_keyboard_grab"), std::string("false")));
#endif

    m_InputManager = OIS::InputManager::createInputSystem(pl);

    m_Keyboard = static_cast< OIS::Keyboard* >(m_InputManager->createInputObject(OIS::OISKeyboard, true));
    m_Keyboard->setEventCallback(this);

    m_Mouse = static_cast< OIS::Mouse* >(m_InputManager->createInputObject(OIS::OISMouse, true));
    m_Mouse->setEventCallback(this);
    windowResized(m_Window);

    //Register as a Window listener
    Ogre::WindowEventUtilities::addWindowEventListener(m_Window, this);
}


GameFrameListener::~GameFrameListener()
{
    m_InputManager->destroyInputObject(m_Keyboard);
    m_InputManager->destroyInputObject(m_Mouse);

    OIS::InputManager::destroyInputSystem(m_InputManager);

    //Remove ourself as a Window listener
    Ogre::WindowEventUtilities::removeWindowEventListener(m_Window, this);
    windowClosed(m_Window);
}


bool
GameFrameListener::frameStarted(const Ogre::FrameEvent& evt)
{
    Timer::getSingleton().AddTime(evt.timeSinceLastFrame);

    if(QGears::g_ApplicationState == QGears::G_EXIT)
    {
        return false;
    }

    if(m_Keyboard)
    {
       m_Keyboard->capture();
    }

    if(m_Mouse)
    {
       m_Mouse->capture();
    }

    InputManager::getSingleton().Update();

    static InputEventArray input_event_array;
    input_event_array.clear();

    InputManager::getSingleton().GetInputEvents(input_event_array);

    bool console_active = Console::getSingleton().IsVisible();

    for(size_t i = 0; i < input_event_array.size(); ++i)
    {
        Console::getSingleton().Input(input_event_array[ i ]);

        if(console_active != true)
        {
            EntityManager::getSingleton().Input(input_event_array[ i ]);
            DialogsManager::getSingleton().Input( input_event_array[ i ] );
            ScriptManager::getSingleton().Input(input_event_array[ i ]);
            CameraManager::getSingleton().Input(input_event_array[ i ], evt.timeSinceLastFrame);
        }
    }

    Console::getSingleton().Update();

    ScriptManager::getSingleton().Update(ScriptManager::SYSTEM);
    UiManager::getSingleton().Update();
    CameraManager::getSingleton().Update();
    EntityManager::getSingleton().Update();
    DialogsManager::getSingleton().Update();

    return true;
}


bool
GameFrameListener::frameEnded(const Ogre::FrameEvent& evt)
{
    if(cv_debug_fps.GetB() == true)
    {
        const Ogre::RenderTarget::FrameStats& stats = m_Window->getStatistics();
        DEBUG_DRAW.SetTextAlignment(DEBUG_DRAW.LEFT);
        DEBUG_DRAW.SetScreenSpace(true);
        DEBUG_DRAW.SetColour(Ogre::ColourValue(1, 1, 1, 1));
        DEBUG_DRAW.Text(10, 10, "Current FPS:" + Ogre::StringConverter::toString(stats.lastFPS));
    }

    return true;
}


void
GameFrameListener::windowMoved(Ogre::RenderWindow* rw)
{
}


void
GameFrameListener::windowResized(Ogre::RenderWindow *rw)
{
    if(m_Mouse)
    {
        const OIS::MouseState& ms = m_Mouse->getMouseState();
        ms.width = (int)rw->getWidth();
        ms.height = (int)rw->getHeight();
    }

    Console::getSingleton().OnResize();
    UiManager::getSingleton().OnResize();
    CameraManager::getSingleton().OnResize();
    EntityManager::getSingleton().OnResize();
}


void
GameFrameListener::windowClosed(Ogre::RenderWindow* rw)
{
    QGears::g_ApplicationState = QGears::G_EXIT;
}


void
GameFrameListener::windowFocusChange(Ogre::RenderWindow* rw)
{
}


bool
GameFrameListener::keyPressed(const OIS::KeyEvent& event)
{
    InputManager::getSingleton().ButtonPressed(event.key, event.text, true);

    return true;
}


bool
GameFrameListener::keyReleased(const OIS::KeyEvent& event)
{
    InputManager::getSingleton().ButtonPressed(event.key, event.text, false);

    return true;
}


bool
GameFrameListener::mouseMoved(const OIS::MouseEvent& e)
{
    if(e.state.Z.rel != 0)
    {
        InputManager::getSingleton().MouseScrolled(e.state.Z.rel);
    }
    else
    {
        InputManager::getSingleton().MouseMoved(e.state.X.rel, e.state.Y.rel);
    }

    return true;
}


bool
GameFrameListener::mousePressed(const OIS::MouseEvent& e, OIS::MouseButtonID id)
{
    InputManager::getSingleton().MousePressed(id, true);

    return true;
}


bool
GameFrameListener::mouseReleased(const OIS::MouseEvent& e, OIS::MouseButtonID id)
{
    InputManager::getSingleton().MousePressed(id, false);

    return true;
}
