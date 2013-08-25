#ifndef FONT_FILE_h
#define FONT_FILE_h

#include "../../../../common/Surface.h"
#include "../../common/utilites/StdString.h"

#include "../../../../common/Vram.h"
#include "../filesystem/File.h"



class FontFile : public File
{
public:
    explicit  FontFile(const RString& file);
    explicit  FontFile(File* pFile);
              FontFile(File* pFile, const u32& offset, const u32& length);
              FontFile(u8* pBuffer, const u32& offset, const u32& length);
    virtual  ~FontFile(void);

    Surface*  GetSurface(void);
};



#endif
