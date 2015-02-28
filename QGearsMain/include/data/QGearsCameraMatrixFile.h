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
#ifndef __QGearsCameraMatrixFile_H__
#define __QGearsCameraMatrixFile_H__

#include <OgreMatrix3.h>

#include "common/QGearsResource.h"

namespace QGears
{
    class CameraMatrixFile : public Resource
    {
    public:

        CameraMatrixFile( Ogre::ResourceManager *creator, const String &name
              ,Ogre::ResourceHandle handle, const String &group
              ,bool isManual = false, Ogre::ManualResourceLoader *loader = NULL );

        virtual ~CameraMatrixFile();

        static const String RESOURCE_TYPE;

        const Ogre::Matrix3&    getMatrix() const;
        void                    setMatrix( const Ogre::Matrix3& matrix );

        const Ogre::Vector3&    getPosition() const;
        void                    setPosition( const Ogre::Vector3& position );

        const Pixel&            getOffset() const;
        void                    setOffset( const Pixel& offset );

        const size_t&           getCount() const;
        void                    setCount( const size_t count );

        const Ogre::Real&       getFocalLength() const;
        void                    setFocalLength( const Ogre::Real );

        Ogre::Quaternion        getOrientation() const;
        Ogre::Radian            getFov( Ogre::Real width ) const;

    protected:
        virtual void loadImpl( void );
        virtual void unloadImpl( void );
        virtual size_t calculateSize( void ) const;

    private:
        Ogre::Matrix3   m_matrix;
        Ogre::Vector3   m_position;
        Pixel           m_offset;
        Ogre::Real      m_focal_length;
        size_t          m_count;
    };

    typedef Ogre::SharedPtr<CameraMatrixFile> CameraMatrixFilePtr;
}

#endif // __QGearsCameraMatrixFile_H__
