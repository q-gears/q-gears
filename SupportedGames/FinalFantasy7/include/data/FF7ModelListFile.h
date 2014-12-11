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
#ifndef __FF7ModelListFile_H__
#define __FF7ModelListFile_H__

#include <OgreColourValue.h>

#include "common/QGearsResource.h"

namespace QGears
{
    namespace FF7
    {
        class ModelListFile : public Resource
        {
        public:

            ModelListFile( Ogre::ResourceManager *creator, const String &name
                          ,Ogre::ResourceHandle handle, const String &group
                          ,bool isManual = false, Ogre::ManualResourceLoader *loader = NULL );

            virtual ~ModelListFile();

            static const String RESOURCE_TYPE;

            struct AnimationDescription
            {
                String  name;
                uint16  unknown;
            };

            typedef std::vector<AnimationDescription>   AnimationList;

            enum ModelType
            {
                PLAYER  = 0
               ,NPC     = 1
               ,UNKNOWN
            };

            struct ModelDescription
            {
                String              name;
                ModelType           type;
                String              hrc_name;
                String              scale;
                Ogre::ColourValue   light_colors[10];
                AnimationList       animations;
            };

            typedef std::vector<ModelDescription>   ModelList;

            virtual uint16      getScale( void ) const;
            virtual void        setScale( uint16 scale );
            virtual ModelList&  getModels( void );

        protected:
            virtual void loadImpl( void );
            virtual void unloadImpl( void );
            virtual size_t calculateSize( void ) const;

        private:
            uint16      m_scale;
            ModelList   m_models;
        };


        typedef Ogre::SharedPtr<ModelListFile> ModelListFilePtr;
    }
}
#endif // __FF7ModelListFile_H__
