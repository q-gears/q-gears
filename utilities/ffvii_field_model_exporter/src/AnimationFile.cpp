#include "../../common/Logger.h"
#include "AnimationFile.h"



AnimationFile::AnimationFile(const Ogre::String& file):
    File(file)
{
}



AnimationFile::AnimationFile(File* pFile):
    File(pFile)
{
}



AnimationFile::AnimationFile(File* pFile, const u32 offset, const u32 length):
    File(pFile, offset, length)
{
}



AnimationFile::AnimationFile(u8* pBuffer, const u32 offset, const u32 length):
    File(pBuffer, offset, length)
{
}



AnimationFile::~AnimationFile()
{
}



void
AnimationFile::GetData( std::vector< s16 >& skeleton_length, const Unit& unit, const int offset_to_animations, const int number_of_animation, const int start_animation, Ogre::SkeletonPtr skeleton)
{
    for (int i = 0; i < number_of_animation; ++i)
    {
        /*LOGGER->Log(LOGGER_INFO, "Animation Header %02x%02x %02x %02x %02x %02x %02x%02x %02x%02x %02x%02x %02x%02x%02x%02x",
                    GetU8(offset_to_animations + i * 0x10 + 0x00), GetU8(offset_to_animations + i * 0x10 + 0x01), GetU8(offset_to_animations + i * 0x10 + 0x02), GetU8(offset_to_animations + i * 0x10 + 0x03),
                    GetU8(offset_to_animations + i * 0x10 + 0x04), GetU8(offset_to_animations + i * 0x10 + 0x05), GetU8(offset_to_animations + i * 0x10 + 0x06), GetU8(offset_to_animations + i * 0x10 + 0x07),
                    GetU8(offset_to_animations + i * 0x10 + 0x08), GetU8(offset_to_animations + i * 0x10 + 0x09), GetU8(offset_to_animations + i * 0x10 + 0x0A), GetU8(offset_to_animations + i * 0x10 + 0x0B),
                    GetU8(offset_to_animations + i * 0x10 + 0x0C), GetU8(offset_to_animations + i * 0x10 + 0x0D), GetU8(offset_to_animations + i * 0x10 + 0x0E), GetU8(offset_to_animations + i * 0x10 + 0x0F));
        */
        AnimationHeader header;
        header.number_of_frames                  = GetU16LE(offset_to_animations + i * 0x10 + 0x00);
        header.number_of_bones                   = GetU8(offset_to_animations + i * 0x10 + 0x02);
        header.number_of_frames_translation      = GetU8(offset_to_animations + i * 0x10 + 0x03);
        header.number_of_static_translation      = GetU8(offset_to_animations + i * 0x10 + 0x04);
        header.number_of_frames_rotation         = GetU8(offset_to_animations + i * 0x10 + 0x05);
        header.offset_to_frames_translation_data = GetU16LE(offset_to_animations + i * 0x10 + 0x06);
        header.offset_to_static_translation_data = GetU16LE(offset_to_animations + i * 0x10 + 0x08);
        header.offset_to_frames_rotation_data    = GetU16LE(offset_to_animations + i * 0x10 + 0x0A);
        header.offset_to_animation_data          = GetU32LE(offset_to_animations + i * 0x10 + 0x0C) - 0x80000000;
        m_AnimationHeaders.push_back(header);
    }

    for (size_t i = 0; (i < static_cast<size_t>(number_of_animation)) && (start_animation + i < unit.animations.size()); ++i)
    {
        if (unit.animations[start_animation + i] == "" || unit.animations[start_animation + i] == " ")
        {
            continue;
        }

        /*
        File file(mpBuffer, m_AnimationHeaders[i].offset_to_animation_data, 0x04 + m_AnimationHeaders[i].number_of_bones * 0x08 + m_AnimationHeaders[i].number_of_frames_translation * m_AnimationHeaders[i].number_of_frames * 0x02 + m_AnimationHeaders[i].number_of_static_translation * 0x02 + m_AnimationHeaders[i].number_of_frames_rotation * m_AnimationHeaders[i].number_of_frames);
        file.WriteFile(RString((Ogre::String("dump/") + Ogre::String("animation_") + Ogre::StringConverter::toString(i) + Ogre::String("_data")).c_str()));
        */

        Ogre::Animation* anim = skeleton->createAnimation(unit.animations[start_animation + i], (float)(m_AnimationHeaders[i].number_of_frames - 1) / 30.0f);

        for (u32 j = 0; j < m_AnimationHeaders[i].number_of_frames; ++j)
        {
            Frame frame;

            // root bone
            Ogre::Bone* root = skeleton->getBone(0);

            Ogre::NodeAnimationTrack* track;
            if (j == 0)
            {
                track = anim->createNodeTrack(0, root);
                track->removeAllKeyFrames();
            }
            else
            {
                track = anim->getNodeTrack(0);
            }

            Ogre::TransformKeyFrame* frame_root = track->createNodeKeyFrame((float)j / 30.0f);

            Ogre::Quaternion rot;
            Ogre::Matrix3 mat;
            mat.FromEulerAnglesZXY(Ogre::Radian(Ogre::Degree(180)), Ogre::Radian(Ogre::Degree(0)), Ogre::Radian(Ogre::Degree(0)));
            rot.FromRotationMatrix(mat);
            frame_root->setRotation(rot);

            for (u32 k = 0; k < m_AnimationHeaders[i].number_of_bones; ++k)
            {
                BonePosition position;

                u8 flag = GetU8(m_AnimationHeaders[i].offset_to_animation_data + 0x04 + k * 0x08 + 0x00);

                u8 rx = GetU8(m_AnimationHeaders[i].offset_to_animation_data + 0x04 + k * 0x08 + 0x01);
                u8 ry = GetU8(m_AnimationHeaders[i].offset_to_animation_data + 0x04 + k * 0x08 + 0x02);
                u8 rz = GetU8(m_AnimationHeaders[i].offset_to_animation_data + 0x04 + k * 0x08 + 0x03);
                u8 tx = GetU8(m_AnimationHeaders[i].offset_to_animation_data + 0x04 + k * 0x08 + 0x04);
                u8 ty = GetU8(m_AnimationHeaders[i].offset_to_animation_data + 0x04 + k * 0x08 + 0x05);
                u8 tz = GetU8(m_AnimationHeaders[i].offset_to_animation_data + 0x04 + k * 0x08 + 0x06);

                // rotation
                if (flag & 0x01)
                {
                    position.rotation_x = 360.0f * GetU8(m_AnimationHeaders[i].offset_to_animation_data + m_AnimationHeaders[i].offset_to_frames_rotation_data + rx * m_AnimationHeaders[i].number_of_frames + j) / 255.0f;
                }
                else
                {
                    position.rotation_x = 360.0f * rx / 255.0f;
                }

                if (flag & 0x02)
                {
                    position.rotation_y = 360.0f * GetU8(m_AnimationHeaders[i].offset_to_animation_data + m_AnimationHeaders[i].offset_to_frames_rotation_data + ry * m_AnimationHeaders[i].number_of_frames + j) / 255.0f;
                }
                else
                {
                    position.rotation_y = 360.0f * ry / 255.0f;
                }

                if (flag & 0x04)
                {
                    position.rotation_z = 360.0f * GetU8(m_AnimationHeaders[i].offset_to_animation_data + m_AnimationHeaders[i].offset_to_frames_rotation_data + rz * m_AnimationHeaders[i].number_of_frames + j) / 255.0f;
                }
                else
                {
                    position.rotation_z = 360.0f * rz / 255.0f;
                }

                // translation
                position.translation_x = 0;
                position.translation_y = 0;
                position.translation_z = 0;

                if (flag & 0x10)
                {
                    position.translation_x = static_cast<float>( -(s16)GetU16LE(m_AnimationHeaders[i].offset_to_animation_data + m_AnimationHeaders[i].offset_to_frames_translation_data + tx * m_AnimationHeaders[i].number_of_frames * 2 + j * 2));
                }
                else if (tx != 0xFF)
                {
                    position.translation_x = static_cast<float>(-(s16)GetU16LE(m_AnimationHeaders[i].offset_to_animation_data + m_AnimationHeaders[i].offset_to_static_translation_data + tx * 2));
                }

                if (flag & 0x20)
                {
                    position.translation_y = static_cast<float>(-(s16)GetU16LE(m_AnimationHeaders[i].offset_to_animation_data + m_AnimationHeaders[i].offset_to_frames_translation_data + ty * m_AnimationHeaders[i].number_of_frames * 2 + j * 2));
                }
                else if (ty != 0xFF)
                {
                    position.translation_y = static_cast<float>(-(s16)GetU16LE(m_AnimationHeaders[i].offset_to_animation_data + m_AnimationHeaders[i].offset_to_static_translation_data + ty * 2));
                }

                if (flag & 0x40)
                {
                    position.translation_z = static_cast<float>(-(s16)GetU16LE(m_AnimationHeaders[i].offset_to_animation_data + m_AnimationHeaders[i].offset_to_frames_translation_data + tz * m_AnimationHeaders[i].number_of_frames * 2 + j * 2));
                }
                else if (tz != 0xFF)
                {
                    position.translation_z = static_cast<float>(-(s16)GetU16LE(m_AnimationHeaders[i].offset_to_animation_data + m_AnimationHeaders[i].offset_to_static_translation_data + tz * 2));
                }

                //LOGGER->Log(LOGGER_INFO, "%d %d", m_AnimationHeaders[i].number_of_frames, j);
                //LOGGER->Log(LOGGER_INFO, "animation (%f %f %f) (%f %f %f)", position.rotation_x, position.rotation_y, position.rotation_z, position.translation_x, position.translation_y, position.translation_z);

                frame.bone.push_back(position);

                Ogre::Bone* bone1 = skeleton->getBone(k * 2 + 1);
                Ogre::Bone* bone2 = skeleton->getBone(k * 2 + 2);

                Ogre::NodeAnimationTrack* track1;
                Ogre::NodeAnimationTrack* track2;
                if (j == 0)
                {
                    track1 = anim->createNodeTrack(k * 2 + 1, bone1);
                    track1->removeAllKeyFrames();
                    track2 = anim->createNodeTrack(k * 2 + 2, bone2);
                    track2->removeAllKeyFrames();
                }
                else
                {
                    track1 = anim->getNodeTrack(k * 2 + 1);
                    track2 = anim->getNodeTrack(k * 2 + 2);
                }

                Ogre::TransformKeyFrame* frame1 = track1->createNodeKeyFrame((float)j / 30.0f);
                Ogre::TransformKeyFrame* frame2 = track2->createNodeKeyFrame((float)j / 30.0f);

                float length = skeleton_length[ k ];

                frame1->setTranslate(Ogre::Vector3(position.translation_x, position.translation_z - length, position.translation_y) / 1024);

                Ogre::Quaternion rot;
                Ogre::Matrix3 mat;
                mat.FromEulerAnglesZXY(Ogre::Radian(Ogre::Degree(-position.rotation_y)), Ogre::Radian(Ogre::Degree(-position.rotation_x)), Ogre::Radian(Ogre::Degree(-position.rotation_z)));
                rot.FromRotationMatrix(mat);
                frame2->setRotation(rot);
            }
        }
    }
}
