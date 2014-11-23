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
#ifdef _MSC_VER
#pragma pack(push)
#pragma pack(1)
#endif
    struct wm_texture
    {
        unsigned int clutx:6;
        unsigned int cluty:10;
        unsigned int tx:4;
        unsigned int ty:1;
        unsigned int abr:2;
        unsigned int tp:2;
        unsigned int reserved:7;
#ifdef _MSC_VER
    };
#pragma pack(pop)
#else
        // Assume GCC
    } __attribute__((packed));
#endif

#ifdef _MSC_VER
#pragma pack(push)
#pragma pack(1)
#endif
    struct psx_pixel
    {
        uint16 r:5;
        uint16 g:5;
        uint16 b:5;
        uint16 trans:1;
#ifdef _MSC_VER
    };
#pragma pack(pop)
#else
        // Assume GCC
    } __attribute__((packed));
#endif
#ifdef _MSC_VER
#pragma pack(push)
#pragma pack(1)
#endif
    struct psx_pixel_4bit
    {
        uint8 index1:4;
        uint8 index2:4;
#ifdef _MSC_VER
    };
#pragma pack(pop)
#else
        // Assume GCC
    } __attribute__((packed));
#endif
#ifdef _MSC_VER
#pragma pack(push)
#pragma pack(1)
#endif
    struct rgba
    {
        unsigned char r = 0;
        unsigned char g = 0;
        unsigned char b = 0;
        unsigned char a = 0;
#ifdef _MSC_VER
    };
#pragma pack(pop)
#else
        // Assume GCC
    } __attribute__((packed));
#endif

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
    std::vector<std::vector<rgba>> GetWorldMapTexture(uint32 id);

private:
    std::vector<vram_block> mVramBlocks;

    void import_decompressed( Ogre::DataStream& stream, TxzFile& dest);
    void import_texture_section( Ogre::DataStream& stream, TxzFile& dest, size_t sectionEnd);
    void extract_texture(const std::array<wm_texture,512>& palTable);

    std::map<uint32, std::vector<std::vector<rgba>>> mTextures;
};

static_assert(sizeof(TxzFileSerializer::wm_texture)==4, "wm_texture is not packed");
static_assert(sizeof(TxzFileSerializer::psx_pixel)==2, "psx_pixel is not packed");

END_QGEARS

#endif // _TXZ_FILE_SERIALIZER_H_
