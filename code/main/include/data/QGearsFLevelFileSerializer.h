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

        virtual void 	importFLevelFile( Ogre::DataStreamPtr &stream, FLevelFile* pDest );

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
        };

        struct Header
        {
            uint16 version;
            uint32 section_count;
        };

    protected:
        virtual void 	readFileHeader( Ogre::DataStreamPtr &stream );
        //using Serializer::readObject;

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

    private:
        Header  m_header;
    };
}

#endif // __QGearsFLevelFileSerializer_H__
