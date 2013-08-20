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

        virtual void 	importBackgroundFile( Ogre::DataStreamPtr &stream, BackgroundFile *pDest );

        struct Header
        {
            uint16 unused;
            uint16 unknown;
        };

    protected:
        virtual void 	readFileHeader( Ogre::DataStreamPtr &stream );
        virtual void    readSectionHeader( Ogre::DataStreamPtr &stream, const String &section_name );

        virtual void    readPallete( Ogre::DataStreamPtr &stream, BackgroundFile *pDest );
        virtual void    readBackground( Ogre::DataStreamPtr &stream, BackgroundFile *pDest );
        //virtual void    readObject( Ogre::DataStreamPtr &stream, BBoxEntry &pDest );
        //using Serializer::readObject;

        static const String SECTION_NAME_PALETTE;
        static const String SECTION_NAME_BACK;
        static const String SECTION_NAME_TEXTURE;

    private:
        Header  m_header;
    };
}

#endif // __QGearsBackgroundFileSerializer_H__
