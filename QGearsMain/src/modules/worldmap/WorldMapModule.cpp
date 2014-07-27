#include "modules/worldmap/WorldMapModule.h"
#include "data/worldmap/MapFileSerializer.h"
#include "data/worldmap/MapFile.h"
#include <OgreSceneManager.h>
#include <OgreManualObject.h>
#include <OgreRoot.h>
#include "core/CameraManager.h"

BEGIN_QGEARS

template<>WorldMapModule *Ogre::Singleton< WorldMapModule >::msSingleton = NULL;

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

static float From16BitFixedPoint(QGears::sint16 coord)
{
    return float(coord);

 //   return (float(coord) / 4096.0f);
}

void createTestMap(SceneManager* mSceneMgr)
{
    std::vector<QGears::MapFileSerializer::SBlock> blocks;
    createReferenceFileInstance([&](Ogre::DataStreamPtr& stream, QGears::WorldMapFile& file)
    {
        QGears::MapFileSerializer s;
        s.importMapFile( stream, file );
        blocks = s.mBlocks;
    });

    int c = 0;

    const int kSpace = 8182;

    size_t numBlocks = blocks.size();

    int mapX = 0;
    int mapY = 0;

    for ( int k=0; k<numBlocks; k++ )
    {
        // 7x9 size

        QGears::MapFileSerializer::SBlock& block = blocks[k];

        int blockX = 0;
        int blockY = 0;
        for ( size_t i=0; i<block.mMeshes.size(); i++ )
        {
            QGears::MapFileSerializer::SBlockPart& part = block.mMeshes[i];

            ManualObject* manual = mSceneMgr->createManualObject(("zzz_manual" + std::to_string(c++)).c_str());
            manual->begin("BaseWhiteNoLighting", RenderOperation::OT_TRIANGLE_LIST);
            for ( size_t j=0; j<part.mVertices.size(); j++)
            {
                QGears::MapFileSerializer::Vertex& v1 = part.mVertices.at(j);
                manual->position(v1.X, -v1.Y, v1.Z);
            }

            for ( size_t j=0; j<part.mTris.size(); j++)
            {
                QGears::MapFileSerializer::BlockTriangle& tri = part.mTris.at(j);

                // define usage of vertices by refering to the indexes
                manual->index(tri.Vertex0Index);
                manual->index(tri.Vertex1Index);
                manual->index(tri.Vertex2Index);
            }


            manual->end();
            SceneNode* node = mSceneMgr->getRootSceneNode()->createChildSceneNode();
            node->attachObject(manual);


            float xPos = (blockX * kSpace) + (mapX * kSpace * 4);
            float yPos = (blockY * kSpace) + (mapY * kSpace * 4);
            node->setPosition( xPos, 0, yPos);
           // node->setOrientation( 0, 0, 180, 0);


            blockX++;
            if (blockX >= 4 )
            {
                blockX = 0;
                blockY++;
            }

        }

        mapX++;
        if (mapX >= 9 )
        {
            mapX = 0;
            mapY++;
        }

    }
}

void WorldMapModule::Init()
{
    createTestMap(Root::getSingleton().getSceneManager("Scene"));
    CameraManager::getSingleton().EnableWireFrame(true);
}

END_QGEARS
