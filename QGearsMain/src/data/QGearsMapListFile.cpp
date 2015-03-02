#include "data/QGearsMapListFile.h"
#include <array>

template<> QGears::MapListFileManager *Ogre::Singleton<QGears::MapListFileManager>::msSingleton = nullptr;

namespace QGears
{
    const int kMapNameMaxSize = 32;

    MapListFileManager::MapListFileManager()
    {
        mResourceType = MapListFile::RESOURCE_TYPE;

        // low, because it will likely reference other resources
        mLoadOrder = 30.0f;

        // this is how we register the ResourceManager with OGRE
        Ogre::ResourceGroupManager::getSingleton()._registerResourceManager(mResourceType, this);
    }

    MapListFileManager::~MapListFileManager()
    {
        Ogre::ResourceGroupManager::getSingleton()._unregisterResourceManager(mResourceType);
    }

    /*static*/ MapListFileManager& MapListFileManager::getSingleton()
    {
        assert(msSingleton);
        return(*msSingleton);
    }

    /*static*/ MapListFileManager* MapListFileManager::getSingletonPtr()
    {
        return msSingleton;
    }

    // ===========================================================================

    MapListFile::MapListFile(Ogre::ResourceManager* creator,
        const String &name,
        Ogre::ResourceHandle handle,
        const String& group,
        bool isManual,
        Ogre::ManualResourceLoader* loader)
        : Resource(creator, name, handle, group, isManual, loader)
    {
    }

    MapListFile::~MapListFile()
    {
        unload();
    }

    void MapListFile::loadImpl(void)
    {
        MapListFileSerializer serializer;
        Ogre::DataStreamPtr stream(openResource());
        serializer.importMapListFile(stream, *this);
    }

    void MapListFile::unloadImpl(void)
    {
        mMapList.clear();
    }

    size_t MapListFile::calculateSize(void) const
    {
        return mMapList.size() * kMapNameMaxSize;
    }

    /*static*/ const String MapListFile::RESOURCE_TYPE("FF7FieldPCMapList");

    Ogre::Resource* MapListFileManager::createImpl(
        const Ogre::String &name,
        Ogre::ResourceHandle handle,
        const Ogre::String& group,
        bool isManual,
        Ogre::ManualResourceLoader* loader,
        const Ogre::NameValuePairList* createParams)
    {
        return new MapListFile(this, name, handle, group, isManual, loader);
    }

    // ===========================================================================

    void MapListFileSerializer::importMapListFile(Ogre::DataStreamPtr &stream, MapListFile& dest)
    {
        uint16 numMaps = 0;
        readShort(stream, numMaps);
        for (auto i = 0u; i < numMaps; i++)
        {
            // +1 to ensure nullptr termination
            std::array<char, kMapNameMaxSize + 1> tmpBuffer = {};
            readChars(stream, tmpBuffer.data(), tmpBuffer.size() - 1);
            std::string tmp = tmpBuffer.data();
            if (!tmp.empty())
            {
                dest.mMapList.emplace_back(tmp);
            }
        }
    }

}
