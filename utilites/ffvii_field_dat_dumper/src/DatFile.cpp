#include "DatFile.h"

#include <OgreStringConverter.h>
#include <OgreVector3.h>



class surface_find
{
public:
    surface_find( const SurfaceTexData& a ):
        m_Surface(a)
    {
    }

    bool
    operator()( const SurfaceTexData& a ) const
    {
        return ( a.page_x == m_Surface.page_x ) &&
               ( a.page_y == m_Surface.page_y ) &&
               ( a.clut_y == m_Surface.clut_y ) &&
               ( a.clut_x == m_Surface.clut_x ) &&
               ( a.bpp    == m_Surface.bpp );
    }

private:
    SurfaceTexData m_Surface;
};



std::vector< Ogre::String > DatFile::m_SoundOpcodes;



//////////////////////////////////////////////
unsigned short english_chars[256] = {
    // 0    1       2       3       4       5       6       7       8       9       A       B       C       D       E       F
    0x2000, 0x2100, 0x2200, 0x2300, 0x2400, 0x2500, 0x2600, 0x2700, 0x2800, 0x2900, 0x2A00, 0x2B00, 0x2C00, 0x2D00, 0x2E00, 0x2F00, // 0x00 - 0x0F
    0x3000, 0x3100, 0x3200, 0x3300, 0x3400, 0x3500, 0x3600, 0x3700, 0x3800, 0x3900, 0x3A00, 0x3B00, 0x3C00, 0x3D00, 0x3E00, 0x3F00, // 0x10 - 0x1F
    0x4000, 0x4100, 0x4200, 0x4300, 0x4400, 0x4500, 0x4600, 0x4700, 0x4800, 0x4900, 0x4A00, 0x4B00, 0x4C00, 0x4D00, 0x4E00, 0x4F00, // 0x20 - 0x2F
    0x5000, 0x5100, 0x5200, 0x5300, 0x5400, 0x5500, 0x5600, 0x5700, 0x5800, 0x5900, 0x5A00, 0x5B00, 0x5C00, 0x5D00, 0x5E00, 0x5F00, // 0x30 - 0x3F
    0x6000, 0x6100, 0x6200, 0x6300, 0x6400, 0x6500, 0x6600, 0x6700, 0x6800, 0x6900, 0x6A00, 0x6B00, 0x6C00, 0x6D00, 0x6E00, 0x6F00, // 0x40 - 0x4F
    0x7000, 0x7100, 0x7200, 0x7300, 0x7400, 0x7500, 0x7600, 0x7700, 0x7800, 0x7900, 0x7A00, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x50 - 0x5F
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x60 - 0x6F
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x70 - 0x7F
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x80 - 0x8F
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x90 - 0x9F
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x2620, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0xA0 - 0xAF
    0x0000, 0x0000, 0x1C20, 0x1D20, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0xB0 - 0xBF
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0xC0 - 0xCF
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0xD0 - 0xDF
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0D00, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0xE0 - 0xEF
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0xF0 - 0xFF
};

unsigned short japanese_chars[256] = {
    // 0    1       2       3       4       5       6       7       8       9       A       B       C       D       E       F
    0xD030, 0x7030, 0xD330, 0x7330, 0xD630, 0x7630, 0xD930, 0x0000, 0xDC30, 0x7C30, 0xAC30, 0x4C30, 0xAE30, 0x4E30, 0xB030, 0x5030, // 0x00 - 0x0F
    0xB230, 0x5230, 0xB430, 0x5430, 0xB630, 0x5630, 0xB830, 0x5830, 0xBA30, 0x5A30, 0xBC30, 0x5C30, 0xBE30, 0x5E30, 0xC030, 0x6030, // 0x10 - 0x1F
    0x0000, 0x0000, 0xC530, 0x0000, 0xC730, 0x6730, 0xC930, 0x6930, 0x0000, 0xD130, 0x7130, 0xD430, 0x0000, 0xD730, 0x7730, 0xDA30, // 0x20 - 0x2F
    0x0000, 0xDD30, 0x0000, 0x3000, 0x3100, 0x3200, 0x3300, 0x3400, 0x3500, 0x3600, 0x3700, 0x3800, 0x3900, 0x0130, 0x0230, 0x2000, // 0x30 - 0x3F
    0xCF30, 0x6F30, 0xD230, 0x7230, 0xD530, 0x7530, 0xD830, 0x7830, 0xDB30, 0x7B30, 0xAB30, 0x4B30, 0xAD30, 0x4D30, 0xAF30, 0x4F30, // 0x40 - 0x4F
    0xB130, 0x5130, 0xB330, 0x5330, 0xB530, 0x5530, 0xB730, 0x5730, 0xB930, 0x5930, 0xBB30, 0x5B30, 0xBD30, 0x5D30, 0xBF30, 0x5F30, // 0x50 - 0x5F
    0xC130, 0x6130, 0xC430, 0x6430, 0xC630, 0x6630, 0xC830, 0x6830, 0xA630, 0x4630, 0xA230, 0x4230, 0xA430, 0x4430, 0xA830, 0x4830, // 0x60 - 0x6F
    0xAA30, 0x4A30, 0xCA30, 0x6A30, 0xCB30, 0x6B30, 0x0000, 0x6C30, 0xCD30, 0x6D30, 0xCE30, 0x6E30, 0xDE30, 0x7E30, 0xDF30, 0x7F30, // 0x70 - 0x7F
    0xE030, 0x8030, 0xE130, 0x8130, 0xE230, 0x8230, 0xE930, 0x8930, 0xEA30, 0x8A30, 0xEB30, 0x8B30, 0xEC30, 0x8C30, 0xED30, 0x8D30, // 0x80 - 0x8F
    0xE430, 0x8430, 0xE630, 0x0000, 0x0000, 0x8830, 0xEF30, 0x8F30, 0xF330, 0x9330, 0x0000, 0x9230, 0xC330, 0x6330, 0xE330, 0x8330, // 0x90 - 0x9F
    0xE530, 0x8530, 0xE730, 0x8730, 0xA130, 0x4130, 0xA330, 0x0000, 0xA530, 0x0000, 0xA730, 0x4730, 0x0000, 0x4930, 0x01FF, 0x1FFF, // 0xA0 - 0xAF
    0x0E30, 0x0F30, 0x0000, 0x0000, 0x4100, 0x4200, 0x4300, 0x4400, 0x4500, 0x4600, 0x4700, 0x4800, 0x4900, 0x4A00, 0x4B00, 0x4C00, // 0xB0 - 0xBF
    0x4D00, 0x4E00, 0x4F00, 0x5000, 0x5100, 0x5200, 0x5300, 0x5400, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFB30, 0x0000, // 0xC0 - 0xCF
    0xFC30, 0x7E00, 0x2620, 0x0000, 0x0000, 0x0000, 0x0000, 0x1030, 0x1130, 0x0000, 0x0000, 0x0000, 0x0000, 0x0C30, 0x0D30, 0x08FF, // 0xD0 - 0xDF
    0x09FF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0D00, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0xE0 - 0xEF
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0xF0 - 0xFF
};



unsigned short japanese_chars_fa[256] = {
    // 0    1       2       3       4       5       6       7       8       9       A       B       C       D       E       F
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x00 - 0x0F
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x10 - 0x1F
    0x0672, 0x7F4F, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x3478, 0x4466, 0x8364, 0x0000, 0x0000, 0x0000, // 0x20 - 0x2F
    0x0000, 0x0000, 0x0000, 0x0000, 0x666B, 0x5E79, 0x0000, 0x0000, 0xA898, 0x0000, 0x176C, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x30 - 0x3F
    0x885B, 0x0000, 0x7D54, 0x0000, 0xD552, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x6297, 0x0000, 0x0000, 0x0000, 0x0854, 0x0000, // 0x40 - 0x4F
    0x0000, 0x0000, 0x0E66, 0x0000, 0x0000, 0x9C62, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x004E, 0x0000, 0x0580, // 0x50 - 0x5F
    0x0000, 0x0000, 0x857F, 0x0000, 0x0000, 0x0000, 0x9950, 0x6856, 0x0000, 0x549B, 0xD56C, 0x0000, 0x0000, 0x0000, 0x0000, 0xFA51, // 0x60 - 0x6F
    0x0163, 0xF876, 0x4B62, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xB965, 0x4C88, 0x0000, // 0x70 - 0x7F
    0x9A5B, 0x0000, 0x0000, 0x4D52, 0x1F77, 0x0000, 0x9A89, 0x1752, 0x8C5F, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xDE56, 0x0000, // 0x80 - 0x8F
    0x9A7D, 0x7565, 0x0000, 0x0000, 0x0000, 0x0000, 0x3E5C, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0882, 0x0000, 0x0000, // 0x90 - 0x9F
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x3E5F, 0x0000, 0x0000, 0x0000, 0x4266, 0x0000, 0x0000, 0x2662, 0x0000, // 0xA0 - 0xAF
    0x0000, 0x0000, 0x0000, 0x0000, 0xB751, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xEA8C, 0x0000, 0x0000, 0x0000, // 0xB0 - 0xBF
    0xCD53, 0x0000, 0xEE76, 0x0000, 0x0000, 0x9B52, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x7551, 0x0000, 0x0000, 0x0000, // 0xC0 - 0xCF
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0xD0 - 0xDF
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0xE0 - 0xEF
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0xF0 - 0xFF
};



unsigned short japanese_chars_fb[256] = {
    // 0    1       2       3       4       5       6       7       8       9       A       B       C       D       E       F
    0x0000, 0x0000, 0xB182, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0B4E, 0x0000, 0x6551, 0x4851, 0x0D4E, 0x505B, 0x9B4F, 0x4B5C, // 0x00 - 0x0F
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x8E96, 0x0000, 0x0000, 0xE890, 0x0000, 0x3458, 0x0000, 0xF24E, 0x9395, 0x0000, 0x0000, // 0x10 - 0x1F
    0x5096, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x554F, 0x0000, 0x9965, 0x0000, 0x0A4E, 0x0000, 0x8B4E, 0x0000, 0x0000, // 0x20 - 0x2F
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x6559, 0x0000, 0x0000, 0x0000, 0x0000, 0x5167, 0x0000, 0x0000, 0x0000, 0x0000, // 0x30 - 0x3F
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x40 - 0x4F
    0x0000, 0x0000, 0xCA8E, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xBA87, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x50 - 0x5F
    0x0000, 0x7751, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xB672, 0x4B61, 0x0000, // 0x60 - 0x6F
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x8B95, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x70 - 0x7F
    0x0000, 0x0C54, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x7354, 0x0000, 0x0000, 0x0000, 0x0D50, 0x0000, 0x0000, 0x0000, // 0x80 - 0x8F
    0x0000, 0xBA4E, 0xCA4E, 0x0000, 0x0000, 0x535F, 0x0000, 0x0000, 0xDB98, 0xE54E, 0x1659, 0x0000, 0x0000, 0x0000, 0xAB8E, 0x0000, // 0x90 - 0x9F
    0xCB65, 0x0000, 0x0000, 0x0000, 0x5F6A, 0xB068, 0x0000, 0x8970, 0xB065, 0x214E, 0x2C67, 0x1B54, 0x0000, 0x8551, 0x5C4F, 0x668B, // 0xA0 - 0xAF
    0x7972, 0x0000, 0x0000, 0x0000, 0x747A, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xB38D, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0xB0 - 0xBF
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x7795, 0x0000, 0x0000, 0x5458, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x8B89, // 0xC0 - 0xCF
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x4351, 0x0000, 0x0000, 0x0000, 0x427D, 0x0000, 0x0000, 0x0D54, 0x0000, 0x0000, // 0xD0 - 0xDF
    0x0000, 0x1062, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0xE0 - 0xEF
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0xF0 - 0xFF
};



unsigned short japanese_chars_fc[256] = {
    // 0    1       2       3       4       5       6       7       8       9       A       B       C       D       E       F
    0x0000, 0x0000, 0x188A, 0x0000, 0x7890, 0x6A75, 0x5788, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x00 - 0x0F
    0x9358, 0xC35F, 0x0000, 0x0000, 0x0000, 0x0000, 0x5390, 0x0000, 0x0000, 0x0000, 0x0000, 0xFB5D, 0x0000, 0x0000, 0x0000, 0x0000, // 0x10 - 0x1F
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x884E, 0x0000, 0x3D84, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x20 - 0x2F
    0xE565, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x30 - 0x3F
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x296E, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x40 - 0x4F
    0x0000, 0x0000, 0x7153, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x008A, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x50 - 0x5F
    0x3159, 0x5765, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x60 - 0x6F
    0x0000, 0x0000, 0xBC62, 0x0000, 0x0000, 0x0000, 0x5965, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x70 - 0x7F
    0x0000, 0x0000, 0x0000, 0x0000, 0xC253, 0xE577, 0x5E80, 0x0000, 0xD54E, 0x2552, 0xC696, 0xE14F, 0x2875, 0x0000, 0x0000, 0x0000, // 0x80 - 0x8F
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xE965, 0x0000, 0x0000, 0x0000, 0x0000, 0x718A, 0x305E, 0x0000, 0x0000, 0x0000, // 0x90 - 0x9F
    0x0000, 0xF258, 0x6E6D, 0x0000, 0xA052, 0x0000, 0x047D, 0x0000, 0x3C79, 0x5F67, 0x0000, 0x3775, 0x0000, 0x0000, 0x0000, 0xCB7A, // 0xA0 - 0xAF
    0x0000, 0xFA4F, 0x0000, 0x0000, 0x0000, 0xC179, 0x0000, 0x0000, 0x1250, 0x114F, 0x0000, 0x0000, 0x0000, 0xA952, 0x0000, 0x0000, // 0xB0 - 0xBF
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xAC8A, 0x0000, 0x0000, 0xF167, 0x0000, 0x0000, // 0xC0 - 0xCF
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0xD0 - 0xDF
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0xE0 - 0xEF
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0xF0 - 0xFF
};



unsigned short japanese_chars_fd[256] = {
    // 0    1       2       3       4       5       6       7       8       9       A       B       C       D       E       F
    0x0000, 0x1D4F, 0x0000, 0xA263, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x00 - 0x0F
    0xE682, 0x0000, 0xF056, 0x0000, 0x0000, 0x0000, 0x0000, 0xA25B, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x10 - 0x1F
    0x0000, 0x2B59, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xB88C, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xDD4F, 0x2F5E, // 0x20 - 0x2F
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x7289, 0x0000, 0x216B, 0x0000, 0x207D, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x30 - 0x3F
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xB78C, 0x0000, 0x0000, 0x0000, 0x7C5E, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x40 - 0x4F
    0x0000, 0x0000, 0x0000, 0x0000, 0x8179, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x50 - 0x5F
    0x0000, 0x975E, 0x0000, 0x0000, 0x0000, 0xCA7D, 0x1478, 0x0000, 0x0000, 0x8766, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x60 - 0x6F
    0xC599, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x70 - 0x7F
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFD88, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x80 - 0x8F
    0x0000, 0x0000, 0x3293, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x5453, 0x0000, 0x0000, // 0x90 - 0x9F
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x8D8E, 0x0000, 0x0000, 0x0000, 0x0000, 0x3052, 0x0000, 0x0000, 0x0000, 0x0000, // 0xA0 - 0xAF
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0xB0 - 0xBF
    0x9F52, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x5291, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0xC0 - 0xCF
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0xD0 - 0xDF
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0xE0 - 0xEF
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0xF0 - 0xFF
};



