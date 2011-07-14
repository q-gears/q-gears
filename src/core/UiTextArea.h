#ifndef UI_TEXT_AREA_H
#define UI_TEXT_AREA_H

#include <OgreHardwareVertexBuffer.h>
#include <OgreRenderQueueListener.h>
#include <OgreRoot.h>
#include <OgreUTFString.h>

#include "UiFont.h"
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
    void SetText( const Ogre::UTFString& text );
    void SetFont( const Ogre::String& font );
    void UpdateGeometry();

private:
    UiTextArea();
    void CreateVertexBuffer();
    void DestroyVertexBuffer();

private:
    Ogre::MaterialPtr                   m_Material;
    Ogre::SceneManager*                 m_SceneManager;
    Ogre::RenderSystem*                 m_RenderSystem;

    int                                 m_MaxLetters;
    Ogre::RenderOperation               m_RenderOp;
    Ogre::HardwareVertexBufferSharedPtr m_VertexBuffer;

    UiFont*                             m_Font;
    TextAlignment                       m_TextAlignment;
    Ogre::UTFString                     m_Text;
};



#endif // UI_TEXT_AREA_H
