#include "MeshFile.h"
#include "../../common/Logger.h"

#define POSITION_BINDING 0
#define COLOUR_BINDING 1
#define TEXTURE_BINDING 2



int tex_width = 512;
int tex_height = 256;



MeshFile::MeshFile(const Ogre::String& file):
    File(file)
{
}



MeshFile::MeshFile(File* pFile):
    File(pFile)
{
}



MeshFile::MeshFile(File* pFile, const u32 offset, const u32 length):
    File(pFile, offset, length)
{
}



MeshFile::MeshFile(u8* pBuffer, const u32 offset, const u32 length):
    File(pBuffer, offset, length)
{
}



MeshFile::~MeshFile(void)
{
}



void
MeshFile::GetData(const Ogre::String& name, const int offset_to_parts, const int number_of_parts, Ogre::MeshPtr mesh, VectorTexForGenBsx& textures)
{
    for (u32 i = 0; i < number_of_parts; ++i)
    {
        u32 offset_to_part   = offset_to_parts + i * 0x20;
        //LOGGER->Log(LOGGER_INFO, "offset_to_part: %08x", offset_to_part);

        // add vertexes to array
        u8  number_of_vertex  = GetU8(offset_to_part + 0x02);
        u16 offset_to_vertexes = GetU16LE(offset_to_part + 0x18);
        //LOGGER->Log(LOGGER_INFO, "number_of_vertex:    %02x", number_of_vertex);
        std::vector<Ogre::Vector3> vertexes;

        for (u32 j = 0; j < number_of_vertex; ++j)
        {
            u16 offset_to_vertex = offset_to_vertexes + j * 0x08;

            Ogre::Vector3 point;
            point.x = -static_cast<float>(static_cast<s16>(GetU16LE(offset_to_vertex + 4 + 0x00)));
            point.z = -static_cast<float>(static_cast<s16>(GetU16LE(offset_to_vertex + 4 + 0x02)));
            point.y = -static_cast<float>(static_cast<s16>(GetU16LE(offset_to_vertex + 4 + 0x04)));
            vertexes.push_back(point / 1024);
        }

        u8  number_of_quad_t      = GetU8(offset_to_part + 0x04);
        u8  number_of_triangle_t  = GetU8(offset_to_part + 0x05);
        u8  number_of_quad_t2     = GetU8(offset_to_part + 0x06);
        u8  number_of_triangle_t2 = GetU8(offset_to_part + 0x07);
        u8  number_of_triangle_m  = GetU8(offset_to_part + 0x08);
        u8  number_of_quad_m      = GetU8(offset_to_part + 0x09);
        u8  number_of_triangle    = GetU8(offset_to_part + 0x0A);
        u8  number_of_quads       = GetU8(offset_to_part + 0x0B);



        Ogre::SubMesh* sub_mesh = mesh->createSubMesh(Ogre::StringConverter::toString(i));
        sub_mesh->setMaterialName("model/field/" + name);
        sub_mesh->useSharedVertices = false;
        sub_mesh->operationType = Ogre::RenderOperation::OT_TRIANGLE_LIST;

        // Allocate and prepare vertex data
        sub_mesh->vertexData = new Ogre::VertexData();
        sub_mesh->vertexData->vertexStart = 0;
        sub_mesh->vertexData->vertexCount = static_cast<size_t>(number_of_quad_t * 6 +
                                                                number_of_triangle_t * 3 +
                                                                number_of_quad_t2 * 6 +
                                                                number_of_triangle_t2 * 3 +
                                                                number_of_triangle_m * 3 +
                                                                number_of_quad_m * 6 +
                                                                number_of_triangle * 3 +
                                                                number_of_quads * 6);
        sub_mesh->indexData = new Ogre::IndexData();
        sub_mesh->indexData->indexStart = 0;
        sub_mesh->indexData->indexCount = sub_mesh->vertexData->vertexCount;
        sub_mesh->indexData->indexBuffer = Ogre::HardwareBufferManager::getSingleton().createIndexBuffer(
            Ogre::HardwareIndexBuffer::IT_16BIT,
            sub_mesh->indexData->indexCount,
            Ogre::HardwareBuffer::HBU_STATIC_WRITE_ONLY);
        u16* idata = static_cast< u16* >(sub_mesh->indexData->indexBuffer->lock(Ogre::HardwareBuffer::HBL_DISCARD));
        u32 cur_index = 0;

        Ogre::VertexDeclaration* decl = sub_mesh->vertexData->vertexDeclaration;
        Ogre::VertexBufferBinding* bind = sub_mesh->vertexData->vertexBufferBinding;
        // 1st buffer
        decl->addElement(POSITION_BINDING, 0, Ogre::VET_FLOAT3, Ogre::VES_POSITION);
        Ogre::HardwareVertexBufferSharedPtr vbuf0 = Ogre::HardwareBufferManager::getSingleton().createVertexBuffer(
                decl->getVertexSize(POSITION_BINDING),
                sub_mesh->vertexData->vertexCount,
                Ogre::HardwareBuffer::HBU_STATIC_WRITE_ONLY);
        bind->setBinding(POSITION_BINDING, vbuf0);

        // 2nd buffer
        decl->addElement(COLOUR_BINDING, 0, Ogre::VET_COLOUR, Ogre::VES_DIFFUSE);
        Ogre::HardwareVertexBufferSharedPtr vbuf1 = Ogre::HardwareBufferManager::getSingleton().createVertexBuffer(
                decl->getVertexSize(COLOUR_BINDING),
                sub_mesh->vertexData->vertexCount,
                Ogre::HardwareBuffer::HBU_STATIC_WRITE_ONLY);
        // Set vertex buffer binding so buffer 1 is bound to our colour buffer
        bind->setBinding(COLOUR_BINDING, vbuf1);

        // 3rd buffer
        decl->addElement(TEXTURE_BINDING, 0, Ogre::VET_FLOAT2, Ogre::VES_TEXTURE_COORDINATES, 0);
        Ogre::HardwareVertexBufferSharedPtr vbuf2 = Ogre::HardwareBufferManager::getSingleton().createVertexBuffer(
                decl->getVertexSize(TEXTURE_BINDING),
                sub_mesh->vertexData->vertexCount,
                Ogre::HardwareBuffer::HBU_STATIC_WRITE_ONLY);
        bind->setBinding(TEXTURE_BINDING, vbuf2);

        float* pPos   = static_cast<float*>(vbuf0->lock(Ogre::HardwareBuffer::HBL_DISCARD));
        float* tPos   = static_cast<float*>(vbuf2->lock(Ogre::HardwareBuffer::HBL_DISCARD));

        Ogre::RenderSystem* rs = Ogre::Root::getSingleton().getRenderSystem();
        Ogre::RGBA colours[sub_mesh->vertexData->vertexCount];



        u32 offset_to_poly           = offset_to_vertexes + GetU16LE(offset_to_part + 0x0E);
        u32 offset_to_texture_coords = offset_to_vertexes + GetU16LE(offset_to_part + 0x10);
        offset_to_4              = offset_to_vertexes + GetU16LE(offset_to_part + 0x12);
        offset_to_5              = offset_to_vertexes + GetU16LE(offset_to_part + 0x14);


        // add textured quad
        for (u32 j = 0; j < number_of_quad_t; ++j)
        {
            // set vertexes
            Ogre::Vector3 a1 = vertexes[GetU8(offset_to_poly + 0x00)];
            Ogre::Vector3 b1 = vertexes[GetU8(offset_to_poly + 0x01)];
            Ogre::Vector3 d1 = vertexes[GetU8(offset_to_poly + 0x02)];
            Ogre::Vector3 c1 = vertexes[GetU8(offset_to_poly + 0x03)];
            *pPos++ = a1.x; *pPos++ = a1.y; *pPos++ = a1.z;
            *pPos++ = b1.x; *pPos++ = b1.y; *pPos++ = b1.z;
            *pPos++ = c1.x; *pPos++ = c1.y; *pPos++ = c1.z;
            *pPos++ = a1.x; *pPos++ = a1.y; *pPos++ = a1.z;
            *pPos++ = c1.x; *pPos++ = c1.y; *pPos++ = c1.z;
            *pPos++ = d1.x; *pPos++ = d1.y; *pPos++ = d1.z;

            TexForGenBsx texture;
            AddTexture(texture, textures);

            Ogre::Vector2 at;
            Ogre::Vector2 bt;
            Ogre::Vector2 ct;
            Ogre::Vector2 dt;

            u8 texture_coords_id = GetU8(offset_to_poly + 0x14);
            int x = GetU8(offset_to_texture_coords + texture_coords_id * 0x02 + 0x00) + texture.start_x;
            x = (texture.type == 0 && x >= 32) ? x - 32 : x;
            at.x = x / (float)tex_width;
            int y = GetU8(offset_to_texture_coords + texture_coords_id * 0x02 + 0x01) + texture.start_y;
            y = (texture.type == 1) ? y + 32 : y;
            at.y = y / (float)tex_height;

            texture_coords_id = GetU8(offset_to_poly + 0x15);
            x = GetU8(offset_to_texture_coords + texture_coords_id * 0x02 + 0x00) + texture.start_x;
            x = (texture.type == 0 && x >= 32) ? x - 32 : x;
            bt.x = x / (float)tex_width;
            y = GetU8(offset_to_texture_coords + texture_coords_id * 0x02 + 0x01) + texture.start_y;
            y = (texture.type == 1) ? y + 32 : y;
            bt.y = y / (float)tex_height;

            texture_coords_id = GetU8(offset_to_poly + 0x16);
            x = GetU8(offset_to_texture_coords + texture_coords_id * 0x02 + 0x00) + texture.start_x;
            x = (texture.type == 0 && x >= 32) ? x - 32 : x;
            dt.x = x / (float)tex_width;
            y = GetU8(offset_to_texture_coords + texture_coords_id * 0x02 + 0x01) + texture.start_y;
            y = (texture.type == 1) ? y + 32 : y;
            dt.y = y / (float)tex_height;

            texture_coords_id = GetU8(offset_to_poly + 0x17);
            x = GetU8(offset_to_texture_coords + texture_coords_id * 0x02 + 0x00) + texture.start_x;
            x = (texture.type == 0 && x >= 32) ? x - 32 : x;
            ct.x = x / (float)tex_width;
            y = GetU8(offset_to_texture_coords + texture_coords_id * 0x02 + 0x01) + texture.start_y;
            y = (texture.type == 1) ? y + 32 : y;
            ct.y = y / (float)tex_height;

            *tPos++ = at.x; *tPos++ = at.y;
            *tPos++ = bt.x; *tPos++ = bt.y;
            *tPos++ = ct.x; *tPos++ = ct.y;
            *tPos++ = at.x; *tPos++ = at.y;
            *tPos++ = ct.x; *tPos++ = ct.y;
            *tPos++ = dt.x; *tPos++ = dt.y;

            // set color to vertexes
            Ogre::ColourValue a_colour = Ogre::ColourValue(GetU8(offset_to_poly + 0x04) / 255.0f, GetU8(offset_to_poly + 0x05) / 255.0f, GetU8(offset_to_poly + 0x06) / 255.0f, 0);
            Ogre::ColourValue b_colour = Ogre::ColourValue(GetU8(offset_to_poly + 0x08) / 255.0f, GetU8(offset_to_poly + 0x09) / 255.0f, GetU8(offset_to_poly + 0x0a) / 255.0f, 0);
            Ogre::ColourValue d_colour = Ogre::ColourValue(GetU8(offset_to_poly + 0x0c) / 255.0f, GetU8(offset_to_poly + 0x0d) / 255.0f, GetU8(offset_to_poly + 0x0e) / 255.0f, 0);
            Ogre::ColourValue c_colour = Ogre::ColourValue(GetU8(offset_to_poly + 0x10) / 255.0f, GetU8(offset_to_poly + 0x11) / 255.0f, GetU8(offset_to_poly + 0x12) / 255.0f, 0);
            rs->convertColourValue(a_colour, colours + cur_index + 0);
            rs->convertColourValue(b_colour, colours + cur_index + 1);
            rs->convertColourValue(c_colour, colours + cur_index + 2);
            rs->convertColourValue(a_colour, colours + cur_index + 3);
            rs->convertColourValue(c_colour, colours + cur_index + 4);
            rs->convertColourValue(d_colour, colours + cur_index + 5);

            idata[cur_index + 0] = cur_index + 0;
            idata[cur_index + 1] = cur_index + 1;
            idata[cur_index + 2] = cur_index + 2;
            idata[cur_index + 3] = cur_index + 3;
            idata[cur_index + 4] = cur_index + 4;
            idata[cur_index + 5] = cur_index + 5;

            cur_index += 6;
            // </OGRE> ///////////////////////////////

            offset_to_poly += 0x18;
        }

        // add textured triangle
        for (u32 j = 0; j < number_of_triangle_t; ++j)
        {
            // set vertexes
            Ogre::Vector3 a1 = vertexes[GetU8(offset_to_poly + 0x00)];
            Ogre::Vector3 b1 = vertexes[GetU8(offset_to_poly + 0x01)];
            Ogre::Vector3 c1 = vertexes[GetU8(offset_to_poly + 0x02)];
            *pPos++ = a1.x; *pPos++ = a1.y; *pPos++ = a1.z;
            *pPos++ = b1.x; *pPos++ = b1.y; *pPos++ = b1.z;
            *pPos++ = c1.x; *pPos++ = c1.y; *pPos++ = c1.z;

            TexForGenBsx texture;
            AddTexture(texture, textures);

            Ogre::Vector2 at;
            Ogre::Vector2 bt;
            Ogre::Vector2 ct;

            u8 texture_coords_id = GetU8(offset_to_poly + 0x10);
            int x = GetU8(offset_to_texture_coords + texture_coords_id * 0x02 + 0x00) + texture.start_x;
            x = (texture.type == 0 && x >= 32) ? x - 32 : x;
            at.x = x / (float)tex_width;
            int y = GetU8(offset_to_texture_coords + texture_coords_id * 0x02 + 0x01) + texture.start_y;
            y = (texture.type == 1) ? y + 32 : y;
            at.y = y / (float)tex_height;

            texture_coords_id = GetU8(offset_to_poly + 0x11);
            x = GetU8(offset_to_texture_coords + texture_coords_id * 0x02 + 0x00) + texture.start_x;
            x = (texture.type == 0 && x >= 32) ? x - 32 : x;
            bt.x = x / (float)tex_width;
            y = GetU8(offset_to_texture_coords + texture_coords_id * 0x02 + 0x01) + texture.start_y;
            y = (texture.type == 1) ? y + 32 : y;
            bt.y = y / (float)tex_height;

            texture_coords_id = GetU8(offset_to_poly + 0x12);
            x = GetU8(offset_to_texture_coords + texture_coords_id * 0x02 + 0x00) + texture.start_x;
            x = (texture.type == 0 && x >= 32) ? x - 32 : x;
            ct.x = x / (float)tex_width;
            y = GetU8(offset_to_texture_coords + texture_coords_id * 0x02 + 0x01) + texture.start_y;
            y = (texture.type == 1) ? y + 32 : y;
            ct.y = y / (float)tex_height;

            *tPos++ = at.x; *tPos++ = at.y;
            *tPos++ = bt.x; *tPos++ = bt.y;
            *tPos++ = ct.x; *tPos++ = ct.y;

            // set color to vertexes
            Ogre::ColourValue a_colour = Ogre::ColourValue(GetU8(offset_to_poly + 0x04) / 255.0f, GetU8(offset_to_poly + 0x05) / 255.0f, GetU8(offset_to_poly + 0x06) / 255.0f, 0);
            Ogre::ColourValue b_colour = Ogre::ColourValue(GetU8(offset_to_poly + 0x08) / 255.0f, GetU8(offset_to_poly + 0x09) / 255.0f, GetU8(offset_to_poly + 0x0a) / 255.0f, 0);
            Ogre::ColourValue c_colour = Ogre::ColourValue(GetU8(offset_to_poly + 0x0c) / 255.0f, GetU8(offset_to_poly + 0x0d) / 255.0f, GetU8(offset_to_poly + 0x0e) / 255.0f, 0);
            rs->convertColourValue(a_colour, colours + cur_index + 0);
            rs->convertColourValue(b_colour, colours + cur_index + 1);
            rs->convertColourValue(c_colour, colours + cur_index + 2);

            idata[cur_index + 0] = cur_index + 0;
            idata[cur_index + 1] = cur_index + 1;
            idata[cur_index + 2] = cur_index + 2;

            cur_index += 3;
            // </OGRE> ///////////////////////////////

            offset_to_poly += 0x14;
        }

        // add textured monochrome quad
        for (u32 j = 0; j < number_of_quad_t2; ++j)
        {
            // set vertexes
            Ogre::Vector3 a1 = vertexes[GetU8(offset_to_poly + 0x00)];
            Ogre::Vector3 b1 = vertexes[GetU8(offset_to_poly + 0x01)];
            Ogre::Vector3 d1 = vertexes[GetU8(offset_to_poly + 0x02)];
            Ogre::Vector3 c1 = vertexes[GetU8(offset_to_poly + 0x03)];
            *pPos++ = a1.x; *pPos++ = a1.y; *pPos++ = a1.z;
            *pPos++ = b1.x; *pPos++ = b1.y; *pPos++ = b1.z;
            *pPos++ = c1.x; *pPos++ = c1.y; *pPos++ = c1.z;
            *pPos++ = a1.x; *pPos++ = a1.y; *pPos++ = a1.z;
            *pPos++ = c1.x; *pPos++ = c1.y; *pPos++ = c1.z;
            *pPos++ = d1.x; *pPos++ = d1.y; *pPos++ = d1.z;

            TexForGenBsx texture;
            AddTexture(texture, textures);

            Ogre::Vector2 at;
            Ogre::Vector2 bt;
            Ogre::Vector2 ct;
            Ogre::Vector2 dt;

            u8 texture_coords_id = GetU8(offset_to_poly + 0x8);
            int x = GetU8(offset_to_texture_coords + texture_coords_id * 0x02 + 0x00) + texture.start_x;
            x = (texture.type == 0 && x >= 32) ? x - 32 : x;
            at.x = x / (float)tex_width;
            int y = GetU8(offset_to_texture_coords + texture_coords_id * 0x02 + 0x01) + texture.start_y;
            y = (texture.type == 1) ? y + 32 : y;
            at.y = y / (float)tex_height;

            texture_coords_id = GetU8(offset_to_poly + 0x9);
            x = GetU8(offset_to_texture_coords + texture_coords_id * 0x02 + 0x00) + texture.start_x;
            x = (texture.type == 0 && x >= 32) ? x - 32 : x;
            bt.x = x / (float)tex_width;
            y = GetU8(offset_to_texture_coords + texture_coords_id * 0x02 + 0x01) + texture.start_y;
            y = (texture.type == 1) ? y + 32 : y;
            bt.y = y / (float)tex_height;

            texture_coords_id = GetU8(offset_to_poly + 0xa);
            x = GetU8(offset_to_texture_coords + texture_coords_id * 0x02 + 0x00) + texture.start_x;
            x = (texture.type == 0 && x >= 32) ? x - 32 : x;
            dt.x = x / (float)tex_width;
            y = GetU8(offset_to_texture_coords + texture_coords_id * 0x02 + 0x01) + texture.start_y;
            y = (texture.type == 1) ? y + 32 : y;
            dt.y = y / (float)tex_height;

            texture_coords_id = GetU8(offset_to_poly + 0xb);
            x = GetU8(offset_to_texture_coords + texture_coords_id * 0x02 + 0x00) + texture.start_x;
            x = (texture.type == 0 && x >= 32) ? x - 32 : x;
            ct.x = x / (float)tex_width;
            y = GetU8(offset_to_texture_coords + texture_coords_id * 0x02 + 0x01) + texture.start_y;
            y = (texture.type == 1) ? y + 32 : y;
            ct.y = y / (float)tex_height;

            *tPos++ = at.x; *tPos++ = at.y;
            *tPos++ = bt.x; *tPos++ = bt.y;
            *tPos++ = ct.x; *tPos++ = ct.y;
            *tPos++ = at.x; *tPos++ = at.y;
            *tPos++ = ct.x; *tPos++ = ct.y;
            *tPos++ = dt.x; *tPos++ = dt.y;

            // set color to vertexes
            Ogre::ColourValue a_colour = Ogre::ColourValue(GetU8(offset_to_poly + 0x04) / 255.0f, GetU8(offset_to_poly + 0x05) / 255.0f, GetU8(offset_to_poly + 0x06) / 255.0f, 0);
            Ogre::ColourValue b_colour = Ogre::ColourValue(GetU8(offset_to_poly + 0x04) / 255.0f, GetU8(offset_to_poly + 0x05) / 255.0f, GetU8(offset_to_poly + 0x06) / 255.0f, 0);
            Ogre::ColourValue d_colour = Ogre::ColourValue(GetU8(offset_to_poly + 0x04) / 255.0f, GetU8(offset_to_poly + 0x05) / 255.0f, GetU8(offset_to_poly + 0x06) / 255.0f, 0);
            Ogre::ColourValue c_colour = Ogre::ColourValue(GetU8(offset_to_poly + 0x04) / 255.0f, GetU8(offset_to_poly + 0x05) / 255.0f, GetU8(offset_to_poly + 0x06) / 255.0f, 0);
            rs->convertColourValue(a_colour, colours + cur_index + 0);
            rs->convertColourValue(b_colour, colours + cur_index + 1);
            rs->convertColourValue(c_colour, colours + cur_index + 2);
            rs->convertColourValue(a_colour, colours + cur_index + 3);
            rs->convertColourValue(c_colour, colours + cur_index + 4);
            rs->convertColourValue(d_colour, colours + cur_index + 5);

            idata[cur_index + 0] = cur_index + 0;
            idata[cur_index + 1] = cur_index + 1;
            idata[cur_index + 2] = cur_index + 2;
            idata[cur_index + 3] = cur_index + 3;
            idata[cur_index + 4] = cur_index + 4;
            idata[cur_index + 5] = cur_index + 5;

            cur_index += 6;
            // </OGRE> ///////////////////////////////

            offset_to_poly += 0x0C;
        }

        // add textured monochrome triangle
        for (u32 j = 0; j < number_of_triangle_t2; ++j)
        {
            // set vertexes
            Ogre::Vector3 a1 = vertexes[GetU8(offset_to_poly + 0x00)];
            Ogre::Vector3 b1 = vertexes[GetU8(offset_to_poly + 0x01)];
            Ogre::Vector3 c1 = vertexes[GetU8(offset_to_poly + 0x02)];
            *pPos++ = a1.x; *pPos++ = a1.y; *pPos++ = a1.z;
            *pPos++ = b1.x; *pPos++ = b1.y; *pPos++ = b1.z;
            *pPos++ = c1.x; *pPos++ = c1.y; *pPos++ = c1.z;

            TexForGenBsx texture;
            AddTexture(texture, textures);

            Ogre::Vector2 at;
            Ogre::Vector2 bt;
            Ogre::Vector2 ct;

            u8 texture_coords_id = GetU8(offset_to_poly + 0x8);
            int x = GetU8(offset_to_texture_coords + texture_coords_id * 0x02 + 0x00) + texture.start_x;
            x = (texture.type == 0 && x >= 32) ? x - 32 : x;
            at.x = x / (float)tex_width;
            int y = GetU8(offset_to_texture_coords + texture_coords_id * 0x02 + 0x01) + texture.start_y;
            y = (texture.type == 1) ? y + 32 : y;
            at.y = y / (float)tex_height;

            texture_coords_id = GetU8(offset_to_poly + 0x9);
            x = GetU8(offset_to_texture_coords + texture_coords_id * 0x02 + 0x00) + texture.start_x;
            x = (texture.type == 0 && x >= 32) ? x - 32 : x;
            bt.x = x / (float)tex_width;
            y = GetU8(offset_to_texture_coords + texture_coords_id * 0x02 + 0x01) + texture.start_y;
            y = (texture.type == 1) ? y + 32 : y;
            bt.y = y / (float)tex_height;

            texture_coords_id = GetU8(offset_to_poly + 0xa);
            x = GetU8(offset_to_texture_coords + texture_coords_id * 0x02 + 0x00) + texture.start_x;
            x = (texture.type == 0 && x >= 32) ? x - 32 : x;
            ct.x = x / (float)tex_width;
            y = GetU8(offset_to_texture_coords + texture_coords_id * 0x02 + 0x01) + texture.start_y;
            y = (texture.type == 1) ? y + 32 : y;
            ct.y = y / (float)tex_height;

            *tPos++ = at.x; *tPos++ = at.y;
            *tPos++ = bt.x; *tPos++ = bt.y;
            *tPos++ = ct.x; *tPos++ = ct.y;

            // set color to vertexes
            Ogre::ColourValue a_colour = Ogre::ColourValue(GetU8(offset_to_poly + 0x04) / 255.0f, GetU8(offset_to_poly + 0x05) / 255.0f, GetU8(offset_to_poly + 0x06) / 255.0f, 0);
            Ogre::ColourValue b_colour = Ogre::ColourValue(GetU8(offset_to_poly + 0x04) / 255.0f, GetU8(offset_to_poly + 0x05) / 255.0f, GetU8(offset_to_poly + 0x06) / 255.0f, 0);
            Ogre::ColourValue c_colour = Ogre::ColourValue(GetU8(offset_to_poly + 0x04) / 255.0f, GetU8(offset_to_poly + 0x05) / 255.0f, GetU8(offset_to_poly + 0x06) / 255.0f, 0);
            rs->convertColourValue(a_colour, colours + cur_index + 0);
            rs->convertColourValue(b_colour, colours + cur_index + 1);
            rs->convertColourValue(c_colour, colours + cur_index + 2);

            idata[cur_index + 0] = cur_index + 0;
            idata[cur_index + 1] = cur_index + 1;
            idata[cur_index + 2] = cur_index + 2;

            cur_index += 3;

            offset_to_poly += 0x0C;
        }

        // add monochrome triangle
        for (u32 j = 0; j < number_of_triangle_m; ++j)
        {
            // set vertexes
            Ogre::Vector3 a1 = vertexes[GetU8(offset_to_poly + 0x00)];
            Ogre::Vector3 b1 = vertexes[GetU8(offset_to_poly + 0x01)];
            Ogre::Vector3 c1 = vertexes[GetU8(offset_to_poly + 0x02)];
            *pPos++ = a1.x; *pPos++ = a1.y; *pPos++ = a1.z;
            *pPos++ = b1.x; *pPos++ = b1.y; *pPos++ = b1.z;
            *pPos++ = c1.x; *pPos++ = c1.y; *pPos++ = c1.z;

            Ogre::Vector2 at(0.99, 0.99);
            Ogre::Vector2 bt(0.99, 0.99);
            Ogre::Vector2 ct(0.99, 0.99);
            *tPos++ = at.x; *tPos++ = at.y;
            *tPos++ = bt.x; *tPos++ = bt.y;
            *tPos++ = ct.x; *tPos++ = ct.y;

            // set color to vertexes
            Ogre::ColourValue a_colour = Ogre::ColourValue(GetU8(offset_to_poly + 0x04) / 255.0f, GetU8(offset_to_poly + 0x05) / 255.0f, GetU8(offset_to_poly + 0x06) / 255.0f, 0);
            Ogre::ColourValue b_colour = Ogre::ColourValue(GetU8(offset_to_poly + 0x04) / 255.0f, GetU8(offset_to_poly + 0x05) / 255.0f, GetU8(offset_to_poly + 0x06) / 255.0f, 0);
            Ogre::ColourValue c_colour = Ogre::ColourValue(GetU8(offset_to_poly + 0x04) / 255.0f, GetU8(offset_to_poly + 0x05) / 255.0f, GetU8(offset_to_poly + 0x06) / 255.0f, 0);
            rs->convertColourValue(a_colour, colours + cur_index + 0);
            rs->convertColourValue(b_colour, colours + cur_index + 1);
            rs->convertColourValue(c_colour, colours + cur_index + 2);

            idata[cur_index + 0] = cur_index + 0;
            idata[cur_index + 1] = cur_index + 1;
            idata[cur_index + 2] = cur_index + 2;

            cur_index += 3;

            offset_to_poly += 0x08;
        }

        // add monochrome quad
        for (u32 j = 0; j < number_of_quad_m; ++j)
        {
            // set vertexes
            Ogre::Vector3 a1 = vertexes[GetU8(offset_to_poly + 0x00)];
            Ogre::Vector3 b1 = vertexes[GetU8(offset_to_poly + 0x01)];
            Ogre::Vector3 d1 = vertexes[GetU8(offset_to_poly + 0x02)];
            Ogre::Vector3 c1 = vertexes[GetU8(offset_to_poly + 0x03)];
            *pPos++ = a1.x; *pPos++ = a1.y; *pPos++ = a1.z;
            *pPos++ = b1.x; *pPos++ = b1.y; *pPos++ = b1.z;
            *pPos++ = c1.x; *pPos++ = c1.y; *pPos++ = c1.z;
            *pPos++ = a1.x; *pPos++ = a1.y; *pPos++ = a1.z;
            *pPos++ = c1.x; *pPos++ = c1.y; *pPos++ = c1.z;
            *pPos++ = d1.x; *pPos++ = d1.y; *pPos++ = d1.z;

            Ogre::Vector2 at(0.99, 0.99);
            Ogre::Vector2 bt(0.99, 0.99);
            Ogre::Vector2 ct(0.99, 0.99);
            Ogre::Vector2 dt(0.99, 0.99);
            *tPos++ = at.x; *tPos++ = at.y;
            *tPos++ = bt.x; *tPos++ = bt.y;
            *tPos++ = ct.x; *tPos++ = ct.y;
            *tPos++ = at.x; *tPos++ = at.y;
            *tPos++ = ct.x; *tPos++ = ct.y;
            *tPos++ = dt.x; *tPos++ = dt.y;

            // set color to vertexes
            Ogre::ColourValue a_colour = Ogre::ColourValue(GetU8(offset_to_poly + 0x04) / 255.0f, GetU8(offset_to_poly + 0x05) / 255.0f, GetU8(offset_to_poly + 0x06) / 255.0f, 0);
            Ogre::ColourValue b_colour = Ogre::ColourValue(GetU8(offset_to_poly + 0x04) / 255.0f, GetU8(offset_to_poly + 0x05) / 255.0f, GetU8(offset_to_poly + 0x06) / 255.0f, 0);
            Ogre::ColourValue d_colour = Ogre::ColourValue(GetU8(offset_to_poly + 0x04) / 255.0f, GetU8(offset_to_poly + 0x05) / 255.0f, GetU8(offset_to_poly + 0x06) / 255.0f, 0);
            Ogre::ColourValue c_colour = Ogre::ColourValue(GetU8(offset_to_poly + 0x04) / 255.0f, GetU8(offset_to_poly + 0x05) / 255.0f, GetU8(offset_to_poly + 0x06) / 255.0f, 0);
            rs->convertColourValue(a_colour, colours + cur_index + 0);
            rs->convertColourValue(b_colour, colours + cur_index + 1);
            rs->convertColourValue(c_colour, colours + cur_index + 2);
            rs->convertColourValue(a_colour, colours + cur_index + 3);
            rs->convertColourValue(c_colour, colours + cur_index + 4);
            rs->convertColourValue(d_colour, colours + cur_index + 5);

            idata[cur_index + 0] = cur_index + 0;
            idata[cur_index + 1] = cur_index + 1;
            idata[cur_index + 2] = cur_index + 2;
            idata[cur_index + 3] = cur_index + 3;
            idata[cur_index + 4] = cur_index + 4;
            idata[cur_index + 5] = cur_index + 5;

            cur_index += 6;

            offset_to_poly += 0x08;
        }

        // add color triangle
        for (u32 j = 0; j < number_of_triangle; ++j)
        {
            // set vertexes
            Ogre::Vector3 a1 = vertexes[GetU8(offset_to_poly + 0x00)];
            Ogre::Vector3 b1 = vertexes[GetU8(offset_to_poly + 0x01)];
            Ogre::Vector3 c1 = vertexes[GetU8(offset_to_poly + 0x02)];
            *pPos++ = a1.x; *pPos++ = a1.y; *pPos++ = a1.z;
            *pPos++ = b1.x; *pPos++ = b1.y; *pPos++ = b1.z;
            *pPos++ = c1.x; *pPos++ = c1.y; *pPos++ = c1.z;

            Ogre::Vector2 at(0.99, 0.99);
            Ogre::Vector2 bt(0.99, 0.99);
            Ogre::Vector2 ct(0.99, 0.99);
            *tPos++ = at.x; *tPos++ = at.y;
            *tPos++ = bt.x; *tPos++ = bt.y;
            *tPos++ = ct.x; *tPos++ = ct.y;

            // set color to vertexes
            Ogre::ColourValue a_colour = Ogre::ColourValue(GetU8(offset_to_poly + 0x04) / 255.0f, GetU8(offset_to_poly + 0x05) / 255.0f, GetU8(offset_to_poly + 0x06) / 255.0f, 0);
            Ogre::ColourValue b_colour = Ogre::ColourValue(GetU8(offset_to_poly + 0x08) / 255.0f, GetU8(offset_to_poly + 0x09) / 255.0f, GetU8(offset_to_poly + 0x0a) / 255.0f, 0);
            Ogre::ColourValue c_colour = Ogre::ColourValue(GetU8(offset_to_poly + 0x0c) / 255.0f, GetU8(offset_to_poly + 0x0d) / 255.0f, GetU8(offset_to_poly + 0x0e) / 255.0f, 0);
            rs->convertColourValue(a_colour, colours + cur_index + 0);
            rs->convertColourValue(b_colour, colours + cur_index + 1);
            rs->convertColourValue(c_colour, colours + cur_index + 2);

            idata[cur_index + 0] = cur_index + 0;
            idata[cur_index + 1] = cur_index + 1;
            idata[cur_index + 2] = cur_index + 2;

            cur_index += 3;

            offset_to_poly += 0x10;
        }

        // add color quad
        for (u32 j = 0; j < number_of_quads; ++j)
        {
            // set vertexes
            Ogre::Vector3 a1 = vertexes[GetU8(offset_to_poly + 0x00)];
            Ogre::Vector3 b1 = vertexes[GetU8(offset_to_poly + 0x01)];
            Ogre::Vector3 d1 = vertexes[GetU8(offset_to_poly + 0x02)];
            Ogre::Vector3 c1 = vertexes[GetU8(offset_to_poly + 0x03)];
            *pPos++ = a1.x; *pPos++ = a1.y; *pPos++ = a1.z;
            *pPos++ = b1.x; *pPos++ = b1.y; *pPos++ = b1.z;
            *pPos++ = c1.x; *pPos++ = c1.y; *pPos++ = c1.z;
            *pPos++ = a1.x; *pPos++ = a1.y; *pPos++ = a1.z;
            *pPos++ = c1.x; *pPos++ = c1.y; *pPos++ = c1.z;
            *pPos++ = d1.x; *pPos++ = d1.y; *pPos++ = d1.z;

            Ogre::Vector2 at(0.99, 0.99);
            Ogre::Vector2 bt(0.99, 0.99);
            Ogre::Vector2 ct(0.99, 0.99);
            Ogre::Vector2 dt(0.99, 0.99);
            *tPos++ = at.x; *tPos++ = at.y;
            *tPos++ = bt.x; *tPos++ = bt.y;
            *tPos++ = ct.x; *tPos++ = ct.y;
            *tPos++ = at.x; *tPos++ = at.y;
            *tPos++ = ct.x; *tPos++ = ct.y;
            *tPos++ = dt.x; *tPos++ = dt.y;

            // set color to vertexes
            Ogre::ColourValue a_colour = Ogre::ColourValue(GetU8(offset_to_poly + 0x04) / 255.0f, GetU8(offset_to_poly + 0x05) / 255.0f, GetU8(offset_to_poly + 0x06) / 255.0f, 0);
            Ogre::ColourValue b_colour = Ogre::ColourValue(GetU8(offset_to_poly + 0x08) / 255.0f, GetU8(offset_to_poly + 0x09) / 255.0f, GetU8(offset_to_poly + 0x0a) / 255.0f, 0);
            Ogre::ColourValue d_colour = Ogre::ColourValue(GetU8(offset_to_poly + 0x0c) / 255.0f, GetU8(offset_to_poly + 0x0d) / 255.0f, GetU8(offset_to_poly + 0x0e) / 255.0f, 0);
            Ogre::ColourValue c_colour = Ogre::ColourValue(GetU8(offset_to_poly + 0x10) / 255.0f, GetU8(offset_to_poly + 0x11) / 255.0f, GetU8(offset_to_poly + 0x12) / 255.0f, 0);
            rs->convertColourValue(a_colour, colours + cur_index + 0);
            rs->convertColourValue(b_colour, colours + cur_index + 1);
            rs->convertColourValue(c_colour, colours + cur_index + 2);
            rs->convertColourValue(a_colour, colours + cur_index + 3);
            rs->convertColourValue(c_colour, colours + cur_index + 4);
            rs->convertColourValue(d_colour, colours + cur_index + 5);

            idata[cur_index + 0] = cur_index + 0;
            idata[cur_index + 1] = cur_index + 1;
            idata[cur_index + 2] = cur_index + 2;
            idata[cur_index + 3] = cur_index + 3;
            idata[cur_index + 4] = cur_index + 4;
            idata[cur_index + 5] = cur_index + 5;

            cur_index += 6;

            offset_to_poly += 0x14;
        }

        vbuf0->unlock();
        vbuf1->writeData(0, vbuf1->getSizeInBytes(), colours, true);
        vbuf2->unlock();

        sub_mesh->indexData->indexBuffer->unlock();
        // Optimize index data
        sub_mesh->indexData->optimiseVertexCacheTriList();

        int vertex_number = sub_mesh->vertexData->vertexCount;
        //LOGGER->Log(LOGGER_INFO, "vertex_number %08x", vertex_number);
        for (int i = 0; i < vertex_number; ++i)
        {
            Ogre::VertexBoneAssignment vba;
            vba.vertexIndex = i;
            vba.boneIndex = GetU8(offset_to_part + 0x01) * 2 + 2;
            vba.weight = 1.0f;
            sub_mesh->addBoneAssignment(vba);
        }
    }
}



