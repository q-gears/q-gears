#include "core/XmlMapFile.h"

#include "core/EntityManager.h"
#include "core/Logger.h"
#include "core/ScriptManager.h"
#include "core/XmlBackground2DFile.h"

#include "map/QGearsBackground2DFileManager.h"
#include "map/QGearsWalkmeshFileManager.h"


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
            Ogre::String name( GetString( node, "file_name" ) );
            if( !name.empty() )
            {
                QGears::WalkmeshFileManager::getSingleton();
                QGears::WalkmeshFilePtr walkmesh =  QGears::WalkmeshFileManager::getSingleton().load( name, "Game" ).staticCast<QGears::WalkmeshFile>();
                EntityManager::getSingleton().GetWalkmesh()->load( walkmesh );
            }
        }
        else if( node->Type() == TiXmlNode::TINYXML_ELEMENT && node->ValueStr() == "movement_rotation" )
        {
            Ogre::Degree rotation = Ogre::Degree( GetFloat( node, "degree", 0 ) );
            EntityManager::getSingleton().SetPlayerMoveRotation( Ogre::Radian( rotation ) );
        }
        else if( node->Type() == TiXmlNode::TINYXML_ELEMENT && node->ValueStr() == "background2d" )
        {
            Ogre::String name = GetString( node, "file_name" );
            if( name != "" )
            {
                // TODO migrate this code to a Resource and use it's group to load background
                QGears::Background2DFilePtr background =  QGears::Background2DFileManager::getSingleton().load( name, "Game" ).staticCast<QGears::Background2DFile>();
                EntityManager::getSingleton().GetBackground2D()->load( background );
            }
        }
        else if( node->Type() == TiXmlNode::TINYXML_ELEMENT && node->ValueStr() == "entity_model" )
        {
            Ogre::String name = GetString( node, "name" );
            if( name == "" )
            {
                LOG_ERROR( "There is no name specified for <entity_model> tag." );
                continue;
            }
            Ogre::String file_name = GetString( node, "file_name" );
            if( file_name == "" )
            {
                LOG_ERROR( "There is no file_name specified for <entity_model> tag." );
                continue;
            }

            Ogre::Vector3 position( GetVector3( node, "position" ) );
            Ogre::Degree direction( Ogre::Degree( GetFloat( node, "direction" ) ) );
            Ogre::Vector3 scale( GetVector3( node, "scale", Ogre::Vector3::UNIT_SCALE ) );
            Ogre::Quaternion orientation( GetQuaternion( node, "root_orientation" ) );

            EntityManager::getSingleton().AddEntity( name, file_name, position, direction, scale, orientation );
        }
        else if( node->Type() == TiXmlNode::TINYXML_ELEMENT && node->ValueStr() == "entity_trigger" )
        {
            Ogre::String name = GetString( node, "name" );
            if( name == "" )
            {
                LOG_ERROR( "There is no name specified for <entity_trigger> tag." );
                continue;
            }

            Ogre::Vector3 point1 = GetVector3( node, "point1", Ogre::Vector3::ZERO );
            Ogre::Vector3 point2 = GetVector3( node, "point2", Ogre::Vector3::ZERO );
            bool enabled = GetBool( node, "enabled", false );

            EntityManager::getSingleton().AddEntityTrigger( name, point1, point2, enabled );
        }
        else if( node->Type() == TiXmlNode::TINYXML_ELEMENT && node->ValueStr() == "entity_point" )
        {
            Ogre::String name = GetString( node, "name" );
            if( name == "" )
            {
                LOG_ERROR( "There is no name specified for <entity_point> tag." );
                continue;
            }

            Ogre::Vector3 position = GetVector3( node, "position" );
            float rotation = GetFloat( node, "rotation" );
            EntityManager::getSingleton().AddEntityPoint( name, position, rotation );
        }
        else if( node->Type() == TiXmlNode::TINYXML_ELEMENT && node->ValueStr() == "entity_script" )
        {
            Ogre::String name = GetString( node, "name" );
            if( name == "" )
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
