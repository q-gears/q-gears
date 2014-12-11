/*
-----------------------------------------------------------------------------
The MIT License (MIT)

Copyright (c) 2013-08-26 Tobias Peters <tobias.peters@kreativeffekt.at>

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
#ifndef __QGearsBackground2DFileManager_H__
#define __QGearsBackground2DFileManager_H__

#include <OgreResourceManager.h>

#include "QGearsPrerequisites.h"

#include "QGearsBackground2DFile.h"

namespace QGears
{
    class _QGearsExport Background2DFileManager : public Ogre::ResourceManager, public Ogre::Singleton<Background2DFileManager>
    {
    public:
        Background2DFileManager();
        virtual ~Background2DFileManager();

        static Background2DFileManager& getSingleton();
        static Background2DFileManager* getSingletonPtr();

    protected:
        Ogre::Resource *createImpl( const Ogre::String &name, Ogre::ResourceHandle handle
          , const Ogre::String &group, bool isManual, Ogre::ManualResourceLoader *loader
          , const Ogre::NameValuePairList *createParams );

    private:
    };
}

#endif // __QGearsBackground2DFileManager_H__
