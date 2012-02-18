#ifndef MODEL_FILE_H
#define MODEL_FILE_H

#include "../../common/File.h"
#include "../../common/OgreGenUtilites.h"



struct ModelInfo
{
    MeshData                  data;
    Ogre::String              file_name;
    std::vector<Ogre::String> animations;
};



struct Bone
{
    int length;
    int parent_id;

    float tx, ty, tz;
    float rx, ry, rz;
};
typedef std::vector< Bone > Skeleton;



class ModelFile : public File
{
public:
    ModelFile( const Ogre::String& file );
    ModelFile( File* pFile );
    ModelFile( File* pFile, u32 offset, u32 length );
    ModelFile( u8* pBuffer, u32 offset, u32 length );
    virtual ~ModelFile();

    Ogre::Entity* GetModel( const ModelInfo& info );

    Skeleton m_Skeleton;
};



#endif // MODEL_FILE_H
