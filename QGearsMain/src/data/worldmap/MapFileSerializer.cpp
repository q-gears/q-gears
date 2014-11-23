#include "data/worldmap/MapFileSerializer.h"
#include "common/LzsFile.h"

BEGIN_QGEARS

const int kWorldMapBlockSize = 0xB800;


MapFileSerializer::MapFileSerializer()
{

}

MapFileSerializer::~MapFileSerializer()
{

}

void MapFileSerializer::importMapFile( Ogre::DataStreamPtr& stream, WorldMapFile& dest )
{
    const auto fileSize = stream->size();
    auto numBlocks = fileSize / kWorldMapBlockSize;

    for ( unsigned int j=0; j<numBlocks; j++ )
    {

        SBlock block;

        const size_t basePos = kWorldMapBlockSize*j;
        stream->seek( basePos );

        // Read the offset to compressed data in this block
        BlockHeader header = {};
        for ( auto i=0u; i<16; i++)
        {
            readUInt32( stream, header.mCompressedDataOffsets[i] );
        }

        for ( auto i=0u; i<16; i++)
        {
            SBlockPart blockPart;

            // Go to the offset
            stream->seek( basePos + header.mCompressedDataOffsets[i] );

            // Read the size of the compressed data
            uint32 compressedDataSize = 0;
            readUInt32( stream, compressedDataSize );

            // Go back to before the compressed data size
            stream->seek( basePos + header.mCompressedDataOffsets[i] );

            // Read the compressed data into a temp buffer, including the compressed data size
            std::vector<uint8> buffer( compressedDataSize + 4 );
            stream->read(buffer.data(), buffer.size());

            // Decompress the data
            auto decompressed = LzsBuffer::Decompress(buffer);

            Ogre::MemoryDataStream decStream(decompressed.data(), decompressed.size(), false, true);

            readUInt16(decStream, blockPart.mHeader.NumberOfTriangles);
            readUInt16(decStream, blockPart.mHeader.NumberOfVertices);

            /*
            std::cout << "block: " << j
                      << " from offset " << header.mCompressedDataOffsets[i]
                      << " old size: " << buffer.size()
                      << " decompressed size is " << decompressed.size()
                      << " header is tris: " <<  blockPart.mHeader.NumberOfTriangles
                      << " verts " << blockPart.mHeader.NumberOfVertices
                      << std::endl;*/


            blockPart.mTris.resize(blockPart.mHeader.NumberOfTriangles);
            for ( int k=0; k<blockPart.mHeader.NumberOfTriangles; k++)
            {
                BlockTriangle& s = blockPart.mTris[k];

                readUInt8( decStream, s.Vertex0Index );
                readUInt8( decStream, s.Vertex1Index );
                readUInt8( decStream, s.Vertex2Index );

                readUInt8( decStream, s.WalkabilityInfo );
                //readUInt8( decStream, s.Unknown );

                readUInt8( decStream, s.uVertex0 );
                readUInt8( decStream, s.vVertex0 );

                readUInt8( decStream, s.uVertex1 );
                readUInt8( decStream, s.vVertex1 );

                readUInt8( decStream, s.uVertex2 );
                readUInt8( decStream, s.vVertex2 );

                readUInt16( decStream, s.TextureInfo );

                s.TextureInfo = s.TextureInfo & 0x1FF;

                //readUInt16( decStream, s.Location );

                /*
                std::cout << "v0: " << int(s.Vertex0Index)
                          << " v1 " << int(s.Vertex1Index)
                          << " v2 " << int(s.Vertex2Index)
                          << " walk " << int(s.WalkabilityInfo)
                          << " u1 " << int(s.uVertex1)
                          << " v1 " << int(s.vVertex1)
                          << " v2 " << int(s.uVertex2)
                          << " u2 " << int(s.vVertex2)
                          << " texture " << s.TextureInfo
                          << " locId " << s.Location
                          << std::endl;*/

            }

            blockPart.mNormal.resize( blockPart.mHeader.NumberOfVertices );
            blockPart.mVertices.resize( blockPart.mHeader.NumberOfVertices );

            // All verts
            for ( int k=0; k<blockPart.mHeader.NumberOfVertices; k++)
            {
                Vertex& v = blockPart.mVertices[k];
                readInt16( decStream, v.X );
                readInt16( decStream, v.Y );
                readInt16( decStream, v.Z );
                readUInt16( decStream, v.Unused );
            }

            // Then all normals
            for ( int k=0; k<blockPart.mHeader.NumberOfVertices; k++)
            {
                Normal& n = blockPart.mNormal[k];
                readInt16( decStream, n.X );
                readInt16( decStream, n.Y );
                readInt16( decStream, n.Z );
                readUInt16( decStream, n.Unused );
            }

            block.mMeshes.push_back( blockPart );
        }
        mBlocks.push_back(block);
    }
}

END_QGEARS
