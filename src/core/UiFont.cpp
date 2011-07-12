#include "UiFont.h"

#include "Logger.h"



UiFont::UiFont( const Ogre::String& name ):
    m_Name( name ),
    m_ImageName( "" ),
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
UiFont::SetImageName( const Ogre::String& image )
{
    m_ImageName = image;
}



const Ogre::String
UiFont::GetImageName() const
{
    return m_ImageName;
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
