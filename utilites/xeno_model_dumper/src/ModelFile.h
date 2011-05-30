#ifndef MODEL_FILE_H
#define MODEL_FILE_H

#include "../../common/File.h"
#include "../../common/Logger.h"
#include "../../common/OgreGenUtilites.h"



class ModelFile : public File
{
public:
    explicit ModelFile(const Ogre::String &file);
    explicit ModelFile(File* file);
    ModelFile(File* file, const u32 &offset, const u32 &length);
    ModelFile(u8* buffer, const u32 &offset, const u32 &length);
    virtual ~ModelFile();

    void GetModel(Ogre::MeshPtr mesh, const MeshData& info, VectorTexForGen& textures, Logger* export_text);

private:
    int LoadPoly010305_18(float*& pPos, float*& tPos, Ogre::RGBA*& cPos, const MeshData& info, VectorTexForGen& textures);
    int LoadPoly04_18(float*& pPos, float*& tPos, Ogre::RGBA*& cPos, const MeshData& info, VectorTexForGen& textures);
    int LoadPoly090d_18(float*& pPos, float*& tPos, Ogre::RGBA*& cPos, const MeshData& info, VectorTexForGen& textures);
    int LoadPoly0c_18(float*& pPos, float*& tPos, Ogre::RGBA*& cPos, const MeshData& info, VectorTexForGen& textures);

    int TexSettings();
    void SetTexPageSettings();
    void SetClutSettings();

    Logger* m_ExportLog;

    int m_LightType;
    int m_PointerToTextureData;
    int m_PointerToMeshData;
    int m_PointerToVertexData;

    u16 m_CurrentClut;
    u16 m_CurrentTexPage;
};



#endif // MODEL_FILE_H
