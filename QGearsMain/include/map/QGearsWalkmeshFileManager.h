/*
-----------------------------------------------------------------------------
Copyright (c) 2013-09-05 Tobias Peters <tobias.peters@kreativeffekt.at>

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
#ifndef __QGearsWalkmeshFileManager_H__
#define __QGearsWalkmeshFileManager_H__

#include <OgreResourceManager.h>

#include "QGearsPrerequisites.h"

#include "QGearsWalkmeshFile.h"

namespace QGears
{
    class _QGearsExport WalkmeshFileManager : public Ogre::ResourceManager, public Ogre::Singleton<WalkmeshFileManager>
    {
    public:
        WalkmeshFileManager();
        virtual ~WalkmeshFileManager();

        static WalkmeshFileManager& getSingleton();
        static WalkmeshFileManager* getSingletonPtr();

    protected:
        Ogre::Resource *createImpl( const Ogre::String &name, Ogre::ResourceHandle handle
          , const Ogre::String &group, bool isManual, Ogre::ManualResourceLoader *loader
          , const Ogre::NameValuePairList *createParams );

    private:
    };
}

#endif // __QGearsWalkmeshFileManager_H__
