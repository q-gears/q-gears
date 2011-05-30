#include "OgreGenUtilites.h"

#include "Logger.h"



void
CreateTextureFromVram(const Ogre::PixelBox& pb, Vram* vram, const int start_x, const int start_y, const int clut_x, const int clut_y, const int texture_x, const int texture_y, const int bpp)
{
    for (u32 y = 0; y < 256; ++y)
    {
        u32* data = static_cast<u32*>(pb.data) + (y + start_y) * pb.rowPitch;

        for (u32 x = 0; x < 256; ++x)
        {
            if (bpp == 0)
            {
                u8 pixel = vram->GetU8(texture_x * 2 + x / 2, texture_y + y);

                u16 clut1 = vram->GetU16(clut_x * 2 + (pixel & 0xf) * 2, clut_y);
                u16 clut2 = vram->GetU16(clut_x * 2 + (pixel >> 4) * 2, clut_y);

                u32 ogre_pixel1 = (((clut1 & 0x1f) * 255 / 31) << 0x18) | ((((clut1 >>  5) & 0x1f) * 255 / 31) << 0x10) | ((((clut1 >> 10) & 0x1f) * 255 / 31) << 0x8) | 0;

                u8 stp = (clut1 & 0x8000) >> 15;
                if (stp == 0 && (ogre_pixel1 & 0xffffff00) == 0)
                {
                    ogre_pixel1 |= 0;
                }
                else if (stp == 0 && (ogre_pixel1 & 0xffffff00) != 0)
                {
                    ogre_pixel1 |= 255;
                }
                else if (stp == 1 && (ogre_pixel1 & 0xffffff00) == 0)
                {
                    ogre_pixel1 |= 255;
                }
                else if (stp == 1 && (ogre_pixel1 & 0xffffff00) != 0)
                {
                    ogre_pixel1 |= 255 / 4;
                }

                u32 ogre_pixel2 = (((clut2 & 0x1f) * 255 / 31) << 0x18) | ((((clut2 >>  5) & 0x1f) * 255 / 31) << 0x10) | ((((clut2 >> 10) & 0x1f) * 255 / 31) << 0x8) | 0;

                stp = (clut2 & 0x8000) >> 15;
                if (stp == 0 && (ogre_pixel2 & 0xffffff00) == 0)
                {
                    ogre_pixel2 |= 0;
                }
                else if (stp == 0 && (ogre_pixel2 & 0xffffff00) != 0)
                {
                    ogre_pixel2 |= 255;
                }
                else if (stp == 1 && (ogre_pixel2 & 0xffffff00) == 0)
                {
                    ogre_pixel2 |= 255;
                }
                else if (stp == 1 && (ogre_pixel2 & 0xffffff00) != 0)
                {
                    ogre_pixel2 |= 255 / 4;
                }

                data[start_x + x] = ogre_pixel1;
                ++x;
                data[start_x + x] = ogre_pixel2;
            }
            else if (bpp == 1)
            {
                u8 pixel = vram->GetU8(texture_x * 2 + x, texture_y + y);
                u16 clut = vram->GetU16(clut_x + pixel * 2, clut_y);

                u32 ogre_pixel = (((clut & 0x1f) * 255 / 31) << 0x18) | ((((clut >>  5) & 0x1f) * 255 / 31) << 0x10) | ((((clut >> 10) & 0x1f) * 255 / 31) << 0x8) | 0;

                u8 stp = (clut & 0x8000) >> 15;
                if (stp == 0 && (ogre_pixel & 0xffffff00) == 0)
                {
                    ogre_pixel |= 0;
                }
                else if (stp == 0 && (ogre_pixel & 0xffffff00) != 0)
                {
                    ogre_pixel |= 255;
                }
                else if (stp == 1 && (ogre_pixel & 0xffffff00) == 0)
                {
                    ogre_pixel |= 255;
                }
                else if (stp == 1 && (ogre_pixel & 0xffffff00) != 0)
                {
                    ogre_pixel |= 255 / 4;
                }

                data[start_x + x] = ogre_pixel;
            }
            else if (bpp == -1)
            {
                data[start_x + x] = 0xffffffff;
            }
        }
    }
}



void
CreateTexture(Vram* vram, const MeshData& mesh_data, const Ogre::String& texture_file_name, const VectorTexForGen& textures)
{
    Ogre::TexturePtr ptex;
    Ogre::HardwarePixelBufferSharedPtr buffer;
    ptex = Ogre::TextureManager::getSingleton().createManual("DynaTex", "General", Ogre::TEX_TYPE_2D, mesh_data.tex_width, mesh_data.tex_height, 0, Ogre::PF_R8G8B8A8, Ogre::TU_STATIC);
    buffer = ptex->getBuffer(0, 0);
    buffer->lock(Ogre::HardwareBuffer::HBL_DISCARD);
    const Ogre::PixelBox& pb = buffer->getCurrentLock();

    for (int i = 0; i < textures.size(); ++i)
    {
        CreateTextureFromVram(pb, vram, textures[i].start_x, textures[i].start_y, textures[i].palette_x, textures[i].palette_y, textures[i].texture_x, textures[i].texture_y, textures[i].bpp);
    }

    Ogre::Image image;
    image.loadDynamicImage((Ogre::uchar*)pb.data, mesh_data.tex_width, mesh_data.tex_height, Ogre::PF_R8G8B8A8);
    image.save(texture_file_name);
    buffer->unlock();

    return;
}



void
CreateMaterial(const Ogre::String& material_name, const Ogre::String& material_file_name, const Ogre::String& texture_name, const Ogre::String& vertex_program, const Ogre::String& fragment_program)
{
    Ogre::MaterialPtr material = Ogre::MaterialManager::getSingleton().create(material_name, "General");
    Ogre::Technique* tech = material->getTechnique(0);
    Ogre::Pass* pass1 = tech->getPass(0);
    pass1->setVertexColourTracking(Ogre::TVC_AMBIENT);
    //pass1->setCullingMode(Ogre::CULL_NONE);
    if( texture_name != "" )
    {
        pass1->setAlphaRejectFunction(Ogre::CMPF_GREATER);
        pass1->setAlphaRejectValue(0);
        Ogre::TextureUnitState* tex = pass1->createTextureUnitState();
        tex->setTextureName(texture_name);
        tex->setNumMipmaps(-1);
        tex->setTextureFiltering(Ogre::TFO_NONE);
    }

    if( vertex_program != "" )
    {
        pass1->setVertexProgram( vertex_program, true );
    }

    if( fragment_program != "" )
    {
        pass1->setFragmentProgram( fragment_program, true );
    }

    Ogre::MaterialSerializer mat;
    mat.exportMaterial(material, material_file_name);
}



void
AddTexture(TexForGen& texture, VectorTexForGen& textures, Logger* logger)
{
    for (int i = 0; i < textures.size(); i++)
    {
        if (texture == textures[i])
        {
            texture.start_x = textures[i].start_x;
            texture.start_y = textures[i].start_y;
            return;
        }
    }

    //logger->Log("New Texture: X:" + ToHexString(texture.texture_x, 4, '0') + ", Y:" + ToHexString(texture.texture_y, 4, '0') + ", CLUTX:" + ToHexString(texture.palette_x, 4, '0') + ", CLUTY:" + ToHexString(texture.palette_y, 4, '0') + ", bpp:" + ToHexString(texture.bpp, 4, '0') + "\n");

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

    //logger->Log("Startx:" + ToHexString(texture.start_x, 4, '0') + ", Starty:" + ToHexString(texture.start_y, 4, '0') + "\n");
}
