#include <fstream>

#include <boost/test/unit_test.hpp>
#include <Ogre.h>

#include "common/TypeDefine.h"
#include "data/worldmap/TxzFileSerializer.h"
#include "data/worldmap/TxzFile.h"

#include <functional>

using namespace Ogre;


static void createReferenceFileInstance(std::string filename, std::function<void(Ogre::DataStreamPtr& stream, QGears::TxzFile& file)> callBack)
{
    class TestFile : public QGears::TxzFile
    {
    public:
        TestFile() : QGears::TxzFile( NULL, "", 0, "" ) {}
    };

    const char* file_name = filename.c_str();
    std::ifstream ifs( file_name, std::ifstream::binary );
    {
        BOOST_REQUIRE( ifs.is_open() );
        Ogre::DataStreamPtr stream( OGRE_NEW Ogre::FileStreamDataStream( &ifs, false ) );
        BOOST_REQUIRE( stream->isReadable() );

        Ogre::LogManager log;
        TestFile f;

        log.createLog( "Default Log", true, true, true );

        callBack(stream, f);

        log.destroyLog( "Default Log" );
    }
}


BOOST_AUTO_TEST_CASE( read_blocks )
{
    createReferenceFileInstance( "/home/paul/qgears/data/cd1/world/wm0.txz", [&](Ogre::DataStreamPtr& stream, QGears::TxzFile& file)
    {
        QGears::TxzFileSerializer s;
        s.import( stream, file );
    });
}

