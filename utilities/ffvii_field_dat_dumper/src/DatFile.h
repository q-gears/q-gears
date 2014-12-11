#ifndef DATFILE_H
#define DATFILE_H

#include "../../common/Logger.h"
#include "common/LzsFile.h"
#include "../../common/Surface.h"
#include "MimFile.h"

enum eOpcodes
{
    RET = 0x0,
    REQ = 0x01,
    REQSW = 0x02,
    REQEW = 0x03,
    RETTO = 0x07,
    JOIN = 0x08,
    SPLIT = 0x09,
    SPTYE = 0x0A,
    GTPYE = 0x0B,
    SPECIAL = 0x0F,
    JMPF = 0x10,
    JMPFL = 0x11,
    JMPB = 0x12,
    JMPBL = 0x13,
    IFUB = 0x14,
    IFUBL = 0x15,
    IFSW = 0x16,
    IFSWL = 0x17,
    IFUW = 0x18,
    TUTOR = 0x21,
    WAIT = 0x24,
    NFADE = 0x25,
    BLINK = 0x26,
    KAWAI = 0x28,
    WCLS = 0x2E,
    WSIZW = 0x2F,
    IFKEY = 0x30,
    IFKEYON = 0x31,
    UC = 0x33,
    WSPCL = 0x36,
    STTIM = 0x38,
    GOLDU = 0x39,
    GOLDD = 0x3A,
    CHGLD = 0x3B,
    MHMMX = 0x3E,
    HMPMAX3 = 0x3F,
    MESSAGE = 0x40,
    MPNAM = 0x43,
    ASK = 0x48,
    MENU = 0x49,
    MENU2 = 0x4A,
    BTLTB = 0x4B,
    WINDOW = 0x50,
    WMODE = 0x52,
    WREST = 0x53,
    WCLSE = 0x54,
    STITM = 0x58,
    CKITM = 0x5A,
    SMTRA = 0x5B,
    SHAKE = 0x5E,
    MAPJUMP = 0x60,
    SCRLC = 0x62,
    SCRLA = 0x63,
    SCR2D = 0x64,
    SCRCC = 0x65,
    SCR2DC = 0x66,
    SCRLW = 0x67,
    SCR2DL = 0x68,
    VWOFT = 0x6A,
    FADE = 0x6B,
    FADEW = 0x6C,
    IDLCK = 0x6D,
    LSTMP = 0x6E,
    BATTLE = 0x70,
    BTLON = 0x71,
    BTLMD = 0x72,
    PLUS_ = 0x76, // PLUS!
    PLUS2_ = 0x77, // PLUS2!
    MINUS_ = 0x78, // MINUS!
    MINUS2_= 0x79, // MINUS2!
    INC_= 0x7A, //  INC!
    TALKON = 0x7E,
    SETBYTE = 0x80,
    SETWORD = 0x81,
    BITON = 0x82,
    BITOFF = 0x83,
    PLUS = 0x85,
    MINUS = 0x87,
    MUL = 0x89,
    MOD = 0x8D,
    AND = 0x8F,
    AND2 = 0x90,
    OR = 0x91,
    OR2 = 0x92,
    INC = 0x95,
    DEC = 0x97,
    RANDOM = 0x99,
    PC = 0xA0,
    opCodeCHAR = 0xA1,
    DFANM = 0xA2,
    ANIME1 = 0xA3,
    VISI = 0xA4,
    XYZI = 0xA5,
    XYI = 0xA6,
    MOVE = 0xA8,
    CMOVE = 0xA9,
    MOVA = 0xAA,
    TURA = 0xAB,
    ANIMW = 0xAC,
    FMOVE = 0xAD,
    ANIME2 = 0xAE,
    ANIM_1 = 0xAF, // ANIM!1
    CANM_1 = 0xB1, // CANM!1 
    MSPED = 0xB2,
    DIR = 0xB3,
    TURNGEN = 0xB4,
    TURN = 0xB5,
    DIRA = 0xB6,
    GETDIR = 0xB7,
    GETAXY = 0xB8,
    GETAI = 0xB9,
    ANIM_2 = 0xBA, // ANIM!2
    CANIM2 = 0xBB,
    CANM_2 = 0xBC, // CANM!2
    ASPED = 0xBD,
    CC = 0xBF,
    JUMP = 0xC0,
    AXYZI = 0xC1,
    LADER = 0xC2,
    OFST = 0xC3,
    OFSTW = 0xC4,
    TALKR = 0xC5,
    CLIDR = 0xC6,
    SOLID = 0xC7,
    PRTYP = 0xC8,
    PRTYM = 0xC9,
    PRTYE = 0xCA,
    MMBUD = 0xCD,
    MMBLK = 0xCE,
    LINE = 0xD0,
    LINON = 0xD1,
    MPJPO = 0xD2,
    SLINE = 0xD3,
    PMJMP = 0xD8,
    AKAO2 = 0xDA,
    ANIMB = 0xDD,
    TURNW = 0xDE,
    BGON = 0xE0,
    BGOFF = 0xE1,
    BGCLR = 0xE4,
    STPAL = 0xE5,
    LDPAL = 0xE6,
    CPPAL = 0xE7,
    ADPAL = 0xE9,
    MPPAL2 = 0xEA,
    STPLS = 0xEB,
    LDPLS = 0xEC,
    RTPAL2 = 0xEE,
    ADPAL2 = 0xEF,
    MUSIC = 0xF0,
    SOUND = 0xF1,
    AKAO = 0xF2,
    MULCK = 0xF5,
    BMUSC = 0xF6,
    PMVIE = 0xF8,
    MOVIE = 0xF9,
    MVIEF = 0xFA,
    MVCAM = 0xFB,
    FMUSC = 0xFC,
    CHMST = 0xFE
};

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
