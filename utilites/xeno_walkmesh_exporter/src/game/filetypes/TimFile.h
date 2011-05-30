// $Id: TimFile.h 103 2006-11-26 07:19:38Z crazy_otaku $

#ifndef TIM_FILE_h
#define TIM_FILE_h

#include "../../common/display/surface/Surface.h"
#include "../../common/utilites/StdString.h"

#include "image/Vram.h"
#include "../filesystem/File.h"



class TimFile : public File
{
public:
    explicit  TimFile(const RString& file);
    explicit  TimFile(File* pFile);
              TimFile(File* pFile, const u32& offset, const u32& length);
              TimFile(u8* pBuffer, const u32& offset, const u32& length);
    virtual  ~TimFile(void);

    Surface*  GetSurface(const u32& clutNumber);

private:
    void      InnerGetImage(void);

private:
    struct TimHeader
    {
        u32 id_tag;           /**< @brief tim id tag */
        u32 id_tag_clut;      /**< @brief tim clut id tag */
        u32 header2_offset;   /**< @brief offset for second header */
        u16 x;                /**< @brief x position of CLUT in VRAM */
        u16 y;                /**< @brief y position of CLUT in VRAM */
        u16 width;            /**< @brief number of colors in CLUT */
        u16 height;           /**< @brief number of CLUT */
    };

    struct TimHeader2
    {
        u32 data_size;        /**< @brief size of image data */
        u16 x;                /**< @brief x position of image in VRAM */
        u16 y;                /**< @brief y position of image in VRAM */
        u16 width;            /**< @brief width of image (width in VRAM) */
        u16 height;           /**< @brief height of image */
    };

    struct ClutColor
    {
        u8 r;                 /**< @brief red color in CLUT */
        u8 g;                 /**< @brief green color in CLUT */
        u8 b;                 /**< @brief blue color in CLUT */
        u8 a;                 /**< @brief alpha in CLUT */
    };

    u32  mIdTag;               /**< @brief tim id tag */
    u32  mIdTagClut;           /**< @brief tim clut id tag */

    u16  mClutVramPositionX;
    u16  mClutVramPositionY;
    u16  mClutWidth;
    u16  mClutHeight;

    u16  mImageVramPositionX;
    u16  mImageVramPositionY;
    u16  mImageWidth;
    u16  mImageHeight;

    Vram mVram;
};



#endif
