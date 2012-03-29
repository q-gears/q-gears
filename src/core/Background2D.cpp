#include "Background2D.h"

#include <OgreHardwareBufferManager.h>
#include <OgreMaterialManager.h>

#include "ConfigVar.h"
#include "Logger.h"
#include "Timer.h"



ConfigVar cv_debug_background2d( "debug_background2d", "Draw background debug info", "false" );
ConfigVar cv_background2d_show( "background2d_show", "Draw background or not", "true" );



Background2D::Background2D():
    m_MaxVertexCount( 0 )
{
    m_SceneManager = Ogre::Root::getSingleton().getSceneManager( "Scene" );
    m_RenderSystem = Ogre::Root::getSingletonPtr()->getRenderSystem();

    CreateVertexBuffer();

    m_Material = Ogre::MaterialManager::getSingleton().create( "Background2D", "General" );
    Ogre::Pass* pass = m_Material->getTechnique( 0 )->getPass( 0 );
    pass->setVertexColourTracking( Ogre::TVC_AMBIENT );
    pass->setCullingMode( Ogre::CULL_NONE );
    pass->setDepthCheckEnabled( true );
    pass->setDepthWriteEnabled( true );
    pass->setLightingEnabled( false );
    pass->setSceneBlending( Ogre::SBT_TRANSPARENT_ALPHA );

    pass->setAlphaRejectFunction( Ogre::CMPF_GREATER );
    pass->setAlphaRejectValue( 0 );
    Ogre::TextureUnitState* tex = pass->createTextureUnitState();
    tex->setTextureName( "system/blank.png" );
    tex->setNumMipmaps( -1 );
    tex->setTextureFiltering( Ogre::TFO_NONE );

    m_SceneManager->addRenderQueueListener( this );
}



Background2D::~Background2D()
{
    m_SceneManager->removeRenderQueueListener( this );

    for( unsigned int i = 0; i < m_Animations.size(); ++i )
    {
        delete m_Animations[ i ];
    }

    DestroyVertexBuffer();
}



void
Background2D::Update()
{
    if( cv_debug_background2d.GetB() == true )
    {
/*
        DEBUG_DRAW.SetScreenSpace( true );
        DEBUG_DRAW.SetTextAlignment( DEBUG_DRAW.CENTER );

        for( int i = 0; i < m_Triangles.size(); ++i )
        {
            if( m_Triangles[ i ].access_side[ 0 ] == -1 )
            {
                DEBUG_DRAW.SetColour( Ogre::ColourValue( 1, 0, 0, 1 ) );
            }
            else
            {
                DEBUG_DRAW.SetColour( Ogre::ColourValue( 1, 1, 1, 1 ) );
            }
            DEBUG_DRAW.Line3d( m_Triangles[ i ].a, m_Triangles[ i ].b );
            if( m_Triangles[ i ].access_side[ 1 ] == -1 )
            {
                DEBUG_DRAW.SetColour( Ogre::ColourValue( 1, 0, 0, 1 ) );
            }
            else
            {
                DEBUG_DRAW.SetColour( Ogre::ColourValue( 1, 1, 1, 1 ) );
            }
            DEBUG_DRAW.Line3d( m_Triangles[ i ].b, m_Triangles[ i ].c );
            if( m_Triangles[ i ].access_side[ 2 ] == -1 )
            {
                DEBUG_DRAW.SetColour( Ogre::ColourValue( 1, 0, 0, 1 ) );
            }
            else
            {
                DEBUG_DRAW.SetColour( Ogre::ColourValue( 1, 1, 1, 1 ) );
            }
            DEBUG_DRAW.Line3d( m_Triangles[ i ].c, m_Triangles[ i ].a );

            DEBUG_DRAW.SetColour( Ogre::ColourValue( 1, 1, 1, 1 ) );
            DEBUG_DRAW.SetFadeDistance( 20, 25 );
            Ogre::Vector3 triangle_pos = ( m_Triangles[ i ].a + m_Triangles[ i ].b + m_Triangles[ i ].c) / 3;
            DEBUG_DRAW.Text( triangle_pos, 0, 0, Ogre::StringConverter::toString( i ) );
        }
*/
    }



    for( unsigned int i = 0; i < m_Animations.size(); ++i )
    {
        m_Animations[ i ]->AddTime( Timer::getSingleton().GetGameTimeDelta() );
    }
}



