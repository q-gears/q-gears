#include <OgreFontManager.h>
#include <OgreHardwareBufferManager.h>
#include <OgreMaterialManager.h>

#include "core/Logger.h"
#include "core/UiManager.h"
#include "core/UiTextArea.h"


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
    m_Text = "";
    m_TextAlign = UiTextArea::LEFT;
    m_TextNode = nullptr;
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
    UiWidget::Update();
}


void
UiTextArea::Render()
{
    if(m_Visible == true)
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
UiTextArea::SetTextAlign(const TextAlign align)
{
    m_TextAlign = align;
}


void
UiTextArea::SetText(const Ogre::UTFString& text)
{
    m_Text = text;
//    TiXmlDocument doc;
//    Ogre::UTFString xml_text = "<container>" + text + "</container>";
//    doc.Parse( xml_text.asUTF8_c_str(), 0, TIXML_ENCODING_UTF8 );
//    if( doc.Error() == true )
//    {
//        LOG_ERROR( "Can't parse text \"" + text + "\". TinyXml Error: " + doc.ErrorDesc() );
//        return;
//    }
//    SetText( doc.RootElement() );
}


void
UiTextArea::SetText(TiXmlNode* text)
{
    m_TextNode = text;
}


void
UiTextArea::SetTextPrintSpeed(const float speed)
{
    m_TextPrintSpeed = speed;
}


void
UiTextArea::SetTextScrollTime(const float time)
{
    m_TextScrollTime = time;
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
}


const UiFont*
UiTextArea::GetFont() const
{
    return m_Font;
}


void
UiTextArea::SetVariable( const Ogre::String& name, const Ogre::UTFString& value )
{
//    if( name == "" )
//    {
//        return;
//    }

//    bool update = false;

//    for( unsigned int i = 0; i < m_TextVariable.size(); ++i )
//    {
//        if( m_TextVariable[ i ].name == name )
//        {
//            m_TextVariable[ i ].value = value;
//            update = true;

//            for( unsigned int j = 0; j < m_Text.size(); ++j )
//            {
//                if( m_Text[ j ].variable == name )
//                {
//                    m_Text.erase( m_Text.begin() + j + 1, m_Text.begin() + j + 1 + m_Text[ j ].variable_len );
//                }
//            }
//        }
//    }

//    if( update == false )
//    {
//        TextVariable var;
//        var.name = name;
//        var.value = value;
//        m_TextVariable.push_back( var );
//    }

//    for( unsigned int i = 0; i < m_Text.size(); ++i )
//    {
//        if( m_Text[ i ].variable == name )
//        {
//            m_Text[ i ].variable_len = value.size();
//            unsigned int j = 0;
//            for( ; j < m_Text[ i ].variable_len; ++j )
//            {
//                TextChar text_char;
//                text_char.char_code = value[ j ];
//                text_char.colour = m_Text[ i ].colour;
//                m_Text.insert( m_Text.begin() + i + 1 + j, text_char );
//            }

//            i += j;
//        }
//    }

//    m_UpdateTransformation = true;
}



Ogre::UTFString
UiTextArea::GetVariable( const Ogre::String& name ) const
{
//    for( unsigned int i = 0; i < m_TextVariable.size(); ++i )
//    {
//        if( m_TextVariable[ i ].name == name )
//        {
//            return m_TextVariable[ i ].value;
//        }
//    }

//    return "";
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


//float
//UiTextArea::GetTextWidth() const
//{
//    float width = 0;
//    float width_max = 0;

//    for( unsigned int i = 0; i < m_Text.size(); ++i )
//    {
//        UiCharData char_data = m_Font->GetCharData( m_Text[ i ].char_code );

//        // if we go to next row store max previous row width
//        if( char_data.char_code == 10 )
//        {
//            width_max = ( width > width_max ) ? width : width_max;
//            width = 0;
//        }
//        else
//        {
//            width += char_data.pre + char_data.width + char_data.post;
//        }
//    }

//    return ( width > width_max ) ? width : width_max;
//}


float
UiTextArea::GetPauseTime() const
{
    return m_PauseTime;
}


void
UiTextArea::UpdateGeometry()
{
    if(m_Font == nullptr)
    {
        LOG_ERROR("Font for \"" + m_PathName + "\" if not set.");
        return;
    }

    if(m_Text.size() > m_MaxLetters)
    {
        LOG_ERROR("Max number of text reached in \"" + m_PathName + "\". Can't render text \"" + m_Text + "\". Max number of letters is " + Ogre::StringConverter::toString(m_MaxLetters) + ".");
        return;
    }
    float length = 0;
    if(m_TextAlign != LEFT)
    {
        if(m_TextNode != nullptr)
        {
            length = GetTextLengthFromNode(m_TextNode);
        }
        else
        {
            length = GetTextLength(m_Text);
        }
        if(m_TextAlign == CENTER)
        {
            length /= 2;
        }
    }
    TextBlockData data;
    data.local_x1 = -m_FinalOrigin.x - length;
    data.local_y1 = -m_FinalOrigin.y;
    data.position = 0;
    TextStyle style;
    style.colour = m_Colour1;
    if(m_TextNode != nullptr)
    {
        SetTextGeometryFromNode(m_TextNode, data, style);
    }
    else
    {
        SetTextGeometry(m_Text, data, style);
    }
}




float
UiTextArea::GetTextLengthFromNode(TiXmlNode* node) const
{
    float length = 0;

    while(node != nullptr)
    {
        switch(node->Type())
        {
            case TiXmlNode::TINYXML_TEXT:
            {
                TiXmlText* childText = node->ToText();
                if(childText)
                {
                    length += GetTextLength(childText->Value());
                }
            }
            break;

            case TiXmlNode::TINYXML_ELEMENT:
            {
                length +=GetTextLengthFromNode(node->FirstChild());
            }
            break;
        }

        node = node->NextSibling();
    }

    return length;
}


float
UiTextArea::GetTextLength(const Ogre::UTFString& text) const
{
    float length = 0;
    for(const auto &c : text)
    {
        UiCharData char_data = m_Font->GetCharData(c);
        length += (char_data.pre + char_data.width + char_data.post) * m_FinalScale.x * m_ScreenHeight / 720.0f;
    }

    return length;
}


void
UiTextArea::SetTextGeometryFromNode(TiXmlNode* node, TextBlockData& data, const TextStyle& style)
{
    while(node != nullptr)
    {
        switch(node->Type())
        {
            case TiXmlNode::TINYXML_TEXT:
            {
                TiXmlText* childText = node->ToText();
                if(childText)
                {
                    SetTextGeometry(childText->Value(), data, style);
                }
            }
            break;

            case TiXmlNode::TINYXML_ELEMENT:
            {
                TextStyle style_child;
                style_child.colour = style.colour;

                Ogre::String name = node->ValueStr();
                if(name == "colour")
                {
                    style_child.colour = Ogre::StringConverter::parseColourValue(node->ToElement()->Attribute("value"));
                }

                TiXmlNode* node_child = node->FirstChild();
                SetTextGeometryFromNode(node_child, data, style_child);
            }
            break;
        }

        node = node->NextSibling();
    }
}


void
UiTextArea::SetTextGeometry(const Ogre::UTFString& text, TextBlockData& data, const TextStyle& style)
{
    float* writeIterator = (float*) m_VertexBuffer->lock(Ogre::HardwareBuffer::HBL_NORMAL);
    writeIterator += data.position * 9 * 6;
    m_RenderOp.vertexData->vertexCount = data.position * 6;


    float local_x1 = data.local_x1;
    float local_y1 = data.local_y1;
    float x = m_FinalTranslate.x;
    float y = m_FinalTranslate.y;

    for(auto &c : text)
    {
        UiCharData char_data = m_Font->GetCharData(c);

        local_x1 += char_data.pre * m_FinalScale.x * m_ScreenHeight / 720.0f;
        float local_x2 = local_x1 + char_data.width * m_FinalScale.x * m_ScreenHeight / 720.0f;
        float local_y2 = local_y1 + char_data.height * m_FinalScale.y * m_ScreenHeight / 720.0f;

        int x1, y1, x2, y2, x3, y3, x4, y4;

        if(m_FinalRotation != 0)
        {
            float cos = Ogre::Math::Cos(Ogre::Radian(Ogre::Degree(m_FinalRotation)));
            float sin = Ogre::Math::Sin(Ogre::Radian(Ogre::Degree(m_FinalRotation)));

            x1 = static_cast<int>(local_x1 * cos - local_y1 * sin + x);
            y1 = static_cast<int>(local_x1 * sin + local_y1 * cos + y);
            x2 = static_cast<int>(local_x2 * cos - local_y1 * sin + x);
            y2 = static_cast<int>(local_x2 * sin + local_y1 * cos + y);
            x3 = static_cast<int>(local_x2 * cos - local_y2 * sin + x);
            y3 = static_cast<int>(local_x2 * sin + local_y2 * cos + y);
            x4 = static_cast<int>(local_x1 * cos - local_y2 * sin + x);
            y4 = static_cast<int>(local_x1 * sin + local_y2 * cos + y);
        }
        else
        {
            x1 = static_cast<int>(local_x1 + x);
            y1 = static_cast<int>(local_y1 + y);
            x2 = static_cast<int>(local_x2 + x);
            y2 = static_cast<int>(local_y1 + y);
            x3 = static_cast<int>(local_x2 + x);
            y3 = static_cast<int>(local_y2 + y);
            x4 = static_cast<int>(local_x1 + x);
            y4 = static_cast<int>(local_y2 + y);
        }

        local_x1 += (char_data.width + char_data.post) * m_FinalScale.x * m_ScreenHeight / 720.0f;

        float width = static_cast<float>(m_Font->GetImageWidth());
        float height = static_cast<float>(m_Font->GetImageHeight());

        Ogre::Vector3 coords[4] = {
            Ogre::Vector3((x1 / m_ScreenWidth) * 2 - 1, -((y1 / m_ScreenHeight) * 2 - 1), m_FinalZ),
            Ogre::Vector3((x2 / m_ScreenWidth) * 2 - 1, -((y2 / m_ScreenHeight) * 2 - 1), m_FinalZ),
            Ogre::Vector3((x3 / m_ScreenWidth) * 2 - 1, -((y3 / m_ScreenHeight) * 2 - 1), m_FinalZ),
            Ogre::Vector3((x4 / m_ScreenWidth) * 2 - 1, -((y4 / m_ScreenHeight) * 2 - 1), m_FinalZ)
        };
        auto texture = Ogre::FloatRect(
            (float)char_data.x / width, // left
            (float)char_data.y / height, // top
            (float)(char_data.x + char_data.width) / width, // right
            (float)(char_data.y + char_data.height) / height // bottom
       );
        Ogre::ColourValue colour = style.colour;

        // draw two triangles with a colour and texture.
        WriteGlyph(writeIterator, coords, Ogre::ColourValue::White, texture);
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
