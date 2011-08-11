#ifndef MESH_FILE_H
#define MESH_FILE_H

#include <Ogre.h>

#include "BsxFile.h"
#include "../../common/File.h"



class MeshFile : public File
{
public:
    explicit     MeshFile(const Ogre::String& file);
    explicit     MeshFile(File* pFile);
                 MeshFile(File* pFile, const u32 offset, const u32 length);
                 MeshFile(u8* pBuffer, const u32 offset, const u32 length);
    virtual     ~MeshFile();

    void         GetData(const Ogre::String& name, const int offset_to_parts, const int number_of_parts, Ogre::MeshPtr mesh, VectorTexForGenBsx& textures);

    void         AddTexture( TexForGenBsx& texture, VectorTexForGenBsx& textures );

private:
    int offset_to_4;
    int offset_to_5;
};



#endif // NESH_FILE_h
