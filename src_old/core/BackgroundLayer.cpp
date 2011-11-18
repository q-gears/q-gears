// $Id$

#include "../../common/utilites/Logger.h"

#include "BackgroundLayer.h"
#include "BackgroundTile.h"



BackgroundLayer::BackgroundLayer(void):
    m_Depth(0)
{
}



BackgroundLayer::~BackgroundLayer(void)
{
    for (Uint32 i = 0; i < m_Tiles.size(); ++i)
    {
        delete m_Tiles[i];
    }
}



void
BackgroundLayer::Draw(void) const
{
    for (Uint32 i = 0; i < m_Tiles.size(); ++i)
    {
        m_Tiles[i]->Draw();
    }
}



void
BackgroundLayer::AddTile(BackgroundTile* tile)
{
    m_Tiles.push_back(tile);
}



const Uint16
BackgroundLayer::GetDepth(void) const
{
    return m_Depth;
}



void
BackgroundLayer::SetDepth(const Uint16 depth)
{
    m_Depth = depth;
}
