#ifndef _TXZ_FILE_MANAGER_H_
#define _TXZ_FILE_MANAGER_H_

#include <OgreResourceManager.h>
#include "common/TypeDefine.h"
#include "QGearsPrerequisites.h"

BEGIN_QGEARS

class _QGearsExport TxzFileManager
        : public Ogre::ResourceManager,
          public Ogre::Singleton<TxzFileManager>
{
public:
    TxzFileManager();
    virtual ~TxzFileManager();

    static TxzFileManager& getSingleton();
    static TxzFileManager* getSingletonPtr();

private:
    virtual Ogre::Resource* createImpl(
            const Ogre::String &name,
            Ogre::ResourceHandle handle,
            const Ogre::String &group,
            bool isManual,
            Ogre::ManualResourceLoader *loader,
            const Ogre::NameValuePairList *createParams ) override final;
};

END_QGEARS

#endif // _TXZ_FILE_MANAGER_H_
