// $Id$

#ifndef BACKGROUND_LAYER_h
#define BACKGROUND_LAYER_h

#include <vector>

#include "../../common/TypeDefine.h"
#include "../../common/utilites/NoCopy.h"

class BackgroundTile;



class BackgroundLayer : public NoCopy<BackgroundLayer>
{
public:
                   BackgroundLayer(void);
    virtual       ~BackgroundLayer(void);

    virtual void   Draw(void) const;

    void           AddTile(BackgroundTile* tile);

    const Uint16   GetDepth(void) const;
    void           SetDepth(const Uint16 depth);

private:
    std::vector<BackgroundTile*> m_Tiles;

    Uint16                       m_Depth;
};



#endif // BACKGROUND_LAYER_h
