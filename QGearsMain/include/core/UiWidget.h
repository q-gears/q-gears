#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <OgreColourValue.h>
#include <OgreString.h>
#include <OgreVector2.h>
#include <vector>

#include "ScriptManager.h"
#include "UiAnimation.h"



class UiWidget
{
public:
    UiWidget( const Ogre::String& name );
    UiWidget( const Ogre::String& name, const Ogre::String& path_name, UiWidget* parent );
    virtual ~UiWidget();

    void Initialise();
    virtual void Update();
    void OnResize();
    virtual void Render();

    void SetVisible( const bool visible );
    bool IsVisible() const;

    const Ogre::String& GetName() const;

    void AddChild( UiWidget* widget );
    UiWidget* GetChild( const Ogre::String& name );
    UiWidget* GetChild(const unsigned int id);
    unsigned int GetNumberOfChildren();
    void RemoveAllChildren();

    // animation related
    void AddAnimation( UiAnimation* animation );
    const Ogre::String& GetCurrentAnimationName() const;
    void PlayAnimation( const Ogre::String& animation, UiAnimation::State state, const float start, const float end );
    void ScriptPlayAnimation( const char* name );
    void ScriptPlayAnimationStop( const char* name );
    void ScriptPlayAnimation( const char* name, const float start, const float end );
    void ScriptPlayAnimationStop( const char* name, const float start, const float end );
    void ScriptSetDefaultAnimation( const char* animation );
    int ScriptAnimationSync();

    virtual void UpdateTransformation();

    enum Align
    {
        LEFT,
        RIGHT,
        CENTER
    };
    enum VerticalAlign
    {
        TOP,
        BOTTOM,
        MIDDLE
    };
    void SetAlign( const UiWidget::Align align );
    void SetVerticalAlign( const UiWidget::VerticalAlign valign );

    float GetFinalZ() const;
    Ogre::Vector2 GetFinalOrigin() const;
    Ogre::Vector2 GetFinalTranslate() const;
    Ogre::Vector2 GetFinalSize() const;
    Ogre::Vector2 GetFinalScale() const;
    float GetFinalRotation() const;

    void SetOriginX( const float percent, const float x );
    void SetOriginY( const float percent, const float y );
    void SetX( const float percent, const float x );
    void SetY( const float percent, const float y );
    void SetZ( const float z );
    void GetX( float &percent, float &x );
    void GetY( float &percent, float &y );
    void SetWidth( const float percent, const float width );
    void GetWidth( float& percent, float& width );
    void SetHeight( const float percent, const float height );
    void GetHeight( float& percent, float& height );
    void SetScale( const Ogre::Vector2& scale );
    void SetRotation( const float degree );
    void SetUpdateTransformation();

    void SetScissor( bool scissor );
    int GetScissorTop() const;
    int GetScissorBottom() const;
    int GetScissorLeft() const;
    int GetScissorRight() const;

    void SetColour( const float r, const float g, const float b );
    void SetColours( const float r1, const float g1, const float b1, const float r2, const float g2, const float b2, const float r3, const float g3, const float b3, const float r4, const float g4, const float b4 );
    void SetAlpha( const float a );

private:
    UiWidget();

protected:
    Ogre::String             m_Name;
    Ogre::String             m_PathName;

    std::vector< UiWidget* > m_Children;
    UiWidget*                m_Parent;

    float                    m_ScreenWidth;
    float                    m_ScreenHeight;

    bool                     m_Visible;
    Ogre::ColourValue        m_Colour1;
    Ogre::ColourValue        m_Colour2;
    Ogre::ColourValue        m_Colour3;
    Ogre::ColourValue        m_Colour4;

    Align                    m_Align;
    VerticalAlign            m_VerticalAlign;

    bool                     m_UpdateTransformation;

    Ogre::Vector2            m_FinalOrigin;
    Ogre::Vector2            m_FinalTranslate;
    float                    m_FinalZ;
    Ogre::Vector2            m_FinalSize;
    Ogre::Vector2            m_FinalScale;
    float                    m_FinalRotation;

    float                    m_OriginXPercent;
    float                    m_OriginX;
    float                    m_OriginYPercent;
    float                    m_OriginY;
    float                    m_XPercent;
    float                    m_X;
    float                    m_YPercent;
    float                    m_Y;
    float                    m_Z;
    float                    m_WidthPercent;
    float                    m_Width;
    float                    m_HeightPercent;
    float                    m_Height;
    Ogre::Vector2            m_Scale;
    float                    m_Rotation;

    bool                     m_Scissor;
    int                      m_ScissorTop;
    int                      m_ScissorBottom;
    int                      m_ScissorLeft;
    int                      m_ScissorRight;

    UiAnimation*                m_AnimationCurrent;
    std::vector< ScriptId >     m_AnimationSync;
    UiAnimation::State          m_AnimationState;
    Ogre::String                m_AnimationDefault;
    float                       m_AnimationEndTime;
    std::vector< UiAnimation* > m_Animations;
};



#endif // UI_WIDGET_H
