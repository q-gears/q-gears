#include <OgreRoot.h>
#include <OgreConfigFile.h>
#include <OgreArchiveManager.h>
#include <OIS.h>

#include "QGearsGameState.h"
//#include "core/AudioManager.h"
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

using std::cout;
using std::endl;

int
main(int argc, char *argv[])
{
    QGears::Application app( argc, argv );
    if( !app.initOgre() ) return 0;

    Ogre::Root         *root( app.getRoot() );
    Ogre::RenderWindow *window( app.getRenderWindow() );
    Ogre::SceneManager *scene_manager( NULL );

    Timer* timer = new Timer();
    ParticleSystemManager* particle_system_manager = new ParticleSystemManager();

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

    QGears::FLevelFilePtr   f;
    QGears::FLevelFilePtr   f2;
    //f  = QGears::LZSFLevelFileManager::getSingleton().load( "md1stin", "FFVII" );
    //f2 = QGears::LZSFLevelFileManager::getSingleton().load( "md1_1"  , "FFVII" );


    // init it before console because it may use it
    ConfigVarManager* config_var_manager = new ConfigVarManager();
    ConfigCmdManager* config_cmd_manager = new ConfigCmdManager();



    DebugDraw* debug_draw = new DebugDraw();



    // init before GameFrameListener, but after ConfigCmdManager
    InputManager* input_manager = new InputManager();



    //AudioManager* audio_manager = new AudioManager();
    //audio_manager->MusicPlay( "loop1" );


    // create This earlier than DisplayFrameListener cause it can fire event there
    CameraManager* camera_manager = new CameraManager();
    EntityManager* entity_manager = new EntityManager();
    UiManager* ui_manager = new UiManager();
    ui_manager->SetLanguage( "English" );
    Console* console = new Console();

    // init after game managers because it attach them to script
    ScriptManager* script_manager = new ScriptManager();


    // set base listner for usual game moduls
    GameFrameListener* frame_listener = new GameFrameListener( window );
    root->addFrameListener( frame_listener );



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
    root->removeFrameListener( frame_listener );
    delete frame_listener;
    // destroy before script manager because it removes things from it.
    delete entity_manager;
    delete ui_manager;
    delete script_manager;
    delete console;
    delete camera_manager;
    //delete audio_manager;
    delete input_manager;
    delete debug_draw;
    delete config_cmd_manager;
    delete config_var_manager;

    f.setNull();
    f2.setNull();

    delete particle_system_manager;
    delete timer;

    return 0;
}
