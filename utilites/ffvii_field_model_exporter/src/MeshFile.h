#ifndef MESH_FILE_H
#define MESH_FILE_H

#include <Ogre.h>

#include "BsxFile.h"
#include "common/File.h"



class MeshFile : public File
{
public:
    explicit     MeshFile(const Ogre::String& file);
    explicit     MeshFile(File* pFile);
                 MeshFile(File* pFile, const u32 offset, const u32 length);
                 MeshFile(u8* pBuffer, const u32 offset, const u32 length);
    virtual     ~MeshFile();

    Ogre::ColourValue  readColor( const u32 offset );

    void         GetData(const Ogre::String& name, const int offset_to_parts, const int number_of_parts, Ogre::MeshPtr mesh, VectorTexForGenBsx& textures );

    void         AddTexture( TexForGenBsx& texture, VectorTexForGenBsx& textures );

    enum BufferBinding
    {
        POSITION_BINDING = 0x0
      , COLOUR_BINDING   = 0x1
      , TEXTURE_BINDING  = 0x2
      , NORMAL_BINDING   = 0x3
    };

private:
    int offset_to_4;
    int offset_to_5;

    void         readQuad( const u32 offset_to_poly, std::vector<Ogre::Vector3>& vertexes, float* &pPos, u16* &index, u32 &cur_vertex, Ogre::RGBA* &cur_colour, bool multi_color );
    void         readTriangle( const u32 offset_to_poly, std::vector<Ogre::Vector3>& vertexes, float* &pPos, u16* &index, u32 &cur_vertex, Ogre::RGBA* &cur_colour, bool multi_color );
    void         readPart( const Ogre::String& name, const u32 i, const u32 offset_to_part, Ogre::MeshPtr mesh, VectorTexForGenBsx& textures );
};



#endif // NESH_FILE_h
