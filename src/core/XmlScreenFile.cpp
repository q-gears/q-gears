#include "XmlScreenFile.h"

#include "Logger.h"
#include "ScriptManager.h"
#include "UiManager.h"
#include "UiSprite.h"
#include "UiWidget.h"



XmlScreenFile::XmlScreenFile( const Ogre::String& file ):
    XmlFile( file )
{
}



XmlScreenFile::~XmlScreenFile()
{
}



void
XmlScreenFile::LoadScreen()
{
    TiXmlNode* node = m_File.RootElement();

    if( node == NULL || node->ValueStr() != "screen" )
    {
        LOG_ERROR( m_File.ValueStr() + " is not a valid fields map file! No <map> in root." );
        return;
    }

    Ogre::String base_name = GetString( node, "name" );
    Ogre::String script = GetString( node, "script" );
    if( script != "" )
    {
        ScriptManager::getSingleton().RunFile( script );
    }

    UiWidget* widget = new UiWidget( base_name );
    bool show = GetBool( node, "show", false );
    if( show == true )
    {
        widget->Show();
    }

    node = node->FirstChild();
    if( node != NULL )
    {
        LoadScreenRecursive( node, base_name, widget );
    }

    UiManager::getSingleton().AddWidget( widget );
}



void
XmlScreenFile::LoadScreenRecursive( TiXmlNode* node, const Ogre::String& base_name, UiWidget* widget )
{
    while( node != NULL )
    {
        // parse widgets
        if( node->Type() == TiXmlNode::TINYXML_ELEMENT && ( node->ValueStr() == "widget" || node->ValueStr() == "sprite" ) )
        {
            Ogre::String name = GetString( node, "name" );
            if( name != "" )
            {
                UiWidget* widget2;

                if( node->ValueStr() == "sprite" )
                {
                    widget2 = new UiSprite( name, base_name + "." + name, widget );
                }
                else
                {
                    widget2 = new UiWidget( name, base_name + "." + name, widget );
                }



                if( node->ValueStr() == "sprite" )
                {
                    Ogre::ColourValue colour = GetColourValue( node, "colour", Ogre::ColourValue::White );
                    ( ( UiSprite* )widget2 )->SetColour( colour.r, colour.g, colour.b, colour.a );

                    Ogre::String image = GetString( node, "image" );
                    if( image != "" )
                    {
                        ( ( UiSprite* )widget2 )->SetImage( image );
                    }
                }



                Ogre::String align = GetString( node, "align" );
                if( align != "" )
                {
                    widget2->SetAlign( ( align == "center" ) ? UiWidget::CENTER : ( ( align == "right" ) ? UiWidget::RIGHT : UiWidget::LEFT ) );
                }



                Ogre::String valign = GetString( node, "valign" );
                if( valign != "" )
                {
                    widget2->SetVerticalAlign( ( valign == "middle" ) ? UiWidget::MIDDLE : ( ( valign == "bottom" ) ? UiWidget::BOTTOM : UiWidget::TOP ) );
                }



                Ogre::String origin_x_str = GetString( node, "origin_x" );
                if( origin_x_str != "" )
                {
                    float x_percent = 0;
                    float x = 0;
                    ParsePersent( x_percent, x, origin_x_str );
                    widget2->SetOriginX( x_percent, x );
                }



                Ogre::String origin_y_str = GetString( node, "origin_y" );
                if( origin_y_str != "" )
                {
                    float y_percent = 0;
                    float y = 0;
                    ParsePersent( y_percent, y, origin_y_str );
                    widget2->SetOriginY( y_percent, y );
                }



                Ogre::String x_str = GetString( node, "x" );
                if( x_str != "" )
                {
                    float x_percent = 0;
                    float x = 0;
                    ParsePersent( x_percent, x, x_str );
                    widget2->SetX( x_percent, x );
                }



                Ogre::String y_str = GetString( node, "y" );
                if( y_str != "" )
                {
                    float y_percent = 0;
                    float y = 0;
                    ParsePersent( y_percent, y, y_str );
                    widget2->SetY( y_percent, y );
                }



                Ogre::String width_str = GetString( node, "width" );
                if( width_str != "" )
                {
                    float width_percent = 0;
                    float width = 0;
                    ParsePersent( width_percent, width, width_str );
                    widget2->SetWidth( width_percent, width );
                }



                Ogre::String height_str  = GetString( node, "height" );
                if( height_str != "" )
                {
                    float height_percent = 0;
                    float height = 0;
                    ParsePersent( height_percent, height, height_str );
                    widget2->SetHeight( height_percent, height );
                }



                Ogre::Vector2 scale = GetVector2( node, "scale", Ogre::Vector2( 1.0f, 1.0f ) );
                widget2->SetScale( scale );



                widget2->SetRotation( GetFloat( node, "rotation", 0.0f ) );



                widget2->SetScissor( GetBool( node, "scissor", false ) );



                bool show = GetBool( node, "show", false );
                if( show == true )
                {
                    widget2->Show();
                }



                widget2->UpdateTransformation();



                if( node->ValueStr() == "sprite" )
                {
                    ( ( UiSprite* )widget2 )->UpdateGeometry();
                }



                widget->AddChild( widget2 );

                TiXmlNode* node2 = node->FirstChild();
                if( node2 != NULL )
                {
                    LoadScreenRecursive( node2, base_name + "." + name, widget2 );
                }
            }
            else
            {
                LOG_ERROR( "There is no name in entity with base name " + base_name );
            }
        }
        // parse animation data for widget
        else if( node->Type() == TiXmlNode::TINYXML_ELEMENT && node->ValueStr() == "animation" )
        {
            Ogre::String name = GetString( node, "name", "" );
            if( name != "" )
            {
                UiAnimation* animation = new UiAnimation( name, widget );

                animation->SetLength( GetFloat( node, "length", 0 ) );

                Ogre::String scale = GetString( node, "scale", "" );
                if( scale != "" )
                {
                    Ogre::StringVector key_frame = Ogre::StringUtil::split( scale, "," );
                    for( int i = 0; i < key_frame.size(); ++i )
                    {
                        Ogre::StringUtil::trim( key_frame[ i ] );

                        Ogre::StringVector data = Ogre::StringUtil::split( key_frame[ i ], ":" );
                        if( data.size() > 1 )
                        {
                            UiKeyFrameVector2 key;
                            key.time = Ogre::StringConverter::parseReal( data[ 0 ] );
                            key.value = Ogre::StringConverter::parseVector2( data[ 1 ] );
                            animation->AddScaleKeyFrame( key );
                        }
                    }
                }



                Ogre::String x = GetString( node, "x", "" );
                if( x != "" )
                {
                    Ogre::StringVector key_frame = Ogre::StringUtil::split( x, "," );
                    for( int i = 0; i < key_frame.size(); ++i )
                    {
                        Ogre::StringUtil::trim( key_frame[ i ] );

                        Ogre::StringVector data = Ogre::StringUtil::split( key_frame[ i ], ":" );
                        if( data.size() > 1 )
                        {
                            UiKeyFrameVector2 key;
                            key.time = Ogre::StringConverter::parseReal( data[ 0 ] );
                            key.value = Ogre::StringConverter::parseVector2( data[ 1 ] );
                            animation->AddXKeyFrame( key );
                        }
                    }
                }



                Ogre::String y = GetString( node, "y", "" );
                if( y != "" )
                {
                    Ogre::StringVector key_frame = Ogre::StringUtil::split( y, "," );
                    for( int i = 0; i < key_frame.size(); ++i )
                    {
                        Ogre::StringUtil::trim( key_frame[ i ] );

                        Ogre::StringVector data = Ogre::StringUtil::split( key_frame[ i ], ":" );
                        if( data.size() > 1 )
                        {
                            UiKeyFrameVector2 key;
                            key.time = Ogre::StringConverter::parseReal( data[ 0 ] );
                            key.value = Ogre::StringConverter::parseVector2( data[ 1 ] );
                            animation->AddYKeyFrame( key );
                        }
                    }
                }



                Ogre::String rotation = GetString( node, "rotation", "" );
                if( rotation != "" )
                {
                    Ogre::StringVector key_frame = Ogre::StringUtil::split( rotation, "," );
                    for( int i = 0; i < key_frame.size(); ++i )
                    {
                        Ogre::StringUtil::trim( key_frame[ i ] );

                        Ogre::StringVector data = Ogre::StringUtil::split( key_frame[ i ], ":" );
                        if( data.size() > 1 )
                        {
                            UiKeyFrameFloat key;
                            key.time = Ogre::StringConverter::parseReal( data[ 0 ] );
                            key.value = Ogre::StringConverter::parseReal( data[ 1 ] );
                            animation->AddRotationKeyFrame( key );
                        }
                    }
                }



                widget->AddAnimation( animation );
            }
        }
        node = node->NextSibling();
    }
}



void
XmlScreenFile::ParsePersent( float& value_percent, float& value, const Ogre::String& string )
{
    if( string.at( string.size() - 1 ) == '%' )
    {
        value_percent = Ogre::StringConverter::parseReal( string.substr( 0, string.size() - 1 ) );
        value = 0;
    }
    else
    {
        Ogre::StringVector param = Ogre::StringUtil::split( string, "%" );
        if( param.size() > 1 )
        {
            value_percent = Ogre::StringConverter::parseReal( param[ 0 ] );
            value = Ogre::StringConverter::parseReal( param[ 1 ] );
        }
        else
        {
            value_percent = 0;
            value = Ogre::StringConverter::parseReal( string );
        }
    }
}
