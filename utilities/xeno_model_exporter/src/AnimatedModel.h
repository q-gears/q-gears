#ifndef ANIMATEDMODEL_H
#define ANIMATEDMODEL_H

#include <Ogre.h>
#include "../../common/DrawSkeleton.h"
#include "../../common/OgreGenUtilites.h"



struct ModelInfo
{
    MeshData                  data;
    Ogre::String              model_file;
    Ogre::String              animation_file;
    std::vector<Ogre::String> animations;
};



class AnimatedModel
{
public:
    AnimatedModel();
    virtual ~AnimatedModel();

    Ogre::Entity* Export( const ModelInfo& info );

private:
    Skeleton m_Skeleton;
};



#endif // ANIMATEDMODEL_H
