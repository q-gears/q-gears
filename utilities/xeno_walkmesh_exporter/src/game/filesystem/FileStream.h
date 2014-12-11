// $Id$

#ifndef FILESTREAM_H
#define FILESTREAM_H

#include "../../common/TypeDefine.h"

template <typename F>
class FileStream : public NoCopy< FileStream<F> >
{
public:
  inline FileStream(F &f):
    mFile(f),
    mOffset(0)
  {}

public:
  inline u8 GetU8() { u8 i = mFile.GetU8(mOffset); ++mOffset; return i; }

  inline u16 GetU16LE() { u16 i = mFile.GetU16LE(mOffset); mOffset += 2; return i; }
  inline s16 GetS16LE() { s16 i = static_cast<s16>(mFile.GetU16LE(mOffset)); mOffset += 2; return i; }

  inline u32 GetU32LE() { u32 i = mFile.GetU32LE(mOffset); mOffset += 4; return i; }

protected:
  F &mFile;
  u32 mOffset;
};

#endif // !FILESTREAM_H
