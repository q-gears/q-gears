#include "core/Logger.h"
#include "core/UiManager.h"
#include "core/UiFont.h"
#include "core/XmlFontFile.h"


XmlFontFile::XmlFontFile(const Ogre::String& file):
    XmlFile(file)
{
}


XmlFontFile::~XmlFontFile()
{
}


void
XmlFontFile::LoadFont()
{
    TiXmlNode* node = m_File.RootElement();

    if(node == nullptr || node->ValueStr() != "font")
    {
        LOG_ERROR(m_File.ValueStr() + " is not a valid font file! No <font> in root.");
        return;
    }

    Ogre::String name = GetString(node, "name", "");
    Ogre::String language = GetString( node, "language", "" );
    Ogre::String image = GetString(node, "image", "");
    Ogre::Vector2 size = GetVector2(node, "image_size", Ogre::Vector2::ZERO);
    int height = GetInt(node, "height", 0);

    if(name != "" && image != "" && size.x != 0 && size.y != 0)
    {
        UiFont* font = new UiFont( name, language );
        font->SetImage(image, (int)size.x, (int)size.y);
        font->SetHeight(height);

        node = node->FirstChild();

        while(node != nullptr)
        {
            if(node->Type() == TiXmlNode::TINYXML_ELEMENT && node->ValueStr() == "char")
            {
                UiCharData data;

                Ogre::UTFString name = GetUTFString(node, "name", "");
                if(name != "")
                {
                    data.char_code = *(name.c_str());
                }

                data.x = GetInt(node, "x", 0);
                data.y = GetInt(node, "y", 0);
                data.width = GetInt(node, "width", 0);
                data.height = GetInt(node, "height", 0);
                data.pre = GetInt(node, "pre", 0);
                data.post = GetInt(node, "post", 0);

                font->AddCharData(data);
            }

            node = node->NextSibling();
        }

        UiManager::getSingleton().AddFont(font);
    }
}
