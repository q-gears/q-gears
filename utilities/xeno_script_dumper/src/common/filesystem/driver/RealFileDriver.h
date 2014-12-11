// $Id: RealFileDriver.h

#ifndef REALFILEDRIVER_H
#define REALFILEDRIVER_H

#include "FileDriver.h"
#include "../../utilites/StdString.h"



class RealFileDriver : public FileDriver
{
public:
             RealFileDriver(const RString &root);
    virtual ~RealFileDriver();

    virtual unsigned int GetFileSize(const RString &path);
    virtual bool         ReadFile(const RString &path, void* buffer, const unsigned int start, const unsigned int length);

            bool         WriteFile(const RString &path, const void* buffer, const unsigned int length);
            bool         WriteNewFile(const RString &path, const void* buffer, const unsigned int length);
            bool         RemoveFile(const RString &path);

 protected:
    const RString mRoot;
};



#endif // REALFILEDRIVER_H
