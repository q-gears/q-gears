#include "UiFont.h"

#include "Logger.h"



UiFont::UiFont( const Ogre::String& name ):
    m_Name( name ),
    m_ImageName( "" ),
    m_ImageWidth( 0 ),
    m_ImageHeight( 0 ),
    m_Height( 0 )
{
}



UiFont::~UiFont()
{
}



const Ogre::String
UiFont::GetName() const
{
    return m_Name;
}



void
UiFont::SetImage( const Ogre::String& image, const int width, const int height )
{
    m_ImageName = image;
    m_ImageWidth = width;
    m_ImageHeight = height;
}



const Ogre::String
UiFont::GetImageName() const
{
    return m_ImageName;
}



const int
UiFont::GetImageWidth() const
{
    return m_ImageWidth;
}



const int
UiFont::GetImageHeight() const
{
    return m_ImageHeight;
}



void
UiFont::SetHeight( const int height )
{
    m_Height = height;
}



const int
UiFont::GetHeight() const
{
    return m_Height;
}



void
UiFont::AddCharData( const UiCharData& data )
{
    m_CharData.push_back( data );
}



const UiCharData
UiFont::GetCharData( const int char_code ) const
{
    for( int i = 0; i < m_CharData.size(); ++i )
    {
        if( m_CharData[ i ].char_code == char_code )
        {
            return m_CharData[ i ];
        }
    }

    LOG_ERROR( "There is no char with char code " + Ogre::StringConverter::toString( char_code ) + " in font " + m_Name + "." );
    UiCharData ret;
    return ret;
}
