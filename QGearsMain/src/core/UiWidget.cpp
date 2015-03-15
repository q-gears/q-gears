#include <OgreMath.h>
#include <OgreRoot.h>

#include "core/ConfigVar.h"
#include "core/CameraManager.h"
#include "core/DebugDraw.h"
#include "core/Logger.h"
#include "core/ScriptManager.h"
#include "core/Timer.h"
#include "core/UiWidget.h"


ConfigVar cv_debug_ui("debug_ui", "Draw ui debug info", "0");


UiWidget::UiWidget(const Ogre::String& name):
    m_Name(name),
    m_PathName(name),
    m_Parent(nullptr)
{
    Initialise();
}


UiWidget::UiWidget(const Ogre::String& name, const Ogre::String& path_name, UiWidget* parent):
    m_Name(name),
    m_PathName(path_name),
    m_Parent(parent)
{
    Initialise();
}


UiWidget::~UiWidget()
{
    for(unsigned int i = 0; i < m_Animations.size(); ++i)
    {
        delete m_Animations[i];
    }

    ScriptManager::getSingleton().RemoveEntity(ScriptManager::UI, m_PathName);

    RemoveAllChildren();
}


void
UiWidget::Initialise()
{
    Ogre::Viewport *viewport(CameraManager::getSingleton().getViewport());
    m_ScreenWidth = static_cast<float>(viewport->getActualWidth());
    m_ScreenHeight = static_cast<float>(viewport->getActualHeight());

    m_Visible = false;

    m_Align = LEFT;
    m_VerticalAlign = TOP;

    m_UpdateTransformation = true;

    m_FinalZ = 0;
    m_FinalOrigin = Ogre::Vector2::ZERO;
    m_FinalTranslate = Ogre::Vector2::ZERO;
    m_FinalSize = Ogre::Vector2(m_ScreenWidth, m_ScreenHeight);
    m_FinalScale = Ogre::Vector2(1, 1);
    m_FinalRotation = 0;

    m_OriginXPercent = 0;
    m_OriginX = 0;
    m_OriginYPercent = 0;
    m_OriginY = 0;
    m_XPercent = 0;
    m_X = 0;
    m_YPercent = 0;
    m_Y = 0;
    m_Z = 0;
    m_WidthPercent = 100;
    m_Width = 0;
    m_HeightPercent = 100;
    m_Height = 0;
    m_Scale = Ogre::Vector2(1.0f, 1.0f);
    m_Rotation = 0.0f;

    m_Scissor = false;
    m_LocalScissor = false;
    m_GlobalScissor = true;
    m_ScissorTop = 0;
    m_ScissorXPercentTop = 0;
    m_ScissorXTop = 0;
    m_ScissorBottom = m_ScreenHeight;
    m_ScissorXPercentBottom = 100;
    m_ScissorXBottom = 0;
    m_ScissorLeft = 0;
    m_ScissorYPercentLeft = 0;
    m_ScissorYLeft = 0;
    m_ScissorRight = m_ScreenWidth;
    m_ScissorYPercentRight = 100;
    m_ScissorYRight = 0;

    m_AnimationCurrent = nullptr;
    m_AnimationDefault = "";
    m_AnimationState = UiAnimation::DEFAULT;
    m_Colour1 = Ogre::ColourValue(1, 1, 1, 1);
    m_Colour2 = Ogre::ColourValue(1, 1, 1, 1);
    m_Colour3 = Ogre::ColourValue(1, 1, 1, 1);
    m_Colour4 = Ogre::ColourValue(1, 1, 1, 1);

    ScriptManager::getSingleton().AddEntity(ScriptManager::UI, m_PathName, nullptr);
}


