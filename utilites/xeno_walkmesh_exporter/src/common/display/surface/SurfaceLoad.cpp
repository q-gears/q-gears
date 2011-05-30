// $Id: SurfaceLoad.cpp 147 2007-02-24 06:13:17Z super_gb $

#include "SurfaceLoad.h"
#include "SurfaceLoadBmp.h"
#include "../../utilites/Logger.h"

#include <set>



static Surface*
TryOpenFile(const std::string &file)
{
    Surface* ret = NULL;
    SurfaceUtils::OpenResult result;

    result = SurfaceUtils::LoadBMP(file, ret);

    if (result == SurfaceUtils::OPEN_OK)
    {
        return ret;
    }

    LOGGER->Log(LOGGER_ERROR, "File %s failed to open.", file.c_str());

    return NULL;
}


Surface*
SurfaceUtils::LoadFile(const std::string &file)
{
    Surface* image = TryOpenFile(file);
    if (image)
    {
        return image;
    }

    return NULL;
}
