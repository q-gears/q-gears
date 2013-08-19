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
#ifndef __QGearsLZSDataStream_H__
#define __QGearsLZSDataStream_H__

#include <OgreDataStream.h>

#include "common/TypeDefine.h"

namespace QGears
{
    template<size_t buffer_size>
    class RingBuffer
	{
	public:
		RingBuffer()
		{
			clear();
		}

		void write( const void *in_buffer )
		{
		    m_buffer[m_pos] = *( static_cast<const uint8*>( in_buffer ) );
		    ++m_pos %= buffer_size;
		    ++m_avail = std::min( m_avail, buffer_size );
		}

		size_t read( void *out_buffer, size_t count )
		{
		    assert( m_avail && "Can't read if no data is available" );
		    size_t read( 0 );
		    uint8 *buffer( static_cast<uint8*>(out_buffer) );
		    while( read < count && m_avail )
            {
		        *(buffer++) = m_buffer[(m_pos - m_avail) % buffer_size];
		        --m_avail;
		        ++read;
            }
		    return read;
		}

		uint8 get( const size_t offset )
		{
		    return m_buffer[offset % buffer_size];
		}

		size_t avail( void ) const
		{
		    return m_avail;
		}

		void clear()
		{
			m_pos = 0;
			m_avail = 0;
			memset( m_buffer, 0, buffer_size );
		}

	protected:
		uint8 m_buffer[buffer_size];
		size_t m_pos, m_avail;

	};

	//-------------------------------------------------------------------------
    class LZSDataStream : public Ogre::DataStream
    {
    public:

                    LZSDataStream( const Ogre::DataStreamPtr &compressed_stream );
                    LZSDataStream( const String &name, const Ogre::DataStreamPtr &compressed_stream );
        virtual    ~LZSDataStream();

        virtual size_t 	read( void *buf, size_t count );

        virtual bool    eof( void ) const;

		virtual void skip(long count);
	    virtual void seek( size_t pos );
	    virtual size_t tell(void) const;
        virtual void close(void);

        virtual size_t availableCompressed( void ) const { return m_available_compressed; };
        virtual size_t availableUncompressed( void ) const { return m_buffer.avail(); };

        virtual void flipEndian( uint32 &inout_data );

    protected:
        virtual void init();
        virtual void decompressChunk();

        Ogre::DataStreamPtr m_compressed_stream;
        uint32              m_available_compressed;
        size_t              m_pos;
        RingBuffer<4096>    m_buffer;
    private:
    };

    typedef Ogre::SharedPtr<LZSDataStream>  LZSDataStreamPtr;
}

#endif // __QGearsLZSDataStream_H__
