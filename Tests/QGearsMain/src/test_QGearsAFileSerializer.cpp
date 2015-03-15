/*
-----------------------------------------------------------------------------
The MIT License (MIT)

Copyright (c) 2013-08-12 Tobias Peters <tobias.peters@kreativeffekt.at>

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

#include <boost/test/unit_test.hpp>
#include <Ogre.h>

#include "data/QGearsAFileSerializer.h"

BOOST_AUTO_TEST_CASE( header_size )
{
    BOOST_CHECK_EQUAL( 0x24, sizeof( QGears::AFileSerializer::Header ) );
}

BOOST_AUTO_TEST_CASE( header_offset )
{
    BOOST_CHECK_EQUAL( 0x00, offsetof( QGears::AFileSerializer::Header, version ) );
    BOOST_CHECK_EQUAL( 0x04, offsetof( QGears::AFileSerializer::Header, frame_count ) );
    BOOST_CHECK_EQUAL( 0x08, offsetof( QGears::AFileSerializer::Header, bone_count ) );
    BOOST_CHECK_EQUAL( 0x0C, offsetof( QGears::AFileSerializer::Header, rotation_order ) );
}

BOOST_AUTO_TEST_CASE( read_file )
{
    class TestFile : public QGears::AFile
    {
    public:
        TestFile() : QGears::AFile( NULL, "", 0, "" ) {}
    };
    const char* file_name( "misc/reference.a" );
    std::ifstream *ifs(  OGRE_NEW_T( std::ifstream, Ogre::MEMCATEGORY_GENERAL )( file_name, std::ifstream::binary ) );
    BOOST_REQUIRE( ifs->is_open() );
    Ogre::DataStreamPtr stream( OGRE_NEW Ogre::FileStreamDataStream( ifs ) );
    BOOST_REQUIRE( stream->isReadable() );

    Ogre::LogManager            logMgr;
    QGears::AFileSerializer     ser;
    TestFile                    f;

    logMgr.createLog( "Default Log", true, true, true );

    ser.importAFile( stream, &f );

    QGears::AFile::FrameList &frames( f.getFrames() );
    BOOST_CHECK_EQUAL( 80, frames.size() );
    BOOST_CHECK( Ogre::Vector3( -63.86031f, 71.90821f, -10.97811f    ).positionEquals( frames.front().root_translation ) );
    BOOST_CHECK( Ogre::Vector3(   0.0f      , 13.53528f,   0.07706928f ).positionEquals( frames.back ().root_translation ) );

    logMgr.destroyLog( "Default Log" );

    ifs->close();
}

