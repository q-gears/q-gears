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

    typedef Ogre::SharedPtr<WalkmeshFile> WalkmeshFilePtr;
}

#endif // __QGearsWalkmeshFile_H__
