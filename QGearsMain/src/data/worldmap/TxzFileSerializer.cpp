#include "data/worldmap/TxzFileSerializer.h"
#include "common/LzsFile.h"
#include <iostream>
#include <sstream>

BEGIN_QGEARS

TxzFileSerializer::TxzFileSerializer()
{

}

TxzFileSerializer::~TxzFileSerializer()
{

}

void TxzFileSerializer::import( Ogre::DataStreamPtr& stream, TxzFile& dest )
{
    // Read uncompressed size and seek back to start
    uint32 uncompressedSize = 0;
    readUInt32( stream, uncompressedSize );
    stream->seek( 0 );

    // Read the compressed data into a temp buffer, including the compressed data size
    std::vector<uint8> compressedData( stream->size() );
    stream->read(compressedData.data(), compressedData.size());

    // Decompress the data and create a new stream for the decompressed buffer
    auto decompressedData = LzsBuffer::Decompress(compressedData);
    Ogre::MemoryDataStream decStream(decompressedData.data(), decompressedData.size(), false, true);
    import_decompressed(decStream, dest);
}

void TxzFileSerializer::import_decompressed( Ogre::DataStream& stream, TxzFile& dest)
{
    uint32 numberOfSections = 0;
    readUInt32(stream, numberOfSections);

    // All known files seem to have 12 sections
    std::vector<uint32> sectionOffsets(numberOfSections);
    for (auto& sectionOffset : sectionOffsets)
    {
        readUInt32(stream, sectionOffset);
    }

    std::cout << "Got " << sectionOffsets.size() << " blocks " << std::endl;

    // Section 2 is the world map textures
    if (sectionOffsets.size() >= 2 )
    {
        auto sectionPos = sectionOffsets[2]+4; // skip 4 to get the real start pos
        stream.seek( sectionPos );
        import_texture_section( stream, dest, sectionOffsets[3]);
    }
}

void TxzFileSerializer::import_texture_section( Ogre::DataStream& stream, TxzFile& dest, size_t sectionEnd)
{
    // Read the texture table
    std::array<wm_texture,512> textureTable = {};
    for (auto& tableEntry : textureTable)
    {
        readUInt32(stream, (uint32&)tableEntry);
    }


    // Read vram blocks until end of section, usually we have 3 blocks
    // block 1 is pallete data, block 2 is main world map textures and block 3
    // is special fx textures, mini and big map texture, sky and metor
    // plus some other block 2 alike textures.
    int c = 1;
    do
    {
        vram_block tmpBlock;
        readUInt32( stream, tmpBlock.mBlockSize );
        readUInt16( stream, tmpBlock.mDstX );
        readUInt16( stream, tmpBlock.mDstY );
        readUInt16( stream, tmpBlock.mWidth );
        readUInt16( stream, tmpBlock.mHeight );
        tmpBlock.mPixels.resize( tmpBlock.mWidth * tmpBlock.mHeight * 2 );

        stream.read( tmpBlock.mPixels.data(), tmpBlock.mPixels.size() );

        std::stringstream ss;
        ss << "raw_pixels" << c << ".raw";
        std::ofstream s(ss.str().c_str(), std::ios::binary);
        if (s.is_open())
        {
            s.write((const char*)tmpBlock.mPixels.data(), tmpBlock.mPixels.size());
        }
        s.close();

        c++;

        std::cout << "adding vram_block "
                  << " block size:" << tmpBlock.mBlockSize
                  << " x:" << tmpBlock.mDstX
                  << " y:" << tmpBlock.mDstY
                  << " width:" << tmpBlock.mWidth
                  <<  "height:" << tmpBlock.mHeight << std::endl;
        mVramBlocks.push_back(tmpBlock);
    }
    while ( stream.tell() < sectionEnd );

   // for ( size_t i=0; i<textureTable.size(); i++)
    {
        int i=19;
        extract_texture(textureTable[i]);
    }

    std::cout << "stream pos "
              << stream.tell() << " end of block pos "
              << sectionEnd << " got "
              << mVramBlocks.size()
              << " vram blocks " << std::endl;

}

static std::vector<std::vector<TxzFileSerializer::psx_pixel>> to2D16bit(const TxzFileSerializer::vram_block& block)
{
    std::vector<std::vector<TxzFileSerializer::psx_pixel>> r;

    r.resize( block.mHeight );
    for ( auto& col : r)
    {
        col.resize( block.mWidth );
    }

    uint16 const* pixelPtr = reinterpret_cast<uint16 const* >(block.mPixels.data());
    for ( auto y = 0; y<block.mHeight; y++ )
    {
        for ( auto x = 0; x<block.mWidth; x++ )
        {
            uint16& t = (uint16&)r[y][x];
            t = (*pixelPtr);
            pixelPtr++;
        }
    }
    return r;
}

static std::vector<std::vector<TxzFileSerializer::psx_pixel_4bit>> to2D8bit(const TxzFileSerializer::vram_block& block)
{
    std::vector<std::vector<TxzFileSerializer::psx_pixel_4bit>> r;

    r.resize( block.mHeight );
    for ( auto& col : r)
    {
        col.resize( block.mWidth*2 );
    }

    uint8 const* pixelPtr = block.mPixels.data();
    for ( auto y = 0; y<block.mHeight; y++ )
    {
        for ( auto x = 0; x<block.mWidth*2; x++ ) // should be x2??
        {
            uint8& t = (uint8&)r[y][x];
            t = (*pixelPtr);
            pixelPtr++;
        }
    }
    return r;
}

