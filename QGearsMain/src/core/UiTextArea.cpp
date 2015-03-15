#include <OgreFontManager.h>
#include <OgreHardwareBufferManager.h>
#include <OgreMaterialManager.h>

#include "core/Logger.h"
#include "core/UiManager.h"
#include "core/UiTextArea.h"
#include "core/TextManager.h"
#include "core/Timer.h"
#include "core/UiSprite.h"
#include "core/Utilites.h"

UiTextArea::UiTextArea(const Ogre::String& name):
    UiWidget(name)
{
    Initialise();
}


UiTextArea::UiTextArea(const Ogre::String& name, const Ogre::String& path_name, UiWidget* parent):
    UiWidget(name, path_name, parent)
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
    m_Font = nullptr;
    m_MaxLetters = 0;
    m_TextAlign = UiTextArea::LEFT;
    m_TextLimit = 0;
    m_TextPrintSpeed = -1; // -1 instant
    m_TextPrintSpeedMod = 1;
    m_TextState = TS_DONE;
    m_TextYOffset = 0;
    m_TextYOffsetTarget = 0;
    m_PauseTime = 0;
    m_NextPageStart = 0;

    m_PaddingTop = 0;
    m_PaddingRight = 0;
    m_PaddingBottom = 0;
    m_PaddingLeft = 0;

    m_NextPressed = false;
    m_NextRepeated = false;

    m_Timer = false;
    m_TimerTime = 0;

    TextVariable var;
    var.name = "UITextAreaTimer";
    var.value = "00:00";
    m_TextVariable.push_back( var );
    m_SceneManager = Ogre::Root::getSingleton().getSceneManager("Scene");
    m_RenderSystem = Ogre::Root::getSingletonPtr()->getRenderSystem();

    CreateVertexBuffer();
}


void
UiTextArea::Update()
{
    if( m_Visible == true )
    {
        if( m_Timer == true )
        {
            int time = Timer::getSingleton().GetGameTimer();
            if( time > 5999 ) // 99:59
            {
                time = 5999;
            }

            if( time != m_TimerTime )
            {
                m_TimerTime = time;

                Ogre::String time_string = "";
                time_string += Ogre::StringConverter::toString( m_TimerTime / 60, 2, '0' );
                time_string += ( m_TimerTime & 1 ) ? ":" : ";";
                time_string += Ogre::StringConverter::toString( m_TimerTime % 60, 2, '0' );
                SetVariable( "UITextAreaTimer", time_string );
            }
        }



        switch( m_TextState )
        {
            case TS_SHOW_TEXT:
            {
                if( m_TextPrintSpeed == -1 )
                {
                    m_TextLimit = m_MaxLetters;
                }
                else
                {
                    float time = Timer::getSingleton().GetGameTimeDelta() * 30;
                    float addition, limit;

                    if( m_NextPressed == true || m_NextRepeated == true )
                    {
                        m_TextPrintSpeedMod += ( m_TextPrintSpeedMod >= 128 ) ? 0 : 1.0f * time;
                    }
                    else
                    {
                        m_TextPrintSpeedMod -= ( m_TextPrintSpeedMod <= 1) ? 0 : 1.0f * time;
                    }

                    if( m_TextPrintSpeed < 128 )
                    {
                        addition = ( ( 128 - m_TextPrintSpeed ) / 32 ) + 2;
                        limit = 1;
                    }
                    else
                    {
                        addition = 2;
                        limit = ( ( m_TextPrintSpeed - 128 ) / 32 ) + 1;
                    }

                    float char_to_add = ( limit * m_TextPrintSpeedMod / 16 + addition ) / limit;
                    m_TextLimit += time * char_to_add;
                }

                m_UpdateTransformation = true;
            }
            break;

            case TS_SCROLL_TEXT:
            {
                m_TextYOffset -= m_Font->GetHeight() *  Timer::getSingleton().GetGameTimeDelta() / m_TextScrollTime;
                if( m_TextYOffset <= m_TextYOffsetTarget )
                {
                    m_TextYOffset = m_TextYOffsetTarget;
                    m_TextPrintSpeedMod = 1;
                    m_TextState = TS_SHOW_TEXT;
                }

                m_UpdateTransformation = true;
            }
            break;

            case TS_PAUSE_OK:
            {
                if( m_NextPressed == true )
                {
                    m_TextPrintSpeedMod = 1;
                    m_TextState = TS_SHOW_TEXT;
                }
            }
            break;

            case TS_PAUSE_TIME:
            {
                m_PauseTime -= Timer::getSingleton().GetGameTimeDelta();

                if( m_PauseTime <= 0 )
                {
                    m_TextPrintSpeedMod = 1;
                    m_TextState = TS_SHOW_TEXT;
                }
            }
            break;

            case TS_OVERFLOW:
            {
                if( m_NextPressed == true )
                {
                    m_TextYOffsetTarget = m_TextYOffset - m_Font->GetHeight();
                    m_TextState = TS_SCROLL_TEXT;
                }
            }
            break;

            case TS_NEXT_PAGE:
            {
                if( m_NextPressed == true )
                {
                    RemoveSpritesFromText( m_NextPageStart );
                    m_Text.erase( m_Text.begin(), m_Text.begin() + m_NextPageStart );

                    m_TextLimit = 0;
                    m_TextPrintSpeedMod = 1;
                    m_TextYOffset = 0;
                    m_TextYOffsetTarget = 0;
                    m_TextState = TS_SHOW_TEXT;
                }
            }
            break;
        }
    }



    m_NextPressed = false;
    m_NextRepeated = false;
    UiWidget::Update();
}


