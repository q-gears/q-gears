#ifndef BACKGROUND_2D_H
#define BACKGROUND_2D_H

#include <OgreHardwareVertexBuffer.h>
#include <OgreRenderQueueListener.h>
#include <OgreRoot.h>
#include <OgreSingleton.h>
#include "Background2DAnimation.h"



class Background2D : public Ogre::RenderQueueListener
{
public:
    Background2D();
    virtual ~Background2D();

    void Update();
    void Clear();

    void SetImage( const Ogre::String& image );
    void AddTile( const float x, const float y, const float width, const float height, const float depth, const float u1, const float v1, const float u2, const float v2 );
    void UpdateTileUV( const unsigned int tile_id, const float u1, const float v1, const float u2, const float v2 );

    void AddAnimation( Background2DAnimation* animation );

    void renderQueueEnded( Ogre::uint8 queueGroupId, const Ogre::String& invocation, bool& repeatThisInvocation );

private:
    void CreateVertexBuffer();
    void DestroyVertexBuffer();

private:
    Ogre::SceneManager*                   m_SceneManager;
    Ogre::RenderSystem*                   m_RenderSystem;

    Ogre::RenderOperation                 m_RenderOp;
    Ogre::HardwareVertexBufferSharedPtr   m_VertexBuffer;
    unsigned int                          m_MaxVertexCount;
    Ogre::MaterialPtr                     m_Material;

    std::vector< Background2DAnimation* > m_Animations;
};



#endif // BACKGROUND_2D_H
