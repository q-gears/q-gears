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

#include <boost/test/unit_test.hpp>

#include <Ogre.h>

#include "data/QGearsLGPArchiveFactory.h"

BOOST_AUTO_TEST_CASE( load )
{
    Ogre::LogManager        logMgr;
    logMgr.createLog( "Default Log", true, true, true );
    const char* filename_1( "Filename 1" );
    const char* filename_2( "max length filename!" );

    class TestLGPArchive : public QGears::LGPArchive
    {
        public:

            TestLGPArchive() :
                QGears::LGPArchive( "misc/reference.lgp", "LGP" )
              , test_stream( NULL )
            {}

            void load()
            {
                QGears::LGPArchive::load( test_stream );
            }

        Ogre::DataStream* test_stream;
    };

    TestLGPArchive lgp;
    // TODO: use Ogre::MemoryDataStream and include data via byte array
    std::ifstream *ifs( OGRE_NEW_T( std::ifstream, Ogre::MEMCATEGORY_GENERAL )( lgp.getName().c_str(), std::ifstream::binary ) );
    lgp.test_stream = OGRE_NEW Ogre::FileStreamDataStream( ifs );

    BOOST_CHECK_EQUAL(  true, lgp.getFiles().empty() );
    BOOST_CHECK_EQUAL( false, lgp.exists( filename_1 ) );
    BOOST_CHECK_EQUAL( false, lgp.exists( filename_2 ) );

    lgp.load();

    BOOST_CHECK_EQUAL( 2, lgp.getFiles().size() );
    BOOST_CHECK_EQUAL(  true, lgp.exists( filename_1 ) );
    BOOST_CHECK_EQUAL(  true, lgp.exists( filename_2 ) );
    BOOST_CHECK_EQUAL( lgp.getFiles().size(), lgp.list()->size() );
    BOOST_CHECK_EQUAL( lgp.getFiles().size(), lgp.listFileInfo()->size() );

    QGears::LGPArchive::FileEntry& entry( lgp.getFiles()[0] );
    BOOST_CHECK_EQUAL( filename_1, entry.file_name );
    BOOST_CHECK_EQUAL( entry.file_name, lgp.list()->at( 0 ) );
    BOOST_CHECK_EQUAL( 0x00000050, entry.file_offset );
    BOOST_CHECK_EQUAL( "FILENAME 1", entry.data_file_name );
    BOOST_CHECK_EQUAL( 0x00000018, entry.data_size );
    BOOST_CHECK_EQUAL( 0x00000068, entry.data_offset );

    Ogre::FileInfoListPtr file_infos( lgp.listFileInfo() );
    Ogre::FileInfo& file_info( file_infos->at( 0 ) );
    BOOST_CHECK_EQUAL( &lgp, file_info.archive );
    BOOST_CHECK_EQUAL( entry.file_name, file_info.filename );
    BOOST_CHECK_EQUAL( entry.file_name, file_info.basename );
    BOOST_CHECK_EQUAL( "", file_info.path );
    BOOST_CHECK_EQUAL( entry.data_size, file_info.uncompressedSize );
    BOOST_CHECK_EQUAL( file_info.uncompressedSize, file_info.compressedSize );

    BOOST_CHECK_EQUAL( 1, lgp.find( "Filename*" )->size() );
    BOOST_CHECK_EQUAL( 1, lgp.find( "*!" )->size() );
    BOOST_CHECK_EQUAL( 2, lgp.find( "*name*" )->size() );

    Ogre::StringVectorPtr found( lgp.find( "*name*" ) );
    BOOST_CHECK_EQUAL( 2, found->size() );
    BOOST_CHECK_EQUAL( filename_1, found->at( 0 ) );
    BOOST_CHECK_EQUAL( filename_2, found->at( 1 ) );

    Ogre::DataStreamPtr stream( lgp.open( filename_1 ) );
    BOOST_CHECK_EQUAL( false, stream.isNull() );
    BOOST_CHECK_EQUAL( entry.data_size, stream->size() );
    BOOST_CHECK_EQUAL( "data of file 1 for test!", stream->getLine() );
    BOOST_CHECK_EQUAL( true, stream->eof() );

    lgp.unload();

    BOOST_CHECK_EQUAL( false, lgp.exists( filename_1 ) );
    BOOST_CHECK_EQUAL( false, lgp.exists( filename_2 ) );
    logMgr.destroyLog( "Default Log" );
}
