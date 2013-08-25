#ifndef ENEMY_FILE_H
#define ENEMY_FILE_H

#include "MeshExtractor.h"
#include "../../common/LzsFile.h"
#include "../../common/Vram.h"
#include "../../common/OgreGenUtilites.h"



struct EnemyInfo
{
    MeshData                  data;
    Ogre::String              file_name;
    std::vector<Ogre::String> animations;
};



struct Bone
{
    int length;
    int parent_id;
    int offset;

    float tx, ty, tz;
    float rx, ry, rz;
};
typedef std::vector<Bone> Skeleton;



class EnemyFile : public LzsFile
{
public:
    EnemyFile(const Ogre::String& file);
    EnemyFile(File* pFile);
    EnemyFile(File* pFile, u32 offset, u32 length);
    EnemyFile(u8* pBuffer, u32 offset, u32 length);
    virtual ~EnemyFile();

    Ogre::Entity* GetModel(const EnemyInfo& info);
    void          DumpSettings(const Ogre::String& file);

private:
    Skeleton m_Skeleton;
    bool     m_WithWeapon;
};



#endif // BSX_FILE_h
