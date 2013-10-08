#include "%SubPath%/%NameSpace%%ClassName%Manager.%CppHeaderSuffix%"

namespace %NameSpace%
{
    //--------------------------------------------------------------------------
    template<> %ClassName%Manager *Ogre::Singleton<%ClassName%Manager>::msSingleton = NULL;

    //--------------------------------------------------------------------------
    %ClassName%Manager *%ClassName%Manager::getSingletonPtr()
    {
        return msSingleton;
    }

    //--------------------------------------------------------------------------
    %ClassName%Manager &%ClassName%Manager::getSingleton()
    {
        assert( msSingleton );
        return(*msSingleton );
    }
    //--------------------------------------------------------------------------
    %ClassName%Manager::%ClassName%Manager()
    {
        mResourceType = %ClassName%::RESOURCE_TYPE;

        // low, because it will likely reference other resources
        mLoadOrder = 30.0f;

        // this is how we register the ResourceManager with OGRE
        Ogre::ResourceGroupManager::getSingleton()._registerResourceManager( mResourceType, this );
    }

    //--------------------------------------------------------------------------
    %ClassName%Manager::~%ClassName%Manager()
    {
        Ogre::ResourceGroupManager::getSingleton()._unregisterResourceManager( mResourceType );
    }

    //--------------------------------------------------------------------------
    Ogre::Resource *%ClassName%Manager::createImpl( const Ogre::String &name
      , Ogre::ResourceHandle handle, const Ogre::String &group, bool isManual
      , Ogre::ManualResourceLoader *loader
      , const Ogre::NameValuePairList *createParams )
    {
        return new %ClassName%( this, name, handle, group, isManual, loader );
    }

    //--------------------------------------------------------------------------
}
