// $Id: NullFileDriver.h 93 2006-11-12 13:49:02Z einherjar $

#ifndef NULLFILEDRIVER_H
#define NULLFILEDRIVER_H


#include "FileDriver.h"
#include "../../utilites/StdString.h"



class NullFileDriver : public FileDriver
{
public:
             NullFileDriver();
    virtual ~NullFileDriver();

    virtual unsigned int GetFileSize(const RString &path);
    virtual bool         ReadFile(const RString &path, void* buffer, const unsigned int start, const unsigned int length);
};



#endif // NULLFILEDRIVER_H
