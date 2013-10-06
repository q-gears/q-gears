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
        
    protected:
        
    private:
    };
}

#endif // __QGearsWalkmeshFileXMLSerializer_H__

