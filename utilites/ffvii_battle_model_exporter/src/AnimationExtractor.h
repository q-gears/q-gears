#ifndef ANIMATION_EXTRACTOR_H
#define ANIMATION_EXTRACTOR_H

#include <Ogre.h>

#include "EnemyFile.h"
#include "../../common/File.h"



void AnimationExtractor(File* file, const Ogre::SkeletonPtr& skeleton, const EnemyInfo& info, Skeleton& skeleton_data, bool with_weapon);



#endif // ANIMATION_EXTRACTOR_H
