#ifndef XML_TEXTS_FILE_H
#define XML_TEXTS_FILE_H

#include "XmlFile.h"



class XmlTextsFile : public XmlFile
{
public:
    XmlTextsFile( const Ogre::String& file );
    virtual ~XmlTextsFile();

    void LoadTexts( const Ogre::String& language );
};



#endif // XML_TEXTS_FILE_H
