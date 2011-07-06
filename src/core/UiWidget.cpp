#include "UiWidget.h"

#include <OgreMath.h>
#include <OgreRoot.h>

#include "ConfigVar.h"
#include "Logger.h"
#include "ScriptManager.h"
#include "Timer.h"



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
    delete m_Animation;

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

    m_FinalOrigin = Ogre::Vector2::ZERO;
    m_FinalTranslate = Ogre::Vector2::ZERO;
    m_FinalSize = Ogre::Vector2( m_ScreenWidth, m_ScreenHeight );
    m_FinalScale = Ogre::Vector2( 1, 1 );
    m_FinalRotation = 0;

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

    m_Animation = NULL;
    if( m_Name == "Dialog0" )
    {
        m_Animation = new UiAnimation( "Idle", this );
    }

    ScriptManager::getSingleton().AddEntity( "Ui." + m_PathName );
}



void
UiWidget::Update()
{
    if( m_Animation != NULL )
    {
        m_Animation->AddTime( Timer::getSingleton().GetGameTimeDelta() );
        OnResize();
    }

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

    UpdateTransformation();

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
UiWidget::UpdateTransformation()
{
    m_FinalScale = ( m_Parent != NULL ) ? m_Parent->GetFinalScale() * Ogre::Vector2( m_ScaleX, m_ScaleY ) : Ogre::Vector2( m_ScaleX, m_ScaleY );



    Ogre::Vector2 area_origin = ( m_Parent != NULL ) ? m_Parent->GetFinalOrigin() : Ogre::Vector2::ZERO;
    Ogre::Vector2 area_translate = ( m_Parent != NULL ) ? m_Parent->GetFinalTranslate() : Ogre::Vector2::ZERO;
    Ogre::Vector2 area_size = ( m_Parent != NULL ) ? m_Parent->GetFinalSize() : Ogre::Vector2( m_ScreenWidth, m_ScreenHeight );
    float area_rotation = ( m_Parent != NULL ) ? m_Parent->GetFinalRotation() : 0;

    float local_x = ( ( m_XPercent == true ) ? ( area_size.x * m_X * m_ScaleX ) / 100.0f + ( m_XAdd * m_ScreenHeight / 720.0f) * m_FinalScale.x : ( m_X * m_ScreenHeight / 720.0f ) * m_FinalScale.x ) - area_origin.x;
    float local_y = ( ( m_YPercent == true ) ? ( area_size.y * m_Y * m_ScaleY ) / 100.0f + ( m_YAdd * m_ScreenHeight / 720.0f ) * m_FinalScale.y : ( m_Y * m_ScreenHeight / 720.0f ) * m_FinalScale.y )  - area_origin.y;

    float x = local_x;
    float y = local_y;

    if( area_rotation != 0 )
    {
        float cos = Ogre::Math::Cos( Ogre::Radian( Ogre::Degree( area_rotation ) ) );
        float sin = Ogre::Math::Sin( Ogre::Radian( Ogre::Degree( area_rotation ) ) );
        x = local_x * cos - local_y * sin;
        y = local_x * sin + local_y * cos;
    }



    m_FinalTranslate.x = area_translate.x;
    if( m_Align == RIGHT )
    {
        m_FinalTranslate.x = area_translate.x + area_size.x;
    }
    else if( m_Align == CENTER )
    {
        m_FinalTranslate.x = area_translate.x + area_size.x / 2;
    }
    m_FinalTranslate.x += x;



    m_FinalTranslate.y = area_translate.y;
    if( m_VerticalAlign == BOTTOM )
    {
        m_FinalTranslate.y = area_translate.y + area_size.y;
    }
    else if( m_VerticalAlign == MIDDLE )
    {
        m_FinalTranslate.y = area_translate.y + area_size.y / 2;
    }
    m_FinalTranslate.y += y;



    m_FinalSize.x = ( m_WidthPercent == true ) ? ( area_size.x * m_Width * m_ScaleX ) / 100.0f + ( m_WidthAdd * m_ScreenHeight / 720.0f ) * m_FinalScale.x : ( m_Width * m_ScreenHeight / 720.0f) * m_FinalScale.x;
    m_FinalSize.y = ( m_HeightPercent == true ) ? ( area_size.y * m_Height * m_ScaleY ) / 100.0f + ( m_HeightAdd * m_ScreenHeight / 720.0f ) * m_FinalScale.y : ( m_Height * m_ScreenHeight / 720.0f ) * m_FinalScale.y;
    m_FinalOrigin.x = ( m_OriginXPercent == true ) ? ( m_FinalSize.x * m_OriginX ) / 100.0f + m_OriginXAdd * m_ScreenHeight / 720.0f : m_OriginX * m_ScreenHeight / 720.0f;
    m_FinalOrigin.y = ( m_OriginYPercent == true ) ? ( m_FinalSize.y * m_OriginY ) / 100.0f + m_OriginYAdd * m_ScreenHeight / 720.0f : m_OriginY * m_ScreenHeight / 720.0f;
    m_FinalRotation = area_rotation + m_Rotation;



    // scissor update
    m_ScissorTop = ( m_Parent != NULL ) ? m_Parent->GetScissorTop() : 0;
    m_ScissorBottom = ( m_Parent != NULL ) ? m_Parent->GetScissorBottom() : m_ScreenHeight;
    m_ScissorLeft = ( m_Parent != NULL ) ? m_Parent->GetScissorLeft() : 0;
    m_ScissorRight = ( m_Parent != NULL ) ? m_Parent->GetScissorRight() : m_ScreenWidth;

    if( m_Scissor == true )
    {
        float local_x1 = -m_FinalOrigin.x;
        float local_y1 = -m_FinalOrigin.y;
        float local_x2 = m_FinalSize.x + local_x1;
        float local_y2 = m_FinalSize.y + local_y1;
        float x = m_FinalTranslate.x;
        float y = m_FinalTranslate.y;

        int x1, y1, x2, y2, x3, y3, x4, y4;

        if( m_FinalRotation != 0 )
        {
            float cos = Ogre::Math::Cos( Ogre::Radian( Ogre::Degree( m_FinalRotation ) ) );
            float sin = Ogre::Math::Sin( Ogre::Radian( Ogre::Degree( m_FinalRotation ) ) );

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



Ogre::Vector2
UiWidget::GetFinalOrigin() const
{
    return m_FinalOrigin;
}



Ogre::Vector2
UiWidget::GetFinalTranslate() const
{
    return m_FinalTranslate;
}



Ogre::Vector2
UiWidget::GetFinalSize() const
{
    return m_FinalSize;
}



Ogre::Vector2
UiWidget::GetFinalScale() const
{
    return m_FinalScale;
}



float
UiWidget::GetFinalRotation() const
{
    return m_FinalRotation;
}



void
UiWidget::SetOriginX( const float x, const float add, const bool percent )
{
    m_OriginX = x;
    m_OriginXAdd = add;
    m_OriginXPercent = percent;
}



void
UiWidget::SetOriginY( const float y, const float add, const bool percent )
{
    m_OriginY = y;
    m_OriginYAdd = add;
    m_OriginYPercent = percent;
}



void
UiWidget::SetX( const float x, const float add, const bool percent )
{
    m_X = x;
    m_XAdd = add;
    m_XPercent = percent;
}



void
UiWidget::SetY( const float y, const float add, const bool percent )
{
    m_Y = y;
    m_YAdd = add;
    m_YPercent = percent;
}



void
UiWidget::SetWidth( const float width, const float add, const bool percent )
{
    m_Width = width;
    m_WidthAdd = add;
    m_WidthPercent = percent;
}



void
UiWidget::SetHeight( const float height, const float add, const bool percent )
{
    m_Height = height;
    m_HeightAdd = add;
    m_HeightPercent = percent;
}



void
UiWidget::SetScale( const Ogre::Vector2& scale )
{
    m_ScaleX = scale.x;
    m_ScaleY = scale.y;
}



void
UiWidget::SetRotation( const float degree )
{
    m_Rotation = degree;
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
