// $Id: Surface.cpp 109 2006-12-13 22:42:47Z gigaherz $

#include "Surface.h"

#ifdef WIN32
#include <windows.h>
#endif
#include <memory.h>



Surface::Surface():
    pixels(NULL),
    width(0),
    height(0)
{
}



Surface::Surface(const Surface &copy):
    pixels(NULL),
    width(copy.width),
    height(copy.height)
{
    if (width && height)
    {
        pixels = new unsigned char[width * height * 4];
        memcpy(pixels, copy.pixels, width * height * 4);
    }
}



Surface&
Surface::operator =(const Surface &copy)
{
    if (width && height)
    {
        delete[] pixels;
    }

    if (copy.width && copy.height)
    {
        width  = copy.width;
        height = copy.height;

        pixels = new unsigned char[width * height * 4];
        memcpy(pixels, copy.pixels, width * height * 4);
    }

    return *this;
}



Surface::~Surface()
{
    if (width && height)
    {
        delete[] pixels;
    }
}



Surface*
CreateSurface(const int width, const int height)
{
    Surface* image = new Surface();

    image->width   = width;
    image->height  = height;
    image->pixels  = new unsigned char[width * height * 4];

    return image;
}



void
CopyToSurface(Surface* dest, const int x_d, const int y_d, Surface* src)
{
    if (dest == NULL || src == NULL)
    {
        return;
    }

    for (int y_from = y_d, y_to = y_d + src->height; y_from < y_to; ++y_from)
    {
        memcpy(dest->pixels + y_from * dest->width * 4 + x_d * 4, src->pixels + (y_from - y_d) * src->width * 4, src->width * 4);
    }
}



Surface*
CreateSubSurface(const int x, const int y, const int width, const int height, Surface* surface)
{
    Surface* image = CreateSurface(width, height);

    if (surface != NULL)
    {
        for (int y_from = y, y_to = y + image->height; y_from < y_to; ++y_from)
        {
            memcpy(image->pixels + (y_from - y) * image->width * 4, surface->pixels + (y_from * surface->width + x) * 4, image->width * 4);
        }
    }

    return image;
}



Surface*
CreateSurfaceFrom(const int width, const int height, unsigned char* pixels)
{
    Surface* image = CreateSurface(width, height);

    if (pixels != NULL)
    {
        memcpy(image->pixels, pixels, width * height * 4);
    }

    return image;
}



void
SetSurfaceSize(Surface* &surface, const int &width, const int &height)
{
    unsigned char* pixels = new unsigned char[width * height * 4];
    memset(pixels, 0x00, width * height * 4);

    for (int y = 0; y < height; y++)
    {
        if (y < surface->height)
        {
            int size_to_copy = (surface->width < width) ? surface->width * 4 : width * 4 ;
            memcpy(pixels + y * width * 4, surface->pixels + y * surface->width * 4, size_to_copy);
        }
    }

    delete surface;
    surface = CreateSurfaceFrom(width, height, pixels);

    delete[] pixels;
}
