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

#ifndef __FFVIIWalkmeshFileSerializer_H__
#define __FFVIIWalkmeshFileSerializer_H__

#include "common/TypeDefine.h"
#include "data/QGearsSerializer.h"
#include "map/QGearsWalkmeshFile.h"

namespace FFVII
{
    class WalkmeshFileSerializer : public Serializer
    {
    public:
                        WalkmeshFileSerializer();
        virtual        ~WalkmeshFileSerializer();

        virtual void    importWalkmeshFile( Ogre::DataStreamPtr &stream, WalkmeshFile *pDest );

        typedef WalkmeshFile::Triangle      WalkmeshTriangle;
        typedef WalkmeshFile::TriangleList  WalkmeshTriangleList;

        enum {
            VERTEX_PADDING_COUNT    = 1
           ,VERTEX_COMPONENT_COUNT  = 3 + VERTEX_PADDING_COUNT
           ,ACCESS_COMPONENT_COUNT  = 3
        };

        struct Triangle
        {
            Ogre::Vector3 a, b, c;
        };

        struct Access
        {
            sint16 a, b, c;
        };

        typedef std::vector<Triangle>   TriangleList;
        typedef std::vector<Access>     AccessList;

    protected:
        virtual void    readObject( Ogre::DataStreamPtr &stream, Triangle &pDest );
        virtual void    readObject( Ogre::DataStreamPtr &stream, Ogre::Vector3 &pDest );
        virtual void    readObject( Ogre::DataStreamPtr &stream, Access &pDest );
        using Serializer::readObject;

        template<typename ValueType>
                void    readVector( Ogre::DataStreamPtr &stream
                                   ,std::vector<ValueType> &pDest
                                   ,size_t count );

    private:
    };
}

#endif // __FFVIIWalkmeshFileSerializer_H__
