#ifndef XML_SCREEN_FILE_H
#define XML_SCREEN_FILE_H

#include "uiWidget.h"
#include "XmlFile.h"



class XmlScreenFile : public XmlFile
{
public:
    explicit XmlScreenFile( const Ogre::String& file );
    virtual ~XmlScreenFile();

    void LoadScreen();
    void LoadScreenRecursive( TiXmlNode* node, const Ogre::String& base_name, UiWidget* widget );
    void ParsePersent( float& value, float& value_add, bool& value_percent, const Ogre::String& string );
};



#endif // XML_SCREEN_FILE_H
