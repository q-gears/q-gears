#include "UiWidget.h"

#include <OgreMath.h>
#include <OgreRoot.h>

#include "ConfigVar.h"
#include "Logger.h"
#include "ScriptManager.h"



ConfigVar cv_debug_ui( "debug_ui", "Draw ui debug info", "false" );



UiWidget::UiWidget( const Ogre::String& name ):
    m_Name( name ),
    m_PathName( name ),
    m_Parent( NULL )
{
    Initialise();
}



UiWidget::UiWidget( const Ogre::String& name, const Ogre::String& path_name, UiWidget* parent ):
    m_Name( name ),
    m_PathName( path_name ),
    m_Parent( parent )
{
    Initialise();
}



UiWidget::~UiWidget()
{
    ScriptManager::getSingleton().RemoveEntity( "Ui." + m_PathName );

    RemoveAllChildren();
}



void
UiWidget::Initialise()
{
    m_ScreenWidth = Ogre::Root::getSingleton().getRenderTarget( "QGearsWindow" )->getViewport( 0 )->getActualWidth();
    m_ScreenHeight = Ogre::Root::getSingleton().getRenderTarget( "QGearsWindow" )->getViewport( 0 )->getActualHeight();

    m_Visible = false;

    m_Align = LEFT;
    m_VerticalAlign = TOP;
    m_OriginX = 0;
    m_OriginXAdd = 0;
    m_OriginXPercent = false;
    m_OriginY = 0;
    m_OriginYAdd = 0;
    m_OriginYPercent = false;
    m_X = 0;
    m_XAdd = 0;
    m_XPercent = false;
    m_Y = 0;
    m_YAdd = 0;
    m_YPercent = false;
    m_Width = 100;
    m_WidthAdd = 0;
    m_WidthPercent = true;
    m_Height = 100;
    m_HeightAdd = 0;
    m_HeightPercent = true;
    m_ScaleX = 1.0f;
    m_ScaleY = 1.0f;
    m_Rotation = 0.0f;

    m_Scissor = false;
    m_ScissorTop = 0;
    m_ScissorBottom = m_ScreenHeight;
    m_ScissorLeft = 0;
    m_ScissorRight = m_ScreenWidth;

    ScriptManager::getSingleton().AddEntity( "Ui." + m_PathName );
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
    m_ScreenWidth = Ogre::Root::getSingleton().getRenderTarget( "QGearsWindow" )->getViewport( 0 )->getActualWidth();
    m_ScreenHeight = Ogre::Root::getSingleton().getRenderTarget( "QGearsWindow" )->getViewport( 0 )->getActualHeight();

    ScissorUpdate();

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
        for( int i = 0; i < m_Children.size(); ++i )
        {
            m_Children[ i ]->Render();
        }
    }
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
UiWidget::SetOriginX( const float x, const float add, const bool percent )
{
    m_OriginX = x;
    m_OriginXAdd = add;
    m_OriginXPercent = percent;
}



float
UiWidget::GetFinalOriginX() const
{
    return ( m_OriginXPercent == true ) ? ( GetFinalWidth() * m_OriginX ) / 100.0f + m_OriginXAdd * m_ScreenHeight / 720.0f : m_OriginX * m_ScreenHeight / 720.0f;
}



void
UiWidget::SetOriginY( const float y, const float add, const bool percent )
{
    m_OriginY = y;
    m_OriginYAdd = add;
    m_OriginYPercent = percent;
}



float
UiWidget::GetFinalOriginY() const
{
    return ( m_OriginYPercent == true ) ? ( GetFinalHeight() * m_OriginY ) / 100.0f + m_OriginYAdd * m_ScreenHeight / 720.0f : m_OriginY * m_ScreenHeight / 720.0f;
}



void
UiWidget::SetX( const float x, const float add, const bool percent )
{
    m_X = x;
    m_XAdd = add;
    m_XPercent = percent;
}



float
UiWidget::GetLocalX() const
{
    float area_width = ( m_Parent != NULL ) ? m_Parent->GetFinalWidth() : m_ScreenWidth;

    return ( m_XPercent == true ) ? ( area_width * m_X * m_ScaleX ) / 100.0f + ( m_XAdd * m_ScreenHeight / 720.0f) * GetFinalScaleX() : ( m_X * m_ScreenHeight / 720.0f ) * GetFinalScaleX();
}



