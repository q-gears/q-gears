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

#define BOOST_TEST_MODULE QGearsRingBuffer
#include <boost/test/unit_test.hpp>

#include "QGearsLZSDataStream.h"

BOOST_AUTO_TEST_CASE( overal )
{
    char data[] = { 0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8 };
    QGears::RingBuffer<4> buffer;
    BOOST_CHECK_EQUAL( 0, buffer.avail() );
    BOOST_CHECK_EQUAL( 0, buffer.get( 0 ) );
    BOOST_CHECK_EQUAL( 0, buffer.get( 1 ) );
    BOOST_CHECK_EQUAL( 0, buffer.get( 2 ) );
    BOOST_CHECK_EQUAL( 0, buffer.get( 3 ) );
    BOOST_CHECK_EQUAL( 0, buffer.get( 4 ) );
    buffer.write( data + 0 );
    buffer.write( data + 1 );
    buffer.write( data + 2 );
    buffer.write( data + 3 );
    BOOST_CHECK_EQUAL( data[0], buffer.get( 0 ) );
    BOOST_CHECK_EQUAL( data[1], buffer.get( 1 ) );
    BOOST_CHECK_EQUAL( data[2], buffer.get( 2 ) );
    BOOST_CHECK_EQUAL( data[3], buffer.get( 3 ) );
    BOOST_CHECK_EQUAL( data[0], buffer.get( 4 ) );
    BOOST_CHECK_EQUAL( 4, buffer.avail() );
    buffer.write( data + 4 );
    buffer.write( data + 5 );
    BOOST_CHECK_EQUAL( 4, buffer.avail() );
    BOOST_CHECK_EQUAL( data[4], buffer.get( 0 ) );
    BOOST_CHECK_EQUAL( data[5], buffer.get( 1 ) );
    BOOST_CHECK_EQUAL( data[2], buffer.get( 2 ) );
    BOOST_CHECK_EQUAL( data[3], buffer.get( 3 ) );
    BOOST_CHECK_EQUAL( data[4], buffer.get( 4 ) );
    BOOST_CHECK_EQUAL( data[5], buffer.get( 5 ) );
    BOOST_CHECK_EQUAL( data[2], buffer.get( 6 ) );

    memset( data, 0x77, sizeof( data ) );
    const char expected[] = { 0x3, 0x4, 0x5, 0x6, 0x77, 0x77, 0x77, 0x77 };
    BOOST_CHECK_EQUAL( sizeof( expected ), sizeof( data ) );

    BOOST_CHECK_EQUAL( 4, buffer.avail() );
    BOOST_CHECK_EQUAL( 4, buffer.read( data, sizeof( data ) ) );
    BOOST_CHECK_EQUAL( 0, buffer.avail() );
    BOOST_CHECK_EQUAL_COLLECTIONS( expected, expected + sizeof( expected ), data, data + sizeof( data ) );
}

BOOST_AUTO_TEST_CASE( read_single_bytes )
{
    QGears::RingBuffer<4> buffer;
    char data;
    data = 1; buffer.write( &data );
    data = 2; buffer.write( &data );
    data = 3; buffer.write( &data );
    data = 4; buffer.write( &data );
    BOOST_CHECK_EQUAL( 1, buffer.read( &data, sizeof( data ) ) ); BOOST_CHECK_EQUAL( 1, data );
    BOOST_CHECK_EQUAL( 1, buffer.read( &data, sizeof( data ) ) ); BOOST_CHECK_EQUAL( 2, data );
    BOOST_CHECK_EQUAL( 1, buffer.read( &data, sizeof( data ) ) ); BOOST_CHECK_EQUAL( 3, data );
    BOOST_CHECK_EQUAL( 1, buffer.read( &data, sizeof( data ) ) ); BOOST_CHECK_EQUAL( 4, data );
}
