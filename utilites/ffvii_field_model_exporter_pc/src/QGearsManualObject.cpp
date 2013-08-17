/*
-----------------------------------------------------------------------------
The MIT License (MIT)

Copyright (c) 2013-08-17 Tobias Peters <tobias.peters@kreativeffekt.at>

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
#include "QGearsManualObject.h"

#include <cstring>

#include <OgreException.h>
#include <OgreHardwareBufferManager.h>
#include <OgreRoot.h>

namespace QGears
{
    //-------------------------------------------------------------------------
    ManualObject::ManualObject( Ogre::Mesh *mesh ) :
        m_mesh( mesh )
       ,m_section( NULL )
       ,m_bbox( mesh->getBounds() )
       ,m_radius( mesh->getBoundingSphereRadius() )
       ,m_position( NULL )
       ,m_normal( NULL )
       ,m_colour( NULL )
       ,m_texture_coordinate( NULL )
       ,m_index( NULL )

    {
    }

    //-------------------------------------------------------------------------
    ManualObject::~ManualObject()
    {
    }

    //-------------------------------------------------------------------------
    template<typename BufferType>
    BufferType*
    ManualObject::createBuffer( const BufferBinding binding
                               ,Ogre::VertexElementType type
                               ,Ogre::VertexElementSemantic semantic )
    {
        Ogre::VertexDeclaration* decl = m_section->vertexData->vertexDeclaration;
        Ogre::VertexBufferBinding* bind = m_section->vertexData->vertexBufferBinding;

        decl->addElement( binding, 0, type, semantic );
        size_t vertex_size( decl->getVertexSize( binding ) );

        VertexBuffer buffer = Ogre::HardwareBufferManager::getSingleton()
            .createVertexBuffer( vertex_size
                                ,m_section->vertexData->vertexCount
                                ,Ogre::HardwareBuffer::HBU_STATIC_WRITE_ONLY);
        bind->setBinding( binding, buffer );
        m_vertex_buffers[binding] = buffer;
        return static_cast<BufferType*>( buffer->lock( Ogre::HardwareBuffer::HBL_DISCARD ) );
    }

    //-------------------------------------------------------------------------
    void
    ManualObject::createPositionBuffer()
    {
        m_position = createBuffer<Ogre::Vector3>( BB_POSITION, Ogre::VET_FLOAT3, Ogre::VES_POSITION );
    }

    //-------------------------------------------------------------------------
    void
    ManualObject::createNormalBuffer()
    {
        m_normal = createBuffer<Ogre::Vector3>( BB_NORMAL, Ogre::VET_FLOAT3, Ogre::VES_NORMAL );
    }

    //-------------------------------------------------------------------------
    void
    ManualObject::createColourBuffer()
    {
        m_colour = createBuffer<uint32>( BB_COLOUR, Ogre::VET_COLOUR_ABGR, Ogre::VES_DIFFUSE  );
    }

    //-------------------------------------------------------------------------
    void
    ManualObject::createTextureCoordinateBuffer()
    {
        m_texture_coordinate = createBuffer<Ogre::Vector2>( BB_TEXTURE, Ogre::VET_FLOAT2, Ogre::VES_TEXTURE_COORDINATES );
    }

    //-------------------------------------------------------------------------
    void
    ManualObject::createIndexBuffer()
    {
        m_index_buffer = Ogre::HardwareBufferManager::getSingleton()
            .createIndexBuffer( Ogre::HardwareIndexBuffer::IT_16BIT
                               ,m_section->indexData->indexCount
                               ,Ogre::HardwareBuffer::HBU_STATIC_WRITE_ONLY );

        void *data( m_index_buffer->lock( Ogre::HardwareBuffer::HBL_DISCARD ) );
        m_index = static_cast< uint16* >( data );
        m_section->indexData->indexBuffer = m_index_buffer;
    }

    //-------------------------------------------------------------------------
    template<typename BufferSharedPtr>
    void
    ManualObject::resetBuffer( BufferSharedPtr &buffer ) const
    {
        if( buffer.isNull() ) return;

        if( buffer->isLocked() )
        {
            buffer->unlock();
        }

        buffer.setNull();
    }

    //-------------------------------------------------------------------------
    void
    ManualObject::resetBuffers()
    {
        for( int i(BINDING_COUNT); i--; )
        {
            resetBuffer( m_vertex_buffers[i] );
        }

        resetBuffer( m_index_buffer );
        m_position = NULL;
        m_normal = NULL;
        m_colour = NULL;
        m_texture_coordinate = NULL;
        m_index = NULL;
    }

    //-------------------------------------------------------------------------
    void
    ManualObject::begin( const String &name, const String &material_name
                        ,size_t vertex_count, size_t index_count )
    {
        if( m_mesh == NULL )
        {
			OGRE_EXCEPT( Ogre::Exception::ERR_INVALIDPARAMS,
				"You cannot begin a section without a Mesh",
				"ManualObject::begin");
        }

        if( m_section != NULL )
        {
			OGRE_EXCEPT( Ogre::Exception::ERR_INVALIDPARAMS,
				"You cannot begin a section without ending the old one first",
				"ManualObject::begin");
        }

        if( vertex_count == 0 )
        {
			OGRE_EXCEPT( Ogre::Exception::ERR_INVALIDPARAMS,
				"You cannot begin with a vertex count of 0",
				"ManualObject::begin");
        }

        m_section = m_mesh->createSubMesh( name );
        m_section->setMaterialName( material_name );
        m_section->useSharedVertices = false;
        m_section->operationType = Ogre::RenderOperation::OT_TRIANGLE_LIST;
        m_section->vertexData = new Ogre::VertexData();
        m_section->vertexData->vertexStart = 0;
        m_section->vertexData->vertexCount = vertex_count;
        m_section->indexData = new Ogre::IndexData();
        m_section->indexData->indexStart = 0;
        m_section->indexData->indexCount = index_count;
    }

    //-------------------------------------------------------------------------
    void
    ManualObject::position( const Ogre::Vector3 &position )
    {
        if( m_position == NULL )
        {
            createPositionBuffer();
        }
        *(m_position++) = position;

		m_bbox.merge( position );
		m_radius = std::max( m_radius, position.length() );
    }

    //-------------------------------------------------------------------------
    void
    ManualObject::normal( const Ogre::Vector3 &normal )
    {
        if( m_normal == NULL )
        {
            createNormalBuffer();
        }
        *(m_normal++) = normal;
    }

    //-------------------------------------------------------------------------
    void
    ManualObject::colour( const Ogre::ColourValue &colour )
    {
        if( m_colour == NULL )
        {
            createColourBuffer();
        }
        *(m_colour++) = Ogre::VertexElement::convertColourValue( colour, Ogre::VET_COLOUR_ABGR );
    }

    //-------------------------------------------------------------------------
    void
    ManualObject::textureCoord( const Ogre::Vector2 &texture_coordinate )
    {
        if( m_texture_coordinate == NULL )
        {
            createTextureCoordinateBuffer();
        }
        *(m_texture_coordinate++) = texture_coordinate;
    }

    //-------------------------------------------------------------------------
    void
    ManualObject::index( const uint32 idx )
    {
        if( m_index == NULL )
        {
            createIndexBuffer();
        }
        *(m_index++) = idx;
    }

    //-------------------------------------------------------------------------
    void
    ManualObject::bone( const uint32 idx, const uint16 bone_handle
                       ,const Ogre::Real weight )
    {
        Ogre::VertexBoneAssignment vba;
        vba.vertexIndex = idx;
        vba.boneIndex = bone_handle;
        vba.weight = weight;
        m_section->addBoneAssignment( vba );
    }

    //-------------------------------------------------------------------------
    void
    ManualObject::end()
    {
        if( m_section == NULL )
        {
			OGRE_EXCEPT( Ogre::Exception::ERR_INVALIDPARAMS,
				"You cannot end a section without beginning one first",
				"ManualObject::end");
        }

        m_mesh->_setBounds( m_bbox );
        m_mesh->_setBoundingSphereRadius( m_radius );
        m_section = NULL;
        resetBuffers();
    }

    //-------------------------------------------------------------------------
}
