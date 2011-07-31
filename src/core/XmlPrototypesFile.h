#ifndef XML_PROTOTYPES_FILE_H
#define XML_PROTOTYPES_FILE_H

#include "XmlFile.h"



class XmlPrototypesFile : public XmlFile
{
public:
    XmlPrototypesFile( const Ogre::String& file );
    virtual ~XmlPrototypesFile();

    void LoadPrototypes();
};



#endif // XML_PROTOTYPES_FILE_H
