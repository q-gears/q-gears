#include "XmlLanguageFile.h"



XmlLanguageFile::XmlLanguageFile( const Ogre::String& file ):
    XmlFile( file )
{
}



XmlLanguageFile::~XmlLanguageFile()
{
}



void
XmlLanguageFile::LoadLanguage( const Ogre::String& language )
{
    TiXmlNode* node = m_File.RootElement();

    if( node == NULL || node->ValueStr() != "languages" )
    {
        LOG_ERROR( "UI Text Manager: " + m_File.ValueStr() + " is not a valid language file! No <languages> in root." );
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