unsigned short japanese_chars_fe[256] = {
    // 0    1       2       3       4       5       6       7       8       9       A       B       C       D       E       F
    0x0000, 0x0000, 0x0000, 0x667D, 0x0000, 0x0000, 0x0000, 0xAD65, 0x0000, 0x0000, 0xB96C, 0x0000, 0xD550, 0x585B, 0x0000, 0x0000, // 0x00 - 0x0F
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x10 - 0x1F
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x8B4F, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x20 - 0x2F
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x9758, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x30 - 0x3F
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x40 - 0x4F
    0x0000, 0x0000, 0x0000, 0xB48C, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x4256, 0xF158, 0x0000, 0x0000, 0x0000, 0x0000, // 0x50 - 0x5F
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xB54F, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x60 - 0x6F
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x1D8B, 0x0000, 0x0000, 0x0000, 0xA14F, 0x206B, 0xC45B, 0xD95F, // 0x70 - 0x7F
    0x0000, 0x944E, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xA65E, 0x0000, 0x0000, 0x0000, 0x0000, 0x988A, // 0x80 - 0x8F
    0x0000, 0x0000, 0x298F, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x668A, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x90 - 0x9F
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x7272, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0xA0 - 0xAF
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xC079, 0x0000, 0xFD8E, 0x0000, 0x0000, 0x0000, // 0xB0 - 0xBF
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x3B52, // 0xC0 - 0xCF
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0xD0 - 0xDF
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0xE0 - 0xEF
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0xF0 - 0xFF
};



DatFile::DatFile(const Ogre::String &file):
    LzsFile(file)
{
}



DatFile::DatFile(File *file, const u32 offset, const u32 length):
    LzsFile(file, offset, length)
{
}



DatFile::DatFile(u8* buffer, const u32 offset, const u32 length):
    LzsFile(buffer, offset, length)
{
}



DatFile::DatFile(File *file):
    LzsFile(file)
{
}



DatFile::~DatFile()
{
    if( full_image != NULL )
    {
        delete full_image;
    }

    for( u8 i = 0; i < m_Surfaces.size(); ++i )
    {
        delete m_Surfaces[ i ].surface;
    }
    m_Surfaces.clear();
}





void
DatFile::DumpTextData( const Ogre::String& export_path, const Field& field, bool english )
{
    std::sort( m_Dialogs.begin(), m_Dialogs.end() );
    m_Dialogs.erase( std::unique( m_Dialogs.begin(), m_Dialogs.end()), m_Dialogs.end() );

    Logger* export_text = new Logger( export_path + "maps/field/" + field.name + "_text.txt" );

    // get sector 1 offset (scripts and dialog)
    u32 offset_to_sector  = 0x1C;
    u16 offset_to_dialogs = GetU16LE( offset_to_sector + 0x04 );

    std::vector< unsigned char > dialog;
    dialog.push_back(0xFF);
    dialog.push_back(0xFE);

    for (int i = 0; i < m_Dialogs.size(); ++i)
    {
        // get offset of string data
        u32 offset = offset_to_sector + offset_to_dialogs + GetU16LE(offset_to_sector + offset_to_dialogs + 0x02 + m_Dialogs[i] * 0x02);

        export_text->Log(dialog);
        dialog.clear();
        export_text->LogW( "<dialog id=\"" + ToIntString(m_Dialogs[i]) + "\">" );

        for (unsigned char temp = 0x00; ; ++offset)
        {
            temp = GetU8(offset);
            if (temp == 0xFF)
            {
                break;
            }

            if (temp == 0xE0 && english == true)
            {
                dialog.push_back(english_chars[0x00] >> 8); dialog.push_back(english_chars[0x00] & 0xFF);
                dialog.push_back(english_chars[0x00] >> 8); dialog.push_back(english_chars[0x00] & 0xFF);
                dialog.push_back(english_chars[0x00] >> 8); dialog.push_back(english_chars[0x00] & 0xFF);
                dialog.push_back(english_chars[0x00] >> 8); dialog.push_back(english_chars[0x00] & 0xFF);
                dialog.push_back(english_chars[0x00] >> 8); dialog.push_back(english_chars[0x00] & 0xFF);
                dialog.push_back(english_chars[0x00] >> 8); dialog.push_back(english_chars[0x00] & 0xFF);
                dialog.push_back(english_chars[0x00] >> 8); dialog.push_back(english_chars[0x00] & 0xFF);
                dialog.push_back(english_chars[0x00] >> 8); dialog.push_back(english_chars[0x00] & 0xFF);
                dialog.push_back(english_chars[0x00] >> 8); dialog.push_back(english_chars[0x00] & 0xFF);
                dialog.push_back(english_chars[0x00] >> 8); dialog.push_back(english_chars[0x00] & 0xFF);
            }
            else if (temp == 0xE1 && english == true)
            {
                dialog.push_back(english_chars[0x00] >> 8); dialog.push_back(english_chars[0x00] & 0xFF);
                dialog.push_back(english_chars[0x00] >> 8); dialog.push_back(english_chars[0x00] & 0xFF);
                dialog.push_back(english_chars[0x00] >> 8); dialog.push_back(english_chars[0x00] & 0xFF);
                dialog.push_back(english_chars[0x00] >> 8); dialog.push_back(english_chars[0x00] & 0xFF);
            }
            else if (temp == 0xE2 && english == true)
            {
                dialog.push_back(english_chars[0x0C] >> 8); dialog.push_back(english_chars[0x0C] & 0xFF);
                dialog.push_back(english_chars[0x00] >> 8); dialog.push_back(english_chars[0x00] & 0xFF);
            }
            else if (temp == 0xE8)
            {
                export_text->Log(dialog);
                dialog.clear();
                export_text->LogW("<new_window />");
            }
            else if (temp == 0xEA)
            {
                export_text->Log(dialog);
                dialog.clear();
                export_text->LogW("<character id=\"0\" />");
            }
            else if (temp == 0xEB)
            {
                export_text->Log(dialog);
                dialog.clear();
                export_text->LogW("<character id=\"1\" />");
            }
            else if (temp == 0xEC)
            {
                export_text->Log(dialog);
                dialog.clear();
                export_text->LogW("<character id=\"2\" />");
            }
            else if (temp == 0xED)
            {
                export_text->Log(dialog);
                dialog.clear();
                export_text->LogW("<character id=\"3\" />");
            }
            else if (temp == 0xEE)
            {
                export_text->Log(dialog);
                dialog.clear();
                export_text->LogW("<character id=\"4\" />");
            }
            else if (temp == 0xEF)
            {
                export_text->Log(dialog);
                dialog.clear();
                export_text->LogW("<character id=\"5\" />");
            }
            else if (temp == 0xF0)
            {
                export_text->Log(dialog);
                dialog.clear();
                export_text->LogW("<character id=\"6\" />");
            }
            else if (temp == 0xF1)
            {
                export_text->Log(dialog);
                dialog.clear();
                export_text->LogW("<character id=\"7\" />");
            }
            else if (temp == 0xF2)
            {
                export_text->Log(dialog);
                dialog.clear();
                export_text->LogW("<character id=\"8\" />");
            }
            else if (temp == 0xF3)
            {
                export_text->Log(dialog);
                dialog.clear();
                export_text->LogW("<character party_id=\"0\" />");
            }
            else if (temp == 0xF4)
            {
                export_text->Log(dialog);
                dialog.clear();
                export_text->LogW("<character party_id=\"1\" />");
            }
            else if (temp == 0xF5)
            {
                export_text->Log(dialog);
                dialog.clear();
                export_text->LogW("<character party_id=\"2\" />");
            }
            else if (temp == 0xF6)
            {
                export_text->Log(dialog);
                dialog.clear();
                export_text->LogW("<image id=\"circle\" />");
            }
            else if (temp == 0xF7)
            {
                export_text->Log(dialog);
                dialog.clear();
                export_text->LogW("<image id=\"triangle\" />");
            }
            else if (temp == 0xF8)
            {
                export_text->Log(dialog);
                dialog.clear();
                export_text->LogW("<image id=\"square\" />");
            }
            else if (temp == 0xF9)
            {
                export_text->Log(dialog);
                dialog.clear();
                export_text->LogW("<image id=\"cross\" />");
            }
            else if ((temp == 0xFA || temp == 0xFB ||temp == 0xFC ||temp == 0xFD) && english == false)
            {
                ++offset;
                unsigned char temp2 = GetU8(offset);

                if (temp == 0xFA)
                {
                    if (japanese_chars_fa[temp2] != 0x0000)
                    {
                        dialog.push_back(japanese_chars_fa[temp2] >> 8); dialog.push_back(japanese_chars_fa[temp2] & 0xFF);
                    }
                    else
                    {
                        export_text->Log(dialog);
                        dialog.clear();
                        export_text->LogW("[MISSING 0xFA " + ToHexString(temp2, 2, '0') + "]");
                    }
                }
                else if (temp == 0xFB)
                {
                    if (japanese_chars_fb[temp2] != 0x0000)
                    {
                        dialog.push_back(japanese_chars_fb[temp2] >> 8); dialog.push_back(japanese_chars_fb[temp2] & 0xFF);
                    }
                    else
                    {
                        export_text->Log(dialog);
                        dialog.clear();
                        export_text->LogW("[MISSING 0xFB " + ToHexString(temp2, 2, '0') + "]");
                    }
                }
                else if (temp == 0xFC)
                {
                    if (japanese_chars_fc[temp2] != 0x0000)
                    {
                        dialog.push_back(japanese_chars_fc[temp2] >> 8); dialog.push_back(japanese_chars_fc[temp2] & 0xFF);
                    }
                    else
                    {
                        export_text->Log(dialog);
                        dialog.clear();
                        export_text->LogW("[MISSING 0xFC " + ToHexString(temp2, 2, '0') + "]");
                    }
                }
                else if (temp == 0xFD)
                {
                    if (japanese_chars_fd[temp2] != 0x0000)
                    {
                        dialog.push_back(japanese_chars_fd[temp2] >> 8); dialog.push_back(japanese_chars_fd[temp2] & 0xFF);
                    }
                    else
                    {
                        export_text->Log(dialog);
                        dialog.clear();
                        export_text->LogW("[MISSING 0xFD " + ToHexString(temp2, 2, '0') + "]");
                    }
                }
            }
            else if (temp == 0xFE)
            {
                ++offset;

                unsigned char temp2 = GetU8(offset);

                if (temp2 == 0xD4)
                {
                    export_text->Log(dialog);
                    dialog.clear();
                    export_text->LogW("<colour id=\"red\" />");
                }
                else if (temp2 == 0xD5)
                {
                    export_text->Log(dialog);
                    dialog.clear();
                    export_text->LogW("<colour id=\"purple\" />");
                }
                else if (temp2 == 0xD6)
                {
                    export_text->Log(dialog);
                    dialog.clear();
                    export_text->LogW("<colour id=\"green\" />");
                }
                else if (temp2 == 0xD7)
                {
                    export_text->Log(dialog);
                    dialog.clear();
                    export_text->LogW("<colour id=\"cyan\" />");
                }
                else if (temp2 == 0xD8)
                {
                    export_text->Log(dialog);
                    dialog.clear();
                    export_text->LogW("<colour id=\"yellow\" />");
                }
                else if (temp2 == 0xD9)
                {
                    export_text->Log(dialog);
                    dialog.clear();
                    export_text->LogW("<colour id=\"white\" />");
                }
                else if (temp2 == 0xDC)
                {
                    export_text->Log(dialog);
                    dialog.clear();
                    export_text->LogW("<pause_ok />");
                }
                else if (temp2 == 0xDD)
                {
                    u16 wait = GetU16LE(offset + 1);
                    ++offset;
                    ++offset;
                    export_text->Log(dialog);
                    dialog.clear();
                    export_text->LogW("<pause wait=\"" + ToIntString(wait) + "\" />");
                }
                else
                {
                    if (japanese_chars_fe[temp2] != 0x0000 && english == false)
                    {
                        dialog.push_back(japanese_chars_fe[temp2] >> 8); dialog.push_back(japanese_chars_fe[temp2] & 0xFF);
                    }
                    else
                    {
                        export_text->Log(dialog);
                        dialog.clear();
                        export_text->LogW("[MISSING 0xFE " + ToHexString(temp2, 2, '0') + "]");
                    }
                }
            }
            else
            {
                if (japanese_chars[temp] != 0x0000 && english == false)
                {
                    dialog.push_back(japanese_chars[temp] >> 8); dialog.push_back(japanese_chars[temp] & 0xFF);
                }
                else if (english_chars[temp] != 0x0000 && english == true)
                {
                    dialog.push_back(english_chars[temp] >> 8); dialog.push_back(english_chars[temp] & 0xFF);
                }
                else
                {
                    export_text->Log(dialog);
                    dialog.clear();
                    export_text->LogW("[MISSING CHAR " + ToHexString(temp, 2, '0') + "]");
                }
            }
        }

        export_text->Log(dialog);
        dialog.clear();
        export_text->LogW("</dialog>\n\n");
    }

    delete export_text;
}



