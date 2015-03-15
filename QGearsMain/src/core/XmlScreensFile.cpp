#include "core/Logger.h"
#include "core/XmlScreenFile.h"
#include "core/XmlScreensFile.h"
#include "core/XmlPrototypesFile.h"


XmlScreensFile::XmlScreensFile(const Ogre::String& file):
    XmlFile(file)
{
}


XmlScreensFile::~XmlScreensFile()
{
}


void
XmlScreensFile::LoadScreens()
{
    TiXmlNode* node = m_File.RootElement();

    if( node == nullptr || node->ValueStr() != "ui" )
    {
        LOG_ERROR( "UI XML Manager: " + m_File.ValueStr() + " is not a valid ui file! No <ui> in root." );
        return;
    }

    node = node->FirstChild();
    while( node != nullptr )
    {
        if( node->Type() == TiXmlNode::TINYXML_ELEMENT && node->ValueStr() == "prototype" )
        {
            XmlPrototypesFile prototypes( "./data/" + GetString( node, "file_name" ) );
            prototypes.LoadPrototypes();
        }
        node = node->NextSibling();
    }

    node = m_File.RootElement();
    node = node->FirstChild();
    while( node != NULL )
    {
        if(node->Type() == TiXmlNode::TINYXML_ELEMENT && node->ValueStr() == "screen")
        {
            XmlScreenFile screen("./data/" + GetString(node, "file_name"));
            screen.LoadScreen();
        }
        node = node->NextSibling();
    }
}
