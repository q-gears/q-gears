/*
-----------------------------------------------------------------------------
Copyright (c) 26.10.2013 Tobias Peters <tobias.peters@kreativeffekt.at>

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
#include "QGearsUtility.h"

namespace QGears
{
    //--------------------------------------------------------------------------
    Utility::Utility(int argc, char *argv[]) :
        Application( argc, argv )
      , m_frame_listener( NULL )
      , m_scene_manager( NULL )
      , m_camera( NULL )
      , m_viewport( NULL )
    {
    }

    //--------------------------------------------------------------------------
    Utility::~Utility()
    {
    }

    //--------------------------------------------------------------------------
    Ogre::Camera*
    Utility::getCamera()
    {
        return m_camera;
    }

    //--------------------------------------------------------------------------
    void
    Utility::initComponents()
    {
        Application::initComponents();
        Ogre::ResourceGroupManager::getSingleton().initialiseAllResourceGroups();

        Ogre::Root         *root( getRoot() );

        m_scene_manager = root->createSceneManager( Ogre::ST_GENERIC, "Scene" );
        m_scene_manager->clearScene();
        m_scene_manager->setAmbientLight( Ogre::ColourValue( 0.5, 0.5, 0.5 ) );
        Ogre::Light* directionalLight = m_scene_manager->createLight("directionalLight");
        directionalLight->setType( Ogre::Light::LT_DIRECTIONAL );
        directionalLight->setDiffuseColour( Ogre::ColourValue( 0.5, 0.5, 0.5) );
        directionalLight->setSpecularColour( Ogre::ColourValue( 0.5, 0.5, 0.5) );
        directionalLight->setDirection( Ogre::Vector3( 0, 0, -1 ) );

        m_camera = m_scene_manager->createCamera( "Camera" );
        m_camera->setNearClipDistance( 0.01f );
        m_camera->setPosition( 0, 5, 10 );
        m_camera->lookAt( 0, 0, 0 );

        Ogre::RenderWindow *window( getRenderWindow() );
        m_viewport = window->addViewport( m_camera );
        m_viewport->setBackgroundColour( Ogre::ColourValue( 0, 0.4, 0 ) );
        m_camera->setAspectRatio( Ogre::Real( m_viewport->getActualWidth() ) / Ogre::Real( m_viewport->getActualHeight() ) );

        m_frame_listener = new DisplayFrameListener( window );
        m_frame_listener->setCamera( m_camera );
        root->addFrameListener( m_frame_listener );
    }

    //--------------------------------------------------------------------------
    void
    Utility::destroyComponents()
    {
        delete m_frame_listener;
        m_frame_listener = NULL;
        Application::destroyComponents();
    }

    //--------------------------------------------------------------------------
}
