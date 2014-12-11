// $Id: NullFileDriver.cpp 147 2007-02-24 06:13:17Z super_gb $

#include "NullFileDriver.h"
#include "../../utilites/Logger.h"



NullFileDriver::NullFileDriver()
{
}



NullFileDriver::~NullFileDriver()
{
}



unsigned int
NullFileDriver::GetFileSize(const RString &path)
{
    LOGGER->Log("Tried to get size of file %s", path.c_str());
    return 0;
}

bool
NullFileDriver::ReadFile(const RString &path, void* buffer, const unsigned int start, const unsigned int length)
{
    LOGGER->Log("Tried to read file %s", path.c_str());
    return false;
}
