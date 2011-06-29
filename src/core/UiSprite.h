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

    void SetColour( const float r, const float g, const float b, const float a );
    void SetImage( const Ogre::String& image );
    void GeometryUpdate();

private:
    UiSprite();
    void CreateQuadVertexBuffer();
    void DestroyQuadVertexBuffer();

private:
    Ogre::MaterialPtr                   m_Material;
    Ogre::ColourValue                   m_Colour;
    Ogre::SceneManager*                 m_SceneManager;
    Ogre::RenderSystem*                 m_RenderSystem;

    Ogre::RenderOperation               m_QuadRenderOp;
    Ogre::HardwareVertexBufferSharedPtr m_QuadVertexBuffer;
};



#endif // UI_SPRITE_H
