#include "CameraManager.h"
#include "CameraManagerCommands.h"

#include <OgreRenderWindow.h>
#include <OgreRoot.h>
#include <OIS.h>

#include "ConfigVar.h"
#include "InputManager.h"
#include "Logger.h"



ConfigVar cv_cam_speed( "camera_speed", "Camera speed", "0.02" );



template<>CameraManager* Ogre::Singleton< CameraManager >::ms_Singleton = NULL;



CameraManager::CameraManager():
    m_CameraFree( false ),
    m_CameraFreeRotate( false ),

    m_2DPosition( Ogre::Vector3::ZERO ),
    m_2DOrientation( Ogre::Quaternion::ZERO ),
    m_2DFOV( 0 ),
    m_2DScroll( Ogre::Vector2::ZERO )
{
    LOG_TRIVIAL( "CameraManager started." );

    InitCommands();

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
    if( m_CameraFree == true )
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



void
CameraManager::SetCameraFree( const bool enable )
{
    m_CameraFree = enable;

    if( m_CameraFree == true )
    {
        m_Camera->resetFrustumExtents();
        CameraManager::getSingleton().GetCurrentCamera()->setFOVy( Ogre::Radian( Ogre::Math::PI / 4.0 ) );
    }
    else
    {
        CameraManager::getSingleton().GetCurrentCamera()->setPosition( m_2DPosition );
        CameraManager::getSingleton().GetCurrentCamera()->setOrientation( m_2DOrientation );
        CameraManager::getSingleton().GetCurrentCamera()->setFOVy( m_2DFOV );
        Set2DScroll( Get2DScroll() );
    }
}



void
CameraManager::Set2DCamera( const Ogre::Vector3 position, const Ogre::Quaternion orientation, const Ogre::Radian fov )
{
    m_2DPosition = position;
    m_2DOrientation = orientation;
    m_2DFOV = fov;
    CameraManager::getSingleton().GetCurrentCamera()->setPosition( m_2DPosition );
    CameraManager::getSingleton().GetCurrentCamera()->setOrientation( m_2DOrientation );
    CameraManager::getSingleton().GetCurrentCamera()->setFOVy( m_2DFOV );
    Set2DScroll( Ogre::Vector2::ZERO );
}



void
CameraManager::Set2DScroll( const Ogre::Vector2& position )
{
    m_2DScroll = position;

    if( m_CameraFree == true )
    {
        return;
    }

    float width = Ogre::Root::getSingleton().getRenderTarget( "QGearsWindow" )->getViewport( 0 )->getActualWidth();
    float height = Ogre::Root::getSingleton().getRenderTarget( "QGearsWindow" )->getViewport( 0 )->getActualHeight();
    float left, right, top, bottom;
    m_Camera->resetFrustumExtents();
    m_Camera->getFrustumExtents( left, right, top, bottom );
    float move_x = ( ( right - left ) / width ) * position.x;
    float move_y = ( ( bottom - top ) / height ) * -position.y;
    m_Camera->setFrustumExtents( left - move_x, right - move_x, top + move_y, bottom + move_y );
}



const Ogre::Vector2&
CameraManager::Get2DScroll() const
{
    return m_2DScroll;
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
