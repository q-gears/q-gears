#include "XmlFile.h"

#include <OgreStringConverter.h>

#include "Logger.h"



XmlFile::XmlFile( const Ogre::String& file ):
    m_File( file )
{
    m_NormalFile = m_File.LoadFile();

    if( m_NormalFile == false )
    {
        LOG_ERROR( "Can't open " + file + ". TinyXml Error: " + m_File.ErrorDesc() );
    }
}



XmlFile::~XmlFile()
{
}



const bool
XmlFile::GetBool( TiXmlNode* node, const Ogre::String& tag, bool def ) const
{
    bool ret = def;

    if( node->Type() == TiXmlNode::TINYXML_ELEMENT )
    {
        const std::string* string = node->ToElement()->Attribute( tag );
        if( string != NULL )
        {
            ret = Ogre::StringConverter::parseBool( *string );
        }
    }

    return ret;
}



const int
XmlFile::GetInt( TiXmlNode* node, const Ogre::String& tag, int def ) const
{
    int ret = def;

    if( node->Type() == TiXmlNode::TINYXML_ELEMENT )
    {
        const std::string* string = node->ToElement()->Attribute( tag );
        if( string != NULL )
        {
            ret = Ogre::StringConverter::parseInt( *string );
        }
    }

    return ret;
}



const float
XmlFile::GetFloat( TiXmlNode* node, const Ogre::String& tag, float def ) const
{
    float ret = def;

    if( node->Type() == TiXmlNode::TINYXML_ELEMENT )
    {
        const std::string* string = node->ToElement()->Attribute( tag );
        if( string != NULL )
        {
            ret = Ogre::StringConverter::parseReal( *string );
        }
    }

    return ret;
}



const Ogre::String
XmlFile::GetString( TiXmlNode* node, const Ogre::String& tag, const Ogre::String& def ) const
{
    Ogre::String ret = def;

    if( node->Type() == TiXmlNode::TINYXML_ELEMENT )
    {
        const std::string* string = node->ToElement()->Attribute( tag );
        if( string != NULL )
        {
            ret = *string;
        }
    }

    return ret;
}



const Ogre::UTFString
XmlFile::GetUTFString( TiXmlNode* node, const Ogre::String& tag, const Ogre::UTFString& def ) const
{
    Ogre::UTFString ret = def;

    if( node->Type() == TiXmlNode::TINYXML_ELEMENT )
    {
        const std::string* string = node->ToElement()->Attribute( tag );
        if( string != NULL )
        {
            ret = ( *string ).c_str();
        }
    }

    return ret;
}



/*
const Ogre::UTFString
XmlFile::GetText(TiXmlNode* node) const
{
    Ogre::UTFString ret = "";

    for (xmlNodePtr node2 = node->xmlChildrenNode; node2 != NULL; node2 = node2->next)
    {
        if (node2->type == XML_TEXT_NODE)
        {
            xmlBufferPtr buffer = xmlBufferCreateSize(1024);
            int res = xmlNodeBufGetContent(buffer, node2);
            if (res == -1)
            {
                Ogre::LogManager::getSingletonPtr()->logMessage("[ERROR] Failed to read text.");
            }
            else
            {
                ret = (const char*)(xmlBufferContent(buffer));
            }
            xmlBufferFree(buffer);
        }
    }

    return ret;
}
*/



const Ogre::Vector2
XmlFile::GetVector2( TiXmlNode* node, const Ogre::String& tag, const Ogre::Vector2& def ) const
{
    Ogre::Vector2 ret = def;

    if( node->Type() == TiXmlNode::TINYXML_ELEMENT )
    {
        const std::string* string = node->ToElement()->Attribute( tag );
        if( string != NULL )
        {
            ret = Ogre::StringConverter::parseVector2( *string );
        }
    }

    return ret;
}



const Ogre::Vector3
XmlFile::GetVector3( TiXmlNode* node, const Ogre::String& tag, const Ogre::Vector3& def ) const
{
    Ogre::Vector3 ret = def;

    if( node->Type() == TiXmlNode::TINYXML_ELEMENT )
    {
        const std::string* string = node->ToElement()->Attribute( tag );
        if( string != NULL )
        {
            ret = Ogre::StringConverter::parseVector3( *string );
        }
    }

    return ret;
}



const Ogre::Matrix4
XmlFile::GetMatrix4( TiXmlNode* node, const Ogre::String& tag ) const
{
    Ogre::Matrix4 ret = Ogre::Matrix4::IDENTITY;

    if( node->Type() == TiXmlNode::TINYXML_ELEMENT )
    {
        const std::string* string = node->ToElement()->Attribute( tag );
        if( string != NULL )
        {
            ret = Ogre::StringConverter::parseMatrix4( *string );
        }
    }

    return ret;
}



const Ogre::ColourValue
XmlFile::GetColourValue( TiXmlNode* node, const Ogre::String& tag, const Ogre::ColourValue& def ) const
{
    Ogre::ColourValue ret = def;

    if( node->Type() == TiXmlNode::TINYXML_ELEMENT )
    {
        const std::string* string = node->ToElement()->Attribute( tag );
        if( string != NULL )
        {
            ret = Ogre::StringConverter::parseColourValue( *string );
        }
    }

    return ret;
}
