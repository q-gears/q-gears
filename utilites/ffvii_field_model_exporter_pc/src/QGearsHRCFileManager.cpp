#include "QGearsHRCFileManager.h"

namespace QGears
{
    //-------------------------------------------------------------------------
    template<> HRCFileManager *Ogre::Singleton<HRCFileManager>::msSingleton = NULL;

    //-------------------------------------------------------------------------
    HRCFileManager *HRCFileManager::getSingletonPtr()
    {
        return msSingleton;
    }

    //-------------------------------------------------------------------------
    HRCFileManager &HRCFileManager::getSingleton()
    {
        assert( msSingleton );
        return(*msSingleton );
    }
     //-------------------------------------------------------------------------
    HRCFileManager::HRCFileManager()
    {
        mResourceType = HRCFile::RESOURCE_TYPE;

        // low, because it will likely reference other resources
        mLoadOrder = 30.0f;

        // this is how we register the ResourceManager with OGRE
        Ogre::ResourceGroupManager::getSingleton()._registerResourceManager( mResourceType, this );
    }

    //-------------------------------------------------------------------------
    HRCFileManager::~HRCFileManager()
    {
        Ogre::ResourceGroupManager::getSingleton()._unregisterResourceManager( mResourceType );
    }

    //-------------------------------------------------------------------------
    HRCFilePtr HRCFileManager::load( const Ogre::String &name, const Ogre::String &group )
    {
        HRCFilePtr file( getByName( name ) );

        if ( file.isNull() )
            file = create( name, group );

        file->load();
        return file;
    }

    //-------------------------------------------------------------------------
    Ogre::Resource *HRCFileManager::createImpl( const Ogre::String &name
      , Ogre::ResourceHandle handle, const Ogre::String &group, bool isManual
      , Ogre::ManualResourceLoader *loader
      , const Ogre::NameValuePairList *createParams )
    {
        return new HRCFile( this, name, handle, group, isManual, loader );
    }

    //-------------------------------------------------------------------------
}
