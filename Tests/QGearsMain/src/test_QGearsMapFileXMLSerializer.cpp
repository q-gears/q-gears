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
    f.
    BOOST_FAIL( "not yet implemented" );

    logMgr.destroyLog( "Default Log" );

    ifs->close();
}
