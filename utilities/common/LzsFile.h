#ifndef LZS_FILE_H
#define LZS_FILE_H

#include "File.h"



class LzsFile : public File
{
public:
    LzsFile(const Ogre::String& file);
    LzsFile(File* pFile);
    LzsFile(File* pFile, u32 offset, u32 length);
    LzsFile(u8* pBuffer, u32 offset, u32 length);
    virtual ~LzsFile();

private:
    void ExtractLzs();
};



#endif // LZS_FILE_H
