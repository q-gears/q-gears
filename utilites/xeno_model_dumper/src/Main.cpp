#include <Ogre.h>
#include <OIS.h>

#include "Main.h"
#include "../../common/FileSystem.h"
#include "../../common/Logger.h"
#include "../../common/OgreGenUtilites.h"

#include "FieldModel.h"
#include "AnimatedModel.h"
#include "ModelFile.h"

std::vector<Ogre::Entity*> entitys;
Ogre::Camera* camera;

int state;



class DisplayFrameListener : public Ogre::FrameListener, public Ogre::WindowEventListener, public OIS::KeyListener, public OIS::MouseListener
{
public:
    // Constructor takes a RenderWindow because it uses that to determine input context
    DisplayFrameListener(Ogre::RenderWindow* win):
        m_Window(win),
        m_InputManager(0),
        m_Keyboard(0),
        m_Mouse(0),
        m_MouseRotate(false),
        m_MouseMoveX(0),
        m_MouseMoveY(0)
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

        m_Keyboard = static_cast<Keyboard*>(m_InputManager->createInputObject(OIS::OISKeyboard, true));
        m_Keyboard->setEventCallback(this);

        m_Mouse = static_cast<OIS::Mouse*>(m_InputManager->createInputObject(OIS::OISMouse, true));
        m_Mouse->setEventCallback(this);

        //Register as a Window listener
        Ogre::WindowEventUtilities::addWindowEventListener(m_Window, this);
    }

    virtual
    ~DisplayFrameListener()
    {
        m_InputManager->destroyInputObject(m_Keyboard);

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

        if (m_Keyboard->isKeyDown(OIS::KC_A))
        {
            camera->moveRelative(Ogre::Vector3(-0.01, 0,  0));
        }
        if (m_Keyboard->isKeyDown(OIS::KC_D))
        {
            camera->moveRelative(Ogre::Vector3( 0.01, 0,  0));
        }
        if (m_Keyboard->isKeyDown(OIS::KC_W))
        {
            camera->moveRelative(Ogre::Vector3( 0, 0, -0.01));
        }
        if (m_Keyboard->isKeyDown(OIS::KC_S))
        {
            camera->moveRelative(Ogre::Vector3( 0, 0,  0.01));
        }
        if (m_MouseRotate == true)
        {
            camera->rotate(Ogre::Vector3::UNIT_Y, Ogre::Radian(Ogre::Degree(-m_MouseMoveX * 0.13)));
            camera->pitch(Ogre::Degree(-m_MouseMoveY * 0.13));
            m_MouseMoveX = 0;
            m_MouseMoveY = 0;
        }

        return true;
    }

    // KeyListener
    bool
    keyPressed(const OIS::KeyEvent& e)
    {
        switch (e.key)
        {
            case OIS::KC_ESCAPE:
            {
                state = EXIT;
            }
            break;

            case OIS::KC_RIGHT:
            {
            }
            break;

            case OIS::KC_LEFT:
            {
            }
            break;

            case OIS::KC_UP:
            {
            }
            break;

            case OIS::KC_DOWN:
            {
            }
            break;
        }

        return true;
    }

    bool
    keyReleased(const OIS::KeyEvent& e)
    {
        return true;
    }

    bool
    mouseMoved(const OIS::MouseEvent& e)
    {
        m_MouseMoveX = e.state.X.rel;
        m_MouseMoveY = e.state.Y.rel;
        return true;
    }

    bool
    mousePressed(const OIS::MouseEvent& e, OIS::MouseButtonID id)
    {
        if (id == OIS::MB_Right)
        {
            m_MouseRotate = true;
        }
        return true;
    }

    bool
    mouseReleased(const OIS::MouseEvent& e, OIS::MouseButtonID id)
    {
        if (id == OIS::MB_Right)
        {
            m_MouseRotate = false;
        }

        return true;
    }

protected:
    Ogre::RenderWindow* m_Window;

    //OIS Input devices
    OIS::InputManager*  m_InputManager;
    OIS::Keyboard*      m_Keyboard;
    OIS::Mouse*         m_Mouse;
    float               m_MouseMoveX;
    float               m_MouseMoveY;
    bool                m_MouseRotate;
};



int
main(int argc, char *argv[])
{
    Ogre::Root*         root;
    Ogre::RenderWindow* window;
    Ogre::SceneManager* scene_manager;
    Ogre::Viewport*     viewport;

    root = new Ogre::Root("plugins.cfg", "q-gears.cfg", "ogre q-gears.log");

    if (root->restoreConfig() == true || root->showConfigDialog() == true)
    {
        window = root->initialise(true, "Xenogears Model Exporter");
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
    camera->setNearClipDistance(0.05);

    viewport = window->addViewport(camera);
    viewport->setBackgroundColour(Ogre::ColourValue(0, 0, 0));
    camera->setAspectRatio(Ogre::Real(viewport->getActualWidth()) / Ogre::Real(viewport->getActualHeight()));

    Ogre::ResourceGroupManager::getSingleton().addResourceLocation("./", "FileSystem", "General");
    Ogre::ResourceGroupManager::getSingleton().addResourceLocation("./exported/", "FileSystem", "General");
    Ogre::ResourceGroupManager::getSingleton().addResourceLocation("./data/OgreCore.zip", "Zip", "Bootstrap");
    Ogre::ResourceGroupManager::getSingleton().initialiseAllResourceGroups();

    scene_manager->clearScene();
    scene_manager->setAmbientLight(Ogre::ColourValue(1.0, 1.0, 1.0));

    scene_manager = Ogre::Root::getSingleton().getSceneManager("Scene");
    camera = scene_manager->getCamera("Camera");
    camera->setPosition(10, 5, 10);
    camera->lookAt(0, 0, 0);



    FILESYSTEM = new FileSystem();
    LOGGER = new Logger("game.txt");

    state = GAME;



    {
        FieldModel model;
        model.Export("data/1500_3.model", "data/1501.texture");
    }

    {
        //AnimatedModel model;
        //model.Export("data/2145.model", "data/2144.animation");
    }

    Ogre::Root::getSingleton().startRendering();



    delete LOGGER;
    delete FILESYSTEM;

    delete root;
    delete frame_listener;

    return 0;
}