void
UiTextArea::Render()
{
    if( m_UpdateTransformation == false && m_Visible == true )
    {
        if(m_RenderOp.vertexData->vertexCount != 0)
        {
            m_RenderSystem->_setWorldMatrix(Ogre::Matrix4::IDENTITY);
            m_RenderSystem->_setProjectionMatrix(Ogre::Matrix4::IDENTITY);
            m_RenderSystem->_setViewMatrix(Ogre::Matrix4::IDENTITY);

            m_SceneManager->_setPass(m_Material->getTechnique(0)->getPass(0), true, false);

            m_RenderSystem->setScissorTest(true, m_ScissorLeft, m_ScissorTop, m_ScissorRight, m_ScissorBottom);
            m_RenderSystem->_render(m_RenderOp);
            m_RenderSystem->setScissorTest(false);
        }
    }

    UiWidget::Render();
}


void
UiTextArea::UpdateTransformation()
{
    UiWidget::UpdateTransformation();
    UpdateGeometry();
}



void
UiTextArea::InputPressed()
{
    m_NextPressed = true;
}



void
UiTextArea::InputRepeated()
{
    m_NextRepeated = true;
}



void
UiTextArea::SetTextAlign( const TextAlign align )
{
    m_TextAlign = align;
    m_UpdateTransformation = true;
}



void
UiTextArea::SetPadding( const float top, const float right, const float bottom, const float left )
{
    m_PaddingTop = top;
    m_PaddingRight = right;
    m_PaddingBottom = bottom;
    m_PaddingLeft = left;
}



void
UiTextArea::SetText( const Ogre::UTFString& text )
{
    TiXmlDocument doc;
    Ogre::UTFString xml_text = "<container>" + text + "</container>";
    doc.Parse( xml_text.asUTF8_c_str(), 0, TIXML_ENCODING_UTF8 );
    if( doc.Error() == true )
    {
        LOG_ERROR( "Can't parse text \"" + text + "\". TinyXml Error: " + doc.ErrorDesc() );
        return;
    }
    SetText( doc.RootElement() );
}