void
DatFile::DumpScriptData( const Ogre::String& export_path, const Field& field )
{
    Logger* export_script = new Logger( export_path + "maps/field/" + field.name + "_script.txt" );

    // get sector 1 offset (scripts and dialog)
    u32 start_address = GetU32LE( 0 );
    u32 offset_to_sector       = 0x1c;

    u8  number_of_entity        = GetU8( offset_to_sector + 0x02 );
    u16 string_offset           = GetU16LE( offset_to_sector + 0x04 );
    u16 number_of_extra_offsets = GetU16LE( offset_to_sector + 0x06 );

    std::vector< Ogre::String > entity_list;

    for( u8 i = 0; i < number_of_entity; ++i )
    {
        // get entity name
        Ogre::String name = Ogre::String( reinterpret_cast< char* >( m_Buffer ) + offset_to_sector + 0x20 + i * 0x08 );
        if( name == "" )
        {
            name = "unnamed_" + ToIntString( i );
        }
        entity_list.push_back( name );
    }

    for( u8 i = 0; i < number_of_entity; ++i )
    {
        export_script->Log(entity_list[i] + "\n");
        u32 prev_script = 0;
        bool one_ret_check = false;

        for (u8 j = 0; j < 32; ++j)
        {
            u32 script = offset_to_sector + GetU16LE(offset_to_sector + 0x20 + number_of_entity * 0x08 + number_of_extra_offsets * 0x04 + i * 0x40 + j * 0x02);
            u32 end = script;

            u8 opcode = GetU8(script);

            if (opcode == 0x00 && j != 0) // skip if script contain only RET opcode and this is not init script
            {
                continue;
            }
            if (prev_script == script)
            {
                continue;
            }
            prev_script = script;

            export_script->Log("script_" + ToIntString(j) + ":\n");

            for (; script <= end;)
            {
                export_script->Log(OffsetString(script) + " (end " + OffsetString(end) + "): ");

                u8 opcode = GetU8(script);

                if (opcode == 0x00) // RET
                {
                    export_script->Log("return;\n");

                    if (j == 0 && one_ret_check == false) // in init we need to meet ret at least once
                    {
                        AdvanceScript(1, script, end);
                        one_ret_check = true;
                    }
                    else
                    {
                        script += 1;
                    }
                }
                else if (opcode == 0x01) // REQ
                {
                    u8 entity_id = GetU8(script + 1);
                    u8 priority  = GetU8(script + 2) >> 5;
                    u8 script_id = GetU8(script + 2) & 0x1F;

                    export_script->Log(
                        "script:request( \"" +
                        entity_list[entity_id] +
                        "\", \"script_" +
                        ToIntString(script_id) +
                        "\", " +
                        ToIntString(priority) +
                        " );\n"
                    );

                    AdvanceScript(3, script, end);
                }
                else if (opcode == 0x02) // REQSW
                {
                    u8 entity_id = GetU8(script + 1);
                    u8 priority  = GetU8(script + 2) >> 5;
                    u8 script_id = GetU8(script + 2) & 0x1F;

                    export_script->Log(
                        "script:request_start_wait( \"" +
                        entity_list[entity_id] +
                        "\", \"script_" +
                        ToIntString(script_id) +
                        "\", " +
                        ToIntString(priority) +
                        " );\n"
                    );

                    AdvanceScript(3, script, end);
                }
                else if (opcode == 0x03) // REQEW
                {
                    u8 entity_id = GetU8(script + 1);
                    u8 priority  = GetU8(script + 2) >> 5;
                    u8 script_id = GetU8(script + 2) & 0x1F;

                    export_script->Log(
                        "script:request_end_wait( \"" +
                        entity_list[entity_id] +
                        "\", \"script_" +
                        ToIntString(script_id) +
                        "\", " +
                        ToIntString(priority) +
                        " );\n"
                    );

                    AdvanceScript(3, script, end);
                }
                else if (opcode == 0x07) // RETTO
                {
                    u8 priority  = GetU8(script + 1) >> 5;
                    u8 script_id = GetU8(script + 1) & 0x1F;

                    export_script->Log(
                        "return_to( \"script_" +
                        ToIntString(script_id) +
                        "\", " +
                        ToIntString(priority) +
                        " );\n"
                    );

                    script += 2;
                }
                else if (opcode == 0x08) // JOIN
                {
                    export_script->Log(
                        "[UNREVERSED] JOIN(" +
                        ArgumentString(script + 1, 1) +
                        ");\n"
                    );

                    AdvanceScript(2, script, end);
                }
                else if (opcode == 0x09) // SPLIT
                {
                    export_script->Log(
                        "[UNREVERSED] SPLIT(" +
                        ArgumentString(script + 1, 14) +
                        ");\n"
                    );

                    AdvanceScript(15, script, end);
                }
                else if (opcode == 0x0A) // SPTYE
                {
                    export_script->Log(
                        "game:party_set( " +
                        ParseGetVariable(GetU8(script + 1) >> 4, GetU8(script + 3)) +
                        ", " +
                        ParseGetVariable(GetU8(script + 1) & 0x0F, GetU8(script + 4)) +
                        ", " +
                        ParseGetVariable(GetU8(script + 2) >> 4, GetU8(script + 5)) +
                        " );\n"
                    );
                    AdvanceScript(6, script, end);
                }
                else if (opcode == 0x0B) // GTPYE
                {
                    export_script->Log(
                        SetVariable(GetU8(script + 1) >> 4, GetU8(script + 3), "game:party_get_id_of_member( 0 )") +
                        SetVariable(GetU8(script + 1) & 0x0F, GetU8(script + 4), "game:party_get_id_of_member( 1 )") +
                        SetVariable(GetU8(script + 2) >> 4, GetU8(script + 5), "game:party_get_id_of_member( 2 )")
                    );
                    AdvanceScript(6, script, end);
                }
                else if (opcode == 0x0F) // SPECIAL
                {
                    u8 special_opcode = GetU8(script + 1);

                    if (special_opcode == 0xF5) // ARROW
                    {
                        export_script->Log(
                            "game:pointer_enable( " +
                            ToBoolString(!(bool)(GetU8(script + 2))) +
                            " )\n"
                        );
                        AdvanceScript(3, script, end);
                    }
                    else if (special_opcode == 0xF9) // FLMAT
                    {
                        export_script->Log("game:fill_materia()\n");
                        AdvanceScript(2, script, end);
                    }
                    else if (special_opcode == 0xFB) // BTLLK
                    {
                        export_script->Log(
                            "game:battle_enable( " +
                            ToBoolString(!(bool)(GetU8(script + 2))) +
                            " )\n"
                        );
                        AdvanceScript(3, script, end);
                    }
                    else if (special_opcode == 0xFC) // MVLCK
                    {
                        export_script->Log(
                            "game:movie_enable( " +
                            ToBoolString(!(bool)(GetU8(script + 2))) +
                            " )\n"
                        );
                        AdvanceScript(3, script, end);
                    }
                    else if (special_opcode == 0xFD) // SPCNM
                    {
                        export_script->Log(
                            "[UNREVERSED] SPECIAL SPCNM(" +
                            ArgumentString(script + 2, 2) +
                            ");\n"
                        );
                        AdvanceScript(4, script, end);
                    }
                    else if (special_opcode == 0xFE) // RSGLB
                    {
                        export_script->Log("game:global_reset()\n");
                        AdvanceScript(2, script, end);
                    }
                    else
                    {
                        export_script->Log("[SPECIAL OPCODE " + ToHexString(special_opcode, 2, '0') + "]\n");
                        script += 2;
                    }
                }
                else if (opcode == 0x10) // JMPF
                {
                    u32 temp_end = script + GetU8(script + 1) + 1;

                    export_script->Log(
                        "jumpto( " +
                        OffsetString(temp_end) +
                        " );\n"
                    );

                    end = (temp_end > end) ? temp_end : end;
                    script += 2;
                }
                else if (opcode == 0x11) // JMPFL
                {
                    u32 temp_end = script + GetU16LE(script + 1) + 1;

                    export_script->Log(
                        "jumpto( " +
                        OffsetString(temp_end) +
                        " );\n"
                    );

                    end = (temp_end > end) ? temp_end : end;
                    script += 3;
                }
                else if (opcode == 0x12) // JMPB
                {
                    export_script->Log(
                        "jumpto( " +
                        OffsetString(script - GetU8(script + 1)) +
                        " );\n"
                    );

                    script += 2;
                }
                else if (opcode == 0x13) // JMPBL
                {
                    export_script->Log(
                        "jumpto( " +
                        OffsetString(script - GetU16LE(script + 1)) +
                        " );\n"
                    );

                    script += 3;
                }
                else if (opcode == 0x14) // IFUB
                {
                    u32 temp_end = script + GetU8(script + 5) + 5;

                    export_script->Log(
                        "if ( " +
                        ParseRelation(GetU8(script + 4), ParseGetVariable(GetU8(script + 1) >> 4, GetU8(script + 2)), ParseGetVariable(GetU8(script + 1) & 0x0F, GetU8(script + 3))) +
                        " ) then continue else jumpto(" + OffsetString(temp_end) + ");\n"
                    );

                    end = (temp_end > end) ? temp_end : end;
                    script += 6;
                }
                else if (opcode == 0x15) // IFUBL
                {
                    u32 temp_end = script + GetU16LE(script + 5) + 5;

                    export_script->Log(
                        "if ( " +
                        ParseRelation(GetU8(script + 4), ParseGetVariable(GetU8(script + 1) >> 4, GetU8(script + 2)), ParseGetVariable(GetU8(script + 1) & 0x0F, GetU8(script + 3))) +
                        " ) then continue else jumpto(" + OffsetString(temp_end) + ");\n"
                    );

                    end = (temp_end > end) ? temp_end : end;
                    script += 7;
                }
                else if (opcode == 0x16) // IFSW
                {
                    u32 temp_end = script + GetU8(script + 7) + 7;

                    export_script->Log(
                        "if ( " +
                        ParseRelation(GetU8(script + 6), ParseGetVariable(GetU8(script + 1) >> 4, (s16)GetU16LE(script + 2)), ParseGetVariable(GetU8(script + 1) & 0x0F, (s16)GetU16LE(script + 4))) +
                        " ) then continue else jumpto(" + OffsetString(temp_end) + ");\n"
                    );

                    end = (temp_end > end) ? temp_end : end;
                    script += 8;
                }
                else if (opcode == 0x17) // IFSWL
                {
                    u32 temp_end = script + GetU16LE(script + 7) + 7;

                    export_script->Log(
                        "if ( " +
                        ParseRelation(GetU8(script + 6), ParseGetVariable(GetU8(script + 1) >> 4, (s16)GetU16LE(script + 2)), ParseGetVariable(GetU8(script + 1) & 0x0F, (s16)GetU16LE(script + 4))) +
                        " ) then continue else jumpto(" + OffsetString(temp_end) + ");\n"
                    );

                    end = (temp_end > end) ? temp_end : end;
                    script += 9;
                }
                else if (opcode == 0x18) // IFUW
                {
                    u32 temp_end = script + GetU8(script + 7) + 7;

                    export_script->Log(
                        "if ( " +
                        ParseRelation(GetU8(script + 6), ParseGetVariable(GetU8(script + 1) >> 4, GetU16LE(script + 2)), ParseGetVariable(GetU8(script + 1) & 0x0F, GetU16LE(script + 4))) +
                        " ) then continue else jumpto(" + OffsetString(temp_end) + ");\n"
                    );

                    end = (temp_end > end) ? temp_end : end;
                    script += 8;
                }
                else if (opcode == 0x21) // TUTOR
                {
                    export_script->Log(
                        "[UNREVERSED] TUTOR(" +
                        ArgumentString(script + 1, 1) +
                        ");\n"
                    );

                    AdvanceScript(2, script, end);
                }
                else if (opcode == 0x24) // WAIT
                {
                    export_script->Log(
                        "script:wait( " +
                        ToFloatString(GetU16LE(script + 1) / 30.0f) +
                        " );\n"
                    );

                    AdvanceScript(3, script, end);
                }
                else if (opcode == 0x25) // NFADE
                {
                    u8 type  = GetU8(script + 3);

                    if (type == 0)
                    {
                        export_script->Log("fade:clear();\n");
                    }
                    else
                    {
                        export_script->Log(
                            "[NEEDS TO CHECK NFADE time needs to be divided] fade:fade(" +
                            ParseGetVariable(GetU8(script + 1) >> 4, GetU16LE(script + 4)) +
                            ", " +
                            ParseGetVariable(GetU8(script + 1) & 0x0F, GetU16LE(script + 5)) +
                            ", " +
                            ParseGetVariable(GetU8(script + 2) >> 4, GetU16LE(script + 6)) +
                            ", " +
                            ((type == 12) ? "Fade.SUBTRACT" : "Fade.ADD") +
                            ", " +
                            ParseGetVariable(GetU8(script + 2) & 0x0F, GetU16LE(script + 7)) +
                            ");\n"
                        );
                    }

                    AdvanceScript(9, script, end);
                }
                else if (opcode == 0x26) // BLINK
                {
                    export_script->Log(
                        entity_list[i] +
                        ":enable_eye_blink(" +
                        ToBoolString(!(bool)(GetU8(script + 1))) +
                        ");\n"
                    );

                    AdvanceScript(2, script, end);
                }
                else if (opcode == 0x28) // KAWAI
                {
                    u8 kawai_length = GetU8(script + 1);

                    export_script->Log(
                        "[UNREVERSED] KAWAI(" +
                        ArgumentString(script + 1, kawai_length - 1) +
                        ");\n"
                    );

                    AdvanceScript(kawai_length, script, end);
                }
                else if (opcode == 0x2E) // WCLS
                {
                    export_script->Log(
                        "[UNREVERSED] WCLS(" +
                        ArgumentString(script + 1, 1) +
                        ");\n"
                    );

                    AdvanceScript(2, script, end);
                }
                else if (opcode == 0x2F) // WSIZW
                {
                    u8 type = GetU8(script + 2);

                    export_script->Log(
                        "-- resize window (id = " +
                        ToIntString(GetU8(script + 1)) +
                        ", x = " +
                        ToIntString(GetU16LE(script + 2)) +
                        ", y = " +
                        ToIntString(GetU16LE(script + 4)) +
                        ", width = " +
                        ToIntString(GetU16LE(script + 6)) +
                        ", height = " +
                        ToIntString(GetU16LE(script + 8)) +
                        ");\n"
                    );

                    AdvanceScript(10, script, end);
                }
                else if (opcode == 0x30) // IFKEY
                {
                    u32 temp_end = script + GetU8(script + 3) + 3;

                    export_script->Log(
                        "if (pressed buttons \"" +
                        ToHexString(GetU16LE(script + 1), 4, '0') +
                        "\") then continue else jumpto(" + OffsetString(temp_end) + ");\n"
                    );

                    end = (temp_end > end) ? temp_end : end;
                    script += 4;
                }
                else if (opcode == 0x31) // IFKEYON
                {
                    u32 temp_end = script + GetU8(script + 3) + 3;

                    export_script->Log(
                        "if (first pressed buttons \"" +
                        ToHexString(GetU16LE(script + 1), 4, '0') +
                        "\") then continue else jumpto(" + OffsetString(temp_end) + ");\n"
                    );

                    end = (temp_end > end) ? temp_end : end;
                    script += 4;
                }
                else if (opcode == 0x33) // UC
                {
                    export_script->Log(
                        "field:pc_lock(" +
                        ToBoolString((bool)(GetU8(script + 1))) +
                        ");\n"
                    );

                    AdvanceScript(2, script, end);
                }
                else if (opcode == 0x36) // WSPCL
                {
                    export_script->Log(
                        "[UNREVERSED] WSPCL(" +
                        ArgumentString(script + 1, 4) +
                        ");\n"
                    );

                    AdvanceScript(5, script, end);
                }
                else if (opcode == 0x38) // STTIM
                {
                    export_script->Log(
                        "game:set_timer(hours(" +
                        ParseGetVariable(GetU8(script + 1) >> 4, GetU8(script + 3)) +
                        "), minutes(" +
                        ParseGetVariable(GetU8(script + 1) & 0x0F, GetU8(script + 4)) +
                        "), seconds(" +
                        ParseGetVariable(GetU8(script + 2) & 0x0F, GetU8(script + 5)) +
                        "));\n"
                    );
                    AdvanceScript(6, script, end);
                }
                else if (opcode == 0x39) // GOLDU
                {
                    export_script->Log(
                        "game:add_money(upper(" +
                        ParseGetVariable(GetU8(script + 1) & 0x0F, GetU16LE(script + 4)) +
                        "), lower(" +
                        ParseGetVariable(GetU8(script + 1) >> 4, GetU16LE(script + 2)) +
                        "));\n"
                    );
                    AdvanceScript(6, script, end);
                }
                else if (opcode == 0x3A) // GOLDD
                {
                    export_script->Log(
                        "game:remove_money(upper(" +
                        ParseGetVariable(GetU8(script + 1) & 0x0F, GetU16LE(script + 4)) +
                        "), lower(" +
                        ParseGetVariable(GetU8(script + 1) >> 4, GetU16LE(script + 2)) +
                        "));\n"
                    );
                    AdvanceScript(6, script, end);
                }
                else if (opcode == 0x3B) // CHGLD
                {
                    export_script->Log(
                        SetVariable(GetU8(script + 1) >> 4, GetU8(script + 2), "game:get_money_lower()") +
                        SetVariable(GetU8(script + 1) & 0x0F, GetU8(script + 3), "game:get_money_top()")
                    );
                    AdvanceScript(4, script, end);
                }
                else if (opcode == 0x3E) // MHMMX
                {
                    export_script->Log(
                        "game:restore_hp_mp_status_to_all();\n"
                    );
                    AdvanceScript(1, script, end);
                }
                else if (opcode == 0x3F) // HMPMAX3
                {
                    export_script->Log(
                        "game:party_restore_hp_mp();\n"
                    );
                    AdvanceScript(1, script, end);
                }
                else if (opcode == 0x40) // MESSAGE
                {
                    m_Dialogs.push_back(GetU8(script + 2));
                    export_script->Log(
                        "message:show_text_wait(" +
                        ToIntString(GetU8(script + 1)) +
                        ", " +
                        ToIntString(GetU8(script + 2)) +
                        ", x, y);\n"
                    );

                    AdvanceScript(3, script, end);
                }
                else if (opcode == 0x43) // MPNAM
                {
                    m_Dialogs.push_back(GetU8(script + 1));
                    export_script->Log(
                        "field:map_name(" +
                        ToIntString(GetU8(script + 1)) +
                        ");\n"
                    );

                    AdvanceScript(2, script, end);
                }
                else if (opcode == 0x48) // ASK
                {
                    m_Dialogs.push_back(GetU8(script + 3));
                    export_script->Log(
                        "message:show_text_wait(" +
                        ToIntString(GetU8(script + 2)) +
                        ", " +
                        ToIntString(GetU8(script + 3)) +
                        ", x, y); -- ASK cursor at \"" +
                        ParseGetVariable(GetU8(script + 1), GetU8(script + 6)) +
                        "\", start " +
                        ToIntString(GetU8(script + 4)) +
                        ", end " +
                        ToIntString(GetU8(script + 5)) +
                        "\n"
                    );

                    AdvanceScript(7, script, end);
                }
                else if (opcode == 0x49) // MENU
                {
                    export_script->Log(
                        "[UNREVERSED] MENU(" +
                        ArgumentString(script + 1, 3) +
                        ");\n"
                    );

                    AdvanceScript(4, script, end);
                }
                else if (opcode == 0x4A) // MENU2
                {
                    export_script->Log(
                        "field:menu_lock(" +
                        ToBoolString((bool)(GetU8(script + 1))) +
                        ");\n"
                    );

                    AdvanceScript(2, script, end);
                }
                else if (opcode == 0x4B) // BTLTB
                {
                    export_script->Log(
                        "field:set_battle_table(" +
                        ToIntString(GetU8(script + 1)) +
                        ");\n"
                    );

                    AdvanceScript(2, script, end);
                }
                else if (opcode == 0x50) // WINDOW
                {
                    export_script->Log(
                        "-- set window parameters (id = " +
                        ToIntString(GetU8(script + 1)) +
                        ", x = " +
                        ToIntString(GetU16LE(script + 2)) +
                        ", y = " +
                        ToIntString(GetU16LE(script + 4)) +
                        ", width = " +
                        ToIntString(GetU16LE(script + 6)) +
                        ", height = " +
                        ToIntString(GetU16LE(script + 8)) +
                        ");\n"
                    );

                    AdvanceScript(10, script, end);
                }
                else if (opcode == 0x52) // WMODE
                {
                    u8 type = GetU8(script + 2);

                    export_script->Log(
                        "-- set window mode (id = " +
                        ToIntString(GetU8(script + 1)) +
                        ", MessageStyle." +
                        ((type == 0) ? "SOLID" : ((type == 1) ? "NONE" : "TRANSPARENT")) +
                        ", disable input from player: " +
                        ToBoolString((bool)(GetU8(script + 3))) +
                        ");\n"
                    );

                    AdvanceScript(4, script, end);
                }
                else if (opcode == 0x53) // WREST
                {
                    export_script->Log(
                        "-- reset window to default (id = " +
                        ToIntString(GetU8(script + 1)) +
                        ");\n"
                    );

                    AdvanceScript(2, script, end);
                }
                else if (opcode == 0x54) // WCLSE
                {
                    export_script->Log(
                        "[UNREVERSED] WCLSE(" +
                        ArgumentString(script + 1, 1) +
                        ");\n"
                    );

                    AdvanceScript(2, script, end);
                }
                else if (opcode == 0x58) // STITM
                {
                    export_script->Log(
                        "game:item_add(" +
                        ParseGetVariable(GetU8(script + 1) >> 4, GetU16LE(script + 2)) +
                        ", " +
                        ParseGetVariable(GetU8(script + 1) & 0x0F, GetU8(script + 4)) +
                        ");\n"
                    );

                    AdvanceScript(5, script, end);
                }
                else if (opcode == 0x5A) // CKITM
                {
                    export_script->Log(
                        SetVariable(GetU8(script + 1), GetU8(script + 4), "game:get_number_of_item(" + ToIntString(GetU16LE(script + 2)) + ")")
                    );
                    AdvanceScript(5, script, end);
                }
                else if (opcode == 0x5B) // SMTRA
                {
                    export_script->Log(
                        "game:materia_add(" +
                        ParseGetVariable(GetU8(script + 1) >> 4, GetU16LE(script + 3)) +
                        ", " +
                        ParseGetVariable(GetU8(script + 1) & 0x0F, GetU8(script + 4)) +
                        ", " +
                        ParseGetVariable(GetU8(script + 2) >> 4, GetU16LE(script + 5)) +
                        ", " +
                        ParseGetVariable(GetU8(script + 2) & 0x0F, GetU8(script + 6)) +
                        ");\n"
                    );

                    AdvanceScript(7, script, end);
                }
                else if (opcode == 0x5E) // SHAKE
                {
                    export_script->Log(
                        "[UNREVERSED] SHAKE(" +
                        ArgumentString(script + 1, 7) +
                        ");\n"
                    );

                    AdvanceScript(8, script, end);
                }
                else if (opcode == 0x60) // MAPJUMP
                {
                    export_script->Log(
                        "field:jump_to_map(" +
                        ToIntString(GetU16LE(script + 1)) +
                        ", " +
                        ToIntString(GetU16LE(script + 3)) +
                        ", " +
                        ToIntString(GetU16LE(script + 5)) +
                        ", " +
                        ToIntString(GetU16LE(script + 7)) +
                        ", " +
                        ToFloatString((GetU8(script + 9) / 256.0f) * 360.0f) +
                        ");\n"
                    );

                    AdvanceScript(10, script, end);
                }
                else if (opcode == 0x62) // SCRLC
                {
                    int type = GetU8(script + 4);

                    export_script->Log(
                        "field:screen_set_scroll_to_pc(" +
                        ((type == 4) ? "Field.NONE" : ((type == 5) ? "Field.LINEAR" : ((type == 6) ? "Field.SMOOTH" : "Unknown_type_" + ToIntString(type)))) +
                        ", " +
                        ParseGetVariable(GetU8(script + 1) & 0x0F, GetU16LE(script + 2), false, 30.0f) +
                        ");\n"
                    );

                    AdvanceScript(5, script, end);
                }
                else if (opcode == 0x63) // SCRLA
                {
                    int type = GetU8(script + 5);

                    export_script->Log(
                        "field:screen_set_scroll_to_entity(" +
                        entity_list[GetU8(script + 4)] +
                        ", " +
                        ((type == 1) ? "Field.NONE" : ((type == 2) ? "Field.LINEAR" : ((type == 3) ? "Field.SMOOTH" : "Unknown_type_" + ToIntString(type)))) +
                        ", " +
                        ParseGetVariable(GetU8(script + 1), GetU16LE(script + 2), false, 30.0f) +
                        ");\n"
                    );

                    AdvanceScript(6, script, end);
                }
                else if (opcode == 0x64) // SCR2D
                {
                    export_script->Log(
                        "field:screen_set_scroll_to_coords_instant( " +
                        ParseGetVariable(GetU8(script + 1) >> 4, GetU16LE(script + 2)) +
                        ", " +
                        ParseGetVariable(GetU8(script + 1) & 0x0F, GetU16LE(script + 4)) +
                        " );\n"
                    );

                    AdvanceScript(6, script, end);
                }
                else if (opcode == 0x65) // SCRCC
                {
                    export_script->Log(
                        "field:screen_set_scroll_to_pc_instant(); -- SCRCC\n"
                    );

                    AdvanceScript(1, script, end);
                }
                else if (opcode == 0x66) // SCR2DC
                {
                    export_script->Log(
                        "field:screen_set_scroll_to_coords_smooth( " +
                        ParseGetVariable(GetU8(script + 1) >> 4, GetU16LE(script + 3)) +
                        ", " +
                        ParseGetVariable(GetU8(script + 1) & 0x0F, GetU16LE(script + 5)) +
                        ", " +
                        ParseGetVariable(GetU8(script + 2) & 0x0F, GetU16LE(script + 7), false, 30.0f) +
                        " );\n"
                    );

                    AdvanceScript(9, script, end);
                }
                else if (opcode == 0x67) // SCRLW
                {
                    export_script->Log("field:screen_scroll_wait();\n");
                    AdvanceScript(1, script, end);
                }
                else if (opcode == 0x68) // SCR2DL
                {
                    export_script->Log(
                        "field:screen_set_scroll_to_coords_linear( " +
                        ParseGetVariable(GetU8(script + 1) >> 4, GetU16LE(script + 3)) +
                        ", " +
                        ParseGetVariable(GetU8(script + 1) & 0x0F, GetU16LE(script + 5)) +
                        ", " +
                        ParseGetVariable(GetU8(script + 2) & 0x0F, GetU16LE(script + 7), false, 30.0f) +
                        " );\n"
                    );

                    AdvanceScript(9, script, end);
                }
                else if (opcode == 0x6A) // VWOFT
                {
                    export_script->Log(
                        "[UNREVERSED] VWOFT(" +
                        ArgumentString(script + 1, 6) +
                        ");\n"
                    );

                    AdvanceScript(7, script, end);
                }
                else if (opcode == 0x6B) // FADE
                {
                    u8 type  = GetU8(script + 7);

                    if (type == 4)
                    {
                        export_script->Log("fade:black();\n");
                    }
                    else
                    {
                        u8 speed = GetU8(script + 6);
                        u8 start = GetU8(script + 8);

                        export_script->Log(
                            "[NEEDS TO CHECK FADE] fade:fade( " +
                            ParseGetVariable(GetU8(script + 1) >> 4, GetU16LE(script + 3)) +
                            ", " +
                            ParseGetVariable(GetU8(script + 1) & 0x0F, GetU16LE(script + 4)) +
                            ", " +
                            ParseGetVariable(GetU8(script + 2) & 0x0F, GetU16LE(script + 5)) +
                            ", " +
                            ((type == 1 || type == 2 || type == 7 || type == 8) ? "Fade.SUBTRACT" : "Fade.ADD") +
                            ", " +
                            ToIntString(speed) +
                            ", " +
                            ToIntString(start) +
                            " );\n"
                        );
                    }

                    AdvanceScript(9, script, end);
                }
                else if (opcode == 0x6C) // FADEW
                {
                    export_script->Log("fade:wait();\n");
                    AdvanceScript(1, script, end);
                }
                else if (opcode == 0x6D) // IDLCK
                {
                    export_script->Log(
                        "field:lock_walkmesh( " +
                        ToIntString(GetU16LE(script + 1)) +
                        ", " +
                        ToBoolString((bool)(GetU8(script + 3))) +
                        " );\n"
                    );

                    AdvanceScript(4, script, end);
                }
                else if (opcode == 0x6E) // LSTMP
                {
                    export_script->Log(
                        SetVariable(GetU8(script + 1), GetU8(script + 2), "field:get_last_map()")
                    );
                    AdvanceScript(3, script, end);
                }
                else if (opcode == 0x70) // BATTLE
                {
                    export_script->Log(
                        "field:battle_run( " +
                        ParseGetVariable(GetU8(script + 1), GetU16LE(script + 2)) +
                        " );\n"
                    );

                    AdvanceScript(4, script, end);
                }
                else if (opcode == 0x71) // BTLON
                {
                    export_script->Log(
                        "field:random_encounter_on( " +
                        ToBoolString(!(bool)(GetU8(script + 1))) +
                        " );\n"
                    );

                    AdvanceScript(2, script, end);
                }
                else if (opcode == 0x72) // BTLMD
                {
                    export_script->Log(
                        "[UNREVERSED] BTLMD(" +
                        ArgumentString(script + 1, 2) +
                        ");\n"
                    );

                    AdvanceScript(3, script, end);
                }
                else if (opcode == 0x76) // PLUS!
                {
                    export_script->Log(
                        SetVariable(GetU8(script + 1) >> 4, GetU8(script + 2), "( ( " + ParseGetVariable(GetU8(script + 1) >> 4, GetU8(script + 2)) + " + " + ParseGetVariable(GetU8(script + 1) & 0x0F, GetU8(script + 3)) + " > 255 ) ? 255 : " + ParseGetVariable(GetU8(script + 1) >> 4, GetU8(script + 2)) + " + " + ParseGetVariable(GetU8(script + 1) & 0x0F, GetU8(script + 3)) + " )")
                    );
                    AdvanceScript(4, script, end);
                }
                else if (opcode == 0x77) // PLUS2!
                {
                    export_script->Log(
                        SetVariable(GetU8(script + 1) >> 4, GetU8(script + 2), "( ( " + ParseGetVariable(GetU8(script + 1) >> 4, GetU8(script + 2)) + " + " + ParseGetVariable(GetU8(script + 1) & 0x0F, GetU16LE(script + 3)) + " > 65535 ) ? 65535 : " + ParseGetVariable(GetU8(script + 1) >> 4, GetU8(script + 2)) + " + " + ParseGetVariable(GetU8(script + 1) & 0x0F, GetU16LE(script + 3)) + " )")
                    );
                    AdvanceScript(5, script, end);
                }
                else if (opcode == 0x78) // MINUS!
                {
                    export_script->Log(
                        SetVariable(GetU8(script + 1) >> 4, GetU8(script + 2), "( ( " + ParseGetVariable(GetU8(script + 1) >> 4, GetU8(script + 2)) + " - " + ParseGetVariable(GetU8(script + 1) & 0x0F, GetU8(script + 3)) + " < 0 ) ? 0 : " + ParseGetVariable(GetU8(script + 1) >> 4, GetU8(script + 2)) + " - " + ParseGetVariable(GetU8(script + 1) & 0x0F, GetU8(script + 3)) + " )")
                    );
                    AdvanceScript(4, script, end);
                }
                else if (opcode == 0x79) // MINUS2!
                {
                    export_script->Log(
                        SetVariable(GetU8(script + 1) >> 4, GetU8(script + 2), "( ( " + ParseGetVariable(GetU8(script + 1) >> 4, GetU8(script + 2)) + " - " + ParseGetVariable(GetU8(script + 1) & 0x0F, GetU16LE(script + 3)) + " < 0 ) ? 0 : " + ParseGetVariable(GetU8(script + 1) >> 4, GetU8(script + 2)) + " - " + ParseGetVariable(GetU8(script + 1) & 0x0F, GetU16LE(script + 3)) + " )")
                    );
                    AdvanceScript(5, script, end);
                }
                else if (opcode == 0x7A) // INC!
                {
                    export_script->Log(
                        SetVariable(GetU8(script + 1), GetU8(script + 2), "( ( " + ParseGetVariable(GetU8(script + 1), GetU8(script + 2)) + " + 1 > 255 ) ? 255 : " + ParseGetVariable(GetU8(script + 1), GetU8(script + 2)) + " + 1 )")
                    );
                    AdvanceScript(3, script, end);
                }
                else if (opcode == 0x7E) // TALKON
                {
                    export_script->Log(
                        entity_list[i] +
                        ":set_talkable( " +
                        ToBoolString(!(bool)(GetU8(script + 1))) +
                        " );\n"
                    );

                    AdvanceScript(2, script, end);
                }
                else if (opcode == 0x80) // SETBYTE
                {
                    export_script->Log(
                        SetVariable(GetU8(script + 1) >> 4, GetU8(script + 2), ParseGetVariable(GetU8(script + 1) & 0x0F, GetU8(script + 3)))
                    );
                    AdvanceScript(4, script, end);
                }
                else if (opcode == 0x81) // SETWORD
                {
                    export_script->Log(
                        SetVariable(GetU8(script + 1) >> 4, GetU8(script + 2), ParseGetVariable(GetU8(script + 1) & 0x0F, GetU16LE(script + 3)))
                    );
                    AdvanceScript(5, script, end);
                }
                else if (opcode == 0x82) // BITON
                {
                    export_script->Log(SetBitChange(GetU8(script + 1) >> 4, GetU8(script + 2), GetU8(script + 1) & 0x0F, GetU8(script + 3), true));

                    AdvanceScript(4, script, end);
                }
                else if (opcode == 0x83) // BITOFF
                {
                    export_script->Log(SetBitChange(GetU8(script + 1) >> 4, GetU8(script + 2), GetU8(script + 1) & 0x0F, GetU8(script + 3), false));

                    AdvanceScript(4, script, end);
                }
                else if (opcode == 0x85) // PLUS
                {
                    export_script->Log(
                        SetVariable(GetU8(script + 1) >> 4, GetU8(script + 2), ParseGetVariable(GetU8(script + 1) >> 4, GetU8(script + 2)) + " + " + ParseGetVariable(GetU8(script + 1) & 0x0F, GetU8(script + 3)))
                    );
                    AdvanceScript(4, script, end);
                }
                else if (opcode == 0x87) // MINUS
                {
                    export_script->Log(
                        SetVariable(GetU8(script + 1) >> 4, GetU8(script + 2), ParseGetVariable(GetU8(script + 1) >> 4, GetU8(script + 2)) + " - " + ParseGetVariable(GetU8(script + 1) & 0x0F, GetU8(script + 3)))
                    );
                    AdvanceScript(4, script, end);
                }
                else if (opcode == 0x89) // MUL
                {
                    export_script->Log(
                        SetVariable(GetU8(script + 1) >> 4, GetU8(script + 2), "((" + ParseGetVariable(GetU8(script + 1) >> 4, GetU8(script + 2)) + " * " + ParseGetVariable(GetU8(script + 1) & 0x0F, GetU8(script + 3)) + " > 255) ? 255 : " + ParseGetVariable(GetU8(script + 1) >> 4, GetU8(script + 2)) + " * " + ParseGetVariable(GetU8(script + 1) & 0x0F, GetU8(script + 3)) + ")")
                    );
                    AdvanceScript(4, script, end);
                }
                else if (opcode == 0x8D) // MOD
                {
                    export_script->Log(
                        SetVariable(GetU8(script + 1) >> 4, GetU8(script + 2), ParseGetVariable(GetU8(script + 1) >> 4, GetU8(script + 2)) + " % " + ParseGetVariable(GetU8(script + 1) & 0x0F, GetU8(script + 3)))
                    );
                    AdvanceScript(4, script, end);
                }
                else if (opcode == 0x8F) // AND
                {
                    export_script->Log(
                        SetVariable(GetU8(script + 1) >> 4, GetU8(script + 2), ParseGetVariable(GetU8(script + 1) >> 4, GetU8(script + 2)) + " & " + ParseGetVariable(GetU8(script + 1) & 0x0F, GetU8(script + 3)))
                    );
                    AdvanceScript(4, script, end);
                }
                else if (opcode == 0x90) // AND2
                {
                    export_script->Log(
                        SetVariable(GetU8(script + 1) >> 4, GetU8(script + 2), ParseGetVariable(GetU8(script + 1) >> 4, GetU8(script + 2)) + " & " + ParseGetVariable(GetU8(script + 1) & 0x0F, GetU16LE(script + 3)))
                    );
                    AdvanceScript(5, script, end);
                }
                else if (opcode == 0x91) // OR
                {
                    export_script->Log(
                        SetVariable(GetU8(script + 1) >> 4, GetU8(script + 2), ParseGetVariable(GetU8(script + 1) >> 4, GetU8(script + 2)) + " | " + ParseGetVariable(GetU8(script + 1) & 0x0F, GetU8(script + 3)))
                    );
                    AdvanceScript(4, script, end);
                }
                else if (opcode == 0x92) // OR2
                {
                    export_script->Log(
                        SetVariable(GetU8(script + 1) >> 4, GetU8(script + 2), ParseGetVariable(GetU8(script + 1) >> 4, GetU8(script + 2)) + " | " + ParseGetVariable(GetU8(script + 1) & 0x0F, GetU16LE(script + 3)))
                    );
                    AdvanceScript(5, script, end);
                }
                else if (opcode == 0x95) // INC
                {
                    export_script->Log(
                        SetVariable(GetU8(script + 1), GetU8(script + 2), ParseGetVariable(GetU8(script + 1), GetU8(script + 2)) + " + 1")
                    );
                    AdvanceScript(3, script, end);
                }
                else if (opcode == 0x97) // DEC
                {
                    export_script->Log(
                        SetVariable(GetU8(script + 1), GetU8(script + 2), ParseGetVariable(GetU8(script + 1), GetU8(script + 2)) + " - 1")
                    );
                    AdvanceScript(3, script, end);
                }
                else if (opcode == 0x99) // RANDOM
                {
                    export_script->Log(
                        SetVariable(GetU8(script + 1), GetU8(script + 2), "math.rand()")
                    );
                    AdvanceScript(3, script, end);
                }
                else if (opcode == 0xA0) // PC
                {
                    export_script->Log(
                        "field:set_entity_to_character(\"" +
                        entity_list[i] +
                        "\", " +
                        ToIntString(GetU8(script + 1)) +
                        ");\n"
                    );

                    AdvanceScript(2, script, end);
                }
                else if (opcode == 0xA1) // CHAR
                {
                    export_script->Log(
                        "-- assosiate entity with model (CHAR) argument doesn't matter;\n"
                    );

                    AdvanceScript(2, script, end);
                }
                else if (opcode == 0xA2) // DFANM
                {
                    export_script->Log(
                        entity_list[i] +
                        ":set_animation_default(\"" +
                        ToIntString(GetU8(script + 1)) +
                        "\", " +
                        ToFloatString(1.0f / GetU8(script + 2)) +
                        ");\n"
                    );

                    AdvanceScript(3, script, end);
                }
                else if (opcode == 0xA3) // ANIME1
                {
                    export_script->Log(
                        entity_list[i] +
                        ":play_animation_wait(\"" +
                        ToIntString(GetU8(script + 1)) +
                        "\", 0, -1, " +
                        ToFloatString(1.0f / GetU8(script + 2)) +
                        ", false);\n"
                    );

                    AdvanceScript(3, script, end);
                }
                else if (opcode == 0xA4) // VISI
                {
                    export_script->Log(
                        entity_list[i] +
                        ":set_visible(" +
                        ToBoolString((bool)(GetU8(script + 1))) +
                        ");\n"
                    );

                    AdvanceScript(2, script, end);
                }
                else if (opcode == 0xA5) // XYZI
                {
                    export_script->Log(
                        entity_list[i] +
                        ":set_position_triangle(" +
                        ParseGetVariable(GetU8(script + 1) >> 4, (s16)GetU16LE(script + 3)) +
                        ", " +
                        ParseGetVariable(GetU8(script + 1) & 0x0F, (s16)GetU16LE(script + 5)) +
                        ", " +
                        ParseGetVariable(GetU8(script + 2) >> 4, (s16)GetU16LE(script + 7)) +
                        ", " +
                        ParseGetVariable(GetU8(script + 2) & 0x0F, (s16)GetU16LE(script + 9)) +
                        ");\n"
                    );

                    AdvanceScript(11, script, end);
                }
                else if (opcode == 0xA6) // XYI
                {
                    export_script->Log(
                        entity_list[i] +
                        ":set_2d_position_triangle( " +
                        ParseGetVariable(GetU8(script + 1) >> 4, (s16)GetU16LE(script + 3)) +
                        ", " +
                        ParseGetVariable(GetU8(script + 1) & 0x0F, (s16)GetU16LE(script + 5)) +
                        ", " +
                        ParseGetVariable(GetU8(script + 2) >> 4, (s16)GetU16LE(script + 7)) +
                        " );\n"
                    );

                    AdvanceScript(9, script, end);
                }
                else if (opcode == 0xA8) // MOVE
                {
                    export_script->Log(
                        entity_list[i] +
                        ":move_to_position( \"" +
                        ParseGetVariable(GetU8(script + 1) >> 4, (s16)GetU16LE(script + 2)) +
                        ", " +
                        ParseGetVariable(GetU8(script + 1) & 0x0F, (s16)GetU16LE(script + 4)) +
                        ", true );\n"
                    );

                    AdvanceScript(6, script, end);
                }
                else if (opcode == 0xA9) // CMOVE
                {
                    export_script->Log(
                        entity_list[i] +
                        ":set_rotation_lock( true );\n" +
                        entity_list[i] +
                        ":move_to_position( \"" +
                        ParseGetVariable(GetU8(script + 1) >> 4, (s16)GetU16LE(script + 2)) +
                        ", " +
                        ParseGetVariable(GetU8(script + 1) & 0x0F, (s16)GetU16LE(script + 4)) +
                        ", false );\n" +
                        entity_list[i] +
                        ":set_rotation_lock( false );\n"
                    );

                    AdvanceScript(6, script, end);
                }
                else if (opcode == 0xAA) // MOVA
                {
                    export_script->Log(
                        entity_list[i] +
                        ":move_to_model(" +
                        entity_list[GetU8(script + 1)] +
                        ", true);\n"
                    );

                    AdvanceScript(2, script, end);
                }
                else if (opcode == 0xAB) // TURA
                {
                    u8 type = GetU8(script + 2);

                    export_script->Log(
                        entity_list[i] +
                        ":turn_to_entity(" +
                        entity_list[GetU8(script + 1)] +
                        ", " +
                        ((type == 0) ? "Entity.CLOCKWISE" : ((type == 1) ? "Entity.ANTICLOCKWISE" : "Entity.CLOSEST")) +
                        ", " +
                        ToFloatString(GetU8(script + 3) / 30.0f) +
                        ");\n"
                    );

                    AdvanceScript(4, script, end);
                }
                else if (opcode == 0xAC) // ANIMW
                {
                    export_script->Log(
                        entity_list[i] +
                        ":set_animation_wait();\n"
                    );

                    AdvanceScript(1, script, end);
                }
                else if (opcode == 0xAD) // FMOVE
                {
                    export_script->Log(
                        entity_list[i] +
                        ":move_to_position( \"" +
                        ParseGetVariable(GetU8(script + 1) >> 4, (s16)GetU16LE(script + 2)) +
                        ", " +
                        ParseGetVariable(GetU8(script + 1) & 0x0F, (s16)GetU16LE(script + 4)) +
                        ", false );\n"
                    );

                    AdvanceScript(6, script, end);
                }
                else if (opcode == 0xAE) // ANIME2
                {
                    export_script->Log(
                        entity_list[i] +
                        ":play_animation( \"" +
                        ToIntString(GetU8(script + 1)) +
                        "\", 0, -1, " +
                        ToFloatString(1.0f / GetU8(script + 2)) +
                        ", false );\n"
                    );

                    AdvanceScript(3, script, end);
                }
                else if (opcode == 0xAF) // ANIM!1
                {
                    export_script->Log(
                        entity_list[i] +
                        ":play_animation( \"" +
                        ToIntString(GetU8(script + 1)) +
                        "\", 0, -1, " +
                        ToFloatString(1.0f / GetU8(script + 2)) +
                        ", true );\n"
                    );

                    AdvanceScript(3, script, end);
                }
                else if (opcode == 0xB1) // CANM!1
                {
                    export_script->Log(
                        entity_list[i] +
                        ":play_animation( \"" +
                        ToIntString(GetU8(script + 1)) +
                        "\", " +
                        ToFloatString(GetU8(script + 2) / 30.0f) +
                        ", " +
                        ToFloatString(GetU8(script + 3) / 30.0f) +
                        ", " +
                        ToFloatString(1.0f / GetU8(script + 4)) +
                        ", true );\n"
                    );

                    AdvanceScript(5, script, end);
                }
                else if (opcode == 0xB2) // MSPED
                {
                    export_script->Log(
                        entity_list[i] +
                        ":set_speed( " +
                        ParseGetVariable(GetU8(script + 1), GetU16LE(script + 2), false, 256.0f / 30.0f) +
                        " );\n"
                    );

                    AdvanceScript(4, script, end);
                }
                else if (opcode == 0xB3) // DIR
                {
                    export_script->Log(
                        entity_list[i] +
                        ":set_direction( " +
                        ParseGetVariable(GetU8(script + 1), GetU8(script + 2), false, 256.0f / 360.0f) +
                        " );\n"
                    );

                    AdvanceScript(3, script, end);
                }
                else if (opcode == 0xB4) // TURNGEN
                {
                    u8 type = GetU8(script + 3);
                    u8 calc = GetU8(script + 5);

                    export_script->Log(
                        entity_list[i] +
                        ":turn_to_direction( " +
                        ParseGetVariable(GetU8(script + 1), GetU8(script + 2), false, 256.0f / 360.0f) +
                        ", " +
                        ((type == 0) ? "Entity.CLOCKWISE" : ((type == 1) ? "Entity.ANTICLOCKWISE" : "Entity.CLOSEST")) +
                        ", " +
                        ((calc == 1) ? "Field.LINEAR" : "Field.SMOOTH") +
                        ", " +
                        ToFloatString(GetU8(script + 4) / 30.0f) +
                        " );\n"
                    );

                    AdvanceScript(6, script, end);
                }
                else if (opcode == 0xB5) // TURN
                {
                    u8 calc = GetU8(script + 5);

                    export_script->Log(
                        entity_list[i] +
                        ":turn_to_direction( " +
                        ParseGetVariable(GetU8(script + 1), GetU16LE(script + 2), false, 256.0f / 360.0f) +
                        ", Entity.CLOCKWISE, " +
                        ((calc == 1) ? "Field.LINEAR" : "Field.SMOOTH") +
                        ", " +
                        ToFloatString(GetU8(script + 4) / 30.0f) +
                        " );\n"
                    );

                    AdvanceScript(6, script, end);
                }
                else if (opcode == 0xB6) // DIRA
                {
                    export_script->Log(
                        entity_list[i] +
                        ":set_direction( " +
                        entity_list[GetU8(script + 1)] +
                        " );\n"
                    );

                    AdvanceScript(2, script, end);
                }
                else if (opcode == 0xB7) // GETDIR
                {
                    export_script->Log(
                        SetVariable(GetU8(script + 1), GetU8(script + 3), entity_list[GetU8(script + 2)] + ":get_direction()")
                    );
                    AdvanceScript(4, script, end);
                }
                else if (opcode == 0xB8) // GETAXY
                {
                    export_script->Log(
                        SetVariable(GetU8(script + 1) >> 4, GetU8(script + 3), entity_list[GetU8(script + 2)] + ":get_x()") +
                        SetVariable(GetU8(script + 1) & 0x0F, GetU8(script + 4), entity_list[GetU8(script + 2)] + ":get_y()")
                    );
                    AdvanceScript(5, script, end);
                }
                else if (opcode == 0xB9) // GETAI
                {
                    export_script->Log(
                        SetVariable(GetU8(script + 1), GetU8(script + 3), entity_list[GetU8(script + 2)] + ":get_triangle()")
                    );
                    AdvanceScript(4, script, end);
                }
                else if (opcode == 0xBA) // ANIM!2
                {
                    export_script->Log(
                        entity_list[i] +
                        ":play_animation_wait( \"" +
                        ToIntString(GetU8(script + 1)) +
                        "\", 0, -1, " +
                        ToFloatString(1.0f / GetU8(script + 2)) +
                        ", true );\n"
                    );

                    AdvanceScript(3, script, end);
                }
                else if (opcode == 0xBB) // CANIM2
                {
                    export_script->Log(
                        entity_list[i] +
                        ":play_animation_wait( \"" +
                        ToIntString(GetU8(script + 1)) +
                        "\", " +
                        ToFloatString(GetU8(script + 2) / 30.0f) +
                        ", " +
                        ToFloatString(GetU8(script + 3) / 30.0f) +
                        ", " +
                        ToFloatString(1.0f / GetU8(script + 4)) +
                        ", false );\n"
                    );

                    AdvanceScript(5, script, end);
                }
                else if (opcode == 0xBC) // CANM!2
                {
                    export_script->Log(
                        entity_list[i] +
                        ":play_animation_wait( \"" +
                        ToIntString(GetU8(script + 1)) +
                        "\", " +
                        ToFloatString(GetU8(script + 2) / 30.0f) +
                        ", " +
                        ToFloatString(GetU8(script + 3) / 30.0f) +
                        ", " +
                        ToFloatString(1.0f / GetU8(script + 4)) +
                        ", true );\n"
                    );

                    AdvanceScript(5, script, end);
                }
                else if (opcode == 0xBD) // ASPED
                {
                    export_script->Log(
                        "-- set speed of entity animation to \"" +
                        ParseGetVariable(GetU8(script + 1), GetU16LE(script + 2)) +
                        "\"\n"
                    );

                    AdvanceScript(4, script, end);
                }
                else if (opcode == 0xBF) // CC
                {
                    export_script->Log(
                        "field:set_player_entity( " +
                        entity_list[GetU8(script + 1)] +
                        " );\n"
                    );

                    AdvanceScript(2, script, end);
                }
                else if (opcode == 0xC0) // JUMP
                {
                    export_script->Log(
                        entity_list[i] +
                        ":jump_to_position( " +
                        ParseGetVariable(GetU8(script + 1) >> 4, (s16)GetU16LE(script + 3)) +
                        ", " +
                        ParseGetVariable(GetU8(script + 1) & 0x0F, (s16)GetU16LE(script + 5)) +
                        ", " +
                        ParseGetVariable(GetU8(script + 2) >> 4, GetU16LE(script + 7)) +
                        ", " +
                        ParseGetVariable(GetU8(script + 2) & 0x0F, GetU16LE(script + 9), false, 30.0f) +
                        " );\n"
                    );

                    AdvanceScript(11, script, end);
                }
                else if (opcode == 0xC1) // AXYZI
                {
                    export_script->Log(
                        SetVariable(GetU8(script + 1) >> 4, GetU8(script + 4), entity_list[GetU8(script + 3)] + ":get_x()") +
                        SetVariable(GetU8(script + 1) & 0x0F, GetU8(script + 5), entity_list[GetU8(script + 3)] + ":get_y()") +
                        SetVariable(GetU8(script + 2) >> 4, GetU8(script + 6), entity_list[GetU8(script + 3)] + ":get_z()") +
                        SetVariable(GetU8(script + 2) & 0x0F, GetU8(script + 7), entity_list[GetU8(script + 3)] + ":get_triangle()")
                    );
                    AdvanceScript(8, script, end);
                }
                else if (opcode == 0xC2) // LADER
                {
                    u8 type = GetU8(script + 11);

                    export_script->Log(
                        entity_list[i] +
                        ":climb_to_position( " +
                        ParseGetVariable(GetU8(script + 1) >> 4, (s16)GetU16LE(script + 3)) +
                        ", " +
                        ParseGetVariable(GetU8(script + 1) & 0x0F, (s16)GetU16LE(script + 5)) +
                        ", " +
                        ParseGetVariable(GetU8(script + 2) >> 4, (s16)GetU16LE(script + 7)) +
                        ", " +
                        ParseGetVariable(GetU8(script + 2) & 0x0F, GetU16LE(script + 9)) +
                        ", " +
                        ((type == 0) ? "Entity.UP_TO_DOWN" : ((type == 1) ? "Entity.DOWN_TO_UP" : ((type == 2) ? "Entity.LEFT_TO_RIGHT" : ((type == 1) ? "Entity.RIGHT_TO_LEFT" : "")))) +
                        " ); -- direction needs to be seted to \"" +
                        ToFloatString((GetU8(script + 13) / 256.0f) * 360.0f) +
                        "\" and animation during climbing is \"" +
                        ToIntString(GetU8(script + 12)) +
                        "\" with speed \"" +
                        ToFloatString(1.0f / GetU8(script + 14)) +
                        "\"\n"
                    );

                    AdvanceScript(15, script, end);
                }
                else if (opcode == 0xC3) // OFST
                {
                    u8 type = GetU8(script + 3);

                    export_script->Log(
                        entity_list[i] +
                        ":offset_to_position( " +
                        ParseGetVariable(GetU8(script + 1) >> 4, (s16)GetU16LE(script + 4)) +
                        ", " +
                        ParseGetVariable(GetU8(script + 1) & 0x0F, (s16)GetU16LE(script + 6)) +
                        ", " +
                        ParseGetVariable(GetU8(script + 2) >> 4, (s16)GetU16LE(script + 8)) +
                        ", " +
                        ((type == 2) ? "Field.SMOOTH" : "Field.LINEAR") +
                        ", " +
                        ParseGetVariable(GetU8(script + 2) & 0x0F, GetU16LE(script + 10), false, 30.0f) +
                        " );\n"
                    );

                    AdvanceScript(12, script, end);
                }
                else if (opcode == 0xC4) // OFSTW
                {
                    export_script->Log(
                        entity_list[i] +
                        ":set_offset_wait();\n"
                    );

                    AdvanceScript(1, script, end);
                }
                else if (opcode == 0xC5) // TALKR
                {
                    export_script->Log(
                        entity_list[i] +
                        ":set_talk_range( " +
                        ParseGetVariable(GetU8(script + 1), GetU8(script + 2)) +
                        " );\n"
                    );

                    AdvanceScript(3, script, end);
                }
                else if (opcode == 0xC6) // CLIDR
                {
                    export_script->Log(
                        entity_list[i] +
                        ":set_solid_range( " +
                        ParseGetVariable(GetU8(script + 1), GetU8(script + 2)) +
                        " );\n"
                    );

                    AdvanceScript(3, script, end);
                }
                else if (opcode == 0xC7) // SOLID
                {
                    export_script->Log(
                        entity_list[i] +
                        ":set_solid( " +
                        ToBoolString(!(bool)(GetU8(script + 1))) +
                        " );\n"
                    );

                    AdvanceScript(2, script, end);
                }
                else if (opcode == 0xC8) // PRTYP
                {
                    export_script->Log(
                        "game:party_add( " +
                        ToIntString(GetU8(script + 1)) +
                        " );\n"
                    );

                    AdvanceScript(2, script, end);
                }
                else if (opcode == 0xC9) // PRTYM
                {
                    export_script->Log(
                        "game:party_remove( " +
                        ToIntString(GetU8(script + 1)) +
                        " );\n"
                    );

                    AdvanceScript(2, script, end);
                }
                else if (opcode == 0xCA) // PRTYE
                {
                    export_script->Log(
                        "game:party_set( " +
                        ToIntString(GetU8(script + 1)) +
                        ", " +
                        ToIntString(GetU8(script + 2)) +
                        ", " +
                        ToIntString(GetU8(script + 3)) +
                        " );\n"
                    );

                    AdvanceScript(4, script, end);
                }
                else if (opcode == 0xCD) // MMBUD
                {
                    export_script->Log(
                        "game:character_enable( " +
                        ToIntString(GetU8(script + 2)) +
                        ", " +
                        ToBoolString((bool)(GetU8(script + 1))) +
                        " );\n"
                    );

                    AdvanceScript(3, script, end);
                }
                else if (opcode == 0xCE) // MMBLK
                {
                    export_script->Log(
                        "[UNREVERSED] MMBLK(" +
                        ArgumentString(script + 1, 1) +
                        ");\n"
                    );

                    AdvanceScript(2, script, end);
                }
                else if (opcode == 0xD0) // LINE
                {
                    export_script->Log(
                        "-- define line point1( " +
                        ToIntString(GetU16LE(script + 1)) +
                        ", " +
                        ToIntString(GetU16LE(script + 3)) +
                        ", " +
                        ToIntString(GetU16LE(script + 5)) +
                        "), point2(" +
                        ToIntString(GetU16LE(script + 7)) +
                        ", " +
                        ToIntString(GetU16LE(script + 9)) +
                        ", " +
                        ToIntString(GetU16LE(script + 11)) +
                        " )\n"
                    );

                    AdvanceScript(13, script, end);
                }
                else if (opcode == 0xD1) // LINON
                {
                    export_script->Log(
                        "-- turn line " +
                        Ogre::String((GetU8(script + 1) == 1) ? "on" : "off") +
                        "\n"
                    );

                    AdvanceScript(2, script, end);
                }
                else if (opcode == 0xD2) // MPJPO
                {
                    export_script->Log(
                        "field:gateway_enable( " +
                        Ogre::String((GetU8(script + 1) == 1) ? "false" : "true") +
                        " );\n"
                    );

                    AdvanceScript( 2, script, end );
                }
                else if( opcode == 0xD3 ) // SLINE
                {
                    u8 type = GetU8(script + 2);

                    export_script->Log(
                        "-- redefine line point1( " +
                        ParseGetVariable(GetU8(script + 1) >> 4, GetU8(script + 4)) +
                        ", " +
                        ParseGetVariable(GetU8(script + 1) & 0x0F, GetU8(script + 6)) +
                        ", " +
                        ParseGetVariable(GetU8(script + 2) >> 4, GetU8(script + 8)) +
                        "), point2(" +
                        ParseGetVariable(GetU8(script + 2) & 0x0F, GetU8(script + 10)) +
                        ", " +
                        ParseGetVariable(GetU8(script + 3) >> 4, GetU8(script + 12)) +
                        ", " +
                        ParseGetVariable(GetU8(script + 3) & 0x0F, GetU8(script + 14)) +
                        " )\n"
                    );

                    AdvanceScript(16, script, end);
                }
                else if (opcode == 0xD8) // PMJMP
                {
                    export_script->Log(
                        "[UNREVERSED] PMJMP(" +
                        ArgumentString(script + 1, 2) +
                        ");\n"
                    );

                    AdvanceScript(3, script, end);
                }
                else if (opcode == 0xDA) // AKAO2
                {
                    u8 sub_opcode = GetU8(script + 4);

                    Ogre::String sound = "music:execute_akao( " +
                        ToHexString(sub_opcode, 2, '0') +
                        ", " +
                        ParseGetVariable(GetU8(script + 1) >> 4, GetU16LE(script + 5), true) +
                        ", " +
                        ParseGetVariable(GetU8(script + 1) & 0x0F, GetU16LE(script + 7), true) +
                        ", " +
                        ParseGetVariable(GetU8(script + 2) >> 4, GetU16LE(script + 9), true) +
                        ", " +
                        ParseGetVariable(GetU8(script + 2) & 0x0F, GetU16LE(script + 11), true) +
                        ", " +
                        ParseGetVariable(GetU8(script + 3) >> 4, GetU16LE(script + 13), true) +
                        ", " +
                        ParseGetVariable(GetU8(script + 3) & 0x0F, GetU16LE(script + 15), true) +
                        " );\n";

                    m_SoundOpcodes.push_back(sound);
                    export_script->Log(sound);

                    AdvanceScript(15, script, end);
                }
                else if (opcode == 0xDD) // ANIMB
                {
                    export_script->Log(
                        entity_list[i] +
                        ":animation_stop();\n"
                    );

                    AdvanceScript(1, script, end);
                }
                else if (opcode == 0xDE) // TURNW
                {
                    export_script->Log(
                        entity_list[i] +
                        ":set_turn_wait();\n"
                    );

                    AdvanceScript(1, script, end);
                }
                else if (opcode == 0xE0) // BGON
                {
                    export_script->Log(
                        "field:background_on( \"" +
                        ParseGetVariable(GetU8(script + 1) >> 4, GetU8(script + 2)) +
                        ", " +
                        ParseGetVariable(GetU8(script + 1) & 0x0F, GetU8(script + 3)) +
                        " ); -- turns on layer of background animation with given id\n"
                    );

                    AdvanceScript(4, script, end);
                }
                else if (opcode == 0xE1) // BGOFF
                {
                    export_script->Log(
                        "field:background_off( \"" +
                        ParseGetVariable(GetU8(script + 1) >> 4, GetU8(script + 2)) +
                        ", " +
                        ParseGetVariable(GetU8(script + 1) & 0x0F, GetU8(script + 3)) +
                        " ); -- turns off layer of background animation with given id\n"
                    );

                    AdvanceScript(4, script, end);
                }
                else if (opcode == 0xE4) // BGCLR
                {
                    export_script->Log(
                        "field:background_clear( " +
                        ParseGetVariable(GetU8(script + 1), GetU8(script + 2)) +
                        " ); -- turns off all layer of background animation with given id\n"
                    );

                    AdvanceScript(3, script, end);
                }
                else if (opcode == 0xE5) // STPAL
                {
                    export_script->Log(
                        "[UNREVERSED] STPAL(" +
                        ArgumentString(script + 1, 4) +
                        ");\n"
                    );

                    AdvanceScript(5, script, end);
                }
                else if (opcode == 0xE6) // LDPAL
                {
                    export_script->Log(
                        "[UNREVERSED] LDPAL(" +
                        ArgumentString(script + 1, 4) +
                        ");\n"
                    );

                    AdvanceScript(5, script, end);
                }
                else if (opcode == 0xE7) // CPPAL
                {
                    export_script->Log(
                        "[UNREVERSED] CPPAL(" +
                        ArgumentString(script + 1, 4) +
                        ");\n"
                    );

                    AdvanceScript(5, script, end);
                }
                else if (opcode == 0xE9) // ADPAL
                {
                    export_script->Log(
                        "[UNREVERSED] ADPAL(" +
                        ArgumentString(script + 1, 9) +
                        ");\n"
                    );

                    AdvanceScript(10, script, end);
                }
                else if (opcode == 0xEA) // MPPAL2
                {
                    export_script->Log(
                        "[UNREVERSED] MPPAL2(" +
                        ArgumentString(script + 1, 9) +
                        ");\n"
                    );

                    AdvanceScript(10, script, end);
                }
                else if (opcode == 0xEE) // RTPAL2
                {
                    export_script->Log(
                        "[UNREVERSED] RTPAL2(" +
                        ArgumentString(script + 1, 7) +
                        ");\n"
                    );

                    AdvanceScript(8, script, end);
                }
                else if (opcode == 0xEF) // ADPAL2
                {
                    export_script->Log(
                        "[UNREVERSED] ADPAL2(" +
                        ArgumentString(script + 1, 10) +
                        ");\n"
                    );

                    AdvanceScript(11, script, end);
                }
                else if (opcode == 0xF0) // MUSIC
                {
                    Ogre::String sound = "music:execute_akao( " +
                        ToHexString(0x10, 2, '0') +
                        ", pointer_to_field_AKAO_" +
                        ToIntString(GetU8(script + 1)) +
                        " ); -- play field music\n";

                    m_SoundOpcodes.push_back(sound);
                    export_script->Log(sound);

                    AdvanceScript(2, script, end);
                }
                else if (opcode == 0xF1) // SOUND
                {
                    Ogre::String sound = "music:execute_akao( " +
                        ToHexString(0x20, 2, '0') +
                        ", " +
                        ParseGetVariable(GetU8(script + 1) & 0x0F, GetU8(script + 4), true) +
                        ", " +
                        ParseGetVariable(GetU8(script + 1) >> 4, GetU16LE(script + 2), true) +
                        " ); -- play sound\n";

                    m_SoundOpcodes.push_back(sound);
                    export_script->Log(sound);

                    AdvanceScript(5, script, end);
                }
                else if (opcode == 0xF2) // AKAO
                {
                    u8 sub_opcode = GetU8(script + 4);

                    Ogre::String sound = "music:execute_akao( " +
                        ToHexString(sub_opcode, 2, '0') +
                        ", " +
                        ParseGetVariable(GetU8(script + 1) >> 4, GetU8(script + 5), true) +
                        ", " +
                        ParseGetVariable(GetU8(script + 1) & 0x0F, GetU16LE(script + 7), true) +
                        ", " +
                        ParseGetVariable(GetU8(script + 2) >> 4, GetU16LE(script + 9), true) +
                        ", " +
                        ParseGetVariable(GetU8(script + 2) & 0x0F, GetU16LE(script + 11), true) +
                        ", " +
                        ParseGetVariable(GetU8(script + 3) >> 4, GetU16LE(script + 13), true) +
                        ", " +
                        ParseGetVariable(GetU8(script + 3) & 0x0F, GetU16LE(script + 15), true) +
                        " );\n";
                    m_SoundOpcodes.push_back(sound);

                    export_script->Log(sound);

                    AdvanceScript(14, script, end);
                }
                else if (opcode == 0xF5) // MULCK
                {
                    export_script->Log(
                        "music:lock( " +
                        ToBoolString((bool)(GetU8(script + 1))) +
                        " );\n"
                    );

                    AdvanceScript(2, script, end);
                }
                else if (opcode == 0xF6) // BMUSC
                {
                    export_script->Log(
                        "[UNREVERSED] BMUSC(" +
                        ToIntString(GetU8(script + 1)) +
                        ");\n"
                    );

                    AdvanceScript(2, script, end);
                }
                else if (opcode == 0xF8) // PMVIE
                {
                    export_script->Log(
                        "field:movie_set( " +
                        ToIntString(GetU8(script + 1)) +
                        " );\n"
                    );

                    AdvanceScript(2, script, end);
                }
                else if (opcode == 0xF9) // MOVIE
                {
                    export_script->Log("field:play_movie();\n");
                    AdvanceScript(1, script, end);
                }
                else if (opcode == 0xFA) // MVIEF
                {
                    export_script->Log(
                        SetVariable(GetU8(script + 1), GetU8(script + 2), "field:get_movie_frame()")
                    );
                    AdvanceScript(3, script, end);
                }
                else if (opcode == 0xFB) // MVCAM
                {
                    export_script->Log(
                        "field:movie_camera_enable( " +
                        ToBoolString(!(bool)(GetU8(script + 1))) +
                        " );\n"
                    );

                    AdvanceScript(2, script, end);
                }
                else if (opcode == 0xFC) // FMUSC
                {
                    export_script->Log(
                        "[UNREVERSED] FMUSC(" +
                        ArgumentString(script + 1, 1) +
                        ");\n"
                    );

                    AdvanceScript(2, script, end);
                }
                else if (opcode == 0xFE) // CHMST
                {
                    export_script->Log(
                        SetVariable(GetU8(script + 1), GetU8(script + 2), "field:is_music_playing()")
                    );
                    AdvanceScript(3, script, end);
                }
                else
                {
                    export_script->Log("[OPCODE " + ToHexString(opcode, 2, '0') + "]\n");
                    script += 1;
                }
            }

            export_script->Log("\n");
        }
    }
    delete export_script;
}



