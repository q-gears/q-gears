/*
-----------------------------------------------------------------------------
The MIT License (MIT)

Copyright (c) 2013-08-24 Tobias Peters <tobias.peters@kreativeffekt.at>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
-----------------------------------------------------------------------------
*/
#include "data/QGearsFLevelFileManager.h"

template<> QGears::FLevelFileManager *Ogre::Singleton<QGears::FLevelFileManager>::msSingleton = NULL;

namespace QGears
{
    //-------------------------------------------------------------------------
    FLevelFileManager *FLevelFileManager::getSingletonPtr()
    {
        return msSingleton;
    }

    //-------------------------------------------------------------------------
    FLevelFileManager &FLevelFileManager::getSingleton()
    {
        assert( msSingleton );
        return(*msSingleton );
    }
     //-------------------------------------------------------------------------
    FLevelFileManager::FLevelFileManager()
    {
        mResourceType = FLevelFile::RESOURCE_TYPE;

        // low, because it will likely reference other resources
        mLoadOrder = 30.0f;

        // this is how we register the ResourceManager with OGRE
        Ogre::ResourceGroupManager::getSingleton()._registerResourceManager( mResourceType, this );
    }

    //-------------------------------------------------------------------------
    FLevelFileManager::~FLevelFileManager()
    {
        Ogre::ResourceGroupManager::getSingleton()._unregisterResourceManager( mResourceType );
    }

    //-------------------------------------------------------------------------
    Ogre::Resource *FLevelFileManager::createImpl( const Ogre::String &name
      , Ogre::ResourceHandle handle, const Ogre::String &group, bool isManual
      , Ogre::ManualResourceLoader *loader
      , const Ogre::NameValuePairList *createParams )
    {
        return new FLevelFile( this, name, handle, group, isManual, loader );
    }

    //-------------------------------------------------------------------------
}
