#ifndef _TXZ_FILE_SERIALIZER_H_
#define _TXZ_FILE_SERIALIZER_H_

#include "common/TypeDefine.h"
#include "data/QGearsSerializer.h"
#include <array>

BEGIN_QGEARS

class TxzFile;

class TxzFileSerializer : public Serializer
{
public:
    // All packed into a single 32bit number
    struct wm_texture
    {

        wm_texture(uint32 bits)
        {
            // TODO: Fix me this is very wrong..
            clutx = (bits >> 0) & 0xFC000000;
            cluty = (bits >> 6-1) & 0x3FF8000;
            tx = (bits >> 16-1) & 0x7800;
            ty = (bits >> 20-1) & 0x400;
            abr = (bits >> 21-1) & 0x300;
            tp = (bits >> 23-1) & 0xC0;
            reserved = (bits >>  25-1) & 0x7F;
        }

        // 0xFC000000 6 bits at index 0
        unsigned int clutx = 0;

        // 0x3FF8000 10 bits at index 6-1
        unsigned int cluty = 0;

        // 0x7800 4 bits at index 16-1
        unsigned int tx = 0;

        // 0x400 1 bit at index 20-1
        unsigned int ty = 0;

        // 0x300 2 bits at index 21-1
        unsigned int abr = 0;

        // 0xC0 2 bits at index 23-1
        unsigned int tp = 0;

        // 0x7F 7 bits at index 25-1
        unsigned int reserved = 0;
    };

    struct vram_block
    {
        uint32 mBlockSize = 0;
        uint16 mDstX = 0;
        uint16 mDstY = 0;
        uint16 mWidth = 0;
        uint16 mHeight = 0;
        // Data is w*h*2
        std::vector<uint8> mPixels;
    };


    TxzFileSerializer();
    virtual ~TxzFileSerializer();
    void import( Ogre::DataStreamPtr& stream, TxzFile& dest );
private:
    std::vector<vram_block> mVramBlocks;

    void import_decompressed( Ogre::DataStream& stream, TxzFile& dest);
    void import_texture_section( Ogre::DataStream& stream, TxzFile& dest, size_t sectionEnd);
};

END_QGEARS

#endif // _TXZ_FILE_SERIALIZER_H_
