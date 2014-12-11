#ifndef MOVABLE_TEXT_AREA_h
#define MOVABLE_TEXT_AREA_h

#include <OgreTextAreaOverlayElement.h>



class MovableTextArea : public Ogre::TextAreaOverlayElement
{
public:
                                MovableTextArea(const Ogre::String& name);
    virtual                    ~MovableTextArea();

    void                        Set3DPosition(const Ogre::Vector3& position);
    void                        SetAdditionalHeight(const float height);

protected:
    void                        getWorldTransforms(Ogre::Matrix4 *xform) const;

private:
    Ogre::Vector3    m_Position;
    float            m_AdditionalHeight;
};



#endif // MOVABLE_TEXT_AREA_h
