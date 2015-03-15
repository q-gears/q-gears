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
        return ( a.page_x     == m_Surface.page_x ) &&
               ( a.page_y     == m_Surface.page_y ) &&
               ( a.clut_y     == m_Surface.clut_y ) &&
               ( a.clut_x     == m_Surface.clut_x ) &&
               ( a.bpp        == m_Surface.bpp ) &&
               ( a.clut_start == m_Surface.clut_start ) &&
               ( a.clut_width == m_Surface.clut_width ) &&
               ( a.mod_type   == m_Surface.mod_type ) &&
               ( a.mod_r      == m_Surface.mod_r ) &&
               ( a.mod_g      == m_Surface.mod_g ) &&
               ( a.mod_b      == m_Surface.mod_b );
    }

private:
    SurfaceTexData m_Surface;
};



class added_tile_find
{
public:
    added_tile_find( const AddedTile& a ):
        m_Tile( a )
    {
    }

    bool
    operator()( const AddedTile& a ) const
    {
        return ( a.background == m_Tile.background ) &&
               ( a.src_x      == m_Tile.src_x ) &&
               ( a.src_y      == m_Tile.src_y ) &&
               ( a.clut_x     == m_Tile.clut_x ) &&
               ( a.clut_y     == m_Tile.clut_y ) &&
               ( a.bpp        == m_Tile.bpp ) &&
               ( a.page_x     == m_Tile.page_x ) &&
               ( a.page_y     == m_Tile.page_y ) &&
               ( a.clut_start == m_Tile.clut_start ) &&
               ( a.clut_width == m_Tile.clut_width ) &&
               ( a.mod_type   == m_Tile.mod_type ) &&
               ( a.mod_r      == m_Tile.mod_r ) &&
               ( a.mod_g      == m_Tile.mod_g ) &&
               ( a.mod_b      == m_Tile.mod_b );
    }

private:
    AddedTile m_Tile;
};



class anim_time_sort
{
public:
    bool
    operator()( const KeyFrame& x, const KeyFrame& y ) const
    {
        return x.time < y.time;
    }
};



class anim_name_sort
{
public:
    bool
    operator()( const Animation& x, const Animation& y ) const
    {
        return x.name < y.name;
    }
};



std::vector< Ogre::String > DatFile::m_SoundOpcodes;



