#include "Background2D.h"

#include <OgreHardwareBufferManager.h>
#include <OgreMaterialManager.h>

#include "CameraManager.h"
#include "ConfigVar.h"
#include "DebugDraw.h"
#include "Logger.h"
#include "Timer.h"



ConfigVar cv_debug_background2d( "debug_background2d", "Draw background debug info", "false" );
ConfigVar cv_show_background2d( "show_background2d", "Draw background", "true" );
ConfigVar cv_background2d_manual( "background2d_manual", "Manual scrolling for 2d background", "false" );


Background2D::Background2D():
    m_AlphaMaxVertexCount( 0 ),
    m_AddMaxVertexCount( 0 ),

    m_RangeMinX( -100000 ),
    m_RangeMinY( -100000 ),
    m_RangeMaxX( 100000 ),
    m_RangeMaxY( 100000 ),

    m_ScrollEntity( NULL ),
    m_ScrollPositionStart( Ogre::Vector2::ZERO ),
    m_ScrollPositionEnd( Ogre::Vector2::ZERO ),
    m_ScrollType( Background2D::NONE ),
    m_ScrollSeconds( 0 ),
    m_ScrollCurrentSeconds( 0 ),
    m_Position( Ogre::Vector2::ZERO ),
    m_PositionReal( Ogre::Vector2::ZERO )
{
    m_SceneManager = Ogre::Root::getSingleton().getSceneManager( "Scene" );
    m_RenderSystem = Ogre::Root::getSingletonPtr()->getRenderSystem();

    CreateVertexBuffers();

    m_AlphaMaterial = Ogre::MaterialManager::getSingleton().create( "Background2DAlpha", "General" );
    Ogre::Pass* pass = m_AlphaMaterial->getTechnique( 0 )->getPass( 0 );
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

    m_AddMaterial = Ogre::MaterialManager::getSingleton().create( "Background2DAdd", "General" );
    pass = m_AddMaterial->getTechnique( 0 )->getPass( 0 );
    pass->setVertexColourTracking( Ogre::TVC_AMBIENT );
    pass->setCullingMode( Ogre::CULL_NONE );
    pass->setDepthCheckEnabled( true );
    pass->setDepthWriteEnabled( true );
    pass->setLightingEnabled( false );
    pass->setSceneBlending( Ogre::SBT_ADD );
    pass->setAlphaRejectFunction( Ogre::CMPF_GREATER );
    pass->setAlphaRejectValue( 0 );
    tex = pass->createTextureUnitState();
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

    DestroyVertexBuffers();
}



void
Background2D::InputDebug( const Event& event )
{
    if( cv_background2d_manual.GetB() == true )
    {
        if( event.type == ET_KEY_IMPULSE && event.param1 == OIS::KC_W )
        {
            m_PositionReal.y += 2;
        }
        else if( event.type == ET_KEY_IMPULSE && event.param1 == OIS::KC_A )
        {
            m_PositionReal.x += 2;
        }
        else if( event.type == ET_KEY_IMPULSE && event.param1 == OIS::KC_S )
        {
            m_PositionReal.y -= 2;
        }
        else if( event.type == ET_KEY_IMPULSE && event.param1 == OIS::KC_D )
        {
            m_PositionReal.x -= 2;
        }

        CameraManager::getSingleton().Set2DScroll( m_PositionReal );
    }
}



void
Background2D::Update()
{
    for( unsigned int i = 0; i < m_AnimationPlayed.size(); ++i )
    {
        for( unsigned int j = 0; j < m_Animations.size(); ++j )
        {
            if( m_Animations[ j ]->GetName() == m_AnimationPlayed[ i ].name )
            {
                float delta_time = Timer::getSingleton().GetGameTimeDelta();
                float time = m_Animations[ j ]->GetTime();
                float end_time = m_Animations[ j ]->GetLength();

                // if animation ended
                if( time + delta_time >= end_time )
                {
                    // set to last frame of animation
                    if( time != end_time )
                    {
                        m_Animations[ j ]->SetTime( end_time );
                    }

                    if( m_AnimationPlayed[ i ].state == Background2DAnimation::ONCE )
                    {
                        for( unsigned int k = 0; k < m_AnimationPlayed[ i ].sync.size(); ++k )
                        {
                            ScriptManager::getSingleton().ContinueScriptExecution( m_AnimationPlayed[ i ].sync[ k ] );
                        }
                        m_AnimationPlayed[ i ].sync.clear();
                        m_AnimationPlayed[ i ].name = ""; // mark to erase this way
                    }
                    else // LOOPED
                    {
                        // in case of looped we need to sync with end
                        m_Animations[ j ]->SetTime( time + delta_time - end_time );
                    }
                }
                else
                {
                    m_Animations[ j ]->AddTime( delta_time );
                }
            }
        }
    }



    // remove stopped animations
    std::vector< AnimationPlayed >::iterator i = m_AnimationPlayed.begin();
    for( ; i != m_AnimationPlayed.end(); )
    {
        if( ( *i ).name == "" )
        {
            i = m_AnimationPlayed.erase( i );
        }
        else
        {
            ++i;
        }
    }
}



