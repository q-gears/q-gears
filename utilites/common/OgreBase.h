#ifndef __OGRE_BASE_H__
#define __OGRE_BASE_H__

#include <Ogre.h>
#include <OgreTextAreaOverlayElement.h>
#include <OIS.h>

#include "FileSystem.h"
#include "Logger.h"



extern Ogre::Root*                     root;
extern Ogre::RenderWindow*             window;
extern std::vector< Ogre::Entity* >    entitys;
extern Ogre::Camera*                   camera;

class DisplayFrameListener;

extern DisplayFrameListener* frame_listener;


class DisplayFrameListener : public Ogre::FrameListener, public Ogre::WindowEventListener, public OIS::KeyListener, public OIS::MouseListener
{
public:
    // Constructor takes a RenderWindow because it uses that to determine input context
    DisplayFrameListener( Ogre::RenderWindow* win ):
        m_Window(win),
        m_InputManager( 0 ),
        m_Keyboard( 0 ),
        m_Mouse( 0 ),
        m_MouseRotate( false ),
        m_Exit( false )
    {

        using namespace OIS;

        Ogre::LogManager::getSingletonPtr()->logMessage( "*** Initializing OIS ***" );
        ParamList pl;
        size_t windowHnd = 0;
        std::ostringstream windowHndStr;

        win->getCustomAttribute( "WINDOW", &windowHnd );
        windowHndStr << windowHnd;
        pl.insert( std::make_pair( std::string( "WINDOW" ), windowHndStr.str() ) );

        m_InputManager = InputManager::createInputSystem( pl );

        m_Keyboard = static_cast< Keyboard* >( m_InputManager->createInputObject( OIS::OISKeyboard, true ) );
        m_Keyboard->setEventCallback( this );

        m_Mouse = static_cast< OIS::Mouse* >( m_InputManager->createInputObject( OIS::OISMouse, true ) );
        m_Mouse->setEventCallback( this );

        //Register as a Window listener
        Ogre::WindowEventUtilities::addWindowEventListener( m_Window, this );



        // debug info
        info_text = new Ogre::TextAreaOverlayElement( "DebugText" );
        info_text->setCaption( "" );
        info_text->setMetricsMode( Ogre::GMM_PIXELS );
        info_text->setPosition( 5, 5 );
        info_text->setFontName( "BlueHighway" );
        info_text->setCharHeight( 18 );

        info_overlay = Ogre::OverlayManager::getSingleton().create( "DebugOverlay" );
        info_overlay->setZOrder( 1 );
        info_overlay->add2D( ( Ogre::OverlayContainer* )info_text );
        info_overlay->show();
    }

    virtual
    ~DisplayFrameListener()
    {
        m_InputManager->destroyInputObject( m_Keyboard );

        OIS::InputManager::destroyInputSystem( m_InputManager );

        //Remove ourself as a Window listener
        Ogre::WindowEventUtilities::removeWindowEventListener( m_Window, this );
        windowClosed( m_Window );
    }

    //Unattach OIS before window shutdown (very important under Linux)
    virtual void
    windowClosed( Ogre::RenderWindow* rw )
    {
        m_Exit = true;
    }

    bool
    frameStarted( const Ogre::FrameEvent& evt )
    {
        if( m_Exit == true )
        {
            return false;
        }

        if( m_Keyboard )
        {
            m_Keyboard->capture();
        }

        if( m_Mouse )
        {
            m_Mouse->capture();
        }

        for( int i = 0; i < entitys.size(); ++i )
        {
            if( entitys[ i ]->isVisible() == true )
            {
                Ogre::AnimationStateIterator animations = entitys[ i ]->getAllAnimationStates()->getAnimationStateIterator();

                while( animations.hasMoreElements() == true )
                {
                    Ogre::AnimationState* state = animations.getNext();

                    if( state->getEnabled() == true )
                    {
                        state->addTime( evt.timeSinceLastFrame );

                        info_text->setCaption( entitys[ i ]->getName() + ": " + state->getAnimationName() );
                    }
                }

                break;
            }
        }

        if( m_Keyboard->isKeyDown( OIS::KC_A ) )
        {
            camera->moveRelative( Ogre::Vector3( -0.005, 0, 0 ) );
        }
        if( m_Keyboard->isKeyDown( OIS::KC_D ) )
        {
            camera->moveRelative( Ogre::Vector3( 0.005, 0, 0 ) );
        }
        if( m_Keyboard->isKeyDown( OIS::KC_W ) )
        {
            camera->moveRelative( Ogre::Vector3( 0, 0, -0.005 ) );
        }
        if( m_Keyboard->isKeyDown( OIS::KC_S ) )
        {
            camera->moveRelative( Ogre::Vector3( 0, 0,  0.005 ) );
        }
        if( m_MouseRotate == true )
        {
            camera->rotate( Ogre::Vector3::UNIT_Y, Ogre::Radian( Ogre::Degree( -m_MouseMoveX * 0.13 ) ) );
            camera->pitch( Ogre::Degree( -m_MouseMoveY * 0.13 ) );
            m_MouseMoveX = 0;
            m_MouseMoveY = 0;
        }

        return true;
    }

