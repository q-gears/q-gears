#ifndef ANIMATION_EXTRACTOR_H
#define ANIMATION_EXTRACTOR_H

#include <Ogre.h>

#include "ModelFile.h"
#include "../../common/File.h"



void AnimationExtractor( const Ogre::SkeletonPtr& skeleton, const ModelInfo& info, Skeleton& skeleton_data );



#endif // ANIMATION_EXTRACTOR_H
