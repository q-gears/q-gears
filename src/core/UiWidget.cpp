#include "UiWidget.h"

#include <OgreHardwareBufferManager.h>
#include <OgreMaterialManager.h>

#include "Logger.h"



UiWidget::UiWidget( const Ogre::String& name ):
    m_Name( name ),
    m_Parent( NULL ),

    m_Colour( 1, 1, 1, 1 )
{
    m_SceneManager = Ogre::Root::getSingleton().getSceneManager( "Scene" );
    m_RenderSystem = Ogre::Root::getSingletonPtr()->getRenderSystem();

    m_Material = Ogre::MaterialManager::getSingleton().create( "DebugDraw", "General" );
    Ogre::Pass* pass = m_Material->getTechnique( 0 )->getPass( 0 );
    pass->setVertexColourTracking( Ogre::TVC_AMBIENT );
    pass->setCullingMode( Ogre::CULL_NONE );
    pass->setDepthCheckEnabled( false );
    pass->setDepthWriteEnabled( false );
    pass->setLightingEnabled( false );
    pass->setSceneBlending( Ogre::SBT_TRANSPARENT_ALPHA );

    CreateQuadVertexBuffer();
}



UiWidget::UiWidget( const Ogre::String& name, UiWidget* parent ):
    m_Name( name ),
    m_Parent( parent )
{
}



UiWidget::~UiWidget()
{
    RemoveAllChildren();

    DestroyQuadVertexBuffer();
}



void
UiWidget::Update()
{
    for( int i = 0; i < m_Children.size(); ++i )
    {
        m_Children[ i ]->Update();
    }
}



void
UiWidget::Render()
{
    m_RenderSystem->_setWorldMatrix( Ogre::Matrix4::IDENTITY );
    m_RenderSystem->_setProjectionMatrix( Ogre::Matrix4::IDENTITY );
    m_RenderSystem->_setViewMatrix( Ogre::Matrix4::IDENTITY );

    if( m_QuadRenderOp.vertexData->vertexCount != 0 )
    {
        m_SceneManager->_setPass( m_Material->getTechnique( 0 )->getPass( 0 ), true, false );
        m_RenderSystem->_render( m_QuadRenderOp );
        //m_QuadRenderOp.vertexData->vertexCount = 0;
    }



    for( int i = 0; i < m_Children.size(); ++i )
    {
        m_Children[ i ]->Render();
    }
}



const Ogre::String&
UiWidget::GetName() const
{
    return m_Name;
}



void
UiWidget::AddChild( UiWidget *widget )
{
    m_Children.push_back( widget );
}



void
UiWidget::RemoveAllChildren()
{
    for( int i = 0; i < m_Children.size(); ++i )
    {
        delete m_Children[ i ];
    }
    m_Children.clear();
}



void
UiWidget::SetColour( const float r, const float g, const float b, const float a )
{
    m_Colour.r = r;
    m_Colour.g = g;
    m_Colour.b = b;
    m_Colour.a = a;
}