void
Background2D::UpdateDebug()
{
    if( m_Position != m_PositionReal )
    {
        if( cv_background2d_manual.GetB() != true )
        {
            m_PositionReal = m_Position;
            CameraManager::getSingleton().Set2DScroll( m_Position );
        }
    }

    if( cv_debug_background2d.GetB() == true )
    {
        DEBUG_DRAW.SetTextAlignment( DEBUG_DRAW.LEFT );
        DEBUG_DRAW.SetScreenSpace( true );
        DEBUG_DRAW.SetColour( Ogre::ColourValue( 0.0, 0.8, 0.8, 1 ) );
        for( unsigned int i = 0; i < m_AnimationPlayed.size(); ++i )
        {
            DEBUG_DRAW.Text( 150, 34 + i * 12, "Background 2D animation: " + m_AnimationPlayed[ i ].name );
        }
    }
}



void
Background2D::OnResize()
{
    float scr_width = Ogre::Root::getSingleton().getRenderTarget( "QGearsWindow" )->getViewport( 0 )->getActualWidth();
    float scr_height = Ogre::Root::getSingleton().getRenderTarget( "QGearsWindow" )->getViewport( 0 )->getActualHeight();

    float scaler = scr_height / 720.0f;

    for( unsigned int i = 0; i < m_Tiles.size(); ++i )
    {
        float new_x1 = ( m_Tiles[ i ].x * scaler / scr_width ) * 2 - 1;
        float new_y1 = -( ( m_Tiles[ i ].y / 720.0f ) * 2 - 1 );
        float new_x2 = ( ( m_Tiles[ i ].x + m_Tiles[ i ].width ) * scaler / scr_width ) * 2 - 1;
        float new_y2 = -( ( m_Tiles[ i ].y / 720.0f ) * 2 - 1 );
        float new_x3 = ( ( m_Tiles[ i ].x + m_Tiles[ i ].width ) * scaler / scr_width ) * 2 - 1;
        float new_y3 = -( ( ( m_Tiles[ i ].y + m_Tiles[ i ].height ) / 720.0f ) * 2 - 1 );
        float new_x4 = ( m_Tiles[ i ].x * scaler / scr_width ) * 2 - 1;
        float new_y4 = -( ( ( m_Tiles[ i ].y + m_Tiles[ i ].height ) / 720.0f ) * 2 - 1 );

        new_x1 += 1;
        new_y1 -= 1;
        new_x2 += 1;
        new_y2 -= 1;
        new_x3 += 1;
        new_y3 -= 1;
        new_x4 += 1;
        new_y4 -= 1;

        Ogre::HardwareVertexBufferSharedPtr vertex_buffer;

        if( m_Tiles[ i ].blending == Background2D::ALPHA )
        {
            vertex_buffer = m_AlphaVertexBuffer;
        }
        else if( m_Tiles[ i ].blending == Background2D::ADD )
        {
            vertex_buffer = m_AddVertexBuffer;
        }

        float* writeIterator = ( float* )vertex_buffer->lock( Ogre::HardwareBuffer::HBL_NORMAL );

        writeIterator += m_Tiles[ i ].start_vertex_index * 9;

        *writeIterator++ = new_x1;
        *writeIterator++ = new_y1;
        writeIterator += 7;

        *writeIterator++ = new_x2;
        *writeIterator++ = new_y2;
        writeIterator += 7;

        *writeIterator++ = new_x3;
        *writeIterator++ = new_y3;
        writeIterator += 7;

        *writeIterator++ = new_x1;
        *writeIterator++ = new_y1;
        writeIterator += 7;

        *writeIterator++ = new_x3;
        *writeIterator++ = new_y3;
        writeIterator += 7;

        *writeIterator++ = new_x4;
        *writeIterator++ = new_y4;

        vertex_buffer->unlock();
    }



    SetScroll( GetScroll() );
}



