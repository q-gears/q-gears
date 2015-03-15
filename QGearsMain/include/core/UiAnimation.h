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
    float GetTime() const;
    void SetLength( const float time );
    float GetLength() const;
    void AddScaleKeyFrame( const UiKeyFrameVector2& key_frame );
    void AddXKeyFrame( const UiKeyFrameVector2& key_frame );
    void AddYKeyFrame( const UiKeyFrameVector2& key_frame );
    void AddWidthKeyFrame( const UiKeyFrameVector2& key_frame );
    void AddHeightKeyFrame( const UiKeyFrameVector2& key_frame );
    void AddRotationKeyFrame( const UiKeyFrameFloat& key_frame );
    void AddAlphaKeyFrame( const UiKeyFrameFloat& key_frame );
    void AddScissorKeyFrame( const UiKeyFrameVector2& x1, const UiKeyFrameVector2& y1, const UiKeyFrameVector2& x2, const UiKeyFrameVector2& y2 );

private:
    UiAnimation();

    float KeyFrameGetValue( std::vector< UiKeyFrameFloat >& data );
    Ogre::Vector2 KeyFrameGetValue( std::vector< UiKeyFrameVector2 >& data );

    Ogre::String m_Name;
    UiWidget*    m_Widget;

    float        m_Time;
    float        m_Length;

    std::vector< UiKeyFrameVector2 > m_Scale;
    std::vector< UiKeyFrameVector2 > m_X;
    std::vector< UiKeyFrameVector2 > m_Y;
    std::vector< UiKeyFrameVector2 > m_Width;
    std::vector< UiKeyFrameVector2 > m_Height;
    std::vector< UiKeyFrameFloat >   m_Rotation;
    std::vector< UiKeyFrameFloat >   m_Alpha;

    std::vector< UiKeyFrameVector2 > m_ScissorXTop;
    std::vector< UiKeyFrameVector2 > m_ScissorYLeft;
    std::vector< UiKeyFrameVector2 > m_ScissorXBottom;
    std::vector< UiKeyFrameVector2 > m_ScissorYRight;
};



#endif // UI_ANIMATION_H
