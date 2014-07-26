#ifndef DATFILE_H
#define DATFILE_H

#include "../../common/Logger.h"
#include "common/LzsFile.h"
#include "../../common/Surface.h"
#include "MimFile.h"



struct FieldKeyFrame
{
    FieldKeyFrame():
        time( 0 ),
        blank( false ),
        animation_id( 0 ),
        animation_frame( 0 ),
        clut_y( -1 ),
        clut_start( 0 ),
        clut_width( 0 ),
        mod_type( "add" ),
        mod_r( 0 ),
        mod_g( 0 ),
        mod_b( 0 )
    {
    }

    float time;
    bool blank;

    int animation_id;
    int animation_frame;

    int clut_y;
    int clut_start;
    int clut_width;
    Ogre::String mod_type;
    float mod_r;
    float mod_g;
    float mod_b;
};

struct FiledAnimation
{
    Ogre::String name;
    float time;
    std::vector< FieldKeyFrame > keyframes;
};

struct Field
{
    Ogre::String name;
    float scale;
    int tex_width;
    int tex_height;
    std::vector< FiledAnimation > animations;
};



struct DatModelData
{
    int face_id;
    int number_of_bones;
    int number_of_parts;
    int number_of_animation;
    int global_model_id;
};



struct SurfaceTexData
{
    Surface* surface;
    u16 page_x;
    u16 page_y;
    u16 clut_x;
    u16 clut_y;
    u8 bpp;

    int clut_start;
    int clut_width;
    Ogre::String mod_type;
    float mod_r;
    float mod_g;
    float mod_b;
};



struct KeyFrame
{
    float time;
    u8 src_x;
    u8 src_y;
    u16 clut_x;
    u16 clut_y;
    u8 bpp;
    u8 page_x;
    u8 page_y;

    int clut_start;
    int clut_width;
    Ogre::String mod_type;
    float mod_r;
    float mod_g;
    float mod_b;
};

struct Animation
{
    float time;
    Ogre::String name;
    std::vector< KeyFrame > keyframes;
};



struct Tile
{
    Tile():
        animated( false )
    {
    }

    bool animated;
    u8 background;
    s16 dest_x;
    s16 dest_y;
    u8 src_x;
    u8 src_y;
    u16 clut_x;
    u16 clut_y;
    u8 bpp;
    u8 page_x;
    u8 page_y;
    float depth;
    u8 blending;
    u8 animation_id;
    u8 animation_frame;
    std::vector< Animation > animations;
};



struct AddedTile
{
    u8 background;
    u8 src_x;
    u8 src_y;
    u16 clut_x;
    u16 clut_y;
    u8 bpp;
    u8 page_x;
    u8 page_y;

    int clut_start;
    int clut_width;
    Ogre::String mod_type;
    float mod_r;
    float mod_g;
    float mod_b;

    float x;
    float y;
    float width;
    float height;
};



class DatFile : public LzsFile
{
public:
    DatFile( const Ogre::String& file );
    DatFile( File* file );
    DatFile( File* file, const u32 offset, const u32 length );
    DatFile( u8* buffer, const u32 offset, const u32 length );
    virtual ~DatFile();

    void DumpText( const Ogre::String& export_path, const Field& field, bool english );
    void DumpScript( const Ogre::String& export_path, const Field& field );
    void DumpWalkmesh( const Ogre::String& export_path, const Field& field );
    void GetCamera( Ogre::Vector3& position, Ogre::Quaternion& orientation, Ogre::Degree& fov, const Field& field );
    void GetScreenRange( int& min_x, int& min_y, int& max_x, int& max_y );
    void DumpBackground( const Ogre::String& export_path, const Field& field, MimFile& mim );
    void DumpTriggersMovements( const Ogre::String& export_path, const Field& field );
    static void DumpSoundOpcodesData( const Ogre::String& export_file );

    void AdvanceScript( u32 value, u32& current, u32& end );

    Ogre::String ParseVariableName( int slot, int value );
    Ogre::String ParseGetVariable( int get_slot, int get_value, unsigned int hex = 0, float fixed = 1.0f );
    Ogre::String SetVariable( int set_slot, int set_value, Ogre::String get_string );
    Ogre::String SetBitChange( int set_slot, int set_value, int get_slot, int get_value, bool on );
    Ogre::String ParseRelation( int relation, Ogre::String string1, Ogre::String string2 );

    Ogre::String PaddingString();

    Ogre::String ArgumentString( int script, int number );
    Ogre::String OffsetString( int val );

    bool TileCompare( const Tile& tile, const FieldKeyFrame& keyframe, MimFile& mim );
    void AddTile( const Tile& tile, MimFile& mim, Logger* export_text );
    AddedTile AddTileTex( const u8 background, const u8 src_x, const u8 src_y, const u16 clut_x, const u16 clut_y, const u8 bpp, const u8 page_x, const u8 page_y, MimFile& mim, const int clut_start, const int clut_width, const Ogre::String& mod_type, const float mod_r, const float mod_g, const float mod_b );

private:
    std::vector< int > m_Dialogs;

    static std::vector< Ogre::String > m_SoundOpcodes;

    std::vector< SurfaceTexData > m_Surfaces;
    Surface* full_image;
    int x_32;
    int y_32;
    int x_16;
    int y_16;
    int n_16;

    std::vector< AddedTile > m_AddedTiles;
};



#endif // DATFILE_H
