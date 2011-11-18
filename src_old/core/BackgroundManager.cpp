// $Id$

#include <Ogre.h>
#include <libxml/xmlwriter.h>

#include "../../common/display/Display.h"
#include "../../common/utilites/Config.h"
#include "../../common/utilites/Logger.h"

#include "BackgroundAnimation.h"
#include "BackgroundLayer.h"
#include "BackgroundManager.h"
#include "BackgroundTile.h"
#include "FieldModule.h"
#include "../filetypes/LzsFile.h"
#include "../../common/display/surface/SurfaceSaveBmp.h"

Surface* full_image = NULL;
int x_32 = 0;
int y_32 = 0;
int x_16 = 0;
int y_16 = 0;
int n_16 = 0;
xmlTextWriterPtr writer;



bool
layer_depth_sort(BackgroundLayer* a, BackgroundLayer* b)
{
    return a->GetDepth() > b->GetDepth();
}



class surface_find
{
public:
    surface_find(const SurfaceTexData& a):
        m_Surface(a)
    {
    }

    bool
    operator()(const SurfaceTexData& a) const
    {
        return (a.page_x == m_Surface.page_x) &&
               (a.page_y == m_Surface.page_y) &&
               (a.clut_y == m_Surface.clut_y) &&
               (a.clut_x == m_Surface.clut_x) &&
               (a.bpp    == m_Surface.bpp);
    }

private:
    SurfaceTexData m_Surface;
};



BackgroundManager::BackgroundManager(FieldModule* field_module):
    m_FieldModule(field_module),

    m_File(NULL),

    m_3rdBackground(NULL),
    m_4thBackground(NULL),

    m_ShowBackground(true)
{
}



BackgroundManager::~BackgroundManager(void)
{
    Clear();
}



