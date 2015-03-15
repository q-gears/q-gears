#include "MeshFile.h"

#include "common/Logger.h"
#include "common/OgreBase.h"

float tex_width  = 512.0f;
float tex_height = 256.0f;


//---------------------------------------------------------------------
MeshFile::MeshFile(const Ogre::String& file):
    File(file)
{
}

//---------------------------------------------------------------------
MeshFile::MeshFile(File* pFile):
    File(pFile)
{
}

//---------------------------------------------------------------------
MeshFile::MeshFile(File* pFile, const u32 offset, const u32 length):
    File(pFile, offset, length)
{
}

//---------------------------------------------------------------------
MeshFile::MeshFile(u8* pBuffer, const u32 offset, const u32 length):
    File(pBuffer, offset, length)
{
}

//---------------------------------------------------------------------
MeshFile::~MeshFile(void)
{
}

//---------------------------------------------------------------------
Ogre::ColourValue
MeshFile::readColor( const u32 offset )
{
    u8 r( GetU8( offset + 0 ) )
      ,g( GetU8( offset + 1 ) )
      ,b( GetU8( offset + 2 ) )
      ,a( GetU8( offset + 3 ) );

    return Ogre::ColourValue( r / 255.0f, g / 255.0f, b / 255.0f, a / 255.0f );
}

//---------------------------------------------------------------------
void
MeshFile::readQuad( const u32 offset_to_poly, std::vector<Ogre::Vector3>& vertexes, float* &pPos, u16* &index, u32 &cur_vertex, Ogre::RGBA* &cur_colour, bool multi_color )
{
    u8 i1( GetU8( offset_to_poly + 0x00 ) )
      ,i2( GetU8( offset_to_poly + 0x01 ) )
      ,i3( GetU8( offset_to_poly + 0x02 ) )
      ,i4( GetU8( offset_to_poly + 0x03 ) );

    // set vertexes
    Ogre::Vector3 a( vertexes[ i1 ] );
    Ogre::Vector3 b( vertexes[ i2 ] );
    Ogre::Vector3 c( vertexes[ i3 ] );
    Ogre::Vector3 d( vertexes[ i4 ] );
    *pPos++ = a.x; *pPos++ = a.y; *pPos++ = a.z;
    *pPos++ = b.x; *pPos++ = b.y; *pPos++ = b.z;
    *pPos++ = c.x; *pPos++ = c.y; *pPos++ = c.z;
    *pPos++ = d.x; *pPos++ = d.y; *pPos++ = d.z;

    Ogre::ColourValue col_a = readColor( offset_to_poly + 0x04);
    Ogre::ColourValue col_b = col_a;
    Ogre::ColourValue col_c = col_a;
    Ogre::ColourValue col_d = col_a;
    if( multi_color ){
        col_b = readColor( offset_to_poly + 0x08 );
        col_c = readColor( offset_to_poly + 0x0c );
        col_d = readColor( offset_to_poly + 0x10 );
    };

    Ogre::RenderSystem* rs = Ogre::Root::getSingleton().getRenderSystem();
    rs->convertColourValue( col_a, cur_colour++ );
    rs->convertColourValue( col_b, cur_colour++ );
    rs->convertColourValue( col_c, cur_colour++ );
    rs->convertColourValue( col_d, cur_colour++ );

    *(index++) = cur_vertex + 0;
    *(index++) = cur_vertex + 2;
    *(index++) = cur_vertex + 3;
    *(index++) = cur_vertex + 3;
    *(index++) = cur_vertex + 1;
    *(index++) = cur_vertex + 0;

    cur_vertex += 4;
}

