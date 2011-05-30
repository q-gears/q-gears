// $Id: Surface.h 103 2006-11-26 07:19:38Z crazy_otaku $

#ifndef SURFACE_H
#define SURFACE_H



struct Surface
{
    Surface();
    Surface(const Surface &copy);
    Surface& operator =(const Surface &copy);
    ~Surface();


    unsigned char *pixels;
    int            width;
    int            height;
};



Surface* CreateSurface(const int width, const int height);
void     CopyToSurface(Surface* dest, const int x_d, const int y_d, Surface* src);
Surface* CreateSubSurface(const int x, const int y, const int width, const int height, Surface* surface);
Surface* CreateSurfaceFrom(const int width, const int height, unsigned char* pixels);

void     SetSurfaceSize(Surface* &surface, const int &width, const int &height);



#endif