void
BackgroundManager::Clear(void)
{
    Uint32 i;

    Uint32 height = 1024;
    Uint32 width  = 512;

    if (full_image != NULL)
    {
/*
        Ogre::TexturePtr ptex;
        Ogre::HardwarePixelBufferSharedPtr buffer;
        ptex = Ogre::TextureManager::getSingleton().createManual("DynaTex", "General", Ogre::TEX_TYPE_2D, width, height, 0, Ogre::PF_R8G8B8A8, Ogre::TU_STATIC);
        buffer = ptex->getBuffer(0, 0);
        buffer->lock(Ogre::HardwareBuffer::HBL_DISCARD);
        const Ogre::PixelBox& pb = buffer->getCurrentLock();

        for (Uint32 y = 0; y < height; ++y)
        {
            Uint32* data = static_cast<Uint32*>(pb.data) + y * pb.rowPitch;

            for (Uint32 x = 0; x < width; ++x)
            {
                Uint32 clut = full_image->pixels[y * width * 4 + x * 4 + 3] | (full_image->pixels[y * width * 4 + x * 4 + 2] << 8) | (full_image->pixels[y * width * 4 + x * 4 + 1] << 16) | (full_image->pixels[y * width * 4 + x * 4 + 0] << 24);
                data[x] = clut;
            }
        }

        Ogre::Image image;
        image.loadDynamicImage((Ogre::uchar*)pb.data, width, height, Ogre::PF_R8G8B8A8);
        image.save("texture.png");
        buffer->unlock();
        Ogre::TextureManager::getSingleton().remove("DynaTex");



        writer = xmlNewTextWriterFilename("background.xml", 0);
        xmlTextWriterSetIndent(writer, 1);
        xmlTextWriterSetIndentString(writer, BAD_CAST "    ");
        xmlTextWriterStartDocument(writer, NULL, "ISO-8859-1", NULL);
        xmlTextWriterStartElement(writer, BAD_CAST "background");

        xmlTextWriterStartElement(writer, BAD_CAST "bottom");

        for (i = 0; i < m_1st.size(); ++i)
        {
            xmlTextWriterStartElement(writer, BAD_CAST "bottom_tile");
            xmlTextWriterWriteFormatAttribute(writer, BAD_CAST "x", "%d", m_1st[i].x);
            xmlTextWriterWriteFormatAttribute(writer, BAD_CAST "y", "%d", m_1st[i].y);
            xmlTextWriterWriteFormatAttribute(writer, BAD_CAST "width", "%d", m_1st[i].width);
            xmlTextWriterWriteFormatAttribute(writer, BAD_CAST "height", "%d", m_1st[i].height);
            xmlTextWriterWriteFormatAttribute(writer, BAD_CAST "src_x", "%d", m_1st[i].src_x);
            xmlTextWriterWriteFormatAttribute(writer, BAD_CAST "src_y", "%d", m_1st[i].src_y);
            xmlTextWriterEndElement(writer);
        }

        xmlTextWriterEndElement(writer);

        xmlTextWriterWriteRaw(writer, BAD_CAST "\n\n\n");

        xmlTextWriterStartElement(writer, BAD_CAST "fixed");

        for (i = 0; i < m_2nd.size(); ++i)
        {
            xmlTextWriterStartElement(writer, BAD_CAST "fixed_tile");
            xmlTextWriterWriteFormatAttribute(writer, BAD_CAST "x", "%d", m_2nd[i].x);
            xmlTextWriterWriteFormatAttribute(writer, BAD_CAST "y", "%d", m_2nd[i].y);
            xmlTextWriterWriteFormatAttribute(writer, BAD_CAST "width", "%d", m_2nd[i].width);
            xmlTextWriterWriteFormatAttribute(writer, BAD_CAST "height", "%d", m_2nd[i].height);
            xmlTextWriterWriteFormatAttribute(writer, BAD_CAST "src_x", "%d", m_2nd[i].src_x);
            xmlTextWriterWriteFormatAttribute(writer, BAD_CAST "src_y", "%d", m_2nd[i].src_y);
            xmlTextWriterWriteFormatAttribute(writer, BAD_CAST "depth", "%d", m_2nd[i].depth);
            xmlTextWriterWriteFormatAttribute(writer, BAD_CAST "group", "%d", m_2nd[i].group);
            xmlTextWriterWriteFormatAttribute(writer, BAD_CAST "index", "%d", m_2nd[i].index);
            xmlTextWriterEndElement(writer);
        }

        xmlTextWriterEndElement(writer);

        xmlTextWriterWriteRaw(writer, BAD_CAST "\n\n\n");

        xmlTextWriterStartElement(writer, BAD_CAST "dynamic_1");

        for (i = 0; i < m_3rd.size(); ++i)
        {
            xmlTextWriterStartElement(writer, BAD_CAST "dynamic_tile");
            xmlTextWriterWriteFormatAttribute(writer, BAD_CAST "x", "%d", m_3rd[i].x);
            xmlTextWriterWriteFormatAttribute(writer, BAD_CAST "y", "%d", m_3rd[i].y);
            xmlTextWriterWriteFormatAttribute(writer, BAD_CAST "width", "%d", m_3rd[i].width);
            xmlTextWriterWriteFormatAttribute(writer, BAD_CAST "height", "%d", m_3rd[i].height);
            xmlTextWriterWriteFormatAttribute(writer, BAD_CAST "src_x", "%d", m_3rd[i].src_x);
            xmlTextWriterWriteFormatAttribute(writer, BAD_CAST "src_y", "%d", m_3rd[i].src_y);
            xmlTextWriterWriteFormatAttribute(writer, BAD_CAST "group", "%d", m_3rd[i].group);
            xmlTextWriterWriteFormatAttribute(writer, BAD_CAST "index", "%d", m_3rd[i].index);
            xmlTextWriterEndElement(writer);
        }

        xmlTextWriterEndElement(writer);

        xmlTextWriterWriteRaw(writer, BAD_CAST "\n\n\n");

        xmlTextWriterStartElement(writer, BAD_CAST "dynamic_2");

        for (i = 0; i < m_3rd.size(); ++i)
        {
            xmlTextWriterStartElement(writer, BAD_CAST "dynamic_tile");
            xmlTextWriterWriteFormatAttribute(writer, BAD_CAST "x", "%d", m_4th[i].x);
            xmlTextWriterWriteFormatAttribute(writer, BAD_CAST "y", "%d", m_4th[i].y);
            xmlTextWriterWriteFormatAttribute(writer, BAD_CAST "width", "%d", m_4th[i].width);
            xmlTextWriterWriteFormatAttribute(writer, BAD_CAST "height", "%d", m_4th[i].height);
            xmlTextWriterWriteFormatAttribute(writer, BAD_CAST "src_x", "%d", m_4th[i].src_x);
            xmlTextWriterWriteFormatAttribute(writer, BAD_CAST "src_y", "%d", m_4th[i].src_y);
            xmlTextWriterWriteFormatAttribute(writer, BAD_CAST "group", "%d", m_4th[i].group);
            xmlTextWriterWriteFormatAttribute(writer, BAD_CAST "index", "%d", m_4th[i].index);
            xmlTextWriterEndElement(writer);
        }

        xmlTextWriterEndElement(writer);

        xmlTextWriterEndElement(writer);

        xmlTextWriterEndDocument(writer);
        xmlFreeTextWriter(writer);
*/


        m_1st.clear();
        m_2nd.clear();
        m_3rd.clear();
        m_4th.clear();




        //SurfaceUtils::SaveBMP("xxx.bmp", full_image);
        delete full_image;
        full_image = NULL;
    }

    if (full_image == NULL)
    {
        full_image = CreateSurface(width, height);
    }

    x_32 = 0;
    y_32 = 0;
    x_16 = 0;
    y_16 = 0;
    n_16 = 0;



    // we must do it right after loading. but if we forgot do it we can do it here.
    UnloadBackground();



    for (i = 0; i < m_1stBackground.size(); ++i)
    {
        delete m_1stBackground[i];
    }
    m_1stBackground.clear();



    for (i = 0; i < m_2ndBackground.size(); ++i)
    {
        delete m_2ndBackground[i];
    }
    m_2ndBackground.clear();



    if (m_3rdBackground != NULL)
    {
        delete m_3rdBackground;
        m_3rdBackground = NULL;
    }



    if (m_4thBackground != NULL)
    {
        delete m_4thBackground;
        m_4thBackground = NULL;
    }



    m_BackgroundAnimation.clear();
}