static uint8 To24Bit(uint8 v)
{
    float value = float(v);

    value = value * 255.0f;
    value = value / 31.0f;

    return uint8(value);
}

void TxzFileSerializer::extract_texture(const TxzFileSerializer::wm_texture& entry)
{
    const vram_block& pals = mVramBlocks[0];
    const vram_block& atlas1 = mVramBlocks[1];
    const vram_block& atlas2 = mVramBlocks[2];


    //std::vector<std::vector<uint16>> pixels2D;
    auto palPixels = to2D16bit(pals);

    std::cout << "clutX " << entry.clutx;
    std::cout << " clutY " << entry.cluty << " ";

    switch (entry.tp)
    {
    case 0x0:       // 4bit CLUT
        std::cout << "4 bit";
        break;

    case 0x1:       // 8bit CLUT
        std::cout << "8 bit";
        break;

    case 0x2:       // 15bit
        std::cout << "16 bit";
        break;
    }

    std::cout << " tx is " << (entry.tx * 64);


    switch(entry.ty)
    {
    case 0x0:
        std::cout << " ty on 0" << std::endl;
        break;

    case 0x1:
        std::cout << " ty on 256" << std::endl;
        break;
    }

    // TODO: Should clutX be * 16 to get real X?
    if (entry.tx*64 == 384 && entry.ty == 0)
    {
        std::cout << "texture id == 19 pal??" << std::endl;
    }

    // texture at 0,0 with w/h = 64 is id =19 pc tex = clf_l

    if ( entry.clutx !=0 || entry.cluty !=0 )
    {
        // We assume pal goes from Y = fixed to X=x+16
        psx_pixel pal[16] = {};
        for ( int i=0; i<16; i++)
        {
            pal[i] = palPixels[entry.cluty-pals.mDstY][entry.clutx-pals.mDstX+i];
           // pal[i] = palPixels[0][i]; // clutX 0 clutY 480 4 bit tx is 384 ty on 0
//            pal[i] = palPixels[0][i];
        }

        {

            int c = 0;
            std::stringstream ss;
            ss << "extracted_pal" << c << ".raw";
            std::ofstream s(ss.str().c_str(), std::ios::binary);
            if (s.is_open())
            {
                for (auto& e : pal)
                {

                    uint8 r = To24Bit(e.r);
                    uint8 g = To24Bit(e.g);
                    uint8 b = To24Bit(e.b);

                    //uint8 alpha = 0;
                    //s.write((const char*)&alpha, sizeof(uint8) );

                      s.write((const char*)&r, sizeof(uint8) );
                      s.write((const char*)&g, sizeof(uint8) );
                      s.write((const char*)&b, sizeof(uint8) );
                }
            }
            s.close();
        }

        // Now we've got the pallete get the main vram block in 8bit format and convert each pixel
        // to 16bit
        auto mainPixels = to2D8bit(atlas1);

        std::vector<std::vector<uint8>> texture;
        texture.resize(256);
        for (auto& col : texture)
        {
            col.resize(640*2);
        }

        for (int y=0; y<256; y++)
        {
            int realXPos = 0;
            for (int x=0; x<(640*2)/2; x++) // div2 as 4bits per index
            {
                // x = 0 to 32, for each one read of mainPixels we get 2 indexes
                texture[y][realXPos++] = mainPixels[y][x].index1;
                texture[y][realXPos++] = mainPixels[y][x].index2;
            }
        }

        std::vector<std::vector<rgba>> textureFinal;
        textureFinal.resize(256);
        for (auto& col : textureFinal)
        {
            col.resize(640*2);
        }
        for (int y=0; y<256; y++)
        {
            for (int x=0; x<640*2; x++)
            {
                psx_pixel palColour = pal[texture[y][x]];

                uint8 r = To24Bit(palColour.r);
                uint8 g = To24Bit(palColour.g);
                uint8 b = To24Bit(palColour.b);

                textureFinal[y][x].b = b;
                textureFinal[y][x].r = r;
                textureFinal[y][x].g = g;

                textureFinal[y][x].a = 0;
            }
        }


        int c = 0;
        std::stringstream ss;
        ss << "extracted_texture" << c << ".raw";
        std::ofstream s(ss.str().c_str(), std::ios::binary);
        if (s.is_open())
        {
            for (int y=0; y<256; y++)
            {

                for (int x=0; x<640*2; x++)
                {
                    //s.write((const char*)&texture[y][x], sizeof(uint8));

                    uint8 r = textureFinal[y][x].r;
                    uint8 g = textureFinal[y][x].g;
                    uint8 b = textureFinal[y][x].b;


                    s.write((const char*)&r, sizeof(uint8) );
                    s.write((const char*)&g, sizeof(uint8) );
                    s.write((const char*)&b, sizeof(uint8) );


                    //uint8 alpha = 0;
                    //s.write((const char*)&alpha, sizeof(uint8) );
                }


            }
        }
        s.close();
    }
    else
    {
        std::wcout << "empty entry" << std::endl;
    }

}

END_QGEARS