void
MeshFile::AddTexture(TexForGenBsx& texture, VectorTexForGenBsx& textures)
{
    u8 control = GetU8(offset_to_5);
    //LOGGER->Log(LOGGER_INFO, "quad control: %02x", control);
    ++offset_to_5;

    u8 blend = (control >> 4) & 0x3;
    u8 flag_id = control & 0xf;
    u32 flag = GetU32LE(offset_to_4 + flag_id * 4);
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
    texture.bpp = bpp;
    texture.type = type;

    for (int i = 0; i < textures.size(); i++)
    {
        if (texture == textures[i])
        {
            texture.start_x = textures[i].start_x;
            texture.start_y = textures[i].start_y;
            return;
        }
    }

    //LOGGER->Log(LOGGER_INFO, "New Texture: X:0x%04x, Y:0x%04x, CLUTX:0x%04x, CLUTY:0x%04x, bpp:0x%02x, type:0x%02x", texture.texture_x, texture.texture_y, texture.palette_x, texture.palette_y, texture.bpp, texture.type);

    texture.start_x = 0;
    texture.start_y = 0;
    for (int i = 0; i < textures.size(); i++)
    {
        if (texture.start_x <= textures[i].start_x)
        {
            texture.start_x = textures[i].start_x + 256;
        }
    }

    textures.push_back(texture);

    //LOGGER->Log(LOGGER_INFO, "Startx:0x%04x, Starty:0x%04x", texture.start_x, texture.start_y);
}