void
UiTextArea::SetText( TiXmlNode* text )
{
    if( text == NULL )
    {
        LOG_ERROR( "Text pointer is NULL." );
        return;
    }

    // reload font if language was changed
    if( m_Font != NULL )
    {
        Ogre::String language = m_Font->GetLanguage();
        if( language != "" )
        {
            if( TextManager::getSingleton().GetLanguage() != language )
            {
                SetFont( m_Font->GetName() );
            }
        }
    }

    TextClear();

    PrepareTextFromNode( text, m_Colour1 );
    m_TextState = TS_SHOW_TEXT;
    m_UpdateTransformation = true;

    if( m_Text.size() > m_MaxLetters )
    {
        m_Text.clear();
        LOG_ERROR( "Max number of text reached in \"" + m_PathName + "\". Can't render text from node. Max number of letters is " + Ogre::StringConverter::toString( m_MaxLetters ) + "." );
    }
}



void
UiTextArea::TextClear()
{
    RemoveSpritesFromText( m_Text.size() );
    m_Text.clear();
    m_TextLimit = 0;
    m_TextPrintSpeedMod = 1;
    m_TextYOffset = 0;
    m_TextYOffsetTarget = 0;
}


void
UiTextArea::RemoveSpritesFromText( const unsigned int end )
{
    for( unsigned int i = 0; i < end; ++i )
    {
        if( m_Text[ i ].sprite != NULL )
        {
            for( unsigned int j = 0; j < m_Children.size(); ++j )
            {
                if( m_Text[ i ].sprite == m_Children[ j ] )
                {
                    delete m_Children[ j ];
                    m_Children.erase( m_Children.begin() + j, m_Children.begin() + j + 1 );
                    break;
                }
            }
        }
    }
}

void
UiTextArea::SetFont(const Ogre::String& font)
{
    m_Font = UiManager::getSingleton().GetFont(font);

    if(m_Font == nullptr)
    {
        LOG_ERROR("Could not find font \"" + font + "\" for \"" + m_PathName + "\".");
        return;
    }

    m_Material = Ogre::MaterialManager::getSingleton().create("UiMaterials." + m_PathName, "General");
    Ogre::Pass* pass = m_Material->getTechnique(0)->getPass(0);
    pass->setVertexColourTracking(Ogre::TVC_AMBIENT);
    pass->setCullingMode(Ogre::CULL_NONE);
    pass->setDepthCheckEnabled(false);
    pass->setDepthWriteEnabled(false);
    pass->setLightingEnabled(false);
    pass->setSceneBlending(Ogre::SBT_TRANSPARENT_ALPHA);

    pass->setAlphaRejectFunction(Ogre::CMPF_GREATER);
    pass->setAlphaRejectValue(0);
    Ogre::TextureUnitState* tex = pass->createTextureUnitState();
    tex->setTextureName(m_Font->GetImageName());
    tex->setNumMipmaps(-1);
    tex->setTextureFiltering(Ogre::TFO_NONE);
    m_UpdateTransformation = true;
}



const UiFont*
UiTextArea::GetFont() const
{
    return m_Font;
}

void
UiTextArea::SetTextPrintSpeed( const float speed )
{
    m_TextPrintSpeed = speed;
}



void
UiTextArea::SetTextScrollTime( const float time )
{
    m_TextScrollTime = time;
}



