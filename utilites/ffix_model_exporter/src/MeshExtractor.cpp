#include "MeshExtractor.h"

#define POSITION_BINDING 0
#define COLOUR_BINDING 1
#define TEXTURE_BINDING 2

#include "../../common/Logger.h"
#include "../../common/OgreGenUtilites.h"



void
MeshExtractor( const MeshData& mesh_data, const Ogre::String& material_name, File* file, int offset_to_data, VectorTexForGen& textures, const Ogre::MeshPtr& mesh )
{
    int number_of_monochrome_textured_quads = file->GetU16LE( offset_to_data + 0x02 );
    int number_of_monochrome_textured_triangles = file->GetU16LE( offset_to_data + 0x04 );
    int number_of_shaded_textured_quads = file->GetU16LE( offset_to_data + 0x06 );
    int number_of_shaded_textured_triangles = file->GetU16LE( offset_to_data + 0x08 );
    int number_of_gradated_quads = file->GetU16LE( offset_to_data + 0x0a );
    int number_of_gradated_triangles = file->GetU16LE( offset_to_data + 0x0c );
    int number_of_monochrome_quads = file->GetU16LE( offset_to_data + 0x0e );
    int number_of_monochrome_triangles = file->GetU16LE( offset_to_data + 0x10 );

    u32 pointer_to_vertex_groups = file->GetU32LE( offset_to_data + 0x14 );
    u32 pointer_to_vertex_data = file->GetU32LE( offset_to_data + 0x18 );
    u32 pointer_to_mesh_data = file->GetU32LE( offset_to_data + 0x1c );



    Ogre::SubMesh* sub_mesh = mesh->createSubMesh(/* name */);
    sub_mesh->setMaterialName( material_name );
    sub_mesh->useSharedVertices = false;
    sub_mesh->operationType = Ogre::RenderOperation::OT_TRIANGLE_LIST;

    // Allocate and prepare vertex data
    sub_mesh->vertexData = new Ogre::VertexData();
    sub_mesh->vertexData->vertexStart = 0;
    sub_mesh->vertexData->vertexCount = static_cast< size_t >(
        number_of_monochrome_textured_quads * 6 +
        number_of_monochrome_textured_triangles * 3/* +
        number_of_shaded_textured_quads * 6 +
        number_of_shaded_textured_triangles * 3 +
        number_of_gradated_quads * 6 +
        number_of_gradated_triangles * 3 +
        number_of_monochrome_quads * 6 +
        number_of_monochrome_triangles * 3*/ );

    sub_mesh->indexData = new Ogre::IndexData();
    sub_mesh->indexData->indexStart = 0;
    sub_mesh->indexData->indexCount = sub_mesh->vertexData->vertexCount;
    sub_mesh->indexData->indexBuffer = Ogre::HardwareBufferManager::getSingleton().createIndexBuffer(
        Ogre::HardwareIndexBuffer::IT_16BIT,
        sub_mesh->indexData->indexCount,
        Ogre::HardwareBuffer::HBU_STATIC_WRITE_ONLY );
    u16* idata = static_cast< u16* >( sub_mesh->indexData->indexBuffer->lock( Ogre::HardwareBuffer::HBL_DISCARD ) );
    u32 cur_index = 0;

    Ogre::VertexDeclaration* decl = sub_mesh->vertexData->vertexDeclaration;
    Ogre::VertexBufferBinding* bind = sub_mesh->vertexData->vertexBufferBinding;
    // 1st buffer
    decl->addElement( POSITION_BINDING, 0, Ogre::VET_FLOAT3, Ogre::VES_POSITION );
    Ogre::HardwareVertexBufferSharedPtr vbuf0 = Ogre::HardwareBufferManager::getSingleton().createVertexBuffer(
        decl->getVertexSize( POSITION_BINDING ),
        sub_mesh->vertexData->vertexCount,
        Ogre::HardwareBuffer::HBU_STATIC_WRITE_ONLY );
    bind->setBinding( POSITION_BINDING, vbuf0 );

    // 2nd buffer
    decl->addElement( COLOUR_BINDING, 0, Ogre::VET_COLOUR, Ogre::VES_DIFFUSE );
    Ogre::HardwareVertexBufferSharedPtr vbuf1 = Ogre::HardwareBufferManager::getSingleton().createVertexBuffer(
        decl->getVertexSize( COLOUR_BINDING ),
        sub_mesh->vertexData->vertexCount,
        Ogre::HardwareBuffer::HBU_STATIC_WRITE_ONLY );
    // Set vertex buffer binding so buffer 1 is bound to our colour buffer
    bind->setBinding( COLOUR_BINDING, vbuf1 );
/*
    // 3rd buffer
    decl->addElement( TEXTURE_BINDING, 0, Ogre::VET_FLOAT2, Ogre::VES_TEXTURE_COORDINATES, 0 );
    Ogre::HardwareVertexBufferSharedPtr vbuf2 = Ogre::HardwareBufferManager::getSingleton().createVertexBuffer(
        decl->getVertexSize( TEXTURE_BINDING ),
        sub_mesh->vertexData->vertexCount,
        Ogre::HardwareBuffer::HBU_STATIC_WRITE_ONLY );
    bind->setBinding( TEXTURE_BINDING, vbuf2 );
*/
    float* pPos   = static_cast< float* >( vbuf0->lock( Ogre::HardwareBuffer::HBL_DISCARD ) );
    //float* tPos   = static_cast< float* >( vbuf2->lock( Ogre::HardwareBuffer::HBL_DISCARD ) );

    Ogre::RenderSystem* rs = Ogre::Root::getSingleton().getRenderSystem();
    Ogre::RGBA colours[ sub_mesh->vertexData->vertexCount ];



    for( int i = 0; i < number_of_monochrome_textured_quads; ++i )
    {
        int index_a = file->GetU16LE( pointer_to_mesh_data + 0x0 );
        int index_b = file->GetU16LE( pointer_to_mesh_data + 0x2 );
        int index_c = file->GetU16LE( pointer_to_mesh_data + 0x4 );
        int index_d = file->GetU16LE( pointer_to_mesh_data + 0x6 );

        Ogre::Vector3 a( ( s16 )file->GetU16LE( pointer_to_vertex_data + index_a * 0x8 + 0x0 ),
                         ( s16 )file->GetU16LE( pointer_to_vertex_data + index_a * 0x8 + 0x2 ),
                         ( s16 )file->GetU16LE( pointer_to_vertex_data + index_a * 0x8 + 0x4 ) );
        Ogre::Vector3 b( ( s16 )file->GetU16LE( pointer_to_vertex_data + index_b * 0x8 + 0x0 ),
                         ( s16 )file->GetU16LE( pointer_to_vertex_data + index_b * 0x8 + 0x2 ),
                         ( s16 )file->GetU16LE( pointer_to_vertex_data + index_b * 0x8 + 0x4 ) );
        Ogre::Vector3 c( ( s16 )file->GetU16LE( pointer_to_vertex_data + index_c * 0x8 + 0x0 ),
                         ( s16 )file->GetU16LE( pointer_to_vertex_data + index_c * 0x8 + 0x2 ),
                         ( s16 )file->GetU16LE( pointer_to_vertex_data + index_c * 0x8 + 0x4 ) );
        Ogre::Vector3 d( ( s16 )file->GetU16LE( pointer_to_vertex_data + index_d * 0x8 + 0x0 ),
                         ( s16 )file->GetU16LE( pointer_to_vertex_data + index_d * 0x8 + 0x2 ),
                         ( s16 )file->GetU16LE( pointer_to_vertex_data + index_d * 0x8 + 0x4 ) );
        a /= 512;
        b /= 512;
        c /= 512;
        d /= 512;
/*
        u16 clut = file->GetU16LE(offset_to_quad_t + 0x4 + j * 0x14 + 0xa);
        int clut_x = (clut & 0x003f) << 3;
        int clut_y = (clut & 0xffc0) >> 6;
        int bpp    = (tpage >> 0x7) & 0x3;
        int vram_x = (tpage & 0xf) * 64;
        int vram_y = ((tpage & 0x10) >> 4) * 256;
        TexForGen texture;
        texture.palette_x = clut_x;
        texture.palette_y = clut_y;
        texture.texture_x = vram_x;
        texture.texture_y = vram_y;
        texture.bpp = bpp;
        AddTexture( texture, mesh_data, textures, LOGGER );

        Ogre::Vector2 at(0, 0);
        Ogre::Vector2 bt(0, 0);
        Ogre::Vector2 ct(0, 0);
        Ogre::Vector2 dt(0, 0);

        int x = file->GetU8(offset_to_quad_t + 0x4 + j * 0x14 + 0x8) + texture.start_x;
        at.x = x / (float)mesh_data.tex_width;
        int y = file->GetU8(offset_to_quad_t + 0x4 + j * 0x14 + 0x9) + texture.start_y;
        at.y = y / (float)mesh_data.tex_height;

        x = file->GetU8(offset_to_quad_t + 0x4 + j * 0x14 + 0xc) + texture.start_x;
        bt.x = x / (float)mesh_data.tex_width;
        y = file->GetU8(offset_to_quad_t + 0x4 + j * 0x14 + 0xd) + texture.start_y;
        bt.y = y / (float)mesh_data.tex_height;

        x = file->GetU8(offset_to_quad_t + 0x4 + j * 0x14 + 0xe) + texture.start_x;
        ct.x = x / (float)mesh_data.tex_width;
        y = file->GetU8(offset_to_quad_t + 0x4 + j * 0x14 + 0xf) + texture.start_y;
        ct.y = y / (float)mesh_data.tex_height;

        x = file->GetU8(offset_to_quad_t + 0x4 + j * 0x14 + 0x10) + texture.start_x;
        dt.x = x / (float)mesh_data.tex_width;
        y = file->GetU8(offset_to_quad_t + 0x4 + j * 0x14 + 0x11) + texture.start_y;
        dt.y = y / (float)mesh_data.tex_height;
*/

        *pPos++ = a.x; *pPos++ = a.y; *pPos++ = a.z;
        *pPos++ = c.x; *pPos++ = c.y; *pPos++ = c.z;
        *pPos++ = b.x; *pPos++ = b.y; *pPos++ = b.z;
        *pPos++ = b.x; *pPos++ = b.y; *pPos++ = b.z;
        *pPos++ = c.x; *pPos++ = c.y; *pPos++ = c.z;
        *pPos++ = d.x; *pPos++ = d.y; *pPos++ = d.z;

/*
        *tPos++ = at.x; *tPos++ = at.y;
        *tPos++ = ct.x; *tPos++ = ct.y;
        *tPos++ = bt.x; *tPos++ = bt.y;
        *tPos++ = bt.x; *tPos++ = bt.y;
        *tPos++ = ct.x; *tPos++ = ct.y;
        *tPos++ = dt.x; *tPos++ = dt.y;
*/

        Ogre::ColourValue colour = Ogre::ColourValue( file->GetU8( pointer_to_mesh_data + 0x10 ) / 256.0f,
                                                      file->GetU8( pointer_to_mesh_data + 0x11 ) / 256.0f,
                                                      file->GetU8( pointer_to_mesh_data + 0x12 ) / 256.0f,
                                                      1.0f );

        rs->convertColourValue( colour, colours + cur_index + 0 );
        rs->convertColourValue( colour, colours + cur_index + 1 );
        rs->convertColourValue( colour, colours + cur_index + 2 );
        rs->convertColourValue( colour, colours + cur_index + 3 );
        rs->convertColourValue( colour, colours + cur_index + 4 );
        rs->convertColourValue( colour, colours + cur_index + 5 );

        idata[ cur_index + 0 ] = cur_index + 0;
        idata[ cur_index + 1 ] = cur_index + 1;
        idata[ cur_index + 2 ] = cur_index + 2;
        idata[ cur_index + 3 ] = cur_index + 3;
        idata[ cur_index + 4 ] = cur_index + 4;
        idata[ cur_index + 5 ] = cur_index + 5;

        cur_index += 6;
        pointer_to_mesh_data += 0x18;
    }



    for( int i = 0; i < number_of_monochrome_textured_triangles; ++i )
    {
        int index_a = file->GetU16LE( pointer_to_mesh_data + 0x0 );
        int index_b = file->GetU16LE( pointer_to_mesh_data + 0x2 );
        int index_c = file->GetU16LE( pointer_to_mesh_data + 0x4 );

        Ogre::Vector3 a( ( s16 )file->GetU16LE( pointer_to_vertex_data + index_a * 0x8 + 0x0 ),
                         ( s16 )file->GetU16LE( pointer_to_vertex_data + index_a * 0x8 + 0x2 ),
                         ( s16 )file->GetU16LE( pointer_to_vertex_data + index_a * 0x8 + 0x4 ) );
        Ogre::Vector3 b( ( s16 )file->GetU16LE( pointer_to_vertex_data + index_b * 0x8 + 0x0 ),
                         ( s16 )file->GetU16LE( pointer_to_vertex_data + index_b * 0x8 + 0x2 ),
                         ( s16 )file->GetU16LE( pointer_to_vertex_data + index_b * 0x8 + 0x4 ) );
        Ogre::Vector3 c( ( s16 )file->GetU16LE( pointer_to_vertex_data + index_c * 0x8 + 0x0 ),
                         ( s16 )file->GetU16LE( pointer_to_vertex_data + index_c * 0x8 + 0x2 ),
                         ( s16 )file->GetU16LE( pointer_to_vertex_data + index_c * 0x8 + 0x4 ) );
        a /= 512;
        b /= 512;
        c /= 512;
/*
        u16 clut = file->GetU16LE(offset_to_triangle_t + 0x4 + j * 0x10 + 0xa);
        int clut_x = (clut & 0x003f) << 3;
        int clut_y = (clut & 0xffc0) >> 6;
        int bpp    = (tpage >> 0x7) & 0x3;
        int vram_x = (tpage & 0xf) * 64;
        int vram_y = ((tpage & 0x10) >> 4) * 256;
        TexForGen texture;
        texture.palette_x = clut_x;
        texture.palette_y = clut_y;
        texture.texture_x = vram_x;
        texture.texture_y = vram_y;
        texture.bpp = bpp;
        AddTexture( texture, mesh_data, textures, LOGGER );

        Ogre::Vector2 at(0, 0);
        Ogre::Vector2 bt(0, 0);
        Ogre::Vector2 ct(0, 0);

        int x = file->GetU8(offset_to_triangle_t + 0x4 + j * 0x10 + 0x8) + texture.start_x;
        at.x = x / (float)mesh_data.tex_width;
        int y = file->GetU8(offset_to_triangle_t + 0x4 + j * 0x10 + 0x9) + texture.start_y;
        at.y = y / (float)mesh_data.tex_height;
        x = file->GetU8(offset_to_triangle_t + 0x4 + j * 0x10 + 0xc) + texture.start_x;
        bt.x = x / (float)mesh_data.tex_width;
        y = file->GetU8(offset_to_triangle_t + 0x4 + j * 0x10 + 0xd) + texture.start_y;
        bt.y = y / (float)mesh_data.tex_height;
        x = file->GetU8(offset_to_triangle_t + 0x4 + j * 0x10 + 0xe) + texture.start_x;
        ct.x = x / (float)mesh_data.tex_width;
        y = file->GetU8(offset_to_triangle_t + 0x4 + j * 0x10 + 0xf) + texture.start_y;
        ct.y = y / (float)mesh_data.tex_height;
*/

        *pPos++ = a.x; *pPos++ = a.y; *pPos++ = a.z;
        *pPos++ = c.x; *pPos++ = c.y; *pPos++ = c.z;
        *pPos++ = b.x; *pPos++ = b.y; *pPos++ = b.z;

/*
        *tPos++ = at.x; *tPos++ = at.y;
        *tPos++ = ct.x; *tPos++ = ct.y;
        *tPos++ = bt.x; *tPos++ = bt.y;
*/

        Ogre::ColourValue colour = Ogre::ColourValue( file->GetU8( pointer_to_mesh_data + 0x10 ) / 256.0f,
                                                      file->GetU8( pointer_to_mesh_data + 0x11 ) / 256.0f,
                                                      file->GetU8( pointer_to_mesh_data + 0x12 ) / 256.0f,
                                                      1.0f );

        rs->convertColourValue( colour, colours + cur_index + 0 );
        rs->convertColourValue( colour, colours + cur_index + 1 );
        rs->convertColourValue( colour, colours + cur_index + 2 );

        idata[ cur_index + 0 ] = cur_index + 0;
        idata[ cur_index + 1 ] = cur_index + 1;
        idata[ cur_index + 2 ] = cur_index + 2;

        cur_index += 3;
        pointer_to_mesh_data += 0x14;
    }



    vbuf0->unlock();
    vbuf1->writeData( 0, vbuf1->getSizeInBytes(), colours, true );
    //vbuf2->unlock();

    sub_mesh->indexData->indexBuffer->unlock();
    // Optimize index data
    sub_mesh->indexData->optimiseVertexCacheTriList();
/*
    if (bone_id != -1)
    {
        LOGGER->Log("Assign bones to vertexes\n");

        int vertex_number = sub_mesh->vertexData->vertexCount;
        for (int i = 0; i < vertex_number; ++i)
        {
            Ogre::VertexBoneAssignment vba;
            vba.vertexIndex = i;
            vba.boneIndex = bone_id;
            vba.weight = 1.0f;
            sub_mesh->addBoneAssignment(vba);
        }
    }
*/
}
