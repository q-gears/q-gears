#include "data/worldmap/MapFileSerializer.h"
#include "common/LzsFile.h"

BEGIN_QGEARS

const int kWorldMapBlockSize = 0xB800;

struct BlockHeader
{
    // Offset in this block of the compressed data
    uint32 mCompressedDataOffsets[16];

    // At the compressed data offset we have another uint32 which
    // is the size of the uncompressed data
};

struct BlockMeshHeader
{
    // Number of BlockTriangle's
    uint16 NumberOfTriangles;

    // Number of Vertex's and Normal's
    uint16 NumberOfVertices;
};

struct Vertex
{
    sint16 X, Y, Z;
    uint16 Unused; // fill to fit structure to 32bit boundry
};

struct Normal
{
    sint16 X, Y, Z;
    uint16 Unused; // fill to fit structure to 32bit boundry
};

struct BlockTriangle
{
    uint8 Vertex0Index;
    uint8 Vertex1Index;
    uint8 Vertex2Index;

    // Only 5 bits are valid
    uint8 WalkabilityInfo:5;

    // Only 3 bits are valid
    uint8 Unknown:3;
    uint8 uVertex0, vVertex0;
    uint8 uVertex1, vVertex1;
    uint8 uVertex2, vVertex2;

    // Only 9 bits are valid
    uint16 TextureInfo:9;

    // Only 7 bits are valid
    uint16 Location:7;
};

enum eTriangleWalkMapTypes
{
    // Most things can go here.
    eGrass = 0,

    // No landing here, but anything else goes.
    eForest = 1,

    // Chocobos and flying machines only.
    eMountain = 2,

    // Only gold chocobo and submarine can go here.
    eSeaDeepWater = 3,

    // Buggy, tiny bronco and water-capable chocobos.
    eRiverCrossing = 4,

    // Tiny bronco and chocobos.
    eRiver = 5,

    // Shallow water, same as above.
    eWater = 6,

    // Midgar zolom can only move in swamp areas.
    eSwamp = 7,

    // No landing.
    eDesert = 8,

    // Found around Midgar, Wutai and misc other. No landing.
    eWasteland = 9,

    // Leaves footprints, no landing.
    eSnow = 10,

    // Beach-like area where river and land meet.
    eRiverside = 11,

    // Sharp drop, usually where the player can be on either side.
    eCliff = 12,

    // Tiny bridge over the waterfall from Costa del Sol to Corel.
    eCorelBridge = 13,

    // Rickety rope bridges south of Wutai.
    eWutaiBridge = 14,

    // Doesn't seem to be used anywhere in the original data.
    eUnused1 = 15,

    // This is the tiny walkable part at the foot of a mountain.
    eHillSide = 16,

    // Where land and shallow water meets.
    eBeach = 17,

    // Only place where you can enter/exit the submarine.
    eSubmarinePen = 18,

    // The ground in cosmo canyon has this type, walkability seems to be the same as wasteland.
    eCanyon = 19,

    // The small path through the mountains connecting Costa del Sol and Corel.
    eMountainPass = 20,

    // Present around bridges, may have some special meaning.
    eUnknown1 = 21,

    // River type where the tiny bronco can't go.
    eWaterfall = 22,

    // Doesn't seem to be used anywhere in the original data.
    eUnused2 = 23,

    // Special desert type for the golden saucer.
    eGoldSaucerDesert = 24,

    // Walkability same as forest, used in southern parts of the map.
    eJungle = 25,

    // Special type of deep water, only used in one small spot next to HP-MP cave,
    // possibly related to the underwater map/submarine.
    eSea = 26,

    // Inside part of the crater, where you can land the highwind.
    eNorthernCave = 27,

    // Narrow strip of land surrounding the golden saucer desert. Probably related to the "quicksand" script.
    eGoldSaucerDesertBorder = 28,

    // Small area at both ends of every bridge. May have some special meaning.
    eBridgehead = 29,

    // Special type that can be set unwalkable from the script.
    eBackEntrance = 30,

    // oesn't seem to be used anywhere in the original data.
    eUnused3 = 31
};

MapFileSerializer::MapFileSerializer()
{

}

MapFileSerializer::~MapFileSerializer()
{

}

void MapFileSerializer::importMapFile( Ogre::DataStreamPtr& stream, WorldMapFile& dest )
{
    const auto fileSize = stream->size();
    const auto numBlocks = fileSize / kWorldMapBlockSize;

    for ( int j=0; j<numBlocks; j++ )
    {
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
            // Go to the offset
            stream->seek( basePos + header.mCompressedDataOffsets[i] );

            // Read the size of the compressed data
            uint32 compressedDataSize = 0;
            readUInt32( stream, compressedDataSize );

            // Go back to before the compressed data size
            stream->seek( basePos + header.mCompressedDataOffsets[i] );

            // Read the compressed data into a temp buffer
            std::vector<uint8> buffer( compressedDataSize + 4 );
            stream->read(buffer.data(), buffer.size());

            // Decompress the data
            auto decompressed = LzsBuffer::Decompress(buffer);

            BlockMeshHeader* h = reinterpret_cast<BlockMeshHeader*>(decompressed.data());

            std::cout << "block: " << j
                      << " from offset << " << header.mCompressedDataOffsets[i]
                      << " old size: " << buffer.size()
                      << " decompressed size is " << decompressed.size()
                      << " header is tris: " << h->NumberOfTriangles
                      << " verts " << h->NumberOfVertices
                      << std::endl;
        }
    }
}

END_QGEARS
