// $Id: TimFile.h 103 2006-11-26 07:19:38Z crazy_otaku $

#ifndef FONT_FILE_h
#define FONT_FILE_h

#include "../../common/display/surface/Surface.h"
#include "../../common/utilites/StdString.h"

#include "image/Vram.h"
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
