/*
-----------------------------------------------------------------------------
The MIT License (MIT)

Copyright (c) 2013-08-22 Tobias Peters <tobias.peters@kreativeffekt.at>

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
#define BOOST_TEST_MODULE QGearsPaletteFileSerializer
#include <boost/test/unit_test.hpp>

#include <Ogre.h>

#include "data/QGearsPaletteFileSerializer.h"

BOOST_AUTO_TEST_CASE( read_file )
{
    class TestFile : public QGears::PaletteFile
    {
    public:
        TestFile() : QGears::PaletteFile( NULL, "", 0, "" ) {}
        size_t getCalculatedSize() const { return calculateSize(); }

        virtual void unload( void ) {};
    };

	Ogre::LogManager                    logMgr;
    logMgr.createLog( "Default Log", true, true, true );

    const char*                     file_name( "reference.palette" );
    TestFile                        file;
    QGears::PaletteFileSerializer   ser;
    std::ifstream *ifs(  OGRE_NEW_T( std::ifstream, Ogre::MEMCATEGORY_GENERAL )( file_name, std::ifstream::binary ) );
    BOOST_REQUIRE( ifs->is_open() );

    Ogre::DataStreamPtr stream( OGRE_NEW Ogre::FileStreamDataStream( ifs ) );
    BOOST_REQUIRE( stream->isReadable() );

    ser.importPaletteFile( stream, &file );
    BOOST_CHECK_EQUAL( 7180, stream->tell() );
    BOOST_REQUIRE_EQUAL(   14, file.getPages().size() );
    BOOST_CHECK_EQUAL(  256, file.getPages()[ 0].size() );
    BOOST_CHECK_EQUAL(  256, file.getPages()[ 1].size() );
    BOOST_CHECK_EQUAL(  256, file.getPages()[ 2].size() );
    BOOST_CHECK_EQUAL(  256, file.getPages()[ 3].size() );
    BOOST_CHECK_EQUAL(  256, file.getPages()[ 4].size() );
    BOOST_CHECK_EQUAL(  256, file.getPages()[ 5].size() );
    BOOST_CHECK_EQUAL(  256, file.getPages()[ 6].size() );
    BOOST_CHECK_EQUAL(  256, file.getPages()[ 7].size() );
    BOOST_CHECK_EQUAL(  256, file.getPages()[ 8].size() );
    BOOST_CHECK_EQUAL(  256, file.getPages()[ 9].size() );
    BOOST_CHECK_EQUAL(  256, file.getPages()[10].size() );
    BOOST_CHECK_EQUAL(  256, file.getPages()[11].size() );
    BOOST_CHECK_EQUAL(  256, file.getPages()[12].size() );
    BOOST_CHECK_EQUAL(  256, file.getPages()[13].size() );
    BOOST_CHECK_EQUAL( 3584 * sizeof( QGears::PaletteFile::Color ), file.getCalculatedSize() );

    BOOST_CHECK_EQUAL( 0x2A12, file.getPages()[0][0] );


    logMgr.destroyLog( "Default Log" );
    ifs->close();
}
