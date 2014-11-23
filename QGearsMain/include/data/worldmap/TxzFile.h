#ifndef _TXZ_FILE_H_
#define _TXZ_FILE_H_

#include "common/QGearsResource.h"

BEGIN_QGEARS

class TxzFile : public Resource
{
public:
    static const String RESOURCE_TYPE;
    TxzFile(Ogre::ResourceManager* creator, const Ogre::String& name, Ogre::ResourceHandle handle,
        const Ogre::String& group, bool isManual = false, Ogre::ManualResourceLoader* loader = 0)
        : Resource(creator, name, handle, group, isManual, loader)
    {

    }
    virtual ~TxzFile();
private:
    virtual void loadImpl() override final;
    virtual void unloadImpl() override final;
};

typedef Ogre::SharedPtr<TxzFile> TxzFilePtr;

END_QGEARS

#endif // _TXZ_FILE_H_
