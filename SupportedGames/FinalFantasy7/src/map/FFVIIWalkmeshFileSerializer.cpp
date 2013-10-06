/*
-----------------------------------------------------------------------------
Copyright (c) 2013-09-05 Tobias Peters <tobias.peters@kreativeffekt.at>

This file is part of Q-Gears

Q-Gears is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, version 2.0 (GPLv2) of the License.

Q-Gears is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.
-----------------------------------------------------------------------------
*/
#include "map/FFVIIWalkmeshFileSerializer.h"

#include <OgreLogManager.h>
#include <OgreException.h>

namespace FFVII
{
    //--------------------------------------------------------------------------
    WalkmeshFileXMLSerializer::WalkmeshFileXMLSerializer() :
        Serializer()
    {
    }

    //--------------------------------------------------------------------------
    WalkmeshFileXMLSerializer::~WalkmeshFileXMLSerializer()
    {
    }

    //--------------------------------------------------------------------------
    template<typename ValueType>
    void
    WalkmeshFileXMLSerializer::readVector( Ogre::DataStreamPtr &stream
                                       ,std::vector<ValueType> &pDest
                                       ,size_t count )
    {
        pDest.clear();
        pDest.reserve( count );
        for( size_t i( count ); i--; )
        {
            ValueType in_tmp;
            readObject( stream, in_tmp );
            pDest.push_back( in_tmp );
        }
    }

    //--------------------------------------------------------------------------
    void
    WalkmeshFileXMLSerializer::importWalkmeshFile( Ogre::DataStreamPtr &stream
                                               ,WalkmeshFile *pDest )
    {
        uint32 triangle_count( 0 );
        readInt( stream, triangle_count );

        TriangleList triangles;
        readVector( stream, triangles, triangle_count );

        AccessList access;
        readVector( stream, access, triangle_count );

        WalkmeshTriangleList   &triangle_list( pDest->getTriangles() );
        triangle_list.clear();
        triangle_list.reserve( triangle_count );

        for( uint32 i(0); i < triangle_count; ++i )
        {
            Triangle   &in_triangle( triangles[i] );
            Access     &in_access( access[i] );
            WalkmeshTriangle tmp_triangle;
            tmp_triangle.a = in_triangle.a;
            tmp_triangle.b = in_triangle.b;
            tmp_triangle.c = in_triangle.c;
            tmp_triangle.access_side[0] = in_access.a;
            tmp_triangle.access_side[1] = in_access.b;
            tmp_triangle.access_side[2] = in_access.c;
            triangle_list.push_back( tmp_triangle );
        }
    }

    //--------------------------------------------------------------------------
    void WalkmeshFileXMLSerializer::readObject( Ogre::DataStreamPtr &stream
                                            ,WalkmeshFileXMLSerializer::Triangle &pDest)
    {
        readObject( stream, pDest.a );
        readObject( stream, pDest.b );
        readObject( stream, pDest.c );
    }

    //--------------------------------------------------------------------------
    void WalkmeshFileXMLSerializer::readObject( Ogre::DataStreamPtr &stream
                                            ,Ogre::Vector3 &pDest )
    {
        sint16 tmp[ VERTEX_COMPONENT_COUNT ];
        readShorts( stream, reinterpret_cast<uint16*>( tmp ), VERTEX_COMPONENT_COUNT );
        pDest.x = static_cast<Ogre::Real>( tmp[0] );
        pDest.y = static_cast<Ogre::Real>( tmp[1] );
        pDest.z = static_cast<Ogre::Real>( tmp[2] );
    }

    //--------------------------------------------------------------------------
    void WalkmeshFileXMLSerializer::readObject( Ogre::DataStreamPtr &stream
                                            ,WalkmeshFileXMLSerializer::Access &pDest )
    {
        uint16 tmp[ ACCESS_COMPONENT_COUNT ];
        readShorts( stream, tmp, ACCESS_COMPONENT_COUNT );
        pDest.a = tmp[0];
        pDest.b = tmp[1];
        pDest.c = tmp[2];
    }

    //--------------------------------------------------------------------------
}
