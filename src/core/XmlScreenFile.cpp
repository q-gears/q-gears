#include "XmlScreenFile.h"

#include "Logger.h"
#include "ScriptManager.h"
#include "UiManager.h"



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
        if( node->Type() == TiXmlNode::TINYXML_ELEMENT && node->ValueStr() == "widget" )
        {
            Ogre::String name        = GetString( node, "name" );
            Ogre::ColourValue colour = GetColourValue( node, "colour" );
            Ogre::String align       = GetString( node, "align" );
            Ogre::String valign      = GetString( node, "valign" );
            Ogre::String x_str       = GetString( node, "x" );
            Ogre::String y_str       = GetString( node, "y" );
            Ogre::String width_str   = GetString( node, "width" );
            Ogre::String height_str  = GetString( node, "height" );

            bool x_percent = false;
            float x = 0;
            if( x_str.size() > 0 )
            {
                if( x_str.at( x_str.size() - 1 ) == '%' )
                {
                    x_percent = true;
                    x = Ogre::StringConverter::parseReal( x_str.substr( 0, x_str.size() - 1 ) );
                }
                else
                {
                    x = Ogre::StringConverter::parseReal( x_str );
                }
            }

            bool y_percent = false;
            float y = 0;
            if( y_str.size() > 0 )
            {
                if( y_str.at( y_str.size() - 1 ) == '%' )
                {
                    y_percent = true;
                    y = Ogre::StringConverter::parseReal( y_str.substr( 0, y_str.size() - 1 ) );
                }
                else
                {
                    y = Ogre::StringConverter::parseReal( y_str );
                }
            }

            bool width_percent = false;
            float width = 0;
            if( width_str.size() > 0 )
            {
                if( width_str.at( width_str.size() - 1 ) == '%' )
                {
                    width_percent = true;
                    width = Ogre::StringConverter::parseReal( width_str.substr( 0, width_str.size() - 1 ) );
                }
                else
                {
                    width = Ogre::StringConverter::parseReal( width_str );
                }
            }

            bool height_percent = false;
            float height = 0;
            if( height_str.size() > 0 )
            {
                if( height_str.at( height_str.size() - 1 ) == '%' )
                {
                    height_percent = true;
                    height = Ogre::StringConverter::parseReal( height_str.substr( 0, height_str.size() - 1 ) );
                }
                else
                {
                    height = Ogre::StringConverter::parseReal( height_str );
                }
            }



            UiWidget* widget2 = new UiWidget( name, base_name + "." + name, widget );
            widget2->SetColour( colour.r, colour.g, colour.b, colour.a );
            widget2->SetAlign( ( align == "center" ) ? UiWidget::CENTER : ( ( align == "right" ) ? UiWidget::RIGHT : UiWidget::LEFT ) );
            widget2->SetVerticalAlign( ( valign == "middle" ) ? UiWidget::MIDDLE : ( ( valign == "bottom" ) ? UiWidget::BOTTOM : UiWidget::TOP ) );
            widget2->SetX( x, x_percent );
            widget2->SetY( y, y_percent );
            widget2->SetWidth( width, width_percent );
            widget2->SetHeight( height, height_percent );
            widget2->GeometryUpdate();
            widget->AddChild( widget2 );

            TiXmlNode* node2 = node->FirstChild();
            if( node2 != NULL )
            {
                LoadScreenRecursive( node2, base_name + "." + name, widget2 );
            }
        }

        node = node->NextSibling();
    }
}