float
UiWidget::GetFinalX() const
{
    float area_x = ( m_Parent != NULL ) ? m_Parent->GetFinalX() : 0;
    float area_origin_x = ( m_Parent != NULL ) ? m_Parent->GetFinalOriginX() : 0;
    float area_width = ( m_Parent != NULL ) ? m_Parent->GetFinalWidth() : m_ScreenWidth;
    float area_rotation = ( m_Parent != NULL ) ? m_Parent->GetFinalRotation() : 0;

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

    float x = GetLocalX() - area_origin_x;

    if( area_rotation != 0 )
    {
        float cos = Ogre::Math::Cos( Ogre::Radian( Ogre::Degree( area_rotation ) ) );
        float sin = Ogre::Math::Sin( Ogre::Radian( Ogre::Degree( area_rotation ) ) );
        float area_origin_y = ( m_Parent != NULL ) ? m_Parent->GetFinalOriginY() : 0;
        float y = GetLocalY() - area_origin_y;
        x = x * cos - y * sin;
    }

    return x + base_x;
}



void
UiWidget::SetY( const float y, const float add, const bool percent )
{
    m_Y = y;
    m_YAdd = add;
    m_YPercent = percent;
}



float
UiWidget::GetLocalY() const
{
    float area_height = ( m_Parent != NULL ) ? m_Parent->GetFinalHeight() : m_ScreenHeight;

    return ( m_YPercent == true ) ? ( area_height * m_Y * m_ScaleY ) / 100.0f + ( m_YAdd * m_ScreenHeight / 720.0f ) * GetFinalScaleY() : ( m_Y * m_ScreenHeight / 720.0f ) * GetFinalScaleY();
}



float
UiWidget::GetFinalY() const
{
    float area_y = ( m_Parent != NULL ) ? m_Parent->GetFinalY() : 0;
    float area_origin_y = ( m_Parent != NULL ) ? m_Parent->GetFinalOriginY() : 0;
    float area_height = ( m_Parent != NULL ) ? m_Parent->GetFinalHeight() : m_ScreenHeight;
    float area_rotation = ( m_Parent != NULL ) ? m_Parent->GetFinalRotation() : 0;

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

    float y = GetLocalY() - area_origin_y;

    if( area_rotation != 0 )
    {
        float cos = Ogre::Math::Cos( Ogre::Radian( Ogre::Degree( area_rotation ) ) );
        float sin = Ogre::Math::Sin( Ogre::Radian( Ogre::Degree( area_rotation ) ) );
        float area_origin_x = ( m_Parent != NULL ) ? m_Parent->GetFinalOriginX() : 0;
        float x = GetLocalX() - area_origin_x;

        y = x * sin + y * cos;
    }

    return y + base_y;
}



void
UiWidget::SetWidth( const float width, const float add, const bool percent )
{
    m_Width = width;
    m_WidthAdd = add;
    m_WidthPercent = percent;
}



float
UiWidget::GetFinalWidth() const
{
    float area_width = ( m_Parent != NULL ) ? m_Parent->GetFinalWidth() : m_ScreenWidth;
    return ( m_WidthPercent == true ) ? ( area_width * m_Width * m_ScaleX ) / 100.0f + ( m_WidthAdd * m_ScreenHeight / 720.0f ) * GetFinalScaleX() : ( m_Width * m_ScreenHeight / 720.0f) * GetFinalScaleX();
}



void
UiWidget::SetHeight( const float height, const float add, const bool percent )
{
    m_Height = height;
    m_HeightAdd = add;
    m_HeightPercent = percent;
}



float
UiWidget::GetFinalHeight() const
{
    float area_height = ( m_Parent != NULL ) ? m_Parent->GetFinalHeight() : m_ScreenHeight;
    return ( m_HeightPercent == true ) ? ( area_height * m_Height * m_ScaleY ) / 100.0f + ( m_HeightAdd * m_ScreenHeight / 720.0f ) * GetFinalScaleY() : ( m_Height * m_ScreenHeight / 720.0f ) * GetFinalScaleY();
}



void
UiWidget::SetScale( const Ogre::Vector2& scale )
{
    m_ScaleX = scale.x;
    m_ScaleY = scale.y;
}



