/*
-----------------------------------------------------------------------------
The MIT License (MIT)

Copyright (c) 2013-08-26 Tobias Peters <tobias.peters@kreativeffekt.at>

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
#include <boost/test/unit_test.hpp>

#include <Ogre.h>

#include "map/QGearsBackground2DFileXMLSerializer.h"

BOOST_AUTO_TEST_SUITE( QGearsBackground2DFileSerializer )

BOOST_AUTO_TEST_CASE( read_file )
{
    class TestFile : public QGears::Background2DFile
    {
    public:
        TestFile() : QGears::Background2DFile( NULL, "", 0, "" ) {}
        size_t getCalculatedSize() const { return calculateSize(); }

        virtual void unload( void ) {};
    };

	Ogre::LogManager                    logMgr;
    logMgr.createLog( "Default Log", true, true, true );

    const char*                             file_name( "reference.background2d.xml" );
    TestFile                                file;
    QGears::Background2DFileXMLSerializer   ser;
    std::ifstream *ifs(  OGRE_NEW_T( std::ifstream, Ogre::MEMCATEGORY_GENERAL )( file_name, std::ifstream::binary ) );
    BOOST_REQUIRE( ifs->is_open() );

    Ogre::DataStreamPtr stream( OGRE_NEW Ogre::FileStreamDataStream( ifs ) );
    BOOST_REQUIRE( stream->isReadable() );

    ser.importBackground2DFile( stream, &file );
    BOOST_CHECK_EQUAL( 1383, stream->tell() );
    BOOST_CHECK_EQUAL( "maps/ffvii/field/md1stin.png", file.getTextureName() );
    BOOST_CHECK_EQUAL( Ogre::Quaternion( -768, -768, 768, 768 ), file.getRange() );
    BOOST_CHECK_EQUAL( Ogre::Vector3( 28.4846, 210.83, 3.10751 ), file.getPosition() );
    BOOST_CHECK_EQUAL( Ogre::Quaternion( 0.742188, 0.667516, -0.0403783, -0.0450658 ), file.getOrientation() );
    BOOST_CHECK_EQUAL( Ogre::Radian( Ogre::Degree( 34.5389 ) ), file.getFov() );
    BOOST_CHECK_EQUAL( 6, file.getTiles().size() );
    BOOST_CHECK_EQUAL( Background2D::ALPHA, file.getTiles()[0].blending );
    BOOST_CHECK_EQUAL( 123, file.getTiles()[0].depth );

    BOOST_CHECK_EQUAL( Background2D::ADD  , file.getTiles()[1].blending );
    BOOST_CHECK_EQUAL( 100, file.getTiles()[1].depth );

    BOOST_CHECK_EQUAL( 48, file.getTiles()[2].width  );
    BOOST_CHECK_EQUAL( 48, file.getTiles()[2].height );
    BOOST_CHECK_EQUAL( 200, file.getTiles()[2].depth );

    BOOST_CHECK_EQUAL( Ogre::Vector4( 0.015625, 0.03125, 0.03125, 0.0625 ), file.getTiles()[3].uv );
    BOOST_CHECK_EQUAL( 300, file.getTiles()[3].depth );

    BOOST_CHECK_CLOSE( 0.002, file.getTiles()[4].depth, 0.0001 );
    BOOST_CHECK_CLOSE( 0.002, file.getTiles()[5].depth, 0.0001 );

    logMgr.destroyLog( "Default Log" );
    ifs->close();
}
BOOST_AUTO_TEST_SUITE_END()
