#ifndef _MAP_FILE_H_
#define _MAP_FILE_H_

#include "common/QGearsResource.h"

BEGIN_QGEARS

class WorldMapFile : public Resource
{
public:
    static const String RESOURCE_TYPE;
    using Resource::Resource;
    virtual ~WorldMapFile();
private:
    virtual void loadImpl() override final;
    virtual void unloadImpl() override final;
};

typedef Ogre::SharedPtr<WorldMapFile> AFilePtr;

END_QGEARS

#endif // _MAP_FILE_H_
