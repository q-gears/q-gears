// $Id: SurfaceLoadBmp.h 86 2006-10-23 21:44:13Z einherjar $

#ifndef SURFACELOADBMP_H
#define SURFACELOADBMP_H



#include "SurfaceLoad.h"

#include <string>



namespace SurfaceUtils
{
    OpenResult
    LoadBMP(const std::string &file, Surface* &img);
};



#endif
