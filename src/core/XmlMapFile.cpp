#include "XmlMapFile.h"

#include "EntityManager.h"
#include "Logger.h"
#include "ScriptManager.h"
#include "XmlBackground2DFile.h"
#include "XmlWalkmeshFile.h"



XmlMapFile::XmlMapFile( const Ogre::String& file ):
    XmlFile( file )
{
}



XmlMapFile::~XmlMapFile()
{
}



void
XmlMapFile::LoadMap()
{
    TiXmlNode* node = m_File.RootElement();

    if( node == NULL || node->ValueStr() != "map" )
    {
        LOG_ERROR( m_File.ValueStr() + " is not a valid fields map file! No <map> in root." );
        return;
    }

    node = node->FirstChild();
    while( node != NULL )
    {
        if( node->Type() == TiXmlNode::TINYXML_ELEMENT && node->ValueStr() == "walkmesh" )
        {
            Ogre::String name = GetString( node, "file_name" );
            if( name != "" )
            {
                XmlWalkmeshFile file( "./data/" + name );
                file.Load();
            }
        }
        else if( node->Type() == TiXmlNode::TINYXML_ELEMENT && node->ValueStr() == "background2d" )
        {
            Ogre::String name = GetString( node, "file_name" );
            if( name != "" )
            {
                XmlBackground2DFile file( "./data/" + name );
                file.Load();
            }
        }
        else if( node->Type() == TiXmlNode::TINYXML_ELEMENT && node->ValueStr() == "entity_model" )
        {
            Ogre::String name = GetString( node, "name" );
            if( name == "")
            {
                LOG_ERROR( "There is no name specified for <entity_model> tag." );
                continue;
            }
            Ogre::String file_name = GetString( node, "file_name" );
            if( file_name == "")
            {
                LOG_ERROR( "There is no file_name specified for <entity_model> tag." );
                continue;
            }

            Ogre::Vector3 position = GetVector3( node, "position" );
            Ogre::Degree direction = Ogre::Degree( GetFloat( node, "direction" ) );

            EntityManager::getSingleton().AddEntityModel( name, file_name, position, direction );
        }
        else if( node->Type() == TiXmlNode::TINYXML_ELEMENT && node->ValueStr() == "entity_script" )
        {
            Ogre::String name = GetString( node, "name" );
            if( name == "")
            {
                LOG_ERROR( "There is no name specified for <entity_script> tag." );
                continue;
            }

            EntityManager::getSingleton().AddEntityScript( name );
        }
        else if( node->Type() == TiXmlNode::TINYXML_ELEMENT && node->ValueStr() == "script" )
        {
            Ogre::String file_name = GetString( node, "file_name" );
            if( file_name != "" )
            {
                ScriptManager::getSingleton().RunFile( file_name );
            }
        }

        node = node->NextSibling();
    }
}



const Ogre::String
XmlMapFile::GetWalkmeshFileName()
{
    TiXmlNode* node = m_File.RootElement();

    if( node == NULL || node->ValueStr() != "map" )
    {
        LOG_ERROR( "Field Map XML Manager: " + m_File.ValueStr() + " is not a valid fields map file! No <map> in root." );
        return "";
    }

    node = node->FirstChild();
    while( node != NULL )
    {
        if( node->Type() == TiXmlNode::TINYXML_ELEMENT && node->ValueStr() == "walkmesh" )
        {
            return GetString( node, "file_name" );
        }
        node = node->NextSibling();
    }

    LOG_WARNING( "Can't find field's walkmesh in " + m_File.ValueStr() + "." );
    return "";
}
