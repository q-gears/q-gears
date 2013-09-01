#include "Background2DAnimation.h"

#include <OgreVector2.h>

#include "Background2D.h"
#include "Logger.h"



//-----------------------------------------------------------------------------
Background2DAnimation::Background2DAnimation( const Ogre::String& name, Background2D* background, const int tile_index ):
    m_Name( name ),
    m_Background( background ),
    m_TileIndex( tile_index ),
    m_Time( 0 ),
    m_Length( 0 )
{
}

//-----------------------------------------------------------------------------
Background2DAnimation::~Background2DAnimation()
{
}

//-----------------------------------------------------------------------------
void
Background2DAnimation::AddTime( const float time )
{
    m_Time += time;
    if( m_Time > m_Length )
    {
        m_Time = m_Length;
    }

    if( m_UV.size() > 0 )
    {
        int min_id = -1;
        float min_time = 0;

        for( unsigned int i = 0; i < m_UV.size(); ++i )
        {
            if( m_UV[ i ].time <= m_Time && m_UV[ i ].time >= min_time )
            {
                min_id = i;
                min_time = m_UV[ i ].time;
            }
        }

        if( min_id != -1 )
        {
            m_Background->UpdateTileUV( m_TileIndex, m_UV[ min_id ].u1, m_UV[ min_id ].v1, m_UV[ min_id ].u2, m_UV[ min_id ].v2 );
        }
    }
}

//-----------------------------------------------------------------------------
const Ogre::String&
Background2DAnimation::GetName() const
{
    return m_Name;
}

//-----------------------------------------------------------------------------
void
Background2DAnimation::SetTime( const float time )
{
    m_Time = time;
}

//-----------------------------------------------------------------------------
float
Background2DAnimation::GetTime() const
{
    return m_Time;
}

//-----------------------------------------------------------------------------
void
Background2DAnimation::SetLength( const float time )
{
    m_Length = time;
}

//-----------------------------------------------------------------------------
float
Background2DAnimation::GetLength() const
{
    return m_Length;
}

//-----------------------------------------------------------------------------
void
Background2DAnimation::AddUVKeyFrame( const QGears::KeyFrame key_frame )
{
    AddUVKeyFrame( key_frame.time, key_frame.uv );
}

//-----------------------------------------------------------------------------
void
Background2DAnimation::AddUVKeyFrame( const float time, const Ogre::Vector4& uv )
{
    AddUVKeyFrame( time, uv.x, uv.y, uv.z, uv.w );
}

//-----------------------------------------------------------------------------
void
Background2DAnimation::AddUVKeyFrame( const float time, const float u1, const float v1, const float u2, const float v2 )
{
    Background2DKeyFrameUV uv_key_frame;
    uv_key_frame.time = time;
    uv_key_frame.u1 = u1;
    uv_key_frame.v1 = v1;
    uv_key_frame.u2 = u2;
    uv_key_frame.v2 = v2;
    m_UV.push_back( uv_key_frame );
}

//-----------------------------------------------------------------------------
