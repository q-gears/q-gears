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
#ifndef __QGearsSerializer_H__
#define __QGearsSerializer_H__

#include <OgreAxisAlignedBox.h>
#include <OgreColourValue.h>
#include <OgreSerializer.h>
#include <OgreVector2.h>
#include <OgreVector3.h>

#include "common/TypeDefine.h"

namespace QGears
{
    class Serializer : public Ogre::Serializer
    {
    public:
                        Serializer();
        virtual        ~Serializer();

        // TODO implement some more serialization!?
        // ISerializeable  readObject( serializer )
        // virtual void readObject( ISerializable o ) { o.readObject( this ); }
        // template<T> readObject( T )
    protected:
        void    readObject( Ogre::DataStreamPtr &stream, Ogre::Vector2 &pDest );
        void    readObject( Ogre::DataStreamPtr &stream, Ogre::Vector3 &pDest );
        void    readObject( Ogre::DataStreamPtr &stream, Ogre::AxisAlignedBox &pDest );
        void    readObject( Ogre::DataStreamPtr &stream, Pixel &pDest );

        void readChars(Ogre::DataStreamPtr& stream, char* pDest, size_t count);
        void    read1ByteBool( Ogre::DataStreamPtr &stream, bool &pDest );
        void    read2ByteBool( Ogre::DataStreamPtr &stream, bool &pDest );
        void    readShort( Ogre::DataStreamPtr &stream, uint16 &pDest );
        void    readInt16( Ogre::DataStream &stream, sint16 &pDest );
        void    readUInt16( Ogre::DataStream &stream, uint16 &pDest );
        void    readInt16( Ogre::DataStreamPtr &stream, sint16 &pDest );
        void    readUInt16( Ogre::DataStreamPtr &stream, uint16 &pDest );
        void    readUInt32( Ogre::DataStreamPtr &stream, uint32 &pDest );
        void    readSInt32(Ogre::DataStreamPtr &stream, sint32 &pDest);
        void    readUInt32( Ogre::DataStream &stream, uint32 &pDest );
        void    readUInt8( Ogre::DataStream& stream, uint8 &pDest );
        void    readUInt8(Ogre::DataStreamPtr &stream, uint8 &pDest );
        void    readFloat( Ogre::DataStreamPtr &stream, float &pDest );
        void    readEndString( Ogre::DataStreamPtr &stream, const String &end_text );


        String  getLine( Ogre::DataStreamPtr &stream ) const;

        static const String TAG_COMMENT;

    private:
    };
}

#endif // __QGearsSerializer_H__
