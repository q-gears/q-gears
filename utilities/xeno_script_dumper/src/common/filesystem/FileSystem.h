// $Id: FileSystem.h 93 2006-11-12 13:49:02Z einherjar $

#ifndef FILESYSTEM_H
#define FILESYSTEM_H



#include "../utilites/NoCopy.h"
#include "../utilites/StdString.h"

#include <vector>



class FileSystem : public NoCopy<FileSystem>
{
public:
                         FileSystem();
    virtual             ~FileSystem();

    virtual unsigned int GetFileSize(const RString &path) = 0;
    virtual bool         ReadFile(const RString &path, void* buffer, const unsigned int start, const unsigned int length) = 0;
};



#endif // FILESYSTEM_H
