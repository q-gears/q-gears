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
#ifndef __QGearsBackground2DFileXMLSerializer_H__
#define __QGearsBackground2DFileXMLSerializer_H__

#include "common/TypeDefine.h"
#include "data/QGearsXMLSerializer.h"

#include "QGearsBackground2DFile.h"

namespace QGears
{
    class Background2DFileXMLSerializer : public XMLSerializer
    {
    public:
        Background2DFileXMLSerializer();
        virtual        ~Background2DFileXMLSerializer();

        virtual void    importBackground2DFile( Ogre::DataStreamPtr &stream, Background2DFile *pDest );

    protected:
        virtual void    readHeader( TiXmlNode *node );
        virtual bool    readAttribute( TiXmlNode &node, const String &attribute, Blending &pDest, const Blending &pDefault );
        using XMLSerializer::readAttribute;

        virtual void    readObject( TiXmlNode &node, Tile &pDest );
        virtual void    readObject( TiXmlNode &node, Animation &pDest );
        virtual void    readObject( TiXmlNode &node, KeyFrame &pDest );

        static const String BLENDING_ALPHA;
        static const String BLENDING_ADD;
        static const String BLENDING_SUBTRACT;

        template<typename ValueType> void
        readVector( TiXmlNode &node, const String &tag, std::vector<ValueType> &pDest )
        {
            pDest.clear();

            TiXmlNode* child( node.FirstChild() );
            while( child != NULL )
            {
                if( child->Type() == TiXmlNode::TINYXML_ELEMENT && child->ValueStr() == tag )
                {
                    ValueType in_tmp;
                    readObject( *child, in_tmp );
                    pDest.push_back( in_tmp );
                }
                child = child->NextSibling();
            }
        }

        template<typename KeyType, typename ValueType> void
        readMap( TiXmlNode& node, const String& tag, const String& key_attribute, std::map< KeyType, ValueType > &pDest )
        {
            pDest.clear();

            TiXmlNode* child( node.FirstChild() );
            while( child != NULL )
            {
                if( child->Type() == TiXmlNode::TINYXML_ELEMENT && child->ValueStr() == tag )
                {
                    KeyType key;
                    if( readAttribute( *child, key_attribute, key ) )
                    {
                        ValueType in_tmp;
                        readObject( *child, in_tmp );
                        pDest[key] = in_tmp;
                    }
                }
                child = child->NextSibling();
            }
        }

    private:
    };
}

#endif // __QGearsBackground2DFileXMLSerializer_H__