void
Background2D::Clear()
{
    m_ScrollEntity = NULL;
    m_ScrollPositionStart = Ogre::Vector2::ZERO;
    m_ScrollPositionEnd = Ogre::Vector2::ZERO;
    m_ScrollSeconds = 0;
    m_ScrollCurrentSeconds = 0;
    m_Position = Ogre::Vector2::ZERO;
    m_PositionReal = Ogre::Vector2::ZERO;
    UnsetScroll();

    for( unsigned int i = 0; i < m_Animations.size(); ++i )
    {
        delete m_Animations[ i ];
    }
    m_Animations.clear();

    for( unsigned int i = 0; i < m_AnimationPlayed.size(); ++i )
    {
        for( unsigned int j = 0; j < m_AnimationPlayed[ i ].sync.size(); ++j )
        {
            ScriptManager::getSingleton().ContinueScriptExecution( m_AnimationPlayed[ i ].sync[ j ] );
        }
    }
    m_AnimationPlayed.clear();

    m_Tiles.clear();
    DestroyVertexBuffers();
    CreateVertexBuffers();
}



void
Background2D::ScriptAutoScrollToEntity( Entity* entity )
{
    m_ScrollEntity = entity;
}



Entity*
Background2D::GetAutoScrollEntity() const
{
    return m_ScrollEntity;
}



void
Background2D::ScriptScrollToPosition( const float x, const float y, const ScrollType type, const float seconds )
{
    LOG_TRIVIAL( "[SCRIPT] Background2d set scroll to position \"" + Ogre::StringConverter::toString( Ogre::Vector2( x, y ) ) + "\"." );

    Ogre::Vector2 position = Ogre::Vector2( x, y );

    m_ScrollEntity = NULL;

    if( type == Background2D::NONE )
    {
        SetScroll( position );
        return;
    }

    m_ScrollPositionStart = GetScroll();
    m_ScrollPositionEnd = position;
    m_ScrollType = type;
    m_ScrollSeconds = seconds;
    m_ScrollCurrentSeconds = 0;
}



int
Background2D::ScriptScrollSync()
{
    ScriptId script = ScriptManager::getSingleton().GetCurrentScriptId();

    LOG_TRIVIAL( "[SCRIPT] Wait Background2d scroll for function \"" + script.function + "\" in script entity \"" + script.entity + "\"." );

    m_ScrollSync.push_back( script );
    return -1;
}



void
Background2D::UnsetScroll()
{
    m_ScrollType = Background2D::NONE;

    for( unsigned int i = 0; i < m_ScrollSync.size(); ++i )
    {
        ScriptManager::getSingleton().ContinueScriptExecution( m_ScrollSync[ i ] );
    }
    m_ScrollSync.clear();
}



const Ogre::Vector2&
Background2D::GetScrollPositionStart() const
{
    return m_ScrollPositionStart;
}



const Ogre::Vector2&
Background2D::GetScrollPositionEnd() const
{
    return m_ScrollPositionEnd;
}



Background2D::ScrollType
Background2D::GetScrollType() const
{
    return m_ScrollType;
}



float
Background2D::GetScrollSeconds() const
{
    return m_ScrollSeconds;
}



void
Background2D::SetScrollCurrentSeconds( const float seconds )
{
    m_ScrollCurrentSeconds = seconds;
}



float
Background2D::GetScrollCurrentSeconds() const
{
    return m_ScrollCurrentSeconds;
}



