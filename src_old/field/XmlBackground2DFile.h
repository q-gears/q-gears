// $Id$

#ifndef XML_Background2D_FILE_h
#define XML_Background2D_FILE_h

#include <string>

#include "Background2D.h"
#include "../core/XmlFile.h"



class XmlBackground2DFile : public XmlFile
{
public:
    explicit XmlBackground2DFile(const std::string& file);
    virtual ~XmlBackground2DFile(void);

    Background2D* Load(void);

private:
    bool       m_NormalFile;
    xmlNodePtr m_RootNode;
};



#endif // XML_Background2D_FILE_h
