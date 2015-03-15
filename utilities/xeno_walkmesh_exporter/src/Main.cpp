// $Id: Main.cpp 147 2007-02-24 06:13:17Z super_gb $

#include <Ogre.h>
#include <OIS/OIS.h>
#include <stdio.h>
#include <iostream>

#include "Define.h"
#include "Main.h"
#include "common/TypeDefine.h"
#include "common/filesystem/GameFileSystem.h"
#include "common/filesystem/RealFileSystem.h"
#include "common/utilites/Logger.h"
#include "common/utilites/StdString.h"
#include "common/utilites/Utilites.h"

#include "core/input/InputFilter.h"

#include "game/field/Walkmesh.h"
#include "game/field/WalkmeshFile.h"

Uint8 state;



class DisplayFrameListener : public Ogre::FrameListener, public Ogre::WindowEventListener, public OIS::KeyListener, public OIS::MouseListener
{
public:
    // Constructor takes a RenderWindow because it uses that to determine input context
    DisplayFrameListener(Ogre::RenderWindow* win):
        m_Window(win),
        m_InputManager(0),
        m_Keyboard(0),

        m_CameraFreeRotate(false)
    {
        using namespace OIS;

        Ogre::LogManager::getSingletonPtr()->logMessage("*** Initializing OIS ***");
        ParamList pl;
        size_t windowHnd = 0;
        std::ostringstream windowHndStr;

        win->getCustomAttribute("WINDOW", &windowHnd);
        windowHndStr << windowHnd;
        pl.insert(std::make_pair(std::string("WINDOW"), windowHndStr.str()));

        m_InputManager = InputManager::createInputSystem(pl);

        m_Keyboard = static_cast<Keyboard*>(m_InputManager->createInputObject(OISKeyboard, true));
        m_Keyboard->setEventCallback(this);

        m_Mouse = static_cast<OIS::Mouse*>(m_InputManager->createInputObject(OIS::OISMouse, true));
        m_Mouse->setEventCallback(this);

        //Register as a Window listener
        Ogre::WindowEventUtilities::addWindowEventListener(m_Window, this);
    }

    virtual
    ~DisplayFrameListener(void)
    {
        m_InputManager->destroyInputObject(m_Keyboard);
        m_InputManager->destroyInputObject(m_Mouse);

        OIS::InputManager::destroyInputSystem(m_InputManager);

        //Remove ourself as a Window listener
        Ogre::WindowEventUtilities::removeWindowEventListener(m_Window, this);
        windowClosed(m_Window);
    }

    //Unattach OIS before window shutdown (very important under Linux)
    virtual void
    windowClosed(Ogre::RenderWindow* rw)
    {
        state = EXIT;
    }

    bool
    frameStarted(const Ogre::FrameEvent& evt)
    {
        if (state == EXIT)
        {
            return false;
        }

        if (m_Keyboard)
        {
            m_Keyboard->capture();
        }

        if (m_Mouse)
        {
            m_Mouse->capture();
        }

        Ogre::SceneManager* scene_manager;
        scene_manager = Ogre::Root::getSingleton().getSceneManager("Scene");

        m_InputFilter.Update();

        static InputEventArray input_event_array;
        input_event_array.clear();
        m_InputFilter.GetInputEvents(input_event_array);

        for (size_t i = 0; i < input_event_array.size(); ++i)
        {
            if (input_event_array[i].name == "quit" && input_event_array[i].type == IE_PRESSED)
            {
                Ogre::LogManager::getSingletonPtr()->logMessage("Quit Pressed");
                state = EXIT;
                continue;
            }

            if (input_event_array[i].name == "camera_forward" && (input_event_array[i].type == IE_PRESSED || input_event_array[i].type == IE_REPEATED))
            {
                scene_manager->getCamera("Camera")->moveRelative(Ogre::Vector3( 0, 0, -2));
            }
            if (input_event_array[i].name == "camera_left" && (input_event_array[i].type == IE_PRESSED || input_event_array[i].type == IE_REPEATED))
            {
                scene_manager->getCamera("Camera")->moveRelative(Ogre::Vector3(-2, 0,  0));
            }
            if (input_event_array[i].name == "camera_backward" && (input_event_array[i].type == IE_PRESSED || input_event_array[i].type == IE_REPEATED))
            {
                scene_manager->getCamera("Camera")->moveRelative(Ogre::Vector3( 0, 0,  2));
            }
            if (input_event_array[i].name == "camera_right" && (input_event_array[i].type == IE_PRESSED || input_event_array[i].type == IE_REPEATED))
            {
                scene_manager->getCamera("Camera")->moveRelative(Ogre::Vector3( 2, 0,  0));
            }

            if (input_event_array[i].name == "camera_rotate"  && input_event_array[i].type == IE_PRESSED)
            {
                m_CameraFreeRotate = true;
            }
            else if (input_event_array[i].name == "camera_rotate"  && input_event_array[i].type == IE_RELEASED)
            {
                m_CameraFreeRotate = false;
            }

            if (m_CameraFreeRotate && input_event_array[i].name == "mouse_move")
            {
                scene_manager->getCamera("Camera")->rotate(Ogre::Vector3::UNIT_Y, Ogre::Radian(Ogre::Degree(input_event_array[i].x * 0.13f)));
                scene_manager->getCamera("Camera")->pitch(Ogre::Degree(-input_event_array[i].y * 0.13f));
            }


        }

        return true;
    }

