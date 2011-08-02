#include "UiSprite.h"

#include <OgreHardwareBufferManager.h>
#include <OgreMaterialManager.h>

#include "Logger.h"



UiSprite::UiSprite( const Ogre::String& name ):
    UiWidget( name )
{
    Initialise();
}



UiSprite::UiSprite( const Ogre::String& name, const Ogre::String& path_name, UiWidget* parent ):
    UiWidget( name, path_name, parent )
{
    Initialise();
}



UiSprite::~UiSprite()
{
    DestroyVertexBuffer();
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
    tex->setTextureName( "system/blank.png" );
    tex->setNumMipmaps( -1 );
    tex->setTextureFiltering( Ogre::TFO_NONE );

    CreateVertexBuffer();
}



void
UiSprite::Update()
{
    UiWidget::Update();
}



void
UiSprite::OnResize()
{
    UiWidget::OnResize();

    UpdateGeometry();
}



void
UiSprite::Render()
{
    if( m_Visible == true )
    {
        if( m_RenderOp.vertexData->vertexCount != 0 )
        {
            m_RenderSystem->_setWorldMatrix( Ogre::Matrix4::IDENTITY );
            m_RenderSystem->_setProjectionMatrix( Ogre::Matrix4::IDENTITY );
            m_RenderSystem->_setViewMatrix( Ogre::Matrix4::IDENTITY );

            m_SceneManager->_setPass( m_Material->getTechnique( 0 )->getPass( 0 ), true, false );

            m_RenderSystem->setScissorTest( true, m_ScissorLeft, m_ScissorTop, m_ScissorRight, m_ScissorBottom );
            m_RenderSystem->_render( m_RenderOp );
            m_RenderSystem->setScissorTest( false );
        }
    }

    UiWidget::Render();
}



void
UiSprite::SetImage( const Ogre::String& image )
{
    Ogre::Pass* pass = m_Material->getTechnique( 0 )->getPass( 0 );
    Ogre::TextureUnitState* tex = pass->getTextureUnitState( 0 );
    tex->setTextureName( image );
}



void
UiSprite::SetVertexShader( const Ogre::String& shader )
{
    Ogre::Pass* pass = m_Material->getTechnique( 0 )->getPass( 0 );
    pass->setVertexProgram( shader, true );
    pass->getVertexProgram()->load();
}



void
UiSprite::SetFragmentShader( const Ogre::String& shader )
{
    Ogre::Pass* pass = m_Material->getTechnique( 0 )->getPass( 0 );
    pass->setFragmentProgram( shader, true );
    pass->getFragmentProgram()->load();
}



