// $Id: SurfaceLoadBmp.cpp 147 2007-02-24 06:13:17Z super_gb $

#include "Surface.h"
#include "SurfaceLoadBmp.h"
#include "../../utilites/Utilites.h"
#include "../../utilites/Logger.h"

#ifdef __BIG_ENDIAN__
#define BYTESWAP_ULONG(a)  (a) = (((a) >> 24) & 0xFF | ((a) >> 8) & 0xFF00 | ((a) << 8) & 0xFF0000 | ((a) << 24) & 0xFF000000);
#define BYTESWAP_USHORT(a) (a) = (((a) >> 8) & 0xFF | ((a) << 8) & 0xFF00);
#else
#define BYTESWAP_ULONG(a);
#define BYTESWAP_USHORT(a);
#endif

enum
{
    COMP_BI_RGB = 0,
    COMP_BI_RLE4,     // unsupported
    COMP_BI_RLE8,     // unsupported
    COMP_BI_BITFIELDS // unsupported
};



// we read only 24bpp BMP and 40 bytes header because we not really need to do this.
// this is just for test purpose (or maybe not ^_^)
static SurfaceUtils::OpenResult
LoadBMPFromBuffer(unsigned char* buffer, int size, Surface* &img)
{
    int pos = 0;

    // if not bmp
    if (buffer[0] != 'B' || buffer[1] != 'M')
    {
        return SurfaceUtils::OPEN_UNKNOWN_FILE_FORMAT;
    }
    pos += 2;
    pos += 4; // skip filesize
    pos += 4; // skip unused data
    if (img != NULL)
    {
        delete img;
        img = NULL;
    }

    unsigned long data_offset = *((unsigned long *)(buffer + pos)); pos += 4;
    BYTESWAP_ULONG(data_offset)    
    unsigned long header_size = *((unsigned long *)(buffer + pos)); pos += 4;
    BYTESWAP_ULONG(header_size)

    unsigned long  width;
    unsigned long  height;
    unsigned short planes;
    unsigned short bpp;
    unsigned long  compression = COMP_BI_RGB;
    unsigned long  colors = 0;

    if (header_size == 40)
    {
        width       = *((unsigned long *)(buffer + pos)); pos += 4;
        BYTESWAP_ULONG(width)
        height      = *((unsigned long *)(buffer + pos)); pos += 4;
        BYTESWAP_ULONG(height)
        planes      = *((unsigned short *)(buffer + pos)); pos += 2;
        BYTESWAP_USHORT(planes)
        bpp         = *((unsigned short *)(buffer + pos)); pos += 2;
        BYTESWAP_USHORT(bpp)
        compression = *((unsigned long *)(buffer + pos)); pos += 4;
        BYTESWAP_ULONG(compression)
        pos += 4; // bitmap size
        pos += 4; // horiz resolution
        pos += 4; // vert resolution
        colors      = *((unsigned long *)(buffer + pos)); pos += 4;
        BYTESWAP_ULONG(colors)
        pos += 4; // "important" colors
    }
    else
    {
        LOGGER->Log(LOGGER_ERROR,
			"ERROR: header must be 40 bytes long. We not support os/2 12 bytes headers.");
        return SurfaceUtils::OPEN_FATAL_ERROR;
    }

    if (planes != 1)
    {
        LOGGER->Log(LOGGER_ERROR,
			"ERROR: expected one plane, got %u.", planes);
        return SurfaceUtils::OPEN_FATAL_ERROR;
    }
    if (bpp != 24)
    {
        LOGGER->Log(LOGGER_ERROR,
			"ERROR: unsupported bpp %u. Must be 24bpp", bpp);
        return SurfaceUtils::OPEN_FATAL_ERROR;
    }
    if (compression != COMP_BI_RGB)
    {
        LOGGER->Log(LOGGER_ERROR,
			"ERROR: unsupported compression %u. Must be COMP_BI_RGB",
			compression);
        return SurfaceUtils::OPEN_FATAL_ERROR;
    }

    pos = data_offset;

    img = CreateSurface(width, height);

    for (int y = (int)height - 1; y >= 0; y--)
    {
        for (int x = 0; x < (int)width; x++)
        {
            *(img->pixels + x * 4 + img->width * 4 * y + 0) = *(buffer + pos + 2);
            *(img->pixels + x * 4 + img->width * 4 * y + 1) = *(buffer + pos + 1);
            *(img->pixels + x * 4 + img->width * 4 * y + 2) = *(buffer + pos + 0);
            *(img->pixels + x * 4 + img->width * 4 * y + 3) = 0xFF;
            pos += 3;
        }
    }

    return SurfaceUtils::OPEN_OK;
}



SurfaceUtils::OpenResult
SurfaceUtils::LoadBMP(const std::string &file, Surface* &img)
{
    unsigned char* buffer;

    FILE *image = fopen(file.c_str(), "rb");
    if (image == NULL)
    {
        return SurfaceUtils::OPEN_FATAL_ERROR;
    }

    // set cursor to end of file
    fseek(image, 0, SEEK_END);
    unsigned int size = ftell(image);
    // set cursor to beginning of file
    fseek(image, 0, SEEK_SET);

    buffer = (unsigned char*)malloc(sizeof(unsigned char) * size);
    fread(buffer, 1, size, image);

    SurfaceUtils::OpenResult ret;

    img = NULL;
    ret = LoadBMPFromBuffer(buffer, size, img);

    if (ret != SurfaceUtils::OPEN_OK && img != NULL)
    {
        delete img;
        img = NULL;
    }

    return ret;
}
