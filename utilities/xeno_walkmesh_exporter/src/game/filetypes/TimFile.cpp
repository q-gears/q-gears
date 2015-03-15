// $Id: TimFile.cpp 147 2007-02-24 06:13:17Z super_gb $
#include <cstring>

#include "../../common/filesystem/GameFileSystem.h"
#include "../../common/utilites/Logger.h"

#include "TimFile.h"



TimFile::TimFile(const RString& file):
    File(*GAMEFILESYSTEM, file)
{
    InnerGetImage();
}



TimFile::TimFile(File* pFile):
    File(pFile)
{
    InnerGetImage();
}



TimFile::TimFile(File* pFile, const u32& offset, const u32& length):
    File(pFile, offset, length)
{
    InnerGetImage();
}



TimFile::TimFile(u8* pBuffer, const u32& offset, const u32& length):
    File(pBuffer, offset, length)
{
    InnerGetImage();
}



TimFile::~TimFile(void)
{
}



Surface*
TimFile::GetSurface(const u32& clutNumber)
{
    Surface* ret = NULL;

    if (clutNumber > mClutHeight)
    {
        LOGGER->Log(LOGGER_WARNING, "TimFile::GetSurface: Warning: 'clut_number' is greater than number of clut in file.");
        return ret;
    }

    // temp clut color
    ClutColor color;

    // convert 4BPP tim
    if (mIdTag == 0x10 && mIdTagClut == 0x08)
    {
        ret = CreateSurface(mImageWidth * 2, mImageHeight);

        for (int y = 0; y < mImageHeight; ++y)
        {
            for (int x = 0; x < mImageWidth; ++x)
            {
                u16 real_x = mImageVramPositionX + x;
                u16 real_y = mImageVramPositionY + y;
                u16 clut_y = static_cast<u16>(clutNumber + mClutVramPositionY);

                u8 data = mVram.GetU8(real_x, real_y) & 0x0F;
                u16 col = mVram.GetU16(data * 2 + mClutVramPositionX, clut_y);

                color.r = ((col      ) & 31) * 255 / 31;
                color.g = ((col >>  5) & 31) * 255 / 31;
                color.b = ((col >> 10) & 31) * 255 / 31;
                u8 stp = (col & 0x80) >> 15;
                if (col == 0x0000)
                {
                    color.a = 0;
                }
                else if (stp == 1 && color.r == 0 && color.g == 0 && color.b == 0)
                {
                    color.a = 255;
                }
                else if (stp == 1 && (color.r != 0 || color.g != 0 || color.b != 0))
                {
                    color.a = 127;
                }
                else if (stp == 0 && (color.r != 0 || color.g != 0 || color.b != 0))
                {
                    color.a = 255;
                }

                memcpy(ret->pixels + x * 8 + ret->width * 4 * y + 0x00, &color, sizeof(ClutColor));

                data    = (mVram.GetU8(real_x, real_y) & 0xF0) >> 4;
                col     = mVram.GetU16(data * 2 + mClutVramPositionX, clut_y);

                color.r = ((col      ) & 31) * 255 / 31;
                color.g = ((col >>  5) & 31) * 255 / 31;
                color.b = ((col >> 10) & 31) * 255 / 31;
                stp = (col & 0x80) >> 15;
                if (col == 0x0000)
                {
                    color.a = 0;
                }
                else if (stp == 1 && color.r == 0 && color.g == 0 && color.b == 0)
                {
                    color.a = 255;
                }
                else if (stp == 1 && (color.r != 0 || color.g != 0 || color.b != 0))
                {
                    color.a = 127;
                }
                else if (stp == 0 && (color.r != 0 || color.g != 0 || color.b != 0))
                {
                    color.a = 255;
                }

                memcpy(ret->pixels + x * 8 + ret->width * 4 * y + 0x04, &color, sizeof(ClutColor));
            }
        }
    }



    // convert 8BPP tim
    else if (mIdTag == 0x10 && mIdTagClut == 0x09)
    {
        ret = CreateSurface(mImageWidth, mImageHeight);

        for (int y = 0; y < mImageHeight; ++y)
        {
            for (int x = 0; x < mImageWidth; ++x)
            {
                u16 real_x = mImageVramPositionX + x;
                u16 real_y = mImageVramPositionY + y;
                u16 clut_y = static_cast<u16>(clutNumber + mClutVramPositionY);

                u8 data = mVram.GetU8(real_x, real_y);
                u16 col = mVram.GetU16(data * 2 + mClutVramPositionX, clut_y);

                color.r = ((col      ) & 31) * 255 / 31;
                color.g = ((col >>  5) & 31) * 255 / 31;
                color.b = ((col >> 10) & 31) * 255 / 31;
                u8 stp = (col & 0x80) >> 15;
                if (col == 0x0000)
                {
                    color.a = 0;
                }
                else if (stp == 1 && color.r == 0 && color.g == 0 && color.b == 0)
                {
                    color.a = 255;
                }
                else if (stp == 1 && (color.r != 0 || color.g != 0 || color.b != 0))
                {
                    color.a = 127;
                }
                else if (stp == 0 && (color.r != 0 || color.g != 0 || color.b != 0))
                {
                    color.a = 255;
                }

                memcpy(ret->pixels + x * 4 + ret->width * 4 * y, &color, sizeof(ClutColor));
            }
        }
    }



    else
    {
        LOGGER->Log(LOGGER_WARNING, "Warning: unknown format! (mIdTag = %02x) (mIdTagClut = %02x)", mIdTag, mIdTagClut);
        LOGGER->Log(LOGGER_INFO, "16BPP TIM, 24BPP TIM left");
    }

    return ret;
}



void
TimFile::InnerGetImage(void)
{
    // get number of clut
    TimHeader* tim_header = (TimHeader*)(mpBuffer);

    mIdTag             = tim_header->id_tag;
    mIdTagClut         = tim_header->id_tag_clut;

    mClutVramPositionX = tim_header->x;
    mClutVramPositionY = tim_header->y;
    mClutWidth         = tim_header->width;
    mClutHeight        = tim_header->height;
    LOGGER->Log(LOGGER_INFO, "VramPositionX (%04x) VramPositionY (%04x) Width (%d) Height (%d)", mClutVramPositionX, mClutVramPositionY, mClutWidth, mClutHeight);
    for (int y = 0; y < mClutHeight; ++y)
    {
        for (int x = 0; x < mClutWidth; ++x)
        {
            u16 color = GetU16LE(sizeof(TimHeader) + y * mClutWidth * 2 + x * 2);
            mVram.PutU16(x * 2 + mClutVramPositionX, y + mClutVramPositionY, color);
        }
    }



    // set image buffer
    TimHeader2* tim_header2 = (TimHeader2*)((u8*)mpBuffer + 0x08 + tim_header->header2_offset);
    mImageVramPositionX = tim_header2->x * 2;
    mImageVramPositionY = tim_header2->y;
    mImageWidth         = tim_header2->width * 2;
    mImageHeight        = tim_header2->height;

    for (int y = 0; y < mImageHeight; ++y)
    {
        for (int x = 0; x < mImageWidth; ++x)
        {
            u8 data = GetU8(0x08 + tim_header->header2_offset + sizeof(TimHeader2) + y * mImageWidth + x);
            mVram.PutU8(x + mImageVramPositionX, y + mImageVramPositionY, data);
        }
    }
}
