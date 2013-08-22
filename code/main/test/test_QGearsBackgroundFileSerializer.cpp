/*
-----------------------------------------------------------------------------
The MIT License (MIT)

Copyright (c) 2013-07-31 Tobias Peters <tobias.peters@kreativeffekt.at>

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
#define BOOST_TEST_MODULE QGearsBackgroundFileSerializer
#include <boost/test/unit_test.hpp>

#include <Ogre.h>

#include "data/QGearsBackgroundFileSerializer.h"

BOOST_AUTO_TEST_CASE( header_size )
{
    BOOST_CHECK_EQUAL( 0x03, sizeof( QGears::BackgroundFile::Color_BGR) );
    BOOST_CHECK_EQUAL( 0x04, sizeof( QGears::BackgroundFile::Pixel) );
}

BOOST_AUTO_TEST_CASE( pixel_offset )
{
    BOOST_CHECK_EQUAL( 0x00, offsetof( QGears::BackgroundFile::Pixel, x ) );
    BOOST_CHECK_EQUAL( 0x02, offsetof( QGears::BackgroundFile::Pixel, y ) );
}

BOOST_AUTO_TEST_CASE( read_file )
{
    class TestFile : public QGears::BackgroundFile
    {
    public:
        TestFile() : QGears::BackgroundFile( NULL, "", 0, "" ) {}
        size_t getCalculatedSize() const { return calculateSize(); }

        virtual void unload( void ) {};
    };

	Ogre::LogManager                    logMgr;
    logMgr.createLog( "Default Log", true, true, true );

    const char*                         file_name( "reference.background" );
    TestFile                            file;
    QGears::BackgroundFileSerializer    ser;
    std::ifstream *ifs(  OGRE_NEW_T( std::ifstream, Ogre::MEMCATEGORY_GENERAL )( file_name, std::ifstream::binary ) );
    BOOST_REQUIRE( ifs->is_open() );

    Ogre::DataStreamPtr stream( OGRE_NEW Ogre::FileStreamDataStream( ifs ) );
    BOOST_REQUIRE( stream->isReadable() );

    ser.importBackgroundFile( stream, &file );
    BOOST_CHECK_EQUAL( 726491, stream->tell() );
    BOOST_CHECK_EQUAL( 721078, file.getCalculatedSize() );

    QGears::BackgroundFile::Layer *layer( file.getLayers() );
    BOOST_CHECK( layer[0].enabled );
    BOOST_CHECK_EQUAL( 400, layer[0].width );
    BOOST_CHECK_EQUAL( 736, layer[0].height );
    BOOST_CHECK_EQUAL(1019, layer[0].sprites.size() );
    BOOST_CHECK_EQUAL(-192, layer[0].sprites[0].dst.x );
    BOOST_CHECK_EQUAL(-168, layer[0].sprites[0].dst.y );
    BOOST_CHECK_EQUAL(   0, layer[0].sprites[0].src.x );
    BOOST_CHECK_EQUAL(   0, layer[0].sprites[0].src.y );

    BOOST_CHECK( layer[1].enabled );
    BOOST_CHECK_EQUAL( 640, layer[1].width );
    BOOST_CHECK_EQUAL( 480, layer[1].height );
    BOOST_CHECK_EQUAL(  64, layer[1].sprites.size() );
    BOOST_CHECK_EQUAL(  48, layer[1].sprites[0].dst.x );
    BOOST_CHECK_EQUAL(-312, layer[1].sprites[0].dst.y );
    BOOST_CHECK_EQUAL( 176, layer[1].sprites[0].src.x );
    BOOST_CHECK_EQUAL( 240, layer[1].sprites[0].src.y );

    BOOST_CHECK( layer[2].enabled );
    BOOST_CHECK_EQUAL( 640, layer[2].width );
    BOOST_CHECK_EQUAL( 480, layer[2].height );
    BOOST_CHECK_EQUAL(   0, layer[2].sprites.size() );

    BOOST_CHECK( layer[3].enabled );
    BOOST_CHECK_EQUAL( 640, layer[3].width );
    BOOST_CHECK_EQUAL( 480, layer[3].height );
    BOOST_CHECK_EQUAL( 280, layer[3].sprites.size() );
    BOOST_CHECK_EQUAL(-160, layer[3].sprites[0].dst.x );
    BOOST_CHECK_EQUAL(-120, layer[3].sprites[0].dst.y );
    BOOST_CHECK_EQUAL(   0, layer[3].sprites[0].src.x );
    BOOST_CHECK_EQUAL(   0, layer[3].sprites[0].src.y );

    QGears::uint8 palatte_expected[] = { 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00 };
    BOOST_CHECK_EQUAL( sizeof( palatte_expected ), QGears::BackgroundFile::PALETTE_ENTRY_COUNT );
    BOOST_CHECK_EQUAL_COLLECTIONS( palatte_expected , palatte_expected  + sizeof( palatte_expected )
                                  ,file.getPalette(), file.getPalette() + QGears::BackgroundFile::PALETTE_ENTRY_COUNT );

    QGears::BackgroundFile::Page *page( file.getPages() );
    bool enabled[] = { 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    BOOST_CHECK_EQUAL( sizeof(enabled), QGears::BackgroundFile::PAGE_COUNT );
    for( size_t i( QGears::BackgroundFile::PAGE_COUNT ); i--; )
    {
        BOOST_CHECK_EQUAL( enabled[i], page[i].enabled );
    }

    logMgr.stream()
        << "\n layer[0].unknown_06: " << layer[0].unknown_06

        << "\n layer[1].unknown_06: " << layer[1].unknown_06
        << "\n layer[1].unknown_08: " << layer[1].unknown_08[0]
        << "\n layer[1].unknown_08: " << layer[1].unknown_08[1]
        << "\n layer[1].unknown_08: " << layer[1].unknown_08[2]
        << "\n layer[1].unknown_0E: " << layer[1].unknown_0E[0]
        << "\n layer[1].unknown_0E: " << layer[1].unknown_0E[1]
        << "\n layer[1].unknown_0E: " << layer[1].unknown_0E[2]
        << "\n layer[1].unknown_0E: " << layer[1].unknown_0E[3]

        << "\n layer[2].unknown_06: " << layer[2].unknown_06
        << "\n layer[2].unknown_0E: " << layer[2].unknown_0E[0]
        << "\n layer[2].unknown_0E: " << layer[2].unknown_0E[1]
        << "\n layer[2].unknown_0E: " << layer[2].unknown_0E[2]
        << "\n layer[2].unknown_0E: " << layer[2].unknown_0E[3]

        << "\n layer[3].unknown_06: " << layer[3].unknown_06
        << "\n layer[3].unknown_0E: " << layer[3].unknown_0E[0]
        << "\n layer[3].unknown_0E: " << layer[3].unknown_0E[1]
        << "\n layer[3].unknown_0E: " << layer[3].unknown_0E[2]
        << "\n layer[3].unknown_0E: " << layer[3].unknown_0E[3]
        << "\n";


    logMgr.destroyLog( "Default Log" );
    ifs->close();
}