void
BackgroundManager::DrawBackground(const Uint16 depth_start, const Uint16 depth_end) const
{
    if (m_ShowBackground == false || m_FieldModule->m_MovieManager.IsPlay() != false)
    {
        return;
    }

    DISPLAY->PushMatrix();
    DISPLAY->Scale(2.0f / CONFIG->GAME_WIDTH, 2.0f / CONFIG->GAME_HEIGHT, 1.0f);
    DISPLAY->Translate(m_FieldModule->m_ScreenManager.GetCameraPositionX(), -m_FieldModule->m_ScreenManager.GetCameraPositionY(), 0.0f);
    DISPLAY->CameraPushMatrix();
    DISPLAY->CameraLoadIdentity();

    // if we render from very bottom - show lowest background
    if (depth_end == 65535)
    {
        for (Uint32 i = 0; i < m_1stBackground.size(); ++i)
        {
            m_1stBackground[i]->Draw();
        }
    }



    bool b3_rendered = false;
    bool b4_rendered = false;

    for (Uint32 i = 0; i < m_2ndBackground.size(); ++i)
    {
        if (m_2ndBackground[i]->GetDepth() < depth_start || m_2ndBackground[i]->GetDepth() >= depth_end)
        {
            continue;
        }

        if (b3_rendered == false && m_3rdBackground != NULL && (m_3rdBackground->GetDepth() > m_2ndBackground[i]->GetDepth()))
        {
            m_3rdBackground->Draw();
            b3_rendered = true;
        }

        if (b4_rendered == false && m_4thBackground != NULL && (m_4thBackground->GetDepth() > m_2ndBackground[i]->GetDepth()))
        {
            m_4thBackground->Draw();
            b4_rendered = true;
        }

        m_2ndBackground[i]->Draw();
    }



    if (b3_rendered == false &&
        m_3rdBackground != NULL &&
        m_3rdBackground->GetDepth() >= depth_start &&
        m_3rdBackground->GetDepth() <  depth_end)
    {
        m_3rdBackground->Draw();
    }



    if (b4_rendered == false &&
        m_4thBackground != NULL &&
        m_4thBackground->GetDepth() >= depth_start &&
        m_4thBackground->GetDepth() <  depth_end)
    {
        m_4thBackground->Draw();
    }



    DISPLAY->CameraPopMatrix();
    DISPLAY->PopMatrix();
}



