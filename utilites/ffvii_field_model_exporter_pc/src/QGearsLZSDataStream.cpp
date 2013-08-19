/*
-----------------------------------------------------------------------------
The MIT License (MIT)

Copyright (c) 2013-08-18 Tobias Peters <tobias.peters@kreativeffekt.at>

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
#include "QGearsLZSDataStream.h"

#include <OgreException.h>

namespace QGears
{
    //---------------------------------------------------------------------
    LZSDataStream::LZSDataStream( const Ogre::DataStreamPtr &compressed_stream ) :
        Ogre::DataStream( compressed_stream->getAccessMode() )
       ,m_compressed_stream( compressed_stream )
       ,m_available_compressed( 0 )
       ,m_pos( 0 )
    {
        init();
    }

    //---------------------------------------------------------------------
    LZSDataStream::LZSDataStream( const String &name, const Ogre::DataStreamPtr &compressed_stream ) :
        Ogre::DataStream( name, compressed_stream->getAccessMode() )
       ,m_compressed_stream( compressed_stream )
       ,m_available_compressed( 0 )
       ,m_pos( 0 )
    {
        init();
    }

    //---------------------------------------------------------------------
    LZSDataStream::~LZSDataStream()
    {
        close();
    }

    //---------------------------------------------------------------------
    void
    LZSDataStream::init()
    {
        if ( m_compressed_stream->read( &m_available_compressed, 4 ) < 4 )
        {
			OGRE_EXCEPT( Ogre::Exception::ERR_INVALIDPARAMS,
				"Can't read LZS Header from stream",
				"LZSDataStream::init");
        }
        #if OGRE_ENDIAN == OGRE_ENDIAN_BIG
            flipEndian( m_available_compressed );
        #endif
    }

    //---------------------------------------------------------------------
    void
    LZSDataStream::flipEndian( uint32 &inout_data )
    {
        inout_data = ( ( inout_data & 0x000000FF ) << 24 )
                    |( ( inout_data & 0x0000FF00 ) <<  8 )
                    |( ( inout_data & 0x00FF0000 ) >>  8 )
                    |( ( inout_data & 0xFF000000 ) >> 24 );
    }

    //---------------------------------------------------------------------
    size_t
    LZSDataStream::read( void *buf, size_t count )
    {
        assert( buf && "NullPointer" );
        size_t  read_total( 0 );
        while( count && !eof() )
        {
            if( !m_buffer.avail() )
            {
                decompressChunk();
            }
            size_t read( m_buffer.read( buf + read_total, count ) );
            count -= read;
            read_total += read;
        }

        m_pos += read_total;

        return read_total;
    }

    //---------------------------------------------------------------------
    void
    LZSDataStream::decompressChunk()
    {
        if( m_compressed_stream->eof() )
        {
            OGRE_EXCEPT( Ogre::Exception::ERR_INVALIDPARAMS,
                "not enough data in Stream to read control byte",
                "LZSDataStream::decompressChunk");
        }

        uint8   data, control_byte, ref[2];
        uint16  ref_offset;
        m_available_compressed -= m_compressed_stream->read( &control_byte, sizeof( control_byte ) );

        for( uint8 control_bit( 8 )
            ;control_bit-- && !m_compressed_stream->eof() && m_available_compressed
            ;control_byte >>= 1 )
        {
            if( control_byte & 1 )
            {
                m_available_compressed -= m_compressed_stream->read( &data, sizeof( data ) );
                m_buffer.write( &data );
            }
            else if( m_available_compressed < 2 )
            {
                OGRE_EXCEPT( Ogre::Exception::ERR_INVALIDPARAMS,
                    "not enough data in Stream to read reference bytes",
                    "LZSDataStream::decompressChunk");
            }
            else
            {
                m_available_compressed -= m_compressed_stream->read( &ref, sizeof( ref ) );
                ref_offset = 18 + ( ((ref[1] & 0xF0) << 4) | ref[0] );
                for( uint8 ref_length( (ref[1] & 0xF ) + 3 ); ref_length--; )
                {
                    data = m_buffer.get( ref_offset++ );
                    m_buffer.write( &data );
                }
            }
        }
    }

    //---------------------------------------------------------------------
    void
    LZSDataStream::skip( long count )
    {
        OGRE_EXCEPT( Ogre::Exception::ERR_NOT_IMPLEMENTED,
            "not yet implemented",
            "LZSDataStream::skip");
    }

    //---------------------------------------------------------------------
    void
    LZSDataStream::seek( size_t pos )
    {
        OGRE_EXCEPT( Ogre::Exception::ERR_NOT_IMPLEMENTED,
            "not yet implemented",
            "LZSDataStream::seek");
    }

    //---------------------------------------------------------------------
    bool
    LZSDataStream::eof( void ) const
    {
        return !m_available_compressed
            && !m_buffer.avail();
    }

    //---------------------------------------------------------------------
    size_t
    LZSDataStream::tell( void ) const
    {
        return m_pos;
    }

    //---------------------------------------------------------------------
    void
    LZSDataStream::close( void )
    {
        m_compressed_stream.setNull();
    }

    //---------------------------------------------------------------------
}
