#include "data/QGearsTriggersFile.h"

template<> QGears::TriggersFileManager *Ogre::Singleton<QGears::TriggersFileManager>::msSingleton = nullptr;

namespace QGears
{
    TriggersFileManager::TriggersFileManager()
    {
        mResourceType = TriggersFile::RESOURCE_TYPE;

        // low, because it will likely reference other resources
        mLoadOrder = 30.0f;

        // this is how we register the ResourceManager with OGRE
        Ogre::ResourceGroupManager::getSingleton()._registerResourceManager(mResourceType, this);
    }

    TriggersFileManager::~TriggersFileManager()
    {
        Ogre::ResourceGroupManager::getSingleton()._unregisterResourceManager(mResourceType);
    }

    /*static*/ TriggersFileManager& TriggersFileManager::getSingleton()
    {
        assert(msSingleton);
        return(*msSingleton);
    }

    /*static*/ TriggersFileManager* TriggersFileManager::getSingletonPtr()
    {
        return msSingleton;
    }

    // ===========================================================================

    TriggersFile::TriggersFile(Ogre::ResourceManager* creator,
        const String &name,
        Ogre::ResourceHandle handle,
        const String& group,
        bool isManual,
        Ogre::ManualResourceLoader* loader)
        : Resource(creator, name, handle, group, isManual, loader)
    {
        // TODO
    }

    TriggersFile::~TriggersFile()
    {
        // TODO
    }
 
    void TriggersFile::loadImpl(void)
    {
        // TODO
    }

    void TriggersFile::unloadImpl(void)
    {
        // TODO
    }

    size_t TriggersFile::calculateSize(void) const
    {
        // TODO
        return 0;
    }

    // TODO: Set this
    /*static*/ const String TriggersFile::RESOURCE_TYPE;

    // ===========================================================================

    Ogre::Resource* TriggersFileManager::createImpl(
        const Ogre::String &name,
        Ogre::ResourceHandle handle,
        const Ogre::String& group,
        bool isManual,
        Ogre::ManualResourceLoader* loader,
        const Ogre::NameValuePairList* createParams)
    {
        return new TriggersFile(this, name, handle, group, isManual, loader);
    }


    TriggerFileSerializer::TriggerFileSerializer()
    {
        // TODO
    }

    void TriggerFileSerializer::importTriggerFile(Ogre::DataStreamPtr &stream, TriggersFile *pDest)
    {
        // TODO
    }

}
