#include "XmlMapsFile.h"

#include "Logger.h"



XmlMapsFile::XmlMapsFile( const Ogre::String& file ):
    XmlFile( file )
{
}



XmlMapsFile::~XmlMapsFile()
{
}



const Ogre::String
XmlMapsFile::GetMapFileNameByName( const Ogre::String& name )
{
    TiXmlNode* node = m_File.RootElement();

    if( node == NULL || node->ValueStr() != "maps" )
    {
        LOG_ERROR( "Field XML Manager: " + m_File.ValueStr() + " is not a valid maps file! No <maps> in root." );
        return "";
    }

    node = node->FirstChild();
    while( node != NULL )
    {
        if( node->Type() == TiXmlNode::TINYXML_ELEMENT && node->ValueStr() == "map" )
        {
            if( GetString( node, "name" ) == name )
            {
                return GetString( node, "file_name" );
            }
        }
        node = node->NextSibling();
    }

    LOG_WARNING( "Can't find map \"" + name + "\" in " + m_File.ValueStr() + "." );
    return "";
}



void
XmlMapsFile::GetMapNames( Ogre::StringVector& complete_params )
{
    TiXmlNode* node = m_File.RootElement();

    if( node == NULL || node->ValueStr() != "maps" )
    {
        LOG_ERROR( "Field XML Manager: " + m_File.ValueStr() + " is not a valid maps file! No <maps> in root." );
        return;
    }

    node = node->FirstChild();
    while( node != NULL )
    {
        if( node->Type() == TiXmlNode::TINYXML_ELEMENT && node->ValueStr() == "map" )
        {
            complete_params.push_back( GetString( node, "name" ) );
        }
        node = node->NextSibling();
    }
}
