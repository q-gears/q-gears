#include "UiAnimation.h"

#include <OgreVector2.h>

#include "UiWidget.h"



UiAnimation::UiAnimation( const Ogre::String& name, UiWidget* widget ):
    m_Name( name ),
    m_Widget( widget )
{
    KeyFrameFloat key;
    key.time = 0;
    key.value = 1;
    m_TrackScaleX.push_back( key );
    key.time = 5;
    key.value = 2.0;
    m_TrackScaleX.push_back( key );
    key.time = 10;
    key.value = 0.1;
    m_TrackScaleX.push_back( key );

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
    if( m_TrackScaleX.size() > 0 )
    {
        float min_value = m_TrackScaleX[ 0 ].value;
        float max_value = min_value;
        float min = 0;
        float max = m_TimeTotal;

        for( int i = 0; i < m_TrackScaleX.size(); ++i )
        {
            if( m_TrackScaleX[ i ].time < m_Time && m_TrackScaleX[ i ].time > min )
            {
                min_value = m_TrackScaleX[ i ].value;
                min = m_TrackScaleX[ i ].time;
            }

            if( m_TrackScaleX[ i ].time > m_Time && m_TrackScaleX[ i ].time < max )
            {
                max_value = m_TrackScaleX[ i ].value;
                max = m_TrackScaleX[ i ].time;
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

        m_Widget->SetScale( Ogre::Vector2( value, 1 ) );
    }
}
