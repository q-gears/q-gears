#include "data/worldmap/TxzFileSerializer.h"
#include "common/LzsFile.h"

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
    uint16 tmp = 0;
    readUInt16(stream, tmp);
}

END_QGEARS