void
DatFile::DumpWalkmeshData( const Ogre::String& export_path, const Field& field )
{
    Logger* export_script = new Logger( export_path + "/maps/field/" + field.name + "_wm.xml" );
    export_script->Log( "<?xml version=\"1.0\" encoding=\"ISO-8859-1\"?>\n<walkmesh>\n" );

    // get sector 2 offset (walkmesh)
    u32 offset_to_walkmesh = 0x1C + GetU32LE( 0x04 ) - GetU32LE( 0x00 );
    u32 number_of_poly = GetU32LE( offset_to_walkmesh );

    int start_walkmesh = offset_to_walkmesh + 0x04;
    int start_access   = offset_to_walkmesh + 0x04 + number_of_poly * 0x18;

    Ogre::Vector3 A, B, C;

    for( u32 i = 0; i < number_of_poly; ++i )
    {
        A.x = static_cast< s16 >( GetU16LE( start_walkmesh + 0x00 ) ) / 128.0f;
        A.y = static_cast< s16 >( GetU16LE( start_walkmesh + 0x02 ) ) / 128.0f;
        A.z = static_cast< s16 >( GetU16LE( start_walkmesh + 0x04 ) ) / 128.0f;

        B.x = static_cast< s16 >( GetU16LE( start_walkmesh + 0x08 ) ) / 128.0f;
        B.y = static_cast< s16 >( GetU16LE( start_walkmesh + 0x0A ) ) / 128.0f;
        B.z = static_cast< s16 >( GetU16LE( start_walkmesh + 0x0C ) ) / 128.0f;

        C.x = static_cast< s16 >( GetU16LE( start_walkmesh + 0x10 ) ) / 128.0f;
        C.y = static_cast< s16 >( GetU16LE( start_walkmesh + 0x12 ) ) / 128.0f;
        C.z = static_cast< s16 >( GetU16LE( start_walkmesh + 0x14 ) ) / 128.0f;

        export_script->Log(
            "    <triangle a=\"" +
            Ogre::StringConverter::toString( A ) +
            "\" b=\"" +
            Ogre::StringConverter::toString( B ) +
            "\" c=\"" +
            Ogre::StringConverter::toString( C ) +
            "\" a_b=\"" +
            ToIntString( ( s16 )GetU16LE( start_access + 0x00 ) ) +
            "\" b_c=\"" +
            ToIntString( ( s16 )GetU16LE( start_access + 0x02 ) ) +
            "\" c_a=\"" +
            ToIntString( ( s16 )GetU16LE( start_access + 0x04 ) ) +
            "\"/>\n"
        );

        // go to the next triangle
        start_walkmesh += 0x18;
        start_access   += 0x06;
    }

    export_script->Log( "</walkmesh>" );
    delete export_script;
}