//////////////////////////////////////////////
static const unsigned short english_chars[256] = {
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

static const unsigned short japanese_chars[256] = {
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



static const unsigned short japanese_chars_fa[256] = {
    // 0    1       2       3       4       5       6       7       8       9       A       B       C       D       E       F
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x2759, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x00 - 0x0F
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x10 - 0x1F
    0x0672, 0x7F4F, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x3478, 0x4466, 0x8364, 0x0000, 0x0000, 0x0000, // 0x20 - 0x2F
    0x0000, 0x0000, 0x0000, 0x0000, 0x666B, 0x5E79, 0x0000, 0x0000, 0xA898, 0x0000, 0x176C, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x30 - 0x3F
    0x885B, 0x0000, 0x7D54, 0x0000, 0xD552, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x6297, 0x0000, 0x0000, 0x0000, 0x0854, 0x0000, // 0x40 - 0x4F
    0x0000, 0x0000, 0x0E66, 0x0000, 0x0000, 0x9C62, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x004E, 0x0000, 0x0580, // 0x50 - 0x5F
    0x0000, 0x0000, 0x857F, 0x0000, 0x0000, 0x0000, 0x9950, 0x6856, 0x0000, 0x549B, 0xD56C, 0x0000, 0x0000, 0x0000, 0x0000, 0xFA51, // 0x60 - 0x6F
    0x0163, 0xF876, 0x4B62, 0x0000, 0xBA78, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xB965, 0x4C88, 0x0000, // 0x70 - 0x7F
    0x9A5B, 0x0000, 0x0000, 0x4D52, 0x1F77, 0x0000, 0x9A89, 0x1752, 0x8C5F, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xDE56, 0x0000, // 0x80 - 0x8F
    0x9A7D, 0x7565, 0x0000, 0x0000, 0x0000, 0x0000, 0x3E5C, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0882, 0x0000, 0x0000, // 0x90 - 0x9F
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x3E5F, 0x0000, 0x0000, 0x0000, 0x4266, 0x0000, 0x0000, 0x2662, 0x0000, // 0xA0 - 0xAF
    0x0000, 0x0000, 0x0000, 0x0000, 0xB751, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xEA8C, 0x0000, 0x0000, 0x0000, // 0xB0 - 0xBF
    0xCD53, 0x0000, 0xEE76, 0x0000, 0x0000, 0x9B52, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x7551, 0x0000, 0x0000, 0x0000, // 0xC0 - 0xCF
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0xD0 - 0xDF
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0xE0 - 0xEF
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0xF0 - 0xFF
};



static const unsigned short japanese_chars_fb[256] = {
    // 0    1       2       3       4       5       6       7       8       9       A       B       C       D       E       F
    0x0000, 0x0000, 0xB182, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0B4E, 0x0000, 0x6551, 0x4851, 0x0D4E, 0x505B, 0x9B4F, 0x4B5C, // 0x00 - 0x0F
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x8E96, 0x0000, 0x0000, 0xE890, 0x0000, 0x3458, 0x0000, 0xF24E, 0x9395, 0x0000, 0x0000, // 0x10 - 0x1F
    0x5096, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x554F, 0x0000, 0x9965, 0x0000, 0x0A4E, 0x0000, 0x8B4E, 0x0000, 0x0000, // 0x20 - 0x2F
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x6559, 0x0000, 0x0000, 0x0000, 0x1D52, 0x5167, 0x0000, 0x0000, 0x0000, 0x0000, // 0x30 - 0x3F
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x40 - 0x4F
    0x0000, 0x0000, 0xCA8E, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xBA87, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x50 - 0x5F
    0x0000, 0x7751, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xB672, 0x4B61, 0x0000, // 0x60 - 0x6F
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x8B95, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x70 - 0x7F
    0x0000, 0x0C54, 0x1F90, 0x4590, 0x0000, 0x0000, 0x0000, 0x0000, 0x7354, 0x0000, 0x0000, 0x0000, 0x0D50, 0x0000, 0x0000, 0x0000, // 0x80 - 0x8F
    0x0000, 0xBA4E, 0xCA4E, 0x0000, 0x0000, 0x535F, 0x0000, 0x0000, 0xDB98, 0xE54E, 0x1659, 0x0000, 0x0000, 0x0000, 0xAB8E, 0x0000, // 0x90 - 0x9F
    0xCB65, 0x0000, 0x0000, 0x0000, 0x5F6A, 0xB068, 0x0000, 0x8970, 0xB065, 0x214E, 0x2C67, 0x1B54, 0x0000, 0x8551, 0x5C4F, 0x668B, // 0xA0 - 0xAF
    0x7972, 0x0000, 0x0000, 0x0000, 0x747A, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xB38D, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0xB0 - 0xBF
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x7795, 0x0000, 0x0000, 0x5458, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x8B89, // 0xC0 - 0xCF
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x4351, 0x0000, 0x0000, 0x0000, 0x427D, 0x0000, 0x0000, 0x0D54, 0x0000, 0x0000, // 0xD0 - 0xDF
    0x0000, 0x1062, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0xE0 - 0xEF
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0xF0 - 0xFF
};



static const unsigned short japanese_chars_fc[256] = {
    // 0    1       2       3       4       5       6       7       8       9       A       B       C       D       E       F
    0x0000, 0x0000, 0x188A, 0x0000, 0x7890, 0x6A75, 0x5788, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x00 - 0x0F
    0x9358, 0xC35F, 0x0000, 0x0000, 0x0000, 0x0000, 0x5390, 0x0000, 0x0000, 0x0000, 0x0000, 0xFB5D, 0x0000, 0x0000, 0x0000, 0x0000, // 0x10 - 0x1F
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x884E, 0x0000, 0x3D84, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x20 - 0x2F
    0xE565, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xE353, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x30 - 0x3F
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x296E, 0x0000, 0x0000, 0x0000, 0x0000, 0x708D, 0x0000, 0x0000, 0x0000, 0x0000, // 0x40 - 0x4F
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



static const unsigned short japanese_chars_fd[256] = {
    // 0    1       2       3       4       5       6       7       8       9       A       B       C       D       E       F
    0x0000, 0x1D4F, 0x0000, 0xA263, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x00 - 0x0F
    0xE682, 0x0000, 0xF056, 0x0000, 0x0000, 0x0000, 0x0000, 0xA25B, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x10 - 0x1F
    0x0000, 0x2B59, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xB88C, 0x1F67, 0x0000, 0x0000, 0x0000, 0x0000, 0xDD4F, 0x2F5E, // 0x20 - 0x2F
    0x0000, 0x0000, 0x0000, 0x1154, 0x0000, 0x0000, 0x7289, 0x0000, 0x216B, 0x0000, 0x207D, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x30 - 0x3F
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xB78C, 0x0000, 0x0000, 0x0000, 0x7C5E, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x40 - 0x4F
    0x0000, 0x0000, 0x0000, 0x0000, 0x8179, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x50 - 0x5F
    0x0000, 0x975E, 0x0000, 0x0000, 0x0000, 0xCA7D, 0x1478, 0x0000, 0x0000, 0x8766, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x60 - 0x6F
    0xC599, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x70 - 0x7F
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFD88, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x80 - 0x8F
    0x0000, 0x0000, 0x3293, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x5453, 0x0000, 0x0000, // 0x90 - 0x9F
    0x0000, 0x0000, 0x0000, 0x0000, 0x3181, 0x0000, 0x8D8E, 0x0000, 0x0000, 0x0000, 0x0000, 0x3052, 0x0000, 0x0000, 0x0000, 0x0000, // 0xA0 - 0xAF
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0xB0 - 0xBF
    0x9F52, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x5291, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0xC0 - 0xCF
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0xD0 - 0xDF
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0xE0 - 0xEF
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0xF0 - 0xFF
};



static const unsigned short japanese_chars_fe[256] = {
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



static const std::map<int, Ogre::String> MapIdToFieldName
{
    { 0x74, "ffvii_md1stin" },
    { 0x75, "ffvii_md1_1" },
    { 0x76, "ffvii_md1_2" }
};

Ogre::String
MapIdToString( const int map_id )
{
    auto it = MapIdToFieldName.find(map_id);
    if (it != std::end(MapIdToFieldName))
    {
        return it->second;
    }
    return "Unknown_0x" + HexToString( map_id, 4, '0' );
}



float
MapIdToScale( const int map_id )
{
    switch( map_id )
    {
        case 0x75: return 2.0f;
    }

    return 1.0f;
}

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
    delete full_image;

    for( u8 i = 0; i < m_Surfaces.size(); ++i )
    {
        delete m_Surfaces[ i ].surface;
    }
    m_Surfaces.clear();
}


void
DatFile::DumpText( const Ogre::String& export_path, const Field& field, bool english )
{
    std::sort( m_Dialogs.begin(), m_Dialogs.end() );
    m_Dialogs.erase( std::unique( m_Dialogs.begin(), m_Dialogs.end()), m_Dialogs.end() );

    Logger* export_text = new Logger( export_path + "maps/ffvii_field/" + field.name + "_text.txt" );

    // get sector 1 offset (scripts and dialog)
    u32 offset_to_sector  = 0x1C;
    u16 offset_to_dialogs = GetU16LE( offset_to_sector + 0x04 );

    std::vector< unsigned char > dialog;
    dialog.push_back(0xFF);
    dialog.push_back(0xFE);

    for (unsigned int i = 0; i < m_Dialogs.size(); ++i)
    {
        // get offset of string data
        u32 offset = offset_to_sector + offset_to_dialogs + GetU16LE(offset_to_sector + offset_to_dialogs + 0x02 + m_Dialogs[i] * 0x02);

        export_text->Log(dialog);
        dialog.clear();
        export_text->LogW( "<dialog id=\"" + IntToString(m_Dialogs[i]) + "\">" );

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
                export_text->LogW("<next_page />");
            }
            else if (temp == 0xEA)
            {
                export_text->Log(dialog);
                dialog.clear();
                export_text->LogW("<include name=\"char_cloud\" />");
            }
            else if (temp == 0xEB)
            {
                export_text->Log(dialog);
                dialog.clear();
                export_text->LogW("<include name=\"char_barret\" />");
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
                export_text->LogW("<image sprite=\"ButtonCircle\" />");
            }
            else if (temp == 0xF7)
            {
                export_text->Log(dialog);
                dialog.clear();
                export_text->LogW("<image sprite=\"ButtonTriangle\" />");
            }
            else if (temp == 0xF8)
            {
                export_text->Log(dialog);
                dialog.clear();
                export_text->LogW("<image sprite=\"ButtonSquare\" />");
            }
            else if (temp == 0xF9)
            {
                export_text->Log(dialog);
                dialog.clear();
                export_text->LogW("<image sprite=\"ButtonCross\" />");
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
                        export_text->LogW("[MISSING 0xFA " + HexToString(temp2, 2, '0') + "]");
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
                        export_text->LogW("[MISSING 0xFB " + HexToString(temp2, 2, '0') + "]");
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
                        export_text->LogW("[MISSING 0xFC " + HexToString(temp2, 2, '0') + "]");
                    }
                }
                else if( temp == 0xFD )
                {
                    if( japanese_chars_fd[ temp2 ] != 0x0000 )
                    {
                        dialog.push_back( japanese_chars_fd[ temp2 ] >> 8 ); dialog.push_back( japanese_chars_fd[ temp2 ] & 0xFF );
                    }
                    else
                    {
                        export_text->Log( dialog );
                        dialog.clear();
                        export_text->LogW( "[MISSING 0xFD " + HexToString( temp2, 2, '0' ) + "]" );
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
                    export_text->LogW("</colour>");
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
                    export_text->LogW("<pause time=\"" + IntToString(wait) + "\" />");
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
                        export_text->LogW("[MISSING 0xFE " + HexToString(temp2, 2, '0') + "]");
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
                    export_text->LogW("[MISSING CHAR " + HexToString(temp, 2, '0') + "]");
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
DatFile::DumpScript(const Ogre::String& export_path, const Field& field)
{
    Logger* export_script = new Logger(export_path + "maps/ffvii_field/" + field.name + "_script.txt");

    // get sector 1 offset (scripts and dialog)
    u32 start_address = GetU32LE(0);
    u32 offset_to_sector = 0x1c;

    u8  number_of_entity = GetU8(offset_to_sector + 0x02);
    u16 string_offset = GetU16LE(offset_to_sector + 0x04);
    u16 number_of_extra_offsets = GetU16LE(offset_to_sector + 0x06);

    float downscaler = 128.0f * field.scale;

    std::vector< Ogre::String > entity_list;

    for (u8 i = 0; i < number_of_entity; ++i)
    {
        // get entity name
        Ogre::String name = Ogre::String(reinterpret_cast<char*>(m_Buffer)+offset_to_sector + 0x20 + i * 0x08);
        if (name == "")
        {
            name = "unnamed_" + IntToString(i);
        }
        entity_list.push_back(name);
    }

    for (u8 i = 0; i < number_of_entity; ++i)
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

            export_script->Log("script_" + IntToString(j) + ":\n");

            for (; script <= end;)
            {
                export_script->Log(OffsetString(script) + " (end " + OffsetString(end) + "): ");

                u8 opcode = GetU8(script);

                switch (opcode)
                {
                case RET:
                {
                    export_script->Log("return\n");

                    if (j == 0 && one_ret_check == false) // in init we need to meet ret at least once
                    {
                        AdvanceScript(1, script, end);
                        one_ret_check = true;
                    }
                    else
                    {
                        script += 1;
                    }
                } break;

                case REQ:
                {
                    u8 entity_id = GetU8(script + 1);
                    u8 priority = GetU8(script + 2) >> 5;
                    u8 script_id = GetU8(script + 2) & 0x1F;
                    export_script->Log("script:request( \"" + entity_list[entity_id] + "\", \"script_" + IntToString(script_id) + "\", " + IntToString(priority) + " )\n");
                    AdvanceScript(3, script, end);
                } break;

                case REQSW:
                {
                    u8 entity_id = GetU8(script + 1);
                    u8 priority = GetU8(script + 2) >> 5;
                    u8 script_id = GetU8(script + 2) & 0x1F;
                    export_script->Log("script:request_start_sync( \"" + entity_list[entity_id] + "\", \"script_" + IntToString(script_id) + "\", " + IntToString(priority) + " )\n");
                    AdvanceScript(3, script, end);
                } break;

                case REQEW:
                {
                    u8 entity_id = GetU8(script + 1);
                    u8 priority = GetU8(script + 2) >> 5;
                    u8 script_id = GetU8(script + 2) & 0x1F;
                    export_script->Log("script:request_end_sync( \"" + entity_list[entity_id] + "\", \"script_" + IntToString(script_id) + "\", " + IntToString(priority) + " )\n");
                    AdvanceScript(3, script, end);
                } break;

                case RETTO:
                {
                    u8 priority = GetU8(script + 1) >> 5;
                    u8 script_id = GetU8(script + 1) & 0x1F;

                    export_script->Log(
                        "return_to( \"script_" +
                        IntToString(script_id) +
                        "\", " +
                        IntToString(priority) +
                        " );\n"
                        );

                    script += 2;
                } break;

                case JOIN:
                {
                    export_script->Log(
                        "[UNREVERSED] JOIN(" +
                        ArgumentString(script + 1, 1) +
                        ");\n"
                        );

                    AdvanceScript(2, script, end);
                } break;

                case SPLIT:
                {
                    export_script->Log(
                        "[UNREVERSED] SPLIT(" +
                        ArgumentString(script + 1, 14) +
                        ");\n"
                        );

                    AdvanceScript(15, script, end);
                } break;

                case SPTYE:
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
                } break;

                case GTPYE:
                {
                    export_script->Log(
                        SetVariable(GetU8(script + 1) >> 4, GetU8(script + 3), "game:party_get_id_of_member( 0 )") +
                        SetVariable(GetU8(script + 1) & 0x0F, GetU8(script + 4), "game:party_get_id_of_member( 1 )") +
                        SetVariable(GetU8(script + 2) >> 4, GetU8(script + 5), "game:party_get_id_of_member( 2 )")
                        );
                    AdvanceScript(6, script, end);
                } break;

                case SPECIAL:
                {
                    u8 special_opcode = GetU8(script + 1);

                    if (special_opcode == 0xF5) // ARROW
                    {
                        export_script->Log(
                            "game:pointer_enable( " +
                            BoolToString(!(GetU8(script + 2))) +
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
                            BoolToString(!(GetU8(script + 2))) +
                            " )\n"
                            );
                        AdvanceScript(3, script, end);
                    }
                    else if (special_opcode == 0xFC) // MVLCK
                    {
                        export_script->Log(
                            "game:movie_enable( " +
                            BoolToString(!(GetU8(script + 2))) +
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
                        export_script->Log("[SPECIAL OPCODE " + HexToString(special_opcode, 2, '0') + "]\n");
                        script += 2;
                    }
                } break;

                case JMPF:
                {
                    u32 temp_end = script + GetU8(script + 1) + 1;
                    export_script->Log("jumpto( " + OffsetString(temp_end) + " );\n");
                    end = (temp_end > end) ? temp_end : end;
                    script += 2;
                } break;

                case JMPFL:
                {
                    u32 temp_end = script + GetU16LE(script + 1) + 1;

                    export_script->Log(
                        "jumpto( " +
                        OffsetString(temp_end) +
                        " );\n"
                        );

                    end = (temp_end > end) ? temp_end : end;
                    script += 3;
                } break;

                case JMPB:
                {
                    export_script->Log(
                        "jumpto( " +
                        OffsetString(script - GetU8(script + 1)) +
                        " );\n"
                        );

                    script += 2;
                } break;

                case JMPBL:
                {
                    export_script->Log(
                        "jumpto( " +
                        OffsetString(script - GetU16LE(script + 1)) +
                        " );\n"
                        );

                    script += 3;
                } break;

                case IFUB:
                {
                    u32 temp_end = script + GetU8(script + 5) + 5;

                    export_script->Log(
                        "if ( " +
                        ParseRelation(GetU8(script + 4), ParseGetVariable(GetU8(script + 1) >> 4, GetU8(script + 2)), ParseGetVariable(GetU8(script + 1) & 0x0F, GetU8(script + 3))) +
                        " ) then continue else jumpto(" + OffsetString(temp_end) + ");\n"
                        );

                    end = (temp_end > end) ? temp_end : end;
                    script += 6;
                } break;

                case IFUBL:
                {
                    u32 temp_end = script + GetU16LE(script + 5) + 5;

                    export_script->Log(
                        "if ( " +
                        ParseRelation(GetU8(script + 4), ParseGetVariable(GetU8(script + 1) >> 4, GetU8(script + 2)), ParseGetVariable(GetU8(script + 1) & 0x0F, GetU8(script + 3))) +
                        " ) then continue else jumpto(" + OffsetString(temp_end) + ");\n"
                        );

                    end = (temp_end > end) ? temp_end : end;
                    script += 7;
                } break;

                case IFSW:
                {
                    u32 temp_end = script + GetU8(script + 7) + 7;

                    export_script->Log(
                        "if ( " +
                        ParseRelation(GetU8(script + 6), ParseGetVariable(GetU8(script + 1) >> 4, (s16)GetU16LE(script + 2)), ParseGetVariable(GetU8(script + 1) & 0x0F, (s16)GetU16LE(script + 4))) +
                        " ) then continue else jumpto(" + OffsetString(temp_end) + ");\n"
                        );

                    // If we find a jump back to this address, then this if statement is actually a while()

                    end = (temp_end > end) ? temp_end : end;
                    script += 8;
                } break;

                case IFSWL:
                {
                    u32 temp_end = script + GetU16LE(script + 7) + 7;

                    export_script->Log(
                        "if ( " +
                        ParseRelation(GetU8(script + 6), ParseGetVariable(GetU8(script + 1) >> 4, (s16)GetU16LE(script + 2)), ParseGetVariable(GetU8(script + 1) & 0x0F, (s16)GetU16LE(script + 4))) +
                        " ) then continue else jumpto(" + OffsetString(temp_end) + ");\n"
                        );

                    end = (temp_end > end) ? temp_end : end;
                    script += 9;
                } break;

                case IFUW:
                {
                    u32 temp_end = script + GetU8(script + 7) + 7;

                    export_script->Log(
                        "if ( " +
                        ParseRelation(GetU8(script + 6), ParseGetVariable(GetU8(script + 1) >> 4, GetU16LE(script + 2)), ParseGetVariable(GetU8(script + 1) & 0x0F, GetU16LE(script + 4))) +
                        " ) then continue else jumpto(" + OffsetString(temp_end) + ");\n"
                        );

                    end = (temp_end > end) ? temp_end : end;
                    script += 8;
                } break;

                case TUTOR:
                {
                    export_script->Log(
                        "[UNREVERSED] TUTOR(" +
                        ArgumentString(script + 1, 1) +
                        ");\n"
                        );

                    AdvanceScript(2, script, end);
                } break;

                case WAIT:
                {
                    export_script->Log("script:wait( " + FloatToString(GetU16LE(script + 1) / 30.0f) + " )\n");
                    AdvanceScript(3, script, end);
                } break;

                case NFADE:
                {
                    u8 type = GetU8(script + 3);

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
                } break;

                case BLINK:
                {
                    export_script->Log(
                        entity_list[i] +
                        ":enable_eye_blink(" +
                        BoolToString(!(GetU8(script + 1))) +
                        ");\n"
                        );

                    AdvanceScript(2, script, end);
                } break;

                case KAWAI:
                {
                    u8 kawai_length = GetU8(script + 1);

                    export_script->Log(
                        "[UNREVERSED] KAWAI(" +
                        ArgumentString(script + 1, kawai_length - 1) +
                        ");\n"
                        );

                    AdvanceScript(kawai_length, script, end);
                } break;

                case WCLS:
                {
                    export_script->Log(
                        "[UNREVERSED] WCLS(" +
                        ArgumentString(script + 1, 1) +
                        ");\n"
                        );

                    AdvanceScript(2, script, end);
                } break;

                case WSIZW:
                {
                    u8 type = GetU8(script + 2);

                    export_script->Log(
                        "-- resize window (id = " +
                        IntToString(GetU8(script + 1)) +
                        ", x = " +
                        IntToString(GetU16LE(script + 2)) +
                        ", y = " +
                        IntToString(GetU16LE(script + 4)) +
                        ", width = " +
                        IntToString(GetU16LE(script + 6)) +
                        ", height = " +
                        IntToString(GetU16LE(script + 8)) +
                        ");\n"
                        );

                    AdvanceScript(10, script, end);
                } break;

                case IFKEY:
                {
                    u32 temp_end = script + GetU8(script + 3) + 3;

                    export_script->Log(
                        "if (pressed buttons \"" +
                        HexToString(GetU16LE(script + 1), 4, '0') +
                        "\") then continue else jumpto(" + OffsetString(temp_end) + ");\n"
                        );

                    end = (temp_end > end) ? temp_end : end;
                    script += 4;
                } break;

                case IFKEYON:
                {
                    u32 temp_end = script + GetU8(script + 3) + 3;

                    export_script->Log(
                        "if (first pressed buttons \"" +
                        HexToString(GetU16LE(script + 1), 4, '0') +
                        "\") then continue else jumpto(" + OffsetString(temp_end) + ");\n"
                        );

                    end = (temp_end > end) ? temp_end : end;
                    script += 4;
                } break;

                case UC:
                {
                    export_script->Log(
                        "field:pc_lock(" +
                        BoolToString(GetU8(script + 1) > 0) +
                        ");\n"
                        );

                    AdvanceScript(2, script, end);
                } break;

                case WSPCL:
                {
                    export_script->Log(
                        "[UNREVERSED] WSPCL(" +
                        ArgumentString(script + 1, 4) +
                        ");\n"
                        );

                    AdvanceScript(5, script, end);
                } break;

                case STTIM:
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
                } break;

                case GOLDU:
                {
                    export_script->Log(
                        "game:add_money(upper(" +
                        ParseGetVariable(GetU8(script + 1) & 0x0F, GetU16LE(script + 4)) +
                        "), lower(" +
                        ParseGetVariable(GetU8(script + 1) >> 4, GetU16LE(script + 2)) +
                        "));\n"
                        );
                    AdvanceScript(6, script, end);
                } break;

                case GOLDD:
                {
                    export_script->Log(
                        "game:remove_money(upper(" +
                        ParseGetVariable(GetU8(script + 1) & 0x0F, GetU16LE(script + 4)) +
                        "), lower(" +
                        ParseGetVariable(GetU8(script + 1) >> 4, GetU16LE(script + 2)) +
                        "));\n"
                        );
                    AdvanceScript(6, script, end);
                } break;

                case CHGLD:
                {
                    export_script->Log(
                        SetVariable(GetU8(script + 1) >> 4, GetU8(script + 2), "game:get_money_lower()") +
                        SetVariable(GetU8(script + 1) & 0x0F, GetU8(script + 3), "game:get_money_top()")
                        );
                    AdvanceScript(4, script, end);
                } break;

                case MHMMX:
                {
                    export_script->Log(
                        "game:restore_hp_mp_status_to_all();\n"
                        );
                    AdvanceScript(1, script, end);
                } break;

                case HMPMAX3:
                {
                    export_script->Log(
                        "game:party_restore_hp_mp();\n"
                        );
                    AdvanceScript(1, script, end);
                } break;

                case MESSAGE:
                {
                    m_Dialogs.push_back(GetU8(script + 2));
                    export_script->Log(
                        "message:show_text_wait(" +
                        IntToString(GetU8(script + 1)) +
                        ", " +
                        IntToString(GetU8(script + 2)) +
                        ", x, y);\n"
                        );

                    AdvanceScript(3, script, end);
                } break;

                case MPNAM:
                {
                    m_Dialogs.push_back(GetU8(script + 1));
                    export_script->Log(
                        "field:map_name(" +
                        IntToString(GetU8(script + 1)) +
                        ");\n"
                        );

                    AdvanceScript(2, script, end);
                } break;

                case ASK:
                {
                    m_Dialogs.push_back(GetU8(script + 3));
                    export_script->Log(
                        "message:show_text_wait(" +
                        IntToString(GetU8(script + 2)) +
                        ", " +
                        IntToString(GetU8(script + 3)) +
                        ", x, y); -- ASK cursor at \"" +
                        ParseGetVariable(GetU8(script + 1), GetU8(script + 6)) +
                        "\", start " +
                        IntToString(GetU8(script + 4)) +
                        ", end " +
                        IntToString(GetU8(script + 5)) +
                        "\n"
                        );

                    AdvanceScript(7, script, end);
                } break;

                case MENU:
                {
                    export_script->Log(
                        "[UNREVERSED] MENU(" +
                        ArgumentString(script + 1, 3) +
                        ");\n"
                        );

                    AdvanceScript(4, script, end);
                } break;

                case MENU2:
                {
                    export_script->Log(
                        "field:menu_lock(" +
                        BoolToString(GetU8(script + 1) > 0) +
                        ");\n"
                        );

                    AdvanceScript(2, script, end);
                } break;

                case BTLTB:
                {
                    export_script->Log(
                        "field:set_battle_table(" +
                        IntToString(GetU8(script + 1)) +
                        ");\n"
                        );

                    AdvanceScript(2, script, end);
                } break;

                case WINDOW:
                {
                    export_script->Log(
                        "-- set window parameters (id = " +
                        IntToString(GetU8(script + 1)) +
                        ", x = " +
                        IntToString(GetU16LE(script + 2)) +
                        ", y = " +
                        IntToString(GetU16LE(script + 4)) +
                        ", width = " +
                        IntToString(GetU16LE(script + 6)) +
                        ", height = " +
                        IntToString(GetU16LE(script + 8)) +
                        ");\n"
                        );

                    AdvanceScript(10, script, end);
                } break;

                case WMODE:
                {
                    u8 type = GetU8(script + 2);

                    export_script->Log(
                        "-- set window mode (id = " +
                        IntToString(GetU8(script + 1)) +
                        ", MessageStyle." +
                        ((type == 0) ? "SOLID" : ((type == 1) ? "NONE" : "TRANSPARENT")) +
                        ", disable input from player: " +
                        BoolToString(GetU8(script + 3) > 0) +
                        ");\n"
                        );

                    AdvanceScript(4, script, end);
                } break;

                case WREST:
                {
                    export_script->Log(
                        "-- reset window to default (id = " +
                        IntToString(GetU8(script + 1)) +
                        ");\n"
                        );

                    AdvanceScript(2, script, end);
                } break;

                case WCLSE:
                {
                    export_script->Log(
                        "[UNREVERSED] WCLSE(" +
                        ArgumentString(script + 1, 1) +
                        ");\n"
                        );

                    AdvanceScript(2, script, end);
                } break;

                case STITM:
                {
                    export_script->Log(
                        "game:item_add(" +
                        ParseGetVariable(GetU8(script + 1) >> 4, GetU16LE(script + 2)) +
                        ", " +
                        ParseGetVariable(GetU8(script + 1) & 0x0F, GetU8(script + 4)) +
                        ");\n"
                        );

                    AdvanceScript(5, script, end);
                } break;

                case CKITM:
                {
                    export_script->Log(
                        SetVariable(GetU8(script + 1), GetU8(script + 4), "game:get_number_of_item(" + IntToString(GetU16LE(script + 2)) + ")")
                        );
                    AdvanceScript(5, script, end);
                } break;

                case SMTRA:
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
                } break;

                case SHAKE:
                {
                    export_script->Log(
                        "[UNREVERSED] SHAKE(" +
                        ArgumentString(script + 1, 7) +
                        ");\n"
                        );

                    AdvanceScript(8, script, end);
                } break;

                case MAPJUMP:
                {
                    export_script->Log(
                        "field:jump_to_map(" +
                        IntToString(GetU16LE(script + 1)) +
                        ", " +
                        IntToString(GetU16LE(script + 3)) +
                        ", " +
                        IntToString(GetU16LE(script + 5)) +
                        ", " +
                        IntToString(GetU16LE(script + 7)) +
                        ", " +
                        FloatToString((GetU8(script + 9) / 256.0f) * 360.0f) +
                        ");\n"
                        );

                    AdvanceScript(10, script, end);
                } break;

                case SCRLC:
                {
                    int type = GetU8(script + 4);

                    export_script->Log(
                        "field:screen_set_scroll_to_pc(" +
                        ((type == 4) ? "Field.NONE" : ((type == 5) ? "Field.LINEAR" : ((type == 6) ? "Field.SMOOTH" : "Unknown_type_" + IntToString(type)))) +
                        ", " +
                        ParseGetVariable(GetU8(script + 1) & 0x0F, GetU16LE(script + 2), 0, 30.0f) +
                        ");\n"
                        );

                    AdvanceScript(5, script, end);
                } break;

                case SCRLA:
                {
                    int type = GetU8(script + 5);

                    export_script->Log(
                        "field:screen_set_scroll_to_entity(" +
                        entity_list[GetU8(script + 4)] +
                        ", " +
                        ((type == 1) ? "Field.NONE" : ((type == 2) ? "Field.LINEAR" : ((type == 3) ? "Field.SMOOTH" : "Unknown_type_" + IntToString(type)))) +
                        ", " +
                        ParseGetVariable(GetU8(script + 1), GetU16LE(script + 2), 0, 30.0f) +
                        ");\n"
                        );

                    AdvanceScript(6, script, end);
                } break;

                case SCR2D:
                {
                    export_script->Log("background2d:scroll_to_position( " + ParseGetVariable(GetU8(script + 1) >> 4, (s16)GetU16LE(script + 2)) + ", " + ParseGetVariable(GetU8(script + 1) & 0x0F, (s16)GetU16LE(script + 4)) + ", Background2D.NONE, 0 )\n");
                    AdvanceScript(6, script, end);
                } break;

                case SCRCC:
                {
                    export_script->Log("background2d:autoscroll_to_entity( --[[ player entity object here ]] )\n");
                    AdvanceScript(1, script, end);
                } break;

                case SCR2DC:
                {
                    export_script->Log("background2d:scroll_to_position( " + ParseGetVariable(GetU8(script + 1) >> 4, (s16)GetU16LE(script + 3)) + ", " + ParseGetVariable(GetU8(script + 1) & 0x0F, (s16)GetU16LE(script + 5)) + ", Background2D.SMOOTH, " + ParseGetVariable(GetU8(script + 2) & 0x0F, (s16)GetU16LE(script + 7), 0, 30.0f) + " )\n");
                    AdvanceScript(9, script, end);
                }  break;

                case SCRLW:
                {
                    export_script->Log("background2d:scroll_sync()\n");
                    AdvanceScript(1, script, end);
                } break;

                case SCR2DL:
                {
                    export_script->Log("background2d:scroll_to_position( " + ParseGetVariable(GetU8(script + 1) >> 4, (s16)GetU16LE(script + 3)) + ", " + ParseGetVariable(GetU8(script + 1) & 0x0F, (s16)GetU16LE(script + 5)) + ", Background2D.LINEAR, " + ParseGetVariable(GetU8(script + 2) & 0x0F, (s16)GetU16LE(script + 7), 0, 30.0f) + " )\n");
                    AdvanceScript(9, script, end);
                } break;

                case VWOFT:
                {
                    export_script->Log(
                        "[UNREVERSED] VWOFT(" +
                        ArgumentString(script + 1, 6) +
                        ");\n"
                        );

                    AdvanceScript(7, script, end);
                } break;

                case FADE:
                {
                    u8 type = GetU8(script + 7);

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
                            IntToString(speed) +
                            ", " +
                            IntToString(start) +
                            " );\n"
                            );
                    }

                    AdvanceScript(9, script, end);
                } break;

                case FADEW:
                {
                    export_script->Log("fade:wait();\n");
                    AdvanceScript(1, script, end);
                } break;

                case IDLCK:
                {
                    export_script->Log(
                        "field:lock_walkmesh( " +
                        IntToString(GetU16LE(script + 1)) +
                        ", " +
                        BoolToString(GetU8(script + 3) > 0) +
                        " );\n"
                        );

                    AdvanceScript(4, script, end);
                } break;

                case LSTMP:
                {
                    export_script->Log(
                        SetVariable(GetU8(script + 1), GetU8(script + 2), "field:get_last_map()")
                        );
                    AdvanceScript(3, script, end);
                } break;

                case BATTLE:
                {
                    export_script->Log(
                        "field:battle_run( " +
                        ParseGetVariable(GetU8(script + 1), GetU16LE(script + 2)) +
                        " );\n"
                        );

                    AdvanceScript(4, script, end);
                } break;

                case BTLON:
                {
                    export_script->Log(
                        "field:random_encounter_on( " +
                        BoolToString(!(GetU8(script + 1))) +
                        " );\n"
                        );

                    AdvanceScript(2, script, end);
                }  break;

                case BTLMD:
                {
                    export_script->Log(
                        "[UNREVERSED] BTLMD(" +
                        ArgumentString(script + 1, 2) +
                        ");\n"
                        );

                    AdvanceScript(3, script, end);
                } break;

                case PLUS_:
                {
                    export_script->Log(
                        SetVariable(GetU8(script + 1) >> 4, GetU8(script + 2), "( ( " + ParseGetVariable(GetU8(script + 1) >> 4, GetU8(script + 2)) + " + " + ParseGetVariable(GetU8(script + 1) & 0x0F, GetU8(script + 3)) + " > 255 ) ? 255 : " + ParseGetVariable(GetU8(script + 1) >> 4, GetU8(script + 2)) + " + " + ParseGetVariable(GetU8(script + 1) & 0x0F, GetU8(script + 3)) + " )")
                        );
                    AdvanceScript(4, script, end);
                } break;

                case PLUS2_:
                {
                    export_script->Log(
                        SetVariable(GetU8(script + 1) >> 4, GetU8(script + 2), "( ( " + ParseGetVariable(GetU8(script + 1) >> 4, GetU8(script + 2)) + " + " + ParseGetVariable(GetU8(script + 1) & 0x0F, GetU16LE(script + 3)) + " > 65535 ) ? 65535 : " + ParseGetVariable(GetU8(script + 1) >> 4, GetU8(script + 2)) + " + " + ParseGetVariable(GetU8(script + 1) & 0x0F, GetU16LE(script + 3)) + " )")
                        );
                    AdvanceScript(5, script, end);
                } break;

                case MINUS_:
                {
                    export_script->Log(
                        SetVariable(GetU8(script + 1) >> 4, GetU8(script + 2), "( ( " + ParseGetVariable(GetU8(script + 1) >> 4, GetU8(script + 2)) + " - " + ParseGetVariable(GetU8(script + 1) & 0x0F, GetU8(script + 3)) + " < 0 ) ? 0 : " + ParseGetVariable(GetU8(script + 1) >> 4, GetU8(script + 2)) + " - " + ParseGetVariable(GetU8(script + 1) & 0x0F, GetU8(script + 3)) + " )")
                        );
                    AdvanceScript(4, script, end);
                } break;

                case MINUS2_:
                {
                    export_script->Log(SetVariable(GetU8(script + 1) >> 4, GetU8(script + 2), "( ( " + ParseGetVariable(GetU8(script + 1) >> 4, GetU8(script + 2)) + " - " + ParseGetVariable(GetU8(script + 1) & 0x0F, GetU16LE(script + 3)) + " < 0 ) ? 0 : " + ParseGetVariable(GetU8(script + 1) >> 4, GetU8(script + 2)) + " - " + ParseGetVariable(GetU8(script + 1) & 0x0F, GetU16LE(script + 3)) + " )"));
                    AdvanceScript(5, script, end);
                } break;

                case INC_:
                {
                    export_script->Log(SetVariable(GetU8(script + 1), GetU8(script + 2), "( ( " + ParseGetVariable(GetU8(script + 1), GetU8(script + 2)) + " + 1 > 255 ) ? 255 : " + ParseGetVariable(GetU8(script + 1), GetU8(script + 2)) + " + 1 )"));
                    AdvanceScript(3, script, end);
                } break;

                case TALKON:
                {
                    export_script->Log(
                        entity_list[i] +
                        ":set_talkable( " +
                        BoolToString(!(GetU8(script + 1))) +
                        " );\n"
                        );

                    AdvanceScript(2, script, end);
                } break;

                case SETBYTE:
                {
                    export_script->Log(
                        SetVariable(GetU8(script + 1) >> 4, GetU8(script + 2), ParseGetVariable(GetU8(script + 1) & 0x0F, GetU8(script + 3)))
                        );
                    AdvanceScript(4, script, end);
                } break;

                case SETWORD:
                {
                    export_script->Log(SetVariable(GetU8(script + 1) >> 4, GetU8(script + 2), ParseGetVariable(GetU8(script + 1) & 0x0F, GetU16LE(script + 3))));
                    AdvanceScript(5, script, end);
                } break;

                case BITON:
                {
                    export_script->Log(SetBitChange(GetU8(script + 1) >> 4, GetU8(script + 2), GetU8(script + 1) & 0x0F, GetU8(script + 3), true));

                    AdvanceScript(4, script, end);
                } break;

                case BITOFF:
                {
                    export_script->Log(SetBitChange(GetU8(script + 1) >> 4, GetU8(script + 2), GetU8(script + 1) & 0x0F, GetU8(script + 3), false));
                    AdvanceScript(4, script, end);
                } break;

                case PLUS:
                {
                    export_script->Log(
                        SetVariable(GetU8(script + 1) >> 4, GetU8(script + 2), ParseGetVariable(GetU8(script + 1) >> 4, GetU8(script + 2)) + " + " + ParseGetVariable(GetU8(script + 1) & 0x0F, GetU8(script + 3)))
                        );
                    AdvanceScript(4, script, end);
                } break;

                case MINUS:
                {
                    export_script->Log(
                        SetVariable(GetU8(script + 1) >> 4, GetU8(script + 2), ParseGetVariable(GetU8(script + 1) >> 4, GetU8(script + 2)) + " - " + ParseGetVariable(GetU8(script + 1) & 0x0F, GetU8(script + 3)))
                        );
                    AdvanceScript(4, script, end);
                } break;

                case MUL:
                {
                    export_script->Log(
                        SetVariable(GetU8(script + 1) >> 4, GetU8(script + 2), "((" + ParseGetVariable(GetU8(script + 1) >> 4, GetU8(script + 2)) + " * " + ParseGetVariable(GetU8(script + 1) & 0x0F, GetU8(script + 3)) + " > 255) ? 255 : " + ParseGetVariable(GetU8(script + 1) >> 4, GetU8(script + 2)) + " * " + ParseGetVariable(GetU8(script + 1) & 0x0F, GetU8(script + 3)) + ")")
                        );
                    AdvanceScript(4, script, end);
                } break;

                case MOD:
                {
                    export_script->Log(
                        SetVariable(GetU8(script + 1) >> 4, GetU8(script + 2), ParseGetVariable(GetU8(script + 1) >> 4, GetU8(script + 2)) + " % " + ParseGetVariable(GetU8(script + 1) & 0x0F, GetU8(script + 3)))
                        );
                    AdvanceScript(4, script, end);
                } break;

                case AND:
                {
                    export_script->Log(
                        SetVariable(GetU8(script + 1) >> 4, GetU8(script + 2), ParseGetVariable(GetU8(script + 1) >> 4, GetU8(script + 2)) + " & " + ParseGetVariable(GetU8(script + 1) & 0x0F, GetU8(script + 3)))
                        );
                    AdvanceScript(4, script, end);
                } break;

                case AND2:
                {
                    export_script->Log(
                        SetVariable(GetU8(script + 1) >> 4, GetU8(script + 2), ParseGetVariable(GetU8(script + 1) >> 4, GetU8(script + 2)) + " & " + ParseGetVariable(GetU8(script + 1) & 0x0F, GetU16LE(script + 3)))
                        );
                    AdvanceScript(5, script, end);
                } break;

                case OR:
                {
                    export_script->Log(SetVariable(GetU8(script + 1) >> 4, GetU8(script + 2), ParseGetVariable(GetU8(script + 1) >> 4, GetU8(script + 2)) + " | " + ParseGetVariable(GetU8(script + 1) & 0x0F, GetU8(script + 3))));
                    AdvanceScript(4, script, end);
                } break;

                case OR2:
                {
                    export_script->Log(
                        SetVariable(GetU8(script + 1) >> 4, GetU8(script + 2), ParseGetVariable(GetU8(script + 1) >> 4, GetU8(script + 2)) + " | " + ParseGetVariable(GetU8(script + 1) & 0x0F, GetU16LE(script + 3)))
                        );
                    AdvanceScript(5, script, end);
                } break;

                case INC:
                {
                    export_script->Log(
                        SetVariable(GetU8(script + 1), GetU8(script + 2), ParseGetVariable(GetU8(script + 1), GetU8(script + 2)) + " + 1")
                        );
                    AdvanceScript(3, script, end);
                } break;

                case DEC:
                {
                    export_script->Log(
                        SetVariable(GetU8(script + 1), GetU8(script + 2), ParseGetVariable(GetU8(script + 1), GetU8(script + 2)) + " - 1")
                        );
                    AdvanceScript(3, script, end);
                } break;

                case RANDOM:
                {
                    export_script->Log(
                        SetVariable(GetU8(script + 1), GetU8(script + 2), "math.rand()")
                        );
                    AdvanceScript(3, script, end);
                } break;

                case PC:
                {
                    export_script->Log("set_entity_to_character( \"" + entity_list[i] + "\", " + IntToString(GetU8(script + 1)) + " );\n");
                    AdvanceScript(2, script, end);
                } break;

                case opCodeCHAR:
                {
                    export_script->Log("-- assosiate entity with model (CHAR) argument doesn't matter\n");
                    AdvanceScript(2, script, end);
                } break;

                case DFANM:
                {
                    export_script->Log(entity_list[i] + ":set_default_animation( \"" + IntToString(GetU8(script + 1)) + "\" ) -- speed=" + FloatToString(1.0f / GetU8(script + 2)) + "\n");
                    export_script->Log("                 " + entity_list[i] + ":play_animation( \"" + IntToString(GetU8(script + 1)) + "\" )\n");
                    AdvanceScript(3, script, end);
                } break;

                case ANIME1:
                {
                    export_script->Log(entity_list[i] + ":play_animation( \"" + IntToString(GetU8(script + 1)) + "\" ) -- speed=" + FloatToString(1.0f / GetU8(script + 2)) + "\n");
                    export_script->Log("                 " + entity_list[i] + ":animation_sync()\n");
                    AdvanceScript(3, script, end);
                } break;

                case VISI:
                {
                    export_script->Log(entity_list[i] + ":set_visible( " + BoolToString(GetU8(script + 1) > 0) + " )\n");
                    AdvanceScript(2, script, end);
                } break;

                case XYZI:
                {
                    export_script->Log(entity_list[i] + ":set_position( " +
                        
                        ParseGetVariable(GetU8(script + 1) >> 4,   (s16)GetU16LE(script + 3), 0, downscaler) + ", " + 
                        ParseGetVariable(GetU8(script + 1) & 0x0F, (s16)GetU16LE(script + 5), 0, downscaler) + ", " + 
                        ParseGetVariable(GetU8(script + 2) >> 4,   (s16)GetU16LE(script + 7), 0, downscaler) + 
                        " ) -- triangle_id=" + ParseGetVariable(GetU8(script + 2) & 0x0F, (s16)GetU16LE(script + 9)) + "\n");
                    AdvanceScript(11, script, end);
                } break;

                case XYI:
                {
                    export_script->Log(
                        entity_list[i] +
                        ":set_2d_position_triangle( " +
                        ParseGetVariable(GetU8(script + 1) >> 4, (s16)GetU16LE(script + 3), false, downscaler) +
                        ", " +
                        ParseGetVariable(GetU8(script + 1) & 0x0F, (s16)GetU16LE(script + 5), false, downscaler) +
                        ", triangle_id=" +
                        ParseGetVariable(GetU8(script + 2) >> 4, (s16)GetU16LE(script + 7)) +
                        ");\n"
                        );

                    AdvanceScript(9, script, end);
                } break;

                case MOVE:
                {
                    export_script->Log(entity_list[i] + ":move_to_position( " + ParseGetVariable(GetU8(script + 1) >> 4, (s16)GetU16LE(script + 2), false, downscaler) + ", " + ParseGetVariable(GetU8(script + 1) & 0x0F, (s16)GetU16LE(script + 4), false, downscaler) + " )\n");
                    export_script->Log("                 " + entity_list[i] + ":move_sync()\n");
                    AdvanceScript(6, script, end);
                } break;

                case CMOVE:
                {
                    export_script->Log(
                        entity_list[i] +
                        ":set_rotation_lock( true );\n" +
                        entity_list[i] +
                        ":move_to_position( " +
                        ParseGetVariable(GetU8(script + 1) >> 4, (s16)GetU16LE(script + 2), 0, downscaler) +
                        ", " +
                        ParseGetVariable(GetU8(script + 1) & 0x0F, (s16)GetU16LE(script + 4), 0, downscaler) +
                        ", false );\n" +
                        entity_list[i] +
                        ":set_rotation_lock( false );\n"
                        );

                    AdvanceScript(6, script, end);
                } break;

                case MOVA:
                {
                    export_script->Log(
                        entity_list[i] +
                        ":move_to_model( " +
                        entity_list[GetU8(script + 1)] +
                        ", true );\n"
                        );

                    AdvanceScript(2, script, end);
                } break;

                case TURA:
                {
                    u8 type = GetU8(script + 2);

                    export_script->Log(
                        entity_list[i] +
                        ":turn_to_entity( " +
                        entity_list[GetU8(script + 1)] +
                        ", " +
                        ((type == 0) ? "Entity.CLOCKWISE" : ((type == 1) ? "Entity.ANTICLOCKWISE" : "Entity.CLOSEST")) +
                        ", " +
                        FloatToString(GetU8(script + 3) / 30.0f) +
                        ");\n"
                        );

                    AdvanceScript(4, script, end);
                } break;

                case ANIMW:
                {
                    export_script->Log(
                        entity_list[i] +
                        ":set_animation_wait();\n"
                        );

                    AdvanceScript(1, script, end);
                } break;

                case FMOVE:
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
                } break;

                case ANIME2:
                {
                    export_script->Log(
                        entity_list[i] +
                        ":play_animation( \"" +
                        IntToString(GetU8(script + 1)) +
                        "\", 0, -1, " +
                        FloatToString(1.0f / GetU8(script + 2)) +
                        ", false );\n"
                        );

                    AdvanceScript(3, script, end);
                } break;

                case ANIM_1:
                {
                    export_script->Log(entity_list[i] + ":play_animation_stop( \"" + IntToString(GetU8(script + 1)) + "\" ) -- speed=" + FloatToString(1.0f / GetU8(script + 2)) + "\n");
                    AdvanceScript(3, script, end);
                } break;

                case CANM_1:
                {
                    export_script->Log(
                        entity_list[i] +
                        ":play_animation( \"" +
                        IntToString(GetU8(script + 1)) +
                        "\", " +
                        FloatToString(GetU8(script + 2) / 30.0f) +
                        ", " +
                        FloatToString(GetU8(script + 3) / 30.0f) +
                        ", " +
                        FloatToString(1.0f / GetU8(script + 4)) +
                        ", true );\n"
                        );

                    AdvanceScript(5, script, end);
                } break;

                case MSPED:
                {
                    export_script->Log(entity_list[i] + ":set_move_speed( " + ParseGetVariable(GetU8(script + 1), GetU16LE(script + 2), 0, 256.0f * downscaler / (30.0f)) + " )\n");
                    AdvanceScript(4, script, end);
                } break;

                case DIR:
                {
                    export_script->Log(entity_list[i] + ":set_direction( " + ParseGetVariable(GetU8(script + 1), GetU8(script + 2), 0, 256.0f / 360.0f) + " )\n");
                    AdvanceScript(3, script, end);
                } break;

                case TURNGEN:
                {
                    u8 type = GetU8(script + 3);
                    u8 calc = GetU8(script + 5);
                    export_script->Log(entity_list[i] + ":turn_to_direction( " + ParseGetVariable(GetU8(script + 1), GetU8(script + 2), 0, 256.0f / 360.0f) + ", " + ((type == 0) ? "Entity.CLOCKWISE" : ((type == 1) ? "Entity.ANTICLOCKWISE" : "Entity.CLOSEST")) + ", " + ((calc == 1) ? "Entity.LINEAR" : "Entity.SMOOTH") + ", " + FloatToString(GetU8(script + 4) / 30.0f) + " )\n");
                    export_script->Log(entity_list[i] + ":turn_sync()\n");
                    AdvanceScript(6, script, end);
                } break;

                case TURN:
                {
                    u8 calc = GetU8(script + 5);

                    export_script->Log(
                        entity_list[i] +
                        ":turn_to_direction( " +
                        ParseGetVariable(GetU8(script + 1), GetU16LE(script + 2), 0, 256.0f / 360.0f) +
                        ", Entity.CLOCKWISE, " +
                        ((calc == 1) ? "Field.LINEAR" : "Field.SMOOTH") +
                        ", " +
                        FloatToString(GetU8(script + 4) / 30.0f) +
                        " );\n"
                        );
                    export_script->Log(entity_list[i] + ":turn_sync()\n");

                    AdvanceScript(6, script, end);
                } break;

                case DIRA:
                {
                    export_script->Log(entity_list[i] + ":set_direction( \"" + entity_list[GetU8(script + 1)] + "\" )\n");
                    AdvanceScript(2, script, end);
                } break;

                case GETDIR:
                {
                    export_script->Log(
                        SetVariable(GetU8(script + 1), GetU8(script + 3), entity_list[GetU8(script + 2)] + ":get_direction()")
                        );
                    AdvanceScript(4, script, end);
                } break;

                case GETAXY:
                {
                    export_script->Log(
                        SetVariable(GetU8(script + 1) >> 4, GetU8(script + 3), entity_list[GetU8(script + 2)] + ":get_x()") +
                        SetVariable(GetU8(script + 1) & 0x0F, GetU8(script + 4), entity_list[GetU8(script + 2)] + ":get_y()")
                        );
                    AdvanceScript(5, script, end);
                } break;

                case GETAI:
                {
                    export_script->Log(SetVariable(GetU8(script + 1), GetU8(script + 3), entity_list[GetU8(script + 2)] + ":get_move_triangle_id()"));
                    AdvanceScript(4, script, end);
                } break;

                case ANIM_2: // ANIM!2
                {
                    export_script->Log(entity_list[i] + ":play_animation_stop( \"" + IntToString(GetU8(script + 1)) + "\" ) -- speed=" + FloatToString(1.0f / GetU8(script + 2)) + "\n");
                    export_script->Log("                 " + entity_list[i] + ":animation_sync()\n");
                    AdvanceScript(3, script, end);
                } break;

                case CANIM2:
                {
                    export_script->Log(entity_list[i] + ":play_animation( \"" + IntToString(GetU8(script + 1)) + "\", " + FloatToString(GetU8(script + 2) / 30.0f) + ", " + FloatToString(GetU8(script + 3) / 30.0f) + " ) -- speed=" + FloatToString(1.0f / GetU8(script + 4)) + "\n");
                    export_script->Log("                 " + entity_list[i] + ":animation_sync()\n");
                    AdvanceScript(5, script, end);
                } break;

                case CANM_2:
                {
                    export_script->Log(entity_list[i] + ":play_animation_stop( \"" + IntToString(GetU8(script + 1)) + "\", " + FloatToString(GetU8(script + 2) / 30.0f) + ", " + FloatToString(GetU8(script + 3) / 30.0f) + " ) -- speed=" + FloatToString(1.0f / GetU8(script + 4)) + "\n");
                    export_script->Log("                 " + entity_list[i] + ":animation_sync()\n");
                    AdvanceScript(5, script, end);
                } break;

                case ASPED:
                {
                    export_script->Log("-- set speed of entity animation to \"" + ParseGetVariable(GetU8(script + 1), GetU16LE(script + 2), 0, 0x10) + "\"\n");
                    AdvanceScript(4, script, end);
                } break;

                case CC:
                {
                    export_script->Log(
                        "field:set_player_entity( " +
                        entity_list[GetU8(script + 1)] +
                        " );\n"
                        );

                    AdvanceScript(2, script, end);
                } break;

                case JUMP:
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
                        ParseGetVariable(GetU8(script + 2) & 0x0F, GetU16LE(script + 9), 0, 30.0f) +
                        " );\n"
                        );

                    AdvanceScript(11, script, end);
                } break;

                case AXYZI:
                {
                    export_script->Log(
                        SetVariable(GetU8(script + 1) >> 4, GetU8(script + 4), entity_list[GetU8(script + 3)] + ":get_x()") +
                        SetVariable(GetU8(script + 1) & 0x0F, GetU8(script + 5), entity_list[GetU8(script + 3)] + ":get_y()") +
                        SetVariable(GetU8(script + 2) >> 4, GetU8(script + 6), entity_list[GetU8(script + 3)] + ":get_z()") +
                        SetVariable(GetU8(script + 2) & 0x0F, GetU8(script + 7), entity_list[GetU8(script + 3)] + ":get_move_triangle_id()")
                        );
                    AdvanceScript(8, script, end);
                } break;

                case LADER:
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
                        FloatToString((GetU8(script + 13) / 256.0f) * 360.0f) +
                        "\" and animation during climbing is \"" +
                        IntToString(GetU8(script + 12)) +
                        "\" with speed \"" +
                        FloatToString(1.0f / GetU8(script + 14)) +
                        "\"\n"
                        );

                    AdvanceScript(15, script, end);
                } break;

                case OFST:
                {
                    u8 type = GetU8(script + 3);
                    export_script->Log(entity_list[i] + ":offset_to_position( " + ParseGetVariable(GetU8(script + 1) >> 4, (s16)GetU16LE(script + 4), 0, downscaler) + ", " + ParseGetVariable(GetU8(script + 1) & 0x0F, (s16)GetU16LE(script + 6), false, downscaler) + ", " + ParseGetVariable(GetU8(script + 2) >> 4, (s16)GetU16LE(script + 8), false, downscaler) + ", " + ((type == 2) ? "Entity.SMOOTH" : "Entity.LINEAR") + ", " + ParseGetVariable(GetU8(script + 2) & 0x0F, GetU16LE(script + 10), 0, 30.0f) + " )\n");
                    AdvanceScript(12, script, end);
                } break;

                case OFSTW:
                {
                    export_script->Log(entity_list[i] + ":offset_sync()\n");
                    AdvanceScript(1, script, end);
                } break;

                case TALKR:
                {
                    export_script->Log(
                        entity_list[i] +
                        ":set_talk_range( " +
                        ParseGetVariable(GetU8(script + 1), GetU8(script + 2)) +
                        " );\n"
                        );

                    AdvanceScript(3, script, end);
                } break;

                case CLIDR:
                {
                    export_script->Log(
                        entity_list[i] +
                        ":set_solid_range( " +
                        ParseGetVariable(GetU8(script + 1), GetU8(script + 2)) +
                        " );\n"
                        );

                    AdvanceScript(3, script, end);
                } break;

                case SOLID:
                {
                    export_script->Log(entity_list[i] + ":set_solid( " + BoolToString(!(GetU8(script + 1))) + " )\n");
                    AdvanceScript(2, script, end);
                } break;

                case PRTYP:
                {
                    export_script->Log(
                        "game:party_add( " +
                        IntToString(GetU8(script + 1)) +
                        " );\n"
                        );

                    AdvanceScript(2, script, end);
                } break;

                case PRTYM:
                {
                    export_script->Log(
                        "game:party_remove( " +
                        IntToString(GetU8(script + 1)) +
                        " );\n"
                        );

                    AdvanceScript(2, script, end);
                } break;

                case PRTYE:
                {
                    export_script->Log(
                        "game:party_set( " +
                        IntToString(GetU8(script + 1)) +
                        ", " +
                        IntToString(GetU8(script + 2)) +
                        ", " +
                        IntToString(GetU8(script + 3)) +
                        " );\n"
                        );

                    AdvanceScript(4, script, end);
                } break;

                case MMBUD:
                {
                    export_script->Log(
                        "game:character_enable( " +
                        IntToString(GetU8(script + 2)) +
                        ", " +
                        BoolToString(GetU8(script + 1) > 0) +
                        " );\n"
                        );

                    AdvanceScript(3, script, end);
                } break;

                case MMBLK:
                {
                    export_script->Log(
                        "[UNREVERSED] MMBLK(" +
                        ArgumentString(script + 1, 1) +
                        ");\n"
                        );

                    AdvanceScript(2, script, end);
                } break;

                case LINE:
                {
                    export_script->Log(
                        "-- define line point1( " +
                        IntToString(GetU16LE(script + 1)) +
                        ", " +
                        IntToString(GetU16LE(script + 3)) +
                        ", " +
                        IntToString(GetU16LE(script + 5)) +
                        "), point2(" +
                        IntToString(GetU16LE(script + 7)) +
                        ", " +
                        IntToString(GetU16LE(script + 9)) +
                        ", " +
                        IntToString(GetU16LE(script + 11)) +
                        " )\n"
                        );

                    AdvanceScript(13, script, end);
                } break;

                case LINON:
                {
                    export_script->Log(
                        "-- turn line " +
                        Ogre::String((GetU8(script + 1) == 1) ? "on" : "off") +
                        "\n"
                        );

                    AdvanceScript(2, script, end);
                } break;

                case MPJPO:
                {
                    export_script->Log(
                        "field:gateway_enable( " +
                        Ogre::String((GetU8(script + 1) == 1) ? "false" : "true") +
                        " );\n"
                        );

                    AdvanceScript(2, script, end);
                } break;

                case SLINE:
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
                } break;

                case PMJMP:
                {
                    export_script->Log(
                        "[UNREVERSED] PMJMP(" +
                        ArgumentString(script + 1, 2) +
                        ");\n"
                        );

                    AdvanceScript(3, script, end);
                } break;

                case AKAO2:
                {
                    u8 sub_opcode = GetU8(script + 4);

                    Ogre::String sound = "music:execute_akao( " +
                        HexToString(sub_opcode, 2, '0') +
                        ", " +
                        ParseGetVariable(GetU8(script + 1) >> 4, GetU16LE(script + 5), 4) +
                        ", " +
                        ParseGetVariable(GetU8(script + 1) & 0x0F, GetU16LE(script + 7), 4) +
                        ", " +
                        ParseGetVariable(GetU8(script + 2) >> 4, GetU16LE(script + 9), 4) +
                        ", " +
                        ParseGetVariable(GetU8(script + 2) & 0x0F, GetU16LE(script + 11), 4) +
                        ", " +
                        ParseGetVariable(GetU8(script + 3) >> 4, GetU16LE(script + 13), 4) +
                        ", " +
                        ParseGetVariable(GetU8(script + 3) & 0x0F, GetU16LE(script + 15), 4) +
                        " );\n";

                    m_SoundOpcodes.push_back(sound);
                    export_script->Log(sound);

                    AdvanceScript(15, script, end);
                } break;

                case ANIMB:
                {
                    export_script->Log(
                        entity_list[i] +
                        ":animation_stop();\n"
                        );

                    AdvanceScript(1, script, end);
                } break;

                case TURNW:
                {
                    export_script->Log(
                        entity_list[i] +
                        ":set_turn_wait();\n"
                        );

                    AdvanceScript(1, script, end);
                } break;

                case BGON:
                {
                    export_script->Log(
                        "field:background_on( \"" +
                        ParseGetVariable(GetU8(script + 1) >> 4, GetU8(script + 2)) +
                        "\", " +
                        ParseGetVariable(GetU8(script + 1) & 0x0F, GetU8(script + 3)) +
                        " ); -- turns on layer of background animation with given id\n"
                        );
                    AdvanceScript(4, script, end);
                } break;

                case BGOFF:
                {
                    export_script->Log(
                        "field:background_off( \"" +
                        ParseGetVariable(GetU8(script + 1) >> 4, GetU8(script + 2)) +
                        "\", " +
                        ParseGetVariable(GetU8(script + 1) & 0x0F, GetU8(script + 3)) +
                        " ); -- turns off layer of background animation with given id\n"
                        );
                    AdvanceScript(4, script, end);
                } break;

                case BGCLR:
                {
                    export_script->Log(
                        "field:background_clear( \"" +
                        ParseGetVariable(GetU8(script + 1), GetU8(script + 2)) +
                        "\" ); -- turns off all layer of background animation with given id\n"
                        );
                    AdvanceScript(3, script, end);
                } break;

                case STPAL:
                {
                    export_script->Log("-- store palette \"" + ParseGetVariable(GetU8(script + 1) >> 4, GetU8(script + 2)) + "\" to slot \"0x" + ParseGetVariable(GetU8(script + 1) & 0x0f, GetU8(script + 3), 2) + "\" starting from clut_x=\"0x00\" and with width=\"0x" + HexToString(GetU8(script + 4) + 1, 2, '0') + "\"\n");
                    AdvanceScript(5, script, end);
                } break;

                case LDPAL:
                {
                    export_script->Log("-- load palette \"" + ParseGetVariable(GetU8(script + 1) & 0x0f, GetU8(script + 3)) + "\" from slot \"0x" + ParseGetVariable(GetU8(script + 1) >> 4, GetU8(script + 2), 2) + "\" starting from clut_x=\"0x00\" and with width=\"0x" + HexToString(GetU8(script + 4) + 1, 2, '0') + "\"\n");
                    AdvanceScript(5, script, end);
                } break;

                case CPPAL:
                {
                    export_script->Log("-- copy palette stored in slot \"0x" + ParseGetVariable(GetU8(script + 1) >> 4, GetU8(script + 2), 2) + "\" with width=\"0x" + HexToString(GetU8(script + 4) + 1, 2, '0') + " to slot \"0x" + ParseGetVariable(GetU8(script + 1) & 0x0f, GetU8(script + 3), 2) + "\"\n");
                    AdvanceScript(5, script, end);
                } break;

                case ADPAL:
                {
                    export_script->Log("-- add to palette stored in slot \"0x" + ParseGetVariable(GetU8(script + 1) >> 4, GetU8(script + 4), 2) + "\" with width=\"0x" + HexToString(GetU8(script + 9) + 1, 2, '0') + "\" with values R=\"" + ParseGetVariable(GetU8(script + 3) >> 4, GetU8(script + 8)) + "\", G=\"" + ParseGetVariable(GetU8(script + 2) & 0x0f, GetU8(script + 7)) + "\", B=\"" + ParseGetVariable(GetU8(script + 2) >> 4, GetU8(script + 6)) + "\" and store it to slot \"0x" + ParseGetVariable(GetU8(script + 1) & 0x0f, GetU8(script + 5), 2) + "\"\n");
                    AdvanceScript(10, script, end);
                } break;

                case MPPAL2:
                {
                    export_script->Log("-- multiply palette stored in slot \"0x" + ParseGetVariable(GetU8(script + 1) >> 4, GetU8(script + 4), 2) + "\" with width=\"0x" + HexToString(GetU8(script + 9) + 1, 2, '0') + " with values R=\"" + ParseGetVariable(GetU8(script + 3) >> 4, GetU8(script + 8)) + "\", G=\"" + ParseGetVariable(GetU8(script + 2) & 0x0f, GetU8(script + 7)) + "\", B=\"" + ParseGetVariable(GetU8(script + 2) >> 4, GetU8(script + 6)) + "\" (note: 64 - 1.0f, 32 - 0.5f) and store it to slot \"0x" + ParseGetVariable(GetU8(script + 1) & 0x0f, GetU8(script + 5), 2) + "\"\n");
                    AdvanceScript(10, script, end);
                } break;

                case STPLS:
                {
                    export_script->Log("-- store palette \"" + IntToString(GetU8(script + 1)) + "\" to slot \"0x" + HexToString(GetU8(script + 2), 2, '0') + "\" starting from clut_x=\"0x" + HexToString(GetU8(script + 3), 2, '0') + "\" and with width=\"0x" + HexToString(GetU8(script + 4) + 1, 2, '0') + "\"\n");
                    AdvanceScript(5, script, end);
                } break;

                case LDPLS:
                {
                    export_script->Log("-- load palette \"" + IntToString(GetU8(script + 2)) + "\" from slot \"0x" + HexToString(GetU8(script + 1), 2, '0') + "\" starting from clut_x=\"0x" + HexToString(GetU8(script + 3), 2, '0') + "\" and with width=\"0x" + HexToString(GetU8(script + 4) + 1, 2, '0') + "\"\n");
                    AdvanceScript(5, script, end);
                } break;

                case RTPAL2:
                {
                    export_script->Log("[UNREVERSED] RTPAL2( " + ArgumentString(script + 1, 7) + " );\n");
                    AdvanceScript(8, script, end);
                } break;

                case ADPAL2:
                {
                    export_script->Log("[UNREVERSED] ADPAL2( " + ArgumentString(script + 1, 10) + ");\n");
                    AdvanceScript(11, script, end);
                } break;

                case MUSIC:
                {
                    Ogre::String sound = "music:execute_akao( " +
                        HexToString(0x10, 2, '0') +
                        ", pointer_to_field_AKAO_" +
                        IntToString(GetU8(script + 1)) +
                        " ); -- play field music\n";

                    m_SoundOpcodes.push_back(sound);
                    export_script->Log(sound);

                    AdvanceScript(2, script, end);
                } break;

                case SOUND:
                {
                    Ogre::String sound = "music:execute_akao( " +
                        HexToString(0x20, 2, '0') +
                        ", " +
                        ParseGetVariable(GetU8(script + 1) & 0x0F, GetU8(script + 4), true) +
                        ", " +
                        ParseGetVariable(GetU8(script + 1) >> 4, GetU16LE(script + 2), true) +
                        " ); -- play sound\n";

                    m_SoundOpcodes.push_back(sound);
                    export_script->Log(sound);

                    AdvanceScript(5, script, end);
                } break;

                case AKAO:
                {
                    u8 sub_opcode = GetU8(script + 4);

                    Ogre::String sound = "music:execute_akao( " +
                        HexToString(sub_opcode, 2, '0') +
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
                } break;

                case MULCK:
                {
                    export_script->Log(
                        "music:lock( " +
                        BoolToString(GetU8(script + 1) > 0) +
                        " );\n"
                        );

                    AdvanceScript(2, script, end);
                } break;

                case BMUSC:
                {
                    export_script->Log(
                        "[UNREVERSED] BMUSC(" +
                        IntToString(GetU8(script + 1)) +
                        ");\n"
                        );

                    AdvanceScript(2, script, end);
                } break;

                case PMVIE:
                {
                    export_script->Log(
                        "field:movie_set( " +
                        IntToString(GetU8(script + 1)) +
                        " );\n"
                        );

                    AdvanceScript(2, script, end);
                } break;

                case MOVIE:
                {
                    export_script->Log("field:play_movie();\n");
                    AdvanceScript(1, script, end);
                } break;

                case MVIEF:
                {
                    export_script->Log(
                        SetVariable(GetU8(script + 1), GetU8(script + 2), "field:get_movie_frame()")
                        );
                    AdvanceScript(3, script, end);
                } break;

                case MVCAM:
                {
                    export_script->Log(
                        "field:movie_camera_enable( " +
                        BoolToString(!GetU8(script + 1)) +
                        " );\n"
                        );

                    AdvanceScript(2, script, end);
                } break;

                case FMUSC:
                {
                    export_script->Log(
                        "[UNREVERSED] FMUSC(" +
                        ArgumentString(script + 1, 1) +
                        ");\n"
                        );

                    AdvanceScript(2, script, end);
                } break;

                case CHMST:
                {
                    export_script->Log(
                        SetVariable(GetU8(script + 1), GetU8(script + 2), "field:is_music_playing()")
                        );
                    AdvanceScript(3, script, end);
                } break;

                default:
                {
                    export_script->Log("[OPCODE " + HexToString(opcode, 2, '0') + "]\n");
                    script += 1;
                } break;
                } // end switch
            }

            export_script->Log("\n");
        }
    }
    delete export_script;
}



