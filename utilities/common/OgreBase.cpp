#include "OgreBase.h"

#ifdef QGEARS_ADD_MANAGERS
#include "data/QGearsBackgroundFileManager.h"
#include "data/QGearsPaletteFileManager.h"
#include "data/QGearsLZSFLevelFileManager.h"
#include "map/QGearsBackground2DFileManager.h"
#endif

Ogre::Root*                     root;
Ogre::RenderWindow*             window;
std::vector< Ogre::Entity* >    entitys;
Ogre::Camera                   *camera;
DisplayFrameListener           *frame_listener;

#ifdef QGEARS_ADD_MANAGERS
QGears::Background2DFileManager    *b2d_mgr;
QGears::BackgroundFileManager      *bmgr;
QGears::PaletteFileManager         *pmgr;
QGears::LZSFLevelFileManager       *fmgr;
#endif

void
InitializeOgreBase( const Ogre::String& name )
{
    Ogre::LogManager* log_manager = new Ogre::LogManager();
    log_manager->createLog( "q-gears.log", true, true );
    log_manager->getDefaultLog()->setLogDetail( ( Ogre::LoggingLevel )3 );

    Ogre::String ressource_cfg("");
    Ogre::String plugins_cfg("");
    Ogre::String dyn_lib_ext("");
    Ogre::String render_system("");

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
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
    misc[ "title" ] = name;
    window = root->createRenderWindow( "QGearsWindow", 800, 600, false, &misc );


    #ifdef QGEARS_ADD_MANAGERS
    // move to plugin if not needed directly
    b2d_mgr = new QGears::Background2DFileManager();
    bmgr = new QGears::BackgroundFileManager();
    pmgr = new QGears::PaletteFileManager();
    fmgr = new QGears::LZSFLevelFileManager();
    #endif

    // initialize resource
    Ogre::ResourceGroupManager::getSingleton().addResourceLocation( "./", "FileSystem", "General" );
    Ogre::ResourceGroupManager::getSingleton().addResourceLocation( "./exported", "FileSystem", "General" );
    Ogre::ResourceGroupManager::getSingleton().initialiseAllResourceGroups();


    Ogre::SceneManager* scene_manager;
    Ogre::Viewport*     viewport;

    frame_listener = new DisplayFrameListener( window );
    root->addFrameListener( frame_listener );

    scene_manager = root->createSceneManager( Ogre::ST_GENERIC, "Scene" );
    scene_manager->clearScene();
    scene_manager->setAmbientLight( Ogre::ColourValue( 0.5, 0.5, 0.5 ) );
    Ogre::Light* directionalLight = scene_manager->createLight("directionalLight");
    directionalLight->setType( Ogre::Light::LT_DIRECTIONAL );
    directionalLight->setDiffuseColour( Ogre::ColourValue( 0.5, 0.5, 0.5) );
    directionalLight->setSpecularColour( Ogre::ColourValue( 0.5, 0.5, 0.5) );
    directionalLight->setDirection( Ogre::Vector3( 0, 0, -1 ) );

    camera = scene_manager->createCamera( "Camera" );
    camera->setNearClipDistance( 0.01f );
    camera->setPosition( 0, 5, 10 );
    camera->lookAt( 0, 0, 0 );

    viewport = window->addViewport( camera );
    viewport->setBackgroundColour( Ogre::ColourValue( 0, 0.4, 0 ) );
    camera->setAspectRatio( Ogre::Real( viewport->getActualWidth() ) / Ogre::Real( viewport->getActualHeight() ) );

    FILESYSTEM = new FileSystem();
    LOGGER = new Logger( "game.log" );
};



void
DeinitializeOgreBase()
{
    delete LOGGER;
    delete FILESYSTEM;

    #ifdef QGEARS_ADD_MANAGERS
    delete fmgr;
    delete bmgr;
    delete pmgr;
    delete b2d_mgr;
    #endif

    delete root;
    delete frame_listener;
};
