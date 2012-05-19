#include "CameraManager.h"

#include <OgreRenderWindow.h>
#include <OgreRoot.h>
#include <OIS.h>

#include "ConfigVar.h"
#include "InputManager.h"
#include "Logger.h"



ConfigVar cv_cam_speed( "camera_speed", "Camera speed", "0.02" );



template<>CameraManager* Ogre::Singleton< CameraManager >::ms_Singleton = NULL;



CameraManager::CameraManager():
    m_State( CAMERA_FREE ),
    m_CameraFreeRotate( false )
{
    LOG_TRIVIAL( "CameraManager started." );

    m_Camera = Ogre::Root::getSingleton().getSceneManager( "Scene" )->createCamera( "Camera" );
    m_Camera->setNearClipDistance( 0.001f );
    m_Camera->setFarClipDistance( 1000.0f );
    m_Camera->setPosition( Ogre::Vector3( 0, -3, 3 ) );
    m_Camera->lookAt( Ogre::Vector3( 0, 0, 0 ) );
    m_Viewport = Ogre::Root::getSingleton().getRenderTarget( "QGearsWindow" )->addViewport( m_Camera, 0 );
    m_Viewport->setBackgroundColour( Ogre::ColourValue( 0, 0, 0 ) );
    m_Camera->setAspectRatio( Ogre::Real( m_Viewport->getActualWidth() ) / Ogre::Real( m_Viewport->getActualHeight() ) );
}



CameraManager::~CameraManager()
{
    LOG_TRIVIAL( "CameraManager finished." );
}



void
CameraManager::Input( const Event& event )
{
    if( m_State == CAMERA_FREE )
    {
        float speed = cv_cam_speed.GetF();
        if( InputManager::getSingleton().IsButtonPressed( OIS::KC_RSHIFT ) || InputManager::getSingleton().IsButtonPressed( OIS::KC_LSHIFT ) )
        {
            speed *= 4;
        }

        if( event.type == ET_KEY_IMPULSE && event.param1 == OIS::KC_W )
        {
            m_Camera->moveRelative( Ogre::Vector3( 0, 0, -speed ) );
        }
        else if( event.type == ET_KEY_IMPULSE && event.param1 == OIS::KC_A )
        {
            m_Camera->moveRelative( Ogre::Vector3( -speed, 0, 0 ) );
        }
        else if( event.type == ET_KEY_IMPULSE && event.param1 == OIS::KC_S )
        {
            m_Camera->moveRelative( Ogre::Vector3( 0, 0, speed ) );
        }
        else if( event.type == ET_KEY_IMPULSE && event.param1 == OIS::KC_D )
        {
            m_Camera->moveRelative( Ogre::Vector3( speed, 0, 0 ) );
        }
        else if( event.type == ET_MOUSE_PRESS && event.param1 == OIS::MB_Right )
        {
            m_CameraFreeRotate = true;
        }
        else if( event.type == ET_MOUSE_RELEASE && event.param1 == OIS::MB_Right )
        {
            m_CameraFreeRotate = false;
        }
        else if( event.type == ET_MOUSE_MOVE && m_CameraFreeRotate == true )
        {
            m_Camera->rotate( Ogre::Vector3::UNIT_Z, Ogre::Radian( Ogre::Degree( -event.param1 * 0.13 ) ) );
            m_Camera->pitch( Ogre::Degree( -event.param2 * 0.13 ) );
        }
    }
}



void
CameraManager::Update()
{
}



void
CameraManager::OnResize()
{
    m_Camera->setAspectRatio( Ogre::Real( m_Viewport->getActualWidth() ) / Ogre::Real( m_Viewport->getActualHeight() ) );
}



const Ogre::Vector3
CameraManager::ProjectPointToScreen( const Ogre::Vector3& point )
{
    Ogre::Vector3 view = m_Camera->getViewMatrix() * point;
    float z = view.z;
    view = m_Camera->getProjectionMatrix() * view;
    view.z = z;

    float width = m_Viewport->getActualWidth() / 2;
    float height = m_Viewport->getActualHeight() / 2;

    view.x = width + view.x * width;
    view.y = height - view.y * height;

    return view;
}



Ogre::Camera*
CameraManager::GetCurrentCamera()
{
    return m_Camera;
}
