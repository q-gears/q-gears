#include "core/XmlFontsFile.h"

#include "core/Logger.h"
#include "core/XmlFontFile.h"



XmlFontsFile::XmlFontsFile( const Ogre::String& file ):
    XmlFile( file )
{
}



XmlFontsFile::~XmlFontsFile()
{
}



void
XmlFontsFile::LoadFonts()
{
    TiXmlNode* node = m_File.RootElement();

    if( node == NULL || node->ValueStr() != "fonts" )
    {
        LOG_ERROR( "UI XML Manager: " + m_File.ValueStr() + " is not a valid fonts file! No <fonts> in root." );
        return;
    }

    node = node->FirstChild();
    while( node != NULL )
    {
        if( node->Type() == TiXmlNode::TINYXML_ELEMENT && node->ValueStr() == "font" )
        {
            XmlFontFile font( "./data/" + GetString( node, "file_name" ) );
            font.LoadFont();
        }
        node = node->NextSibling();
    }
}
