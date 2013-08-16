#ifndef __QGearsHRCFileManage_H__
#define __QGearsHRCFileManage_H__

#include <OgreResourceManager.h>

#include "QGearsHRCFile.h"

namespace QGears
{
    class HRCFileManager : public Ogre::ResourceManager, public Ogre::Singleton<HRCFileManager>
    {
    public:
        HRCFileManager();
        virtual ~HRCFileManager();

        virtual HRCFilePtr load( const Ogre::String &name, const Ogre::String &group );
        static HRCFileManager &getSingleton();
        static HRCFileManager *getSingletonPtr();

    protected:
        Ogre::Resource *createImpl( const Ogre::String &name, Ogre::ResourceHandle handle
          , const Ogre::String &group, bool isManual, Ogre::ManualResourceLoader *loader
          , const Ogre::NameValuePairList *createParams );

    private:
    };
}

#endif // __QGearsHRCFileManage_H__