void
Background2D::Clear()
{
    DestroyVertexBuffer();
    CreateVertexBuffer();
}



void
Background2D::SetImage( const Ogre::String& image )
{
    Ogre::Pass* pass = m_Material->getTechnique( 0 )->getPass( 0 );
    Ogre::TextureUnitState* tex = pass->getTextureUnitState( 0 );
    tex->setTextureName( image );
}



void
Background2D::AddTile( const float x, const float y, const float width, const float height, const float depth, const float u1, const float v1, const float u2, const float v2 )
{
    if( m_RenderOp.vertexData->vertexCount + 6 > m_MaxVertexCount )
    {
        LOG_ERROR( "Max number of tiles reached. Can't create more than " + Ogre::StringConverter::toString( m_MaxVertexCount / 6 ) + " tiles." );
        return;
    }

    float scr_width = Ogre::Root::getSingleton().getRenderTarget( "QGearsWindow" )->getViewport( 0 )->getActualWidth();
    float scr_height = Ogre::Root::getSingleton().getRenderTarget( "QGearsWindow" )->getViewport( 0 )->getActualHeight();

    float new_x1 = ( ( int ) x / scr_width ) * 2 - 1;
    float new_y1 = -( ( ( int ) y / scr_height ) * 2 - 1 );
    float new_x2 = ( ( int ) ( x + width ) / scr_width ) * 2 - 1;
    float new_y2 = -( ( y / scr_height ) * 2 - 1 );
    float new_x3 = ( ( int ) ( x + width ) / scr_width ) * 2 - 1;
    float new_y3 = -( ( ( int ) ( y + height ) / scr_height ) * 2 - 1 );
    float new_x4 = ( ( int ) x / scr_width ) * 2 - 1;
    float new_y4 = -( ( ( int ) ( y + height ) / scr_height ) * 2 - 1 );

    new_x1 += 1;
    new_y1 -= 1;
    new_x2 += 1;
    new_y2 -= 1;
    new_x3 += 1;
    new_y3 -= 1;
    new_x4 += 1;
    new_y4 -= 1;

    float* writeIterator = ( float* )m_VertexBuffer->lock( Ogre::HardwareBuffer::HBL_NORMAL );
    writeIterator += m_RenderOp.vertexData->vertexCount * 9;

    *writeIterator++ = new_x1;
    *writeIterator++ = new_y1;
    *writeIterator++ = depth;
    *writeIterator++ = 1;
    *writeIterator++ = 1;
    *writeIterator++ = 1;
    *writeIterator++ = 1;
    *writeIterator++ = u1;
    *writeIterator++ = v1;

    *writeIterator++ = new_x2;
    *writeIterator++ = new_y2;
    *writeIterator++ = depth;
    *writeIterator++ = 1;
    *writeIterator++ = 1;
    *writeIterator++ = 1;
    *writeIterator++ = 1;
    *writeIterator++ = u2;
    *writeIterator++ = v1;

    *writeIterator++ = new_x3;
    *writeIterator++ = new_y3;
    *writeIterator++ = depth;
    *writeIterator++ = 1;
    *writeIterator++ = 1;
    *writeIterator++ = 1;
    *writeIterator++ = 1;
    *writeIterator++ = u2;
    *writeIterator++ = v2;

    *writeIterator++ = new_x1;
    *writeIterator++ = new_y1;
    *writeIterator++ = depth;
    *writeIterator++ = 1;
    *writeIterator++ = 1;
    *writeIterator++ = 1;
    *writeIterator++ = 1;
    *writeIterator++ = u1;
    *writeIterator++ = v1;

    *writeIterator++ = new_x3;
    *writeIterator++ = new_y3;
    *writeIterator++ = depth;
    *writeIterator++ = 1;
    *writeIterator++ = 1;
    *writeIterator++ = 1;
    *writeIterator++ = 1;
    *writeIterator++ = u2;
    *writeIterator++ = v2;

    *writeIterator++ = new_x4;
    *writeIterator++ = new_y4;
    *writeIterator++ = depth;
    *writeIterator++ = 1;
    *writeIterator++ = 1;
    *writeIterator++ = 1;
    *writeIterator++ = 1;
    *writeIterator++ = u1;
    *writeIterator++ = v2;

    m_RenderOp.vertexData->vertexCount += 6;

    m_VertexBuffer->unlock();
}



