#include "core/Logger.h"
#include "core/XmlTextFile.h"
#include "core/XmlTextsFile.h"
#include "core/TextManager.h"

XmlTextsFile::XmlTextsFile( const Ogre::String& file):
    XmlFile( file)
{
}


XmlTextsFile::~XmlTextsFile()
{
}



void
XmlTextsFile::GetAvailableLanguages( Ogre::StringVector& languages )
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
            languages.push_back( GetString( node, "name" ) );
        }
        node = node->NextSibling();
    }
}



void
XmlTextsFile::LoadTexts()
{
    TiXmlNode* node = m_File.RootElement();

    if( node == NULL || node->ValueStr() != "texts" )
    {
        LOG_ERROR( "Text Manager: " + m_File.ValueStr() + " is not a valid texts file! No <texts> in root." );
        return;
    }

    Ogre::String language = TextManager::getSingleton().GetLanguage();

    node = node->FirstChild();
    while( node != nullptr )
    {
        if( node->Type() == TiXmlNode::TINYXML_ELEMENT && node->ValueStr() == "language" )
        {
            if( GetString( node, "name" ) == language )
            {
                TiXmlNode* node2 = node->FirstChild();
                while( node2 != nullptr )
                {
                    if( node2->Type() == TiXmlNode::TINYXML_ELEMENT && node2->ValueStr() == "text" )
                    {
                        Ogre::String file = GetString( node2, "file" );
                        if( file != "" )
                        {
                            XmlTextFile text( "./data/" + file );
                            text.LoadTexts();
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
