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
    BOOST_CHECK_EQUAL( 0x34, sizeof( QGears::BackgroundFile::SpriteData ) );
    BOOST_CHECK_EQUAL( 0x03, sizeof( QGears::BackgroundFile::Color_BGR) );

    QGears::BackgroundFile::SpriteData* sd( NULL );
    BOOST_CHECK_EQUAL( sizeof( *sd ), sizeof( QGears::BackgroundFile::SpriteData ) );
}

BOOST_AUTO_TEST_CASE( sprite_data_offset )
{
    BOOST_CHECK_EQUAL( 0x00, offsetof( QGears::BackgroundFile::SpriteData, dst_x ) );
    BOOST_CHECK_EQUAL( 0x02, offsetof( QGears::BackgroundFile::SpriteData, dst_y ) );
    BOOST_CHECK_EQUAL( 0x08, offsetof( QGears::BackgroundFile::SpriteData, src_x ) );
    BOOST_CHECK_EQUAL( 0x0A, offsetof( QGears::BackgroundFile::SpriteData, src_y ) );
    BOOST_CHECK_EQUAL( 0x14, offsetof( QGears::BackgroundFile::SpriteData, palette_page ) );
    BOOST_CHECK_EQUAL( 0x1E, offsetof( QGears::BackgroundFile::SpriteData, data_page ) );
}

BOOST_AUTO_TEST_CASE( read_file )
{
    class TestFile : public QGears::BackgroundFile
    {
    public:
        TestFile() : QGears::BackgroundFile( NULL, "", 0, "" ) {}
        size_t getCalculatedSize() const { return calculateSize(); }
    };

	Ogre::LogManager                    logMgr;

    const char*                         file_name( "reference.background" );
    TestFile                            file;
    QGears::BackgroundFileSerializer    ser;
    std::ifstream *ifs(  OGRE_NEW_T( std::ifstream, Ogre::MEMCATEGORY_GENERAL )( file_name, std::ifstream::binary ) );
    BOOST_REQUIRE( ifs->is_open() );
    Ogre::DataStreamPtr stream( OGRE_NEW Ogre::FileStreamDataStream( ifs ) );
    BOOST_REQUIRE( stream->isReadable() );

    logMgr.createLog( "Default Log", true, true, true );

    ser.importBackgroundFile( stream, &file );

    logMgr.destroyLog( "Default Log" );

    BOOST_CHECK( file.getLayers()[0].enabled );

    QGears::uint8 palatte_expected[] = { 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00 };
    BOOST_CHECK_EQUAL( sizeof( palatte_expected ), QGears::BackgroundFile::PALETTE_ENTRY_COUNT );
    BOOST_CHECK_EQUAL_COLLECTIONS( palatte_expected        , palatte_expected + sizeof( palatte_expected )
                                  ,file.getPaletteIndices(), file.getPaletteIndices() + QGears::BackgroundFile::PALETTE_ENTRY_COUNT );

    ifs->close();
}
