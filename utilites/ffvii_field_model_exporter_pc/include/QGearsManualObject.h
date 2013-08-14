/*
-----------------------------------------------------------------------------
The MIT License (MIT)

Copyright (c) 2013-08-14 Tobias Peters <tobias.peters@kreativeffekt.at>

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
#ifndef __QGearsManualObject_H__
#define __QGearsManualObject_H__

#include <OgreColourValue.h>
#include <OgreMesh.h>
#include <OgreSubMesh.h>
#include <OgreVector2.h>
#include <OgreVector3.h>

#include "common/TypeDefine.h"

namespace QGears
{
    class ManualObject
    {
        public:
            explicit ManualObject( Ogre::Mesh *mesh );
            virtual ~ManualObject();

            enum BufferBinding
            {
                BB_POSITION
              , BB_NORMAL
              , BB_COLOUR
              , BB_TEXTURE
              , BINDING_COUNT
            };

            virtual void begin( const String &name
                               ,const String &material_name
                               ,size_t vertex_count );

            virtual void position( const Ogre::Vector3 &position );

            virtual void end();

        protected:
            virtual void createBuffer( const BufferBinding binding, Ogre::VertexElementType type, Ogre::VertexElementSemantic semantic);
            virtual void createPositionBuffer();
            virtual void createNormalBuffer();
            virtual void createColourBuffer();
            virtual void createTextureCoordinateBuffer();
            virtual void createIndexBuffer();

        private:
            Ogre::Mesh     *m_mesh;
            Ogre::SubMesh  *m_section;

            typedef Ogre::HardwareVertexBufferSharedPtr Buffer;
            Buffer          m_buffer[BINDING_COUNT];
    };
}

#endif // __QGearsManualObject_H__
