// $Id$

#ifndef BACKGROUND_2D_h
#define BACKGROUND_2D_h

#include <Ogre.h>
#include <vector>

#include "BackgroundTile.h"
#include "../core/Actor.h"



class Background2D : public Actor
{
public:
                  Background2D(void);
    virtual      ~Background2D(void);

    virtual void  Input(const Event& input);
    virtual void  Update(const float delta_time);

    void          SetTexture(const Ogre::String& name);
    void          AddTileBottom(const int x, const int y, const int width, const int height, const int src_x, const int src_y);
    void          AddTileFixed(const int x, const int y, const int width, const int height, const int src_x, const int src_y, const int depth, const int group, const int index);

private:
    std::vector<BackgroundTile*> m_LayerBottom;
    std::vector<BackgroundTile*> m_LayerFixed;
};



#endif // BACKGROUND_2D_h