void
Background2D::SetScroll( const Ogre::Vector2& position )
{
    m_Position = position;

    float scr_width = Ogre::Root::getSingleton().getRenderTarget( "QGearsWindow" )->getViewport( 0 )->getActualWidth() / 2.0f;
    float scr_height = Ogre::Root::getSingleton().getRenderTarget( "QGearsWindow" )->getViewport( 0 )->getActualHeight() / 2.0f;
    m_Position.x = ( m_Position.x + scr_width > m_RangeMaxX ) ? m_RangeMaxX - scr_width : m_Position.x;
    m_Position.x = ( m_Position.x - scr_width < m_RangeMinX ) ? m_RangeMinX + scr_width : m_Position.x;
    m_Position.y = ( m_Position.y + scr_height > m_RangeMaxY ) ? m_RangeMaxY - scr_height : m_Position.y;
    m_Position.y = ( m_Position.y - scr_height < m_RangeMinY ) ? m_RangeMinY + scr_height : m_Position.y;

    if( cv_background2d_manual.GetB() != true )
    {
        m_PositionReal = m_Position;
        CameraManager::getSingleton().Set2DScroll( m_PositionReal );
    }
}



const Ogre::Vector2&
Background2D::GetScroll() const
{
    return m_Position;
}



void
Background2D::SetImage( const Ogre::String& image )
{
    Ogre::Pass* pass = m_AlphaMaterial->getTechnique( 0 )->getPass( 0 );
    Ogre::TextureUnitState* tex = pass->getTextureUnitState( 0 );
    tex->setTextureName( image );
    pass = m_AddMaterial->getTechnique( 0 )->getPass( 0 );
    tex = pass->getTextureUnitState( 0 );
    tex->setTextureName( image );
}



void
Background2D::SetRange( const int min_x, const int min_y, const int max_x, const int max_y )
{
    // if screen range lesser than screen size - expand screen range to screen size
    float scr_width = Ogre::Root::getSingleton().getRenderTarget( "QGearsWindow" )->getViewport( 0 )->getActualWidth() / 2.0f;
    float scr_height = Ogre::Root::getSingleton().getRenderTarget( "QGearsWindow" )->getViewport( 0 )->getActualHeight() / 2.0f;
    m_RangeMinX = ( min_x > -scr_width ) ? -scr_width : min_x;
    m_RangeMinY = ( min_y > -scr_height ) ? -scr_height : min_y;
    m_RangeMaxX = ( max_x < scr_width ) ? scr_width : max_x;
    m_RangeMaxY = ( max_y < scr_height ) ? scr_height : max_y;
}



void
Background2D::AddTile( const int x, const int y, const int width, const int height, const float depth, const float u1, const float v1, const float u2, const float v2, const Blending blending )
{
    Ogre::RenderOperation render_op;
    Ogre::HardwareVertexBufferSharedPtr vertex_buffer;
    unsigned int max_vertex_count;

    if( blending == Background2D::ALPHA )
    {
        render_op = m_AlphaRenderOp;
        vertex_buffer = m_AlphaVertexBuffer;
        max_vertex_count = m_AlphaMaxVertexCount;
    }
    else if( blending == Background2D::ADD )
    {
        render_op = m_AddRenderOp;
        vertex_buffer = m_AddVertexBuffer;
        max_vertex_count = m_AddMaxVertexCount;
    }
    else
    {
        LOG_ERROR( "Unknown blending type." );
        return;
    }

    if( render_op.vertexData->vertexCount + 6 > max_vertex_count )
    {
        LOG_ERROR( "Max number of tiles reached. Can't create more than " + Ogre::StringConverter::toString( max_vertex_count / 6 ) + " tiles." );
        return;
    }

    Tile tile;
    tile.x = x;
    tile.y = y;
    tile.width = width;
    tile.height = height;
    tile.start_vertex_index = render_op.vertexData->vertexCount;
    tile.blending = blending;
    m_Tiles.push_back( tile );

    float scr_width = Ogre::Root::getSingleton().getRenderTarget( "QGearsWindow" )->getViewport( 0 )->getActualWidth();
    float scr_height = Ogre::Root::getSingleton().getRenderTarget( "QGearsWindow" )->getViewport( 0 )->getActualHeight();

    float scaler = scr_height / 720.0f;

    float new_x1 = ( x * scaler / scr_width ) * 2 - 1;
    float new_y1 = -( ( y / 720.0f ) * 2 - 1 );
    float new_x2 = ( ( x + width ) * scaler / scr_width ) * 2 - 1;
    float new_y2 = -( ( y / 720.0f ) * 2 - 1 );
    float new_x3 = ( ( x + width ) * scaler / scr_width ) * 2 - 1;
    float new_y3 = -( ( ( y + height ) / 720.0f ) * 2 - 1 );
    float new_x4 = ( x * scaler / scr_width ) * 2 - 1;
    float new_y4 = -( ( ( y + height ) / 720.0f ) * 2 - 1 );

    new_x1 += 1;
    new_y1 -= 1;
    new_x2 += 1;
    new_y2 -= 1;
    new_x3 += 1;
    new_y3 -= 1;
    new_x4 += 1;
    new_y4 -= 1;

    float* writeIterator = ( float* )vertex_buffer->lock( Ogre::HardwareBuffer::HBL_NORMAL );
    writeIterator += render_op.vertexData->vertexCount * 9;

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

    render_op.vertexData->vertexCount += 6;

    vertex_buffer->unlock();
}



