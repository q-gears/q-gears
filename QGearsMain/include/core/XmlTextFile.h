#ifndef XML_TEXT_FILE_H
#define XML_TEXT_FILE_H

#include "XmlFile.h"



class XmlTextFile : public XmlFile
{
public:
    XmlTextFile( const Ogre::String& file );
    virtual ~XmlTextFile();

    void LoadTexts();
};



#endif // XML_TEXT_FILE_H
