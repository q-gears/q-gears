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

            Ogre::Matrix4 matrix = Ogre::Matrix4::IDENTITY;
            matrix.makeTransform ( Ogre::Vector3( 0.0f, 0.0f, 0.0f ), Ogre::Vector3( 1.0, 1.0f, 0.0f ), Ogre::Quaternion ( Ogre::Radian( Ogre::Degree( 0 ) ), Ogre::Vector3( 0, 0, -1 ) ) );
            m_RenderSystem->_setViewMatrix( matrix );

            m_SceneManager->_setPass( m_Material->getTechnique( 0 )->getPass( 0 ), true, false );

            //m_RenderSystem->setScissorTest( true, 200, 200, 400, 400 );
            m_RenderSystem->_render( m_QuadRenderOp );
            //m_RenderSystem->setScissorTest( false );
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
    float x1 = GetScreenX();
    float y1 = GetScreenY();
    float width = GetScreenWidth();
    float height = GetScreenHeight();
    float x2 = x1 + width;
    float y2 = y1;
    float x3 = x2;
    float y3 = y2 + height;
    float x4 = x1;
    float y4 = y3;

    //LOG_ERROR( m_Name );
    //LOG_ERROR( "x1 = " + Ogre::StringConverter::toString( x1 ) + ", y1 = " + Ogre::StringConverter::toString( y1 ) );
    //LOG_ERROR( "x2 = " + Ogre::StringConverter::toString( x2 ) + ", y2 = " + Ogre::StringConverter::toString( y2 ) );
    //LOG_ERROR( "x3 = " + Ogre::StringConverter::toString( x3 ) + ", y3 = " + Ogre::StringConverter::toString( y3 ) );
    //LOG_ERROR( "x4 = " + Ogre::StringConverter::toString( x4 ) + ", y4 = " + Ogre::StringConverter::toString( y4 ) );

    float screen_width = Ogre::Root::getSingleton().getRenderTarget( "QGearsWindow" )->getViewport( 0 )->getActualWidth();
    float screen_height = Ogre::Root::getSingleton().getRenderTarget( "QGearsWindow" )->getViewport( 0 )->getActualHeight();
    float new_x1 = ( ( int )x1 / screen_width ) * 2 - 1;
    float new_y1 = -( ( ( int )y1 / screen_height ) * 2 - 1 );
    float new_x2 = ( ( int )x2 / screen_width ) * 2 - 1;
    float new_y2 = -( ( ( int )y2 / screen_height ) * 2 - 1 );
    float new_x3 = ( ( int )x3 / screen_width ) * 2 - 1;
    float new_y3 = -( ( ( int )y3 / screen_height ) * 2 - 1 );
    float new_x4 = ( ( int )x4 / screen_width ) * 2 - 1;
    float new_y4 = -( ( ( int )y4 / screen_height ) * 2 - 1 );

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
