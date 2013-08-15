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

#define BOOST_TEST_MODULE QGearsManualObject
#include <boost/test/unit_test.hpp>

#include <Ogre.h>
#include <OgreDefaultHardwareBufferManager.h>

#include "QGearsManualObject.h"

BOOST_AUTO_TEST_CASE( mesh_export )
{
	Ogre::LogManager  logMgr;
    // this log catches output from the parseArgs call and routes it to stdout only
    logMgr.createLog("Temporary log", false, true, true);
    logMgr.destroyLog("Temporary log");
    Ogre::ResourceGroupManager rgm;
    Ogre::Math mth;
    Ogre::LodStrategyManager lodMgr;
    Ogre::MeshManager meshMgr;
    Ogre::MaterialManager matMgr;
    matMgr.initialise();
    Ogre::SkeletonManager skelMgr;
    Ogre::DefaultHardwareBufferManager bufferManager; // needed because we don't have a rendersystem
    const char* name( "test" );
    const char* filename_mesh( "test.mesh" );
    const char* filename_skeleton( "test.skeleton" );

    Ogre::MeshPtr mesh( Ogre::MeshManager::getSingleton().create( name, "General" ) );
    mesh->setSkeletonName( filename_skeleton );

    QGears::ManualObject mo( mesh.getPointer() );
    mo.begin( "sub_name1", "material1", 3, 3 );
    mo.position( Ogre::Vector3( 0, 0, 0 ) );
    mo.normal( Ogre::Vector3( 0, 0, 1 ) );
    mo.colour( Ogre::ColourValue( 1, 0, 0 ) );
    mo.position( Ogre::Vector3( 1, 0, 0 ) );
    mo.normal( Ogre::Vector3( 0, 0, 1 ) );
    mo.colour( Ogre::ColourValue( 0, 1, 0 ) );
    mo.position( Ogre::Vector3( 0, 1, 0 ) );
    mo.normal( Ogre::Vector3( 0, 0, 1 ) );
    mo.colour( Ogre::ColourValue( 0, 0, 1 ) );
    mo.bone( 0, 1 );
    mo.index( 0 );
    mo.bone( 1, 2, 3 );
    mo.index( 1 );
    mo.bone( 2, 2, 2 );
    mo.index( 2 );
    mo.end();
    mo.begin( "sub_name2", "material2", 3, 3 );
    mo.position( Ogre::Vector3( 0, 0, 0 ) );
    mo.normal( Ogre::Vector3( 0, 0, 1 ) );
    mo.colour( Ogre::ColourValue( 1, 0, 0 ) );
    mo.position( Ogre::Vector3( 1, 0, 0 ) );
    mo.normal( Ogre::Vector3( 0, 0, 1 ) );
    mo.colour( Ogre::ColourValue( 0, 1, 0 ) );
    mo.position( Ogre::Vector3( 0, 1, 0 ) );
    mo.normal( Ogre::Vector3( 0, 0, 1 ) );
    mo.colour( Ogre::ColourValue( 0, 0, 1 ) );
    mo.bone( 0, 1 );
    mo.index( 0 );
    mo.bone( 1, 2, 3 );
    mo.index( 1 );
    mo.bone( 2, 2, 2 );
    mo.index( 2 );
    mo.end();
    Ogre::MeshSerializer m_ser;
    m_ser.exportMesh( mesh.getPointer(), filename_mesh );

    std::ifstream actual( filename_mesh );
    std::ifstream expected( "reference.mesh" );

    std::istream_iterator<char> it_actual  ( actual   ), end_actual;
    std::istream_iterator<char> it_expected( expected ), end_expected;

    BOOST_CHECK_EQUAL_COLLECTIONS(it_expected, end_actual, it_actual, end_expected);
}
