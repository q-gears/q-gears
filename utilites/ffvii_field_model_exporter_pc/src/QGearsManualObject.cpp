#include "QGearsManualObject.h"

#include <cstring>

#include <OgreException.h>

namespace QGears
{
    //-------------------------------------------------------------------------
    ManualObject::ManualObject( Ogre::Mesh *mesh ) :
        m_mesh( mesh )
       ,m_section( NULL )
    {
    }

    //-------------------------------------------------------------------------
    ManualObject::~ManualObject()
    {
    }

    //-------------------------------------------------------------------------
    void
    ManualObject::createBuffer( const BufferBinding binding
                               ,Ogre::VertexElementType type
                               ,Ogre::VertexElementSemantic semantic )
    {
        Ogre::VertexDeclaration* decl = m_section->vertexData->vertexDeclaration;
        Ogre::VertexBufferBinding* bind = m_section->vertexData->vertexBufferBinding;

        decl->addElement( binding, 0, type, semantic );
        size_t vertex_size( decl->getVertexSize( binding ) );

        Buffer buffer = Ogre::HardwareBufferManager::getSingleton()
            .createVertexBuffer( vertex_size
                                ,m_section->vertexData->vertexCount
                                ,Ogre::HardwareBuffer::HBU_STATIC_WRITE_ONLY);
        bind->setBinding( binding, buffer );
        buffer->lock( Ogre::HardwareBuffer::HBL_DISCARD );
        m_buffer[binding] = buffer;
    }

    //-------------------------------------------------------------------------
    void
    ManualObject::createPositionBuffer()
    {
        createBuffer( BB_POSITION, Ogre::VET_FLOAT3, Ogre::VES_POSITION );
    }

    //-------------------------------------------------------------------------
    void
    ManualObject::createNormalBuffer()
    {
        createBuffer( BB_POSITION, Ogre::VET_FLOAT3, Ogre::VES_POSITION );
    }

    //-------------------------------------------------------------------------
    void
    ManualObject::createColourBuffer()
    {
        createBuffer( BB_POSITION, Ogre::VET_FLOAT3, Ogre::VES_POSITION );
    }

    //-------------------------------------------------------------------------
    void
    ManualObject::createTextureCoordinateBuffer()
    {
        createBuffer( BB_POSITION, Ogre::VET_FLOAT3, Ogre::VES_POSITION );
    }

    //-------------------------------------------------------------------------
    void
    ManualObject::begin( const String &name, const String &material_name
                        ,size_t vertex_count )
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
        for( int i(BINDING_COUNT); i--; )
        {
            m_buffer[i].setNull();
        }
    }

    //-------------------------------------------------------------------------
    void
    ManualObject::position( const Ogre::Vector3 &position )
    {

        m_first_vertex = false;
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
    }

    //-------------------------------------------------------------------------
}
