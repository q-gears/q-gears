#include "UiSprite.h"

#include <OgreHardwareBufferManager.h>
#include <OgreMaterialManager.h>

#include "Logger.h"



UiSprite::UiSprite( const Ogre::String& name ):
    UiWidget( name ),
    m_Colour( 1, 1, 1, 1 )
{
    Initialise();
}



UiSprite::UiSprite( const Ogre::String& name, const Ogre::String& path_name, UiWidget* parent ):
    UiWidget( name, path_name, parent ),
    m_Colour( 1, 1, 1, 1 )
{
    Initialise();
}



UiSprite::~UiSprite()
{
    DestroyQuadVertexBuffer();
}



void
UiSprite::Initialise()
{
    m_SceneManager = Ogre::Root::getSingleton().getSceneManager( "Scene" );
    m_RenderSystem = Ogre::Root::getSingletonPtr()->getRenderSystem();

    m_Material = Ogre::MaterialManager::getSingleton().create( "Ui." + m_PathName, "General" );
    Ogre::Pass* pass = m_Material->getTechnique( 0 )->getPass( 0 );
    pass->setVertexColourTracking( Ogre::TVC_AMBIENT );
    pass->setCullingMode( Ogre::CULL_NONE );
    pass->setDepthCheckEnabled( false );
    pass->setDepthWriteEnabled( false );
    pass->setLightingEnabled( false );
    pass->setSceneBlending( Ogre::SBT_TRANSPARENT_ALPHA );

    pass->setAlphaRejectFunction( Ogre::CMPF_GREATER );
    pass->setAlphaRejectValue( 0 );
    Ogre::TextureUnitState* tex = pass->createTextureUnitState();
    tex->setTextureName( "system/no_texture.png" );
    tex->setNumMipmaps( -1 );
    tex->setTextureFiltering( Ogre::TFO_NONE );

    CreateQuadVertexBuffer();
}



void
UiSprite::Update()
{
    UiWidget::Update();
}



void
UiSprite::OnResize()
{
    GeometryUpdate();

    UiWidget::OnResize();
}



void
UiSprite::Render()
{
    if( m_Visible == true )
    {
        if( m_QuadRenderOp.vertexData->vertexCount != 0 )
        {
            m_RenderSystem->_setWorldMatrix( Ogre::Matrix4::IDENTITY );
            m_RenderSystem->_setProjectionMatrix( Ogre::Matrix4::IDENTITY );
            m_RenderSystem->_setViewMatrix( Ogre::Matrix4::IDENTITY );

            m_SceneManager->_setPass( m_Material->getTechnique( 0 )->getPass( 0 ), true, false );
            m_RenderSystem->_render( m_QuadRenderOp );
        }
    }

    UiWidget::Render();
}



void
UiSprite::SetColour( const float r, const float g, const float b, const float a )
{
    m_Colour.r = r;
    m_Colour.g = g;
    m_Colour.b = b;
    m_Colour.a = a;
}



void
UiSprite::SetImage( const Ogre::String& image )
{
    Ogre::Pass* pass = m_Material->getTechnique( 0 )->getPass( 0 );
    Ogre::TextureUnitState* tex = pass->getTextureUnitState( 0 );
    tex->setTextureName( image );
}



