#ifndef TextFILE_H
#define TextFILE_H

#include "../../common/File.h"



class TextFile : public File
{
public:
    TextFile(const Ogre::String& file);
    TextFile(File* pFile);
    TextFile(File* pFile, u32 offset, u32 length);
    TextFile(u8* pBuffer, u32 offset, u32 length);
    virtual ~TextFile();

    void DumpTexts();
};



#endif // TextFILE_H
