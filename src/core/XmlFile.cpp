#include "XmlFile.h"

#include <OgreStringConverter.h>

#include "Logger.h"



XmlFile::XmlFile( const Ogre::String& file ):
    m_File( file )
{
    m_NormalFile = m_File.LoadFile();

    if (m_NormalFile == false)
    {
        LOG_ERROR( "Can't open " + file + ". TinyXml Error: " + m_File.ErrorDesc() );
    }
}



XmlFile::~XmlFile()
{
}



const bool
XmlFile::GetBool( TiXmlNode* node, const Ogre::String& tag ) const
{
    bool ret = false;

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
XmlFile::GetInt( TiXmlNode* node, const Ogre::String& tag ) const
{
    int ret = 0;

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
XmlFile::GetFloat( TiXmlNode* node, const Ogre::String& tag ) const
{
    float ret = 0;

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
XmlFile::GetString( TiXmlNode* node, const Ogre::String& tag ) const
{
    Ogre::String ret( "" );

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
XmlFile::GetVector2( TiXmlNode* node, const Ogre::String& tag ) const
{
    Ogre::Vector2 ret = Ogre::Vector2::ZERO;

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
XmlFile::GetVector3( TiXmlNode* node, const Ogre::String& tag ) const
{
    Ogre::Vector3 ret = Ogre::Vector3::ZERO;

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
XmlFile::GetColourValue( TiXmlNode* node, const Ogre::String& tag ) const
{
    Ogre::ColourValue ret = Ogre::ColourValue::ZERO;

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
