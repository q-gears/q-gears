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
#include <OgreVector3.h>

#include "common/TypeDefine.h"
#include "common/QGearsPaletteFile.h"

namespace QGears
{
    class BackgroundFile : public Ogre::Resource
    {
    public:

        BackgroundFile( Ogre::ResourceManager *creator, const String &name
              ,Ogre::ResourceHandle handle, const String &group
              ,bool isManual = false, Ogre::ManualResourceLoader *loader = NULL );

        virtual ~BackgroundFile();

        static const String RESOURCE_TYPE;

        typedef PaletteFile::Color_BGR Color_BGR;

        enum {
            PAGE_DATA_WIDTH     = 0x100
           ,PAGE_DATA_HEIGHT    = PAGE_DATA_WIDTH
           ,PAGE_DATA_SIZE      = PAGE_DATA_WIDTH * PAGE_DATA_HEIGHT
           ,SPRITE_WIDTH        = 0x10
           ,SPRITE_HEIGHT       = SPRITE_WIDTH
           ,LAYER_COUNT         = 4
           ,PALETTE_ENTRY_COUNT = 20
           ,PAGE_COUNT          = 42
        };

        struct Pixel
        {
            sint16 x;
            sint16 y;
        };

        struct SpriteData
        {
            Pixel dst;
            uint16 unknown_04[2];
            Pixel src;
            uint16 unknown_0C[4];

            uint16 palette_page;
            uint16 unknown_16;
            uint8  flags_18[2];
            bool   flags_20[2];
            uint16 unknown_1C;
            uint16 data_page;
            uint16 unknown_20;
            uint16 unknown_22;
            Ogre::Vector3 unknown_24;
        };


        typedef std::vector<SpriteData> SpriteList;

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


        typedef std::vector<uint8>  Buffer;

        struct Page
        {
            bool enabled; // only read further if this is > 0
            uint16 unknown_02;
            uint16 value_size;
            // uint8 if value_size == 1, uint16 if value_size == 2
            //uint8 data[PAGE_DATA_WIDTH][PAGE_DATA_HEIGHT];
            Buffer data;
        };

        virtual Layer* getLayers ( void ) { return m_layers;  };
        virtual uint8* getPalette( void ) { return m_palette; };
        virtual Page*  getPages  ( void ) { return m_pages;   };

    protected:
        virtual void loadImpl();
        virtual void unloadImpl();
        virtual size_t calculateSize() const;
        virtual size_t calculateSize( const Layer &layer ) const;
        virtual size_t calculateSize( const Page  &page  ) const;

    private:
        Layer m_layers [ LAYER_COUNT ];
        uint8 m_palette[ PALETTE_ENTRY_COUNT ];

        Page m_pages[ PAGE_COUNT ];
    };

    //-------------------------------------------------------------------------
    class BackgroundFilePtr : public Ogre::SharedPtr<BackgroundFile>
    {
    public:
        BackgroundFilePtr() : Ogre::SharedPtr<BackgroundFile>() {}
        explicit BackgroundFilePtr( BackgroundFile *rep ) : Ogre::SharedPtr<BackgroundFile>(rep) {}
        BackgroundFilePtr( const BackgroundFilePtr &r ) : Ogre::SharedPtr<BackgroundFile>(r) {}
        BackgroundFilePtr( const Ogre::ResourcePtr &r ) : Ogre::SharedPtr<BackgroundFile>()
        {
            if( r.isNull() )
                return;
            // lock & copy other mutex pointer
            OGRE_LOCK_MUTEX(*r.OGRE_AUTO_MUTEX_NAME)
            OGRE_COPY_AUTO_SHARED_MUTEX(r.OGRE_AUTO_MUTEX_NAME)
            pRep = static_cast<BackgroundFile*>(r.getPointer());
            pUseCount = r.useCountPointer();
            useFreeMethod = r.freeMethod();
            if (pUseCount)
            {
                ++(*pUseCount);
            }
        }

        /// Operator used to convert a ResourcePtr to a BackgroundFilePtr
        BackgroundFilePtr& operator=( const Ogre::ResourcePtr& r )
        {
            if(pRep == static_cast<BackgroundFile*>(r.getPointer()))
                return *this;
            release();
            if( r.isNull() )
                return *this; // resource ptr is null, so the call to release above has done all we need to do.
            // lock & copy other mutex pointer
            OGRE_LOCK_MUTEX(*r.OGRE_AUTO_MUTEX_NAME)
            OGRE_COPY_AUTO_SHARED_MUTEX(r.OGRE_AUTO_MUTEX_NAME)
            pRep = static_cast<BackgroundFile*>(r.getPointer());
            pUseCount = r.useCountPointer();
            useFreeMethod = r.freeMethod();
            if (pUseCount)
            {
                ++(*pUseCount);
            }
            return *this;
        }
    };
}

#endif // __QGearsBackgroundFile_H__
