#ifndef FADE_h
#define FADE_h

#include <OgreOverlayContainer.h>



class Fade : public Ogre::OverlayContainer
{
public:
    Fade(const Ogre::String& name);
    virtual ~Fade();

    virtual void initialise(void);

    void SetColour(const Ogre::ColourValue& colour);

    void SetBackgroundUV(const float u1, const float v1, const float u2, const float v2);

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

    float m_BackgroundU1,   m_BackgroundV1,   m_BackgroundU2,   m_BackgroundV2;

    Ogre::ColourValue m_Colour;
};



#endif // FADE_h
