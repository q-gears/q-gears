#include "UiTextArea.h"

#include <OgreFontManager.h>
#include <OgreHardwareBufferManager.h>
#include <OgreMaterialManager.h>

#include "Logger.h"
#include "UiManager.h"



UiTextArea::UiTextArea( const Ogre::String& name ):
    UiWidget( name )
{
    Initialise();
}



UiTextArea::UiTextArea( const Ogre::String& name, const Ogre::String& path_name, UiWidget* parent ):
    UiWidget( name, path_name, parent )
{
    Initialise();
}



UiTextArea::~UiTextArea()
{
    DestroyVertexBuffer();
}



void
UiTextArea::Initialise()
{
    m_Font = NULL;
    m_MaxLetters = 0;
    m_TextAlignment = UiTextArea::LEFT;
    m_Text = "";
    m_TextNode = NULL;

    m_SceneManager = Ogre::Root::getSingleton().getSceneManager( "Scene" );
    m_RenderSystem = Ogre::Root::getSingletonPtr()->getRenderSystem();

    CreateVertexBuffer();
}



void
UiTextArea::Update()
{
    UiWidget::Update();
}



void
UiTextArea::OnResize()
{
    UiWidget::OnResize();

    UpdateGeometry();
}



void
UiTextArea::Render()
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
UiTextArea::SetTextAlignment( const TextAlignment alignment )
{
    m_TextAlignment = alignment;
}



void
UiTextArea::SetText( const Ogre::UTFString& text )
{
    m_Text = text;
}



void
UiTextArea::SetText( TiXmlNode* text )
{
    m_TextNode = text;
}



void
UiTextArea::SetFont( const Ogre::String& font )
{
    m_Font = UiManager::getSingleton().GetFont( font );

    if( m_Font == NULL )
    {
        LOG_ERROR( "Could not find font \"" + font + "\" for \"Ui." + m_PathName + "\"." );
        return;
    }

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
    tex->setTextureName( m_Font->GetImageName() );
    tex->setNumMipmaps( -1 );
    tex->setTextureFiltering( Ogre::TFO_NONE );
}



void
UiTextArea::UpdateGeometry()
{
    if( m_Font == NULL )
    {
        LOG_ERROR( "Font for \"Ui." + m_PathName + "\" if not set." );
        return;
    }

    if( m_Text.size() > m_MaxLetters )
    {
        LOG_ERROR( "Max number of text reached in \"Ui." + m_PathName + "\". Can't render text \"" + m_Text + "\". Max number of letters is " + Ogre::StringConverter::toString( m_MaxLetters ) + "." );
        return;
    }

    float length = 0;
    if( m_TextAlignment != LEFT )
    {
        for( int i = 0; i < m_Text.size(); ++i )
        {
            UiCharData char_data = m_Font->GetCharData( m_Text[ i ] );
            length += ( char_data.pre + char_data.width + char_data.post ) * m_FinalScale.x * m_ScreenHeight / 720.0f;
        }

        if( m_TextAlignment == CENTER )
        {
            length /= 2;
        }
    }



    TextBlockData data;
    data.local_x1 = -m_FinalOrigin.x;
    data.local_y1 = -m_FinalOrigin.y;
    data.position = 0;

    TextStyle style;
    style.colour = m_Colour1;

    if( m_TextNode != NULL )
    {
        SetTextGeometryFromNode( m_TextNode, data, style );
    }
    else
    {
        SetTextGeometry( m_Text, data, style );
    }
}



void
UiTextArea::SetTextGeometryFromNode( TiXmlNode* node, TextBlockData& data, const TextStyle& style )
{
    while( node != NULL )
    {
        switch( node->Type() )
        {
            case TiXmlNode::TINYXML_TEXT:
            {
                TiXmlText* childText = node->ToText();
                if( childText )
                {
                    SetTextGeometry( childText->Value(), data, style );
                }
            }
            break;

            case TiXmlNode::TINYXML_ELEMENT:
            {
                TextStyle style_child;
                style_child.colour = style.colour;

                Ogre::String name = node->ValueStr();
                if( name == "colour" )
                {
                    style_child.colour = Ogre::StringConverter::parseColourValue( node->ToElement()->Attribute( "value" ) );
                }

                TiXmlNode* node_child = node->FirstChild();
                SetTextGeometryFromNode( node_child, data, style_child );
            }
            break;
        }

        node = node->NextSibling();
    }
}



