/*
-----------------------------------------------------------------------------
Copyright (c) 27.10.2013 Tobias Peters <tobias.peters@kreativeffekt.at>

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

#include "map/QGearsMapFileXMLSerializer.h"

BOOST_AUTO_TEST_CASE( read_file )
{
    class TestFile : public QGears::MapFile
    {
    public:
        TestFile() : QGears::MapFile( NULL, "", 0, "" ) {}
        size_t getCalculatedSize() const { return calculateSize(); }

        virtual void unload( void ) {}
    };
    const char* file_name( "misc/map.xml" );
    std::ifstream *ifs(  OGRE_NEW_T( std::ifstream, Ogre::MEMCATEGORY_GENERAL )( file_name, std::ifstream::binary ) );
    BOOST_REQUIRE( ifs->is_open() );
    Ogre::DataStreamPtr stream( OGRE_NEW Ogre::FileStreamDataStream( ifs ) );
    BOOST_REQUIRE( stream->isReadable() );

    Ogre::LogManager                logMgr;
    QGears::MapFileXMLSerializer    ser;
    TestFile                        f;

    logMgr.createLog( "Default Log", true, true, true );
    ser.importMapFile( stream, &f );

    BOOST_CHECK_EQUAL( "path/to/script.lua"         , f.getScriptName() );
    BOOST_CHECK_EQUAL( "background_2d_resource_name", f.getBackground2dName() );
    BOOST_CHECK_EQUAL( "walkmesh_resource_name"     , f.getWalkmeshName() );
    BOOST_CHECK_CLOSE( -5.625, f.getForwardDirection(), 0.001 );

    QGears::MapFile::PointList     &points( f.getPoints() );
    BOOST_REQUIRE_EQUAL( 1, points.size() );
    QGears::MapFile::PointList::value_type    &point( points.at(0) );
    BOOST_CHECK_EQUAL( "Spawn_md1_1", point.GetName() );
    BOOST_CHECK( Ogre::Vector3( 29.0547f, 229.234f, 2.56082f ).positionEquals( point.GetPosition() ) );
    BOOST_CHECK_CLOSE( 67.7647, point.GetRotation(), 0.001 );

    QGears::MapFile::TriggerList   &triggers( f.getTriggers() );
    BOOST_REQUIRE_EQUAL( 1, triggers.size() );
    QGears::MapFile::TriggerList::value_type    &trigger( triggers.at(0) );
    BOOST_CHECK_EQUAL( "Gateway0", trigger.GetName() );
    BOOST_CHECK( Ogre::Vector3( 28.6016f, 228.562f, 2.75781f ).positionEquals( trigger.GetPoint1() ) );
    BOOST_CHECK( Ogre::Vector3( 28.6641f, 229.438f, 2.75781f ).positionEquals( trigger.GetPoint2() ) );
    BOOST_CHECK_EQUAL( true, trigger.IsEnabled() );

    logMgr.destroyLog( "Default Log" );
    ifs->close();
}
