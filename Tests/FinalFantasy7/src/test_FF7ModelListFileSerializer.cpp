/*
-----------------------------------------------------------------------------
Copyright (c) 07.10.2013 Tobias Peters <tobias.peters@kreativeffekt.at>

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

#include "data/FF7ModelListFileSerializer.h"

BOOST_AUTO_TEST_CASE( read_file )
{
    class TestFile : public QGears::FF7::ModelListFile
    {
    public:
        TestFile() : QGears::FF7::ModelListFile( NULL, "", 0, "" ) {}
        size_t getCalculatedSize() const { return calculateSize(); }

        virtual void unload( void ) {}
    };
    const char* file_name( "misc/reference.model_list" );
    std::ifstream *ifs(  OGRE_NEW_T( std::ifstream, Ogre::MEMCATEGORY_GENERAL )( file_name, std::ifstream::binary ) );
    BOOST_REQUIRE( ifs->is_open() );
    Ogre::DataStreamPtr stream( OGRE_NEW Ogre::FileStreamDataStream( ifs ) );
    BOOST_REQUIRE( stream->isReadable() );

    Ogre::LogManager                        logMgr;
    QGears::FF7::ModelListFileSerializer    ser;
    TestFile                                f;

    logMgr.createLog( "Default Log", true, true, true );

    ser.importModelListFile( stream, &f );
    BOOST_CHECK_EQUAL( 1314, stream->tell() );

    BOOST_CHECK_EQUAL( 512, f.getScale() );

    QGears::FF7::ModelListFile::ModelList &models( f.getModels() );
    BOOST_CHECK_EQUAL( 10, models.size() );

    QGears::FF7::ModelListFile::ModelDescription &m1( models.front() );
    BOOST_CHECK_EQUAL( "md1stinmain_n_cloud.char", m1.name );
    BOOST_CHECK_EQUAL( "AAAA.HRC", m1.hrc_name );
    BOOST_CHECK_EQUAL( "512", m1.scale );
    QGears::FF7::ModelListFile::AnimationList &animations1( m1.animations );
    BOOST_CHECK_EQUAL( 4, animations1.size() );
    QGears::FF7::ModelListFile::AnimationDescription &a1_1( animations1.front() );
    BOOST_CHECK_EQUAL( "ACFE.aki", a1_1.name );
    BOOST_CHECK_EQUAL( 1, a1_1.unknown );
    QGears::FF7::ModelListFile::AnimationDescription &a1_2( animations1.back() );
    BOOST_CHECK_EQUAL( "BVJF.yos", a1_2.name );
    BOOST_CHECK_EQUAL( 1, a1_2.unknown );

    QGears::FF7::ModelListFile::ModelDescription &m2( models.back() );
    BOOST_CHECK_EQUAL( "md1stinshinra_guard.char", m2.name );
    BOOST_CHECK_EQUAL( "AZHE.HRC", m2.hrc_name );
    BOOST_CHECK_EQUAL( "512", m2.scale );
    QGears::FF7::ModelListFile::AnimationList &animations2( m2.animations );
    BOOST_CHECK_EQUAL( 8, animations2.size() );
    QGears::FF7::ModelListFile::AnimationDescription &a2_1( animations2.front() );
    BOOST_CHECK_EQUAL( "AAFE.aki", a2_1.name );
    BOOST_CHECK_EQUAL( 1, a2_1.unknown );
    QGears::FF7::ModelListFile::AnimationDescription &a2_2( animations2.back() );
    BOOST_CHECK_EQUAL( "BXIA.yos", a2_2.name );
    BOOST_CHECK_EQUAL( 1, a2_2.unknown );

    logMgr.destroyLog( "Default Log" );

    ifs->close();
}
