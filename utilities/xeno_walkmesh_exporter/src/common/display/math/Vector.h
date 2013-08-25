// $Id: Vector.h 76 2006-08-25 18:41:20Z crazy_otaku $

#ifndef VECTOR_H
#define VECTOR_H
// The Vector Structs : Represent vectors for math operations

#include <math.h>

#include "../../utilites/Logger.h"



struct Vector2
{
    Vector2() {}
    Vector2(const float *f)                          {x = f[0]; y = f[1];}
    Vector2(float x1, float y1): x(x1), y(y1)        {}

    // casting
    operator float* ()                               {return &x;};
    operator const float* () const                   {return &x;};

    // assignment operators
    Vector2& operator += (const Vector2& other)      {x += other.x; y += other.y; return *this;}
    Vector2& operator -= (const Vector2& other)      {x -= other.x; y -= other.y; return *this;}
    Vector2& operator *= (float f)                   {x *= f; y *= f; return *this;}
    Vector2& operator /= (float f)                   {x /= f; y /= f; return *this;}

    // binary operators
    Vector2 operator + (const Vector2& other) const  {return Vector2(x + other.x, y + other.y);}
    Vector2 operator - (const Vector2& other) const  {return Vector2(x - other.x, y - other.y);}
    Vector2 operator * (float f) const               {return Vector2(x * f, y * f);}
    Vector2 operator / (float f) const               {return Vector2(x / f, y / f);}

    bool operator == (const Vector2& other) const    {return ((x == other.x) && (y == other.y));}
    bool operator != (const Vector2& other) const    {return !(*this == other);}

    Vector2 normalize() const                        {float l = length(); return Vector2(x / l, y / l);}
    float length() const                             {return sqrtf(x * x + y * y);}

    friend Vector2 operator * (float f, const Vector2& other) {return other * f;}

    float x, y;
};



struct Vector3
{
    Vector3() {}
    Vector3(const float *f)                         {x = f[0]; y = f[1]; z = f[2];}
    Vector3(float x1, float y1, float z1)           {x = x1; y = y1; z = z1;}

    // casting
    operator float* ()                                        {return &x;};
    operator const float* () const                            {return &x;};

    // assignment operators
    Vector3& operator += (const Vector3& other)               {x += other.x; y += other.y; z += other.z; return *this;}
    Vector3& operator -= (const Vector3& other)               {x -= other.x; y -= other.y; z -= other.z; return *this;}
    Vector3& operator *= (float f)                            {x *= f; y *= f; z *= f; return *this;}
    Vector3& operator /= (float f)                            {x /= f; y /= f; z /= f; return *this;}

    // binary operators
    Vector3 operator + (const Vector3& other) const           {return Vector3(x + other.x, y + other.y, z + other.z);}
    Vector3 operator - (const Vector3& other) const           {return Vector3(x - other.x, y - other.y, z - other.z);}
    Vector3 operator * (float f) const                        {return Vector3(x * f, y * f, z * f);}
    Vector3 operator / (float f) const                        {return Vector3(x / f, y / f, z / f);}

    bool operator == (const Vector3& other) const             {return ((x == other.x) && (y == other.y) && (z == other.z));}
    bool operator != (const Vector3& other) const             {return !(*this == other);}

    Vector3 normalize() const                                 {float l = length(); return Vector3(x / l, y / l, z / l);} 
    float length() const                                      {return sqrtf(x * x + y * y + z * z);}
    float dotProduct(const Vector3& other) const              {return x * other.x + y * other.y + z * other.z;}
    Vector3 crossProduct(const Vector3& other) const          {return Vector3(y * other.z - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x);}

    friend Vector3 operator * (float f, const Vector3& other) {return other * f;}

    float x, y, z;
};



struct Vector4
{
    Vector4() {}
    Vector4(const float *f)                         {x = f[0]; y = f[1]; z = f[2]; w = f[3];}
    Vector4(float x1, float y1, float z1, float w1) {x = x1; y = y1; z = z1; w = w1;}

    // casting
    operator float* ()                              {return &x;};
    operator const float* () const                  {return &x;};

    // assignment operators
    Vector4& operator += (const Vector4& other)     {x += other.x; y += other.y; z += other.z; w += other.w; return *this;}
    Vector4& operator -= (const Vector4& other)     {x -= other.x; y -= other.y; z -= other.z; w -= other.w; return *this;}
    Vector4& operator *= (float f)                  {x *= f; y *= f; z *= f; w *= f; return *this;}
    Vector4& operator /= (float f)                  {x /= f; y /= f; z /= f; w /= f; return *this;}

    // binary operators
    Vector4 operator + (const Vector4& other) const {return Vector4(x + other.x, y + other.y, z + other.z, w + other.w);}
    Vector4 operator - (const Vector4& other) const {return Vector4(x - other.x, y - other.y, z - other.z, w - other.w);}
    Vector4 operator * (float f) const              {return Vector4(x * f, y * f, z * f, w * f);}
    Vector4 operator / (float f) const              {return Vector4(x / f, y / f, z / f, w / f);}

    bool operator == (const Vector4& other) const             {return ((x == other.x) && (y == other.y) && (z == other.z) && (w == other.w));}
    bool operator != (const Vector4& other) const             {return !(*this == other);}

    float length() const                                      {return sqrtf(x * x + y * y + z * z);}
    float dotProduct(const Vector4& other) const              {return x * other.x + y * other.y + z * other.z;}
    Vector4 crossProduct(const Vector4& other) const          {return Vector4(y * other.z - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x, 1.0f);}

    friend Vector4 operator * (float f, const Vector4& other) {return other * f;}

    float x, y, z, w;
};



struct Plane
{
    Plane()                                           {Plane(Vector3(0.f, 0.f, 0.f), 0.f);}
    Plane(const Vector3& normal_, float offset)       {normal = normal_; D = offset;}
    Plane(float nX, float nY, float nZ, float offset) {Plane(Vector3(nX, nY, nZ), offset);}
    Plane(const Plane& other)                         {Plane(other.normal, other.D);}
    Plane(const Vector3& p1, const Vector3& p2, const Vector3& p3)
    {
        normal = (p2 - p1).crossProduct(p3 - p1);
        D = -normal.dotProduct(p1);
    }

    float distanceToPoint(const Vector3& point) const
    {
        return fabs(signedDistanceToPoint(point));
    }

    float signedDistanceToPoint(const Vector3& point) const
    {
        return (normal.dotProduct(point) + D) / normal.length();
    }

    Vector3 findHeightIntersection(const Vector3& point) const
    {
        float dist = signedDistanceToPoint(point);
        return point - (dist * normal.normalize());
    }

    bool intersectsWithLineSegment(const Vector3& linePoint1, const Vector3& linePoint2, Vector3& intersectionPoint) const
    {
        float d1 = signedDistanceToPoint(linePoint1);
        float d2 = signedDistanceToPoint(linePoint2);

        if (((d1 > 0) && (d2 < 0)) || ((d1 < 0) && (d2 > 0)))
        {
            Vector3 distance = linePoint1 - linePoint2;
            intersectionPoint = linePoint2 - distance * (d2 / distance.length());
            return true;
        }
        return false;
    }

    Vector3 normal;
    float   D;
};



#endif // VECTOR_H
