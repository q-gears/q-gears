/*
-----------------------------------------------------------------------------
The MIT License (MIT)

Copyright (c) 2013-07-30 Tobias Peters <tobias.peters@kreativeffekt.at>

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
#include "QGearsTexFile.h"

#include <OgreException.h>
#include <OgreImageCodec.h>

using Ogre::Exception;
using Ogre::ImageCodec;
using Ogre::MemoryDataStream;
using Ogre::uint32;

namespace QGears
{
    //---------------------------------------------------------------------
    const Ogre::uint8 TexFile::USE_REFERENCE_ALPHA( 0xFE );

    //---------------------------------------------------------------------
    TexFile::TexFile()
    {
        //ctor
    }

    //---------------------------------------------------------------------
    TexFile::~TexFile()
    {
        //dtor
    }

    //---------------------------------------------------------------------
    void TexFile::read( Ogre::DataStreamPtr& input )
    {
        readHeader( input );

        size_t image_pixel_count(
            m_header.image_data.width
          * m_header.image_data.height
        );
		m_image_data.resize( image_pixel_count );
		memset( &m_image_data[0], 0
          , image_pixel_count * sizeof( t_ImageData::value_type )
        );

		if( m_header.palette_data.flag )
		{
		    readPalleted( input );
		}
		else
        {
			OGRE_EXCEPT( Exception::ERR_NOT_IMPLEMENTED
              , "PixelFormat Data not yet implemented"
              , "QGears::TexFile::read"
            );
        }
    }

    //---------------------------------------------------------------------
    void TexFile::readHeader( Ogre::DataStreamPtr& input )
    {
		// Read header in full
		input->read( &m_header, sizeof( m_header ) );
		// Endian flip if required, all 32-bit values
		flipEndian( &m_header, 4, sizeof( m_header ) / 4 );

		if ( m_header.version != 0x1 )
		{
			OGRE_EXCEPT( Exception::ERR_NOT_IMPLEMENTED
              , "Only TEX Version 0x1 implemented"
              , "QGears::TexFile::read"
            );
		}

    }

    //---------------------------------------------------------------------
    void TexFile::readPalleted( Ogre::DataStreamPtr& input )
    {
        size_t image_pixel_count( m_image_data.size() );

        entry_t total_color_count( m_header.palette_data.total_color_count );
        if( !total_color_count )
        {
            total_color_count = m_header.palette_total_color_count;
        }

        entry_t current_palette( 0 );
        entry_t color_key_flag( m_header.color_key_flag );
        if( m_header.color_key_array_flag )
        {
            //color_key_flag = color_key_array[current_palette];
        }

        size_t palette_data_size(
            total_color_count
          * sizeof( t_Palette::value_type )
        );
        m_palette.resize( total_color_count );
        void *ptr_palette( &m_palette[0] );
        input->read( ptr_palette, palette_data_size );
        flipEndian( ptr_palette, sizeof( t_Palette::value_type )
          , total_color_count
        );

        typedef std::vector<Ogre::uint8> t_IndexData;
        t_IndexData index_data( image_pixel_count );
        input->read( &index_data[0], image_pixel_count );
        for( size_t i( 0 ); i < image_pixel_count; ++i )
        {
            t_IndexData::value_type index( index_data[i] );
            if( index < m_palette.size() )
            {
                m_image_data[i] = m_palette[index];
            }
            else
            {
    			OGRE_EXCEPT( Exception::ERR_INVALIDPARAMS
                  , "PaletteIndexOutOfBounds"
                  , "QGears::TexFile::readPalleted"
                );
            }
        }
    }

    //---------------------------------------------------------------------
    MemoryDataStream* TexFile::getPixelData() const
    {
        size_t data_size( m_image_data.size()
          * sizeof( t_ImageData::value_type )
        );
        MemoryDataStream* data( OGRE_NEW MemoryDataStream( data_size ) );
        memcpy( data->getPtr(), &m_image_data[0], data_size );
        return data;
    }

    //---------------------------------------------------------------------
    ImageCodec::ImageData* TexFile::getImageData() const
    {
		ImageCodec::ImageData *img_data = OGRE_NEW ImageCodec::ImageData();
		const ImageData &data( m_header.image_data );

		img_data->width  = data.width;
		img_data->height = data.height;
		img_data->size = m_image_data.size() * sizeof( t_ImageData::value_type );
		img_data->num_mipmaps = 0;
		img_data->flags = 0;
		img_data->depth = 1;
		img_data->format = Ogre::PF_A8R8G8B8;
        return img_data;
    }

    //---------------------------------------------------------------------
    void TexFile::flipEndian(void * pData, size_t size, size_t count) const
    {
#if OGRE_ENDIAN == OGRE_ENDIAN_BIG
		for(unsigned int index = 0; index < count; index++)
        {
            flipEndian((void *)((long)pData + (index * size)), size);
        }
#endif
    }
    //---------------------------------------------------------------------
    void TexFile::flipEndian(void * pData, size_t size) const
    {
#if OGRE_ENDIAN == OGRE_ENDIAN_BIG
        char swapByte;
        for(unsigned int byteIndex = 0; byteIndex < size/2; byteIndex++)
        {
            swapByte = *(char *)((long)pData + byteIndex);
            *(char *)((long)pData + byteIndex) = *(char *)((long)pData + size - byteIndex - 1);
            *(char *)((long)pData + size - byteIndex - 1) = swapByte;
        }
#endif
    }
}