//---------------------------------------------------------------------
void
MeshFile::readTriangle( const u32 offset_to_poly, std::vector<Ogre::Vector3>& vertexes, float* &pPos, u16* &index, u32 &cur_vertex, Ogre::RGBA* &cur_colour, bool multi_color )
{
    u8 i1( GetU8( offset_to_poly + 0x00 ) )
      ,i2( GetU8( offset_to_poly + 0x01 ) )
      ,i3( GetU8( offset_to_poly + 0x02 ) );
    // set vertexes
    Ogre::Vector3 a = vertexes[ i1 ];
    Ogre::Vector3 b = vertexes[ i2 ];
    Ogre::Vector3 c = vertexes[ i3 ];
    *pPos++ = a.x; *pPos++ = a.y; *pPos++ = a.z;
    *pPos++ = b.x; *pPos++ = b.y; *pPos++ = b.z;
    *pPos++ = c.x; *pPos++ = c.y; *pPos++ = c.z;

    Ogre::ColourValue col_a = readColor( offset_to_poly + 0x04 );
    Ogre::ColourValue col_b = col_a;
    Ogre::ColourValue col_c = col_a;
    if( multi_color ){
        col_b = readColor( offset_to_poly + 0x08);
        col_c = readColor( offset_to_poly + 0x0c);
    };

    Ogre::RenderSystem* rs = Ogre::Root::getSingleton().getRenderSystem();
    rs->convertColourValue( col_a, cur_colour++ );
    rs->convertColourValue( col_b, cur_colour++ );
    rs->convertColourValue( col_c, cur_colour++ );
    *(index++) = cur_vertex + 2;
    *(index++) = cur_vertex + 1;
    *(index++) = cur_vertex + 0;

    cur_vertex += 3;
}

