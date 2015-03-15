#include "AnimationExtractor.h"

#include "../../common/Logger.h"



float
ReadBitStream(File* file, const int offset, int &readed_bits, const int bit_to_read, const int real_size)
{
    int ret = 0;

    for (int i = 0; i < bit_to_read; ++i)
    {
        ret <<= 1;

        // read new bit
        int byte = file->GetU8(offset + (readed_bits / 8));
        //LOGGER->Log(LOGGER_INFO, "ReadBitStream data = %02x readed_bits = %02x", byte, readed_bits);
        if ((byte >> (7 - (readed_bits & 7))) & 1)
        {
            ret |= 1;
        }

        readed_bits += 1;
    }

    // force the sign bit to extend across the 32-bit boundary.
    ret <<= (0x20 - bit_to_read);
    ret >>= (0x20 - bit_to_read);
    // extend compressed value
    ret <<= (real_size - bit_to_read);
    return (float)ret;
}



float
ReadDynamicFrameOffsetBits(File* file, const int offset, int &readed_bits)
{
    int readed_bytes = readed_bits / 8;
    int bit_in_byte = readed_bits & 7;
    int data = (file->GetU8(offset + readed_bytes + 0) << 8) | file->GetU8(offset + readed_bytes + 1);
    //LOGGER->Log(LOGGER_INFO, "ReadDynamicFrameOffsetBits data = %04x (bit_in_byte %02x)", data, bit_in_byte);
    if ((data & (1 << (15 - bit_in_byte))) != 0)
    {
        // 16 bit value
        data <<= 8;
        //LOGGER->Log(LOGGER_INFO, "ReadDynamicFrameOffsetBits 16bit = %04x", data);
        data |= file->GetU8(offset + readed_bytes + 2);
        //LOGGER->Log(LOGGER_INFO, "ReadDynamicFrameOffsetBits 16bit = %04x", data);
        data <<= (bit_in_byte + 9);
        //LOGGER->Log(LOGGER_INFO, "ReadDynamicFrameOffsetBits 16bit = %04x", data);
        data >>= 0x10;
        //LOGGER->Log(LOGGER_INFO, "ReadDynamicFrameOffsetBits 16bit = %04x", data);
        readed_bits += 17;
    }
    else
    {
        // 7 bit value
        data <<= (bit_in_byte + 0x11);
        data >>= 0x19;
        //LOGGER->Log(LOGGER_INFO, "ReadDynamicFrameOffsetBits 7bit = %d", data);
        readed_bits += 8;
    }

    //LOGGER->Log(LOGGER_INFO, "ReadDynamicFrameOffsetBits = %d", data);
    return (float)data;
}



float
ReadEncryptedRotationBits(File* file, const int offset, int &readed_bits, const int compression)
{
    int ret = 0;

    int control_bit = static_cast<int>(ReadBitStream(file, offset, readed_bits, 1, 1));
    //LOGGER->Log(LOGGER_INFO, "ReadEncryptedRotationBits control_bit = %x", control_bit);
    if (control_bit != 0)
    {
        control_bit = static_cast<int>(ReadBitStream(file, offset, readed_bits, 3, 3));
        control_bit &= 7;
        //LOGGER->Log(LOGGER_INFO, "ReadEncryptedRotationBits control_bit = %x", control_bit);
        if (control_bit == 0)
        {
            ret = -1;
        }
        else if (control_bit == 7)
        {
            ret = static_cast<int>(ReadBitStream(file, offset, readed_bits, 12 - compression, 12));
        }
        else
        {
            int data = static_cast<int>(ReadBitStream(file, offset, readed_bits, control_bit, control_bit));
            //LOGGER->Log(LOGGER_INFO, "ReadEncryptedRotationBits data = %x", data);
            if (data >= 0)
            {
                data += (1 << (control_bit - 1));
            }
            else
            {
                data -= (1 << (control_bit - 1));
            }

            ret = data << (compression + 16);
            ret >>= 16;
        }
    }

    //LOGGER->Log(LOGGER_INFO, "ReadEncryptedRotationBits = %x", ret);
    return (float)ret;
}



