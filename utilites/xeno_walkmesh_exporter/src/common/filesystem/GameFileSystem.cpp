// $Id: GameFileSystem.cpp 103 2006-11-26 07:19:38Z crazy_otaku $

#include "GameFileSystem.h"



GameFileSystem* GAMEFILESYSTEM = NULL;



GameFileSystem::GameFileSystem():
    mFileDriver("./data")
//    mFileDriver("/dev/cdrom")
{
}



GameFileSystem::~GameFileSystem()
{
}



unsigned int
GameFileSystem::GetFileSize(const RString &path)
{
    return mFileDriver.GetFileSize(path);
}



bool
GameFileSystem::ReadFile(const RString &path, void* buffer, const unsigned int start, const unsigned int length)
{
    return mFileDriver.ReadFile(path, buffer, start, length);
}