void
DatFile::DumpSoundOpcodesData( const Ogre::String& export_file )
{
    std::sort( m_SoundOpcodes.begin(), m_SoundOpcodes.end() );
    m_SoundOpcodes.erase(std::unique(m_SoundOpcodes.begin(), m_SoundOpcodes.end()), m_SoundOpcodes.end());

    Logger* export_sound = new Logger(export_file);

    for (int i = 0; i < m_SoundOpcodes.size(); ++i)
    {
        export_sound->Log(m_SoundOpcodes[i]);
    }

    delete export_sound;
}



void
DatFile::AdvanceScript(u32 value, u32& current, u32& end)
{
    current += value;
    u32 temp_end = current;
    end = (temp_end > end) ? temp_end : end;
}



Ogre::String
DatFile::ParseVariableName(int slot, int value)
{
    if (slot == 1)
    {
        switch (value)
        {
            case 3: return "love_point_aeris";
            case 4: return "love_point_tifa";
            case 5: return "love_point_yuffie";
            case 6: return "love_point_barret";
            case 21: return "timer_minutes";
            case 22: return "timer_seconds";
            case 23: return "timer_frames";
            case 36: return "graveyard_item";
            case 48: return "item_mask2";
            case 80: return "battle_love_aeris";
            case 81: return "battle_love_tifa";
            case 82: return "battle_love_yuffie";
            case 83: return "battle_love_barret";
            case 164: return "graveyard_train";
            case 225: return "act1_1_flags1";
            case 226: return "act1_1_flags2";
        }
    }
    else if (slot == 2)
    {
        switch (value)
        {
            case 0: return "progress_game";
            case 28: return "menu_appear";
            case 30: return "menu_selectable";
        }
    }
    else if (slot == 3)
    {
        switch (value)
        {
            case 66: return "act1_1_flags3";
            case 111: return "flower_flag";
            case 112: return "act1_3_flags5";
            case 126: return "act1_3_unknown";
            case 127: return "tunnel_room";
            case 128: return "act1_3_flags1";
            case 129: return "act1_3_flags2";
            case 130: return "act1_3_flags3";
            case 131: return "act1_3_flags4";
            case 208: return "act1_2_flags1";
            case 209: return "act1_2_flags2";
            case 210: return "act1_2_flags3";
            case 211: return "act1_2_flags4";
            case 212: return "act1_2_flags5";
            case 213: return "act1_2_flags6";
            case 214: return "act1_2_flags7";
            case 215: return "act1_2_flags8";
            case 216: return "act1_2_flags9";
            case 217: return "act1_7_flags1";
            case 223: return "act1_1_flags4";
        }
    }
    else if (slot == 13)
    {
        switch (value)
        {
            case 30: return "pointer";
            case 31: return "materia_full";
            case 91: return "save_flag";
        }
    }
    else if (slot == 15)
    {
        switch (value)
        {
            case 32: return "sector1_item";
            case 33: return "sector5_item";
            case 80: return "subway_item";
        }
    }

    LOGGER->Log("\n[WARNING] ParseVariableName " + ToIntString(value) + " for slot " + ToIntString(slot) + " not implemented.\n");

    return "";
}



