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
            Ogre::String name = GetString( node, "name" );

            Ogre::ColourValue colour = GetColourValue( node, "colour" );
            Ogre::Vector2 point1 = GetVector2( node, "point1" );
            Ogre::Vector2 point2 = GetVector2( node, "point2" );
            Ogre::Vector2 point3 = GetVector2( node, "point3" );
            Ogre::Vector2 point4 = GetVector2( node, "point4" );

            UiWidget* widget2 = new UiWidget( name, base_name + "." + name, widget );
            widget2->SetColour( colour.r, colour.g, colour.b, colour.a );
            widget2->Quad( point1.x, point1.y, point2.x, point2.y, point3.x, point3.y, point4.x, point4.y );
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
