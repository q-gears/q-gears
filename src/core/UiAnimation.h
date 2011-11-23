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



class UiAnimation
{
public:
    UiAnimation( const Ogre::String& name, UiWidget* widget );
    virtual ~UiAnimation();

    enum State
    {
        DEFAULT,
        ONCE
    };

    void AddTime( const float time );

    const Ogre::String& GetName() const;

    void SetTime( const float time );
    const float GetTime() const;
    void SetLength( const float time );
    const float GetLength() const;
    void AddScaleKeyFrame( const UiKeyFrameVector2& key_frame );
    void AddXKeyFrame( const UiKeyFrameVector2& key_frame );
    void AddYKeyFrame( const UiKeyFrameVector2& key_frame );
    void AddRotationKeyFrame( const UiKeyFrameFloat& key_frame );
    void AddAlphaKeyFrame( const UiKeyFrameFloat& key_frame );

private:
    UiAnimation();

    Ogre::String m_Name;
    UiWidget*    m_Widget;

    float        m_Time;
    float        m_Length;

    std::vector< UiKeyFrameVector2 > m_Scale;
    std::vector< UiKeyFrameVector2 > m_X;
    std::vector< UiKeyFrameVector2 > m_Y;
    std::vector< UiKeyFrameFloat >   m_Rotation;
    std::vector< UiKeyFrameFloat >   m_Alpha;
};



#endif // UI_ANIMATION_H
