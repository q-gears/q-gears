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

#define BOOST_TEST_MODULE QGearsASerializer
#include <boost/test/unit_test.hpp>
#include <OgreRoot.h>

#include "QGearsAFileSerializer.h"

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
    const char* file_name( "../../../../output/data_orig/field/char/acfe.a" );
    std::ifstream *ifs(  OGRE_NEW_T( std::ifstream, Ogre::MEMCATEGORY_GENERAL )( file_name, std::ifstream::binary ) );
    BOOST_REQUIRE( ifs->is_open() );
    Ogre::DataStreamPtr stream( OGRE_NEW Ogre::FileStreamDataStream( ifs ) );
    BOOST_REQUIRE( stream->isReadable() );

    Ogre::Root root("","");

    QGears::AFileSerializer   ser;
    QGears::AFile             f;
    ser.importAFile( stream, &f );

    ifs->close();
}
