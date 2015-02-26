/*
-----------------------------------------------------------------------------
The MIT License (MIT)

Copyright (c) 2013-08-19 Tobias Peters <tobias.peters@kreativeffekt.at>

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
#ifndef __QGearsBackgroundFile_H__
#define __QGearsBackgroundFile_H__

#include <OgreResource.h>
#include <OgreImage.h>
#include <OgreVector3.h>

#include "common/TypeDefine.h"
#include "data/QGearsPaletteFile.h"

#include <array>

namespace QGears
{
    // TODO inherit from Qgears Ressource
    class BackgroundFile : public Ogre::Resource
    {
    public:

        BackgroundFile( Ogre::ResourceManager *creator, const String &name
              ,Ogre::ResourceHandle handle, const String &group
              ,bool isManual = false, Ogre::ManualResourceLoader *loader = NULL );

        virtual ~BackgroundFile();

        static const String RESOURCE_TYPE;

        enum {
            PAGE_DATA_WIDTH     = 256
           ,PAGE_DATA_HEIGHT    = PAGE_DATA_WIDTH
           ,PAGE_DATA_SIZE      = PAGE_DATA_WIDTH * PAGE_DATA_HEIGHT
           ,SPRITE_WIDTH        = 16
           ,SPRITE_HEIGHT       = SPRITE_WIDTH
           ,SPRITE_PIXEL_COUNT  = SPRITE_WIDTH * SPRITE_HEIGHT
           ,LAYER_COUNT         = 4
           ,PALETTE_ENTRY_COUNT = 20
           ,PAGE_COUNT          = 42
        };

        struct SpriteData
        {
            Pixel dst;
            uint16 unknown_04[2]; // Unused
            Pixel src;
            Pixel src2; // used for special effects pages, when data_page2 != 0, it must be used instead of src
            uint16 width;
            uint16 height;

            uint16 palette_page;
            uint16 depth; // <=> Z
            uint8  animation_id;
            uint8  animation_frame;
            bool   has_blending[2];
            uint16 blending;
            uint16 data_page;
            uint16 data_page2; // used for special effects pages, when data_page2 != 0, it must be used instead of data_page
            uint16 colour_depth; // Use texture page depth instead
            Ogre::Vector3 src_big; // For PC use (z = unknown, x = srcX / 16 * 625000, y = srcY / 16 * 625000)
        };


        typedef std::vector<SpriteData> SpriteList;
        typedef std::vector<SpriteData*> SpritePtrList;

        struct Layer
        {
            bool enabled;
            uint16 width;
            uint16 height;
            // uint16 sprite_count only read in serializer
            uint16 unknown_06; // unused in layer0
            uint16 unknown_08[3]; // layer 1,2,3
            uint16 unknown_0E[4]; // layer   2,3
            SpriteList sprites;
        };

        typedef PaletteFile::Color Color;

        typedef std::vector<uint8> Buffer;
        typedef std::vector<Color> Colors;

        struct Page
        {
            bool enabled; // only read further if this is > 0
            uint16 unknown_02;
            uint16 value_size;
            // uint8 if value_size == 1, uint16 if value_size == 2
            //uint8 data[PAGE_DATA_WIDTH][PAGE_DATA_HEIGHT];
            Buffer data;
            Colors colors;
        };

        std::array<Layer, LAYER_COUNT>& getLayers(void) { return m_layers; }
        std::array<uint8, PALETTE_ENTRY_COUNT>& getPalette(void) { return m_palette; }
        std::array<Page, PAGE_COUNT>&  getPages(void) { return m_pages; }

        Ogre::Image*        createImage     ( const PaletteFilePtr &palette );

        void addAllSprites( SpritePtrList& sprites ) ;

    protected:
        virtual void loadImpl();
        virtual void unloadImpl();
        virtual size_t calculateSize() const;
        virtual size_t calculateSize( const Layer &layer ) const;
        virtual size_t calculateSize( const Page  &page  ) const;

    private:
        std::array<Layer, LAYER_COUNT> m_layers;
        std::array<uint8, PALETTE_ENTRY_COUNT> m_palette;

        std::array<Page, PAGE_COUNT> m_pages;
    };

    typedef Ogre::SharedPtr<BackgroundFile> BackgroundFilePtr;
}

#endif // __QGearsBackgroundFile_H__
