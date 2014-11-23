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
#ifndef __QGearsResource_H__
#define __QGearsResource_H__

#include <OgreDataStream.h>
#include <OgreResource.h>
#include <OgreResourceGroupManager.h>

#include "common/TypeDefine.h"
#include "QGearsPrerequisites.h"

namespace QGears
{
    class _QGearsExport Resource : public Ogre::Resource
    {
    public:
        Resource(Ogre::ResourceManager *creator
            , const String &name, Ogre::ResourceHandle handle
            , const String &group, bool isManual
            , Ogre::ManualResourceLoader *loader) :
            Ogre::Resource(creator, name, handle, group, isManual, loader)
        {
        }

        virtual ~Resource() = default;

    protected:
        Ogre::DataStreamPtr openResource()
        {
            return Ogre::ResourceGroupManager::getSingleton().openResource(mName, mGroup, true, this);
        }

    private:
    };
}

#endif // __QGearsResource_H__
