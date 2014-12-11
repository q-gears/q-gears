#ifndef XML_MUSICS_FILE_H
#define XML_MUSICS_FILE_H

#include "XmlFile.h"



class XmlMusicsFile : public XmlFile
{
public:
    XmlMusicsFile( const Ogre::String& file );
    virtual ~XmlMusicsFile();

    void LoadMusics();
};



#endif // XML_MUSICS_FILE_H
