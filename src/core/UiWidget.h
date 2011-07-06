#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <OgreString.h>
#include <OgreVector2.h>
#include <vector>

#include "UiAnimation.h"



class UiWidget
{
public:
    UiWidget( const Ogre::String& name );
    UiWidget( const Ogre::String& name, const Ogre::String& path_name, UiWidget* parent );
    virtual ~UiWidget();

    void Initialise();
    virtual void Update();
    virtual void OnResize();
    virtual void Render();

    void Show();
    void Hide();

    const Ogre::String& GetName() const;

    void AddChild( UiWidget *widget );
    UiWidget* GetChild( const Ogre::String& name );
    void RemoveAllChildren();



    void UpdateTransformation();

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

    Ogre::Vector2 GetFinalOrigin() const;
    Ogre::Vector2 GetFinalTranslate() const;
    Ogre::Vector2 GetFinalSize() const;
    Ogre::Vector2 GetFinalScale() const;
    float GetFinalRotation() const;

    void SetOriginX( const float x, const float percent );
    void SetOriginY( const float y, const float percent );
    void SetX( const float x, const float percent );
    void SetY( const float y, const float percent );
    void SetWidth( const float width, const float percent );
    void SetHeight( const float height, const float percent );
    void SetScale( const Ogre::Vector2& scale );
    void SetRotation( const float degree );

    void SetScissor( bool scissor );
    int GetScissorTop() const;
    int GetScissorBottom() const;
    int GetScissorLeft() const;
    int GetScissorRight() const;

private:
    UiWidget();

protected:
    Ogre::String             m_Name;
    Ogre::String             m_PathName;

    UiWidget*                m_Parent;
    std::vector< UiWidget* > m_Children;

    float                    m_ScreenWidth;
    float                    m_ScreenHeight;

    bool                     m_Visible;

    Align                    m_Align;
    VerticalAlign            m_VerticalAlign;

    Ogre::Vector2            m_FinalOrigin;
    Ogre::Vector2            m_FinalTranslate;
    Ogre::Vector2            m_FinalSize;
    Ogre::Vector2            m_FinalScale;
    float                    m_FinalRotation;

    float                    m_OriginXPercent;
    float                    m_OriginX;
    float                    m_OriginYPercent;
    float                    m_OriginY;
    float                    m_X;
    float                    m_XPercent;
    float                    m_Y;
    float                    m_YPercent;
    float                    m_Width;
    float                    m_WidthPercent;
    float                    m_Height;
    float                    m_HeightPercent;
    Ogre::Vector2            m_Scale;
    float                    m_Rotation;

    bool                     m_Scissor;
    int                      m_ScissorTop;
    int                      m_ScissorBottom;
    int                      m_ScissorLeft;
    int                      m_ScissorRight;

    UiAnimation*             m_Animation;
};



#endif // UI_WIDGET_H
