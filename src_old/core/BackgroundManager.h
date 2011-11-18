// $Id$

#ifndef BACKGROUND_MANAGER_h
#define BACKGROUND_MANAGER_h

#include "../../common/display/3dTypes.h"
#include "../../common/input/InputFilter.h"
#include "../../common/utilites/NoCopy.h"

#include "MimFile.h"

class BackgroundAnimation;
class BackgroundLayer;
class BackgroundTile;
class FieldModule;



struct SurfaceTexData
{
    Surface* surface;
    Uint16   page_x;
    Uint16   page_y;
    Uint16   clut_x;
    Uint16   clut_y;
    Uint8    bpp;
};



class BackgroundManager : public NoCopy<BackgroundManager>
{
public:
    explicit BackgroundManager(FieldModule* field_module);
    virtual ~BackgroundManager(void);

    void     Clear(void);
    void     DrawBackground(const Uint16 depth_start, const Uint16 depth_end) const;
    bool     Input(const InputEvent& input);
    void     Update(const Uint32 delta_time);

    void     LoadBackground(const RString& name);
    void     AddTile(const Uint8  background,
                     const Sint16 dest_x,
                     const Sint16 dest_y,
                     const Uint8  src_x,
                     const Uint8  src_y,
                     const Uint16 clut_x,
                     const Uint16 clut_y,
                     const Uint8  bpp,
                     const Uint8  page_x,
                     const Uint8  page_y,
                     const Uint16 depth,
                     const Uint8  blending,
                     const Uint8  animation,
                     const Uint8  animation_index);
    void     UnloadBackground(void);

    void     BackgroundClear(const Uint8 group);
    void     BackgroundOn(const Uint8 group, const Uint8 index);
    void     BackgroundOff(const Uint8 group, const Uint8 index);
    void     BackgroundDepth(const Uint8 background_id, const Uint16 depth);

private:
    FieldModule*                   m_FieldModule;  /**< @brief feed back to field module */

    MimFile*                       m_File;
    std::vector<SurfaceTexData>    m_Surfaces;

    struct Tile
    {
        Uint32 x;
        Uint32 y;
        Uint32 width;
        Uint32 height;
        Uint32 src_x;
        Uint32 src_y;
        Uint16 depth;
        Uint32 group;
        Uint32 index;
    };

    std::vector<BackgroundTile*>   m_1stBackground;
    std::vector<BackgroundLayer*>  m_2ndBackground;
    BackgroundLayer*               m_3rdBackground;
    BackgroundLayer*               m_4thBackground;
    std::vector<Tile>              m_1st;
    std::vector<Tile>              m_2nd;
    std::vector<Tile>              m_3rd;
    std::vector<Tile>              m_4th;

    typedef std::pair<BackgroundAnimation*, Uint8> Animation;
    std::vector<Animation>         m_BackgroundAnimation;



    // debug
    bool                           m_ShowBackground;
};



#endif // BACKGROUND_MANAGER_h
