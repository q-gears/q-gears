#ifndef ENEMY_FILE_H
#define ENEMY_FILE_H

#include "../../common/File.h"



class EnemyFile : public File
{
public:
    EnemyFile( const Ogre::String &file );
    EnemyFile( File* file );
    EnemyFile( File* file, const u32 &offset, const u32 &length );
    EnemyFile( u8* buffer, const u32 &offset, const u32 &length );
    virtual ~EnemyFile();

private:
    void DumpData();
};



#endif // ENEMY_FILE_H
