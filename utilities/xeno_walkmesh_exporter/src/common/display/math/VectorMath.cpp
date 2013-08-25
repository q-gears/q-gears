// $Id: VectorMath.cpp 93 2006-11-12 13:49:02Z einherjar $

#include <math.h>

#include "Vector.h"
#include "VectorMath.h"
#include "../../utilites/Logger.h"




void
Vector2Normalize(Vector2& out, const Vector2& v)
{
    float scale = 1.0f / sqrtf(v.x * v.x + v.y * v.y);
    out.x = v.x * scale;
    out.y = v.y * scale;
}



void
Vector3Normalize(Vector3& out, const Vector3& v)
{
    float scale = 1.0f / sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
    out.x = v.x * scale;
    out.y = v.y * scale;
    out.z = v.z * scale;
}



void
Vector4Transform(Vector4& out, const Vector4& v, const Matrix& a)
{
    out = Vector4(
        a.m[0][0] * v.x + a.m[1][0] * v.y + a.m[2][0] * v.z + a.m[3][0] * v.w,
        a.m[0][1] * v.x + a.m[1][1] * v.y + a.m[2][1] * v.z + a.m[3][1] * v.w,
        a.m[0][2] * v.x + a.m[1][2] * v.y + a.m[2][2] * v.z + a.m[3][2] * v.w,
        a.m[0][3] * v.x + a.m[1][3] * v.y + a.m[2][3] * v.z + a.m[3][3] * v.w);
}



float
AngleVector3Vector3(const Vector3& v1, const Vector3& v2)
{
    return acosf((v1.x * v2.x + v1.y * v2.y + v1.z * v2.z) / (sqrtf(v1.x * v1.x + v1.y * v1.y + v1.z * v1.z) * sqrtf(v2.x * v2.x + v2.y * v2.y + v2.z * v2.z)));
    //return acosf(v1.dotProduct(v2) / (v1.length() * v2.length()));
}



float
AngleVector4Vector4(const Vector4& v1, const Vector4& v2)
{
    return acosf((v1.x * v2.x + v1.y * v2.y + v1.z * v2.z) / (sqrtf(v1.x * v1.x + v1.y * v1.y + v1.z * v1.z) * sqrtf(v2.x * v2.x + v2.y * v2.y + v2.z * v2.z)));
    //return acosf(v1.dotProduct(v2) / (v1.length() * v2.length()));
}
