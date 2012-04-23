#ifndef LOGGER_H
#define LOGGER_H

#include <OgreString.h>
#include <OgreUTFString.h>



Ogre::String HexToString( int value, unsigned short width, char fill );
Ogre::String BoolToString( bool value );
Ogre::String IntToString( int value );
Ogre::String FloatToString( float value );



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