void
Background2D::UpdateTileUV( const unsigned int tile_id, const float u1, const float v1, const float u2, const float v2 )
{
    if( tile_id >= m_Tiles.size() )
    {
        LOG_ERROR( "Tile with id " + Ogre::StringConverter::toString( tile_id ) + " doesn't exist." );
        return;
    }

    Ogre::HardwareVertexBufferSharedPtr vertex_buffer;

    if( m_Tiles[ tile_id ].blending == Background2D::ALPHA )
    {
        vertex_buffer = m_AlphaVertexBuffer;
    }
    else if( m_Tiles[ tile_id ].blending == Background2D::ADD )
    {
        vertex_buffer = m_AddVertexBuffer;
    }

    float* writeIterator = ( float* )vertex_buffer->lock( Ogre::HardwareBuffer::HBL_NORMAL );

    writeIterator += m_Tiles[ tile_id ].start_vertex_index * 9;

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

    vertex_buffer->unlock();
}



void
Background2D::AddAnimation( Background2DAnimation* animation )
{
    m_Animations.push_back( animation );
}



void
Background2D::PlayAnimation( const Ogre::String& animation, const Background2DAnimation::State state )
{
    bool found = false;

    for( unsigned int i = 0; i < m_Animations.size(); ++i )
    {
        if( m_Animations[ i ]->GetName() == animation )
        {
            found = true;
            m_Animations[ i ]->SetTime( 0 );
            m_Animations[ i ]->AddTime( 0 );
        }
    }

    for( unsigned int i = 0; i < m_AnimationPlayed.size(); ++i )
    {
        if( m_AnimationPlayed[ i ].name == animation )
        {
            m_AnimationPlayed.erase( m_AnimationPlayed.begin() + i );
        }
    }

    if( found == true )
    {
        AnimationPlayed anim;
        anim.name = animation;
        anim.state = state;
        m_AnimationPlayed.push_back( anim );
    }
    else
    {
        LOG_ERROR( "Background2D doesn't has animation \"" + animation + "\"." );
    }
}



void
Background2D::ScriptPlayAnimationLooped( const char* name )
{
    PlayAnimation( Ogre::String( name ), Background2DAnimation::LOOPED );
}



void
Background2D::ScriptPlayAnimationOnce( const char* name )
{
    PlayAnimation( Ogre::String( name ), Background2DAnimation::ONCE );
}



int
Background2D::ScriptAnimationSync( const char* animation )
{
    for( unsigned int i = 0; i < m_AnimationPlayed.size(); ++i )
    {
        if( m_AnimationPlayed[ i ].name == animation )
        {
            ScriptId script = ScriptManager::getSingleton().GetCurrentScriptId();
            m_AnimationPlayed[ i ].sync.push_back( script );
            return -1;
        }
    }

    return 1;
}



