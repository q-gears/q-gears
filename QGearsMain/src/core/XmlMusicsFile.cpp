#include "core/AudioManager.h"
#include "core/Logger.h"
#include "core/XmlMusicsFile.h"


XmlMusicsFile::XmlMusicsFile(const Ogre::String& file):
    XmlFile(file)
{
}


XmlMusicsFile::~XmlMusicsFile()
{
}


void
XmlMusicsFile::LoadMusics()
{
    TiXmlNode* node = m_File.RootElement();

    if(node == nullptr || node->ValueStr() != "musics")
    {
        LOG_ERROR(m_File.ValueStr() + " is not a valid musics file! No <musics> in root.");
        return;
    }

    node = node->FirstChild();
    while(node != nullptr)
    {
        if(node->Type() == TiXmlNode::TINYXML_ELEMENT && node->ValueStr() == "music")
        {
            AudioManager::Music music;
            music.name = GetString(node, "name");
            music.file = "./data/" + GetString(node, "file_name");
            music.loop = GetFloat(node, "loop", -1);

            AudioManager::getSingleton().AddMusic(music);

        }
        node = node->NextSibling();
    }
}
