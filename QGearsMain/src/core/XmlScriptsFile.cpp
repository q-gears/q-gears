#include "core/XmlScriptsFile.h"

#include "core/Logger.h"
#include "core/ScriptManager.h"



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
    ScriptManager &script_manager(ScriptManager::getSingleton());
    while( node != NULL )
    {
        if( node->Type() == TiXmlNode::TINYXML_ELEMENT && node->ValueStr() == "script" )
        {
            script_manager.RunFile( GetString( node, "file" ) );
        }
        else if( node->Type() == TiXmlNode::TINYXML_ELEMENT && node->ValueStr() == "system_script" )
        {
            Ogre::String name = GetString( node, "name" );
            if( name == "" )
            {
                LOG_ERROR( "There is no name specified for <system_script> tag." );
                continue;
            }

            script_manager.AddEntity( ScriptManager::SYSTEM, name, NULL );
        }

        node = node->NextSibling();
    }
}
