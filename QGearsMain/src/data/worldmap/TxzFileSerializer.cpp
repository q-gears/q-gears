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
    std::array<uint32,512> textureTable = {};
    for (auto& tableEntry : textureTable)
    {
        readUInt32(stream, tableEntry);
    }

    std::vector<wm_texture> table;
    for (auto tableEntry : textureTable)
    {
        wm_texture tmp(tableEntry);
        table.push_back(tmp);
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
                  << " width:" << tmpBlock.mWidth*2
                  <<  "height:" << tmpBlock.mHeight*2 << std::endl;
        mVramBlocks.push_back(tmpBlock);
    }
    while ( stream.tell() < sectionEnd );

    std::cout << "stream pos "
              << stream.tell() << " end of block pos "
              << sectionEnd << " got "
              << mVramBlocks.size()
              << " vram blocks " << std::endl;

}

END_QGEARS
