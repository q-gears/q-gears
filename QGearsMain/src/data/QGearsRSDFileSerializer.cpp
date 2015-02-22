/*
-----------------------------------------------------------------------------
The MIT License (MIT)

Copyright (c) 2013-08-16 Tobias Peters <tobias.peters@kreativeffekt.at>

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
#include "data/QGearsRSDFileSerializer.h"

#include <OgreException.h>
#include <OgreLogManager.h>
#include <OgreStringConverter.h>

namespace QGears
{
    typedef Ogre::StringConverter   StringConverter;

    //---------------------------------------------------------------------
    const String RSDFileSerializer::TAG_HEADER          ("@RSD");
    const String RSDFileSerializer::TAG_POLYGON         ("PLY" );
    const String RSDFileSerializer::TAG_MATERIAL        ("MAT" );
    const String RSDFileSerializer::TAG_GROUP           ("GRP" );
    const String RSDFileSerializer::TAG_TEXTURE_COUNT   ("NTEX");
    const String RSDFileSerializer::TAG_TEXTURE_NAME    ("TEX" );
    const String RSDFileSerializer::PARSE_DELIMITER     ("[]=" );

    //---------------------------------------------------------------------
    RSDFileSerializer::RSDFileSerializer()
    {
    }

    //---------------------------------------------------------------------
    RSDFileSerializer::~RSDFileSerializer()
    {
    }

    //---------------------------------------------------------------------
    void
    RSDFileSerializer::readFileHeader( Ogre::DataStreamPtr &stream )
    {
        String line( getLine( stream ) );
        if( !Ogre::StringUtil::startsWith( line, TAG_HEADER, false ) )
        {
            Ogre::LogManager::getSingleton().stream() << line;
            OGRE_EXCEPT(Ogre::Exception::ERR_INVALIDPARAMS
                ,"First line in RSD File should start with " + TAG_HEADER
                ,"RSDFileSerializer::readFileHeader" );
        }
    }

    //---------------------------------------------------------------------
    void
    RSDFileSerializer::parseLine( const String &line, RSDFile* pDest )
    {
        if( line.empty() ) return;

        Ogre::StringVector parts( Ogre::StringUtil::split( line, PARSE_DELIMITER ));
        if( parts.size() < 2 )
        {
            Ogre::LogManager::getSingleton().stream() << "line is: '" << line << "'";
            OGRE_EXCEPT(Ogre::Exception::ERR_INVALIDPARAMS
                ,"Lines should contain a variable name and an assignment"
                ,"RSDFileSerializer::parseLine" );
        }

        if( parts[0] == TAG_POLYGON )
        {
            pDest->setPolygonName( parts[1] );
        }
        else if ( parts[0] == TAG_MATERIAL )
        {
            pDest->setMaterialName( parts[1] );
        }
        else if ( parts[0] == TAG_GROUP )
        {
            pDest->setGroupName( parts[1] );
        }
        else if ( parts[0] == TAG_TEXTURE_COUNT )
        {
            if( m_has_texture_count )
            {
                Ogre::LogManager::getSingleton().stream() << line;
                OGRE_EXCEPT(Ogre::Exception::ERR_INVALIDPARAMS
                    ,"texture count already set"
                    ,"RSDFileSerializer::parseLine" );
            }
            m_texture_count = StringConverter::parseUnsignedInt( parts.back() );
            pDest->getTextureNames().resize( m_texture_count, "" );
            m_has_texture_count = true;
        }
        else if ( parts[0] == TAG_TEXTURE_NAME )
        {
            if( !m_has_texture_count )
            {
                Ogre::LogManager::getSingleton().stream() << line;
                OGRE_EXCEPT(Ogre::Exception::ERR_INVALIDPARAMS
                    ,"can't set texture names if texture count is not set"
                    ,"RSDFileSerializer::parseLine" );
            }
            if( parts.size() != 3 )
            {
                Ogre::LogManager::getSingleton().stream() << line;
                OGRE_EXCEPT(Ogre::Exception::ERR_INVALIDPARAMS
                    ,"can't set texture name unknown format, array assignment "
                     "should look like " + TAG_TEXTURE_NAME + "[0]=filename.ext"
                    ,"RSDFileSerializer::parseLine" );
            }
            size_t texture_index( StringConverter::parseUnsignedInt( parts[1] ) );
            String texture_name( parts[2] );
            if( texture_index >= m_texture_count )
            {
                Ogre::LogManager::getSingleton().stream()
                    << "Warning: Index Out of Bounds in texture name array '"
                    << line << "' RSDFileSerializer::parseLine";
            }
            pDest->getTextureNames()[texture_index] = texture_name;
        }
    }

    //---------------------------------------------------------------------
    void
    RSDFileSerializer::importRSDFile( Ogre::DataStreamPtr &stream
                                     ,RSDFile* pDest )
    {
        m_texture_count = 0;
        m_has_texture_count = false;
        readFileHeader( stream );
        while( !stream->eof() )
        {
            parseLine( getLine( stream ), pDest );
        }
        if( !m_has_texture_count )
        {
            Ogre::LogManager::getSingleton().stream()
                << "Warning: no texture count was read"
                << " RSDFileSerializer::importRSDFile";
        }
    }

    //---------------------------------------------------------------------
}
