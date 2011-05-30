// $Id: SurfaceLoad.h 93 2006-11-12 13:49:02Z einherjar $

#ifndef SURFACELOAD_H
#define SURFACELOAD_H



#include "Surface.h"

#include <string>



namespace SurfaceUtils
{
    enum OpenResult
    {
        OPEN_OK,
        OPEN_UNKNOWN_FILE_FORMAT = 1,
        OPEN_FATAL_ERROR = 2,
    };

    Surface *LoadFile(const std::string &file);
}



#endif
