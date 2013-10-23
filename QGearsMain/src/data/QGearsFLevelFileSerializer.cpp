/*
-----------------------------------------------------------------------------
The MIT License (MIT)

Copyright (c) 2013-08-24 Tobias Peters <tobias.peters@kreativeffekt.at>

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
#include "data/QGearsFLevelFileSerializer.h"

#include <OgreLogManager.h>
#include <OgreException.h>

#include "FF7Common.h"
#include "common/QGearsStringUtil.h"

#include "data/QGearsBackgroundFileManager.h"
#include "data/QGearsBackgroundFileSerializer.h"
#include "data/QGearsCameraMatrixFileManager.h"
#include "data/QGearsCameraMatrixFileSerializer.h"
#include "data/FF7ModelListFileManager.h"
#include "data/FF7ModelListFileSerializer.h"
#include "data/QGearsPaletteFileManager.h"
#include "data/QGearsPaletteFileSerializer.h"
#include "map/QGearsWalkmeshFileManager.h"
#include "map/FF7WalkmeshFileSerializer.h"

namespace QGears
{
    // TODO: move flevel stuff to ff7 as it is ff7 related
    using FF7::ModelListFileManager;
    using FF7::ModelListFileSerializer;
    using FF7::WalkmeshFileSerializer;

    //--------------------------------------------------------------------------
    const String    FLevelFileSerializer::TAG_FILE_END( "FINAL FANTASY7" );

    //--------------------------------------------------------------------------
    FLevelFileSerializer::FLevelFileSerializer() :
        Serializer()
    {
    }

    //--------------------------------------------------------------------------
    FLevelFileSerializer::~FLevelFileSerializer()
    {
    }

    //--------------------------------------------------------------------------
    void
    FLevelFileSerializer::importFLevelFile( Ogre::DataStreamPtr &stream, FLevelFile* pDest )
    {
        size_t start_position( stream->tell() );
        readFileHeader( stream );

        uint32 section_offsets[ m_header.section_count ];
        readInts( stream, section_offsets, m_header.section_count );

        Ogre::DataStreamPtr section;
        for( size_t i(0); i < m_header.section_count; ++i )
        {
            size_t current_offset( stream->tell() - start_position );
            size_t section_gap( section_offsets[i] - current_offset );
            if( current_offset > section_offsets[i] )
            {
                OGRE_EXCEPT(Ogre::Exception::ERR_INVALIDPARAMS
                    ,"FLevel sections overlap"
                    ,"FLevelFileSerializer::importFLevelFile" );
            }
            else if( section_gap )
            {
                stream->skip( section_gap );
                Ogre::LogManager::getSingleton().stream()
                    << "Warning: skiping gap in front of section " << i
                    << " gap size " << section_gap
                    << " FLevelFileSerializer::importFLevelFile";
            }

            readSectionData( stream, section );
            readSection( section, pDest, i );
            section->close();
            section.setNull();
        }
        readEnd( stream );
    }

    //--------------------------------------------------------------------------
    void
    FLevelFileSerializer::readFileHeader( Ogre::DataStreamPtr &stream )
    {
        readShort( stream, m_header.version );
        if( m_header.version != 0 )
        {
            OGRE_EXCEPT(Ogre::Exception::ERR_INVALIDPARAMS
                ,"FLevel has unsupported version"
                ,"FLevelFileSerializer::importFLevelFile" );
        }

        readInt(   stream, m_header.section_count );
        if( m_header.section_count != SECTION_COUNT )
        {
            Ogre::LogManager::getSingleton().stream()
                << "Warning: FLevel section_count has unexpected value "
                << m_header.section_count << " should be " << SECTION_COUNT
                << " FLevelFileSerializer::importFLevelFile";
        }
    }

    //--------------------------------------------------------------------------
    void
    FLevelFileSerializer::readSectionData( Ogre::DataStreamPtr &stream
                                          ,Ogre::DataStreamPtr &out_buffer )
    {
        uint32 length( 0 );
        readInt( stream, length );
        // TODO: implement SubDataStream class to restrict access size etc
        // so we don't have to copy the whole memory
        Ogre::MemoryDataStream *buffer( new Ogre::MemoryDataStream( length ) );
        stream->read( buffer->getPtr(), length );
        out_buffer = Ogre::DataStreamPtr( buffer );
    }

    //--------------------------------------------------------------------------
    void
    FLevelFileSerializer::readSection( Ogre::DataStreamPtr &stream
                                      ,FLevelFile *pDest
                                      ,const size_t section_index )
    {
        switch( section_index )
        {
            case SECTION_CAMERA_MATRIX:
                readCameraMatrix( stream, pDest );
                break;

            case SECTION_MODEL_LOADER:
                readModelList( stream, pDest );
                break;

            case SECTION_PALETTE:
                readPalette( stream, pDest );
                break;

            case SECTION_WALKMESH:
                readWalkmesh( stream, pDest );
                break;

            case SECTION_BACKGROUND:
                readBackground( stream, pDest );
                break;
        }
    }

    //--------------------------------------------------------------------------
    template<typename ResourceManagerType>
    Ogre::ResourcePtr
    FLevelFileSerializer::createResource( FLevelFile *pDest, const String &extension )
    {
        assert( pDest );
        Ogre::ResourceManager &mgr( ResourceManagerType::getSingleton() );
        String name( getBaseName( pDest ) + extension );
        Ogre::ResourcePtr resource( mgr.create( name, pDest->getGroup(), true ) );
        resource->_notifyOrigin( pDest->getName() );
        return resource;
    }

    //--------------------------------------------------------------------------
    void
    FLevelFileSerializer::readCameraMatrix( Ogre::DataStreamPtr &stream, FLevelFile *pDest )
    {
        CameraMatrixFilePtr camera_matrix( createResource<CameraMatrixFileManager>( pDest, EXT_CAMERA_MATRIX ) );
        CameraMatrixFileSerializer ser;
        ser.importCameraMatrixFile( stream, camera_matrix.getPointer() );
        pDest->setCameraMatrix( camera_matrix );
    }

    //--------------------------------------------------------------------------
    void
    FLevelFileSerializer::readModelList( Ogre::DataStreamPtr &stream, FLevelFile *pDest )
    {
        ModelListFilePtr model_list( createResource<ModelListFileManager>( pDest, EXT_MODEL_LIST ) );
        ModelListFileSerializer ser;
        ser.importModelListFile( stream, model_list.getPointer() );
        pDest->setModelList( model_list );
    }

    //--------------------------------------------------------------------------
    void
    FLevelFileSerializer::readPalette( Ogre::DataStreamPtr &stream, FLevelFile *pDest )
    {
        PaletteFilePtr palette( createResource<PaletteFileManager>( pDest, EXT_PALETTE ) );
        PaletteFileSerializer ser;
        ser.importPaletteFile( stream, palette.getPointer() );
        pDest->setPalette( palette );
    }

    //--------------------------------------------------------------------------
    void
    FLevelFileSerializer::readWalkmesh( Ogre::DataStreamPtr &stream, FLevelFile *pDest )
    {
        WalkmeshFilePtr walkmesh( createResource<WalkmeshFileManager>( pDest, EXT_WALKMESH ) );
        WalkmeshFileSerializer ser;
        ser.importWalkmeshFile( stream, walkmesh.getPointer() );

        WalkmeshFile::TriangleList& triangles( walkmesh->getTriangles() );
        WalkmeshFile::TriangleList::iterator it( triangles.begin() );
        WalkmeshFile::TriangleList::const_iterator it_end( triangles.end() );
        Ogre::Real scale( pDest->getCameraMatrix()->getCount() );
        scale *= FF7::FIELD_POSITION_SCALE;
        while( it != it_end )
        {
            it->a /= scale;
            it->b /= scale;
            it->c /= scale;
            ++it;
        }
        pDest->setWalkmesh( walkmesh );
    }

    //--------------------------------------------------------------------------
    void
    FLevelFileSerializer::readBackground( Ogre::DataStreamPtr &stream, FLevelFile *pDest )
    {
        BackgroundFilePtr background( createResource<BackgroundFileManager>( pDest, EXT_BACKGROUND ) );
        BackgroundFileSerializer ser;
        ser.importBackgroundFile( stream, background.getPointer() );
        pDest->setBackground( background );
    }

    //--------------------------------------------------------------------------
    String
    FLevelFileSerializer::getBaseName( const FLevelFile *pDest ) const
    {
        String base_name;
        StringUtil::splitBase( pDest->getName(), base_name );
        return base_name;
    }

    //--------------------------------------------------------------------------
    void
    FLevelFileSerializer::readEnd( Ogre::DataStreamPtr &stream )
    {
        readEndString( stream, TAG_FILE_END );
    }

    //----------------------------------------------------------------------
    template<typename ValueType>
    void
    FLevelFileSerializer::readVector( Ogre::DataStreamPtr &stream
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

    //--------------------------------------------------------------------------
}
