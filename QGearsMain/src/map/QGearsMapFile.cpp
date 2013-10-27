/*
-----------------------------------------------------------------------------
Copyright (c) 27.10.2013 Tobias Peters <tobias.peters@kreativeffekt.at>

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
#include "map/QGearsMapFile.h"

#include "map/QGearsMapFileXMLSerializer.h"

namespace QGears
{
    //--------------------------------------------------------------------------
    const String    MapFile::RESOURCE_TYPE( "QGearsMapFile" );
    
    //--------------------------------------------------------------------------
    MapFile::MapFile( Ogre::ResourceManager *creator
                      ,const String &name, Ogre::ResourceHandle handle
                      ,const String &group, bool isManual
                      ,Ogre::ManualResourceLoader *loader ) :
        Resource( creator, name, handle, group, isManual, loader )
    {
    }
    
    //--------------------------------------------------------------------------
    MapFile::~MapFile()
    {
        unload();
    }

    //--------------------------------------------------------------------------
    void
    MapFile::loadImpl()
    {
        MapFileXMLSerializer serializer;
        Ogre::DataStreamPtr stream( openResource() );
        serializer.importMapFile( stream, this );
    }
    
    //--------------------------------------------------------------------------
    void
    MapFile::unloadImpl()
    {
        m_script_name.clear();
        m_background2d_name.clear();
        m_walkmesh_name.clear();
        m_forward_direction = 0;
    }
    
    //--------------------------------------------------------------------------
    size_t
    MapFile::calculateSize() const
    {
        return m_script_name.size()
             + m_background2d_name.size()
             + m_walkmesh_name.size()
             + sizeof( m_forward_direction );
    }
    
    //--------------------------------------------------------------------------
    const String&
    MapFile::getScriptName() const
    {
        return m_script_name;
    }

    //--------------------------------------------------------------------------
    const String&
    MapFile::getBackground2dName() const
    {
        return m_background2d_name;
    }

    //--------------------------------------------------------------------------
    const String&
    MapFile::getWalkmeshName() const
    {
        return m_walkmesh_name;
    }

    //--------------------------------------------------------------------------
    Ogre::Real
    MapFile::getForwardDirection() const
    {
        return m_forward_direction;
    }

    //--------------------------------------------------------------------------
    void MapFile::setScriptName( const String &script_name )
    {
    }

    //--------------------------------------------------------------------------
    void MapFile::getBackground2dName( const String &background2d_name )
    {
    }

    //--------------------------------------------------------------------------
    void
    MapFile::getWalkmeshName( const String &walkmesh_name )
    {
    }

    //--------------------------------------------------------------------------
    void MapFile::getForwardDirection( const Ogre::Real &forward_direction )
    {
    }

    //--------------------------------------------------------------------------
}

