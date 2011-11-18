// $Id$

#ifndef BACKGROUND_TILE_h
#define BACKGROUND_TILE_h

#include "../../common/TypeDefine.h"
#include "../../common/display/actor/Actor.h"
#include "../../common/display/3dTypes.h"



class BackgroundTile : public Actor
{
public:
                   BackgroundTile(const Uint8 size, const Uint32 texture_id, const BlendMode& blending, const Sint16 x, const Sint16 y);
    virtual       ~BackgroundTile(void);

    virtual void   Input(const InputEvent& input);
    virtual void   Update(const Uint32 delta_time);
    virtual void   Draw(void) const;

    void           SetDraw(const bool draw);

private:
    Uint32            m_TextureId;

    Sint16            m_X;
    Sint16            m_Y;

    Geometry          m_Poly;

    bool              m_Draw;
};



#endif // BACKGROUND_TILE_h
