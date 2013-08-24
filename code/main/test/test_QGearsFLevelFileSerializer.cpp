/*
-----------------------------------------------------------------------------
The MIT License (MIT)

Copyright (c) 2013-08-24 Tobias Peters <tobias.peters@kreativeffekt.at>

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
#define BOOST_TEST_MODULE QGearsFLevelFileSerializer
#include <boost/test/unit_test.hpp>

#include <Ogre.h>

#include "data/QGearsFLevelFileSerializer.h"

#include "data/QGearsBackgroundFileManager.h"
#include "data/QGearsPaletteFileManager.h"

BOOST_AUTO_TEST_CASE( read_file )
{
    class TestFile : public QGears::FLevelFile
    {
    public:
        TestFile() : QGears::FLevelFile( NULL, "reference.flevel", 0, "General" ) {}
    };

    class TestSerializer : public QGears::FLevelFileSerializer
    {
    public:
        QGears::String base      ( TestFile *file ) { return getBaseName      ( file ); }
        QGears::String palette   ( TestFile *file ) { return getPaletteName   ( file ); }
        QGears::String background( TestFile *file ) { return getBackgroundName( file ); }
    };

	Ogre::LogManager                    logMgr;
	Ogre::Root                          root("","");
	Ogre::ResourceGroupManager         &rgm( Ogre::ResourceGroupManager::getSingleton() );
	QGears::PaletteFileManager          pmgr;
	QGears::BackgroundFileManager       bmgr;
    logMgr.createLog( "Default Log", true, true, true );

    rgm.addResourceLocation( ".", "FileSystem" );
    rgm.initialiseAllResourceGroups();

    TestFile                file;
    Ogre::DataStreamPtr     stream( rgm.openResource( file.getName(), file.getGroup() ));
    BOOST_REQUIRE( stream->isReadable() );

    TestSerializer   ser;
    BOOST_CHECK_EQUAL( "reference"           , ser.base( &file ) );
    BOOST_CHECK_EQUAL( "reference.palette"   , ser.palette( &file ) );
    BOOST_CHECK_EQUAL( "reference.background", ser.background( &file ) );
    ser.importFLevelFile( stream, &file );
    BOOST_CHECK_EQUAL( 757890, stream->tell() );

    BOOST_CHECK( !file.getPalette().isNull() );
    BOOST_CHECK( !file.getBackground().isNull() );
    Ogre::Image *image( file.getBackground()->createImage( file.getPalette() ));
    image->save( file.getName() + ".png" );
    delete image;

    logMgr.destroyLog( "Default Log" );
    stream->close();
}
