#include "XmlScriptsFile.h"

#include "Logger.h"
#include "ScriptManager.h"



XmlScriptsFile::XmlScriptsFile( const Ogre::String& file ):
    XmlFile( file )
{
}



XmlScriptsFile::~XmlScriptsFile()
{
}



void
XmlScriptsFile::LoadScripts()
{
    TiXmlNode* node = m_File.RootElement();

    if( node == NULL || node->ValueStr() != "scripts" )
    {
        LOG_ERROR( m_File.ValueStr() + " is not a valid scripts file! No <scripts> in root." );
        return;
    }

    node = node->FirstChild();
    while( node != NULL )
    {
        if( node->Type() == TiXmlNode::TINYXML_ELEMENT && node->ValueStr() == "script" )
        {
            ScriptManager::getSingleton().RunFile( GetString( node, "file" ) );
        }
        else if( node->Type() == TiXmlNode::TINYXML_ELEMENT && node->ValueStr() == "entity_script" )
        {
            Ogre::String name = GetString( node, "name" );
            if( name == "" )
            {
                LOG_ERROR( "There is no name specified for <entity_script> tag." );
                continue;
            }

            ScriptManager::getSingleton().AddEntity( ScriptManager::SYSTEM, name );
        }

        node = node->NextSibling();
    }
}
