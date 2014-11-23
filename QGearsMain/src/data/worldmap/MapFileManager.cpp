#include "data/worldmap/MapFileManager.h"
#include "data/worldmap/MapFile.h"

template<> QGears::MapFileManager* Ogre::Singleton<QGears::MapFileManager>::msSingleton = nullptr;

BEGIN_QGEARS

MapFileManager *MapFileManager::getSingletonPtr()
{
    return msSingleton;
}

MapFileManager &MapFileManager::getSingleton()
{
    assert( msSingleton );
    return(*msSingleton );
}

MapFileManager::MapFileManager()
{
    mResourceType = WorldMapFile::RESOURCE_TYPE;
    mLoadOrder = 30.0f;
    Ogre::ResourceGroupManager::getSingleton()._registerResourceManager( mResourceType, this );
}

MapFileManager::~MapFileManager()
{
    Ogre::ResourceGroupManager::getSingleton()._unregisterResourceManager( mResourceType );
}

Ogre::Resource* MapFileManager::createImpl(
        const Ogre::String& name,
        Ogre::ResourceHandle handle,
        const Ogre::String& group,
        bool isManual,
        Ogre::ManualResourceLoader* loader,
        const Ogre::NameValuePairList* createParams )
{
    return new WorldMapFile( this, name, handle, group, isManual, loader );
}

END_QGEARS
