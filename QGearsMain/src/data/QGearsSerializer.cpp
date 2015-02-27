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
#include "data/QGearsSerializer.h"

#include <OgreLogManager.h>

namespace QGears
{
    typedef Ogre::StringUtil        StringUtil;

    //---------------------------------------------------------------------
    const String Serializer::TAG_COMMENT( "#" );

    //---------------------------------------------------------------------
    Serializer::Serializer()
    {
        determineEndianness( Ogre::Serializer::ENDIAN_LITTLE );
    }

    //---------------------------------------------------------------------
    Serializer::~Serializer()
    {
    }

    //---------------------------------------------------------------------
    void
    Serializer::readObject( Ogre::DataStreamPtr &stream
                           ,Ogre::Vector2 &pDest )
    {
        float v[2];
        readFloats( stream, v, 2 );
        pDest.x = v[0];
        pDest.y = v[1];
    }

    //---------------------------------------------------------------------
    void
    Serializer::readObject( Ogre::DataStreamPtr &stream
                           ,Ogre::Vector3 &pDest )
    {
        float tmp[3];
        readFloats( stream, tmp, 3 );
        pDest.x = tmp[0];
        pDest.y = tmp[1];
        pDest.z = tmp[2];
    }

    //---------------------------------------------------------------------
    void
    Serializer::readObject( Ogre::DataStreamPtr &stream
                           ,Ogre::AxisAlignedBox &pDest )
    {
        Ogre::Vector3 tmp;
        readObject( stream, tmp );
        pDest.setMaximum( tmp );

        readObject( stream, tmp );
        pDest.setMinimum( tmp );
    }

    //---------------------------------------------------------------------
    void
    Serializer::readObject( Ogre::DataStreamPtr &stream, Pixel &pDest )
    {
        stream->read( &pDest, sizeof( pDest ) );
        flipFromLittleEndian( &pDest, 2, 2 );
    }

    void Serializer::readChars(Ogre::DataStreamPtr& stream, char* pDest, size_t count)
    {
        stream->read(pDest, count);
    }

    //---------------------------------------------------------------------
    void
    Serializer::read1ByteBool( Ogre::DataStreamPtr &stream, bool &pDest )
    {
        uint8 enabled;
        stream->read( &enabled, 1 );
        pDest = enabled > 0;
    }

    //---------------------------------------------------------------------
    void
    Serializer::read2ByteBool( Ogre::DataStreamPtr &stream, bool &pDest )
    {
        uint16 enabled;
        readShort( stream, enabled );
        pDest = enabled > 0;
    }

    //---------------------------------------------------------------------
    void
    Serializer::readShort( Ogre::DataStreamPtr &stream, uint16 &pDest )
    {
        readShorts( stream, &pDest, 1 );
    }

    void Serializer::readInt16( Ogre::DataStream &stream, sint16 &pDest )
    {
        stream.read( &pDest, sizeof(sint16) );
    }

    void Serializer::readUInt16( Ogre::DataStream &stream, uint16 &pDest )
    {
        stream.read( &pDest, sizeof(uint16) );
    }

    void Serializer::readInt16( Ogre::DataStreamPtr &stream, sint16 &pDest )
    {
        stream->read( &pDest, sizeof(sint16) );
    }

    void Serializer::readUInt16( Ogre::DataStreamPtr &stream, uint16 &pDest )
    {
        readShorts( stream, &pDest, 1 );
    }

    //---------------------------------------------------------------------
    void
    Serializer::readUInt32( Ogre::DataStreamPtr &stream, uint32 &pDest )
    {
        readInts( stream, &pDest, 1 );
    }

    void Serializer::readSInt32(Ogre::DataStreamPtr &stream, sint32 &pDest)
    {
        stream->read(&pDest, sizeof(sint32));
    }

    void Serializer::readUInt32( Ogre::DataStream &stream, uint32 &pDest )
    {
        stream.read(&pDest,sizeof(uint32));
    }

    void Serializer::readUInt8( Ogre::DataStream& stream, uint8 &pDest )
    {
        stream.read(&pDest,1);
    }

    void Serializer::readUInt8( Ogre::DataStreamPtr &stream, uint8 &pDest )
    {
        stream->read(&pDest,1);
    }

    //---------------------------------------------------------------------
    void
    Serializer::readFloat( Ogre::DataStreamPtr &stream, float &pDest )
    {
        readFloats( stream, &pDest, 1 );
    }

    //---------------------------------------------------------------------
    String
    Serializer::getLine( Ogre::DataStreamPtr &stream ) const
    {
        String line("");
        do
        {
            line = stream->getLine();

        } while( StringUtil::startsWith( line, TAG_COMMENT ) );

        return line;
    }

    //---------------------------------------------------------------------
    void
    Serializer::readEndString( Ogre::DataStreamPtr &stream, const String &end_text )
    {
        String actual( readString( stream, end_text.size() ) );
        if( actual != end_text )
        {
            Ogre::LogManager::getSingleton().stream()
                << "Warning: File didn't end with"
                << " expected String '" << end_text << "'"
                << " actual was '" << actual << "'";
        }
    }

    //---------------------------------------------------------------------
}
