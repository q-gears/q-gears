#ifndef XML_FONTS_FILE_H
#define XML_FONTS_FILE_H

#include "XmlFile.h"



class XmlFontsFile : public XmlFile
{
public:
    XmlFontsFile( const Ogre::String& file );
    virtual ~XmlFontsFile();

    void LoadFonts();
};



#endif // XML_FONTS_FILE_H
