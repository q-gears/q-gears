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
#include "data/FF7ModelListFile.h"



#include "data/FF7ModelListFileSerializer.h"

namespace QGears
{
    namespace FF7
    {
        //----------------------------------------------------------------------
        const String    ModelListFile::RESOURCE_TYPE( "FF7ModelListFile" );

        //----------------------------------------------------------------------
        ModelListFile::ModelListFile( Ogre::ResourceManager *creator
                                      ,const String &name, Ogre::ResourceHandle handle
                                      ,const String &group, bool isManual
                                      ,Ogre::ManualResourceLoader *loader ) :
            Resource( creator, name, handle, group, isManual, loader )
          , m_scale( 0 )
        {
        }

        //----------------------------------------------------------------------
        ModelListFile::~ModelListFile()
        {
            unload();
        }

        //----------------------------------------------------------------------
        void
        ModelListFile::loadImpl()
        {
            ModelListFileSerializer serializer;
            Ogre::DataStreamPtr stream( openResource() );
            serializer.importModelListFile( stream, this );
        }

        //----------------------------------------------------------------------
        void
        ModelListFile::unloadImpl()
        {
            m_scale = 0;
            m_models.clear();
        }

        //----------------------------------------------------------------------
        size_t
        ModelListFile::calculateSize() const
        {
            return 0;
        }

        //----------------------------------------------------------------------
        ModelListFile::ModelList&
        ModelListFile::getModels()
        {
            return m_models;
        }

        //----------------------------------------------------------------------
        uint16
        ModelListFile::getScale() const
        {
            return m_scale;
        }

        //----------------------------------------------------------------------
        void
        ModelListFile::setScale( uint16 scale )
        {
            m_scale = scale;
        }

        //----------------------------------------------------------------------
    }
}
