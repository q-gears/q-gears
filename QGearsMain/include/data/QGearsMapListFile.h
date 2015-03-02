#pragma once

#include <OgreResourceManager.h>
#include "QGearsPrerequisites.h"
#include "common/QGearsResource.h"
#include "QGearsSerializer.h"

namespace QGears
{
    class MapListFileManager :
        public Ogre::ResourceManager,
        public Ogre::Singleton<MapListFileManager>
    {
    public:
        MapListFileManager();
        virtual ~MapListFileManager();
        static MapListFileManager& getSingleton();
        static MapListFileManager* getSingletonPtr();
    protected:
        virtual Ogre::Resource *createImpl(
            const Ogre::String &name,
            Ogre::ResourceHandle handle,
            const Ogre::String& group,
            bool isManual,
            Ogre::ManualResourceLoader* loader,
            const Ogre::NameValuePairList* createParams) override;
    };

    class MapListFile : public Resource
    {
    public:
        MapListFile(Ogre::ResourceManager* creator,
            const String &name,
            Ogre::ResourceHandle handle,
            const String& group,
            bool isManual = false,
            Ogre::ManualResourceLoader* loader = nullptr);
        virtual ~MapListFile();
        static const String RESOURCE_TYPE;
        const std::vector<std::string> GetMapList() const
        {
            return mMapList;
        }
    protected:
        virtual void loadImpl(void) override;
        virtual void unloadImpl(void) override;
        virtual size_t calculateSize(void) const override;
    private:
        friend class MapListFileSerializer;
        std::vector<std::string> mMapList;
    };

    class MapListFileSerializer : public Serializer
    {
    public:
        MapListFileSerializer() = default;
        void importMapListFile(Ogre::DataStreamPtr &stream, MapListFile& dest);
    };

    typedef Ogre::SharedPtr<MapListFile> MapListFilePtr;
}
