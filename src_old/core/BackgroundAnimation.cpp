// $Id$

#include "../../common/utilites/Logger.h"

#include "BackgroundAnimation.h"
#include "BackgroundTile.h"



BackgroundAnimation::BackgroundAnimation(void)
{
}



BackgroundAnimation::~BackgroundAnimation(void)
{
}



void
BackgroundAnimation::Input(const InputEvent& input)
{
}



void
BackgroundAnimation::Update(const Uint32 delta_time)
{
}



void
BackgroundAnimation::Draw(void) const
{
    for (Uint32 i = 0; i < m_Tiles.size(); ++i)
    {
        m_Tiles[i].first->Draw();
    }
}



void
BackgroundAnimation::AddTile(BackgroundTile* tile, const Uint8 index)
{
    m_Tiles.push_back(TileWithIndex(tile, index));
}



void
BackgroundAnimation::SetTileDraw(const Uint8 index, const bool draw)
{
    for (Uint32 i = 0; i < m_Tiles.size(); ++i)
    {
        if (m_Tiles[i].second == index)
        {
            m_Tiles[i].first->SetDraw(draw);
        }
    }
}



void
BackgroundAnimation::UnsetAllDraw(void)
{
    for (Uint32 i = 0; i < m_Tiles.size(); ++i)
    {
        m_Tiles[i].first->SetDraw(false);
    }
}
