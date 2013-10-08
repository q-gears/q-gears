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
#ifndef __FF7ModelListFileSerializer_H__
#define __FF7ModelListFileSerializer_H__

#include "common/TypeDefine.h"
#include "data/QGearsSerializer.h"

#include "FF7ModelListFile.h"

namespace QGears
{
    namespace FF7
    {
        class ModelListFileSerializer : public Serializer
        {
        public:
            ModelListFileSerializer();
            virtual        ~ModelListFileSerializer();

            virtual void    importModelListFile( Ogre::DataStreamPtr &stream, ModelListFile *pDest );

            typedef ModelListFile::AnimationDescription AnimationDescription;
            typedef ModelListFile::ModelDescription     ModelDescription;

            enum {
                HRC_NAME_LENGTH = 8
               ,SCALE_LENGTH    = 4
            };

        protected:
            virtual void    readObject( Ogre::DataStreamPtr &stream, AnimationDescription &pDest );
            virtual void    readObject( Ogre::DataStreamPtr &stream, ModelDescription &pDest );
            using Serializer::readObject;

            template<typename ValueType>
                    void    readVector( Ogre::DataStreamPtr &stream
                                       ,std::vector<ValueType> &pDest
                                       ,size_t count );

        private:
        };
    }
}

#endif // __FF7ModelListFileSerializer_H__
