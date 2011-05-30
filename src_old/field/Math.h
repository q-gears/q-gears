// $Id: Math.h 96 2006-11-13 03:34:17Z crazy_otaku $

#ifndef MATH_H
#define MATH_H

#include <Ogre.h>



const Ogre::Degree
get_direction_to_point(const Ogre::Vector3& current_point, const Ogre::Vector3& direction_point);


const float
point_elevation(const Ogre::Vector2& point, const Ogre::Vector3& A, const Ogre::Vector3& B, const Ogre::Vector3& C);



const float
side_of_vector(const Ogre::Vector2& point, const Ogre::Vector2& p1, const Ogre::Vector2& p2);



const float
square_distance_to_line(const Ogre::Vector3& p, const Ogre::Vector3& p1, const Ogre::Vector3& p2, Ogre::Vector3& proj);



#endif // MATH_H
