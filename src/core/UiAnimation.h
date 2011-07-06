#ifndef UI_ANIMATION_H
#define UI_ANIMATION_H

#include <OgreString.h>
#include <OgreVector2.h>
#include <vector>



class UiWidget;



struct UiKeyFrameFloat
{
    float time;
    float value;
};



struct UiKeyFrameVector2
{
    float time;
    Ogre::Vector2 value;
};



struct UiKeyFramePercent
{
};



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
    float        m_TimeTotal;

    std::vector< UiKeyFrameVector2 > m_TrackScale;
};



#endif // UI_ANIMATION_H
