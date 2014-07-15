#include <OgreRoot.h>
#include <OgreConfigFile.h>
#include <OgreArchiveManager.h>
#include <OIS.h>

#include "QGearsGameState.h"
#include "core/AudioManager.h"
#include "common/QGearsApplication.h"
#include "core/CameraManager.h"
#include "core/ConfigCmdManager.h"
#include "core/ConfigFile.h"
#include "core/ConfigVarManager.h"
#include "core/Console.h"
#include "core/DebugDraw.h"
#include "core/EntityManager.h"
#include "core/GameFrameListner.h"
#include "core/InputManager.h"
#include "core/Logger.h"
#include "core/ScriptManager.h"
#include "core/Timer.h"
#include "core/UiManager.h"
#include "core/particles/ParticleSystemManager.h"

#include "data/QGearsLZSFLevelFileManager.h"
#include "common/make_unique.h"
#include <Overlay/OgreFontManager.h>
#include <Overlay/OgreOverlayManager.h>
#include <Overlay/OgreOverlaySystem.h>
int
main(int argc, char *argv[])
{
    QGears::Application app( argc, argv );
    if( !app.initOgre() ) return 0;

    Ogre::Root         *root( app.getRoot() );
    Ogre::RenderWindow *window( app.getRenderWindow() );
    Ogre::SceneManager *scene_manager( NULL );

    auto timer = std::make_unique<Timer>();
    auto particle_system_manager = std::make_unique<ParticleSystemManager>();

    // set scene camera and viewport for other moduls
    // create this before initialize particle because some of them use scene to create themself
    scene_manager = root->createSceneManager( Ogre::ST_GENERIC, "Scene" );
    scene_manager->setAmbientLight( Ogre::ColourValue( 1, 1, 1 ) );
    scene_manager->setAmbientLight( Ogre::ColourValue( 0.5, 0.5, 0.5 ) );

    Ogre::Light *directionalLight( scene_manager->createLight("directionalLight") );
    directionalLight->setType( Ogre::Light::LT_DIRECTIONAL );
    directionalLight->setDiffuseColour( Ogre::ColourValue( 0.5, 0.5, 0.5 ) );
    directionalLight->setSpecularColour( Ogre::ColourValue( 0.0, 0.0, 0.0 ) );
    directionalLight->setDirection( Ogre::Vector3( 0, 1, 0 ) );


    Ogre::ResourceGroupManager::getSingleton().initialiseAllResourceGroups();

    // init it before console because it may use it
    auto config_var_manager = std::make_unique<ConfigVarManager>();
    auto config_cmd_manager = std::make_unique<ConfigCmdManager>();

    auto debug_draw = std::make_unique<DebugDraw>();


    // init before GameFrameListener, but after ConfigCmdManager
    auto input_manager = std::make_unique<InputManager>();


    auto audio_manager = std::make_unique<AudioManager>();
    audio_manager->MusicPlay( "loop1" );

    // create This earlier than DisplayFrameListener cause it can fire event there
    auto camera_manager = std::make_unique<CameraManager>();

    auto console = std::make_unique<Console>();


    auto entity_manager = std::make_unique<EntityManager>();
    auto ui_manager = std::make_unique<UiManager>();
    ui_manager->SetLanguage( "English" );

    // init after game managers because it attach them to script
    auto script_manager = std::make_unique<ScriptManager>();

    // set base listner for usual game moduls
    auto frame_listener = std::make_unique<GameFrameListener>( window );
    root->addFrameListener( frame_listener.get() );

    // execute config
    {
        ConfigFile config;
        config.Execute( "./data/config.cfg" );
    }

    // init ui and run it scripts
    ui_manager->Initialise();


    // run application cycle
    QGears::g_ApplicationState = QGears::G_GAME;
    root->startRendering();



    // system moduls
    // we must remove this first cause this can fire event to console
    root->removeFrameListener( frame_listener.get() );


    // Must destruct before the script manager
    entity_manager.reset();
    ui_manager.reset();

    script_manager.reset();

    return 0;
}
