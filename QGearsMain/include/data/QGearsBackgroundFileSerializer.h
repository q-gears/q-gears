/*
-----------------------------------------------------------------------------
The MIT License (MIT)

Copyright (c) 2013-08-10 Tobias Peters <tobias.peters@kreativeffekt.at>

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
#ifndef __QGearsBackgroundFileSerializer_H__
#define __QGearsBackgroundFileSerializer_H__

#include "common/TypeDefine.h"

#include "data/QGearsBackgroundFile.h"
#include "data/QGearsSerializer.h"

namespace QGears
{
    class BackgroundFileSerializer : public Serializer
    {
    public:
                        BackgroundFileSerializer();
        virtual        ~BackgroundFileSerializer();

        void    importBackgroundFile( Ogre::DataStreamPtr &stream, BackgroundFile *pDest );

        enum {
            BIT_MASK_RED    = 0xF800
           ,BIT_MASK_GREEN  = 0x07C0
           ,BIT_MASK_BLUE   = 0x001F
           ,BIT_SIZE        = 0x001F
           ,BIT_MASK_RGB    = BIT_MASK_BLUE | BIT_MASK_GREEN | BIT_MASK_RED
        };

        struct Header
        {
            uint16 unused;
            uint16 sort_sprites_by_palette;
        };

        typedef BackgroundFile::Layer       Layer;
        typedef BackgroundFile::SpriteData  SpriteData;
        typedef BackgroundFile::SpriteList  SpriteList;
        typedef BackgroundFile::Page        Page;
        typedef BackgroundFile::Color       Color;

    protected:
        virtual void 	readFileHeader( Ogre::DataStreamPtr &stream );
        virtual void    readSectionHeader( Ogre::DataStreamPtr &stream, const String &section_name );

        virtual void    readPallete( Ogre::DataStreamPtr &stream, BackgroundFile *pDest );
        virtual void    readBackground( Ogre::DataStreamPtr &stream, BackgroundFile *pDest );
        virtual void    readTexture( Ogre::DataStreamPtr &stream, BackgroundFile *pDest );
        virtual void    readEnd( Ogre::DataStreamPtr &stream );

        virtual void    readLayer( Ogre::DataStreamPtr &stream, Layer *pDest, size_t layer_index  );

        virtual void    readObject( Ogre::DataStreamPtr &stream, SpriteData &pDest  );
        virtual void    readObject( Ogre::DataStreamPtr &stream, Color &pDest  );
        virtual void    readObject( Ogre::DataStreamPtr &stream, Page &pDest  );
        using Serializer::readObject;

        template<typename ValueType> void
        readVector( Ogre::DataStreamPtr &stream, std::vector<ValueType> &pDest, size_t count )
        {
            pDest.clear();
            pDest.reserve( count );
            for( size_t i( count ); i--; )
            {
                ValueType in_tmp;
                readObject( stream, in_tmp );
                pDest.push_back( in_tmp );
            }
        }


        static const String     SECTION_NAME_PALETTE;
        static const String     SECTION_NAME_BACK;
        static const String     SECTION_NAME_TEXTURE;
        static const String     TAG_FILE_END;
        static const Ogre::Real src_big_SCALE;

    private:
        Header  m_header;
        size_t m_layer_index;
    };
}

#endif // __QGearsBackgroundFileSerializer_H__