Ogre::String
DatFile::ParseGetVariable(int get_slot, int get_value, bool hex, float fixed)
{
    if (get_slot == 0)
    {
        if (hex == true)
        {
            return ToHexString(get_value, 8, '0');
        }
        else
        {
            return ToFloatString(get_value / fixed);
        }
    }
    else if (get_slot == 1 || get_slot == 2 || get_slot == 3 || get_slot == 13 || get_slot == 15)
    {
        return "game:variable_get(\"" + ParseVariableName(get_slot, get_value) + "\")";
    }
    else if (get_slot == 5)
    {
        return "temp5_" + ToIntString(get_value);
    }
    else if (get_slot == 6)
    {
        return "temp6_" + ToIntString(get_value);
    }

    LOGGER->Log("\n[WARNING] ParseGetVariable " + ToIntString(get_value) + " for slot " + ToIntString(get_slot) + " not implemented.\n");

    return "";
}



Ogre::String
DatFile::SetVariable(int set_slot, int set_value, Ogre::String get_string)
{
    if (set_slot == 1 || set_slot == 2 || set_slot == 3 || set_slot == 13 || set_slot == 15)
    {
        return "game:variable_set(\"" + ParseVariableName(set_slot, set_value) + "\", " + get_string + ");\n";
    }
    else if (set_slot == 5)
    {
        return "temp5_" + ToIntString(set_value) + " = " + get_string + ";\n";
    }
    else if (set_slot == 6)
    {
        return "temp6_" + ToIntString(set_value) + " = " + get_string + ";\n";
    }

    LOGGER->Log("\n[WARNING] SetVariable " + ToIntString(set_value) + " for slot " + ToIntString(set_slot) + " not implemented.\n");

    return "";
}



