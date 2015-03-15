#include "ModelFile.h"
#include "../../common/Logger.h"
#include "../../common/OgreGenUtilites.h"

#include <OgreStringConverter.h>



ModelFile::ModelFile( const Ogre::String& file ):
    File( file )
{
}



ModelFile::ModelFile( File *file, const u32 offset, const u32 length ):
    File( file, offset, length )
{
}



ModelFile::ModelFile( u8* buffer, const u32 offset, const u32 length ):
    File( buffer, offset, length )
{
}



ModelFile::ModelFile( File* file ):
    File( file )
{
}



ModelFile::~ModelFile()
{
}



void
ModelFile::GetModel( Ogre::MeshPtr mesh, const MeshData& data, VectorTexForGen& textures, Logger* export_text )
{
    m_ExportLog = export_text;

    int number_of_parts = GetU32LE( 0x0 );

    m_ExportLog->Log( "Model:\nnumber_of_parts: " + Ogre::StringConverter::toString( number_of_parts ) + "\n" );

    for( int part_id = 0; part_id < number_of_parts; ++part_id )
    {
        GetModelPart( part_id, mesh, data, textures, export_text, 0 );
    }
}



void
ModelFile::GetModelPart( const int part_id, Ogre::MeshPtr mesh, const MeshData& data, VectorTexForGen& textures, Logger* export_text, const int bone_id )
{
    int pointer_to_part_header = 0x10 + part_id * 0x38;
    int number_of_poly_blocks = GetU16LE( pointer_to_part_header + 0x6 );
    m_PointerToVertexData = GetU32LE( pointer_to_part_header + 0x08 );
    m_PointerToMeshData = GetU32LE( pointer_to_part_header + 0x10 );
    m_PointerToTextureData = GetU32LE( pointer_to_part_header + 0x14 );

    m_ExportLog->Log(
        "Part: " + Ogre::StringConverter::toString( part_id ) + "\n" +
        "    number of poly blocks: " + Ogre::StringConverter::toString( number_of_poly_blocks ) + "\n"
        "    pointer to polygon data: " + Ogre::StringConverter::toString( m_PointerToMeshData ) + "\n"
        "    pointer to texture data: " + Ogre::StringConverter::toString( m_PointerToTextureData ) + "\n"
    );

    for( int poly_block_id = 0; poly_block_id < number_of_poly_blocks; ++poly_block_id )
    {
        u8 polygon_type = GetU8(m_PointerToMeshData + 0);
        int number_of_polygons = GetU16LE(m_PointerToMeshData + 2);
        int number_of_triangles = number_of_polygons;
        if (polygon_type == 0x09 || polygon_type == 0x0c || polygon_type == 0x0d) // if quads
        {
            number_of_triangles *= 2;
        }

        m_PointerToMeshData += 4;

        m_ExportLog->Log(
            "        polygon type: " +
            Ogre::StringConverter::toString(polygon_type) +
            ", number of polygons: " +
            Ogre::StringConverter::toString(number_of_polygons) +
            "\n"
        );



        Ogre::SubMesh* sub_mesh = mesh->createSubMesh( Ogre::StringConverter::toString( part_id ) + "_" + Ogre::StringConverter::toString( poly_block_id ) );
        sub_mesh->setMaterialName( "xenogears/model/" + data.name );
        sub_mesh->useSharedVertices = false;
        sub_mesh->operationType = Ogre::RenderOperation::OT_TRIANGLE_LIST;

        // Allocate and prepare vertex data
        sub_mesh->vertexData = new Ogre::VertexData();
        sub_mesh->vertexData->vertexStart = 0;
        sub_mesh->vertexData->vertexCount = static_cast< size_t >( number_of_triangles * 3 );

        // Index buffer
        sub_mesh->indexData = new Ogre::IndexData();
        sub_mesh->indexData->indexStart = 0;
        sub_mesh->indexData->indexCount = sub_mesh->vertexData->vertexCount;
        sub_mesh->indexData->indexBuffer = Ogre::HardwareBufferManager::getSingleton().createIndexBuffer(Ogre::HardwareIndexBuffer::IT_16BIT, sub_mesh->indexData->indexCount, Ogre::HardwareBuffer::HBU_STATIC_WRITE_ONLY);
        u16* idata = static_cast<u16*>(sub_mesh->indexData->indexBuffer->lock(Ogre::HardwareBuffer::HBL_DISCARD));
        for( unsigned int i = 0; i < sub_mesh->vertexData->vertexCount; ++i )
        {
            idata[ i ] = i;
        }
        sub_mesh->indexData->indexBuffer->unlock();

        Ogre::VertexDeclaration* decl = sub_mesh->vertexData->vertexDeclaration;
        Ogre::VertexBufferBinding* bind = sub_mesh->vertexData->vertexBufferBinding;

        // 1st buffer (positions)
        decl->addElement(0, 0, Ogre::VET_FLOAT3, Ogre::VES_POSITION);
        Ogre::HardwareVertexBufferSharedPtr vbuf0 = Ogre::HardwareBufferManager::getSingleton().createVertexBuffer(decl->getVertexSize(0), sub_mesh->vertexData->vertexCount, Ogre::HardwareBuffer::HBU_STATIC_WRITE_ONLY);
        bind->setBinding(0, vbuf0);
        float* pPos = static_cast<float*>(vbuf0->lock(Ogre::HardwareBuffer::HBL_DISCARD));

        // 2nd buffer (colours)
        decl->addElement(1, 0, Ogre::VET_COLOUR, Ogre::VES_DIFFUSE);
        Ogre::HardwareVertexBufferSharedPtr vbuf1 = Ogre::HardwareBufferManager::getSingleton().createVertexBuffer(decl->getVertexSize(1), sub_mesh->vertexData->vertexCount, Ogre::HardwareBuffer::HBU_STATIC_WRITE_ONLY);
        bind->setBinding(1, vbuf1);
        Ogre::RGBA* cPos = static_cast<Ogre::RGBA*>(vbuf1->lock(Ogre::HardwareBuffer::HBL_DISCARD));

        // 3rd buffer (texture coords)
        decl->addElement(2, 0, Ogre::VET_FLOAT2, Ogre::VES_TEXTURE_COORDINATES, 0);
        Ogre::HardwareVertexBufferSharedPtr vbuf2 = Ogre::HardwareBufferManager::getSingleton().createVertexBuffer(decl->getVertexSize(2), sub_mesh->vertexData->vertexCount, Ogre::HardwareBuffer::HBU_STATIC_WRITE_ONLY);
        bind->setBinding(2, vbuf2);
        float* tPos = static_cast<float*>(vbuf2->lock(Ogre::HardwareBuffer::HBL_DISCARD));



        m_LightType = 0;



        for (int poly_id = 0; poly_id < number_of_polygons; ++poly_id)
        {
            // textured triangle
            if (polygon_type == 0x01 || polygon_type == 0x03 || polygon_type == 0x05)
            {
                if (LoadPoly010305_18(pPos, tPos, cPos, data, textures) != 0)
                {
                    m_PointerToMeshData += 8;
                    m_PointerToTextureData += 8;
                }
                else
                {
                    --poly_id;
                    m_PointerToTextureData += 4;
                }
            }
            // monochrome triangle
            else if (polygon_type == 0x04)
            {
                if (LoadPoly04_18(pPos, tPos, cPos, data, textures) != 0)
                {
                    m_PointerToMeshData += 8;
                    m_PointerToTextureData += 4;
                }
                else
                {
                    --poly_id;
                    m_PointerToTextureData += 4;
                }
            }
            // textured quad
            else if( polygon_type == 0x09 || polygon_type == 0x0d )
            {
                if( LoadPoly090d_18( pPos, tPos, cPos, data, textures ) != 0 )
                {
                    m_PointerToMeshData += 8;
                    m_PointerToTextureData += 12;
                }
                else
                {
                    --poly_id;
                    m_PointerToTextureData += 4;
                }
            }
            // monochrome quad
            else if( polygon_type == 0x0c )
            {
                if( LoadPoly0c_18( pPos, tPos, cPos, data, textures ) != 0 )
                {
                    m_PointerToMeshData += 8;
                    m_PointerToTextureData += 4;
                }
                else
                {
                    --poly_id;
                    m_PointerToTextureData += 4;
                }
            }
            else
            {
                m_ExportLog->Log( "ERROR: polygon type \"" + Ogre::StringConverter::toString(polygon_type) + "\" not implemented.\n" );
                break;
            }
        }

        vbuf0->unlock();
        vbuf1->unlock();
        vbuf2->unlock();

        // Optimize index data
        sub_mesh->indexData->optimiseVertexCacheTriList();



        LOGGER->Log( "Assign bones to vertexes\n" );

        int vertex_number = sub_mesh->vertexData->vertexCount;
        for( int i = 0; i < vertex_number; ++i )
        {
            Ogre::VertexBoneAssignment vba;
            vba.vertexIndex = i;
            vba.boneIndex = bone_id;
            vba.weight = 1.0f;
            sub_mesh->addBoneAssignment( vba );
        }
    }
}



