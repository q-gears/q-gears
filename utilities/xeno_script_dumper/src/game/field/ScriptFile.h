// $Id: ScriptFile.h 103 2006-11-26 07:19:38Z crazy_otaku $

#ifndef ScriptFILE_H
#define ScriptFILE_H

#include <vector>

#include "../../common/utilites/StdString.h"

#include "../filesystem/File.h"



class ScriptFile : public File
{
public:
    explicit ScriptFile(const RString &file);
    explicit ScriptFile(File* file);
    ScriptFile(File* file, const u32 &offset, const u32 &length);
    ScriptFile(u8* buffer, const u32 &offset, const u32 &length);
    virtual ~ScriptFile();

    void GetScripts();
    void GetEVariable(u32& script_pointer);
    void GetFVariable(u32& script_pointer);

    void GetU8Variable(u32& script_pointer, const RString &name);
    void GetS16Variable(u32& script_pointer, const RString &name);
    void GetU16Variable(u32& script_pointer, const RString &name);

    void GetVF40Variable(u32& script_pointer, const RString &name);
    void GetVF80Variable(u32& script_pointer, const RString &name);
    void GetVVariable(u32& script_pointer, const RString &name);
    void GetV80Variable(u32& script_pointer, const RString &name);
};



#endif // ScriptFILE_H
