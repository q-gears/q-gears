#ifndef __QGears%ClassName%Manager_H__
#define __QGears%ClassName%Manager_H__

#include <OgreResourceManager.h>

#include "QGearsPrerequisites.h"

#include "QGears%ClassName%.h"

namespace QGears
{
    class _QGearsExport %ClassName%Manager : public Ogre::ResourceManager, public Ogre::Singleton<%ClassName%Manager>
    {
    public:
        %ClassName%Manager();
        virtual ~%ClassName%Manager();

        static %ClassName%Manager &getSingleton();
        static %ClassName%Manager *getSingletonPtr();

    protected:
        Ogre::Resource *createImpl( const Ogre::String &name, Ogre::ResourceHandle handle
          , const Ogre::String &group, bool isManual, Ogre::ManualResourceLoader *loader
          , const Ogre::NameValuePairList *createParams );

    private:
    };
}

#endif // __QGears%ClassName%Manager_H__
