#include "data/worldmap/TxzFile.h"
#include "data/worldmap/TxzFileSerializer.h"

BEGIN_QGEARS

/*static*/ const String TxzFile::RESOURCE_TYPE( "QGearsWorldMapTxzFile" );

TxzFile::~TxzFile()
{

}

void TxzFile::loadImpl()
{
    TxzFileSerializer serializer;
    Ogre::DataStreamPtr stream( openResource() );
    serializer.import( stream, *this );
}

void TxzFile::unloadImpl()
{

}

END_QGEARS
