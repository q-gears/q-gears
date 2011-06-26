#include "UiManager.h"

#include <OgreStringVector.h>

#include "ConfigVar.h"
#include "DebugDraw.h"
#include "Logger.h"
#include "ScriptManager.h"
#include "Utilites.h"
#include "XmlScreensFile.h"



ConfigVar cv_debug_ui( "debug_ui", "Draw ui debug info", "false" );



template<>UiManager *Ogre::Singleton< UiManager >::ms_Singleton = NULL;



UiManager::UiManager()
{
    Ogre::Root::getSingleton().getSceneManager( "Scene" )->addRenderQueueListener( this );
}



UiManager::~UiManager()
{
    Ogre::Root::getSingleton().getSceneManager( "Scene" )->removeRenderQueueListener( this );

    for( int i = 0; i < m_Widgets.size(); ++i )
    {
        delete m_Widgets[ i ];
    }
}



void
UiManager::Initialise()
{
    XmlScreensFile screens( "./data/ui/screens.xml" );
    screens.LoadScreens();
}



void
UiManager::Update()
{
    for( int i = 0; i < m_Widgets.size(); ++i )
    {
        m_Widgets[ i ]->Update();
    }



    // debug output
    if( cv_debug_ui.GetB() == true )
    {
        DEBUG_DRAW.SetScreenSpace( true );
        DEBUG_DRAW.SetTextAlignment( DEBUG_DRAW.LEFT );
        DEBUG_DRAW.Text( 100, 100, "TEST" );
    }
}



void
UiManager::OnResize()
{
    for( int i = 0; i < m_Widgets.size(); ++i )
    {
        m_Widgets[ i ]->OnResize();
    }
}



void
UiManager::AddWidget( UiWidget* widget )
{
    m_Widgets.push_back( widget );
}



UiWidget*
UiManager::GetWidget( const Ogre::String& name )
{
    // get real table by name
    Ogre::StringVector table_path = StringTokenise( name, "." );
    UiWidget* widget = NULL;

    if( table_path.size() > 0 )
    {
        for( int i = 0; i < m_Widgets.size(); ++i )
        {
            if( m_Widgets[ i ]->GetName() == table_path[ 0 ] )
            {
                widget = m_Widgets[ i ];

                for( int j = 1; ( j < table_path.size() ) && ( widget != NULL ); ++j )
                {
                    widget = widget->GetChild( table_path[ j ] );
                }
            }
        }
    }

    return widget;
}



UiWidget*
UiManager::ScriptGetWidget( const char* name )
{
    return GetWidget( Ogre::String( name ) );
}



void
UiManager::renderQueueEnded( Ogre::uint8 queueGroupId, const Ogre::String& invocation, bool& repeatThisInvocation )
{
    if( queueGroupId == Ogre::RENDER_QUEUE_OVERLAY )
    {
        for( int i = 0; i < m_Widgets.size(); ++i)
        {
            m_Widgets[ i ]->Render();
        }
    }
}
