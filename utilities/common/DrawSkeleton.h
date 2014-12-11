#ifndef DRAW_SKELETON_H
#define DRAW_SKELETON_H

#include <Ogre.h>



struct Bone
{
    Bone():
        length( 0 ),
        parent_id( -1 )
    {
    }
    float length;
    int parent_id;
};
typedef std::vector< Bone > Skeleton;



void DrawSkeleton( const Skeleton& skeleton, const Ogre::MeshPtr& mesh );

void DrawBone( const Skeleton& skeleton, int parent_index, Ogre::RGBA* colours );

#endif // DRAW_SKELETON_H
