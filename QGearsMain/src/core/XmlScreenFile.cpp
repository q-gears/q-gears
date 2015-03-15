#include "core/Logger.h"
#include "core/ScriptManager.h"
#include "core/UiManager.h"
#include "core/UiSprite.h"
#include "core/UiTextArea.h"
#include "core/UiWidget.h"
#include "core/TextManager.h"
#include "core/XmlScreenFile.h"
#include "core/Utilites.h"



XmlScreenFile::XmlScreenFile(const Ogre::String& file):
    XmlFile(file)
{
}


XmlScreenFile::~XmlScreenFile()
{
}


void
XmlScreenFile::LoadScreen()
{
    TiXmlNode* node = m_File.RootElement();

    if(node == nullptr || node->ValueStr() != "screen")
    {
        LOG_ERROR(m_File.ValueStr() + " is not a valid screen file! No <screen> in root.");
        return;
    }

    Ogre::String base_name = GetString(node, "name");
    Ogre::String script = GetString(node, "script");
    if(script != "")
    {
        ScriptManager::getSingleton().RunFile(script);
    }

    UiWidget* widget = new UiWidget(base_name);
    widget->SetVisible(GetBool(node, "visible", false));

    node = node->FirstChild();
    if(node != nullptr)
    {
        LoadScreenRecursive(node, base_name, widget);
    }

    UiManager::getSingleton().AddWidget(widget);
}


