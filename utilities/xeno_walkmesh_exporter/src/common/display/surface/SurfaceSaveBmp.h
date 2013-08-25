// $Id: SurfaceSaveBmp.h 93 2006-11-12 13:49:02Z einherjar $

#ifndef SURFACESAVEBMP_H
#define SURFACESAVEBMP_H



#include "Surface.h"

#include <string>



namespace SurfaceUtils
{
    bool
    SaveBMP(const std::string &file, Surface* surface);
};



#endif
