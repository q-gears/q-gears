#ifndef __QGearsBackgroundFile_H__
#define __QGearsBackgroundFile_H__

#include "QGearsPaletteFile.h"

namespace QGears
{
    class BackgroundFile : public File
    {
    public:
        BackgroundFile( const File* pFile, u32 offset, u32 length, const PaletteFile* palette );
        virtual ~BackgroundFile();

        typedef PaletteFile::Color_BGR Color_BGR;

        enum {
            PAGE_DATA_WIDTH  = 0x100
           ,PAGE_DATA_HEIGHT = PAGE_DATA_WIDTH
           ,PAGE_DATA_SIZE   = PAGE_DATA_WIDTH * PAGE_DATA_HEIGHT
           ,SPRITE_WIDTH     = 0x10
           ,SPRITE_HEIGHT    = SPRITE_WIDTH
        };

#if OGRE_COMPILER == OGRE_COMPILER_MSVC
#pragma pack (push, 1)
#else
#pragma pack (1)
#endif
        struct SpriteData
        {
            s16 dst_x;
            s16 dst_y;
            u16 unknown_03;
            u16 unknown_04;
            s16 src_x;
            s16 src_y;
            u16 unknown_07;
            u16 unknown_08;
            u16 unknown_09;
            u16 unknown_0A;

            u16 palette_page;
            u16 unknown_00;
            u8 flags_0A;
            u8 flags_0B;
            u8 flags_0C; // boolean
            u8 flags_0D;
            u16 unknown_0E;
            u16 data_page;
            u16 unknown_0F;
            u16 unknown_38;
            float unknown_u;
            float unknown_v;
            float unknown_w;
            u16 unused_30;
            u16 unused_32;
        };


        struct Page
        {
            u16 unknown_00; // only read further if this is > 0
            u16 unknown_02;
            u16 value_size;
            // u8 i value_size == 1, u16 if value_size == 2
            u8 data[ PAGE_DATA_WIDTH ][ PAGE_DATA_HEIGHT ];
        };

#if OGRE_COMPILER == OGRE_COMPILER_MSVC
#pragma pack (pop)
#else
#pragma pack ()
#endif

    private:
        void read();
        void readSpriteList( u16 layer_index );

        void writeSprites( Color_BGR* image, u16 layer_index );

        const PaletteFile* m_palette;
        u16 m_width;
        u16 m_height;
        u16 m_min_y;

        struct Layer
        {
            bool enabled;
            u16 width;
            u16 height;
            u16 count;
            SpriteData* sprites;
        } m_layers[4];

        u32 m_row_pitch;
        u32 m_raw_data_offset;

        Page* m_pages; // 42 items
    };

}

#endif // __QGearsBackgroundFile_H__
