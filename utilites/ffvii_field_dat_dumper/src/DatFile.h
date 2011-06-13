#ifndef DATFILE_H
#define DATFILE_H

#include "../../common/LzsFile.h"
#include "../../common/Surface.h"
#include "MimFile.h"



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
};



class DatFile : public LzsFile
{
public:
    DatFile( const Ogre::String& file );
    DatFile( File* file );
    DatFile( File* file, const u32 offset, const u32 length );
    DatFile( u8* buffer, const u32 offset, const u32 length );
    virtual ~DatFile();

    void DumpTextData( const Ogre::String& export_file, bool english );
    void DumpScriptData( const Ogre::String& export_file );
    void DumpWalkmeshData( const Ogre::String& export_file );
    void DumpBackground( const Ogre::String &export_file, MimFile& mim );
    static void DumpSoundOpcodesData( const Ogre::String& export_file );

    void AdvanceScript( u32 value, u32& current, u32& end );

    Ogre::String ParseVariableName( int slot, int value );
    Ogre::String ParseGetVariable( int get_slot, int get_value, bool hex = false, float fixed = 1.0f );
    Ogre::String SetVariable( int set_slot, int set_value, Ogre::String get_string );
    Ogre::String SetBitChange( int set_slot, int set_value, int get_slot, int get_value, bool on );
    Ogre::String ParseRelation( int relation, Ogre::String string1, Ogre::String string2 );

    Ogre::String PaddingString();

    Ogre::String ArgumentString( int script, int number );
    Ogre::String OffsetString( int val );

    void AddTile( const u8 background, const s16 dest_x, const s16 dest_y, const u8 src_x, const u8 src_y, const u16 clut_x, const u16 clut_y, const u8 bpp, const u8 page_x, const u8 page_y, const u16 depth, const u8 blending, const u8 animation, const u8 animation_index );

private:
    std::vector< int > m_Dialogs;

    static std::vector< Ogre::String > m_SoundOpcodes;
};



#endif // DATFILE_H
