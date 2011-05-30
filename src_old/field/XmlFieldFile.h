// $Id$

#ifndef XML_FIELD_FILE_h
#define XML_FIELD_FILE_h

#include "../core/XmlFile.h"



class XmlFieldFile : public XmlFile
{
public:
    explicit XmlFieldFile(const Ogre::String& file);
    virtual ~XmlFieldFile(void);

    const Ogre::String GetMapFileNameById(const int field_id);

private:
    bool       m_NormalFile;
    xmlNodePtr m_RootNode;
};



#endif // XML_FIELD_FILE_h