int
ModelFile::LoadPoly010305_18( float*& pPos, float*& tPos, Ogre::RGBA*& cPos, const MeshData& info, VectorTexForGen& textures )
{

    if (TexSettings() == 0)
    {
        return 0;
    }

    int offset_a = GetU16LE(m_PointerToMeshData + 0x0);
    int offset_b = GetU16LE(m_PointerToMeshData + 0x2);
    int offset_c = GetU16LE(m_PointerToMeshData + 0x4);

    Ogre::Vector3 a((s16)GetU16LE(m_PointerToVertexData + offset_a * 0x8 + 00),
                    (s16)GetU16LE(m_PointerToVertexData + offset_a * 0x8 + 02),
                    (s16)GetU16LE(m_PointerToVertexData + offset_a * 0x8 + 04));
    Ogre::Vector3 b((s16)GetU16LE(m_PointerToVertexData + offset_b * 0x8 + 00),
                    (s16)GetU16LE(m_PointerToVertexData + offset_b * 0x8 + 02),
                    (s16)GetU16LE(m_PointerToVertexData + offset_b * 0x8 + 04));
    Ogre::Vector3 c((s16)GetU16LE(m_PointerToVertexData + offset_c * 0x8 + 00),
                    (s16)GetU16LE(m_PointerToVertexData + offset_c * 0x8 + 02),
                    (s16)GetU16LE(m_PointerToVertexData + offset_c * 0x8 + 04));
    a /= 512;
    b /= 512;
    c /= 512;

    //m_ExportLog->Log("        polygon: A (" + Ogre::StringConverter::toString(a) + "), B (" + Ogre::StringConverter::toString(b) + "), C (" + Ogre::StringConverter::toString(c) + ").\n");

    int clut_x = (m_CurrentClut & 0x3f) * 16;
    int clut_y = (m_CurrentClut >> 0x6) & 0x1ff;
    int bpp    = (m_CurrentTexPage >> 0x7) & 0x3;
    int vram_x = (m_CurrentTexPage & 0xf) * 64;
    int vram_y = ((m_CurrentTexPage & 0x10) >> 4) * 256;
    TexForGen texture;
    texture.palette_x = clut_x;
    texture.palette_y = clut_y;
    texture.texture_x = vram_x;
    texture.texture_y = vram_y;
    texture.bpp = ( BPP )bpp;
    AddTexture(texture, info, textures, m_ExportLog);

    Ogre::Vector2 at(0, 0);
    Ogre::Vector2 bt(0, 0);
    Ogre::Vector2 ct(0, 0);

    int x = GetU8(m_PointerToTextureData + 0x4) + texture.start_x;
    at.x = x / (float)info.tex_width;
    int y = GetU8(m_PointerToTextureData + 0x5) + texture.start_y;
    at.y = y / (float)info.tex_height;
    x = GetU8(m_PointerToTextureData + 0x6) + texture.start_x;
    bt.x = x / (float)info.tex_width;
    y = GetU8(m_PointerToTextureData + 0x7) + texture.start_y;
    bt.y = y / (float)info.tex_height;
    x = GetU8(m_PointerToTextureData + 0x0) + texture.start_x;
    ct.x = x / (float)info.tex_width;
    y = GetU8(m_PointerToTextureData + 0x1) + texture.start_y;
    ct.y = y / (float)info.tex_height;

    *pPos++ = a.x; *pPos++ = a.y; *pPos++ = a.z;
    *pPos++ = c.x; *pPos++ = c.y; *pPos++ = c.z;
    *pPos++ = b.x; *pPos++ = b.y; *pPos++ = b.z;

    *tPos++ = at.x; *tPos++ = at.y;
    *tPos++ = ct.x; *tPos++ = ct.y;
    *tPos++ = bt.x; *tPos++ = bt.y;

    Ogre::ColourValue colour = Ogre::ColourValue(1.0f, 1.0f, 1.0f, 1.0f);

    Ogre::RenderSystem* rs = Ogre::Root::getSingleton().getRenderSystem();
    Ogre::RGBA conv_colour;
    rs->convertColourValue(colour, &conv_colour); *cPos++ = conv_colour;
    rs->convertColourValue(colour, &conv_colour); *cPos++ = conv_colour;
    rs->convertColourValue(colour, &conv_colour); *cPos++ = conv_colour;

    return 1;
}



