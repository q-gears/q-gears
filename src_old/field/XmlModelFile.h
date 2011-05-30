// $Id$

#ifndef XML_MODEL_FILE_h
#define XML_MODEL_FILE_h

#include "../core/XmlFile.h"



class XmlModelFile : public XmlFile
{
public:
    explicit XmlModelFile(const Ogre::String& file);
    virtual ~XmlModelFile(void);

    const Ogre::String GetModelFileNameById(const int model_id);

private:
    bool       m_NormalFile;
    xmlNodePtr m_RootNode;
};



#endif // XML_MODEL_FILE_h
