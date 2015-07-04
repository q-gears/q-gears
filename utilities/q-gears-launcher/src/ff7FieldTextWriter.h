#pragma once

#include "common/TypeDefine.h"
#include "common/Logger.h"
#include <vector>
#include <memory>

class FF7FieldTextWriter
{
public:
    void Begin(std::string fileName);
    void Write(const std::vector<u8>& scriptSectionBuffer, std::string fieldName, bool english = true);
    void End();
private:
    void AddText(std::vector< unsigned char >& text);

    u16 GetU16LE(u32 offset);
    u8 GetU8(u32 offset);

    std::unique_ptr<Logger> mLogger;
    std::vector<u8> mData;
    bool mTagOpen = false;
};
