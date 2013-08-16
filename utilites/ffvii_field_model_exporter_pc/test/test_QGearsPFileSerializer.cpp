/*
-----------------------------------------------------------------------------
The MIT License (MIT)

Copyright (c) 2013-08-10 Tobias Peters <tobias.peters@kreativeffekt.at>

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

#define BOOST_TEST_MODULE QGearsPFileSerializer
#include <boost/test/unit_test.hpp>
#include <OgreRoot.h>

#include "QGearsPFileSerializer.h"

BOOST_AUTO_TEST_CASE( read_hrc_file )
{
	Ogre::LogManager                    logMgr;
    Ogre::ResourceGroupManager          rgm;
    Ogre::Math                          mth;
    Ogre::LodStrategyManager            lodMgr;
    Ogre::MeshManager                   meshMgr;
    Ogre::MaterialManager               matMgr;
    Ogre::SkeletonManager               skelMgr;
    logMgr.createLog( "Default Log", true, true, true );
    matMgr.initialise();

    const char* file_name( "reference.p" );
    std::ifstream *ifs(  OGRE_NEW_T( std::ifstream, Ogre::MEMCATEGORY_GENERAL )( file_name, std::ifstream::binary ) );
    BOOST_REQUIRE( ifs->is_open() );
    Ogre::DataStreamPtr stream( OGRE_NEW Ogre::FileStreamDataStream( ifs ) );
    BOOST_REQUIRE( stream->isReadable() );

    QGears::PFileSerializer   ser;
    QGears::PFile             file;
    ser.importPFile( stream, &file );

    ifs->close();
}
