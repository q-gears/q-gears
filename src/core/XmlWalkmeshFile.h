#ifndef XML_WALKMESH_FILE_H
#define XML_WALKMESH_FILE_H

#include "Walkmesh.h"
#include "XmlFile.h"



class XmlWalkmeshFile : public XmlFile
{
public:
    XmlWalkmeshFile( const Ogre::String& file );
    virtual ~XmlWalkmeshFile();

    void Load();
};



#endif // XML_WALKMESH_FILE_H
