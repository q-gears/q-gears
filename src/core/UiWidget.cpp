#include "UiWidget.h"

#include <OgreHardwareBufferManager.h>
#include <OgreMaterialManager.h>

#include "Logger.h"
#include "ScriptManager.h"



UiWidget::UiWidget( const Ogre::String& name ):
    m_Name( name ),
    m_PathName( name ),
    m_Parent( NULL ),
    m_Colour( 1, 1, 1, 1 ),
    m_Visible( false ),

    m_Align( LEFT ),
    m_VerticalAlign( TOP ),
    m_X( 0 ),
    m_XPercent( false ),
    m_Y( 0 ),
    m_YPercent( false ),
    m_Width( 100 ),
    m_WidthPercent( true ),
    m_Height( 100 ),
    m_HeightPercent( true )
{
    Initialise();
}



UiWidget::UiWidget( const Ogre::String& name, const Ogre::String& path_name, UiWidget* parent ):
    m_Name( name ),
    m_PathName( path_name ),
    m_Parent( parent ),
    m_Colour( 1, 1, 1, 1 ),
    m_Visible( false ),

    m_Align( LEFT ),
    m_VerticalAlign( TOP ),
    m_X( 0 ),
    m_XPercent( false ),
    m_Y( 0 ),
    m_YPercent( false ),
    m_Width( 100 ),
    m_WidthPercent( true ),
    m_Height( 100 ),
    m_HeightPercent( true )
{
    Initialise();
}



UiWidget::~UiWidget()
{
    ScriptManager::getSingleton().RemoveEntity( "Ui." + m_PathName );

    RemoveAllChildren();

    DestroyQuadVertexBuffer();
}



void
UiWidget::Initialise()
{
    ScriptManager::getSingleton().AddEntity( "Ui." + m_PathName );

    m_SceneManager = Ogre::Root::getSingleton().getSceneManager( "Scene" );
    m_RenderSystem = Ogre::Root::getSingletonPtr()->getRenderSystem();

    m_Material = Ogre::MaterialManager::getSingleton().create( "DebugDraw", "General" );
    Ogre::Pass* pass = m_Material->getTechnique( 0 )->getPass( 0 );
    pass->setVertexColourTracking( Ogre::TVC_AMBIENT );
    pass->setCullingMode( Ogre::CULL_NONE );
    pass->setDepthCheckEnabled( false );
    pass->setDepthWriteEnabled( false );
    pass->setLightingEnabled( false );
    pass->setSceneBlending( Ogre::SBT_TRANSPARENT_ALPHA );

    CreateQuadVertexBuffer();
}



void
UiWidget::Update()
{
    for( int i = 0; i < m_Children.size(); ++i )
    {
        m_Children[ i ]->Update();
    }
}



void
UiWidget::OnResize()
{
    GeometryUpdate();

    for( int i = 0; i < m_Children.size(); ++i )
    {
        m_Children[ i ]->OnResize();
    }
}



void
UiWidget::Render()
{
    if( m_Visible == true )
    {
        if( m_QuadRenderOp.vertexData->vertexCount != 0 )
        {
            m_RenderSystem->_setWorldMatrix( Ogre::Matrix4::IDENTITY );
            m_RenderSystem->_setProjectionMatrix( Ogre::Matrix4::IDENTITY );
            m_RenderSystem->_setViewMatrix( Ogre::Matrix4::IDENTITY );

            m_SceneManager->_setPass( m_Material->getTechnique( 0 )->getPass( 0 ), true, false );
            m_RenderSystem->_render( m_QuadRenderOp );
        }

        // render all child of this widget
        for( int i = 0; i < m_Children.size(); ++i )
        {
            m_Children[ i ]->Render();
        }
    }
}



const Ogre::String&
UiWidget::GetName() const
{
    return m_Name;
}



void
UiWidget::AddChild( UiWidget *widget )
{
    m_Children.push_back( widget );
}



UiWidget*
UiWidget::GetChild( const Ogre::String& name )
{
    for( int i = 0; i < m_Children.size(); ++i )
    {
        if( m_Children[ i ]->GetName() == name )
        {
            return m_Children[ i ];
        }
    }

    return NULL;
}



void
UiWidget::RemoveAllChildren()
{
    for( int i = 0; i < m_Children.size(); ++i )
    {
        delete m_Children[ i ];
    }
    m_Children.clear();
}



void
UiWidget::SetColour( const float r, const float g, const float b, const float a )
{
    m_Colour.r = r;
    m_Colour.g = g;
    m_Colour.b = b;
    m_Colour.a = a;
}



void
UiWidget::SetAlign( const UiWidget::Align align )
{
    m_Align = align;
}



