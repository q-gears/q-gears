#ifndef DRAW_SKELETON_H
#define DRAW_SKELETON_H

#include "ModelFile.h"

#include <Ogre.h>



void DrawSkeleton( const Skeleton& skeleton, const Ogre::MeshPtr& mesh );

void DrawBone( const Skeleton& skeleton, int parent_index, const Ogre::Matrix3& matrix, const Ogre::Vector3& translation );

#endif // DRAW_SKELETON_H
