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
    //--------------------------------------------------------------------------
    XMLSerializer::XMLSerializer()
    {
    }

    //--------------------------------------------------------------------------
    XMLSerializer::~XMLSerializer()
    {
    }

    //--------------------------------------------------------------------------
    void
    XMLSerializer::parse( Ogre::DataStreamPtr &stream, TiXmlDocument &pDest )
    {
        pDest.Parse( stream->getAsString().c_str() );
    }

    //--------------------------------------------------------------------------
    const String*
    XMLSerializer::readAttribute( TiXmlNode &node, const String &attribute )
    {
        assertElement( node );
        return node.ToElement()->Attribute( attribute );
    }

    //--------------------------------------------------------------------------
    bool
    XMLSerializer::readAttribute( TiXmlNode &node, const String &attribute, bool &pDest, const bool &pDefault)
    {
        const String *value( readAttribute( node, attribute ) );
        if( value == NULL )
        {
            pDest = pDefault;
            return false;
        }
        pDest = Ogre::StringConverter::parseBool( *value );
        return true;
    }

    //--------------------------------------------------------------------------
    bool
    XMLSerializer::readAttribute( TiXmlNode &node, const String &attribute, int &pDest, const int &pDefault)
    {
        const String *value( readAttribute( node, attribute ) );
        if( value == NULL )
        {
            pDest = pDefault;
            return false;
        }
        pDest = Ogre::StringConverter::parseInt( *value );
        return true;
    }

    //--------------------------------------------------------------------------
    bool
    XMLSerializer::readAttribute( TiXmlNode &node, const String &attribute
                                , String &pDest, const String &pDefault )
    {
        const String *value( readAttribute( node, attribute ) );
        if( value == NULL )
        {
            pDest = pDefault;
            return false;
        }
        pDest = *value;
        return true;
    }

    //--------------------------------------------------------------------------
    bool
    XMLSerializer::readAttribute(TiXmlNode &node, const String &attribute, Ogre::Real &pDest, const Ogre::Real &pDefault)
    {
        const String *value( readAttribute( node, attribute ) );
        if( value == NULL )
        {
            pDest = pDefault;
            return false;
        }
        pDest = Ogre::StringConverter::parseReal( *value );
        return true;
    }

    //--------------------------------------------------------------------------
    bool
    XMLSerializer::readAttribute(TiXmlNode &node, const String &attribute, Ogre::Vector2 &pDest, const Ogre::Vector2 &pDefault)
    {
        const String *value( readAttribute( node, attribute ) );
        if( value == NULL )
        {
            pDest = pDefault;
            return false;
        }
        pDest = Ogre::StringConverter::parseVector2( *value );
        return true;
    }

    //--------------------------------------------------------------------------
    bool
    XMLSerializer::readAttribute(TiXmlNode &node, const String &attribute, Ogre::Vector3 &pDest, const Ogre::Vector3 &pDefault)
    {
        const String *value( readAttribute( node, attribute ) );
        if( value == NULL )
        {
            pDest = pDefault;
            return false;
        }
        pDest = Ogre::StringConverter::parseVector3( *value );
        return true;
    }

    //--------------------------------------------------------------------------
    bool
    XMLSerializer::readAttribute(TiXmlNode &node, const String &attribute, Ogre::Vector4 &pDest, const Ogre::Vector4 &pDefault)
    {
        const String *value( readAttribute( node, attribute ) );
        if( value == NULL )
        {
            pDest = pDefault;
            return false;
        }
        pDest = Ogre::StringConverter::parseVector4( *value );
        return true;
    }

    //--------------------------------------------------------------------------
    bool
    XMLSerializer::readAttribute(TiXmlNode &node, const String &attribute, Ogre::Quaternion &pDest, const Ogre::Quaternion &pDefault)
    {
        const String *value( readAttribute( node, attribute ) );
        if( value == NULL )
        {
            pDest = pDefault;
            return false;
        }
        pDest = Ogre::StringConverter::parseQuaternion( *value );
        return true;
    }

    //--------------------------------------------------------------------------
    TiXmlNode*
    XMLSerializer::findChildNode( TiXmlNode &node, const String &tag )
    {
        TiXmlNode* child( node.FirstChild() );
        while( child != NULL && child->ValueStr() != tag )
        {
            child = child->NextSibling();
        }
        return child;
    }

    //--------------------------------------------------------------------------
}
