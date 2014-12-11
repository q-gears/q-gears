#ifndef LZS_FILE_H
#define LZS_FILE_H

#include "common/File.h"
#include "common/TypeDefine.h"
#include <vector>

class LzsFile : public File
{
public:
    LzsFile(const Ogre::String& file);
    LzsFile(File* pFile);
    LzsFile(File* pFile, u32 offset, u32 length);
    LzsFile(const u8* pBuffer, u32 offset, u32 length);
    virtual ~LzsFile();

private:
    void ExtractLzs();
    friend class LzsBuffer;
};

class LzsBuffer
{
public:
    LzsBuffer() = delete;
    static std::vector<QGears::uint8> Decompress(const std::vector<QGears::uint8>& buffer);
};


#endif // LZS_FILE_H