void
UiWidget::SetVerticalAlign( const UiWidget::VerticalAlign valign )
{
    m_VerticalAlign = valign;
}



void
UiWidget::SetX( const float x, const bool percent )
{
    m_X = x;
    m_XPercent = percent;
}



float
UiWidget::GetScreenX() const
{
    float screen_width = Ogre::Root::getSingleton().getRenderTarget( "QGearsWindow" )->getViewport( 0 )->getActualWidth();
    float screen_height = Ogre::Root::getSingleton().getRenderTarget( "QGearsWindow" )->getViewport( 0 )->getActualHeight();

    float area_x = ( m_Parent != NULL ) ? m_Parent->GetScreenX() : 0;
    float area_width = ( m_Parent != NULL ) ? m_Parent->GetScreenWidth() : screen_width;

    // calculate base x depending in aligment
    float base_x = area_x;
    if( m_Align == RIGHT )
    {
        base_x = area_x + area_width;
    }
    else if( m_Align == CENTER )
    {
        base_x = area_x + area_width / 2;
    }

    return base_x + ( ( m_XPercent == true ) ? ( area_width * m_X ) / 100.0f : m_X * screen_height / 720.0f );
}



void
UiWidget::SetY( const float y, const bool percent )
{
    m_Y = y;
    m_YPercent = percent;
}



float
UiWidget::GetScreenY() const
{
    float screen_height = Ogre::Root::getSingleton().getRenderTarget( "QGearsWindow" )->getViewport( 0 )->getActualHeight();

    float area_y = ( m_Parent != NULL ) ? m_Parent->GetScreenY() : 0;
    float area_height = ( m_Parent != NULL ) ? m_Parent->GetScreenHeight() : screen_height;

    // calculate base y depending in vertical aligment
    float base_y = area_y;
    if( m_VerticalAlign == BOTTOM )
    {
        base_y = area_y + area_height;
    }
    else if( m_VerticalAlign == MIDDLE )
    {
        base_y = area_y + area_height / 2;
    }

    //LOG_ERROR( m_Name + ": area_y = " + Ogre::StringConverter::toString( area_y ) + ", area_height = " + Ogre::StringConverter::toString( area_height ) + ", base_y = " + Ogre::StringConverter::toString( base_y ) );

    return base_y + ( ( m_YPercent == true ) ? ( area_height * m_Y ) / 100.0f : m_Y * screen_height / 720.0f );
}



void
UiWidget::SetWidth( const float width, const bool percent )
{
    m_Width = width;
    m_WidthPercent = percent;
}



float
UiWidget::GetScreenWidth() const
{
    float screen_width = Ogre::Root::getSingleton().getRenderTarget( "QGearsWindow" )->getViewport( 0 )->getActualWidth();
    float screen_height = Ogre::Root::getSingleton().getRenderTarget( "QGearsWindow" )->getViewport( 0 )->getActualHeight();
    float area_width = ( m_Parent != NULL ) ? m_Parent->GetScreenWidth() : screen_width;
    return ( m_WidthPercent == true ) ? ( area_width * m_Width ) / 100.0f : m_Width * screen_height / 720.0f;
}



void
UiWidget::SetHeight( const float height, const bool percent )
{
    m_Height = height;
    m_HeightPercent = percent;
}



float
UiWidget::GetScreenHeight() const
{
    float screen_height = Ogre::Root::getSingleton().getRenderTarget( "QGearsWindow" )->getViewport( 0 )->getActualHeight();
    float area_height = ( m_Parent != NULL ) ? m_Parent->GetScreenHeight() : screen_height;
    return ( m_HeightPercent == true ) ? ( area_height * m_Height ) / 100.0f : m_Height * screen_height / 720.0f;
}