int
ModelFile::LoadPoly04_18(float*& pPos, float*& tPos, Ogre::RGBA*& cPos, const MeshData& info, VectorTexForGen& textures)
{
    int offset_a = GetU16LE(m_PointerToMeshData + 0x0);
    int offset_b = GetU16LE(m_PointerToMeshData + 0x2);
    int offset_c = GetU16LE(m_PointerToMeshData + 0x4);

    Ogre::Vector3 a((s16)GetU16LE(m_PointerToVertexData + offset_a * 0x8 + 00),
                    (s16)GetU16LE(m_PointerToVertexData + offset_a * 0x8 + 02),
                    (s16)GetU16LE(m_PointerToVertexData + offset_a * 0x8 + 04));
    Ogre::Vector3 b((s16)GetU16LE(m_PointerToVertexData + offset_b * 0x8 + 00),
                    (s16)GetU16LE(m_PointerToVertexData + offset_b * 0x8 + 02),
                    (s16)GetU16LE(m_PointerToVertexData + offset_b * 0x8 + 04));
    Ogre::Vector3 c((s16)GetU16LE(m_PointerToVertexData + offset_c * 0x8 + 00),
                    (s16)GetU16LE(m_PointerToVertexData + offset_c * 0x8 + 02),
                    (s16)GetU16LE(m_PointerToVertexData + offset_c * 0x8 + 04));
    a /= 512;
    b /= 512;
    c /= 512;

    //m_ExportLog->Log("        polygon: A (" + Ogre::StringConverter::toString(a) + "), B (" + Ogre::StringConverter::toString(b) + "), C (" + Ogre::StringConverter::toString(c) + ").\n");

    Ogre::Vector2 at(0, 0);
    Ogre::Vector2 bt(0, 0);
    Ogre::Vector2 ct(0, 0);

    *pPos++ = a.x; *pPos++ = a.y; *pPos++ = a.z;
    *pPos++ = c.x; *pPos++ = c.y; *pPos++ = c.z;
    *pPos++ = b.x; *pPos++ = b.y; *pPos++ = b.z;

    *tPos++ = at.x; *tPos++ = at.y;
    *tPos++ = ct.x; *tPos++ = ct.y;
    *tPos++ = bt.x; *tPos++ = bt.y;

    Ogre::ColourValue colour = Ogre::ColourValue(GetU8(m_PointerToTextureData + 0x0) / 255.0f, GetU8(m_PointerToTextureData + 0x1) / 255.0f, GetU8(m_PointerToTextureData + 0x2) / 255.0f, 1.0f);

    Ogre::RenderSystem* rs = Ogre::Root::getSingleton().getRenderSystem();
    Ogre::RGBA conv_colour;
    rs->convertColourValue(colour, &conv_colour); *cPos++ = conv_colour;
    rs->convertColourValue(colour, &conv_colour); *cPos++ = conv_colour;
    rs->convertColourValue(colour, &conv_colour); *cPos++ = conv_colour;

    return 1;
}



