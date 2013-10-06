#include "core/XmlScreensFile.h"

#include "core/Logger.h"
#include "core/XmlScreenFile.h"



XmlScreensFile::XmlScreensFile( const Ogre::String& file ):
    XmlFile( file )
{
}



XmlScreensFile::~XmlScreensFile()
{
}



void
XmlScreensFile::LoadScreens()
{
    TiXmlNode* node = m_File.RootElement();

    if( node == NULL || node->ValueStr() != "screens" )
    {
        LOG_ERROR( "UI XML Manager: " + m_File.ValueStr() + " is not a valid screens file! No <screens> in root." );
        return;
    }

    node = node->FirstChild();
    while( node != NULL )
    {
        if( node->Type() == TiXmlNode::TINYXML_ELEMENT && node->ValueStr() == "screen" )
        {
            XmlScreenFile screen( "./data/" + GetString( node, "file_name" ) );
            screen.LoadScreen();
        }
        node = node->NextSibling();
    }
}
