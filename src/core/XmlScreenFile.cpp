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
                    Ogre::ColourValue colour = GetColourValue( node, "colour" );
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



                Ogre::String x_str = GetString( node, "x" );
                if( x_str != "" )
                {
                    float x = 0;
                    float x_add = 0;
                    bool x_percent = false;

                    if( x_str.at( x_str.size() - 1 ) == '%' )
                    {
                        x = Ogre::StringConverter::parseReal( x_str.substr( 0, x_str.size() - 1 ) );
                        x_percent = true;
                    }
                    else
                    {
                        Ogre::StringVector param = Ogre::StringUtil::split( x_str, "%" );
                        if( param.size() > 1 )
                        {
                            x = Ogre::StringConverter::parseReal( param[ 0 ] );
                            x_add = Ogre::StringConverter::parseReal( param[ 1 ] );
                            x_percent = true;
                        }
                        else
                        {
                            x = Ogre::StringConverter::parseReal( x_str );
                        }
                    }

                    widget2->SetX( x, x_add, x_percent );
                }



                Ogre::String y_str = GetString( node, "y" );
                if( y_str != "" )
                {
                    float y = 0;
                    float y_add = 0;
                    bool y_percent = false;

                    if( y_str.at( y_str.size() - 1 ) == '%' )
                    {
                        y = Ogre::StringConverter::parseReal( y_str.substr( 0, y_str.size() - 1 ) );
                        y_percent = true;
                    }
                    else
                    {
                        Ogre::StringVector param = Ogre::StringUtil::split( y_str, "%" );
                        if( param.size() > 1 )
                        {
                            y = Ogre::StringConverter::parseReal( param[ 0 ] );
                            y_add = Ogre::StringConverter::parseReal( param[ 1 ] );
                            y_percent = true;
                        }
                        else
                        {
                            y = Ogre::StringConverter::parseReal( y_str );
                        }
                    }

                    widget2->SetY( y, y_add, y_percent );
                }



                Ogre::String width_str = GetString( node, "width" );
                if( width_str != "" )
                {
                    bool width_percent = false;
                    float width = 0;
                    float width_add = 0;

                    if( width_str.at( width_str.size() - 1 ) == '%' )
                    {
                        width_percent = true;
                        width = Ogre::StringConverter::parseReal( width_str.substr( 0, width_str.size() - 1 ) );
                    }
                    else
                    {
                        Ogre::StringVector param = Ogre::StringUtil::split( width_str, "%" );
                        if( param.size() > 1 )
                        {
                            width = Ogre::StringConverter::parseReal( param[ 0 ] );
                            width_add = Ogre::StringConverter::parseReal( param[ 1 ] );
                            width_percent = true;
                        }
                        else
                        {
                            width = Ogre::StringConverter::parseReal( width_str );
                        }
                    }

                    widget2->SetWidth( width, width_add, width_percent );
                }



                Ogre::String height_str  = GetString( node, "height" );
                if( height_str != "" )
                {
                    float height = 0;
                    float height_add = 0;
                    bool height_percent = false;

                    if( height_str.at( height_str.size() - 1 ) == '%' )
                    {
                        height = Ogre::StringConverter::parseReal( height_str.substr( 0, height_str.size() - 1 ) );
                        height_percent = true;
                    }
                    else
                    {
                        Ogre::StringVector param = Ogre::StringUtil::split( height_str, "%" );
                        if( param.size() > 1 )
                        {
                            height = Ogre::StringConverter::parseReal( param[ 0 ] );
                            height_add = Ogre::StringConverter::parseReal( param[ 1 ] );
                            height_percent = true;
                        }
                        else
                        {
                            height = Ogre::StringConverter::parseReal( height_str );
                        }
                    }

                    widget2->SetHeight( height, height_add, height_percent );
                }



                if( node->ValueStr() == "sprite" )
                {
                    ( ( UiSprite* )widget2 )->GeometryUpdate();
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

        node = node->NextSibling();
    }
}
