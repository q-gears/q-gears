#ifndef MODEL_H
#define MODEL_H

#include <Ogre.h>



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



struct Animation
{
    std::vector<Frame> frame;
};



struct Model
{
    struct Bone
    {
        Sint16 length;
        Sint8  parent_id;
    };
    std::vector<Bone>             m_Skeleton;
};



#endif // MODEL_H
