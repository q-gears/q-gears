#ifndef _WORLD_MAP_MODULE_H_
#define _WORLD_MAP_MODULE_H_

#include <OgreSingleton.h>
#include "common/TypeDefine.h"

BEGIN_QGEARS

class WorldMapModule : public Ogre::Singleton< WorldMapModule >
{
public:
    void Init();
};

END_QGEARS

#endif // _WORLD_MAP_MODULE_H_