void
UiTextArea::SetTextGeometry( const Ogre::UTFString& text, TextBlockData& data, const TextStyle& style )
{
    float* writeIterator = ( float* ) m_VertexBuffer->lock( Ogre::HardwareBuffer::HBL_NORMAL );
    writeIterator += data.position * 9 * 6;
    m_RenderOp.vertexData->vertexCount = data.position * 6;


    float local_x1 = data.local_x1;
    float local_y1 = data.local_y1;
    float x = m_FinalTranslate.x;
    float y = m_FinalTranslate.y;

    for( int i = 0; i < text.size(); ++i )
    {
        UiCharData char_data = m_Font->GetCharData( text[ i ] );

        local_x1 += char_data.pre * m_FinalScale.x * m_ScreenHeight / 720.0f;
        float local_x2 = local_x1 + char_data.width * m_FinalScale.x * m_ScreenHeight / 720.0f;
        float local_y2 = local_y1 + char_data.height * m_FinalScale.y * m_ScreenHeight / 720.0f;

        int x1, y1, x2, y2, x3, y3, x4, y4;

        //LOG_ERROR( m_Name );
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

        local_x1 += ( char_data.width + char_data.post ) * m_FinalScale.x * m_ScreenHeight / 720.0f;

        float width = m_Font->GetImageWidth();
        float height = m_Font->GetImageHeight();
        float left = ( float )char_data.x / width;
        float right = ( float )( char_data.x + char_data.width ) / width;
        float top = ( float )char_data.y / height;
        float bottom = ( float )( char_data.y + char_data.height ) / height;

        //LOG_ERROR( "width = " + Ogre::StringConverter::toString( width ) + "." );
        //LOG_ERROR( "height = " + Ogre::StringConverter::toString( height ) + "." );
        //LOG_ERROR( "char_data.x = " + Ogre::StringConverter::toString( char_data.x ) + "." );
        //LOG_ERROR( "char_data.y = " + Ogre::StringConverter::toString( char_data.y ) + "." );
        //LOG_ERROR( "char_data.width = " + Ogre::StringConverter::toString( char_data.width ) + "." );
        //LOG_ERROR( "char_data.height = " + Ogre::StringConverter::toString( char_data.height ) + "." );
        //LOG_ERROR( "left = " + Ogre::StringConverter::toString( left ) + "." );
        //LOG_ERROR( "right = " + Ogre::StringConverter::toString( right ) + "." );
        //LOG_ERROR( "top = " + Ogre::StringConverter::toString( top ) + "." );
        //LOG_ERROR( "bottom = " + Ogre::StringConverter::toString( bottom ) + "." );

        *writeIterator++ = new_x1;
        *writeIterator++ = new_y1;
        *writeIterator++ = 0; // z
        *writeIterator++ = style.colour.r;
        *writeIterator++ = style.colour.g;
        *writeIterator++ = style.colour.b;
        *writeIterator++ = style.colour.a;
        *writeIterator++ = left;
        *writeIterator++ = top;

        *writeIterator++ = new_x2;
        *writeIterator++ = new_y2;
        *writeIterator++ = 0; // z
        *writeIterator++ = style.colour.r;
        *writeIterator++ = style.colour.g;
        *writeIterator++ = style.colour.b;
        *writeIterator++ = style.colour.a;
        *writeIterator++ = right;
        *writeIterator++ = top;

        *writeIterator++ = new_x3;
        *writeIterator++ = new_y3;
        *writeIterator++ = 0; // z
        *writeIterator++ = style.colour.r;
        *writeIterator++ = style.colour.g;
        *writeIterator++ = style.colour.b;
        *writeIterator++ = style.colour.a;
        *writeIterator++ = right;
        *writeIterator++ = bottom;

        *writeIterator++ = new_x1;
        *writeIterator++ = new_y1;
        *writeIterator++ = 0; // z
        *writeIterator++ = style.colour.r;
        *writeIterator++ = style.colour.g;
        *writeIterator++ = style.colour.b;
        *writeIterator++ = style.colour.a;
        *writeIterator++ = left;
        *writeIterator++ = top;

        *writeIterator++ = new_x3;
        *writeIterator++ = new_y3;
        *writeIterator++ = 0; // z
        *writeIterator++ = style.colour.r;
        *writeIterator++ = style.colour.g;
        *writeIterator++ = style.colour.b;
        *writeIterator++ = style.colour.a;
        *writeIterator++ = right;
        *writeIterator++ = bottom;

        *writeIterator++ = new_x4;
        *writeIterator++ = new_y4;
        *writeIterator++ = 0; // z
        *writeIterator++ = style.colour.r;
        *writeIterator++ = style.colour.g;
        *writeIterator++ = style.colour.b;
        *writeIterator++ = style.colour.a;
        *writeIterator++ = left;
        *writeIterator++ = bottom;

        m_RenderOp.vertexData->vertexCount += 6;
        data.position += 1;
    }

    m_VertexBuffer->unlock();

    data.local_x1 = local_x1;
    data.local_y1 = local_y1;
}



void
UiTextArea::CreateVertexBuffer()
{
    m_MaxLetters = 1024;
    m_RenderOp.vertexData = new Ogre::VertexData;
    m_RenderOp.vertexData->vertexStart = 0;

    Ogre::VertexDeclaration* vDecl = m_RenderOp.vertexData->vertexDeclaration;

    size_t offset = 0;
    vDecl->addElement( 0, 0, Ogre::VET_FLOAT3, Ogre::VES_POSITION );
    offset += Ogre::VertexElement::getTypeSize( Ogre::VET_FLOAT3 );
    vDecl->addElement( 0, offset, Ogre::VET_FLOAT4, Ogre::VES_DIFFUSE );
    offset += Ogre::VertexElement::getTypeSize( Ogre::VET_FLOAT4 );
    vDecl->addElement( 0, offset, Ogre::VET_FLOAT2, Ogre::VES_TEXTURE_COORDINATES );

    m_VertexBuffer = Ogre::HardwareBufferManager::getSingletonPtr()->createVertexBuffer( vDecl->getVertexSize( 0 ), m_MaxLetters * 6, Ogre::HardwareBuffer::HBU_DYNAMIC_WRITE_ONLY, false );

    m_RenderOp.vertexData->vertexBufferBinding->setBinding( 0, m_VertexBuffer );
    m_RenderOp.operationType = Ogre::RenderOperation::OT_TRIANGLE_LIST;
    m_RenderOp.useIndexes = false;
}



void
UiTextArea::DestroyVertexBuffer()
{
    delete m_RenderOp.vertexData;
    m_RenderOp.vertexData = 0;
    m_VertexBuffer.setNull();
    m_MaxLetters = 0;
}
