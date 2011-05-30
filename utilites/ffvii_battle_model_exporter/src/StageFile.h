#ifndef STAGE_FILE_H
#define STAGE_FILE_H

#include "MeshExtractor.h"
#include "../../common/LzsFile.h"
#include "../../common/Vram.h"
#include "../../common/OgreGenUtilites.h"



struct StageInfo
{
    MeshData                  data;
    Ogre::String              file_name;
};



class StageFile : public LzsFile
{
public:
    StageFile(const Ogre::String& file);
    StageFile(File* pFile);
    StageFile(File* pFile, u32 offset, u32 length);
    StageFile(u8* pBuffer, u32 offset, u32 length);
    virtual ~StageFile();

    Ogre::Entity* GetModel(const StageInfo& info);
    //void          DumpSettings(const Ogre::String& file);
};



#endif // STAGE_FILE_H
