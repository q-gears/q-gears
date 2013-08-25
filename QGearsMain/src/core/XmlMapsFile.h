#ifndef XML_MAPS_FILE_H
#define XML_MAPS_FILE_H

#include <OgreStringVector.h>

#include "XmlFile.h"



class XmlMapsFile : public XmlFile
{
public:
    XmlMapsFile( const Ogre::String& file );
    virtual ~XmlMapsFile();

    const Ogre::String GetMapFileNameByName( const Ogre::String& name );
    void GetMapNames( Ogre::StringVector& complete_params );
};



#endif // XML_FIELD_FILE_H