void
UiWidget::Update()
{
    if(m_Visible != true)
    {
        return;
    }

    if(m_AnimationCurrent != nullptr)
    {
        float delta_time = Timer::getSingleton().GetGameTimeDelta();
        float time = m_AnimationCurrent->GetTime();

        // if animation ended
        if(time + delta_time >= m_AnimationEndTime)
        {
            if(time != m_AnimationEndTime)
            {
                m_AnimationCurrent->AddTime(m_AnimationEndTime - time);
            }

            for(unsigned int i = 0; i < m_AnimationSync.size(); ++i)
            {
                ScriptManager::getSingleton().ContinueScriptExecution(m_AnimationSync[i]);
            }
            m_AnimationSync.clear();

            if(m_AnimationState == UiAnimation::DEFAULT && m_AnimationDefault != "")
            {
                // in case of cycled default we need to sync with end
                time = time + delta_time - m_AnimationCurrent->GetLength();
                PlayAnimation(m_AnimationDefault, UiAnimation::DEFAULT, time, -1);
            }
            else
            {
                m_AnimationCurrent = NULL;
            }
        }
        else
        {
            m_AnimationCurrent->AddTime(delta_time);
        }
    }
    else if( m_AnimationCurrent == NULL && m_AnimationState == UiAnimation::DEFAULT && m_AnimationDefault != "" )
    {
        PlayAnimation( m_AnimationDefault, UiAnimation::DEFAULT, 0, -1 );
    }



    if( m_UpdateTransformation == true )
    {
        UpdateTransformation();
    }



    for( unsigned int i = 0; i < m_Children.size(); ++i )
    {
        m_Children[ i ]->Update();
    }


    // debug output
    if(cv_debug_ui.GetI() >= 1)
    {
        float local_x1 = -m_FinalOrigin.x;
        float local_y1 = -m_FinalOrigin.y;
        float local_x2 = m_FinalSize.x + local_x1;
        float local_y2 = m_FinalSize.y + local_y1;
        float x = m_FinalTranslate.x;
        float y = m_FinalTranslate.y;

        DEBUG_DRAW.SetScreenSpace(true);

        DEBUG_DRAW.SetColour(Ogre::ColourValue(1, 0, 0, 1));

        int x1, y1, x2, y2, x3, y3, x4, y4;

        if(m_FinalRotation != 0)
        {
            float cos = Ogre::Math::Cos(Ogre::Radian(Ogre::Degree(m_FinalRotation)));
            float sin = Ogre::Math::Sin(Ogre::Radian(Ogre::Degree(m_FinalRotation)));

            x1 = static_cast<int>(local_x1 * cos - local_y1 * sin + x);
            y1 = static_cast<int>(local_x1 * sin + local_y1 * cos + y);
            x2 = static_cast<int>(local_x2 * cos - local_y1 * sin + x);
            y2 = static_cast<int>(local_x2 * sin + local_y1 * cos + y);
            x3 = static_cast<int>(local_x2 * cos - local_y2 * sin + x);
            y3 = static_cast<int>(local_x2 * sin + local_y2 * cos + y);
            x4 = static_cast<int>(local_x1 * cos - local_y2 * sin + x);
            y4 = static_cast<int>(local_x1 * sin + local_y2 * cos + y);
        }
        else
        {
            x1 = static_cast<int>(local_x1 + x);
            y1 = static_cast<int>(local_y1 + y);
            x2 = static_cast<int>(local_x2 + x);
            y2 = static_cast<int>(local_y1 + y);
            x3 = static_cast<int>(local_x2 + x);
            y3 = static_cast<int>(local_y2 + y);
            x4 = static_cast<int>(local_x1 + x);
            y4 = static_cast<int>(local_y2 + y);
        }

        // slightly modify to let show things that are on board of screen
        DEBUG_DRAW.Line(static_cast<float>(x1), static_cast<float>(y1 + 1), static_cast<float>(x2), static_cast<float>(y2 + 1));
        DEBUG_DRAW.Line(static_cast<float>(x2 - 1), static_cast<float>(y2), static_cast<float>(x3 - 1), static_cast<float>(y3));
        DEBUG_DRAW.Line(static_cast<float>(x3), static_cast<float>(y3), static_cast<float>(x4), static_cast<float>(y4));
        DEBUG_DRAW.Line(static_cast<float>(x4), static_cast<float>(y4), static_cast<float>(x1), static_cast<float>(y1));

        // draw translation
        DEBUG_DRAW.SetColour(Ogre::ColourValue(0, 1, 0, 1));
        Ogre::Vector2 area_origin = (m_Parent != nullptr) ? m_Parent->GetFinalOrigin() : Ogre::Vector2::ZERO;
        Ogre::Vector2 area_translate = (m_Parent != nullptr) ? m_Parent->GetFinalTranslate() : Ogre::Vector2::ZERO;
        Ogre::Vector2 pos = area_translate - area_origin;
        DEBUG_DRAW.Line(pos.x, pos.y, x, y);
        DEBUG_DRAW.Quad(x - 2, y - 2, x + 2, y - 2, x + 2, y + 2, x - 2, y + 2);

        if(cv_debug_ui.GetI() >= 2)
        {
            DEBUG_DRAW.SetColour(Ogre::ColourValue::White);
            DEBUG_DRAW.SetTextAlignment(DEBUG_DRAW.LEFT);
            DEBUG_DRAW.Text(static_cast<float>(x1 + 3), static_cast<float>(y1), m_PathName);
            DEBUG_DRAW.Text(static_cast<float>(x1 + 3), static_cast<float>(y1 + 12), GetCurrentAnimationName());
        }

        // draw origin
        DEBUG_DRAW.SetColour(Ogre::ColourValue(1, 0, 0, 1));
        DEBUG_DRAW.Line(x, y, static_cast<float>(x1), static_cast<float>(y1 + 1));
    }
}


