/*
-----------------------------------------------------------------------------
The MIT License (MIT)

Copyright (c) 2013-08-26 Tobias Peters <tobias.peters@kreativeffekt.at>

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
#ifndef __QGearsXMLSerializer_H__
#define __QGearsXMLSerializer_H__

#include <OgreAxisAlignedBox.h>
#include <OgreColourValue.h>
#include <OgreSerializer.h>
#include <OgreVector2.h>
#include <OgreVector3.h>
#include <tinyxml.h>

#include "common/TypeDefine.h"

namespace QGears
{
    class XMLSerializer
    {
    public:
                        XMLSerializer();
        virtual        ~XMLSerializer();

    protected:
        virtual void    parse( Ogre::DataStreamPtr &stream, TiXmlDocument &pDest );
        virtual void    assertElement( TiXmlNode& node );

        virtual void    readAttribute( TiXmlNode& node,           String &pDest, const String &attribute );
        virtual void    readAttribute( TiXmlNode& node,       Ogre::Real &pDest, const String &attribute );
        virtual void    readAttribute( TiXmlNode& node,    Ogre::Vector2 &pDest, const String &attribute );
        virtual void    readAttribute( TiXmlNode& node,    Ogre::Vector3 &pDest, const String &attribute );
        virtual void    readAttribute( TiXmlNode& node,    Ogre::Vector4 &pDest, const String &attribute );
        virtual void    readAttribute( TiXmlNode& node, Ogre::Quaternion &pDest, const String &attribute );

    private:
    };
}

#endif // __QGearsXMLSerializer_H__