int
ModelFile::LoadPoly090d_18(float*& pPos, float*& tPos, Ogre::RGBA*& cPos, const MeshData& info, VectorTexForGen& textures)
{
    if (TexSettings() == 0)
    {
        return 0;
    }

    int offset_a = GetU16LE(m_PointerToMeshData + 0x0);
    int offset_b = GetU16LE(m_PointerToMeshData + 0x2);
    int offset_c = GetU16LE(m_PointerToMeshData + 0x4);
    int offset_d = GetU16LE(m_PointerToMeshData + 0x6);

    Ogre::Vector3 a((s16)GetU16LE(m_PointerToVertexData + offset_a * 0x8 + 00),
                    (s16)GetU16LE(m_PointerToVertexData + offset_a * 0x8 + 02),
                    (s16)GetU16LE(m_PointerToVertexData + offset_a * 0x8 + 04));
    Ogre::Vector3 b((s16)GetU16LE(m_PointerToVertexData + offset_b * 0x8 + 00),
                    (s16)GetU16LE(m_PointerToVertexData + offset_b * 0x8 + 02),
                    (s16)GetU16LE(m_PointerToVertexData + offset_b * 0x8 + 04));
    Ogre::Vector3 c((s16)GetU16LE(m_PointerToVertexData + offset_c * 0x8 + 00),
                    (s16)GetU16LE(m_PointerToVertexData + offset_c * 0x8 + 02),
                    (s16)GetU16LE(m_PointerToVertexData + offset_c * 0x8 + 04));
    Ogre::Vector3 d((s16)GetU16LE(m_PointerToVertexData + offset_d * 0x8 + 00),
                    (s16)GetU16LE(m_PointerToVertexData + offset_d * 0x8 + 02),
                    (s16)GetU16LE(m_PointerToVertexData + offset_d * 0x8 + 04));

    a /= 512;
    b /= 512;
    c /= 512;
    d /= 512;

    //m_ExportLog->Log("        polygon: A (" + Ogre::StringConverter::toString(a) + "), B (" + Ogre::StringConverter::toString(b) + "), C (" + Ogre::StringConverter::toString(c) + "), D (" + Ogre::StringConverter::toString(d) + ").\n");

    int clut_x = (m_CurrentClut & 0x3f) * 16;
    int clut_y = (m_CurrentClut >> 0x6) & 0x1ff;
    int bpp    = (m_CurrentTexPage >> 0x7) & 0x3;
    int vram_x = (m_CurrentTexPage & 0xf) * 64;
    int vram_y = ((m_CurrentTexPage & 0x10) >> 4) * 256;
    TexForGen texture;
    texture.palette_x = clut_x;
    texture.palette_y = clut_y;
    texture.texture_x = vram_x;
    texture.texture_y = vram_y;
    texture.bpp = ( BPP )bpp;
    AddTexture(texture, info, textures, m_ExportLog);

    Ogre::Vector2 at(0, 0);
    Ogre::Vector2 bt(0, 0);
    Ogre::Vector2 ct(0, 0);
    Ogre::Vector2 dt(0, 0);

    int x = GetU8(m_PointerToTextureData + 0x4) + texture.start_x;
    at.x = x / (float)info.tex_width;
    int y = GetU8(m_PointerToTextureData + 0x5) + texture.start_y;
    at.y = y / (float)info.tex_height;
    x = GetU8(m_PointerToTextureData + 0x6) + texture.start_x;
    bt.x = x / (float)info.tex_width;
    y = GetU8(m_PointerToTextureData + 0x7) + texture.start_y;
    bt.y = y / (float)info.tex_height;
    x = GetU8(m_PointerToTextureData + 0x8) + texture.start_x;
    ct.x = x / (float)info.tex_width;
    y = GetU8(m_PointerToTextureData + 0x9) + texture.start_y;
    ct.y = y / (float)info.tex_height;
    x = GetU8(m_PointerToTextureData + 0xa) + texture.start_x;
    dt.x = x / (float)info.tex_width;
    y = GetU8(m_PointerToTextureData + 0xb) + texture.start_y;
    dt.y = y / (float)info.tex_height;

    *pPos++ = a.x; *pPos++ = a.y; *pPos++ = a.z;
    *pPos++ = c.x; *pPos++ = c.y; *pPos++ = c.z;
    *pPos++ = b.x; *pPos++ = b.y; *pPos++ = b.z;
    *pPos++ = b.x; *pPos++ = b.y; *pPos++ = b.z;
    *pPos++ = c.x; *pPos++ = c.y; *pPos++ = c.z;
    *pPos++ = d.x; *pPos++ = d.y; *pPos++ = d.z;

    *tPos++ = at.x; *tPos++ = at.y;
    *tPos++ = ct.x; *tPos++ = ct.y;
    *tPos++ = bt.x; *tPos++ = bt.y;
    *tPos++ = bt.x; *tPos++ = bt.y;
    *tPos++ = ct.x; *tPos++ = ct.y;
    *tPos++ = dt.x; *tPos++ = dt.y;

    Ogre::ColourValue colour = Ogre::ColourValue(1.0f, 1.0f, 1.0f, 1.0f);

    Ogre::RenderSystem* rs = Ogre::Root::getSingleton().getRenderSystem();
    Ogre::RGBA conv_colour;
    rs->convertColourValue(colour, &conv_colour); *cPos++ = conv_colour;
    rs->convertColourValue(colour, &conv_colour); *cPos++ = conv_colour;
    rs->convertColourValue(colour, &conv_colour); *cPos++ = conv_colour;
    rs->convertColourValue(colour, &conv_colour); *cPos++ = conv_colour;
    rs->convertColourValue(colour, &conv_colour); *cPos++ = conv_colour;
    rs->convertColourValue(colour, &conv_colour); *cPos++ = conv_colour;

    return 1;
}



