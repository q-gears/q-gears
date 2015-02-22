#ifndef BACKGROUND_2D_H
#define BACKGROUND_2D_H

#include <OgreHardwareVertexBuffer.h>
#include <OgreRenderQueueListener.h>
#include <OgreRoot.h>

#include "map/QGearsBackground2DFile.h"

#include "Background2DAnimation.h"
#include "Entity.h"
#include "ScriptManager.h"


class Background2D : public Ogre::RenderQueueListener
{
public:

    typedef QGears::Blending  Blending;

    enum ScrollType
    {
        NONE,
        LINEAR,
        SMOOTH
    };

    Background2D();
    virtual ~Background2D();

    void InputDebug(const QGears::Event& event);
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

    // Scroll position in screen coordinates
    void SetScreenScroll( const Ogre::Vector2& position );
    const Ogre::Vector2 GetScreenScroll() const;
    // scroll in game internal screen coordinates
    void SetScroll( const Ogre::Vector2& position );
    const Ogre::Vector2& GetScroll() const;


    void SetImage( const Ogre::String& image );

    void SetRange( const int min_x, const int min_y, const int max_x, const int max_y );
    void SetRange( const Ogre::Vector4& range );

    void AddTile( const int x, const int y, const int width, const int height, const float depth, const float u1, const float v1, const float u2, const float v2, const Blending blending );
    void AddTile( const Ogre::Vector2& destination, const int width, const int height, const float depth, const Ogre::Vector4& uv, const Blending blending );
    void AddTile( const QGears::Tile& tile );

    void UpdateTileUV( const unsigned int tile_id, const float u1, const float v1, const float u2, const float v2 );

    void AddAnimation( Background2DAnimation* animation );
    void PlayAnimation( const Ogre::String& animation, const Background2DAnimation::State state );
    void ScriptPlayAnimationLooped( const char* name );
    void ScriptPlayAnimationOnce( const char* name );
    int ScriptAnimationSync( const char* name );

    void renderQueueEnded( Ogre::uint8 queueGroupId, const Ogre::String& invocation, bool& repeatThisInvocation );

    struct Tile
    {
        int x;
        int y;
        int width;
        int height;
        size_t start_vertex_index;
        Blending blending;
    };
    typedef std::vector< Tile > TileList;

    virtual void load( const QGears::Background2DFilePtr &background );

protected:
    virtual void load( const QGears::Background2DFile::TileList &tiles );
    virtual void load( const size_t tile_index, const QGears::AnimationMap &animations );
    virtual void applyScroll( void );
    virtual void calculateScreenScale( void );
    virtual void virtualScreenToWorldSpace( Ogre::Vector2 &pos ) const;

    enum
    {
        TILE_VERTEX_COUNT = 6
       ,TILE_VERTEX_INDEX_SIZE = TILE_VERTEX_COUNT + 3
    };

private:
    void CreateVertexBuffers();
    void DestroyVertexBuffers();

private:
    Ogre::SceneManager*                   m_SceneManager;
    Ogre::RenderSystem*                   m_RenderSystem;

    TileList                              m_Tiles;

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

    // subtract blended
    Ogre::RenderOperation                 m_SubtractRenderOp;
    Ogre::HardwareVertexBufferSharedPtr   m_SubtractVertexBuffer;
    unsigned int                          m_SubtractMaxVertexCount;
    Ogre::MaterialPtr                     m_SubtractMaterial;

    Entity*                               m_ScrollEntity;
    Ogre::Vector2                         m_ScrollPositionStart;
    Ogre::Vector2                         m_ScrollPositionEnd;
    ScrollType                            m_ScrollType;
    float                                 m_ScrollSeconds;
    float                                 m_ScrollCurrentSeconds;
    std::vector< ScriptId >               m_ScrollSync;
    Ogre::Vector2                         m_Position;
    Ogre::Vector2                         m_PositionReal;

    Ogre::Real                            m_screen_scale;
    Ogre::Vector2                         m_screen_proportion;
    Ogre::Vector2                         m_virtual_screen_size;
    Ogre::AxisAlignedBox                  m_range;

    struct AnimationPlayed
    {
        Ogre::String                 name;
        std::vector< ScriptId >      sync;
        Background2DAnimation::State state;
    };
    std::vector< AnimationPlayed >        m_AnimationPlayed;
    std::vector< Background2DAnimation* > m_Animations;
};



#endif // BACKGROUND_2D_H