Ogre::String
DatFile::SetBitChange(int set_slot, int set_value, int get_slot, int get_value, bool on)
{
    if (set_slot == 1 || set_slot == 3  || set_slot == 5 || set_slot == 13 || set_slot == 15)
    {
        if (on == true)
        {
            return SetVariable(set_slot, set_value, "(" + ParseGetVariable(set_slot, set_value) + " | (1 << " + ParseGetVariable(get_slot, get_value) + "))");
        }
        else
        {
            return SetVariable(set_slot, set_value, "(" + ParseGetVariable(set_slot, set_value) + " & XOR(1 << " + ParseGetVariable(get_slot, get_value) + "))");
        }
    }

    LOGGER->Log("\n[WARNING] SetBitChange " + ToIntString(set_value) + " for slot " + ToIntString(set_slot) + " not implemented.\n");

    return "";
}



Ogre::String
DatFile::ParseRelation(int relation, Ogre::String string1, Ogre::String string2)
{
    switch (relation)
    {
        case 0:  return string1 + " == " + string2;
        case 1:  return string1 + " != " + string2;
        case 2:  return string1 + " > " + string2;
        case 3:  return string1 + " < " + string2;
        case 4:  return string1 + " >= " + string2;
        case 5:  return string1 + " <= " + string2;
        case 6:  return string1 + " & " + string2;
        case 7:  return string1 + " ^ " + string2;
        case 8:  return string1 + " | " + string2;
        case 9:  return string1 + " & (1 << " + string2 + ")";
        case 10: return "!(" + string1 + " & (1 << " + string2 + "))";
    }

    return "";
}



Ogre::String
DatFile::ArgumentString(int script, int number)
{
    Ogre::String ret = "";

    for (int i = 0; i < number; ++i)
    {
        ret += ToHexString(GetU8(script + i), 2, '0');
        if (i + 1 < number)
        {
            ret += ", ";
        }
    }

    return ret;
}



Ogre::String
DatFile::OffsetString(int val)
{
    return ToHexString(val, 4, '0');
}



