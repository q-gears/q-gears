/*
-----------------------------------------------------------------------------
Copyright (c) 07.10.2013 Tobias Peters <tobias.peters@kreativeffekt.at>

This file is part of Q-Gears

Q-Gears is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, version 2.0 (GPLv2) of the License.

Q-Gears is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.
-----------------------------------------------------------------------------
*/
#include "data/FF7ModelListFileManager.h"

namespace QGears
{
    namespace FF7
    {
        //----------------------------------------------------------------------
        template<> ModelListFileManager *Ogre::Singleton<ModelListFileManager>::msSingleton = NULL;

        //----------------------------------------------------------------------
        ModelListFileManager *ModelListFileManager::getSingletonPtr()
        {
            return msSingleton;
        }

        //----------------------------------------------------------------------
        ModelListFileManager &ModelListFileManager::getSingleton()
        {
            assert( msSingleton );
            return(*msSingleton );
        }
        //----------------------------------------------------------------------
        ModelListFileManager::ModelListFileManager()
        {
            mResourceType = ModelListFile::RESOURCE_TYPE;

            // low, because it will likely reference other resources
            mLoadOrder = 30.0f;

            // this is how we register the ResourceManager with OGRE
            Ogre::ResourceGroupManager::getSingleton()._registerResourceManager( mResourceType, this );
        }

        //----------------------------------------------------------------------
        ModelListFileManager::~ModelListFileManager()
        {
            Ogre::ResourceGroupManager::getSingleton()._unregisterResourceManager( mResourceType );
        }

        //----------------------------------------------------------------------
        Ogre::Resource *ModelListFileManager::createImpl( const Ogre::String &name
                                                         ,Ogre::ResourceHandle handle, const Ogre::String &group, bool isManual
                                                         ,Ogre::ManualResourceLoader *loader
                                                         ,const Ogre::NameValuePairList *createParams )
        {
            return new ModelListFile( this, name, handle, group, isManual, loader );
        }

        //----------------------------------------------------------------------
    }
}
