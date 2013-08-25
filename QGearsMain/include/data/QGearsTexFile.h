/*
-----------------------------------------------------------------------------
The MIT License (MIT)

Copyright (c) 2013-07-30 Tobias Peters <tobias.peters@kreativeffekt.at>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
-----------------------------------------------------------------------------
*/
#ifndef __QGearsTexFile_H__
#define __QGearsTexFile_H__

#include <vector>

#include <boost/cstdint.hpp>

#include <OgreImageCodec.h>
#include <OgrePlatform.h>

#include "common/TypeDefine.h"

namespace QGears
{
    class TexFile
    {
    public:
        TexFile();
        virtual ~TexFile();

        void read( Ogre::DataStreamPtr& input );
        void readHeader( Ogre::DataStreamPtr& input );
        void readPalleted( Ogre::DataStreamPtr& input );
        Ogre::MemoryDataStream* getPixelData() const;
        Ogre::ImageCodec::ImageData* getImageData() const;

        typedef Ogre::int32 entry_t;

#if OGRE_COMPILER == OGRE_COMPILER_MSVC
#pragma pack (push, 1)
#else
#pragma pack (1)
#endif
        struct BitData
        {
            entry_t color_min;
            entry_t color_max;
            entry_t alpha_min;
            entry_t alpha_max;
            entry_t pixel_min;
            entry_t pixel_max;
        };

        struct ImageData
        {
            entry_t bit_depth;
            entry_t width;
            entry_t height;
            entry_t pitch;
        };

        struct PaletteData
        {
            entry_t flag;
            entry_t index_bits;
            entry_t index_8bit;
            entry_t total_color_count;
            entry_t colors_per_palette;
        };

        struct RGBAData
        {
            entry_t red;
            entry_t green;
            entry_t blue;
            entry_t alpha;
        };

        struct PixelFormat
        {
            entry_t bits_per_pixel;
            entry_t bytes_per_pixel;
            RGBAData bit_count;
            RGBAData bit_mask;
            RGBAData bit_shift;
            RGBAData bit_count_unused;
            RGBAData shades;
        };

        struct Header
        {
            entry_t version;
            entry_t unknown_0x04;
            entry_t color_key_flag;
            entry_t unknown_0x0C;
            entry_t unknown_0x10;
            BitData bit_data;
            entry_t palette_type;
            entry_t palette_count;
            entry_t palette_total_color_count;
            ImageData image_data;
            entry_t unknown_0x48;
            PaletteData palette_data;
            entry_t runtime_data_ptr_palette_data;
            PixelFormat pixel_format;
            entry_t color_key_array_flag;
            entry_t runtime_data_ptr_color_key_array;
            entry_t reference_alpha;
            entry_t runtime_data_02;
            entry_t unknown_0xCC;
            entry_t runtime_data_palette_index;
            entry_t runtime_data_ptr_image_data;
            entry_t runtime_data_04;
            entry_t unknown_06;
            entry_t unknown_07;
            entry_t unknown_08;
            entry_t unknown_09;
        } m_header;

        // reversing ff7 code
        // structure @ 0x3c
        // size 0x80
        struct rev_TextureFormat
        {
            entry_t width;
            entry_t height;
            entry_t pitch;
            entry_t unknown_0x48;
            entry_t palette_flag;
            entry_t bits_per_palette_index;
            entry_t palette_index_8bit;
            entry_t palette_size;
            entry_t palette_color_count;
            entry_t runtime_data_ptr_palette_data;
            PixelFormat pixel_format;
        };

#if OGRE_COMPILER == OGRE_COMPILER_MSVC
#pragma pack (pop)
#else
#pragma pack ()
#endif
        enum PaletteType
        {
            // as in ogre, eg msb -> lsb
            PF_A8R8G8B8     = 0x00
           ,PF_FLOAT32_ARGB = 0x01
           ,PF_B8G8R8A8     = 0x02
        };

        typedef ColorA8R8G8B8 Color;
        typedef std::vector<Color> t_Palette;
        typedef std::vector<Color> t_ImageData;

        t_Palette m_palette;
        t_ImageData m_image_data;

    private:
        void flipEndian(void * pData, size_t size, size_t count) const;
        void flipEndian(void * pData, size_t size) const;

        static const Ogre::uint8 USE_REFERENCE_ALPHA;
    };
}

#endif // __QGearsTexFile_H__
