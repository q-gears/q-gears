#ifndef GUI_EFFECT_H
#define GUI_EFFECT_H

#include <OgreOverlayContainer.h>



class GuiEffect : public Ogre::OverlayContainer
{
public:
    GuiEffect( const Ogre::String& name );
    virtual ~GuiEffect();

    virtual void initialise();

    virtual const Ogre::String& getTypeName() const;
    void getRenderOperation( Ogre::RenderOperation& op );

protected:
    virtual void updatePositionGeometry();
    virtual void updateTextureGeometry();

private:
    Ogre::RenderOperation m_RenderOp;
};



#endif // GUI_EFFECT_H
