// $Id$

#ifndef VRAM_H
#define VRAM_H

#include "../../../common/TypeDefine.h"
#include "../../../common/display/surface/Surface.h"



class Vram
{
public:
               Vram(void);
    virtual   ~Vram(void);

    const u16& GetWidth(void) const;
    const u16& GetHeight(void) const;

    Surface*   GetSurface(void) const;

    void       AddImageBuffer(const u16& x, const u16& y, const u16& width, const u16& height, u8* buffer);
    void       PutU8(const u16& x, const u16& y, const u8& byte);
    u8         GetU8(const u16& x, const u16& y) const;
    void       PutU16(const u16& x, const u16& y, const u16& bytes);
    u16        GetU16(const u16& x, const u16& y) const;

private:
    u8  mVram[2048 * 512];

    u16 mWidth;
    u16 mHeight;
};



#endif
