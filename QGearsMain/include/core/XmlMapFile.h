#ifndef XML_MAP_FILE_H
#define XML_MAP_FILE_H

#include "XmlFile.h"



class XmlMapFile : public XmlFile
{
public:
    explicit XmlMapFile( const Ogre::String& file );
    virtual ~XmlMapFile();

    void LoadMap();
    const Ogre::String GetWalkmeshFileName();
};



#endif // XML_MAP_FILE_H
