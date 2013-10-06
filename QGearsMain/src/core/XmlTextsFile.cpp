#include "core/XmlTextsFile.h"

#include "core/Logger.h"
#include "core/XmlTextFile.h"



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
                    if( node2->Type() == TiXmlNode::TINYXML_ELEMENT && node2->ValueStr() == "text" )
                    {
                        Ogre::String file = GetString( node2, "file" );
                        if( file != "" )
                        {
                            XmlTextFile text( "./data/" + file );
                            text.LoadText();
                        }
                        else
                        {
                            LOG_ERROR( "Empty filename in language " + language + "." );
                        }
                    }
                    node2 = node2->NextSibling();
                }
            }
        }
        node = node->NextSibling();
    }
}
