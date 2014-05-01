/*
-----------------------------------------------------------------------------
The MIT License (MIT)

Copyright (c) 2013-09-22 Tobias Peters <tobias.peters@kreativeffekt.at>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
-----------------------------------------------------------------------------
*/
#include "data/QGearsLGPArchiveSerializer.h"

#include <OgreLogManager.h>
#include <OgreException.h>

namespace QGears
{
    //---------------------------------------------------------------------
    LGPArchiveSerializer::LGPArchiveSerializer() :
        Serializer()
    {
    }

    //---------------------------------------------------------------------
    LGPArchiveSerializer::~LGPArchiveSerializer()
    {
    }

    //---------------------------------------------------------------------
    void
    LGPArchiveSerializer::importLGPArchive( Ogre::DataStreamPtr &stream
                                           ,LGPArchive* pDest )
    {
        readFileHeader( stream );
        uint32 file_count( 0 );
        readInt( stream, file_count );
        FileList& files( pDest->getFiles() );
        readVector( stream, files, file_count );

        FileList::iterator it( files.begin() );
        FileList::const_iterator it_end( files.end() );
        while( it != it_end )
        {
            stream->seek( it->file_offset );
            it->data_file_name = readString( stream, FILE_NAME_LENGTH );
            readInt( stream, it->data_size );
            it->data_offset = stream->tell();
            ++it;
        }
    }

    //---------------------------------------------------------------------
    void
    LGPArchiveSerializer::readFileHeader( Ogre::DataStreamPtr &stream )
    {
        stream->skip( 2 ); // unused
        String magic_string( readString( stream, MAGIC_STRING_LENGTH ) );
    }

    //---------------------------------------------------------------------
    void
    LGPArchiveSerializer::readObject( Ogre::DataStreamPtr &stream
                                     ,FileEntry& file_entry )
    {
        file_entry.file_name = readString( stream, FILE_NAME_LENGTH );
        readInt( stream, file_entry.file_offset );
        stream->read( &file_entry.unknown1, sizeof( file_entry.unknown1 ) );
        readShort( stream, file_entry.unknown2 );

        if(   (file_entry.unknown1 != 14 && file_entry.unknown1 != 11 )
           || file_entry.unknown2 != 0 )
        {
            Ogre::LogManager::getSingleton().stream()
                << "file_name: " << file_entry.file_name
                << " file_offset: " << file_entry.file_offset
                << " unknown1: " << (uint16)file_entry.unknown1
                << " unknown2: " << file_entry.unknown2
                ;
        }
    }

    //---------------------------------------------------------------------
}