int
ModelFile::LoadPoly0c_18(float*& pPos, float*& tPos, Ogre::RGBA*& cPos, const MeshData& info, VectorTexForGen& textures)
{
    int offset_a = GetU16LE(m_PointerToMeshData + 0x0);
    int offset_b = GetU16LE(m_PointerToMeshData + 0x2);
    int offset_c = GetU16LE(m_PointerToMeshData + 0x4);
    int offset_d = GetU16LE(m_PointerToMeshData + 0x6);

    Ogre::Vector3 a((s16)GetU16LE(m_PointerToVertexData + offset_a * 0x8 + 00),
                    (s16)GetU16LE(m_PointerToVertexData + offset_a * 0x8 + 02),
                    (s16)GetU16LE(m_PointerToVertexData + offset_a * 0x8 + 04));
    Ogre::Vector3 b((s16)GetU16LE(m_PointerToVertexData + offset_b * 0x8 + 00),
                    (s16)GetU16LE(m_PointerToVertexData + offset_b * 0x8 + 02),
                    (s16)GetU16LE(m_PointerToVertexData + offset_b * 0x8 + 04));
    Ogre::Vector3 c((s16)GetU16LE(m_PointerToVertexData + offset_c * 0x8 + 00),
                    (s16)GetU16LE(m_PointerToVertexData + offset_c * 0x8 + 02),
                    (s16)GetU16LE(m_PointerToVertexData + offset_c * 0x8 + 04));
    Ogre::Vector3 d((s16)GetU16LE(m_PointerToVertexData + offset_d * 0x8 + 00),
                    (s16)GetU16LE(m_PointerToVertexData + offset_d * 0x8 + 02),
                    (s16)GetU16LE(m_PointerToVertexData + offset_d * 0x8 + 04));

    a /= 512;
    b /= 512;
    c /= 512;
    d /= 512;

    //m_ExportLog->Log("        polygon: A (" + Ogre::StringConverter::toString(a) + "), B (" + Ogre::StringConverter::toString(b) + "), C (" + Ogre::StringConverter::toString(c) + "), D (" + Ogre::StringConverter::toString(d) + ").\n");

    Ogre::Vector2 at(0, 0);
    Ogre::Vector2 bt(0, 0);
    Ogre::Vector2 ct(0, 0);
    Ogre::Vector2 dt(0, 0);

    *pPos++ = a.x; *pPos++ = a.y; *pPos++ = a.z;
    *pPos++ = c.x; *pPos++ = c.y; *pPos++ = c.z;
    *pPos++ = b.x; *pPos++ = b.y; *pPos++ = b.z;
    *pPos++ = b.x; *pPos++ = b.y; *pPos++ = b.z;
    *pPos++ = c.x; *pPos++ = c.y; *pPos++ = c.z;
    *pPos++ = d.x; *pPos++ = d.y; *pPos++ = d.z;

    *tPos++ = at.x; *tPos++ = at.y;
    *tPos++ = ct.x; *tPos++ = ct.y;
    *tPos++ = bt.x; *tPos++ = bt.y;
    *tPos++ = bt.x; *tPos++ = bt.y;
    *tPos++ = ct.x; *tPos++ = ct.y;
    *tPos++ = dt.x; *tPos++ = dt.y;

    Ogre::ColourValue colour = Ogre::ColourValue(GetU8(m_PointerToTextureData + 0x0) / 255.0f, GetU8(m_PointerToTextureData + 0x1) / 255.0f, GetU8(m_PointerToTextureData + 0x2) / 255.0f, 1.0f);

    Ogre::RenderSystem* rs = Ogre::Root::getSingleton().getRenderSystem();
    Ogre::RGBA conv_colour;
    rs->convertColourValue(colour, &conv_colour); *cPos++ = conv_colour;
    rs->convertColourValue(colour, &conv_colour); *cPos++ = conv_colour;
    rs->convertColourValue(colour, &conv_colour); *cPos++ = conv_colour;
    rs->convertColourValue(colour, &conv_colour); *cPos++ = conv_colour;
    rs->convertColourValue(colour, &conv_colour); *cPos++ = conv_colour;
    rs->convertColourValue(colour, &conv_colour); *cPos++ = conv_colour;

    return 1;
}



