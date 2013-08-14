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
        m_colour = createBuffer<uint32>( BB_COLOUR, Ogre::VET_COLOUR, Ogre::VES_DIFFUSE  );
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
    void
    ManualObject::resetBuffers()
    {
        for( int i(BINDING_COUNT); i--; )
        {
            if( m_vertex_buffers[i]->isLocked() )
            {
                m_vertex_buffers[i]->unlock();
            }
            m_vertex_buffers[i].setNull();
        }

        if( m_index_buffer->isLocked() )
        {
            m_index_buffer->unlock();
        }
        m_index_buffer.setNull();
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
        m_mesh->_setBounds( m_bbox );
        m_mesh->_setBoundingSphereRadius( m_radius );
        resetBuffers();
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
        Ogre::RenderSystem* rs( Ogre::Root::getSingleton().getRenderSystem() );
        rs->convertColourValue( colour, m_colour++  );
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
    ManualObject::end()
    {
        if( m_section == NULL )
        {
			OGRE_EXCEPT( Ogre::Exception::ERR_INVALIDPARAMS,
				"You cannot end a section without beginning one first",
				"ManualObject::end");
        }

        m_section = NULL;
        resetBuffers();
    }

    //-------------------------------------------------------------------------
}
