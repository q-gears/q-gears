// $Id: XmlFile.cpp 147 2007-02-24 06:13:17Z super_gb $

#include "RealFileSystem.h"
#include "XmlFile.h"
#include "../utilites/Logger.h"




XmlFile::XmlFile(const RString& file):
    mFileName(file),
    mFile(NULL)
{
    u32 buffer_size = REALFILESYSTEM->GetFileSize(file);

    // if it exist read properties
    if (buffer_size > 0)
    {
        u8* p_buffer = (u8*)malloc(sizeof(u8) * buffer_size);
        REALFILESYSTEM->ReadFile(file, p_buffer, 0, buffer_size);

        mFile = xmlParseMemory((const char*)p_buffer, buffer_size);

        free(p_buffer);
    }
    else
    {
        LOGGER->Log(LOGGER_WARNING, "Warning: %s not found!", mFileName.c_str());
    }
}



XmlFile::~XmlFile(void)
{
    xmlFreeDoc(mFile);
}



const RString&
XmlFile::GetFileName(void) const
{
    return mFileName;
}


const Sint32
XmlFile::GetInt(const xmlNodePtr& node, const RString& tag) const
{
    s32 ret = 0;

    xmlChar* prop = xmlGetProp(node, BAD_CAST tag.c_str());
    if (prop != NULL)
    {
        ret = atoi((const char*)prop);
        xmlFree(prop);
    }

    return ret;
}



const RString
XmlFile::GetString(const xmlNodePtr& node, const RString& tag) const
{
    RString ret("");

    xmlChar* prop = xmlGetProp(node, BAD_CAST tag.c_str());
    if (prop != NULL)
    {
        ret = (const char*)prop;
        xmlFree(prop);
    }

    return ret;
}



const Vector3
XmlFile::GetVector3(const xmlNodePtr& node, const RString& tag) const
{
    Vector3 ret(0.0f, 0.0f, 0.0f);

    xmlChar* prop = xmlGetProp(node, BAD_CAST tag.c_str());
    if (prop != NULL)
    {
        RString temp = (const char*)prop;
        xmlFree(prop);

        int equal_index = temp.find(" ");
        ret.x = atoi(temp.substr(0, equal_index).c_str());

        if (equal_index != RString::npos)
        {
            RString yz = temp.substr(equal_index + 1, temp.size() - equal_index - 1);
            equal_index = yz.find(" ");
            ret.y = atoi(yz.substr(0, equal_index).c_str());

            if (equal_index != RString::npos)
            {
                ret.z = atoi(yz.substr(equal_index + 1, yz.size() - equal_index - 1).c_str());
            }
        }
    }

    return ret;
}