//---------------------------------------------------------------------
void
MeshFile::readPart( const Ogre::String& name, const u32 i, const u32 offset_to_part, Ogre::MeshPtr mesh, VectorTexForGenBsx& textures )
{
    Ogre::String material_name( "ffvii/model/field/" + name );
    // add vertexes to array
    u8  number_of_vertex   = GetU8(offset_to_part + 0x02);
    u16 offset_to_vertexes = GetU16LE(offset_to_part + 0x18);
    //LOGGER->Log(LOGGER_INFO, "number_of_vertex:    %02x", number_of_vertex);
    std::vector<Ogre::Vector3> vertexes;
    for (u32 j = 0; j < number_of_vertex; ++j)
    {
        u16 offset_to_vertex = offset_to_vertexes + j * 0x08;

        Ogre::Vector3 point;
        point.x = static_cast<float>(-( s16 )GetU16LE( offset_to_vertex + 4 + 0x00 ));
        point.z = static_cast<float>(-(s16)GetU16LE(offset_to_vertex + 4 + 0x02));
        point.y = static_cast<float>(-(s16)GetU16LE(offset_to_vertex + 4 + 0x04));
        point /= 1024.0f;
        vertexes.push_back( point );
    }

    u8 number_of_quad_t      = GetU8(offset_to_part + 0x04);
    u8 number_of_triangle_t  = GetU8(offset_to_part + 0x05);
    u8 number_of_quad_t2     = GetU8(offset_to_part + 0x06);
    u8 number_of_triangle_t2 = GetU8(offset_to_part + 0x07);
    u8 number_of_triangle_m  = GetU8(offset_to_part + 0x08);
    u8 number_of_quad_m      = GetU8(offset_to_part + 0x09);
    u8 number_of_triangle    = GetU8(offset_to_part + 0x0A);
    u8 number_of_quads       = GetU8(offset_to_part + 0x0B);

    size_t quad_count( number_of_quad_t
                     + number_of_quad_t2
                     + number_of_quad_m
                     + number_of_quads );

    size_t triangle_count( number_of_triangle_t
                         + number_of_triangle_t2
                         + number_of_triangle_m
                         + number_of_triangle );

    Ogre::SubMesh* sub_mesh = mesh->createSubMesh(Ogre::StringConverter::toString(i));
    sub_mesh->setMaterialName( material_name );
    sub_mesh->useSharedVertices = false;
    sub_mesh->operationType = Ogre::RenderOperation::OT_TRIANGLE_LIST;

    Ogre::HardwareBufferManager& buffer_manager( Ogre::HardwareBufferManager::getSingleton() );
    // Allocate and prepare vertex data
    sub_mesh->vertexData = new Ogre::VertexData();
    sub_mesh->vertexData->vertexStart = 0;
    sub_mesh->vertexData->vertexCount = triangle_count * 3 + quad_count * 4;
    sub_mesh->indexData = new Ogre::IndexData();
    sub_mesh->indexData->indexStart = 0;
    sub_mesh->indexData->indexCount = triangle_count * 3 + quad_count * 6;
    sub_mesh->indexData->indexBuffer = buffer_manager.createIndexBuffer(
        Ogre::HardwareIndexBuffer::IT_16BIT,
        sub_mesh->indexData->indexCount,
        Ogre::HardwareBuffer::HBU_STATIC_WRITE_ONLY);
    u16* cur_index = static_cast< u16* >(sub_mesh->indexData->indexBuffer->lock(Ogre::HardwareBuffer::HBL_DISCARD));
    u32 cur_vertex = 0;

    Ogre::VertexDeclaration* decl = sub_mesh->vertexData->vertexDeclaration;
    Ogre::VertexBufferBinding* bind = sub_mesh->vertexData->vertexBufferBinding;
    // position buffer
    decl->addElement(POSITION_BINDING, 0, Ogre::VET_FLOAT3, Ogre::VES_POSITION);
    Ogre::HardwareVertexBufferSharedPtr vbuf0 = buffer_manager.createVertexBuffer(
            decl->getVertexSize(POSITION_BINDING),
            sub_mesh->vertexData->vertexCount,
            Ogre::HardwareBuffer::HBU_STATIC_WRITE_ONLY);
    bind->setBinding(POSITION_BINDING, vbuf0);

    // vertex color buffer
    decl->addElement(COLOUR_BINDING, 0, Ogre::VET_COLOUR, Ogre::VES_DIFFUSE);
    Ogre::HardwareVertexBufferSharedPtr vbuf1 = buffer_manager.createVertexBuffer(
            decl->getVertexSize(COLOUR_BINDING),
            sub_mesh->vertexData->vertexCount,
            Ogre::HardwareBuffer::HBU_STATIC_WRITE_ONLY);
    // Set vertex buffer binding so buffer 1 is bound to our colour buffer
    bind->setBinding(COLOUR_BINDING, vbuf1);

    // texture coordinate buffer
    decl->addElement(TEXTURE_BINDING, 0, Ogre::VET_FLOAT2, Ogre::VES_TEXTURE_COORDINATES, 0);
    Ogre::HardwareVertexBufferSharedPtr vbuf2 = buffer_manager.createVertexBuffer(
            decl->getVertexSize(TEXTURE_BINDING),
            sub_mesh->vertexData->vertexCount,
            Ogre::HardwareBuffer::HBU_STATIC_WRITE_ONLY);
    bind->setBinding(TEXTURE_BINDING, vbuf2);

    float* pPos   = static_cast<float*>(vbuf0->lock(Ogre::HardwareBuffer::HBL_DISCARD));
    float* tPos   = static_cast<float*>(vbuf2->lock(Ogre::HardwareBuffer::HBL_DISCARD));

    Ogre::RenderSystem* rs = Ogre::Root::getSingleton().getRenderSystem();
    
    std::vector<Ogre::RGBA> coloursVec(sub_mesh->vertexData->vertexCount);
    Ogre::RGBA* colours = coloursVec.data();

    Ogre::RGBA* cur_colour( colours );




    u32 offset_to_poly           = offset_to_vertexes + GetU16LE( offset_to_part + 0x0E );
    u32 offset_to_texture_coords = offset_to_vertexes + GetU16LE( offset_to_part + 0x10 );
    offset_to_4                  = offset_to_vertexes + GetU16LE( offset_to_part + 0x12 );
    offset_to_5                  = offset_to_vertexes + GetU16LE( offset_to_part + 0x14 );

    // add textured quad
    for( u32 j = 0; j < number_of_quad_t; ++j )
    {
        readQuad( offset_to_poly, vertexes, pPos, cur_index, cur_vertex, cur_colour, true );
        TexForGenBsx texture;
        AddTexture( texture, textures );

        Ogre::Vector2 at;
        Ogre::Vector2 bt;
        Ogre::Vector2 ct;
        Ogre::Vector2 dt;

        u8 texture_coords_id = GetU8( offset_to_poly + 0x14 );
        int x = GetU8( offset_to_texture_coords + texture_coords_id * 0x02 + 0x00 ) + texture.start_x;
        at.x = x / tex_width;
        int y = GetU8( offset_to_texture_coords + texture_coords_id * 0x02 + 0x01 ) + texture.start_y;
        at.y = y / tex_height;

        texture_coords_id = GetU8( offset_to_poly + 0x15 );
        x = GetU8( offset_to_texture_coords + texture_coords_id * 0x02 + 0x00 ) + texture.start_x;
        bt.x = x / tex_width;
        y = GetU8( offset_to_texture_coords + texture_coords_id * 0x02 + 0x01 ) + texture.start_y;
        bt.y = y / tex_height;

        texture_coords_id = GetU8(offset_to_poly + 0x16);
        x = GetU8(offset_to_texture_coords + texture_coords_id * 0x02 + 0x00) + texture.start_x;
        ct.x = x / tex_width;
        y = GetU8(offset_to_texture_coords + texture_coords_id * 0x02 + 0x01) + texture.start_y;
        ct.y = y / tex_height;

        texture_coords_id = GetU8(offset_to_poly + 0x17);
        x = GetU8(offset_to_texture_coords + texture_coords_id * 0x02 + 0x00) + texture.start_x;
        dt.x = x / tex_width;
        y = GetU8(offset_to_texture_coords + texture_coords_id * 0x02 + 0x01) + texture.start_y;
        dt.y = y / tex_height;


        *tPos++ = at.x; *tPos++ = at.y;
        *tPos++ = bt.x; *tPos++ = bt.y;
        *tPos++ = ct.x; *tPos++ = ct.y;
        *tPos++ = dt.x; *tPos++ = dt.y;

        offset_to_poly += 0x18;
    }

    // add textured triangle
    for (u32 j = 0; j < number_of_triangle_t; ++j)
    {
        readTriangle( offset_to_poly, vertexes, pPos, cur_index, cur_vertex, cur_colour, true );

        TexForGenBsx texture;
        AddTexture( texture, textures );

        Ogre::Vector2 at;
        Ogre::Vector2 bt;
        Ogre::Vector2 ct;

        u8 texture_coords_id = GetU8(offset_to_poly + 0x10);
        int x = GetU8(offset_to_texture_coords + texture_coords_id * 0x02 + 0x00) + texture.start_x;
        at.x = x / tex_width;
        int y = GetU8(offset_to_texture_coords + texture_coords_id * 0x02 + 0x01) + texture.start_y;
        at.y = y / tex_height;

        texture_coords_id = GetU8(offset_to_poly + 0x11);
        x = GetU8(offset_to_texture_coords + texture_coords_id * 0x02 + 0x00) + texture.start_x;
        bt.x = x / tex_width;
        y = GetU8(offset_to_texture_coords + texture_coords_id * 0x02 + 0x01) + texture.start_y;
        bt.y = y / tex_height;

        texture_coords_id = GetU8(offset_to_poly + 0x12);
        x = GetU8(offset_to_texture_coords + texture_coords_id * 0x02 + 0x00) + texture.start_x;
        ct.x = x / tex_width;
        y = GetU8(offset_to_texture_coords + texture_coords_id * 0x02 + 0x01) + texture.start_y;
        ct.y = y / tex_height;

        *tPos++ = at.x; *tPos++ = at.y;
        *tPos++ = bt.x; *tPos++ = bt.y;
        *tPos++ = ct.x; *tPos++ = ct.y;

        offset_to_poly += 0x14;
    }

    // add textured monochrome quad
    for (u32 j = 0; j < number_of_quad_t2; ++j)
    {
        readQuad( offset_to_poly, vertexes, pPos, cur_index, cur_vertex, cur_colour, false );

        TexForGenBsx texture;
        AddTexture( texture, textures );

        Ogre::Vector2 at;
        Ogre::Vector2 bt;
        Ogre::Vector2 ct;
        Ogre::Vector2 dt;

        u8 texture_coords_id = GetU8(offset_to_poly + 0x8);
        int x = GetU8(offset_to_texture_coords + texture_coords_id * 0x02 + 0x00) + texture.start_x;
        at.x = x / tex_width;
        int y = GetU8(offset_to_texture_coords + texture_coords_id * 0x02 + 0x01) + texture.start_y;
        at.y = y / tex_height;

        texture_coords_id = GetU8(offset_to_poly + 0x9);
        x = GetU8(offset_to_texture_coords + texture_coords_id * 0x02 + 0x00) + texture.start_x;
        bt.x = x / tex_width;
        y = GetU8(offset_to_texture_coords + texture_coords_id * 0x02 + 0x01) + texture.start_y;
        bt.y = y / tex_height;

        texture_coords_id = GetU8(offset_to_poly + 0xa);
        x = GetU8(offset_to_texture_coords + texture_coords_id * 0x02 + 0x00) + texture.start_x;
        dt.x = x / tex_width;
        y = GetU8(offset_to_texture_coords + texture_coords_id * 0x02 + 0x01) + texture.start_y;
        dt.y = y / tex_height;

        texture_coords_id = GetU8(offset_to_poly + 0xb);
        x = GetU8(offset_to_texture_coords + texture_coords_id * 0x02 + 0x00) + texture.start_x;
        ct.x = x / tex_width;
        y = GetU8(offset_to_texture_coords + texture_coords_id * 0x02 + 0x01) + texture.start_y;
        ct.y = y / tex_height;

        *tPos++ = at.x; *tPos++ = at.y;
        *tPos++ = bt.x; *tPos++ = bt.y;
        *tPos++ = ct.x; *tPos++ = ct.y;
        *tPos++ = dt.x; *tPos++ = dt.y;

        offset_to_poly += 0x0C;
    }

    // add textured monochrome triangle
    for (u32 j = 0; j < number_of_triangle_t2; ++j)
    {
        readTriangle( offset_to_poly, vertexes, pPos, cur_index, cur_vertex, cur_colour, false );

        TexForGenBsx texture;
        AddTexture( texture, textures );

        Ogre::Vector2 at;
        Ogre::Vector2 bt;
        Ogre::Vector2 ct;

        u8 texture_coords_id = GetU8(offset_to_poly + 0x8);
        int x = GetU8(offset_to_texture_coords + texture_coords_id * 0x02 + 0x00) + texture.start_x;
        at.x = x / tex_width;
        int y = GetU8(offset_to_texture_coords + texture_coords_id * 0x02 + 0x01) + texture.start_y;
        at.y = y / tex_height;

        texture_coords_id = GetU8(offset_to_poly + 0x9);
        x = GetU8(offset_to_texture_coords + texture_coords_id * 0x02 + 0x00) + texture.start_x;
        bt.x = x / tex_width;
        y = GetU8(offset_to_texture_coords + texture_coords_id * 0x02 + 0x01) + texture.start_y;
        bt.y = y / tex_height;

        texture_coords_id = GetU8(offset_to_poly + 0xa);
        x = GetU8(offset_to_texture_coords + texture_coords_id * 0x02 + 0x00) + texture.start_x;
        ct.x = x / tex_width;
        y = GetU8(offset_to_texture_coords + texture_coords_id * 0x02 + 0x01) + texture.start_y;
        ct.y = y / tex_height;

        *tPos++ = at.x; *tPos++ = at.y;
        *tPos++ = bt.x; *tPos++ = bt.y;
        *tPos++ = ct.x; *tPos++ = ct.y;

        offset_to_poly += 0x0C;
    }

    // add monochrome triangle
    for (u32 j = 0; j < number_of_triangle_m; ++j)
    {
        readTriangle( offset_to_poly, vertexes, pPos, cur_index, cur_vertex, cur_colour, false );

        Ogre::Vector2 at(0.99f, 0.99f);
        Ogre::Vector2 bt(0.99f, 0.99f);
        Ogre::Vector2 ct(0.99f, 0.99f);
        *tPos++ = at.x; *tPos++ = at.y;
        *tPos++ = bt.x; *tPos++ = bt.y;
        *tPos++ = ct.x; *tPos++ = ct.y;

        offset_to_poly += 0x08;
    }

    // add monochrome quad
    for (u32 j = 0; j < number_of_quad_m; ++j)
    {
        readQuad( offset_to_poly, vertexes, pPos, cur_index, cur_vertex, cur_colour, false );

        Ogre::Vector2 at(0.99f, 0.99f);
        Ogre::Vector2 bt(0.99f, 0.99f);
        Ogre::Vector2 ct(0.99f, 0.99f);
        Ogre::Vector2 dt(0.99f, 0.99f);
        *tPos++ = at.x; *tPos++ = at.y;
        *tPos++ = bt.x; *tPos++ = bt.y;
        *tPos++ = ct.x; *tPos++ = ct.y;
        *tPos++ = dt.x; *tPos++ = dt.y;

        offset_to_poly += 0x08;
    }

    // add color triangle
    for (u32 j = 0; j < number_of_triangle; ++j)
    {
        readTriangle( offset_to_poly, vertexes, pPos, cur_index, cur_vertex, cur_colour, true );

        Ogre::Vector2 at(0.99f, 0.99f);
        Ogre::Vector2 bt(0.99f, 0.99f);
        Ogre::Vector2 ct(0.99f, 0.99f);
        *tPos++ = at.x; *tPos++ = at.y;
        *tPos++ = bt.x; *tPos++ = bt.y;
        *tPos++ = ct.x; *tPos++ = ct.y;

        offset_to_poly += 0x10;
    }

    // add color quad
    for (u32 j = 0; j < number_of_quads; ++j)
    {
        readQuad( offset_to_poly, vertexes, pPos, cur_index, cur_vertex, cur_colour, true );

        Ogre::Vector2 a(0.99f, 0.99f);
        Ogre::Vector2 b(0.99f, 0.99f);
        Ogre::Vector2 c(0.99f, 0.99f);
        Ogre::Vector2 d(0.99f, 0.99f);
        *tPos++ = a.x; *tPos++ = a.y;
        *tPos++ = b.x; *tPos++ = b.y;
        *tPos++ = c.x; *tPos++ = c.y;
        *tPos++ = d.x; *tPos++ = d.y;

        offset_to_poly += 0x14;
    }

    vbuf0->unlock();
    vbuf1->writeData(0, vbuf1->getSizeInBytes(), colours, true);
    vbuf2->unlock();

    sub_mesh->indexData->indexBuffer->unlock();
    // Optimize index data
    sub_mesh->indexData->optimiseVertexCacheTriList();

    int vertex_number = sub_mesh->vertexData->vertexCount;
    u8 bone_index( GetU8(offset_to_part + 0x01) );
    //LOGGER->Log(LOGGER_INFO, "vertex_number %08x", vertex_number);
    for (int i = 0; i < vertex_number; ++i)
    {
        Ogre::VertexBoneAssignment vba;
        vba.vertexIndex = i;
        vba.boneIndex = bone_index * 2 + 2;
        vba.weight = 1.0f;
        sub_mesh->addBoneAssignment(vba);
    }
}

