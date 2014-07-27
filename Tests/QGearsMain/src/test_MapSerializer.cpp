#include <fstream>

//#include <boost/test/unit_test.hpp>
#include <Ogre.h>

#include "common/TypeDefine.h"
#include "data/worldmap/MapFileSerializer.h"
#include "data/worldmap/MapFile.h"

#include <functional>

using namespace Ogre;


static void createReferenceFileInstance(std::function<void(Ogre::DataStreamPtr& stream, QGears::WorldMapFile& file)> callBack)
{
    class TestFile : public QGears::WorldMapFile
    {
    public:
        TestFile() : QGears::WorldMapFile( NULL, "", 0, "" ) {}
    };

    const char* file_name = "/home/paul/qgears/q-gears/Tests/FinalFantasy7/misc/reference.map";
    std::ifstream ifs( file_name, std::ifstream::binary );
    {
//        BOOST_REQUIRE( ifs.is_open() );
        Ogre::DataStreamPtr stream( OGRE_NEW Ogre::FileStreamDataStream( &ifs, false ) );
//        BOOST_REQUIRE( stream->isReadable() );

        //Ogre::LogManager log;
        TestFile f;

       // log.createLog( "Default Log", true, true, true );

        callBack(stream, f);

       // log.destroyLog( "Default Log" );
    }
}

/*
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
*/

class GameFrameListener : public Ogre::FrameListener
{
public:
    using Ogre::FrameListener::FrameListener;

    bool frameStarted( const Ogre::FrameEvent& evt )
    {
        return true;
    }
};

static float Convert(QGears::sint16 coord)
{
    return (float(coord) / 4096.0f) * 100.0f;

   // return float(coord);
}

void createColourCube(SceneManager* mSceneMgr)
{ 
    std::vector<QGears::MapFileSerializer::SBlock> blocks;
    createReferenceFileInstance([&](Ogre::DataStreamPtr& stream, QGears::WorldMapFile& file)
    {
        QGears::MapFileSerializer s;
        s.importMapFile( stream, file );
        blocks = s.mBlocks;
    });

    int c = 0;
    for ( int k=0; k<blocks.size(); k++ )
    {
        QGears::MapFileSerializer::SBlock& block = blocks[k];

        for ( size_t i=0; i<block.mParts.size(); i++ )
        {
            QGears::MapFileSerializer::SBlockPart& part = block.mParts[i];
            for ( size_t j=0; j<part.mTris.size(); j++)
            {
                ManualObject* manual = mSceneMgr->createManualObject(("manual" + std::to_string(c++)).c_str());
                manual->begin("BaseWhiteNoLighting", RenderOperation::OT_TRIANGLE_LIST);

                QGears::MapFileSerializer::BlockTriangle& tri = part.mTris.at(j);

                QGears::MapFileSerializer::Vertex& v1 = part.mVertices.at(tri.Vertex0Index);
                QGears::MapFileSerializer::Vertex& v2 = part.mVertices.at(tri.Vertex1Index);
                QGears::MapFileSerializer::Vertex& v3 = part.mVertices.at(tri.Vertex2Index);

                manual->position( Convert(v1.X), Convert(v1.Y), Convert(v1.Z) );
                manual->position( Convert(v2.X), Convert(v2.Y), Convert(v2.Z) );
                manual->position( Convert(v3.X), Convert(v3.Y), Convert(v3.Z) );
                manual->end();
                mSceneMgr->getRootSceneNode()->createChildSceneNode()->attachObject(manual);
            }
        }

    }
}

int main(int argc, char **argv)
{
    Root *root = new Root();
    // choose renderer

    if(!root->showConfigDialog())
    {
        return 0;
    }

    // initialise root
    root->initialise(false);
    // create main window
    RenderWindow *renderWindow = root->createRenderWindow("Main",320,240,false);
    // create the scene
    SceneManager *sceneMgr = root->createSceneManager(Ogre::ST_GENERIC);
    // add a camera
    Camera *mainCam = sceneMgr->createCamera("MainCam");
    // add viewport
    Viewport *vp = renderWindow->addViewport(mainCam);

    Root::getSingleton().addResourceLocation (".", "FileSystem");
    ResourceGroupManager::getSingleton().initialiseAllResourceGroups();

    GameFrameListener *frameListener= new GameFrameListener();
  //  frameListener->showDebugOverlay(true);
    // Create an Entity

      Ogre::Entity* ogreHead = sceneMgr->createEntity("axes", "axes.mesh");

      // Create a SceneNode and attach the Entity to it
      Ogre::SceneNode* headNode = sceneMgr->getRootSceneNode()->createChildSceneNode("HeadNode");
      headNode->attachObject(ogreHead);
        headNode->setPosition( 200, 200, 30 );

      createColourCube(sceneMgr);

      mainCam->setPolygonMode(PM_WIREFRAME);

      mainCam->setFarClipDistance(9000.0f);
      mainCam->setPosition( 400, 400, 4000 );
      mainCam->lookAt( 0, 0, 0);

    root->addFrameListener(frameListener);

    root->startRendering();

    return 0;
}
