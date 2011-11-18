#ifndef XML_BACKGROUND_2D_FILE_H
#define XML_BACKGROUND_2D_FILE_H

#include "XmlFile.h"



class XmlBackground2DFile : public XmlFile
{
public:
    XmlBackground2DFile( const Ogre::String& file );
    virtual ~XmlBackground2DFile();

    void Load();
};



#endif // XML_BACKGROUND_2D_FILE_H
