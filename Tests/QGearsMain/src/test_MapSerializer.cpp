#include <fstream>

#include <boost/test/unit_test.hpp>
#include <Ogre.h>

#include "common/TypeDefine.h"
#include "data/worldmap/MapFileSerializer.h"
#include "data/worldmap/MapFile.h"

#include <functional>

static void createReferenceFileInstance(std::function<void(Ogre::DataStreamPtr& stream, QGears::WorldMapFile& file)> callBack)
{
    class TestFile : public QGears::WorldMapFile
    {
    public:
        TestFile() : QGears::WorldMapFile( NULL, "", 0, "" ) {}
    };

    const char* file_name = "misc/reference.map";
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

BOOST_AUTO_TEST_CASE( file_size_is_multiple_of_block_size )
{
    createReferenceFileInstance([&](Ogre::DataStreamPtr& stream, QGears::WorldMapFile& file)
    {
        QGears::MapFileSerializer s;
        s.importMapFile( stream, file );
    });
}

// compare meshes to hand picked data that we know should be in the block
BOOST_AUTO_TEST_CASE( parse_16_meshes_in_one_block )
{

}


BOOST_AUTO_TEST_CASE( parsing_whole_map )
{

}

BOOST_AUTO_TEST_CASE( replace_story_meshes )
{

}
