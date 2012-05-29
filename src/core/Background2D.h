#ifndef BACKGROUND_2D_H
#define BACKGROUND_2D_H

#include <OgreHardwareVertexBuffer.h>
#include <OgreRenderQueueListener.h>
#include <OgreRoot.h>
#include "Background2DAnimation.h"
#include "Entity.h"
#include "ScriptManager.h"



class Background2D : public Ogre::RenderQueueListener
{
public:
    enum Blending
    {
        ALPHA,
        ADD
    };

    enum ScrollType
    {
        NONE,
        LINEAR,
        SMOOTH
    };

    Background2D();
    virtual ~Background2D();

    void Update();
    void UpdateDebug();
    void OnResize();

    void Clear();

    void ScriptAutoScrollToEntity( Entity* entity );
    Entity* GetAutoScrollEntity() const;
    void ScriptScrollToPosition( const float x, const float y, const ScrollType type, const float seconds );
    int ScriptScrollSync();
    void UnsetScroll();
    const Ogre::Vector2& GetScrollPositionStart() const;
    const Ogre::Vector2& GetScrollPositionEnd() const;
    ScrollType GetScrollType() const;
    float GetScrollSeconds() const;
    void SetScrollCurrentSeconds( const float seconds );
    float GetScrollCurrentSeconds() const;

    void SetScroll( const Ogre::Vector2& position );
    const Ogre::Vector2& GetScroll() const;

    void SetImage( const Ogre::String& image );
    void AddTile( const int x, const int y, const int width, const int height, const float depth, const float u1, const float v1, const float u2, const float v2, const Blending blending );
    void UpdateTileUV( const unsigned int tile_id, const float u1, const float v1, const float u2, const float v2 );

    void AddAnimation( Background2DAnimation* animation );
    const Ogre::String& GetCurrentAnimationName() const;
    void PlayAnimation( const Ogre::String& animation, Background2DAnimation::State state, const float start, const float end );
    void ScriptPlayAnimation( const char* name );
    void ScriptPlayAnimationStop( const char* name );
    void ScriptPlayAnimation( const char* name, const float start, const float end );
    void ScriptPlayAnimationStop( const char* name, const float start, const float end );
    void ScriptSetDefaultAnimation( const char* animation );
    int ScriptAnimationSync();

    void renderQueueEnded( Ogre::uint8 queueGroupId, const Ogre::String& invocation, bool& repeatThisInvocation );

private:
    void CreateVertexBuffers();
    void DestroyVertexBuffers();

private:
    Ogre::SceneManager*                   m_SceneManager;
    Ogre::RenderSystem*                   m_RenderSystem;

    struct Tile
    {
        int x;
        int y;
        int width;
        int height;
        unsigned int start_vertex_index;
        Blending blending;
    };
    std::vector< Tile >                   m_Tiles;

    // alpha blended
    Ogre::RenderOperation                 m_AlphaRenderOp;
    Ogre::HardwareVertexBufferSharedPtr   m_AlphaVertexBuffer;
    unsigned int                          m_AlphaMaxVertexCount;
    Ogre::MaterialPtr                     m_AlphaMaterial;

    // add blended
    Ogre::RenderOperation                 m_AddRenderOp;
    Ogre::HardwareVertexBufferSharedPtr   m_AddVertexBuffer;
    unsigned int                          m_AddMaxVertexCount;
    Ogre::MaterialPtr                     m_AddMaterial;

    Entity*                               m_ScrollEntity;
    Ogre::Vector2                         m_ScrollPositionStart;
    Ogre::Vector2                         m_ScrollPositionEnd;
    ScrollType                            m_ScrollType;
    float                                 m_ScrollSeconds;
    float                                 m_ScrollCurrentSeconds;
    std::vector< ScriptId >               m_ScrollSync;
    Ogre::Vector2                         m_Position;

    Ogre::String                          m_AnimationCurrent;
    std::vector< ScriptId >               m_AnimationSync;
    Background2DAnimation::State          m_AnimationState;
    Ogre::String                          m_AnimationDefault;
    float                                 m_AnimationEndTime;
    std::vector< Background2DAnimation* > m_Animations;
};



#endif // BACKGROUND_2D_H
