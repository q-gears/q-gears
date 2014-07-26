#ifndef _MAP_FILE_SERIALIZER_H_
#define _MAP_FILE_SERIALIZER_H_

#include "common/TypeDefine.h"
#include "data/QGearsSerializer.h"

BEGIN_QGEARS

class WorldMapFile;

class MapFileSerializer : public Serializer
{
public:
    MapFileSerializer();
    virtual ~MapFileSerializer();
    void importMapFile( Ogre::DataStreamPtr& stream, WorldMapFile& dest );
};

END_QGEARS

#endif // _MAP_FILE_SERIALIZER_H_
