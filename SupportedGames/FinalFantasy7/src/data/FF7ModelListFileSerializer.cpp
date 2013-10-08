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
#include "data/FF7ModelListFileSerializer.h"

#include <OgreLogManager.h>
#include <OgreException.h>

namespace QGears
{
    namespace FF7
    {
        //----------------------------------------------------------------------
        ModelListFileSerializer::ModelListFileSerializer() :
            Serializer()
        {
        }

        //----------------------------------------------------------------------
        ModelListFileSerializer::~ModelListFileSerializer()
        {
        }

        //----------------------------------------------------------------------
        template<typename ValueType>
        void
        ModelListFileSerializer::readVector( Ogre::DataStreamPtr &stream
                                            ,std::vector<ValueType> &pDest
                                            ,size_t count )
        {
            pDest.clear();
            pDest.reserve( count );
            for( size_t i( count ); i--; )
            {
                ValueType in_tmp;
                readObject( stream, in_tmp );
                pDest.push_back( in_tmp );
            }
        }

        //----------------------------------------------------------------------
        void
        ModelListFileSerializer::importModelListFile( Ogre::DataStreamPtr &stream
                                                     ,ModelListFile *pDest )
        {
            stream->skip( 2 ); // uint16 unused

            uint16 model_count;
            readShort( stream, model_count );

            uint16 model_scale;
            readShort( stream, model_scale );
            pDest->setScale( model_scale );

            readVector( stream, pDest->getModels(), model_count );
        }

        //----------------------------------------------------------------------
        void
        ModelListFileSerializer::readObject( Ogre::DataStreamPtr &stream
                                            ,ModelListFileSerializer::ModelDescription &pDest )
        {
            uint16 name_length;
            readShort( stream, name_length );
            pDest.name = readString( stream, name_length );

            uint16 type;
            readShort( stream, type );
            pDest.type = ModelListFile::UNKNOWN;
            if ( type == ModelListFile::PLAYER )
            {
                pDest.type = ModelListFile::PLAYER;
            }
            else if ( type == ModelListFile::NPC )
            {
                pDest.type = ModelListFile::NPC;
            }

            pDest.hrc_name = readString( stream, HRC_NAME_LENGTH );
            pDest.scale = readString( stream, SCALE_LENGTH );

            uint16 animation_count;
            readShort( stream, animation_count );

            stream->skip( 3 * (3 + 6) + 3 ); // 3 *( 3 uint8 + 3 uint16 ) + 3 uint8 light colors

            readVector( stream, pDest.animations, animation_count );
        }

        //----------------------------------------------------------------------
        void
        ModelListFileSerializer::readObject( Ogre::DataStreamPtr &stream
                                            ,ModelListFileSerializer::AnimationDescription &pDest )
        {
            uint16 name_length;
            readShort( stream, name_length );
            pDest.name = readString( stream, name_length );

            readShort( stream, pDest.unknown );
        }

        //----------------------------------------------------------------------
    }
}
