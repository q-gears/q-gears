#ifndef FILESYSTEM_H
#define FILESYSTEM_H



#include <OgreString.h>



class FileSystem
{
public:
                         FileSystem();
    virtual             ~FileSystem();

    virtual unsigned int GetFileSize(const Ogre::String& path);
    virtual bool         ReadFile(const Ogre::String &path, void* buffer, const unsigned int start, const unsigned int length);
            bool         WriteFile(const Ogre::String &path, const void* buffer, const unsigned int length);
            bool         WriteNewFile(const Ogre::String &path, const void* buffer, const unsigned int length);
            bool         RemoveFile(const Ogre::String &path);
};



extern FileSystem *FILESYSTEM;



#endif // FILESYSTEM_H
