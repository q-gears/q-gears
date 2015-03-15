#include <OgreRoot.h>
#include <OgreConfigFile.h>
#include <OgreArchiveManager.h>
#include <OIS.h>

#include "QGearsGameState.h"
#ifdef QGears_SOUND
#include "core/AudioManager.h"
#endif
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
#include "core/TextManager.h"
#include "core/DialogsManager.h"
#include "data/QGearsLZSFLevelFileManager.h"
#include "common/make_unique.h"
#include <OgreFontManager.h>
#include <OgreOverlayManager.h>
#include <OgreOverlaySystem.h>

#include "modules/worldmap/WorldMapModule.h"
#include "data/worldmap/MapFileManager.h"
#include "data/QGearsLGPArchiveFactory.h"

int
main(int argc, char *argv[])
{
    try
    {
        QGears::Application app(argc, argv);
        if (!app.initOgre()) return 0;

        Ogre::Root         *root(app.getRoot());
        Ogre::RenderWindow *window(app.getRenderWindow());
        Ogre::SceneManager *scene_manager(nullptr);

        auto timer = std::make_unique<Timer>();
        auto particle_system_manager = std::make_unique<ParticleSystemManager>();

        // set scene camera and viewport for other moduls
        // create this before initialize particle because some of them use scene to create themself
        scene_manager = root->createSceneManager(Ogre::ST_GENERIC, "Scene");
        scene_manager->setAmbientLight(Ogre::ColourValue(1, 1, 1));
        scene_manager->setAmbientLight(Ogre::ColourValue(0.5, 0.5, 0.5));

        Ogre::Light *directionalLight(scene_manager->createLight("directionalLight"));
        directionalLight->setType(Ogre::Light::LT_DIRECTIONAL);
        directionalLight->setDiffuseColour(Ogre::ColourValue(0.5, 0.5, 0.5));
        directionalLight->setSpecularColour(Ogre::ColourValue(0.0, 0.0, 0.0));
        directionalLight->setDirection(Ogre::Vector3(0, 1, 0));

        // auto fontManager = std::make_unique<Ogre::FontManager>();

        QGears::MapFileManager* worldManager = new QGears::MapFileManager();

        Ogre::Root::getSingleton().addResourceLocation(".", "FileSystem");
        Ogre::Root::getSingleton().addResourceLocation("./data/wm", "FileSystem", "TEST");
        Ogre::Root::getSingleton().addResourceLocation("./data/wm/world_us.lgp", QGears::LGPArchiveFactory::ARCHIVE_TYPE, "TEST");


        Ogre::ResourceGroupManager::getSingleton().initialiseAllResourceGroups();

        // init it before console because it may use it
        auto config_var_manager = std::make_unique<ConfigVarManager>();
        auto config_cmd_manager = std::make_unique<ConfigCmdManager>();

        auto debug_draw = std::make_unique<DebugDraw>();


        // init before GameFrameListener, but after ConfigCmdManager
        auto input_manager = std::make_unique<InputManager>();


#ifdef QGears_SOUND
        //auto audio_manager = std::make_unique<AudioManager>();
        //audio_manager->MusicPlay( "loop1" );
#endif

        // create This earlier than DisplayFrameListener cause it can fire event there
        auto camera_manager = std::make_unique<CameraManager>();
        auto text_manager = std::make_unique<TextManager>();

        auto ui_manager = std::make_unique<UiManager>();
        auto dialogs_manager = std::make_unique<DialogsManager>();
        auto entity_manager = std::make_unique<EntityManager>();

        auto console = std::make_unique<Console>();

        auto worldMapModule = std::make_unique<QGears::WorldMapModule>();


        // init after game managers because it attach them to script
        auto script_manager = std::make_unique<ScriptManager>();

        // set base listner for usual game moduls
        auto frame_listener = std::make_unique<GameFrameListener>(window);
        root->addFrameListener(frame_listener.get());




        // execute config
        {
            ConfigFile config;
            config.Execute("./data/config.cfg");
        }

        // init ui and run it scripts
        ui_manager->Initialise();
    dialogs_manager->Initialise();


        // run application cycle
        QGears::g_ApplicationState = QGears::G_GAME;
        root->startRendering();



        // system moduls
        // we must remove this first cause this can fire event to console
        root->removeFrameListener(frame_listener.get());


        // Must destruct before the script manager
        entity_manager.reset();
        ui_manager.reset();

        script_manager.reset();
    }
    catch (const std::runtime_error& ex)
    {
        std::cout << "std::runtime_error thrown: " << ex.what() << std::endl;
    }
    catch (const Ogre::Exception& ex)
    {
        std::cout << "Ogre::Exception thrown: " << ex.what() << std::endl;
    }

    return 0;
}
