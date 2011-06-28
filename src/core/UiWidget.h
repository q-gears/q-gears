#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <OgreHardwareVertexBuffer.h>
#include <OgreRenderQueueListener.h>
#include <OgreRoot.h>
#include <OgreString.h>
#include <vector>



class UiWidget
{
public:
                        UiWidget( const Ogre::String& name );
                        UiWidget( const Ogre::String& name, const Ogre::String& path_name, UiWidget* parent );
    virtual            ~UiWidget();

    void                Initialise();
    void                Update();
    void                OnResize();
    void                Render();

    const Ogre::String& GetName() const;

    void                AddChild( UiWidget *widget );
    UiWidget*           GetChild( const Ogre::String& name );
    void                RemoveAllChildren();



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

    void                SetColour( const float r, const float g, const float b, const float a );
    void                SetAlign( const UiWidget::Align align );
    void                SetVerticalAlign( const UiWidget::VerticalAlign valign );
    void                SetX( const float x, const bool percent );
    float               GetScreenX() const;
    void                SetY( const float y, const bool percent );
    float               GetScreenY() const;
    void                SetWidth( const float width, const bool percent );
    float               GetScreenWidth() const;
    void                SetHeight( const float height, const bool percent );
    float               GetScreenHeight() const;
    void                GeometryUpdate();

    void                Show();
    void                Hide();

private:
                        UiWidget();
    void                CreateQuadVertexBuffer();
    void                DestroyQuadVertexBuffer();

private:
    Ogre::String             m_Name;
    Ogre::String             m_PathName;

    UiWidget*                m_Parent;
    std::vector< UiWidget* > m_Children;

    Ogre::MaterialPtr        m_Material;
    Ogre::ColourValue        m_Colour;
    Ogre::SceneManager*      m_SceneManager;
    Ogre::RenderSystem*      m_RenderSystem;
    // quad
    Ogre::RenderOperation               m_QuadRenderOp;
    Ogre::HardwareVertexBufferSharedPtr m_QuadVertexBuffer;
    bool                                m_Visible;

    Align                               m_Align;
    VerticalAlign                       m_VerticalAlign;
    float                               m_X;
    bool                                m_XPercent;
    float                               m_Y;
    bool                                m_YPercent;
    float                               m_Width;
    bool                                m_WidthPercent;
    float                               m_Height;
    bool                                m_HeightPercent;
};



#endif // UI_WIDGET_H
