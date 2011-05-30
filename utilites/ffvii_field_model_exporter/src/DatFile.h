#ifndef DATFILE_H
#define DATFILE_H

#include "../../common/LzsFile.h"



struct DatModelData
{
    int face_id;
    int number_of_bones;
    int number_of_parts;
    int number_of_animation;
    int global_model_id;
};



class DatFile : public LzsFile
{
public:
    explicit DatFile(const Ogre::String& file);
    explicit DatFile(File* file);
    DatFile(File* file, const u32 offset, const u32 length);
    DatFile(u8* buffer, const u32 offset, const u32 length);
    virtual ~DatFile();

    void GetModelData(const int model_id, DatModelData& data);
};



#endif // DATFILE_H
