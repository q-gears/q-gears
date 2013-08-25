#ifndef XML_SCREEN_FILE_H
#define XML_SCREEN_FILE_H

#include "UiWidget.h"
#include "XmlFile.h"



class XmlScreenFile : public XmlFile
{
public:
    explicit XmlScreenFile( const Ogre::String& file );
    virtual ~XmlScreenFile();

    void LoadScreen();
    void LoadScreenRecursive( TiXmlNode* node, const Ogre::String& base_name, UiWidget* widget );
    void ParsePersent( float& value_percent, float& value, const Ogre::String& string );
};



#endif // XML_SCREEN_FILE_H
