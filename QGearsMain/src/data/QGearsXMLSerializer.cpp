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
#include "data/QGearsXMLSerializer.h"

#include <OgreException.h>
#include <OgreLogManager.h>
#include <OgreStringConverter.h>

namespace QGears
{
    //---------------------------------------------------------------------
    XMLSerializer::XMLSerializer()
    {
    }

    //---------------------------------------------------------------------
    XMLSerializer::~XMLSerializer()
    {
    }

    //---------------------------------------------------------------------
    void
    XMLSerializer::parse( Ogre::DataStreamPtr& stream, TiXmlDocument &pDest )
    {
        pDest.Parse( stream->getAsString().c_str() );
    }

    //---------------------------------------------------------------------
    void
    XMLSerializer::assertElement( TiXmlNode& node )
    {
        if( node.Type() != TiXmlNode::TINYXML_ELEMENT )
        {
            OGRE_EXCEPT(Ogre::Exception::ERR_INVALIDPARAMS
                ,"node has wrong type, needs to be TINYXML_ELEMENT"
                ,"XMLSerializer::assertElement" );
        }
    }

    //---------------------------------------------------------------------
    bool
    XMLSerializer::readAttribute( TiXmlNode& node, int &pDest, const String &attribute )
    {
        assertElement( node );
        const String* value( node.ToElement()->Attribute( attribute ) );
        if( value == NULL ) return false;
        pDest = Ogre::StringConverter::parseInt( *value );
        return true;
    }

    //---------------------------------------------------------------------
    bool
    XMLSerializer::readAttribute( TiXmlNode& node, String &pDest, const String &attribute )
    {
        assertElement( node );
        const String* value( node.ToElement()->Attribute( attribute ) );
        if( value == NULL ) return false;
        pDest = *value;
        return true;
    }

    //---------------------------------------------------------------------
    bool
    XMLSerializer::readAttribute( TiXmlNode& node, Ogre::Real &pDest, const String &attribute )
    {
        assertElement( node );
        const String* value( node.ToElement()->Attribute( attribute ) );
        if( value == NULL ) return false;

        pDest = Ogre::StringConverter::parseReal( *value );
        return true;
    }

    //---------------------------------------------------------------------
    bool
    XMLSerializer::readAttribute( TiXmlNode& node, Ogre::Vector2 &pDest, const String &attribute )
    {
        assertElement( node );
        const String* value( node.ToElement()->Attribute( attribute ) );
        if( value == NULL ) return false;

        pDest = Ogre::StringConverter::parseVector2( *value );
        return true;
    }

    //---------------------------------------------------------------------
    bool
    XMLSerializer::readAttribute( TiXmlNode& node, Ogre::Vector3 &pDest, const String &attribute )
    {
        assertElement( node );
        const String* value( node.ToElement()->Attribute( attribute ) );
        if( value == NULL ) return false;

        pDest = Ogre::StringConverter::parseVector3( *value );
        return true;
    }

    //---------------------------------------------------------------------
    bool
    XMLSerializer::readAttribute( TiXmlNode& node, Ogre::Vector4 &pDest, const String &attribute )
    {
        assertElement( node );
        const String* value( node.ToElement()->Attribute( attribute ) );
        if( value == NULL ) return false;

        pDest = Ogre::StringConverter::parseVector4( *value );
    }

    //---------------------------------------------------------------------
    bool
    XMLSerializer::readAttribute( TiXmlNode& node, Ogre::Quaternion &pDest, const String &attribute )
    {
        assertElement( node );
        const String* value( node.ToElement()->Attribute( attribute ) );
        if( value == NULL ) return false;

        pDest = Ogre::StringConverter::parseQuaternion( *value );
    }

    //---------------------------------------------------------------------
}
