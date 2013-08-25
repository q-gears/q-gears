// $Id: 3dTypes.h 103 2006-11-26 07:19:38Z crazy_otaku $

#ifndef _3DTYPES_H
#define _3DTYPES_H
// Few types for 3d render

#include <vector>
#include <string>

#include "math/Vector.h"
#include "math/VectorMath.h"
#include "math/Matrix.h"
#include "math/MatrixMath.h"
#include "../TypeDefine.h"



enum BlendMode
{
    BLEND_DISABLED,
    BLEND_PSX_0,
    BLEND_PSX_1,
    BLEND_PSX_2,
    BLEND_PSX_3
};
enum CullMode    {CULL_BACK,      CULL_FRONT,          CULL_NONE};
enum ZTestMode   {ZTEST_OFF,      ZTEST_WRITE_ON_PASS, ZTEST_WRITE_ON_FAIL};
enum PolygonMode {POLYGON_FILL,   POLYGON_LINE};



struct Color
{
public:
    Color() {}
    Color(const float* f)                         {r = f[0]; g = f[1]; b = f[2]; a = f[3];}
    Color(float r1, float g1, float b1, float a1) {r = r1; g = g1; b = b1; a = a1;}

    // casting
    operator float* ()                            {return &r;};
    operator const float* () const                {return &r;};

    // assignment operators
    Color& operator += (const Color& other)       {r += other.r; g += other.g; b += other.b; a += other.a; return *this;}
    Color& operator -= (const Color& other)       {r -= other.r; g -= other.g; b -= other.b; a -= other.a; return *this;}
    Color& operator *= (const Color& other)       {r *= other.r; g *= other.g; b *= other.b; a *= other.a; return *this;}
    Color& operator *= (float f)                  {r *= f; g *= f; b *= f; a *= f; return *this;}
    Color& operator /= (float f)                  {r /= f; g /= f; b /= f; a /= f; return *this;}

    // binary operators
    Color operator + (const Color& other) const   {return Color(r + other.r, g + other.g, b + other.b, a + other.a);}
    Color operator - (const Color& other) const   {return Color(r - other.r, g - other.g, b - other.b, a - other.a);}
    Color operator * (const Color& other) const   {return Color(r * other.r, g * other.g, b * other.b, a * other.a);}
    Color operator * (float f) const              {return Color(r * f, g * f, b * f, a * f);}
    Color operator / (float f) const              {return Color(r / f, g / f, b / f, a / f);}

    friend Color operator * (float f, const Color& other) {return other * f;}

    bool operator == (const Color& other) const   {return r == other.r && g == other.g && b == other.b && a == other.a;}
    bool operator != (const Color& other) const   {return !operator==(other);}

    bool FromString(const std::string &str)
    {
        int result = sscanf(str.c_str(), "%f,%f,%f,%f", &r, &g, &b, &a);
        if (result == 3)
        {
            a = 1;
            return true;
        }
        if (result == 4)
        {
            return true;
        }

        int ir = 255, ib = 255, ig = 255, ia = 255;
        result = sscanf(str.c_str(), "#%2x%2x%2x%2x", &ir, &ig, &ib, &ia);
        if (result >= 3)
        {
            r = ir / 255.0f; g = ig / 255.0f; b = ib / 255.0f;
            if (result == 4)
            {
                a = ia / 255.0f;
            }
            else
            {
                a = 1;
            }

            return true;
        }

        r = 1; b = 1; g = 1; a = 1;

        return false;
    }

    float r, g, b, a;
};



// Structure for our custom vertex type.
struct Vertex
{
    Vector3     p;  // position
    Vector3     n;  // normal
    Color       c;  // color
    Vector2     t;  // texture coordinates
};



struct Geometry
{
    Geometry():
        blend(BLEND_PSX_0),
        texture_enabled(false)
    {
    }

    std::vector<Vertex> vertexes;
    BlendMode           blend;  // blend mode
    Uint32              texture_index;
    bool                texture_enabled;
};



struct TotalGeometry
{
    std::vector<Geometry> triangles;
    std::vector<Geometry> quads;
};



#endif // _3DTYPES_H
