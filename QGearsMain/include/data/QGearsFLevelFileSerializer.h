/*
-----------------------------------------------------------------------------
The MIT License (MIT)

Copyright (c) 2013-08-24 Tobias Peters <tobias.peters@kreativeffekt.at>

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
#ifndef __QGearsFLevelFileSerializer_H__
#define __QGearsFLevelFileSerializer_H__

#include "common/TypeDefine.h"

#include "QGearsFLevelFile.h"
#include "QGearsSerializer.h"

namespace QGears
{
    class FLevelFileSerializer : public Serializer
    {
    public:
                        FLevelFileSerializer();
        virtual        ~FLevelFileSerializer();

        virtual void    importFLevelFile( Ogre::DataStreamPtr &stream, FLevelFile* pDest );

        enum
        {
            SECTION_SCRIPT
           ,SECTION_CAMERA_MATRIX
           ,SECTION_MODEL_LOADER
           ,SECTION_PALETTE
           ,SECTION_WALKMESH
           ,SECTION_TILE_MAP
           ,SECTION_ENCOUNTER
           ,SECTION_TRIGGER
           ,SECTION_BACKGROUND
           ,SECTION_COUNT
        };

        struct Header
        {
            uint16 version;
            uint32 section_count;
        };

    protected:
        void    readFileHeader( Ogre::DataStreamPtr &stream );

        void    readSectionData(Ogre::DataStreamPtr &stream, Ogre::DataStreamPtr &out_buffer, size_t sectionSize);
        virtual void    readSection( Ogre::DataStreamPtr &stream, FLevelFile* pDest, const size_t section_index );

        template<typename ResourceManagerType>
        Ogre::ResourcePtr createResource( FLevelFile *pDest, const String &extension );

        void    readCameraMatrix( Ogre::DataStreamPtr &stream, FLevelFile* pDest );
        void    readModelList   ( Ogre::DataStreamPtr &stream, FLevelFile* pDest );
        void    readPalette     ( Ogre::DataStreamPtr &stream, FLevelFile* pDest );
        void    readWalkmesh    ( Ogre::DataStreamPtr &stream, FLevelFile* pDest );
        void    readBackground  ( Ogre::DataStreamPtr &stream, FLevelFile* pDest );
        void    readTriggers    (Ogre::DataStreamPtr &stream, FLevelFile* pDest);

        void    readEnd( Ogre::DataStreamPtr &stream );

        template<typename ValueType> void
        readVector( Ogre::DataStreamPtr &stream, std::vector<ValueType> &pDest, size_t count );

        virtual String  getBaseName        ( const FLevelFile* pDest ) const;

        static const String     TAG_FILE_END;

    private:
        Header  m_header;
    };
}

#endif // __QGearsFLevelFileSerializer_H__
