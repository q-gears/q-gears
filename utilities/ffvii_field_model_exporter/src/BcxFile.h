#ifndef BCX_FILE_H
#define BCX_FILE_H



#include "BsxFile.h"
#include "../../common/LzsFile.h"



class BcxFile : public LzsFile
{
public:
    explicit BcxFile(const Ogre::String& file);
    explicit BcxFile(File* file);
             BcxFile(File* file, const u32 offset, const u32 length);
             BcxFile(u8* buffer, const u32 offset, const u32 length);
    virtual ~BcxFile(void);

    void GetModel( std::vector< s16 >& skeleton_length, const Unit& unit, Ogre::MeshPtr mesh, Ogre::SkeletonPtr skeleton, VectorTexForGenBsx& textures );
    void GetSkeleton( std::vector< s16 >& skeleton_length );
};



#endif // BCX_FILE_h
