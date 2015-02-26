#pragma once

#include <OgreResourceManager.h>
#include "QGearsPrerequisites.h"
#include "common/QGearsResource.h"
#include "QGearsSerializer.h"

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
    protected:
        virtual void loadImpl(void) override;
        virtual void unloadImpl(void) override;
        virtual size_t calculateSize(void) const override;
    private:
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

        struct Exit
        {
            Vertex_s exit_line[2];
            Vertex_s destination;
            u16 fieldID;
            u8 dir, dir_copy1, dir_copy2, dir_copy3;
        };

        struct Trigger
        {
            Vertex_s trigger_line[2];
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
            char name[9];
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
            u8 unknown[24];
            Exit doors[12];// 24 * 12 bytes
            Trigger triggers[12];// 16 * 12 bytes
            // Only in occidental/international version
            u8 display_arrow[12];
            Arrow arrows[12];// 16 * 12 bytes
        };
        
        // TODO: Fails!
       // static_assert( sizeof(TriggerData) != 740, "Wrong size, check type defines and alignment");

        TriggerData mData;
    };
    
    class TriggerFileSerializer : public Serializer
    {
    public:
        TriggerFileSerializer();
        void importTriggerFile(Ogre::DataStreamPtr &stream, TriggersFile *pDest);
    };

    typedef Ogre::SharedPtr<TriggersFile> TriggersFilePtr;
}