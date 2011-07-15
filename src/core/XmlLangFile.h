// $Id$

#ifndef XML_LANG_FILE_h
#define XML_LANG_FILE_h

#include "TextManager.h"
#include "XmlFile.h"



class XmlLangFile : public XmlFile
{
public:
    explicit XmlLangFile(const Ogre::String& file);
    virtual ~XmlLangFile(void);

    void LoadLanguageRoot(TextManager* text_manager, const Ogre::String& language);

private:
    bool       m_NormalFile;
    xmlNodePtr m_RootNode;
};



#endif // XML_LANG_FILE_h
