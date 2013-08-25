#include "Main.h"

#include <Ogre.h>
#include <OIS.h>

#include "../../common/FileSystem.h"
#include "../../common/Logger.h"


#include "SoundParser.h"
#include "engine/SoundManager.h"



int state;



class DisplayFrameListener : public Ogre::FrameListener, public Ogre::WindowEventListener, public OIS::KeyListener
{
public:
    DisplayFrameListener(Ogre::RenderWindow* win):
        m_Window(win),
        m_InputManager(0),
        m_Keyboard(0),
        m_Timer(0)
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

        //Register as a Window listener
        Ogre::WindowEventUtilities::addWindowEventListener(m_Window, this);
    }

    virtual
    ~DisplayFrameListener(void)
    {
        m_InputManager->destroyInputObject(m_Keyboard);

        OIS::InputManager::destroyInputSystem(m_InputManager);

        //Remove ourself as a Window listener
        Ogre::WindowEventUtilities::removeWindowEventListener(m_Window, this);
        windowClosed(m_Window);
    }

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

        //if (m_Timer >= 0.003)
        //{
            //m_Timer = 0;
            SOUND_PARSER->Update();
        //}
        //m_Timer += evt.timeSinceLastFrame;

        SOUNDMAN->Update();

        return true;
    }

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
        }

        return true;
    }

    bool
    keyReleased(const OIS::KeyEvent& e)
    {
        return true;
    }

protected:
    Ogre::RenderWindow* m_Window;

    OIS::InputManager*  m_InputManager;
    OIS::Keyboard*      m_Keyboard;

    float               m_Timer;
};



int
main( int argc, char *argv[] )
{
    Ogre::Root*         root;
    Ogre::RenderWindow* window;

    root = new Ogre::Root( "", "" );
#ifndef _DEBUG
    root->loadPlugin( "RenderSystem_GL.dll" );
#else
    root->loadPlugin( "RenderSystem_GL_d.dll" );
#endif
    root->setRenderSystem( root->getAvailableRenderers()[ 0 ] );
    root->initialise( false );
    Ogre::NameValuePairList misc;
    misc[ "title" ] = "Xenogears SoundDumper";
    window = root->createRenderWindow( "QGearsWindow", 800, 600, false, &misc );



    FILESYSTEM = new FileSystem();
    LOGGER = new Logger( "game.log" );

    state = GAME;



    DisplayFrameListener* frame_listener = new DisplayFrameListener( window );
    root->addFrameListener( frame_listener );

    Ogre::SceneManager* scene_manager = root->createSceneManager( Ogre::ST_GENERIC, "Scene" );
    scene_manager->setAmbientLight( Ogre::ColourValue( 1.0, 1.0, 1.0 ) );

    Ogre::Camera* camera = scene_manager->createCamera( "Camera" );
    camera->setNearClipDistance( 5 );

    Ogre::Viewport* viewport = window->addViewport( camera );
    viewport->setBackgroundColour( Ogre::ColourValue( 0, 0, 0 ) );
    camera->setAspectRatio( Ogre::Real( viewport->getActualWidth()) / Ogre::Real( viewport->getActualHeight() ) );



    SOUNDMAN = new SoundManager();
    SOUND_PARSER = new SoundParser();



    Ogre::Root::getSingleton().startRendering();



    delete SOUND_PARSER;
    delete SOUNDMAN;



    delete root;
    delete frame_listener;

    delete FILESYSTEM;
    delete LOGGER;

    return 0;
}