void
UiSprite::UpdateGeometry()
{
    float local_x1 = -m_FinalOrigin.x;
    float local_y1 = -m_FinalOrigin.y;
    float local_x2 = m_FinalSize.x + local_x1;
    float local_y2 = m_FinalSize.y + local_y1;
    float x = m_FinalTranslate.x;
    float y = m_FinalTranslate.y;

    int x1, y1, x2, y2, x3, y3, x4, y4;

    //LOG_ERROR( m_Name + ", rotation = " + Ogre::StringConverter::toString( rotation ) );
    //LOG_ERROR( "local_x1 = " + Ogre::StringConverter::toString( local_x1 ) + ", local_y1 = " + Ogre::StringConverter::toString( local_y1 ) );
    //LOG_ERROR( "local_x2 = " + Ogre::StringConverter::toString( local_x2 ) + ", local_y2 = " + Ogre::StringConverter::toString( local_y2 ) );

    if( m_FinalRotation != 0 )
    {
        float cos = Ogre::Math::Cos( Ogre::Radian( Ogre::Degree( m_FinalRotation ) ) );
        float sin = Ogre::Math::Sin( Ogre::Radian( Ogre::Degree( m_FinalRotation ) ) );

        x1 = local_x1 * cos - local_y1 * sin + x;
        y1 = local_x1 * sin + local_y1 * cos + y;
        x2 = local_x2 * cos - local_y1 * sin + x;
        y2 = local_x2 * sin + local_y1 * cos + y;
        x3 = local_x2 * cos - local_y2 * sin + x;
        y3 = local_x2 * sin + local_y2 * cos + y;
        x4 = local_x1 * cos - local_y2 * sin + x;
        y4 = local_x1 * sin + local_y2 * cos + y;
    }
    else
    {
        x1 = local_x1 + x;
        y1 = local_y1 + y;
        x2 = local_x2 + x;
        y2 = local_y1 + y;
        x3 = local_x2 + x;
        y3 = local_y2 + y;
        x4 = local_x1 + x;
        y4 = local_y2 + y;
    }

    //LOG_ERROR( "x1 = " + Ogre::StringConverter::toString( x1 ) + ", y1 = " + Ogre::StringConverter::toString( y1 ) );
    //LOG_ERROR( "x2 = " + Ogre::StringConverter::toString( x2 ) + ", y2 = " + Ogre::StringConverter::toString( y2 ) );
    //LOG_ERROR( "x3 = " + Ogre::StringConverter::toString( x3 ) + ", y3 = " + Ogre::StringConverter::toString( y3 ) );
    //LOG_ERROR( "x4 = " + Ogre::StringConverter::toString( x4 ) + ", y4 = " + Ogre::StringConverter::toString( y4 ) );

    float new_x1 = ( x1 / m_ScreenWidth ) * 2 - 1;
    float new_y1 = -( ( y1 / m_ScreenHeight ) * 2 - 1 );
    float new_x2 = ( x2 / m_ScreenWidth ) * 2 - 1;
    float new_y2 = -( ( y2 / m_ScreenHeight ) * 2 - 1 );
    float new_x3 = ( x3 / m_ScreenWidth ) * 2 - 1;
    float new_y3 = -( ( y3 / m_ScreenHeight ) * 2 - 1 );
    float new_x4 = ( x4 / m_ScreenWidth ) * 2 - 1;
    float new_y4 = -( ( y4 / m_ScreenHeight ) * 2 - 1 );

    float* writeIterator = ( float* ) m_VertexBuffer->lock( Ogre::HardwareBuffer::HBL_NORMAL );

    *writeIterator++ = new_x1;
    *writeIterator++ = new_y1;
    *writeIterator++ = 0; // z
    *writeIterator++ = m_Colour1.r;
    *writeIterator++ = m_Colour1.g;
    *writeIterator++ = m_Colour1.b;
    *writeIterator++ = m_Colour1.a;
    *writeIterator++ = 0;
    *writeIterator++ = 0;

    *writeIterator++ = new_x2;
    *writeIterator++ = new_y2;
    *writeIterator++ = 0; // z
    *writeIterator++ = m_Colour2.r;
    *writeIterator++ = m_Colour2.g;
    *writeIterator++ = m_Colour2.b;
    *writeIterator++ = m_Colour2.a;
    *writeIterator++ = 1;
    *writeIterator++ = 0;

    *writeIterator++ = new_x3;
    *writeIterator++ = new_y3;
    *writeIterator++ = 0; // z
    *writeIterator++ = m_Colour3.r;
    *writeIterator++ = m_Colour3.g;
    *writeIterator++ = m_Colour3.b;
    *writeIterator++ = m_Colour3.a;
    *writeIterator++ = 1;
    *writeIterator++ = 1;

    *writeIterator++ = new_x1;
    *writeIterator++ = new_y1;
    *writeIterator++ = 0; // z
    *writeIterator++ = m_Colour1.r;
    *writeIterator++ = m_Colour1.g;
    *writeIterator++ = m_Colour1.b;
    *writeIterator++ = m_Colour1.a;
    *writeIterator++ = 0;
    *writeIterator++ = 0;

    *writeIterator++ = new_x3;
    *writeIterator++ = new_y3;
    *writeIterator++ = 0; // z
    *writeIterator++ = m_Colour3.r;
    *writeIterator++ = m_Colour3.g;
    *writeIterator++ = m_Colour3.b;
    *writeIterator++ = m_Colour3.a;
    *writeIterator++ = 1;
    *writeIterator++ = 1;

    *writeIterator++ = new_x4;
    *writeIterator++ = new_y4;
    *writeIterator++ = 0; // z
    *writeIterator++ = m_Colour4.r;
    *writeIterator++ = m_Colour4.g;
    *writeIterator++ = m_Colour4.b;
    *writeIterator++ = m_Colour4.a;
    *writeIterator++ = 0;
    *writeIterator++ = 1;

    m_RenderOp.vertexData->vertexCount = 6;

    m_VertexBuffer->unlock();
}



void
UiSprite::CreateVertexBuffer()
{
    m_RenderOp.vertexData = new Ogre::VertexData;
    m_RenderOp.vertexData->vertexStart = 0;

    Ogre::VertexDeclaration* vDecl = m_RenderOp.vertexData->vertexDeclaration;

    size_t offset = 0;
    vDecl->addElement( 0, 0, Ogre::VET_FLOAT3, Ogre::VES_POSITION );
    offset += Ogre::VertexElement::getTypeSize( Ogre::VET_FLOAT3 );
    vDecl->addElement( 0, offset, Ogre::VET_FLOAT4, Ogre::VES_DIFFUSE );
    offset += Ogre::VertexElement::getTypeSize( Ogre::VET_FLOAT4 );
    vDecl->addElement( 0, offset, Ogre::VET_FLOAT2, Ogre::VES_TEXTURE_COORDINATES );

    m_VertexBuffer = Ogre::HardwareBufferManager::getSingletonPtr()->createVertexBuffer( vDecl->getVertexSize( 0 ), 6, Ogre::HardwareBuffer::HBU_DYNAMIC_WRITE_ONLY, false );

    m_RenderOp.vertexData->vertexBufferBinding->setBinding( 0, m_VertexBuffer );
    m_RenderOp.operationType = Ogre::RenderOperation::OT_TRIANGLE_LIST;
    m_RenderOp.useIndexes = false;
}



void
UiSprite::DestroyVertexBuffer()
{
    delete m_RenderOp.vertexData;
    m_RenderOp.vertexData = 0;
    m_VertexBuffer.setNull();
}
