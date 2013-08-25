/*
-----------------------------------------------------------------------------
The MIT License (MIT)

Copyright (c) 2013-08-22 Tobias Peters <tobias.peters@kreativeffekt.at>

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
#include "data/QGearsPaletteFileSerializer.h"

#include <OgreLogManager.h>

namespace QGears
{
    //---------------------------------------------------------------------
    PaletteFileSerializer::PaletteFileSerializer() :
        Serializer()
    {
    }

    //---------------------------------------------------------------------
    PaletteFileSerializer::~PaletteFileSerializer()
    {
    }

    //---------------------------------------------------------------------
    void
    PaletteFileSerializer::importPaletteFile( Ogre::DataStreamPtr &stream, PaletteFile* pDest )
    {
        readFileHeader( stream );
        readVector( stream, pDest->getPages(), m_header.page_count );
    }

    //---------------------------------------------------------------------
    void
    PaletteFileSerializer::readFileHeader( Ogre::DataStreamPtr &stream )
    {
        readInt(   stream, m_header.file_size );
        readShort( stream, m_header.pal_x );
        readShort( stream, m_header.pal_y );
        readShort( stream, m_header.colors_per_page );
        readShort( stream, m_header.page_count );
    }

    //---------------------------------------------------------------------
    void
    PaletteFileSerializer::readObject( Ogre::DataStreamPtr &stream, Color &pDest )
    {
        readShort( stream, pDest );
    }

    //---------------------------------------------------------------------
    void
    PaletteFileSerializer::readObject( Ogre::DataStreamPtr &stream, Page &pDest )
    {
        readVector( stream, pDest, m_header.colors_per_page );
    }

    //---------------------------------------------------------------------
}
