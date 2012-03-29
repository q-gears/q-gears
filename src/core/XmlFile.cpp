#include "XmlFile.h"

#include <OgreStringConverter.h>

#include "Logger.h"



XmlFile::XmlFile( const Ogre::String& file ):
    m_File( file )
{
    m_File.SetCondenseWhiteSpace( false );
    m_NormalFile = m_File.LoadFile();

    if( m_NormalFile == false )
    {
        LOG_ERROR( "Can't open " + file + ". TinyXml Error: " + m_File.ErrorDesc() );
    }
}



XmlFile::~XmlFile()
{
}



bool
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



int
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



float
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



const Ogre::Vector4
XmlFile::GetVector4( TiXmlNode* node, const Ogre::String& tag, const Ogre::Vector4& def ) const
{
    Ogre::Vector4 ret = def;

    if( node->Type() == TiXmlNode::TINYXML_ELEMENT )
    {
        const std::string* string = node->ToElement()->Attribute( tag );
        if( string != NULL )
        {
            ret = Ogre::StringConverter::parseVector4( *string );
        }
    }

    return ret;
}



const Ogre::Matrix4
XmlFile::GetMatrix4( TiXmlNode* node, const Ogre::String& tag, const Ogre::Matrix4& def ) const
{
    Ogre::Matrix4 ret = def;

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



const Ogre::Quaternion
XmlFile::GetQuaternion( TiXmlNode* node, const Ogre::String& tag, const Ogre::Quaternion& def ) const
{
    Ogre::Quaternion ret = def;

    if( node->Type() == TiXmlNode::TINYXML_ELEMENT )
    {
        const std::string* string = node->ToElement()->Attribute( tag );
        if( string != NULL )
        {
            ret = Ogre::StringConverter::parseQuaternion( *string );
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
