#pragma once

#include <OgreResourceManager.h>
#include "QGearsPrerequisites.h"
#include "common/QGearsResource.h"
#include "QGearsSerializer.h"
#include <memory>
#include <array>

namespace QGears
{
    class TriggersFileManager :
        public Ogre::ResourceManager, 
        public Ogre::Singleton<TriggersFileManager>
    {
    public:
        TriggersFileManager();
        virtual ~TriggersFileManager();
        static TriggersFileManager& getSingleton();
        static TriggersFileManager* getSingletonPtr();
    protected:
        virtual Ogre::Resource *createImpl(
            const Ogre::String &name,
            Ogre::ResourceHandle handle,
            const Ogre::String& group,
            bool isManual,
            Ogre::ManualResourceLoader* loader,
            const Ogre::NameValuePairList* createParams) override;
    };

    class TriggersFile : public Resource
    {
    public:
        TriggersFile(Ogre::ResourceManager* creator, 
            const String &name,
            Ogre::ResourceHandle handle,
            const String& group, 
            bool isManual = false,
            Ogre::ManualResourceLoader* loader = nullptr);
        virtual ~TriggersFile();
        static const String RESOURCE_TYPE;
       
        struct Range
        {
            s16 left;
            s16 top;
            s16 right;
            s16 bottom;
        };

        struct Vertex_s
        {
            u16 x;
            u16 y;
            u16 z;
        };

        struct Gateway
        {
            std::array<Vertex_s, 2> exit_line;
            Vertex_s destination;
            u16 destinationFieldId;
            u8 dir, dir_copy1, dir_copy2, dir_copy3;
        };

        struct Trigger
        {
            std::array<Vertex_s, 2> trigger_line;
            u8 background_parameter;
            u8 background_state;
            u8 behavior;
            /* 0 - OnTrigger - ON
            * 1 - OnTrigger - OFF
            * 2 - OnTrigger - ON, AwayFromTrigger - OFF
            * 3 - OnTrigger - OFF, AwayFromTrigger - ON
            * 4 - OnTrigger - ON, AwayFromTriggerOnPlusSide - OFF
            * 5 - OnTrigger - OFF, AwayFromTriggerOnPlusSide - ON
            */
            u8 soundID;
        };

        struct Arrow
        {
            s32 positionX;
            s32 positionZ;
            s32 positionY;
            u32 type;// 0 - Invisible, 1 - Red, 2 - Green
        };

        struct TriggerData
        {
            std::array<char, 9> name;
            u8 control;
            s16 cameraFocusHeight;
            Range camera_range; // 8 bytes
            u8 bg_layer1_flag;
            u8 bg_layer2_flag;
            u8 bg_layer3_flag;
            u8 bg_layer4_flag;
            s16 bg_layer3_width;
            s16 bg_layer3_height;
            s16 bg_layer4_width;
            s16 bg_layer4_height;
            std::array<u8, 24> unknown;
            std::array<Gateway, 12> doors;// 24 * 12 bytes
            std::array<Trigger, 12> triggers;// 16 * 12 bytes
            // Only in occidental/international version
            std::array<u8, 12> display_arrow;
            std::array<Arrow, 12> arrows;// 16 * 12 bytes
        };

        const Range& getCameraRange() const
        {
            return mData->camera_range;
        }

        float MovementRotation() const
        {
            // This is the angle in which the player moves when "up" is pressed
            return 180.0f * (static_cast<float>(mData->control) - 128.0f) / 128.0f;
        }

        const std::array<Gateway, 12>& GetGateways() const
        {
            return mData->doors;
        }

    protected:
        virtual void loadImpl(void) override;
        virtual void unloadImpl(void) override;
        virtual size_t calculateSize(void) const override;
    private:

 
        std::unique_ptr<TriggerData> mData;

        friend class TriggerFileSerializer;
    };
    
    class TriggerFileSerializer : public Serializer
    {
    public:
        TriggerFileSerializer();
        void importTriggerFile(Ogre::DataStreamPtr &stream, TriggersFile *pDest);
    private:
        void ReadVertex_s(Ogre::DataStreamPtr& stream, TriggersFile::Vertex_s& vertex);
        void ReadRange(Ogre::DataStreamPtr& stream, TriggersFile::Range& range);
        void ReadGateway(Ogre::DataStreamPtr& stream, TriggersFile::Gateway& exit);
        void ReadArrow(Ogre::DataStreamPtr& stream, TriggersFile::Arrow& arrow);
        void ReadTrigger(Ogre::DataStreamPtr& stream, TriggersFile::Trigger& trigger);
    };

    typedef Ogre::SharedPtr<TriggersFile> TriggersFilePtr;
}