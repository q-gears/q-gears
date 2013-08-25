// $Id: MatrixMath.cpp 93 2006-11-12 13:49:02Z einherjar $

#include "MatrixMath.h"
#include "Vector.h"
#include "VectorMath.h"

#include <math.h>
#include <memory.h>



void
MatrixIdentity(Matrix &out)
{
    static float identity[16] = {1, 0, 0, 0,
                                 0, 1, 0, 0,
                                 0, 0, 1, 0,
                                 0, 0, 0, 1};
    memcpy(&(out.m[0][0]), identity, sizeof(identity));
}



void
MatrixTranslation(Matrix &out, float x, float y, float z)
{
    MatrixIdentity(out);
    out.m[3][0] = x;
    out.m[3][1] = y;
    out.m[3][2] = z;
}



void
MatrixScaling(Matrix &out, float x, float y, float z)
{
    MatrixIdentity(out);
    out.m[0][0] = x;
    out.m[1][1] = y;
    out.m[2][2] = z;
}



void
MatrixRotationX(Matrix &out, float theta)
{
    MatrixIdentity(out);

    theta *= 3.141592653589793f / 180;

    out.m[1][1] = (float)cos(theta);
    out.m[2][2] = out.m[1][1];
    out.m[2][1] = (float)sin(theta);
    out.m[1][2] = -out.m[2][1];
}



void
MatrixRotationY(Matrix &out, float theta)
{
    MatrixIdentity(out);

    theta *= 3.141592653589793f / 180;

    out.m[0][0] = (float)cos(theta);
    out.m[2][2] = out.m[0][0];
    out.m[0][2] = (float)sin(theta);
    out.m[2][0] = -out.m[0][2];
}



void
MatrixRotationZ(Matrix &out, float theta)
{
    MatrixIdentity(out);

    theta *= 3.141592653589793f / 180;

    out.m[0][0] = (float)cos(theta);
    out.m[1][1] = out.m[0][0];
    out.m[0][1] = (float)sin(theta);
    out.m[1][0] = -out.m[0][1];
}



// Return MatrixRotationX(rX) * MatrixRotationY(rY) * MatrixRotationZ(rZ)
// quickly (without actually doing two complete matrix multiplies), by removing the
// parts of the matrix multiplies that we know will be 0.
void
MatrixRotationXYZ(Matrix &out, float rx, float ry, float rz)
{
    rx *= 3.141592653589793f / 180;
    ry *= 3.141592653589793f / 180;
    rz *= 3.141592653589793f / 180;

    float cx = (float)cos(rx);
    float sx = (float)sin(rx);
    float cy = (float)cos(ry);
    float sy = (float)sin(ry);
    float cz = (float)cos(rz);
    float sz = (float)sin(rz);

    out.m[0][0] = cz * cy;
    out.m[0][1] = cz * sy * sx + sz * cx;
    out.m[0][2] = cz * sy * cx - sz * sx;
    out.m[0][3] = 0;
    out.m[1][0] = -sz * cy;
    out.m[1][1] = -sz * sy * sx + cz * cx;
    out.m[1][2] = -sz * sy * cx - cz * sx;
    out.m[1][3] = 0;
    out.m[2][0] = -sy;
    out.m[2][1] = cy * sx;
    out.m[2][2] = cy * cx;
    out.m[2][3] = 0;
    out.m[3][0] = 0;
    out.m[3][1] = 0;
    out.m[3][2] = 0;
    out.m[3][3] = 1;
}



Matrix
LookAt(float eyex,    float eyey,    float eyez,
       float centerx, float centery, float centerz,
       float upx,     float upy,     float upz)
{
    Vector3 z(eyex - centerx, eyey - centery, eyez - centerz);
    Vector3Normalize(z, z);

    Vector3 x(
          upy * z[2] -  upz * z[1],
         -upx * z[2] +  upz * z[0],
          upx * z[1] -  upy * z[0]);

    Vector3 y(
         z[1] * x[2] - z[2] * x[1],
        -z[0] * x[2] + z[2] * x[0],
         z[0] * x[1] - z[1] * x[0]);

    Vector3Normalize(x, x);
    Vector3Normalize(y, y);

    Matrix mat(
        x[0], y[0], z[0], 0,
        x[1], y[1], z[1], 0,
        x[2], y[2], z[2], 0,
        0,    0,    0,    1);

    Matrix mat2;
    MatrixTranslation(mat2, -eyex, -eyey, -eyez);

    Matrix ret;
    MatrixMultiply(ret, mat, mat2);

    return ret;
}



void
MatrixMultiply(Matrix &out, const Matrix &a, const Matrix &b)
{
    out = Matrix(
        b.m[0][0] * a.m[0][0] + b.m[0][1] * a.m[1][0] + b.m[0][2] * a.m[2][0] + b.m[0][3] * a.m[3][0],
        b.m[0][0] * a.m[0][1] + b.m[0][1] * a.m[1][1] + b.m[0][2] * a.m[2][1] + b.m[0][3] * a.m[3][1],
        b.m[0][0] * a.m[0][2] + b.m[0][1] * a.m[1][2] + b.m[0][2] * a.m[2][2] + b.m[0][3] * a.m[3][2],
        b.m[0][0] * a.m[0][3] + b.m[0][1] * a.m[1][3] + b.m[0][2] * a.m[2][3] + b.m[0][3] * a.m[3][3],
        b.m[1][0] * a.m[0][0] + b.m[1][1] * a.m[1][0] + b.m[1][2] * a.m[2][0] + b.m[1][3] * a.m[3][0],
        b.m[1][0] * a.m[0][1] + b.m[1][1] * a.m[1][1] + b.m[1][2] * a.m[2][1] + b.m[1][3] * a.m[3][1],
        b.m[1][0] * a.m[0][2] + b.m[1][1] * a.m[1][2] + b.m[1][2] * a.m[2][2] + b.m[1][3] * a.m[3][2],
        b.m[1][0] * a.m[0][3] + b.m[1][1] * a.m[1][3] + b.m[1][2] * a.m[2][3] + b.m[1][3] * a.m[3][3],
        b.m[2][0] * a.m[0][0] + b.m[2][1] * a.m[1][0] + b.m[2][2] * a.m[2][0] + b.m[2][3] * a.m[3][0],
        b.m[2][0] * a.m[0][1] + b.m[2][1] * a.m[1][1] + b.m[2][2] * a.m[2][1] + b.m[2][3] * a.m[3][1],
        b.m[2][0] * a.m[0][2] + b.m[2][1] * a.m[1][2] + b.m[2][2] * a.m[2][2] + b.m[2][3] * a.m[3][2],
        b.m[2][0] * a.m[0][3] + b.m[2][1] * a.m[1][3] + b.m[2][2] * a.m[2][3] + b.m[2][3] * a.m[3][3],
        b.m[3][0] * a.m[0][0] + b.m[3][1] * a.m[1][0] + b.m[3][2] * a.m[2][0] + b.m[3][3] * a.m[3][0],
        b.m[3][0] * a.m[0][1] + b.m[3][1] * a.m[1][1] + b.m[3][2] * a.m[2][1] + b.m[3][3] * a.m[3][1],
        b.m[3][0] * a.m[0][2] + b.m[3][1] * a.m[1][2] + b.m[3][2] * a.m[2][2] + b.m[3][3] * a.m[3][2],
        b.m[3][0] * a.m[0][3] + b.m[3][1] * a.m[1][3] + b.m[3][2] * a.m[2][3] + b.m[3][3] * a.m[3][3]
    );
}
