// $Id: RealFileSystem.cpp 93 2006-11-12 13:49:02Z einherjar $

#include "RealFileSystem.h"
#include "../utilites/Logger.h"

#include <stdio.h>



RealFileSystem *REALFILESYSTEM = NULL;



RealFileSystem::RealFileSystem(const RString &root):
  mRealFileDriver(root)
{
}



RealFileSystem::~RealFileSystem()
{
}



unsigned int
RealFileSystem::GetFileSize(const RString &path)
{
    return mRealFileDriver.GetFileSize(path);
}



bool
RealFileSystem::ReadFile(const RString &path, void* buffer, const unsigned int start, const unsigned int length)
{
    return mRealFileDriver.ReadFile(path, buffer, start, length);
}



bool
RealFileSystem::WriteFile(const RString &path, const void* buffer, const unsigned int length)
{
    return mRealFileDriver.WriteFile(path, buffer, length);
}



bool
RealFileSystem::WriteNewFile(const RString &path, const void* buffer, unsigned int length)
{
    return mRealFileDriver.WriteNewFile(path, buffer, length);
}



bool
RealFileSystem::RemoveFile(const RString &path)
{
    return mRealFileDriver.RemoveFile(path);
}
