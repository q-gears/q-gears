// $Id: XmlFile.h 96 2006-11-13 03:34:17Z crazy_otaku $

#ifndef XML_FILE_h
#define XML_FILE_h

#include "../../common/TypeDefine.h"
#include "../../common/display/3dTypes.h"
#include "../../common/utilites/NoCopy.h"
#include "../../common/utilites/StdString.h"

#include <libxml/tree.h>



class XmlFile : public NoCopy<XmlFile>
{
public:
    explicit       XmlFile(const RString& file);
    virtual       ~XmlFile(void);

    const RString& GetFileName(void) const;

    const Sint32   GetInt(const xmlNodePtr& node, const RString& tag) const;
    const RString  GetString(const xmlNodePtr& node, const RString& tag) const;
    const Vector3  GetVector3(const xmlNodePtr& node, const RString& tag) const;

protected:
    RString   mFileName;   /**< @brief name of file       */
    xmlDocPtr mFile;
};



#endif // XML_FILE_h
