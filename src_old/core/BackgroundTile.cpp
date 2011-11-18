// $Id$

#include "../../common/display/Display.h"
#include "../../common/utilites/Logger.h"

#include "BackgroundTile.h"



BackgroundTile::BackgroundTile(const Uint8 size, const Uint32 texture_id, const BlendMode& blending, const Sint16 x, const Sint16 y):
    m_TextureId(texture_id),

    m_X(x),
    m_Y(y),

    m_Draw(true)
{
    m_Poly.blend = blending;

    Vertex point;
    point.p.x = 0.0f;  point.p.y = 0.0f;   point.p.z = 0.0f;
    point.c.r = 1.0f;  point.c.g = 1.0f;   point.c.b = 1.0f; point.c.a = 1.0f;
    point.t.x = 0.0f;  point.t.y = 0.0f;
    m_Poly.vertexes.push_back(point);
    point.p.x = size;  point.p.y = 0.0f;   point.p.z = 0.0f;
    point.c.r = 1.0f;  point.c.g = 1.0f;   point.c.b = 1.0f; point.c.a = 1.0f;
    point.t.x = 1.0f;  point.t.y = 0.0f;
    m_Poly.vertexes.push_back(point);
    point.p.x = size;  point.p.y = -size;  point.p.z = 0.0f;
    point.c.r = 1.0f;  point.c.g = 1.0f;   point.c.b = 1.0f; point.c.a = 1.0f;
    point.t.x = 1.0f;  point.t.y = 1.0f;
    m_Poly.vertexes.push_back(point);
    point.p.x = 0.0f;  point.p.y = -size;  point.p.z = 0.0f;
    point.c.r = 1.0f;  point.c.g = 1.0f;   point.c.b = 1.0f; point.c.a =  1.0f;
    point.t.x = 0.0f;  point.t.y = 1.0f;
    m_Poly.vertexes.push_back(point);
}



BackgroundTile::~BackgroundTile(void)
{
    DISPLAY->DeleteTexture(m_TextureId);
}



void
BackgroundTile::Input(const InputEvent& input)
{
}



void
BackgroundTile::Update(const Uint32 delta_time)
{
}



void
BackgroundTile::Draw(void) const
{
    if (m_Draw != true)
    {
        return;
    }

    DISPLAY->PushMatrix();
    DISPLAY->Translate(m_X, -m_Y, 0);
    DISPLAY->SetTexture(m_TextureId);
    DISPLAY->DrawQuads(m_Poly);
    DISPLAY->UnsetTexture();
    DISPLAY->PopMatrix();
}



void
BackgroundTile::SetDraw(const bool draw)
{
    m_Draw = draw;
}