int
ModelFile::TexSettings()
{
    int tex_settings = GetU8(m_PointerToTextureData + 0x3);

    if (tex_settings == 0xc4)
    {
        SetTexPageSettings();
        return 0;
    }
    if (tex_settings == 0xc8)
    {
        SetClutSettings();
        return 0;
    }

    return 1;
}



void
ModelFile::SetTexPageSettings()
{
    //m_ExportLog->Log("    Tex page settings values 0x" + ToHexString(GetU16LE(m_PointerToTextureData), 4, '0') + ".\n");

    m_CurrentTexPage = GetU16LE(m_PointerToTextureData);

/*
    if (w[8004f7ac] == 1)
    {
        m_CurrentTexPage = h(w[800589b0] | (hu[[800589a8]] & ffe0));
    }
    else if (V1 == 2)
    {
        m_CurrentTexPage = h(w[800589b0]);
    }
*/
}



void
ModelFile::SetClutSettings()
{
    //m_ExportLog->Log("    Clut settings values 0x" + ToHexString(GetU16LE(m_PointerToTextureData), 4, '0') + ".\n");

    m_CurrentClut = GetU16LE(m_PointerToTextureData);

/*
    [800589ac] = h(hu[A0 + 0]);

    if (w[8004f7b0] == 0)
    {
        m_CurrentClut = h(w[800589b4] | (hu[[800589ac]] & 000f));
    }
*/
}
