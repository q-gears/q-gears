#include "core/Logger.h"
#include "core/UiFont.h"


UiFont::UiFont( const Ogre::String& name, const Ogre::String& language ):
    m_Name(name),
    m_Language( language ),
    m_ImageName(""),
    m_ImageWidth(0),
    m_ImageHeight(0),
    m_Height(0)
{
    // Insets special symbol of next row
    UiCharData data;
    data.char_code = 10;
    data.x = 0;
    data.y = 0;
    data.width = 0;
    data.height = 0;
    data.pre = 0;
    data.post = 0;
    m_CharData.push_back( data );
}


UiFont::~UiFont()
{
}


const Ogre::String&
UiFont::GetName() const
{
    return m_Name;
}



const Ogre::String&
UiFont::GetLanguage() const
{
    return m_Language;
}
void
UiFont::SetImage(const Ogre::String& image, const int width, const int height)
{
    m_ImageName = image;
    m_ImageWidth = width;
    m_ImageHeight = height;
}


const Ogre::String&
UiFont::GetImageName() const
{
    return m_ImageName;
}


int
UiFont::GetImageWidth() const
{
    return m_ImageWidth;
}


int
UiFont::GetImageHeight() const
{
    return m_ImageHeight;
}


void
UiFont::SetHeight(const int height)
{
    m_Height = height;
}


int
UiFont::GetHeight() const
{
    return m_Height;
}


void
UiFont::AddCharData(const UiCharData& data)
{
    m_CharData.push_back(data);
}


UiCharData
UiFont::GetCharData(const int char_code) const
{
    for(size_t i = 0; i < m_CharData.size(); ++i)
    {
        if(m_CharData[i].char_code == char_code)
        {
            return m_CharData[i];
        }
    }

    LOG_ERROR("There is no char with char code " + Ogre::StringConverter::toString(char_code) + " in font " + m_Name + ".");
    UiCharData ret = {};
    return ret;
}
