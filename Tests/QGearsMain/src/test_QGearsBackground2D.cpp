/*
-----------------------------------------------------------------------------
The MIT License (MIT)

Copyright (c) 2013-08-28 Tobias Peters <tobias.peters@kreativeffekt.at>

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

#include "core/Background2D.h"
#include "map/QGearsBackground2DFileManager.h"

BOOST_AUTO_TEST_SUITE( QGearsBackground2D )

BOOST_AUTO_TEST_CASE( load )
{
    class TestFile : public Background2D
    {
    public:
        TestFile() : Background2D() {}
    };

	Ogre::LogManager    logMgr;
    logMgr.createLog( "Default Log", true, true, true );
    Ogre::Root          root;
    TestFile            file;
    QGears::Background2DFileManager b_mgr;
    QGears::Background2DFilePtr     b;


    logMgr.destroyLog( "Default Log" );
}
BOOST_AUTO_TEST_SUITE_END()
