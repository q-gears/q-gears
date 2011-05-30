// $Id$

#include <Ogre.h>
#include <OIS/OIS.h>

#include "Main.h"
#include "core/Configuration.h"
#include "core/Console.h"
#include "core/DisplayFrameListner.h"
#include "core/ModuleManager.h"
#include "core/TextManager.h"
//#include "core/sound/SoundEngine.h"
#include "game/GameState.h"



QG_STATE  g_ApplicationState;



int
main(int argc, char *argv[])
{
    // init configuration first cause it doesn't need anything but required for all others
    Configuration* config = new Configuration();



    // init ogre part
    Ogre::Root*         root;
    Ogre::RenderWindow* window;
    Ogre::SceneManager* scene_manager;
    Ogre::Camera*       camera;
    Ogre::Viewport*     viewport;

    // init root early
    root = new Ogre::Root("plugins.cfg", "plugins_video.cfg", "qgears.log");

    if (root->restoreConfig() == true || root->showConfigDialog() == true)
    {
        window = root->initialise(true, QG_VERSION_NAME);
    }
    else
    {
        return 0;
    }

    // init this early cause other moduls may need resource
    Ogre::ConfigFile cf;
    cf.load("resources.cfg");

    // Go through all sections & settings in the file
    Ogre::ConfigFile::SectionIterator seci = cf.getSectionIterator();

    Ogre::String secName, typeName, archName;
    while (seci.hasMoreElements())
    {
        secName = seci.peekNextKey();
        Ogre::ConfigFile::SettingsMultiMap* settings = seci.getNext();
        Ogre::ConfigFile::SettingsMultiMap::iterator i;

        if (secName == "Root")
        {
            i = settings->begin();
            config->SetFileRoot(i->second);
            continue;
        }

        for (i = settings->begin(); i != settings->end(); ++i)
        {
            typeName = i->first;
            archName = i->second;
            Ogre::ResourceGroupManager::getSingleton().addResourceLocation(archName, typeName, secName);
        }
    }

    Ogre::ResourceGroupManager::getSingleton().initialiseAllResourceGroups();

    // set scene camera and viewport for other moduls
    scene_manager = root->createSceneManager(Ogre::ST_GENERIC, "Scene");
    scene_manager->setAmbientLight(Ogre::ColourValue(1.0, 1.0, 1.0));

    camera = scene_manager->createCamera("Camera");
    camera->setNearClipDistance(5);

    viewport = window->addViewport(camera, 0);
    viewport->setBackgroundColour(Ogre::ColourValue(0, 0, 0));
    camera->setAspectRatio(Ogre::Real(viewport->getActualWidth()) / Ogre::Real(viewport->getActualHeight()));




    // init sound manager
    //SoundEngine *g_Sound = new SoundEngine();

    // test playback
    //g_Sound->AddSound(1, "data/music/law.ogg", 0.0f);
    //SoundEngine::Handle music_handle = g_Sound->PlaySoundA(1);



    // create console earlier than DisplayFrameListener cause it can fire event to console
    Console* g_Console = new Console();



    // set base listner for usual game moduls
    DisplayFrameListener* frame_listener = new DisplayFrameListener(window);
    root->addFrameListener(frame_listener);



    // init game moduls
    g_ModuleManager = new ModuleManager();
    g_GameState = new GameState();
    g_TextManager = new TextManager();



    // run application cycle
    g_ApplicationState = QG_GAME;
    Ogre::Root::getSingleton().startRendering();



    // delete game moduls first to stop the game process
    delete g_TextManager;
    delete g_GameState;
    delete g_ModuleManager;



    // system moduls
    // we must remove this first cause this can fire event to console
    root->removeFrameListener(frame_listener);
    delete frame_listener;



    delete g_Console;



    //delete g_Sound;



    delete root;



    delete config;



    return 0;
}
