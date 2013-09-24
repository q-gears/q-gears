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
#include "data/QGearsLGPArchive.h"

#include "OgreThreadDefines.h"

#include "common/QGearsStringUtil.h"
#include "data/QGearsLGPArchiveSerializer.h"

namespace QGears
{
    //-------------------------------------------------------------------------
    LGPArchive::LGPArchive( const String &name, const String &archType ) :
        Ogre::Archive( name, archType )
    {
    }

    //-------------------------------------------------------------------------
    LGPArchive::~LGPArchive()
    {
        unload();
    }

    //-------------------------------------------------------------------------
    void
    LGPArchive::load()
    {
        std::ifstream *ifs( OGRE_NEW_T( std::ifstream, Ogre::MEMCATEGORY_GENERAL )( mName.c_str(), std::ifstream::binary ) );
        m_lgp_file.bind( OGRE_NEW Ogre::FileStreamDataStream( ifs ) );
        LGPArchiveSerializer lgp_archive_serializer;
        lgp_archive_serializer.importLGPArchive( m_lgp_file, this );

        FileList::const_iterator it( m_files.begin() ), it_end( m_files.end() );
        while( it != it_end )
        {
            Ogre::FileInfo file_info;
            file_info.archive = this;
            file_info.filename = it->file_name;
            StringUtil::splitFilename( it->file_name, file_info.basename, file_info.path );
            file_info.uncompressedSize = it->data_size;
            file_info.compressedSize = file_info.uncompressedSize;
            m_file_infos.push_back( file_info );
            ++it;
        }

        // writing not implemented
        mReadOnly = true;
    }

    //-------------------------------------------------------------------------
    void
    LGPArchive::unload()
    {
        m_files.clear();
        m_lgp_file.setNull();
        m_file_infos.clear();
    }

    //-------------------------------------------------------------------------
    Ogre::DataStreamPtr
    LGPArchive::open( const String& filename, bool readOnly ) const
    {
        Ogre::MemoryDataStream* buffer( NULL );
        if( !m_lgp_file.isNull() )
        {
            FileList::const_iterator it( m_files.begin() );
            FileList::const_iterator it_end( m_files.end() );
            while( it != it_end )
            {
                if( it->file_name == filename )
                {
                    m_lgp_file->seek( it->data_offset );
                    size_t length( it->data_size );
                    buffer = new Ogre::MemoryDataStream( length );
                    m_lgp_file->read( buffer->getPtr(), length );
                    break;
                }
                ++it;
            }
        }
        return Ogre::DataStreamPtr( buffer );
    }

    //-------------------------------------------------------------------------
    Ogre::DataStreamPtr
    LGPArchive::create( const String& filename ) const
    {
		OGRE_EXCEPT(Ogre::Exception::ERR_NOT_IMPLEMENTED,
			"Modification of lgp archives is not supported",
			"LGPArchive::create");
    }

    //-------------------------------------------------------------------------
    void
    LGPArchive::remove(const String& filename) const
    {
    }

    //-------------------------------------------------------------------------
    Ogre::StringVectorPtr
    LGPArchive::list( bool recursive, bool dirs )
    {
        //OGRE_LOCK_AUTO_MUTEX
        Ogre::StringVector* file_names( OGRE_NEW_T( Ogre::StringVector, Ogre::MEMCATEGORY_GENERAL)() );
        FileList::const_iterator it( m_files.begin() );
        FileList::const_iterator it_end( m_files.end() );
        while( it != it_end )
        {
            file_names->push_back( it->file_name );
            ++it;
        }
        return Ogre::StringVectorPtr( file_names, Ogre::SPFM_DELETE_T );
    }

    //-------------------------------------------------------------------------
    Ogre::FileInfoListPtr
    LGPArchive::listFileInfo( bool recursive, bool dirs )
    {
        //OGRE_LOCK_AUTO_MUTEX
        return Ogre::FileInfoListPtr( OGRE_NEW_T( Ogre::FileInfoList, Ogre::MEMCATEGORY_GENERAL )( m_file_infos ), Ogre::SPFM_DELETE_T );
    }

    //-------------------------------------------------------------------------
    Ogre::StringVectorPtr
    LGPArchive::find( const String& pattern, bool recursive, bool dirs )
    {
        //OGRE_LOCK_AUTO_MUTEX
        Ogre::StringVector* file_names( OGRE_NEW_T( Ogre::StringVector, Ogre::MEMCATEGORY_GENERAL)() );

        Ogre::FileInfoListPtr found_infos( findFileInfo( pattern, recursive, dirs ) );
        Ogre::FileInfoList::const_iterator it( found_infos->begin() ), it_end( found_infos->end() );
        while( it != it_end )
        {
            file_names->push_back( it->filename );
            ++it;
        }

        return Ogre::StringVectorPtr( file_names, Ogre::SPFM_DELETE_T );
    }

    //-------------------------------------------------------------------------
    Ogre::FileInfoListPtr
    LGPArchive::findFileInfo( const String& pattern, bool recursive, bool dirs ) const
    {
        //OGRE_LOCK_AUTO_MUTEX
        Ogre::FileInfoList* file_infos( OGRE_NEW_T( Ogre::FileInfoList, Ogre::MEMCATEGORY_GENERAL)() );
        // If pattern contains a directory name, do a full match
        bool full_match = (pattern.find ('/') != String::npos) ||
                          (pattern.find ('\\') != String::npos);

        Ogre::FileInfoList::const_iterator it( m_file_infos.begin() ), it_end( m_file_infos.end() );
        while( it != it_end )
        {
            const String& file_name( full_match ? it->filename : it->basename );
            if ( StringUtil::match( file_name, pattern, isCaseSensitive() ) )
            {
                file_infos->push_back( *it );
            }
            ++it;
        }

        return Ogre::FileInfoListPtr( file_infos, Ogre::SPFM_DELETE_T );
    }

    //-------------------------------------------------------------------------
    bool
    LGPArchive::exists( const String& filename )
    {
        FileList::const_iterator it( m_files.begin() );
        FileList::const_iterator it_end( m_files.end() );
        while( it != it_end )
        {
            if( it->file_name == filename ) return true;
            ++it;
        }
        return false;
    }

    //-------------------------------------------------------------------------
    time_t
    LGPArchive::getModifiedTime( const String& filename )
    {
		struct stat tagStat;
		bool ret = (stat(mName.c_str(), &tagStat) == 0);

		if (ret)
		{
			return tagStat.st_mtime;
		}
		else
		{
			return 0;
		}
    }

    //-------------------------------------------------------------------------
    LGPArchive::FileList&
    LGPArchive::getFiles( void )
    {
        return m_files;
    }

    //-------------------------------------------------------------------------
}
