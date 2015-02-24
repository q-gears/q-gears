#ifndef UI_FONT_H
#define UI_FONT_H

#include <OgreString.h>



struct UiCharData
{
    int char_code;
    int x;
    int y;
    int width;
    int height;
    int pre;
    int post;
};



class UiFont
{
public:
    UiFont( const Ogre::String& name, const Ogre::String& language );
    virtual ~UiFont();

    const Ogre::String& GetName() const;
    const Ogre::String& GetLanguage() const;

    void SetImage( const Ogre::String& image, const int width, const int height );
    const Ogre::String& GetImageName() const;
    int GetImageWidth() const;
    int GetImageHeight() const;

    void SetHeight( const int height );
    int GetHeight() const;

    void AddCharData( const UiCharData& data );
    UiCharData GetCharData( const int char_code ) const;

private:
    Ogre::String              m_Name;
    Ogre::String              m_Language;

    Ogre::String              m_ImageName;
    int                       m_ImageWidth;
    int                       m_ImageHeight;
    int                       m_Height;
    std::vector< UiCharData > m_CharData;
};



#endif // UI_FONT_H
