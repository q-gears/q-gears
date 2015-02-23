#ifndef SURFACE_H
#define SURFACE_H

#include <Ogre.h>



struct Surface
{
    Surface();
    Surface( const Surface &copy );
    Surface& operator =( const Surface &copy );
    ~Surface();


    std::vector<unsigned char> pixels;
    int            width;
    int            height;
};



Surface* CreateSurface( const int width, const int height );
void     CopyToSurface( Surface* dest, const int x_d, const int y_d, Surface* src );
Surface* CreateSubSurface( const int x, const int y, const int width, const int height, Surface* surface );
Surface* CreateSurfaceFrom( const int width, const int height, unsigned char* pixels );


#endif