void
Background2D::UpdateTileUV( const unsigned int tile_id, const float u1, const float v1, const float u2, const float v2 )
{
    if( tile_id * 6 > m_RenderOp.vertexData->vertexCount )
    {
        LOG_ERROR( "Tile with id " + Ogre::StringConverter::toString( tile_id ) + " doesn't exist." );
        return;
    }

    float* writeIterator = ( float* )m_VertexBuffer->lock( Ogre::HardwareBuffer::HBL_NORMAL );

    writeIterator += tile_id * 6 * 9;

    writeIterator += 7;
    *writeIterator++ = u1;
    *writeIterator++ = v1;
    writeIterator += 7;
    *writeIterator++ = u2;
    *writeIterator++ = v1;
    writeIterator += 7;
    *writeIterator++ = u2;
    *writeIterator++ = v2;
    writeIterator += 7;
    *writeIterator++ = u1;
    *writeIterator++ = v1;
    writeIterator += 7;
    *writeIterator++ = u2;
    *writeIterator++ = v2;
    writeIterator += 7;
    *writeIterator++ = u1;
    *writeIterator++ = v2;

    m_VertexBuffer->unlock();
}



void
Background2D::AddAnimation( Background2DAnimation* animation )
{
    m_Animations.push_back( animation );
}



void
Background2D::renderQueueEnded( Ogre::uint8 queueGroupId, const Ogre::String& invocation, bool& repeatThisInvocation )
{
    if( cv_background2d_show.GetB() == false )
    {
        return;
    }



    if( queueGroupId == Ogre::RENDER_QUEUE_MAIN )
    {
        m_RenderSystem->_setWorldMatrix( Ogre::Matrix4::IDENTITY );
        m_RenderSystem->_setProjectionMatrix( Ogre::Matrix4::IDENTITY );
        m_RenderSystem->_setViewMatrix( Ogre::Matrix4::IDENTITY );

        if( m_RenderOp.vertexData->vertexCount != 0 )
        {
            m_SceneManager->_setPass( m_Material->getTechnique( 0 )->getPass( 0 ), true, false );
            m_RenderSystem->_render( m_RenderOp );
        }
    }
}



void
Background2D::CreateVertexBuffer()
{
    m_MaxVertexCount = 2048 * 6;
    m_RenderOp.vertexData = new Ogre::VertexData;
    m_RenderOp.vertexData->vertexStart = 0;

    Ogre::VertexDeclaration* vDecl = m_RenderOp.vertexData->vertexDeclaration;

    size_t offset = 0;
    vDecl->addElement( 0, 0, Ogre::VET_FLOAT3, Ogre::VES_POSITION );
    offset += Ogre::VertexElement::getTypeSize( Ogre::VET_FLOAT3 );
    vDecl->addElement( 0, offset, Ogre::VET_FLOAT4, Ogre::VES_DIFFUSE );
    offset += Ogre::VertexElement::getTypeSize( Ogre::VET_FLOAT4 );
    vDecl->addElement( 0, offset, Ogre::VET_FLOAT2, Ogre::VES_TEXTURE_COORDINATES );

    m_VertexBuffer = Ogre::HardwareBufferManager::getSingletonPtr()->createVertexBuffer( vDecl->getVertexSize( 0 ), m_MaxVertexCount, Ogre::HardwareBuffer::HBU_DYNAMIC_WRITE_ONLY, false );

    m_RenderOp.vertexData->vertexBufferBinding->setBinding( 0, m_VertexBuffer );
    m_RenderOp.operationType = Ogre::RenderOperation::OT_TRIANGLE_LIST;
    m_RenderOp.useIndexes = false;
}



void
Background2D::DestroyVertexBuffer()
{
    delete m_RenderOp.vertexData;
    m_RenderOp.vertexData = 0;
    m_VertexBuffer.setNull();
    m_MaxVertexCount = 0;
}