void
UiWidget::OnResize()
{
    Ogre::Viewport *viewport(CameraManager::getSingleton().getViewport());
    m_ScreenWidth = static_cast<float>(viewport->getActualWidth());
    m_ScreenHeight = static_cast<float>(viewport->getActualHeight());

    for(size_t i = 0; i < m_Children.size(); ++i)
    {
        m_Children[i]->OnResize();
    }

    m_UpdateTransformation = true;
}


void
UiWidget::Render()
{
    if(m_Visible == true)
    {
        for(size_t i = 0; i < m_Children.size(); ++i)
        {
            m_Children[i]->Render();
        }
    }
}


void
UiWidget::SetVisible(const bool visible)
{
    m_Visible = visible;
}


bool
UiWidget::IsVisible() const
{
    return m_Visible;
}


const Ogre::String&
UiWidget::GetName() const
{
    return m_Name;
}


void
UiWidget::AddChild(UiWidget *widget)
{
    m_Children.push_back(widget);
}


UiWidget*
UiWidget::GetChild( const Ogre::String& name )
{
    for( unsigned int i = 0; i < m_Children.size(); ++i )
    {
        if( m_Children[ i ]->GetName() == name )
        {
            return m_Children[ i ];
        }
    }

    return NULL;
}



UiWidget*
UiWidget::GetChild( const unsigned int id )
{
    if( id >= m_Children.size() )
    {
        return NULL;
    }

    return m_Children[ id ];
}



unsigned int
UiWidget::GetNumberOfChildren()
{
    return m_Children.size();
}

void
UiWidget::RemoveAllChildren()
{
    for(size_t i = 0; i < m_Children.size(); ++i)
    {
        delete m_Children[i];
    }
    m_Children.clear();
}


void
UiWidget::AddAnimation(UiAnimation* animation)
{
    m_Animations.push_back(animation);
}


const Ogre::String&
UiWidget::GetCurrentAnimationName() const
{
    if(m_AnimationCurrent != nullptr)
    {
        return m_AnimationCurrent->GetName();
    }

    return Ogre::StringUtil::BLANK;
}


void
UiWidget::PlayAnimation(const Ogre::String& animation, UiAnimation::State state, const float start, const float end)
{
    for(size_t i = 0; i < m_Animations.size(); ++i)
    {
        if(m_Animations[i]->GetName() == animation)
        {
            m_AnimationCurrent = m_Animations[i];
            m_AnimationCurrent->SetTime((start == -1) ? m_AnimationCurrent->GetLength() : start);
            m_AnimationCurrent->AddTime(0);
            m_AnimationEndTime = (end == -1) ? m_AnimationCurrent->GetLength() : end;
            m_AnimationState = state;
            return;
        }
    }

    // stop current state and animation
    m_AnimationCurrent = nullptr;
    m_AnimationState = UiAnimation::ONCE;
    LOG_ERROR("Widget '" + m_Name + "' doesn't has animation '" + animation + "'.");
}


void
UiWidget::ScriptPlayAnimation(const char* name)
{
    PlayAnimation(Ogre::String(name), UiAnimation::DEFAULT, 0, -1);
}


void
UiWidget::ScriptPlayAnimationStop(const char* name)
{
    PlayAnimation(Ogre::String(name), UiAnimation::ONCE, 0, -1);
}


