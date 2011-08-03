#include "UiWidget.h"

#include <OgreMath.h>
#include <OgreRoot.h>

#include "ConfigVar.h"
#include "DebugDraw.h"
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
    for( int i = 0; i < m_Animations.size(); ++i )
    {
        delete m_Animations[ i ];
    }

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

    m_OriginXPercent = 0;
    m_OriginX = 0;
    m_OriginYPercent = 0;
    m_OriginY = 0;
    m_XPercent = 0;
    m_X = 0;
    m_YPercent = 0;
    m_Y = 0;
    m_WidthPercent = 100;
    m_Width = 0;
    m_HeightPercent = 100;
    m_Height = 0;
    m_Scale = Ogre::Vector2( 1.0f, 1.0f );
    m_Rotation = 0.0f;

    m_Scissor = false;
    m_ScissorTop = 0;
    m_ScissorBottom = m_ScreenHeight;
    m_ScissorLeft = 0;
    m_ScissorRight = m_ScreenWidth;

    m_AnimationCurrent = NULL;
    m_AnimationDefault = "";
    m_AnimationState = UiAnimation::DEFAULT;
    m_Colour1 = Ogre::ColourValue( 1, 1, 1, 1 );
    m_Colour2 = Ogre::ColourValue( 1, 1, 1, 1 );
    m_Colour3 = Ogre::ColourValue( 1, 1, 1, 1 );
    m_Colour4 = Ogre::ColourValue( 1, 1, 1, 1 );

    ScriptManager::getSingleton().AddEntity( "Ui." + m_PathName );
}