void
DatFile::DumpBackground( const Ogre::String& export_path, const Field& field, MimFile& mim )
{
    Logger* export_text = new Logger( export_path + "maps/field/" + field.name + "_bg.xml" );

    int width = field.tex_width;
    int height = field.tex_height;

    export_text->Log( "<background2d image=\"maps/field/" + field.name + ".png\">\n" );

    full_image = CreateSurface( width, height );
    x_32 = 0; y_32 = 0;
    x_16 = 0; y_16 = 0;
    n_16 = 0;

    // sector 3
    u32 offset_to_background = 0x1c + GetU32LE( 0x08 ) - GetU32LE( 0x00 );
    LOGGER->Log( "offset_to_background = " + ToHexString( offset_to_background, 8, '0' ) + "\n" );

    u32 offset_to_1 = offset_to_background + 0x10;
    u32 offset_to_2 = offset_to_background + GetU32LE( offset_to_background + 0x00 );
    u32 offset_to_3 = offset_to_background + GetU32LE( offset_to_background + 0x04 );
    u32 offset_to_4 = offset_to_background + GetU32LE( offset_to_background + 0x08 );
    u32 offset_to_5 = offset_to_background + GetU32LE( offset_to_background + 0x0c );

    u32 s1 = offset_to_1;
    u32 s2 = offset_to_2;
    u32 s3 = offset_to_3;
    u32 s4 = offset_to_4;
    u32 s5 = offset_to_5;



    // get global texture setting
    u16 g_page_x   =   GetU16LE( s3 ) & 0x000f;
    u16 g_page_y   = ( GetU16LE( s3 ) & 0x0010 ) >> 0x04;
    u8  g_blending = ( GetU16LE( s3 ) & 0x0060 ) >> 0x05;
    u8  g_bpp      = ( GetU16LE( s3 ) & 0x0180 ) >> 0x07;
    s3 += 0x02;
    LOGGER->Log( "Set global tex page x = " + ToHexString( g_page_x, 4, '0' ) +", tex page y = " + ToHexString( g_page_y, 4, '0' ) + ", blending = " + ToHexString( g_blending, 2, '0' ) + ", bpp = " + ToHexString( g_bpp, 2, '0' ) + "\n" );



    for( ; s1 < offset_to_2; s1 += 0x06 )
    {
        if( GetU16LE(s1) == 0x7ffe )
        {
            g_page_x   =   GetU16LE( s3 ) & 0x000f;
            g_page_y   = ( GetU16LE( s3 ) & 0x0010 ) >> 0x04;
            g_blending = ( GetU16LE( s3 ) & 0x0060 ) >> 0x05;
            g_bpp      = ( GetU16LE( s3 ) & 0x0180 ) >> 0x07;
            s3 += 0x02;
            LOGGER->Log( "Set global tex page x = " + ToHexString( g_page_x, 4, '0' ) +", tex page y = " + ToHexString( g_page_y, 4, '0' ) + ", blending = " + ToHexString( g_blending, 2, '0' ) + ", bpp = " + ToHexString( g_bpp, 2, '0' ) + "\n" );
            s1 += 0x06;
        }
        if( GetU16LE( s1 ) == 0x7fff )
        {
            s1 += 0x02;
            break;
        }

        u16 sprite_num = GetU16LE( s1 + 0x04 );

        for( u16 i = 0; i < sprite_num; ++i )
        {
            s16 dest_x =   GetU16LE( s2 + 0x00 );
            s16 dest_y =   GetU16LE( s2 + 0x02 );
            u8  src_x  =   GetU16LE( s2 + 0x04 );
            u8  src_y  =   GetU16LE( s2 + 0x05 );
            u16 clut_y = ( GetU16LE( s2 + 0x06 ) & 0xffc0 ) >> 6;
            u16 clut_x = ( GetU16LE( s2 + 0x06 ) & 0x003f ) << 4;

            LOGGER->Log( "Add layer 1 sprite to (" + ToIntString( dest_x ) + " " + ToIntString( dest_y ) + ") from (" + ToIntString( src_x ) + " " + ToIntString( src_y ) + " texpage_x " + ToIntString( g_page_x ) + ", texpage_y " + ToIntString( g_page_y ) + ", clut_x " + ToIntString( clut_x ) + ", clut_y " + ToIntString( clut_y ) + ")\n" );
            AddTile( 0, dest_x, dest_y, src_x, src_y, clut_x, clut_y, g_bpp, g_page_x, g_page_y, 999, 0, 0, 0, mim, export_text );
            s2 += 0x08;
        }
    }



    for( ; s1 < offset_to_2; s1 += 0x06 )
    {
        if( GetU16LE( s1 ) == 0x7fff )
        {
            s1 += 0x02;
            break;
        }

        u16 sprite_num = GetU16LE( s1 + 0x04 );

        for( u32 i = 0; i < sprite_num; ++i )
        {
            s16 dest_x    =   GetU16LE( s4 + 0x00 );
            s16 dest_y    =   GetU16LE( s4 + 0x02 );
            u8  src_x     =   GetU16LE( s4 + 0x04 );
            u8  src_y     =   GetU16LE( s4 + 0x05 );
            u16 clut_y    = ( GetU16LE( s4 + 0x06 ) & 0xffc0 ) >> 6;
            u16 clut_x    = ( GetU16LE( s4 + 0x06 ) & 0x003f ) << 4;
            u16 page_x    =   GetU16LE( s4 + 0x08 ) & 0x000f;
            u16 page_y    = ( GetU16LE( s4 + 0x08 ) & 0x0010 ) >> 0x04;
            u8  bpp       = ( GetU16LE( s4 + 0x08 ) & 0x0180 ) >> 0x07;
            u8  blending  = ( GetU16LE( s4 + 0x08 ) & 0x60 ) >> 0x05;
            u16 distance  =   GetU16LE( s4 + 0x0a );
            u8  animation =   GetU8( s4 + 0x0c ) & 0x0f;
            u8  index     =   GetU8( s4 + 0x0d );

            LOGGER->Log( "Add layer 2 sprite to (" + ToIntString( dest_x ) + " " + ToIntString( dest_y ) + ") from (" + ToIntString( src_x ) + " " + ToIntString( src_y ) + " texpage_x " + ToIntString( g_page_x ) + ", texpage_y " + ToIntString( g_page_y ) + ", clut_x " + ToIntString( clut_x ) + ", clut_y " + ToIntString( clut_y ) + "). Depth " + ToIntString( distance ) + ". Anim group " + ToIntString( animation ) + ", index " + ToIntString( index ) + ". Anim " + ToHexString( GetU16LE(s4 + 0x0c), 4, '0' ) + "\n" );
            AddTile( 1, dest_x, dest_y, src_x, src_y, clut_x, clut_y, bpp, page_x, page_y, distance, blending, animation, index, mim, export_text );
            s4 += 0x0e;
        }
    }



    for( ; s1 < offset_to_2; s1 += 0x06 )
    {
        if( GetU16LE( s1 ) == 0x7ffe )
        {
            g_page_x   =   GetU16LE( s3 ) & 0x000f;
            g_page_y   = ( GetU16LE( s3 ) & 0x0010 ) >> 0x04;
            g_blending = ( GetU16LE( s3 ) & 0x0060 ) >> 0x05;
            g_bpp      = ( GetU16LE( s3 ) & 0x0180 ) >> 0x07;
            s3 += 0x02;
            LOGGER->Log( "Set global tex page x = " + ToHexString( g_page_x, 4, '0' ) +", tex page y = " + ToHexString( g_page_y, 4, '0' ) + ", blending = " + ToHexString( g_blending, 2, '0' ) + ", bpp = " + ToHexString( g_bpp, 2, '0' ) + "\n" );
            s1 += 0x06;
        }
        if( GetU16LE( s1 ) == 0x7fff )
        {
            s1 += 0x02;
            break;
        }

        u16 sprite_num = GetU16LE( s1 + 0x04 );

        for( u32 i = 0; i < sprite_num; ++i )
        {
            s16 dest_x    =   GetU16LE( s5 + 0x00 );
            s16 dest_y    =   GetU16LE( s5 + 0x02 );
            u8  src_x     =   GetU16LE( s5 + 0x04 );
            u8  src_y     =   GetU16LE( s5 + 0x05 );
            u16 clut_y    = ( GetU16LE( s5 + 0x06 ) & 0xffc0 ) >> 6;
            u16 clut_x    = ( GetU16LE( s5 + 0x06 ) & 0x003f ) << 4;
            u8  animation =   GetU8( s5 + 0x08 ) & 0x0f;
            u8  index     =   GetU8( s5 + 0x09 );
            LOGGER->Log( "Add layer 3 sprite to (" + ToIntString( dest_x ) + " " + ToIntString( dest_y ) + ") from (" + ToIntString( src_x ) + " " + ToIntString( src_y ) + " texpage_x " + ToIntString( g_page_x ) + ", texpage_y " + ToIntString( g_page_y ) + ", clut_x " + ToIntString( clut_x ) + ", clut_y " + ToIntString( clut_y ) + "). Anim group " + ToIntString( animation ) + ", index " + ToIntString( index ) + ". Anim " + ToHexString( GetU16LE(s5 + 0x08), 4, '0' ) + "\n" );
            AddTile( 2, dest_x, dest_y, src_x, src_y, clut_x, clut_y, g_bpp, g_page_x, g_page_y, 0, g_blending, animation, index, mim, export_text );
            s5 += 0x0a;
        }
    }



    // add layer 4 sprite
    for( ; s1 < offset_to_2; s1 += 0x06 )
    {
        if( GetU16LE( s1 ) == 0x7ffe )
        {
            g_page_x   =   GetU16LE( s3 ) & 0x000f;
            g_page_y   = ( GetU16LE( s3 ) & 0x0010 ) >> 0x04;
            g_blending = ( GetU16LE( s3 ) & 0x0060 ) >> 0x05;
            g_bpp      = ( GetU16LE( s3 ) & 0x0180 ) >> 0x07;
            s3 += 0x02;
            LOGGER->Log( "Set global tex page x = " + ToHexString( g_page_x, 4, '0' ) +", tex page y = " + ToHexString( g_page_y, 4, '0' ) + ", blending = " + ToHexString( g_blending, 2, '0' ) + ", bpp = " + ToHexString( g_bpp, 2, '0' ) + "\n" );
            s1 += 0x06;
        }
        if( GetU16LE( s1 ) == 0x7fff )
        {
            break;
        }

        u16 sprite_num = GetU16LE( s1 + 0x04 );

        for( u32 i = 0; i < sprite_num; ++i )
        {
            s16 dest_x    =   GetU16LE( s5 + 0x00 );
            s16 dest_y    =   GetU16LE( s5 + 0x02 );
            u8  src_x     =   GetU16LE( s5 + 0x04 );
            u8  src_y     =   GetU16LE( s5 + 0x05 );
            u16 clut_y    = ( GetU16LE( s5 + 0x06 ) & 0xffc0 ) >> 6;
            u16 clut_x    = ( GetU16LE( s5 + 0x06 ) & 0x003f ) << 4;
            u8  animation =   GetU8( s5 + 0x08 ) & 0x0f;
            u8  index     =   GetU8( s5 + 0x09 );

            LOGGER->Log( "Add layer 4 sprite to (" + ToIntString( dest_x ) + " " + ToIntString( dest_y ) + ") from (" + ToIntString( src_x ) + " " + ToIntString( src_y ) + " texpage_x " + ToIntString( g_page_x ) + ", texpage_y " + ToIntString( g_page_y ) + ", clut_x " + ToIntString( clut_x ) + ", clut_y " + ToIntString( clut_y ) + "). Anim group " + ToIntString( animation ) + ", index " + ToIntString( index ) + ". Anim " + ToHexString( GetU16LE(s5 + 0x08), 4, '0' ) + "\n" );
            AddTile( 3, dest_x, dest_y, src_x, src_y, clut_x, clut_y, g_bpp, g_page_x, g_page_y, 0, g_blending, animation, index, mim, export_text );
            s5 += 0x0a;
        }
    }



    Ogre::TexturePtr ptex;
    Ogre::HardwarePixelBufferSharedPtr buffer;
    ptex = Ogre::TextureManager::getSingleton().createManual( "DynaTex", "General", Ogre::TEX_TYPE_2D, width, height, 0, Ogre::PF_R8G8B8A8, Ogre::TU_STATIC );
    buffer = ptex->getBuffer( 0, 0 );
    buffer->lock( Ogre::HardwareBuffer::HBL_DISCARD );
    const Ogre::PixelBox& pb = buffer->getCurrentLock();

    for( u32 y = 0; y < height; ++y )
    {
        u32* data = static_cast< u32* >( pb.data ) + y * pb.rowPitch;

        for( u32 x = 0; x < width; ++x )
        {
            u32 clut = full_image->pixels[ y * width * 4 + x * 4 + 3 ] | ( full_image->pixels[ y * width * 4 + x * 4 + 2 ] << 8 ) | ( full_image->pixels[ y * width * 4 + x * 4 + 1 ] << 16 ) | ( full_image->pixels[ y * width * 4 + x * 4 + 0 ] << 24 );
            data[ x ] = clut;
        }
    }

    Ogre::Image image;
    image.loadDynamicImage( ( Ogre::uchar* )pb.data, width, height, Ogre::PF_R8G8B8A8 );
    image.save( export_path + "maps/field/" + field.name + ".png" );
    buffer->unlock();
    Ogre::TextureManager::getSingleton().remove( "DynaTex" );

    export_text->Log( "</background2d>" );
    delete export_text;
}



void
DatFile::AddTile( const u8 background, const s16 dest_x, const s16 dest_y, const u8 src_x, const u8 src_y, const u16 clut_x, const u16 clut_y, const u8 bpp, const u8 page_x, const u8 page_y, const u16 depth, const u8 blending, const u8 animation, const u8 animation_index, MimFile& mim, Logger* export_text )
{
    SurfaceTexData surface;
    surface.page_x = page_x;
    surface.page_y = page_y;
    surface.clut_x = clut_x;
    surface.clut_y = clut_y;
    surface.bpp    = bpp;

    std::vector< SurfaceTexData >::iterator it = std::find_if( m_Surfaces.begin(), m_Surfaces.end(), surface_find( surface ) );

    if( it == m_Surfaces.end() )
    {
        surface.surface = mim.GetSurface( surface.page_x, surface.page_y, surface.clut_x, surface.clut_y, surface.bpp );
        m_Surfaces.push_back( surface );
    }
    else
    {
        surface = *it;
    }

    // set size depending on background
    u8 size = ( background > 1 ) ? 32 : 16;

    Surface* sub_image = CreateSubSurface( src_x, src_y, size, size, surface.surface );

    int x = 0;
    int y = 0;
    if( sub_image->width == 32 )
    {
        x = x_32;
        y = y_32;

        x_32 += 32;
        if( x_32 == full_image->width )
        {
            y_32 += 32;
            x_32 = 0;
        }
    }
    else if( sub_image->width == 16 )
    {
        // if we start new 16x16*4 block
        if( n_16 == 0 )
        {
            x_16 = x_32;
            y_16 = y_32;

            x_32 += 32;
            if( x_32 == full_image->width )
            {
                y_32 += 32;
                x_32 = 0;
            }
        }

        x = x_16;
        y = y_16;

        ++n_16;
        if( n_16 == 1 || n_16 == 3 )
        {
            x_16 += 16;
        }
        else if( n_16 == 2 )
        {
            x_16 -= 16;
            y_16 += 16;
        }
        else if( n_16 == 4 )
        {
            n_16 = 0;
        }
    }

    CopyToSurface( full_image, x, y, sub_image );

    export_text->Log(
                        "    <tile destination=\"" +
                        Ogre::StringConverter::toString( dest_x * 3 ) +
                        " " +
                        Ogre::StringConverter::toString( dest_y * 3 ) +
                        "\" width=\"" +
                        Ogre::StringConverter::toString( sub_image->width * 3 ) +
                        "\" height=\"" +
                        Ogre::StringConverter::toString( sub_image->height * 3 ) +
                        "\" uv1=\"" +
                        Ogre::StringConverter::toString( x / ( float ) full_image->width ) +
                        " " +
                        Ogre::StringConverter::toString( y / ( float ) full_image->height ) +
                        "\" uv2=\"" +
                        Ogre::StringConverter::toString( ( x + sub_image->width ) / ( float ) full_image->width ) +
                        " " +
                        Ogre::StringConverter::toString( ( y + sub_image->height ) / ( float ) full_image->height ) +
                        "\" depth=\"" +
                        Ogre::StringConverter::toString( depth / 1024.0f ) +
                        "\" />\n"
    );

    delete sub_image;
}