void
UiWidget::ScriptPlayAnimation(const char* name, const float start, const float end)
{
    PlayAnimation(Ogre::String(name), UiAnimation::DEFAULT, start, end);
}


void
UiWidget::ScriptPlayAnimationStop(const char* name, const float start, const float end)
{
    PlayAnimation(Ogre::String(name), UiAnimation::ONCE, start, end);
}


void
UiWidget::ScriptSetDefaultAnimation(const char* animation)
{
    m_AnimationDefault = Ogre::String(animation);
    m_AnimationState = UiAnimation::DEFAULT;
}


int
UiWidget::ScriptAnimationSync()
{
    ScriptId script = ScriptManager::getSingleton().GetCurrentScriptId();
    m_AnimationSync.push_back(script);
    return -1;
}



void
UiWidget::SetUpdateTransformation()
{
    for( unsigned int i = 0; i < m_Children.size(); ++i )
    {
        m_Children[ i ]->SetUpdateTransformation();
    }

    m_UpdateTransformation = true;
}

void
UiWidget::UpdateTransformation()
{
    Ogre::Vector2 area_scale = (m_Parent != nullptr) ? m_Parent->GetFinalScale() : Ogre::Vector2(1, 1);
    Ogre::Vector2 area_origin = (m_Parent != nullptr) ? m_Parent->GetFinalOrigin() : Ogre::Vector2::ZERO;
    Ogre::Vector2 area_translate = (m_Parent != nullptr) ? m_Parent->GetFinalTranslate() : Ogre::Vector2::ZERO;
    Ogre::Vector2 area_size = (m_Parent != nullptr) ? m_Parent->GetFinalSize() : Ogre::Vector2(m_ScreenWidth, m_ScreenHeight);
    float area_rotation = (m_Parent != nullptr) ? m_Parent->GetFinalRotation() : 0;

    float local_x = ((area_size.x * m_XPercent) / 100.0f + (m_X * m_ScreenHeight / 720.0f) * area_scale.x) - area_origin.x;
    float local_y = ((area_size.y * m_YPercent) / 100.0f + (m_Y * m_ScreenHeight / 720.0f) * area_scale.y) - area_origin.y;

    float x = local_x;
    float y = local_y;

    if(area_rotation != 0)
    {
        float cos = Ogre::Math::Cos(Ogre::Radian(Ogre::Degree(area_rotation)));
        float sin = Ogre::Math::Sin(Ogre::Radian(Ogre::Degree(area_rotation)));
        x = local_x * cos - local_y * sin;
        y = local_x * sin + local_y * cos;
    }

    m_FinalTranslate.x = area_translate.x;
    if(m_Align == RIGHT)
    {
        m_FinalTranslate.x = area_translate.x + area_size.x;
    }
    else if(m_Align == CENTER)
    {
        m_FinalTranslate.x = area_translate.x + area_size.x / 2;
    }
    m_FinalTranslate.x += x;

    m_FinalTranslate.y = area_translate.y;
    if(m_VerticalAlign == BOTTOM)
    {
        m_FinalTranslate.y = area_translate.y + area_size.y;
    }
    else if(m_VerticalAlign == MIDDLE)
    {
        m_FinalTranslate.y = area_translate.y + area_size.y / 2;
    }
    m_FinalTranslate.y += y;



    m_FinalZ = ( m_Parent != NULL ) ? m_Parent->GetFinalZ() + m_Z : m_Z;
    m_FinalScale = area_scale * m_Scale;
    m_FinalSize.x = ( area_size.x * m_WidthPercent * m_Scale.x ) / 100.0f + ( m_Width * m_ScreenHeight / 720.0f ) * m_FinalScale.x;
    m_FinalSize.y = ( area_size.y * m_HeightPercent * m_Scale.y ) / 100.0f + ( m_Height * m_ScreenHeight / 720.0f ) * m_FinalScale.y;
    m_FinalOrigin.x = ( m_FinalSize.x * m_OriginXPercent ) / 100.0f + m_OriginX * m_ScreenHeight * m_FinalScale.x / 720.0f;
    m_FinalOrigin.y = ( m_FinalSize.y * m_OriginYPercent ) / 100.0f + m_OriginY * m_ScreenHeight * m_FinalScale.y / 720.0f;
    m_FinalRotation = area_rotation + m_Rotation;



    // scissor update
    if( m_LocalScissor == true )
    {
        float local_x1 = m_FinalSize.x * m_ScissorXPercentTop / 100.0f + m_ScissorXTop * m_ScreenHeight * m_FinalScale.x / 720.0f - m_FinalOrigin.x;
        float local_y1 = m_FinalSize.y * m_ScissorYPercentLeft / 100.0f + m_ScissorYLeft * m_ScreenHeight * m_FinalScale.y / 720.0f - m_FinalOrigin.y;
        float local_x2 = m_FinalSize.x * m_ScissorXPercentBottom / 100.0f + m_ScissorXBottom * m_ScreenHeight * m_FinalScale.x / 720.0f - m_FinalOrigin.x;
        float local_y2 = m_FinalSize.y * m_ScissorYPercentRight / 100.0f + m_ScissorYRight * m_ScreenHeight * m_FinalScale.y / 720.0f - m_FinalOrigin.y;
        float x = m_FinalTranslate.x;
        float y = m_FinalTranslate.y;

        int x1, y1, x2, y2, x3, y3, x4, y4;

        if(m_FinalRotation != 0)
        {
            float cos = Ogre::Math::Cos(Ogre::Radian(Ogre::Degree(m_FinalRotation)));
            float sin = Ogre::Math::Sin(Ogre::Radian(Ogre::Degree(m_FinalRotation)));

            x1 = static_cast<int>(local_x1 * cos - local_y1 * sin + x);
            y1 = static_cast<int>(local_x1 * sin + local_y1 * cos + y);
            x2 = static_cast<int>(local_x2 * cos - local_y1 * sin + x);
            y2 = static_cast<int>(local_x2 * sin + local_y1 * cos + y);
            x3 = static_cast<int>(local_x2 * cos - local_y2 * sin + x);
            y3 = static_cast<int>(local_x2 * sin + local_y2 * cos + y);
            x4 = static_cast<int>(local_x1 * cos - local_y2 * sin + x);
            y4 = static_cast<int>(local_x1 * sin + local_y2 * cos + y);
        }
        else
        {
            x1 = static_cast<int>(local_x1 + x);
            y1 = static_cast<int>(local_y1 + y);
            x2 = static_cast<int>(local_x2 + x);
            y2 = static_cast<int>(local_y1 + y);
            x3 = static_cast<int>(local_x2 + x);
            y3 = static_cast<int>(local_y2 + y);
            x4 = static_cast<int>(local_x1 + x);
            y4 = static_cast<int>(local_y2 + y);
        }

        m_Scissor = true;
        m_ScissorTop = std::min( std::min( y1 , y2 ), std::min( y3 , y4 ) );
        m_ScissorBottom = std::max( std::max( y1 , y2 ), std::max( y3 , y4 ) );
        m_ScissorLeft = std::min( std::min( x1 , x2 ), std::min( x3 , x4 ) );
        m_ScissorRight = std::max( std::max( x1 , x2 ), std::max( x3 , x4 ) );
    }
    if( m_Parent != NULL && m_GlobalScissor == true )
    {
        bool use_scissor;
        Ogre::Vector4 scissor = m_Parent->GetFinalScissor( use_scissor );
        if( use_scissor == true )
        {
            m_Scissor = true;
            if( m_LocalScissor == true )
            {
                m_ScissorTop = std::max( (float) m_ScissorTop, scissor.x );
                m_ScissorBottom = std::min( (float) m_ScissorBottom, scissor.y );
                m_ScissorLeft = std::max( (float) m_ScissorLeft, scissor.z );
                m_ScissorRight = std::min( (float) m_ScissorRight, scissor.w );
            }
            else
            {
                m_ScissorTop = scissor.x;
                m_ScissorBottom = scissor.y;
                m_ScissorLeft = scissor.z;
                m_ScissorRight = scissor.w;
            }
        }
    }



    m_UpdateTransformation = false;
}