void
UiSprite::GeometryUpdate()
{
    int x1 = GetScreenX();
    int y1 = GetScreenY();
    int width = GetScreenWidth();
    int height = GetScreenHeight();
    int x2 = x1 + width;
    int y2 = y1;
    int x3 = x2;
    int y3 = y2 + height;
    int x4 = x1;
    int y4 = y3;

    //LOG_ERROR( m_Name );
    //LOG_ERROR( "width = " + Ogre::StringConverter::toString( width ) + ", height = " + Ogre::StringConverter::toString( height ) );
    //LOG_ERROR( "x1 = " + Ogre::StringConverter::toString( x1 ) + ", y1 = " + Ogre::StringConverter::toString( y1 ) );

    float screen_width = Ogre::Root::getSingleton().getRenderTarget( "QGearsWindow" )->getViewport( 0 )->getActualWidth();
    float screen_height = Ogre::Root::getSingleton().getRenderTarget( "QGearsWindow" )->getViewport( 0 )->getActualHeight();
    float new_x1 = ( x1 / screen_width ) * 2 - 1;
    float new_y1 = -( ( y1 / screen_height ) * 2 - 1 );
    float new_x2 = ( x2 / screen_width ) * 2 - 1;
    float new_y2 = -( ( y2 / screen_height ) * 2 - 1 );
    float new_x3 = ( x3 / screen_width ) * 2 - 1;
    float new_y3 = -( ( y3 / screen_height ) * 2 - 1 );
    float new_x4 = ( x4 / screen_width ) * 2 - 1;
    float new_y4 = -( ( y4 / screen_height ) * 2 - 1 );

    float* writeIterator = ( float* ) m_QuadVertexBuffer->lock( Ogre::HardwareBuffer::HBL_NORMAL );

    *writeIterator++ = new_x1;
    *writeIterator++ = new_y1;
    *writeIterator++ = 0; // z
    *writeIterator++ = m_Colour.r;
    *writeIterator++ = m_Colour.g;
    *writeIterator++ = m_Colour.b;
    *writeIterator++ = m_Colour.a;
    *writeIterator++ = 0;
    *writeIterator++ = 0;

    *writeIterator++ = new_x2;
    *writeIterator++ = new_y2;
    *writeIterator++ = 0; // z
    *writeIterator++ = m_Colour.r;
    *writeIterator++ = m_Colour.g;
    *writeIterator++ = m_Colour.b;
    *writeIterator++ = m_Colour.a;
    *writeIterator++ = 1;
    *writeIterator++ = 0;

    *writeIterator++ = new_x3;
    *writeIterator++ = new_y3;
    *writeIterator++ = 0; // z
    *writeIterator++ = m_Colour.r;
    *writeIterator++ = m_Colour.g;
    *writeIterator++ = m_Colour.b;
    *writeIterator++ = m_Colour.a;
    *writeIterator++ = 1;
    *writeIterator++ = 1;

    *writeIterator++ = new_x1;
    *writeIterator++ = new_y1;
    *writeIterator++ = 0; // z
    *writeIterator++ = m_Colour.r;
    *writeIterator++ = m_Colour.g;
    *writeIterator++ = m_Colour.b;
    *writeIterator++ = m_Colour.a;
    *writeIterator++ = 0;
    *writeIterator++ = 0;

    *writeIterator++ = new_x3;
    *writeIterator++ = new_y3;
    *writeIterator++ = 0; // z
    *writeIterator++ = m_Colour.r;
    *writeIterator++ = m_Colour.g;
    *writeIterator++ = m_Colour.b;
    *writeIterator++ = m_Colour.a;
    *writeIterator++ = 1;
    *writeIterator++ = 1;

    *writeIterator++ = new_x4;
    *writeIterator++ = new_y4;
    *writeIterator++ = 0; // z
    *writeIterator++ = m_Colour.r;
    *writeIterator++ = m_Colour.g;
    *writeIterator++ = m_Colour.b;
    *writeIterator++ = m_Colour.a;
    *writeIterator++ = 0;
    *writeIterator++ = 1;

    m_QuadRenderOp.vertexData->vertexCount = 6;

    m_QuadVertexBuffer->unlock();
}



void
UiSprite::CreateQuadVertexBuffer()
{
    m_QuadRenderOp.vertexData = new Ogre::VertexData;
    m_QuadRenderOp.vertexData->vertexStart = 0;

    Ogre::VertexDeclaration* vDecl = m_QuadRenderOp.vertexData->vertexDeclaration;

    size_t offset = 0;
    vDecl->addElement( 0, 0, Ogre::VET_FLOAT3, Ogre::VES_POSITION );
    offset += Ogre::VertexElement::getTypeSize( Ogre::VET_FLOAT3 );
    vDecl->addElement( 0, offset, Ogre::VET_FLOAT4, Ogre::VES_DIFFUSE );
    offset += Ogre::VertexElement::getTypeSize( Ogre::VET_FLOAT4 );
    vDecl->addElement( 0, offset, Ogre::VET_FLOAT2, Ogre::VES_TEXTURE_COORDINATES );

    m_QuadVertexBuffer = Ogre::HardwareBufferManager::getSingletonPtr()->createVertexBuffer( vDecl->getVertexSize( 0 ), 6, Ogre::HardwareBuffer::HBU_DYNAMIC_WRITE_ONLY, false );

    m_QuadRenderOp.vertexData->vertexBufferBinding->setBinding( 0, m_QuadVertexBuffer );
    m_QuadRenderOp.operationType = Ogre::RenderOperation::OT_TRIANGLE_LIST;
    m_QuadRenderOp.useIndexes = false;
}



void
UiSprite::DestroyQuadVertexBuffer()
{
    delete m_QuadRenderOp.vertexData;
    m_QuadRenderOp.vertexData = 0;
    m_QuadVertexBuffer.setNull();
}