void
UiWidget::GeometryUpdate()
{
    int x1 = GetScreenX();
    int y1 = GetScreenY();
    int width = GetScreenWidth();
    int height = GetScreenHeight();
    int x2 = x1 + width;
    int y2 = y1;
    int x3 = x2;
    int y3 = y2 + height;
    int x4 = x1;
    int y4 = y3;

    //LOG_ERROR( m_Name );
    //LOG_ERROR( "width = " + Ogre::StringConverter::toString( width ) + ", height = " + Ogre::StringConverter::toString( height ) );
    //LOG_ERROR( "x1 = " + Ogre::StringConverter::toString( x1 ) + ", y1 = " + Ogre::StringConverter::toString( y1 ) );

    float screen_width = Ogre::Root::getSingleton().getRenderTarget( "QGearsWindow" )->getViewport( 0 )->getActualWidth();
    float screen_height = Ogre::Root::getSingleton().getRenderTarget( "QGearsWindow" )->getViewport( 0 )->getActualHeight();
    float new_x1 = ( x1 / screen_width ) * 2 - 1;
    float new_y1 = -( ( y1 / screen_height ) * 2 - 1 );
    float new_x2 = ( x2 / screen_width ) * 2 - 1;
    float new_y2 = -( ( y2 / screen_height ) * 2 - 1 );
    float new_x3 = ( x3 / screen_width ) * 2 - 1;
    float new_y3 = -( ( y3 / screen_height ) * 2 - 1 );
    float new_x4 = ( x4 / screen_width ) * 2 - 1;
    float new_y4 = -( ( y4 / screen_height ) * 2 - 1 );

    float* writeIterator = ( float* ) m_QuadVertexBuffer->lock( Ogre::HardwareBuffer::HBL_NORMAL );

    *writeIterator++ = new_x1;
    *writeIterator++ = new_y1;
    *writeIterator++ = 0; // z
    *writeIterator++ = m_Colour.r;
    *writeIterator++ = m_Colour.g;
    *writeIterator++ = m_Colour.b;
    *writeIterator++ = m_Colour.a;

    *writeIterator++ = new_x2;
    *writeIterator++ = new_y2;
    *writeIterator++ = 0; // z
    *writeIterator++ = m_Colour.r;
    *writeIterator++ = m_Colour.g;
    *writeIterator++ = m_Colour.b;
    *writeIterator++ = m_Colour.a;

    *writeIterator++ = new_x3;
    *writeIterator++ = new_y3;
    *writeIterator++ = 0; // z
    *writeIterator++ = m_Colour.r;
    *writeIterator++ = m_Colour.g;
    *writeIterator++ = m_Colour.b;
    *writeIterator++ = m_Colour.a;

    *writeIterator++ = new_x1;
    *writeIterator++ = new_y1;
    *writeIterator++ = 0; // z
    *writeIterator++ = m_Colour.r;
    *writeIterator++ = m_Colour.g;
    *writeIterator++ = m_Colour.b;
    *writeIterator++ = m_Colour.a;

    *writeIterator++ = new_x3;
    *writeIterator++ = new_y3;
    *writeIterator++ = 0; // z
    *writeIterator++ = m_Colour.r;
    *writeIterator++ = m_Colour.g;
    *writeIterator++ = m_Colour.b;
    *writeIterator++ = m_Colour.a;

    *writeIterator++ = new_x4;
    *writeIterator++ = new_y4;
    *writeIterator++ = 0; // z
    *writeIterator++ = m_Colour.r;
    *writeIterator++ = m_Colour.g;
    *writeIterator++ = m_Colour.b;
    *writeIterator++ = m_Colour.a;

    m_QuadRenderOp.vertexData->vertexCount = 6;

    m_QuadVertexBuffer->unlock();
}



void
UiWidget::Show()
{
    m_Visible = true;
    ScriptManager::getSingleton().ScriptRequest( ( "Ui." + m_PathName ).c_str(), "on_show", 0 );
}



void
UiWidget::Hide()
{
    m_Visible = false;
    ScriptManager::getSingleton().ScriptRequest( ( "Ui." + m_PathName ).c_str(), "on_hide", 0 );
}



void
UiWidget::CreateQuadVertexBuffer()
{
    m_QuadRenderOp.vertexData = new Ogre::VertexData;
    m_QuadRenderOp.vertexData->vertexStart = 0;

    Ogre::VertexDeclaration* vDecl = m_QuadRenderOp.vertexData->vertexDeclaration;

    size_t offset = 0;
    vDecl->addElement( 0, 0, Ogre::VET_FLOAT3, Ogre::VES_POSITION );
    offset += Ogre::VertexElement::getTypeSize( Ogre::VET_FLOAT3 );
    vDecl->addElement( 0, offset, Ogre::VET_FLOAT4, Ogre::VES_DIFFUSE );

    m_QuadVertexBuffer = Ogre::HardwareBufferManager::getSingletonPtr()->createVertexBuffer( vDecl->getVertexSize( 0 ), 6, Ogre::HardwareBuffer::HBU_DYNAMIC_WRITE_ONLY, false );

    m_QuadRenderOp.vertexData->vertexBufferBinding->setBinding( 0, m_QuadVertexBuffer );
    m_QuadRenderOp.operationType = Ogre::RenderOperation::OT_TRIANGLE_LIST;
    m_QuadRenderOp.useIndexes = false;
}



void
UiWidget::DestroyQuadVertexBuffer()
{
    delete m_QuadRenderOp.vertexData;
    m_QuadRenderOp.vertexData = 0;
    m_QuadVertexBuffer.setNull();
}
