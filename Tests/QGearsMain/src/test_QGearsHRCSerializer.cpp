/*
-----------------------------------------------------------------------------
The MIT License (MIT)

Copyright (c) 2013-08-10 Tobias Peters <tobias.peters@kreativeffekt.at>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
-----------------------------------------------------------------------------
*/
#include <fstream>

//#define BOOST_TEST_MODULE QGearsHRCFileSerializer
#include <boost/test/unit_test.hpp>

#include <Ogre.h>

#include "data/QGearsHRCFileSerializer.h"

const char* LOG_NAME( "Default Log" );

BOOST_AUTO_TEST_CASE( simple_hrc )
{
    class TestFile : public QGears::HRCFile
    {
    public:
        TestFile() : QGears::HRCFile( NULL, "", 0, "" ) {}
    };
    Ogre::LogManager            logMgr;
    logMgr.createLog( LOG_NAME, true, true, true );

    const char* file_name( "misc/test_hrc_simple.hrc" );
    std::ifstream *ifs(  OGRE_NEW_T( std::ifstream, Ogre::MEMCATEGORY_GENERAL )( file_name, std::ifstream::binary ) );
    BOOST_REQUIRE( ifs->is_open() );
    Ogre::DataStreamPtr stream( OGRE_NEW Ogre::FileStreamDataStream( ifs ) );
    BOOST_REQUIRE( stream->isReadable() );

    TestFile                    file;
    QGears::HRCFileSerializer   ser;
    ser.importHRCFile( stream, &file );

    BOOST_CHECK_EQUAL( "test_skeleton", file.getSkeletonName() );

    const QGears::HRCFile::BoneList& bones( file.getBones() );
    BOOST_CHECK_EQUAL( 3, bones.size() );
    BOOST_CHECK_EQUAL( "bone.1", bones.at(0).name );
    BOOST_CHECK_EQUAL( "root", bones.at(0).parent );
    BOOST_CHECK_CLOSE( 1.5f, bones.at(0).length, 0.0001f );
    BOOST_CHECK_EQUAL( 1, bones.at(0).rsd_names.size() );
    BOOST_CHECK_EQUAL( "model.1", bones.at(0).rsd_names.at(0) );

    BOOST_CHECK_EQUAL( "bone.1.1", bones.at(1).name );
    BOOST_CHECK_EQUAL( bones.at(0).name, bones.at(1).parent );
    BOOST_CHECK_CLOSE( 2.0f, bones.at(1).length, 0.0001f );
    BOOST_CHECK_EQUAL( 1, bones.at(1).rsd_names.size() );
    BOOST_CHECK_EQUAL( "model.1.1", bones.at(1).rsd_names.at(0) );

    BOOST_CHECK_EQUAL( "bone.2", bones.at(2).name );
    BOOST_CHECK_EQUAL( bones.at(0).parent, bones.at(2).parent );
    BOOST_CHECK_CLOSE( 3.125f, bones.at(2).length, 0.0001f );
    BOOST_CHECK_EQUAL( 3, bones.at(2).rsd_names.size() );
    BOOST_CHECK_EQUAL( "model.2-1", bones.at(2).rsd_names.at(0) );
    BOOST_CHECK_EQUAL( "model.2-2", bones.at(2).rsd_names.at(1) );
    BOOST_CHECK_EQUAL( "model.2-3", bones.at(2).rsd_names.at(2) );

    ifs->close();
}

BOOST_AUTO_TEST_CASE( empty_hrc )
{
    class TestFile : public QGears::HRCFile
    {
    public:
        TestFile() : QGears::HRCFile( NULL, "", 0, "" ) {}
    };
    Ogre::LogManager            logMgr;
    logMgr.createLog( LOG_NAME, true, true, true );

    const char* file_name( "misc/test_hrc_empty.hrc" );
    std::ifstream *ifs(  OGRE_NEW_T( std::ifstream, Ogre::MEMCATEGORY_GENERAL )( file_name, std::ifstream::binary ) );
    BOOST_REQUIRE( ifs->is_open() );
    Ogre::DataStreamPtr stream( OGRE_NEW Ogre::FileStreamDataStream( ifs ) );
    BOOST_REQUIRE( stream->isReadable() );

    TestFile                    file;
    QGears::HRCFileSerializer   ser;
    ser.importHRCFile( stream, &file );

    BOOST_CHECK_EQUAL( "test_empty_skeleton", file.getSkeletonName() );

    const QGears::HRCFile::BoneList& bones( file.getBones() );
    BOOST_CHECK_EQUAL( 1, bones.size() );
    BOOST_CHECK_EQUAL( "null", bones.at(0).name );
    BOOST_CHECK_EQUAL( "root", bones.at(0).parent );
    BOOST_CHECK_CLOSE( 1.5f, bones.at(0).length, 0.0001f );
    BOOST_CHECK_EQUAL( 1, bones.at(0).rsd_names.size() );
    BOOST_CHECK_EQUAL( "model.1", bones.at(0).rsd_names.at(0) );

    ifs->close();
}