void
UiWidget::SetAlign(const UiWidget::Align align)
{
    m_Align = align;
}


void
UiWidget::SetVerticalAlign(const UiWidget::VerticalAlign valign)
{
    m_VerticalAlign = valign;
}


float
UiWidget::GetFinalZ() const
{
    return m_FinalZ;
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



Ogre::Vector4
UiWidget::GetFinalScissor( bool& scissor ) const
{
    if( m_Scissor == true )
    {
        scissor = true;
        return Ogre::Vector4( m_ScissorTop, m_ScissorBottom, m_ScissorLeft, m_ScissorRight );
    }

    scissor = false;
    return Ogre::Vector4::ZERO;
}
float
UiWidget::GetFinalRotation() const
{
    return m_FinalRotation;
}


void
UiWidget::SetOriginX(const float percent, const float x)
{
    m_OriginXPercent = percent;
    m_OriginX = x;
    SetUpdateTransformation();
}


void
UiWidget::SetOriginY(const float percent, const float y)
{
    m_OriginYPercent = percent;
    m_OriginY = y;
    SetUpdateTransformation();
}



void
UiWidget::SetX( const float percent, const float x )
{
    m_XPercent = percent;
    m_X = x;
    SetUpdateTransformation();
}



void
UiWidget::GetX( float& percent, float& x )
{
    percent = m_XPercent;
    x = m_X;
}



void
UiWidget::SetY( const float percent, const float y )
{
    m_YPercent = percent;
    m_Y = y;
    SetUpdateTransformation();
}



void
UiWidget::GetY( float& percent, float& y )
{
    percent = m_YPercent;
    y = m_Y;
}



void
UiWidget::SetZ( const float z )
{
    m_Z = z;
    SetUpdateTransformation();
}



void
UiWidget::SetWidth( const float percent, const float width )
{
    m_WidthPercent = percent;
    m_Width = width;
    SetUpdateTransformation();
}



void
UiWidget::GetWidth( float& percent, float& width )
{
    percent = m_WidthPercent;
    width = m_Width;
}



void
UiWidget::SetHeight( const float percent, const float height )
{
    m_HeightPercent = percent;
    m_Height = height;
    SetUpdateTransformation();
}



void
UiWidget::GetHeight( float& percent, float& height )
{
    percent = m_HeightPercent;
    height = m_Height;
}



void
UiWidget::SetScale( const Ogre::Vector2& scale )
{
    m_Scale = scale;
    SetUpdateTransformation();
}



void
UiWidget::SetRotation( const float degree )
{
    m_Rotation = degree;
    SetUpdateTransformation();
}



void
UiWidget::SetScissorArea( const float percent_x1, const float x1, const float percent_y1, const float y1, const float percent_x2, const float x2, const float percent_y2, const float y2 )
{
    m_LocalScissor = true;

    m_ScissorXPercentTop = percent_x1;
    m_ScissorXTop = x1;
    m_ScissorXPercentBottom = percent_x2;
    m_ScissorXBottom = x2;
    m_ScissorYPercentLeft = percent_y1;
    m_ScissorYLeft = y1;
    m_ScissorYPercentRight = percent_y2;
    m_ScissorYRight = y2;

    SetUpdateTransformation();
}



void
UiWidget::SetGlobalScissor( const bool global )
{
    m_GlobalScissor = global;
    SetUpdateTransformation();
}



void
UiWidget::SetColour( const float r, const float g, const float b )
{
    m_Colour1.r = r; m_Colour1.g = g; m_Colour1.b = b;
    m_Colour2.r = r; m_Colour2.g = g; m_Colour2.b = b;
    m_Colour3.r = r; m_Colour3.g = g; m_Colour3.b = b;
    m_Colour4.r = r; m_Colour4.g = g; m_Colour4.b = b;
    SetUpdateTransformation();
}



void
UiWidget::SetColours( const float r1, const float g1, const float b1, const float r2, const float g2, const float b2, const float r3, const float g3, const float b3, const float r4, const float g4, const float b4 )
{
    m_Colour1.r = r1; m_Colour1.g = g1; m_Colour1.b = b1;
    m_Colour2.r = r2; m_Colour2.g = g2; m_Colour2.b = b2;
    m_Colour3.r = r3; m_Colour3.g = g3; m_Colour3.b = b3;
    m_Colour4.r = r4; m_Colour4.g = g4; m_Colour4.b = b4;
    SetUpdateTransformation();
}



void
UiWidget::SetAlpha( const float a )
{
    m_Colour1.a = a;
    m_Colour2.a = a;
    m_Colour3.a = a;
    m_Colour4.a = a;
    SetUpdateTransformation();
}
