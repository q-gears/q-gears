#include "GuiEffect.h"

#include <Ogre.h>

#define POSITION_BINDING 0
#define COLOUR_BINDING 1
#define TEXTURE_BINDING 2



GuiEffect::GuiEffect( const Ogre::String& name ):
    Ogre::OverlayContainer( name )
{
}



GuiEffect::~GuiEffect()
{
}



void
GuiEffect::initialise()
{
    if( !mInitialised )
    {
        // Setup render op in advance
        m_RenderOp.vertexData = new Ogre::VertexData();
        m_RenderOp.vertexData->vertexStart = 0;
        m_RenderOp.vertexData->vertexCount = 6;
        m_RenderOp.useIndexes = false;
        m_RenderOp.operationType = Ogre::RenderOperation::OT_TRIANGLE_LIST;

        // Create as separate buffers so we can lock & discard separately
        Ogre::VertexDeclaration* decl = m_RenderOp.vertexData->vertexDeclaration;
        decl->addElement( POSITION_BINDING, 0, Ogre::VET_FLOAT3, Ogre::VES_POSITION );
        decl->addElement( COLOUR_BINDING, 0, Ogre::VET_COLOUR, Ogre::VES_DIFFUSE );
        decl->addElement( TEXTURE_BINDING, 0, Ogre::VET_FLOAT2, Ogre::VES_TEXTURE_COORDINATES, 0 );

        // Vertex buffer
        Ogre::HardwareVertexBufferSharedPtr vbuf0 = Ogre::HardwareBufferManager::getSingleton().createVertexBuffer(
            decl->getVertexSize( POSITION_BINDING ),
            m_RenderOp.vertexData->vertexCount,
            Ogre::HardwareBuffer::HBU_STATIC_WRITE_ONLY );

        // Colour buffer
        Ogre::HardwareVertexBufferSharedPtr vbuf1 = Ogre::HardwareBufferManager::getSingleton().createVertexBuffer(
            decl->getVertexSize( COLOUR_BINDING ),
            m_RenderOp.vertexData->vertexCount,
            Ogre::HardwareBuffer::HBU_STATIC_WRITE_ONLY );

        // Texture buffer
        Ogre::HardwareVertexBufferSharedPtr vbuf2 = Ogre::HardwareBufferManager::getSingleton().createVertexBuffer(
            decl->getVertexSize( TEXTURE_BINDING ),
            m_RenderOp.vertexData->vertexCount,
            Ogre::HardwareBuffer::HBU_STATIC_WRITE_ONLY );

        // Bind buffer
        m_RenderOp.vertexData->vertexBufferBinding->setBinding( POSITION_BINDING, vbuf0 );
        m_RenderOp.vertexData->vertexBufferBinding->setBinding( COLOUR_BINDING, vbuf1 );
        m_RenderOp.vertexData->vertexBufferBinding->setBinding( TEXTURE_BINDING, vbuf2 );



        float* pPos = static_cast< float* >( vbuf0->lock( Ogre::HardwareBuffer::HBL_DISCARD ) );

        float left = -1;
        float right = 1;
        float top = -1;
        float bottom = 1;

        // center
        *pPos++ = left;  *pPos++ = top;    *pPos++ = 0.0f;
        *pPos++ = right; *pPos++ = top;    *pPos++ = 1.0f;
        *pPos++ = left;  *pPos++ = bottom; *pPos++ = 0.0f;
        *pPos++ = right; *pPos++ = top;    *pPos++ = 1.0f;
        *pPos++ = right; *pPos++ = bottom; *pPos++ = 1.0f;
        *pPos++ = left;  *pPos++ = bottom; *pPos++ = 0.0f;

        vbuf0->unlock();



        Ogre::RenderSystem* rs = Ogre::Root::getSingleton().getRenderSystem();
        Ogre::RGBA colours[ m_RenderOp.vertexData->vertexCount ];

        // only center needs cpecific colours
        rs->convertColourValue( Ogre::ColourValue( 0.5, 0, 0, 0.5 ), colours + 1 );
        rs->convertColourValue( Ogre::ColourValue( 0.2, 0, 0, 0.5 ), colours + 0 );
        rs->convertColourValue( Ogre::ColourValue( 0.2, 0, 0, 0.5 ), colours + 2 );
        rs->convertColourValue( Ogre::ColourValue( 0.5, 0, 0, 0.5 ), colours + 3 );
        rs->convertColourValue( Ogre::ColourValue( 0.5, 0, 0, 0.5 ), colours + 4 );
        rs->convertColourValue( Ogre::ColourValue( 0.2, 0, 0, 0.5 ), colours + 5 );

        vbuf1->writeData(0, vbuf1->getSizeInBytes(), colours, true);

        mInitialised = true;
    }
}



const Ogre::String&
GuiEffect::getTypeName() const
{
    return "GuiEffect";
}



void
GuiEffect::getRenderOperation( Ogre::RenderOperation& op )
{
    op = m_RenderOp;
}



void
GuiEffect::updatePositionGeometry()
{
}



void
GuiEffect::updateTextureGeometry()
{
}
