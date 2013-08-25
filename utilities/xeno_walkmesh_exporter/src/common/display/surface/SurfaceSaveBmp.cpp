// $Id: SurfaceSaveBmp.cpp 93 2006-11-12 13:49:02Z einherjar $

#include "Surface.h"
#include "SurfaceSaveBmp.h"
#include "../../utilites/Logger.h"

#include <stdio.h>
#include <cstring>

#pragma pack(1)



bool
SurfaceUtils::SaveBMP(const std::string &file, Surface* surface)
{
    FILE* image_file = fopen(file.c_str(), "wb");

    struct BitmapFileHeader
    {
        unsigned short Type;
        unsigned long  Size;
        unsigned short Reserved1;
        unsigned short Reserved2;
        unsigned long  OffBits;
    } bfh;

    struct BitmapInfoHeader
    {
        unsigned long  Size;
        signed long    Width;
        signed long    Height;
        unsigned short Planes;
        unsigned short BitCount;
        unsigned long  Compression;
        unsigned long  SizeImage;
        signed long    XPelsPerMeter;
        signed long    YPelsPerMeter;
        unsigned long  ClrUsed;
        unsigned long  ClrImportant;
    } bih;

    memset(&bfh, 0, sizeof(bfh));
    bfh.Type        = 0x4D42; // BM
    bfh.OffBits     = sizeof(bfh) + sizeof(bih) + 1024;
    bfh.Size        = bfh.OffBits + 3 * surface->width * surface->height + surface->height * (surface->width % 4);

    memset(&bih, 0, sizeof(bih));
    bih.Size        = sizeof(bih);
    bih.BitCount    = 24;
    bih.Compression = 0; // COMP_BI_RGB;
    bih.Height      = surface->height;
    bih.Width       = surface->width;
    bih.Planes      = 1;

    unsigned char palette[1024];
    memset(palette, 0, 1024);

    fwrite(&bfh, 1, sizeof(bfh), image_file);
    fwrite(&bih, 1, sizeof(bih), image_file);
    fwrite(palette, 1, 1024, image_file);

    int data_size = surface->width * surface->height * 3 + surface->height * (surface->width % 4);
    unsigned char* temp = new unsigned char[data_size];
    int temp_pos = 0;

    for (int y = surface->height - 1; y >= 0; --y)
    {
        for (int x = 0; x < surface->width; ++x)
        {
            temp[temp_pos++] = surface->pixels[x * 4 + surface->width * 4 * y + 2];
            temp[temp_pos++] = surface->pixels[x * 4 + surface->width * 4 * y + 1];
            temp[temp_pos++] = surface->pixels[x * 4 + surface->width * 4 * y + 0];
        }

        for (int i = 0; i < surface->width % 4; ++i)
        {
            temp[temp_pos++] = 0;
        }
    }

    fwrite(temp, 1, data_size, image_file);

    delete[] temp;

    fclose(image_file);

    return true;
}
