#ifndef LOGGER_H
#define LOGGER_H

#include <OgreString.h>
#include <OgreUTFString.h>



Ogre::String ToHexString( int value, unsigned short width, char fill );
Ogre::String ToBoolString( bool value );
Ogre::String ToIntString( int value );
Ogre::String ToFloatString( float value );



class Logger
{
public:
    explicit Logger( const Ogre::String& logFileName );
    virtual ~Logger();

    void     Log( const Ogre::String& text );
    void     LogW( const Ogre::UTFString& text );
    void     Log( std::vector<unsigned char>& text );

private:
    Ogre::String m_LogFile;
};



extern Logger *LOGGER;



#endif // LOGGER_H
