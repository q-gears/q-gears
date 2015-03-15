#include "SkeletonFile.h"
#include "common/Logger.h"



SkeletonFile::SkeletonFile(const Ogre::String& file):
    File( file )
{
}



SkeletonFile::SkeletonFile(File* pFile):
    File(pFile)
{
}



SkeletonFile::SkeletonFile(File* pFile, const u32 offset, const u32 length):
    File(pFile, offset, length)
{
}



SkeletonFile::SkeletonFile(u8* pBuffer, const u32 offset, const u32 length):
    File(pBuffer, offset, length)
{
}



SkeletonFile::~SkeletonFile()
{
}



void
SkeletonFile::GetData( std::vector< s16 >& skeleton_length, const int offset_to_bones, const int number_of_bones, Ogre::SkeletonPtr skeleton )
{
    if (skeleton.isNull() == false)
    {
        Ogre::Bone* root = skeleton->createBone( "0", 0 );
    }

    for( int i = 0; i < number_of_bones; ++i )
    {
        s16 length    = GetU16LE(offset_to_bones + i * 0x04 + 0x00);
        s8  parent_id = GetU8(offset_to_bones + i * 0x04 + 0x02);

        skeleton_length.push_back( length );

        if (skeleton.isNull() == false)
        {
            //LOGGER->Log(LOGGER_INFO, "Skeleton bone-%d length-%d parent-%d part-%d", i, length, parent_id, GetU8(offset_to_bones + i * 0x04 + 0x03));

            Ogre::Bone* bone1 = skeleton->createBone(Ogre::StringConverter::toString(i * 2 + 1), i * 2 + 1);
            Ogre::Bone* bone2 = skeleton->createBone(Ogre::StringConverter::toString(i * 2 + 2), i * 2 + 2);

            if (parent_id == -1)
            {
                skeleton->getBone(0)->addChild(bone1);
            }
            else
            {
                skeleton->getBone(parent_id * 2 + 2)->addChild(bone1);
            }
            bone1->addChild(bone2);
        }
    }
}
