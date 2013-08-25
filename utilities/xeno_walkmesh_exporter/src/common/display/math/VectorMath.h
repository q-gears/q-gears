// $Id: VectorMath.h 93 2006-11-12 13:49:02Z einherjar $

#ifndef VECTORMATH_H
#define VECTORMATH_H
// Functions with vectors



#include "Vector.h"
#include "Matrix.h"



void  Vector2Normalize(Vector2& out, const Vector2& v);
void  Vector3Normalize(Vector3& out, const Vector3& v);

void  Vector4Transform(Vector4& out, const Vector4& v, const Matrix& a);

float AngleVector3Vector3(const Vector3& v1, const Vector3& v2);
float AngleVector4Vector4(const Vector4& v1, const Vector4& v2);



#endif // VECTORMATH_H
