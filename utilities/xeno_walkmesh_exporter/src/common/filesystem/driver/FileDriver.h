// $Id: FileDriver.h 93 2006-11-12 13:49:02Z einherjar $

#ifndef FILEDRIVER_H
#define FILEDRIVER_H


#include "../../utilites/NoCopy.h"
#include "../../utilites/StdString.h"




class FileDriver : NoCopy<FileDriver>
{
public:
             FileDriver();
    virtual ~FileDriver();

    virtual unsigned int GetFileSize(const RString &path) = 0;
    virtual bool         ReadFile(const RString &path, void* buffer, const unsigned int start, const unsigned int length) = 0;
};



#endif // FILEDRIVER_H
