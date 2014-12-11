// $Id: RealFileSystem.h 93 2006-11-12 13:49:02Z einherjar $

#ifndef REALFILESYSTEM_H
#define REALFILESYSTEM_H



#include "FileSystem.h"
#include "driver/RealFileDriver.h"
#include "../utilites/StdString.h"
#include <vector>



class RealFileSystem : public FileSystem
{
public:
                         RealFileSystem(const RString &root = ".");
    virtual             ~RealFileSystem();

    virtual unsigned int GetFileSize(const RString& path);
    virtual bool         ReadFile(const RString &path, void* buffer, const unsigned int start, const unsigned int length);
            bool         WriteFile(const RString &path, const void* buffer, const unsigned int length);
            bool         WriteNewFile(const RString &path, const void* buffer, const unsigned int length);
            bool         RemoveFile(const RString &path);

protected:
    RealFileDriver mRealFileDriver;
};



extern RealFileSystem *REALFILESYSTEM;



#endif // REALFILESYSTEM_H
