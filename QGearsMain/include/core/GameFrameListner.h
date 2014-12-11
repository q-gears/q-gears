#ifndef GAME_FRAME_LISTENER_H
#define GAME_FRAME_LISTENER_H

#include <OgreFrameListener.h>
#include <OgreRenderWindow.h>
#include <OgreWindowEventUtilities.h>
#include <OIS.h>



class GameFrameListener : public Ogre::FrameListener, public Ogre::WindowEventListener, public OIS::KeyListener, public OIS::MouseListener
{
public:
                 GameFrameListener( Ogre::RenderWindow* win );
    virtual     ~GameFrameListener();

    bool         frameStarted( const Ogre::FrameEvent& evt );
    bool         frameEnded( const Ogre::FrameEvent& evt );

    virtual void windowMoved( Ogre::RenderWindow *rw );
    virtual void windowResized( Ogre::RenderWindow *rw );
    virtual void windowClosed( Ogre::RenderWindow* rw );
    virtual void windowFocusChange( Ogre::RenderWindow *rw );

    bool         keyPressed( const OIS::KeyEvent& e );
    bool         keyReleased( const OIS::KeyEvent& e );

    bool         mouseMoved( const OIS::MouseEvent &e );
    bool         mousePressed( const OIS::MouseEvent &e, OIS::MouseButtonID id );
    bool         mouseReleased( const OIS::MouseEvent &e, OIS::MouseButtonID id );

protected:
    Ogre::RenderWindow* m_Window;

    OIS::InputManager*  m_InputManager;
    OIS::Keyboard*      m_Keyboard;
    OIS::Mouse*         m_Mouse;
};



#endif // GAME_FRAME_LISTENER_H