void
UiWidget::Update()
{
    if( m_Visible != true )
    {
        return;
    }

    if( m_AnimationCurrent != NULL )
    {
        float delta_time = Timer::getSingleton().GetGameTimeDelta();
        float time = m_AnimationCurrent->GetTime();
        m_AnimationCurrent->AddTime( delta_time );

        // if animation ended
        if( time + delta_time >= m_AnimationEndTime )
        {
            for( int i = 0; i < m_AnimationSync.size(); ++i)
            {
                ScriptManager::getSingleton().ContinueScriptExecution( m_AnimationSync[ i ] );
            }
            m_AnimationSync.clear();

            if( m_AnimationState == UiAnimation::DEFAULT && m_AnimationDefault != "" )
            {
                // in case of cycled default we need to sync with end
                time = time + delta_time - m_AnimationCurrent->GetLength();
                PlayAnimation( m_AnimationDefault, UiAnimation::DEFAULT, time, -1 );

                if( m_AnimationCurrent != NULL ) // check if we can play default animation
                {
                    m_AnimationCurrent->AddTime( 0 );
                }
            }
        }

        OnResize();
    }
    else if( m_AnimationCurrent == NULL && m_AnimationState == UiAnimation::DEFAULT && m_AnimationDefault != "" )
    {
        PlayAnimation( m_AnimationDefault, UiAnimation::DEFAULT, 0, -1 );
    }



    for( int i = 0; i < m_Children.size(); ++i )
    {
        m_Children[ i ]->Update();
    }



    // debug output
    if( cv_debug_ui.GetB() == true )
    {
        float local_x1 = -m_FinalOrigin.x;
        float local_y1 = -m_FinalOrigin.y;
        float local_x2 = m_FinalSize.x + local_x1;
        float local_y2 = m_FinalSize.y + local_y1;
        float x = m_FinalTranslate.x;
        float y = m_FinalTranslate.y;

        DEBUG_DRAW.SetColour( Ogre::ColourValue::White );
        DEBUG_DRAW.SetScreenSpace( true );
        DEBUG_DRAW.SetTextAlignment( DEBUG_DRAW.LEFT );
        DEBUG_DRAW.Text( x + 3, y, "Ui." + m_PathName );
        DEBUG_DRAW.Text( x + 3, y + 12, GetCurrentAnimationName() );
        DEBUG_DRAW.SetColour( Ogre::ColourValue( 1, 0, 0, 1 ) );

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

        // slightly modify to let show things that are on board of screen
        DEBUG_DRAW.Line( x1, y1 + 1, x2, y2 + 1 );
        DEBUG_DRAW.Line( x2 - 1, y2, x3 - 1, y3 );
        DEBUG_DRAW.Line( x3, y3, x4, y4 );
        DEBUG_DRAW.Line( x4, y4, x1, y1 );

        // draw translation
        DEBUG_DRAW.SetColour( Ogre::ColourValue( 0, 1, 0, 1 ) );
        Ogre::Vector2 area_translate = ( m_Parent != NULL ) ? m_Parent->GetFinalTranslate() : Ogre::Vector2::ZERO;
        DEBUG_DRAW.Line( area_translate.x, area_translate.y, x, y );
        DEBUG_DRAW.Quad( x - 2, y - 2, x + 2, y - 2, x + 2, y + 2, x - 2, y + 2 );

        // draw origin
        DEBUG_DRAW.SetColour( Ogre::ColourValue( 0, 0.5, 0, 1 ) );
        DEBUG_DRAW.Line( x, y, x1, y1 + 1 );
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

    ScriptEntity* script_entity = ScriptManager::getSingleton().GetScriptEntityByName( "Ui." + m_PathName );
    if( script_entity != NULL )
    {
        ScriptManager::getSingleton().ScriptRequest( script_entity, "on_show", 0, "", "", false, false );
    }
}



void
UiWidget::Hide()
{
    m_Visible = false;
    ScriptEntity* script_entity = ScriptManager::getSingleton().GetScriptEntityByName( "Ui." + m_PathName );
    if( script_entity != NULL )
    {
        ScriptManager::getSingleton().ScriptRequest( script_entity, "on_hide", 0, "", "", false, false );
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
UiWidget::AddAnimation( UiAnimation *animation )
{
    m_Animations.push_back( animation );
}



const Ogre::String&
UiWidget::GetCurrentAnimationName() const
{
    if( m_AnimationCurrent != NULL )
    {
        return m_AnimationCurrent->GetName();
    }

    return Ogre::StringUtil::BLANK;
}



void
UiWidget::PlayAnimation( const Ogre::String& animation, UiAnimation::State state, const float start, const float end )
{
    for( int i = 0; i < m_Animations.size(); ++i)
    {
        if( m_Animations[ i ]->GetName() == animation )
        {
            m_AnimationCurrent = m_Animations[ i ];
            m_AnimationCurrent->SetTime( start );
            m_AnimationEndTime = ( end == -1 ) ? m_AnimationCurrent->GetLength() : end;
            m_AnimationState = state;
            return;
        }
    }

    // stop current state and animation
    m_AnimationCurrent = NULL;
    m_AnimationState = UiAnimation::ONCE;
    LOG_ERROR( "Widget '" + m_Name + "' doesn't has animation '" + animation + "'." );
}



void
UiWidget::ScriptPlayAnimation( const char* name )
{
    PlayAnimation( Ogre::String( name ), UiAnimation::DEFAULT, 0, -1 );
}



void
UiWidget::ScriptPlayAnimationStop( const char* name )
{
    PlayAnimation( Ogre::String( name ), UiAnimation::ONCE, 0, -1 );
}



void
UiWidget::ScriptPlayAnimation( const char* name, const float start, const float end )
{
    PlayAnimation( Ogre::String( name ), UiAnimation::DEFAULT, start, end );
}



void
UiWidget::ScriptPlayAnimationStop( const char* name, const float start, const float end )
{
    PlayAnimation( Ogre::String( name ), UiAnimation::ONCE, start, end );
}



void
UiWidget::ScriptSetDefaultAnimation( const char* animation )
{
    m_AnimationDefault = Ogre::String( animation );
    m_AnimationState = UiAnimation::DEFAULT;
}



const int
UiWidget::ScriptAnimationSync()
{
    ScriptId script = ScriptManager::getSingleton().GetCurrentScriptId();
    m_AnimationSync.push_back( script );
    return -1;
}



void
UiWidget::UpdateTransformation()
{
    Ogre::Vector2 area_scale = ( m_Parent != NULL ) ? m_Parent->GetFinalScale() : Ogre::Vector2( 1, 1 );
    Ogre::Vector2 area_origin = ( m_Parent != NULL ) ? m_Parent->GetFinalOrigin() : Ogre::Vector2::ZERO;
    Ogre::Vector2 area_translate = ( m_Parent != NULL ) ? m_Parent->GetFinalTranslate() : Ogre::Vector2::ZERO;
    Ogre::Vector2 area_size = ( m_Parent != NULL ) ? m_Parent->GetFinalSize() : Ogre::Vector2( m_ScreenWidth, m_ScreenHeight );
    float area_rotation = ( m_Parent != NULL ) ? m_Parent->GetFinalRotation() : 0;

    float local_x = ( ( area_size.x * m_XPercent ) / 100.0f + ( m_X * m_ScreenHeight / 720.0f) * area_scale.x ) - area_origin.x;
    float local_y = ( ( area_size.y * m_YPercent ) / 100.0f + ( m_Y * m_ScreenHeight / 720.0f ) * area_scale.y ) - area_origin.y;

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



    m_FinalScale = area_scale * m_Scale;
    m_FinalSize.x = ( area_size.x * m_WidthPercent * m_Scale.x ) / 100.0f + ( m_Width * m_ScreenHeight / 720.0f ) * m_FinalScale.x;
    m_FinalSize.y = ( area_size.y * m_HeightPercent * m_Scale.y ) / 100.0f + ( m_Height * m_ScreenHeight / 720.0f ) * m_FinalScale.y;
    m_FinalOrigin.x = ( m_FinalSize.x * m_OriginXPercent ) / 100.0f + m_OriginX * m_ScreenHeight * m_FinalScale.x / 720.0f;
    m_FinalOrigin.y = ( m_FinalSize.y * m_OriginYPercent ) / 100.0f + m_OriginY * m_ScreenHeight * m_FinalScale.y / 720.0f;
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
UiWidget::SetOriginX( const float percent, const float x )
{
    m_OriginXPercent = percent;
    m_OriginX = x;
}



void
UiWidget::SetOriginY( const float percent, const float y )
{
    m_OriginYPercent = percent;
    m_OriginY = y;
}



void
UiWidget::SetX( const float percent, const float x )
{
    m_XPercent = percent;
    m_X = x;
}



void
UiWidget::SetY( const float percent, const float y )
{
    m_YPercent = percent;
    m_Y = y;
}



void
UiWidget::SetWidth( const float percent, const float width )
{
    m_WidthPercent = percent;
    m_Width = width;
}



void
UiWidget::SetHeight( const float percent, const float height )
{
    m_HeightPercent = percent;
    m_Height = height;
}



void
UiWidget::SetScale( const Ogre::Vector2& scale )
{
    m_Scale = scale;
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



void
UiWidget::SetColour( const float r, const float g, const float b )
{
    m_Colour1.r = r; m_Colour1.g = g; m_Colour1.b = b;
    m_Colour2.r = r; m_Colour2.g = g; m_Colour2.b = b;
    m_Colour3.r = r; m_Colour3.g = g; m_Colour3.b = b;
    m_Colour4.r = r; m_Colour4.g = g; m_Colour4.b = b;
}



void
UiWidget::SetColours( const float r1, const float g1, const float b1, const float r2, const float g2, const float b2, const float r3, const float g3, const float b3, const float r4, const float g4, const float b4 )
{
    m_Colour1.r = r1; m_Colour1.g = g1; m_Colour1.b = b1;
    m_Colour2.r = r2; m_Colour2.g = g2; m_Colour2.b = b2;
    m_Colour3.r = r3; m_Colour3.g = g3; m_Colour3.b = b3;
    m_Colour4.r = r4; m_Colour4.g = g4; m_Colour4.b = b4;
}



void
UiWidget::SetAlpha( const float a )
{
    m_Colour1.a = a;
    m_Colour2.a = a;
    m_Colour3.a = a;
    m_Colour4.a = a;
}
