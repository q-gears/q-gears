// $Id: GameFileSystem.h 103 2006-11-26 07:19:38Z crazy_otaku $

#ifndef GAMEFILESYSTEM_H
#define GAMEFILESYSTEM_H

#include <vector>

#include "FileSystem.h"
#include "driver/RealFileDriver.h"
#include "../utilites/StdString.h"



class GameFileSystem : public FileSystem
{
public:
                         GameFileSystem();
    virtual             ~GameFileSystem();

    virtual unsigned int GetFileSize(const RString &path);
    virtual bool         ReadFile(const RString &path, void* buffer, const unsigned int start, const unsigned int length);

private:
    RealFileDriver mFileDriver;
};



extern GameFileSystem* GAMEFILESYSTEM;



#endif // GAMEFILESYSTEM_H