void
UiTextArea::SetVariable( const Ogre::String& name, const Ogre::UTFString& value )
{
    if( name == "" )
    {
        return;
    }

    bool update = false;

    for( unsigned int i = 0; i < m_TextVariable.size(); ++i )
    {
        if( m_TextVariable[ i ].name == name )
        {
            m_TextVariable[ i ].value = value;
            update = true;

            for( unsigned int j = 0; j < m_Text.size(); ++j )
            {
                if( m_Text[ j ].variable == name )
                {
                    m_Text.erase( m_Text.begin() + j + 1, m_Text.begin() + j + 1 + m_Text[ j ].variable_len );
                }
            }
        }
    }

    if( update == false )
    {
        TextVariable var;
        var.name = name;
        var.value = value;
        m_TextVariable.push_back( var );
    }

    for( unsigned int i = 0; i < m_Text.size(); ++i )
    {
        if( m_Text[ i ].variable == name )
        {
            m_Text[ i ].variable_len = value.size();
            unsigned int j = 0;
            for( ; j < m_Text[ i ].variable_len; ++j )
            {
                TextChar text_char;
                text_char.char_code = value[ j ];
                text_char.colour = m_Text[ i ].colour;
                m_Text.insert( m_Text.begin() + i + 1 + j, text_char );
            }

            i += j;
        }
    }

    m_UpdateTransformation = true;
}



Ogre::UTFString
UiTextArea::GetVariable( const Ogre::String& name ) const
{
    for( unsigned int i = 0; i < m_TextVariable.size(); ++i )
    {
        if( m_TextVariable[ i ].name == name )
        {
            return m_TextVariable[ i ].value;
        }
    }

    return "";
}



TextState
UiTextArea::GetTextState() const
{
    return m_TextState;
}



float
UiTextArea::GetTextLimit() const
{
    return m_TextLimit;
}



unsigned int
UiTextArea::GetTextSize() const
{
    return m_Text.size();
}



float
UiTextArea::GetPauseTime() const
{
    return m_PauseTime;
}


