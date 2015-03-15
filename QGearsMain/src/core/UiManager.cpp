#include <OgreRoot.h>
#include <OgreStringVector.h>

#include "core/Logger.h"
#include "core/ScriptManager.h"
#include "core/UiManager.h"
#include "core/Utilites.h"
#include "core/XmlFontsFile.h"
#include "core/XmlPrototypesFile.h"
#include "core/XmlScreensFile.h"
#include "core/XmlTextsFile.h"
#include "core/TextManager.h"

template<>UiManager *Ogre::Singleton<UiManager>::msSingleton = nullptr;


UiManager::UiManager()
{
    Ogre::Root::getSingleton().getSceneManager("Scene")->addRenderQueueListener(this);
}


UiManager::~UiManager()
{
    Ogre::Root::getSingleton().getSceneManager("Scene")->removeRenderQueueListener(this);


    for(size_t i = 0; i < m_Fonts.size(); ++i)
    {
        delete m_Fonts[i];
    }

    for(size_t i = 0; i < m_Widgets.size(); ++i)
    {
        delete m_Widgets[i];
    }
}


void
UiManager::Initialise()
{
    XmlFontsFile fonts("./data/fonts.xml");
    fonts.LoadFonts();


    XmlScreensFile screens("./data/screens.xml");
    screens.LoadScreens();
}


void
UiManager::Update()
{
    // update all ui scripts
    ScriptManager::getSingleton().Update(ScriptManager::UI);
    for(unsigned int i = 0; i < m_Widgets.size(); ++i)
    {
        m_Widgets[i]->Update();
    }
}


void
UiManager::OnResize()
{
    for(unsigned int i = 0; i < m_Widgets.size(); ++i)
    {
        m_Widgets[i]->OnResize();
    }
}



void
UiManager::AddFont( UiFont* font )
{
    m_Fonts.push_back( font );
}



UiFont*
UiManager::GetFont( const Ogre::String& name )
{
    Ogre::String language = TextManager::getSingleton().GetLanguage();

    for( unsigned int i = 0; i < m_Fonts.size(); ++i )
    {
        if( m_Fonts[ i ]->GetName() == name )
        {
            Ogre::String f_lang = m_Fonts[ i ]->GetLanguage();
            if( ( f_lang == "" ) || ( f_lang == language ) )
            {
                return m_Fonts[ i ];
            }
        }
    }

    return NULL;
}



void
UiManager::AddPrototype( const Ogre::String& name, TiXmlNode* prototype )
{
    UiPrototype ui_prototype;
    ui_prototype.name = name;
    ui_prototype.node = prototype;
    m_Prototypes.push_back( ui_prototype );
}



TiXmlNode*
UiManager::GetPrototype( const Ogre::String& name ) const
{
    for( unsigned int i = 0; i < m_Prototypes.size(); ++i )
    {
        if( m_Prototypes[ i ].name == name )
        {
            return m_Prototypes[ i ].node;
        }
    }

    return NULL;
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
        for( unsigned int i = 0; i < m_Widgets.size(); ++i )
        {
            if( m_Widgets[ i ]->GetName() == table_path[ 0 ] )
            {
                widget = m_Widgets[ i ];

                for( unsigned int j = 1; ( j < table_path.size() ) && ( widget != NULL ); ++j )
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
UiManager::renderQueueStarted( Ogre::uint8 queueGroupId, const Ogre::String& invocation, bool& skipThisInvocation )
{
    if( queueGroupId == Ogre::RENDER_QUEUE_OVERLAY )
    {
        Ogre::Root::getSingletonPtr()->getRenderSystem()->clearFrameBuffer( Ogre::FBT_DEPTH );

        for( unsigned int i = 0; i < m_Widgets.size(); ++i)
        {
            m_Widgets[ i ]->Render();
        }
    }
}
