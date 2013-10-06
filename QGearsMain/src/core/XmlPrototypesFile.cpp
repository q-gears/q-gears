#include "core/XmlPrototypesFile.h"

#include "core/Logger.h"
#include "core/UiManager.h"



XmlPrototypesFile::XmlPrototypesFile( const Ogre::String& file ):
    XmlFile( file )
{
}



XmlPrototypesFile::~XmlPrototypesFile()
{
}



void
XmlPrototypesFile::LoadPrototypes()
{
    TiXmlNode* node = m_File.RootElement();

    if( node == NULL || node->ValueStr() != "prototypes" )
    {
        LOG_ERROR( "UI Manager: " + m_File.ValueStr() + " is not a valid prototypes file! No <prototypes> in root." );
        return;
    }

    node = node->FirstChild();
    while( node != NULL )
    {
        if( node->Type() == TiXmlNode::TINYXML_ELEMENT && node->ValueStr() == "prototype" )
        {
            Ogre::String name = GetString( node, "name" );
            UiManager::getSingleton().AddPrototype( name, node->Clone() );
        }

        node = node->NextSibling();
    }
}