void
Background2D::renderQueueEnded( Ogre::uint8 queueGroupId, const Ogre::String& invocation, bool& repeatThisInvocation )
{
    if( cv_show_background2d.GetB() == false )
    {
        return;
    }



    if( queueGroupId == Ogre::RENDER_QUEUE_MAIN )
    {
        m_RenderSystem->_setWorldMatrix( Ogre::Matrix4::IDENTITY );
        m_RenderSystem->_setProjectionMatrix( Ogre::Matrix4::IDENTITY );

        float width = Ogre::Root::getSingleton().getRenderTarget( "QGearsWindow" )->getViewport( 0 )->getActualWidth();
        float height = Ogre::Root::getSingleton().getRenderTarget( "QGearsWindow" )->getViewport( 0 )->getActualHeight();
        Ogre::Matrix4 view;
        view.makeTrans( Ogre::Vector3( m_PositionReal.x * 2 / width, -m_PositionReal.y * 2 / height, 0 ) );
        m_RenderSystem->_setViewMatrix( view );

        if( m_AlphaRenderOp.vertexData->vertexCount != 0 )
        {
            m_SceneManager->_setPass( m_AlphaMaterial->getTechnique( 0 )->getPass( 0 ), true, false );
            m_RenderSystem->_render( m_AlphaRenderOp );
        }

        if( m_AddRenderOp.vertexData->vertexCount != 0 )
        {
            m_SceneManager->_setPass( m_AddMaterial->getTechnique( 0 )->getPass( 0 ), true, false );
            m_RenderSystem->_render( m_AddRenderOp );
        }
    }
}



void
Background2D::CreateVertexBuffers()
{
    m_AlphaMaxVertexCount = 2048 * 6;
    m_AlphaRenderOp.vertexData = new Ogre::VertexData;
    m_AlphaRenderOp.vertexData->vertexStart = 0;

    Ogre::VertexDeclaration* vDecl = m_AlphaRenderOp.vertexData->vertexDeclaration;

    size_t offset = 0;
    vDecl->addElement( 0, 0, Ogre::VET_FLOAT3, Ogre::VES_POSITION );
    offset += Ogre::VertexElement::getTypeSize( Ogre::VET_FLOAT3 );
    vDecl->addElement( 0, offset, Ogre::VET_FLOAT4, Ogre::VES_DIFFUSE );
    offset += Ogre::VertexElement::getTypeSize( Ogre::VET_FLOAT4 );
    vDecl->addElement( 0, offset, Ogre::VET_FLOAT2, Ogre::VES_TEXTURE_COORDINATES );

    m_AlphaVertexBuffer = Ogre::HardwareBufferManager::getSingletonPtr()->createVertexBuffer( vDecl->getVertexSize( 0 ), m_AlphaMaxVertexCount, Ogre::HardwareBuffer::HBU_DYNAMIC_WRITE_ONLY, false );

    m_AlphaRenderOp.vertexData->vertexBufferBinding->setBinding( 0, m_AlphaVertexBuffer );
    m_AlphaRenderOp.operationType = Ogre::RenderOperation::OT_TRIANGLE_LIST;
    m_AlphaRenderOp.useIndexes = false;



    m_AddMaxVertexCount = 256 * 6;
    m_AddRenderOp.vertexData = new Ogre::VertexData;
    m_AddRenderOp.vertexData->vertexStart = 0;

    vDecl = m_AddRenderOp.vertexData->vertexDeclaration;

    offset = 0;
    vDecl->addElement( 0, 0, Ogre::VET_FLOAT3, Ogre::VES_POSITION );
    offset += Ogre::VertexElement::getTypeSize( Ogre::VET_FLOAT3 );
    vDecl->addElement( 0, offset, Ogre::VET_FLOAT4, Ogre::VES_DIFFUSE );
    offset += Ogre::VertexElement::getTypeSize( Ogre::VET_FLOAT4 );
    vDecl->addElement( 0, offset, Ogre::VET_FLOAT2, Ogre::VES_TEXTURE_COORDINATES );

    m_AddVertexBuffer = Ogre::HardwareBufferManager::getSingletonPtr()->createVertexBuffer( vDecl->getVertexSize( 0 ), m_AddMaxVertexCount, Ogre::HardwareBuffer::HBU_DYNAMIC_WRITE_ONLY, false );

    m_AddRenderOp.vertexData->vertexBufferBinding->setBinding( 0, m_AddVertexBuffer );
    m_AddRenderOp.operationType = Ogre::RenderOperation::OT_TRIANGLE_LIST;
    m_AddRenderOp.useIndexes = false;
}



void
Background2D::DestroyVertexBuffers()
{
    delete m_AlphaRenderOp.vertexData;
    m_AlphaRenderOp.vertexData = 0;
    m_AlphaVertexBuffer.setNull();
    m_AlphaMaxVertexCount = 0;

    delete m_AddRenderOp.vertexData;
    m_AddRenderOp.vertexData = 0;
    m_AddVertexBuffer.setNull();
    m_AddMaxVertexCount = 0;
}