void
XmlScreenFile::LoadScreenRecursive(TiXmlNode* node, const Ogre::String& base_name, UiWidget* widget)
{
    while(node != nullptr)
    {
        // parse widgets
        if(node->Type() == TiXmlNode::TINYXML_ELEMENT && (node->ValueStr() == "widget" || node->ValueStr() == "sprite" || node->ValueStr() == "text_area" || node->ValueStr() == "prototype"))
        {
            if(node->ValueStr() == "prototype")
            {
                Ogre::String name = GetString(node, "name");
                if(name != "")
                {
                    TiXmlNode* node2 = UiManager::getSingleton().GetPrototype(name);
                    if(node != nullptr)
                    {
                        node2 = node2->FirstChild();
                        if(node2 != nullptr)
                        {
                            LoadScreenRecursive(node2, base_name, widget);
                        }
                    }
                }
            }
            else
            {
                Ogre::String name = GetString(node, "name");
                if(name != "")
                {
                    UiWidget* widget2;

                    if(node->ValueStr() == "sprite")
                    {
                        widget2 = new UiSprite(name, base_name + "." + name, widget);
                    }
                    else if(node->ValueStr() == "text_area")
                    {
                        widget2 = new UiTextArea(name, base_name + "." + name, widget);
                    }
                    else
                    {
                        widget2 = new UiWidget(name, base_name + "." + name, widget);
                    }

                    if(node->ValueStr() == "sprite")
                    {
                        Ogre::String image = GetString(node, "image");
                        if(image != "")
                        {
                            ((UiSprite*)widget2)->SetImage(image);
                        }

                        Ogre::String vertex_shader = GetString(node, "vertex_shader");
                        if(vertex_shader != "")
                        {
                            ((UiSprite*)widget2)->SetVertexShader(vertex_shader);
                        }

                        Ogre::String fragment_shader = GetString(node, "fragment_shader");
                        if(fragment_shader != "")
                        {
                            ((UiSprite*)widget2)->SetFragmentShader(fragment_shader);
                        }
                    }

                    if(node->ValueStr() == "text_area")
                    {
                        Ogre::String text = GetString(node, "text_name", "");
                        if(text != "")
                        {
                            TiXmlNode* utf = TextManager::getSingleton().GetText( text );
                            if( utf != nullptr )
                            {
                                ( ( UiTextArea* )widget2 )->SetText( utf );
                            }
                        }

                        Ogre::String font = GetString(node, "font", "");
                        if(font != "")
                        {
                            ((UiTextArea*)widget2)->SetFont(font);
                        }

                        Ogre::String align = GetString(node, "text_align", "");
                        if(align != "")
                        {
                            ((UiTextArea*)widget2)->SetTextAlign((align == "center") ? UiTextArea::CENTER : ((align == "right") ? UiTextArea::RIGHT : UiTextArea::LEFT));
                        }
                        Ogre::Vector4 padding = GetVector4( node, "padding", Ogre::Vector4::ZERO );
                        if( padding != Ogre::Vector4::ZERO )
                        {
                            ( ( UiTextArea* )widget2 )->SetPadding( padding.x, padding.y, padding.z, padding.w );
                        }
                    }

                    Ogre::String colours = GetString(node, "colours", "");
                    if(colours != "")
                    {
                        Ogre::StringVector colour_string = Ogre::StringUtil::split(colours, ",");
                        Ogre::Vector3 colour[4];
                        for(unsigned int i = 0; i < 4; ++i)
                        {
                            Ogre::StringUtil::trim(colour_string[i]);
                            colour[i] = (i < colour_string.size()) ? Ogre::StringConverter::parseVector3(colour_string[i]) : Ogre::Vector3(1, 1, 1);
                        }
                        widget2->SetColours(colour[0].x, colour[0].y, colour[0].z, colour[1].x, colour[1].y, colour[1].z, colour[2].x, colour[2].y, colour[2].z, colour[3].x, colour[3].y, colour[3].z);
                    }
                    else
                    {
                        Ogre::Vector3 colour = GetVector3(node, "colour", Ogre::Vector3(1, 1, 1));
                        widget2->SetColour(colour.x, colour.y, colour.z);
                    }

                    float alpha = GetFloat(node, "alpha", 1);
                    widget2->SetAlpha(alpha);

                    Ogre::String align = GetString(node, "align");
                    if(align != "")
                    {
                        widget2->SetAlign((align == "center") ? UiWidget::CENTER : ((align == "right") ? UiWidget::RIGHT : UiWidget::LEFT));
                    }

                    Ogre::String valign = GetString(node, "valign");
                    if(valign != "")
                    {
                        widget2->SetVerticalAlign((valign == "middle") ? UiWidget::MIDDLE : ((valign == "bottom") ? UiWidget::BOTTOM : UiWidget::TOP));
                    }

                    Ogre::String origin_x_str = GetString(node, "origin_x");
                    if(origin_x_str != "")
                    {
                        float x_percent = 0;
                        float x = 0;
                        ParsePersent(x_percent, x, origin_x_str);
                        widget2->SetOriginX(x_percent, x);
                    }

                    Ogre::String origin_y_str = GetString(node, "origin_y");
                    if(origin_y_str != "")
                    {
                        float y_percent = 0;
                        float y = 0;
                        ParsePersent(y_percent, y, origin_y_str);
                        widget2->SetOriginY(y_percent, y);
                    }

                    Ogre::String x_str = GetString(node, "x");
                    if(x_str != "")
                    {
                        float x_percent = 0;
                        float x = 0;
                        ParsePersent(x_percent, x, x_str);
                        widget2->SetX(x_percent, x);
                    }

                    Ogre::String y_str = GetString(node, "y");
                    if(y_str != "")
                    {
                        float y_percent = 0;
                        float y = 0;
                        ParsePersent(y_percent, y, y_str);
                        widget2->SetY(y_percent, y);
                    }

                    Ogre::String width_str = GetString(node, "width");
                    if(width_str != "")
                    {
                        float width_percent = 0;
                        float width = 0;
                        ParsePersent(width_percent, width, width_str);
                        widget2->SetWidth(width_percent, width);
                    }

                    Ogre::String height_str  = GetString(node, "height");
                    if(height_str != "")
                    {
                        float height_percent = 0;
                        float height = 0;
                        ParsePersent(height_percent, height, height_str);
                        widget2->SetHeight(height_percent, height);
                    }

                    Ogre::Vector2 scale = GetVector2(node, "scale", Ogre::Vector2(1.0f, 1.0f));
                    widget2->SetScale(scale);
                    widget2->SetRotation(GetFloat(node, "rotation", 0.0f));

                    Ogre::String scissor_area  = GetString( node, "scissor_area" );
                    if( scissor_area != "" )
                    {
                        Ogre::StringVector coords = Ogre::StringUtil::split( scissor_area, " " );
                        if( coords.size() == 4 )
                        {
                            float percent_x1, x1, percent_y1, y1, percent_x2, x2, percent_y2, y2 = 0;
                            ParsePersent( percent_x1, x1, coords[ 0 ] );
                            ParsePersent( percent_y1, y1, coords[ 1 ] );
                            ParsePersent( percent_x2, x2, coords[ 2 ] );
                            ParsePersent( percent_y2, y2, coords[ 3 ] );
                            widget2->SetScissorArea( percent_x1, x1, percent_y1, y1, percent_x2, x2, percent_y2, y2 );
                        }
                    }



                    widget2->SetGlobalScissor( GetBool( node, "global_scissor", true ) );

                    widget2->SetVisible(GetBool(node, "visible", false));

                    if(node->ValueStr() == "sprite")
                    {
                        ((UiSprite*)widget2)->UpdateGeometry();
                    }
                    else if(node->ValueStr() == "text_area")
                    {
                        ((UiTextArea*)widget2)->UpdateGeometry();
                    }

                    widget->AddChild(widget2);

                    TiXmlNode* node2 = node->FirstChild();
                    if(node2 != nullptr)
                    {
                        LoadScreenRecursive(node2, base_name + "." + name, widget2);
                    }
                }
                else
                {
                    LOG_ERROR("There is no name in entity with base name " + base_name);
                }
            }
        }
        // parse animation data for widget
        else if(node->Type() == TiXmlNode::TINYXML_ELEMENT && node->ValueStr() == "animation")
        {
            Ogre::String name = GetString(node, "name", "");
            if(name != "")
            {
                UiAnimation* animation = new UiAnimation(name, widget);

                float anim_length = GetFloat( node, "length", 0 );
                animation->SetLength( anim_length );

                Ogre::String scale = GetString(node, "scale", "");
                if(scale != "")
                {
                    Ogre::StringVector key_frame = Ogre::StringUtil::split(scale, ",");
                    for(unsigned int i = 0; i < key_frame.size(); ++i)
                    {
                        Ogre::StringUtil::trim(key_frame[i]);

                        Ogre::StringVector data = Ogre::StringUtil::split(key_frame[i], ":");
                        if(data.size() > 1)
                        {
                            UiKeyFrameVector2 key;
                            key.time = ParseKeyFrameTime( anim_length, data[ 0 ] );
                            key.value = Ogre::StringConverter::parseVector2( data[ 1 ] );
                            animation->AddScaleKeyFrame( key );
                        }
                    }
                }



                Ogre::String x = GetString( node, "x", "" );
                if( x != "" )
                {
                    Ogre::StringVector key_frame = Ogre::StringUtil::split( x, "," );
                    for( unsigned int i = 0; i < key_frame.size(); ++i )
                    {
                        Ogre::StringUtil::trim( key_frame[ i ] );

                        Ogre::StringVector data = Ogre::StringUtil::split( key_frame[ i ], ":" );
                        if( data.size() > 1 )
                        {
                            UiKeyFrameVector2 key;
                            key.time = ParseKeyFrameTime( anim_length, data[ 0 ] );
                            ParsePersent( key.value.x, key.value.y, data[ 1 ] );
                            animation->AddXKeyFrame( key );
                        }
                    }
                }



                Ogre::String y = GetString( node, "y", "" );
                if( y != "" )
                {
                    Ogre::StringVector key_frame = Ogre::StringUtil::split( y, "," );
                    for( unsigned int i = 0; i < key_frame.size(); ++i )
                    {
                        Ogre::StringUtil::trim( key_frame[ i ] );

                        Ogre::StringVector data = Ogre::StringUtil::split( key_frame[ i ], ":" );
                        if( data.size() > 1 )
                        {
                            UiKeyFrameVector2 key;
                            key.time = ParseKeyFrameTime( anim_length, data[ 0 ] );
                            ParsePersent( key.value.x, key.value.y, data[ 1 ] );
                            animation->AddYKeyFrame( key );
                        }
                    }
                }



                Ogre::String width = GetString( node, "width", "" );
                if( width != "" )
                {
                    Ogre::StringVector key_frame = Ogre::StringUtil::split( width, "," );
                    for( unsigned int i = 0; i < key_frame.size(); ++i )
                    {
                        Ogre::StringUtil::trim( key_frame[ i ] );

                        Ogre::StringVector data = Ogre::StringUtil::split( key_frame[ i ], ":" );
                        if( data.size() > 1 )
                        {
                            UiKeyFrameVector2 key;
                            key.time = ParseKeyFrameTime( anim_length, data[ 0 ] );
                            ParsePersent( key.value.x, key.value.y, data[ 1 ] );
                            animation->AddWidthKeyFrame( key );
                        }
                    }
                }



                Ogre::String height = GetString( node, "height", "" );
                if( height != "" )
                {
                    Ogre::StringVector key_frame = Ogre::StringUtil::split( height, "," );
                    for( unsigned int i = 0; i < key_frame.size(); ++i )
                    {
                        Ogre::StringUtil::trim( key_frame[ i ] );

                        Ogre::StringVector data = Ogre::StringUtil::split( key_frame[ i ], ":" );
                        if( data.size() > 1 )
                        {
                            UiKeyFrameVector2 key;
                            key.time = ParseKeyFrameTime( anim_length, data[ 0 ] );
                            ParsePersent( key.value.x, key.value.y, data[ 1 ] );
                            animation->AddHeightKeyFrame( key );
                        }
                    }
                }



                Ogre::String rotation = GetString( node, "rotation", "" );
                if( rotation != "" )
                {
                    Ogre::StringVector key_frame = Ogre::StringUtil::split( rotation, "," );
                    for( unsigned int i = 0; i < key_frame.size(); ++i )
                    {
                        Ogre::StringUtil::trim( key_frame[ i ] );

                        Ogre::StringVector data = Ogre::StringUtil::split( key_frame[ i ], ":" );
                        if( data.size() > 1 )
                        {
                            UiKeyFrameFloat key;
                            key.time = ParseKeyFrameTime( anim_length, data[ 0 ] );
                            key.value = Ogre::StringConverter::parseReal( data[ 1 ] );
                            animation->AddRotationKeyFrame( key );
                        }
                    }
                }



                Ogre::String alpha = GetString( node, "alpha", "" );
                if( alpha != "" )
                {
                    Ogre::StringVector key_frame = Ogre::StringUtil::split( alpha, "," );
                    for( unsigned int i = 0; i < key_frame.size(); ++i )
                    {
                        Ogre::StringUtil::trim( key_frame[ i ] );

                        Ogre::StringVector data = Ogre::StringUtil::split( key_frame[ i ], ":" );
                        if( data.size() > 1 )
                        {
                            UiKeyFrameFloat key;
                            key.time = ParseKeyFrameTime( anim_length, data[ 0 ] );
                            key.value = Ogre::StringConverter::parseReal( data[ 1 ] );
                            animation->AddAlphaKeyFrame( key );
                        }
                    }
                }



                Ogre::String scissor_area = GetString( node, "scissor_area", "" );
                if( scissor_area != "" )
                {
                    Ogre::StringVector key_frame = Ogre::StringUtil::split( scissor_area, "," );
                    for( unsigned int i = 0; i < key_frame.size(); ++i )
                    {
                        Ogre::StringUtil::trim( key_frame[ i ] );

                        Ogre::StringVector data = Ogre::StringUtil::split( key_frame[ i ], ":" );
                        if( data.size() > 1 )
                        {
                            UiKeyFrameVector2 key1, key2, key3, key4;
                            key1.time = ParseKeyFrameTime( anim_length, data[ 0 ] );
                            key2.time = key1.time;
                            key3.time = key1.time;
                            key4.time = key1.time;
                            Ogre::StringVector keys = Ogre::StringUtil::split( data[ 1 ], " " );
                            float percent_x1, x1, percent_y1, y1, percent_x2, x2, percent_y2, y2 = 0;
                            ParsePersent( key1.value.x, key1.value.y, keys[ 0 ] );
                            ParsePersent( key2.value.x, key2.value.y, keys[ 1 ] );
                            ParsePersent( key3.value.x, key3.value.y, keys[ 2 ] );
                            ParsePersent( key4.value.x, key4.value.y, keys[ 3 ] );
                            animation->AddScissorKeyFrame( key1, key2, key3, key4 );
                        }
                    }
                }



                widget->AddAnimation( animation );
            }
        }
        node = node->NextSibling();
    }
}
