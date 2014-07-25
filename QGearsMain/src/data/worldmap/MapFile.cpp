#include "data/worldmap/MapFile.h"
#include "data/worldmap/MapFileSerializer.h"

BEGIN_QGEARS

/*static*/ const String MapFile::RESOURCE_TYPE( "QGearsWorldMap7File" );

MapFile::~MapFile()
{

}

void MapFile::loadImpl()
{
    MapFileSerializer serializer;
    Ogre::DataStreamPtr stream( openResource() );
    serializer.importMapFile( stream, *this );
}

void MapFile::unloadImpl()
{

}

END_QGEARS
