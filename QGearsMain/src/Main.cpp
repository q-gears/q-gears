#include <OgreRoot.h>
#include <OgreConfigFile.h>
#include <OIS.h>

#include "QgearsGameState.h"
//#include "core/AudioManager.h"
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

#include "data/QGearsBackgroundFileManager.h"
#include "data/QGearsPaletteFileManager.h"
#include "data/QGearsLZSFLevelFileManager.h"
#include "map/QGearsBackground2DFileManager.h"




int
main(int argc, char *argv[])
{
    Ogre::Root* root;
    Ogre::RenderWindow* window;
    Ogre::SceneManager* scene_manager;

    Ogre::LogManager* log_manager = new Ogre::LogManager();
    log_manager->createLog( "q-gears.log", true, true );
    log_manager->getDefaultLog()->setLogDetail( ( Ogre::LoggingLevel )3 );

    Ogre::String ressource_cfg("");
    Ogre::String plugins_cfg("");
    Ogre::String dyn_lib_ext("");
    Ogre::String render_system("");

#ifdef __WIN32__
    dyn_lib_ext = ".dll";
#else // Assume Linux for now
    dyn_lib_ext = ".so";
#endif

#ifdef _DEBUG
    ressource_cfg = "resources_d.cfg";
    plugins_cfg = "plugins_d.cfg";
    render_system = "./RenderSystem_GL_d" + dyn_lib_ext;
#else
    ressource_cfg = "resources.cfg";
    plugins_cfg = "plugins.cfg";
    render_system = "./RenderSystem_GL" + dyn_lib_ext;
#endif

    // init root early
    root = new Ogre::Root( plugins_cfg );

    // set up resources
    // Load resource paths from config file
    Ogre::ConfigFile cf;
    cf.load( ressource_cfg );

    // Go through all sections & settings in the file
    Ogre::ConfigFile::SectionIterator seci = cf.getSectionIterator();

    Ogre::String secName, typeName, archName;
    Ogre::ResourceGroupManager &res_gm( Ogre::ResourceGroupManager::getSingleton() );
    while (seci.hasMoreElements())
    {
        secName = seci.peekNextKey();
        Ogre::ConfigFile::SettingsMultiMap *settings = seci.getNext();
        Ogre::ConfigFile::SettingsMultiMap::iterator i;
        for (i = settings->begin(); i != settings->end(); ++i)
        {
            typeName = i->first;
            archName = i->second;
            res_gm.addResourceLocation( archName, typeName, secName, true );
        }
    }

//-------------------------------------------------------------------------------------
    // configure
    // Show the configuration dialog and initialise the system
    // You can skip this and use root.restoreConfig() to load configuration
    // settings if you were sure there are valid ones saved in ogre.cfg
    if( !root->restoreConfig() && !root->showConfigDialog() )
    {
        root->setRenderSystem( root->getAvailableRenderers()[ 0 ] );
    }
    root->initialise( false );
    Ogre::NameValuePairList misc;
    misc[ "title" ] = QG_VERSION_NAME;
    window = root->createRenderWindow( "QGearsWindow", 1280, 720, false, &misc );



    Timer* timer = new Timer();



    ParticleSystemManager* particle_system_manager = new ParticleSystemManager();



    // set scene camera and viewport for other moduls
    // create this before initialize particle because some of them use scene to create themself
    scene_manager = root->createSceneManager( Ogre::ST_GENERIC, "Scene" );
    scene_manager->setAmbientLight( Ogre::ColourValue( 1.0, 1.0, 1.0 ) );

    QGears::Background2DFileManager *b2d_mgr( new QGears::Background2DFileManager() );
    QGears::BackgroundFileManager   *bgf_mgr( new QGears::BackgroundFileManager() );
    QGears::LZSFLevelFileManager    *flv_mgr( new QGears::LZSFLevelFileManager() );
    QGears::PaletteFileManager      *plt_mgr( new QGears::PaletteFileManager() );
    res_gm.addResourceLocation( "./data", "FileSystem", "Game", true );
    res_gm.initialiseResourceGroup( "Game" );
    QGears::FLevelFilePtr   f( QGears::LZSFLevelFileManager::getSingleton().load( "field/gflevel/md1stin", "Game" ) );
    QGears::FLevelFilePtr   f2( QGears::LZSFLevelFileManager::getSingleton().load( "field/gflevel/md1_1", "Game" ) );




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
    delete flv_mgr;
    delete plt_mgr;
    delete bgf_mgr;
    delete b2d_mgr;

    delete particle_system_manager;
    delete timer;
    delete root;
    delete log_manager;

    return 0;
}
