#ifndef SKELETON_FILE_H
#define SKELETON_FILE_H

#include <Ogre.h>

#include "SkeletonFile.h"
#include "../../common/File.h"



class SkeletonFile : public File
{
public:
    explicit     SkeletonFile(const Ogre::String& file);
    explicit     SkeletonFile(File* pFile);
                 SkeletonFile(File* pFile, const u32 offset, const u32 length);
                 SkeletonFile(u8* pBuffer, const u32 offset, const u32 length);
    virtual     ~SkeletonFile(void);

    void         GetData ( std::vector< s16 >& skeleton_length, const int offset_to_bones, const int number_of_bones, Ogre::SkeletonPtr skeleton );
};



#endif // SKELETON_FILE_H
