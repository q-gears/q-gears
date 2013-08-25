#ifndef BSX_FILE_H
#define BSX_FILE_H

#include <Ogre.h>

#include "DatFile.h"
#include "../../common/LzsFile.h"
#include "../../common/Vram.h"
#include "../../common/OgreGenUtilites.h"



struct Unit
{
    Ogre::String name;
    std::vector<Ogre::String> animations;
};

struct Field
{
    Ogre::String name;
    std::vector< Unit > units;
};

struct TexForGenBsx: TexForGen
{
    int type;

    bool operator==( const TexForGenBsx& i ) const
    {
        return i.texture_x == texture_x &&
               i.texture_y == texture_y &&
               i.palette_y == palette_y &&
               i.palette_x == palette_x &&
               i.bpp       == bpp &&
             ( i.type == type || ( i.type < 2 && type < 2 ) );
    }
};

typedef std::vector< TexForGenBsx > VectorTexForGenBsx;



class BsxFile : public LzsFile
{
public:
    explicit     BsxFile(const Ogre::String& file);
    explicit     BsxFile(File* pFile);
                 BsxFile(File* pFile, const u32 offset, const u32 length);
                 BsxFile(u8* pBuffer, const u32 offset, const u32 length);
    virtual     ~BsxFile();

    Ogre::Entity* GetModel(Ogre::Entity* entity, const s8 character_id, const Unit& unit, const DatModelData dat);
    void         CreateTexture(const Ogre::String& name, const int face_id, const VectorTexForGenBsx& textures);
    void         ReadBSXTextureToVram();

private:
    Vram m_Vram;
};



#endif // BSX_FILE_h
