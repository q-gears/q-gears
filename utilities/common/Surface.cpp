#include "Surface.h"

#ifdef WIN32
    #include <windows.h>
#endif
#include <memory.h>



Surface::Surface():
    pixels( NULL ),
    width( 0 ),
    height( 0 )
{
}



Surface::Surface( const Surface &copy ):
    pixels( NULL ),
    width( copy.width ),
    height( copy.height )
{
    if( width && height )
    {
        pixels = copy.pixels;
    }
}



Surface&
Surface::operator =( const Surface &copy )
{
    if( copy.width && copy.height )
    {
        width  = copy.width;
        height = copy.height;

        pixels = copy.pixels;
    }

    return *this;
}



Surface::~Surface()
{

}



Surface*
CreateSurface( const int width, const int height )
{
    Surface* image = new Surface();

    image->width   = width;
    image->height  = height;
    image->pixels.resize( width * height * 4 );

    return image;
}



void
CopyToSurface( Surface* dest, const int x_d, const int y_d, Surface* src )
{
    if( dest == NULL || src == NULL )
    {
        return;
    }

    for( int y_from = y_d, y_to = y_d + src->height; y_from < y_to; ++y_from )
    {
        memcpy( dest->pixels.data() + y_from * dest->width * 4 + x_d * 4, src->pixels.data() + ( y_from - y_d ) * src->width * 4, src->width * 4 );
    }
}



Surface*
CreateSubSurface( const int x, const int y, const int width, const int height, Surface* surface )
{
    Surface* image = CreateSurface( width, height );

    if( surface != NULL )
    {
        for( int y_from = y, y_to = y + image->height; y_from < y_to; ++y_from )
        {
            memcpy( image->pixels.data() + ( y_from - y ) * image->width * 4, surface->pixels.data() + ( y_from * surface->width + x ) * 4, image->width * 4) ;
        }
    }

    return image;
}



Surface*
CreateSurfaceFrom( const int width, const int height, unsigned char* pixels )
{
    Surface* image = CreateSurface( width, height );
    if( pixels != NULL )
    {
        memcpy( image->pixels.data(), pixels, width * height * 4 );
    }
    return image;
}