void
AnimationExtractor(File* file, const Ogre::SkeletonPtr& skeleton, const EnemyInfo& info, Skeleton& skeleton_data, bool with_weapon)
{
    float weapon_tx, weapon_ty, weapon_tz, weapon_rx, weapon_ry, weapon_rz = 0;

    for (size_t i = 0; i < info.animations.size(); ++i)
    {
        if (info.animations[i] == "")
        {
            continue;
        }
        LOGGER->Log("AnimationExtractor:" + Ogre::StringConverter::toString(i) + " " + info.animations[i] + "\n");
        int offset_to_animation = file->GetU32LE(0x0c + i * 0x04);
        int offset_to_animation_weapon = 0;
        if (with_weapon)
        {
            offset_to_animation_weapon = file->GetU32LE(0x4c + i * 0x04);
        }
        int number_of_frames = file->GetU16LE(offset_to_animation + 0x0);
        int compression = file->GetU8(offset_to_animation + 0x4);
        int compression_weapon = 0;
        if (with_weapon)
        {
            compression_weapon = file->GetU8(offset_to_animation_weapon + 0x4);
        }

        Ogre::Animation* anim = skeleton->createAnimation(info.animations[i], (number_of_frames - 1) / 10.0f);

        float time = 0;
        int readed_bits = 0;
        int readed_bits_weapon = 0;

        float tx, ty, tz;
        Ogre::Bone* bone1;
        Ogre::Bone* bone2;
        Ogre::NodeAnimationTrack* track1;
        Ogre::NodeAnimationTrack* track2;
        Ogre::TransformKeyFrame* frame1;
        Ogre::TransformKeyFrame* frame2;
        Ogre::Quaternion rot;
        Ogre::Matrix3 mat;

        for (int frame = 0; frame < number_of_frames; ++frame)
        {
            if (readed_bits == 0)
            {
                tx = ReadBitStream(file, offset_to_animation + 5, readed_bits, 16, 16);
                ty = ReadBitStream(file, offset_to_animation + 5, readed_bits, 16, 16);
                tz = ReadBitStream(file, offset_to_animation + 5, readed_bits, 16, 16);
                // skip first rotation
                ReadBitStream(file, offset_to_animation + 5, readed_bits, 12 - compression, 12);
                ReadBitStream(file, offset_to_animation + 5, readed_bits, 12 - compression, 12);
                ReadBitStream(file, offset_to_animation + 5, readed_bits, 12 - compression, 12);

                bone1 = skeleton->getBone(0);
                track1 = anim->createNodeTrack(0, bone1);
                track1->removeAllKeyFrames();
                frame1 = track1->createNodeKeyFrame(time);
                mat.FromEulerAnglesYXZ(Ogre::Radian(Ogre::Degree(0)), Ogre::Radian(Ogre::Degree(-90)), Ogre::Radian(Ogre::Degree(0)));
                rot.FromRotationMatrix(mat);
                frame1->setRotation(rot);
                bone2 = skeleton->getBone(1);
                track2 = anim->createNodeTrack(1, bone2);
                track2->removeAllKeyFrames();
                frame2 = track2->createNodeKeyFrame(time);
                frame2->setTranslate(Ogre::Vector3(tx, ty, tz) / 512);

                for (size_t bone = 0; bone < skeleton_data.size(); ++bone)
                {
                    skeleton_data[bone].rx = (ReadBitStream(file, offset_to_animation + 5, readed_bits, 12 - compression, 12) / 4096.0f) * 360;
                    skeleton_data[bone].ry = (ReadBitStream(file, offset_to_animation + 5, readed_bits, 12 - compression, 12) / 4096.0f) * 360;
                    skeleton_data[bone].rz = (ReadBitStream(file, offset_to_animation + 5, readed_bits, 12 - compression, 12) / 4096.0f) * 360;

                    bone1 = skeleton->getBone(bone * 2 + 2);
                    bone2 = skeleton->getBone(bone * 2 + 3);
                    track1 = anim->createNodeTrack(bone * 2 + 2, bone1);
                    track1->removeAllKeyFrames();
                    track2 = anim->createNodeTrack(bone * 2 + 3, bone2);
                    track2->removeAllKeyFrames();
                    frame1 = track1->createNodeKeyFrame(time);
                    frame2 = track2->createNodeKeyFrame(time);
                    frame2->setTranslate(Ogre::Vector3(0.0f, 0.0f, static_cast<float>(skeleton_data[bone].length) / 512));
                    mat.FromEulerAnglesYXZ(Ogre::Radian(Ogre::Degree(skeleton_data[bone].ry)), Ogre::Radian(Ogre::Degree(skeleton_data[bone].rx)), Ogre::Radian(Ogre::Degree(skeleton_data[bone].rz)));
                    rot.FromRotationMatrix(mat);
                    frame1->setRotation(rot);
                }

                if (with_weapon)
                {
                    weapon_tx = ReadBitStream(file, offset_to_animation_weapon + 5, readed_bits_weapon, 16, 16);
                    weapon_ty = ReadBitStream(file, offset_to_animation_weapon + 5, readed_bits_weapon, 16, 16);
                    weapon_tz = ReadBitStream(file, offset_to_animation_weapon + 5, readed_bits_weapon, 16, 16);
                    weapon_rx = (ReadBitStream(file, offset_to_animation_weapon + 5, readed_bits_weapon, 12 - compression_weapon, 12) / 4096.0f) * 360;
                    weapon_ry = (ReadBitStream(file, offset_to_animation_weapon + 5, readed_bits_weapon, 12 - compression_weapon, 12) / 4096.0f) * 360;
                    weapon_rz = (ReadBitStream(file, offset_to_animation_weapon + 5, readed_bits_weapon, 12 - compression_weapon, 12) / 4096.0f) * 360;

                    bone1 = skeleton->getBone(skeleton_data.size() * 2 + 3);
                    track1 = anim->createNodeTrack(skeleton_data.size() * 2 + 3, bone1);
                    track1->removeAllKeyFrames();
                    frame1 = track1->createNodeKeyFrame(time);
                    mat.FromEulerAnglesYXZ(Ogre::Radian(Ogre::Degree(weapon_ry)), Ogre::Radian(Ogre::Degree(weapon_rx)), Ogre::Radian(Ogre::Degree(weapon_rz)));
                    rot.FromRotationMatrix(mat);
                    frame1->setRotation(rot);

                    bone2 = skeleton->getBone(skeleton_data.size() * 2 + 2);
                    track2 = anim->createNodeTrack(skeleton_data.size() * 2 + 2, bone2);
                    track2->removeAllKeyFrames();
                    frame2 = track2->createNodeKeyFrame(time);
                    frame2->setTranslate(Ogre::Vector3(weapon_tx, weapon_ty, weapon_tz) / 512);
                }
            }
            else
            {
                tx += ReadDynamicFrameOffsetBits(file, offset_to_animation + 5, readed_bits);
                ty += ReadDynamicFrameOffsetBits(file, offset_to_animation + 5, readed_bits);
                tz += ReadDynamicFrameOffsetBits(file, offset_to_animation + 5, readed_bits);
                // skip first rotation
                ReadEncryptedRotationBits(file, offset_to_animation + 5, readed_bits, compression);
                ReadEncryptedRotationBits(file, offset_to_animation + 5, readed_bits, compression);
                ReadEncryptedRotationBits(file, offset_to_animation + 5, readed_bits, compression);

                bone1 = skeleton->getBone(0);
                track1 = anim->getNodeTrack(0);
                frame1 = track1->createNodeKeyFrame(time);
                mat.FromEulerAnglesYXZ(Ogre::Radian(Ogre::Degree(0)), Ogre::Radian(Ogre::Degree(-90)), Ogre::Radian(Ogre::Degree(0)));
                rot.FromRotationMatrix(mat);
                frame1->setRotation(rot);
                bone2 = skeleton->getBone(1);
                track2 = anim->getNodeTrack(1);
                frame2 = track2->createNodeKeyFrame(time);
                frame2->setTranslate(Ogre::Vector3(tx, ty, tz) / 512);

                for (size_t bone = 0; bone < skeleton_data.size(); ++bone)
                {
                    skeleton_data[bone].rx += (ReadEncryptedRotationBits(file, offset_to_animation + 5, readed_bits, compression) / 4096.0f) * 360;
                    skeleton_data[bone].ry += (ReadEncryptedRotationBits(file, offset_to_animation + 5, readed_bits, compression) / 4096.0f) * 360;
                    skeleton_data[bone].rz += (ReadEncryptedRotationBits(file, offset_to_animation + 5, readed_bits, compression) / 4096.0f) * 360;
                    bone1 = skeleton->getBone(bone * 2 + 2);
                    bone2 = skeleton->getBone(bone * 2 + 3);
                    track1 = anim->getNodeTrack(bone * 2 + 2);
                    track2 = anim->getNodeTrack(bone * 2 + 3);
                    frame1 = track1->createNodeKeyFrame(time);
                    frame2 = track2->createNodeKeyFrame(time);
                    frame2->setTranslate(Ogre::Vector3(0.0f, 0.0f, static_cast<float>(skeleton_data[bone].length) / 512));
                    mat.FromEulerAnglesYXZ(Ogre::Radian(Ogre::Degree(skeleton_data[bone].ry)), Ogre::Radian(Ogre::Degree(skeleton_data[bone].rx)), Ogre::Radian(Ogre::Degree(skeleton_data[bone].rz)));
                    rot.FromRotationMatrix(mat);
                    frame1->setRotation(rot);
                }

                if (with_weapon)
                {
                    weapon_tx += ReadDynamicFrameOffsetBits(file, offset_to_animation_weapon + 5, readed_bits_weapon);
                    weapon_ty += ReadDynamicFrameOffsetBits(file, offset_to_animation_weapon + 5, readed_bits_weapon);
                    weapon_tz += ReadDynamicFrameOffsetBits(file, offset_to_animation_weapon + 5, readed_bits_weapon);
                    weapon_rx += (ReadEncryptedRotationBits(file, offset_to_animation_weapon + 5, readed_bits_weapon, compression_weapon) / 4096.0f) * 360;
                    weapon_ry += (ReadEncryptedRotationBits(file, offset_to_animation_weapon + 5, readed_bits_weapon, compression_weapon) / 4096.0f) * 360;
                    weapon_rz += (ReadEncryptedRotationBits(file, offset_to_animation_weapon + 5, readed_bits_weapon, compression_weapon) / 4096.0f) * 360;

                    bone1 = skeleton->getBone(skeleton_data.size() * 2 + 3);
                    track1 = anim->getNodeTrack(skeleton_data.size() * 2 + 3);
                    frame1 = track1->createNodeKeyFrame(time);
                    mat.FromEulerAnglesYXZ(Ogre::Radian(Ogre::Degree(weapon_ry)), Ogre::Radian(Ogre::Degree(weapon_rx)), Ogre::Radian(Ogre::Degree(weapon_rz)));
                    rot.FromRotationMatrix(mat);
                    frame1->setRotation(rot);

                    bone2 = skeleton->getBone(skeleton_data.size() * 2 + 2);
                    track2 = anim->getNodeTrack(skeleton_data.size() * 2 + 2);
                    frame2 = track2->createNodeKeyFrame(time);
                    frame2->setTranslate(Ogre::Vector3(weapon_tx, weapon_ty, weapon_tz) / 512);
                }
            }

            time += 1.0f / 10.0f;
        }
    }
}
