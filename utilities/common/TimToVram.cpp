#include "TimToVram.h"

#include <OgreStringConverter.h>

#include "Logger.h"



void
LoadTimFileToVram(File* file, int tim_offset, Vram* vram)
{
    LOGGER->Log("Load image at offset " + HexToString(tim_offset, 4, '0') + " to VRAM.\n");

    int next_offset          = file->GetU32LE(tim_offset + 0x08);
    int clut_vram_position_x = file->GetU16LE(tim_offset + 0x0c);
    int clut_vram_position_y = file->GetU16LE(tim_offset + 0x0e);
    int clut_width           = file->GetU16LE(tim_offset + 0x10);
    int clut_height          = file->GetU16LE(tim_offset + 0x12);

    LOGGER->Log("ClutVramPositionX (" + HexToString(clut_vram_position_x, 4, '0') + ") ClutVramPositionY (" + HexToString(clut_vram_position_y, 4, '0') + ") Width (" + HexToString(clut_width, 4, '0') + ") Height (" +  HexToString(clut_height, 4, '0') + ")\n");
    for (int y = 0; y < clut_height; ++y)
    {
        for (int x = 0; x < clut_width; ++x)
        {
            u16 color = file->GetU16LE(tim_offset + 0x14 + y * clut_width * 2 + x * 2);
            vram->PutU16(x * 2 + clut_vram_position_x, y + clut_vram_position_y, color);
        }
    }

    //while (next_offset != 0)
    {
        // set image buffer
        int image_vram_position_x = file->GetU16LE(tim_offset + 0x08 + next_offset + 0x4) * 2;
        int image_vram_position_y = file->GetU16LE(tim_offset + 0x08 + next_offset + 0x6);
        int image_width           = file->GetU16LE(tim_offset + 0x08 + next_offset + 0x8) * 2;
        int image_height          = file->GetU16LE(tim_offset + 0x08 + next_offset + 0xa);

        LOGGER->Log("ImageVramPositionX (" + HexToString(image_vram_position_x, 4, '0') + ") ImageVramPositionY (" + HexToString(image_vram_position_y, 4, '0') + ") ImageWidth (" + HexToString(image_width, 4, '0') + ") ImageHeight (" +  HexToString(image_height, 4, '0') + ")\n");
        for (int y = 0; y < image_height; ++y)
        {
            for (int x = 0; x < image_width; ++x)
            {
                u8 data = file->GetU8(tim_offset + 0x08 + next_offset + 0xc + y * image_width + x);
                vram->PutU8(x + image_vram_position_x, y + image_vram_position_y, data);
            }
        }

        //next_offset = file->GetU16LE(tim_offset + 0x08 + next_offset + 0x0);
    }
}
