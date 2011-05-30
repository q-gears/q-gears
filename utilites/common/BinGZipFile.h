#ifndef BIN_G_ZIP_FILE_H
#define BIN_G_ZIP_FILE_H

#include "File.h"



class BinGZipFile : public File
{
public:
    BinGZipFile(const Ogre::String& file);
    BinGZipFile(File* pFile);
    BinGZipFile(File* pFile, u32 offset, u32 length);
    BinGZipFile(u8* pBuffer, u32 offset, u32 length);
    virtual ~BinGZipFile();

    File* ExtractGZip(u32 fileNumber);
    u32 GetNumberOfFiles();

private:
    void InnerGetNumberOfFiles();
    u32 InnerGetFileOffset(u32 fileNumber);

private:
    u32 m_NumberOfFiles;
};



#endif // BIN_G_ZIP_FILE_H
