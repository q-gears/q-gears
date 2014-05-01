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
#ifndef __QGearsApplication_H__
#define __QGearsApplication_H__

#include <OgreRoot.h>

#include "TypeDefine.h"

namespace QGears
{
    class Application : public Ogre::Singleton<Application>
    {
    public:
        Application( int argc, char *argv[] );
        virtual ~Application();

        virtual bool                initOgre( void );

        virtual Ogre::Root*         getRoot( void );
        virtual Ogre::RenderWindow* getRenderWindow( void );
        virtual const String&       getResourcesFilename( void );

    protected:
        virtual String  getWindowTitle( void ) const;

        virtual bool    processCommandLine( int argc, char *argv[] );
        virtual void    registerArchiveFactories( void );
        virtual void    loadResourcesConfig( void );
        virtual void    initComponents( void );
        virtual void    destroyComponents( void );
        virtual void    createResourceManagers( void );
        virtual void    destroyResourceManagers( void );

    private:
        typedef std::vector<Ogre::ResourceManager*> ResourceManagerList;

        Application();

        static const char*      CLI_SECTION_GENERIC;
        static const char*      CLI_HELP;
        static const char*      CLI_HELP_DESCRIPTION;
        static const char*      CLI_CONFIG_FILE;
        static const char*      CLI_CONFIG_FILE_DESCRIPTION;
        static const char*      CLI_LOG_FILE;
        static const char*      CLI_LOG_FILE_DESCRIPTION;
        static const char*      CLI_PLUGINS_FILE;
        static const char*      CLI_PLUGINS_FILE_DESCRIPTION;
        static const char*      CLI_RESOURCES_FILE;
        static const char*      CLI_RESOURCES_FILE_DESCRIPTION;

        int     m_argc;
        char  **m_argv;
        String  m_config_filename;
        String  m_log_filename;
        String  m_plugins_filename;
        String  m_resources_filename;

        bool                m_initialized;
        Ogre::Root         *m_root;
        Ogre::RenderWindow *m_render_window;
        ResourceManagerList m_resource_managers;
    };
}

#endif // __QGearsApplication_H__
