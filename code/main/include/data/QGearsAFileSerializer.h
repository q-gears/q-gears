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
#ifndef __QGearsAFileSerializer_H__
#define __QGearsAFileSerializer_H__

#include "common/TypeDefine.h"
#include "QGearsAFile.h"
#include "QGearsSerializer.h"

namespace QGears
{
    class AFileSerializer : public Serializer
    {
    public:
                        AFileSerializer();
        virtual        ~AFileSerializer();

        virtual void 	importAFile( Ogre::DataStreamPtr &stream, AFile* pDest );

        struct Header
        {
            uint32 version;
            uint32 frame_count;
            uint32 bone_count;
            uint32 rotation_order;
            uint32 runtime_data[5];
        };

    protected:
        virtual void 	readFileHeader( Ogre::DataStreamPtr &stream );
        virtual void 	readObject( Ogre::DataStreamPtr &stream, AFile::Frame &pDest );
        using Serializer::readObject;

        template<typename ValueType>
        void readVector( Ogre::DataStreamPtr &stream
                        ,std::vector<ValueType> &pDest, size_t count );

    private:
        Header  m_header;
    };
}

#endif // __QGearsAFileSerializer_H__
