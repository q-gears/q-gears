/*
-----------------------------------------------------------------------------
The MIT License (MIT)

Copyright (c) 2013-08-10 Tobias Peters <tobias.peters@kreativeffekt.at>

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
#include "data/QGearsHRCFileSerializer.h"

#include <OgreException.h>
#include <OgreLogManager.h>
#include <OgreStringConverter.h>

namespace QGears
{
    //---------------------------------------------------------------------
    const String HRCFileSerializer::TAG_VERSION   ( ":HEADER_BLOCK" );
    const String HRCFileSerializer::TAG_NAME      ( ":SKELETON"     );
    const String HRCFileSerializer::TAG_BONE_COUNT( ":BONES"        );

    //---------------------------------------------------------------------
    HRCFileSerializer::HRCFileSerializer()
    {
    }

    //---------------------------------------------------------------------
    HRCFileSerializer::~HRCFileSerializer()
    {
    }

    //---------------------------------------------------------------------
    template<typename ValueType>
    void
    HRCFileSerializer::readVector( Ogre::DataStreamPtr &stream
                                  ,std::vector<ValueType> &pDest
                                  ,size_t count )
    {
        pDest.clear();
        pDest.reserve( count );
        for( size_t i( count ); i--; )
        {
            ValueType in_tmp;
            readObject( stream, in_tmp );
            pDest.push_back( in_tmp );
        }
    }

    //---------------------------------------------------------------------
    void
    HRCFileSerializer::readBlock( Ogre::DataStreamPtr &stream
                                 ,Block& pDest )
    {
        String line;
        while( !stream->eof() && !(line = getLine( stream ) ).empty() )
        {
            pDest.push_back( line );
        }
    }

    //---------------------------------------------------------------------
    void
    HRCFileSerializer::readFileHeader( Ogre::DataStreamPtr &stream )
    {
        m_header.version    = 0;
        m_header.bone_count = 0;
        m_header.name       = "";

        if( stream->eof() )
        {
            OGRE_EXCEPT(Ogre::Exception::ERR_INVALIDPARAMS
            ,"Empty file"
            ,"HRCFileSerializer::readFileHeader" );
        }

        Block header_block;
        readBlock( stream, header_block );

        for( Block::const_iterator it( header_block.begin() )
            ;it != header_block.end()
            ;++it )
        {
            Ogre::StringVector parts( Ogre::StringUtil::split( *it ) );
            if( parts.size() != 2 )
            {
                Ogre::LogManager::getSingleton().stream() << *it;
                OGRE_EXCEPT(Ogre::Exception::ERR_INVALIDPARAMS
                    ,"Header directive does not have a value"
                    ,"HRCFileSerializer::readFileHeader" );
            }

            if( parts[0] == TAG_VERSION )
            {
                m_header.version = Ogre::StringConverter::parseLong( parts[1] );
            }
            else if( parts[0] == TAG_NAME )
            {
                m_header.name = parts[1];
            }
            else if( parts[0] == TAG_BONE_COUNT )
            {
                m_header.bone_count = Ogre::StringConverter::parseLong( parts[1] );
            }
        }
    }

    //---------------------------------------------------------------------
    void
    HRCFileSerializer::readObject( Ogre::DataStreamPtr &stream, Bone &pDest )
    {
        Block bone_block;
        readBlock( stream, bone_block );

        Block::const_iterator it( bone_block.begin() );
        pDest.name          = *(it++);
        pDest.parent        = *(it++);
        pDest.length = Ogre::StringConverter::parseReal(*(it++)) / HRCFile::kDownScaler;

        Ogre::StringVector rsd_list( Ogre::StringUtil::split( *it ) );
        size_t rsd_count( Ogre::StringConverter::parseUnsignedInt( rsd_list.front() ) );

        String rsd_names("");
        for( Ogre::StringVector::const_iterator it( ++rsd_list.begin() )
            ;it != rsd_list.end()
            ;++it )
        {
            pDest.rsd_names.push_back( *it );
            rsd_names += *it + " ";
        }

        if( rsd_count != pDest.rsd_names.size() )
        {
            Ogre::LogManager::getSingleton().stream()
                 << "Warning: rsd_names should have " << rsd_count
                 << " entries but got " << pDest.rsd_names.size()
                 << " instead"
                 << "\n name     : " << pDest.name
                 << "\n parent   : " << pDest.parent
                 << "\n length   : " << pDest.length
                 << "\n rsd_count: " << rsd_names
                 << "\n";
        }
    }

    //---------------------------------------------------------------------
    void
    HRCFileSerializer::importHRCFile( Ogre::DataStreamPtr &stream
                                     ,HRCFile* pDest )
    {
        readFileHeader( stream );
        if( m_header.bone_count == 0 )
        {
            m_header.bone_count = 1;
        }
        pDest->setSkeletonName( m_header.name );
        readVector( stream, pDest->getBones(), m_header.bone_count );
    }

    //---------------------------------------------------------------------
}
