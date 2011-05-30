#ifndef RAM_EFFECT_FILE_h
#define RAM_EFFECT_FILE_h

#include "MeshExtractor.h"
#include "../../common/File.h"



struct EffectInfo
{
    MeshData data;
    int      offset;
};



class RamEffectFile : public File
{
public:
    RamEffectFile(const Ogre::String& file);
    RamEffectFile(File* pFile);
    RamEffectFile(File* pFile, u32 offset, u32 length);
    RamEffectFile(u8* pBuffer, u32 offset, u32 length);
    virtual ~RamEffectFile();

    Ogre::Entity* GetModel(const EffectInfo info);
};



#endif // RAM_EFFECT_FILE_h
