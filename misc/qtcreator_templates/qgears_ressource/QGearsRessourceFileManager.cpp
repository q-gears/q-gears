#include "%SubPath%/%NameSpace%%ClassNameManager%.%CppHeaderSuffix%"

namespace %NameSpace%
{
    //--------------------------------------------------------------------------
    template<> %ClassNameManager% *Ogre::Singleton<%ClassNameManager%>::msSingleton = NULL;

    //--------------------------------------------------------------------------
    %ClassNameManager% *%ClassNameManager%::getSingletonPtr()
    {
        return msSingleton;
    }

    //--------------------------------------------------------------------------
    %ClassNameManager% &%ClassNameManager%::getSingleton()
    {
        assert( msSingleton );
        return(*msSingleton );
    }
    //--------------------------------------------------------------------------
    %ClassNameManager%::%ClassNameManager%()
    {
        mResourceType = %ClassName%::RESOURCE_TYPE;

        // low, because it will likely reference other resources
        mLoadOrder = 30.0f;

        // this is how we register the ResourceManager with OGRE
        Ogre::ResourceGroupManager::getSingleton()._registerResourceManager( mResourceType, this );
    }

    //--------------------------------------------------------------------------
    %ClassNameManager%::~%ClassNameManager%()
    {
        Ogre::ResourceGroupManager::getSingleton()._unregisterResourceManager( mResourceType );
    }

    //--------------------------------------------------------------------------
    Ogre::Resource *%ClassNameManager%::createImpl( const Ogre::String &name
      , Ogre::ResourceHandle handle, const Ogre::String &group, bool isManual
      , Ogre::ManualResourceLoader *loader
      , const Ogre::NameValuePairList *createParams )
    {
        return new %ClassName%( this, name, handle, group, isManual, loader );
    }

    //--------------------------------------------------------------------------
}
