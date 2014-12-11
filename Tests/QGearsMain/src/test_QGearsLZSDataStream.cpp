/*
-----------------------------------------------------------------------------
The MIT License (MIT)

Copyright (c) 2013-08-18 Tobias Peters <tobias.peters@kreativeffekt.at>

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

#define BOOST_TEST_MODULE QGearsLZSDataStream
#include <boost/test/unit_test.hpp>

#include <Ogre.h>

#include "QGearsLZSDataStream.h"

const unsigned char hexData[] = {



    0x00, 0x00, 0x6C, 0x6F, 0x00, 0x00, 0x54, 0x9E,
    0x00, 0x00, 0x88, 0x9E, 0x00, 0x00, 0x70, 0xA1,
    0x00, 0x00, 0x44, 0x4B, 0x00, 0x00, 0x02, 0x05,
    0x0C, 0x0A, 0x90, 0x08, 0x02, 0x00, 0x00, 0x02,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6B, 0x69,
    0x74, 0x61, 0x00, 0x00, 0x00, 0x00, 0x6D, 0x64,
    0x31, 0x73, 0x74, 0x69, 0x6E, 0x00, 0x64, 0x69,
    0x72, 0x00, 0x00, 0x00, 0x00, 0x00, 0x63, 0x6C,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x62, 0x61,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x76, 0x69,
    0x65, 0x77, 0x00, 0x00, 0x00, 0x00, 0x68, 0x65,
    0x69, 0x30, 0x00, 0x00, 0x00, 0x00, 0x68, 0x65,
    0x69, 0x31, 0x00, 0x00, 0x00, 0x00, 0x61, 0x76,
    0x5F, 0x6D, 0x00, 0x00, 0x00, 0x00, 0x61, 0x76,
    0x5F, 0x6C, 0x00, 0x00, 0x00, 0x00, 0x61, 0x76,
    0x5F, 0x73, 0x00, 0x00, 0x00, 0x00, 0x67, 0x75,
    0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x67, 0x75,
    0x31, 0x00, 0x00, 0x00, 0x00, 0x00, 0x67, 0x75,
    0x61, 0x64, 0x64, 0x00, 0x00, 0x00, 0x90, 0x1C
};


BOOST_AUTO_TEST_CASE( read_file )
{
    const char* in_file_name( "reference_lzs.compressed" );
    const char* out_file_name( "test_lzs.decompressed" );
    std::ifstream *ifs(  OGRE_NEW_T( std::ifstream, Ogre::MEMCATEGORY_GENERAL )( in_file_name, std::ifstream::binary ) );
    std::ofstream ofs( out_file_name, std::ifstream::binary );
    BOOST_REQUIRE( ifs->is_open() );
    BOOST_REQUIRE( ofs.is_open() );
    Ogre::DataStreamPtr         file_stream( OGRE_NEW Ogre::FileStreamDataStream( ifs ) );
    QGears::LZSDataStreamPtr    lzs_stream( OGRE_NEW QGears::LZSDataStream( file_stream ) );
    BOOST_REQUIRE( file_stream->isReadable() );
    BOOST_REQUIRE( lzs_stream->isReadable() );

    BOOST_CHECK_EQUAL( 208640, lzs_stream->availableCompressed() );
    BOOST_CHECK_EQUAL(      0, lzs_stream->availableUncompressed() );
    size_t data_size( sizeof(hexData) );
    unsigned char data[sizeof(hexData)];
    memset( data, 0x77, data_size );

    BOOST_CHECK_EQUAL( 8, lzs_stream->read( data +  0, 8 ) );
    BOOST_CHECK_EQUAL( 208629, lzs_stream->availableCompressed() );
    BOOST_CHECK_EQUAL(      4, lzs_stream->availableUncompressed() );
    BOOST_CHECK( !lzs_stream->eof() );
    BOOST_CHECK_EQUAL( 1, lzs_stream->read( data +  8, 1 ) );
    BOOST_CHECK_EQUAL( 208629, lzs_stream->availableCompressed() );
    BOOST_CHECK_EQUAL(      3, lzs_stream->availableUncompressed() );
    BOOST_CHECK( !lzs_stream->eof() );
    BOOST_CHECK_EQUAL( 3, lzs_stream->read( data +  9, 3 ) );
    BOOST_CHECK_EQUAL( 208629, lzs_stream->availableCompressed() );
    BOOST_CHECK_EQUAL(      0, lzs_stream->availableUncompressed() );
    BOOST_CHECK( !lzs_stream->eof() );
    BOOST_CHECK_EQUAL( 4, lzs_stream->read( data + 12, 4 ) );
    BOOST_CHECK_EQUAL( 208619, lzs_stream->availableCompressed() );
    BOOST_CHECK_EQUAL(      6, lzs_stream->availableUncompressed() );
    BOOST_CHECK( !lzs_stream->eof() );
    BOOST_CHECK_EQUAL( 8, lzs_stream->read( data + 16, 8 ) );
    BOOST_CHECK_EQUAL( 208610, lzs_stream->availableCompressed() );
    BOOST_CHECK_EQUAL(      6, lzs_stream->availableUncompressed() );

    for( size_t i(0); i < 3*8; ++i )
    {
        ofs << data[i];
    }

    BOOST_REQUIRE_EQUAL( data_size, lzs_stream->read( data, data_size ) );
    for( size_t i(0); i < data_size; ++i )
    {
        ofs << data[i];
    }
    BOOST_CHECK_EQUAL_COLLECTIONS(hexData, hexData + data_size, data, data + data_size );

    for( size_t i(427020); i--; )
    {
        lzs_stream->read( data, 1 );
        ofs << data[0];
    }
    BOOST_CHECK_EQUAL( 427196, lzs_stream->tell() );
    BOOST_CHECK_EQUAL( 6, lzs_stream->availableCompressed() );
    BOOST_CHECK_EQUAL( 0, lzs_stream->availableUncompressed() );
    for( size_t i(4); i--; )
    {
        lzs_stream->read( data, 1 );
        ofs << data[0];
    }
    BOOST_CHECK_EQUAL( 427200, lzs_stream->tell() );
    BOOST_CHECK_EQUAL( 0, lzs_stream->availableCompressed() );
    BOOST_CHECK_EQUAL( 1, lzs_stream->availableUncompressed() );
    lzs_stream->read( data, 1 );
    ofs << data[0];

    BOOST_CHECK_EQUAL( 427201, lzs_stream->tell() );
    BOOST_CHECK_EQUAL( 0, lzs_stream->availableCompressed() );
    BOOST_CHECK_EQUAL( 0, lzs_stream->availableUncompressed() );
    BOOST_CHECK( lzs_stream->eof() );
    BOOST_CHECK_EQUAL( 0, lzs_stream->read( data, 1 ) );

    QGears::uint32 flip( 0x12345678 );
    lzs_stream->flipEndian( flip );
    BOOST_CHECK_EQUAL( 0x78563412, flip );

    lzs_stream.setNull();
    file_stream.setNull();
    ofs.close();

    std::ifstream actual( out_file_name );
    std::ifstream expected( "reference_lzs.decompressed" );

    std::istream_iterator<char> it_actual  ( actual   ), end_actual;
    std::istream_iterator<char> it_expected( expected ), end_expected;

    BOOST_REQUIRE_EQUAL_COLLECTIONS(it_expected, end_actual, it_actual, end_expected);
}
