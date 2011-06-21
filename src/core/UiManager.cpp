#include "UiManager.h"

#include "ConfigVar.h"
#include "DebugDraw.h"



ConfigVar cv_debug_ui( "debug_ui", "Draw ui debug info", "false" );



template<>UiManager *Ogre::Singleton< UiManager >::ms_Singleton = NULL;



UiManager::UiManager()
{
    m_BaseWidget = new UiWidget( "UI" );



    // <test code>
    UiWidget* widget = new UiWidget( "StartScreen" );

    UiWidget* widget1 = new UiWidget( "Background" );
    widget1->Quad( 0, 0, 10, 0, 10, 10, 0, 10 );
    widget->AddChild( widget1 );
    UiWidget* widget2 = new UiWidget( "StartButton" );
    widget1->Quad( 10, 10, 100, 10, 100, 100, 10, 100 );
    widget->AddChild( widget2 );
    UiWidget* widget3 = new UiWidget( "ContinueButton" );
    widget->AddChild( widget3 );
    UiWidget* widget4 = new UiWidget( "Cursor" );
    widget->AddChild( widget4 );
    m_BaseWidget->AddChild( widget );
    // </test code>



    Ogre::Root::getSingleton().getSceneManager( "Scene" )->addRenderQueueListener( this );
}



UiManager::~UiManager()
{
    Ogre::Root::getSingleton().getSceneManager( "Scene" )->removeRenderQueueListener( this );

    delete m_BaseWidget;
}



void
UiManager::Update()
{
    m_BaseWidget->Update();



    // debug output
    if( cv_debug_ui.GetB() == true )
    {
        DEBUG_DRAW.SetScreenSpace( true );
        DEBUG_DRAW.SetTextAlignment( DEBUG_DRAW.LEFT );
        DEBUG_DRAW.Text( 100, 100, "TEST" );
    }
}



void
UiManager::renderQueueEnded( Ogre::uint8 queueGroupId, const Ogre::String& invocation, bool& repeatThisInvocation )
{
    if( queueGroupId == Ogre::RENDER_QUEUE_OVERLAY )
    {
        m_BaseWidget->Render();
    }
}
