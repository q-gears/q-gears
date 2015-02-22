#include "core/Logger.h"
#include "core/UiManager.h"
#include "core/XmlTextFile.h"


XmlTextFile::XmlTextFile(const Ogre::String& file):
    XmlFile(file)
{
}


XmlTextFile::~XmlTextFile()
{
}


void
XmlTextFile::LoadText()
{
    TiXmlNode* node = m_File.RootElement();

    if(node == nullptr || node->ValueStr() != "texts")
    {
        LOG_ERROR("UI Manager: " + m_File.ValueStr() + " is not a valid text file! No <texts> in root.");
        return;
    }

    node = node->FirstChild();
    while(node != nullptr)
    {
        if(node->Type() == TiXmlNode::TINYXML_ELEMENT && node->ValueStr() == "text")
        {
            Ogre::String name = GetString(node, "name");
            UiManager::getSingleton().AddText(name, node->Clone());
        }

        node = node->NextSibling();
    }
}
