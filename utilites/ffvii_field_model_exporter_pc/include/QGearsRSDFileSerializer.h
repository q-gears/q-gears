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
#ifndef __QGearsRSDFileSerializer_H__
#define __QGearsRSDFileSerializer_H__

#include "QGearsRSDFile.h"
#include "QGearsSerializer.h"

#include "common/TypeDefine.h"

namespace QGears
{
    class RSDFileSerializer : public Serializer
    {
    public:
                        RSDFileSerializer();
        virtual        ~RSDFileSerializer();

        virtual void 	importRSDFile( Ogre::DataStreamPtr &stream, RSDFile* pDest );

    protected:
        virtual String  readLine( Ogre::DataStreamPtr &stream ) const;
        virtual void 	readFileHeader( Ogre::DataStreamPtr &stream );
        virtual void    parseLine( const String &line, RSDFile* pDest );

        static const String TAG_COMMENT;
        static const String TAG_HEADER;
        static const String TAG_POLYGON;
        static const String TAG_MATERIAL;
        static const String TAG_GROUP;
        static const String TAG_TEXTURE_COUNT;
        static const String TAG_TEXTURE_NAME;
        static const String PARSE_DELIMITER;
    private:
        bool    m_has_texture_count;
        size_t  m_texture_count;
    };
}

#endif // __QGearsRSDFileSerializer_H__
