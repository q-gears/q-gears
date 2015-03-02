/*
-----------------------------------------------------------------------------
Copyright (c) 19.10.2013 Tobias Peters <tobias.peters@kreativeffekt.at>

This file is part of Q-Gears

Q-Gears is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, version 2.0 (GPLv2) of the License.

Q-Gears is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.
-----------------------------------------------------------------------------
*/
#include "common/QGearsApplication.h"

#include <boost/filesystem.hpp>
#include <boost/program_options.hpp>
#include <OgreConfigFile.h>
#include <OgreArchiveManager.h>

#include "QGearsGameState.h"
#include "data/QGearsAFileManager.h"
#include "data/QGearsBackgroundFileManager.h"
#include "data/QGearsCameraMatrixFileManager.h"
#include "data/QGearsHRCFileManager.h"
#include "data/QGearsLZSFLevelFileManager.h"
#include "data/QGearsPaletteFileManager.h"
#include "data/QGearsPFileManager.h"
#include "data/QGearsRSDFileManager.h"
#include "data/QGearsTexCodec.h"
#include "map/QGearsBackground2DFileManager.h"
#include "map/QGearsWalkmeshFileManager.h"
#include "data/FF7ModelListFileManager.h"
#include "data/QGearsLGPArchiveFactory.h"
#include "data/QGearsTriggersFile.h"
#include "data/QGearsMapListFile.h"
#include "common/make_unique.h"
#include "qgears_version.h"

template<> QGears::Application *Ogre::Singleton<QGears::Application>::msSingleton = nullptr;

namespace QGears
{
    namespace bfs = boost::filesystem;
    namespace bpo = boost::program_options;
    typedef Ogre::ConfigFile::SettingsMultiMap SettingsMultiMap;

    const char*     Application::CLI_SECTION_GENERIC( "Generic options" );
    const char*     Application::CLI_HELP( "help" );
    const char*     Application::CLI_HELP_DESCRIPTION( "this help message" );
    const char*     Application::CLI_CONFIG_FILE( "config-file" );
    const char*     Application::CLI_CONFIG_FILE_DESCRIPTION( "path to Ogre config file containing selected rendersystem and resolution" );
    const char*     Application::CLI_LOG_FILE( "log-file" );
    const char*     Application::CLI_LOG_FILE_DESCRIPTION( "path to log file" );
    const char*     Application::CLI_PLUGINS_FILE( "plugins-file" );
    const char*     Application::CLI_PLUGINS_FILE_DESCRIPTION( "path to config file containing available plugins" );
    const char*     Application::CLI_RESOURCES_FILE( "resources-file" );
    const char*     Application::CLI_RESOURCES_FILE_DESCRIPTION( "path to config file containing available resources" );

    //--------------------------------------------------------------------------
    Application::Application( int argc, char *argv[] ) :
        m_argc( argc )
      , m_argv( argv )
    {
    }

    //--------------------------------------------------------------------------
    Application::~Application()
    {
        destroyComponents();
    }

    //--------------------------------------------------------------------------
    bool
    Application::initOgre(bool hideWindow)
    {
        if( m_initialized )
        {
            return false;
        }

        m_initialized = true;

        if (m_argc && m_argv)
        {
            if (!processCommandLine(m_argc, m_argv))
            {
                return false;
            }
        }

        m_root = std::make_unique<Ogre::Root>( m_plugins_filename, m_config_filename, m_log_filename );
        m_overlay_system = std::make_unique<Ogre::OverlaySystem>();

        Ogre::Log* default_log( Ogre::LogManager::getSingleton().getDefaultLog() );
        assert( default_log );
        default_log->setLogDetail( Ogre::LL_BOREME );

        //-------------------------------------------------------------------------
        // configure
        // Show the configuration dialog and initialise the system
        // You can skip this and use root.restoreConfig() to load configuration
        // settings if you were sure there are valid ones saved in ogre.cfg
        if(/* !m_root->restoreConfig() &&*/ !m_root->showConfigDialog() )
        {
            return false;
        }

        if (hideWindow)
        {
            Ogre::NameValuePairList list;
            list.emplace("hidden", "true");
            m_root->initialise(false, getWindowTitle());
            m_render_window = m_root->createRenderWindow(getWindowTitle(), 1, 1, false, &list);
        }
        else
        {
            m_render_window = m_root->initialise(true, getWindowTitle());
        }

        registerArchiveFactories();
        loadResourcesConfig();
        initComponents();

        return true;
    }

    //--------------------------------------------------------------------------
    void
    Application::loadResourcesConfig()
    {
        // set up resources
        // Load resource paths from config file
        Ogre::ConfigFile config_file;
        config_file.load( m_resources_filename );

        // Go through all sections & settings in the file
        Ogre::ConfigFile::SectionIterator section( config_file.getSectionIterator() );

        Ogre::String section_name, archive_type, archive_name;
        mResMgr = (&Ogre::ResourceGroupManager::getSingleton());
        while( section.hasMoreElements() )
        {
            section_name = section.peekNextKey();
            SettingsMultiMap *settings( section.getNext() );
            SettingsMultiMap::const_iterator it ( settings->begin() );
            SettingsMultiMap::const_iterator end( settings->end()   );
            while( it != end )
            {
                archive_type = it->first;
                archive_name = it->second;
                mResMgr->addResourceLocation(archive_name, archive_type, section_name, true);
                ++it;
            }
        }
    }

