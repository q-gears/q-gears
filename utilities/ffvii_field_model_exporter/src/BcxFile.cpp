#include <Ogre.h>
#include <math.h>
#include <vector>

#include "../../common/Logger.h"

#include "AnimationFile.h"
#include "BcxFile.h"
#include "MeshFile.h"
#include "SkeletonFile.h"



BcxFile::BcxFile(const Ogre::String& file):
    LzsFile(file)
{
}



BcxFile::BcxFile(File *file, const u32 offset, const u32 length):
    LzsFile(file, offset, length)
{
}



BcxFile::BcxFile(u8* buffer, const u32 offset, const u32 length):
    LzsFile(buffer, offset, length)
{
}



BcxFile::BcxFile(File *file):
    LzsFile(file)
{
}



BcxFile::~BcxFile()
{
}



void
BcxFile::GetModel( std::vector< s16 >& skeleton_length, const Unit& unit, Ogre::MeshPtr mesh, Ogre::SkeletonPtr skeleton, VectorTexForGenBsx& textures )
{
    u32 offset_to_model_info = GetU32LE(0x04);

    u8 number_of_bones      = GetU8(offset_to_model_info + 0x02);
    u8 number_of_parts      = GetU8(offset_to_model_info + 0x03);
    u8 number_of_animations = GetU8(offset_to_model_info + 0x04);

    //////////////////////////
    // mesh
    //////////////////////////
    u16 offset_to_parts = GetU16LE(offset_to_model_info + 0x1c) + number_of_bones * 4;
    MeshFile file_m(this);
    file_m.GetData(unit.name, offset_to_parts, number_of_parts, mesh, textures);
    //////////////////////////

    //////////////////////////
    // skeleton
    //////////////////////////
    u16 offset_to_bones = GetU16LE(offset_to_model_info + 0x1C);
    SkeletonFile file_s(this);
    file_s.GetData( skeleton_length, offset_to_bones, number_of_bones, skeleton );
    //////////////////////////

    ///////////////////////////////////////////////////
    // animations
    ///////////////////////////////////////////////////
    u32 offset_to_animations = GetU32LE(offset_to_model_info + 0x1C) - 0x80000000 + number_of_bones * 4 + number_of_parts * 0x20;

    AnimationFile afile(this);
    afile.GetData( skeleton_length, unit, offset_to_animations, number_of_animations, 0, skeleton );
}



void
BcxFile::GetSkeleton( std::vector< s16 >& skeleton_length )
{
    u32 offset_to_model_info = GetU32LE(0x04);

    u8 number_of_bones  = GetU8(offset_to_model_info + 0x02);
    u16 offset_to_bones = GetU16LE(offset_to_model_info + 0x1C);
    SkeletonFile file_s(this);
    Ogre::SkeletonPtr skeleton;
    skeleton.setNull();
    file_s.GetData( skeleton_length, offset_to_bones, number_of_bones, skeleton);
}
