#include "XmlFontFile.h"

#include "Logger.h"
#include "UiManager.h"
#include "UiFont.h"



XmlFontFile::XmlFontFile( const Ogre::String& file ):
    XmlFile( file )
{
}



XmlFontFile::~XmlFontFile()
{
}



void
XmlFontFile::LoadFont()
{
    TiXmlNode* node = m_File.RootElement();

    if( node == NULL || node->ValueStr() != "font" )
    {
        LOG_ERROR( m_File.ValueStr() + " is not a valid font file! No <font> in root." );
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
        if( node->Type() == TiXmlNode::TINYXML_ELEMENT && ( node->ValueStr() == "widget" || node->ValueStr() == "sprite" || node->ValueStr() == "text_area" ) )
        {
            Ogre::String name = GetString( node, "name" );
            if( name != "" )
            {
                UiWidget* widget2;

                if( node->ValueStr() == "sprite" )
                {
                    widget2 = new UiSprite( name, base_name + "." + name, widget );
                }
                else if( node->ValueStr() == "text_area" )
                {
                    widget2 = new UiTextArea( name, base_name + "." + name, widget );
                }
                else
                {
                    widget2 = new UiWidget( name, base_name + "." + name, widget );
                }



                if( node->ValueStr() == "sprite" )
                {
                    Ogre::String image = GetString( node, "image" );
                    if( image != "" )
                    {
                        ( ( UiSprite* )widget2 )->SetImage( image );
                    }
                }



                if( node->ValueStr() == "text_area" )
                {
                    Ogre::String text = GetString( node, "text", "" );
                    if( text != "" )
                    {
                        ( ( UiTextArea* )widget2 )->SetText( text );
                    }

                    Ogre::String font = GetString( node, "font", "" );
                    if( font != "" )
                    {
                        Ogre::StringVector data = Ogre::StringUtil::split( font, " " );
                        if( data.size() > 1 )
                        {
                            ( ( UiTextArea* )widget2 )->SetFont( data[ 0 ], Ogre::StringConverter::parseReal( data[ 1 ] ) );
                        }
                    }
                }



                Ogre::Vector3 colour = GetVector3( node, "colour", Ogre::Vector3( 1, 1, 1 ) );
                widget2->SetColour( colour.x, colour.y, colour.z );

                float alpha = GetFloat( node, "alpha", 1 );
                widget2->SetAlpha( alpha );




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
                else if( node->ValueStr() == "text_area" )
                {
                    ( ( UiTextArea* )widget2 )->UpdateGeometry();
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
