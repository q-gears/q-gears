#ifndef XML_FONT_FILE_H
#define XML_FONT_FILE_H

#include "UiWidget.h"
#include "XmlFile.h"



class XmlFontFile : public XmlFile
{
public:
    explicit XmlFontFile( const Ogre::String& file );
    virtual ~XmlFontFile();

    void LoadFont();
};



#endif // XML_FONT_FILE_H