void
DatFile::DumpSoundOpcodesData( const Ogre::String& export_file )
{
    std::sort( m_SoundOpcodes.begin(), m_SoundOpcodes.end() );
    m_SoundOpcodes.erase(std::unique(m_SoundOpcodes.begin(), m_SoundOpcodes.end()), m_SoundOpcodes.end());

    Logger* export_sound = new Logger(export_file);

    for (unsigned int i = 0; i < m_SoundOpcodes.size(); ++i)
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

// A map of slots to values to value names, for example slot 1 value 3 = "love_point_aeris"
std::map<int, std::map<int, Ogre::String>> VariableNamesMap 
{
    // Slot 1
    { 1, { { 3, "love_point_aeris" },
    { 4, "love_point_tifa" },
    { 5, "love_point_yuffie" },
    { 6, "love_point_barret" },
    { 21, "timer_minutes" },
    { 22, "timer_seconds" },
    { 23, "timer_frames" },
    { 36, "graveyard_item" },
    { 48, "item_mask2" },
    { 80, "battle_love_aeris" },
    { 81, "battle_love_tifa" },
    { 82, "battle_love_yuffie" },
    { 83, "battle_love_barret" },
    { 164, "graveyard_train" },
    { 225, "act1_1_flags1" },
    { 226, "act1_1_flags2" } }
    },
    // Slot 2
    { 2, { { 0, "progress_game" },
    { 28, "menu_appear" },
    { 30, "menu_selectable" }
    } },
    // Slot 3
    { 3, { { 66, "act1_1_flags3" },
    { 111, "flower_flag" },
    { 112, "act1_3_flags5" },
    { 126, "act1_3_unknown" },
    { 127, "tunnel_room" },
    { 128, "act1_3_flags1" },
    { 129, "act1_3_flags2" },
    { 130, "act1_3_flags3" },
    { 131, "act1_3_flags4" },
    { 208, "act1_2_flags1" },
    { 209, "act1_2_flags2" },
    { 210, "act1_2_flags3" },
    { 211, "act1_2_flags4" },
    { 212, "act1_2_flags5" },
    { 213, "act1_2_flags6" },
    { 214, "act1_2_flags7" },
    { 215, "act1_2_flags8" },
    { 216, "act1_2_flags9" },
    { 217, "act1_7_flags1" },
    { 223, "act1_1_flags4" },
    } },
    // Slot 13
    { 13, { { 30, "pointer" },
    { 31, "materia_full" },
    { 91, "save_flag" }
    } },
    // Slot 15
    { 15, { { 32, "sector1_item" },
    { 33, "sector5_item" },
    { 80, "subway_item" }
    } }
};

Ogre::String
DatFile::ParseVariableName(int slot, int value)
{
    auto slotMap = VariableNamesMap.find(slot);
    if (slotMap != std::end(VariableNamesMap))
    {
        auto valueStr = slotMap->second.find(value);
        if (valueStr != std::end(slotMap->second))
        {
            return valueStr->second;
        }
    }
    LOGGER->Log("\n[WARNING] ParseVariableName " + IntToString(value) + " for slot " + IntToString(slot) + " not implemented.\n");
    return "";
}

Ogre::String
DatFile::ParseGetVariable( int get_slot, int get_value, unsigned int hex, float fixed )
{
    if( get_slot == 0 )
    {
        if( hex > 0 )
        {
            return HexToString( get_value, hex, '0' );
        }
        else
        {
            return FloatToString( get_value / fixed );
        }
    }
    else if( get_slot == 1 || get_slot == 2 || get_slot == 3 || get_slot == 13 || get_slot == 15 )
    {
        return "game:variable_get( \"" + ParseVariableName( get_slot, get_value ) + "\" )";
    }
    else if( get_slot == 5 )
    {
        return "temp5_" + HexToString( get_value, 2, '0' );
    }
    else if( get_slot == 6 )
    {
        return "temp6_" + HexToString( get_value, 2, '0' );
    }

    LOGGER->Log( "\n[WARNING] ParseGetVariable " + IntToString( get_value ) + " for slot " + IntToString( get_slot ) + " not implemented.\n" );

    return "";
}



Ogre::String
DatFile::SetVariable( int set_slot, int set_value, Ogre::String get_string )
{
    if (set_slot == 1 || set_slot == 2 || set_slot == 3 || set_slot == 13 || set_slot == 15)
    {
        return "game:variable_set(\"" + ParseVariableName(set_slot, set_value) + "\", " + get_string + ");\n";
    }
    else if (set_slot == 5)
    {
        return "temp5_" + HexToString( set_value, 2, '0' ) + " = " + get_string + ";\n";
    }
    else if (set_slot == 6)
    {
        return "temp6_" + HexToString( set_value, 2, '0' ) + " = " + get_string + ";\n";
    }

    LOGGER->Log("\n[WARNING] SetVariable " + IntToString(set_value) + " for slot " + IntToString(set_slot) + " not implemented.\n");

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

    LOGGER->Log("\n[WARNING] SetBitChange " + IntToString(set_value) + " for slot " + IntToString(set_slot) + " not implemented.\n");

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
        ret += HexToString(GetU8(script + i), 2, '0');
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
    return HexToString(val, 4, '0');
}



void
DatFile::GetCamera( Ogre::Vector3& position, Ogre::Quaternion& orientation, Ogre::Degree& fov, const Field& field )
{
    float downscaler = 128.0f * field.scale;

    // sector 4
    u32 offset_to_camera = 0x1c + GetU32LE( 0x0c ) - GetU32LE( 0x00 );
    LOGGER->Log( "offset_to_camera = " + HexToString( offset_to_camera, 8, '0' ) + "\n" );

    // get camera matrix (3 vectors)
    Ogre::Matrix3 matrix;
    matrix[ 0 ][ 0 ] = ( s16 )GetU16LE( offset_to_camera + 0x00 ) / 4096.0f;
    matrix[ 1 ][ 0 ] = ( s16 )GetU16LE( offset_to_camera + 0x02 ) / 4096.0f;
    matrix[ 2 ][ 0 ] = ( s16 )GetU16LE( offset_to_camera + 0x04 ) / 4096.0f;
    matrix[ 0 ][ 1 ] = ( s16 )GetU16LE( offset_to_camera + 0x06 ) / 4096.0f;
    matrix[ 1 ][ 1 ] = ( s16 )GetU16LE( offset_to_camera + 0x08 ) / 4096.0f;
    matrix[ 2 ][ 1 ] = ( s16 )GetU16LE( offset_to_camera + 0x0a ) / 4096.0f;
    matrix[ 0 ][ 2 ] = ( s16 )GetU16LE( offset_to_camera + 0x0c ) / 4096.0f;
    matrix[ 1 ][ 2 ] = ( s16 )GetU16LE( offset_to_camera + 0x0e ) / 4096.0f;
    matrix[ 2 ][ 2 ] = ( s16 )GetU16LE( offset_to_camera + 0x12 ) / 4096.0f;
    // get camera position in camera space
    position.x  = -( s32 )GetU32LE( offset_to_camera + 0x14 ) / downscaler;
    position.y  = -( s32 )GetU32LE( offset_to_camera + 0x18 ) / downscaler;
    position.z  = -( s32 )GetU32LE( offset_to_camera + 0x1c ) / downscaler;

    orientation.FromRotationMatrix( matrix );
    position = orientation * position;
    matrix[ 0 ][ 0 ] = matrix[ 0 ][ 0 ];
    matrix[ 1 ][ 0 ] = matrix[ 1 ][ 0 ];
    matrix[ 2 ][ 0 ] = matrix[ 2 ][ 0 ];
    matrix[ 0 ][ 1 ] = -matrix[ 0 ][ 1 ];
    matrix[ 1 ][ 1 ] = -matrix[ 1 ][ 1 ];
    matrix[ 2 ][ 1 ] = -matrix[ 2 ][ 1 ];
    matrix[ 0 ][ 2 ] = -matrix[ 0 ][ 2 ];
    matrix[ 1 ][ 2 ] = -matrix[ 1 ][ 2 ];
    matrix[ 2 ][ 2 ] = -matrix[ 2 ][ 2 ];
    orientation.FromRotationMatrix( matrix );

    float focal_length = GetU16LE( offset_to_camera + 0x24 );
    fov = Ogre::Degree( Ogre::Radian( 2 * atanf( 240.0f / ( 2.0f * focal_length ) ) ) );

    LOGGER->Log( "Field camera matrix : " + Ogre::StringConverter::toString( matrix ) + "\n" );
    LOGGER->Log( "Camera position     : " + Ogre::StringConverter::toString( position ) + "\n" );
    LOGGER->Log( "Camera focal_length : " + FloatToString( focal_length ) + "\n");
    LOGGER->Log( "Unknown (depth que?): DQB = " + HexToString( GetU32LE( offset_to_camera + 0x20 ), 8, '0' ) + ", DQA = " + HexToString( GetU16LE( offset_to_camera + 0x26 ), 4, '0' ) + "\n" );
}



void
DatFile::GetScreenRange( int& min_x, int& min_y, int& max_x, int& max_y )
{
    // sector 5
    u32 offset_to_triggers = 0x1c + GetU32LE( 0x10 ) - GetU32LE( 0x00 );

    min_x = ( s16 )GetU16LE( offset_to_triggers + 0x0c ) * 3;
    min_y = ( s16 )GetU16LE( offset_to_triggers + 0x0e ) * 3;
    max_x = ( s16 )GetU16LE( offset_to_triggers + 0x10 ) * 3;
    max_y = ( s16 )GetU16LE( offset_to_triggers + 0x12 ) * 3;

    //LOGGER->Log(LOGGER_INFO, "Screen range: x: max = %d", max_x);
    //LOGGER->Log(LOGGER_INFO, "                 min = %d", min_x);
    //LOGGER->Log(LOGGER_INFO, "              y: max = %d", max_y);
    //LOGGER->Log(LOGGER_INFO, "                 min = %d", min_y);
    //LOGGER->Log(LOGGER_INFO, "Leftover info %02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x %08x %08x %08x %08x %08x %08x", GetU8(offset_to_triggers + 0x14), GetU8(offset_to_triggers + 0x15), GetU8(offset_to_triggers + 0x16), GetU8(offset_to_triggers + 0x17), GetU8(offset_to_triggers + 0x18), GetU8(offset_to_triggers + 0x19), GetU8(offset_to_triggers + 0x1A), GetU8(offset_to_triggers + 0x1B), GetU8(offset_to_triggers + 0x1C), GetU8(offset_to_triggers + 0x1D), GetU8(offset_to_triggers + 0x1E), GetU8(offset_to_triggers + 0x1F), GetU32LE(offset_to_triggers + 0x20), GetU32LE(offset_to_triggers + 0x24), GetU32LE(offset_to_triggers + 0x28), GetU32LE(offset_to_triggers + 0x2C), GetU32LE(offset_to_triggers + 0x30), GetU32LE(offset_to_triggers + 0x34));
}



void
DatFile::DumpBackground( const Ogre::String& export_path, const Field& field, MimFile& mim )
{
    Logger* export_text = new Logger( export_path + "maps/ffvii_field/" + field.name + "_bg.xml" );

    int width = field.tex_width;
    int height = field.tex_height;

    // set camera for depth calculation
    Ogre::Vector3 position = Ogre::Vector3::ZERO;
    Ogre::Quaternion orientation = Ogre::Quaternion::IDENTITY;
    Ogre::Degree fov = Ogre::Degree( 90 );
    GetCamera( position, orientation, fov, field );

    int min_x, min_y, max_x, max_y;
    GetScreenRange( min_x, min_y, max_x, max_y );

    export_text->Log( "<background2d" );
    export_text->Log( " image=\"maps/ffvii/field/" + field.name + ".png\"" );
    export_text->Log( " position=\"" + Ogre::StringConverter::toString( position ) + "\"" );
    export_text->Log( " orientation=\"" + Ogre::StringConverter::toString( orientation ) + "\"" );
    export_text->Log( " fov=\"" + Ogre::StringConverter::toString( fov ) + "\"" );
    export_text->Log( " range=\"" + IntToString( min_x ) + " " + IntToString( min_y ) + " " + IntToString( max_x ) + " " + IntToString( max_y ) + "\"" );
    export_text->Log( " clip=\"" + IntToString( 320 * 3 ) + " " + IntToString( 240 * 3 ) + "\"" );
    export_text->Log( ">\n" );

    assert(width != 0);
    assert(height != 0);
    full_image = CreateSurface( width, height );
    x_32 = 0; y_32 = 0; x_16 = 0; y_16 = 0; n_16 = 0;

    // sector 3
    u32 offset_to_background = 0x1c + GetU32LE( 0x08 ) - GetU32LE( 0x00 );
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



    std::vector< Tile > tiles;

    for( ; s1 < offset_to_2; s1 += 0x06 )
    {
        if( GetU16LE(s1) == 0x7ffe )
        {
            g_page_x   =   GetU16LE( s3 ) & 0x000f;
            g_page_y   = ( GetU16LE( s3 ) & 0x0010 ) >> 0x04;
            g_blending = ( GetU16LE( s3 ) & 0x0060 ) >> 0x05;
            g_bpp      = ( GetU16LE( s3 ) & 0x0180 ) >> 0x07;
            s3 += 0x02;
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
            Tile tile;
            tile.background      = 0;
            tile.dest_x          = GetU16LE( s2 + 0x00 );
            tile.dest_y          = GetU16LE( s2 + 0x02 );
            tile.src_x           = GetU8( s2 + 0x04 );
            tile.src_y           = GetU8( s2 + 0x05 );
            tile.clut_y          = ( GetU16LE( s2 + 0x06 ) & 0xffc0 ) >> 6;
            tile.clut_x          = ( GetU16LE( s2 + 0x06 ) & 0x003f ) << 4;
            tile.bpp             = g_bpp;
            tile.page_x          = u8(g_page_x);
            tile.page_y          = u8(g_page_y);
            tile.depth           = 999;
            tile.blending        = 0;
            tile.animation_id    = 0;
            tile.animation_frame = 0;
            tiles.push_back( tile );
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
            Tile tile;
            tile.background      = 1;
            tile.dest_x          = GetU16LE( s4 + 0x00 );
            tile.dest_y          = GetU16LE( s4 + 0x02 );
            tile.src_x           = u8(GetU16LE( s4 + 0x04 ));
            tile.src_y           = u8(GetU16LE( s4 + 0x05 ));
            tile.clut_y          = ( GetU16LE( s4 + 0x06 ) & 0xffc0 ) >> 6;
            tile.clut_x          = ( GetU16LE( s4 + 0x06 ) & 0x003f ) << 4;
            tile.bpp             = ( GetU16LE( s4 + 0x08 ) & 0x0180 ) >> 0x07;
            tile.page_x          = GetU16LE( s4 + 0x08 ) & 0x000f;
            tile.page_y          = ( GetU16LE( s4 + 0x08 ) & 0x0010 ) >> 0x04;
            tile.depth           = GetU16LE( s4 + 0x0a ) / ( 32.0f * field.scale );
            tile.blending        = ( GetU16LE( s4 + 0x08 ) & 0x60 ) >> 0x05;
            tile.animation_id    = GetU8( s4 + 0x0c ) & 0x0f;
            tile.animation_frame = GetU8( s4 + 0x0d );
            tiles.push_back( tile );
            s4 += 0x0e;
        }
    }


/*
    for( ; s1 < offset_to_2; s1 += 0x06 )
    {
        if( GetU16LE( s1 ) == 0x7ffe )
        {
            g_page_x   =   GetU16LE( s3 ) & 0x000f;
            g_page_y   = ( GetU16LE( s3 ) & 0x0010 ) >> 0x04;
            g_blending = ( GetU16LE( s3 ) & 0x0060 ) >> 0x05;
            g_bpp      = ( GetU16LE( s3 ) & 0x0180 ) >> 0x07;
            s3 += 0x02;
            //LOGGER->Log( "Set global tex page x = " + HexToString( g_page_x, 4, '0' ) +", tex page y = " + HexToString( g_page_y, 4, '0' ) + ", blending = " + HexToString( g_blending, 2, '0' ) + ", bpp = " + HexToString( g_bpp, 2, '0' ) + "\n" );
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
            Tile tile;
            tile.background = 2;
            tile.dest_x     = GetU16LE( s5 + 0x00 );
            tile.dest_y     = GetU16LE( s5 + 0x02 );
            tile.src_x      = GetU8( s5 + 0x04 );
            tile.src_y      = GetU8( s5 + 0x05 );
            tile.clut_y     = ( GetU16LE( s5 + 0x06 ) & 0xffc0 ) >> 6;
            tile.clut_x     = ( GetU16LE( s5 + 0x06 ) & 0x003f ) << 4;
            tile.bpp        = g_bpp;
            tile.page_x     = g_page_x;
            tile.page_y     = g_page_y;
            tile.depth      = 0;
            tile.blending   = g_blending;
            tile.animation  = GetU8( s5 + 0x08 ) & 0x0f;
            tile.animation_index = GetU8( s5 + 0x09 );
            tiles.push_back( tile );

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
            //LOGGER->Log( "Set global tex page x = " + ToHexString( g_page_x, 4, '0' ) +", tex page y = " + ToHexString( g_page_y, 4, '0' ) + ", blending = " + ToHexString( g_blending, 2, '0' ) + ", bpp = " + ToHexString( g_bpp, 2, '0' ) + "\n" );
            s1 += 0x06;
        }
        if( GetU16LE( s1 ) == 0x7fff )
        {
            break;
        }

        u16 sprite_num = GetU16LE( s1 + 0x04 );

        for( u32 i = 0; i < sprite_num; ++i )
        {
            Tile tile;
            tile.background = 3;
            tile.dest_x     = GetU16LE( s5 + 0x00 );
            tile.dest_y     = GetU16LE( s5 + 0x02 );
            tile.src_x      = GetU8( s5 + 0x04 );
            tile.src_y      = GetU8( s5 + 0x05 );
            tile.clut_y     = ( GetU16LE( s5 + 0x06 ) & 0xffc0 ) >> 6;
            tile.clut_x     = ( GetU16LE( s5 + 0x06 ) & 0x003f ) << 4;
            tile.bpp        = g_bpp;
            tile.page_x     = g_page_x;
            tile.page_y     = g_page_y;
            tile.depth      = 0;
            tile.blending   = g_blending;
            tile.animation  = GetU8( s5 + 0x08 ) & 0x0f;
            tile.animation_index = GetU8( s5 + 0x09 );
            tiles.push_back( tile );

            s5 += 0x0a;
        }
    }
*/



    // unify animations
    std::vector< Tile > temp_tiles;



    for( unsigned int i = 0; i < field.animations.size(); ++i )
    {
        LOGGER->Log( "Start add animation \"" + field.animations[ i ].name + "\".\n" );

        for( unsigned int j = 0; j < field.animations[ i ].keyframes.size(); ++j )
        {
            if( field.animations[ i ].keyframes[ j ].blank != true )
            {
                LOGGER->Log( "Start add not blank keyframe at time \"" + FloatToString( field.animations[ i ].keyframes[ j ].time ) + "\".\n" );

                for( unsigned int k = 0; k < tiles.size(); ++k )
                {
                    if( TileCompare( tiles[ k ], field.animations[ i ].keyframes[ j ], mim ) == true )
                    {
                        tiles[ k ].animated = true;

                        Tile tile;

                        unsigned int l = 0;
                        for( ; l < temp_tiles.size(); ++l )
                        {
                            if(   tiles[ k ].dest_x == temp_tiles[ l ].dest_x &&
                                  tiles[ k ].dest_y == temp_tiles[ l ].dest_y &&
                                  tiles[ k ].blending == temp_tiles[ l ].blending &&
                                ( tiles[ k ].animation_id == temp_tiles[ l ].animation_id ||
                                  tiles[ k ].depth == temp_tiles[ l ].depth ) )
                            {
                                LOGGER->Log( "Temp_tile found use existed one.\n" );
                                tile = temp_tiles[ l ];
                                break;
                            }
                        }

                        if( l == temp_tiles.size() )
                        {
                            LOGGER->Log( "Temp_tile not found add new one.\n" );
                            tile = tiles[ k ];
                        }

                        LOGGER->Log( "Search for existed animation in temp_tiles.\n" );
                        unsigned int m = 0;
                        for( ; m < tile.animations.size(); ++m )
                        {
                            if( tile.animations[ m ].name == field.animations[ i ].name )
                            {
                                LOGGER->Log( "Animation found.\n" );
                                break;
                            }
                        }

                        if( m == tile.animations.size() )
                        {
                            LOGGER->Log( "Animation not found add new one.\n" );
                            Animation animation;
                            animation.name = field.animations[ i ].name;
                            animation.time = field.animations[ i ].time;
                            tile.animations.push_back( animation );
                        }

                        KeyFrame frame;
                        frame.time       = field.animations[ i ].keyframes[ j ].time;
                        frame.src_x      = tiles[ k ].src_x;
                        frame.src_y      = tiles[ k ].src_y;
                        frame.clut_x     = tiles[ k ].clut_x;
                        frame.clut_y     = tiles[ k ].clut_y;
                        frame.bpp        = tiles[ k ].bpp;
                        frame.page_x     = tiles[ k ].page_x;
                        frame.page_y     = tiles[ k ].page_y;
                        frame.clut_start = field.animations[ i ].keyframes[ j ].clut_start;
                        frame.clut_width = field.animations[ i ].keyframes[ j ].clut_width;
                        frame.mod_type   = field.animations[ i ].keyframes[ j ].mod_type;
                        frame.mod_r      = field.animations[ i ].keyframes[ j ].mod_r;
                        frame.mod_g      = field.animations[ i ].keyframes[ j ].mod_g;
                        frame.mod_b      = field.animations[ i ].keyframes[ j ].mod_b;


                        tile.animations[ m ].keyframes.push_back( frame );
                        LOGGER->Log( "Keyframe at time \"" + FloatToString( field.animations[ i ].keyframes[ j ].time ) + "\" added.\n" );

                        if( l == temp_tiles.size() )
                        {
                            temp_tiles.push_back( tile );
                        }
                        else
                        {
                            temp_tiles[ l ] = tile;
                        }
                    }
                }
            }
            else
            {
                LOGGER->Log( "Start add blank keyframe at time \"" + FloatToString( field.animations[ i ].keyframes[ j ].time ) + "\".\n" );

                for( unsigned int k = 0; k < tiles.size(); ++k )
                {
                    if( tiles[ k ].animation_id == field.animations[ i ].keyframes[ j ].animation_id && tiles[ k ].animation_frame == 1 )
                    {
                        Tile tile;

                        unsigned int l = 0;
                        for( ; l < temp_tiles.size(); ++l )
                        {
                            if(   tiles[ k ].dest_x == temp_tiles[ l ].dest_x &&
                                  tiles[ k ].dest_y == temp_tiles[ l ].dest_y &&
                                  tiles[ k ].blending == temp_tiles[ l ].blending &&
                                ( tiles[ k ].animation_id == temp_tiles[ l ].animation_id ||
                                  tiles[ k ].depth == temp_tiles[ l ].depth ) )
                            {
                                LOGGER->Log( "Temp_tile found use existed one.\n" );
                                tile = temp_tiles[ l ];
                                break;
                            }
                        }

                        if( l == temp_tiles.size() )
                        {
                            LOGGER->Log( "Temp_tile not found add new one.\n" );
                            tile = tiles[ k ];
                        }

                        LOGGER->Log( "Search for existed animation in temp_tiles.\n" );
                        unsigned int m = 0;
                        for( ; m < tile.animations.size(); ++m )
                        {
                            if( tile.animations[ m ].name == field.animations[ i ].name )
                            {
                                LOGGER->Log( "Animation found.\n" );
                                break;
                            }
                        }

                        if( m == tile.animations.size() )
                        {
                            LOGGER->Log( "Animation not found add new one.\n" );
                            Animation animation;
                            animation.name = field.animations[ i ].name;
                            animation.time = field.animations[ i ].time;
                            tile.animations.push_back( animation );
                        }

                        KeyFrame frame;
                        frame.time       = field.animations[ i ].keyframes[ j ].time;
                        frame.src_x      = 0;
                        frame.src_y      = 0;
                        frame.clut_x     = 0;
                        frame.clut_y     = 0;
                        frame.bpp        = 0;
                        frame.page_x     = 0;
                        frame.page_y     = 0;
                        frame.mod_type   = "";
                        tile.animations[ m ].keyframes.push_back( frame );
                        LOGGER->Log( "Keyframe at time \"" + FloatToString( field.animations[ i ].keyframes[ j ].time ) + "\" added.\n" );

                        if( l == temp_tiles.size() )
                        {
                            temp_tiles.push_back( tile );
                        }
                        else
                        {
                            temp_tiles[ l ] = tile;
                        }
                    }
                }
            }
        }
    }



    for( unsigned int i = 0; i < tiles.size(); ++i )
    {
        if( tiles[ i ].animated != true )
        {
             temp_tiles.push_back( tiles[ i ] );
        }
    }



    LOGGER->Log( "Start sorting all tiles.\n" );
    for( unsigned int i = 0; i < temp_tiles.size(); ++i )
    {
        for (unsigned int l = 0; l < temp_tiles[i].animations.size(); ++l)
        {
            std::sort( temp_tiles[ i ].animations[ l ].keyframes.begin(), temp_tiles[ i ].animations[ l ].keyframes.end(), anim_time_sort() );
        }
        std::sort( temp_tiles[ i ].animations.begin(), temp_tiles[ i ].animations.end(), anim_name_sort() );
    }
    LOGGER->Log( "Finish sorting all tiles.\n" );



    tiles = temp_tiles;



    LOGGER->Log( "Start add tiles to file.\n" );
    for( unsigned int i = 0; i < tiles.size(); ++i )
    {
        AddTile( tiles[ i ], mim, export_text );
    }
    LOGGER->Log( "Finish add tiles to file.\n" );



    Ogre::TexturePtr ptex;
    Ogre::HardwarePixelBufferSharedPtr buffer;
    ptex = Ogre::TextureManager::getSingleton().createManual( "DynaTex", "General", Ogre::TEX_TYPE_2D, width, height, 0, Ogre::PF_R8G8B8A8, Ogre::TU_STATIC );
    buffer = ptex->getBuffer( 0, 0 );
    buffer->lock( Ogre::HardwareBuffer::HBL_DISCARD );
    const Ogre::PixelBox& pb = buffer->getCurrentLock();

    for( s32 y = 0; y < height; ++y )
    {
        u32* data = static_cast< u32* >( pb.data ) + y * pb.rowPitch;

        for( s32 x = 0; x < width; ++x )
        {
            u32 clut = full_image->pixels[ y * width * 4 + x * 4 + 3 ]
                   | ( full_image->pixels[ y * width * 4 + x * 4 + 2 ] << 8 )
                   | ( full_image->pixels[ y * width * 4 + x * 4 + 1 ] << 16 )
                   | ( full_image->pixels[ y * width * 4 + x * 4 + 0 ] << 24 );
            data[ x ] = clut;
        }
    }

    Ogre::Image image;
    image.loadDynamicImage( ( Ogre::uchar* )pb.data, width, height, Ogre::PF_R8G8B8A8 );
    image.save( export_path + "maps/ffvii_field/" + field.name + ".png" );
    buffer->unlock();
    Ogre::TextureManager::getSingleton().remove( "DynaTex" );

    export_text->Log( "</background2d>" );
    delete export_text;
}



bool
DatFile::TileCompare( const Tile& tile, const FieldKeyFrame& keyframe, MimFile& mim )
{
    bool ret = true;

    // compare animations
    if( keyframe.animation_id != tile.animation_id )
    {
        ret = false;
    }
    else if( keyframe.animation_id != 0 )
    {
        if( ( 1 << keyframe.animation_frame ) != tile.animation_frame )
        {
            ret = false;
        }
    }

    // compare palette
    if( keyframe.clut_y != -1 )
    {
        if( keyframe.clut_y != tile.clut_y )
        {
            ret = false;
        }
/*
        else
        {
            // set size depending on background
            u8 size = ( tile.background > 1 ) ? 32 : 16;
            if( mim.ClutCheck( tile.page_x, tile.page_y, tile.clut_x, tile.bpp, tile.src_x, tile.src_y, size, size, keyframe.clut_x, keyframe.clut_width ) == false )
            {
                ret = false;
            }
        }
*/
    }

    return ret;
}



void
DatFile::AddTile( const Tile& tile, MimFile& mim, Logger* export_text )
{
    AddedTile added_main_tile = AddTileTex( tile.background, tile.src_x, tile.src_y, tile.clut_x, tile.clut_y, tile.bpp, tile.page_x, tile.page_y, mim, 0, 0, "", 1, 1, 1 );

    Ogre::String blending_str = "";
    if( tile.blending == 0 )
    {
        blending_str = "alpha";
    }
    else if( tile.blending == 1 || tile.blending == 3 ) // 3 is source + 0.25 * destination
    {
        blending_str = "add";
    }
    else if( tile.blending == 2 )
    {
        blending_str = "subtract";
    }
    else
    {
        LOGGER->Log( "Tile blending with type \"" + Ogre::StringConverter::toString( tile.blending ) + "\" not supported." );
    }

    export_text->Log(
                        "    <tile destination=\"" +
                        Ogre::StringConverter::toString( tile.dest_x * 3 ) +
                        " " +
                        Ogre::StringConverter::toString( tile.dest_y * 3 ) +
                        "\" width=\"" +
                        Ogre::StringConverter::toString( added_main_tile.width * 3 ) +
                        "\" height=\"" +
                        Ogre::StringConverter::toString( added_main_tile.height * 3 ) +
                        "\" uv=\"" +
                        Ogre::StringConverter::toString( added_main_tile.x / ( float ) full_image->width ) +
                        " " +
                        Ogre::StringConverter::toString( added_main_tile.y / ( float ) full_image->height ) +
                        " " +
                        Ogre::StringConverter::toString( ( added_main_tile.x + added_main_tile.width ) / ( float ) full_image->width ) +
                        " " +
                        Ogre::StringConverter::toString( ( added_main_tile.y + added_main_tile.height ) / ( float ) full_image->height ) +
                        "\" depth=\"" +
                        Ogre::StringConverter::toString( ( tile.depth > 0.002f ) ? tile.depth : 0.002f ) +
                        "\" blending=\"" + blending_str + "\""
    );

    if( tile.animations.size() == 0 )
    {
        export_text->Log( " />\n" );
    }
    else
    {
        export_text->Log( ">\n" );

        for( unsigned int l = 0; l < tile.animations.size(); ++l )
        {
            export_text->Log( "        <animation name=\"" + tile.animations[ l ].name + "\" length=\"" + Ogre::StringConverter::toString( tile.animations[ l ].time ) + "\" >" );

            for( unsigned int i = 0; i < tile.animations[ l ].keyframes.size(); ++i )
            {
                export_text->Log( "<keyframe" );
                export_text->Log( " time=\"" + Ogre::StringConverter::toString( tile.animations[ l ].keyframes[ i ].time ) + "\"" );

                //LOGGER->Log( "Animation tile pixels src_x=\"" + IntToString( tile.animation_key.keyframes[ i ].src_x ) + "\" src_y=\"" + IntToString( tile.animation_key.keyframes[ i ].src_y ) + "\"\n" );
                AddedTile added_tile = AddTileTex( tile.background, tile.animations[ l ].keyframes[ i ].src_x, tile.animations[ l ].keyframes[ i ].src_y, tile.animations[ l ].keyframes[ i ].clut_x, tile.animations[ l ].keyframes[ i ].clut_y, tile.animations[ l ].keyframes[ i ].bpp, tile.animations[ l ].keyframes[ i ].page_x, tile.animations[ l ].keyframes[ i ].page_y, mim, tile.animations[ l ].keyframes[ i ].clut_start, tile.animations[ l ].keyframes[ i ].clut_width, tile.animations[ l ].keyframes[ i ].mod_type, tile.animations[ l ].keyframes[ i ].mod_r, tile.animations[ l ].keyframes[ i ].mod_g, tile.animations[ l ].keyframes[ i ].mod_b );
                //LOGGER->Log( "Animation tile pixels x=\"" + IntToString( x ) + "\" y=\"" + IntToString( y ) + "\"\n" );
                export_text->Log( " uv=\""
                                 +Ogre::StringConverter::toString( added_tile.x / ( float ) full_image->width )
                                 +" "
                                 +Ogre::StringConverter::toString( added_tile.y / ( float ) full_image->height )
                                 +" "
                                 +Ogre::StringConverter::toString( ( added_tile.x + added_tile.width ) / ( float ) full_image->width )
                                 +" "
                                 +Ogre::StringConverter::toString( ( added_tile.y + added_tile.height ) / ( float ) full_image->height )
                                 +"\""
                );
                export_text->Log( "/>" );
            }

            export_text->Log( "</animation>\n" );
        }

        export_text->Log( "    </tile>\n" );
    }
}



AddedTile
DatFile::AddTileTex( const u8 background, const u8 src_x, const u8 src_y, const u16 clut_x, const u16 clut_y, const u8 bpp, const u8 page_x, const u8 page_y, MimFile& mim, const int clut_start, const int clut_width, const Ogre::String& mod_type, const float mod_r, const float mod_g, const float mod_b )
{
    AddedTile tile;
    tile.background = background;
    tile.src_x      = src_x;
    tile.src_y      = src_y;
    tile.clut_x     = clut_x;
    tile.clut_y     = clut_y;
    tile.bpp        = bpp;
    tile.page_x     = page_x;
    tile.page_y     = page_x;
    tile.clut_start = clut_start;
    tile.clut_width = clut_width;
    tile.mod_type   = mod_type;
    tile.mod_r      = mod_r;
    tile.mod_g      = mod_g;
    tile.mod_b      = mod_b;
    std::vector< AddedTile >::iterator tile_it = std::find_if( m_AddedTiles.begin(), m_AddedTiles.end(), added_tile_find( tile ) );

    if( tile_it != m_AddedTiles.end() )
    {
        return *tile_it;
    }



    SurfaceTexData surface;
    surface.page_x     = page_x;
    surface.page_y     = page_y;
    surface.clut_x     = clut_x;
    surface.clut_y     = clut_y;
    surface.bpp        = bpp;
    surface.clut_start = clut_start;
    surface.clut_width = clut_width;
    surface.mod_type   = mod_type;
    surface.mod_r      = mod_r;
    surface.mod_g      = mod_g;
    surface.mod_b      = mod_b;

    std::vector< SurfaceTexData >::iterator it = std::find_if( m_Surfaces.begin(), m_Surfaces.end(), surface_find( surface ) );

    if( it == m_Surfaces.end() )
    {
        surface.surface = mim.GetSurface( page_x, page_y, clut_x, clut_y, bpp, clut_start, clut_width, mod_type, mod_r, mod_g, mod_b );
        m_Surfaces.push_back( surface );
    }
    else
    {
        surface = *it;
    }

    // set size depending on background
    u8 size = ( background > 1 ) ? 32 : 16;

    Surface* sub_image = CreateSubSurface( src_x, src_y, size, size, surface.surface );

    if( sub_image->width == 32 )
    {
        tile.x = float(x_32);
        tile.y = float(y_32);

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

        tile.x = float(x_16);
        tile.y = float(y_16);

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

    CopyToSurface( full_image, int(tile.x), int(tile.y), sub_image );



    tile.width  = size;
    tile.height = size;
    m_AddedTiles.push_back( tile );
    return tile;
}



void
DatFile::DumpWalkmesh( const Ogre::String& export_path, const Field& field )
{
    Logger* export_script = new Logger( export_path + "/maps/ffvii_field/" + field.name + "_wm.xml" );
    export_script->Log( "<walkmesh>\n" );

    // get sector 2 offset (walkmesh)
    u32 offset_to_walkmesh = 0x1C + GetU32LE( 0x04 ) - GetU32LE( 0x00 );
    u32 number_of_poly = GetU32LE( offset_to_walkmesh );

    int start_walkmesh = offset_to_walkmesh + 0x04;
    int start_access   = offset_to_walkmesh + 0x04 + number_of_poly * 0x18;

    float downscaler = 128.0f * field.scale;

    Ogre::Vector3 A, B, C;

    for( u32 i = 0; i < number_of_poly; ++i )
    {
        A.x = ( s16 )GetU16LE( start_walkmesh + 0x00 ) / downscaler;
        A.y = ( s16 )GetU16LE( start_walkmesh + 0x02 ) / downscaler;
        A.z = ( s16 )GetU16LE( start_walkmesh + 0x04 ) / downscaler;

        B.x = ( s16 )GetU16LE( start_walkmesh + 0x08 ) / downscaler;
        B.y = ( s16 )GetU16LE( start_walkmesh + 0x0A ) / downscaler;
        B.z = ( s16 )GetU16LE( start_walkmesh + 0x0C ) / downscaler;

        C.x = ( s16 )GetU16LE( start_walkmesh + 0x10 ) / downscaler;
        C.y = ( s16 )GetU16LE( start_walkmesh + 0x12 ) / downscaler;
        C.z = ( s16 )GetU16LE( start_walkmesh + 0x14 ) / downscaler;

        export_script->Log(
            "    <triangle a=\"" +
            Ogre::StringConverter::toString( A ) +
            "\" b=\"" +
            Ogre::StringConverter::toString( B ) +
            "\" c=\"" +
            Ogre::StringConverter::toString( C ) +
            "\" a_b=\"" +
            IntToString( ( s16 )GetU16LE( start_access + 0x00 ) ) +
            "\" b_c=\"" +
            IntToString( ( s16 )GetU16LE( start_access + 0x02 ) ) +
            "\" c_a=\"" +
            IntToString( ( s16 )GetU16LE( start_access + 0x04 ) ) +
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
DatFile::DumpTriggersMovements( const Ogre::String& export_path, const Field& field )
{
    Logger* export_script = new Logger( export_path + "/maps/ffvii_field/" + field.name + "_triggers.xml" );

    // get sector 5 triggers
    u32 offset_to_triggers = 0x1c + GetU32LE( 0x10 ) - GetU32LE( 0x00 );

    u32 start_triggers = offset_to_triggers + 0x38;

    float downscaler_this = 128.0f * field.scale;

    for( u32 i = 0; i < 12; ++i )
    {
        s16 map_id = GetU16LE( start_triggers + 0x12 );

        // if not inactive gateway
        if( map_id != 32767 )
        {
            float downscaler_next = 128.0f * MapIdToScale( map_id );

            Ogre::Vector3 point1(   ( s16 )GetU16LE( start_triggers + 0x00 ) / downscaler_this,
                                    ( s16 )GetU16LE( start_triggers + 0x02 ) / downscaler_this,
                                    ( s16 )GetU16LE( start_triggers + 0x04 ) / downscaler_this );
            Ogre::Vector3 point2(   ( s16 )GetU16LE( start_triggers + 0x06 ) / downscaler_this,
                                    ( s16 )GetU16LE( start_triggers + 0x08 ) / downscaler_this,
                                    ( s16 )GetU16LE( start_triggers + 0x0a ) / downscaler_this );
            Ogre::Vector3 position( ( s16 )GetU16LE( start_triggers + 0x0c ) / downscaler_next,
                                    ( s16 )GetU16LE( start_triggers + 0x0e ) / downscaler_next,
                                    ( s16 )GetU16LE( start_triggers + 0x10 ) / downscaler_next );
            float direction = 360.0f * GetU8( start_triggers + 0x14 ) / 255.0f;

            export_script->Log( "    <entity_trigger name=\"Gateway" + IntToString( i ) + "\" point1=\"" + Ogre::StringConverter::toString( point1 ) + "\" point2=\"" + Ogre::StringConverter::toString( point2 ) + "\" enabled=\"true\" />\n" );
            export_script->Log( "    <entity_point name=\"Spawn_"+ field.name + "\" position=\"" + Ogre::StringConverter::toString( position ) + "\" rotation=\"" + FloatToString( direction ) + "\" />\n" );
            export_script->Log( "    <!-- map \"" + MapIdToString( map_id ) + "\" -->\n" );
        }

        start_triggers += 0x18;
    }



    // movement rotation
    const u8 movement = GetU8(offset_to_triggers + 0x09);
    const float movementDegree = 180.0f * (static_cast<float>(movement) - 128.0f) / 128.0f;
    export_script->Log( "<movement_rotation degree=\"" + Ogre::StringConverter::toString( movementDegree ) + "\" />\n" );



    delete export_script;
}