    // KeyListener
    bool
    keyPressed(const OIS::KeyEvent& e)
    {
        m_InputFilter.ButtonPressed(e.key, true);

        return true;
    }

    bool
    keyReleased(const OIS::KeyEvent& e)
    {
        m_InputFilter.ButtonPressed(e.key, false);

        return true;
    }

    bool
    mouseMoved(const OIS::MouseEvent &e)
    {
        m_InputFilter.MouseMoved(e.state.X.rel, e.state.Y.rel);

        return true;
    }

    bool
    mousePressed(const OIS::MouseEvent &e, OIS::MouseButtonID id)
    {
        m_InputFilter.ButtonPressed(id + 256, true);

        return true;
    }

    bool
    mouseReleased(const OIS::MouseEvent &e, OIS::MouseButtonID id)
    {
        m_InputFilter.ButtonPressed(id + 256, false);

        return true;
    }

protected:
    Ogre::RenderWindow* m_Window;

    InputFilter         m_InputFilter;

    //OIS Input devices
    OIS::InputManager*  m_InputManager;
    OIS::Keyboard*      m_Keyboard;
    OIS::Mouse*         m_Mouse;

    bool          m_CameraFreeRotate;
};



int
main(int argc, char *argv[])
{
    Ogre::Root*         root;
    Ogre::RenderWindow* window;
    Ogre::SceneManager* scene_manager;
    Ogre::Camera*       camera;
    Ogre::Viewport*     viewport;

    root = new Ogre::Root("plugins.cfg", "q-gears.cfg", "ogre q-gears.log");

    if (root->restoreConfig() == true || root->showConfigDialog() == true)
    {
        window = root->initialise(true, "FFVII Model Exporter 0.00 alpha3");
    }
    else
    {
        return 0;
    }

    DisplayFrameListener* frame_listener = new DisplayFrameListener(window);
    root->addFrameListener(frame_listener);

    scene_manager = root->createSceneManager(Ogre::ST_GENERIC, "Scene");
    scene_manager->setAmbientLight(Ogre::ColourValue(1.0, 1.0, 1.0));

    camera = scene_manager->createCamera("Camera");
    camera->setNearClipDistance(5);

    viewport = window->addViewport(camera);
    viewport->setBackgroundColour(Ogre::ColourValue(0, 0, 0));
    camera->setAspectRatio(Ogre::Real(viewport->getActualWidth()) / Ogre::Real(viewport->getActualHeight()));

    Ogre::ResourceGroupManager::getSingleton().addResourceLocation("./data/", "FileSystem", "General");
    Ogre::ResourceGroupManager::getSingleton().addResourceLocation("./data/OgreCore.zip", "Zip", "Bootstrap");
    Ogre::ResourceGroupManager::getSingleton().initialiseAllResourceGroups();



    REALFILESYSTEM   = new RealFileSystem();
    LOGGER           = new Logger(DEFAULT_LOG, true, true);
    LOGGER->Log(LOGGER_ERROR, "ModuleManager created.");



    GAMEFILESYSTEM = new GameFileSystem();
    state = GAME;



    scene_manager->clearScene();
    scene_manager->setAmbientLight(Ogre::ColourValue(1.0, 1.0, 1.0));



    camera        = scene_manager->getCamera("Camera");
    camera->setPosition(300, -500, 300);
    camera->lookAt(0, 0, 0);



    Walkmesh* walkmesh = new Walkmesh();
    WalkmeshFile* file = new WalkmeshFile("field/1_walkmesh");
    file->GetWalkmesh(walkmesh);
    delete file;

    walkmesh->SetUpWalkmesh();
    walkmesh->setVisible(true);
    Ogre::SceneNode* node = Ogre::Root::getSingleton().getSceneManager("Scene")->getRootSceneNode()->createChildSceneNode();
    node->attachObject(walkmesh);



    Ogre::Root::getSingleton().startRendering();



    LOGGER->Log(LOGGER_INFO, "===================== Stop the game!!!");



    delete GAMEFILESYSTEM;



    SAFE_DELETE(LOGGER)
    SAFE_DELETE(REALFILESYSTEM)

    delete root;
    delete frame_listener;

    return 0;
}
