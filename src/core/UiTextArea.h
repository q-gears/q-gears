#ifndef UI_TEXT_AREA_H
#define UI_TEXT_AREA_H

#include <OgreFont.h>
#include <OgreHardwareVertexBuffer.h>
#include <OgreRenderQueueListener.h>
#include <OgreRoot.h>

#include "UiWidget.h"



class UiTextArea : public UiWidget
{
public:
    UiTextArea( const Ogre::String& name );
    UiTextArea( const Ogre::String& name, const Ogre::String& path_name, UiWidget* parent );
    virtual ~UiTextArea();

    void Initialise();
    virtual void Update();
    virtual void OnResize();
    virtual void Render();

    enum TextAlignment
    {
        LEFT,
        RIGHT,
        CENTER
    };
    void SetTextAlignment( const TextAlignment alignment );
    void SetText( const Ogre::String& text );
    void SetFont( const Ogre::String& font, const float size );
    void UpdateGeometry();

private:
    UiTextArea();
    void CreateVertexBuffer();
    void DestroyVertexBuffer();

private:
    Ogre::SceneManager*                 m_SceneManager;
    Ogre::RenderSystem*                 m_RenderSystem;

    int                                 m_MaxLetters;
    Ogre::RenderOperation               m_RenderOp;
    Ogre::HardwareVertexBufferSharedPtr m_VertexBuffer;

    Ogre::FontPtr                       m_Font;
    int                                 m_FontHeight;
    TextAlignment                       m_TextAlignment;
    Ogre::String                        m_Text;
};



#endif // UI_TEXT_AREA_H
