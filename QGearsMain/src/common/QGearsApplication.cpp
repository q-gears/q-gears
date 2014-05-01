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

namespace QGears
{
    namespace bfs = boost::filesystem;
    namespace bpo = boost::program_options;
    typedef Ogre::ConfigFile::SettingsMultiMap SettingsMultiMap;

    //--------------------------------------------------------------------------
    template<> Application *Ogre::Singleton<Application>::msSingleton = NULL;

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
      , m_initialized( false )
      , m_root( NULL )
      , m_render_window( NULL )
    {
    }

    //--------------------------------------------------------------------------
    Application::~Application()
    {
        destroyComponents();
        if( m_root ) delete m_root;
    }

    //--------------------------------------------------------------------------
    bool
    Application::initOgre()
    {
        if( m_initialized ) return false;
        m_initialized = true;

        if( !processCommandLine( m_argc, m_argv ) ) return false;

        m_root = new Ogre::Root( m_plugins_filename, m_config_filename
                               , m_log_filename );

        Ogre::Log* default_log( Ogre::LogManager::getSingleton().getDefaultLog() );
        assert( default_log );
        default_log->setLogDetail( Ogre::LL_BOREME );

        //-------------------------------------------------------------------------
        // configure
        // Show the configuration dialog and initialise the system
        // You can skip this and use root.restoreConfig() to load configuration
        // settings if you were sure there are valid ones saved in ogre.cfg
        if( !m_root->restoreConfig() && !m_root->showConfigDialog() )
        {
            return false;
        }
        m_render_window = m_root->initialise( true, getWindowTitle() );

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
        Ogre::ResourceGroupManager &res_gm( Ogre::ResourceGroupManager::getSingleton() );
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
                res_gm.addResourceLocation( archive_name, archive_type, section_name, true );
                ++it;
            }
        }
    }

    //--------------------------------------------------------------------------
    Ogre::Root*
    Application::getRoot()
    {
        return m_root;
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
        // TODO maybe we should use SharedPtr so we don't have to really care
        // for destruction!?
        m_resource_managers.push_back( new QGears::CameraMatrixFileManager() );
        m_resource_managers.push_back( new QGears::PaletteFileManager() );
        m_resource_managers.push_back( new QGears::WalkmeshFileManager() );
        m_resource_managers.push_back( new QGears::FF7::ModelListFileManager() );
        m_resource_managers.push_back( new QGears::HRCFileManager() );
        m_resource_managers.push_back( new QGears::RSDFileManager() );
        m_resource_managers.push_back( new QGears::AFileManager() );
        m_resource_managers.push_back( new QGears::PFileManager() );
        m_resource_managers.push_back( new QGears::LZSFLevelFileManager() );
        m_resource_managers.push_back( new QGears::BackgroundFileManager() );
        m_resource_managers.push_back( new QGears::Background2DFileManager() );
    }

    //--------------------------------------------------------------------------
    void
    Application::destroyResourceManagers()
    {
        ResourceManagerList::iterator       it ( m_resource_managers.begin() );
        ResourceManagerList::const_iterator end( m_resource_managers.end() );
        while( it != end )
        {
            delete (*it++);
        }
        m_resource_managers.clear();
    }

    //--------------------------------------------------------------------------
}
