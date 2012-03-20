#ifndef WALKMESH_H
#define WALKMESH_H

#include <OgreVector3.h>
#include <vector>



struct WalkmeshTriangle
{
    WalkmeshTriangle():
        a( 0, 0, 0 ),
        b( 0, 0, 0 ),
        c( 0, 0, 0 ),
        locked( false )
    {
        access_side[ 0 ] = -1;
        access_side[ 1 ] = -1;
        access_side[ 2 ] = -1;
    }

    Ogre::Vector3 a;
    Ogre::Vector3 b;
    Ogre::Vector3 c;

    int           access_side[ 3 ];
    bool          locked;
};



class Walkmesh
{
public:
    Walkmesh();
    virtual ~Walkmesh();

    void Update();
    void Clear();

    void AddTriangle( const WalkmeshTriangle& triangle );

    int GetAccessSide( unsigned int triangle_id, unsigned char side ) const;
    const Ogre::Vector3& GetA( unsigned int triangle_id ) const;
    const Ogre::Vector3& GetB( unsigned int triangle_id ) const;
    const Ogre::Vector3& GetC( unsigned int triangle_id ) const;
    int GetNumberOfTriangles() const;
    void LockWalkmesh( unsigned int triangle_id, bool lock );
    bool IsLocked( unsigned int triangle_id ) const;

private:
    std::vector< WalkmeshTriangle > m_Triangles;
};



#endif // WALKMESH_H
