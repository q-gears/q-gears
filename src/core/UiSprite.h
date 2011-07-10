#ifndef UI_SPRITE_H
#define UI_SPRITE_H

#include <OgreHardwareVertexBuffer.h>
#include <OgreRenderQueueListener.h>
#include <OgreRoot.h>

#include "UiWidget.h"



class UiSprite : public UiWidget
{
public:
    UiSprite( const Ogre::String& name );
    UiSprite( const Ogre::String& name, const Ogre::String& path_name, UiWidget* parent );
    virtual ~UiSprite();

    void Initialise();
    virtual void Update();
    virtual void OnResize();
    virtual void Render();

    void SetImage( const Ogre::String& image );
    void UpdateGeometry();

private:
    UiSprite();
    void CreateVertexBuffer();
    void DestroyVertexBuffer();

private:
    Ogre::MaterialPtr                   m_Material;
    Ogre::SceneManager*                 m_SceneManager;
    Ogre::RenderSystem*                 m_RenderSystem;

    Ogre::RenderOperation               m_RenderOp;
    Ogre::HardwareVertexBufferSharedPtr m_VertexBuffer;
};



#endif // UI_SPRITE_H
