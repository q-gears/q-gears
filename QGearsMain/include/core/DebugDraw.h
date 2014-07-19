#ifndef DEBUG_DRAW_H
#define DEBUG_DRAW_H

#include <OgreHardwareVertexBuffer.h>
#include <OgreRenderQueueListener.h>
#include <OgreRoot.h>
#include <OgreSingleton.h>
#include <Overlay/OgreFont.h>


class DebugDraw : public Ogre::RenderQueueListener, public Ogre::Singleton< DebugDraw >
{
public:
    DebugDraw();
    virtual ~DebugDraw();

    void SetColour( const Ogre::ColourValue& colour );
    void SetScreenSpace( const bool screen_space );
    void SetZ( const float z );
    void SetFadeDistance( const float fade_s, const float fade_e );

    enum TextAlignment
    {
        LEFT,
        RIGHT,
        CENTER
    };
    void SetTextAlignment( TextAlignment alignment );

    void Line( const float x1, const float y1, const float x2, const float y2 );
    void Line3d( const Ogre::Vector3& point1, const Ogre::Vector3& point2 );
    void Triangle3d( const Ogre::Vector3& point1, const Ogre::Vector3& point2, const Ogre::Vector3& point3 );
    void Quad( const float x1, const float y1, const float x2, const float y2, const float x3, const float y3, const float x4, const float y4 );
    void Text( const float x1, const float y1, const Ogre::String& text );
    void Text( const Ogre::Vector3& point, const float x, const float y, const Ogre::String& text );

    void renderQueueEnded( Ogre::uint8 queueGroupId, const Ogre::String& invocation, bool& repeatThisInvocation );

private:
    void CreateLineVertexBuffer();
    void DestroyLineVertexBuffer();
    void CreateLine3dVertexBuffer();
    void DestroyLine3dVertexBuffer();
    void CreateTriangle3dVertexBuffer();
    void DestroyTriangle3dVertexBuffer();
    void CreateQuadVertexBuffer();
    void DestroyQuadVertexBuffer();
    void CreateTextVertexBuffer();
    void DestroyTextVertexBuffer();

private:
    Ogre::SceneManager* m_SceneManager;
    Ogre::RenderSystem* m_RenderSystem;

    // line
    Ogre::RenderOperation               m_LineRenderOp;
    Ogre::HardwareVertexBufferSharedPtr m_LineVertexBuffer;
    unsigned int                        m_LineMaxVertexCount;

    // line3d
    Ogre::RenderOperation               m_Line3dRenderOp;
    Ogre::HardwareVertexBufferSharedPtr m_Line3dVertexBuffer;
    unsigned int                        m_Line3dMaxVertexCount;

    // triangle3d
    Ogre::RenderOperation               m_Triangle3dRenderOp;
    Ogre::HardwareVertexBufferSharedPtr m_Triangle3dVertexBuffer;
    unsigned int                        m_Triangle3dMaxVertexCount;

    // quad
    Ogre::RenderOperation               m_QuadRenderOp;
    Ogre::HardwareVertexBufferSharedPtr m_QuadVertexBuffer;
    unsigned int                        m_QuadMaxVertexCount;

    // text
    Ogre::RenderOperation               m_TextRenderOp;
    Ogre::HardwareVertexBufferSharedPtr m_TextVertexBuffer;
    unsigned int                        m_TextMaxVertexCount;
    Ogre::FontPtr                       m_Font;
    int                                 m_FontHeight;
    TextAlignment                       m_TextAlignment;

    Ogre::MaterialPtr                   m_Material;
    Ogre::MaterialPtr                   m_Material3d;
    Ogre::ColourValue                   m_Colour;
    bool                                m_ScreenSpace;
    float                               m_Z;
    float                               m_FadeStartSquare; // text start fading from this distance
    float                               m_FadeEndSquare; // text fully faded from this distance
};



#define DEBUG_DRAW DebugDraw::getSingleton()



#endif // DEBUG_DRAW_H
