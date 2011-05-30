// $Id$

#ifndef XML_TEXT_FILE_h
#define XML_TEXT_FILE_h

#include "TextManager.h"
#include "XmlFile.h"



class XmlTextFile : public XmlFile
{
public:
    explicit XmlTextFile(const Ogre::String& file);
    virtual ~XmlTextFile(void);

    void LoadAllTexts(TextDataVector& texts);

private:
    bool       m_NormalFile;
    xmlNodePtr m_RootNode;
};



#endif // XML_TEXT_FILE_h
