/*
-----------------------------------------------------------------------------
The MIT License (MIT)

Copyright (c) 2013-09-02 Tobias Peters <tobias.peters@kreativeffekt.at>

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
#include "data/QGearsCameraMatrixFile.h"

#include <OgreLogManager.h>

#include "data/QGearsCameraMatrixFileSerializer.h"

namespace QGears
{
    //---------------------------------------------------------------------
    const String    CameraMatrixFile::RESOURCE_TYPE( "QGearsCameraMatrixFile" );

    //---------------------------------------------------------------------
    CameraMatrixFile::CameraMatrixFile( Ogre::ResourceManager *creator
                 ,const String &name, Ogre::ResourceHandle handle
                 ,const String &group, bool isManual
                 ,Ogre::ManualResourceLoader *loader ) :
        Resource( creator, name, handle, group, isManual, loader )
    {
    }

    //---------------------------------------------------------------------
    CameraMatrixFile::~CameraMatrixFile()
    {
        unload();
    }

    //---------------------------------------------------------------------
    void
    CameraMatrixFile::loadImpl()
    {
        CameraMatrixFileSerializer serializer;
        Ogre::DataStreamPtr stream( openResource() );
        serializer.importCameraMatrixFile( stream, this );
    }

    //---------------------------------------------------------------------
    void
    CameraMatrixFile::unloadImpl()
    {
        m_matrix = Ogre::Matrix3::ZERO;
        m_position = Ogre::Vector3::ZERO;
        m_offset.x = 0;
        m_offset.y = 0;
        m_focal_length = 0;
        m_count = 0;
    }

    //---------------------------------------------------------------------
    size_t
    CameraMatrixFile::calculateSize() const
    {
        return 0;
    }

    //---------------------------------------------------------------------
    Ogre::Quaternion
    CameraMatrixFile::getOrientation() const
    {
        return Ogre::Quaternion( m_matrix );
    }
    //---------------------------------------------------------------------
    const Ogre::Matrix3&
    CameraMatrixFile::getMatrix() const
    {
        return m_matrix;
    }

    //---------------------------------------------------------------------
    void
    CameraMatrixFile::setMatrix( const Ogre::Matrix3& matrix )
    {
        m_matrix = matrix;
    }

    //---------------------------------------------------------------------
    const Ogre::Vector3&
    CameraMatrixFile::getPosition() const
    {
        return m_position;
    }

    //---------------------------------------------------------------------
    void
    CameraMatrixFile::setPosition( const Ogre::Vector3& position )
    {
        m_position = position;
    }

    //---------------------------------------------------------------------
    const Pixel&
    CameraMatrixFile::getOffset() const
    {
        return m_offset;
    }

    //---------------------------------------------------------------------
    void
    CameraMatrixFile::setOffset( const Pixel& offset )
    {
        m_offset = offset;
    }

    //---------------------------------------------------------------------
    const size_t&
    CameraMatrixFile::getCount() const
    {
        return m_count;
    }

    //---------------------------------------------------------------------
    void
    CameraMatrixFile::setCount( const size_t count )
    {
        m_count = count;
    }

    //---------------------------------------------------------------------
    const Ogre::Real&
    CameraMatrixFile::getFocalLength() const
    {
        return m_focal_length;
    }

    //---------------------------------------------------------------------
    void
    CameraMatrixFile::setFocalLength( const Ogre::Real focal_length )
    {
        m_focal_length = focal_length;
    }

    //---------------------------------------------------------------------
    Ogre::Radian
    CameraMatrixFile::getFov( Ogre::Real width ) const
    {
        return 2 * Ogre::Math::ATan( width / (2 * m_focal_length ) );
    }

    //---------------------------------------------------------------------
}
