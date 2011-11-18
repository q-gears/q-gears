// $Id$

#ifndef BACKGROUND_ANIMATION_h
#define BACKGROUND_ANIMATION_h

#include <vector>

#include "../../common/TypeDefine.h"
#include "../../common/display/actor/Actor.h"

class BackgroundTile;



class BackgroundAnimation : public Actor
{
public:
                   BackgroundAnimation(void);
    virtual       ~BackgroundAnimation(void);

    virtual void   Input(const InputEvent& input);
    virtual void   Update(const Uint32 delta_time);
    virtual void   Draw(void) const;

    void           AddTile(BackgroundTile* tile, const Uint8 index);
    void           SetTileDraw(const Uint8 index, const bool draw);
    void           UnsetAllDraw(void);

private:
    typedef std::pair<BackgroundTile*, Uint8> TileWithIndex;
    std::vector<TileWithIndex> m_Tiles;
};



#endif // BACKGROUND_ANIMATION_h
