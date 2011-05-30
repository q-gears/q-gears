#ifndef DATFILE_H
#define DATFILE_H

#include "../../common/LzsFile.h"
#include "MimFile.h"



struct DatModelData
{
    int face_id;
    int number_of_bones;
    int number_of_parts;
    int number_of_animation;
    int global_model_id;
};



class DatFile : public LzsFile
{
public:
    DatFile( const Ogre::String& file );
    DatFile( File* file );
    DatFile( File* file, const u32 offset, const u32 length );
    DatFile( u8* buffer, const u32 offset, const u32 length );
    virtual ~DatFile();

    void DumpTextData(const Ogre::String& export_file, bool english);
    void DumpScriptData(const Ogre::String& export_file);
    void DumpWalkmeshData(const Ogre::String& export_file);
    void DumpBackground( const Ogre::String &export_file, MimFile& mim );
    static void DumpSoundOpcodesData(const Ogre::String& export_file);

    void AdvanceScript(u32 value, u32& current, u32& end);

    Ogre::String ParseVariableName(int slot, int value);
    Ogre::String ParseGetVariable(int get_slot, int get_value, bool hex = false, float fixed = 1.0f);
    Ogre::String SetVariable(int set_slot, int set_value, Ogre::String get_string);
    Ogre::String SetBitChange(int set_slot, int set_value, int get_slot, int get_value, bool on);
    Ogre::String ParseRelation(int relation, Ogre::String string1, Ogre::String string2);

    Ogre::String PaddingString();

    Ogre::String ArgumentString(int script, int number);
    Ogre::String OffsetString(int val);

private:
    std::vector<int> m_Dialogs;

    static std::vector<Ogre::String> m_SoundOpcodes;
};



#endif // DATFILE_H
