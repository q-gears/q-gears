#ifndef XML_TEXTS_FILE_H
#define XML_TEXTS_FILE_H

#include "XmlFile.h"

#include <OgreStringVector.h>


class XmlTextsFile : public XmlFile
{
public:
    XmlTextsFile( const Ogre::String& file );
    virtual ~XmlTextsFile();

    void GetAvailableLanguages( Ogre::StringVector& languages );
    void LoadTexts();
};

#endif // XML_TEXTS_FILE_H