bool
BackgroundManager::Input(const InputEvent &input)
{
    if (input.type == IET_FIRST_PRESS)
    {
        switch (input.button)
        {
            case KEY_C1: m_ShowBackground = (m_ShowBackground) ? false : true; break;
        }
    }

    return false;
}



void
BackgroundManager::Update(const Uint32 delta_time)
{
}



void
BackgroundManager::LoadBackground(const RString& name)
{
    LzsFile lzs_file(name);
    //lzs_file.WriteFile("DEL3.MIM_u");
    m_File = new MimFile(&lzs_file);
}



void
BackgroundManager::AddTile(const Uint8 background, const Sint16 dest_x, const Sint16 dest_y, const Uint8 src_x, const Uint8 src_y, const Uint16 clut_x, const Uint16 clut_y, const Uint8 bpp, const Uint8 page_x, const Uint8 page_y, const Uint16 depth, const Uint8 blending, const Uint8 animation, const Uint8 animation_index)
{
    SurfaceTexData surface;
    surface.page_x = page_x;
    surface.page_y = page_y;
    surface.clut_x = clut_x;
    surface.clut_y = clut_y;
    surface.bpp    = bpp;

    std::vector<SurfaceTexData>::iterator it = std::find_if(m_Surfaces.begin(), m_Surfaces.end(), surface_find(surface));

    if (it == m_Surfaces.end())
    {
        surface.surface = m_File->GetSurface(surface.page_x, surface.page_y, surface.clut_x, surface.clut_y, surface.bpp);
        m_Surfaces.push_back(surface);
    }
    else
    {
        surface = *it;
    }



    // set size depending on background
    Uint8 size = (background > 1) ? 32 : 16;

    Surface* sub_image = CreateSubSurface(src_x, src_y, size, size, surface.surface);

    int x = 0;
    int y = 0;
    if (sub_image->width == 32)
    {
        x = x_32;
        y = y_32;

        x_32 += 32;
        if (x_32 == full_image->width)
        {
            y_32 += 32;
            x_32 = 0;
        }
    }
    else if (sub_image->width == 16)
    {
        // if we start new 16x16*4 block
        if (n_16 == 0)
        {
            x_16 = x_32;
            y_16 = y_32;

            x_32 += 32;
            if (x_32 == full_image->width)
            {
                y_32 += 32;
                x_32 = 0;
            }
        }

        x = x_16;
        y = y_16;

        ++n_16;
        if (n_16 == 1 || n_16 == 3)
        {
            x_16 += 16;
        }
        else if (n_16 == 2)
        {
            x_16 -= 16;
            y_16 += 16;
        }
        else if (n_16 == 4)
        {
            n_16 = 0;
        }
    }
    CopyToSurface(full_image, x, y, sub_image);

    Tile t;
    t.x = dest_x;
    t.y = dest_y;
    t.width = size;
    t.height = size;
    t.src_x = x;
    t.src_y = y;
    t.depth = depth;
    t.group = animation;
    t.index = animation_index;
    switch (background)
    {
        case 0: m_1st.push_back(t); break;
        case 1: m_2nd.push_back(t); break;
        case 2: m_3rd.push_back(t); break;
        case 3: m_4th.push_back(t); break;
    }

    Uint32 texture_id = DISPLAY->CreateTexture(sub_image);
    BackgroundTile* tile = new BackgroundTile(size, texture_id, (blending == 0) ? BLEND_PSX_0 : BLEND_PSX_1, dest_x, dest_y);



    // if we want to add animation
    if (animation > 0)
    {
        // get pointer to existed group or create new one
        BackgroundAnimation* animation_set;
        bool found = false;
        for (Uint32 i = 0; i < m_BackgroundAnimation.size(); ++i)
        {
            if (m_BackgroundAnimation[i].second == animation)
            {
                animation_set = m_BackgroundAnimation[i].first;
                found = true;
            }
        }
        if (found == false)
        {
            animation_set = new BackgroundAnimation();
            m_BackgroundAnimation.push_back(Animation(animation_set, animation));
        }
        animation_set->AddTile(tile, animation_index);
    }



    // if this is 1st background
    if (background == 0)
    {
        m_1stBackground.push_back(tile);
    }



    // if this is 2nd background
    else if (background == 1)
    {
        // get pointer to existed layer or create new one
        BackgroundLayer* tile_layer;
        bool found = false;
        for (Uint32 i = 0; i < m_2ndBackground.size(); ++i)
        {
            if (m_2ndBackground[i]->GetDepth() == depth)
            {
                tile_layer = m_2ndBackground[i];
                found = true;
            }
        }
        if (found == false)
        {
            tile_layer = new BackgroundLayer();
            tile_layer->SetDepth(depth);
            m_2ndBackground.push_back(tile_layer);
            // it may be a bad idea to sort vector every time
            std::sort(m_2ndBackground.begin(), m_2ndBackground.end(), layer_depth_sort);
        }
        tile_layer->AddTile(tile);
    }



    // if this is 3rd background
    else if (background == 2)
    {
        if (m_3rdBackground == NULL)
        {
            m_3rdBackground = new BackgroundLayer();
        }

        m_3rdBackground->AddTile(tile);
    }



    // if this is 4th background
    else if (background == 3)
    {
        if (m_4thBackground == NULL)
        {
            m_4thBackground = new BackgroundLayer();
        }

        m_4thBackground->AddTile(tile);
    }



    delete sub_image;
}



