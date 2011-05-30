#ifndef ScriptFILE_H
#define ScriptFILE_H

#include "../../common/File.h"



struct StackItem
{
    u32 value_int;
    Ogre::String value_string;
};



class ScriptFile : public File
{
public:
    ScriptFile(const Ogre::String& file);
    ScriptFile(File* pFile);
    ScriptFile(File* pFile, u32 offset, u32 length);
    ScriptFile(u8* pBuffer, u32 offset, u32 length);
    virtual ~ScriptFile();

    void DumpScripts();
    void StackOpcodeParse();
    u32  StackOpcode80Parse( u32 stack_opcode );
    Ogre::String LoadVariable( const StackItem& item );
    Ogre::String GetStringFromStack( int position = -1 );
    Ogre::String StoreVariableByStack( const Ogre::String& value );
    Ogre::String Get8Variable();
    Ogre::String Get16Variable();
    Ogre::String Get24Variable();
    void AdvanceScript( u32 value, u32 jump = 0 );
};



#endif // ScriptFILE_H
