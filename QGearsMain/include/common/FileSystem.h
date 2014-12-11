#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <OgreString.h>

class FileSystem
{
public:
    FileSystem() = delete;
    static unsigned int GetFileSize(const Ogre::String& path);
    static bool         ReadFile(const Ogre::String &path, void* buffer, const unsigned int start, const unsigned int length);
    static bool         WriteFile(const Ogre::String &path, const void* buffer, const unsigned int length);
    static bool         WriteNewFile(const Ogre::String &path, const void* buffer, const unsigned int length);
    static bool         RemoveFile(const Ogre::String &path);
};

#endif // FILESYSTEM_H