void
UiTextArea::UpdateGeometry()
{
    if( m_Font == NULL )
    {
        LOG_ERROR( "Font for \"" + m_PathName + "\" if not set." );
        return;
    }

    float width = 0;
    if( m_TextAlign != LEFT )
    {
        width = GetTextWidth();

        if( m_TextAlign == CENTER )
        {
            width /= 2;
        }
    }

    //LOG_ERROR( "1) m_FinalOrigin.y = " + Ogre::StringConverter::toString( m_FinalOrigin.y ) + ", m_TextYOffset = " + Ogre::StringConverter::toString( m_TextYOffset ) );

    float* writeIterator = ( float* ) m_VertexBuffer->lock( Ogre::HardwareBuffer::HBL_NORMAL );
    m_RenderOp.vertexData->vertexCount = 0;

    float local_x_start = -m_FinalOrigin.x - ( width - m_PaddingLeft ) * m_FinalScale.x * m_ScreenHeight / 720.0f;
    float local_x1 = local_x_start;
    float local_y1 = -m_FinalOrigin.y + ( ( m_TextYOffset + m_PaddingTop ) * m_FinalScale.y * m_ScreenHeight / 720.0f );
    float local_x2;
    float local_y2;
    float x = m_FinalTranslate.x;
    float y = m_FinalTranslate.y;

    unsigned int i = 0;
    for( ; ( i < m_TextLimit ) && ( i < m_Text.size() ); ++i )
    {
        if( m_Text[ i ].skip == true )
        {
            continue;
        }
        else if( m_Text[ i ].pause_ok == true )
        {
            m_Text[ i ].skip = true;
            m_TextState = TS_PAUSE_OK;
            break;
        }
        else if( m_Text[ i ].pause_time != 0 )
        {
            m_Text[ i ].skip = true;
            m_PauseTime = m_Text[ i ].pause_time;
            m_TextState = TS_PAUSE_TIME;
            break;
        }
        else if( m_Text[ i ].next_page == true )
        {
            m_Text[ i ].skip = true;
            m_NextPageStart = i + 1;
            m_TextState = TS_NEXT_PAGE;
            break;
        }
        else if( m_Text[ i ].sprite != NULL )
        {
            float width_percent = 0;
            float width = 0;
            m_Text[ i ].sprite->GetWidth( width_percent, width );
            m_Text[ i ].sprite->SetX( 0, local_x1 / ( m_FinalScale.x * m_ScreenHeight / 720.0f ) );
            local_x1 += width * m_FinalScale.x * m_ScreenHeight / 720.0f;
            float height_percent = 0;
            float height = 0;
            m_Text[ i ].sprite->GetHeight( height_percent, height );
            m_Text[ i ].sprite->SetY( 0, m_Text[ i ].sprite_y + ( local_y1 / ( m_FinalScale.y * m_ScreenHeight / 720.0f ) ) );
            m_Text[ i ].sprite->SetVisible( true );
            m_Text[ i ].sprite->UpdateGeometry();
            continue;
        }



        UiCharData char_data = m_Font->GetCharData( m_Text[ i ].char_code );
        Ogre::ColourValue colour = m_Text[ i ].colour;

        if( char_data.char_code == 10 )
        {
            local_x1 = local_x_start;
            local_y1 += m_Font->GetHeight() * m_FinalScale.y * m_ScreenHeight / 720.0f;
            continue;
        }

        local_x1 += char_data.pre * m_FinalScale.x * m_ScreenHeight / 720.0f;
        local_x2 = local_x1 + char_data.width * m_FinalScale.x * m_ScreenHeight / 720.0f;
        local_y2 = local_y1 + char_data.height * m_FinalScale.y * m_ScreenHeight / 720.0f;

        if( local_x2 + char_data.post * m_FinalScale.x * m_ScreenHeight / 720.0f > m_FinalSize.x - m_PaddingRight * m_FinalScale.x * m_ScreenHeight / 720.0f )
        {
            local_x1 = local_x_start;
            local_x2 = local_x1 + char_data.width * m_FinalScale.x * m_ScreenHeight / 720.0f;
            local_y1 += m_Font->GetHeight() * m_FinalScale.y * m_ScreenHeight / 720.0f;
            local_y2 = local_y1 + char_data.height * m_FinalScale.y * m_ScreenHeight / 720.0f;
        }

        // if we cross lower border of textarea - generate event and stop rendering
        if( local_y2 > m_FinalSize.y - m_PaddingBottom * m_FinalScale.y * m_ScreenHeight / 720.0f )
        {
            if( m_TextState != TS_SCROLL_TEXT )
            {
                m_TextState = TS_OVERFLOW;
            }

            break;
        }


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
        *writeIterator++ = m_FinalZ;
        *writeIterator++ = colour.r;
        *writeIterator++ = colour.g;
        *writeIterator++ = colour.b;
        *writeIterator++ = colour.a;
        *writeIterator++ = left;
        *writeIterator++ = top;

        *writeIterator++ = new_x2;
        *writeIterator++ = new_y2;
        *writeIterator++ = m_FinalZ;
        *writeIterator++ = colour.r;
        *writeIterator++ = colour.g;
        *writeIterator++ = colour.b;
        *writeIterator++ = colour.a;
        *writeIterator++ = right;
        *writeIterator++ = top;

        *writeIterator++ = new_x3;
        *writeIterator++ = new_y3;
        *writeIterator++ = m_FinalZ;
        *writeIterator++ = colour.r;
        *writeIterator++ = colour.g;
        *writeIterator++ = colour.b;
        *writeIterator++ = colour.a;
        *writeIterator++ = right;
        *writeIterator++ = bottom;

        *writeIterator++ = new_x1;
        *writeIterator++ = new_y1;
        *writeIterator++ = m_FinalZ;
        *writeIterator++ = colour.r;
        *writeIterator++ = colour.g;
        *writeIterator++ = colour.b;
        *writeIterator++ = colour.a;
        *writeIterator++ = left;
        *writeIterator++ = top;

        *writeIterator++ = new_x3;
        *writeIterator++ = new_y3;
        *writeIterator++ = m_FinalZ;
        *writeIterator++ = colour.r;
        *writeIterator++ = colour.g;
        *writeIterator++ = colour.b;
        *writeIterator++ = colour.a;
        *writeIterator++ = right;
        *writeIterator++ = bottom;

        *writeIterator++ = new_x4;
        *writeIterator++ = new_y4;
        *writeIterator++ = m_FinalZ;
        *writeIterator++ = colour.r;
        *writeIterator++ = colour.g;
        *writeIterator++ = colour.b;
        *writeIterator++ = colour.a;
        *writeIterator++ = left;
        *writeIterator++ = bottom;

        m_RenderOp.vertexData->vertexCount += 6;
    }

    m_VertexBuffer->unlock();

    if( i == m_Text.size() )
    {
        m_TextState = TS_DONE;
    }
}


