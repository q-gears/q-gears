#ifndef XML_LANGUAGE_FILE_H
#define XML_LANGUAGE_FILE_H

#include "TextManager.h"
#include "XmlFile.h"



class XmlLanguageFile : public XmlFile
{
public:
    XmlLanguageFile( const Ogre::String& file );
    virtual ~XmlLanguageFile();

    void LoadLanguage( const Ogre::String& language );
};



#endif // XML_LANGUAGE_FILE_H
