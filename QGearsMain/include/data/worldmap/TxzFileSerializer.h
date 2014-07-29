#ifndef _TXZ_FILE_SERIALIZER_H_
#define _TXZ_FILE_SERIALIZER_H_

#include "common/TypeDefine.h"
#include "data/QGearsSerializer.h"

BEGIN_QGEARS

class TxzFile;

class TxzFileSerializer : public Serializer
{
public:
    TxzFileSerializer();
    virtual ~TxzFileSerializer();
    void import( Ogre::DataStreamPtr& stream, TxzFile& dest );
private:
    void import_decompressed( Ogre::DataStream& stream, TxzFile& dest);
};

END_QGEARS

#endif // _TXZ_FILE_SERIALIZER_H_