float
UiTextArea::GetTextWidth() const
{
    float width = 0;
    float width_max = 0;

    for( unsigned int i = 0; i < m_Text.size(); ++i )
    {
        UiCharData char_data = m_Font->GetCharData( m_Text[ i ].char_code );

        // if we go to next row store max previous row width
        if( char_data.char_code == 10 )
        {
            width_max = ( width > width_max ) ? width : width_max;
            width = 0;
        }
        else
        {
            width += char_data.pre + char_data.width + char_data.post;
        }
    }

    return ( width > width_max ) ? width : width_max;
}


void
UiTextArea::PrepareTextFromNode( TiXmlNode* node, const Ogre::ColourValue& colour )
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
                    PrepareTextFromText( childText->Value(), colour );
                }
            }
            break;

            case TiXmlNode::TINYXML_ELEMENT:
            {
                Ogre::ColourValue colour_child = colour;

                Ogre::String name = node->ValueStr();
                if( name == "colour" )
                {
                    colour_child = Ogre::StringConverter::parseColourValue( node->ToElement()->Attribute( "value" ) );
                }
                else if( name == "pause_ok" )
                {
                    TextChar new_char;
                    new_char.pause_ok = true;
                    m_Text.push_back( new_char );
                }
                else if( name == "pause" )
                {
                    const std::string* string = node->ToElement()->Attribute( Ogre::String( "time" ) );
                    if( string != NULL )
                    {
                        TextChar new_char;
                        new_char.pause_time = Ogre::StringConverter::parseReal( *string );
                        m_Text.push_back( new_char );
                    }
                }
                else if( name == "next_page" )
                {
                    TextChar new_char;
                    new_char.next_page = true;
                    m_Text.push_back( new_char );
                }
                else if( name == "timer" )
                {
                    m_Timer = true;

                    TextChar new_char;
                    new_char.skip = true;
                    new_char.variable = "UITextAreaTimer";
                    new_char.colour = colour;
                    Ogre::UTFString var = GetVariable( "UITextAreaTimer" );
                    new_char.variable_len = var.size();
                    m_Text.push_back( new_char );

                    for( unsigned int i = 0; i < var.size(); ++i )
                    {
                        TextChar text_char;
                        text_char.char_code = var[ i ];
                        text_char.colour = colour;
                        m_Text.push_back( text_char );
                    }
                }
                else if( name == "variable" )
                {
                    const std::string* string = node->ToElement()->Attribute( Ogre::String( "name" ) );

                    if( string != NULL )
                    {
                        TextChar new_char;
                        new_char.skip = true;
                        new_char.variable = *string;
                        new_char.colour = colour;
                        Ogre::UTFString var = GetVariable( *string );
                        new_char.variable_len = var.size();
                        m_Text.push_back( new_char );

                        for( unsigned int i = 0; i < var.size(); ++i )
                        {
                            TextChar text_char;
                            text_char.char_code = var[ i ];
                            text_char.colour = colour;
                            m_Text.push_back( text_char );
                        }
                    }
                }
                else if( name == "include" )
                {
                    const std::string* text_name = node->ToElement()->Attribute( Ogre::String( "name" ) );

                    if( text_name != NULL )
                    {
                        TiXmlNode* text = TextManager::getSingleton().GetText( *text_name );
                        if( text != NULL )
                        {
                            PrepareTextFromNode( text, colour_child );
                        }
                    }
                }
                else if( name == "image" )
                {
                    Ogre::String name1 = GetString( node, "sprite" );
                    if( name1 != "" )
                    {
                        TiXmlNode* sprites = UiManager::getSingleton().GetPrototype( "TextAreaSprite" );
                        if( sprites != NULL )
                        {
                            sprites = sprites->FirstChild();
                            while( sprites != NULL )
                            {
                                if( sprites->Type() == TiXmlNode::TINYXML_ELEMENT && sprites->ValueStr() == "sprite" )
                                {
                                    Ogre::String name2 = GetString( sprites, "name" );
                                    if( name1 == name2 )
                                    {
                                        TextChar new_char;

                                        UiSprite* sprite = new UiSprite( name1, m_Name + "." + name1, this );
                                        Ogre::String image = GetString( sprites, "image" );
                                        if( image != "" )
                                        {
                                            sprite->SetImage( image );
                                        }
                                        Ogre::String y_str = GetString( sprites, "y" );
                                        if( y_str != "" )
                                        {
                                            float y_percent = 0;
                                            float y = 0;
                                            ParsePersent( y_percent, y, y_str );
                                            new_char.sprite_y = y;
                                        }
                                        Ogre::String width_str = GetString( sprites, "width" );
                                        if( width_str != "" )
                                        {
                                            float width_percent = 0;
                                            float width = 0;
                                            ParsePersent( width_percent, width, width_str );
                                            sprite->SetWidth( 0, width );
                                        }
                                        Ogre::String height_str = GetString( sprites, "height" );
                                        if( height_str != "" )
                                        {
                                            float height_percent = 0;
                                            float height = 0;
                                            ParsePersent( height_percent, height, height_str );
                                            sprite->SetHeight( height_percent, height );
                                        }

                                        sprite->SetVisible( false );
                                        AddChild( sprite );
                                        new_char.sprite = sprite;
                                        m_Text.push_back( new_char );
                                        break;
                                    }
                                }

                                sprites = sprites->NextSibling();
                            }
                        }
                    }
                }

                TiXmlNode* node_child = node->FirstChild();
                PrepareTextFromNode( node_child, colour_child );
            }
            break;
        }

        node = node->NextSibling();
    }
}



