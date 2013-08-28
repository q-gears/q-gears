/*
-----------------------------------------------------------------------------
The MIT License (MIT)

Copyright (c) 2013-08-26 Tobias Peters <tobias.peters@kreativeffekt.at>

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
#include "map/QGearsBackground2DFile.h"

#include <OgreLogManager.h>
#include <OgreResourceGroupManager.h>

#include "map/QGearsBackground2DFileXMLSerializer.h"

namespace QGears
{
    //---------------------------------------------------------------------
    const String    Background2DFile::RESOURCE_TYPE( "QGearsBackground2DFile" );

    //---------------------------------------------------------------------
    Background2DFile::Background2DFile( Ogre::ResourceManager *creator
                 ,const String &name, Ogre::ResourceHandle handle
                 ,const String &group, bool isManual
                 ,Ogre::ManualResourceLoader *loader ) :
        Resource( creator, name, handle, group, isManual, loader )
    {
    }

    //---------------------------------------------------------------------
    Background2DFile::~Background2DFile()
    {
        unload();
    }

    //---------------------------------------------------------------------
    void
    Background2DFile::loadImpl()
    {
        Background2DFileXMLSerializer serializer;
        Ogre::DataStreamPtr stream( openResource() );
        serializer.importBackground2DFile( stream, this );
    }

    //---------------------------------------------------------------------
    void
    Background2DFile::unloadImpl()
    {
        m_texture_name.clear();
        m_range = 0;
        m_position = Ogre::Vector3::ZERO;
        m_orientation = Ogre::Quaternion::IDENTITY;
        m_fov = 0;
        m_tiles.clear();
    }

    //---------------------------------------------------------------------
    size_t
    Background2DFile::calculateSize() const
    {
        return 0;
    }

    //---------------------------------------------------------------------
    void
    Background2DFile::setTextureName( const String &texture_name )
    {
        m_texture_name = texture_name;
    }

    //---------------------------------------------------------------------
    String
    Background2DFile::getTextureName() const
    {
        return m_texture_name;
    }

    //---------------------------------------------------------------------
    void
    Background2DFile::setRange( const Ogre::Vector4 &range )
    {
        m_range = range;
    }

    //---------------------------------------------------------------------
    Ogre::Vector4
    Background2DFile::getRange() const
    {
        return m_range;
    }

    //---------------------------------------------------------------------
    void
    Background2DFile::setPosition( const Ogre::Vector3 &position )
    {
        m_position = position;
    }

    //---------------------------------------------------------------------
    Ogre::Vector3
    Background2DFile::getPosition() const
    {
        return m_position;
    }

    //---------------------------------------------------------------------
    void
    Background2DFile::setOrientation( const Ogre::Quaternion &orientation )
    {
        m_orientation = orientation;
    }

    //---------------------------------------------------------------------
    Ogre::Quaternion
    Background2DFile::getOrientation() const
    {
        return m_orientation;
    }

    //---------------------------------------------------------------------
    void
    Background2DFile::setFov( const Ogre::Radian &fov )
    {
        m_fov = fov;
    }

    //---------------------------------------------------------------------
    Ogre::Radian
    Background2DFile::getFov() const
    {
        return m_fov;
    }

    //---------------------------------------------------------------------
    Background2DFile::TileList&
    Background2DFile::getTiles( void )
    {
        return m_tiles;
    }

    //---------------------------------------------------------------------
}
