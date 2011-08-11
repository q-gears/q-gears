#ifndef TDB_FILE_H
#define TDB_FILE_H

#include <Ogre.h>

#include "../../common/Surface.h"
#include "../../common/LzsFile.h"
#include "../../common/Vram.h"



class TdbFile : public LzsFile
{
public:
    explicit     TdbFile( const Ogre::String& file );
    explicit     TdbFile( File* pFile );
                 TdbFile( File* pFile, const u32 offset, const u32 length );
                 TdbFile( u8* pBuffer, const u32 offset, const u32 length );
    virtual     ~TdbFile();

    void         CreateTexture( const Ogre::PixelBox& pb, const int face_id, const int start_x, const int start_y );
};



#endif // TDB_FILE_h
