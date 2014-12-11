// $Id: RealFileDriver.cpp

#include "RealFileDriver.h"
#include "../../utilites/Logger.h"



RealFileDriver::RealFileDriver(const RString &root):
    mRoot(root)
{
}



RealFileDriver::~RealFileDriver()
{
}



unsigned int
RealFileDriver::GetFileSize(const RString &path)
{
    FILE* file = fopen(RString(mRoot + "/" + path).c_str(), "rb");

    if (file == NULL)
    {
        LOGGER->Log("Can't open file %s", (mRoot + "/" + path).c_str());
        return 0;
    }

    // set cursor to end of file
    fseek(file, 0, SEEK_END);
    unsigned int size = ftell(file);
    fclose(file);
    return size;
}



bool
RealFileDriver::ReadFile(const RString &path, void* buffer, const unsigned int start, const unsigned int length)
{
    FILE* file = fopen(RString(mRoot + "/" + path).c_str(), "rb");

    if (file == NULL)
    {
        LOGGER->Log("Can't open file %s", path.c_str());
        return false;
    }

    fseek(file, start, SEEK_SET);
    fread(buffer, sizeof(char), length, file);
    fclose(file);

    return true;
}



bool
RealFileDriver::WriteFile(const RString &path, const void* buffer, const unsigned int length)
{
    FILE* file = fopen(RString(mRoot + "/" + path).c_str(), "ab");

    if (file == NULL)
    {
        return false;
    }

    fwrite(buffer, sizeof(char), length, file);
    fclose(file);

    return true;
}



bool
RealFileDriver::WriteNewFile(const RString &path, const void* buffer, unsigned int length)
{
    RemoveFile(path);
    return !!(WriteFile(path, buffer, length));
}



bool
RealFileDriver::RemoveFile(const RString &path)
{
    return (remove(path.c_str()) == 0);
}
