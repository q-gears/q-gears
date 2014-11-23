#include "data/worldmap/TxzFileManager.h"
#include "data/worldmap/TxzFile.h"

BEGIN_QGEARS

template<> TxzFileManager* Ogre::Singleton<TxzFileManager>::msSingleton = nullptr;

TxzFileManager* TxzFileManager::getSingletonPtr()
{
    return msSingleton;
}

TxzFileManager& TxzFileManager::getSingleton()
{
    assert( msSingleton );
    return(*msSingleton );
}

TxzFileManager::TxzFileManager()
{
    mResourceType = TxzFile::RESOURCE_TYPE;
    mLoadOrder = 20.0f;
    Ogre::ResourceGroupManager::getSingleton()._registerResourceManager( mResourceType, this );
}

TxzFileManager::~TxzFileManager()
{
    Ogre::ResourceGroupManager::getSingleton()._unregisterResourceManager( mResourceType );
}

Ogre::Resource* TxzFileManager::createImpl(
        const Ogre::String& name,
        Ogre::ResourceHandle handle,
        const Ogre::String& group,
        bool isManual,
        Ogre::ManualResourceLoader* loader,
        const Ogre::NameValuePairList* createParams )
{
    return new TxzFile( this, name, handle, group, isManual, loader );
}

END_QGEARS
