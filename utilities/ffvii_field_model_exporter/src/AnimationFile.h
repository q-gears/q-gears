#ifndef ANIMATION_FILE_H
#define ANIMATION_FILE_H

#include <Ogre.h>

#include "../../common/File.h"
#include "BsxFile.h"



struct BonePosition
{
    float rotation_x;
    float rotation_y;
    float rotation_z;

    float translation_x;
    float translation_y;
    float translation_z;
};



struct Frame
{
    std::vector<BonePosition> bone;
};



class AnimationFile : public File
{
public:
    explicit     AnimationFile(const Ogre::String& file);
    explicit     AnimationFile(File* pFile);
                 AnimationFile(File* pFile, const u32 offset, const u32 length);
                 AnimationFile(u8* pBuffer, const u32 offset, const u32 length);
    virtual     ~AnimationFile();

    void         GetData( std::vector< s16 >& skeleton_length, const Unit& unit, const int offset_to_animations, const int number_of_animation, const int start_animation, Ogre::SkeletonPtr skeleton );

private:
    struct AnimationHeader
    {
        u16 number_of_frames;                  // 00-01
        u16 number_of_bones;                   // 02
        u16 number_of_frames_translation;      // 03
        u16 number_of_static_translation;      // 04
        u16 number_of_frames_rotation;         // 05
        u16 offset_to_frames_translation_data; // 06-07
        u16 offset_to_static_translation_data; // 08-09
        u16 offset_to_frames_rotation_data;    // 0A-0B
        u32 offset_to_animation_data;          // 0C-0F
    };

    typedef std::vector<AnimationHeader> AnimationHeaders;

    AnimationHeaders m_AnimationHeaders;
};



#endif // ANIMATION_FILE_H
