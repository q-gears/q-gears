#ifndef __QGearsWalkmeshFileXMLSerializer_H__
#define __QGearsWalkmeshFileXMLSerializer_H__

#include "common/TypeDefine.h"
#include "data/QGearsXMLSerializer.h"

#include "QGearsWalkmeshFile.h"

namespace QGears
{
    class WalkmeshFileXMLSerializer : public XMLSerializer
    {
    public:
        WalkmeshFileXMLSerializer();
        virtual        ~WalkmeshFileXMLSerializer();
        
        virtual void    importWalkmeshFile( Ogre::DataStreamPtr &stream, WalkmeshFile *pDest );

        typedef WalkmeshFile::Triangle      Triangle;
        typedef WalkmeshFile::TriangleList  TriangleList;

    protected:
        virtual void    readHeader( TiXmlNode *node );
        virtual void    readObject( TiXmlNode &node, Triangle &pDest );

        template<typename ValueType> void
        readVector( TiXmlNode &node, std::vector<ValueType> &pDest, const String &tag )
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

    private:
    };
}

#endif // __QGearsWalkmeshFileXMLSerializer_H__

