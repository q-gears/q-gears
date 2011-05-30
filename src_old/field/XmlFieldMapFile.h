// $Id$

#ifndef XML_FIELD_MAP_FILE_h
#define XML_FIELD_MAP_FILE_h

#include "../core/XmlFile.h"

class FieldModule;



class XmlFieldMapFile : public XmlFile
{
public:
    explicit XmlFieldMapFile(const Ogre::String& file);
    virtual ~XmlFieldMapFile();

    void     LoadMap(FieldModule* field_module);

private:
    bool       m_NormalFile;
    xmlNodePtr m_RootNode;
};



#endif // XML_FIELD_MAP_FILE_h