void
UiWidget::Quad( const float x1, const float y1, const float x2, const float y2, const float x3, const float y3, const float x4, const float y4 )
{
    bool m_ScreenSpace = true;



    if( m_QuadRenderOp.vertexData->vertexCount + 6 > m_QuadMaxVertexCount )
    {
        LOG_ERROR( "Max number of quads reached. Can't create more than " + Ogre::StringConverter::toString( m_QuadMaxVertexCount / 6 ) + " quads." );
        return;
    }

    float width = Ogre::Root::getSingleton().getRenderTarget( "QGearsWindow" )->getViewport( 0 )->getActualWidth();
    float height = Ogre::Root::getSingleton().getRenderTarget( "QGearsWindow" )->getViewport( 0 )->getActualHeight();

    float new_x1 = ( m_ScreenSpace == true ) ? ( ( int ) x1 / width ) * 2 - 1 : x1;
    float new_y1 = ( m_ScreenSpace == true ) ? -( ( ( int ) y1 / height ) * 2 - 1 ) : y1;
    float new_x2 = ( m_ScreenSpace == true ) ? ( ( int ) x2 / width ) * 2 - 1 : x2;
    float new_y2 = ( m_ScreenSpace == true ) ? -( ( y2 / height ) * 2 - 1 ) : y2;
    float new_x3 = ( m_ScreenSpace == true ) ? ( ( int ) x3 / width ) * 2 - 1 : x3;
    float new_y3 = ( m_ScreenSpace == true ) ? -( ( ( int ) y3 / height ) * 2 - 1 ) : y3;
    float new_x4 = ( m_ScreenSpace == true ) ? ( ( int ) x4 / width ) * 2 - 1 : x4;
    float new_y4 = ( m_ScreenSpace == true ) ? -( ( ( int ) y4 / height ) * 2 - 1 ) : y4;

    float* writeIterator = ( float* ) m_QuadVertexBuffer->lock( Ogre::HardwareBuffer::HBL_NORMAL );
    writeIterator += m_QuadRenderOp.vertexData->vertexCount * 7;

    *writeIterator++ = new_x1;
    *writeIterator++ = new_y1;
    *writeIterator++ = 0; // z
    *writeIterator++ = m_Colour.r;
    *writeIterator++ = m_Colour.g;
    *writeIterator++ = m_Colour.b;
    *writeIterator++ = m_Colour.a;

    *writeIterator++ = new_x2;
    *writeIterator++ = new_y2;
    *writeIterator++ = 0; // z
    *writeIterator++ = m_Colour.r;
    *writeIterator++ = m_Colour.g;
    *writeIterator++ = m_Colour.b;
    *writeIterator++ = m_Colour.a;

    *writeIterator++ = new_x3;
    *writeIterator++ = new_y3;
    *writeIterator++ = 0; // z
    *writeIterator++ = m_Colour.r;
    *writeIterator++ = m_Colour.g;
    *writeIterator++ = m_Colour.b;
    *writeIterator++ = m_Colour.a;

    *writeIterator++ = new_x1;
    *writeIterator++ = new_y1;
    *writeIterator++ = 0; // z
    *writeIterator++ = m_Colour.r;
    *writeIterator++ = m_Colour.g;
    *writeIterator++ = m_Colour.b;
    *writeIterator++ = m_Colour.a;

    *writeIterator++ = new_x3;
    *writeIterator++ = new_y3;
    *writeIterator++ = 0; // z
    *writeIterator++ = m_Colour.r;
    *writeIterator++ = m_Colour.g;
    *writeIterator++ = m_Colour.b;
    *writeIterator++ = m_Colour.a;

    *writeIterator++ = new_x4;
    *writeIterator++ = new_y4;
    *writeIterator++ = 0; // z
    *writeIterator++ = m_Colour.r;
    *writeIterator++ = m_Colour.g;
    *writeIterator++ = m_Colour.b;
    *writeIterator++ = m_Colour.a;

    m_QuadRenderOp.vertexData->vertexCount += 6;

    m_QuadVertexBuffer->unlock();
}



void
UiWidget::CreateQuadVertexBuffer()
{
    m_QuadMaxVertexCount = 128 * 6;
    m_QuadRenderOp.vertexData = new Ogre::VertexData;
    m_QuadRenderOp.vertexData->vertexStart = 0;

    Ogre::VertexDeclaration* vDecl = m_QuadRenderOp.vertexData->vertexDeclaration;

    size_t offset = 0;
    vDecl->addElement( 0, 0, Ogre::VET_FLOAT3, Ogre::VES_POSITION );
    offset += Ogre::VertexElement::getTypeSize( Ogre::VET_FLOAT3 );
    vDecl->addElement( 0, offset, Ogre::VET_FLOAT4, Ogre::VES_DIFFUSE );

    m_QuadVertexBuffer = Ogre::HardwareBufferManager::getSingletonPtr()->createVertexBuffer( vDecl->getVertexSize( 0 ), m_QuadMaxVertexCount, Ogre::HardwareBuffer::HBU_DYNAMIC_WRITE_ONLY, false );

    m_QuadRenderOp.vertexData->vertexBufferBinding->setBinding( 0, m_QuadVertexBuffer );
    m_QuadRenderOp.operationType = Ogre::RenderOperation::OT_TRIANGLE_LIST;
    m_QuadRenderOp.useIndexes = false;
}



void
UiWidget::DestroyQuadVertexBuffer()
{
    delete m_QuadRenderOp.vertexData;
    m_QuadRenderOp.vertexData = 0;
    m_QuadVertexBuffer.setNull();
    m_QuadMaxVertexCount = 0;
}
