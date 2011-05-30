// $Id: MatrixMath.h 93 2006-11-12 13:49:02Z einherjar $

#ifndef MATRIXMATH_H
#define MATRIXMATH_H
// Function with matrix



#include "Matrix.h"



#define DegreeToRadian(degree) ((degree) * (3.141592653589793f / 180.0f))
#define RadianToDegree(radian) ((radian) * (180.0f / 3.141592653589793f))



void MatrixIdentity   (Matrix &out);
void MatrixTranslation(Matrix &out, float x, float y, float z);
void MatrixScaling    (Matrix &out, float x, float y, float z);
void MatrixRotationX  (Matrix &out, float theta);
void MatrixRotationY  (Matrix &out, float theta);
void MatrixRotationZ  (Matrix &out, float theta);
void MatrixRotationXYZ(Matrix &out, float rx, float ry, float rz);

void MatrixMultiply   (Matrix &out, const Matrix &a, const Matrix &b);

Matrix LookAt(float eyex,    float eyey,    float eyez,
              float centerx, float centery, float centerz,
              float upx,     float upy,     float upz);



#endif
