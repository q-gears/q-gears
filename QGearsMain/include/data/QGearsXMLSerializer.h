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
#include <tinyxml/tinyxml.h>

#include "common/TypeDefine.h"

namespace QGears
{
#ifdef NDEBUG
#define assertElement( node )((void)0)
#else
#define assertElement( node )\
{\
    if( node.Type() != TiXmlNode::TINYXML_ELEMENT )\
    {\
        OGRE_EXCEPT(Ogre::Exception::ERR_INVALIDPARAMS\
            ,"node has wrong type, needs to be TINYXML_ELEMENT"\
            ,"XMLSerializer::assertElement" );\
    }\
}
#endif

    class XMLSerializer
    {
    public:
        XMLSerializer();
        virtual ~XMLSerializer();

    protected:
        virtual void    parse( Ogre::DataStreamPtr &stream, TiXmlDocument &pDest );

        virtual const String* readAttribute( TiXmlNode &node, const String &attribute );

        virtual bool    readAttribute( TiXmlNode &node, const String &attribute, bool             &pDest, const bool             &pDefault = false );
        virtual bool    readAttribute( TiXmlNode &node, const String &attribute, int              &pDest, const int              &pDefault = 0 );
        virtual bool    readAttribute( TiXmlNode &node, const String &attribute, String           &pDest, const String           &pDefault = "" );
        virtual bool    readAttribute( TiXmlNode &node, const String &attribute, Ogre::Real       &pDest, const Ogre::Real       &pDefault = 0 );
        virtual bool    readAttribute( TiXmlNode &node, const String &attribute, Ogre::Vector2    &pDest, const Ogre::Vector2    &pDefault = Ogre::Vector2::ZERO );
        virtual bool    readAttribute( TiXmlNode &node, const String &attribute, Ogre::Vector3    &pDest, const Ogre::Vector3    &pDefault = Ogre::Vector3::ZERO );
        virtual bool    readAttribute( TiXmlNode &node, const String &attribute, Ogre::Vector4    &pDest, const Ogre::Vector4    &pDefault = Ogre::Vector4::ZERO );
        virtual bool    readAttribute( TiXmlNode &node, const String &attribute, Ogre::Quaternion &pDest, const Ogre::Quaternion &pDefault = Ogre::Quaternion::IDENTITY );

        virtual TiXmlNode* findChildNode( TiXmlNode &node, const String &tag );

    private:
    };
}

#endif // __QGearsXMLSerializer_H__
