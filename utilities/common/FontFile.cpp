#include "common/FileSystem.h"
#include "common/Logger.h"

#include "FontFile.h"

#include <Ogre.h>

#include "common/TypeDefine.h"

using namespace QGears;

/*
FontFile::FontFile(const Ogre::String& file):
    File(*GAMEFILESYSTEM, file)
{
}
*/


FontFile::FontFile(File* pFile):
    File(pFile)
{
}



FontFile::FontFile(File* pFile, const u32& offset, const u32& length):
    File(pFile, offset, length)
{
}



FontFile::FontFile(u8* pBuffer, const u32& offset, const u32& length):
    File(pBuffer, offset, length)
{
}



FontFile::~FontFile(void)
{
}



Surface*
FontFile::GetSurface(void)
{
    int width    = 512;
    int height   = 4096;
    int chars    = 0;
    int char_num = 6165;
    Surface* ret = CreateSurface(width, height);

    int x_16 = 0;
    int y_16 = 0;

    struct ClutColor
    {
        u8 r;                 /**< @brief red color in CLUT */
        u8 g;                 /**< @brief green color in CLUT */
        u8 b;                 /**< @brief blue color in CLUT */
        u8 a;                 /**< @brief alpha in CLUT */
    };

    ClutColor color;
    color.r = 0;
    color.g = 0;
    color.b = 0;
    color.a = 255;

    u8 data = 0;


    for (int chars = 0; chars < char_num; ++chars)
    {
        Surface* glyth = CreateSurface(16, 16);

        for (int y = 0; y < 16; ++y)
        {
            data = (y < 11) ? GetU8(0xE + chars * 22 + y * 2 + 0) : 0;
            //LOGGER->Log(LOGGER_INFO, "%x, %02x", y, data);
            int j = 0;
            for (int i = 7; i >= 0; --i)
            {
                color.r = (((data >> i) & 0x01) == 1) ? 0 : 255;
                color.g = (((data >> i) & 0x01) == 1) ? 0 : 255;
                color.b = (((data >> i) & 0x01) == 1) ? 0 : 255;
                color.a = (((data >> i) & 0x01) == 1) ? 255 : 255;
                memcpy(glyth->pixels.data() + 64 * y + j, &color, sizeof(ClutColor));
                j += 4;
            }

            data = (y < 11) ? GetU8(0xE + chars * 22 + y * 2 + 1) : 0;
            //LOGGER->Log(LOGGER_INFO, "%02x", data);
            for (int i = 7; i >= 0; --i)
            {
                color.r = (((data >> i) & 0x01) == 1) ? 0 : 255;
                color.g = (((data >> i) & 0x01) == 1) ? 0 : 255;
                color.b = (((data >> i) & 0x01) == 1) ? 0 : 255;
                color.a = (((data >> i) & 0x01) == 1) ? 255 : 255;
                memcpy(glyth->pixels.data() + 64 * y + j, &color, sizeof(ClutColor));
                j += 4;
            }
        }

        CopyToSurface(ret, x_16, y_16, glyth);
        delete glyth;
        x_16 += 16;
        if (x_16 == ret->width)
        {
            y_16 += 16;
            x_16 = 0;
        }
    }



    Ogre::TexturePtr ptex;
    Ogre::HardwarePixelBufferSharedPtr buffer;
    ptex = Ogre::TextureManager::getSingleton().createManual("DynaTex", "General", Ogre::TEX_TYPE_2D, ret->width, ret->height, 0, Ogre::PF_R8G8B8A8, Ogre::TU_STATIC);
    buffer = ptex->getBuffer(0, 0);
    buffer->lock(Ogre::HardwareBuffer::HBL_DISCARD);
    const Ogre::PixelBox& pb = buffer->getCurrentLock();

    for (auto y = 0; y < ret->height; ++y)
    {
        auto* data = static_cast<unsigned int*>(pb.data) + y * pb.rowPitch;

        for (auto x = 0; x < ret->width; ++x)
        {
            auto clut = ret->pixels[y * ret->width * 4 + x * 4 + 3] | (ret->pixels[y * ret->width * 4 + x * 4 + 2] << 8) | (ret->pixels[y * ret->width * 4 + x * 4 + 1] << 16) | (ret->pixels[y * ret->width * 4 + x * 4 + 0] << 24);
            data[x] = clut;
        }
    }

    Ogre::Image image;
    image.loadDynamicImage((Ogre::uchar*)pb.data, ret->width, ret->height, Ogre::PF_R8G8B8A8);
    image.save("font.png");
    buffer->unlock();
    Ogre::TextureManager::getSingleton().remove("DynaTex");



    return ret;
}
