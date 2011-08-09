#include "XmlMusicsFile.h"
#include "AudioManager.h" /* For default loop */
#include "Logger.h"

XmlMusicsFile::XmlMusicsFile( const Ogre::String& file ):
    XmlFile( file )
{
}

XmlMusicsFile::~XmlMusicsFile()
{
}

void
XmlMusicsFile::LoadMusics()
{
    TiXmlNode* node = m_File.RootElement();

    if( node == NULL || node->ValueStr() != "musics" )
    {
        LOG_ERROR( "UI XML Manager: " + m_File.ValueStr() + " is not a valid musics file! No <musics> in root." );
        return;
    }

    node = node->FirstChild();
    while( node != NULL )
    {
        if( node->Type() == TiXmlNode::TINYXML_ELEMENT && node->ValueStr() == "music" )
        {
            AudioManager &engine = AudioManager::getSingleton();

            AudioManager::Music Music;
            Music.Name = GetString( node, "name" );
            Music.File = "./data/" + GetString( node, "file_name" );
            Music.Loop = GetFloat( node, "loop", AudioManager::getSingleton().m_DEFAULT_LOOP );

            engine.AddMusic(Music);

        }
        node = node->NextSibling();
    }
}
