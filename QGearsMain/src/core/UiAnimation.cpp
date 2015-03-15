#include <OgreVector2.h>

#include "core/UiAnimation.h"
#include "core/UiWidget.h"


UiAnimation::UiAnimation(const Ogre::String& name, UiWidget* widget):
    m_Name(name),
    m_Widget(widget),
    m_Time(0),
    m_Length(0)
{
}


UiAnimation::~UiAnimation()
{
}


void
UiAnimation::AddTime(const float time)
{
    m_Time += time;
    if(m_Time > m_Length)
    {
        m_Time = m_Length;
    }



    if( m_Scale.size() > 0 )
    {
        m_Widget->SetScale( KeyFrameGetValue( m_Scale ) );
    }

    if( m_X.size() > 0 )
    {
        Ogre::Vector2 value = KeyFrameGetValue( m_X );
        m_Widget->SetX( value.x, value.y );
    }

    if( m_Y.size() > 0 )
    {
        Ogre::Vector2 value = KeyFrameGetValue( m_Y );
        m_Widget->SetY( value.x, value.y );
    }

    if( m_Width.size() > 0 )
    {
        Ogre::Vector2 value = KeyFrameGetValue( m_Width );
        m_Widget->SetWidth( value.x, value.y );
    }

    if( m_Height.size() > 0 )
    {
        Ogre::Vector2 value = KeyFrameGetValue( m_Height );
        m_Widget->SetHeight( value.x, value.y );
    }

    if( m_Rotation.size() > 0 )
    {
        m_Widget->SetRotation( KeyFrameGetValue( m_Rotation ) );
    }

    if( m_Alpha.size() > 0 )
    {
        m_Widget->SetAlpha( KeyFrameGetValue( m_Alpha ) );
    }

    if( m_ScissorXTop.size() > 0 )
    {
        Ogre::Vector2 value1 =  KeyFrameGetValue( m_ScissorXTop );
        Ogre::Vector2 value2 =  KeyFrameGetValue( m_ScissorYLeft );
        Ogre::Vector2 value3 =  KeyFrameGetValue( m_ScissorXBottom );
        Ogre::Vector2 value4 =  KeyFrameGetValue( m_ScissorYRight );

        m_Widget->SetScissorArea( value1.x, value1.y, value2.x, value2.y, value3.x, value3.y, value4.x, value4.y );
    }
}



const Ogre::String&
UiAnimation::GetName() const
{
    return m_Name;
}



void
UiAnimation::SetTime( const float time )
{
    m_Time = time;
}



float
UiAnimation::GetTime() const
{
    return m_Time;
}



void
UiAnimation::SetLength( const float time )
{
    m_Length = time;
}



float
UiAnimation::GetLength() const
{
    return m_Length;
}



void
UiAnimation::AddScaleKeyFrame( const UiKeyFrameVector2& key_frame )
{
    m_Scale.push_back( key_frame );
}



void
UiAnimation::AddXKeyFrame( const UiKeyFrameVector2& key_frame )
{
    m_X.push_back( key_frame );
}



void
UiAnimation::AddYKeyFrame( const UiKeyFrameVector2& key_frame )
{
    m_Y.push_back( key_frame );
}



void
UiAnimation::AddWidthKeyFrame( const UiKeyFrameVector2& key_frame )
{
    m_Width.push_back( key_frame );
}



void
UiAnimation::AddHeightKeyFrame( const UiKeyFrameVector2& key_frame )
{
    m_Height.push_back( key_frame );
}



void
UiAnimation::AddRotationKeyFrame( const UiKeyFrameFloat& key_frame )
{
    m_Rotation.push_back( key_frame );
}



void
UiAnimation::AddAlphaKeyFrame( const UiKeyFrameFloat& key_frame )
{
    m_Alpha.push_back( key_frame );
}



void
UiAnimation::AddScissorKeyFrame( const UiKeyFrameVector2& x1, const UiKeyFrameVector2& y1, const UiKeyFrameVector2& x2, const UiKeyFrameVector2& y2 )
{
    m_ScissorXTop.push_back( x1 );
    m_ScissorYLeft.push_back( y1 );
    m_ScissorXBottom.push_back( x2 );
    m_ScissorYRight.push_back( y2 );
}



float
UiAnimation::KeyFrameGetValue( std::vector< UiKeyFrameFloat >& data )
{
    float min_value = data[ 0 ].value;
    float max_value = min_value;
    float min = 0;
    float max = m_Length;

    for( unsigned int i = 0; i < data.size(); ++i )
    {
        if( data[ i ].time < m_Time && data[ i ].time > min )
        {
            min_value = data[ i ].value;
            min = data[ i ].time;
        }

        if( data[ i ].time >= m_Time && data[ i ].time <= max )
        {
            max_value = data[ i ].value;
            max = data[ i ].time;
        }
    }

    float value;

    if( m_Time == 0 )
    {
        value = min_value;
    }
    else
    {
        value = min_value + ( max_value - min_value ) * ( ( m_Time - min ) / ( max - min ) );
    }

    return value;
}



Ogre::Vector2
UiAnimation::KeyFrameGetValue( std::vector< UiKeyFrameVector2 >& data )
{
    Ogre::Vector2 min_value = data[ 0 ].value;
    Ogre::Vector2 max_value = min_value;
    float min = 0;
    float max = m_Length;

    for( unsigned int i = 0; i < data.size(); ++i )
    {
        if( data[ i ].time < m_Time && data[ i ].time > min )
        {
            min_value = data[ i ].value;
            min = data[ i ].time;
        }

        if( data[ i ].time >= m_Time && data[ i ].time <= max )
        {
            max_value = data[ i ].value;
            max = data[ i ].time;
        }
    }

    Ogre::Vector2 value;

    if( m_Time == 0 )
    {
        value = min_value;
    }
    else
    {
        value = min_value + ( max_value - min_value ) * ( ( m_Time - min ) / ( max - min ) );
    }

    return value;
}
