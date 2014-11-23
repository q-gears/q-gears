#ifndef _MAP_FILE_H_
#define _MAP_FILE_H_

#include "common/QGearsResource.h"

BEGIN_QGEARS

class WorldMapFile : public Resource
{
public:
    static const String RESOURCE_TYPE;
    WorldMapFile(Ogre::ResourceManager* creator, const Ogre::String& name, Ogre::ResourceHandle handle,
        const Ogre::String& group, bool isManual = false, Ogre::ManualResourceLoader* loader = 0)
        : Resource(creator, name, handle, group, isManual, loader)
    {

    }

    virtual ~WorldMapFile();
private:
    virtual void loadImpl() override final;
    virtual void unloadImpl() override final;
};

typedef Ogre::SharedPtr<WorldMapFile> MapFilePtr;

END_QGEARS

#endif // _MAP_FILE_H_
