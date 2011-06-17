#include "UiManager.h"

#include "ConfigVar.h"
#include "DebugDraw.h"



ConfigVar cv_debug_ui( "debug_ui", "Draw ui debug info", "false" );



template<>UiManager *Ogre::Singleton< UiManager >::ms_Singleton = NULL;



UiManager::UiManager()
{
    m_BaseWidget = new UiWidget( "UI" );
}



UiManager::~UiManager()
{
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
