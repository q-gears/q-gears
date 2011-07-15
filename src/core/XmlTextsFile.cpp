#include "XmlTextsFile.h"

#include "Logger.h"
#include "XmlTextFile.h"



XmlTextsFile::XmlTextsFile( const Ogre::String& file ):
    XmlFile( file )
{
}



XmlTextsFile::~XmlTextsFile()
{
}



void
XmlTextsFile::LoadTexts( const Ogre::String& language )
{
    TiXmlNode* node = m_File.RootElement();

    if( node == NULL || node->ValueStr() != "texts" )
    {
        LOG_ERROR( "UI Text Manager: " + m_File.ValueStr() + " is not a valid texts file! No <texts> in root." );
        return;
    }

    node = node->FirstChild();
    while( node != NULL )
    {
        if( node->Type() == TiXmlNode::TINYXML_ELEMENT && node->ValueStr() == "language" )
        {
            if( GetString( node, "name" ) == language )
            {
                TiXmlNode* node2 = node->FirstChild();
                while( node2 != NULL )
                {
                    XmlTextFile text( "./data/" + GetString( node2, "file" ) );
                    text.LoadText();

                    node2 = node2->NextSibling();
                }
            }
        }
        node = node->NextSibling();
    }
}
