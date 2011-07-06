#include "UiAnimation.h"

#include <OgreVector2.h>

#include "UiWidget.h"



UiAnimation::UiAnimation( const Ogre::String& name, UiWidget* widget ):
    m_Name( name ),
    m_Widget( widget )
{
    UiKeyFrameVector2 key;
    key.time = 0;
    key.value = Ogre::Vector2( 1.0f, 1.0f );
    m_TrackScale.push_back( key );
    key.time = 5;
    key.value = Ogre::Vector2( 2.0f, 2.0f );
    m_TrackScale.push_back( key );
    key.time = 10;
    key.value = Ogre::Vector2( 0.5f, 0.5f );
    m_TrackScale.push_back( key );

    m_Time = 0;
    m_TimeTotal = 10;
}



UiAnimation::~UiAnimation()
{
}



void
UiAnimation::AddTime( const float time )
{
    m_Time += time;
    if( m_Time > m_TimeTotal )
    {
        m_Time = m_TimeTotal;
    }



    // update all
    if( m_TrackScale.size() > 0 )
    {
        Ogre::Vector2 min_value = m_TrackScale[ 0 ].value;
        Ogre::Vector2 max_value = min_value;
        float min = 0;
        float max = m_TimeTotal;

        for( int i = 0; i < m_TrackScale.size(); ++i )
        {
            if( m_TrackScale[ i ].time < m_Time && m_TrackScale[ i ].time > min )
            {
                min_value = m_TrackScale[ i ].value;
                min = m_TrackScale[ i ].time;
            }

            if( m_TrackScale[ i ].time >= m_Time && m_TrackScale[ i ].time <= max )
            {
                max_value = m_TrackScale[ i ].value;
                max = m_TrackScale[ i ].time;
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
}