void
UiTextArea::PrepareTextFromText( const Ogre::UTFString& text, const Ogre::ColourValue& colour_child )
{
    for( unsigned int i = 0; i < text.size(); ++i )
    {
        TextChar new_char;
        new_char.char_code = text[ i ];
        new_char.colour = colour_child;
        m_Text.push_back( new_char );
    };
}



void
UiTextArea::CreateVertexBuffer()
{
    m_MaxLetters = 1024;
    m_RenderOp.vertexData = new Ogre::VertexData;
    m_RenderOp.vertexData->vertexStart = 0;

    Ogre::VertexDeclaration* vDecl = m_RenderOp.vertexData->vertexDeclaration;

    size_t offset = 0;
    vDecl->addElement(0, 0, Ogre::VET_FLOAT3, Ogre::VES_POSITION);
    offset += Ogre::VertexElement::getTypeSize(Ogre::VET_FLOAT3);
    vDecl->addElement(0, offset, Ogre::VET_FLOAT4, Ogre::VES_DIFFUSE);
    offset += Ogre::VertexElement::getTypeSize(Ogre::VET_FLOAT4);
    vDecl->addElement(0, offset, Ogre::VET_FLOAT2, Ogre::VES_TEXTURE_COORDINATES);

    m_VertexBuffer = Ogre::HardwareBufferManager::getSingletonPtr()->createVertexBuffer(vDecl->getVertexSize(0), m_MaxLetters * 6, Ogre::HardwareBuffer::HBU_DYNAMIC_WRITE_ONLY, false);

    m_RenderOp.vertexData->vertexBufferBinding->setBinding(0, m_VertexBuffer);
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
