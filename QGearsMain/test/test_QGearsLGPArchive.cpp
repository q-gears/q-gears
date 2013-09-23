/*
-----------------------------------------------------------------------------
The MIT License (MIT)

Copyright (c) 2013-09-22 Tobias Peters <tobias.peters@kreativeffekt.at>

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

#define BOOST_TEST_MODULE QGearsLGPArchive
#include <boost/test/unit_test.hpp>

#include <Ogre.h>

#include "data/QGearsLGPArchive.h"

BOOST_AUTO_TEST_CASE( load )
{
    QGears::LGPArchive archive( "reference.lgp", "LGP" );

    BOOST_CHECK_EQUAL(  true, archive.getFiles().empty() );
    BOOST_CHECK_EQUAL( false, archive.exists( "aaac.p" ) );
    BOOST_CHECK_EQUAL( false, archive.exists( "mmmm.p" ) );

	Ogre::LogManager        logMgr;
    logMgr.createLog( "Default Log", true, true, true );
    archive.load();
    logMgr.destroyLog( "Default Log" );

    BOOST_CHECK_EQUAL( 12649, archive.getFiles().size() );
    BOOST_CHECK_EQUAL(  true, archive.exists( "aaac.p" ) );
    BOOST_CHECK_EQUAL(  true, archive.exists( "mmmm.p" ) );

    QGears::LGPArchive::FileEntry& entry( archive.getFiles()[1] );
    BOOST_CHECK_EQUAL( "aaad.rsd", entry.file_name );
    BOOST_CHECK_EQUAL( 0x00054ACB, entry.file_offset );
    BOOST_CHECK_EQUAL( 0x0000003E, entry.data_size );
    BOOST_CHECK_EQUAL( 0x00054AE3, entry.data_offset );

    Ogre::DataStreamPtr stream( archive.open( "aaad.rsd" ) );
    BOOST_CHECK_EQUAL( false, stream.isNull() );
    BOOST_CHECK_EQUAL( 0x3E, stream->size() );
    BOOST_CHECK_EQUAL( "@RSD940102", stream->getLine() );
    BOOST_CHECK_EQUAL( "PLY=AAAE.PLY", stream->getLine() );
    BOOST_CHECK_EQUAL( "MAT=AAAE.MAT", stream->getLine() );
    BOOST_CHECK_EQUAL( "GRP=AAAE.GRP", stream->getLine() );
    BOOST_CHECK_EQUAL( "NTEX=0", stream->getLine() );
    BOOST_CHECK_EQUAL( true, stream->eof() );

    archive.unload();

    BOOST_CHECK_EQUAL( false, archive.exists( "aaac.p" ) );
    BOOST_CHECK_EQUAL( false, archive.exists( "mmmm.p" ) );
}
