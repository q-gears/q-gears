#include "UiManager.h"

#include "ConfigVar.h"
#include "DebugDraw.h"
#include "ScriptManager.h"



ConfigVar cv_debug_ui( "debug_ui", "Draw ui debug info", "false" );



template<>UiManager *Ogre::Singleton< UiManager >::ms_Singleton = NULL;



UiManager::UiManager()
{
    m_BaseWidget = new UiWidget( "ui" );

    Ogre::Root::getSingleton().getSceneManager( "Scene" )->addRenderQueueListener( this );
}



UiManager::~UiManager()
{
    Ogre::Root::getSingleton().getSceneManager( "Scene" )->removeRenderQueueListener( this );

    delete m_BaseWidget;
}



void
UiManager::Initialise()
{
    // <test code>
    ScriptManager::getSingleton().RunFile( "ui/screens/start_menu.lua" );



    UiWidget* widget = new UiWidget( "StartScreen", m_BaseWidget );

    UiWidget* widget1 = new UiWidget( "StartScreen.Background", widget );
    widget1->SetColour( 1, 1, 1, 1 );
    widget1->Quad( 10, 10, 100, 10, 100, 100, 10, 100 );
    widget->AddChild( widget1 );
    UiWidget* widget2 = new UiWidget( "StartScreen.StartButton", widget );
    widget2->SetColour( 1, 0, 0, 1 );
    widget2->Quad( 20, 20, 90, 20, 90, 30, 20, 30 );
    widget->AddChild( widget2 );
    UiWidget* widget3 = new UiWidget( "StartScreen.ContinueButton", widget );
    widget3->SetColour( 0, 1, 0, 1 );
    widget3->Quad( 20, 40, 90, 40, 90, 50, 20, 50 );
    widget->AddChild( widget3 );
    UiWidget* widget4 = new UiWidget( "StartScreen.Cursor", widget );
    widget4->SetColour( 0, 0, 0, 1 );
    widget4->Quad( 10, 20, 20, 20, 20, 30, 10, 30 );
    widget->AddChild( widget4 );
    m_BaseWidget->AddChild( widget );
    // </test code>
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