    // KeyListener
    bool
    keyPressed( const OIS::KeyEvent& e )
    {
        switch( e.key )
        {
            case OIS::KC_RIGHT:
            {
                bool change = false;
                for( int i = 0; i < entitys.size(); ++i )
                {
                    if( change == true )
                    {
                        entitys[ i ]->setVisible( true );
                        break;
                    }
                    if( entitys[ i ]->isVisible() == true && ( i != entitys.size() - 1 ) )
                    {
                        entitys[ i ]->setVisible( false );
                        change = true;
                    }
                }
            }
            break;

            case OIS::KC_LEFT:
            {
                bool change = false;
                for( int i = entitys.size() - 1; i >= 0; --i )
                {
                    if( change == true )
                    {
                        entitys[ i ]->setVisible( true );
                        break;
                    }
                    if( entitys[ i ]->isVisible() == true && i != 0 )
                    {
                        entitys[ i ]->setVisible( false );
                        change = true;
                    }
                }
            }
            break;

            case OIS::KC_UP:
            {
                bool change = false;
                for( int i = 0; i < entitys.size(); ++i )
                {
                    if( entitys[ i ]->isVisible() == true )
                    {
                        Ogre::AnimationStateIterator animations = entitys[ i ]->getAllAnimationStates()->getAnimationStateIterator();

                        Ogre::AnimationState* old_state;
                        Ogre::AnimationState* new_state = animations.getNext();

                        while( animations.hasMoreElements() == true )
                        {
                            old_state = new_state;
                            new_state = animations.getNext();

                            if( new_state->getEnabled() == true )
                            {
                                new_state->setEnabled( false );
                                new_state->setLoop( false );
                                old_state->setEnabled( true );
                                old_state->setLoop( true );
                            }
                        }

                        break;
                    }
                }
            }
            break;

            case OIS::KC_DOWN:
            {
                bool change = false;
                for( int i = 0; i < entitys.size(); ++i )
                {
                    if( entitys[ i ]->isVisible() == true )
                    {
                        Ogre::AnimationStateIterator animations = entitys[ i ]->getAllAnimationStates()->getAnimationStateIterator();

                        while( animations.hasMoreElements() == true )
                        {
                            Ogre::AnimationState* state = animations.getNext();

                            if( change == true )
                            {
                                state->setEnabled( true );
                                state->setLoop( true );
                                break;
                            }
                            if( state->getEnabled() == true && animations.hasMoreElements() != false )
                            {
                                state->setEnabled( false );
                                state->setLoop( false );
                                change = true;
                            }
                        }

                        break;
                    }
                }
            }
            break;
        }

        return true;
    }

    bool
    keyReleased( const OIS::KeyEvent& e )
    {
        return true;
    }

    bool
    mouseMoved( const OIS::MouseEvent& e )
    {
        m_MouseMoveX = e.state.X.rel;
        m_MouseMoveY = e.state.Y.rel;
        return true;
    }

    bool
    mousePressed( const OIS::MouseEvent& e, OIS::MouseButtonID id )
    {
        if( id == OIS::MB_Right )
        {
            m_MouseRotate = true;
        }
        return true;
    }

    bool
    mouseReleased( const OIS::MouseEvent& e, OIS::MouseButtonID id )
    {
        if( id == OIS::MB_Right )
        {
            m_MouseRotate = false;
        }

        return true;
    }

public:
    Ogre::TextAreaOverlayElement*   info_text;
    Ogre::Overlay*                  info_overlay;

private:
    Ogre::RenderWindow* m_Window;

    //OIS Input devices
    OIS::InputManager*  m_InputManager;
    OIS::Keyboard*      m_Keyboard;
    OIS::Mouse*         m_Mouse;
    float               m_MouseMoveX;
    float               m_MouseMoveY;
    bool                m_MouseRotate;
    bool                m_Exit;
};

void
InitializeOgreBase( const Ogre::String& name );

void
DeinitializeOgreBase();

#endif // __OGRE_BASE_H__
