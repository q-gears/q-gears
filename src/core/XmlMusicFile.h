#ifndef XML_MUSIC_FILE_H
#define XML_MUSIC_FILE_H

#include "Ogre.h"

class XmlMusicFile
{
public:
    XmlMusicFile( const Ogre::String& name, const Ogre::String& file, float loop );
    ~XmlMusicFile();

    void LoadMusic();
private:
    Ogre::String MusicName;
    Ogre::String MusicFile;
    float MusicLoop;
};



#endif // XML_MUSIC_FILE_H
