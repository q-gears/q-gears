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
#ifndef __QGearsHRCFileSerializer_H__
#define __QGearsHRCFileSerializer_H__

#include "QGearsHRCFile.h"
#include "QGearsSerializer.h"

namespace QGears
{
    class HRCFileSerializer : public Serializer
    {
    public:
                        HRCFileSerializer();
        virtual        ~HRCFileSerializer();

        virtual void    importHRCFile( Ogre::DataStreamPtr &stream, HRCFile* pDest );

    protected:
        static const String TAG_COMMENT;
        static const String TAG_VERSION;
        static const String TAG_NAME;
        static const String TAG_BONE_COUNT;

        typedef std::vector<String> Block;
        typedef HRCFile::Bone       Bone;

        virtual void    readFileHeader( Ogre::DataStreamPtr &stream );
        virtual void    readBlock( Ogre::DataStreamPtr &stream, Block& pDest );
        virtual void    readObject( Ogre::DataStreamPtr &stream, Bone &pDest );

        template<typename ValueType>
                void    readVector( Ogre::DataStreamPtr &stream
                                   ,std::vector<ValueType> &pDest
                                   ,size_t count );

        struct Header
        {
            long    version;
            long    bone_count;
            String  name;
        };

    private:
        Header  m_header;
    };
}

#endif // __QGearsHRCFileSerializer_H__
