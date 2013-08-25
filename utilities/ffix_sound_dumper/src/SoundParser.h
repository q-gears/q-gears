#ifndef SOUND_PARSER_H
#define SOUND_PARSER_H

#include <Ogre.h>

#include "common/File.h"
#include "common/TypeDefine.h"



class SoundParser
{
public:
    SoundParser();
    virtual ~SoundParser();

    void Update();

    // debug routines
    void DumpSequenceData( const Ogre::String& file );



private:
    void UpdateSpu();
};



extern SoundParser *SOUND_PARSER;



#endif // SOUND_PARSER_H