float
UiWidget::GetFinalScaleX() const
{
    return ( m_Parent != NULL ) ? m_Parent->GetFinalScaleX() * m_ScaleX : m_ScaleX;
}



float
UiWidget::GetFinalScaleY() const
{
    return ( m_Parent != NULL ) ? m_Parent->GetFinalScaleY() * m_ScaleY : m_ScaleY;
}



void
UiWidget::SetRotation( const float degree )
{
    m_Rotation = degree;
}



float
UiWidget::GetFinalRotation() const
{
    return ( m_Parent != NULL ) ? m_Parent->GetFinalRotation() + m_Rotation : m_Rotation;
}



void
UiWidget::SetScissor( bool scissor )
{
    m_Scissor = scissor;
}



int
UiWidget::GetScissorTop() const
{
    return m_ScissorTop;
}



int
UiWidget::GetScissorBottom() const
{
    return m_ScissorBottom;
}



int
UiWidget::GetScissorLeft() const
{
    return m_ScissorLeft;
}



int
UiWidget::GetScissorRight() const
{
    return m_ScissorRight;
}



void
UiWidget::ScissorUpdate()
{
    m_ScissorTop = ( m_Parent != NULL ) ? m_Parent->GetScissorTop() : 0;
    m_ScissorBottom = ( m_Parent != NULL ) ? m_Parent->GetScissorBottom() : m_ScreenHeight;
    m_ScissorLeft = ( m_Parent != NULL ) ? m_Parent->GetScissorLeft() : 0;
    m_ScissorRight = ( m_Parent != NULL ) ? m_Parent->GetScissorRight() : m_ScreenWidth;

    if( m_Scissor == true )
    {
        float local_x1 = -GetFinalOriginX();
        float local_y1 = -GetFinalOriginY();
        float local_x2 = GetFinalWidth() + local_x1;
        float local_y2 = GetFinalHeight() + local_y1;
        float x = GetFinalX();
        float y = GetFinalY();

        int x1, y1, x2, y2, x3, y3, x4, y4;
        float width, height;

        float rotation = GetFinalRotation();

        //LOG_ERROR( m_Name + ", rotation = " + Ogre::StringConverter::toString( rotation ) );
        //LOG_ERROR( "local_x1 = " + Ogre::StringConverter::toString( local_x1 ) + ", local_y1 = " + Ogre::StringConverter::toString( local_y1 ) );
        //LOG_ERROR( "local_x2 = " + Ogre::StringConverter::toString( local_x2 ) + ", local_y2 = " + Ogre::StringConverter::toString( local_y2 ) );

        if( rotation != 0 )
        {
            float cos = Ogre::Math::Cos( Ogre::Radian( Ogre::Degree( rotation ) ) );
            float sin = Ogre::Math::Sin( Ogre::Radian( Ogre::Degree( rotation ) ) );

            x1 = local_x1 * cos - local_y1 * sin + x;
            y1 = local_x1 * sin + local_y1 * cos + y;
            x2 = local_x2 * cos - local_y1 * sin + x;
            y2 = local_x2 * sin + local_y1 * cos + y;
            x3 = local_x2 * cos - local_y2 * sin + x;
            y3 = local_x2 * sin + local_y2 * cos + y;
            x4 = local_x1 * cos - local_y2 * sin + x;
            y4 = local_x1 * sin + local_y2 * cos + y;
        }
        else
        {
            x1 = local_x1 + x;
            y1 = local_y1 + y;
            x2 = local_x2 + x;
            y2 = local_y1 + y;
            x3 = local_x2 + x;
            y3 = local_y2 + y;
            x4 = local_x1 + x;
            y4 = local_y2 + y;
        }

        m_ScissorTop = std::max( m_ScissorTop, std::min( std::min( y1 , y2 ), std::min( y3 , y4 ) ) );
        m_ScissorBottom = std::min( m_ScissorBottom, std::max( std::max( y1 , y2 ), std::max( y3 , y4 ) ) );
        m_ScissorLeft = std::max( m_ScissorLeft, std::min( std::min( x1 , x2 ), std::min( x3 , x4 ) ) );
        m_ScissorRight = std::min( m_ScissorRight, std::max( std::max( x1 , x2 ), std::max( x3 , x4 ) ) );
    }
}
