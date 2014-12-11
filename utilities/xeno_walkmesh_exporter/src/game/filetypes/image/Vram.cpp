// $Id$
#include <cstring>

#include "Vram.h"

#include "../../../common/utilites/Logger.h"



Vram::Vram(void):
    mWidth(2048),
    mHeight(512)
{
}



Vram::~Vram(void)
{
}



const u16&
Vram::GetWidth(void) const
{
    return mWidth;
}



const u16&
Vram::GetHeight(void) const
{
    return mHeight;
}



Surface*
Vram::GetSurface(void) const
{
    u8* buffer = new u8[mWidth * mHeight * 2];

    for (u32 i = 0, size = mWidth * mHeight; i < size; i += 2)
    {
        u16 col = (mVram[i] << 8) | mVram[i + 1];
        u32 color  =  ((col      ) & 31) * 255 / 31;
            color |= (((col >>  5) & 31) * 255 / 31) << 8;
            color |= (((col >> 10) & 31) * 255 / 31) << 16;
            color |= ((col == 0x0000) ? 0 : 255) << 24;
        memcpy(buffer + i * 2, &color, 4);
    }

    Surface* image = CreateSurfaceFrom(mWidth / 2, mHeight, buffer);
    delete[] buffer;

    return image;
}



void
Vram::PutU8(const u16& x, const u16& y, const u8& byte)
{
    if (x > mWidth || y > mHeight)
    {
        LOGGER->Log(LOGGER_ERROR, "Vram::PutU8: Error: Tried to put byte in Vram x(%d) y(%d)", x, y);
        return;
    }

    mVram[y * mWidth + x] = byte;
}



u8
Vram::GetU8(const u16& x, const u16& y) const
{
    if (x > mWidth || y > mHeight)
    {
        LOGGER->Log(LOGGER_ERROR, "Vram::GetU8: Error: Tried to get byte from Vram x(%d) y(%d)", x, y);
        return 0;
    }

    return mVram[y * mWidth + x];
}



void
Vram::PutU16(const u16& x, const u16& y, const u16& bytes)
{
    if (x + 1 > mWidth || y > mHeight)
    {
        LOGGER->Log(LOGGER_ERROR, "Vram::PutU16: Error: Tried to put pixel in Vram x(%d) y(%d)", x, y);
        return;
    }

    mVram[y * mWidth + x    ] = bytes >> 8;
    mVram[y * mWidth + x + 1] = bytes & 0x00FF;
}



u16
Vram::GetU16(const u16& x, const u16& y) const
{
    if (x + 1 > mWidth || y > mHeight)
    {
        LOGGER->Log(LOGGER_ERROR, "Vram::GetU16: Error: Tried to get pixel from Vram x(%d) y(%d)", x, y);
        return 0;
    }

    return (mVram[y * mWidth + x] << 8) | mVram[y * mWidth + x + 1];
}
