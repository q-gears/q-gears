#include "core/Walkmesh.h"

#include "core/ConfigVar.h"
#include "core/DebugDraw.h"
#include "core/Logger.h"
#include "map/QGearsWalkmeshFile.h"


ConfigVar cv_debug_walkmesh( "debug_walkmesh", "Draw walkmesh and walkmesh debug info", "false" );




Walkmesh::Walkmesh()
{
}



Walkmesh::~Walkmesh()
{
}



void
Walkmesh::UpdateDebug()
{
    if( cv_debug_walkmesh.GetB() == true )
    {
        DEBUG_DRAW.SetScreenSpace( true );
        DEBUG_DRAW.SetTextAlignment( DEBUG_DRAW.CENTER );

        for( unsigned int i = 0; i < m_Triangles.size(); ++i )
        {
            if( m_Triangles[ i ].access_side[ 0 ] == -1 )
            {
                DEBUG_DRAW.SetColour( Ogre::ColourValue( 1, 0, 0, 1 ) );
            }
            else
            {
                DEBUG_DRAW.SetColour( Ogre::ColourValue( 1, 1, 1, 1 ) );
            }
            DEBUG_DRAW.Line3d( m_Triangles[ i ].a, m_Triangles[ i ].b );

            if( m_Triangles[ i ].access_side[ 1 ] == -1 )
            {
                DEBUG_DRAW.SetColour( Ogre::ColourValue( 1, 0, 0, 1 ) );
            }
            else
            {
                DEBUG_DRAW.SetColour( Ogre::ColourValue( 1, 1, 1, 1 ) );
            }
            DEBUG_DRAW.Line3d( m_Triangles[ i ].b, m_Triangles[ i ].c );

            if( m_Triangles[ i ].access_side[ 2 ] == -1 )
            {
                DEBUG_DRAW.SetColour( Ogre::ColourValue( 1, 0, 0, 1 ) );
            }
            else
            {
                DEBUG_DRAW.SetColour( Ogre::ColourValue( 1, 1, 1, 1 ) );
            }
            DEBUG_DRAW.Line3d( m_Triangles[ i ].c, m_Triangles[ i ].a );

            /*
            if( m_Triangles[ i ].locked == false )
            {
                DEBUG_DRAW.SetColour( Ogre::ColourValue( 1, 1, 1, 0.5 ) );
            }
            else
            {
                DEBUG_DRAW.SetColour( Ogre::ColourValue( 1, 0, 0, 0.5 ) );
            }
            */
            //DEBUG_DRAW.Triangle3d( m_Triangles[ i ].a, m_Triangles[ i ].b, m_Triangles[ i ].c );

            DEBUG_DRAW.SetColour( Ogre::ColourValue( 1, 1, 1, 1 ) );
            DEBUG_DRAW.SetFadeDistance( 40, 50 );
            Ogre::Vector3 triangle_pos = ( m_Triangles[ i ].a + m_Triangles[ i ].b + m_Triangles[ i ].c) / 3;
            DEBUG_DRAW.Text( triangle_pos, 0, 0, Ogre::StringConverter::toString( i ) );
        }
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
    m_Triangles.push_back( triangle );
}



int
Walkmesh::GetAccessSide( unsigned int triangle_id, unsigned char side ) const
{
    if( triangle_id >= m_Triangles.size() )
    {
        LOG_ERROR( "Triangle_id greater than number of triangles in walkmesh or less than zero." );
        return -1;
    }

    if( side >= 3 )
    {
        LOG_ERROR( "Side greater than 2. Side indexed from 0 to 2." );
        return -1;
    }

    return m_Triangles[ triangle_id ].access_side[ side ];
}



const Ogre::Vector3&
Walkmesh::GetA( unsigned int triangle_id ) const
{
    if( triangle_id >= m_Triangles.size() )
    {
        LOG_ERROR( "Triangle_id greater than number of triangles in walkmesh or less than zero." );
        return Ogre::Vector3::ZERO;
    }

    return m_Triangles[ triangle_id ].a;
}



const Ogre::Vector3&
Walkmesh::GetB( unsigned int triangle_id ) const
{
    if( triangle_id >= m_Triangles.size() )
    {
        LOG_ERROR( "Triangle_id greater than number of triangles in walkmesh or less than zero." );
        return Ogre::Vector3::ZERO;
    }

    return m_Triangles[ triangle_id ].b;
}



const Ogre::Vector3&
Walkmesh::GetC( unsigned int triangle_id ) const
{
    if( triangle_id >= m_Triangles.size() )
    {
        LOG_ERROR( "Triangle_id greater than number of triangles in walkmesh or less than zero." );
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
        LOG_ERROR( "Triangle_id greater than number of triangles in walkmesh or less than zero." );
        return;
    }

    m_Triangles[ triangle_id ].locked = lock;
}



bool
Walkmesh::IsLocked( unsigned int triangle_id ) const
{
    if( triangle_id >= m_Triangles.size() )
    {
        LOG_ERROR( "Triangle_id greater than number of triangles in walkmesh or less than zero." );
        return false;
    }

    return m_Triangles[ triangle_id ].locked;
}

//------------------------------------------------------------------------------
void Walkmesh::load(const QGears::WalkmeshFilePtr &walkmesh)
{
    QGears::WalkmeshFile::TriangleList &triangles( walkmesh->getTriangles() );
    QGears::WalkmeshFile::TriangleList::const_iterator it( triangles.begin() );
    QGears::WalkmeshFile::TriangleList::const_iterator it_end( triangles.end() );
    while( it != it_end )
    {
        AddTriangle( *it );
        ++it;
    }
}

//------------------------------------------------------------------------------
