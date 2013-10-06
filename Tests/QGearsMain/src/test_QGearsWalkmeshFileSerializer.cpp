/*
-----------------------------------------------------------------------------
Copyright (c) 06.10.2013 Tobias Peters <tobias.peters@kreativeffekt.at>

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
#include <fstream>

#include <boost/test/unit_test.hpp>
#include <Ogre.h>

#include "data/QGearsWalkmeshFileSerializer.h"

BOOST_AUTO_TEST_CASE( read_file )
{
    class TestFile : public QGears::WalkmeshFile
    {
    public:
        TestFile() : QGears::WalkmeshFile( NULL, "", 0, "" ) {}
        size_t getCalculatedSize() const { return calculateSize(); }

        virtual void unload( void ) {}
    };
    const char* file_name( "misc/reference.walkmesh" );
    std::ifstream *ifs(  OGRE_NEW_T( std::ifstream, Ogre::MEMCATEGORY_GENERAL )( file_name, std::ifstream::binary ) );
    BOOST_REQUIRE( ifs->is_open() );
    Ogre::DataStreamPtr stream( OGRE_NEW Ogre::FileStreamDataStream( ifs ) );
    BOOST_REQUIRE( stream->isReadable() );

    Ogre::LogManager                logMgr;
    QGears::WalkmeshFileXMLSerializer  ser;
    TestFile                        f;

    logMgr.createLog( "Default Log", true, true, true );

    ser.importWalkmeshFile( stream, &f );
    QGears::WalkmeshFile::TriangleList &triangles( f.getTriangles() );
    BOOST_CHECK_EQUAL( 39, triangles.size() );

    QGears::WalkmeshFile::Triangle &t1( triangles.front() );
    BOOST_CHECK_EQUAL( Ogre::Vector3( 3784, 27544, 325 ), t1.a );
    BOOST_CHECK_EQUAL( Ogre::Vector3( 3778, 27434, 325 ), t1.b );
    BOOST_CHECK_EQUAL( Ogre::Vector3( 3751, 27410, 310 ), t1.c );
    BOOST_CHECK_EQUAL( 26, t1.access_side[0] );
    BOOST_CHECK_EQUAL( -1, t1.access_side[1] );
    BOOST_CHECK_EQUAL(  1, t1.access_side[2] );

    QGears::WalkmeshFile::Triangle &t2( triangles.back() );
    BOOST_CHECK_EQUAL( Ogre::Vector3( 3506, 29251, 432 ), t2.a );
    BOOST_CHECK_EQUAL( Ogre::Vector3( 3527, 29405, 432 ), t2.b );
    BOOST_CHECK_EQUAL( Ogre::Vector3( 3566, 29245, 400 ), t2.c );
    BOOST_CHECK_EQUAL( -1, t2.access_side[0] );
    BOOST_CHECK_EQUAL( 37, t2.access_side[1] );
    BOOST_CHECK_EQUAL( -1, t2.access_side[2] );

    BOOST_CHECK_EQUAL( 1174, stream->tell() );

    logMgr.destroyLog( "Default Log" );

    ifs->close();
}
