#include "Walkmesh.h"

#include "CameraManager.h"
#include "ConfigVar.h"
#include "DebugDraw.h"
#include "Logger.h"



ConfigVar cv_debug_walkmesh( "debug_walkmesh", "Draw walkmesh and walkmesh debug info", "false" );




Walkmesh::Walkmesh()
{
}



Walkmesh::~Walkmesh()
{
}



void
Walkmesh::Update()
{
    if( cv_debug_walkmesh.GetB() == true )
    {
        DEBUG_DRAW.SetScreenSpace( true );
        DEBUG_DRAW.SetTextAlignment( DEBUG_DRAW.CENTER );

        for( int i = 0; i < m_Triangles.size(); ++i )
        {
            Ogre::Vector3 triangle_pos = ( m_Triangles[ i ].a + m_Triangles[ i ].b + m_Triangles[ i ].c) / 3;
            Ogre::Vector3 point = CameraManager::getSingleton().ProjectPointToScreen( triangle_pos );

            if( m_Triangles[ i ].access_side[ 0 ] == -1 )
            {
                DEBUG_DRAW.SetColour( 1, 0, 0, 1 );
            }
            else
            {
                DEBUG_DRAW.SetColour( 1, 1, 1, 1 );
            }
            DEBUG_DRAW.Line3d( m_Triangles[ i ].a, m_Triangles[ i ].b );
            if( m_Triangles[ i ].access_side[ 1 ] == -1 )
            {
                DEBUG_DRAW.SetColour( 1, 0, 0, 1 );
            }
            else
            {
                DEBUG_DRAW.SetColour( 1, 1, 1, 1 );
            }
            DEBUG_DRAW.Line3d( m_Triangles[ i ].b, m_Triangles[ i ].c );
            if( m_Triangles[ i ].access_side[ 2 ] == -1 )
            {
                DEBUG_DRAW.SetColour( 1, 0, 0, 1 );
            }
            else
            {
                DEBUG_DRAW.SetColour( 1, 1, 1, 1 );
            }
            DEBUG_DRAW.Line3d( m_Triangles[ i ].c, m_Triangles[ i ].a );

            if( point.z <= 0 )
            {
                float dist_sq = triangle_pos.squaredDistance( CameraManager::getSingleton().GetCurrentCamera()->getPosition() );
                float fade_s = 20 * 20; // text start fading from this distance
                float fade_e = 25 * 25; // text fully faded from this distance

                if( dist_sq < fade_e )
                {
                    float a = ( dist_sq > fade_s ) ? ( 1.0f - ( dist_sq - fade_s ) / ( fade_e - fade_s ) ) : 1.0f;
                    DEBUG_DRAW.SetColour( 1, 1, 1, a );
                    DEBUG_DRAW.Text( point.x, point.y, Ogre::StringConverter::toString( i ) );
                }
            }
        }

        DEBUG_DRAW.SetTextAlignment( DEBUG_DRAW.LEFT );
    }
}



void
Walkmesh::Clear()
{
    m_Triangles.clear();
}



void
Walkmesh::AddTriangle( const WalkmeshTriangle& triangle )
{
    m_Triangles.push_back(triangle);
}



int
Walkmesh::GetAccessSide( unsigned int triangle_id, unsigned char side ) const
{
    if( triangle_id >= m_Triangles.size() )
    {
        LOG_ERROR( "Walkmesh::GetAccessSide: triangle_id greater than number of triangles in walkmesh or less than zero." );
        return -1;
    }

    if( side >= 3 )
    {
        LOG_ERROR( "Walkmesh::GetAccessSide: side greater than 2. Side indexed from 0 to 2." );
        return -1;
    }

    return m_Triangles[ triangle_id ].access_side[ side ];
}



const Ogre::Vector3&
Walkmesh::GetA( unsigned int triangle_id ) const
{
    if( triangle_id >= m_Triangles.size() )
    {
        LOG_ERROR( "Walkmesh::GetA: triangle_id greater than number of triangles in walkmesh or less than zero." );
        return Ogre::Vector3::ZERO;
    }

    return m_Triangles[ triangle_id ].a;
}



const Ogre::Vector3&
Walkmesh::GetB( unsigned int triangle_id ) const
{
    if( triangle_id >= m_Triangles.size() )
    {
        LOG_ERROR( "Walkmesh::GetB: triangle_id greater than number of triangles in walkmesh or less than zero." );
        return Ogre::Vector3::ZERO;
    }

    return m_Triangles[ triangle_id ].b;
}



const Ogre::Vector3&
Walkmesh::GetC( unsigned int triangle_id ) const
{
    if( triangle_id >= m_Triangles.size() )
    {
        LOG_ERROR( "Walkmesh::GetC: triangle_id greater than number of triangles in walkmesh or less than zero." );
        return Ogre::Vector3::ZERO;
    }

    return m_Triangles[ triangle_id ].c;
}



int
Walkmesh::GetNumberOfTriangles() const
{
    return m_Triangles.size();
}



void
Walkmesh::LockWalkmesh( unsigned int triangle_id, bool lock )
{
    if( triangle_id >= m_Triangles.size() )
    {
        LOG_ERROR( "Walkmesh::SetAccessible: triangle_id greater than number of triangles in walkmesh or less than zero." );
        return;
    }

    m_Triangles[ triangle_id ].locked = lock;
}



bool
Walkmesh::IsLocked( unsigned int triangle_id ) const
{
    if( triangle_id >= m_Triangles.size() )
    {
        LOG_ERROR( "Walkmesh::IsAccessible: triangle_id greater than number of triangles in walkmesh or less than zero." );
        return -1;
    }

    return m_Triangles[ triangle_id ].locked;
}
