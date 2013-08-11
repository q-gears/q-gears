#ifndef __QGearsPaletteFile_H__
#define __QGearsPaletteFile_H__

#include "File.h"

namespace QGears
{
    class PaletteFile : public File
    {
    public:
#if OGRE_COMPILER == OGRE_COMPILER_MSVC
#pragma pack (push, 1)
#else
#pragma pack (1)
#endif
        struct Header
        {
            u32 file_size;
            u16 pal_x;
            u16 pal_y;
            u16 colors_per_page;
            u16 page_count;
        };

        struct Color_BGR
        {
            u8 red;
            u8 green;
            u8 blue;
        };

#if OGRE_COMPILER == OGRE_COMPILER_MSVC
#pragma pack (pop)
#else
#pragma pack ()
#endif

        PaletteFile( const File* pFile, u32 offset, u32 length );
        virtual ~PaletteFile();
        u16* getPage( u16 page_number ) const;

        /// covert 16 bit A1B5G5R5 color to 32 BIT A8B8G8R8
        static Color_BGR convertColor( u16 color );

    private:
        void read();
        void clear();

        Header m_header;
        u16* m_colors;
    };

}

#endif // __QGearsPaletteFile_H__
