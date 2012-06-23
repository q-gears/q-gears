#ifndef MIM_FILE_H
#define MIM_FILE_H

#include "../../common/LzsFile.h"
#include "../../common/Vram.h"



class MimFile : public LzsFile
{
public:
    struct ClutColor
    {
        u8 r;                 /**< @brief red color in CLUT */
        u8 g;                 /**< @brief green color in CLUT */
        u8 b;                 /**< @brief blue color in CLUT */
        u8 a;                 /**< @brief alpha in CLUT */
    };

    MimFile( const Ogre::String& file );
    MimFile( File* pFile );
    MimFile( File* pFile, const u32 offset, const u32 length );
    MimFile( u8* pBuffer, const u32 offset, const u32 length );
    virtual ~MimFile();
    Surface* GetSurface( const u16 page_x, const u16 page_y, const u16 clut_x, const u16 clut_y, const u8 bpp, const int clut_start, const int clut_width, const Ogre::String& mod_type, const float mod_r, const float mod_g, const float mod_b );
    void GetModifiedClut( ClutColor& clut, const Ogre::String& mod_type, const float mod_r, const float mod_g, const float mod_b );
    //bool ClutCheck(const u16 page_x, const u16 page_y, const u16 clut_x, const u8 bpp, const u8 src_x, const u8 src_y, const u8 width, const u8 height, const u16 check_clut_x, const u16 check_clut_width );

private:
    void InnerGetImage();

private:
    struct MimHeader
    {
        u32 header2_offset;   /**< @brief offset for second header */
        u16 x;                /**< @brief x position of CLUT in VRAM */
        u16 y;                /**< @brief y position of CLUT in VRAM */
        u16 width;            /**< @brief number of colors in CLUT */
        u16 height;           /**< @brief number of CLUT */
    };

    struct MimHeader2
    {
        u32 data_size;        /**< @brief size of image data */
        u16 x;                /**< @brief x position of image in VRAM */
        u16 y;                /**< @brief y position of image in VRAM */
        u16 width;            /**< @brief width of image */
        u16 height;           /**< @brief height of image */
    };

    u16  mClutVramPositionX;
    u16  mClutVramPositionY;
    u16  mClutWidth;
    u16  mClutHeight;

    u16  mImageVramPositionX;
    u16  mImageVramPositionY;
    u16  mImageWidth;
    u16  mImageHeight;

    Vram m_Vram;
};



#endif