void
BackgroundManager::UnloadBackground(void)
{
    if (m_File != NULL)
    {
        delete m_File;
        m_File = NULL;
    }

    for (u8 i = 0; i < m_Surfaces.size(); ++i)
    {
        delete m_Surfaces[i].surface;
    }
    m_Surfaces.clear();
}



void
BackgroundManager::BackgroundClear(const Uint8 group)
{
    for (Uint32 i = 0; i < m_BackgroundAnimation.size(); ++i)
    {
        if (m_BackgroundAnimation[i].second == group)
        {
            m_BackgroundAnimation[i].first->UnsetAllDraw();
        }
    }
}



void
BackgroundManager::BackgroundOn(const Uint8 group, const Uint8 index)
{
    for (Uint32 i = 0; i < m_BackgroundAnimation.size(); ++i)
    {
        if (m_BackgroundAnimation[i].second == group)
        {
            m_BackgroundAnimation[i].first->SetTileDraw(1 << index, true);
        }
    }
}



void
BackgroundManager::BackgroundOff(const Uint8 group, const Uint8 index)
{
    for (Uint32 i = 0; i < m_BackgroundAnimation.size(); ++i)
    {
        if (m_BackgroundAnimation[i].second == group)
        {
            m_BackgroundAnimation[i].first->SetTileDraw(1 << index, false);
        }
    }
}



void
BackgroundManager::BackgroundDepth(const Uint8 background_id, const Uint16 depth)
{
    if (background_id != 2 && background_id != 3)
    {
        LOGGER->Log(LOGGER_WARNING, "BackgroundManager::BackgroundDepth: tried change depth of background with id != 2 or 3");
        return;
    }

    if (background_id == 2 && m_3rdBackground != NULL)
    {
        m_3rdBackground->SetDepth(depth);
    }
    else if (background_id == 3 && m_4thBackground != NULL)
    {
        m_4thBackground->SetDepth(depth);
    }
}
