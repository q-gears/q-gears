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
#ifndef __QGearsHRCFile_H__
#define __QGearsHRCFile_H__

#include <OgreResource.h>
#include <OgreSkeleton.h>

#include "common/TypeDefine.h"

namespace QGears
{
    class HRCFile : public Ogre::Resource
    {
    public:

        HRCFile( Ogre::ResourceManager *creator, const Ogre::String &name
                ,Ogre::ResourceHandle handle, const Ogre::String &group
                ,bool isManual = false, Ogre::ManualResourceLoader *loader = NULL );

        virtual ~HRCFile();

        virtual Ogre::SkeletonPtr   createSkeleton( const String &name
                                                   ,const String &group ) const;

        typedef std::vector<String> RSDNameList;

        struct Bone
        {
            String      name;
            String      parent;
            Ogre::Real  length;
            RSDNameList rsd_names;
        };

        typedef std::vector<Bone> BoneList;

        virtual void        setName ( const String& name );
        virtual String&     getName ( void ) { return m_name; }
        virtual BoneList&   getBones( void ) { return m_bones; }

        static const Ogre::String RESOURCE_TYPE;

    protected:
        virtual void loadImpl();
        virtual void unloadImpl();
        virtual size_t calculateSize() const;
        virtual size_t calculateSize( const Bone &bone ) const;

        static const String ROOT_BONE_NAME;
        static const Ogre::Quaternion ROOT_ORIENTATION;
        static Ogre::Quaternion createRootOrientation();

    private:
        String      m_name;
        BoneList    m_bones;
    };

    //-------------------------------------------------------------------------
    class HRCFilePtr : public Ogre::SharedPtr<HRCFile>
    {
    public:
        HRCFilePtr() : Ogre::SharedPtr<HRCFile>() {}
        explicit HRCFilePtr(HRCFile *rep) : Ogre::SharedPtr<HRCFile>(rep) {}
        HRCFilePtr(const HRCFilePtr &r) : Ogre::SharedPtr<HRCFile>(r) {}
        HRCFilePtr(const Ogre::ResourcePtr &r) : Ogre::SharedPtr<HRCFile>()
        {
            if( r.isNull() )
                return;
            // lock & copy other mutex pointer
            OGRE_LOCK_MUTEX(*r.OGRE_AUTO_MUTEX_NAME)
            OGRE_COPY_AUTO_SHARED_MUTEX(r.OGRE_AUTO_MUTEX_NAME)
            pRep = static_cast<HRCFile*>(r.getPointer());
            pUseCount = r.useCountPointer();
            useFreeMethod = r.freeMethod();
            if (pUseCount)
            {
                ++(*pUseCount);
            }
        }

        /// Operator used to convert a ResourcePtr to a HRCFilePtr
        HRCFilePtr& operator=(const Ogre::ResourcePtr& r)
        {
            if(pRep == static_cast<HRCFile*>(r.getPointer()))
                return *this;
            release();
            if( r.isNull() )
                return *this; // resource ptr is null, so the call to release above has done all we need to do.
            // lock & copy other mutex pointer
            OGRE_LOCK_MUTEX(*r.OGRE_AUTO_MUTEX_NAME)
            OGRE_COPY_AUTO_SHARED_MUTEX(r.OGRE_AUTO_MUTEX_NAME)
            pRep = static_cast<HRCFile*>(r.getPointer());
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

#endif // __QGearsHRCFile_H__
