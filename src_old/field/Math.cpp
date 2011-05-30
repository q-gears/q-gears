// $Id: Math.cpp 96 2006-11-13 03:34:17Z crazy_otaku $

#include "Math.h"



const Ogre::Degree
get_direction_to_point(const Ogre::Vector3& current_point, const Ogre::Vector3& direction_point)
{
    Ogre::Vector2 up(0.0f, -1.0f);
    Ogre::Vector2 dir(direction_point.x - current_point.x, direction_point.y - current_point.y);
    // angle between vectors
    Ogre::Degree angle(Ogre::Radian(acosf(dir.dotProduct(up) / (dir.length() * up.length()))));
    return (dir.x < 0) ? Ogre::Degree(360) - angle : angle;
}



const float
point_elevation(const Ogre::Vector2& point, const Ogre::Vector3& A, const Ogre::Vector3& B, const Ogre::Vector3& C)
{
    float _A = A.z * (B.y - C.y) + B.z * (C.y - A.y) + C.z * (A.y - B.y);
    float _B = A.y * (B.x - C.x) + B.y * (C.x - A.x) + C.y * (A.x - B.x);
    float _C = A.x * (B.z - C.z) + B.x * (C.z - A.z) + C.x * (A.z - B.z);
    float _D = A.x * (B.z * C.y - C.z * B.y) + B.x * (C.z * A.y - A.z * C.y) + C.x * (A.z * B.y - B.z * A.y);

    return (_D - _C * point.y - _A * point.x) / _B;
}



const float
side_of_vector(const Ogre::Vector2& point, const Ogre::Vector2& p1, const Ogre::Vector2& p2)
{
    Ogre::Vector2 AB = p2    - p1;
    Ogre::Vector2 AP = point - p1;
    return AB.x * AP.y - AB.y * AP.x;
}



const float
square_distance_to_line(const Ogre::Vector3& p, const Ogre::Vector3& p1, const Ogre::Vector3& p2, Ogre::Vector3& proj)
{
    float temp = -((p1.x - p.x) * (p2.x - p1.x) + (p1.y - p.y) * (p2.y - p1.y) + (p1.z - p.z) * (p2.z - p1.z)) / ((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y) + (p2.z - p1.z) * (p2.z - p1.z));

    proj.x = temp * (p2.x - p1.x) + p1.x;
    proj.y = temp * (p2.y - p1.y) + p1.y;
    proj.z = temp * (p2.z - p1.z) + p1.z;

    if (((p1.x >= proj.x && p2.x <= proj.x) || (p1.x < proj.x && p2.x >= proj.x)) &&
        ((p1.y >= proj.y && p2.y <= proj.y) || (p1.y < proj.y && p2.y >= proj.y)))
    {
        return (proj.x - p.x) * (proj.x - p.x) + (proj.y - p.y) * (proj.y - p.y) + (proj.z - p.z) * (proj.z - p.z);
    }

    return -1;
}
