#ifndef WINDOW_h
#define WINDOW_h

#include <OgreOverlayContainer.h>



class Window : public Ogre::OverlayContainer
{
public:
    Window(const Ogre::String& name);
    virtual ~Window();

    virtual void initialise(void);

    void SetTransparent(const bool transparent);

    void SetBackgroundColour(const Ogre::ColourValue& tl, const Ogre::ColourValue& tr, const Ogre::ColourValue& bl, const Ogre::ColourValue& br);

    void SetBackgroundUV(const float u1, const float v1, const float u2, const float v2);
    void SetBackgroundTransparentUV(const float u1, const float v1, const float u2, const float v2);
    void SetTopLeftUV(const float u1, const float v1, const float u2, const float v2);
    void SetTopUV(const float u1, const float v1, const float u2, const float v2);
    void SetTopRightUV(const float u1, const float v1, const float u2, const float v2);
    void SetLeftUV(const float u1, const float v1, const float u2, const float v2);
    void SetRightUV(const float u1, const float v1, const float u2, const float v2);
    void SetBottomLeftUV(const float u1, const float v1, const float u2, const float v2);
    void SetBottomUV(const float u1, const float v1, const float u2, const float v2);
    void SetBottomRightUV(const float u1, const float v1, const float u2, const float v2);

    /** See OverlayElement. */
    virtual const Ogre::String& getTypeName(void) const;
    /** See Renderable. */
    void getRenderOperation(Ogre::RenderOperation& op);
    /** Overridden from OverlayElement */
    void setMaterialName(const Ogre::String& matName);
    /** Overridden from OverlayContainer */
    void _updateRenderQueue(Ogre::RenderQueue* queue);

protected:
    /// internal method for setting up geometry, called by OverlayElement::update
    virtual void updatePositionGeometry(void);

    /// Called to update the texture coords when layers change
    virtual void updateTextureGeometry(void);

    virtual void updateColours(void);

protected:
    Ogre::RenderOperation mRenderOp;

    static Ogre::String msTypeName;

    float             m_BorderWidth;
    float             m_BackgroundPadding;

    bool              m_Transparent;

    float m_BackgroundU1,   m_BackgroundV1,   m_BackgroundU2,   m_BackgroundV2;
    float m_BackgroundTrU1, m_BackgroundTrV1, m_BackgroundTrU2, m_BackgroundTrV2;
    float m_TopLeftU1,      m_TopLeftV1,      m_TopLeftU2,      m_TopLeftV2;
    float m_TopU1,          m_TopV1,          m_TopU2,          m_TopV2;
    float m_TopRightU1,     m_TopRightV1,     m_TopRightU2,     m_TopRightV2;
    float m_LeftU1,         m_LeftV1,         m_LeftU2,         m_LeftV2;
    float m_RightU1,        m_RightV1,        m_RightU2,        m_RightV2;
    float m_BottomLeftU1,   m_BottomLeftV1,   m_BottomLeftU2,   m_BottomLeftV2;
    float m_BottomU1,       m_BottomV1,       m_BottomU2,       m_BottomV2;
    float m_BottomRightU1,  m_BottomRightV1,  m_BottomRightU2,  m_BottomRightV2;

    Ogre::ColourValue m_TopLeft;
    Ogre::ColourValue m_TopRight;
    Ogre::ColourValue m_BottomLeft;
    Ogre::ColourValue m_BottomRight;
};



#endif // WINDOW_h
