#ifndef UI_ANIMATION_H
#define UI_ANIMATION_H

#include <OgreString.h>
#include <vector>



class UiAnimation
{
public:
    UiAnimation( const Ogre::String& name, UiWidget* widget );
    virtual ~UiAnimation();

    void AddTime( const float time );

    const Ogre::String& GetName() const;

private:
    UiAnimation();

    Ogre::String m_Name;
    UiWidget*    m_Widget;

    float        m_Time;

    std::vector< float > m_TrackScaleX;
};



#endif // UI_ANIMATION_H