//---------------------------------------------------------------------
void
MeshFile::GetData(const Ogre::String& name, const int offset_to_parts, const int number_of_parts, Ogre::MeshPtr mesh, VectorTexForGenBsx& textures)
{
    int part_end( number_of_parts );
    int part_begin = 0;

    for (int i = part_begin; i < number_of_parts && i < part_end; ++i)
    {
        u32 offset_to_part   = offset_to_parts + i * 0x20;
        readPart( name, i, offset_to_part, mesh, textures );
    }
}

//---------------------------------------------------------------------
void
MeshFile::AddTexture( TexForGenBsx& texture, VectorTexForGenBsx& textures )
{
    u8 control = GetU8(offset_to_5);
    //LOGGER->Log(LOGGER_INFO, "quad control: %02x", control);
    ++offset_to_5;

    u8 blend = ( control >> 4 ) & 0x3;
    u8 flag_id = control & 0xf;
    u32 flag = GetU32LE( offset_to_4 + flag_id * 4 );
    int type = flag & 0x3f;
    int bpp = (flag >> 0x6) & 0x3;
    int vram_x = ((flag >> 0x8) & 0xf) * 64;
    int vram_y = ((flag >> 0xc) & 0x1) * 256;
    int clut_x = ((flag >> 0x10) & 0x3f) * 16;
    int clut_y = (flag >> 0x16) & 0x1ff;

    texture.texture_x = vram_x;
    texture.texture_y = vram_y;
    texture.palette_x = clut_x;
    texture.palette_y = clut_y;
    texture.bpp = ( BPP )bpp;
    texture.type = type;

    for( size_t i = 0; i < textures.size(); i++ )
    {
        if( texture == textures[ i ] )
        {
            texture.start_x = textures[ i ].start_x;
            texture.start_y = textures[ i ].start_y;
            return;
        }
    }

    LOGGER->Log( "New Texture: X:0x" + HexToString( texture.texture_x, 4, '0' ) + ", Y:0x" + HexToString( texture.texture_y, 4, '0' ) + ", CLUTX:0x" + HexToString( texture.palette_x, 4, '0' ) + ", CLUTY:0x" + HexToString( texture.palette_y, 4, '0' ) + ", bpp:0x" + HexToString( texture.bpp, 2, '0' ) + ", type:0x" + HexToString( texture.type, 2, '0' ) + "\n" );

    texture.start_x = 0;
    texture.start_y = 0;
    for (size_t i = 0; i < textures.size(); i++)
    {
        if (texture.start_x <= textures[i].start_x)
        {
            texture.start_x = textures[i].start_x + 256;
        }
    }

    textures.push_back( texture );

    //LOGGER->Log(LOGGER_INFO, "Startx:0x%04x, Starty:0x%04x", texture.start_x, texture.start_y);
}

//---------------------------------------------------------------------
