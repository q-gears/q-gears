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
#ifndef __QGearsWalkmeshFile_H__
#define __QGearsWalkmeshFile_H__

#include "common/QGearsResource.h"
#include "core/Walkmesh.h"

namespace QGears
{
    class WalkmeshFile : public Resource
    {
    public:

        WalkmeshFile( Ogre::ResourceManager *creator, const String &name
              ,Ogre::ResourceHandle handle, const String &group
              ,bool isManual = false, Ogre::ManualResourceLoader *loader = NULL );

        virtual ~WalkmeshFile();

        static const String RESOURCE_TYPE;

        typedef ::WalkmeshTriangle      Triangle;
        typedef std::vector<Triangle>   TriangleList;

        virtual TriangleList& getTriangles( void );

    protected:
        virtual void loadImpl( void );
        virtual void unloadImpl( void );
        virtual size_t calculateSize( void ) const;

    private:
        TriangleList    m_triangles;
    };

    //-------------------------------------------------------------------------
    class WalkmeshFilePtr : public Ogre::SharedPtr<WalkmeshFile>
    {
    public:
        WalkmeshFilePtr() : Ogre::SharedPtr<WalkmeshFile>() {}
        explicit WalkmeshFilePtr( WalkmeshFile *rep ) : Ogre::SharedPtr<WalkmeshFile>(rep) {}
        WalkmeshFilePtr( const WalkmeshFilePtr &r ) : Ogre::SharedPtr<WalkmeshFile>(r) {}
        WalkmeshFilePtr( const Ogre::ResourcePtr &r ) : Ogre::SharedPtr<WalkmeshFile>()
        {
            if( r.isNull() )
                return;
            // lock & copy other mutex pointer
            OGRE_LOCK_MUTEX(*r.OGRE_AUTO_MUTEX_NAME)
            OGRE_COPY_AUTO_SHARED_MUTEX(r.OGRE_AUTO_MUTEX_NAME)
            pRep = static_cast<WalkmeshFile*>(r.getPointer());
            pUseCount = r.useCountPointer();
            useFreeMethod = r.freeMethod();
            if (pUseCount)
            {
                ++(*pUseCount);
            }
        }

        /// Operator used to convert a ResourcePtr to a WalkmeshFilePtr
        WalkmeshFilePtr& operator=( const Ogre::ResourcePtr& r )
        {
            if(pRep == static_cast<WalkmeshFile*>(r.getPointer()))
                return *this;
            release();
            if( r.isNull() )
                return *this; // resource ptr is null, so the call to release above has done all we need to do.
            // lock & copy other mutex pointer
            OGRE_LOCK_MUTEX(*r.OGRE_AUTO_MUTEX_NAME)
            OGRE_COPY_AUTO_SHARED_MUTEX(r.OGRE_AUTO_MUTEX_NAME)
            pRep = static_cast<WalkmeshFile*>(r.getPointer());
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

#endif // __QGearsWalkmeshFile_H__
