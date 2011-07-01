#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <OgreString.h>
#include <vector>



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
    void SetOriginX( const float x, const float add, const bool percent );
    float GetFinalOriginX() const;
    void SetOriginY( const float y, const float add, const bool percent );
    float GetFinalOriginY() const;
    void SetX( const float x, const float add, const bool percent );
    float GetLocalX() const;
    float GetFinalX() const;
    void SetY( const float y, const float add, const bool percent );
    float GetLocalY() const;
    float GetFinalY() const;
    void SetWidth( const float width, const float add, const bool percent );
    float GetFinalWidth() const;
    void SetHeight( const float height, const float add, const bool percent );
    float GetFinalHeight() const;
    void SetScaleX( const float x );
    float GetFinalScaleX() const;
    void SetScaleY( const float y );
    float GetFinalScaleY() const;
    void SetRotation( const float degree );
    float GetFinalRotation() const;

private:
    UiWidget();

protected:
    Ogre::String             m_Name;
    Ogre::String             m_PathName;

    UiWidget*                m_Parent;
    std::vector< UiWidget* > m_Children;

    bool                     m_Visible;

    Align                    m_Align;
    VerticalAlign            m_VerticalAlign;

    float                    m_OriginX;
    float                    m_OriginXAdd;
    bool                     m_OriginXPercent;
    float                    m_OriginY;
    float                    m_OriginYAdd;
    bool                     m_OriginYPercent;
    float                    m_X;
    float                    m_XAdd;
    bool                     m_XPercent;
    float                    m_Y;
    float                    m_YAdd;
    bool                     m_YPercent;
    float                    m_Width;
    float                    m_WidthAdd;
    bool                     m_WidthPercent;
    float                    m_Height;
    float                    m_HeightAdd;
    bool                     m_HeightPercent;
    float                    m_ScaleX;
    float                    m_ScaleY;
    float                    m_Rotation;

    bool                     m_Scissor;
    int                      m_Top;
    int                      m_Bottom;
    int                      m_Left;
    int                      m_Right;
};



#endif // UI_WIDGET_H
