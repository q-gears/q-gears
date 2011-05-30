#include "FileSystem.h"
#include "Logger.h"

#include <stdio.h>



FileSystem *FILESYSTEM = NULL;



FileSystem::FileSystem()
{
}



FileSystem::~FileSystem()
{
}



unsigned int
FileSystem::GetFileSize(const Ogre::String &path)
{
    FILE* file = fopen(path.c_str(), "rb");

    if (file == NULL)
    {
        LOGGER->Log("Can't open file " + path + ".\n");
        return 0;
    }

    // set cursor to end of file
    fseek(file, 0, SEEK_END);
    unsigned int size = ftell(file);
    fclose(file);
    return size;
}



bool
FileSystem::ReadFile(const Ogre::String &path, void* buffer, const unsigned int start, const unsigned int length)
{
    FILE* file = fopen(path.c_str(), "rb");

    if (file == NULL)
    {
        LOGGER->Log("Can't open file " + path + ".\n");
        return false;
    }

    fseek(file, start, SEEK_SET);
    fread(buffer, sizeof(char), length, file);
    fclose(file);

    return true;
}



bool
FileSystem::WriteFile(const Ogre::String &path, const void* buffer, const unsigned int length)
{
    FILE* file = fopen(path.c_str(), "ab");

    if (file == NULL)
    {
        return false;
    }

    fwrite(buffer, sizeof(char), length, file);
    fclose(file);

    return true;
}



bool
FileSystem::WriteNewFile(const Ogre::String &path, const void* buffer, unsigned int length)
{
    RemoveFile(path);
    return !!(WriteFile(path, buffer, length));
}



bool
FileSystem::RemoveFile(const Ogre::String &path)
{
    return (remove(path.c_str()) == 0);
}
