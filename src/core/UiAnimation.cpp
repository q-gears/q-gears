#include "UiAnimation.h"

#include <OgreVector2.h>

#include "UiWidget.h"



UiAnimation::UiAnimation( const Ogre::String& name, UiWidget* widget ):
    m_Name( name ),
    m_Widget( widget ),
    m_Time( 0 ),
    m_Length( 0 )
{
}



UiAnimation::~UiAnimation()
{
}



void
UiAnimation::AddTime( const float time )
{
    m_Time += time;
    if( m_Time > m_Length )
    {
        m_Time = m_Length;
    }



    // update all
    if( m_Scale.size() > 0 )
    {
        Ogre::Vector2 min_value = m_Scale[ 0 ].value;
        Ogre::Vector2 max_value = min_value;
        float min = 0;
        float max = m_Length;

        for( size_t i = 0; i < m_Scale.size(); ++i )
        {
            if( m_Scale[ i ].time < m_Time && m_Scale[ i ].time > min )
            {
                min_value = m_Scale[ i ].value;
                min = m_Scale[ i ].time;
            }

            if( m_Scale[ i ].time >= m_Time && m_Scale[ i ].time <= max )
            {
                max_value = m_Scale[ i ].value;
                max = m_Scale[ i ].time;
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

        m_Widget->SetScale( value );
    }



    if( m_X.size() > 0 )
    {
        Ogre::Vector2 min_value = m_X[ 0 ].value;
        Ogre::Vector2 max_value = min_value;
        float min = 0;
        float max = m_Length;

        for( size_t i = 0; i < m_X.size(); ++i )
        {
            if( m_X[ i ].time < m_Time && m_X[ i ].time > min )
            {
                min_value = m_X[ i ].value;
                min = m_X[ i ].time;
            }

            if( m_X[ i ].time >= m_Time && m_X[ i ].time <= max )
            {
                max_value = m_X[ i ].value;
                max = m_X[ i ].time;
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

        m_Widget->SetX( value.x, value.y );
    }



    if( m_Y.size() > 0 )
    {
        Ogre::Vector2 min_value = m_Y[ 0 ].value;
        Ogre::Vector2 max_value = min_value;
        float min = 0;
        float max = m_Length;

        for( size_t i = 0; i < m_Y.size(); ++i )
        {
            if( m_Y[ i ].time < m_Time && m_Y[ i ].time > min )
            {
                min_value = m_Y[ i ].value;
                min = m_Y[ i ].time;
            }

            if( m_Y[ i ].time >= m_Time && m_Y[ i ].time <= max )
            {
                max_value = m_Y[ i ].value;
                max = m_Y[ i ].time;
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

        m_Widget->SetY( value.x, value.y );
    }



    if( m_Rotation.size() > 0 )
    {
        float min_value = m_Rotation[ 0 ].value;
        float max_value = min_value;
        float min = 0;
        float max = m_Length;

        for( size_t i = 0; i < m_Rotation.size(); ++i )
        {
            if( m_Rotation[ i ].time < m_Time && m_Rotation[ i ].time > min )
            {
                min_value = m_Rotation[ i ].value;
                min = m_Rotation[ i ].time;
            }

            if( m_Rotation[ i ].time >= m_Time && m_Rotation[ i ].time <= max )
            {
                max_value = m_Rotation[ i ].value;
                max = m_Rotation[ i ].time;
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

        m_Widget->SetRotation( value );
    }



    if( m_Alpha.size() > 0 )
    {
        float min_value = m_Alpha[ 0 ].value;
        float max_value = min_value;
        float min = 0;
        float max = m_Length;

        for( size_t i = 0; i < m_Alpha.size(); ++i )
        {
            if( m_Alpha[ i ].time < m_Time && m_Alpha[ i ].time > min )
            {
                min_value = m_Alpha[ i ].value;
                min = m_Alpha[ i ].time;
            }

            if( m_Alpha[ i ].time >= m_Time && m_Alpha[ i ].time <= max )
            {
                max_value = m_Alpha[ i ].value;
                max = m_Alpha[ i ].time;
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

        m_Widget->SetAlpha( value );
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
UiAnimation::AddRotationKeyFrame( const UiKeyFrameFloat& key_frame )
{
    m_Rotation.push_back( key_frame );
}



void
UiAnimation::AddAlphaKeyFrame( const UiKeyFrameFloat& key_frame )
{
    m_Alpha.push_back( key_frame );
}
