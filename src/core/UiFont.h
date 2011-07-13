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
    UiFont( const Ogre::String& name );
    virtual ~UiFont();

    const Ogre::String GetName() const;

    void SetImageName( const Ogre::String& image );
    const Ogre::String GetImageName() const;

    void SetImageSize( const int width, const int height );
    const int GetImageWidth() const;
    const int GetImageHeight() const;

    void SetHeight( const int height );
    const int GetHeight() const;

    void AddCharData( const UiCharData& data );
    const UiCharData GetCharData( const int char_code ) const;

private:
    Ogre::String              m_Name;

    Ogre::String              m_ImageName;
    int                       m_ImageWidth;
    int                       m_ImageHeight;
    int                       m_Height;
    std::vector< UiCharData > m_CharData;
};



#endif // UI_FONT_H
