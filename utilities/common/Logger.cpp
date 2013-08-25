#include "Logger.h"
#include "FileSystem.h"

#include <OgreStringConverter.h>



Logger* LOGGER = NULL; // global and accessable from anywhere in our program



Ogre::String
HexToString( int value, unsigned short width, char fill )
{
    std::stringstream stream;
    stream.width( width );
    stream.fill( fill );
    stream.setf( std::ios::hex, std::ios::basefield );
    stream << value;
    return stream.str();
}



Ogre::String
BoolToString( bool value )
{
    return Ogre::StringConverter::toString( value );
}



Ogre::String
IntToString( int value )
{
    return Ogre::StringConverter::toString( value );
}



Ogre::String
FloatToString( float value )
{
    return Ogre::StringConverter::toString( value );
}



Logger::Logger( const Ogre::String& logFileName ):
    m_LogFile( logFileName )
{
    FILESYSTEM->RemoveFile( m_LogFile );
}



Logger::~Logger()
{
}



void
Logger::Log( const Ogre::String& text )
{
    FILESYSTEM->WriteFile(m_LogFile, text.c_str(), text.size());
}



void
Logger::LogW( const Ogre::UTFString& text )
{
    FILESYSTEM->WriteFile( m_LogFile, text.c_str(), text.size() * 2 );
}



void
Logger::Log( std::vector< unsigned char >& text )
{
    unsigned char* temp = new unsigned char[ text.size() ];
    for( int i = 0; i < text.size(); ++i )
    {
        temp[ i ] = text[ i ];
    }

    FILESYSTEM->WriteFile( m_LogFile, temp, text.size() );

    delete[] temp;
}