    //--------------------------------------------------------------------------
    Ogre::Root*
    Application::getRoot()
    {
        return m_root.get();
    }

    //--------------------------------------------------------------------------
    Ogre::RenderWindow*
    Application::getRenderWindow()
    {
        return m_render_window;
    }

    //--------------------------------------------------------------------------
    const String&
    Application::getResourcesFilename()
    {
        return m_resources_filename;
    }

    //--------------------------------------------------------------------------
    String Application::getWindowTitle() const
    {
        return QG_VERSION_NAME;
    }

    //--------------------------------------------------------------------------
    bool
    Application::processCommandLine(  int argc, char *argv[] )
    {
        bfs::path self( argv[0] );
        const String self_stem( self.stem().string() );
        const String config_filename    ( self_stem     + EXT_CONFIG );
        const String log_filename       ( self_stem     + EXT_LOG );

#ifdef  NDEBUG
        const String plugins_filename   ( "plugins"     + EXT_CONFIG );
        const String resources_filename ( "resources"   + EXT_CONFIG );
#else
        const String plugins_filename   ( "plugins_d"   + EXT_CONFIG );
        const String resources_filename ( "resources_d" + EXT_CONFIG );
#endif

        bpo::options_description generic( CLI_SECTION_GENERIC );
        generic.add_options()
            ( CLI_HELP, CLI_HELP_DESCRIPTION )
            (   CLI_CONFIG_FILE
              , bpo::value< String >()->default_value( config_filename )
              , CLI_CONFIG_FILE_DESCRIPTION
            )
            (   CLI_LOG_FILE
              , bpo::value< String >()->default_value( log_filename )
              , CLI_LOG_FILE_DESCRIPTION
            )
            (   CLI_PLUGINS_FILE
              , bpo::value< String >()->default_value( plugins_filename )
              , CLI_PLUGINS_FILE_DESCRIPTION
            )
            (   CLI_RESOURCES_FILE
              , bpo::value< String >()->default_value( resources_filename )
              , CLI_RESOURCES_FILE_DESCRIPTION
            )
            ;
        bpo::variables_map vm;
        bpo::store( bpo::command_line_parser( argc, argv ).options( generic ).run(), vm );
        if ( vm.count( CLI_HELP ) )
        {
            std::cout << "Usage: " << self_stem << "\n"
                      << generic << "\n";
            return false;
        }

        bpo::notify( vm );
        m_config_filename       = vm[CLI_CONFIG_FILE].as< String >();
        m_log_filename          = vm[CLI_LOG_FILE].as< String >();
        m_plugins_filename      = vm[CLI_PLUGINS_FILE].as< String >();
        m_resources_filename    = vm[CLI_RESOURCES_FILE].as< String >();

        return true;
    }

    //--------------------------------------------------------------------------
    void
    Application::registerArchiveFactories()
    {
        Ogre::ArchiveManager::getSingleton().addArchiveFactory( new LGPArchiveFactory() );
    }

    //--------------------------------------------------------------------------
    void
    Application::initComponents()
    {
        QGears::TexCodec::install();
        QGears::TexCodec::initialise();
        createResourceManagers();
    }

    //--------------------------------------------------------------------------
    void
    Application::destroyComponents()
    {
        destroyResourceManagers();
        QGears::TexCodec::shutdown();
        QGears::TexCodec::uninstall();
    }

    //--------------------------------------------------------------------------
    void
    Application::createResourceManagers()
    {
        assert( m_resource_managers.empty() );
        m_resource_managers.emplace_back( std::make_shared<QGears::CameraMatrixFileManager>() );
        m_resource_managers.emplace_back( std::make_shared<QGears::PaletteFileManager>() );
        m_resource_managers.emplace_back( std::make_shared<QGears::WalkmeshFileManager>() );
        m_resource_managers.emplace_back( std::make_shared<QGears::FF7::ModelListFileManager>() );
        m_resource_managers.emplace_back( std::make_shared<QGears::HRCFileManager>() );
        m_resource_managers.emplace_back( std::make_shared<QGears::RSDFileManager>() );
        m_resource_managers.emplace_back( std::make_shared<QGears::AFileManager>() );
        m_resource_managers.emplace_back( std::make_shared<QGears::PFileManager>() );
        m_resource_managers.emplace_back( std::make_shared<QGears::LZSFLevelFileManager>() );
        m_resource_managers.emplace_back( std::make_shared<QGears::BackgroundFileManager>() );
        m_resource_managers.emplace_back( std::make_shared<QGears::Background2DFileManager>() );
        m_resource_managers.emplace_back(std::make_shared<QGears::TriggersFileManager>());
        m_resource_managers.emplace_back(std::make_shared<QGears::MapListFileManager>());
    }

    //--------------------------------------------------------------------------
    void
    Application::destroyResourceManagers()
    {
        m_resource_managers.clear();
    }

    //--------------------------------------------------------------------------
}
