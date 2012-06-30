#ifndef XML_SCRIPTS_FILE_H
#define XML_SCRIPTS_FILE_H

#include "XmlFile.h"



class XmlScriptsFile : public XmlFile
{
public:
    XmlScriptsFile( const Ogre::String& file );
    virtual ~XmlScriptsFile();

    void LoadScripts();
};



#endif // XML_SCRIPTS_FILE_H
