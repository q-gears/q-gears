/*
-----------------------------------------------------------------------------
Copyright (c) 15.1.2013 Tobias Peters <tobias.peters@kreativeffekt.at>

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
#ifndef __QGearsAFile_H__
#define __QGearsAFile_H__

#include <OgreSkeleton.h>
#include <OgreVector3.h>

#include "common/TypeDefine.h"
#include "common/QGearsResource.h"

namespace QGears
{
    class AFile : public Resource
    {
    public:
        AFile( Ogre::ResourceManager *creator, const String &name
              ,Ogre::ResourceHandle handle, const String &group
              ,bool isManual = false, Ogre::ManualResourceLoader *loader = NULL );

        virtual ~AFile();

        static const Ogre::Real FRAME_DURATION;
        static const String     RESOURCE_TYPE;

        virtual void addTo( Ogre::SkeletonPtr skeleton, const String &name ) const;

        typedef std::vector<Ogre::Vector3>  BoneRotationList;

        struct Frame
        {
            Ogre::Vector3       root_rotation;
            Ogre::Vector3       root_translation;
            BoneRotationList    bone_rotations;
        };

        typedef std::vector<Frame>  FrameList;
        virtual FrameList&  getFrames() { return m_frames; }

        virtual void    setBoneCount( const uint32 bone_count );

    protected:
        virtual void loadImpl();
        virtual void unloadImpl();
        virtual size_t calculateSize() const;

        virtual void    setFrameRotation( Ogre::TransformKeyFrame *key_frame
                                         ,const Ogre::Vector3 &rotation ) const;

    private:
        uint32      m_bone_count;
        FrameList   m_frames;
    };

    //-------------------------------------------------------------------------
    class AFilePtr : public Ogre::SharedPtr<AFile>
    {
    public:
        AFilePtr() : Ogre::SharedPtr<AFile>() {}
        explicit AFilePtr( AFile *rep ) : Ogre::SharedPtr<AFile>(rep) {}
        AFilePtr( const AFilePtr &r ) : Ogre::SharedPtr<AFile>(r) {}
        AFilePtr( const Ogre::ResourcePtr &r ) : Ogre::SharedPtr<AFile>()
        {
            if( r.isNull() )
                return;
            // lock & copy other mutex pointer
            OGRE_LOCK_MUTEX(*r.OGRE_AUTO_MUTEX_NAME)
            OGRE_COPY_AUTO_SHARED_MUTEX(r.OGRE_AUTO_MUTEX_NAME)
            pRep = static_cast<AFile*>(r.getPointer());
            pUseCount = r.useCountPointer();
            useFreeMethod = r.freeMethod();
            if (pUseCount)
            {
                ++(*pUseCount);
            }
        }

        /// Operator used to convert a ResourcePtr to a AFilePtr
        AFilePtr& operator=( const Ogre::ResourcePtr& r )
        {
            if(pRep == static_cast<AFile*>(r.getPointer()))
                return *this;
            release();
            if( r.isNull() )
                return *this; // resource ptr is null, so the call to release above has done all we need to do.
            // lock & copy other mutex pointer
            OGRE_LOCK_MUTEX(*r.OGRE_AUTO_MUTEX_NAME)
            OGRE_COPY_AUTO_SHARED_MUTEX(r.OGRE_AUTO_MUTEX_NAME)
            pRep = static_cast<AFile*>(r.getPointer());
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

#endif // __QGearsAFile_H__
