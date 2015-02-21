#include <cassert>
#include <string.h>

#include "common/File.h"
#include "common/FileSystem.h"
#include "core/Logger.h"



//-------------------------------------------------------------------------
File::File(const Ogre::String& file):
  m_FileName(file),
  m_Buffer(nullptr),
  m_BufferSize(0)
{
    LOG_TRIVIAL("Loading file: " + m_FileName + "\n");
    m_BufferSize = FileSystem::GetFileSize(m_FileName);

    m_Buffer = (u8*)malloc(sizeof(u8) * m_BufferSize);

    if (!FileSystem::ReadFile(m_FileName, m_Buffer, 0, m_BufferSize))
    {
        LOG_TRIVIAL("Warning: " + m_FileName + " not found!\n");
    }
}

//-------------------------------------------------------------------------
File::File(const File* pFile, u32 offset, u32 length):
  m_Buffer(nullptr),
  m_BufferSize(length)
{
    assert(pFile != nullptr);

    m_FileName = pFile->GetFileName();

    m_Buffer = (u8 *)malloc(sizeof(u8) * m_BufferSize);
    pFile->GetFileBuffer(m_Buffer, offset, m_BufferSize);
}

//-------------------------------------------------------------------------
File::File(const u8* pBuffer, u32 offset, u32 length):
  m_FileName("BUFFER"),
  m_Buffer(nullptr),
  m_BufferSize(length)
{
    assert(pBuffer != nullptr);

    m_Buffer = (u8*)malloc(sizeof(u8) * m_BufferSize);
    memcpy(m_Buffer, pBuffer + offset, m_BufferSize);
}

//-------------------------------------------------------------------------
File::File(const File* pFile)
{
    assert(pFile != nullptr);

    m_BufferSize = pFile->GetFileSize();
    m_FileName   = pFile->GetFileName();

    m_Buffer = (u8*)malloc(sizeof(u8) * m_BufferSize);
    pFile->GetFileBuffer(m_Buffer, 0, m_BufferSize);
}

//-------------------------------------------------------------------------
File::~File()
{
    free(m_Buffer);
}

//-------------------------------------------------------------------------
void
File::WriteFile(const Ogre::String& file) const
{
  FileSystem::WriteNewFile(file, m_Buffer, m_BufferSize);
}

//-------------------------------------------------------------------------
const Ogre::String&
File::GetFileName() const
{
    return m_FileName;
}

//-------------------------------------------------------------------------
u32
File::GetFileSize() const
{
    return m_BufferSize;
}

//-------------------------------------------------------------------------
void
File::GetFileBuffer(u8* pBuffer, const u32 &start, const u32 &length) const
{
    memcpy(pBuffer, m_Buffer + start, length);
}

//-------------------------------------------------------------------------
u8
File::GetU8(u32 offset) const
{
    return *(m_Buffer + offset);
}

//-------------------------------------------------------------------------
u16
File::GetU16LE(u32 offset) const
{
    return (m_Buffer + offset)[0] | ((m_Buffer + offset)[1] << 8);
}

//-------------------------------------------------------------------------
u32
File::GetU32LE(u32 offset) const
{
    return (m_Buffer + offset)[0] | ((m_Buffer + offset)[1] << 8) | ((m_Buffer + offset)[2] << 16) | ((m_Buffer + offset)[3] << 24);
}

//-------------------------------------------------------------------------
u8
File::readU8()
{
    return GetU8( m_offset++ );
}

//-------------------------------------------------------------------------
u16
File::readU16LE()
{
    u16 data( GetU16LE(m_offset) );
    m_offset += 2;
    return data;
}

//-------------------------------------------------------------------------
u32
File::readU32LE()
{
    u32 data( GetU32LE(m_offset) );
    m_offset += 4;
    return data;
}

//-------------------------------------------------------------------------
