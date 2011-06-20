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
                        UiWidget( const Ogre::String& name, UiWidget* parent );
    virtual            ~UiWidget();

    void                Update();
    void                Render();

    const Ogre::String& GetName() const;

    void                AddChild( UiWidget *widget );
    void                RemoveChild( UiWidget *widget );
    UiWidget*           GetChild( const Ogre::String& name );
    void                RemoveAllChildren();

    void                Quad( const float x1, const float y1, const float x2, const float y2, const float x3, const float y3, const float x4, const float y4 );

private:
                        UiWidget();
    void                CreateQuadVertexBuffer();
    void                DestroyQuadVertexBuffer();

private:
    Ogre::String             m_Name;

    UiWidget*                m_Parent;
    std::vector< UiWidget* > m_Children;

    Ogre::MaterialPtr        m_Material;
    Ogre::SceneManager*      m_SceneManager;
    Ogre::RenderSystem*      m_RenderSystem;
    // quad
    Ogre::RenderOperation               m_QuadRenderOp;
    Ogre::HardwareVertexBufferSharedPtr m_QuadVertexBuffer;
    int                                 m_QuadMaxVertexCount;
};



#endif // UI_WIDGET_H
