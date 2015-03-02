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
    }

    TriggersFile::~TriggersFile()
    {
        unload();
    }
 
    void TriggersFile::loadImpl(void)
    {
        TriggerFileSerializer serializer;
        Ogre::DataStreamPtr stream(openResource());
        serializer.importTriggerFile(stream, this);
    }

    void TriggersFile::unloadImpl(void)
    {

    }

    size_t TriggersFile::calculateSize(void) const
    {
        return sizeof(TriggerData);
    }

    /*static*/ const String TriggersFile::RESOURCE_TYPE("FF7FieldTriggersSection");

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

    }

    void TriggerFileSerializer::ReadVertex_s(Ogre::DataStreamPtr& stream, TriggersFile::Vertex_s& vertex)
    {
        readShort(stream, vertex.x);
        readShort(stream, vertex.y);
        readShort(stream, vertex.z);
    }

    void TriggerFileSerializer::ReadRange(Ogre::DataStreamPtr& stream, TriggersFile::Range& range)
    {
        readInt16(stream, range.left);
        readInt16(stream, range.top);
        readInt16(stream, range.right);
        readInt16(stream, range.bottom);
    }

    void TriggerFileSerializer::ReadGateway(Ogre::DataStreamPtr& stream, TriggersFile::Gateway& exit)
    {
        for (size_t i = 0; i < exit.exit_line.size(); i++)
        {
            ReadVertex_s(stream, exit.exit_line[i]);
        }
        ReadVertex_s(stream, exit.destination);
        readShort(stream, exit.destinationFieldId);
        readUInt8(stream, exit.dir);
        readUInt8(stream, exit.dir_copy1);
        readUInt8(stream, exit.dir_copy2);
        readUInt8(stream, exit.dir_copy3);
    }

    void TriggerFileSerializer::ReadArrow(Ogre::DataStreamPtr& stream, TriggersFile::Arrow& arrow)
    {
        readSInt32(stream, arrow.positionX);
        readSInt32(stream, arrow.positionZ);
        readSInt32(stream, arrow.positionY);
        readUInt32(stream, arrow.type);
    }

    void TriggerFileSerializer::ReadTrigger(Ogre::DataStreamPtr& stream, TriggersFile::Trigger& trigger)
    {
        for (size_t i = 0; i < trigger.trigger_line.size(); i++)
        {
            ReadVertex_s(stream, trigger.trigger_line[i]);
        }
        readUInt8(stream, trigger.background_parameter);
        readUInt8(stream, trigger.background_state);
        readUInt8(stream, trigger.behavior);
        readUInt8(stream, trigger.soundID);
    }

    void TriggerFileSerializer::importTriggerFile(Ogre::DataStreamPtr &stream, TriggersFile *pDest)
    {
        std::unique_ptr<TriggersFile::TriggerData> data = std::unique_ptr<TriggersFile::TriggerData>(new TriggersFile::TriggerData());

        readChars(stream, data->name.data(), data->name.size());
        readUInt8(stream, data->control);
        readInt16(stream, data->cameraFocusHeight);
        ReadRange(stream, data->camera_range);

        readUInt8(stream, data->bg_layer1_flag);
        readUInt8(stream, data->bg_layer2_flag);
        readUInt8(stream, data->bg_layer3_flag);
        readUInt8(stream, data->bg_layer4_flag);
   
        readInt16(stream, data->bg_layer3_width);
        readInt16(stream, data->bg_layer3_height);
        readInt16(stream, data->bg_layer4_width);
        readInt16(stream, data->bg_layer4_height);

        stream->read(data->unknown.data(), data->unknown.size());


        for (size_t i = 0; i < data->doors.size(); i++)
        {
            TriggersFile::Gateway& exit = data->doors[i];
            ReadGateway(stream, exit);
        }
        
        for (size_t i = 0; i < data->triggers.size(); i++)
        {
            TriggersFile::Trigger& trigger = data->triggers[i];
            ReadTrigger(stream, trigger);
        }

        stream->read(data->display_arrow.data(), data->display_arrow.size());

        for (size_t i = 0; i < data->arrows.size(); i++)
        {
            TriggersFile::Arrow& arrow = data->arrows[i];
            ReadArrow(stream, arrow);
        }

        pDest->mData = std::move(data);


    }

}
