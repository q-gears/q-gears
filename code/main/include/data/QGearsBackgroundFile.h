/*
-----------------------------------------------------------------------------
The MIT License (MIT)

Copyright (c) 2013-08-11 Tobias Peters <tobias.peters@kreativeffekt.at>

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
#ifndef __QGearsBackgroundFile_H__
#define __QGearsBackgroundFile_H__

#include <OgreAxisAlignedBox.h>
#include <OgreColourValue.h>
#include <OgreMesh.h>
#include <OgreResource.h>
#include <OgreVector2.h>
#include <OgreVector3.h>

#include "common/TypeDefine.h"

namespace QGears
{
    class BackgroundFile : public Ogre::Resource
    {
    public:

        BackgroundFile( Ogre::ResourceManager *creator, const String &name
              ,Ogre::ResourceHandle handle, const String &group
              ,bool isManual = false, Ogre::ManualResourceLoader *loader = NULL );

        virtual ~BackgroundFile();

        static const String RESOURCE_TYPE;

    protected:
        virtual void loadImpl();
        virtual void unloadImpl();
        virtual size_t calculateSize() const;

    private:
    };

    //-------------------------------------------------------------------------
    class BackgroundFilePtr : public Ogre::SharedPtr<BackgroundFile>
    {
    public:
        BackgroundFilePtr() : Ogre::SharedPtr<BackgroundFile>() {}
        explicit BackgroundFilePtr( BackgroundFile *rep ) : Ogre::SharedPtr<BackgroundFile>(rep) {}
        BackgroundFilePtr( const BackgroundFilePtr &r ) : Ogre::SharedPtr<BackgroundFile>(r) {}
        BackgroundFilePtr( const Ogre::ResourcePtr &r ) : Ogre::SharedPtr<BackgroundFile>()
        {
            if( r.isNull() )
                return;
            // lock & copy other mutex pointer
            OGRE_LOCK_MUTEX(*r.OGRE_AUTO_MUTEX_NAME)
            OGRE_COPY_AUTO_SHARED_MUTEX(r.OGRE_AUTO_MUTEX_NAME)
            pRep = static_cast<BackgroundFile*>(r.getPointer());
            pUseCount = r.useCountPointer();
            useFreeMethod = r.freeMethod();
            if (pUseCount)
            {
                ++(*pUseCount);
            }
        }

        /// Operator used to convert a ResourcePtr to a BackgroundFilePtr
        BackgroundFilePtr& operator=( const Ogre::ResourcePtr& r )
        {
            if(pRep == static_cast<BackgroundFile*>(r.getPointer()))
                return *this;
            release();
            if( r.isNull() )
                return *this; // resource ptr is null, so the call to release above has done all we need to do.
            // lock & copy other mutex pointer
            OGRE_LOCK_MUTEX(*r.OGRE_AUTO_MUTEX_NAME)
            OGRE_COPY_AUTO_SHARED_MUTEX(r.OGRE_AUTO_MUTEX_NAME)
            pRep = static_cast<BackgroundFile*>(r.getPointer());
            pUseCount = r.useCountPointer();
            useFreeMethod = r.freeMethod();
            if (pUseCount)
            {
                ++(*pUseCount);
            }
            return *this;
        }
    };
}

#endif // __QGearsBackgroundFile_H__
