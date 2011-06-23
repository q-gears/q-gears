#ifndef XML_SCREENS_FILE_H
#define XML_SCREENS_FILE_H

#include "XmlFile.h"



class XmlScreensFile : public XmlFile
{
public:
    XmlScreensFile( const Ogre::String& file );
    virtual ~XmlScreensFile();

    void LoadScreens();
};



#endif // XML_SCREENS_FILE_H
