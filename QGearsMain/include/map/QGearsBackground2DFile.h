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
#ifndef __QGearsBackground2DFile_H__
#define __QGearsBackground2DFile_H__

#include <OgreQuaternion.h>
#include <OgreVector3.h>
#include <OgreVector4.h>

#include "common/QGearsResource.h"

#include "QGearsTile.h"

namespace QGears
{
    class Background2DFile : public Resource
    {
    public:

        Background2DFile( Ogre::ResourceManager *creator, const String &name
              ,Ogre::ResourceHandle handle, const String &group
              ,bool isManual = false, Ogre::ManualResourceLoader *loader = NULL );

        virtual ~Background2DFile();

        static const String RESOURCE_TYPE;

        typedef std::vector< Tile >     TileList;

        virtual void   setTextureName( const String &texture_name );
        virtual String getTextureName( void ) const;

        virtual void            setRange( const Ogre::Vector4& range );
        virtual Ogre::Vector4   getRange( void ) const;

        virtual void            setClip( const Ogre::Vector2& clip );
        virtual Ogre::Vector2   getClip( void ) const;

        virtual void            setPosition( const Ogre::Vector3 &position );
        virtual Ogre::Vector3   getPosition( void ) const;

        virtual void                setOrientation( const Ogre::Quaternion &orientation );
        virtual Ogre::Quaternion    getOrientation( void ) const;

        virtual void            setFov( const Ogre::Radian &fov );
        virtual Ogre::Radian    getFov( void ) const;

        virtual TileList& getTiles( void );

    protected:
        virtual void loadImpl( void );
        virtual void unloadImpl( void );
        virtual size_t calculateSize( void ) const;

    private:
        String              m_texture_name;
        Ogre::Vector2       m_clip;
        Ogre::Vector4       m_range;
        Ogre::Vector3       m_position;
        Ogre::Quaternion    m_orientation;
        Ogre::Radian        m_fov;
        TileList            m_tiles;
    };

    typedef Ogre::SharedPtr<Background2DFile> Background2DFilePtr;
}

#endif // __QGearsBackground2DFile_H__
